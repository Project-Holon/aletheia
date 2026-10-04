/*
 * function: func_021B95A0
 * address:  0x021B95A0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_021B985C  0x021B985C  thumb  ov217
 *   func_021B9874  0x021B9874  thumb  ov217
 *   func_021B9894  0x021B9894  thumb  ov217
 *   func_021B98B8  0x021B98B8  thumb  ov217
 *   func_021B9920  0x021B9920  thumb  ov217
 *   func_021B9A24  0x021B9A24  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct DispVram;
struct Obj0203159C;
extern void func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32 swap);
extern void func_021B985C(void *p, u32 value);
extern void func_021B9874(u32 a0);
extern void func_021B9894(u32 a0);
extern u32 func_021B98B8();
extern u32 func_021B9920();
extern void func_021B9A24(u32 heap);
u32 func_021B95A0(u32 a0, u32 a1, u8 *a2, u32 a3)
{
    switch (*(u32*)(((u8*)a1))) {
    case 0:
    func_0203159C((struct Obj0203159C *)a0, 32, 1);
    *(u32*)(((u8*)a1)) = (u32)(*(u32*)(((u8*)a1)) + 1);
    break;
    case 1:
    func_021B985C((void *)a3, *(u32*)(((u8*)a2)));
    func_020433E0((const struct DispVram *)0x21C2EA0);
    func_0204363C(0);
    func_021B98B8(*(u16*)(((u8*)a3)));
    func_021B9A24(*(u16*)(((u8*)a3)));
    func_021B9920(*(u16*)(((u8*)a3)));
    func_021B9874(a3);
    func_021B9894(a3);
    return 1;
    }
    return 0;
}

