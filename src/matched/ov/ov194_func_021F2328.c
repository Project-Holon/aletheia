/*
 * function: func_021F2328
 * address:  0x021F2328
 * packet:   pkt_021F2328
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045994 0x02045994 arm
 */

extern int func_02045994(int, void *, int);

int func_021F2328(char *self, int x)
{
    return func_02045994(x, self, *(unsigned short *)(self + 0x1e) + 1);
}
