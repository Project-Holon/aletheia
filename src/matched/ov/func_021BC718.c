/*
 * function: ZUKAN_DETAIL_COMMON_StartFadeIn
 * address:  0x021BC718
 * packet:   pkt_021BC6D8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZUKAN_DETAIL_COMMON_IsFadeBusy 0x021BC6C8  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_RequestFade 0x021BC7B4  thumb  ov208

 * Runs the idle transition with 0x10 twice and marks state 1.
 */
#include "../include/Obj18189.h"


extern int ZUKAN_DETAIL_COMMON_IsFadeBusy(char *);
extern void ZUKAN_DETAIL_COMMON_RequestFade(char *p, short b, unsigned char c, unsigned char d);

void ZUKAN_DETAIL_COMMON_StartFadeIn(char *p)
{
    if (ZUKAN_DETAIL_COMMON_IsFadeBusy(p))
        return;
    ZUKAN_DETAIL_COMMON_RequestFade(p, 0, 0x10, 0x10);
    ((struct Obj18189 *)p)->f10 = 1;
}

