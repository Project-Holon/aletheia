/*
 * function: func_021F3870
 * address: 0x021F3870
 * packet: pkt_ov048_021F3870
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F47BC 0x021F47BC thumb ov048
 */
struct M;
extern void func_021F47BC(struct M *p, int v);
void func_021F3870(int *p) { func_021F47BC((void *)p[5], p[6] << 12); }
