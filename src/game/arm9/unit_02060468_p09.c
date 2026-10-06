/*
 * file:     unit_02060468_p09.c
 * unit:     yes
 * function: func_02060E30, func_02060E6C, func_02060E94, func_02060F18, func_02060F40, func_02060F50, func_02060F90, func_02060F98
 * address:  0x02060E30
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02060764   0x02060764  arm
 *   func_02060790   0x02060790  arm
 *   func_02060B6C   0x02060B6C  arm
 *   func_02091588  0x02091588  arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct MBlock {
    u16            signature;
    u16            attr;
    u32            size;
    struct MBlock *prev;
    struct MBlock *next;
};

struct MBlockList {
    struct MBlock *head;
    struct MBlock *tail;
};

struct ExpHeap {
    u8                pad_00[0x24];
    struct MBlockList freeList;
    struct MBlockList usedList;
    u16               groupId;
    u16               feature;
};

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

extern void func_02060764(int *out, int *blk);
extern void *func_02060790(int *p, int *node);
extern int            func_02060B6C(struct MBlockList *list, int *info);
extern s32 func_02091588(s32 x);
int func_02060E6C(int *p);
u32 func_02060F18(char *p, u32 v);
u16 func_02060F40(char *p, u16 v);
void func_02060F50(int *p, void (*fn)(void *, void *, int), int ctx);
int func_02060F90(char *p);
u8 func_02060F98(char *p);


/*
 * The expanded heap's free primitive: read the block's own extent with
 * func_02060764, unlink its header from the heap's used list (+0x2c) and hand
 * the extent to func_02060B6C, which splices it back into the free list at
 * +0x24 and merges it with any adjacent free block.
 *
 * The 2-word extent is two separate scalars, not an int[2] and not a struct,
 * and that is load-bearing: mwcc caches the address of one object in a
 * callee-saved register (r4) across the second call when the two call sites
 * name the same object, collapsing `add r0, sp, #0` / `add r1, sp, #0` into
 * one `add r4, sp, #0` plus a `mov`, four bytes longer.  Two distinct
 * variables are different objects to its alias analysis, so each site
 * rematerialises `sp + 0` and the original's 60 bytes come out.
 *
 * The second site spells the base as `&end - 1`, since `end` is the *later*
 * declaration and mwcc lays locals out with the later declaration at the
 * lower address: `end` sits at sp+0 and `start` at sp+4, so `&end - 1` and the
 * block's own base (`&start`, as func_02060764 must be handed) are the same
 * word.  The pair is not a struct or an array: with one object named at both
 * sites the compiler folds the two addresses into one value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02060E30.c \
 *       --func func_02060E30 --addr 0x02060E30 --cc 1.1p1 --arm
 */
void func_02060E30(struct ExpHeap *heap, void *block)
{
    struct MBlock *hdr = (struct MBlock *)((u8 *)block - 0x10);
    int            end;
    int            start;

    func_02060764(&start, (int *)hdr);
    func_02060790((int *)(&heap->usedList), (int *)hdr);
    func_02060B6C(&heap->freeList, &end - 1);
}

int func_02060E6C(int *p)
{
    int *q = (int *)p[9];
    int total = 0;
    if (q == 0)
        return 0;
    do {
        total += q[1];
        q = (int *)q[3];
    } while (q != 0);
    return total;
}


/*
 * Largest-free-space search over the allocator's block list hanging off the
 * heap object at +0x24.  Each node is {u32, u32 size, u32, Node *next} with
 * its payload at +0x10; the size passed in is first folded through
 * func_02091588 (abs), so it doubles as the alignment: the aligned start of
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
 *   python tools/match.py one --src src/matched/func_02060E94.c \
 *       --func func_02060E94 --addr 0x02060E94 --cc 1.1p1 --arm
 */
s32 func_02060E94(struct Heap *heap, s32 x)
{
    s32 size = func_02091588(x);
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


/*
 * Setter: replaces bit 0 of the halfword at +0x36 and returns the old bit 0.
 * 2026-10-05 (wave D7 lane 18): closed by reading the old bit first
 * (`old = *h & 1`, which places the and before the orr) and doing the two
 * stores through a named u16 pointer local (plain `*h = *h & ~1; *h = *h | (v & 1)`).
 */
u32 func_02060F18(char *p, u32 v)
{
    u32 old = *(u16 *)(p + 0x36) & 1;
    u16 *h = (u16 *)(p + 0x36);
    *h = *h & ~1;
    *h = *h | (v & 1);
    return old;
}


/*
 * Setter: stores a halfword at +0x34 and returns the old value.
 */
u16 func_02060F40(char *p, u16 v)
{
    u16 old = *(u16 *)(p + 0x34);
    *(u16 *)(p + 0x34) = v;
    return old;
}

void func_02060F50(int *p, void (*fn)(void *, void *, int), int ctx)
{
    int *q = (int *)p[0xb];
    if (q == 0)
        return;
    do {
        int *next = (int *)q[3];
        fn((char *)q + 0x10, p, ctx);
        q = next;
    } while (q != 0);
}

int func_02060F90(char *p){ return *(int *)(p - 0xc); }


/*
 * 12-byte ARM leaf right after func_02060F90 (its sibling getter on the
 * same header, p - 0xc): "ldrh r0, [r0, #-0xe]; and r0, r0, #0xff; bx lr".
 * It saves nothing, so the prologue sweep prints it as .word data.  The
 * only call site in the image is the blx at ov009 0x02156FE4
 * (func_02156FDC), which needs this entry as its matched witness.
 */
u8 func_02060F98(char *p)
{
    return *(u16 *)(p - 0xe);
}
