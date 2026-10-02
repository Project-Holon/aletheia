/*
 * function: func_02186A2C
 * address: 0x02186A2C
 * packet: pkt_ov020_02186A2C
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02186A58 0x02186A58 thumb ov020
 */

extern int func_02186A58(char *p, int id);
int func_02186A2C(char *p, int id) { int i; int n; n = 0; for (i = 0; i < 30; i++) { if (func_02186A58(p, i) == 0) { if (n == id) return i; n++; } } return 0; }
