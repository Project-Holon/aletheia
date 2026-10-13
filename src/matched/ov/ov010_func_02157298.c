/*
 * function: MUSICAL_PROGRAM_PackPicks
 * address:  0x02157298
 * packet:   pkt_ov010_02157298
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Little-endian 24-bit read from bytes 8..10 of a record (inverse of
 * MUSICAL_PROGRAM_UnpackPicks).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

u32 MUSICAL_PROGRAM_PackPicks(const u8 *p)
{
    return p[8] + (p[9] << 8) + (p[10] << 16);
}
