/*
 * function: WORLDTRADE_INPUT_PrintPageNumberA
 * address:  0x021FB2F0
 * packet:   pkt_021FB2F0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   WORLDTRADE_INPUT_PutBmpWinString  0x021FAC50  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BGWINFRM_PutBmpWin  0x0202CEBC  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *str;
    int val;
} Item;

typedef struct {
    void **wins;
    u8 pad4[0xC - 4];
    u32 up;
    u32 down;
    u8 pad14[0x18 - 0x14];
    void *mgr;
    u8 pad1C[0x30 - 0x1C];
    Item *items;
    void *num;
    u8 pad38[0x56 - 0x38];
    s16 page;
    int total;
    u8 pad5C[0x7C - 0x5C];
    u8 g[4];
} Menu;

struct WinMgr;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void WORLDTRADE_INPUT_PutBmpWinString(void *mgr, void *win, void *str, u32 x, u16 color, void *g);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BGWINFRM_PutBmpWin(struct WinMgr *mgr, u32 idx, void *a);

void WORLDTRADE_INPUT_PrintPageNumberA(Menu *m, int page, int total)
{
    int i;

    for (i = 0; i < 4; i++) {
        BMP_Clear(BMP_WIN_GetBmp(m->wins[i]), 0xA);
        if (i + page * 4 < total) {
            WORLDTRADE_INPUT_PutBmpWinString(m->mgr, m->wins[i], m->items[page * 4 + i].str, 0, 0x3DC2, m->g);
        } else {
            BMP_WIN_TransferChars(m->wins[i]);
            BGWINFRM_PutBmpWin(m->mgr, 0, m->wins[i]);
        }
    }
}
