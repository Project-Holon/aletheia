/*
 * unit:     no
 * function: NNS_G2dSetRendererTargetSurface
 * address:  0x02065B64
 * packet:   pkt_02065020
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj11548.h"
#include "../include/Obj16459.h"

void NNS_G2dSetRendererTargetSurface(int p0, void *p1){ ((struct Obj16459 *)p1)->f30 = (int)((struct Obj11548 *)p0)->f70; ((struct Obj11548 *)p0)->f70 = (int)p1; }
