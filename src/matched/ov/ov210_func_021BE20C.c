/*
 * function: ZKNSEARCH_MAIN_ClearEntry3
 * address:  0x021BE20C
 * packet:   pkt_ov210_021BE20C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZKNSEARCH_MAIN_PrintEntryCount3  0x021BEA54  thumb  ov210
 *   ZKNSEARCH_MAIN_HideColumnActors  0x021BF81C  thumb  ov210
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00222.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
extern void ZKNSEARCH_MAIN_PrintEntryCount3(u8 *p);
extern void ZKNSEARCH_MAIN_HideColumnActors(char *p);

void ZKNSEARCH_MAIN_ClearEntry3(u8 *p)
{
    (*(u8 **)(*(u8 * *)&((struct Obj00222 *)p)->f0 + 8))[3] = 0xff;
    (*(u8 **)(*(u8 * *)&((struct Obj00222 *)p)->f0 + 8))[4] = 0xff;
    ZKNSEARCH_MAIN_PrintEntryCount3(p);
    ZKNSEARCH_MAIN_HideColumnActors((char *)p);
}
