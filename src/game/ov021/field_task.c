/*
 * file:     field_task.c
 * unit:     yes
 * function: func_021C6C70, func_021C6CA8, func_021C6CBC, func_021C6CC4, func_021C6CCC, func_021C6CD0, func_021C6CE0, func_021C6CE4, func_021C6CEC, func_021C6CF4, func_021C6D10, func_021C6D5C, func_021C6D90, func_021C6DE0, func_021C6E20
 * address:  0x021C6C70
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
 *   d_021DE4D4  0x021DE4D4  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   d_021DE4E4     0x021DE4E4  data  ov021  a4
 *   func_021C6E74  0x021C6E74  thumb  ov021
 *   func_021C6E94  0x021C6E94  thumb  ov021
 *   func_021C6EA8  0x021C6EA8  thumb  ov021
 *   func_021C6EDC  0x021C6EDC  thumb  ov021
 *   func_021C6E5C  0x021C6E5C  thumb  ov021
 */
#include "../../matched/include/Obj18314.h"
#include "../../matched/include/Obj18315.h"
#include "../../matched/include/Obj18316.h"
#include "../../matched/include/Obj18318.h"
#include "../../matched/include/Obj09696.h"
#include "../../matched/include/Obj12957.h"

struct Node;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u16 fC;
    u16 fE;
    u16 f10[8];
    u8 f20;
} D;

typedef struct Q {
    u32 state;
    u32 *arg;
    int (*check)(u32 *);
} Q;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u8 n; u8 pad[3]; void *f4; void *f8; } R_021C6D5C;


typedef struct { u8 n; u8 pad[3]; Q **f4; u32 *f8; } R_021C6E20;

extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021C6E74(R_021C6D5C *r, u8 i);
extern void func_021C6E94(u8 *p, u8 i);
extern void func_021C6EA8(u8 *p, u8 i);
extern void func_021C6EDC(u8 *p, u8 i);
extern void func_021C6E5C(u8 *p, u8 i, u32 a, u32 b);
Q *func_021C6C70(u32 heap, u32 size, int (*check)(u32 *));
void func_021C6CA8(Q *q);
void func_021C6CBC(Q *q);
void func_021C6CC4(u32 *a0);
u32 func_021C6CCC(u8 *p);
int func_021C6CD0(u32 a);
u32 func_021C6CE0(u8 *p);
void func_021C6CE4(u32 *p);
int func_021C6CEC(u32 a);
void func_021C6CF4(Q *q);
u8 *func_021C6D10(int n, int heap);
void func_021C6D5C(R_021C6D5C *r);
void func_021C6D90(u8 *p);
void func_021C6DE0(u8 *p, u32 *a, u32 b);
u8 func_021C6E20(R_021C6E20 *r);
extern char d_021DE4D4[];
extern int d_021DE4E4;



Q *func_021C6C70(u32 heap, u32 size, int (*check)(u32 *))
{
    Q *q = func_02030734(heap, 0xc, 0, d_021DE4D4, 0x3b);
    q->state = 0;
    q->arg = func_02030734(heap, size, 1, d_021DE4D4, 0x3d);
    q->check = check;
    return q;
}



void func_021C6CA8(Q *q)
{
    func_020307B0(q->arg);
    func_020307B0(q);
}




/*
 * Tail-call thunk: forwards to func_021C6CF4 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021C6CBC(Q *q)
{
    func_021C6CF4(q);
}




/*
 * Tail-call thunk: forwards to func_021C6CE4 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021C6CC4(u32 *a0)
{
    func_021C6CE4(a0);
}




/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
u32 func_021C6CCC(u8 *p)
{
    return ((struct Obj18314 *)p)->f4;
}




/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C6CD0(u32 a)
{
if (((struct Obj18315 *)((u8 *)(a)))->f0 == 2) {
    return 1;
}
return 0;
}




/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C6CE0(u8 *p)
{
    return ((struct Obj18316 *)p)->f0;
}






/*
 * Unlabelled leaf setter; callee of the thunk at 0x021C6CC4.
 *
 * Addresses are Black-image addresses.
 */
void func_021C6CE4(u32 *p)
{
    *p = 1;
}




int func_021C6CEC(u32 a)
{
((struct Obj18318 *)((u8 *)(a)))->f0 = 2;
return a;
}



void func_021C6CF4(Q *q)
{
    if (q->state == 1) {
        if (q->check(q->arg) == 1)
            func_021C6CEC((u32)q);
    }
}




/*
 * Addresses are Black-image addresses.
 */
u8 *func_021C6D10(int n, int heap)
{
    u8 *p = (u8 *)func_02030734(heap, 12, 0, (const char *)&d_021DE4E4, 0x34);

    p[0] = n;
    ((struct Obj09696 *)p)->f4 = func_02030734(heap, n * 4, 1, (const char *)&d_021DE4E4, 0x36);
    ((struct Obj09696 *)p)->f8 = func_02030734(heap, n * 4, 1, (const char *)&d_021DE4E4, 0x37);
    return p;
}


void func_021C6D5C(R_021C6D5C *r)
{
    int i;
    for (i = 0; i < r->n; i++)
        func_021C6E74(r, i);
    func_020307B0(r->f4);
    func_020307B0(r->f8);
    func_020307B0(r);
}



void func_021C6D90(u8 *p)
{
    int i;

    for (i = 0; i < p[0]; i++)
        func_021C6E94(p, i);
    for (i = 0; i < p[0]; i++)
        func_021C6EA8(p, i);
    for (i = 0; i < p[0]; i++)
        func_021C6EDC(p, i);
}



void func_021C6DE0(u8 *p, u32 *a, u32 b)
{
    int i;

    for (i = 0; i < p[0]; i++) {
        if (((u32 *)((struct Obj12957 *)p)->f4)[i] == 0) {
            func_021C6E5C(p, i, (u32)a, b);
            if (b == 0)
                func_021C6CC4(a);
            return;
        }
    }
    func_021C6CA8((Q *)a);
}


u8 func_021C6E20(R_021C6E20 *r)
{
    int i;
    u8 c = 0;
    for (i = 0; i < r->n; i++) {
        if (r->f4[i] != 0)
            c++;
    }
    return c;
}
