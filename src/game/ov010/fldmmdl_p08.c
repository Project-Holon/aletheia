/*
 * file:     fldmmdl_p08.c
 * unit:     yes
 * function: func_0216CD50, func_0216CD64
 * address:  0x0216CD50
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
 *   func_02197C4C  0x02197C4C  thumb
 *   func_0216CD30  0x0216CD30  thumb  ov010
 *   func_02030D28  0x02030D28  arm
 *   func_0219C5FC  0x0219C5FC  thumb
 */
#include "../../matched/include/Obj17770.h"
#include "../../matched/include/Obj01464.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_02197C4C();
extern int func_0216CD30();
extern int func_02030D28();
extern int func_0219C5FC();
int func_0216CD50(int a0);
int func_0216CD64(int a0);


int func_0216CD50(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_02197C4C(a0);
loc_0216CD58:
a0 = 0;
((struct Obj17770 *)t4)->f40 = a0;
a0 = t4 + 0;
    a0 = func_0216CD30(a0);
loc_0216CD62:
    return a0;}


int func_0216CD64(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj01464 *)t4)->f20;
    a0 = func_02030D28(a0);
loc_0216CD6E:
a0 = t4 + 0;
    a0 = func_0219C5FC(a0);
loc_0216CD74:
    return a0;}
