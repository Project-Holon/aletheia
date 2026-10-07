/*
 * file:     symbol_map_p07.c
 * unit:     yes
 * function: func_021670F8, func_0216711C, func_02167154, func_02167168, func_02167178, func_021671CC, func_021671DC
 * address:  0x021670F8
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
 *   func_02167080 0x02167080 thumb ov010
 *   func_02082BCC 0x02082BCC arm
 *   func_02188C84 0x02188C84 thumb ov021
 *   func_02188C54 0x02188C54 thumb ov021
 *   func_02045B38  0x02045B38  arm
 *   func_02045C04  0x02045C04  arm
 *   func_021672D0  0x021672D0  thumb  ov010
 *   func_02190708  0x02190708  thumb  ov021
 *   func_02190728  0x02190728  thumb
 *   func_0201EC64  0x0201EC64  thumb
 */
#include "../../matched/include/Obj05899.h"
#include "../../matched/include/Obj00565.h"

struct O;
struct Desc;
struct Obj;
struct Ctx;
struct MsgBank;
struct Fx;
struct WordSet;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

struct O {
    u16 pad0[8];
    int f10;
    int f14;
    int f18;
};

extern int func_02167080(void *a, int *st, struct O *o, int a3);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern void func_02082BCC(void *, int, int);
extern u16 func_02188C84(u8 *p);
extern u32 func_02188C54(u8 *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern int func_02045C04();
extern int func_021672D0(int a0);
extern void *func_02190708(struct Fx *p, u32 a, u16 b, u16 c, u16 d, u16 e);
extern int func_02190728();
extern struct WordSet *func_0201EC64(u32 heap);
void *func_021670F8(void *p);
void func_0216711C(u8 *p, void *sys);
struct MsgBank *func_02167154(int a0, int a1, int a2, int a3);
int func_02167168(int a0);
void func_02167178(struct O *o);
int func_021671CC(int a0);
struct WordSet *func_021671DC(int a0);

void *func_021670F8(void *p) {
    void *task;
    task = func_020122C0(p, 0, func_02167080, 32);
    func_0216711C(func_020124E8(task), p);
    return task;
}

/*
 * extent: two zero alignment bytes at 0x02167152 precede the next function.
 */
void func_0216711C(u8 *p, void *sys) {
    void *field;
    field = func_0201210C(sys);
    func_02082BCC(p, 0, 32);
    ((struct Obj05899 *)p)->f0 = func_02188C84(field);
    ((struct Obj05899 *)p)->f4 = sys;
    ((struct Obj05899 *)p)->f8 = func_020120F4(sys);
    ((struct Obj05899 *)p)->fC = field;
    ((struct Obj05899 *)p)->f10 = func_02188C54(field);
}


struct MsgBank *func_02167154(int a0, int a1, int a2, int a3)
{
    int t4;
    struct MsgBank *bank;

t4 = a0 + 0;
a3 = ((struct Obj00565 *)((char *)t4))->f0;
a0 = 0;
a1 = 3;
a2 = 0x2f;
    bank = func_02045B38(a0, a1, a2, a3);
loc_02167164:
*(struct MsgBank * *)&((struct Obj00565 *)t4)->f18 = bank;
    return bank;}


int func_02167168(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)&((struct Obj00565 *)t4)->f18;
    a0 = func_02045C04(a0);
loc_02167172:
a0 = 0;
*(int *)&((struct Obj00565 *)t4)->f18 = a0;
    return a0;}


void func_02167178(struct O *o)
{
    int a;
    int b;
    int c;
    switch (func_021672D0((int)o)) {
    case 0:
        a = 1;
        b = 0x1e;
        c = 4;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        a = 1;
        b = 0x1e;
        c = 8;
        break;
    }
    o->f14 = (int)func_02190708((struct Fx *)o->f10, o->f18, a, a, b, c);
}


int func_021671CC(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj00565 *)t4)->f14;
    a0 = func_02190728(a0);
loc_021671D6:
a0 = 0;
((struct Obj00565 *)t4)->f14 = a0;
    return a0;}


struct WordSet *func_021671DC(int a0)
{
    int t4;
    struct WordSet *ws;

t4 = a0 + 0;
a0 = ((struct Obj00565 *)((char *)t4))->f0;
    ws = func_0201EC64(a0);
loc_021671E6:
*(struct WordSet * *)&((struct Obj00565 *)t4)->f1C = ws;
    return ws;}
