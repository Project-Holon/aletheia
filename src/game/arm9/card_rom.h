#ifndef GAME_ARM9_CARD_ROM_H
#define GAME_ARM9_CARD_ROM_H

#include "../types.h"

/* Card ROM transfer request. */

typedef struct CARDTransferInfo
{
    u32 command;
    void (*callback)(void *);
    void *userdata;
    uptr src;
    uptr dst;
    u32 len;
    u32 work;
} CARDTransferInfo;

#include "../arm9/card_common.h"
void CARDi_SetRomOp(u32 command, u32 offset);
BOOL CARDi_IsNormalMode(void);
void CARDi_StartRomPageTransfer(u32 offset);
u32 CARDi_ReadRomIDCore(void);
u32 CARDi_ReadRomStatusCore(void);
void CARDi_RefreshRom(u32 warn_mask);
void CARDi_RefreshRomCore(void);
BOOL CARDi_ReadRomWithCPU(void *userdata, void *buffer, u32 offset, u32 length);
void CARDi_DmaReadPageCallback(void);
void CARDi_ReadRomWithDMA(CARDTransferInfo *info);
void CARDi_DmaReadDone(void *arg);
BOOL CARDi_IsRomDmaAvailable(u32 dma, void *dst, u32 src, u32 len);
void CARDi_ReadRomSyncCore(CARDiCommon *c);
void CARDi_InitRom(void);
void CARD_WaitRomAsync(void);
void *CARDi_GetRomCacheBuffer(void);

#endif
