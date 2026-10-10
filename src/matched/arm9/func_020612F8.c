/*
 * function: func_020612F8
 * address: 0x020612F8
 * packet: pkt_arm9_020612F8
 * region: arm9
 * compiler: dsi/../2.0/sp2
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/arm9/unit_02061224.c and filed here.
 *
 * symbols:
 *   func_020868E0 0x020868E0 arm
 */

typedef unsigned int u32;

struct Allocator02061 {
    void *funcs;
    void *heap;
    u32 param1;
    u32 param2;
};

extern void *func_020868E0(int id, int heap, unsigned long size);
void *func_020612F8(struct Allocator02061 *allocator, u32 size);

void *func_020612F8(struct Allocator02061 *allocator, u32 size)
{
    return func_020868E0((int)allocator->param1, (int)allocator->heap, size);
}
