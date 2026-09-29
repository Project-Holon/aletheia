/*
 * function: func_021CF918
 * address:  0x021CF918
 * packet:   pkt_ov093_021CF918
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021CF89C  0x021CF89C  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021CF9B4  0x021CF9B4  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021B9C00(void *p, int i);
extern int func_021D5B68(int m);
extern u32 func_021CF89C(void *g, int m);
extern u16 func_021D5B40(int m);
extern int func_021D59B4(int m, int k);
extern u32 func_021CF9B4(void *g, int m, int a, int b);

u32 func_021CF918(u8 *g, int a, int b)
{
    u32 i;
    int m;
    u32 r;

    for (i = 0; i < g[0x11c]; i++) {
        m = func_021B9C00(*(void **)(g + 0x118), (u8)i);
        if (func_021D5B68(m) == 0) {
            if (func_021CF89C(g, m) != 0 && func_021D5B40(m) == 0xe4)
                return 4;
            if (func_021D59B4(m, 0x11) == 0x32)
                return 4;
        }
    }
    for (i = 0; i < g[0x11c]; i++) {
        r = func_021CF9B4(g, func_021B9C00(*(void **)(g + 0x118), (u8)i), a, b);
        if (r != 4)
            return r;
    }
    return 4;
}
