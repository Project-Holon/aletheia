/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202C72C
 * packet:   pkt_0202C6C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0202C72C
 *
 * symbols:
 *   sub_0202C6B8  0x0202C6B8  thumb
 *
 * The fourth dense switch of this family
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md) and the
 * exact complement of src/matched/unit_0202C760.c: states 0 and 2 answer 1
 * where 0x0202C760 answers 0, and the trailing `return 0` outside the
 * switch is what the `bhi` lands on. Four arms that produce only two
 * distinct values are still four separate two-instruction blocks; this
 * compiler does not cross-jump them, which is what makes the table's four
 * distinct displacements readable as four written case labels.
 *
 * Matched as a one-function unit rather than with `one` because the two
 * bytes of `00 00` at 0x0202C75E are the linker's inter-section fill
 * before 0x0202C760, so the listing extent is 52 where the function is 50
 * and `one` reports EXACT* for a padding gap rather than for an
 * unlabelled follower. `tu` compares the section as laid out and the
 * verdict is a clean EXACT.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202C72C.c \
 *       --addr 0x0202C72C --thumb
 */

typedef unsigned int u32;

extern u32 sub_0202C6B8(void *p);

u32 sub_0202C72C(void *p)
{
    switch (sub_0202C6B8(p)) {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
        return 0;
    }
    return 0;
}
