/*
 * function: func_0215A64C
 * address:  0x0215A64C
 * packet:   pkt_ov010_0215A64C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, blocker of ov021 func_021C457C/func_021C4608: reads the word at +0x10 of the record held at +0x20.
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

void *func_0215A64C(void *p)
{
    return *(void **)(*(char **)((char *)p + 0x20) + 0x10);
}
