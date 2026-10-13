/*
 * function: MUSICAL_EVENT_GetPlayerOfSlot
 * address:  0x021568E8
 * packet:   pkt_021568E8
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
#include "../include/Obj17618.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int MUSICAL_EVENT_GetPlayerOfSlot(int a0, u8 a1)
{
    int a2;
    int a3;

a3 = 0;
loc_021568EA:
a2 = a0 + a3;
a2 = a2 + 0x44;
a2 = ((struct Obj17618 *)((char *)a2))->f0;
    if (a1 != a2) goto loc_021568F8;
loc_021568F4:
a0 = a3 + 0;
    return a0;
loc_021568F8:
a2 = a3 + 1;
a2 = a2 << 0x18;
a3 = (unsigned)a2 >> 0x18;
    if ((unsigned)a3 < (unsigned)4) goto loc_021568EA;
loc_02156902:
a0 = 0;
    return a0;}
