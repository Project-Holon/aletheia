/*
 * function: WIFI_2DCHAR_GetActorDrawEnable
 * address:  0x021C425C
 * packet:   pkt_ov127_021C425C
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub: ldr r0,[r0,#4]; ldr r3,=0x0204B3F4; bx r3.
 * Leaf of ov127 WF2DMAP_OBJDRAW_GetActorValue (blocker of ov099 func_021BA2D4).
 *
 * symbols:
 *   CLACT_GetActorDrawEnable  0x0204B3F4  arm
 */
#include "../include/Obj23016.h"

typedef unsigned int   u32;
struct Obj;
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);

int WIFI_2DCHAR_GetActorDrawEnable(char *p)
{
    return CLACT_GetActorDrawEnable(((struct Obj23016 *)p)->f4);
}
