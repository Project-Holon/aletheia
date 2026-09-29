/*
 * function: func_021B992C
 * address:  0x021B992C
 * packet:   pkt_ov071_021B992C
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern void func_02041300(u32 a, u32 b, u32 c, u32 d, u8 e, u8 f, u8 g);
extern void func_020409B4(u32 a);

void func_021B992C(char *a)
{
    int x;
    int t;

    x = *(u8 *)(a + 0x27c);
    if (x - 2 < 7) {
        t = (x - 1) * 32 / 8;
        func_02041300(6, 0, 0, (u8)t, 0x20, 0x20 - t, 0x11);
        func_020409B4(6);
    }
}
