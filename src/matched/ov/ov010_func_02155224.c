/*
 * function: func_02155224
 * address:  0x02155224
 * packet:   pkt_ov010_02155224
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Trims the list at +0x38 and the four lists at +0x3c to three entries each.
 *
 * symbols:
 *   func_02155200  0x02155200  thumb  ov010
 */

typedef unsigned char u8;

struct Ctx {
    u8 pad00[0x38];
    void *f38;
    void *f3c[4];
};

extern void func_02155200(void *list);

void func_02155224(struct Ctx *ctx)
{
    int i;

    func_02155200(ctx->f38);
    for (i = 0; i < 4; i++)
        func_02155200(ctx->f3c[i]);
}
