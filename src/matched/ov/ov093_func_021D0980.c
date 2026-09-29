/*
 * function: func_021D0980
 * address:  0x021D0980
 * packet:   pkt_ov093_021D0980
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021D7F2C  0x021D7F2C  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D5B7C  0x021D5B7C  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u32 func_021B9B94(void *p);
extern u32 func_021B8588(void *p);
extern int func_021D7F2C(int a, int b);
extern int func_021B9C00(void *p, int i);
extern int func_021D5B7C(int m);

u8 func_021D0980(u8 *g, u8 *out)
{
    u32 n;
    u8 c;
    u32 i;

    n = func_021B9B94(*(void **)(g + 0x118));
    i = func_021D7F2C(func_021B8588(*(void **)g), g[0x11c]);
    c = 0;
    for (; i < n; i = (u8)(i + 1)) {
        if (func_021D5B7C(func_021B9C00(*(void **)(g + 0x118), i))) {
            if (out)
                out[c] = i;
            c = (u8)(c + 1);
        }
    }
    return c;
}
