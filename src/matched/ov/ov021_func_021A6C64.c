/*
 * function: FIELD_PLAYER_NOGRID_IsInputHoldKept
 * address:  0x021A6C64
 * packet:   pkt_021A6C64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned int u32;

u32 FIELD_PLAYER_NOGRID_IsInputHoldKept(u8 *p)
{
    return ((u32)*p << 30) >> 31;
}
