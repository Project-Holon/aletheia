/*
 * function: func_021BAB80
 * address:  0x021BAB80
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
 *   func_021BC634  0x021BC634  thumb  ov217
 *   func_021BC638  0x021BC638  thumb  ov217
 *   func_021BC640  0x021BC640  thumb  ov217
 *   func_021BC758  0x021BC758  thumb  ov217
 *   func_021BC774  0x021BC774  thumb  ov217
 *   func_021C09AC  0x021C09AC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021BC634();
extern u32 func_021BC638();
extern u32 func_021BC640();
extern u32 func_021BC758();
extern u32 func_021BC774();
extern u32 func_021C09AC();
u32 func_021BAB80(u32 a0, u32 a1)
{
    u32 v1 = func_021C09AC();
    u32 v2 = func_021BC758();
    func_021BC774();
    func_021BC634(v2, v1);
    func_021BC638(v2, a0);
    func_021BC640(v2, a1);
    return v2;
}

