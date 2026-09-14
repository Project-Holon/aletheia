/*
 * function: func_020306F0
 * address:  0x020306F0
 * packet:   pkt_02030608
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   MATCH
 *
 * symbols:
 *   sub_02030A5C   0x02030A5C  arm
 *   sub_0202FF98   0x0202FF98  arm
 *   sub_02030524   0x02030524  arm
 *   OS_Terminate   0x02088234  arm
 *
 * Heap teardown: run the pre-destroy hook, then destroy.  On failure ask
 * sub_02030524 for the current error policy and terminate under policies 1
 * and 2, the same policy read the rest of the heap layer does (see
 * src/matched/sub_0203084C.c, which spells the complementary
 * `!= 1 && != 2 && == 3` shape).
 *
 * The two arms each carry their own `bl OS_Terminate` and their own
 * epilogue rather than sharing one: that is what an `else if` chain of two
 * equality tests gives here, and it is also the evidence that the compiler
 * was not told OS_Terminate is noreturn, since a `pop` follows each call.
 *
 * The two arms must be a `switch`, not an `else if` chain.  Written as two
 * equality `if`s the compiler inlines the first arm on the fall-through
 * path (`bne` over a `bl`/`pop` pair) and the function comes out 64 bytes
 * instead of 68; the switch is what pushes both arms past the shared
 * `pop {r4, pc}` and leaves two forward `beq`s.
 *
 * Byte-correct, capped at MATCH: the PC24 at +0x10 (sub_0202FF98) has no
 * witness outside 020306F0..02030730.  func_020306F0 is 0x0202FF98's only
 * caller image-wide, so the `label` class is unavailable, the two are not
 * contiguous so no unit can make the site `local`, and there is no EXACT
 * entry for 0x0202FF98 to serve as a `matched` witness.  0x0202FF98 is a
 * 256-byte heap-destroy body with six further call sites of its own, so
 * unsticking this file means decompiling that, not finding more evidence.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020306F0.c \
 *       --func func_020306F0 --addr 0x020306F0 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void sub_02030A5C(void *heap);
extern u32  sub_0202FF98(void *heap);
extern u32  sub_02030524(void);
extern void OS_Terminate(void);

void func_020306F0(void *heap)
{
    sub_02030A5C(heap);

    if (sub_0202FF98(heap) == 0) {
        u32 state = sub_02030524();

        switch (state) {
        case 1:
            OS_Terminate();
            break;
        case 2:
            OS_Terminate();
            break;
        }
    }
}
