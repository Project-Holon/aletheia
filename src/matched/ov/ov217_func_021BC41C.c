/*
 * function: RESEARCH_LIST_GetScrollRangeMax
 * address:  0x021BC41C
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
 *   RESEARCH_LIST_GetScrollRange  0x021BC40C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern int RESEARCH_LIST_GetScrollRange(void *p);
u32 RESEARCH_LIST_GetScrollRangeMax(void *p)
{
    return RESEARCH_LIST_GetScrollRange(p) + 168;
}

