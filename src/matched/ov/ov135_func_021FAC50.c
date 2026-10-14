/*
 * function: WORLDTRADE_INPUT_PutBmpWinString
 * address:  0x021FAC50
 * packet:   pkt_021FAC50
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_ADAPTER_PrintQueColor  0x022028C8  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BGWINFRM_PutBmpWin  0x0202CEBC  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct WinMgr;
extern u32 WORLDTRADE_ADAPTER_PrintQueColor(void *win, u32 z, void *str, u32 x, u32 y, u32 z2, u16 color, void *g);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BGWINFRM_PutBmpWin(struct WinMgr *mgr, u32 idx, void *a);

void WORLDTRADE_INPUT_PutBmpWinString(void *mgr, void *win, void *str, u32 x, u16 color, void *g)
{
    WORLDTRADE_ADAPTER_PrintQueColor(win, 0, str, x, 0, 0, color, g);
    BMP_WIN_TransferChars(win);
    BGWINFRM_PutBmpWin(mgr, 0, win);
}
