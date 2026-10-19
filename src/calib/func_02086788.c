/*
 * function: OS_AllocFromArenaLo
 * address:  0x02086788
 * packet:   pkt_02086788
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;

extern u32  func_02086580(u32 a0);
extern u32  func_0208656C(u32 a0);
extern void func_02086774(u32 a0, u32 a1);

u32 OS_AllocFromArenaLo(u32 r7, u32 r6, u32 r5)
{
    u32 r0 = func_02086580(r7);
    u32 r1, r2, r4;

    if (r0 == 0) {
        return 0;
    }
    r1 = r5 - 1;
    r2 = ~r1;
    r0 = r0 + r5 - 1;
    r4 = r2 & r0;

    r0 = r4 + r6;
    r0 = r0 + r5 - 1;
    r5 = r2 & r0;

    if (r5 > func_0208656C(r7)) {
        return 0;
    }

    func_02086774(r7, r5);
    return r4;
}
