/*
 * function: WF2DMAP_OBJDRAW_GetActorValue
 * address:  0x021C5834
 * packet:   pkt_ov127_021C5834
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub: ldr r0,[r0,#4]; ldr r3,=WIFI_2DCHAR_GetActorDrawEnable; bx r3.
 * Blocker of ov099 func_021BA2D4.
 *
 * symbols:
 *   WIFI_2DCHAR_GetActorDrawEnable  0x021C425C  thumb  ov127
 */
#include "../include/Obj23049.h"

extern int WIFI_2DCHAR_GetActorDrawEnable(char *p);

int WF2DMAP_OBJDRAW_GetActorValue(char *p)
{
    return WIFI_2DCHAR_GetActorDrawEnable(((struct Obj23049 *)p)->f4);
}
