/*
 * function: func_02155280
 * address:  0x02155280
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Calls func_02155648 on the argument twice and returns 1.
 *
 * symbols:
 *   func_02155648  0x02155648  thumb  ov009
 */

extern void func_02155648(int a, int b);

int func_02155280(int a)
{
    func_02155648(a, a);

    return 1;
}

