/*
 * function: func_021DAE04
 * address: 0x021DAE04
 * packet: pkt_ov093_021DAE04
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 */
extern int func_021D775C(int);
extern int func_021D76BC(int,unsigned int);
void func_021DAE04(int a, int b, int c, int *d) { unsigned short k; k = func_021D775C(18); *d = 0; if (k == 153 || k == 120) { if (func_021D775C(34) == 0) { *d = func_021D76BC(34,19); d[1] = k; } } }
