/*
 * function: func_021B0130
 * address:  0x021B0130
 * packet:   pkt_ov021_021B0130
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B010C  0x021B010C  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern u32 func_021B010C(u32 a, u32 x, u32 y);
extern void func_0215897C(void *vm, void *task);

int func_021B0130(u32 a, u32 b)
{
    u16 *r = func_02159AE8((void *)a, (void *)b);
    void *x = func_0215A5F4((void *)b);

    func_0215897C(x, (void *)func_021B010C((u32)func_0215A5DC((void *)b), b, (u32)r));
    return 1;
}
