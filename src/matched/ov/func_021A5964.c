/*
 * function: FIELD_PLAYER_NOGRID_ClearRailWork
 * address:  0x021A5964
 * packet:   pkt_021A5964
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf: clears the word at +0x20.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void FIELD_PLAYER_NOGRID_ClearRailWork(u32 *p)
{
    p[8] = 0;
}
