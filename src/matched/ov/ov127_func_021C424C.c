/*
 * function: WIFI_2DCHAR_SetSubActorDrawEnable
 * address:  0x021C424C
 * packet:   pkt_021C424C
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14015.h"

typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);

void WIFI_2DCHAR_SetSubActorDrawEnable(char *p, int a)
{
    if (((struct Obj14015 *)p)->f8 != 0)
        CLACT_SetActorDrawEnable(((struct Obj14015 *)p)->f8, a);
}
