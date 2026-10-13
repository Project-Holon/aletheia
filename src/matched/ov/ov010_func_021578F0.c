/*
 * function: DELIVERY_BEACON_HasAnyPiece
 * address:  0x021578F0
 * packet:   pkt_ov010_021578F0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, blocker of ov021 func_021D0C58: whether any of 18 slots (stride 100) has its flag byte set.
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

int DELIVERY_BEACON_HasAnyPiece(void *p)
{
    int i;

    for (i = 0; i < 18; i++) {
        if (((u8 *)p)[i * 100 + 0xd9] != 0) {
            return 1;
        }
    }
    return 0;
}
