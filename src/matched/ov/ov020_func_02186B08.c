/*
 * function: func_02186B08
 * address: 0x02186B08
 * packet: pkt_ov020_02186B08
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02161ECC 0x02161ECC thumb ov010
 */

extern int func_02161ECC(char *p);
int func_02186B08(char *p) { int i; for (i = 0; i < 10; i++) { if (func_02161ECC(p + i * 24) == 0) return 0; } return 1; }
