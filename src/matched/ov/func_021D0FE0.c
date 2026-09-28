/*
 * function: func_021D0FE0
 * address:  0x021D0FE0
 * packet:   pkt_021D0FE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D0FE0   0x021D0FE0  thumb ov021
 *
 * Unlabelled ov021 leaf hidden in a word run: returns the word at +0x150 of
 * its pointer argument (the second argument register).  Matched to supply the
 * `matched` witness for the pending ov010 caller func_0216A6B4.
 */

int func_021D0FE0(int x, int *p)
{
    return *(int *)((char *)p + 0x150);
}
