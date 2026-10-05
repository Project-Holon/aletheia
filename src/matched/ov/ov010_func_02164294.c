/*
 * function: func_02164294
 * address:  0x02164294
 * packet:   pkt_ov010_02164294
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf, blocker of ov021 func_0218B4B0: widens three integers to 16.16 fixed point.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_02164294(int x, int y, int z, int *out)
{
    out[0] = x << 16;
    out[1] = y << 16;
    out[2] = z << 16;
}
