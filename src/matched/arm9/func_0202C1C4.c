/*
 * function: ISS_SWITCH_SYS_UpdateActiveSet
 * address:  0x0202C1C4
 * packet:   pkt_0202C148
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ISS_SWITCH_SYS_GetActiveSet  0x0202C24C  thumb
 *   ISS_SWITCH_SET_Main  0x0202C320  thumb
 */

int ISS_SWITCH_SYS_UpdateActiveSet(int a0){ int t0, t1; t0 = ISS_SWITCH_SYS_GetActiveSet(a0); if ((unsigned int)(t0) != (unsigned int)(0)) { t1 = ISS_SWITCH_SET_Main((int)t0); return t1; } else { return t0; } }
