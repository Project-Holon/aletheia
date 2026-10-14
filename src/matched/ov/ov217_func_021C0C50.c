/*
 * function: RESEARCH_COMMON_DeletePalAnm
 * address:  0x021C0C50
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
 *   PALANM_Delete  0x02021540  thumb
 *   RESEARCH_COMMON_DeletePalAnm  0x021C0C50  thumb  ov217
 *

 * BLOCKED at MATCH: the relocation site(s) below have no independent witness.
 *   +0008 ABS32 PALANM_Delete          -> unresolved: 02021540 (arm, from name) has no witness outside 021C0C50..021C0C5C
 * Promote automatically when the target is matched.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25990.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 PALANM_Delete(void *a0);
void RESEARCH_COMMON_DeletePalAnm(u8 *a0)
{
    PALANM_Delete((void *)(((struct Obj25990 *)(((u8*)a0)))->f28));
}

