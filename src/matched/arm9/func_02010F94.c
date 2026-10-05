/*
 * function: func_02010F94
 * address:  0x02010F94
 * packet:   pkt_02010F94
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf: byte at +0xa of the 12-byte record idx.
 *
 * symbols:
 *   (none - no relocations)
 */

struct Rec02010F94 {
    unsigned char pad[10];
    unsigned char f;
    unsigned char pad2;
};

unsigned int func_02010F94(struct Rec02010F94 *p, int idx)
{
    return p[idx].f;
}
