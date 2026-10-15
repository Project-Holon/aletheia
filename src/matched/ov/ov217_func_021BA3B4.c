/*
 * function: RESEARCH_TOP_IsSelectionValid
 * address:  0x021BA3B4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   RESEARCH_TOP_CountUnlockedEntries  0x021BA434  thumb  ov217
 *
 * Returns 1 unless a1 is zero and RESEARCH_TOP_CountUnlockedEntries() reports more than one.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern unsigned char RESEARCH_TOP_CountUnlockedEntries(char *p);
u32 RESEARCH_TOP_IsSelectionValid(u32 a0, u32 a1)
{
    if (a1 == 0) {
    if (RESEARCH_TOP_CountUnlockedEntries((char *)a0) > 1) {
    return 1;
    }
    return 0;
    }
    return 1;
}
