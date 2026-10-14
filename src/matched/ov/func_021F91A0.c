/*
 * function: WORLDTRADE_INPUT_PrintStringAlignedLine
 * address:  0x021F91A0
 * packet:   pkt_021F91A0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_INPUT_PrintStringAligned  0x021F914C  thumb  ov135
 *   WORLDTRADE_ADAPTER_PrintQueColor  0x022028C8  thumb  ov135

 * Seven-argument wrapper: forwards the object, three words, the 0 and the u16/g pair to the two helpers.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int WORLDTRADE_INPUT_PrintStringAligned(void *win, void *str, int x, int align, int unused, int font, void *ctx);
extern u32 WORLDTRADE_ADAPTER_PrintQueColor(u8 *p, u32 z, u32 b, u32 r, u32 d, u32 z2, u16 f, u32 g);

int WORLDTRADE_INPUT_PrintStringAlignedLine(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g)
{
    u32 r = WORLDTRADE_INPUT_PrintStringAligned(p, (void *)b, c, e, f, 0, (void *)g);

    return WORLDTRADE_ADAPTER_PrintQueColor(p, 0, b, r, d, 0, f, g);
}
