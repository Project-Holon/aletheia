/*
 * function: func_021CBED8
 * address:  0x021CBED8
 * packet:   pkt_ov021_021CBED8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Forwarder into ov010 that drops the first argument and returns its byte result.
 *
 * symbols:
 *   func_02168878  0x02168878  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 func_02168878(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

u8 func_021CBED8(u32 unused, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g)
{
    return func_02168878(a, b, c, d, e, f, g);
}
