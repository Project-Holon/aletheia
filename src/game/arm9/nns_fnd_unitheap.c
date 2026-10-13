/*
 * file:     nns_fnd_unitheap.c
 * unit:     yes
 * function: func_02061224, func_0206123C, func_0206127C, func_0206128C, func_020612A0, func_020612B0, func_020612C4, func_020612C8, func_020612E8, func_020612F8, func_02061314, func_02061330, func_02061344, func_02061358, func_02061370, func_02061378, func_02061380, func_02061388, func_02061390, func_020613D8, func_02061460, func_020614D4, func_02061644, func_0206164C, func_0206168C
 * address:  0x02061224
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MIi_CpuClear32  0x02082A7C  arm
 *   func_02060CA0  0x02060CA0  arm
 *   func_02060E30  0x02060E30  arm
 *   func_02061124  0x02061124  arm
 *   func_020868E0  0x020868E0  arm
 *   func_020869E8  0x020869E8  arm
 *   g_020A1708     0x020A1708  data
 *   g_020A8150     0x020A8150  data
 *   g_020A816C     0x020A816C  data
 *   g_02146B70      0x02146B70  data
 *   NNS_GfdDefaultFuncAllocTexVram      0x020A8140  data
 *   NNS_GfdDefaultFuncFreeTexVram      0x020A8144  data
 *   g_020A8158  0x020A8158  data
 */
struct ExpHeap;
struct Big0206123C;
struct UnitHeap0206127C;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Big0206123C {
    u32 w[8];
    u32 unk20;
    u32 unk24;
    u32 unk28;
};

struct UnitBlock0206127C {
    struct UnitBlock0206127C *next;
};

struct UnitHeap0206127C {
    u32 head[9];
    struct UnitBlock0206127C *freeList;
};

typedef signed int   s32;

struct Allocator02061 {
    void *funcs;
    void *heap;
    u32 param1;
    u32 param2;
};

struct Inner020612C8 {
    u32 w[10];
    u32 unk28;
};

struct Obj020612C8 {
    u32 unk0;
    struct Inner020612C8 *inner;
};

typedef void (*Vfn)(void *self, u32 x);

struct Vt02061330 { Vfn f0; Vfn f1; };

struct Obj02061330 { struct Vt02061330 *vt; };

struct S02061358 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
};

struct Slot {
    u32 cur;      /* 0x00 */
    u32 end;      /* 0x04 */
    u32 enable;   /* 0x08 */
    u32 unk_0c;
    u16 kind;     /* 0x10 */
    u16 pad_12;
    u32 base;     /* 0x14 */
};

extern void MIi_CpuClear32(u32 val, void *dst, u32 size);
extern void *func_02060CA0(struct ExpHeap *heap, u32 size, s32 align);
extern void func_02060E30(struct ExpHeap *heap, void *block);
extern unsigned int func_02061124(char *p, int n, int v);
extern void *func_020868E0(int id, int heap, unsigned long size);
extern void func_020869E8(int id, int heap, void *ptr);
void *func_02061224(int **p);
void *func_0206123C(struct Big0206123C *o);
void func_0206127C(struct UnitHeap0206127C *heap, void *block);
void *func_0206128C(struct Allocator02061 *allocator, u32 size);
void func_020612A0(struct Allocator02061 *allocator, void *block);
void *func_020612B0(struct Allocator02061 *allocator, u32 size);
void func_020612C4(struct Allocator02061 *allocator, void *block);
int func_020612C8(struct Obj020612C8 *o, u32 i);
void func_020612E8(struct Allocator02061 *allocator, void *block);
void *func_020612F8(struct Allocator02061 *allocator, u32 size);
void func_02061314(struct Allocator02061 *allocator, void *ptr);
void func_02061330(struct Obj02061330 *o, u32 x);
void func_02061344(struct Obj02061330 *o, u32 x);
void func_02061358(struct S02061358 *s, u32 a, u32 b);
int func_02061370(void);
int func_02061378(void);
int func_02061380(void);
int func_02061388(void);
void func_02061390(u32 a, u32 b, u32 c, u32 d, u32 e);
void func_020613D8(u32 mode, u32 flag);
void func_02061460(void);
u32 func_020614D4(u32 size, u32 which);
u32 func_02061644(void);
void func_0206164C(u32 *dst);
void func_0206168C(u32 *src);
extern u8 g_020A1708[];
extern struct Slot g_020A816C[5];
extern struct Slot *g_020A8150[7];
extern u16 g_02146B70;
extern u32 NNS_GfdDefaultFuncAllocTexVram;
extern u32 NNS_GfdDefaultFuncFreeTexVram;
extern struct Slot *g_020A8158[5];







void *func_02061224(int **p)
{
    int *r = *p;
    if (r != 0)
        *p = (int *)r[0];
    return r;
}








/*
 * A 64-byte allocate-or-fetch helper: it hands the address of the object's
 * field at +0x24 to func_02061224, and if that returns non-null clears the
 * block it belongs to with MIi_CpuClear32(0, p, o->unk28).
 *
 * Two source shapes are load-bearing and both were measured against the bytes:
 *
 * 1. The guard must be written positively -- `if (p != 0) { ... }` -- not as
 *    an early `if (p == 0) return 0;`.  With the early return mwccarm 1.1p1
 *    hoists the `ldr r2, [r5, #0x28]` (the size) below the `beq` and the file
 *    is five sites wrong; with the body inside the arm the load is issued
 *    between the flag load and the mask, exactly as the original does.  See
 *    docs/idioms/a-guard-whose-arm-can-carry-the-body-is-not-predicated.md.
 * 2. The size has to reach the call through a named local (`u32 size;
 *    size = o->unk28;`) rather than as the call's third argument written out
 *    at the call site: the local pins the load above the mask test, and
 *    nothing else in the function moves once both loads are in that order.
 *
 * The `and r0, r0, #0xff` before the `tst r0, #1` is the u8 narrowing of the
 * flag field; the field itself is a word (a plain `ldr`, not an `ldrb`), so
 * the cast is in the source, and `((u8)o->unk20) & 1` is the spelling that
 * keeps both instructions -- `(o->unk20 & 0xff) & 1` folds the mask away and
 * costs four bytes.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206123C.c \
 *       --func func_0206123C --addr 0x0206123C --arm --cc 1.1p1
 *   EXACT, 64 bytes, 2 relocation sites, all 2 resolved.
 */
void *func_0206123C(struct Big0206123C *o)
{
    u32 size;
    void *p = func_02061224((int **)(&o->unk24));

    if (p != 0) {
        size = o->unk28;
        if (((u8)o->unk20) & 1) {
            MIi_CpuClear32(0, p, size);
        }
    }
    return p;
}










/*
 * Unit-heap free: pushes the block onto the free list at +0x24 of the
 * heap head (the same list func_0206123C pops through func_02061224).
 * Its only reference is the ARM pool word at 0x020612F4, the tail call
 * of the allocator-table entry 0x020612E8 (word at 0x020A16FC).
 */
void func_0206127C(struct UnitHeap0206127C *heap, void *block)
{
    struct UnitBlock0206127C *b = (struct UnitBlock0206127C *)block;

    b->next = heap->freeList;
    heap->freeList = b;
}








/*
 * Allocator-table alloc for the expanded heap: tail call to
 * func_02060CA0(allocator->heap, size, allocator->param1).  Table word
 * 0x0206128C at 0x020A1708.
 */
void *func_0206128C(struct Allocator02061 *allocator, u32 size)
{
    return func_02060CA0(allocator->heap, size, (s32)allocator->param1);
}









/*
 * Allocator-table free for the expanded heap: tail call to
 * func_02060E30(allocator->heap, block).  Table word 0x020612A0 at
 * 0x020A170C.
 *
 * NitroSystem fnd code, compiled like the fnd heap neighbours
 * (func_020611D4) with ../2.0/sp2: dsi/1.1p1 issues the pool load after
 * the argument load, the transposition in
 * docs/idioms/a-tail-calls-pool-word-is-scheduled-before-the-last-argument-write.md.
 * The other four allocator stubs match under either compiler and use the
 * same one for consistency.
 */
void func_020612A0(struct Allocator02061 *allocator, void *block)
{
    func_02060E30(allocator->heap, block);
}








/*
 * Allocator-table alloc for the frame heap: tail call to
 * func_02061124(allocator->heap, size, allocator->param1).  Table word
 * 0x020612B0 at 0x020A1700.
 */
void *func_020612B0(struct Allocator02061 *allocator, u32 size)
{
    return (void *)func_02061124(allocator->heap, size, (s32)allocator->param1);
}








/*
 * Allocator-table free for the frame heap: a frame heap frees only in
 * bulk, so the per-block free is empty.  Table word 0x020612C4 at
 * 0x020A1704.
 */
void func_020612C4(struct Allocator02061 *allocator, void *block)
{
    (void)allocator;
    (void)block;
}






/*
 * The tail `bl func_0206123C` at 0x020612E0 was the file's only MATCH site:
 * 0x0206123C had no `label` witness, because this call is the only branch to
 * it in the image.  Now that src/matched/func_0206123C.c is an EXACT entry,
 * the site resolves as `matched` and the file is EXACT (with a trailing `*`
 * for the unlabelled follower at 0x0206127C).
 *
 * The guard is an unsigned compare (`cmp r1, r2` / `movhi r0, #0` / `pophi`),
 * so the second parameter is `u32`, and the loaded field is passed on as r0:
 * `return func_0206123C(p);` -- the value handed back is the callee's own
 * result, which is why the call is not a tail call.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020612C8.c \
 *       --func func_020612C8 --addr 0x020612C8 --arm --cc 1.1p1
 *   MATCH, 32 bytes, 1 relocation site, 0 resolved.
 */
int func_020612C8(struct Obj020612C8 *o, u32 i)
{
    struct Inner020612C8 *p = o->inner;

    if (i > p->unk28) {
        return 0;
    }
    return (int)func_0206123C((struct Big0206123C *)p);
}





void func_020612E8(struct Allocator02061 *allocator, void *block)
{
    func_0206127C((struct UnitHeap0206127C *)allocator->heap, block);
}





void *func_020612F8(struct Allocator02061 *allocator, u32 size)
{
    return func_020868E0((int)allocator->param1, (int)allocator->heap, size);
}





void func_02061314(struct Allocator02061 *allocator, void *ptr)
{
    func_020869E8((int)allocator->param1, (int)allocator->heap, ptr);
}






/*
 * functions:
 *   func_02061330  0x02061330  arm
 *   func_02061344  0x02061344  arm
 *
 * Two two-argument vtable forwarders, 20 bytes each, no relocations at all.
 * The object at r0 holds a pointer to a table of function pointers at r0[0];
 * the call dispatches through slot 0 (0x02061330) and slot 1 (0x02061344).
 *
 * The tell that the callee takes *two* arguments is the register the loaded
 * pointer lands in.  Written as a one-argument call (`o->vt->f0(o)`) mwcc
 * keeps the function pointer in r1, which is free; the original puts it in
 * r2, which is only necessary when r0 and r1 are both argument registers, so
 * the wrapper forwards its own second parameter.  Same bytes either way for
 * the load pair, four differing bytes for the register choice.
 *
 * The wrapper's own arity is not visible in its body (the caller's r1 is
 * simply passed on), so the two-parameter reading is the one that reproduces
 * the register numbering; the functions are only reachable through a pointer
 * table, so no call site can be consulted.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02061330.c \
 *       --addr 0x02061330 --arm
 *   EXACT, 40 bytes, 2 functions, 0 relocation sites.
 */
void func_02061330(struct Obj02061330 *o, u32 x)
{
    o->vt->f0(o, x);
}




void func_02061344(struct Obj02061330 *o, u32 x)
{
    o->vt->f1(o, x);
}





/*
 *           func_02061388
 *
 * functions:
 *   func_02061358  0x02061358  arm
 *   func_02061370  0x02061370  arm
 *   func_02061378  0x02061378  arm
 *   func_02061380  0x02061380  arm
 *   func_02061388  0x02061388  arm
 *
 * The four eight-byte functions after the first are the `0` / `-1` stub
 * pair the object's own dispatch table points at (the word stored at
 * 0x020A1708 is 0x0206128C, and the stubs sit right behind the table pointer
 * this function installs).  `disasm.py` never labels them, because a leaf
 * that saves no register has no prologue to sweep, so they print as a run of
 * `.word`s between two literal pools -- see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.  They are read
 * out of the bytes here, and folding them into this unit is also what makes
 * the unit EXACT rather than EXACT*: on its own, func_02061358's inferred
 * extent runs 56 bytes to the next label at 0x02061390.
 *
 * The store order in the first function is the whole of its codegen: the zero
 * word has to be written *second* in the source (after the table pointer,
 * before the two arguments) for mwcc to fold the a/b/0 stores into a single
 * `stmib r0, {r1, r2, r3}`.  With `unkC = 0` written last the compiler emits
 * a two-register `stmib` plus a separate `str` and the literal pool moves
 * four bytes along.
 *
 * The one relocation site is the pool word for the data object at 0x020A1708;
 * it resolves as `data_table` (40 witnesses elsewhere in the image), which is
 * why this file is EXACT rather than the MATCH the single-function,
 * own-pool-witness reading would suggest.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02061358.c \
 *       --addr 0x02061358 --arm
 *   EXACT, 56 bytes, 5 functions, 1 relocation site, resolved.
 */
void func_02061358(struct S02061358 *s, u32 a, u32 b)
{
    s->unk0 = (u32)g_020A1708;
    s->unkC = 0;
    s->unk4 = a;
    s->unk8 = b;
}




int func_02061370(void)  { return 0; }



int func_02061378(void)  { return -1; }



int func_02061380(void)  { return 0; }



int func_02061388(void)  { return -1; }





/*
 * The two pool words at 0x020613D0 / 0x020613D4 resolve through `literal`
 * witnesses in other functions (0x020614D0 for the table, 0x0206163C for the
 * global), so the file is EXACT; its section is 72 bytes, the 64 code bytes
 * the worklist records plus its own pool.
 *
 * The function indexes a table of 0x18-byte records (mla r6, r0, ip, r5 with
 * ip = 0x18) five times, once per parameter, and stores the five computed
 * addresses into consecutive words at +8..+0x18 of a global at 0x020A8150.
 * The fifth parameter arrives on the stack, at [sp, #0x10] before the push.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02061390.c \
 *       --func func_02061390 --addr 0x02061390 --arm --cc 1.1p1
 *   EXACT, 72 bytes, 2 relocation sites, all 2 resolved.
 */
void func_02061390(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    g_020A8150[2] = &g_020A816C[a];
    g_020A8150[3] = &g_020A816C[b];
    g_020A8150[4] = &g_020A816C[c];
    g_020A8150[5] = &g_020A816C[d];
    g_020A8150[6] = &g_020A816C[e];
}





/*
 * The mode selector of the NNS G2D multi-cell renderer.  It builds one of two
 * five-slot tables through func_02061390 depending on the mode, publishes the
 * mode word at 0x02146B70, re-runs func_02061460 (the table walker that lives
 * just past this function), and installs the two callbacks at 0x020A8140 /
 * 0x020A8144 when the second argument is non-zero.
 *
 * The mode test is written `mode <= 2`: the original's fall-through arm is the
 * (2, 0) table pair and its branch is the positive `bhi` to the (0, 2) pair,
 * which is what mwccarm emits for the negated form.
 *
 * THE COMPILER PIN.  The C below is, character for character, the body
 * docs/notes/pkt_020613D8.c.txt parked as DIFF.  The residue that note records
 * -- "this compiler cross-jumps the two calls' identical two-instruction tails
 * (`str ip, [sp]; bl func_02061390`) into one shared block, the original keeps
 * both copies", 128 compiled against 136 -- is a FRONT-END artefact, not a
 * source-shape question.  Under `../2.0/sp2` the same source keeps both copies
 * and is byte-exact at 136.  The note's sweep (separate `if`s, `else if`, an
 * explicit `goto`, a `switch`, and four `#pragma`s) was correct in concluding
 * that no spelling moves it under 1.1p1.
 *
 * The pin is shared with src/matched/func_020616CC.c in this same cluster and
 * its evidence row is in docs/FRONTEND-PINS.md; a whole-function tail
 * duplication that 1.1p1 merges and 2.0/sp2 keeps is a second instance of the
 * same "2.0 spends bytes where 1.1p1 shares them" family as the kept-constants
 * tell.
 *
 * The pool word for func_02061644 at +0x80 resolves only because
 * src/matched/func_02061644.c is an EXACT manifest entry: this store is the
 * only reference to that eight-byte stub anywhere in the image.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020613D8.c \
 *       --func func_020613D8 --addr 0x020613D8 --arm --cc ../2.0/sp2
 *   EXACT, 136 bytes, 8 relocation sites, all 8 resolved.
 */
void func_020613D8(u32 mode, u32 flag)
{
    if (mode <= 2) {
        func_02061390(4, 3, 2, 0, 1);
    } else {
        func_02061390(4, 3, 0, 2, 1);
    }

    g_02146B70 = (u16)mode;
    func_02061460();

    if (flag == 0) {
        return;
    }

    NNS_GfdDefaultFuncAllocTexVram = (u32)func_020614D4;
    NNS_GfdDefaultFuncFreeTexVram = (u32)func_02061644;
}





/*
 * Re-derive every descriptor's enable and limit words from the renderer
 * mode (docs/families/cluster_020611D4.h): records below n = mode (plus
 * one when mode > 1) are enabled, and each record's {lo, hi} limit pair
 * is reset to {0, 0x10000} or {0, 0x20000} by its +0x0c kind word.
 *
 * THE LEVER, after two earlier lanes left this at 6 bytes (docs/notes/
 * pkt_020611D4.c.txt, docs/notes/pkt_020613D8.c.txt): the three stored
 * zeros are ONE named zero, `lo`, and the loop counter is INITIALISED
 * FROM IT (`for (i = lo; ...)`).  The image's `mov r5, #0` is the
 * counter's start and `mov lr, r5` / `mov r1, r5` / `mov r3, r5` are the
 * hoisted copies of the same value; with a literal 0 at each store (and
 * `i = 0`) the compiler materialises a separate zero into lr first and
 * gives the counter its own `mov r5, #0` -- the whole 6-byte residue.
 * `u32 z = i` spellings (tried before) do not reach it: the counter must
 * be derived from the zero, not the zero from the counter.  The permuter
 * is flat on the literal-zero body (hill, 161 singles), because no
 * value-preserving mutation it has introduces a shared zero variable.
 *
 * Front end: NOT pinned; EXACT under both dsi/1.1p1 and ../2.0/sp2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061460.c \
 *       --func func_02061460 --addr 0x02061460 --arm
 */
void func_02061460(void)
{
    int i;
    u32 lo = 0;
    struct Slot *t = g_020A816C;
    int n = g_02146B70;

    if (n > 1u) n++;

    for (i = lo; i < 5; i++, t++) {
        if (i < n) t->enable = 1;
        else       t->enable = lo;
        if (t->unk_0c != 0) {
            t->cur = lo;
            t->end = 0x10000;
        } else {
            t->cur = lo;
            t->end = 0x20000;
        }
    }
}




/* free extent of a slot, read through a signed word view */
#define ROOM(s) ((u32)((int *)(s))[1] - (u32)((int *)(s))[0])




/*
 * The descriptor-bank allocator of the NNS G2D multi-cell VRAM manager
 * (docs/families/cluster_020611D4.h, subsystem B), installed into the
 * 0x020A8140 callback slot by func_020613D8.  Round the request to 16
 * (0 -> 16), refuse >= 0x7FFF0, then
 *   which != 0: walk the TWO slots at 0x020A8150; a live slot with room
 *     picks a companion by its halfword kind -- kind 0 -> &g_020A816C[1]
 *     (0x020A8184), kind 3 -> &g_020A816C[2] (0x020A819C), else null --
 *     which must have room for HALF the request; bump both cursors and
 *     answer the main slot's base + old cursor;
 *   which == 0: walk the FIVE slots at 0x020A8158 and allocate downward
 *     from the slot's end.
 * The answer packs ((n >> 4) << 16) | ((addr << 13) >> 16) | (which << 31),
 * size-high first as in func_0206216C.
 *
 * CORRECTIONS to docs/notes/pkt_020611D4.c.txt's reading: the TWO-slot
 * walk is 0x020A8150 and the FIVE-slot walk 0x020A8158 (the note had
 * them swapped), and the companions are not pointer variables but the
 * ADDRESSES 0x020A8184 / 0x020A819C, i.e. records 1 and 2 of the bank,
 * which is why they resolve through g_020A816C's own witnesses.
 *
 * What closed it, in order:
 *   1. the dispatch as a `switch` (0 / 3 / default).  Under ../2.0/sp2 it
 *      compiles to the image's chain of real branches to three
 *      one-instruction blocks; the default's null is derived from the loop
 *      counter's zero (`mov r7, r4`) with no help.
 *   2. the room checks must NOT be CSE'd into the bodies: the image reads
 *      cur/end with an `ldm` for the check and re-loads the one it needs
 *      in the body (`ldr r4, [lr]`, `ldr r2, [ip, #4]`).  Spelled through
 *      the fields, both front ends keep the check's load live and come out
 *      4 bytes short with a different allocation.  Reading the pair
 *      through a signed word view -- the ROOM() macro below -- makes the
 *      check's loads a different expression from the body's u32 field
 *      reads.  A `u32 *` view is NOT enough for the end-relative check of
 *      the downward walk (still CSE'd); the `int *` view is.
 *   3. declaration order addr, ok, n, b, a, i (a sweep of 24 orders; the
 *      field order closes only this one) puts n in r3 and addr in r2.
 *
 * Pin evidence (2.0): the same C under dsi/1.1p1 is 356 code+pool bytes
 * against 368, 145 out.  The image's push list {r3-r9, lr} and the
 * derived-zero default both come out under 2.0 only, the same pin its
 * sibling allocator func_020616CC carries.
 *
 * EXACT* (not a byte difference): the listing extent (376) runs over the
 * unlabelled 8-byte stub func_02061644 at 0x02061644, already its own
 * EXACT entry; the function is 348 code bytes plus a 20-byte pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020614D4.c \
 *       --func func_020614D4 --addr 0x020614D4 --arm --cc ../2.0/sp2
 */
u32 func_020614D4(u32 size, u32 which)
{
    u32 addr;
    u32 ok;
    u32 n;
    struct Slot *b;
    struct Slot *a;
    int i;

    if (size == 0)
        n = 0x10;
    else
        n = (size + 0xf) & ~0xfu;
    if (n >= 0x7fff0u)
        return 0;

    if (which != 0) {
        for (i = 0; i < 2; i++) {
            a = g_020A8150[i];
            if (a->enable == 0)
                continue;
            if (ROOM(a) < n)
                continue;
            switch (a->kind) {
            case 0:  b = &g_020A816C[1]; break;
            case 3:  b = &g_020A816C[2]; break;
            default: b = 0; break;
            }
            if (b->enable == 0)
                continue;
            if (ROOM(b) < (n >> 1))
                continue;
            ok = 1;
            addr = a->cur;
            a->cur = addr + n;
            b->cur += n >> 1;
            addr += a->base;
            goto done;
        }
        ok = 0;
    } else {
        for (i = 0; i < 5; i++) {
            struct Slot *c = g_020A8158[i];
            if (c->enable == 0)
                continue;
            if (ROOM(c) < n)
                continue;
            ok = 1;
            c->end -= n;
            addr = c->end + c->base;
            goto done;
        }
        ok = 0;
    }
done:
    if (ok == 0)
        return 0;
    return ((n >> 4) << 16) | ((addr << 13) >> 16) | (which << 31);
}



/*
 * An eight-byte unlabelled leaf: `mov r0, #0; bx lr`.  disasm.py only labels
 * a function whose prologue saves lr, so this stub is invisible in the
 * listing and sits between the tail of func_020614D4's literal pool (which
 * ends at 0x02061640) and the next labelled function at 0x0206164C.
 *
 * It is the default callback func_020613D8 installs at 0x020A8144 as a
 * function pointer, so the pool word naming it is the only reference in the
 * image; filing this entry is what lets that pool word resolve.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061644.c \
 *       --func func_02061644 --addr 0x02061644 --arm --cc 1.1p1
 */
u32 func_02061644(void)
{
    return 0;
}



/*
 * SAVE half of the save/restore pair the NNS G2D multi-cell renderer uses
 * around a mode switch: it copies the first two words of each of the five
 * 0x18-byte records at 0x020A816C out into the caller's flat buffer, two
 * words per record.  func_0206168C at 0x0206168C is the exact mirror and
 * restores them.
 *
 * The residue docs/notes/pkt_0206164C.c.txt recorded (10 concrete bytes, "which
 * of the three loop quantities gets which register") is resolved here, and the
 * lever is not declaration order, which that note swept exhaustively: it is
 * WHERE THE FIRST ZERO IS MATERIALISED.  The image does
 *
 *     mov r3, #0          <- i
 *     ...
 *     mov lr, r3          <- j = i, derived from the same zero
 *
 * so `i` must be the value that owns the literal and `j` must be spelled as a
 * COPY OF IT, not as its own `0`.  `int i = 0; ... int j = i;` with the `for`
 * carrying an empty init clause is byte-exact; `int j = 0` in any of the six
 * declaration orders leaves the two `mov`s swapped, which is the whole of the
 * previously recorded 10-byte residue.  This is the same shape the sibling
 * func_02061460 note describes (the original derives the second zero from the
 * first, the compiler materialises a second one), and the same fix applies.
 *
 * `t` sits between the two so the pointer, not `j`, takes ip; that ordering is
 * the permuter's decl-order(j<->t) result and is load-bearing for the
 * `add ip, ip, #0x18` / `add lr, lr, #2` pair.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206164C.c \
 *       --func func_0206164C --addr 0x0206164C --arm --cc 1.1p1
 *   EXACT, 64 bytes, 1 relocation site, resolved.
 */
void func_0206164C(u32 *dst)
{
    int i = 0;
    struct Slot *t = g_020A816C;
    int j = i;

    for (; i < 5; i++) {
        dst[j] = t->cur;
        dst[j + 1] = t->end;
        t++;
        j += 2;
    }
}



/*
 * RESTORE half of the pair whose save half is src/matched/func_0206164C.c:
 * it copies two words per record back from the caller's flat buffer into the
 * first two words of each of the five 0x18-byte records at 0x020A816C.
 *
 * Same lever as the save half (see that file's header): the image derives the
 * second loop zero from the first with `mov ip, r3`, so `j` has to be spelled
 * as a copy of `i` and not as its own literal `0`.
 *
 * The one DIFFERENCE from the save half is declaration order, and it is not
 * cosmetic.  In the save half `t` is declared BETWEEN `i` and `j`, which puts
 * the table pointer in ip and the destination index in lr; here the same order
 * is 10 bytes out because the registers are the other way round -- the image
 * puts the table pointer in lr and the index in ip.  Declaring `j` before `t`
 * reproduces it exactly.  The two mirrors therefore disagree on declaration
 * order despite being written from the same template, which is the
 * declaration-order-is-register-order idiom applied in both directions.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206168C.c \
 *       --func func_0206168C --addr 0x0206168C --arm --cc 1.1p1
 *   EXACT, 64 bytes, 1 relocation site, resolved.
 */
void func_0206168C(u32 *src)
{
    int i = 0;
    int j = i;
    struct Slot *t = g_020A816C;

    for (; i < 5; i++) {
        t->cur = src[j];
        t->end = src[j + 1];
        j += 2;
        t++;
    }
}
