/*
 * file:     unit_0216B24C_p01.c
 * unit:     yes
 * function: func_0216B24C, func_0216B280
 * address:  0x0216B24C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02176850  0x02176850  thumb  ov011
 *   func_02176870  0x02176870  thumb  ov011
 */
#include "../../matched/include/Obj09327.h"

struct Ctx;
struct Desc;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int value; u8 flag; u8 padding[3]; } Work;

extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *, int, int);
extern void *func_020124E4(struct Obj *p);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158344(int a0);
extern int func_02176850(u8 *p, u8 value);
extern u32 func_02176870(u8 *p);
int func_0216B24C(void *vm, int value, int flag);
int func_0216B280(int a0, int *state, u8 **work);

int func_0216B24C(void *vm, int value, int flag)
{
    int task;
    Work *p;
    func_020120F4((const struct Ctx *)vm);
    task = (int)func_020122C0((void *)vm, 0, func_0216B280, 8);
    p = func_020124E8((struct Obj *)task);
    func_02082BCC(p, 0, 8);
    p->value = value;
    p->flag = flag;
    return task;
}


int func_0216B280(int a0, int *state, u8 **work)
{
    int r;
    u16 *p;

    r = func_02158344(func_02012138((const struct Ctx *)func_020124E4((struct Obj *)a0)));
    if (r == 0) {
        p = *(u16 * *)&((struct Obj09327 *)work)->f0;
        if (p != 0)
            *p = 0;
        return 1;
    }
    switch (*state) {
    case 0:
        if (func_02176850((u8 *)r, ((u8 *)work)[4]) == 1)
            (*state)++;
        break;
    case 1:
        if (func_02176870((u8 *)r) == 1)
            (*state)++;
        break;
    case 2:
        p = *(u16 * *)&((struct Obj09327 *)work)->f0;
        if (p != 0)
            *p = 1;
        return 1;
    }
    return 0;
}
