/*
 * function: func_02155A4C
 * address:  0x02155A4C
 * packet:   pkt_ov010_02155A4C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Frees the four lists at +0x3c and then the list at +0x38.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;

struct Ctx {
    u8 pad00[0x38];
    void *f38;
    void *f3c[4];
};

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_02155A4C(struct Ctx *ctx)
{
    int i;

    for (i = 0; i < 4; i++)
        func_020307B0(ctx->f3c[i]);
    func_020307B0(ctx->f38);
}
