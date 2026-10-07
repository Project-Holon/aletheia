/*
 * file:     game_beacon_search_p13.c
 * unit:     yes
 * function: func_02165760, func_0216576C
 * address:  0x02165760
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
 *   func_0202744C   0x0202744C  thumb
 *   func_02027060   0x02027060  thumb
 *   func_02026FB8   0x02026FB8  thumb
 *   g_02146940      0x02146940  data
 *   func_02165794   0x02165794  thumb  ov010
 */
#include "../../matched/include/Obj00121.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_0202744C(void *dst);
extern u32 func_02027060(u32 a);
extern void func_02026FB8(void *);
extern int func_02165794(int a0, int a1);
void func_02165760(void *a0);
void func_0216576C(void *a0);
extern char *g_02146940;


/*
 * Short thunk: stamp the id halfword on the record and hand it
 * straight to the shared submitter.
 */
void func_02165760(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 0x2E;
    func_0202744C(a0);
}


/*
 * Test id 0x2F against the overlay's table and, when it takes, file the
 * record at the shared globals pointer (sibling of func_02165634).
 */
void func_0216576C(void *a0)
{
    if (func_02027060(0x2F)) {
        func_02165794((int)(g_02146940 + 4), (int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}
