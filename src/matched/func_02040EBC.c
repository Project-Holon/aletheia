/*
 * function: func_02040EBC
 * address:  0x02040EBC
 * packet:   pkt_02040DA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;

extern void func_02040E78(u32, void *, u32, u32);

void func_02040EBC(u32 a0, u32 a1)
{
    func_02040E78(a0, &a1, 2, 0);
}
