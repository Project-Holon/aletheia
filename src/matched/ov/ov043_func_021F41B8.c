/*
 * function: func_021F41B8
 * address:  0x021F41B8
 * packet:   pkt_ov043_021F41B8
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218EC5C  0x0218EC5C  thumb  ov021
 *   func_0218ECC4  0x0218ECC4  thumb  ov021
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern u32 func_0218EC5C(u8 *p);
extern void func_0218ECC4(int p, void *v);

void func_021F41B8(int a0, int a1, int a2, int a3, u8 *s)
{
    s[0] = 0;
    s[1] = 0;
    *(int *)(s + 8) = a3;
    *(int *)(s + 0xC) = func_0218EC5C((u8 *)a3);
    func_0218ECC4(a3, s + 0x10);
    if (a2) {
        *(int *)(s + 4) = 0x1000;
        s[2] = 2;
    } else {
        if (a0 == 5) {
            *(int *)(s + 4) = 0x4000;
        } else {
            *(int *)(s + 4) = 0x2000;
        }
        s[2] = 4;
    }
    if (a1 < 0) {
        *(int *)(s + 4) *= -1;
    }
}
