/*
 * file:     game_beacon_search_p02.c
 * unit:     yes
 * function: func_02164F9C, func_02164FC4, func_02164FD0, func_0216505C, func_02165078, func_02165094, func_021650BC, func_021650CC, func_021650F4, func_02165104, func_0216512C, func_0216513C, func_02165164, func_02165174, func_0216519C, func_021651AC, func_021651D4, func_021651E4, func_0216520C, func_0216521C, func_02165244, func_02165254, func_0216527C, func_0216528C, func_021652B4, func_021652C4, func_021652EC, func_0216530C, func_02165334, func_02165344, func_02165368, func_02165374, func_021653B4, func_021653C4, func_021653E8, func_021653F4, func_02165418, func_02165424, func_0216544C, func_02165468, func_02165490, func_021654AC, func_021654D4, func_021654F0, func_02165518, func_02165534, func_0216555C, func_0216556C, func_02165590, func_0216559C, func_021655C4, func_021655D4, func_021655F8, func_02165604, func_02165628, func_02165634, func_0216565C, func_0216566C, func_02165690, func_021656A0, func_021656C4, func_021656D0
 * address:  0x02164F9C
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
 *   func_02082D44  0x02082D44  arm
 *   func_02012138  0x02012138  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02012164  0x02012164  thumb
 *   func_020264AC  0x020264AC  thumb
 *   func_0203CD98  0x0203CD98  arm
 *   func_02026454  0x02026454  thumb
 *   func_02030734  0x02030734  arm
 *   func_020263D8  0x020263D8  thumb
 *   d_021729BC     0x021729BC  data  ov010  a1
 *   func_0202708C  0x0202708C  thumb
 *   func_02027060   0x02027060  thumb
 *   func_02026FB8   0x02026FB8  thumb
 *   g_02146940      0x02146940  data
 *   func_020273C4   0x020273C4  thumb
 *   func_0202744C  0x0202744C  thumb
 *   func_020273DC   0x020273DC  thumb
 *   func_020273F8   0x020273F8  thumb
 *   func_02027414   0x02027414  thumb
 *   func_02027430   0x02027430  thumb
 *   d_02171CA0      0x02171CA0  data  ov010  a1
 *   func_020270AC  0x020270AC  thumb
 *   func_021656F8   0x021656F8  thumb  ov010
 */
#include "../../matched/include/Obj18988.h"
#include "../../matched/include/Obj12364.h"
#include "../../matched/include/Obj18989.h"
#include "../../matched/include/Obj12050.h"
#include "../../matched/include/Obj00121.h"
#include "../../matched/include/Obj05717.h"
#include "../../matched/include/Obj05718.h"
#include "../../matched/include/Obj05719.h"
#include "../../matched/include/Obj05720.h"

struct Ctx;
struct Comm;
struct IcaAnime;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Ent {
    u8 b0;
    u8 lo : 4;
    u8 hi : 4;
    u8 flag : 1;
    u8 kind : 5;
    u8 rest : 2;
} Ent;

typedef struct Obj { u8 pad[3]; u8 lo:7; u8 hi:1; u8 gap[0x2c]; u16 event; } Obj;

extern void  func_02082D44(void *src, void *dst, int n);
extern u32   func_02012138(const struct Ctx *p);
extern u32 func_020307B0(void *p);
extern u32 func_02012164(struct IcaAnime *p);
extern u32 func_020264AC(void *obj);
extern int   func_0203CD98(void);
extern u32 func_02026454(void *obj);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020263D8(struct Comm *p, u32 a1, u32 a2);
extern int func_0202708C();
extern u32 func_02027060(u32 a);
extern void func_02026FB8(void *);
extern void func_020273C4(void *, unsigned);
extern int func_0202744C(void *);
extern void func_020273DC(void *, unsigned);
extern void func_020273F8(void *, unsigned);
extern void func_02027414(void *, unsigned);
extern void func_02027430(void *, unsigned);
extern int func_020270AC();
extern void func_021656F8(void *, void *);
Ent *func_02164F9C(Ent *p,Ent *q);
void func_02164FC4(char *p);
void func_02164FD0(u8 *obj, int flag);
int func_0216505C(int a0);
int func_02165078(int a0);
int func_02165094(void *a0);
void func_021650BC(void *a0, unsigned a1);
int func_021650CC(void *a0);
void func_021650F4(void *a0, unsigned a1);
int func_02165104(void *a0);
void func_0216512C(void *a0, unsigned a1);
int func_0216513C(void *a0);
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
void func_0216528C(void *a0);
void func_021652B4(void *a0, unsigned a1);
void func_021652C4(void *a0);
void func_021652EC(Obj *p,u32 v);
void func_0216530C(void *a0);
void func_02165334(void *a0, unsigned a1);
void func_02165344(void);
void func_02165368(void *a0);
void func_02165374(unsigned a0);
void func_021653B4(void *a0, unsigned a1);
void func_021653C4(void);
void func_021653E8(void *a0);
void func_021653F4(u16 species);
void func_02165418(void *a0);
void func_02165424(void *a0);
int func_0216544C(int a0, int a1);
void func_02165468(void *a0);
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
void func_02165690(void *a0);
void func_021656A0(void);
void func_021656C4(void *a0);
void func_021656D0(void *a0);
extern const char d_021729BC[];
extern char *g_02146940;
extern u8 d_02171CA0[5];





Ent *func_02164F9C(Ent *p,Ent *q) { if(p->flag) return q; if(p->lo>=p->hi || p->lo<q->lo) return q; return p; }







void func_02164FC4(char *p)
{
    ((struct Obj18988 *)p)->fC = 0x708;
}







/*
 * Copies a 6-byte record out of the object, and when no flag / busy
 * checks trip allocates a 0x10-byte record holding it and registers it.
 *
 * Addresses are Black-image addresses.
 */
void func_02164FD0(u8 *obj, int flag)
{
    u8 buf[6];
    u32 o = ((struct Obj18989 *)obj)->f0;
    u32 w;
    u8 *p;
    func_02082D44(obj + 4, buf, 6);
    w = func_02012138((const struct Ctx *)o);
    func_020307B0(obj);
    if (flag == 0 && func_02012164((struct IcaAnime *)o) == 1 && func_020264AC((void *)w) == 0
        && func_0203CD98() == 0 && func_02026454((void *)w) == 0) {
        p = func_02030734(5, 0x10, 1, d_021729BC, 0x287);
        ((struct Obj12364 *)p)->f0 = o;
        ((struct Obj12364 *)p)->f4 = func_02012138((const struct Ctx *)o);
        func_02082D44(buf, p + 8, 6);
        func_020263D8((struct Comm *)w, 2, (u32)p);
    }
}





int func_0216505C(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0202708C(a0);
loc_02165064:
    if (a0 == 0) goto loc_02165070;
loc_02165068:
a0 = t4 + 0;
    a0 = func_02165104((void *)a0);
loc_0216506E:
    return a0;
loc_02165070:
a0 = t4 + 0;
    a0 = func_02165094((void *)a0);
loc_02165076:
    return a0;}





int func_02165078(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0202708C(a0);
loc_02165080:
    if (a0 == 0) goto loc_0216508C;
loc_02165084:
a0 = t4 + 0;
    a0 = func_0216513C((void *)a0);
loc_0216508A:
    return a0;
loc_0216508C:
a0 = t4 + 0;
    a0 = func_021650CC((void *)a0);
loc_02165092:
    return a0;}





/*
 * Test the id against the overlay's table and, when it takes,
 * re-submit the record at the shared globals pointer.
 */
int func_02165094(void *a0){
    if (func_02027060(0x2)) {
        func_021650BC(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}







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







int func_021650CC(void *a0){
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







int func_02165104(void *a0){
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







int func_0216513C(void *a0){
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





void func_021653F4(u16 species)
{
    if (func_02027060(0x1E)) {
        func_02165418(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}





void func_02165418(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 0x1E;
    func_0202744C(a0);
}





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
    a0 = func_0202744C((void *)a0);
loc_02165464:
    return a0;}





void func_02165468(void *a0)
{
    if (func_02027060(0x20)) {
        func_02165490((int)(g_02146940 + 4), (int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}





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
    a0 = func_0202744C((void *)a0);
loc_021654A8:
    return a0;}





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
    a0 = func_0202744C((void *)a0);
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
    a0 = func_0202744C((void *)a0);
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





void func_0216556C(void)
{
    if (func_02027060(0x25)) {
        func_02165590(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}





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




void func_021656A0(void)
{
    if (func_02027060(0x2B)) {
        func_021656C4(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}




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
