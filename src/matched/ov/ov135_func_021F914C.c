/*
 * function: WORLDTRADE_INPUT_PrintStringAligned
 * address: 0x021F914C
 * packet: pkt_ov135_021F914C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: unused fifth argument leaves font and context in stack slots +4/+8.
 * symbols:
 *   WORLDTRADE_ADAPTER_StrObjThunk 0x022026C4 thumb ov135
 *   BMP_WIN_GetWidth 0x02045738 arm
 */
typedef unsigned char u8;
typedef unsigned int   u32;
extern int WORLDTRADE_ADAPTER_StrObjThunk(u32 *p, u32 b, u32 a, u32 c);
struct Descriptor;
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
int WORLDTRADE_INPUT_PrintStringAligned(void *win, void *str, int x, int align, int unused, int font, void *ctx)
{
    int width;
    switch (align) {
    case 1:
        width = WORLDTRADE_ADAPTER_StrObjThunk(ctx, (u8)font, (u32)str, (int)0);
        x = (BMP_WIN_GetWidth(win) * 8 - width) / 2;
        break;
    case 2:
        width = WORLDTRADE_ADAPTER_StrObjThunk(ctx, (u8)font, (u32)str, (int)0);
        x = BMP_WIN_GetWidth(win) * 8 - width;
        break;
    }
    return x;
}
