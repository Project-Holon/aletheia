/*
 * unit: yes
 * function: func_021DAC6C, func_021DAC84
 * address: 0x021DAC6C
 * packet: pkt_ov093_021DAC6C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0A10 0x021F0A10 data a4
 *   func_021D775C 0x021D775C thumb ov093
 */
extern const unsigned int d_021F0A10[];
extern int func_021D775C(int);
void func_021DAC6C(int a, int b, int c, int *d) { if (c == func_021D775C(2)) *d = 0; }
const unsigned int *func_021DAC84(int *n) { *n = 3; return d_021F0A10; }
