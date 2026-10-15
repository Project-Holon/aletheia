/*
 * unit:     no
 * function: NNSi_FndGetListAllocatableSize
 * address:  0x02060E94
 * packet:   pkt_02060E94
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   abs  0x02091588  arm
 *
 * Largest-free-space search over the allocator's block list hanging off the
 * heap object at +0x24.  Each node is {u32, u32 size, u32, Node *next} with
 * its payload at +0x10; the size passed in is first folded through
 * abs (abs), so it doubles as the alignment: the aligned start of
 * the candidate payload is (size - 1 + payload) & ~(size - 1), and what is
 * left between that start and the node's end (payload + size) is the space
 * on offer.  The winning node is the one with the most space, ties going to
 * the smaller offset; the amount is what comes back, or 0 if nothing fit.
 *
 * Notes on the codegen, all three of which are required to reach the
 * original's register assignment:
 *
 *  - `m` and `mask` are NOT locals in this file.  They are the two
 *    sub-expressions of the loop-invariant `start` computation, so the
 *    compiler hoists them into the loop preheader, which is emitted after
 *    the loop's entry test (the `beq` to the shared epilogue at +0x20).  As
 *    named locals they are emitted in source order before the test and the
 *    whole function's allocation shifts by one register.
 *  - The declaration order is size, best, ofs, blk.  That order is what puts
 *    the loop cursor in lr, `best` in r3 and `ofs` in ip; moving the cursor
 *    declaration earlier rotates those three the other way.
 *  - `ofs = -1` is spelled `sub ip, r3, #1`, i.e. rematerialised off the
 *    zero in `best` (docs/idioms/a-small-constant-is-rematerialised-off-a-
 *    zero-register-unless-an-argument-shares-it.md), and it is that, not
 *    `mvn ip, #0`, that shows in the original.  `best` being in r3 rather
 *    than r0 is also why the epilogue needs its `mov r0, r3`: 32 of the 33
 *    instructions of a version that hoists `best` into r0, which is
 *    otherwise byte-identical, and is what the "same size, register names
 *    only" trap looks like here.
 *
 * EXACT*, not EXACT: the inferred extent runs to 0x02060F50 (188 bytes)
 * because the code after this function's `pop` at 0x02060F18 has no
 * func_ label.  It is not padding and not a byte difference: 0x02060F18 is
 * a pair of unlabelled ARM leaf accessors (ldrh/and/bic/strh on the
 * halfword at +0x36, then ldrh/strh on +0x34, each ending in `bx lr`),
 * which disasm.py only auto-labels when a leaf saves lr.  Both want
 * seeding into layout/function_starts.txt, which is the integrator's file.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_FndGetListAllocatableSize.c \
 *       --func NNSi_FndGetListAllocatableSize --addr 0x02060E94 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

struct HeapBlock {
    u32 unk_00;
    u32 size;
    u32 unk_08;
    struct HeapBlock *next;
};

struct Heap {
    u8 pad_00[0x24];
    struct HeapBlock *head;
};

extern s32 abs(s32 x);

s32 NNSi_FndGetListAllocatableSize(struct Heap *heap, s32 x)
{
    s32 size = abs(x);
    u32 best = 0;
    u32 ofs = -1;
    struct HeapBlock *blk = heap->head;

    for (; blk != 0; blk = blk->next) {
        u32 data = (u32)blk + 0x10;
        u32 start = ((size - 1) + data) & ~(size - 1);
        u32 end = blk->size + data;

        if (start < end) {
            u32 amt = end - start;
            u32 off = start - data;

            if (best < amt || (best == amt && ofs > off)) {
                best = amt;
                ofs = off;
            }
        }
    }
    return best;
}
