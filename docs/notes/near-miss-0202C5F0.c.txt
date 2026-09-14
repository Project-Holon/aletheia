/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202C5F0
 * packet:   pkt_0202C4CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * function: sub_0202C5F0, sub_0202C630, sub_0202C634
 *
 * symbols:
 *   sub_0202C6B8  0x0202C6B8  thumb
 *   sub_0202C638  0x0202C638  thumb
 *   sub_0202C654  0x0202C654  thumb
 *
 * One of the four open trampoline targets of src/pending/unit_0202C548.c
 * (reached through sub_0202C580's pool-word-and-bx tail call). It is a
 * dense switch over the window's state accessor
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md), and two
 * of its four cases are trivial `bx lr` stubs with no prologue
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md) that sit
 * between the switch and the next labelled function, so the whole
 * 72-byte range is matched as one unit rather than one function.
 *
 * Codegen near miss, not evidence: every concrete byte matches except
 * two register letters (r0 against r1) in the five-instruction dispatch
 * sequence that computes the jump table index. This compiler picks r1
 * for the switch value here, against r0 in the otherwise identical shape
 * at 0x0202C72C and at src/matched/sub_0202C760.c; renaming the switch
 * variable, adding a trailing `return`, reversing case order and marking
 * it `register` all reproduce the same r1 choice. sub_0202C638 and
 * sub_0202C654 both resolve (both are src/matched/sub_0202C638.c and
 * src/matched/sub_0202C654.c, EXACT), so this is the only thing still
 * open in the range.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/unit_0202C5F0.c \
 *       --addr 0x0202C5F0 --thumb --diff
 */

typedef unsigned int u32;

extern u32 sub_0202C6B8(void *p);
extern u32 sub_0202C638(void *p);
extern u32 sub_0202C654(void *p);

u32 sub_0202C630(void *p);
u32 sub_0202C634(void *p);

u32 sub_0202C5F0(void *p)
{
    u32 state = sub_0202C6B8(p);

    switch (state) {
    case 0:
        return sub_0202C630(p);
    case 1:
        return sub_0202C634(p);
    case 2:
        return sub_0202C638(p);
    case 3:
        return sub_0202C654(p);
    }
}

u32 sub_0202C630(void *p)
{
}

u32 sub_0202C634(void *p)
{
}
