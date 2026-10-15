/*
 * function: BR_CODEIN_ButtonLoadFadePalettes
 * address:  0x021DB924
 * packet:   pkt_021DB924
 * region:   ov183
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BR_RES_LoadFadePalettes  0x021FC240  thumb  ov186
 */
#include "../include/Obj08309.h"
#include "../include/Obj14420.h"

extern void BR_RES_LoadFadePalettes(char *p, void *owner, unsigned short heap);

void BR_CODEIN_ButtonLoadFadePalettes(int a0, char *p)
{
    int v = ((struct Obj08309 *)p)->f10;
    char *q = *(char * *)&((struct Obj08309 *)p)->fC;

    if (v == 0) {
        BR_RES_LoadFadePalettes((char *)(((struct Obj14420 *)q)->f18), (void *)(((struct Obj14420 *)q)->f10),
                      ((struct Obj08309 *)p)->f14);
    }
    ((struct Obj08309 *)p)->f10 = 1;
}
