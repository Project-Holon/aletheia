/*
 * function: func_02177AA8
 * address: 0x02177AA8
 * packet: pkt_ov014_02177AA8
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021797A4 0x021797A4 data ov014 a4
 *   func_02178E4C 0x02178E4C thumb ov014
 */

extern unsigned char *g_021797A4;
extern int func_02178E4C(void);
int func_02177AA8(void) { if (g_021797A4 != 0) { if (func_02178E4C() == 1) return 1; return 0; } return 1; }
