/*
 * function: RESEARCH_LIST_GetRowOffset
 * address:  0x021BBF04
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_LIST_FindSaveIndex  0x021BBC50  thumb  ov217
 *
 * Returns 2, or 1 when RESEARCH_LIST_FindSaveIndex() reports the caller's own a1.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u8 RESEARCH_LIST_FindSaveIndex(u8 *p);
u32 RESEARCH_LIST_GetRowOffset(u32 a0, u32 a1)
{
    u8 v = 2;
    if (a1 == RESEARCH_LIST_FindSaveIndex((u8 *)a0)) {
    v -= 1;
    }
    return v;
}
