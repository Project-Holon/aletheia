/*
 * function: func_021C831C
 * address: 0x021C831C
 * packet: pkt_ov093_021C831C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: add the byte index to the base before applying the constant offset.
 */
typedef unsigned char u8;
void func_021C831C(u8 *p, int v) { unsigned int n; n=p[0x788]; if(n<6) { p[0x788]=n+1; (p+n)[0x78b]=v; } }
