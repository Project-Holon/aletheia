/*
 * function: CircleGraph_Draw
 * address:  0x021C112C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CircleGraph_DrawSlices  0x021C124C  thumb  ov217
 *   CircleGraph_DrawOutline  0x021C13E8  thumb  ov217
 *   CircleGraph_SetupCamera  0x021C14DC  thumb  ov217
 *   CircleGraph_IsEnabled  0x021C1D24  thumb  ov217
 *
 * When CircleGraph_IsEnabled() reports 1 and the +8 field is set, runs the
 * +0x3C update triplet.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj26006.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void CircleGraph_DrawSlices(u8 *p);
struct Big;
extern void CircleGraph_DrawOutline(struct Big *p);
extern void CircleGraph_SetupCamera(u8 *p);
extern u32 CircleGraph_IsEnabled(void *);
void CircleGraph_Draw(u8 *p)
{
    if (CircleGraph_IsEnabled(p) == 1) {
    if (((struct Obj26006 *)p)->f8 != 0) {
    CircleGraph_SetupCamera(p);
    CircleGraph_DrawSlices(p);
    CircleGraph_DrawOutline((struct Big *)p);
    }
    }
}
