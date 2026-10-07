/*
 * file:     game_beacon_search_p10.c
 * unit:     yes
 * function: func_02165490, func_021654AC, func_021654D4, func_021654F0, func_02165518, func_02165534, func_0216555C, func_0216556C, func_02165590, func_0216559C, func_021655C4, func_021655D4, func_021655F8, func_02165604, func_02165628, func_02165634, func_0216565C, func_0216566C
 * address:  0x02165490
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
 *   func_02027060   0x02027060  thumb
 *   func_02026FB8   0x02026FB8  thumb
 *   g_02146940      0x02146940  data
 *   func_02165690   0x02165690  thumb  ov010
 */
#include "../../matched/include/Obj00121.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_020270AC();
extern int func_0202744C();
extern u32 func_02027060(u32 a);
extern void func_02026FB8(void *);
extern void func_02165690(void *);
int func_02165490(int a0, int a1);
void func_021654AC(void *a0);
int func_021654D4(int a0, int a1);
void func_021654F0(void *a0);
int func_02165518(int a0, int a1);
void func_02165534(void *a0);
void func_0216555C(void *a0, unsigned a1);
void func_0216556C(void);
void func_02165590(void *a0);
void func_0216559C(void *a0);
void func_021655C4(void *a0, unsigned a1);
void func_021655D4(void);
void func_021655F8(void *a0);
void func_02165604(void);
void func_02165628(void *a0);
void func_02165634(void *a0);
void func_0216565C(void *a0, unsigned a1);
void func_0216566C(void);
extern char *g_02146940;


int func_02165490(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = 0x20;
((struct Obj00121 *)t4)->f30 = a0;
a0 = a1 + 0;
a1 = t4 + 0;
a1 = a1 + 0x34;
    a0 = func_020270AC(a0, a1);
loc_021654A2:
a0 = t4 + 0;
    a0 = func_0202744C(a0);
loc_021654A8:
    return a0;}


/*
 * Test the id against the overlay's table and, when it takes,
 * re-submit the record at the shared globals pointer.
 */
void func_021654AC(void *a0)
{
    if (func_02027060(0x21)) {
        func_021654D4((int)(g_02146940 + 4), (int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}


int func_021654D4(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = 0x21;
((struct Obj00121 *)t4)->f30 = a0;
a0 = a1 + 0;
a1 = t4 + 0;
a1 = a1 + 0x34;
    a0 = func_020270AC(a0, a1);
loc_021654E6:
a0 = t4 + 0;
    a0 = func_0202744C(a0);
loc_021654EC:
    return a0;}


void func_021654F0(void *a0)
{
    if (func_02027060(0x22)) {
        func_02165518((int)(g_02146940 + 4), (int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}


int func_02165518(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = 0x22;
((struct Obj00121 *)t4)->f30 = a0;
a0 = a1 + 0;
a1 = t4 + 0;
a1 = a1 + 0x34;
    a0 = func_020270AC(a0, a1);
loc_0216552A:
a0 = t4 + 0;
    a0 = func_0202744C(a0);
loc_02165530:
    return a0;}


void func_02165534(void *a0)
{
    if (func_02027060(0x24)) {
        func_0216555C(g_02146940 + 4, (unsigned int)a0);
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
 *   python tools/match.py one --src src/matched/func_0216555C.c \
 *       --func func_0216555C --addr 0x0216555C --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216555C(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 36;
    ((struct Obj00121 *)a0)->f34 = a1;
    func_0202744C(a0);
}


/*
 * Gate on an id test, then submit the record at the shared globals
 * pointer.
 */
void func_0216556C(void)
{
    if (func_02027060(0x25)) {
        func_02165590(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}


/*
 * Short thunk: stamp the id halfword on the record and hand it
 * straight to the shared submitter.
 */
void func_02165590(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 0x25;
    func_0202744C(a0);
}


void func_0216559C(void *a0)
{
    if (func_02027060(0x26)) {
        func_021655C4(g_02146940 + 4, (unsigned int)a0);
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
 *   python tools/match.py one --src src/matched/func_021655C4.c \
 *       --func func_021655C4 --addr 0x021655C4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_021655C4(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 38;
    ((struct Obj00121 *)a0)->f32 = a1;
    func_0202744C(a0);
}


void func_021655D4(void)
{
    if (func_02027060(0x27)) {
        func_021655F8(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}


void func_021655F8(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 0x27;
    func_0202744C(a0);
}


void func_02165604(void)
{
    if (func_02027060(0x28)) {
        func_02165628(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}


void func_02165628(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 0x28;
    func_0202744C(a0);
}


void func_02165634(void *a0)
{
    if (func_02027060(0x29)) {
        func_0216565C(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}


/*
 * Stamp the fixed id halfword and the caller's value on the two
 * record fields, then jump to the shared submitter.
 */
void func_0216565C(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 0x29;
    *(u32 *)((char *)a0 + 0x34) = (u32)a1;
    func_0202744C(a0);
}


void func_0216566C(void)
{
    if (func_02027060(0x2A)) {
        func_02165690(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}
