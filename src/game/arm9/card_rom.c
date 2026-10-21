/*
 * file:     card_rom.c
 * unit:     yes
 * function: CARDi_SetRomOp, CARDi_IsNormalMode, CARDi_StartRomPageTransfer, CARDi_ReadRomIDCore, CARDi_ReadRomStatusCore, CARDi_RefreshRom, CARDi_RefreshRomCore, CARDi_ReadRomWithCPU, CARDi_DmaReadPageCallback, CARDi_ReadRomWithDMA, CARDi_DmaReadDone, CARDi_IsRomDmaAvailable, CARDi_ReadRomSyncCore, CARDi_ReadRom, CARDi_InitRom, CARD_WaitRomAsync, CARDi_GetRomCacheBuffer
 * address:  0x02076BBC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   CARD_GetOwnRomHeaderTWL  0x02075E04  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   OS_GetBootType  0x02087B04  arm
 *   CARDi_IsNormalMode  0x02076C3C  arm
 *   CARDi_SetRomOp  0x02076BBC  arm
 *   CARDi_ReadRomStatusCore  0x02076D38  arm
 *   CARDi_RefreshRomCore  0x02076E00  arm
 *   OS_IsAlarmAvailable  0x02087244  arm
 *   OS_Sleep  0x02085A38  arm
 *   OSi_IsThreadInitialized  0x02150FDC  data
 *   CARDi_StartRomPageTransfer  0x02076C88  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   CARDi_ReadRomIDCore  0x02076CD0  arm
 *   CARDi_CheckPulledOutCore  0x02077518  arm
 *   CARDiEnableCacheInvalidationDC  0x020A8498  data
 *   CARDi_cache_buf  0x02150900  data
 *   OS_DisableIrqMask  0x02084998  arm
 *   OS_ResetRequestIrqMask  0x020849C8  arm
 *   cardi_rom_base  0x02150840  data
 *   cardi_common  0x02150200  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_SetIrqFunction  0x02084774  arm
 *   OS_EnableIrqMask  0x02084968  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   CARDi_DmaReadPageCallback  0x02076F68  arm
 *   CARDi_RefreshRom  0x02076DA0  arm
 *   CARDi_EndTask  0x020762A8  arm
 *   OS_GetDTCMAddress  0x02086CE0  arm
 *   CARD_CheckEnabled               0x02075DB0  arm
 *   CARDi_GetAccessLevel            0x02075FCC  arm
 *   OS_Terminate                    0x02088234  arm
 *   CARDi_WaitForTask               0x02076230  arm
 *   CARDi_GetDmaInterface           0x020762F4  arm
 *   CARDi_IsRomDmaAvailable         0x020770B4  arm
 *   CARDi_ICInvalidateSmart         0x02076344  arm
 *   CARDi_DCInvalidateSmart         0x02076360  arm
 *   CARDi_ReadRomWithDMA            0x02077008  arm
 *   CARDi_ExecuteOldTypeTask        0x02076170  arm
 *   CARDi_DmaReadDone               0x02077084  arm
 *   CARDi_ReadRomWithCPU            0x02076E4C  arm
 *   CARDiDmaReadInfo                0x02150850  data
 *   CARDi_ReadRomSyncCore           0x02077168  arm
 *   CARD_GetOwnRomHeader  0x02075DF8  arm
 *   OS_GetLockID  0x02084EB8  arm
 *   CARD_LockRom  0x02075E10  arm
 *   CARD_UnlockRom  0x02075E80  arm
 *   OS_ReleaseLockID  0x02084F10  arm
 *   CARDi_InitRomHash  0x0272EA74  arm
 *   CARDiOwnSignature  0x0215086C  data
 *   CARDi_WaitAsync  0x02076050  arm
 */
#define reg_MI_MCCNT0 (*(vu16 *)REG_MCCNT0_ADDR)
#define reg_MI_MCCNT1 (*(vu32 *)REG_MCCNT1_ADDR)
#define reg_MI_MCCMD0 (*(vu32 *)REG_MCCMD0_ADDR)
#define reg_MI_MCCMD1 (*(vu32 *)REG_MCCMD1_ADDR)
#define MI_HToBE32(x) ((((x) & 0xFF000000) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))
#define CARDi_romctrl (*(vu32 *)0x02FFFAE0)
#define reg_MI_MCD1 (*(vu32 *)0x04100010)
#define CARDi_romid (*(vu32 *)0x02FFFC00)
#define CARD_ROM_PAGE_SIZE 512
#define MATH_ROUNDDOWN(x, align) ((x) & ~((align) - 1))
#define MATH_MIN(a, b) (((a) <= (b)) ? (a) : (b))
#define REG_MI_MCCNT1_RDY_MASK 0x00800000
#define REG_MI_MCCNT1_START_MASK 0x80000000
#define CARD_ACCESS_LEVEL_ROM  0x4
#define MI_DMA_NOT_USE         ((u32)-1)
#define MI_DMA_MAX_NUM         3
#include "../types.h"
#include "../sdk_ioreg.h"

#include "../sdk_os.h"

#include "../sdk_card.h"

#include "card_common.h"

#include "card_rom.h"

typedef int (*CARDiReadRomFunc)(void *userdata, void *buffer, u32 offset, u32 length);

typedef struct CARDiRomCacheState
{
    BOOL enable_dc_invalidation;
    u32 cached_page;
} CARDiRomCacheState;

typedef struct CARDiRomState
{
    u32 rom_base;
    CARDiReadRomFunc read_func;
    BOOL enableCacheInvalidationIC;
    CARDTransferInfo *registeredInfo;
    CARDTransferInfo dmaReadInfo;
} CARDiRomState;

typedef void (*MIDmaCallback)(void *);

#include "card_api.h"
#include "../twl/card_rom.h"
#include "os_emulator.h"
#include "os_systemwork.h"
extern BOOL CARDi_IsNormalMode(void);
extern void CARDi_SetRomOp(u32 command, u32 offset);
extern u32 CARDi_ReadRomStatusCore(void);
extern void CARDi_RefreshRomCore(void);
#include "os_alarm.h"
#include "os_thread.h"
extern void CARDi_StartRomPageTransfer(u32 offset);
#include "mi_memory.h"
extern u32 CARDi_ReadRomIDCore(void);
#include "card_pullout.h"
#include "os_interrupt.h"
#include "os_system.h"
extern void OS_SetIrqFunction(u32 intrBit, void (*function)(void));
extern void CARDi_DmaReadPageCallback(void);
extern void CARDi_RefreshRom(u32 warn_mask);
#include "card_task.h"
#include "os_tcm.h"
#include "os_terminate_processor.h"
#include "card_utility.h"
extern BOOL CARDi_IsRomDmaAvailable(u32 dma, void *dst, u32 src, u32 len);
extern void CARDi_ReadRomWithDMA(CARDTransferInfo *info);
extern void CARDi_DmaReadDone(void *arg);
extern int CARDi_ReadRomWithCPU(void *userdata, void *buffer, u32 offset, u32 length);
extern void CARDi_ReadRomSyncCore(CARDiCommon *c);
#include "os_spinlock.h"
void CARDi_ReadRom(u32 dma, const void *src, void *dst, u32 len, MIDmaCallback callback, void *arg, BOOL is_async);
void CARDi_InitRom(void);
void CARD_WaitRomAsync(void);
void *CARDi_GetRomCacheBuffer(void);
extern BOOL OSi_IsThreadInitialized;
extern CARDiRomCacheState CARDiEnableCacheInvalidationDC;
extern CARDiCommon cardi_common;
extern CARDiRomState cardi_rom_base;
extern CARDTransferInfo CARDiDmaReadInfo[1];
extern u8 CARDiOwnSignature[136];

/*
 * sdk:      CARDi_SetRomOp (libcard.TWL.HYB.a card_rom.o)
 */
void CARDi_SetRomOp(u32 command, u32 offset)
{
    u32 cmd1 = (u32)((offset >> 8) | (command << 24));
    u32 cmd2 = (u32)((offset << 24));

    while ((reg_MI_MCCNT1 & 0x80000000) != 0)
    {
    }
    reg_MI_MCCNT0 = (u16)((reg_MI_MCCNT0 & ~0x2000) | 0xC000);
    reg_MI_MCCMD0 = MI_HToBE32(cmd1);
    reg_MI_MCCMD1 = MI_HToBE32(cmd2);
}

/*
 * sdk:      CARDi_IsNormalMode (libcard.TWL.HYB.a card_rom.o)
 */
BOOL CARDi_IsNormalMode(void)
{
    const CARDRomHeaderTWL *oh = CARD_GetOwnRomHeaderTWL();

    return OS_IsRunOnTwl() &&
           (OS_GetBootType() != 1) &&
           oh->access_control.gameCardPowerOn &&
           !oh->access_control.gameCardNitroMode;
}

/*
 * sdk:      CARDi_StartRomPageTransfer (libcard.TWL.HYB.a card_rom.o)
 */
void CARDi_StartRomPageTransfer(u32 offset)
{
    u8 op = 0xB7;

    if (CARDi_IsNormalMode())
    {
        op = 0x00;
    }
    CARDi_SetRomOp(op, offset);
    reg_MI_MCCNT1 = (CARDi_romctrl & ~0x07000000) | 0xA1000000;
}

/*
 * sdk:      CARDi_ReadRomIDCore (libcard.TWL.HYB.a card_rom.o)
 */
u32 CARDi_ReadRomIDCore(void)
{
    u8 op = 0xB8;

    if (CARDi_IsNormalMode())
    {
        op = 0x90;
    }
    CARDi_SetRomOp(op, 0);
    reg_MI_MCCNT1 = (u32)((CARDi_romctrl & ~0x07000000) | 0xA7000000) & ~0x1FFF;
    while ((reg_MI_MCCNT1 & 0x00800000) == 0)
    {
    }
    return reg_MI_MCD1;
}

/*
 * sdk:      CARDi_ReadRomStatusCore (libcard.TWL.HYB.a card_rom.o)
 */
u32 CARDi_ReadRomStatusCore(void)
{
    if ((CARDi_romid & 0x20000000) == 0)
    {
        return 0x20;
    }
    CARDi_SetRomOp(0xD6, 0);
    reg_MI_MCCNT1 = (u32)((CARDi_romctrl & ~0x07000000) | 0xA7000000) & ~0x1FFF;
    while ((reg_MI_MCCNT1 & 0x00800000) == 0)
    {
    }
    return reg_MI_MCD1;
}

/*
 * sdk:      CARDi_RefreshRom (libcard.TWL.HYB.a card_rom.o)
 */
void CARDi_RefreshRom(u32 warn_mask)
{
    if ((CARDi_ReadRomStatusCore() & warn_mask) != 0)
    {
        CARDi_RefreshRomCore();
        while ((CARDi_ReadRomStatusCore() & 0x20) == 0)
        {
            if (OSi_IsThreadInitialized && OS_IsAlarmAvailable())
            {
                OS_Sleep(1);
            }
        }
    }
}

/*
 * sdk:      CARDi_RefreshRomCore (libcard.TWL.HYB.a card_rom.o)
 */
void CARDi_RefreshRomCore(void)
{
    CARDi_SetRomOp(0xB5, 0);
    reg_MI_MCCNT1 = (u32)((CARDi_romctrl & ~0x07000000) | 0xA0000000) & ~0x1FFF;
    while ((reg_MI_MCCNT1 & 0x80000000) != 0)
    {
    }
}

extern u8 CARDi_cache_buf[512] __attribute__((aligned(32)));

/*
 * notes:    CARDi_cache_buf is a 512-byte static in card_rom.o .bss with sh_addralign 32;
 *            declaring that alignment keeps n as a real copy at the compare.
 *
 * sdk:      CARDi_ReadRomWithCPU (libcard.TWL.HYB.a card_rom.o)
 */
BOOL CARDi_ReadRomWithCPU(void *userdata, void *buffer, u32 offset, u32 length)
{
    BOOL retval = (BOOL)length;
    u32 cachedPage = CARDiEnableCacheInvalidationDC.cached_page;
    u8 *const cacheBuffer = CARDi_cache_buf;
    while (length > 0)
    {
        u8 *ptr = (u8 *)buffer;
        u32 n = CARD_ROM_PAGE_SIZE;
        u32 pos = MATH_ROUNDDOWN(offset, CARD_ROM_PAGE_SIZE);
        if (pos == cachedPage)
        {
            ptr = cacheBuffer;
        }
        else
        {
            if ((pos != offset) || (((uptr)buffer & 3) != 0) || (length < n))
            {
                ptr = cacheBuffer;
                cachedPage = pos;
            }
            CARDi_StartRomPageTransfer(pos);
            {
                u32 word = 0;
                for (;;)
                {
                    u32 ctrl = reg_MI_MCCNT1;
                    if ((ctrl & REG_MI_MCCNT1_RDY_MASK) != 0)
                    {
                        u32 data = reg_MI_MCD1;
                        if (word < CARD_ROM_PAGE_SIZE / sizeof(u32))
                        {
                            ((u32 *)ptr)[word++] = data;
                        }
                    }
                    if ((ctrl & REG_MI_MCCNT1_START_MASK) == 0)
                    {
                        break;
                    }
                }
            }
        }
        if (ptr == cacheBuffer)
        {
            u32 mod = offset - pos;
            n = MATH_MIN(length, CARD_ROM_PAGE_SIZE - mod);
            MI_CpuCopy8(cacheBuffer + mod, buffer, n);
        }
        buffer = (u8 *)buffer + n;
        offset += n;
        length -= n;
    }
    
    CARDi_CheckPulledOutCore(CARDi_ReadRomIDCore());
    CARDiEnableCacheInvalidationDC.cached_page = cachedPage;
    return retval;
}

/*
 * sdk:      CARDi_DmaReadPageCallback (libcard.TWL.HYB.a card_rom.o)
 */
void CARDi_DmaReadPageCallback(void)
{
    CARDTransferInfo *const info = cardi_rom_base.registeredInfo;

    if (info)
    {
        info->src += 512;
        info->dst += 512;
        info->len -= 512;
        if (info->len != 0)
        {
            CARDi_StartRomPageTransfer(info->src);
        }
        else
        {
            (*cardi_common.DmaCall->Stop)(cardi_common.dma);
            (void)OS_DisableIrqMask(0x80000);
            (void)OS_ResetRequestIrqMask(0x80000);
            cardi_rom_base.registeredInfo = 0;
            CARDi_CheckPulledOutCore(CARDi_ReadRomIDCore());
            if (info->callback)
            {
                (*info->callback)(info->userdata);
            }
        }
    }
}

/*
 * sdk:      CARDi_ReadRomWithDMA (libcard.TWL.HYB.a card_rom.o)
 */
void CARDi_ReadRomWithDMA(CARDTransferInfo *info)
{
    u32 bak_psr = OS_DisableInterrupts();

    cardi_rom_base.registeredInfo = info;
    OS_SetIrqFunction(0x80000, CARDi_DmaReadPageCallback);
    (void)OS_ResetRequestIrqMask(0x80000);
    (void)OS_EnableIrqMask(0x80000);
    (void)OS_RestoreInterrupts(bak_psr);
    {
        CARDiCommon *const p = &cardi_common;

        (*p->DmaCall->Recv)(p->dma, (const void *)0x04100010, (void *)info->dst, 0x200);
    }
    CARDi_StartRomPageTransfer(info->src);
}

/*
 * sdk:      CARDi_DmaReadDone (libcard.TWL.HYB.a card_rom.o)
 */
void CARDi_DmaReadDone(void *arg)
{
    CARDi_CheckPulledOutCore(CARDi_ReadRomIDCore());
    CARDi_RefreshRom(8);
    cardi_common.cmd->result = 0;
    CARDi_EndTask(&cardi_common);
}

static inline BOOL CARDi_IsNotITCM(const void *dst, u32 len)
{
    return ((uptr)dst + len <= 0x01FF8000) || ((uptr)dst >= 0x02000000);
}

static inline BOOL CARDi_IsNotDTCM(const void *dst, u32 len)
{
    return ((uptr)dst + len <= (u32)OS_GetDTCMAddress()) || ((uptr)dst >= (u32)OS_GetDTCMAddress() + 0x4000);
}

static inline BOOL CARDi_IsDmaTarget(u32 dma, const void *dst, u32 len)
{
    return (dma <= 3) && (len > 0) && (((uptr)dst & 31) == 0) && CARDi_IsNotITCM(dst, len);
}

static inline BOOL CARDi_IsDmaDestination(u32 dma, const void *dst, u32 len)
{
    return CARDi_IsDmaTarget(dma, dst, len) && CARDi_IsNotDTCM(dst, len);
}

/*
 * sdk:      CARDi_IsRomDmaAvailable (libcard.TWL.HYB.a card_rom.o)
 */
BOOL CARDi_IsRomDmaAvailable(u32 dma, void *dst, u32 src, u32 len)
{
    return CARDi_IsDmaDestination(dma, dst, len) && (((src | len) & 0x1FF) == 0);
}

/*
 * sdk:      CARDi_ReadRomSyncCore (libcard.TWL.HYB.a card_rom.o)
 */
void CARDi_ReadRomSyncCore(CARDiCommon *c)
{
    (void)(*cardi_rom_base.read_func)(0, (void *)c->dst, c->src, c->len);
    CARDi_CheckPulledOutCore(CARDi_ReadRomIDCore());
    CARDi_RefreshRom(8);
    cardi_common.cmd->result = 0;
}

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

    c->src = (uptr)src + cardi_rom_base.rom_base;
    c->dst = (uptr)dst;
    c->len = len;

    cardi_rom_base.dmaReadInfo.callback = CARDi_DmaReadDone;
    cardi_rom_base.dmaReadInfo.userdata = 0;
    cardi_rom_base.dmaReadInfo.src = c->src;
    cardi_rom_base.dmaReadInfo.dst = c->dst;
    cardi_rom_base.dmaReadInfo.len = c->len;
    cardi_rom_base.dmaReadInfo.work = 0;

    if ((cardi_rom_base.read_func == CARDi_ReadRomWithCPU) &&
        CARDi_IsRomDmaAvailable(c->dma, (void *)c->dst, c->src, c->len)) {
        {
            OSIntrMode bak_psr = OS_DisableInterrupts();
            if (cardi_rom_base.enableCacheInvalidationIC) {
                CARDi_ICInvalidateSmart((void *)c->dst, c->len, c->flush_threshold_ic);
            }
            if (CARDiEnableCacheInvalidationDC.enable_dc_invalidation) {
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

/*
 * sdk:      CARDi_InitRom (libcard.TWL.HYB.a card_rom.o)
 */
void CARDi_InitRom(void)
{
    cardi_rom_base.read_func = CARDi_ReadRomWithCPU;
    if ((OS_GetBootType() == 1) && (CARD_GetOwnRomHeader()->rom_size != 0))
    {
        u16 id = (u16)OS_GetLockID();

        CARD_LockRom(id);
        (void)CARDi_ReadRomWithCPU(0, CARDiOwnSignature, CARD_GetOwnRomHeader()->rom_size, sizeof(CARDiOwnSignature));
        CARD_UnlockRom(id);
        OS_ReleaseLockID(id);
    }
    if (OS_IsRunOnTwl())
    {
        CARDi_InitRomHash();
    }
}

void CARD_WaitRomAsync(void){ CARDi_WaitAsync(); }

/*
 * Getter returning the address of a global (CARDi_GetOwnSignature).  Called
 * from the ov107 segment reader 0x021F2FA0.
 */
void *CARDi_GetRomCacheBuffer(void)
{
    return CARDiOwnSignature;
}
