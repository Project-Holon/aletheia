/*
 * function: func_021DAD2C
 * address: 0x021DAD2C
 * packet: pkt_ov093_021DAD2C
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
void func_021DAD2C(int a, int b, int c, int *d) { if (c == func_021D775C(2)) { if (*d != 0) { d[1] = func_021D76BC(34,19); *d = 0; } else *d = 1; } }
