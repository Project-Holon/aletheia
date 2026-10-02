/*
 * function: func_020612C4
 * address:  0x020612C4
 * packet:   pkt_020612C4
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Allocator-table free for the frame heap: a frame heap frees only in
 * bulk, so the per-block free is empty.  Table word 0x020612C4 at
 * 0x020A1704.
 */

typedef unsigned int u32;

struct Allocator02061 {
    void *funcs;
    void *heap;
    u32 param1;
    u32 param2;
};

void func_020612C4(struct Allocator02061 *allocator, void *block)
{
    (void)allocator;
    (void)block;
}
