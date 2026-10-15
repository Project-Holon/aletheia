/*
 * function: SPL_EMITTER_EvalKey
 * address:  0x02057C9C
 * packet:   pkt_02052F58
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 *
 * A keyframed RGB555 colour ramp over three key times t0 < t1 < t2: below t0
 * the key's first colour, between t0 and t1 a per-channel lerp from the
 * key's first colour to the node's colour, between t1 and t2 a lerp from the
 * node's colour to the key's second colour, and past t2 the second colour.
 * The key's bit-2 flag switches the lerp off (the target colour is stored
 * recomposed).  The three _s32_div_f calls per segment come out in b, r, g
 * order from the GX_RGB expression tree.
 *
 * Closes docs/notes/pkt_02057C9C.c.txt (16 out at the end of wave 8).  The
 * two segments are two inline helpers with different parameter and channel
 * declaration orders; segment 1 is the note's ColLerp unchanged.  What closed
 * segment 2 (wave 9, third lane): its helper takes the KEY colour FIRST
 * (`to`, then `from`), called ColLerp2(out, k->c1, n->col, ...), and declares
 * its channels in plain per-channel from/to order fr, tr, fg, tg, fb, tb.  In
 * both segments the key colour is therefore the first colour parameter.
 * Found by a joint search of the (to, from) signature over the 720 channel
 * orders; (to, from) with the note's order was 22 out.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef u16 GXRgb;
#define GX_RGB(r, g, b) (((r) << 0) | ((g) << 5) | ((b) << 10))
struct KeyF { u16 b0 : 2; u16 on : 1; u16 rest : 13; };
struct Key {
    GXRgb c0;
    GXRgb c1;
    u8 t0;
    u8 t1;
    u8 t2;
    u8 pad7;
    struct KeyF f;
};
struct Node { u8 pad_00[0x22]; GXRgb col; };
struct Ctx { struct Node *node; u8 pad_04[4]; struct Key *key; };
struct Out { u8 pad_00[0x36]; GXRgb col; };

static inline void ColLerp(struct Out *out, s32 from, s32 to, u32 on, s32 num, s32 den)
{
    s32 tr = to & 0x1f;
    s32 fr = from & 0x1f;
    s32 tg = (to >> 5) & 0x1f;
    s32 fg = (from >> 5) & 0x1f;
    s32 fb = (from >> 10) & 0x1f;
    s32 tb = (to >> 10) & 0x1f;
    if (!on) {
        out->col = GX_RGB(tr, tg, tb);
        return;
    }
    out->col = GX_RGB(fr + num * (tr - fr) / den, fg + num * (tg - fg) / den, fb + num * (tb - fb) / den);
}
/* Segment 2 copy: the key colour is the FIRST parameter (`to`) and the
 * node colour the second (`from`); channels declared from/to per channel. */
static inline void ColLerp2(struct Out *out, s32 to, s32 from, u32 on, s32 num, s32 den)
{
    s32 fr = from & 0x1f;
    s32 tr = to & 0x1f;
    s32 fg = (from >> 5) & 0x1f;
    s32 tg = (to >> 5) & 0x1f;
    s32 fb = (from >> 10) & 0x1f;
    s32 tb = (to >> 10) & 0x1f;
    if (!on) {
        out->col = GX_RGB(tr, tg, tb);
        return;
    }
    out->col = GX_RGB(fr + num * (tr - fr) / den, fg + num * (tg - fg) / den, fb + num * (tb - fb) / den);
}
void SPL_EMITTER_EvalKey(struct Out *out, struct Ctx *ctx, s32 t)
{
    struct Key *k = ctx->key;
    s32 t0 = k->t0;
    struct Node *n = ctx->node;
    s32 t1 = k->t1;
    s32 t2 = k->t2;
    if (t < t0) {
        out->col = k->c0;
        return;
    }
    if (t < t1) {
        ColLerp(out, k->c0, n->col, k->f.on, t - t0, t1 - t0);
        return;
    }
    if (t < t2) {
        ColLerp2(out, k->c1, n->col, k->f.on, t - t1, t2 - t1);
        return;
    }
    out->col = k->c1;
}
