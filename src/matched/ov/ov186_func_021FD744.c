/*
 * function: func_021FD744
 * address:  0x021FD744
 * packet:   pkt_021FD744
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FD744   0x021FD744  thumb ov186
 *   func_021FD73C   0x021FD73C  thumb ov186
 *
 * Unlabelled ov186 thunk hidden in a word run: tail-calls func_021FD73C with
 * the second argument zeroed.  Matched to supply the `matched` witness for the
 * pending caller func_021F8624.
 */

extern int *func_021FD73C(int *p, int v);

int func_021FD744(int *a)
{
    return (int)func_021FD73C(a, 0);
}
