/*
 * unit:     no
 * address:  0x02045A38
 * packet:   pkt_020452E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_02045A38
 *
 * symbols:
 *   g_020A7E7C  0x020A7E7C  data
 *
 * Copies at most `n` slots out of a u16-array object into a caller's
 * buffer, stopping after the slot that equals the stamp, and forcing a
 * stamp into the last output slot if the loop ran to the limit without
 * finding one. In other words the stamp is this container's terminator
 * value and this is its bounded, always-terminated extraction.
 *
 * Two shape tells worth keeping:
 *
 *  - The stamp is re-read from the global on every iteration
 *    (`ldrh ip, [r3]` inside the loop, from a pool base hoisted out of
 *    it). It is not volatile: the store into the caller's buffer may
 *    alias it, so the load cannot be hoisted. Caching it in a local
 *    before the loop removes the reload and shortens the body.
 *  - The final store is written as a pointer expression, not a subscript.
 *    `add r1, r1, r2, lsl #1` followed by `strh r0, [r1, #-2]` scales,
 *    adds, then subtracts the element size, which is what
 *    `*(out + n - 1)` produces; `out[n - 1]` folds to a single scaled
 *    offset instead
 *    (docs/idioms/pointer-minus-one-scales-before-the-subtraction.md).
 *
 * The loop is the compiler's usual rotation of a counted `for`: a
 * zero-trip guard at the top, the increment and the bound test at the
 * bottom, and the `break` falling straight into the `i == n` test that
 * distinguishes "found the terminator" from "ran out of room". Because
 * `break` leaves the counter un-incremented, that one comparison is the
 * whole post-condition and no separate flag is needed. The entire tail is
 * predicated on `eq`, so it costs no branch.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045A38.c \
 *       --func sub_02045A38 --addr 0x02045A38 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

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
struct AllocStamp {
    u16  value;      /* 0x020A7E7C, the stamp every object copies to +0x8 */
    u16  pad;
    char site[1];    /* 0x020A7E80, the allocator's fourth argument */
};

extern struct AllocStamp g_020A7E7C;

void sub_02045A38(struct U16Vec *vec, u16 *out, u32 n)
{
    u32 i;
    u16 v;

    for (i = 0; i < n; i++) {
        v = vec->slots[i];
        out[i] = v;
        if (g_020A7E7C.value == v) {
            break;
        }
    }
    if (i == n) {
        *(out + n - 1) = g_020A7E7C.value;
    }
}
