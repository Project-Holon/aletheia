/*
 * function: RESEARCH_LIST_IsValidIndex
 * address:  0x021BC6F4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_LIST_GetEntryCount  0x021BC6DC  thumb  ov217
 *
 * 1 while a1 is below RESEARCH_LIST_GetEntryCount(), else 0.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 RESEARCH_LIST_GetEntryCount(void *p);
u32 RESEARCH_LIST_IsValidIndex(u32 a0, u32 a1)
{
    if (a1 < RESEARCH_LIST_GetEntryCount((void *)a0)) {
    return 1;
    }
    return 0;
}
