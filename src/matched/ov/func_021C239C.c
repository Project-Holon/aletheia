/*
 * function: ZUKAN_DETAIL_AREA_DisableWindowsAndBrightness
 * address:  0x021C239C
 * packet:   pkt_021C239C
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
 * Masks 0x04000000 with 0xFFFF1FFF, then tail-calls ZUKAN_DETAIL_COMMON_InitBrightnessTarget on the word at +0x418.
 */
#include "../include/Obj18288.h"

extern void ZUKAN_DETAIL_COMMON_InitBrightnessTarget(int *p);

void ZUKAN_DETAIL_AREA_DisableWindowsAndBrightness(char *p)
{
    *(volatile unsigned int *)0x04000000 &= 0xffff1fff;
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget((int *)(((struct Obj18288 *)p)->f418));
}
