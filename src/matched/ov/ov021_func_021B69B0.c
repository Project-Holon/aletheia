/*
 * function: func_021B69B0
 * address:  0x021B69B0
 * packet:   pkt_ov021_021B69B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * d_021F45F0 is the ov055 proc table (ov055 is the overlay id passed to
 * func_021BB990), hence the ov055 token on its symbols: line.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb ov010
 *   func_02158F58  0x02158F58  thumb ov010
 *   func_02188D24  0x02188D24  thumb ov021
 *   func_021BB990  0x021BB990  thumb ov021
 *   ov055_id       0x00000037  data  a1
 *   d_021F45F0     0x021F45F0  data  ov055  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);
extern u32 func_02188D24(u8 *p);
extern int *func_021BB990(int, int *, const int *);
extern u8 ov055_id[];
extern const int d_021F45F0[];

int func_021B69B0(void *a, void *b)
{
    func_021BB990((int)ov055_id, (int *)func_02188D24((u8 *)(((u32 *)func_02158F58((int)func_0215A5F4(b)))[1])), d_021F45F0);
    return 0;
}
