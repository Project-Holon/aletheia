/*
 * function: func_021B503C
 * address:  0x021B503C
 * packet:   pkt_ov021_021B503C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AA0A0  0x021AA0A0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern void func_0215897C(void *vm, void *task);
extern unsigned int func_02159B10(void *a, void *b);
extern void *func_02158F54(void *p);
extern int func_02158F58(int a0);
extern u32 func_02188CE8(u8 *p);
extern u32 func_021AA0A0(u32 a, u32 b, u32 c, u32 d);

int func_021B503C(u32 a, u32 b)
{
    void *r4;
    u32 s0;
    u32 r7;
    u32 r5;

    r4 = func_0215A5F4((void *)b);
    s0 = func_02159B10((void *)a, (void *)b);
    r7 = func_02159B10((void *)a, (void *)b);
    r5 = func_02159B10((void *)a, (void *)b);
    func_02158F54(r4);
    func_0215897C(r4, (void *)func_021AA0A0(func_02188CE8((u8 *)(((u32 *)func_02158F58((int)r4))[1])), s0, (u8)r7, r5));
    return 1;
}
