/*
 * function: func_02155A6C
 * address:  0x02155A6C
 * packet:   pkt_ov010_02155A6C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stops the sound handle at +0x54 (if any) and clears it.
 *
 * symbols:
 *   func_02005D90  0x02005D90  thumb
 *   func_02005DF8  0x02005DF8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx {
    u8 pad00[0x54];
    u32 f54;
};

extern void func_02005D90(u32 a, u16 b);
extern void func_02005DF8(u32 a);

void func_02155A6C(struct Ctx *ctx)
{
    if (ctx->f54 != 0) {
        func_02005D90(ctx->f54, 0xFFFF);
        func_02005DF8(0x3c);
        ctx->f54 = 0;
    }
}
