/*
 * function: func_021E4A08
 * address:  0x021E4A08
 * packet:   pkt_ov093_021E4A08
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021B9B94(u8 *x);
extern u32 func_021B9C00(u8 *x, u32 i);
extern int func_021D62A8(u32 h);
extern u8 func_021D5440(u32 h);

u8 func_021E4A08(u8 *x, u8 idx, u8 lim, u8 *buf)
{
    u8 j;
    u8 i;
    u8 n = func_021B9B94(x);
    u32 h;

    j = 0;
    for (i = 0; i < n; i++) {
        if (idx >= lim)
            break;
        h = func_021B9C00(x, i);
        if (func_021D62A8(h) != 0) {
            buf[idx] = func_021D5440(h);
            idx = idx + 1;
            j = j + 1;
        }
    }
    return j;
}
