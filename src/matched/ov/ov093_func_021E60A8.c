/*
 * function: func_021E60A8
 * address:  0x021E60A8
 * packet:   pkt_ov093_021E60A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C7FCC  0x021C7FCC  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D5B7C  0x021D5B7C  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void *func_021C7FCC(void *a, u32 b);
extern u32 func_021B9B94(void *p);
extern u8 *func_021B9C00(void *p, int i);
extern u32 func_021D5440(u8 *p);
extern int func_021D5B7C(u8 *p);
extern int func_021D62A8(u8 *p);

u8 *func_021E60A8(void *a, u32 b, u8 c)
{
    void *s;
    u32 n;
    u32 i;
    u8 *t;
    int r;
    s = func_021C7FCC(a, b);
    n = func_021B9B94(s);
    if (c >= n)
        return 0;
    for (i = 0; i < n; i++) {
        r = 0;
        t = func_021B9C00(s, (u8)i);
        if (b == func_021D5440(t))
            r = 1;
        else if (func_021D5B7C(t) != 0 && func_021D62A8(t) == 0)
            r = 1;
        if (r != 0) {
            if (c == 0)
                return t;
            c = c - 1;
        }
    }
    return 0;
}
