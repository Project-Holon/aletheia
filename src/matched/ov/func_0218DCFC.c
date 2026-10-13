/*
 * function: FIELD_G3D_MAPPER_SlotResGetGroundAnime
 * address:  0x0218DCFC
 * packet:   pkt_0218DCFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to FIELD_G3D_MAPPER_SlotResReadGroundAnime with no argument change.
 *
 * symbols:
 *   FIELD_G3D_MAPPER_SlotResReadGroundAnime  0x0218DD6C  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_G3D_MAPPER_SlotResReadGroundAnime(u32 *p);

int FIELD_G3D_MAPPER_SlotResGetGroundAnime(u32 *a0)
{
    return FIELD_G3D_MAPPER_SlotResReadGroundAnime(a0);
}
