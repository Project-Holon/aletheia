/*
 * function: func_0201C974
 * address:  0x0201C974
 * packet:   pkt_0201C974
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201CAC8  0x0201CAC8  thumb
 *   func_0201CC34  0x0201CC34  thumb
 *
 * printsys.c: the glyph-run interpreter.  Walks the halfword string `p`
 * rendering one glyph per call to the renderer hook at PrintCtx+0x18 and
 * returns the cursor one halfword past the glyph it drew; 0xFFFF (end) and a
 * 0xF000 control block whose code byte is 0xBE with `f == 0` return the
 * cursor unchanged.
 *
 * Three facts the bytes pin, each one worth a whole spelling:
 *
 *  1. PrintCtx+0x04 is a SIGNED 10-BIT BITFIELD, not the `u32` flag word
 *     docs/families/printsys.h had.  The 0xFFFE (line break) arm reads it as
 *     `lsls #0x16 / asrs #0x16`, a 22-bit equal-width pair with a signed right
 *     half, which only `s32 :10` produces
 *     (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).  Spelled
 *     `u32` the store is a bare `strh` and the pair is gone.
 *
 *  2. The control-code dispatch is a SWITCH, not an if/else chain.  The
 *     original tests 0xBD, 0xBE, 0xFF with three forward `beq`s and a final
 *     `b default`; an if/else chain of the same three tests emits `bne` skips
 *     instead and costs 86 concrete bytes here.  The switch is sparse (0xBD,
 *     0xBE, 0xFF), so no jump table appears, only the compare chain.
 *
 *  3. The 0xBE arm's guard is spelled `if (f != 0) { ...; break; } return p;`
 *     and NOT `if (f == 0) return p;`.  The original's `cmp r1, #0 / beq` puts
 *     the return out of line as the TAKEN target; the equality form emits
 *     `bne` and mirrors the last seven instructions
 *     (docs/idioms/the-fall-through-arm-is-the-source-order.md).  This was the
 *     last 13 concrete bytes.
 *
 * The block-layout shape also matters: the glyph body is reached by an
 * explicit `goto glyph` to a label AFTER the `while (1)`, which is what places
 * it physically last (at +0x8E) rather than in the middle.  Written as the
 * final `else` arm of the chain the compiler sinks the F000 block instead and
 * the function comes out 180 bytes, four short.
 *
 * The redundant inner `if (v == 0xF000) k = (u8)(p[1] >> 8); else k = 0xFF;`
 * inside the F000 arm is real: the original repeats the same `cmp r0, r7` test
 * (at +0x3C, reusing the flags of the outer one at +0x12) rather than assuming
 * it.  That is an inlined code-fetch helper, and collapsing it to a plain
 * `k = (u8)(p[1] >> 8)` loses the `bne`/`movs #0xff` pair.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct PrintCtx {
    s16   unk00;
    s16   unk02;
    s32   unk04 : 10;
    u32   unk04b : 22;
    u16   unk08;
    u16   unk0A;
    u16   unk0C;
    u16   unk0E;
    void *unk10;
    void *unk14;
    void (*unk18)(void *a, s32 b, s32 c, void *d, u16 e, u8 *f);
};

extern u16 *func_0201CAC8(struct PrintCtx *c, u16 *p);
extern u16 *func_0201CC34(struct PrintCtx *c, u16 *p);

u16 *func_0201C974(struct PrintCtx *c, u16 *p, u32 f)
{
    u8 pen[4];
    s16 *py = &c->unk02;

    while (1) {
        u16 v = *p;
        if (v != 0xF000) {
            if (v != 0xFFFE) {
                if (v == 0xFFFF) {
                    return p;
                }
                goto glyph;
            }
            c->unk00 = (s16)c->unk04;
            p = p + 1;
            *py = (s16)(*py + 0x10);
            continue;
        }
        {
            u32 k;
            if (v == 0xF000) {
                k = (u8)(p[1] >> 8);
            } else {
                k = 0xFF;
            }
            switch (k) {
            case 0xBD:
                p = func_0201CAC8(c, p);
                break;
            case 0xFF:
                p = func_0201CC34(c, p);
                break;
            case 0xBE:
                if (f != 0) {
                    if (v != 0xF000) {
                        continue;
                    }
                    p = (u16 *)((u8 *)(p + 3) + p[2] * 2);
                    break;
                }
                return p;
            default:
                if (v != 0xF000) {
                    continue;
                }
                p = (u16 *)((u8 *)(p + 3) + p[2] * 2);
                break;
            }
        }
    }
  glyph:
    {
        u16 v = *p;
        c->unk18(c->unk14, c->unk00, c->unk02, c->unk10, v, pen);
        c->unk00 = (s16)(c->unk00 + pen[2]);
        return p + 1;
    }
}
