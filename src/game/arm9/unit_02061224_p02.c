/*
 * file:     unit_02061224_p02.c
 * unit:     yes
 * function: func_0206127C, func_0206128C, func_020612A0, func_020612B0, func_020612C4
 * address:  0x0206127C
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
 *   func_02060CA0  0x02060CA0  arm
 *   func_02060E30  0x02060E30  arm
 *   func_02061124  0x02061124  arm
 */
struct ExpHeap;
typedef unsigned int u32;

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

extern void *func_02060CA0(struct ExpHeap *heap, u32 size, s32 align);
extern void func_02060E30(struct ExpHeap *heap, void *block);
extern unsigned int func_02061124(char *p, int n, int v);




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
