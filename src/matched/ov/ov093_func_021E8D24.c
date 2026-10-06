/*
 * function: func_021E8D24
 * address:  0x021E8D24
 * packet:   pkt_ov093_021E8D24
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E8CFC  0x021E8CFC  thumb  ov093
 *   func_021E8D04  0x021E8D04  thumb  ov093
 */
extern unsigned char func_021E8CFC(int x);
extern int func_021E8D04(int x);

int func_021E8D24(int x, int k)
{
    if (k == func_021E8CFC(x)) {
        return 1;
    }
    if (k == func_021E8D04(x)) {
        return 1;
    }
    return 0;
}
