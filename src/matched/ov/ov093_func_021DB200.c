/*
 * function: func_021DB200
 * address: 0x021DB200
 * packet: pkt_ov093_021DB200
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7324 0x021D7324 thumb ov093
 */
extern int func_021D775C(int);
extern void func_021D7324(char *);
void func_021DB200(char *a, int b, int c, int *d) { if (c == func_021D775C(2) && *d == 1) { func_021D7324(a); *d = 0; } }
