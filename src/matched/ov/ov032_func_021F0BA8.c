/*
 * function: func_021F0BA8
 * address:  0x021F0BA8
 * packet:   pkt_ov032_021F0BA8
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0BA8  0x021F0BA8  thumb
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   BG_SYS_Check1FF4  0x02041FF4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 TOUCHPANEL_GetPointTrg(u32 *x, u32 *y);
extern u32 BG_SYS_Check1FF4(u32 layer, u16 x, u16 y, u16 *flags);

int func_021F0BA8(u8 *p)
{
    u32 x;
    u32 y;
    u16 v = 0xFFFE;
    u8 c = p[0];

    p[0] = c - 1;
    if (c == 0) {
        p[0] = 0;
        return 1;
    }
    if (TOUCHPANEL_GetPointTrg(&x, &y) != 0) {
        if (BG_SYS_Check1FF4(6, x, y + 0x40, &v) != 0) {
            p[0] = 0;
            return 1;
        }
    }
    return 0;
}
