/*
 * function: func_02167B18
 * address:  0x02167B18
 * packet:   pkt_ov010_02167B18
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, blocker of ov021 func_021CB8AC: tail call of func_0203A5E4(0x2C00); the argument is ignored.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * symbols:
 *   func_0203A5E4  0x0203A5E4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_0203A5E4(u32 key);

void func_02167B18(void *p)
{
    func_0203A5E4(0x2c00);
}
