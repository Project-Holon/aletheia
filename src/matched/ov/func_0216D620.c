/*
 * function: func_0216D620
 * address:  0x0216D620
 * packet:   pkt_0216D620
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none: no relocation site)
 */
#include "../include/Obj00113.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int func_0216D620(int a0, int a1, int a2)
{

    if (a2 == 0) goto loc_0216D62E;
loc_0216D624:
    if (a2 == 1) goto loc_0216D632;
loc_0216D628:
    if (a2 == 2) goto loc_0216D636;
loc_0216D62C:
    return a0;
loc_0216D62E:
((struct Obj00113 *)a0)->f20 = a1;
    return a0;
loc_0216D632:
((struct Obj00113 *)a0)->f22 = a1;
    return a0;
loc_0216D636:
((struct Obj00113 *)a0)->f24 = a1;
    return a0;}
