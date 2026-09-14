/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202C518
 * packet:   pkt_0202C518
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0202C518
 *
 * symbols:
 *   sub_0202C510  0x0202C510  thumb
 *   sub_0202C588  0x0202C588  thumb
 *
 * The last of the six blocked callers of the trampoline run at
 * 0x0202C548: the same nine-slot broadcast as
 * src/matched/unit_0202C470.c, but the operation takes a second argument
 * and it is the constant 0x7F that sub_0202C6C4 produces as a full-scale
 * fraction. 0x7F is hoisted into r6 before the loop and copied into r1
 * inside it, which is why the prologue saves r4, r5 and r6 where
 * unit_0202C470.c saves r3, r4 and r5.
 *
 * What closed it: sub_0202C588 is the last trampoline of
 * src/matched/unit_0202C558.c, so the `matched` class witnesses the site.
 *
 * The loop counter is signed, the same `blt` tell as
 * src/matched/unit_0202C470.c. Matched as a one-function unit because the
 * two bytes of `00 00` at 0x0202C536 are the linker's inter-section fill
 * before 0x0202C538.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202C518.c \
 *       --addr 0x0202C518 --thumb
 */

typedef signed int   s32;
typedef unsigned int u32;

extern void *sub_0202C510(void *p, s32 idx);
extern void sub_0202C588(void *w, u32 v);

void sub_0202C518(void *p)
{
    s32 i;

    for (i = 0; i < 9; i++) {
        sub_0202C588(sub_0202C510(p, i), 0x7F);
    }
}
