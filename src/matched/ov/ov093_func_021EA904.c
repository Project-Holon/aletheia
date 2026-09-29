/*
 * function: func_021EA904
 * address:  0x021EA904
 * packet:   pkt_ov093_021EA904
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E9100  0x021E9100  thumb  ov093
 *   func_021B8BEC  0x021B8BEC  thumb  ov093
 *   func_021EA990  0x021EA990  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *func_021E9100(u8 *p, int n);
extern u8 func_021B8BEC(u8 *p, u32 a, u32 b);
extern int func_021EA990(int *st, u8 *b);

void func_021EA904(u32 *p, u32 a, u32 b, u32 c, u8 d, u8 e)
{
    u8 *t;

    t = func_021E9100((u8 *)p, 7);
    t[0] = a;
    t[1] = b;
    t[2] = c;
    t[3] = d;
    t[4] = e;
    t[5] = func_021B8BEC((u8 *)p[0], a, d);
    t[6] = func_021B8BEC((u8 *)p[0], a, e);
    p[7] = 0;
    p[8] = (u32)func_021EA990;
    p[9] = (u32)p;
    p[10] = 0;
}
