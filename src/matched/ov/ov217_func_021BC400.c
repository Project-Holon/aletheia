/*
 * function: RESEARCH_LIST_EntryIndexToYBottom
 * address:  0x021BC400
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   RESEARCH_LIST_EntryIndexToY  0x021BC3F8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 RESEARCH_LIST_EntryIndexToY(u32 v);
u32 RESEARCH_LIST_EntryIndexToYBottom(u32 v)
{
    return RESEARCH_LIST_EntryIndexToY(v) + 23;
}

