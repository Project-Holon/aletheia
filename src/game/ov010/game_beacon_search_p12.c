/*
 * file:     game_beacon_search_p12.c
 * unit:     yes
 * function: func_021656F8, func_0216570C, func_02165730, func_0216573C
 * address:  0x021656F8
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
 *   func_0202744C 0x0202744C thumb
 *   func_02027060   0x02027060  thumb
 *   func_02026FB8   0x02026FB8  thumb
 *   g_02146940      0x02146940  data
 *   func_02165760   0x02165760  thumb  ov010
 */
#include "../../matched/include/Obj00121.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_0202744C(void *);
extern u32 func_02027060(u32 a);
extern void func_02026FB8(void *);
extern void func_02165760(void *);
void func_021656F8(u8 *p, u8 v);
void func_0216570C(void);
void func_02165730(void *a0);
void func_0216573C(void);
extern char *g_02146940;

void func_021656F8(u8 *p, u8 v) { ((struct Obj00121 *)p)->f30=0x2c; p[0x34]=v; func_0202744C(p); }


/*
 * Gate on an id test, then submit the record at the shared globals
 * pointer.
 */
void func_0216570C(void)
{
    if (func_02027060(0x2D)) {
        func_02165730(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}


/*
 * Short thunk: stamp the id halfword on the record and hand it
 * straight to the shared submitter.
 */
void func_02165730(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 0x2D;
    func_0202744C(a0);
}


void func_0216573C(void)
{
    if (func_02027060(0x2E)) {
        func_02165760(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}
