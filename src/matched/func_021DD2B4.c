/*
 * function: func_021DD2B4
 * address:  0x021DD2B4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DD2D0  0x021DD2D0  thumb  ov170
 *
 * Open the range, then feed the handle to the second call.
 */



extern int func_021DD2D0(int, int, int);
extern void func_02017E64(int, int, int);
void func_021DD2B4(int a, int b, int c, int d, int e)
{
    int r = func_021DD2D0(a, c, b);
    if (r)
        func_02017E64(r, d, e);
}
