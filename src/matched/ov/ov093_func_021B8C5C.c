/*
 * function: func_021B8C5C
 * address:  0x021B8C5C
 * packet:   pkt_ov093_021B8C5C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8C20  0x021B8C20  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 func_021B8C20(int kind, u32 flags, u32 v);

u8 func_021B8C5C(int kind, u32 flags)
{
    u8 x;
    switch (kind) {
    default:
    case 0:
        return func_021B8C20(kind, flags, 0);
    case 1:
        x = flags >> 1;
        return func_021B8C20(kind, flags, (u8)(1 ^ x));
    case 2:
        x = flags >> 1;
        if (x == 0) {
            x = 2;
        } else if (x == 2) {
            x = 0;
        }
        return func_021B8C20(kind, flags, x);
    case 3:
        return func_021B8C20(kind, flags, 0);
    }
}
