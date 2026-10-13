/*
 * function: func_021FD104
 * address:  0x021FD104
 * packet:   pkt_021FD104
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   tbl_02203668   0x02203668  data  a4
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 x;
    u32 y;
    u32 w;
    u32 h;
    u32 bg;
} WinDef;

typedef struct {
    u8 pad0[0xD40];
    u32 frame;
    u8 padD44[0xD50 - 0xD44];
    u32 side[2];
    u8 padD58[0xD90 - 0xD58];
    u32 win[16];
    u8 padDD0[0x12FC - 0xDD0];
    u32 flag;
} Menu;

extern const WinDef tbl_02203668[];

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 v);

void func_021FD104(Menu *p)
{
    int i;
    const WinDef *d;
    u32 v;

    p->frame = BMP_WIN_Create((u8)4, (u8)2, (u8)0x13, (u8)0x1b, 4, 1, (u16)1);
    if (p->flag == 0) {
        p->side[0] = BMP_WIN_Create((u8)4, (u8)1, (u8)0x15, (u8)0xd, 2, 1, (u16)1);
        p->side[1] = BMP_WIN_Create((u8)4, (u8)0x11, (u8)0x15, (u8)0xd, 2, 1, (u16)1);
    }
    for (i = 0; i < 16; i++) {
        d = &tbl_02203668[i];
        if (d->bg == 2) {
            p->win[i] = BMP_WIN_Create((u8)d->bg, (u8)d->x, (u8)d->y, (u8)d->w, d->h, 0xd, (u16)1);
        } else {
            p->win[i] = BMP_WIN_Create((u8)d->bg, (u8)d->x, (u8)d->y, (u8)d->w, d->h, 1, (u16)1);
        }
        v = p->win[i];
        BMP_WIN_TransferChars((struct Descriptor *)v);
        BMP_WIN_MakeScreen((struct Cfg *)v);
        func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)v));
    }
}
