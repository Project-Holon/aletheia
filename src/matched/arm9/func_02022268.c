/*
 * unit:     no
 * address:  0x02022268
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: WIPE_SetMstBrightColor
 *
 * symbols:
 *   g_021468E4     0x021468E4  data
 *   WIPE_SetBrightness  0x020222CC  thumb
 *
 * Same sentinel-mapping shape as WIPE_SetBrightnessFadeOut.c, but read-modify-write:
 * it substitutes the sentinel readback the same way, maps the result to
 * one of the same two hardware constants, forwards it to both of
 * WIPE_SetBrightness's hardware selections (0 and 1), and then stores the
 * *pre-mapping* colour back into the same halfword field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SetMstBrightColor.c \
 *       --func WIPE_SetMstBrightColor --addr 0x02022268 --cc 1.1p1 --thumb
 */

#include "../include/G_021468E4.h"

typedef unsigned int   u32;
typedef unsigned short u16;
typedef unsigned char  u8;

extern void WIPE_SetBrightness(u32 which, int brightness);

extern struct G_021468E4 g_021468E4;

void WIPE_SetMstBrightColor(u32 color)
{
    u32 mapped;

    if (color == 0xFFFF) {
        color = g_021468E4.f10;
    }
    if (color == 0x7FFF) {
        mapped = 0x10;
    } else {
        mapped = ~(u32)0xF;
    }
    WIPE_SetBrightness(0, mapped);
    WIPE_SetBrightness(1, mapped);
    g_021468E4.f10 = color;
}
