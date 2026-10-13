/*
 * function: POKEGRA_RegisterTrainerCgr
 * address:  0x0202DA48
 * packet:   pkt_0202DA18
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKEGRA_GetTrainerCgrArcIndex  0x0202D5D8  thumb
 */

typedef unsigned int u32;

extern u32  POKEGRA_GetTrainerCgrArcIndex(u32 a, u32 b);
extern void func_0204A6C8(u32 a, u32 b, u32 c, u32 d, u32 e);

void POKEGRA_RegisterTrainerCgr(u32 a, u32 b, u32 c, u32 d)
{
    func_0204A6C8(a, POKEGRA_GetTrainerCgrArcIndex(b, 0), 1, c, d);
}
