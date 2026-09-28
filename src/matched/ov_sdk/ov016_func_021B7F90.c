/*
 * function: arcfour_byte
 * address:  0x021B7F90
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   _u32_div_f  0x0209C2B0  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol arcfour_byte (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B7F90.c \
 *       --func arcfour_byte --addr 0x021B7F90 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

typedef struct {
    unsigned int   x;
    unsigned int   y;
    unsigned char *state;
    unsigned int   SizeOfState;
} ArcfourContext;

unsigned int arcfour_byte(ArcfourContext *ctx)
{
    unsigned char x, y, sx, sy;
    unsigned char *state;

    state = ctx->state;
    x = (ctx->x + 1) % ctx->SizeOfState;
    sx = state[x];
    y = (sx + ctx->y) % ctx->SizeOfState;
    sy = state[y];
    ctx->x = x;
    ctx->y = y;
    state[y] = sx;
    state[x] = sy;
    return state[(sx + sy) % ctx->SizeOfState];
}
