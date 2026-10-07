/*
 * file:     game_beacon_search_p15.c
 * unit:     yes
 * function: func_021657D8, func_021657E8
 * address:  0x021657D8
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
 *   func_0202744C  0x0202744C  thumb
 *   func_02027060 0x02027060 thumb
 *   func_02026FB8 0x02026FB8 thumb
 *   g_02146940 0x02146940 data
 *   func_02165814 0x02165814 thumb ov010
 */
#include "../../matched/include/Obj00121.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_0202744C(void *);
extern u32 func_02027060(u32 a);
extern void func_02026FB8(void *);
extern void func_02165814(u8 *,void *,u16);
void func_021657D8(void *a0, u16 a1);
void func_021657E8(void *a,u16 b);
extern char *g_02146940;


void func_021657D8(void *a0, u16 a1)
{
    ((struct Obj00121 *)a0)->f30 = 48;
    ((struct Obj00121 *)a0)->f34 = a1;
    func_0202744C(a0);
}

void func_021657E8(void *a,u16 b) { if(func_02027060(0x18)) { func_02165814((u8 *)g_02146940+4,a,b); func_02026FB8(g_02146940+4); } }
