/*
 * function: MUSICAL_PROGRAM_PackBonus
 * address:  0x02157260
 * packet:   pkt_ov010_02157260
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Little-endian 32-bit read from a byte record (inverse of MUSICAL_PROGRAM_UnpackBonus).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

u32 MUSICAL_PROGRAM_PackBonus(const u8 *p)
{
    return p[0] + (p[1] << 8) + (p[2] << 16) + (p[3] << 24);
}
