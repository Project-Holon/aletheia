/*
 * unit:     no
 * function: APP_KEYCURSOR_Update
 * address:  0x020286C4
 * packet:   pkt_02028618
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_PrintStreamGetState   0x0201CE30  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   APP_KEYCURSOR_DrawMark  0x02028618  thumb
 *   APP_KEYCURSOR_Animate  0x0202865C  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx {
    void *f00;
    u8    f04;
    u8    f05;
    u8    f06;
    u8    b0 : 1;
    u8    b1 : 1;
    u8    b2 : 6;
    u16   f08;
};

extern u32   PRINTSYS_PrintStreamGetState(void *p);
extern u32   KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
struct Bmp;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void APP_KEYCURSOR_DrawMark(struct Ctx *ctx, const struct Bmp *bmp, u32 color);
extern void APP_KEYCURSOR_Animate(struct Ctx *ctx, const struct Bmp *bmp, u32 color);
extern void BMP_WIN_TransferChars(struct Descriptor *d);

void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell)
{
    u32 mode = PRINTSYS_PrintStreamGetState(p);

    switch (mode) {
    case 2:
        ctx->f06 = 0;
        return;
    case 1:
    {
        u32 r = 0;

        if (ctx->b0) {
            r = KEY_GetTrg() & 3;
        }
        if (r == 0) {
            if (ctx->b1) {
                r = TOUCHPANEL_GetTrg();
            }
        }
        if (r != 0) {
            ctx->f06 = 1;
            APP_KEYCURSOR_DrawMark(ctx, BMP_WIN_GetBmp(cell), ctx->f08);
            BMP_WIN_TransferChars(cell);
            return;
        }
        if (ctx->f06 != 0) {
            return;
        }
        APP_KEYCURSOR_Animate(ctx, BMP_WIN_GetBmp(cell), ctx->f08);
        BMP_WIN_TransferChars(cell);
        return;
    }
    case 0:
        ctx->f06 = 0;
        return;
    }
}
