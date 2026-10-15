/*
 * function: BR_POKESEARCH_HitPrev
 * address:  0x021F9008
 * packet:   pkt_021F9008
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
#include "../include/Obj24762.h"


extern void BR_UTIL_StartEffect(int, int, int *);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

int BR_POKESEARCH_HitPrev(int a, int b, int c)
{
    int ok = ((unsigned)(b - 0x18) <= 0x28) & ((unsigned)(c - 0x40) <= 0x28);
    if (ok) {
        int buf[2];
        buf[0] = b;
        buf[1] = c;
        BR_UTIL_StartEffect(((struct Obj24762 *)a)->f3C, 1, buf);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}
