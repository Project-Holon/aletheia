/*
 * file:     game_beacon_search_p05.c
 * unit:     yes
 * function: func_021650BC, func_021650CC, func_021650F4, func_02165104, func_0216512C, func_0216513C, func_02165164, func_02165174, func_0216519C, func_021651AC, func_021651D4, func_021651E4, func_0216520C, func_0216521C, func_02165244, func_02165254, func_0216527C
 * address:  0x021650BC
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
 *   func_020273C4   0x020273C4  thumb
 *   func_02027060   0x02027060  thumb
 *   func_02026FB8   0x02026FB8  thumb
 *   g_02146940      0x02146940  data
 *   func_0202744C  0x0202744C  thumb
 *   func_020273DC   0x020273DC  thumb
 *   func_020273F8   0x020273F8  thumb
 *   func_02027414   0x02027414  thumb
 *   func_02027430   0x02027430  thumb
 */
#include "../../matched/include/Obj12050.h"
#include "../../matched/include/Obj00121.h"
#include "../../matched/include/Obj05717.h"
#include "../../matched/include/Obj05718.h"
#include "../../matched/include/Obj05719.h"
#include "../../matched/include/Obj05720.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_020273C4(void *, unsigned);
extern u32 func_02027060(u32 a);
extern void func_02026FB8(void *);
extern void func_0202744C(void *);
extern void func_020273DC(void *, unsigned);
extern void func_020273F8(void *, unsigned);
extern void func_02027414(void *, unsigned);
extern void func_02027430(void *, unsigned);
void func_021650BC(void *a0, unsigned a1);
void func_021650CC(void *a0);
void func_021650F4(void *a0, unsigned a1);
void func_02165104(void *a0);
void func_0216512C(void *a0, unsigned a1);
void func_0216513C(void *a0);
void func_02165164(void *a0, unsigned a1);
void func_02165174(void *a0);
void func_0216519C(void *a0, unsigned a1);
void func_021651AC(void *a0);
void func_021651D4(void *a0, unsigned a1);
void func_021651E4(void *a0);
void func_0216520C(void *a0, unsigned a1);
void func_0216521C(void *a0);
void func_02165244(void *a0, unsigned a1);
void func_02165254(void *a0);
void func_0216527C(void *a0, unsigned a1);
extern char *g_02146940;


/*
 * blocked:   wild=4
 *
 * Stamp the fixed id halfword and the caller's value on the two
 * record fields, then jump to the shared submitter.
 */
void func_021650BC(void *a0, unsigned a1)
{
    ((struct Obj12050 *)a0)->f30 = 0x2;
    ((struct Obj12050 *)a0)->f32 = a1;
    func_020273C4(a0, a1);
}


/*
 * Test the id against the overlay's table and, when it takes,
 * re-submit the record at the shared globals pointer.
 */
void func_021650CC(void *a0)
{
    if (func_02027060(0x3)) {
        func_021650F4(g_02146940 + 4, (unsigned int)a0);
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
 *   python tools/match.py one --src src/matched/func_021650F4.c \
 *       --func func_021650F4 --addr 0x021650F4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_021650F4(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 3;
    ((struct Obj00121 *)a0)->f32 = a1;
    func_0202744C(a0);
}


void func_02165104(void *a0)
{
    if (func_02027060(0x4)) {
        func_0216512C(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}


void func_0216512C(void *a0, unsigned a1)
{
    ((struct Obj05717 *)a0)->f30 = 0x4;
    ((struct Obj05717 *)a0)->f32 = a1;
    func_020273DC(a0, a1);
}


void func_0216513C(void *a0)
{
    if (func_02027060(0x5)) {
        func_02165164(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}


void func_02165164(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 5;
    ((struct Obj00121 *)a0)->f32 = a1;
    func_0202744C(a0);
}


void func_02165174(void *a0)
{
    if (func_02027060(0x6)) {
        func_0216519C(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}


void func_0216519C(void *a0, unsigned a1)
{
    ((struct Obj05718 *)a0)->f30 = 0x6;
    ((struct Obj05718 *)a0)->f34 = a1;
    func_020273F8(a0, a1);
}


void func_021651AC(void *a0)
{
    if (func_02027060(0x7)) {
        func_021651D4(g_02146940 + 4, (unsigned int)a0);
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
 *   python tools/match.py one --src src/matched/func_021651D4.c \
 *       --func func_021651D4 --addr 0x021651D4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_021651D4(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 7;
    ((struct Obj00121 *)a0)->f34 = a1;
    func_0202744C(a0);
}


void func_021651E4(void *a0)
{
    if (func_02027060(0x8)) {
        func_0216520C(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}


void func_0216520C(void *a0, unsigned a1)
{
    ((struct Obj05719 *)a0)->f30 = 0x8;
    ((struct Obj05719 *)a0)->f34 = a1;
    func_02027414(a0, a1);
}


void func_0216521C(void *a0)
{
    if (func_02027060(0x9)) {
        func_02165244(g_02146940 + 4, (unsigned int)a0);
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
 *   python tools/match.py one --src src/matched/func_02165244.c \
 *       --func func_02165244 --addr 0x02165244 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_02165244(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 9;
    ((struct Obj00121 *)a0)->f34 = a1;
    func_0202744C(a0);
}


void func_02165254(void *a0)
{
    if (func_02027060(0xA)) {
        func_0216527C(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}


void func_0216527C(void *a0, unsigned a1)
{
    ((struct Obj05720 *)a0)->f30 = 0xA;
    ((struct Obj05720 *)a0)->f34 = a1;
    func_02027430(a0, a1);
}
