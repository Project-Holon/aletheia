/*
 * function: func_02184320
 * address:  0x02184320
 * packet:   pkt_ov023_02184320
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02185AB0  0x02185AB0  thumb  ov023
 *   func_02082AC0  0x02082AC0  arm
 *   func_021841A4  0x021841A4  thumb  ov022
 *   func_021841A0  0x021841A0  thumb  ov022
 */

typedef unsigned int u32;

extern void func_02185AB0(char *p, int a, int b);
extern void func_02082AC0(int v, char *dst, u32 n);
extern u32 func_021841A4(u32 x);
extern u32 func_021841A0(u32 x);

void func_02184320(int a0, int a1, int a2, char *p)
{
    func_02185AB0(p, 3, 0);
    func_02082AC0(0, p + 0x4290, 0x3840);
    *(u32 *)(p + 0x1ac) = func_021841A4(*(u32 *)*(u32 **)(p + 4));
    *(u32 *)(p + 0x1b0) = func_021841A0(*(u32 *)*(u32 **)(p + 4));
    *(u32 *)(p + 0x9e6c) = 1;
}
