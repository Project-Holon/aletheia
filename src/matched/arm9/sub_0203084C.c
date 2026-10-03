/*
 * unit:     no
 * address:  0x0203084C
 * packet:   pkt_020307E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_0203084C
 *
 * Promoted from MATCH with no change to the C. The call to sub_020304CC at
 * +0004 was the one unresolved site: 0x020304CC's only branch reference in
 * the image is this call, so no `label` witness exists. It closed when
 * src/matched/sub_020304CC.c landed EXACT, which makes the site `matched`.
 *
 * Asserting wrapper around sub_020304CC, the same shape as sub_02030830
 * but with the assertion itself gated on the heap-layer state word.
 *
 *   void *sub_0203084C(u32 heapId)
 *
 * The guard is one three-term conjunction, and the way it splits across
 * the instructions is what pins that reading: `cmp r0, #1` / `cmpne r0,
 * #2` is the conditional-compare fold of the first two terms into a single
 * `beq`, and the third term gets its own `cmp r0, #3` / `bne`. The third
 * term subsumes the first two, so as written the test is just `state ==
 * 3`; the compiler does not simplify it, and writing only `state == 3`
 * loses the first two comparisons and eight bytes. The redundancy is
 * evidence that the original spelled three named state constants.
 *
 * symbols:
 *   sub_020304CC    0x020304CC  arm
 *   sub_02030524    0x02030524  arm
 *   OS_Terminate    0x02088234  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203084C.c \
 *       --func sub_0203084C --addr 0x0203084C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void *sub_020304CC(u32 heapId);
typedef unsigned short u16;
extern u16 sub_02030524(void);
extern void OS_Terminate(void);

void *sub_0203084C(u32 heapId)
{
    void *p;
    u32 state;

    p = sub_020304CC(heapId);
    if (p == 0) {
        state = sub_02030524();
        if (state != 1 && state != 2 && state == 3) {
            OS_Terminate();
        }
    }
    return p;
}
