/*
 * file:     nns_gfd_vram_load.c
 * unit:     yes
 * function: NNSi_GfdLoadMainObjExtPltt, NNSi_GfdLoadMainBgExtPltt, NNSi_GfdLoadMainOam, NNSi_GfdLoadMainObjChar, NNSi_GfdLoadSubBg0Char, NNSi_GfdLoadSubBg1Char, NNSi_GfdLoadSubBg2Char, NNSi_GfdLoadSubBg3Char, NNSi_GfdLoadSubBg0Scr, NNSi_GfdLoadSubBg1Scr, NNSi_GfdLoadSubBg2Scr, NNSi_GfdLoadSubBg3Scr, NNSi_GfdLoadSubBg2ScrAffine, NNSi_GfdLoadSubBg3ScrAffine, NNSi_GfdLoadSubObjPltt, NNSi_GfdLoadSubBgPltt, NNSi_GfdLoadSubObjExtPltt, NNSi_GfdLoadSubBgExtPltt, NNSi_GfdLoadSubOam, NNSi_GfdLoadSubObjChar, NNSi_GfdRunVramTransferTask, NNSi_GfdResetVramTransferTaskQueue, NNSi_GfdPushVramTransferTask, NNSi_GfdGetHeadVramTransferTask, NNSi_GfdGetTailVramTransferTask, NNSi_GfdPopVramTransferTask, NNS_GfdInitVramTransferTaskQueue, NNS_GfdResetVramTransferTaskQueue
 * address:  0x020619BC
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NitroSystem gfd VRAM load functions (one per destination: OAM, character,
 * screen, palette, extended palette, main and sub engine), and the ring
 * buffer that holds the registered VRAM transfer tasks.
 *
 * Own object: EXACT only with ../2.0/sp2; DIFF with 1.1p1 and dsi/1.2 (the
 * builds of nns_gfd_vram_transfer.c next to it) and with ../1.2/sp2.
 *
 * symbols:
 *   gNNSiGfdVramLoadFuncTable     0x020A1718  data
 *   DC_FlushRange  0x020862F0  arm
 *   NNSi_GfdRingIsEmpty  0x02061878  arm
 *   NNSi_GfdRingNextIndex  0x02061840  arm
 *   sVramTransferTaskQueue     0x02146B80  data
 *   g_02146B80_cb  0x02146B80  data
 *   NNSi_GfdRingIsFull  0x02061860  arm
 *   GX_LoadOAM  0x0207E684  arm
 *   GXS_LoadOAM  0x0207E708  arm
 *   GXS_LoadBGPltt  0x0207E468  arm
 *   GXS_LoadOBJPltt  0x0207E5D0  arm
 *   GX_LoadOBJ  0x0207E780  arm
 *   GXS_LoadOBJ  0x0207E804  arm
 *   GXS_LoadBG0Scr  0x0207E944  arm
 *   GXS_LoadBG1Scr  0x0207EABC  arm
 *   GXS_LoadBG2Scr  0x0207EC34  arm
 *   GXS_LoadBG3Scr  0x0207EDAC  arm
 *   GXS_LoadBG1Char  0x0207F024  arm
 *   GXS_LoadBG2Char  0x0207F14C  arm
 *   GXS_LoadBG3Char  0x0207F274  arm
 *   GX_BeginLoadBGExtPltt  0x0207F308  arm
 *   GX_LoadBGExtPltt  0x0207F394  arm
 *   GX_EndLoadBGExtPltt  0x0207F428  arm
 *   GX_BeginLoadOBJExtPltt  0x0207F47C  arm
 *   GX_LoadOBJExtPltt  0x0207F4C4  arm
 *   GX_EndLoadOBJExtPltt  0x0207F560  arm
 *   GXS_BeginLoadBGExtPltt  0x0207F5B0  arm
 *   GXS_LoadBGExtPltt  0x0207F5C8  arm
 *   GXS_EndLoadBGExtPltt  0x0207F65C  arm
 *   GXS_BeginLoadOBJExtPltt  0x0207F6A8  arm
 *   GXS_LoadOBJExtPltt  0x0207F6C0  arm
 *   GXS_EndLoadOBJExtPltt  0x0207F754  arm
 */

#include "../types.h"

/* Loader for one VRAM destination: (source, destination offset, byte size). */
typedef void (*NNSiGfdVramLoadFunc)(u32 pSrc, u32 offset, u32 szByte);

/* One registered transfer task (0x10 bytes): taskType indexes the loader table. */
typedef struct {
    u32 taskType;
    u32 pSrc;
    u32 offset;
    u32 szByte;
} NNSiGfdVramTransferTask;

/* Ring buffer of transfer tasks, with the running byte total of the queued tasks. */
typedef struct {
    u32 pTaskArray;
    u32 numTasks;
    u16 head;
    u16 tail;
    u16 count;
    u16 pad0E;
    s32 totalSzByte;
} NNSiGfdVramTransferTaskQueue;

#include "gx_load2d.h"
#include "os_cache.h"
#include "nns_gfd_vram_man.h"
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
extern NNSiGfdVramLoadFunc gNNSiGfdVramLoadFuncTable[];
extern NNSiGfdVramTransferTaskQueue sVramTransferTaskQueue;
extern NNSiGfdVramTransferTaskQueue g_02146B80_cb;

void NNSi_GfdLoadMainObjExtPltt(const void *pSrc, u32 offset, u32 szByte)
{
    GX_BeginLoadOBJExtPltt();
    GX_LoadOBJExtPltt(pSrc, offset, szByte);
    GX_EndLoadOBJExtPltt();
}

void NNSi_GfdLoadMainBgExtPltt(const void *pSrc, u32 offset, u32 szByte)
{
    GX_BeginLoadBGExtPltt();
    GX_LoadBGExtPltt(pSrc, offset, szByte);
    GX_EndLoadBGExtPltt();
}

void NNSi_GfdLoadMainOam(const void *pSrc, u32 offset, u32 szByte)
{
    GX_LoadOAM(pSrc, offset, szByte);
}

void NNSi_GfdLoadMainObjChar(const void *pSrc, u32 offset, u32 szByte)
{
    GX_LoadOBJ(pSrc, offset, szByte);
}

void NNSi_GfdLoadSubBg0Char(const void *pSrc, u32 offset, u32 szByte)
{
    GXS_LoadBG0Char(pSrc, offset, szByte);
}

void NNSi_GfdLoadSubBg1Char(const void *pSrc, u32 offset, u32 szByte)
{
    GXS_LoadBG1Char(pSrc, offset, szByte);
}

void NNSi_GfdLoadSubBg2Char(const void *pSrc, u32 offset, u32 szByte)
{
    GXS_LoadBG2Char(pSrc, offset, szByte);
}

void NNSi_GfdLoadSubBg3Char(const void *pSrc, u32 offset, u32 szByte)
{
    GXS_LoadBG3Char(pSrc, offset, szByte);
}

void NNSi_GfdLoadSubBg0Scr(const void *pSrc, u32 offset, u32 szByte)
{
    GXS_LoadBG0Scr(pSrc, offset, szByte);
}

void NNSi_GfdLoadSubBg1Scr(const void *pSrc, u32 offset, u32 szByte)
{
    GXS_LoadBG1Scr(pSrc, offset, szByte);
}

void NNSi_GfdLoadSubBg2Scr(const void *pSrc, u32 offset, u32 szByte)
{
    GXS_LoadBG2Scr(pSrc, offset, szByte);
}

void NNSi_GfdLoadSubBg3Scr(const void *pSrc, u32 offset, u32 szByte)
{
    GXS_LoadBG3Scr(pSrc, offset, szByte);
}

void NNSi_GfdLoadSubBg2ScrAffine(const void *pSrc, u32 offset, u32 szByte)
{
    GXS_LoadBG2Scr(pSrc, offset, szByte);
}

void NNSi_GfdLoadSubBg3ScrAffine(const void *pSrc, u32 offset, u32 szByte)
{
    GXS_LoadBG3Scr(pSrc, offset, szByte);
}

void NNSi_GfdLoadSubObjPltt(const void *pSrc, u32 offset, u32 szByte)
{
    GXS_LoadOBJPltt(pSrc, offset, szByte);
}

void NNSi_GfdLoadSubBgPltt(const void *pSrc, u32 offset, u32 szByte)
{
    GXS_LoadBGPltt(pSrc, offset, szByte);
}

void NNSi_GfdLoadSubObjExtPltt(const void *pSrc, u32 offset, u32 szByte)
{
    GXS_BeginLoadOBJExtPltt();
    GXS_LoadOBJExtPltt(pSrc, offset, szByte);
    GXS_EndLoadOBJExtPltt();
}

void NNSi_GfdLoadSubBgExtPltt(const void *pSrc, u32 offset, u32 szByte)
{
    GXS_BeginLoadBGExtPltt();
    GXS_LoadBGExtPltt(pSrc, offset, szByte);
    GXS_EndLoadBGExtPltt();
}

void NNSi_GfdLoadSubOam(const void *pSrc, u32 offset, u32 szByte)
{
    GXS_LoadOAM(pSrc, offset, szByte);
}

void NNSi_GfdLoadSubObjChar(const void *pSrc, u32 offset, u32 szByte)
{
    GXS_LoadOBJ(pSrc, offset, szByte);
}

/*
 * Run one transfer task: fetch the loader gNNSiGfdVramLoadFuncTable[taskType] first,
 * flush the source range (DC_FlushRange = DC_FlushRange on pSrc, szByte), then
 * call the loader with (pSrc, offset, szByte). The re-read tell
 * (docs/FRONTEND-PINS.md): the image reloads all three fields after the first
 * call with one `ldmib r5, {r0, r1, r2}`; 1.1p1 keeps szByte live from the
 * first call's argument and emits `ldr r2, [r5, #0xc]` plus a two-register
 * ldmib (52 bytes, 20 out). Under ../2.0/sp2 the same C is 44 bytes.
 */
void NNSi_GfdRunVramTransferTask(NNSiGfdVramTransferTask *pTask)
{
    NNSiGfdVramLoadFunc loadFunc = gNNSiGfdVramLoadFuncTable[pTask->taskType];
    DC_FlushRange((void *)(pTask->pSrc), pTask->szByte);
    loadFunc(pTask->pSrc, pTask->offset, pTask->szByte);
}

/* Reset the queue: head, tail, count and the running byte total. */
void NNSi_GfdResetVramTransferTaskQueue(NNSiGfdVramTransferTaskQueue *pQueue)
{
    pQueue->tail = 0;
    pQueue->head = 0;
    pQueue->count = 0;
    pQueue->totalSzByte = 0;
}

/* Push: advance the tail and count (volatile accesses keep the halfword loads and stores). Returns 0 when full. */
int NNSi_GfdPushVramTransferTask(NNSiGfdVramTransferTaskQueue *pQueue)
{
    int next;
    if (NNSi_GfdRingIsFull((u8 *)pQueue))
        return 0;
    next = NNSi_GfdRingNextIndex((u8 *)pQueue, pQueue->tail);
    *(volatile u16 *)&pQueue->tail = (u16)next;
    *(volatile u16 *)&pQueue->count = (u16)(*(volatile u16 *)&pQueue->count + 1);
    return 1;
}

/* Address of the head task: base plus the head index scaled by the task size (0x10). */
u32 NNSi_GfdGetHeadVramTransferTask(NNSiGfdVramTransferTaskQueue *pQueue)
{
    return pQueue->pTaskArray + ((u32)pQueue->head << 4);
}

/* Address of the tail slot (where the next task is written): base plus the tail index scaled by 0x10. */
u32 NNSi_GfdGetTailVramTransferTask(NNSiGfdVramTransferTaskQueue *pQueue)
{
    return pQueue->pTaskArray + ((u32)pQueue->tail << 4);
}

/*
 * Pop: advance the head and decrement the count. Returns 0 when empty.
 * The load/store interleave tell of the 2.0 front end: the image stores the
 * call result (`strh r0, [r4, #8]`) before loading the counter
 * (`ldrh r1, [r4, #0xc]`); 1.1p1 hoists the load above the store (6 bytes
 * out).
 */
u32 NNSi_GfdPopVramTransferTask(NNSiGfdVramTransferTaskQueue *pQueue)
{
    if (NNSi_GfdRingIsEmpty(pQueue) != 0) {
        return 0;
    }
    pQueue->head = NNSi_GfdRingNextIndex((u8 *)pQueue, pQueue->head);
    pQueue->count -= 1;
    return 1;
}

/*
 * NNS_GfdInitVramTransferTaskQueue: install the task array base and capacity
 * into the queue object at 0x02146B80 and tail-call NNSi_GfdResetVramTransferTaskQueue on it (the
 * `ldr ip` / `bx ip` pair rather than a `b`). The same queue is the one
 * NNS_GfdRegisterNewVramTransferTask pushes onto.
 *
 * Why 0x02146B80 costs two pool words: written as one symbol, mwcc
 * common-subexpressions the two references and emits `mov r0, r2` where the
 * original emits a second `ldr r0, [pc]`. `volatile`, an address-of-member
 * argument and casts all still CSE; two distinct declarations at the address
 * are the only spelling that reproduces the pair: `g_02146B80_cb` for the
 * array/capacity stores and `sVramTransferTaskQueue` for the queue the tail
 * call takes. A static helper makes it worse (a real tail call plus an `stm`
 * the original does not have).
 */
void NNS_GfdInitVramTransferTaskQueue(void *pTaskArray, u32 numTasks)
{
    g_02146B80_cb.pTaskArray = (u32)pTaskArray;
    g_02146B80_cb.numTasks = numTasks;
    NNSi_GfdResetVramTransferTaskQueue(&sVramTransferTaskQueue);
}

/*
 * NNS_GfdResetVramTransferTaskQueue: unlabelled tail-call stub right after
 * NNS_GfdInitVramTransferTaskQueue (the same tail call to NNSi_GfdResetVramTransferTaskQueue without the two stores).
 * Front-end tell: the image issues the callee pool load first
 * (`ldr ip, [pc, #4]`), then `ldr r0, [pc, #4]`; the other front ends
 * schedule the pool load after the argument write (8 bytes out). Same
 * ../2.0/sp2 pin as NNSi_GfdPopVramTransferTask. Witness for ov131 P_STATUS_ExitGraphics.
 */
void NNS_GfdResetVramTransferTaskQueue(void)
{
    NNSi_GfdResetVramTransferTaskQueue(&sVramTransferTaskQueue);
}
