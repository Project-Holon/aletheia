/*
 * file:     game_beacon_search_p16.c
 * unit:     yes
 * function: func_02165844, func_0216586C
 * address:  0x02165844
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
 *   func_02027060 0x02027060 thumb
 *   func_02026FB8 0x02026FB8 thumb
 *   g_02146940 0x02146940 data
 *   func_02045A38  0x02045A38  arm
 *   func_0202744C  0x0202744C  thumb
 */
#include "../../matched/include/Obj00121.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u32 func_02027060(u32 a);
extern void func_02026FB8(void *);
extern int func_02045A38();
extern int func_0202744C();
void func_02165844(void *v);
int func_0216586C(int a0, int a1);
extern char *g_02146940;

void func_02165844(void *v) { if(func_02027060(0x31)) { func_0216586C((int)(g_02146940+4),(int)v); func_02026FB8(g_02146940+4); } }


int func_0216586C(int a0, int a1)
{
    int a2;
    int t4;

t4 = a0 + 0;
a0 = a1 + 0;
a1 = t4 + 0;
a1 = a1 + 0x34;
a2 = 9;
    a0 = func_02045A38(a0, a1, a2);
loc_0216587C:
a0 = 0x31;
((struct Obj00121 *)t4)->f30 = a0;
a0 = t4 + 0;
    a0 = func_0202744C(a0);
loc_02165886:
    return a0;}
