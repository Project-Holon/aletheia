/*
 * function: func_021F0DC0
 * address: 0x021F0DC0
 * packet: pkt_ov032_021F0DC0
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02165E24 0x02165E24 thumb ov010
 */
extern unsigned short func_02165E24(void *);
int func_021F0DC0(void *p) { int a; a=func_02165E24(p); if(a==0 || a>=0x33) return 0x12; return a+0x11; }
