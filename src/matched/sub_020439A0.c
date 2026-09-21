/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * function: func_020439A0
 * address:  0x020439A0
 * packet:   pkt_0204384C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02043B98  0x02043B98  arm
 *   func_02043F4C  0x02043F4C  arm
 *   func_020445F4  0x020445F4  arm
 *   func_02044954  0x02044954  arm
 *
 * bmp.c's nine-argument blit dispatcher.  Source and destination must agree
 * on the halfword at +8; after that the halfword at +0xA of the source picks
 * one of two families and the +8 value picks between the 0x20 member of that
 * family and the general one.
 *
 * The two families have different prototypes, and that is what the shift
 * pairs in the second arm are: the 0x020445F4 family takes the two register
 * coordinates and the last two stack arguments as `u16` and the middle two
 * as `s16`, so every one of the six is re-extended at the call
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md
 * does not apply; these are equal-amount pairs, plain narrowing casts).  The
 * 0x02043B98 family takes all nine wide and needs none of it.  This
 * function's own parameters must therefore be the wide types: a `u16`
 * parameter would arrive already extended and the call would not re-extend
 * it.
 *
 * Both branch polarities are the source order
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md): the `!= 2` arm
 * falls through, and inside each arm the `== 0x20` arm falls through.  The
 * five outgoing stack stores are written out in both arms of the first
 * family and the compiler tail-merges them ahead of the `cmp`
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md); in the
 * second family it keeps two copies instead, because the narrowing makes the
 * two blocks different lengths.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020439A0.c \
 *       --func func_020439A0 --addr 0x020439A0 --cc 1.1p1 --arm
 */

typedef short          s16;
typedef unsigned short u16;
typedef unsigned char  u8;
typedef unsigned int   u32;

struct Bmp {
    u8  pad00[8];
    u16 unk08;
    u16 unk0A;
};

extern void func_02043B98(struct Bmp *dst, struct Bmp *src, u32 x, u32 y,
                          int sx, int sy, u32 w, u32 h, u32 key);
extern void func_02043F4C(struct Bmp *dst, struct Bmp *src, u32 x, u32 y,
                          int sx, int sy, u32 w, u32 h, u32 key);
extern void func_020445F4(struct Bmp *dst, struct Bmp *src, u16 x, u16 y,
                          s16 sx, s16 sy, u16 w, u16 h, u32 key);
extern void func_02044954(struct Bmp *dst, struct Bmp *src, u16 x, u16 y,
                          s16 sx, s16 sy, u16 w, u16 h, u32 key);

void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y,
                   int sx, int sy, u32 w, u32 h, u32 key)
{
    if (dst->unk08 != src->unk08) {
        return;
    }
    if (src->unk0A != 2) {
        if (dst->unk08 == 0x20) {
            func_02043B98(dst, src, x, y, sx, sy, w, h, key);
        } else {
            func_02043F4C(dst, src, x, y, sx, sy, w, h, key);
        }
    } else {
        if (dst->unk08 == 0x20) {
            func_020445F4(dst, src, x, y, sx, sy, w, h, key);
        } else {
            func_02044954(dst, src, x, y, sx, sy, w, h, key);
        }
    }
}
