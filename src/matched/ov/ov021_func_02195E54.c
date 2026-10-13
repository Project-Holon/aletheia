/*
 * function: TALKMSGWIN_DrawFrameByType
 * address:  0x02195E54
 * packet:   pkt_ov021_02195E54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TALKMSGWIN_DrawSimpleFrame  0x021955EC  thumb  ov021
 *   TALKMSGWIN_DrawCorneredFrame  0x02195938  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

struct FrameStyle;
extern void TALKMSGWIN_DrawSimpleFrame(struct FrameStyle *style, void *win, int deco);
extern void TALKMSGWIN_DrawCorneredFrame(struct FrameStyle *style, void *win, int deco);

void TALKMSGWIN_DrawFrameByType(u32 a, u32 b, u8 c, u32 d)
{
    switch (c) {
    case 0:
        TALKMSGWIN_DrawSimpleFrame((struct FrameStyle *)a, (void *)b, d);
        break;
    case 1:
        TALKMSGWIN_DrawCorneredFrame((struct FrameStyle *)a, (void *)b, d);
        break;
    }
}
