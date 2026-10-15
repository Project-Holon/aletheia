/*
 * function: ZKNSEARCH_MAIN_ExitState
 * address:  0x021BD36C
 * packet:   pkt_021BD36C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKNSEARCH_MAIN_SetFadeStateB  0x021BCD3C  thumb  ov210
 *   ZKNSEARCH_MAIN_SetActorVisible  0x021BEDF0  thumb  ov210
 *   ZKNSEARCH_MAIN_DeleteCursorMove  0x021BFF18  thumb  ov210
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01779.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void ZKNSEARCH_MAIN_SetFadeStateB(u8 *);
extern void ZKNSEARCH_MAIN_SetActorVisible(int p, int i, int v);
extern void ZKNSEARCH_MAIN_DeleteCursorMove(int p);

u32 ZKNSEARCH_MAIN_ExitState(u8 *p)
{
    ZKNSEARCH_MAIN_SetFadeStateB(p);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 7, 0);
    ZKNSEARCH_MAIN_DeleteCursorMove((int)p);
    return ((struct Obj01779 *)p)->f18;
}

