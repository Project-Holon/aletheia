/*
 * unit: yes
 * function: func_021DB224, func_021DB248
 * address: 0x021DB224
 * packet: pkt_ov093_021DB224
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0C24 0x021F0C24 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7324 0x021D7324 thumb ov093
 */
extern const unsigned int d_021F0C24[];
extern int func_021D775C(int);
typedef unsigned char  u8;
extern void func_021D7324(u8 *p);
void func_021DB224(char *a, int b, int c, int *d) { if (c == func_021D775C(2) && *d == 1) { func_021D7324((u8 *)a); *d = 0; } }
const unsigned int *func_021DB248(int *n) { *n = 5; return d_021F0C24; }
