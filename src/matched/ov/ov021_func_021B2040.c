/*
 * function: func_021B2040
 * address:  0x021B2040
 * packet:   pkt_ov021_021B2040
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3238  0x021A3238  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
typedef unsigned char  u8;
extern int func_02158F58(int a0);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_021A3238(u8 *p);

int func_021B2040(u32 a, u32 b)
{
    void *x = func_02188CB4((struct Obj00020 *)(((u32 *)func_02158F58((int)func_0215A5F4((void *)b)))[1]));
    u16 *o = func_02159AE8((void *)a, (void *)b);

    *o = func_021A3238(x);
    return 0;
}
