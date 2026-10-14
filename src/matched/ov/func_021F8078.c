/*
 * function: WORLDTRADE_DEPOSIT_GetModeFontColor
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
 *   WORLDTRADE_DEPOSIT_GetModeColor  0x021F7F80  thumb
 */

typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 WORLDTRADE_DEPOSIT_GetModeColor(int mode);

u16 WORLDTRADE_DEPOSIT_GetModeFontColor(int mode, u16 color)
{
    if (mode == 1) {
        return WORLDTRADE_DEPOSIT_GetModeColor(0);
    }
    if (mode == 2) {
        color = WORLDTRADE_DEPOSIT_GetModeColor(1);
    }
    return color;
}
