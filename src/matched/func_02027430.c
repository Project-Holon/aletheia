/*
 * function: func_02027430
 * address:  0x02027430
 * packet:   pkt_02027430
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 *
 * symbols:
 *   func_02027430  0x02027430  thumb
 */

void func_02027430(char *p, unsigned short v)
{
    *(unsigned short *)(p + 0x48) = (*(unsigned short *)(p + 0x48) & ~0xff) | 4;
    *(unsigned short *)(p + 0x4e) = v;
}
