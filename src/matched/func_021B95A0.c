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

extern u32 func_0203159C();
extern u32 func_020433E0();
extern u32 func_0204363C();
extern u32 func_021B985C();
extern u32 func_021B9874();
extern u32 func_021B9894();
extern u32 func_021B98B8();
extern u32 func_021B9920();
extern u32 func_021B9A24();
u32 func_021B95A0(u32 a0, u32 a1, u8 *a2, u32 a3)
{
    switch (*(u32*)(((u8*)a1))) {
    case 0:
    func_0203159C(a0, 32, 1);
    *(u32*)(((u8*)a1)) = (u32)(*(u32*)(((u8*)a1)) + 1);
    break;
    case 1:
    func_021B985C(a3, *(u32*)(((u8*)a2)));
    func_020433E0(0x21C2EA0);
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

