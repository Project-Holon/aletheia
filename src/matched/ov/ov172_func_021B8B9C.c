/*
 * function: CTVT_COMM_GetPeerStatus
 * address:  0x021B8B9C
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Address 0x40 bytes into the second argument.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

char *CTVT_COMM_GetPeerStatus(int unused, char *base)
{
    return base + 0x40;
}
