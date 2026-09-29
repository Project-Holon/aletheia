/*
 * function: func_021D04E4
 * address:  0x021D04E4
 * packet:   pkt_ov093_021D04E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021D7F2C  0x021D7F2C  thumb  ov093
 *   func_021CFBBC  0x021CFBBC  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u32 func_021B9B94(void *p);
extern u32 func_021B8588(void *p);
extern int func_021D7F2C(int a, int b);
extern int func_021CFBBC(void *g, u8 k);
extern int func_021B9C00(void *p, int i);
extern int func_021D5B68(int m);
extern int func_021D59B4(int m, int k);

int func_021D04E4(u8 *g, u8 a, u8 *out)
{
    u32 n;
    u32 i;
    int m;

    n = func_021B9B94(*(void **)(g + 0x118));
    i = func_021D7F2C(func_021B8588(*(void **)g), g[0x11c]);
    for (; i < n; i++) {
        if (func_021CFBBC(g, i) == 0) {
            m = func_021B9C00(*(void **)(g + 0x118), (u8)i);
            if (func_021D5B68(m) == 0 && a == func_021D59B4(m, 0x11)) {
                *out = i;
                return 1;
            }
        }
    }
    return 0;
}
