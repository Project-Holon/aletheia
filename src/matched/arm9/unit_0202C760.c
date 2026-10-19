/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202C760
 * packet:   pkt_0202C4CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: ISS_SWITCH_IsOffState
 *
 * symbols:
 *   sub_0202C6B8  0x0202C6B8  thumb
 *
 * A dense switch over the window's state accessor
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md), mapping
 * states 0..3 to a parity flag and anything above 3 to 0. Not itself one
 * of the named callee list, but sub_0202C688's only call to it has no
 * other witness in the image, so it needs its own EXACT entry before
 * sub_0202C688 can resolve. src/matched/unit_0202C72C.c is its exact
 * complement.
 *
 * Matched as a one-function unit rather than with `one` because the two
 * bytes of `00 00` at 0x0202C792 are the linker's inter-section fill
 * before 0x0202C794, so the listing extent runs two bytes past the
 * function and `one` reports EXACT* for a padding gap rather than for an
 * unlabelled follower. `tu` compares the section as laid out and the
 * verdict is a clean EXACT.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202C760.c \
 *       --addr 0x0202C760 --thumb
 */

typedef unsigned int u32;

struct Obj0202C6B8;
extern u32 sub_0202C6B8(struct Obj0202C6B8 *p);

u32 ISS_SWITCH_IsOffState(void *p)
{
    switch (sub_0202C6B8(p)) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 0;
    case 3:
        return 1;
    }
    return 0;
}
