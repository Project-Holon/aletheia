/*
 * unit:     no
 * function: NNSi_G2dGetVramHandleEx
 * address:  0x02063800
 * packet:   pkt_02063640
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

int NNSi_G2dGetVramHandleEx(char *p, int i){ return *(int *)(p + i * 4 + 8); }
