/*
 * function: func_0218872C
 * address: 0x0218872C
 * packet: pkt_ov096_0218872C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0218875C 0x0218875C thumb ov096
 */
typedef unsigned char u8;
extern void func_0218875C(u8 *, int, int);
int func_0218872C(u8 *a, u8 *b)
{
    func_0218875C(a, (int)b, 1);
    return *(int *)(b + 0xc4);
}
