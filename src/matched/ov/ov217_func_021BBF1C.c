/*
 * function: RESEARCH_LIST_GetRowBase
 * address:  0x021BBF1C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Three times the byte argument, truncated to u8.  The first parameter is unused.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 RESEARCH_LIST_GetRowBase(u32 unused, u32 v)
{
    return (u8)(v * 3);
}
