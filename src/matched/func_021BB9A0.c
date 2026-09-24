/*
 * function: func_021BB9A0
 * address:  0x021BB9A0
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
 *   func_021BBCFC  0x021BBCFC  thumb  ov217
 *   func_021BBD18  0x021BBD18  thumb  ov217
 *   func_021BBD28  0x021BBD28  thumb  ov217
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

extern u32 func_020061E4();
extern u32 func_021BBCFC();
extern u32 func_021BBD18();
extern u32 func_021BBD28();
extern u32 func_021BC580();
u32 func_021BB9A0(u32 a0)
{
    func_021BBD28(a0, *(u32*)(((u8*)a0) + 44));
    func_021BBCFC(a0, -1);
    func_021BBD18(a0, *(u32*)(((u8*)a0) + 44));
    func_020061E4(1352);
    return func_021BC580(a0, 4);
}

