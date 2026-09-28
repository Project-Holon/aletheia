/*
 * unit:     no
 * function: func_0202865C
 * address:  0x0202865C
 * packet:   pkt_02028618
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02028618  0x02028618  thumb
 *   func_020437DC  0x020437DC  arm
 *   func_020437E4  0x020437E4  arm
 *   func_020439A0  0x020439A0  arm
 *   _s32_div_f     0x0209C0A4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Bmp {
    void *pixels;
    u16   width;
    u16   height;
    u16   depth;
    u16   kind;
};

struct Ctx {
    void *f00;
    u8    f04;
    u8    f05;
};

extern void func_02028618(struct Ctx *ctx, const struct Bmp *bmp, u32 color);
extern u16  func_020437DC(const struct Bmp *bmp);
extern u16  func_020437E4(const struct Bmp *bmp);
extern void func_020439A0(void *a, const struct Bmp *b, u32 c, u32 d,
                          u32 e, u32 f, u32 g, u32 h, u32 i);

void func_0202865C(struct Ctx *ctx, const struct Bmp *bmp, u32 color)
{
    u16 w;
    u16 h;

    func_02028618(ctx, bmp, color);

    ctx->f05 = ctx->f05 + 1;
    if (ctx->f05 >= 8) {
        ctx->f05 = 0;
        ctx->f04 = ctx->f04 + 1;
        ctx->f04 = (s32)ctx->f04 % 3;
    }

    w = func_020437DC(bmp) - 11;
    h = func_020437E4(bmp) - 9;

    func_020439A0(ctx->f00, bmp, 0, 2, w, h + ctx->f04, 0xa, 7, 0);
}
