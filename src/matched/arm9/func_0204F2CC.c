/*
 * unit:     no
 * function: BILLBOARD_GetImagePlttVramOffset
 * address:  0x0204F2CC
 * packet:   pkt_0204E8C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 */
#include "../include/Obj16128.h"
#include "../include/Obj16129.h"

void BILLBOARD_GetImagePlttVramOffset(int p0, int p1, int p2){ ((struct Obj16129 *)p2)->f0 = (int)*(int *)(((p1 * 0x28 + ((struct Obj16128 *)p0)->f4) + 16)); }
