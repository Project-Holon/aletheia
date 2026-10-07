/*
 * file:     game_beacon_search_p11.c
 * unit:     yes
 * function: func_02165690, func_021656A0, func_021656C4, func_021656D0
 * address:  0x02165690
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
 *   func_02027060   0x02027060  thumb
 *   func_02026FB8   0x02026FB8  thumb
 *   g_02146940      0x02146940  data
 *   func_021656F8   0x021656F8  thumb  ov010
 */
#include "../../matched/include/Obj00121.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_0202744C(void *);
extern u32 func_02027060(u32 a);
extern void func_02026FB8(void *);
extern void func_021656F8(void *, void *);
void func_02165690(void *a0);
void func_021656A0(void);
void func_021656C4(void *a0);
void func_021656D0(void *a0);
extern char *g_02146940;


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
 *   python tools/match.py one --src src/matched/func_02165690.c \
 *       --func func_02165690 --addr 0x02165690 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_02165690(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 42;
    *(u32 *)((char *)a0 + 52) = 0;
    func_0202744C(a0);
}


/*
 * Gate on an id test, then submit the record at the shared globals
 * pointer.
 */
void func_021656A0(void)
{
    if (func_02027060(0x2B)) {
        func_021656C4(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}


/*
 * Short thunk: stamp the id halfword on the record and hand it
 * straight to the shared submitter.
 */
void func_021656C4(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 0x2B;
    func_0202744C(a0);
}


void func_021656D0(void *a0)
{
    if (func_02027060(0x2C)) {
        func_021656F8(g_02146940 + 4, a0);
        func_02026FB8(g_02146940 + 4);
    }
}
