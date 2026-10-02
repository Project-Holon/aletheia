/*
 * function: func_021E8AC0
 * address:  0x021E8AC0
 * packet:   pkt_021E8AC0
 * region:   ov177
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008C58  0x02008C58  thumb
 *   func_02008DF0  0x02008DF0  thumb
 */

extern int  func_02012EBC(int a);
extern int  func_02008C58(int sys);
extern void func_02008DF0(int x, int y);

void func_021E8AC0(int a, int b)
{
    int x;

    x = func_02008C58(func_02012EBC(a));
    switch (b) {
    case 1:
    case 4:
        func_02008DF0(x, 0x12);
        break;
    case 0:
    case 3:
        func_02008DF0(x, 0x13);
        break;
    case 2:
        func_02008DF0(x, 0x14);
        break;
    }
    func_02008DF0(x, 0x11);
}
