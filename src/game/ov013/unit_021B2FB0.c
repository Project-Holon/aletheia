/*
 * file:     unit_021B2FB0.c
 * unit:     yes
 * function: VCT_POOL_AllocFrame, VCT_POOL_FreeFrame
 * address:  0x021B2FB0
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gVoiceFramePool 0x021B4C24 data a4
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 */
#include "vct_types.h"

extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int);
VctRxPacket *VCT_POOL_AllocFrame(void);
void VCT_POOL_FreeFrame(VctRxPacket *frame);

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
