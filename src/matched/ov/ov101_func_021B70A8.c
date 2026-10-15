/*
 * function: IRC_COMPATIBLE_CalcBirthdayScore
 * address: 0x021B70A8
 * packet: pkt_ov101_021B70A8
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   IRC_RANKING_GetDateScore 0x0200AA00 thumb
 */
struct Date { unsigned a,b,c,d; }; extern unsigned char IRC_RANKING_GetDateScore(unsigned,unsigned,struct Date *);
unsigned char IRC_COMPATIBLE_CalcBirthdayScore(unsigned char *p,unsigned x) { struct Date d; d.a=(unsigned char)(x>>24); d.b=(unsigned char)(x>>16); d.c=(unsigned char)(x>>8); d.d=(unsigned char)x; return IRC_RANKING_GetDateScore(p[4],p[5],&d); }
