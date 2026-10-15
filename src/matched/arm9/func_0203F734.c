/*
 * function: GF_STANDARD_DegToAngle
 * address:  0x0203F734
 * packet:   pkt_0203F734
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM leaf (no lr save) that scales x by 0xFFFF and divides by
 * 360: floor(x * 65535 / 360) for x < 360, else 0.  The unsigned guard
 * gives `movhs`, and mwcc emits the signed /360 magic (0xB60B60B7) because
 * the guard proves the product positive.  It is the witness that unblocks
 * the thumb caller BEACON_DETAIL_CalcDistance.
 */

typedef unsigned short u16;
typedef unsigned int u32;

u16 GF_STANDARD_DegToAngle(int x)
{
    if ((u32)x >= 0x168)
        return 0;
    return (u16)(x * 0xFFFF / 0x168);
}
