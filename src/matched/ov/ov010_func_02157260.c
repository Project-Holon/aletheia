/*
 * function: func_02157260
 * address:  0x02157260
 * packet:   pkt_ov010_02157260
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Little-endian 32-bit read from a byte record (inverse of func_02157278).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

u32 func_02157260(const u8 *p)
{
    return p[0] + (p[1] << 8) + (p[2] << 16) + (p[3] << 24);
}
