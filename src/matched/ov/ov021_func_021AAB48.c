/*
 * function: EFFECT_ENCOUNT_GetItemId
 * address:  0x021AAB48
 * packet:   pkt_021AAB48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj19848.h"
#include "../include/Obj19849.h"

typedef unsigned short u16;

u16 EFFECT_ENCOUNT_GetItemId(char *p)
{
    return ((struct Obj19849 *)(*(char * *)&((struct Obj19848 *)p)->f10))->f5BC;
}
