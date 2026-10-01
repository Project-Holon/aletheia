/*
 * function: func_021A4114
 * address:  0x021A4114
 * packet:   pkt_ov021_021A4114
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02029D8C  0x02029D8C  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

int func_02188C80(u32 x);
int func_020120F4(int x);
int func_02012A30(int x);
int func_02188C9C(u32 x);
void func_02029D8C(int a, int b, u16 c);

void func_021A4114(u32 *p)
{
    int a = func_020120F4(func_02188C80(p[2]));
    int b = func_02012A30(a);

    func_02029D8C(b, a, (u16)func_02188C9C(p[2]));
}
