/*
 * function: FIELD_PLAYER_CORE_GetStepPhase
 * address:  0x021A3970
 * packet:   pkt_021A3970
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf getter at +0x10.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELD_PLAYER_CORE_GetStepPhase(u32 *p)
{
    return p[4];
}
