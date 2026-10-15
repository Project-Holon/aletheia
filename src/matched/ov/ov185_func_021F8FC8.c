/*
 * function: BR_POKESEARCH_HitTab
 * address:  0x021F8FC8
 * packet:   pkt_021F8FC8
 * region:   ov185
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BR_UTIL_StartEffect   0x021FD860  thumb
 *   GFL_USE_PlaySeDefaultVolume   0x020061E4  thumb
 *
 * Range-gate the pair then hand them to 0x21FD860 as a two-word record.
 */
#include "../include/Obj24761.h"


extern void BR_UTIL_StartEffect(int, int, int *);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

int BR_POKESEARCH_HitTab(int a, int b, int c)
{
    int ok = ((unsigned)(b - 0x40) <= 0x78) & ((unsigned)(c - 0x10) <= 0x20);
    if (ok) {
        int buf[2];
        buf[0] = b;
        buf[1] = c;
        BR_UTIL_StartEffect(((struct Obj24761 *)a)->f3C, 1, buf);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}
