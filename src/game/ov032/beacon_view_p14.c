/*
 * file:     beacon_view_p14.c
 * unit:     yes
 * function: func_021F20E4, func_021F2144, func_021F21B0, func_021F21F8
 * address:  0x021F20E4
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02045770 0x02045770 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02031194 0x02031194 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_020257D0 0x020257D0 thumb
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../../matched/include/Obj06136.h"
#include "../../matched/include/Obj06137.h"
#include "../../matched/include/Obj20448.h"
#include "../../matched/include/Obj07635.h"
#include "../../matched/include/Obj07637.h"
#include "../../matched/include/Obj20452.h"
#include "../../matched/include/Obj20453.h"
#include "../../matched/include/Obj07638.h"
#include "../../matched/include/Obj20455.h"
#include "../../matched/include/Obj20458.h"

struct Cfg;
struct Descriptor;
struct PrintSys;
struct TcblNode;
struct CharBuf;
struct Obj;
struct S02030FB4;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed short   s16;

extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *a);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void func_02031194(struct TcblNode *n);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_020257D0(struct Obj *o);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern void *func_02031290(struct S02030FB4 *p);
extern void func_02082BCC(void *p, int v, int n);
void func_021F20E4(void *task, char *q);
void func_021F2144(char *p, char *q, void *text, u16 col, u32 a4);
void func_021F21B0(char *p, char *q, int *r);
void func_021F21F8(void *task, char *q);


void func_021F20E4(void *task, char *q)
{
    u8 *s;
    u32 v;
    int *r;

    v = ((struct Obj20448 *)(*(char * *)&((struct Obj06136 *)q)->f8))->fB4;
    s = *(u8 * *)&((struct Obj06136 *)q)->f4 + 8;
    if (s[4] != 0) {
        if (func_0201C6C4((struct PrintSys *)v, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj06137 *)s)->f0))) == 0) {
            func_02045334((struct Descriptor *)((struct Obj06137 *)s)->f0);
            s[4] = 0;
        }
    }
    if (s[4] == 0) {
        func_02045374((struct Cfg *)(**(u32 * *)&((struct Obj06136 *)q)->f4));
        func_02041B6C(func_02045730((struct Descriptor *)(**(u32 * *)&((struct Obj06136 *)q)->f4)));
        r = *(int * *)&((struct Obj06136 *)q)->fC;
        if (r != 0)
            (*r)--;
        func_02031194(task);
    }
}


void func_021F2144(char *p, char *q, void *text, u16 col, u32 a4)
{
    u32 *t;

    t = (u32 *)(q + 0x18);
    func_02043B5C((struct CharBuf *)t[1], 0);
    if (((struct Obj07635 *)p)->f7A != 0) {
        func_0201C7D0((void *)t[1], 0, 0, text, (void *)(((struct Obj07635 *)p)->fB0), col);
        func_020257D0((struct Obj *)t[0]);
        return;
    }
    func_0201C724((void *)(((struct Obj07635 *)p)->fB4), t[1], 0, 0, (u32)text, ((struct Obj07635 *)p)->fB0, col);
    func_021F21B0(p, q, (int *)a4);
}


void func_021F21B0(char *p, char *q, int *r)
{
    void *t;
    u8 *s;

    t = func_020311B8(((struct Obj20452 *)p)->fA0, (void *)func_021F21F8, 0x10, 0);
    s = func_02031290(t);
    func_02082BCC(s, 0, 0x10);
    *(char * *)&((struct Obj07637 *)s)->f8 = p;
    *(char * *)&((struct Obj07637 *)s)->f0 = q;
    *(char * *)&((struct Obj07637 *)s)->f4 = q + 0x18;
    ((struct Obj20453 *)q)->f2C = t;
    if (r != 0) {
        *(int * *)&((struct Obj07637 *)s)->fC = r;
        (*r)++;
    }
}

void func_021F21F8(void *task, char *q)
{
    int *r;
    if (func_0201C6C4((struct PrintSys *)(((struct Obj20455 *)(*(char * *)&((struct Obj07638 *)q)->f8))->fB4), (void *)((*(u32 **)(q + 4))[1])) == 0) {
        func_020257D0((struct Obj *)(**(u32 * *)&((struct Obj07638 *)q)->f4));
        r = *(int * *)&((struct Obj07638 *)q)->fC;
        if (r != 0)
            (*r)--;
        ((struct Obj20458 *)(*(char * *)&((struct Obj07638 *)q)->f0))->f2C = 0;
        func_02031194(task);
    }
}
