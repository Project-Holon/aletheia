/*
 * function: func_021C0004
 * address:  0x021C0004
 * packet:   pkt_ov114_021C0004
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BFB90 0x021BFB90  arm
 */

typedef struct Base {
    unsigned char pad0[0x40];
    int f40;
    unsigned char pad1[0x124 - 0x44];
    int f124;
} Base;

typedef struct Ctx {
    Base *f0;
    char *f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
} Ctx;

extern int func_021BFB90(void *, int);

int func_021C0004(Ctx *ctx, int ch)
{
    if (ctx == 0)
        return 0;
    if (ctx->f20 != 0)
        return 0;
    if (ctx->fC + 1 >= ctx->f8) {
        if (ctx->f18 != 0) {
            ctx->f0->f124 = 1;
            ctx->f0->f40 = 2;
            return 0;
        }
        if (func_021BFB90(ctx, ctx->f14) != 0)
            goto append;
        ctx->f0->f124 = 1;
        ctx->f0->f40 = 1;
        return 0;
    }
append:
    ctx->f4[ctx->fC] = ch;
    ctx->fC++;
    ctx->f4[ctx->fC] = 0;
    return 1;
}
