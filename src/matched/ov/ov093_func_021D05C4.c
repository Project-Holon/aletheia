/*
 * function: func_021D05C4
 * address:  0x021D05C4
 * packet:   pkt_ov093_021D05C4
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
 *   func_021D5B7C  0x021D5B7C  thumb  ov093
 *   func_021D57FC  0x021D57FC  thumb  ov093
 *   func_021D799C  0x021D799C  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u32 func_021B9B94(void *p);
extern u32 func_021B8588(void *p);
extern int func_021D7F2C(int a, int b);
extern int func_021CFBBC(void *g, u8 k);
extern int func_021B9C00(void *p, int i);
extern int func_021D5B7C(int m);
extern u16 func_021D57FC(int m);
extern int func_021D799C(int a, int b);

int func_021D05C4(u8 *g, u8 a, int b, u8 *out)
{
    u32 n;
    u32 i;
    int m;

    n = func_021B9B94(*(void **)(g + 0x118));
    i = func_021D7F2C(func_021B8588(*(void **)g), g[0x11c]);
    for (; i < n; i++) {
        if (func_021CFBBC(g, i) == 0) {
            m = func_021B9C00(*(void **)(g + 0x118), (u8)i);
            if (func_021D5B7C(m) != 0 && func_021D799C(a, func_021D57FC(m)) <= b) {
                *out = i;
                return 1;
            }
        }
    }
    return 0;
}
