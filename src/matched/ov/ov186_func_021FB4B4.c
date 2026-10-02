/*
 * function: func_021FB4B4
 * address:  0x021FB4B4
 * packet:   pkt_021FB4B4
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FB4CC  0x021FB4CC  thumb  ov186
 *   func_020061E4  0x020061E4  thumb
 */

extern int func_021FB4CC(int obj, int x, int y);
extern void func_020061E4(int);

int func_021FB4B4(int obj, int x, int y)
{
    int r = func_021FB4CC(obj, x, y);

    if (r != 0)
        func_020061E4(0x703);
    return r;
}
