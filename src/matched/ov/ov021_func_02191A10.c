/*
 * function: FIELD_MSGBG_CreateBgWinFont
 * address:  0x02191A10
 * packet:   pkt_ov021_02191A10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DDA50     0x021DDA50  data  a4
 *   func_02030734  0x02030734  arm
 *   BG_SYS_FillScrollArea  0x02040618  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_Create  0x02043678  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   FIELD_MSGBG_LoadBgWinGraphics  0x02191D88  thumb  ov021
 *   BMP_WIN_GetPosX  0x02045758  arm
 *   BMP_WIN_GetPosY  0x02045760  arm
 *   BMP_WIN_GetWidth  0x02045738  arm
 *   BMP_WIN_GetHeight  0x02045740  arm
 *   FIELD_MSGBG_DrawBgWinFrame  0x02191DC8  thumb  ov021
 *   BG_SYS_PushTile  0x020409B4  arm
 *   FIELD_MSGBG_InitCursor  0x021927C0  thumb  ov021
 *   FIELD_MSGBG_SetBlend  0x02193044  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern char d_021DDA50[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Bmp;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *w);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *w);
extern void FIELD_MSGBG_LoadBgWinGraphics(u32 a, u32 b, u32 c, u32 d);
extern u8 BMP_WIN_GetPosX(struct Descriptor *p);
extern u8 BMP_WIN_GetPosY(struct Descriptor *p);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern u8 BMP_WIN_GetHeight(struct Descriptor *p);
extern void FIELD_MSGBG_DrawBgWinFrame(u32 layer, u32 x, u32 y, u32 w, u32 h, u32 tile, u32 pal);
extern void BG_SYS_PushTile(u32 layer);
struct Fx;
struct G;
extern void FIELD_MSGBG_InitCursor(struct G *g, struct Fx *a);
extern void FIELD_MSGBG_SetBlend(u32 a);

u32 *FIELD_MSGBG_CreateBgWinFont(u16 *a, u32 b, u32 c)
{
    u32 *p;
    u32 x;
    u32 y;
    u32 w;
    u32 h;

    p = (u32 *)func_02030734(a[0], 0x34, 1, d_021DDA50, 0xee0);
    p[0] = (u32)a;
    p[12] = c;
    p[7] = -48;
    BG_SYS_FillScrollArea((u8)a[1], 0, 0);
    BG_SYS_FillScrollArea((u8)((u16 *)p[0])[1], 3, p[7]);
    p[1] = BMP_WIN_Create((u8)a[1], 2, 0x13, 0x1c, 4, 9, 1);
    p[2] = (u32)BMP_Create(0x1c, 4, 0x20, a[0]);
    p[3] = (u32)BMP_Create(0x1c, 4, 0x20, a[0]);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p[1])), 15);
    BMP_WIN_MakeScreen((struct Cfg *)p[1]);
    BMP_WIN_TransferChars((struct Descriptor *)p[1]);
    FIELD_MSGBG_LoadBgWinGraphics(a[1], 9, b, a[0]);
    x = BMP_WIN_GetPosX((struct Descriptor *)p[1]);
    y = BMP_WIN_GetPosY((struct Descriptor *)p[1]);
    w = BMP_WIN_GetWidth((struct Descriptor *)p[1]);
    h = BMP_WIN_GetHeight((struct Descriptor *)p[1]);
    FIELD_MSGBG_DrawBgWinFrame((u8)a[1], x, y, w, h, 0x33, 9);
    BG_SYS_PushTile((u8)a[1]);
    FIELD_MSGBG_InitCursor((struct G *)(p + 10), (struct Fx *)p[0]);
    a[3] = 11;
    FIELD_MSGBG_SetBlend(0);
    return p;
}
