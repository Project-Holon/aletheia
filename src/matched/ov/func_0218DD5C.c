/*
 * function: FIELD_G3D_MAPPER_SlotResTestGroundAnime
 * address:  0x0218DD5C
 * packet:   pkt_0218DD5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Disasm reads its bytes as `.word` because it saves no lr; it is the
 * callee of the thunk at 0x0218DCF4.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;



int FIELD_G3D_MAPPER_SlotResTestGroundAnime(u32 *p)
{
    return *p != 0;
}
