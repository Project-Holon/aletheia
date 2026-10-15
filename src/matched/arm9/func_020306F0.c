/*
 * function: GFL_HEAP_DeleteChecked
 * address:  0x020306F0
 * packet:   pkt_02030608
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   GFL_HEAP_DumpIfLive   0x02030A5C  arm
 *   GFL_HEAP_Delete   0x0202FF98  arm
 *   sub_02030524   0x02030524  arm
 *   OS_Terminate   0x02088234  arm
 *
 * Heap teardown: run the pre-destroy hook, then destroy.  On failure ask
 * sub_02030524 for the current error policy and terminate under policies 1
 * and 2, the same policy read the rest of the heap layer does (see
 * src/matched/GFL_HEAP_GetHeapHeadChecked.c, which spells the complementary
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
 * The PC24 at +0x10 (GFL_HEAP_Delete) has no `label` witness: GFL_HEAP_DeleteChecked
 * is 0x0202FF98's only caller image-wide, and the two are not contiguous,
 * so no unit can make the site `local` either.  It resolves on class
 * `matched` against src/matched/GFL_HEAP_Delete.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_DeleteChecked.c \
 *       --func GFL_HEAP_DeleteChecked --addr 0x020306F0 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void GFL_HEAP_DumpIfLive(u32 heap);
extern u32  GFL_HEAP_Delete(u32 heap);
typedef unsigned short u16;
extern u16 sub_02030524(void);
extern void OS_Terminate(void);

void GFL_HEAP_DeleteChecked(u32 heap)
{
    GFL_HEAP_DumpIfLive(heap);

    if (GFL_HEAP_Delete(heap) == 0) {
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
