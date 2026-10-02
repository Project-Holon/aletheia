/*
 * function: func_021C11FC
 * address:  0x021C11FC
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
 *   func_021C1AC0  0x021C1AC0  thumb  ov217
 *   func_021C1B74  0x021C1B74  thumb  ov217
 *   func_021C1F44  0x021C1F44  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *func_021C1AC0(u32 a0, u8 a1);
extern u32 func_021C1B74();
extern u32 func_021C1F44();
u32 func_021C11FC(u32 a0, u8 a1, u32 a2, u32 a3)
{
    u8 s[8];
    func_021C1B74(a0, func_021C1AC0(a0, a1), s + 0);
    return func_021C1F44(s + 0, a2, a3);
}

