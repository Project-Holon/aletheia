/*
 * file:     game_beacon_search_p09.c
 * unit:     yes
 * function: func_02165424, func_0216544C, func_02165468
 * address:  0x02165424
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
 *   func_02027060   0x02027060  thumb
 *   func_02026FB8   0x02026FB8  thumb
 *   g_02146940      0x02146940  data
 *   func_020270AC  0x020270AC  thumb
 *   func_0202744C  0x0202744C  thumb
 *   func_02165490   0x02165490  thumb  ov010
 */
#include "../../matched/include/Obj00121.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u32 func_02027060(u32 a);
extern void func_02026FB8(void *);
extern int func_020270AC();
extern int func_0202744C();
extern int func_02165490(int a0, int a1);
void func_02165424(void *a0);
int func_0216544C(int a0, int a1);
void func_02165468(void *a0);
extern char *g_02146940;


/*
 * Test the id against the overlay's table and, when it takes,
 * re-submit the record at the shared globals pointer.
 */
void func_02165424(void *a0)
{
    if (func_02027060(0x1F)) {
        func_0216544C((int)(g_02146940 + 4), (int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}


int func_0216544C(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = 0x1f;
((struct Obj00121 *)t4)->f30 = a0;
a0 = a1 + 0;
a1 = t4 + 0;
a1 = a1 + 0x34;
    a0 = func_020270AC(a0, a1);
loc_0216545E:
a0 = t4 + 0;
    a0 = func_0202744C(a0);
loc_02165464:
    return a0;}


void func_02165468(void *a0)
{
    if (func_02027060(0x20)) {
        func_02165490((int)(g_02146940 + 4), (int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}
