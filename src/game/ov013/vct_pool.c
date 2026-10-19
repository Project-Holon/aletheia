/*
 * file:     vct_pool.c
 * unit:     yes
 * function: VCT_POOL_InitFrames, VCT_POOL_Reset, VCT_POOL_AllocFrame, VCT_POOL_FreeFrame
 * address:  0x021B2ED8
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from vct_audio.c, vct_session.c by tools/splitfile.py.
 *
 * symbols:
 *   VCT_POOL_AllocFrame  0x021B2FB0  arm  ov013
 *   VCT_POOL_FreeFrame  0x021B2FE4  arm  ov013
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   gVoiceFramePool 0x021B4C24 data a4
 *   MIi_CpuClearFast 0x02082AC0 arm
 */
#include "vct_types.h"
#include "vct_audio_shared_types.h"

extern OSIntrMode OS_DisableInterrupts(void);

extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);

extern void MIi_CpuClearFast(int, void *, u32);

int VCT_POOL_InitFrames(VctRxPacket *buffer, u32 size);

void VCT_POOL_Reset(void);

VctRxPacket *VCT_POOL_AllocFrame(void);

void VCT_POOL_FreeFrame(VctRxPacket *frame);

/*
 * lever: fill call takes data, p and b; r1/r2 stay live across the guards.
 */
/* Set up the frame buffer pool over a 32 byte aligned area of 4 to 72 frames and chain the free list. */
int VCT_POOL_InitFrames(VctRxPacket *buffer, u32 size)
{
    u32 i;
    u32 count;
    VctRxPacket *area;
    count = size / 0x478;
    area = buffer;
    gVoiceFramePool.base = area;
    if (count < 4 || count > 0x48) return 0;
    if (area == 0) return 0;
    if ((u32)area & 0x1f) {
        gVoiceFramePool.base = 0;
        return 0;
    }
    i = 0;
    MIi_CpuClearFast(i, area, size);
    for (i = 0; i < count - 1; i++)
        gVoiceFramePool.base[i].freeLink = &gVoiceFramePool.base[i + 1];
    (gVoiceFramePool.base + count)[-1].freeLink = 0;
    gVoiceFramePool.freeHead = gVoiceFramePool.base;
    return 1;
}

/* Forget the frame buffer area of the frame pool. */
void VCT_POOL_Reset(void)
{
    gVoiceFramePool.freeHead = 0;
    gVoiceFramePool.base = 0;
}

/* Take a frame buffer from the free list, or return 0 when the pool is empty. */
VctRxPacket *VCT_POOL_AllocFrame(void)
{
    VctRxPacket *result=0;
    int irq=OS_DisableInterrupts();
    if(gVoiceFramePool.freeHead != 0) {
        result=gVoiceFramePool.freeHead;
        gVoiceFramePool.freeHead=gVoiceFramePool.freeHead->freeLink;
    }
    OS_RestoreInterrupts(irq);
    return result;
}

/* Clear the list links of a frame buffer and put it back on the free list. */
void VCT_POOL_FreeFrame(VctRxPacket *frame)
{
    int irq=OS_DisableInterrupts();
    frame->freeLink=gVoiceFramePool.freeHead;
    gVoiceFramePool.freeHead=frame;
    frame->prev=0;
    frame->next=0;
    OS_RestoreInterrupts(irq);
}
