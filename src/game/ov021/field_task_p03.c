/*
 * file:     field_task_p03.c
 * unit:     yes
 * function: func_021C6D5C, func_021C6D90, func_021C6DE0, func_021C6E20
 * address:  0x021C6D5C
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
 *   func_021C6E74  0x021C6E74  thumb  ov021
 *   func_021C6E94  0x021C6E94  thumb  ov021
 *   func_021C6EA8  0x021C6EA8  thumb  ov021
 *   func_021C6EDC  0x021C6EDC  thumb  ov021
 *   func_021C6E5C  0x021C6E5C  thumb  ov021
 *   func_021C6CC4  0x021C6CC4  thumb  ov021
 *   func_021C6CA8  0x021C6CA8  thumb  ov021
 */
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

typedef struct { u8 n; u8 pad[3]; void *f4; void *f8; } R_021C6D5C;

typedef struct Q Q;

typedef struct { u8 n; u8 pad[3]; Q **f4; u32 *f8; } R_021C6E20;

extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021C6E74(R_021C6D5C *r, u8 i);
extern void func_021C6E94(u8 *p, u8 i);
extern void func_021C6EA8(u8 *p, u8 i);
extern void func_021C6EDC(u8 *p, u8 i);
extern void func_021C6E5C(u8 *p, u8 i, u32 a, u32 b);
extern void func_021C6CC4(u32 *a0);
extern void func_021C6CA8(u32 a);
void func_021C6D5C(R_021C6D5C *r);
void func_021C6D90(u8 *p);
void func_021C6DE0(u8 *p, u32 *a, u32 b);
u8 func_021C6E20(R_021C6E20 *r);

void func_021C6D5C(R_021C6D5C *r)
{
    int i;
    for (i = 0; i < r->n; i++)
        func_021C6E74(r, i);
    func_020307B0(r->f4);
    func_020307B0(r->f8);
    func_020307B0(r);
}


/*
 * Addresses are Black-image addresses.
 */
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
    func_021C6CA8((u32)a);
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
