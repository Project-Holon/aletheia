/*
 * function: PALANM_StepFadeValue
 * address:  0x02021CA8
 * packet:   pkt_02021B6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Steps or clears one slider on the record at `s`. The halfword at s+2 is
 * three fields: lo6:6, cur:5, max:5. When cur has already reached max, the
 * function instead toggles bit `idx` of the 14-bit flag field at p[0x118]
 * bits[2:16) (pool word 0xFFFF0003 preserves the low two bits) and returns,
 * doing nothing at all if that bit was already clear. Otherwise the sign bit
 * of the halfword at s+4 picks the direction and s->step (5 bits at s+6) the
 * amount: cur moves up and is clamped down to max, or down and clamped up to
 * max, and is written back through pool word 0xFFFFF83F.
 *
 * Three things the earlier note (docs/notes/PALANM_StepFadeValue.c.txt) left open,
 * all settled here:
 *   - the write target in blocks 2a/2b really is `cur` (bits[6:11)), which
 *     is what 0xFFFFF83F clears; the note's own "re-check before trusting
 *     this paragraph" was right to doubt the bits[11:16) reading.
 *   - blocks 2a and 2b each carry their own copy of the read-mask-or-store
 *     writeback. Factoring it out after the if/else costs a register and the
 *     `pop {r4,r5}` grows to `pop {r3,r4,r5,r6}`.
 *   - the value sign-extended at the top of each arm is `(s16)s->cur`, the
 *     already-extracted 5-bit field, NOT a fresh s16 read of the raw
 *     halfword at s+2. Both spell `lsls #0x10; asrs #0x10`, but reading the
 *     raw halfword keeps it live in a fifth register across the whole
 *     function and was the last 105 bytes of the diff; using the field
 *     lets the compiler re-derive it and closes the function outright.
 * The p[0x118] flag field is the same bits[2:16) register PALANM_StepFadeWait
 * uses, as the note suspected.
 */
#include "../include/Obj06878.h"
#include "../include/Obj08779.h"
typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed   short s16;
typedef unsigned int   u32;
typedef signed   int   s32;

struct S {
    u16 f0;
    u16 lo6 : 6;
    u16 cur : 5;
    u16 max : 5;
    u16 dir : 15;
    u16 sign : 1;
    u16 step : 5;
};

void PALANM_StepFadeValue(u8 *p, u32 idx, struct S *s)
{
    u32 bit;
    u32 flags;
    s32 v;

    if (s->cur == s->max) {
        bit = 1 << idx;
        flags = ((u32)((struct Obj08779 *)p)->f118 << 0x10) >> 0x12;
        if (flags & bit) {
            ((struct Obj08779 *)p)->f118 =
                (u16)((((struct Obj08779 *)p)->f118 & 0xFFFF0003)
                      | (((flags ^ (u16)bit) << 0x12) >> 0x10));
        }
        return;
    }

    if (!s->sign) {
        v = (s16)((s16)s->cur + (s32)s->step);
        if (v > (s32)s->max) {
            v = (s16)s->max;
        }
        ((struct Obj06878 *)s)->f2 =
            (u16)((((struct Obj06878 *)s)->f2 & 0xFFFFF83F)
                  | (((u32)(u16)v << 0x1b) >> 0x15));
    } else {
        v = (s16)((s16)s->cur - (s32)s->step);
        if (v < (s32)s->max) {
            v = (s16)s->max;
        }
        ((struct Obj06878 *)s)->f2 =
            (u16)((((struct Obj06878 *)s)->f2 & 0xFFFFF83F)
                  | (((u32)(u16)v << 0x1b) >> 0x15));
    }
}
