/*
 * function: ZKNSEARCH_MAIN_ClearEntry2
 * address:  0x021BE178
 * packet:   pkt_021BE178
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKNSEARCH_MAIN_PrintEntryCount2  0x021BE978  thumb  ov210
 *   ZKNSEARCH_MAIN_HideColumnActors  0x021BF81C  thumb  ov210
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00222.h"
#include "../include/Obj25607.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void ZKNSEARCH_MAIN_PrintEntryCount2(u8 *);
extern void ZKNSEARCH_MAIN_HideColumnActors(char *p);

void ZKNSEARCH_MAIN_ClearEntry2(u8 *p)
{
    u32 t = *(u32 *)&((struct Obj00222 *)p)->f0;
    *(u8 *)(((struct Obj25607 *)t)->f8 + 2) = 0xff;
    ZKNSEARCH_MAIN_PrintEntryCount2(p);
    ZKNSEARCH_MAIN_HideColumnActors((char *)p);
}

