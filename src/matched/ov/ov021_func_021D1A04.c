/*
 * function: func_021D1A04
 * address:  0x021D1A04
 * packet:   pkt_ov021_021D1A04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021D182C  0x021D182C  thumb  ov021
 *   func_02159104  0x02159104  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);
extern u16 func_02188C84(u8 *p);
extern unsigned int func_02159B10(void *a, void *b);
extern void *func_02188CB4(unsigned char *p);
struct VecFx32;
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern u8 *func_021D182C(u32 a, u32 b, u32 *c, u32 d);
extern void func_02159104(u8 *p, u32 v);

int func_021D1A04(u32 a, u32 b)
{
    u32 buf[3];
    void *s = func_0215A5F4((void *)b);
    u32 *q = (u32 *)func_02158F58((int)s);
    u32 t = func_02188C84((u8 *)q[1]);
    u32 k = func_02159B10((void *)a, (void *)b);
    u8 *r;

    func_021A3038(func_02188CB4((u8 *)q[1]), (struct VecFx32 *)buf);
    r = func_021D182C(q[1], k, buf, t);
    func_02159104(s, (u32)r);
    return 0;
}
