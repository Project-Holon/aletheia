/*
 * function: BLINK_PALANM_Update
 * address:  0x0202EA40
 * packet:   pkt_0202EA40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_020A1B38  0x020A1B38  data
 *   func_02061CA4  0x02061CA4  arm
 *
 * blink_palanm.c: the per-frame BGR555 cross-fade.  Advances the phase word
 * at +0x10 by 0x400 (wrapping at 0x10000), takes the fade scale as
 * (table[phase >> 4 pair, second entry] + 0x1000) / 2 from the signed table
 * at 0x020A1B38, blends every pixel of the src row toward the dst row into
 * the output row, then hands the output row to func_02061CA4.
 *
 * Two facts closed it (wave 13).  The pixels are u16 locals, not s32: with
 * `s32 b` the dst channel extraction is scheduled differently (46 out).  And
 * the final pack is `(r << 10) | (bl | (g << 5))`: the channel ORed last is
 * the one the compiler evaluates FIRST, so red is blended and held, then
 * blue, then green, exactly the image's order; the left-nested
 * `(r << 10) | (g << 5) | bl` evaluates green before blue.
 *
 * EXACT* because the listing extent runs 8 bytes long: the unlabelled leaf
 * at 0x0202EB04 (src/matched/BLINK_PALANM_ResetPhase.c) follows the pool word.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

struct Row {
    u16 *src;
    u16 *dst;
    u16 *out;
    u16 unk0c;
    u16 count;
    u16 phase;
    u32 unk14;
};

extern s16 g_020A1B38[];
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);

s32 BLINK_PALANM_Update(struct Row *p)
{
    s32 scale;
    u32 i;
    u16 a;
    u16 b;
    s32 r;
    s32 g;
    s32 bl;

    if (p->phase + 0x400 >= 0x10000) {
        p->phase = p->phase - 0xFC00;
    } else {
        p->phase = p->phase + 0x400;
    }

    scale = (g_020A1B38[((p->phase >> 4) << 1) + 1] + 0x1000) / 2;

    for (i = 0; i < p->count; i++) {
        a = p->src[i];
        b = p->dst[i];
        r = (u8)(((a >> 10) & 0x1f)
                 + (((((b >> 10) & 0x1f) - ((a >> 10) & 0x1f)) * scale) >> 12));
        bl = (u8)((a & 0x1f)
                  + ((((b & 0x1f) - (a & 0x1f)) * scale) >> 12));
        g = (u8)(((a >> 5) & 0x1f)
                 + (((((b >> 5) & 0x1f) - ((a >> 5) & 0x1f)) * scale) >> 12));
        p->out[i] = (u16)((r << 10) | (bl | (g << 5)));
    }

    return func_02061CA4((void *)p->unk14, p->unk0c * 2, (u32)p->out, p->count * 2);
}
