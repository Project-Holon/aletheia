/*
 * function: func_02157700
 * address: 0x02157700
 * packet: pkt_ov010_02157700
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_021727F0 0x021727F0 data a4
 */
extern void func_02034714(void *, int, void *);
extern char d_021727F0[];
void func_02157700(int *p) { if (p[2] != 0 && p[2] >= 0x5e8) func_02034714(d_021727F0, 0, d_021727F0); }
