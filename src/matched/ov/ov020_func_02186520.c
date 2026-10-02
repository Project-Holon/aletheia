/*
 * function: func_02186520
 * address: 0x02186520
 * packet: pkt_ov020_02186520
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02186AC8 0x02186AC8 thumb ov020
 */
extern void func_02186AC8(char *, int, char *, int);
void func_02186520(char *p, int b, char *c) { if (*(unsigned short *)(p + 2) == 0) func_02186AC8(p,b,c,1); else func_02186AC8(p,b,c,0); }
