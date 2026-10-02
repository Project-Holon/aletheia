/*
 * function: func_021F3CF4
 * address: 0x021F3CF4
 * packet: pkt_ov055_021F3CF4
 * region: ov055
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F45C0 0x021F45C0 data a4
 */
extern void (*d_021F45C0[])(unsigned char *,unsigned int,unsigned int);
void func_021F3CF4(unsigned char *p,unsigned int a,unsigned int b) { if (p[0]) d_021F45C0[p[2]](p,a,b); }
