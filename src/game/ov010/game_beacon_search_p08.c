/*
 * file:     game_beacon_search_p08.c
 * unit:     yes
 * function: func_021653F4, func_02165418
 * address:  0x021653F4
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
 *   func_0202744C   0x0202744C  thumb
 */
#include "../../matched/include/Obj00121.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u32 func_02027060(u32 a);
extern void func_02026FB8(void *);
extern void func_0202744C(void *dst);
void func_021653F4(u16 species);
void func_02165418(void *a0);
extern char *g_02146940;


/*
 * Gate on an id test, then submit the record at the shared globals
 * pointer.
 */
void func_021653F4(u16 species)
{
    if (func_02027060(0x1E)) {
        func_02165418(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}


/*
 * Short thunk: stamp the id halfword on the record and hand it
 * straight to the shared submitter.
 */
void func_02165418(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 0x1E;
    func_0202744C(a0);
}
