/*
 * unit:     no
 * function: NNSi_FndResetFrmHeapHead
 * address:  0x020610A0
 * packet:   pkt_02060FA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj04082.h"

void NNSi_FndResetFrmHeapHead(void *p0){ ((struct Obj04082 *)p0)->f24 = (int)((struct Obj04082 *)p0)->f18; ((struct Obj04082 *)p0)->f2C = (int)0; }
