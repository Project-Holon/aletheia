/*
 * function: MAP_ATTR_GetAt
 * address:  0x021AB0D4
 * packet:   pkt_ov021_021AB0D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Runs the lookup FIELD_G3D_MAPPER_QueryNearestHit into a four-word buffer and returns its third
 * word on success, -1 otherwise.
 *
 * symbols:
 *   FIELD_G3D_MAPPER_QueryNearestHit  0x0218DAEC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern int FIELD_G3D_MAPPER_QueryNearestHit(void *a, void *b, u32 *out);

int MAP_ATTR_GetAt(void *a, void *b)
{
    u32 buf[4];

    if (FIELD_G3D_MAPPER_QueryNearestHit(a, b, buf) == 1)
        return buf[2];
    return -1;
}
