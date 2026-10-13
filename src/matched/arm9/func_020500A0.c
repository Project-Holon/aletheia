/*
 * unit:     no
 * function: BILLBOARD_ACT_ResetPlayback
 * address:  0x020500A0
 * packet:   pkt_0204F5A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj02611.h"

void BILLBOARD_ACT_ResetPlayback(int p0){ ((struct Obj02611 *)p0)->f10 = (unsigned short)0; ((struct Obj02611 *)p0)->f12 = (unsigned short)0; ((struct Obj02611 *)p0)->f14 = (unsigned short)0; ((struct Obj02611 *)p0)->f1C = (unsigned short)0; }
