/*
 * unit:     no
 * function: BILLBOARD_SetElemCell
 * address:  0x0204F66C
 * packet:   pkt_0204F5A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj16141.h"
#include "../include/Obj16142.h"

void BILLBOARD_SetElemCell(int p0, int p1, int p2){ *(unsigned short *)(((p1 * 0x1c + ((struct Obj16141 *)p0)->f8) + 16)) = (unsigned short)((struct Obj16142 *)p2)->f0; }
