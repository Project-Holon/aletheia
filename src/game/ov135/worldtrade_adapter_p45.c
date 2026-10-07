/*
 * file:     worldtrade_adapter_p45.c
 * unit:     yes
 * function: func_02202744, func_02202770
 * address:  0x02202744
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj07257.h"

struct PrintSys;
struct S02031140;
struct Ctx;
struct Descriptor;
struct Rec;
struct Rec3;
struct Tcbl;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef signed short s16;

typedef signed char s8;

typedef struct {
    void *win;
    u8 busy;
    void *active;
} Ent;

typedef struct {
    u8 pad0[4];
    void *heap;
    u8 pad8[0xC - 8];
    void *queue;
    void *yesno;
    void *yesnoArg;
    Ent ent[24];
    void *bg;
} Printer;

extern int func_02028604(int a0);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern void func_02031140(struct S02031140 *p);
extern void func_02082BCC(u32 p, u32 v, u32 n);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern u32 func_0201CE30(void *p);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_020061E4(u32 se);
extern void func_0201CE38(void *menu);
extern void func_0201CE48(struct Rec3 *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_020310C4(struct Tcbl *p);
void func_02202744(u8 *p);
void func_02202770(Printer *p);


/*
 * Free every buffer the object owns and blank the 0x13c-byte tail.
 */
void func_02202744(u8 *p)
{
    func_02028604(((struct Obj07257 *)p)->f138);
    func_0201C4C0((struct PrintSys *)(((struct Obj07257 *)p)->fC));
    func_0201D83C((void *)(((struct Obj07257 *)p)->f0));
    func_02031140((struct S02031140 *)(((struct Obj07257 *)p)->f4));
    func_02082BCC((u32)p, 0, 0x13c);
}


void func_02202770(Printer *p)
{
    int i;
    Ent *e;
    void *queue;

    for (i = 0; i < 24; i++) {
        e = &p->ent[i];
        if (e->active != 0) {
            queue = p->queue;
            if (e->busy != 0 && func_0201C6C4(queue, func_02045770(e->win)) == 0) {
                func_02045334(e->win);
                e->busy = 0;
            }
            if (e->busy == 0) {
                e->active = 0;
            }
        }
    }
    if (p->yesno != 0) {
        func_020286C4(p->bg, p->yesno, p->yesnoArg);
        switch (func_0201CE30(p->yesno)) {
        case 0:
            if ((func_020362DC() & 3) || func_02035C60() != 0) {
                func_0201CE5C(p->yesno, 0);
            }
            break;
        case 1:
            if ((func_020362DC() & 3) || func_02035C60() != 0) {
                func_020061E4(0x547);
                func_0201CE38(p->yesno);
            }
            break;
        case 2:
            func_0201CE48(p->yesno);
            p->yesno = 0;
            p->yesnoArg = 0;
            break;
        }
    }
    func_0201C4E4(p->queue);
    func_020310C4(p->heap);
}
