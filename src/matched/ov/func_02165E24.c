/*
 * function: GAME_BEACON_ACCESSOR_GetActionNo
 * address:  0x02165E24
 * packet:   pkt_02165E24
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none: no relocation site)
 */
#include "../include/Obj17726.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int GAME_BEACON_ACCESSOR_GetActionNo(int a0)
{

a0 = ((struct Obj17726 *)a0)->f30;
    if (a0 == 0) goto loc_02165E2E;
loc_02165E2A:
    if ((unsigned)a0 < (unsigned)0x33) goto loc_02165E30;
loc_02165E2E:
a0 = 1;
loc_02165E30:
    return a0;}
