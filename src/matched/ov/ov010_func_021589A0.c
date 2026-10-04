/*
 * function: func_021589A0
 * address: 0x021589A0
 * packet: pkt_ov010_021589A0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent ends in two alignment padding bytes.
 * symbols:
 *   func_021589DC 0x021589DC thumb ov010
 *   func_02158BFC 0x02158BFC thumb ov010
 *   func_0215886C 0x0215886C thumb ov010
 */
typedef unsigned short u16;
extern int func_021589DC(int a0);
extern int func_02158BFC(int, int, int, int, int);
extern int func_0215886C(u16 *, int);
int func_021589A0(int a, int b, int c) {
    u16 *p = (u16 *)func_021589DC(a);
    if (p) return func_0215886C(p, func_02158BFC(*p, a, b, c, 0));
    return 3;
}
