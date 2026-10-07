/*
 * function: CARDi_ReadRom
 * address:  0x020771B4
 * packet:   pkt_020771B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libcard card_rom.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Starts a card ROM read: takes the card task, picks the DMA interface for the
 * channel (stopping it), records the transfer in cardi_common and in
 * CARDiDmaReadInfo, then either runs the page-wise DMA transfer (invalidating
 * the caches over the destination first) when the default CPU reader is
 * installed and the DMA can do the job, or queues the old-style synchronous
 * task.  The .bss statics of card_rom.o from cardi_rom_base on are addressed
 * off that one symbol.
 *
 * symbols:
 *   CARD_CheckEnabled               0x02075DB0  arm
 *   CARDi_GetAccessLevel            0x02075FCC  arm
 *   OS_Terminate                    0x02088234  arm
 *   CARDi_WaitForTask               0x02076230  arm
 *   CARDi_GetDmaInterface           0x020762F4  arm
 *   CARDi_IsRomDmaAvailable         0x020770B4  arm
 *   OS_DisableInterrupts            0x02087988  arm
 *   CARDi_ICInvalidateSmart         0x02076344  arm
 *   CARDi_DCInvalidateSmart         0x02076360  arm
 *   OS_RestoreInterrupts            0x0208799C  arm
 *   CARDi_ReadRomWithDMA            0x02077008  arm
 *   CARD_WaitRomAsync               0x020773C4  arm
 *   CARDi_ExecuteOldTypeTask        0x02076170  arm
 *   cardi_common                    0x02150200  data
 *   cardi_rom_base                  0x02150840  data
 *   CARDi_DmaReadDone               0x02077084  arm
 *   CARDi_ReadRomWithCPU            0x02076E4C  arm
 *   CARDiEnableCacheInvalidationDC  0x020A8498  data
 *   CARDiDmaReadInfo                0x02150850  data
 *   CARDi_ReadRomSyncCore           0x02077168  arm
 */

#include "../include/G_CARDiRomCacheState.h"

typedef unsigned char u8;
typedef unsigned long u32;
typedef int BOOL;
typedef u32 OSIntrMode;
typedef void (*MIDmaCallback)(void *);

#define CARD_ACCESS_LEVEL_ROM  0x4
#define MI_DMA_NOT_USE         ((u32)-1)
#define MI_DMA_MAX_NUM         3

typedef struct CARDDmaInterface {
    void (*Recv)(u32 channel, const void *src, void *dst, u32 len);
    void (*Stop)(u32 channel);
} CARDDmaInterface;

typedef struct CARDTransferInfo {
    u32 command;
    void (*callback)(void *);
    void *userdata;
    u32 src;
    u32 dst;
    u32 len;
    u32 work;
} CARDTransferInfo;

typedef struct CARDiCommon {
    void *cmd;
    volatile u32 flag;
    u32 priority;
    u32 flush_threshold_ic;
    u32 flush_threshold_dc;
    u8 opaque[0x4FC - 0x14];
    u32 src;
    u32 dst;
    u32 len;
    u32 dma;
    const CARDDmaInterface *DmaCall;
} CARDiCommon;

typedef int (*CARDiReadRomFunc)(void *userdata, void *buffer, u32 offset, u32 length);

/* card_rom.o's .bss statics from cardi_rom_base on, in their laid-out order */
typedef struct {
    u32 rom_base;
    CARDiReadRomFunc readRomFunction;
    BOOL enableCacheInvalidationIC;
    CARDTransferInfo *registeredInfo;
    CARDTransferInfo dmaReadInfo;
} CARDiRomState;

extern CARDiCommon cardi_common;
extern CARDiRomState cardi_rom_base;
extern CARDTransferInfo CARDiDmaReadInfo[1];
extern struct CARDiRomCacheState CARDiEnableCacheInvalidationDC;

extern void CARD_CheckEnabled(void);
extern int CARDi_GetAccessLevel(void);
extern void OS_Terminate(void);
extern BOOL CARDi_WaitForTask(CARDiCommon *p, BOOL restart, MIDmaCallback callback, void *callback_arg);
extern const CARDDmaInterface *CARDi_GetDmaInterface(u32 channel);
extern BOOL CARDi_IsRomDmaAvailable(u32 dma, void *dst, u32 src, u32 len);
extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern void CARDi_ICInvalidateSmart(void *buffer, u32 length, u32 threshold);
extern void CARDi_DCInvalidateSmart(void *buffer, u32 length, u32 threshold);
extern void CARDi_ReadRomWithDMA(CARDTransferInfo *info);
extern void CARD_WaitRomAsync(void);
extern BOOL CARDi_ExecuteOldTypeTask(void (*task)(CARDiCommon *), BOOL async);
extern void CARDi_DmaReadDone(void *arg);
extern int CARDi_ReadRomWithCPU(void *userdata, void *buffer, u32 offset, u32 length);
extern void CARDi_ReadRomSyncCore(CARDiCommon *c);

void CARDi_ReadRom(u32 dma, const void *src, void *dst, u32 len, MIDmaCallback callback, void *arg, BOOL is_async)
{
    CARDiCommon *c = &cardi_common;

    CARD_CheckEnabled();
    if ((CARDi_GetAccessLevel() & CARD_ACCESS_LEVEL_ROM) == 0) {
        OS_Terminate();
    }

    (void)CARDi_WaitForTask(c, 1, callback, arg);

    c->DmaCall = CARDi_GetDmaInterface(dma);
    c->dma = c->DmaCall ? (dma & 3) : MI_DMA_NOT_USE;
    if (c->dma <= MI_DMA_MAX_NUM) {
        c->DmaCall->Stop(c->dma);
    }

    c->src = (u32)src + cardi_rom_base.rom_base;
    c->dst = (u32)dst;
    c->len = len;

    cardi_rom_base.dmaReadInfo.callback = CARDi_DmaReadDone;
    cardi_rom_base.dmaReadInfo.userdata = 0;
    cardi_rom_base.dmaReadInfo.src = c->src;
    cardi_rom_base.dmaReadInfo.dst = c->dst;
    cardi_rom_base.dmaReadInfo.len = c->len;
    cardi_rom_base.dmaReadInfo.work = 0;

    if ((cardi_rom_base.readRomFunction == CARDi_ReadRomWithCPU) &&
        CARDi_IsRomDmaAvailable(c->dma, (void *)c->dst, c->src, c->len)) {
        {
            OSIntrMode bak_psr = OS_DisableInterrupts();
            if (cardi_rom_base.enableCacheInvalidationIC) {
                CARDi_ICInvalidateSmart((void *)c->dst, c->len, c->flush_threshold_ic);
            }
            if ((*(BOOL *)&CARDiEnableCacheInvalidationDC)) {
                CARDi_DCInvalidateSmart((void *)c->dst, c->len, c->flush_threshold_dc);
            }
            (void)OS_RestoreInterrupts(bak_psr);
        }
        CARDi_ReadRomWithDMA(CARDiDmaReadInfo);
        if (!is_async) {
            CARD_WaitRomAsync();
        }
    } else {
        if (cardi_rom_base.enableCacheInvalidationIC) {
            CARDi_ICInvalidateSmart((void *)c->dst, c->len, c->flush_threshold_ic);
        }
        (void)CARDi_ExecuteOldTypeTask(CARDi_ReadRomSyncCore, is_async);
    }
}
