/*
 * function: func_021D055C
 * address:  0x021D055C
 * packet:   pkt_ov093_021D055C
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
 *   func_021CFBBC  0x021CFBBC  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D0644  0x021D0644  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u32 func_021B9B94(void *p);
extern u32 func_021B8588(void *p);
extern int func_021D7F2C(int a, int b);
extern int func_021CFBBC(void *g, u8 k);
extern int func_021B9C00(void *p, int i);
extern int func_021D0644(void *g, int m, int a, int b);

int func_021D055C(u8 *g, int a, int b)
{
    u32 n;
    u32 i;

    n = func_021B9B94(*(void **)(g + 0x118));
    i = func_021D7F2C(func_021B8588(*(void **)g), g[0x11c]);
    for (; i < n; i++) {
        if (func_021CFBBC(g, i) == 0) {
            if (func_021D0644(g, func_021B9C00(*(void **)(g + 0x118), (u8)i), a, b))
                return 1;
        }
    }
    return 0;
}
