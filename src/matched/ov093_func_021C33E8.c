/*
 * function: func_021C33E8
 * address:  0x021C33E8
 * packet:   pkt_ov093_021C33E8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C3428  0x021C3428  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021C5B74  0x021C5B74  thumb  ov093
 */

extern int func_021D5440(int);
extern int func_021C3428(int, int);
extern void func_021CD4B0(int, int, int, int);
extern void func_021C5B74(int, int, int, int);

void func_021C33E8(int a, int b, int c)
{
    int v = func_021C3428(a + 0x1ab8, func_021D5440(b));
    if (v != 6)
        func_021CD4B0(*(int *)(a + 0xc), 0x4d, v, 0x263);
    func_021C5B74(a, b, c, 1);
}
