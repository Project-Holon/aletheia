/*
 * function: func_021BA2BC
 * address:  0x021BA2BC
 * packet:   pkt_ov217_021BA2BC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

extern void func_020413B0(int, int, int, int, int, int);
typedef unsigned int   u32;
extern void func_020409B4(u32 index);

void func_021BA2BC(int sel)
{
    int a, b, c, d, e, f;
    switch (sel) {
    case 0:
        a = 2; b = 3; c = 5; d = 0x1a; e = 5; f = 5;
        break;
    case 1:
        a = 2; b = 3; c = 0xc; d = 0x1a; e = 5; f = 6;
        break;
    default:
        return;
    }
    func_020413B0(a, b, c, d, e, f);
    func_020409B4(a);
}
