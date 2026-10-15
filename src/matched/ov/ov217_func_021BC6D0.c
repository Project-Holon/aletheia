/*
 * function: RESEARCH_LIST_GetInputFlag
 * address:  0x021BC6D0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   RESEARCH_LIST_GetOwner  0x021BC63C  thumb  ov217
 *   RESEARCH_COMMON_GetInputFlag  0x021C09F8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 RESEARCH_LIST_GetOwner(void *p);
extern u32 RESEARCH_COMMON_GetInputFlag(void *p);
u32 RESEARCH_LIST_GetInputFlag(void *p)
{
    return RESEARCH_COMMON_GetInputFlag((void *)RESEARCH_LIST_GetOwner(p));
}

