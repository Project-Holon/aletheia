/*
 * function: func_021B8D8C
 * address:  0x021B8D8C
 * packet:   pkt_ov093_021B8D8C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8D08  0x021B8D08  thumb  ov093
 *   func_021B9864  0x021B9864  thumb  ov093
 *   func_021B8BEC  0x021B8BEC  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021B8D08(u32 x);
extern int func_021B9864(int a, int b, int c);
extern u8 func_021B8BEC(u8 *p, u32 k, u8 n);

int func_021B8D8C(void *p, void *a, u32 b)
{
    u8 i = func_021B8D08(b);
    int r = func_021B9864((int)a, i, b);

    if (r >= 0) {
        r = func_021B8BEC(p, i, r);
        if (r != 6) return r;
    }
    return 6;
}
