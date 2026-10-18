/*
 * function: RC4init
 * address:  0x021B7F00
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
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol RC4init (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B7F00.c \
 *       --func RC4init --addr 0x021B7F00 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

typedef struct {
    unsigned int   x;
    unsigned int   y;
    unsigned char *state;
    unsigned int   SizeOfState;
} ArcfourContext;

void RC4init(ArcfourContext *ctx, unsigned char *key, unsigned int key_len, unsigned int size)
{
    unsigned int keyindex, stateindex, counter;
    unsigned char t, u;
    unsigned char *state;

    state = ctx->state;
    ctx->y = 0;
    ctx->x = 0;
    ctx->SizeOfState = size;
    for (counter = 0; counter < size; counter++)
        state[counter] = counter;
    stateindex = 0;
    keyindex = 0;
    for (counter = 0; counter < size; counter++) {
        t = state[counter];
        stateindex = (stateindex + key[keyindex] + t) % ctx->SizeOfState;
        u = state[stateindex];
        state[stateindex] = t;
        state[counter] = u;
        if (++keyindex >= key_len)
            keyindex = 0;
    }
}
