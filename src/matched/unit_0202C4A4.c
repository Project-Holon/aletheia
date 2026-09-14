/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202C4A4
 * packet:   pkt_0202C3A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0202C4A4
 *
 * symbols:
 *   sub_0202C510  0x0202C510  thumb
 *   sub_0202C570  0x0202C570  thumb
 *   sub_0202C578  0x0202C578  thumb
 *
 * One of the six blocked callers of the trampoline run at 0x0202C548, and
 * the asymmetric broadcast: slot 0 gets one operation and slots 1 to 8
 * get another, which is what the peeled first iteration in front of the
 * loop is. `movs r1, #0` sits before the pointer copy because the index
 * of the peeled call is a literal and the loop's `movs r4, #1` is not
 * rematerialised from it
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * What closed it: sub_0202C570 and sub_0202C578 are both trampolines of
 * src/matched/unit_0202C558.c, so the `matched` class witnesses both
 * sites; neither is the target of any other branch in the image.
 *
 * The loop counter is signed, the same `blt` tell as
 * src/matched/unit_0202C470.c. Matched as a one-function unit because the
 * range ends exactly at func_0202C4C8, an unlabelled leaf matched
 * separately as src/matched/sub_0202C4C8.c, so the listing extent runs
 * four bytes long into it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202C4A4.c \
 *       --addr 0x0202C4A4 --thumb
 */

typedef signed int s32;

extern void *sub_0202C510(void *p, s32 idx);
extern void sub_0202C570(void *w);
extern void sub_0202C578(void *w);

void sub_0202C4A4(void *p)
{
    s32 i;

    sub_0202C570(sub_0202C510(p, 0));
    for (i = 1; i < 9; i++) {
        sub_0202C578(sub_0202C510(p, i));
    }
}
