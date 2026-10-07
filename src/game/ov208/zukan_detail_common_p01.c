/*
 * file:     zukan_detail_common_p01.c
 * unit:     yes
 * function: func_021BC240, func_021BC26C, func_021BC274, func_021BC2F0, func_021BC310, func_021BC32C, func_021BC34C, func_021BC35C, func_021BC39C, func_021BC3A4, func_021BC3A8, func_021BC3AC, func_021BC3B0
 * address:  0x021BC240
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021C8D80 0x021C8D80 data a1
 *   func_020307B0 0x020307B0  arm
 *   d_021C8D98     0x021C8D98  data  ov208  a4
 */
#include "../../matched/include/Obj09194.h"
#include "../../matched/include/Obj09195.h"
#include "../../matched/include/Obj18177.h"
#include "../../matched/include/Obj12110.h"
#include "../../matched/include/Obj03064.h"

struct State;
typedef unsigned short u16;

typedef unsigned int u32;

struct Ov208Obj { void *owner; int f4; int f8; int fc; int f10; };

typedef int (*Callback)(struct State *,int *,int,int,int);

struct State { Callback *callbacks; int state,counter,a,b; };

typedef void (*Vfn)(char *self, char *a, int b, int c, int d);

struct Ov208Buf { int f0; int f4; int f8; int fc; void *buf; };

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
struct Ov208Obj *func_021BC240(void *owner, int val, u32 heap);
void func_021BC26C(void *p);
int func_021BC274(struct State *p,int arg);
void func_021BC2F0(char *p, int a, int b);
void func_021BC310(char *p, int v);
void *func_021BC32C(struct Ov208Buf *p, u32 size, u32 heap);
void func_021BC34C(char *p);
void func_021BC35C(int a, int b, int c, int d, int e, int f, int g, int h, unsigned short i, int j);
void func_021BC39C(void *a0);
int func_021BC3A4(int *p);
int func_021BC3A8(int *p);
int func_021BC3AC(int *p);
int func_021BC3B0(int *p);
extern const char d_021C8D80[];
extern int d_021C8D98;

struct Ov208Obj *func_021BC240(void *owner, int val, u32 heap)
{
    struct Ov208Obj *p = func_02030734(heap, 20, 0, d_021C8D80, 0x4f);
    p->owner = owner;
    p->f4 = 0;
    p->f8 = 0;
    p->fc = val;
    p->f10 = 0;
    return p;
}


void func_021BC26C(void *p)
{
    func_020307B0(p);
}

int func_021BC274(struct State *p,int arg)
{
    int result=1;
    switch(p->state) {
    case 0:
        if(p->callbacks[0]) result=p->callbacks[0](p,&p->counter,p->a,p->b,arg);
        if(result==1) { p->state=1; p->counter=0; }
        break;
    case 1:
        if(p->callbacks[1]) result=p->callbacks[1](p,&p->counter,p->a,p->b,arg);
        if(result==1) { p->state=2; p->counter=0; }
        break;
    case 2:
        if(p->callbacks[2]) result=p->callbacks[2](p,&p->counter,p->a,p->b,arg);
        if(result==1) return 1;
        break;
    }
    return 0;
}



/*
 * Virtual call through the field at +0 of the object at +0, passing the object and three of its fields plus the two arguments.
 */
void func_021BC2F0(char *p, int a, int b)
{
    void (*fn)(char *, char *, int, int, int, int);

    fn = *(void (**)(char *, char *, int, int, int, int))(((struct Obj09194 *)p)->f0 + 0xc);
    if (fn != 0)
        fn(p, p + 8, ((struct Obj09194 *)p)->fC, ((struct Obj09194 *)p)->f10, a, b);
}


void func_021BC310(char *p, int v)
{
    Vfn fn = *(Vfn *)&((struct Obj18177 *)(*(char * *)&((struct Obj09195 *)p)->f0))->f10;

    if (fn != 0)
        fn(p, p + 8, ((struct Obj09195 *)p)->fC, ((struct Obj09195 *)p)->f10, v);
}

void *func_021BC32C(struct Ov208Buf *p, u32 size, u32 heap)
{
    p->buf = func_02030734(heap, size, 0, d_021C8D80, 0xc8);
    return p->buf;
}


void func_021BC34C(char *p)
{
    func_020307B0((void *)(((struct Obj12110 *)p)->f10));
    ((struct Obj12110 *)p)->f10 = 0;
}


void func_021BC35C(int a, int b, int c, int d, int e, int f, int g, int h,
                   unsigned short i, int j)
{
    int *p = (int *)func_02030734(a, 0x24, 1, (const char *)&d_021C8D98, 0x60);

    p[0] = b;
    p[1] = c;
    p[2] = d;
    p[3] = e;
    p[4] = f;
    p[5] = g;
    p[6] = h;
    ((struct Obj03064 *)p)->f1C = i;
    p[8] = j;
}


/*
 * Tail call to the ARM9 function at 0x020307B0: loads the pointer from the pool and branches through it.
 */
void func_021BC39C(void *a0)
{
    func_020307B0(a0);
}

/*
 * Returns the word at +0 of the object.
 */
int func_021BC3A4(int *p)
{
    return p[0];
}

/*
 * Returns the word at +4.
 */
int func_021BC3A8(int *p)
{
    return p[1];
}

int func_021BC3AC(int *p)
{
    return p[2];
}

int func_021BC3B0(int *p)
{
    return p[3];
}
