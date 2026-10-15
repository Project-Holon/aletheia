/*
 * unit:     no
 * function: BUTTON_MAN_Func1A3C
 * address:  0x02051A3C
 * packet:   pkt_02051648
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_GfdDefaultAllocTexVram  0x020614D4  arm
 */

unsigned int BUTTON_MAN_Func1A3C(int a0, int a1, int a2, int a3){ int t0 = NNSi_GfdDefaultAllocTexVram((int)a0, (int)a1, (int)0); return ((unsigned int)((t0 << 0x10)) >> 0xd); }
