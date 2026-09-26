/*
 * function: func_021E5548
 * address:  0x021E5548
 * packet:   pkt_021E5548
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E5548   0x021E5548  thumb ov177
 *   func_021E5678   0x021E5678  thumb ov177
 *
 * Unlabelled ov177 thunk hidden in a word run: tail-calls func_021E5678 with
 * its pointer argument advanced by one word.  Matched to supply the `matched`
 * witness for the pending ov176 caller func_0217AF2C.
 */

extern int func_021E5678(int *);

int func_021E5548(int *p)
{
    return func_021E5678(p + 1);
}
