/*
 * function: func_02168878
 * address:  0x02168878
 * packet:   pkt_ov010_02168878
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021688BC  0x021688BC  thumb
 *   func_02168924  0x02168924  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern int func_021688BC(u8 *, int, u16);
extern int func_02168924(int, int, u8 *, u8, int, int, int, u16);
extern void func_020307B0(void *p);

int func_02168878(u8 *a, int b, int c, int d, int e, int f, u16 g)
{
    int t = func_021688BC(a, b, g);
    int r = func_02168924(t, b, a + 0x30, (u8)c, d, e, f, g);
    func_020307B0((void *)t);
    return r;
}
