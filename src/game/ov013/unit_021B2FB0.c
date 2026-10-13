/*
 * file:     unit_021B2FB0.c
 * unit:     yes
 * function: func_021B2FB0, VCT_POOL_FreeFrame
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
 *   d_021B4C24 0x021B4C24 data a4
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 */
#include "vct_types.h"

extern int func_02087988(void);
extern void func_0208799C(int);
VctRxPacket *func_021B2FB0(void);
void VCT_POOL_FreeFrame(VctRxPacket *frame);

/* Take a frame buffer from the free list, or return 0 when the pool is empty. */
VctRxPacket *func_021B2FB0(void)
{
    VctRxPacket *result=0;
    int irq=func_02087988();
    if(d_021B4C24.freeHead != 0) {
        result=d_021B4C24.freeHead;
        d_021B4C24.freeHead=d_021B4C24.freeHead->freeLink;
    }
    func_0208799C(irq);
    return result;
}

/* Clear the list links of a frame buffer and put it back on the free list. */
void VCT_POOL_FreeFrame(VctRxPacket *frame)
{
    int irq=func_02087988();
    frame->freeLink=d_021B4C24.freeHead;
    d_021B4C24.freeHead=frame;
    frame->prev=0;
    frame->next=0;
    func_0208799C(irq);
}
