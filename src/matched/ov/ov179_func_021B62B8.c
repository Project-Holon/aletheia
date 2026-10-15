/*
 * function: CDEMO_WIPE_StartFadeIn
 * address:  0x021B62B8
 * packet:   pkt_ov179_021B62B8
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SYS_Start  0x0202208C  thumb
 */
#include "../include/Obj24467.h"
typedef unsigned int u32;

extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

void CDEMO_WIPE_StartFadeIn(char *p, u32 a, u32 b, u32 c)
{
    WIPE_SYS_Start(0, 0, 0, 0, a, b, 0x7f);
    ((struct Obj24467 *)p)->f6054 = c;
}
