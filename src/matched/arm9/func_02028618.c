/*
 * unit:     no
 * function: func_02028618
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
extern u16  func_020437E4(const struct Bmp *bmp);
extern void func_02043AF4(const struct Bmp *bmp, s16 x, s16 y, u32 d,
                          u32 e, u32 f);

void func_02028618(struct Ctx *ctx, const struct Bmp *bmp, u32 color)
{
    u16 w = func_020437DC(bmp) - 11;
    u16 h = func_020437E4(bmp) - 9;

    func_02043AF4(bmp, (s16)w, (s16)(h + ctx->f04), 0xa, 7, (u8)color);
}
