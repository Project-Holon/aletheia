/*
 * unit:     no
 * function: NNSi_G2dIsVramHandleSetEx
 * address:  0x0206380C
 * packet:   pkt_0206380C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Neighbour of NNSi_G2dGetVramHandleEx (same accessor family): that one returns the
 * slot's raw word, this one reports whether the slot is occupied, i.e. not
 * the sentinel -1.
 */

int NNSi_G2dIsVramHandleSetEx(char *p, int i){ int v = *(int *)(p + i * 4 + 8); int s = -1; return v != s; }
