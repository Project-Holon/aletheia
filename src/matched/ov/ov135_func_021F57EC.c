/*
 * function: WORLDTRADE_BOX_CreateWindows
 * address:  0x021F57EC
 * packet:   pkt_021F57EC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
 * symbols:
 *   WORLDTRADE_INPUT_PrintStringAlignedLine  0x021F91A0  thumb
 *   WORLDTRADE_TITLE_CreateMenuWindow  0x02200BAC  thumb
 *   BMP_Clear  0x02043B5C  arm  arm9
 *   BMP_WIN_Create  0x020450F0  arm  arm9
 *   BMP_WIN_TransferChars  0x02045334  arm  arm9
 *   BMP_WIN_MakeScreen  0x02045374  arm  arm9
 *   BMP_WIN_GetBgLayer  0x02045730  arm  arm9
 *   BMP_WIN_GetBmp  0x02045770  arm  arm9
 *   BG_SYS_PushTile  0x020409B4  arm  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[0x20];
    int mode;
    u8 pad24[0xB84 - 0x24];
    void *strs;
    u8 padB88[0xD40 - 0xB88];
    void *win1;
    u8 padD44[0xD4C - 0xD44];
    void *win0;
    u8 padD50[0xD54 - 0xD50];
    void *win3;
    u8 padD58[0xDD0 - 0xD58];
    void *win2;
    u8 padDD4[0xFA0 - 0xDD4];
    u8 g[4];
} Work;

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32 layer);
extern int WORLDTRADE_INPUT_PrintStringAlignedLine(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
extern void WORLDTRADE_TITLE_CreateMenuWindow(u8 *p, u32 k);

void WORLDTRADE_BOX_CreateWindows(Work *p)
{
    void *w;

    p->win0 = (void *)BMP_WIN_Create(3, 4, 0, 0xD, 3, 0xD, 1);
    BMP_Clear(BMP_WIN_GetBmp(p->win0), 0);
    w = p->win0;
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(w));

    p->win1 = (void *)BMP_WIN_Create(0, 2, 0x15, 0x1B, 2, 0xD, 1);
    BMP_Clear(BMP_WIN_GetBmp(p->win1), 0);
    w = p->win1;
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(w));

    p->win2 = (void *)BMP_WIN_Create(0, 2, 0x13, 0x1B, 4, 0xD, 1);
    BMP_Clear(BMP_WIN_GetBmp(p->win2), 0);
    w = p->win1;
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(w));

    p->win3 = (void *)BMP_WIN_Create(1, 0x18, 0x10, 6, 2, 0, 1);
    BMP_Clear(BMP_WIN_GetBmp(p->win3), 4);
    w = p->win3;
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(w));

    WORLDTRADE_INPUT_PrintStringAlignedLine(p->win3, (u32)p->strs, 0, 1, 1, 0x3DC4, (u32)p->g);
    if (p->mode == 5) {
        WORLDTRADE_TITLE_CreateMenuWindow((u8 *)p, 3);
    } else {
        WORLDTRADE_TITLE_CreateMenuWindow((u8 *)p, 1);
    }
}
