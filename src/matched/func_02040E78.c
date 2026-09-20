/*
 * function: func_02040E78
 * address:  0x02040E78
 * packet:   pkt_02040DA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;

extern void func_020862F0(void *, u32);
extern void func_0207E3D0(void *, u32, u32);
extern void func_0207E468(void *, u32, u32);

void func_02040E78(u32 r7, void *r6, u32 r5, u32 r4)
{
    func_020862F0(r6, r5);
    if (r7 < 4) {
        func_0207E3D0(r6, r4, r5);
    } else {
        func_0207E468(r6, r4, r5);
    }
}
