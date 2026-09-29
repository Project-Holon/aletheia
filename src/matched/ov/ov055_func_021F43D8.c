/*
 * function: func_021F43D8
 * address:  0x021F43D8
 * packet:   pkt_ov055_021F43D8
 * region:   ov055
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_02045B38  0x02045B38  arm
 *   func_021F4510  0x021F4510  thumb  ov055
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 func_020056EC(u32 v);
extern u32 func_02045B38(u32 a, u32 b, u32 c, u32 d);
extern void func_021F4510(u8 *p, u32 i);

void func_021F43D8(u32 *a, u32 b, s16 *c, u32 d, u16 e)
{
    int i;
    u32 t;
    s16 m;
    u16 *h = (u16 *)a;
    u8 *q;

    i = 0;
    t = func_020056EC(0);
    m = c[d];
    h[0] = i;
    h[1] = 0x10 + t % m;
    a[2] = func_02045B38(0, 3, 0x9f, e);
    a[3] = b;
    a[1] = t & 0xf;
    q = (u8 *)a + 0x10;
    for (i = 0; i < 16; i++) {
        func_021F4510(q + i * 8, (u16)i);
    }
}
