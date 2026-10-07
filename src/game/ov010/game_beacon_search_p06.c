/*
 * file:     game_beacon_search_p06.c
 * unit:     yes
 * function: func_0216528C, func_021652B4, func_021652C4, func_021652EC, func_0216530C, func_02165334, func_02165344, func_02165368
 * address:  0x0216528C
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
 *   func_0202744C  0x0202744C  thumb
 */
#include "../../matched/include/Obj00121.h"

struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Obj { u8 pad[3]; u8 lo:7; u8 hi:1; u8 gap[0x2c]; u16 event; } Obj;

extern u32 func_02027060(u32 a);
extern void func_02026FB8(void *);
extern void func_0202744C(void *);
void func_0216528C(void *a0);
void func_021652B4(void *a0, unsigned a1);
void func_021652C4(void *a0);
void func_021652EC(Obj *p,u32 v);
void func_0216530C(void *a0);
void func_02165334(void *a0, unsigned a1);
void func_02165344(void);
void func_02165368(void *a0);
extern char *g_02146940;


/*
 * Test the id against the overlay's table and, when it takes,
 * re-submit the record at the shared globals pointer.
 */
void func_0216528C(void *a0)
{
    if (func_02027060(0xB)) {
        func_021652B4(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
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
 *   python tools/match.py one --src src/matched/func_021652B4.c \
 *       --func func_021652B4 --addr 0x021652B4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_021652B4(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 11;
    ((struct Obj00121 *)a0)->f34 = a1;
    func_0202744C(a0);
}


void func_021652C4(void *a0)
{
    if (func_02027060(0x12)) {
        func_021652EC((struct Obj *)(g_02146940 + 4), (u32)a0);
        func_02026FB8(g_02146940 + 4);
    }
}

void func_021652EC(Obj *p,u32 v) { p->event=0x12; p->lo=(u8)v; func_0202744C(p); }


void func_0216530C(void *a0)
{
    if (func_02027060(0x13)) {
        func_02165334(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
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
 *   python tools/match.py one --src src/matched/func_02165334.c \
 *       --func func_02165334 --addr 0x02165334 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_02165334(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 19;
    ((struct Obj00121 *)a0)->f34 = a1;
    func_0202744C(a0);
}


/*
 * Gate on an id test, then submit the record at the shared globals pointer.
 */
void func_02165344(void)
{
    if (func_02027060(0x15)) {
        func_02165368(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
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
 *   python tools/match.py one --src src/matched/func_02165368.c \
 *       --func func_02165368 --addr 0x02165368 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_02165368(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 21;
    func_0202744C(a0);
}
