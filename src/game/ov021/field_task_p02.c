/*
 * file:     field_task_p02.c
 * unit:     yes
 * function: func_021C6CE4, func_021C6CEC, func_021C6CF4, func_021C6D10
 * address:  0x021C6CE4
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
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   d_021DE4E4     0x021DE4E4  data  ov021  a4
 */
#include "../../matched/include/Obj18318.h"
#include "../../matched/include/Obj09696.h"

struct Node;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u16 fC;
    u16 fE;
    u16 f10[8];
    u8 f20;
} D;

typedef struct { u32 f0; u32 *f4; int (*f8)(u32 *); } Q;

extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
void func_021C6CE4(u32 *p);
int func_021C6CEC(u32 a);
void func_021C6CF4(Q *q);
u8 *func_021C6D10(int n, int heap);
extern int d_021DE4E4;




/*
 * Unlabelled leaf setter; callee of the thunk at 0x021C6CC4.
 *
 * Addresses are Black-image addresses.
 */
void func_021C6CE4(u32 *p)
{
    *p = 1;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C6CEC(u32 a)
{
((struct Obj18318 *)((u8 *)(a)))->f0 = 2;
return a;
}

void func_021C6CF4(Q *q)
{
    if (q->f0 == 1) {
        if (q->f8(q->f4) == 1)
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
