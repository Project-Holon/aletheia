/*
 * function: func_021BBAA4
 * address:  0x021BBAA4
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
 *   func_021BBD38  0x021BBD38  thumb  ov217
 *   func_021BBD68  0x021BBD68  thumb  ov217
 *   func_021BBDAC  0x021BBDAC  thumb  ov217
 *   func_021BC580  0x021BC580  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_020061E4(u32 a);
extern u32 func_021BBD38();
extern u32 func_021BBD68();
extern void func_021BBDAC(u8 *p);
extern u32 func_021BC580();
u32 func_021BBAA4(u32 a0, u32 a1)
{
    func_021BBDAC((u8 *)a0);
    func_021BBD38(a0, a1);
    func_021BBD68(a0);
    func_020061E4(1352);
    return func_021BC580(a0, 1);
}

