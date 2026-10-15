/*
 * function: VIEWER_TEXT_DrawPage
 * address:  0x021C6874
 * packet:   pkt_ov111_021C6874
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   VIEWER_TEXT_DrawRow  0x021C63B8  thumb  ov111
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

typedef struct {
    u8 pad0[0x1C];
    void *bg;
    u8 pad20[0x32FA - 0x20];
    u8 list[0x13];
} Work;

struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(unsigned int bit);
extern void VIEWER_TEXT_DrawRow(Work *p, void *a, int sel, int y, int idx);

void VIEWER_TEXT_DrawPage(Work *p, int scroll, int flush, int idx)
{
    void *bg = p->bg;
    int i;
    int top = -(scroll / 16);

    BMP_Clear(BMP_WIN_GetBmp(bg), 0);
    for (i = 0; i < 5; i++) {
        VIEWER_TEXT_DrawRow(p, bg, p->list[i + top], scroll % 16 + i * 16, idx);
    }
    if (flush) {
        BMP_WIN_TransferChars(bg);
        BMP_WIN_MakeScreen(bg);
        func_02041B6C(BMP_WIN_GetBgLayer(bg));
    }
}
