/*
 * function: func_021B9824
 * address:  0x021B9824
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD62C  0x021BD62C  thumb  ov217
 *   func_021BD708  0x021BD708  thumb  ov217
 *   func_021BD710  0x021BD710  thumb  ov217
 *
 * Mode query against the +0x18 body: 3 when the body is inert, else 4
 * when it is still busy, else 1.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021BD62C();
extern u32 func_021BD708();
extern u32 func_021BD710();
u32 func_021B9824(u32 a0)
{
    func_021BD62C(*(u32*)(((u8*)a0) + 24));
    if (func_021BD708(*(u32*)(((u8*)a0) + 24)) != 0) {
    if (func_021BD710(*(u32*)(((u8*)a0) + 24)) == 0) {
    return 1;
    }
    return 4;
    }
    return 3;
}
