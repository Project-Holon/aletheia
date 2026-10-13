/*
 * function: ISS_SWITCH_SYS_IsSwitchOn
 * address:  0x0202C0F8
 * packet:   pkt_0202C0F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ISS_SWITCH_SYS_GetActiveSet  0x0202C24C  thumb
 *   ISS_SWITCH_SET_IsSwitchOn  0x0202C350  thumb
 */

int ISS_SWITCH_SYS_IsSwitchOn(int a0, int a1){ int t0, t1; t0 = ISS_SWITCH_SYS_GetActiveSet(a0); if ((unsigned int)(t0) != (unsigned int)(0)) { t1 = ISS_SWITCH_SET_IsSwitchOn((int)t0, (int)((a1 + 0) + 0)); return t1; } else { return 0; } }
