/*
 * function: func_021B70A8
 * address: 0x021B70A8
 * packet: pkt_ov101_021B70A8
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0200AA00 0x0200AA00 thumb
 */
struct Date { unsigned a,b,c,d; }; extern unsigned char func_0200AA00(unsigned,unsigned,struct Date *);
unsigned char func_021B70A8(unsigned char *p,unsigned x) { struct Date d; d.a=(unsigned char)(x>>24); d.b=(unsigned char)(x>>16); d.c=(unsigned char)(x>>8); d.d=(unsigned char)x; return func_0200AA00(p[4],p[5],&d); }
