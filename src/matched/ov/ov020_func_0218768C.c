/*
 * function: EL_SCOREBOARD_TickLamp
 * address: 0x0218768C
 * packet: pkt_ov020_0218768C
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: capture the base in a local before filling the stack pair, preserving the original r3 load.
 * symbols:
 *   EL_SCOREBOARD_AnimateLampPalette 0x021876B0 thumb ov020
 */
#include "../include/Obj07404.h"
typedef struct { int index; char *base; } Pair;
extern void EL_SCOREBOARD_AnimateLampPalette(Pair *p, int tick);
void EL_SCOREBOARD_TickLamp(char *p)
{
    Pair pair;
    char *base;
    (((struct Obj07404 *)p)->f18)++;
    base = *(char * *)&((struct Obj07404 *)p)->f14;
    if (base != (char *)-1) {
        pair.index = ((struct Obj07404 *)p)->fC;
        pair.base = base;
        EL_SCOREBOARD_AnimateLampPalette(&pair, ((struct Obj07404 *)p)->f18);
    }
}
