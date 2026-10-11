/*
 * function: func_0689D1FC
 * address:  0x0689D1FC
 * packet:   pkt_ov095_0689D1FC
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021B8640  0x021B8640  thumb
 *   func_0689D258  0x0689D258  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 func_021B8640(int);
extern void func_0689D258(u8 *, int, int, u8);

void func_0689D1FC(u8 *a, int b, int c)
{
    u32 i;
    u32 n;

    for (i = 0; i < 6; i++) {
        a[i * 3] = 0;
        a[i * 3 + 2] = 0x1f;
    }
    for (i = 0; i < 6; i++)
        a[0x12 + i] = 6;
    n = func_021B8640(b);
    for (i = 0; i <= n; i++)
        func_0689D258(a, b, c, i);
}
