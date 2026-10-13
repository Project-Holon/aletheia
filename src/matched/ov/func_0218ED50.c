/*
 * function: FIELD_CAMERA_GetViewYawPtr
 * address:  0x0218ED50
 * packet:   pkt_0218EC2C
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the object pointer advanced by 0x82 bytes.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 *FIELD_CAMERA_GetViewYawPtr(u8 *p)
{
    return p + 0x82;
}

