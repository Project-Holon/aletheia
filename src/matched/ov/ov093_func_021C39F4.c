/*
 * function: func_021C39F4
 * address:  0x021C39F4
 * packet:   pkt_ov093_021C39F4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B99C0  0x021B99C0  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D5B7C  0x021D5B7C  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 func_021B9B94(void *p);
extern u8 func_021B99C0(void *p, int i);
extern u8 *func_021B9C00(void *p, u32 i);
extern int func_021D5B7C(void *m);
extern u32 func_021D78AC(u32 range);

int func_021C39F4(u8 *a, u8 *b)
{
    u8 buf[8];
    u32 n;
    u32 i;
    int c;

    n = func_021B9B94(*(void **)(b + 4));
    i = func_021B99C0(*(void **)(a + 4), b[0xb]);
    c = 0;
    for (; i < n; i++) {
        if (func_021D5B7C(func_021B9C00(*(void **)(b + 4), (u8)i))) {
            buf[c] = i;
            c++;
        }
    }
    if (c != 0) {
        return buf[func_021D78AC(c)];
    }
    return -1;
}
