/*
 * function: TALKMSGWIN_IsEntryShown
 * address:  0x02194A84
 * packet:   pkt_02194A84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Untraced .word blob in ov021 (only reached by an r3 tail call): predicate
 * on a u16 field.  Listing bytes 00 88 04 28 01 D1 01 20 70 47 00 20 70 47.
 *
 * symbols:
 *   TALKMSGWIN_IsEntryShown  0x02194A84  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int TALKMSGWIN_IsEntryShown(u16 *p, int i)
{
    return *p == 4;
}
