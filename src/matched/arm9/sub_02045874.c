/*
 * unit:     no
 * address:  0x02045874
 * packet:   pkt_020452E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_02045874
 *
 * symbols:
 *   sub_020457B0  0x020457B0  arm
 *   sub_02045838  0x02045838  arm
 *
 * Clones a u16-array object: allocate one with exactly enough room
 * (used + 1 slots, the +1 being the stamp slot that sub_02045838's guard
 * insists on), then copy into it.
 *
 * The heap id is never touched in this function's body. sub_020457B0
 * takes (capacity, heapId) and only r0 is set up here, so r1 arrives
 * untouched from this function's own second parameter: the shape of
 * docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md
 * read in reverse, where the "leftover" register really is a passed
 * argument and naming it is what makes the code compile to two
 * instructions instead of three.
 *
 * `used + 1` reaches sub_020457B0 with no narrowing, which is what pins
 * that function's first parameter to a full word rather than the u16 its
 * own body would suggest: see
 * docs/idioms/a-missing-truncation-at-the-call-site-widens-the-parameter.md.
 * With a u16 prototype this function comes out eight bytes long and
 * sub_020457B0 still matches, so the call site is the only evidence for
 * the width.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045874.c  *       --func sub_02045874 --addr 0x02045874 --cc 1.1p1 --arm
 */

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

extern struct U16Vec *sub_020457B0(u32 capacity, u32 heapId);
extern void sub_02045838(struct U16Vec *dst, struct U16Vec *src);

struct U16Vec *sub_02045874(struct U16Vec *src, u32 heapId)
{
    struct U16Vec *dst;

    dst = sub_020457B0(src->used + 1, heapId);
    sub_02045838(dst, src);
    return dst;
}
