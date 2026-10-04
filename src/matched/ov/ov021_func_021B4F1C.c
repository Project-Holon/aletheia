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
extern unsigned int func_02159B10(void *, void *);
struct Big;
struct Sub020090B0Obj;
struct Sub02009210Obj;
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern void func_020090D8(struct Sub020090B0Obj *obj, u8 value);
extern void *func_02168BBC(void *a, void *b);

int func_021B4F1C(u32 a, u32 b)
{
    u32 r7;
    u32 r5;
    void *r6;
    void *r4;

    r7 = (u32)func_02009210(func_02012EBC(func_0215A5E4((void *)b)));
    r5 = func_02159B10((void *)a, (void *)b);
    r6 = func_0215A5F4((void *)b);
    r4 = func_0215A5DC((void *)b);
    func_020090D8((struct Sub020090B0Obj *)r7, 1);
    func_0215897C(r6, func_02168BBC(r4, (void *)r5));
    return 1;
}
