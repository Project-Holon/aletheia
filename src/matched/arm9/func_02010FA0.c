/*
 * function: GPOWER_GetPowerCost
 * address:  0x02010FA0
 * packet:   pkt_02010FA0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf: halfword at +0x2 of the 12-byte record idx.
 *
 * symbols:
 *   (none - no relocations)
 */

struct Rec02010FA0 {
    unsigned short a;
    unsigned short f;
    unsigned char pad[8];
};

unsigned int GPOWER_GetPowerCost(struct Rec02010FA0 *p, int idx)
{
    return p[idx].f;
}
