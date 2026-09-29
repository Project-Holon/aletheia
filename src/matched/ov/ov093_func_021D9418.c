/*
 * unit:     yes
 * function: func_021D9418, func_021D9440, func_021D9450
 * address:  0x021D9418
 * packet:   pkt_ov093_021D9418
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D9648  0x021D9648  thumb  ov093
 *   func_021D96DC  0x021D96DC  thumb  ov093
 *   func_021D96FC  0x021D96FC  thumb  ov093
 */

extern int func_021D9648(int, int, int);
extern void func_021D96DC(int, int, int);
extern void func_021D96FC(int, int, int);

void func_021D9418(int a, int b, int c, int *out)
{
    int r;

    r = func_021D9648(b, c, 2);
    *out = r;
    if (r == 0)
        *out = func_021D9648(b, c, 0xe);
}

void func_021D9440(int a, int b, int c)
{
    func_021D96DC(b, c, 2);
}

void func_021D9450(int a, int b, int c)
{
    func_021D96FC(b, c, 2);
}
