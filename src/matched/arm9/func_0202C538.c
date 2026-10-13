/*
 * function: ISS_SWITCH_Create
 * address:  0x0202C538
 * packet:   pkt_0202C538
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ISS_SWITCH_Alloc  0x0202C590  thumb
 *   ISS_SWITCH_Init  0x0202C5B4  thumb
 */

int ISS_SWITCH_Create(int a0){ int t0, t1; t0 = ISS_SWITCH_Alloc(a0); t1 = ISS_SWITCH_Init((int)t0); return ((t0 + 0) + 0); }
