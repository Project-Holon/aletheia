/*
 * file:     wf2dmap_objdraw_p01.c
 * unit:     yes
 * function: func_021C5564, func_021C5590, func_021C5608, func_021C5658, func_021C5664, func_021C5680, func_021C5704, func_021C571C, func_021C574C, func_021C57D8, func_021C57DC, func_021C57E8, func_021C57F4
 * address:  0x021C5564
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C4AC4 0x021C4AC4 thumb ov127
 *   func_02030734 0x02030734 arm
 *   func_021C3EE0 0x021C3EE0 thumb ov127
 *   func_021C3FDC 0x021C3FDC thumb ov127
 *   func_021C40A0 0x021C40A0 thumb ov127
 *   d_021C6130 0x021C6130 data a1
 *   func_021C58B8 0x021C58B8 thumb ov127
 *   func_021C40B4 0x021C40B4 thumb ov127
 *   func_021C3F80 0x021C3F80 thumb ov127
 *   func_020307B0 0x020307B0 arm
 *   func_021C4010 0x021C4010 thumb ov127
 *   func_021C4044  0x021C4044  thumb
 *   func_021C58C8 0x021C58C8 thumb ov127
 *   func_021C49A4 0x021C49A4 thumb ov127
 *   func_021C5878 0x021C5878 thumb ov127
 *   func_021C40BC 0x021C40BC thumb ov127
 *   func_021C41BC  0x021C41BC  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_021C58F8 0x021C58F8 thumb ov127
 *   func_021C5944 0x021C5944 thumb ov127
 *   func_021C5914 0x021C5914 thumb ov127
 *   func_021C41DC 0x021C41DC thumb ov127
 *   func_021C4214 0x021C4214 thumb ov127
 *   func_021C42C4 0x021C42C4 thumb ov127
 */
#include "../../matched/include/Obj10476.h"
#include "../../matched/include/Obj05374.h"
#include "../../matched/include/Obj23044.h"
#include "../../matched/include/Obj02184.h"
#include "../../matched/include/Obj00328.h"
#include "../../matched/include/Obj14031.h"
#include "../../matched/include/Obj23045.h"
#include "../../matched/include/Obj10477.h"
#include "../../matched/include/Obj23047.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { u16 x,y; } Pos;

typedef unsigned int u32;

typedef struct { void *f0; void *f4; u16 count; u8 a,b; } Obj;

typedef signed short s16;

typedef signed int     s32;

extern Pos func_021C4AC4(void *);
extern void *func_02030734(u16, u32, int, const char *, u16);
extern void *func_021C3EE0(void *, void *, u32, u32);
extern void func_021C3FDC(u8 *p, int a, int b, int c, int d);
extern void func_021C40A0(u8 *p, int a, int b, int c);
extern int func_021C58B8(char *p);
extern void func_021C40B4(u8 *p);
extern void func_021C3F80(u8 *p);
extern u32 func_020307B0(void *p);
extern void func_021C4010(u8 *p);
extern void func_021C4044(u8 *p, int a, int b, int c, int d);
extern u8 *func_021C58C8(void *);
extern int func_021C49A4(u8 *p, unsigned int i);
extern int func_021C5878(int, int);
extern void *func_021C40BC(void *, s16 *, int, u32);
extern void func_021C41BC(u8 *p);
extern void func_02082BCC(void *, int, int);
extern int func_021C58F8(char *p, int b);
extern void func_021C5944(u8 *p, int n, int a);
extern void func_021C5914(char *p, short *x, short *y);
extern void func_021C41DC(u8 *p, int x, int y);
extern void func_021C4214(u8 *p, u32 v);
extern void func_021C42C4(u8 *p);
void func_021C5564(u8 *out,void *p,int kind,int index,int value);
Obj *func_021C5590(void *p, void *q, u32 n, void *r, int s, u32 b, u32 heap);
void func_021C5608(u8 *p);
void func_021C5658(void *p);
void func_021C5664(char *p, int a, int b);
u8 *func_021C5680(u8 *p, void *q, int n, u32 heap);
void func_021C5704(u8 *p);
void func_021C571C(u8 *p);
void func_021C574C(u8 *p);
void func_021C57D8(u8 *p, int v);
void func_021C57DC(u8 *p);
void func_021C57E8(char *p);
void func_021C57F4(u8 *p);
extern const char d_021C6130[];

void func_021C5564(u8 *out,void *p,int kind,int index,int value) { *(Pos *)out=func_021C4AC4(p); ((struct Obj10476 *)out)->f4=kind; out[7]=index; out[6]=value; }

Obj *func_021C5590(void *p, void *q, u32 n, void *r, int s, u32 b, u32 heap)
{
    Obj *o = func_02030734(heap, 12, 1, d_021C6130, 161);
    o->f0 = func_021C3EE0(p, q, n, heap);
    o->count = n;
    o->f4 = func_02030734(heap, 20 * o->count, 1, d_021C6130, 168);
    o->a = 2;
    o->b = b;
    func_021C3FDC(o->f0, (int)r, o->b, s, heap);
    func_021C40A0(o->f0, o->b, 255, heap);
    return o;
}

/*
 * extent: two zero alignment bytes at 021C5656 follow the return.
 */
void func_021C5608(u8 *p)
{
    int i;
    for (i = 0; i < ((struct Obj05374 *)p)->f8; i++) {
        int offset = i * 20;
        if (!func_021C58B8((char *)(*(u8 * *)&((struct Obj05374 *)p)->f4+offset)))
            func_021C5704(*(u8 * *)&((struct Obj05374 *)p)->f4+offset);
    }
    func_021C40B4(((struct Obj05374 *)p)->f0);
    func_021C5658(p);
    func_021C3F80(((struct Obj05374 *)p)->f0);
    func_020307B0(((struct Obj05374 *)p)->f4);
    func_020307B0(p);
}

void func_021C5658(void *p) { func_021C4010(((struct Obj23044 *)p)->f0); }


/*
 * Addresses are Black-image addresses.
 */
void func_021C5664(char *p, int a, int b)
{
    func_021C4044(((struct Obj02184 *)p)->f0, ((struct Obj02184 *)p)->fB, a, 0, b);
}

u8 *func_021C5680(u8 *p, void *q, int n, u32 heap)
{
    u8 *o = func_021C58C8(p);
    s16 pos[4];
    ((struct Obj00328 *)o)->f8 = func_021C49A4(q, 5);
    ((struct Obj00328 *)o)->fA = func_021C49A4(q, 6);
    ((struct Obj00328 *)o)->fC = func_021C49A4(q, 4);
    ((struct Obj00328 *)o)->f0 = q;
    o[18] = n;
    o[19] = 1;
    ((struct Obj00328 *)o)->fE = 0;
    ((struct Obj00328 *)o)->f10 = 0;
    pos[0] = func_021C49A4(q, 0);
    pos[1] = func_021C49A4(q, 1);
    pos[2] = func_021C5878(pos[1], o[18]);
    pos[3] = p[10];
    ((struct Obj00328 *)o)->f4 = func_021C40BC(((struct Obj14031 *)p)->f0, pos, func_021C49A4(q, 7), heap);
    func_021C574C(o);
    return o;
}


void func_021C5704(u8 *p)
{
    func_021C41BC(((struct Obj23045 *)p)->f4);
    func_02082BCC(p, 0, 0x14);
}

void func_021C571C(u8 *p) { int i,offset; for(i=0;i<((struct Obj10477 *)p)->f8;i++) { offset=i*20; if(func_021C58B8(*(char * *)&((struct Obj10477 *)p)->f4+offset)==0) func_021C574C(*(u8 * *)&((struct Obj10477 *)p)->f4+offset); } }

void func_021C574C(u8 *p)
{
    if (p[19]) {
        int a = func_021C49A4(((struct Obj00328 *)p)->f0, 5);
        int b = func_021C49A4(((struct Obj00328 *)p)->f0, 6);
        s16 c = func_021C49A4(((struct Obj00328 *)p)->f0, 8);
        s16 x, y;
        u16 d;
        if (((struct Obj00328 *)p)->f8 != a || ((struct Obj00328 *)p)->fA != b || c == 0) {
            ((struct Obj00328 *)p)->f8 = a;
            ((struct Obj00328 *)p)->fA = b;
            func_021C5944(p, func_021C58F8(((struct Obj00328 *)p)->f4, a), b);
        }
        func_021C5914((char *)p, &x, &y);
        func_021C41DC(((struct Obj00328 *)p)->f4, x, y);
        d = func_021C5878(y, p[18]);
        func_021C4214(((struct Obj00328 *)p)->f4, d);
        func_021C42C4(((struct Obj00328 *)p)->f4);
    }
}


/*
 * Blocker of ov099 func_021B99F4 / func_021B9A70.
 */
void func_021C57D8(u8 *p, int v)
{
    p[0x13] = v;
}


/*
 * Tail-call forwarder: (p) -> func_021C5944(p, 1, p->u16 at +0xA).
 * Blocker of ov099 func_021B99F4 / func_021B9A70.
 */
void func_021C57DC(u8 *p)
{
    func_021C5944(p, 1, ((struct Obj00328 *)p)->fA);
}


/*
 * Unlabelled tail-call stub: ldr r0,[r0,#4]; ldr r3,=func_021C42C4; bx r3.
 * Blocker of ov099 func_021BA2D4.
 */
void func_021C57E8(char *p)
{
    func_021C42C4(((struct Obj23047 *)p)->f4);
}

void func_021C57F4(u8 *p) { func_021C5944(p,func_021C58F8(*(char * *)&((struct Obj00328 *)p)->f4,((struct Obj00328 *)p)->f8),((struct Obj00328 *)p)->fA); func_021C574C(p); }
