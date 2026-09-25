/*
 * function: func_021B77C4
 * address:  0x021B77C4
 * packet:   pkt_021B77C4
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B7798  0x021B7798  thumb  ov180
 */

extern void func_021B7798(int *, int);

void func_021B77C4(int *p)
{
    unsigned int i;

    for (i = 0; i < 4; i++)
        func_021B7798(p, i);
}
