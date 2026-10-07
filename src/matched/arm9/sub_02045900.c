/*
 * unit:     no
 * address:  0x02045900
 * packet:   pkt_020452E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_02045900
 *
 * symbols:
 *   g_020A7E7C  0x020A7E7C  data
 *
 * Truncates a u16-array object back to `index` slots, writing the stamp
 * into the slot that becomes the new terminator. It is the inverse of
 * whatever appends, and it is a no-op when `index` is not strictly below
 * the current count, so it can only ever shrink.
 *
 * The whole body is predicated on `lo` with no branch at all, which is
 * why the guard has to be an unsigned comparison: `index` is a full u32
 * (nothing masks it before `add r3, r0, r1, lsl #1`) while `used` is a
 * zero-extended u16, so the comparison is unsigned on both sides and a
 * signed `int` index produces `lt` instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045900.c  *       --func sub_02045900 --addr 0x02045900 --cc 1.1p1 --arm
 */

#include "../include/G_AllocStamp.h"

typedef unsigned short u16;
typedef unsigned int u32;

/*
 * The object's tail is one u16 array based at +0x8, not a scalar stamp
 * followed by a separate entry array: sub_02045900 indexes it from zero
 * with `add r3, r0, r1, lsl #1` / `strh r2, [r3, #8]`, and sub_02045838
 * copies (used + 1) halfwords starting at +0x8. Slot 0 is the stamp
 * sub_020457B0 seeds from g_020A7E7C; slots 1.. are the payload.
 */
struct U16Vec {
    u16 capacity;
    u16 used;
    u32 magic;
    u16 slots[1];
};

/*
 * The global based at 0x020A7E7C is one small object, not two independent
 * words: sub_020457B0 loads 0x020A7E80 out of a pool as the allocator's
 * fourth argument, and that word is this symbol plus four
 * (docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md).
 * Reading it as a separate object splits one symbol into two and loses
 * the relocation: 0x020A7E80 has exactly one pool reference image-wide
 * and so no witness of its own, while the base has thirty-six.
 */

extern struct AllocStamp g_020A7E7C;

void sub_02045900(struct U16Vec *vec, u32 index)
{
    if (index < vec->used) {
        vec->slots[index] = g_020A7E7C.value;
        vec->used = index;
    }
}
