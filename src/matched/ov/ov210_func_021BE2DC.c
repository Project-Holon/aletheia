/*
 * function: ZKNSEARCH_MAIN_ClearEntry5
 * address:  0x021BE2DC
 * packet:   pkt_021BE2DC
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKNSEARCH_MAIN_ShowEntry6Actor  0x021BF618  thumb  ov210
 *   ZKNSEARCH_MAIN_HideColumnActors  0x021BF81C  thumb  ov210
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14678.h"
#include "../include/Obj25613.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void ZKNSEARCH_MAIN_ShowEntry6Actor(char *p);
extern void ZKNSEARCH_MAIN_HideColumnActors(char *p);

void ZKNSEARCH_MAIN_ClearEntry5(u8 *p)
{
    u32 t = *(u32 *)&((struct Obj14678 *)p)->f0;
    *(u8 *)(((struct Obj25613 *)t)->f8 + 6) = 0xff;
    ZKNSEARCH_MAIN_ShowEntry6Actor((char *)p);
    ZKNSEARCH_MAIN_HideColumnActors((char *)p);
}

