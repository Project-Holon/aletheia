/*
 * function: func_021BE46C
 * address:  0x021BE46C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   RESEARCH_COMMON_GetPreviousScreen  0x021C09C8  thumb  ov217
 *   RESEARCH_COMMON_GetEntryHandled  0x021C09CC  thumb  ov217
 *
 * Classifies the record: 3 when the first query is busy and the second is
 * not, else 2.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25902.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 RESEARCH_COMMON_GetPreviousScreen(void *p);
extern u32 RESEARCH_COMMON_GetEntryHandled(void *p);
u32 func_021BE46C(u8 *a0)
{
    u32 v = ((struct Obj25902 *)a0)->f0;
    u32 a = RESEARCH_COMMON_GetPreviousScreen((void *)v);
    u32 b = RESEARCH_COMMON_GetEntryHandled((void *)v);
    if (a != 0 && b == 0) {
    return 3;
    }
    return 2;
}
