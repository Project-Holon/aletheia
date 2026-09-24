/*
 * function: func_021C0F5C
 * address:  0x021C0F5C
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
 *   func_021C0F78  0x021C0F78  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_020307B0();
extern u32 func_02045EC0();
extern u32 func_021C0F78();
u32 func_021C0F5C(u32 a0)
{
    u32 v4 = func_02045EC0(*(u32*)(((u8*)a0) + 20));
    func_021C0F78(a0, v4);
    return func_020307B0(v4);
}

