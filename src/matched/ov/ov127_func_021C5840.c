/*
 * function: WF2DMAP_OBJDRAW_SetActorDrawEnable
 * address:  0x021C5840
 * packet:   pkt_ov127_021C5840
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub: ldr r0,[r0,#4]; ldr r3,=WIFI_2DCHAR_SetActorDrawEnable; bx r3.
 * (ov093 labels a different function at this address.)
 * Blocker of ov099 func_021BA2D4.
 *
 * symbols:
 *   WIFI_2DCHAR_SetActorDrawEnable  0x021C4230  thumb  ov127
 */
#include "../include/Obj23050.h"

extern void WIFI_2DCHAR_SetActorDrawEnable(char *p, int a);

void WF2DMAP_OBJDRAW_SetActorDrawEnable(char *p, int a)
{
    WIFI_2DCHAR_SetActorDrawEnable(((struct Obj23050 *)p)->f4, a);
}
