#ifndef GAME_ARM9_NNS_GFD_VRAM_LOAD_H
#define GAME_ARM9_NNS_GFD_VRAM_LOAD_H

#include "../types.h"

/* One registered transfer task (0x10 bytes): taskType indexes the loader table. */
typedef struct NNSiGfdVramTransferTask {
    u32 taskType;
    u32 pSrc;
    u32 offset;
    u32 szByte;
} NNSiGfdVramTransferTask;

/* Ring buffer of transfer tasks, with the running byte total of the queued tasks. */
typedef struct NNSiGfdVramTransferTaskQueue {
    u32 pTaskArray;
    u32 numTasks;
    u16 head;
    u16 tail;
    u16 count;
    u16 pad0E;
    s32 totalSzByte;
} NNSiGfdVramTransferTaskQueue;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_gfd_vram_load.c, prototypes copied from their definitions. */

#include "../types.h"

void NNSi_GfdLoadMainObjExtPltt(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadMainBgExtPltt(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadMainOam(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadMainObjChar(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBg0Char(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBg1Char(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBg2Char(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBg3Char(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBg0Scr(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBg1Scr(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBg2Scr(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBg3Scr(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBg2ScrAffine(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBg3ScrAffine(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubObjPltt(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBgPltt(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubObjExtPltt(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubBgExtPltt(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubOam(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdLoadSubObjChar(const void *pSrc, u32 offset, u32 szByte);
void NNSi_GfdRunVramTransferTask(NNSiGfdVramTransferTask *pTask);
void NNSi_GfdResetVramTransferTaskQueue(NNSiGfdVramTransferTaskQueue *pQueue);
int NNSi_GfdPushVramTransferTask(NNSiGfdVramTransferTaskQueue *pQueue);
u32 NNSi_GfdGetHeadVramTransferTask(NNSiGfdVramTransferTaskQueue *pQueue);
u32 NNSi_GfdGetTailVramTransferTask(NNSiGfdVramTransferTaskQueue *pQueue);
u32 NNSi_GfdPopVramTransferTask(NNSiGfdVramTransferTaskQueue *pQueue);
void NNS_GfdInitVramTransferTaskQueue(void *pTaskArray, u32 numTasks);
void NNS_GfdResetVramTransferTaskQueue(void);
/* END mkheaders: generated region */

#endif
