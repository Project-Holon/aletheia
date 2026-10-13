/*
 * function: TOWNMAP_CursorGetPos
 * address: 0x021BA3BC
 * packet: pkt_ov072_021BA3BC
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: trailing two-byte alignment padding.
 */
#include "../include/Obj13194.h"
void TOWNMAP_CursorGetPos(char *p, int *q) {
    q[0] = ((struct Obj13194 *)p)->f8;
    q[1] = ((struct Obj13194 *)p)->fA;
}
