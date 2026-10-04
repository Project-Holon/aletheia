/*
 * function: func_021BCE9C
 * address: 0x021BCE9C
 * packet: pkt_ov091_021BCE9C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B1CC 0x0204B1CC arm
 */
struct Bank;
extern void func_0204B1CC(struct Bank *bank);
void func_021BCE9C(unsigned int p) { func_0204B1CC((struct Bank *)(*(unsigned int *)(p + 0x1EC))); }
