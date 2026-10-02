/*
 * function: func_021CA544
 * address:  0x021CA544
 * packet:   pkt_ov021_021CA544
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02011330  0x02011330  thumb
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021C9934  0x021C9934  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0215A5F4(void *p);
extern void func_02158F58(void *h);
extern u32 func_02158F54(void *h);
extern u32 func_02011330(u32 a);
extern u32 func_02159B10(u32 a, u32 b);
extern void func_021C9934(u32 a, u32 b, u32 c);
int func_021CA544(u32 a, u32 b)
{
    void *h = func_0215A5F4((void *)b);
    u32 x, y;
    func_02158F58(h);
    x = func_02158F54(h);
    y = func_02011330(a);
    func_021C9934(x, y, func_02159B10(a, b));
    return 0;
}
