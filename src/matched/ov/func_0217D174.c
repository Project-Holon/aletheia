/*
 * function: func_0217D174
 * address:  0x0217D174
 * packet:   pkt_0217D174
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E62A0  0x021E62A0  thumb  ov177
 */

extern void func_021E62A0(int);

void func_0217D174(int *p)
{
    if (*(int *)((char *)p + 0x10)) {
        func_021E62A0(*(int *)((char *)p + 0x10));
        *(int *)((char *)p + 0x10) = 0;
    }
}
