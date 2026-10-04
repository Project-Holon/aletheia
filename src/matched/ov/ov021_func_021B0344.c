/*
 * function: func_021B0344
 * address:  0x021B0344
 * packet:   pkt_ov021_021B0344
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02158F78  0x02158F78  thumb  ov010
 *   func_02158F7C  0x02158F7C  thumb  ov010
 *   func_0215A7F0  0x0215A7F0  thumb  ov010
 */

typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern u32 func_02011330(u32);
extern unsigned int func_02159B10(void *a0, void *a1);
typedef unsigned char  u8;
extern u32 func_02158F78(u8 *p);
extern u32 func_02158F7C(u8 *p);
extern u32 func_0215A7F0(u32, u32, u32, u32, u32, u32);

int func_021B0344(u32 a, u32 b)
{
    u32 x, y, z;
    void *t;

    t = func_0215A5F4((void *)b);
    x = func_02011330(a);
    y = func_02011330(a);
    z = func_02159B10((void *)a, (void *)b);
    func_0215A7F0(b, x, y, z, func_02158F78(t), func_02158F7C(t));
    return 0;
}
