/*
 * function: func_02188F58
 * address:  0x02188F58
 * packet:   pkt_ov096_02188F58
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C7DAC  0x021C7DAC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0201134C(int);
extern void func_0218A0F4(int, int, int, int, int);
extern u8 func_021D5440(u8 *p);
extern int func_021C7DAC(int, int, int, int);

int func_02188F58(int a, int b)
{
    int t0;
    int t1;
    int y;
    int z;
    int r;

    t0 = func_0201134C(a);
    t1 = func_0201134C(a);
    y = func_021D5440(*(u8 **)(b + 0xbc));
    z = func_021D5440(*(u8 **)(b + 0xc0));
    r = func_021C7DAC(*(int *)(b + 0xb4), y, z, *(u16 *)(b + 2));
    func_0218A0F4(a, 2, r, t0, t1);
    return *(int *)(b + 0xc4);
}
