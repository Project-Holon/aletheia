/*
 * function: ZKNSEARCH_MAIN_ClearEntry4
 * address:  0x021BE278
 * packet:   pkt_021BE278
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKNSEARCH_MAIN_PrintEntryCount4  0x021BEB8C  thumb  ov210
 *   ZKNSEARCH_MAIN_HideColumnActors  0x021BF81C  thumb  ov210
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00222.h"
#include "../include/Obj25611.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void ZKNSEARCH_MAIN_PrintEntryCount4(u8 *);
extern void ZKNSEARCH_MAIN_HideColumnActors(char *p);

void ZKNSEARCH_MAIN_ClearEntry4(u8 *p)
{
    u32 t = *(u32 *)&((struct Obj00222 *)p)->f0;
    *(u8 *)(((struct Obj25611 *)t)->f8 + 5) = 0xff;
    ZKNSEARCH_MAIN_PrintEntryCount4(p);
    ZKNSEARCH_MAIN_HideColumnActors((char *)p);
}

