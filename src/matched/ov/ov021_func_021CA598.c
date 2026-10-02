/*
 * function: func_021CA598
 * address:  0x021CA598
 * packet:   pkt_ov021_021CA598
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012ED8  0x02012ED8  thumb
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021C9B24  0x021C9B24  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0215A5F4(void *p);
extern void func_02158F58(void *h);
extern u32 func_02158F54(void *h);
extern u32 func_020120F4(u32 a);
extern u32 func_02012ED8(u32 a);
extern void func_021C9B24(u32 a, u32 b);
int func_021CA598(u32 a, u32 b)
{
    void *h = func_0215A5F4((void *)b);
    u32 x;
    func_02158F58(h);
    x = func_02158F54(h);
    func_021C9B24(x, func_02012ED8(func_020120F4(x)));
    return 0;
}
