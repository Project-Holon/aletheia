/*
 * function: func_021ECA24
 * address:  0x021ECA24
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ECA38  0x021ECA38  thumb  ov170
 *
 * Zero*p through the pool, then run the sibling teardown.
 */


extern void func_0204B3DC(int, int);
extern void func_021ECA38(int *);
void func_021ECA24(int *p)
{
    func_0204B3DC(*p, 0);
    func_021ECA38(p);
}
