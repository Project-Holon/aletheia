/*
 * function: func_021861BC
 * address: 0x021861BC
 * packet: pkt_ov020_021861BC
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02161E84 0x02161E84 thumb ov010
 */
extern int func_02161E84(char *);
int func_021861BC(unsigned short *p) { char *q; int i; if(p[0]==1 && p[1]>=2) return 0; q=(char *)p; i=0; q+=8; for(;i<10;i++) if(func_02161E84(q+i*0x18)==0) return 0; return 1; }
