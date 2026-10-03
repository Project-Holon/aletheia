/*
 * function: func_021A5610
 * address:  0x021A5610
 * packet:   pkt_ov021_021A5610
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A5788  0x021A5788  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021A55FC  0x021A55FC  thumb  ov021
 */

typedef unsigned int u32;

void func_021A5788(u32 *p, int k, int *out);
typedef unsigned short u16;
u16 func_021AB0F0(u32 attr);
int func_021A55FC(int x);

int func_021A5610(u32 *p)
{
    int x;

    func_021A5788(p, 9, &x);
    if (func_021A55FC(func_021AB0F0(x)) == 1)
        return 1;
    return 0;
}
