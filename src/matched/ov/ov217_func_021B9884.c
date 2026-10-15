/*
 * function: RESEARCH_TOP_DestroyCommon
 * address:  0x021B9884
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   RESEARCH_COMMON_Destroy  0x021C099C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj08431.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 RESEARCH_COMMON_Destroy(void *a0);
u32 RESEARCH_TOP_DestroyCommon(u32 a0)
{
    RESEARCH_COMMON_Destroy((void *)(((struct Obj08431 *)(((u8*)a0)))->fC));
    ((struct Obj08431 *)(((u8*)a0)))->fC = 0;
    return 0;
}

