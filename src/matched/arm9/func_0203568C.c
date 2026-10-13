/*
 * unit:     no
 * function: UI_GetPowerState
 * address:  0x0203568C
 * packet:   pkt_0203568C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

int UI_GetPowerState(void){ return *(unsigned char *)((*(int *)(0x21469BC) + 63)); }
