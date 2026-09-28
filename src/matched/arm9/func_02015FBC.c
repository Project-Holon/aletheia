/*
 * function: func_02015FBC
 * address:  0x02015FBC
 * packet:   pkt_02015FBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness (ov117 func_021D49F4): the low byte of the word at +0x140.
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   func_02015FBC  0x02015FBC  thumb
 */

void func_02015FBC(char *p, int v)
{
    *(int *)(p + 0x140) = (*(int *)(p + 0x140) & ~0xFF) | (unsigned char)v;
}
