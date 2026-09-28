/*
 * function: func_020273DC
 * address:  0x020273DC
 * packet:   pkt_020273DC
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
 *   func_020273DC  0x020273DC  thumb
 */

void func_020273DC(char *p, unsigned short v)
{
    *(unsigned short *)(p + 0x48) = (*(unsigned short *)(p + 0x48) & ~0xff) | 1;
    *(unsigned short *)(p + 0x4e) = v;
}
