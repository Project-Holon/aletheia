/*
 * file:     weather_task_p03.c
 * unit:     yes
 * function: func_021A1BF4, func_021A1BF8, func_021A1C04, func_021A1C1C, func_021A1C34, func_021A1C68, func_021A1D04
 * address:  0x021A1BF4
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
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021A1670  0x021A1670  thumb  ov021
 *   func_021A1D78  0x021A1D78  thumb  ov021
 *   d_021D886C     0x021D886C  data  ov021  a4
 *   d_021D8868     0x021D8868  data  ov021  a4
 *   func_021A2050  0x021A2050  thumb  ov021
 *   func_021A21B0  0x021A21B0  thumb  ov021
 *   func_021A1FEC  0x021A1FEC  thumb  ov021
 */
#include "../../matched/include/Obj17998.h"
#include "../../matched/include/Obj00755.h"
#include "../../matched/include/Obj01356.h"

struct O;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct {
    u32 pad0;
    u32 pad4;
    u16 result;
    u16 busy;
    u16 cur;
    u16 next;
    u32 flag;
    u16 queued;
} Obj021A1C34;

extern int func_02034AC4(s32 handle);
void func_02034A5C(int x);
void func_021A1670(u8 *p);
int func_021A1D78(u16 a, u16 b);
extern void func_021A2050(struct O *p, u32 a, u32 b);
extern int func_021A21B0(u8 *a0);
extern void func_021A1FEC(struct O *p, u32 v, u8 b, u32 c, u32 d, u32 e, u32 g);
u16 func_021A1BF4(u8 *p);
void func_021A1BF8(u32 *p, u32 v);
void func_021A1C04(u8 *p);
void func_021A1C1C(int a, u32 *p);
int func_021A1C34(Obj021A1C34 *p, u16 x);
void func_021A1C68(u8 *p, int x);
void func_021A1D04(u8 *p, int x);
extern const u32 d_021D886C[];
extern const u32 d_021D8868[];


/*
 * Loads the 16-bit halfword at +0xc of the object.
 */
u16 func_021A1BF4(u8 *p)
{
    return ((struct Obj17998 *)p)->fC;
}


/*
 * Stores the word at +0x28, then tail calls on it.
 *
 * Addresses are Black-image addresses.
 */
void func_021A1BF8(u32 *p, u32 v)
{
    p[0xa] = v;
    func_02034AC4(v);
}


void func_021A1C04(u8 *p)
{
    if (((struct Obj00755 *)p)->f28 != -1) {
        func_02034A5C(((struct Obj00755 *)p)->f28);
        ((struct Obj00755 *)p)->f28 = -1;
    }
}


void func_021A1C1C(int a, u32 *p)
{
    int i;

    for (i = 0; i < 2; i++)
        func_021A1670((u8 *)p[i]);
}


int func_021A1C34(Obj021A1C34 *p, u16 x)
{
    if (p->busy != 0) {
        p->queued = x;
        return 0;
    }
    if (p->cur == x && x != 0)
        return 0;
    p->next = x;
    p->flag = 1;
    p->result = func_021A1D78(p->cur, p->next);
    p->busy = 1;
    return 1;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A1C68(u8 *p, int x)
{
    switch (((struct Obj00755 *)p)->fA) {
    case 0:
        break;
    case 1:
        func_021A2050((struct O *)(((struct Obj00755 *)p)->f20), 1, 1);
        ((struct Obj00755 *)p)->fA = 2;
        break;
    case 2:
        if (func_021A21B0((u8 *)(((struct Obj00755 *)p)->f20)) == 0) {
            func_021A1C04(p);
            ((struct Obj00755 *)p)->fA = 3;
        }
        break;
    case 3:
        func_021A1BF8((u32 *)p, d_021D886C[((struct Obj00755 *)p)->fE * 2]);
        ((struct Obj00755 *)p)->fA = 4;
        break;
    case 4:
        func_021A1FEC((struct O *)(((struct Obj00755 *)p)->f20), d_021D8868[((struct Obj00755 *)p)->fE * 2], 1, 1, 1,
                      ((struct Obj00755 *)p)->f10, x);
        ((struct Obj00755 *)p)->f10 = 1;
        ((struct Obj00755 *)p)->fC = ((struct Obj00755 *)p)->fE;
        ((struct Obj00755 *)p)->fE = 0xFFFF;
        ((struct Obj00755 *)p)->fA = 0;
        break;
    }
}


void func_021A1D04(u8 *p, int x)
{
    u32 t;

    switch (((struct Obj01356 *)p)->fA) {
    case 0:
        break;
    case 1:
        func_021A1FEC((struct O *)(((struct Obj01356 *)p)->f24), d_021D8868[((struct Obj01356 *)p)->fE * 2], 1, 1, 2,
                      ((struct Obj01356 *)p)->f10, x);
        func_021A2050((struct O *)(((struct Obj01356 *)p)->f20), 1, 2);
        ((struct Obj01356 *)p)->fA = 2;
        break;
    case 2:
        if (func_021A21B0((u8 *)(((struct Obj01356 *)p)->f20)) == 0) {
            t = ((struct Obj01356 *)p)->f20;
            ((struct Obj01356 *)p)->f20 = ((struct Obj01356 *)p)->f24;
            ((struct Obj01356 *)p)->f24 = t;
            ((struct Obj01356 *)p)->fC = ((struct Obj01356 *)p)->fE;
            ((struct Obj01356 *)p)->fE = 0xFFFF;
            ((struct Obj01356 *)p)->f10 = 1;
            ((struct Obj01356 *)p)->fA = 0;
        }
        break;
    }
}
