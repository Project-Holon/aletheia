/*
 * file:     beacon_view_p11.c
 * unit:     yes
 * function: func_021F178C, func_021F17D8
 * address:  0x021F178C
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
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02040618 0x02040618 arm
 *   func_02031194 0x02031194 arm
 */
#include "../../matched/include/Obj04311.h"
#include "../../matched/include/Obj20428.h"
#include "../../matched/include/Obj03636.h"

struct S02030FB4;
struct TcblNode;
typedef unsigned char u8;

typedef unsigned int u32;

typedef signed char s8;

extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern void *func_02031290(struct S02030FB4 *p);
extern void func_02082BCC(void *p, int v, int n);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_02031194(struct TcblNode *n);
void func_021F178C(char *this, u8 a, int *p);
void func_021F17D8(void *task, u8 *q);


void func_021F178C(char *this, u8 a, int *p)
{
    u8 *r;
    int v;

    r = func_02031290(func_020311B8(((struct Obj20428 *)this)->fA0, (void *)func_021F17D8, 0xc, 0));
    func_02082BCC(r, 0, 0xc);
    r[0] = a;
    if (r[0] == 0) {
        r[3] = 0;
        v = 0x10;
    } else {
        v = 0x40;
        r[3] = v;
        v -= 0x50;
    }
    r[4] = v;
    r[1] = 4;
    *(int * *)&((struct Obj04311 *)r)->f8 = p;
    *p = *p + 1;
}

void func_021F17D8(void *task, u8 *q)
{
    u32 old;
    int x;
    old = q[2];
    q[2] = old + 1;
    if (old < q[1]) {
        x = ((struct Obj03636 *)q)->f3;
        q[3] = x + ((struct Obj03636 *)q)->f4;
        func_02040618(6, 3, ((struct Obj03636 *)q)->f3);
        return;
    }
    (**(int * *)&((struct Obj03636 *)q)->f8)--;
    func_02031194(task);
}
