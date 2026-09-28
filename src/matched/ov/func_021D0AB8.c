/*
 * function: func_021D0AB8
 * address:  0x021D0AB8
 * packet:   pkt_021D0AB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D0AB8   0x021D0AB8  thumb ov021
 *
 * Unlabelled ov021 leaf hidden in a word run: stores the second argument at
 * +0x130 of the first.  Matched to supply the `matched` witness for the
 * pending ov010 caller func_0216A594.
 */

void func_021D0AB8(int *p, int v)
{
    *(int *)((char *)p + 0x130) = v;
}
