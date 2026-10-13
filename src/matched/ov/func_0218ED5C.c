/*
 * function: FIELD_CAMERA_GetVectorAngles
 * address:  0x0218ED5C
 * packet:   pkt_0218ED5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_CAMERA_CalcAngles  0x0218E610  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_CAMERA_CalcAngles(u32, u32, u32, u32);

int FIELD_CAMERA_GetVectorAngles(u32 a, u32 b, u32 c, u32 d)
{
return FIELD_CAMERA_CalcAngles(a, b, c, d);
}

