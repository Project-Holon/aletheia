/*
 * function: ZUKAN_DETAIL_COMMON_StartFadeOut
 * address:  0x021BC6D8
 * packet:   pkt_021BC6D8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_COMMON_IsFadeBusy 0x021BC6C8  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_RequestFade 0x021BC7B4  thumb  ov208

 * Runs the idle transition when ZUKAN_DETAIL_COMMON_IsFadeBusy is false and marks state 2.
 */
#include "../include/Obj18187.h"


extern int ZUKAN_DETAIL_COMMON_IsFadeBusy(char *);
extern void ZUKAN_DETAIL_COMMON_RequestFade(char *p, short b, unsigned char c, unsigned char d);

void ZUKAN_DETAIL_COMMON_StartFadeOut(char *p)
{
    if (ZUKAN_DETAIL_COMMON_IsFadeBusy(p))
        return;
    ZUKAN_DETAIL_COMMON_RequestFade(p, -1, 0x10, 0);
    ((struct Obj18187 *)p)->f10 = 2;
}

