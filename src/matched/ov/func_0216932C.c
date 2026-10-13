/*
 * function: FIELD_G3D_MAP_WaitLoad
 * address:  0x0216932C
 * packet:   pkt_0216932C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_G3D_MAP_Update  0x02169308  thumb  ov010
 *   FIELD_G3D_MAP_GetActiveRef  0x02169520  thumb  ov010
 */
#include "../include/Obj04162.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FIELD_G3D_MAP_Update();
extern int FIELD_G3D_MAP_GetActiveRef(int a0, int a1);

int FIELD_G3D_MAP_WaitLoad(int a0)
{
    int a1;
    int v0;
    int t4;
    int t5;
t5 = a0 + 0;
a0 = 1;
((struct Obj04162 *)t5)->f2 = a0;
t4 = (int)&v0;
loc_02169336:
a0 = t5 + 0;
    a0 = FIELD_G3D_MAP_Update(a0);
loc_0216933C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FIELD_G3D_MAP_GetActiveRef(a0, a1);
loc_02169344:
    a0 = v0;
a0 = ((struct Obj04162 *)((char *)a0))->f0;
    if (a0 != 0) goto loc_02169336;
loc_0216934C:
a0 = 0;
((struct Obj04162 *)t5)->f2 = a0;
    return a0;
}
