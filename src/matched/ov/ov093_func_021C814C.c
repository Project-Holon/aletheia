/*
 * function: func_021C814C
 * address: 0x021C814C
 * packet: pkt_ov093_021C814C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: ov095 D588 forwards the same table pointer and key to D5C8;
 * original keeps r1 live and has no narrowing, so retain a full-word key.
 * symbols:
 *   func_0689D588 0x0689D588 thumb ov095
 */
typedef unsigned char u8;
extern int func_0689D588(u8 *, int);
int func_021C814C(u8 *p, int v) { return func_0689D588(p+0x1ab8,v); }
