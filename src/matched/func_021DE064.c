/*
 * function: func_021DE064
 * address:  0x021DE064
 * packet:   pkt_021DE064
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 */

extern void func_0204B3DC(int, int);

void func_021DE064(int *p, int i, int a)
{
    int v = *(int *)((char *)p + i * 4 + 0xB74);

    if (v)
        func_0204B3DC(v, a);
}
