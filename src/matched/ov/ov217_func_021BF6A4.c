/*
 * function: func_021BF6A4
 * address:  0x021BF6A4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PALANM_GetFadeRequestBits  0x02021ED8  thumb
 *
 * Note: the record's +0x3B8 handle is idle.
 * blocker: the only relocation is PALANM_GetFadeRequestBits (0x02021ED8), which has no
 *            witness outside 021BF6A4..021BF6BC.  Bytes are exact and 24/24
 *            match the listing extent; file the TARGET first (OV-BRIEF rule
 *            10) and this promotes to EXACT with no source change.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25929.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 PALANM_GetFadeRequestBits(const char *ptr);
u32 func_021BF6A4(u8 *a0)
{
    if (PALANM_GetFadeRequestBits((const char *)(((struct Obj25929 *)(((u8*)a0)))->f3B8)) == 0) {
    return 1;
    }
    return 0;
}
