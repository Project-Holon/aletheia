/*
 * file:     bsubway_scr_p03.c
 * unit:     yes
 * function: func_021C89BC, func_021C8A30, func_021C8A74
 * address:  0x021C89BC
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
 *   func_021C8AAC  0x021C8AAC  thumb  ov021
 *   func_021C89A8  0x021C89A8  thumb  ov021
 *   func_021C8AD0  0x021C8AD0  thumb  ov021
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_021C8B48  0x021C8B48  thumb  ov021
 *   func_021C8B5C  0x021C8B5C  thumb  ov021
 *   func_02006148  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_021C8B14  0x021C8B14  thumb  ov021
 *   func_021C8B78  0x021C8B78  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 */
struct Desc;
struct Obj;
struct Obj00020;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

struct Work8A30 {
    void *sys;
    u8 *owner;
    u8 *f8;
    void *fC;
    u32 f10;
    u16 f14;
    u16 pad16;
    u32 f18;
};

typedef int (*TaskFn)(void *task, int *state, void *work);

extern int func_021C8AAC(int *p);
extern int func_021C89A8(u32 a);
extern void func_021C8AD0(int *p);
extern int func_0216D454(int a);
extern void func_021C8B48(int *p);
extern int func_021C8B5C(u32 a);
extern int func_02006148(u32 a0);
extern void func_020061F8(int a);
extern void func_021C8B14(int *p);
extern void func_021C8B78(int *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern u16 func_0216D5F8(void *p);
int func_021C89BC(int a, int *st, int *p);
void *func_021C8A30(u32 prio, void *sys, struct Obj00020 *owner);
int func_021C8A74(u32 a);


int func_021C89BC(int a, int *st, int *p)
{
    switch (*st) {
    case 0:
        if (func_021C89A8(func_021C8AAC(p)) == 0) {
            *st = 2;
        } else {
            *st = 1;
        }
        break;
    case 1:
        func_021C8AD0(p);
        if (func_0216D454(p[3])) {
            func_021C8B48(p);
            if (func_021C8B5C((u32)p)) {
                func_020061F8(func_02006148(0x694));
                *st = 2;
            } else {
                func_021C8B14(p);
            }
        }
        break;
    case 2:
        func_021C8B78(p);
        return 1;
    }
    return 0;
}


/*
 * Creates task func_021C89BC with a 0x1C byte work area and fills it from the
 * owner object.
 *
 * Addresses are Black-image addresses.
 */
void *func_021C8A30(u32 prio, void *sys, struct Obj00020 *owner)
{
    void *task = func_020122C0(sys, (void *)prio, (TaskFn)func_021C89BC, 0x1C);
    struct Work8A30 *w = func_020124E8(task);

    w->sys = sys;
    w->owner = (u8 *)owner;
    w->f8 = func_02188CB4(owner);
    w->fC = func_021A3074(w->f8);
    w->f10 = 0;
    w->f14 = func_0216D5F8(w->fC);
    w->f18 = 0;
    return task;
}


/*
 * Tail-call thunk: forwards to func_021C89A8 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
int func_021C8A74(u32 a)
{
    return func_021C89A8(a);
}
