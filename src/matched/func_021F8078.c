/*
 * function: func_021F8078
 * address:  0x021F8078
 * packet:   pkt_021F8078
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F7F80  0x021F7F80  thumb
 */

typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 func_021F7F80(int mode);

u16 func_021F8078(int mode, u16 color)
{
    if (mode == 1) {
        return func_021F7F80(0);
    }
    if (mode == 2) {
        color = func_021F7F80(1);
    }
    return color;
}
