/*
 * unit:     no
 * function: NNSi_FndGetMBlockSize
 * address:  0x02060F90
 * packet:   pkt_02060CD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

int NNSi_FndGetMBlockSize(char *p){ return *(int *)(p - 0xc); }
