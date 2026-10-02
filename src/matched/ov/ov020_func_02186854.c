/*
 * function: func_02186854
 * address: 0x02186854
 * packet: pkt_ov020_02186854
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */

typedef unsigned short u16;
int func_02186854(u16 *p) { int i; int n; n = 0; for (i = 0; i < 10; i++) { if (p[i] != 0xFFFF) n++; } return n; }
