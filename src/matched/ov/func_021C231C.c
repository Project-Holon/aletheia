/*
 * function: ZUKAN_DETAIL_AREA_ApplyBrightness
 * address:  0x021C231C
 * packet:   pkt_021C231C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_COMMON_InitBrightnessTarget 0x021BC518  thumb  ov208
 *
 * Loads the word at +0x418 and tail-calls ZUKAN_DETAIL_COMMON_InitBrightnessTarget with it.
 */
#include "../include/Obj18287.h"

extern void ZUKAN_DETAIL_COMMON_InitBrightnessTarget(int *p);

void ZUKAN_DETAIL_AREA_ApplyBrightness(char *p)
{
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget((int *)(((struct Obj18287 *)p)->f418));
}
