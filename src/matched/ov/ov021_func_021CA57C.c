/*
 * function: func_021CA57C
 * address:  0x021CA57C
 * packet:   pkt_ov021_021CA57C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021C9924  0x021C9924  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0215A5F4(void *p);
extern void func_02158F58(u32 h);
extern u32 func_02158F54(u32 h);
extern void func_021C9924(u32 a);
int func_021CA57C(u32 a, u32 b)
{
    void *h = func_0215A5F4((void *)b);
    func_02158F58(h);
    func_021C9924(func_02158F54(h));
    return 0;
}
