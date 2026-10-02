/*
 * function: func_021C26E8
 * address:  0x021C26E8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_021C28FC  0x021C28FC  thumb  ov217
 *   func_021C291C  0x021C291C  thumb  ov217
 *   func_021C2934  0x021C2934  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021C28FC(u32 a0);
extern u32 func_021C291C();
extern u32 func_021C2934();
u32 func_021C26E8(u32 a0, u32 a1, u32 a2)
{
    u32 v1 = func_021C28FC(a0);
    func_021C291C(v1, a0);
    func_021C2934(v1, a1, a2);
    return v1;
}

