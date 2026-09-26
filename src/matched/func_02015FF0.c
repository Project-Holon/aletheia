/*
 * function: func_02015FF0
 * address:  0x02015FF0
 * packet:   pkt_02015FF0
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
 *   func_02015FF0  0x02015FF0  thumb
 */

void func_02015FF0(char *p, int v)
{
    *(int *)(p + 0x140) = (*(int *)(p + 0x140) & 0xFF7FFFFF) | ((v & 1) << 23);
}
