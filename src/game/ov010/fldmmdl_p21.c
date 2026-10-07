/*
 * file:     fldmmdl_p21.c
 * unit:     yes
 * function: func_0216D60C, func_0216D620
 * address:  0x0216D60C
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
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D600  0x0216D600  thumb  ov010
 */
#include "../../matched/include/Obj00113.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_0216D5E0();
extern int func_0216D600(int a0, int a1);
int func_0216D60C(int a0, int a1);
int func_0216D620(int a0, int a1, int a2);


int func_0216D60C(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_0216D5E0(a0, a1);
loc_0216D616:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0216D600(a0, a1);
loc_0216D61E:
    return a0;}




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
