/*
 * function: WF2DMAP_OBJDRAW_GetActorDrawPriority
 * address:  0x021C5858
 * packet:   pkt_ov127_021C5858
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled accessor veneer after WF2DMAP_OBJDRAW_SetActorValue2 (`ldr r0,[r0,#4]; ldr r3,=
 * WIFI_2DCHAR_GetActorDrawPriority; bx r3`).  Blocker of ov099 func_021B989C.
 *
 * symbols:
 *   WIFI_2DCHAR_GetActorDrawPriority  0x021C4224  thumb  ov127
 */
#include "../include/Obj23052.h"

typedef unsigned char u8;

extern int WIFI_2DCHAR_GetActorDrawPriority(u8 *p);

int WF2DMAP_OBJDRAW_GetActorDrawPriority(u8 *p)
{
    return WIFI_2DCHAR_GetActorDrawPriority(((struct Obj23052 *)p)->f4);
}
