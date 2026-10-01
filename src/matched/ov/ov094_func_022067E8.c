/*
 * function: func_022067E8
 * address:  0x022067E8
 * packet:   pkt_ov094_022067E8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F8AC0  0x021F8AC0  thumb  ov094
 *   func_021F8554  0x021F8554  thumb  ov094
 */

extern void func_021F8AC0(int a);
extern void func_021F8554(void *h, int a, int b, int c, int d);

void func_022067E8(char *p)
{
    func_021F8AC0(2);
    func_021F8554(*(void **)(p + 0x278), 1, 10, 0, 8);
}
