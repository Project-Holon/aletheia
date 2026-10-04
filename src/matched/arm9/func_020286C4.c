/*
 * unit:     no
 * function: func_020286C4
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
 *   sub_0201CE30   0x0201CE30  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_02045770  0x02045770  arm
 *   func_02028618  0x02028618  thumb
 *   func_0202865C  0x0202865C  thumb
 *   func_02045334  0x02045334  arm
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

extern u32   sub_0201CE30(void *p);
extern u32   func_020362DC(void);
extern u32   func_02035C60(void);
struct Bmp;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02028618(struct Ctx *ctx, const struct Bmp *bmp, u32 color);
extern void func_0202865C(struct Ctx *ctx, const struct Bmp *bmp, u32 color);
extern void func_02045334(struct Descriptor *d);

void func_020286C4(struct Ctx *ctx, void *p, void *cell)
{
    u32 mode = sub_0201CE30(p);

    switch (mode) {
    case 2:
        ctx->f06 = 0;
        return;
    case 1:
    {
        u32 r = 0;

        if (ctx->b0) {
            r = func_020362DC() & 3;
        }
        if (r == 0) {
            if (ctx->b1) {
                r = func_02035C60();
            }
        }
        if (r != 0) {
            ctx->f06 = 1;
            func_02028618(ctx, func_02045770(cell), ctx->f08);
            func_02045334(cell);
            return;
        }
        if (ctx->f06 != 0) {
            return;
        }
        func_0202865C(ctx, func_02045770(cell), ctx->f08);
        func_02045334(cell);
        return;
    }
    case 0:
        ctx->f06 = 0;
        return;
    }
}
