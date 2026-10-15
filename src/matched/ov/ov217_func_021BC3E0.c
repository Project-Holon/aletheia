/*
 * function: RESEARCH_LIST_GetScrollMax
 * address:  0x021BC3E0
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
 *   RESEARCH_LIST_GetScrollY  0x021BC3AC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern int RESEARCH_LIST_GetScrollY(void);
u32 RESEARCH_LIST_GetScrollMax(void)
{
    return RESEARCH_LIST_GetScrollY() + 168;
}

