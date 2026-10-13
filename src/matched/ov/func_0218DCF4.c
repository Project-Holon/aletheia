/*
 * function: FIELD_G3D_MAPPER_SlotResHasGroundAnime
 * address:  0x0218DCF4
 * packet:   pkt_0218DCF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to FIELD_G3D_MAPPER_SlotResTestGroundAnime with no argument change.
 *
 * symbols:
 *   FIELD_G3D_MAPPER_SlotResTestGroundAnime  0x0218DD5C  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_G3D_MAPPER_SlotResTestGroundAnime(u32 *p);

int FIELD_G3D_MAPPER_SlotResHasGroundAnime(u32 *a0)
{
    return FIELD_G3D_MAPPER_SlotResTestGroundAnime(a0);
}
