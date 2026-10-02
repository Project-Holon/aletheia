/*
 * function: func_021C7F24
 * address: 0x021C7F24
 * packet: pkt_ov093_021C7F24
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C7FCC 0x021C7FCC thumb ov093
 *   func_021C7F04 0x021C7F04 thumb ov093
 *   func_021B9BC4 0x021B9BC4 thumb ov093
 */
typedef unsigned char u8;
extern char *func_021C7FCC(u8 *, int);
extern int func_021C7F04(u8 *, int);
extern u8 func_021B9BC4(u8 *, int);
int func_021C7F24(u8 *p, int i) { char *q = func_021C7FCC(p, i); if (func_021B9BC4((u8 *)q, func_021C7F04(p, i))) return 1; return 0; }
