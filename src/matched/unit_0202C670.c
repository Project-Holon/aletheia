/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202C670
 * packet:   pkt_0202C4CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0202C670
 *
 * symbols:
 *   sub_0202C72C  0x0202C72C  thumb
 *   sub_0202C6BC  0x0202C6BC  thumb
 *
 * One of the four open trampoline targets of src/matched/unit_0202C558.c
 * (reached through sub_0202C560's pool-word-and-bx tail call). Tests the
 * window's state accessor and, unless it already reads 1, resets the
 * object to state 2. sub_0202C72C is called from a second site outside
 * this range, so its target resolves through the `label` class.
 *
 * Matched as a one-function unit rather than with `one` because the two
 * bytes of `00 00` at 0x0202C686 are the linker's inter-section fill
 * before 0x0202C688, so the listing extent runs two bytes past the
 * function and `one` reports EXACT* for a padding gap rather than for an
 * unlabelled follower. `tu` compares the section as laid out and the
 * verdict is a clean EXACT.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202C670.c \
 *       --addr 0x0202C670 --thumb
 */

typedef unsigned int u32;

extern u32 sub_0202C72C(void *p);
extern u32 sub_0202C6BC(void *p, u32 v);

u32 sub_0202C670(void *p)
{
    if (sub_0202C72C(p) != 1) {
        sub_0202C6BC(p, 2);
    }
}
