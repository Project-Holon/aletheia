/*
 * function: func_021F0668
 * address: 0x021F0668
 * packet: pkt_ov032_021F0668
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B98C 0x0204B98C arm
 */
typedef unsigned int u32;
struct Actor;
extern u32 func_0204B98C(struct Actor *);
int func_021F0668(char *p, int i) { return func_0204B98C(*(struct Actor **)(p + i * 4 + 0x2bc)); }
