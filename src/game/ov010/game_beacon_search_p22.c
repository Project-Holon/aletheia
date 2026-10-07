/*
 * file:     game_beacon_search_p22.c
 * unit:     yes
 * function: func_02165D6C, func_02165D8C
 * address:  0x02165D6C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204581C  0x0204581C  arm
 *   func_02045924  0x02045924  arm
 */
#include "../../matched/include/Obj17724.h"
#include "../../matched/include/Obj17725.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_0204581C();
extern int func_02045924();
int func_02165D6C(int a0, int a1);
int func_02165D8C(int a0, int a1);


int func_02165D6C(int a0, int a1)
{
    int a2;

a2 = a0 + 0;
a0 = ((struct Obj17724 *)a2)->f30;
    if (a0 == 0x18) goto loc_02165D7E;
loc_02165D76:
a0 = a1 + 0;
    a0 = func_0204581C(a0);
loc_02165D7C:
    return a0;
loc_02165D7E:
a2 = a2 + 0x34;
a0 = a1 + 0;
a1 = a2 + 0;
    a0 = func_02045924(a0, a1);
loc_02165D88:
    return a0;}


int func_02165D8C(int a0, int a1)
{
    int a2;

a2 = a0 + 0;
a0 = ((struct Obj17725 *)a2)->f30;
    if (a0 == 0x31) goto loc_02165D9E;
loc_02165D96:
a0 = a1 + 0;
    a0 = func_0204581C(a0);
loc_02165D9C:
    return a0;
loc_02165D9E:
a2 = a2 + 0x34;
a0 = a1 + 0;
a1 = a2 + 0;
    a0 = func_02045924(a0, a1);
loc_02165DA8:
    return a0;}
