/*
 * function: func_021E8AA8
 * address:  0x021E8AA8
 * packet:   pkt_021E8AA8
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E8AA8   0x021E8AA8  thumb ov177
 *   func_021E8AA0   0x021E8AA0  thumb ov177
 *
 * Unlabelled ov177 thunk hidden in a word run: tail-calls func_021E8AA0 with
 * its second argument zeroed.  Matched to supply the `matched` witness for the
 * pending ov175 caller func_021D61CC.
 */

extern void func_021E8AA0(int *p, int v);

void func_021E8AA8(int a)
{
    func_021E8AA0((int *)a, 0);
}
