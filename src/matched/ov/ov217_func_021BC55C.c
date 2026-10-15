/*
 * function: RESEARCH_LIST_IsPaletteFadeDone
 * address:  0x021BC55C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The listing extent runs long (into the following data) because the next
 * function has no label; all concrete bytes reproduce.
 *
 * symbols:
 *   PALANM_GetFadeRequestBits  0x02021ED8  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25858.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 PALANM_GetFadeRequestBits(const char *ptr);
u32 RESEARCH_LIST_IsPaletteFadeDone(u32 a0)
{
    if (PALANM_GetFadeRequestBits((const char *)(((struct Obj25858 *)((u8*)a0))->f98)) == 0) {
    return 1;
    }
    return 0;
}
