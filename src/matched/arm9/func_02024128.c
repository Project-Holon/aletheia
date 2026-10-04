/*
 * function: func_02024128
 * address:  0x02024128
 * packet:   pkt_02024128
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf accessor: copy the halfwords at +0x18 and +0x1a to out. __restrict on out makes both loads precede both stores.
 *
 * symbols:
 *   (none - no relocations)
 */

struct Src02024128 {
    unsigned char pad[0x18];
    unsigned short a;
    unsigned short b;
};

void func_02024128(struct Src02024128 *p, unsigned short *__restrict out)
{
    out[0] = p->a;
    out[1] = p->b;
}
