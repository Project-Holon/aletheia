/*
 * function: func_020612A0
 * address:  0x020612A0
 * packet:   pkt_020612A0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02060E30  0x02060E30  arm
 *
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

typedef unsigned int u32;

struct Allocator02061 {
    void *funcs;
    void *heap;
    u32 param1;
    u32 param2;
};

struct ExpHeap;
extern void func_02060E30(struct ExpHeap *heap, void *block);

void func_020612A0(struct Allocator02061 *allocator, void *block)
{
    func_02060E30(allocator->heap, block);
}
