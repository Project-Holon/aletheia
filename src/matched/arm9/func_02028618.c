/*
 * unit:     no
 * function: APP_KEYCURSOR_DrawMark
 * address:  0x02028618
 * packet:   pkt_02028618
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020437DC  0x020437DC  arm
 *   func_020437E4  0x020437E4  arm
 *   func_02043AF4  0x02043AF4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Bmp {
    void *pixels;
    u16   width;
    u16   height;
    u16   depth;
    u16   kind;
};

struct Ctx {
    u32 f00;
    u8  f04;
};

extern u16  func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);

void APP_KEYCURSOR_DrawMark(struct Ctx *ctx, const struct Bmp *bmp, u32 color)
{
    u16 w = func_020437DC(bmp) - 11;
    u16 h = func_020437E4(bmp) - 9;

    func_02043AF4((struct Bmp *)bmp, (s16)w, (s16)(h + ctx->f04), 0xa, 7, (u8)color);
}
