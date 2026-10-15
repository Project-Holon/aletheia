/*
 * unit:     no
 * function: NNSi_GfdSetVramManagerWork
 * address:  0x02061824
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj11496.h"

void NNSi_GfdSetVramManagerWork(void *p0){ *(int *)(0x2146B74) = (int)((struct Obj11496 *)p0)->f0; *(int *)((0x2146B74 + 4)) = (int)((struct Obj11496 *)p0)->f4; }
