/*
 * file:     field_task_p01.c
 * unit:     yes
 * function: func_021C6C70, func_021C6CA8, func_021C6CBC, func_021C6CC4, func_021C6CCC, func_021C6CD0, func_021C6CE0
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
 *   func_021C6CF4  0x021C6CF4  thumb
 *   func_021C6CE4  0x021C6CE4  thumb  ov021
 */
#include "../../matched/include/Obj18314.h"
#include "../../matched/include/Obj18315.h"
#include "../../matched/include/Obj18316.h"

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

typedef struct { u32 f0; u32 *f4; u32 f8; } Q;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021C6CF4();
extern void func_021C6CE4(u32 *p);
Q *func_021C6C70(u32 heap, u32 size, u32 v);
void func_021C6CA8(Q *q);
void func_021C6CBC(void);
void func_021C6CC4(u32 *a0);
u32 func_021C6CCC(u8 *p);
int func_021C6CD0(u32 a);
u32 func_021C6CE0(u8 *p);
extern char d_021DE4D4[];

Q *func_021C6C70(u32 heap, u32 size, u32 v)
{
    Q *q = func_02030734(heap, 0xc, 0, d_021DE4D4, 0x3b);
    q->f0 = 0;
    q->f4 = func_02030734(heap, size, 1, d_021DE4D4, 0x3d);
    q->f8 = v;
    return q;
}

void func_021C6CA8(Q *q)
{
    func_020307B0(q->f4);
    func_020307B0(q);
}


/*
 * Tail-call thunk: forwards to func_021C6CF4 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021C6CBC(void)
{
    func_021C6CF4();
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
