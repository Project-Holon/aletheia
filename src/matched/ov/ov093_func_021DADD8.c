/*
 * unit: yes
 * function: func_021DADD8, func_021DADF8
 * address: 0x021DADD8
 * packet: pkt_ov093_021DADD8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0B94 0x021F0B94 data a4
 *   func_021D775C 0x021D775C thumb ov093
 */
extern const unsigned int d_021F0B94[];
extern int func_021D775C(int);
void func_021DADD8(int a, int b, int c, int *d) { if (c == func_021D775C(2) && func_021D775C(12) == 7) *d = 0; }
const unsigned int *func_021DADF8(int *n) { *n = 4; return d_021F0B94; }
