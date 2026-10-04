/*
 * function: func_021C452C
 * address:  0x021C452C
 * packet:   pkt_ov021_021C452C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern void *func_0201ADE4(u32 a, int b, u32 c);
extern u32 func_0201AE1C(u32 a, u32 b);
extern void func_0201AE14(u32 a);

u8 func_021C452C(u32 a, u32 b, u32 c, u32 d)
{
    u32 s[3];
    u32 x = (u32)func_0201ADE4(a, b, d);
    u32 i;

    s[0] = func_0201AE1C(x, 0x1a);
    s[1] = func_0201AE1C(x, 0x1b);
    s[2] = func_0201AE1C(x, 0x1c);
    func_0201AE14(x);
    for (i = 0; i < 3; i++) {
        if (c == s[i])
            break;
    }
    if (i >= 3)
        i = 0;
    return i;
}
