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
 * function: STRBUF_Clone
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_Copy  0x02045838  arm
 *
 * Clones a u16-array object: allocate one with exactly enough room
 * (used + 1 slots, the +1 being the stamp slot that STRBUF_Copy's guard
 * insists on), then copy into it.
 *
 * The heap id is never touched in this function's body. STRBUF_Create
 * takes (capacity, heapId) and only r0 is set up here, so r1 arrives
 * untouched from this function's own second parameter: the shape of
 * docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md
 * read in reverse, where the "leftover" register really is a passed
 * argument and naming it is what makes the code compile to two
 * instructions instead of three.
 *
 * `used + 1` reaches STRBUF_Create with no narrowing, which is what pins
 * that function's first parameter to a full word rather than the u16 its
 * own body would suggest: see
 * docs/idioms/a-missing-truncation-at-the-call-site-widens-the-parameter.md.
 * With a u16 prototype this function comes out eight bytes long and
 * STRBUF_Create still matches, so the call site is the only evidence for
 * the width.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_Clone.c  *       --func STRBUF_Clone --addr 0x02045874 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

/*
 * The object's tail is one u16 array based at +0x8, not a scalar stamp
 * followed by a separate entry array: STRBUF_Truncate indexes it from zero
 * with `add r3, r0, r1, lsl #1` / `strh r2, [r3, #8]`, and STRBUF_Copy
 * copies (used + 1) halfwords starting at +0x8. Slot 0 is the stamp
 * STRBUF_Create seeds from g_020A7E7C; slots 1.. are the payload.
 */
struct U16Vec {
    u16 capacity;
    u16 used;
    u32 magic;
    u16 slots[1];
};

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_Copy(struct U16Vec *dst, struct U16Vec *src);

struct U16Vec *STRBUF_Clone(struct U16Vec *src, u32 heapId)
{
    struct U16Vec *dst;

    dst = STRBUF_Create(src->used + 1, heapId);
    STRBUF_Copy(dst, src);
    return dst;
}
