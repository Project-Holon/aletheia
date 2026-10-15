/*
 * unit:     no
 * function: NNSi_G2dSetVramHandleEx
 * address:  0x020637F4
 * packet:   pkt_02063640
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

void NNSi_G2dSetVramHandleEx(char *p, int i, int v){ *(int *)(p + i * 4 + 8) = v; }
