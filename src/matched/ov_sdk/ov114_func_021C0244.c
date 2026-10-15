/*
 * function: ghiCallCompletedCallback
 * address:  0x021C0244
 * packet:   pkt_ov114_021C0244
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sGhttpSocketError    0x021CE598  data  a4
 *   gsDebugFormat 0x0217D254  arm
 */

typedef struct Ctx {
    unsigned char pad0[4];
    void *f4;
    unsigned char pad1[4];
    int fC;
    unsigned char pad2[0x40 - 0x10];
    int f40;
    int f44;
    int f48;
    int f4C;
    int f50;
    int f54;
    unsigned char pad3[0xEC - 0x58];
    int fEC;
    unsigned char pad4[0x104 - 0xF0];
    int f104;
    unsigned char pad5[0x128 - 0x108];
    int f128;
} Ctx;

extern int sGhttpSocketError[];
extern int gsDebugFormat(int, int, int, void *, int);

void ghiCallCompletedCallback(Ctx *ctx)
{
    if (ctx->f40 != 0)
        gsDebugFormat(8, 0, 2, sGhttpSocketError, ctx->f54);
    if (ctx->f48 != 0) {
        int r5 = ctx->fC == 0 ? ctx->fEC : 0;
        int res = ((int (*)(void *, int, int, int, int))ctx->f48)
                      (ctx->f4, ctx->f40, r5, ctx->f128, ctx->f4C);
        if (r5 == 0)
            return;
        if (res == 0)
            ctx->f104 = 1;
    }
}
