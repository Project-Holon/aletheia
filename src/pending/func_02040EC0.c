/*
 * function: func_02040EC0
 * address:  0x02040EC0
 * packet:   pkt_02040EC0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02040E78  0x02040E78  arm
 */

typedef unsigned int u32;

extern void func_02040E78(u32 a0, u32 *out, u32 a2, u32 a3);

void func_02040EC0(u32 a0, ...)
{
    func_02040E78(a0, (u32 *)((char *)&a0 + 0xc), 2, 0);
}
