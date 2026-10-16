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
 * function: GFL_HEAP_GetHeapHeadChecked
 *
 * Promoted from MATCH with no change to the C. The call to GFL_HEAP_IsHeapValid at
 * +0004 was the one unresolved site: 0x020304CC's only branch reference in
 * the image is this call, so no `label` witness exists. It closed when
 * src/matched/GFL_HEAP_IsHeapValid.c landed EXACT, which makes the site `matched`.
 *
 * Asserting wrapper around GFL_HEAP_IsHeapValid, the same shape as GFL_HEAP_GetHeapHead
 * but with the assertion itself gated on the heap-layer state word.
 *
 *   void *GFL_HEAP_GetHeapHeadChecked(u32 heapId)
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
 *   GFL_HEAP_IsHeapValid    0x020304CC  arm
 *   sub_02030524    0x02030524  arm
 *   OS_Terminate    0x02088234  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_GetHeapHeadChecked.c \
 *       --func GFL_HEAP_GetHeapHeadChecked --addr 0x0203084C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 GFL_HEAP_IsHeapValid(u32 heapId);
typedef unsigned short u16;
extern u16 sub_02030524(void);
extern void OS_Terminate(void);

void *GFL_HEAP_GetHeapHeadChecked(u32 heapId)
{
    void *p;
    u32 state;

    p = (void *)GFL_HEAP_IsHeapValid(heapId);
    if (p == 0) {
        state = sub_02030524();
        if (state != 1 && state != 2 && state == 3) {
            OS_Terminate();
        }
    }
    return p;
}
