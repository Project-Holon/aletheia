/*
 * function: func_021E64C0
 * address:  0x021E64C0
 * packet:   pkt_ov177_021E64C0
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E64C0   0x021E64C0  thumb ov177
 *   func_021E6E8C   0x021E6E8C  thumb ov177
 *
 * Unlabelled ov177 thunk hidden in a word run: forwards to func_021E6E8C.
 * Matched to supply the `matched` witness for the pending ov176 caller
 * func_0217D434.
 */

extern int func_021E6E8C(unsigned char *p, void *mgr);

int func_021E64C0(unsigned char *p, void *mgr)
{
    return func_021E6E8C(p, mgr);
}
