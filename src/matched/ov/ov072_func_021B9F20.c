/*
 * function: func_021B9F20
 * address: 0x021B9F20
 * packet: pkt_ov072_021B9F20
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: trailing two-byte alignment padding.
 * symbols:
 *   func_021B639C 0x021B639C thumb ov067
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_02082BCC 0x02082BCC arm
 */
extern void func_021B639C(unsigned char *);
extern void func_0204B3B4(unsigned);
extern void func_0204AFD8(unsigned);
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
extern void func_02082BCC(void *,int,int);
void func_021B9F20(unsigned *p) {
    func_021B639C((unsigned char *)p[3]);
    func_0204B3B4(p[5]); func_0204AFD8(p[2]);
    func_0204A8D4(p[1]); func_0204ADA4(p[0]);
    func_02082BCC(p,0,32);
}
