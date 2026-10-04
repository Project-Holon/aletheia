/*
 * unit:     yes
 * function: func_021D70E4, func_021D70F0
 * address:  0x021D70E4
 * packet:   pkt_021D70E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two wrappers fixing the third argument to 7.
 *
 * symbols:
 *   func_021D7108  0x021D7108  thumb  ov093
 */

extern void func_021D7108(void *, int, int, int);

void func_021D70E4(void *a, int id)
{
    func_021D7108(a, id, 7, 0);
}

void func_021D70F0(void *a, int id)
{
    func_021D7108(a, id, 7, 1);
}
