/*
 * unit:     no
 * function: POKEGRA_OpenHandle
 * address:  0x0202D7C8
 * packet:   pkt_0202D6F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKEGRA_GetArcID  0x0202D060  thumb
 */

int POKEGRA_OpenHandle(int a0){ int t0 = POKEGRA_GetArcID(); int t1 = func_020490F4((int)t0, (int)((a0 + 0) + 0)); return t1; }
