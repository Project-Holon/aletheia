/*
 * function: RESEARCH_COMMON_GetContext
 * address:  0x021C09B0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter: word at +4.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 RESEARCH_COMMON_GetContext(u32 *p);
u32 RESEARCH_COMMON_GetContext(u32 *p)
{
    return p[1];
}

