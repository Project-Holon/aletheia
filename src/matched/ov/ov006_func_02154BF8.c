/*
 * function: func_02154BF8
 * address:  0x02154BF8
 * packet:   pkt_ov006_02154BF8
 * region:   ov006
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_02154B08  0x02154B08  thumb  ov006
 *   func_021544F0  0x021544F0  thumb  ov006
 */

int func_020122C0(int p, int a, void (*cb)(void), int n);
void func_02154B08(int h, int a, int b, int c);
void func_021544F0(void);

int func_02154BF8(int a, int b, int c)
{
    int h;

    h = func_020122C0(a, 0, func_021544F0, 0x174);
    func_02154B08(h, a, b, c);
    return h;
}
