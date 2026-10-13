/*
 * function: FIELD_ENCOUNT_ST_GetEffectEncount
 * address:  0x0215E33C
 * packet:   pkt_0215E33C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetEncount  0x02188CE8  thumb
 *   EFFECT_ENCOUNT_LoadSetting  0x021AA7DC  thumb
 */
#include "../include/Obj17696.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FIELDMAP_GetEncount();
extern int EFFECT_ENCOUNT_LoadSetting();

int FIELD_ENCOUNT_ST_GetEffectEncount(int a0)
{
    int a1;

    a0 = FIELDMAP_GetEncount(a0);
loc_0215E342:
a1 = ((struct Obj17696 *)a0)->f10;
    a0 = EFFECT_ENCOUNT_LoadSetting(a0, a1);
loc_0215E348:
    return a0;}
