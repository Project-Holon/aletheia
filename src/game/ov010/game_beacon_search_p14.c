/*
 * file:     game_beacon_search_p14.c
 * unit:     yes
 * function: func_02165794, func_021657B0
 * address:  0x02165794
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
 *   func_020270AC  0x020270AC  thumb
 *   func_0202744C  0x0202744C  thumb
 *   func_02027060 0x02027060 thumb
 *   func_02026FB8 0x02026FB8 thumb
 *   g_02146940 0x02146940 data
 *   func_021657D8 0x021657D8 thumb ov010
 */
#include "../../matched/include/Obj00121.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_020270AC();
extern int func_0202744C();
extern u32 func_02027060(u32 a);
extern void func_02026FB8(void *);
extern void func_021657D8(void *,u16);
int func_02165794(int a0, int a1);
void func_021657B0(u16 v);
extern char *g_02146940;


int func_02165794(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = 0x2f;
((struct Obj00121 *)t4)->f30 = a0;
a0 = a1 + 0;
a1 = t4 + 0;
a1 = a1 + 0x34;
    a0 = func_020270AC(a0, a1);
loc_021657A6:
a0 = t4 + 0;
    a0 = func_0202744C(a0);
loc_021657AC:
    return a0;}

void func_021657B0(u16 v) { if(func_02027060(0x30)) { func_021657D8(g_02146940+4,v); func_02026FB8(g_02146940+4); } }
