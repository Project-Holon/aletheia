/*
 * file:     game_beacon_search_p07.c
 * unit:     yes
 * function: func_02165374, func_021653B4, func_021653C4, func_021653E8
 * address:  0x02165374
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
 *   d_02171CA0      0x02171CA0  data  ov010  a1
 *   func_0202744C  0x0202744C  thumb
 */
#include "../../matched/include/Obj00121.h"

typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

extern u32 func_02027060(u32 a);
extern void func_02026FB8(void *);
extern void func_0202744C(void *);
void func_02165374(unsigned a0);
void func_021653B4(void *a0, unsigned a1);
void func_021653C4(void);
void func_021653E8(void *a0);
extern char *g_02146940;
extern u8 d_02171CA0[5];


/*
 * Looks the id up in a five-entry byte table; on a hit re-submits the
 * record at the shared globals pointer.
 */
void func_02165374(unsigned a0)
{
    unsigned i;

    if (func_02027060(0x16)) {
        for (i = 0; i < 5; i++) {
            if (a0 == d_02171CA0[i]) {
                func_021653B4(g_02146940 + 4, a0);
                func_02026FB8(g_02146940 + 4);
                return;
            }
        }
    }
}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0202744C, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021653B4.c \
 *       --func func_021653B4 --addr 0x021653B4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_021653B4(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 22;
    *(u32 *)((char *)a0 + 52) = a1;
    func_0202744C(a0);
}


/*
 * Gate on an id test, then submit the record at the shared globals
 * pointer.
 */
void func_021653C4(void)
{
    if (func_02027060(0x17)) {
        func_021653E8(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}


/*
 * Short thunk: stamp the id halfword on the record and hand it
 * straight to the shared submitter.
 */
void func_021653E8(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 0x17;
    func_0202744C(a0);
}
