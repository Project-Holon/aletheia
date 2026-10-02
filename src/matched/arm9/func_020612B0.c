/*
 * function: func_020612B0
 * address:  0x020612B0
 * packet:   pkt_020612B0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02061124  0x02061124  arm
 *
 * Allocator-table alloc for the frame heap: tail call to
 * func_02061124(allocator->heap, size, allocator->param1).  Table word
 * 0x020612B0 at 0x020A1700.
 */

typedef unsigned int u32;
typedef signed int   s32;

struct Allocator02061 {
    void *funcs;
    void *heap;
    u32 param1;
    u32 param2;
};

extern void *func_02061124(void *heap, u32 size, s32 align);

void *func_020612B0(struct Allocator02061 *allocator, u32 size)
{
    return func_02061124(allocator->heap, size, (s32)allocator->param1);
}
