/*
 * unit:     no
 * function: POKEGRA_OpenTrainerHandle
 * address:  0x0202DA04
 * packet:   pkt_0202D6F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKEGRA_GetTrainerArcID  0x0202D5CC  thumb
 */

int POKEGRA_OpenTrainerHandle(int a0){ int t0 = POKEGRA_GetTrainerArcID((int)0); int t1 = func_020490F4((int)t0, (int)((a0 + 0) + 0)); return t1; }
