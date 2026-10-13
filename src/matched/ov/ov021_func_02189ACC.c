/*
 * function: FIELDMAP_GetProjDepthOffset
 * address:  0x02189ACC
 * packet:   pkt_ov021_02189ACC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf: returns one of two pooled constants (0x1EE / 0x136) depending on
 * func_02013BA8() == 1.  Callee of FIELDMAP_SeqCreateSubsystems (assigns p->x104).
 *
 * symbols:
 *   func_02013BA8  0x02013BA8  thumb
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u8 func_02013BA8(u32 id);

int FIELDMAP_GetProjDepthOffset(u32 a0)
{
    if (func_02013BA8(a0) == 1)
        return 0x1EE;
    return 0x136;
}
