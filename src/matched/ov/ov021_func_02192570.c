/*
 * function: FIELD_MSGBG_CreateSpWin
 * address:  0x02192570
 * packet:   pkt_ov021_02192570
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
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_Create  0x02043678  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   FIELD_MSGBG_LoadFrameTile  0x02192264  thumb  ov021
 *   FIELD_MSGBG_DrawFrameBmp  0x021922A4  thumb  ov021
 *   FIELD_MSGBG_LoadSpWinPalette  0x02192244  thumb  ov021
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
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Bmp;
struct Cfg;
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *w);
extern void FIELD_MSGBG_LoadFrameTile(u32 a, u32 b, u32 c, u32 d);
extern void FIELD_MSGBG_DrawFrameBmp(u32 a, u32 b, u32 c);
extern void FIELD_MSGBG_LoadSpWinPalette(u32 a, u32 b, u32 c);
extern void BG_SYS_PushTile(u32 layer);
struct Fx;
struct G;
extern void FIELD_MSGBG_InitCursor(struct G *g, struct Fx *a);
extern void FIELD_MSGBG_SetBlend(u32 a);

u32 *FIELD_MSGBG_CreateSpWin(u16 *a, u32 b, u32 c, u16 d, u16 e, u16 f)
{
    u32 *t;

    t = (u32 *)func_02030734(*a, 0x18, 1, d_021DDA50, 0x115D);
    t[2] = (u32)a;
    t[0] = BMP_WIN_Create((u8)a[1], (u8)c, (u8)d, (u8)e, (u8)f, 9, 1);
    t[3] = (u32)BMP_Create(1, 1, 0x20, *a);
    FIELD_MSGBG_LoadFrameTile(t[3], b, *a, 9);
    FIELD_MSGBG_DrawFrameBmp((u32)BMP_WIN_GetBmp((struct Descriptor *)t[0]), b, *a);
    FIELD_MSGBG_LoadSpWinPalette(a[1], 9, *a);
    BMP_WIN_MakeScreen((struct Cfg *)t[0]);
    BMP_WIN_TransferChars((struct Descriptor *)t[0]);
    BG_SYS_PushTile((u8)a[1]);
    FIELD_MSGBG_InitCursor((struct G *)(t + 4), (struct Fx *)a);
    a[3] = 0xB;
    FIELD_MSGBG_SetBlend(0);
    return t;
}
