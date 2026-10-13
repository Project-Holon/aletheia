/*
 * function: MOVE_POKEMON_IsSkillUsable
 * address:  0x0215F104
 * packet:   pkt_0215F104
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
#include "../include/Obj17701.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int MOVE_POKEMON_IsSkillUsable(int a0, int a1)
{
    int a2;
    int a3;

a3 = ((struct Obj17701 *)a0)->f2;
a2 = 1;
a2 = a2 << a1;
a1 = a3 + 0;
a0 = 1;
    if ((a1 & a2) != 0) goto loc_0215F114;
loc_0215F112:
a0 = 0;
loc_0215F114:
    return a0;}
