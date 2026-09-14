/*
 * function: sub_02035428
 * address:  0x02035428
 * packet:   pkt_020353B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   PM_SetBackLight 0x0208BDD8  arm
 *
 * Retry PM_SetBackLight on the bottom screen until it reports success or a
 * thousand attempts have gone by.  The loop counter is assigned before the
 * hoisted screen selector, which is what puts `mov r5, #0` ahead of
 * `mov r4, #2`
 * (docs/idioms/assign-the-loop-counter-before-the-loop-bound-or-zero-costs-a-pool-word.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02035428.c \n *       --func sub_02035428 --addr 0x02035428 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern int PM_SetBackLight(u32 which, u32 status);

void sub_02035428(u32 status)
{
    int i;

    for (i = 0; i < 1000; i++) {
        if (PM_SetBackLight(2, status) == 0) {
            return;
        }
    }
}
