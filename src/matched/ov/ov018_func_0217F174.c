/*
 * function: INTRUDE_SUBDISP_StartButtonBlink
 * address: 0x0217F174
 * packet: pkt_ov018_0217F174
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 */
#include "../include/Obj09396.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
void INTRUDE_SUBDISP_StartButtonBlink(u8 *p)
{
    p[0x117] = 0;
    p[0x116] = 1;
    CLACT_SetActorPaletteOffset(((struct Obj09396 *)p)->f9C, 6, 1);
}
