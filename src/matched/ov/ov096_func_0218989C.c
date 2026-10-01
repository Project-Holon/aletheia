/*
 * function: func_0218989C
 * address: 0x0218989C
 * packet: pkt_ov096_0218989C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Caller-visible return/second arguments override tail-forwarder declarations.
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_0218A160 0x0218A160 thumb ov096
 *   func_0218A2FC 0x0218A2FC thumb ov096
 *   func_0218A308 0x0218A308 thumb ov096
 *   func_0218A0F4 0x0218A0F4 thumb ov096
 *   func_021B8DE4 0x021B8DE4 thumb ov093
 *   func_021B9AF8 0x021B9AF8 thumb ov093
 *   func_021B99B8 0x021B99B8 thumb ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D554C 0x021D554C thumb ov093
 */
typedef unsigned char u8;
extern unsigned int func_0201134C(int);
extern int func_0218A160(int, int);
extern int func_0218A2FC(int, int);
extern int func_0218A308(int, u8);
extern int func_0218A0F4(int, int, int, int, int);
extern int func_021B8DE4(int, int);
extern int func_021B9AF8(int, int);
extern int func_021B99B8(int, int);
extern int func_021B9B94(int);
extern int func_021D5B68(int);
extern int func_021D5448(int);
extern int func_021D554C(int, u8);
int func_0218989C(int a, int b)
{
    int x, z, y, n, p, i, j;
    x = func_0201134C(a);
    z = func_0201134C(a);
    y = func_0218A160(b, x);
    n = func_021B8DE4(*(int *)(b + 0xb0), y);
    p = func_021B9AF8(*(int *)(b + 0xb8), n);
    i = func_021B99B8(*(int *)(b + 0xb0), n);
    for (; i < func_021B9B94(p); i++) {
        if (func_021D5B68(func_0218A308(p, i)) == 0) {
            for (j = 0; j < func_021D5448(func_0218A2FC(b, y)); j++) {
                if (func_0218A0F4(a, 3, func_021D554C(func_0218A2FC(b, y), j), 0, z) != 0)
                    break;
            }
            if (j != func_021D5448(func_0218A2FC(b, y)))
                break;
        }
    }
    return *(int *)(b + 0xc4);
}
