/*
 * function: func_02186878
 * address: 0x02186878
 * packet: pkt_ov020_02186878
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */

typedef unsigned short u16;
int func_02186878(u16 *p, u16 v, int i) { if (p[i] == 0xFFFF) { p[i] = v; return 1; } return 0; }
