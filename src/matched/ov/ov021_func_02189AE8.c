/*
 * function: func_02189AE8
 * address:  0x02189AE8
 * packet:   pkt_ov021_02189AE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Leaf: 0 for id 0x3f, else 0 when func_02013CE0() reports 1, else 1.
 * Callee of func_02189204.  EXACT* because the unlabelled follower
 * (0x02189B04) has no seed; no byte differs.
 *
 * symbols:
 *   func_02013CE0  0x02013CE0  thumb
 */

typedef unsigned int   u32;
extern u32 func_02013CE0(u32 id);

int func_02189AE8(int a)
{
    if (a == 0x3f)
        return 0;
    if (func_02013CE0(a) == 1)
        return 0;
    return 1;
}
