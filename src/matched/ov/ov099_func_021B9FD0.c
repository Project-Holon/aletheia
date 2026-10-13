/*
 * function: WIFICLUBACTOR_HideMarkerActor
 * address:  0x021B9FD0
 * packet:   pkt_ov099_021B9FD0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb tail-call thunk in a .word run:
 *   ldr r0,[r0,#0x2c]; ldr r3,[pc,#4]; movs r1,#0; bx r3; .word 0x0204B3DC
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 */
#include "../include/Obj22013.h"

struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);

void WIFICLUBACTOR_HideMarkerActor(void *p)
{
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj22013 *)p)->f2C, 0);
}
