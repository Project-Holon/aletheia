/*
 * function: func_021B4F1C
 * address:  0x021B4F1C
 * packet:   pkt_ov021_021B4F1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009210  0x02009210  thumb
 *   func_020090D8  0x020090D8  thumb
 *   func_02168BBC  0x02168BBC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern void func_0215897C(void *a, void *b);
extern u32 func_02159B10(u32 a, u32 b);
extern u32 func_02012EBC(void *a);
extern u32 func_02009210(u32 a);
extern void func_020090D8(u32 a, u32 b);
extern void *func_02168BBC(void *a, u32 b);

int func_021B4F1C(u32 a, u32 b)
{
    u32 r7;
    u32 r5;
    void *r6;
    void *r4;

    r7 = func_02009210(func_02012EBC(func_0215A5E4((void *)b)));
    r5 = func_02159B10(a, b);
    r6 = func_0215A5F4((void *)b);
    r4 = func_0215A5DC((void *)b);
    func_020090D8(r7, 1);
    func_0215897C(r6, func_02168BBC(r4, r5));
    return 1;
}
