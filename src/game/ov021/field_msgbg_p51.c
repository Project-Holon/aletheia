/*
 * file:     field_msgbg_p51.c
 * unit:     yes
 * function: func_02190344, func_02190378, func_02190398, func_021903CC, func_021903E0, func_0219047C, func_02190490
 * address:  0x02190344
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02194798  0x02194798  thumb
 *   func_02192E0C  0x02192E0C  thumb  ov021
 *   func_020056A0  0x020056A0  thumb
 *   func_02192EB8  0x02192EB8  thumb  ov021
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_021919C8  0x021919C8  thumb  ov021
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_020310C4  0x020310C4  arm
 *   func_0219470C  0x0219470C  thumb  ov021
 *   func_02194760  0x02194760  thumb  ov021
 *   func_02194764  0x02194764  thumb  ov021
 *   func_0201C6EC  0x0201C6EC  thumb
 */
#include "../../matched/include/Obj04205.h"
#include "../../matched/include/Obj09473.h"
#include "../../matched/include/Obj19582.h"
#include "../../matched/include/Obj19583.h"
#include "../../matched/include/Obj17921.h"

struct PrintSys;
struct Q;
struct Tcbl;
struct Descriptor;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16_02190344;

typedef signed int     s32;

typedef signed short   s16_02190378;

typedef struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot;

typedef struct Obj {
    u32  f00;
    u32  f04;
    u32  f08;
    u32  f0c;
    Slot slot[4];
    u32  f0a0[8];
} Obj;

typedef short          s16_0219047C;

extern void func_02194798(unsigned char *a);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);
extern void func_02192E0C(u32 *p);
extern u32 func_020056A0(void *fn, void *arg, int z);
extern void func_02192EB8(u32 a, u8 *b);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern int func_021919C8(struct Q *q);
extern void *func_02045770(struct Descriptor *a);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *a);
extern void func_020310C4(struct Tcbl *p);
extern void func_0219470C(unsigned char *a);
extern void func_02194760(u32 a);
extern void func_02194764(void *p);
extern void func_0201C6EC(struct PrintSys *p);
void func_02190344(u8 *a);
int func_02190378(u8 *a);
void func_02190398(u32 *p);
int func_021903CC(u8 *p);
void func_021903E0(Obj *o);
void func_0219047C(u8 *p);
void func_02190490(u8 *p);


void func_02190344(u8 *a)
{
    if (((struct Obj04205 *)a)->f15C != 0) {
        func_02194798(((struct Obj04205 *)a)->f15C);
        ((struct Obj04205 *)a)->f15C = 0;
    }
    if (((struct Obj04205 *)a)->f2 != 0xff) {
        func_02040DA8(((struct Obj04205 *)a)->f2, 1, 0);
        func_020403F4((u8)(((struct Obj04205 *)a)->f2));
        ((struct Obj04205 *)a)->f2 = 0xff;
    }
}


int func_02190378(u8 *a)
{
    if (((struct Obj09473 *)a)->f4 != 0xff) {
        func_020403F4((u8)(((struct Obj09473 *)a)->f4));
        ((struct Obj09473 *)a)->f4 = 0xff;
        return 1;
    }
    return 0;
}


/*
 * Addresses are Black-image addresses.
 */
void func_02190398(u32 *p)
{
    if (p[0x57] != 0) {
        func_02194798((unsigned char *)p[0x57]);
    }
    func_02192E0C(p);
    if (p[0x5b] == 0) {
        p[0x5b] = func_020056A0((void *)func_02192EB8, p, 0);
    }
}


/*
 * Unlabelled leaf predicate, called from func_021BEF8C.
 */
int func_021903CC(u8 *p)
{
    if (((struct Obj19582 *)p)->f16C == 0)
        return 1;
    return 0;
}


void func_021903E0(Obj *o)
{
    int i;
    u32 *w;
    Slot *s;
    int j;
    u32 t;

    func_0201C4E4((struct PrintSys *)o->f0c);
    i = 0;
    w = o->f0a0;
    for (; i < 8; i++, w++) {
        if (*w != 0) {
            func_021919C8((struct Q *)(*w));
        }
    }
    s = o->slot;
    for (j = 0; j < 4; j++, s++) {
        t = s->f0c;
        if (t != 0) {
            if (s->f20 != 0) {
                if (func_0201C6C4((struct PrintSys *)t, (void *)((u32)func_02045770((struct Descriptor *)s->f1c))) == 0) {
                    func_02045334((struct Descriptor *)s->f1c);
                    s->f20 = 0;
                }
            }
            s->f04 = (s->f20 == 0) ? 1 : 0;
        }
    }
    func_020310C4((struct Tcbl *)(((u32 *)o)[0x59]));
    if (((u32 *)o)[0x57] != 0) {
        func_0219470C((unsigned char *)(((u32 *)o)[0x57]));
        func_02194760(((u32 *)o)[0x57]);
    }
}


void func_0219047C(u8 *p)
{
    void *q = ((struct Obj19583 *)p)->f15C;
    if (q != 0)
        func_02194764(q);
}


/*
 * Tail-call thunk: the object's word at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_02190490(u8 *p)
{
    func_0201C6EC((struct PrintSys *)(((struct Obj17921 *)p)->fC));
}
