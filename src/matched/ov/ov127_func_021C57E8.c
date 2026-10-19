/*
 * function: WF2DMAP_OBJDRAW_StepActorAnim
 * address:  0x021C57E8
 * packet:   pkt_ov127_021C57E8
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub: ldr r0,[r0,#4]; ldr r3,=WIFI_2DCHAR_StepActorAnim; bx r3.
 * Blocker of ov099 func_021BA2D4.
 *
 * symbols:
 *   WIFI_2DCHAR_StepActorAnim  0x021C42C4  thumb  ov127
 */
#include "../include/Obj23047.h"

typedef unsigned char  u8;
extern void WIFI_2DCHAR_StepActorAnim(u8 *p);

void WF2DMAP_OBJDRAW_StepActorAnim(char *p)
{
    WIFI_2DCHAR_StepActorAnim(((struct Obj23047 *)p)->f4);
}
