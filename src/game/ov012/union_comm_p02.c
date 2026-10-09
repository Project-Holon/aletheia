/*
 * file:     union_comm_p02.c
 * unit:     yes
 * function: func_02172C4C, func_02172C78, func_02172C98, func_02172CAC, func_02172CE8, func_02172D14, func_02172D20, func_02172D38, func_02172D50, func_02172D68, func_02172D7C, func_02172E48
 * address:  0x02172C4C
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02172BC0 0x02172BC0 thumb ov012
 *   func_0203CBAC 0x0203CBAC arm
 *   d_02175380 0x02175380 data ov012 a4
 *   func_0203D0FC 0x0203D0FC arm
 *   func_0203D8C4  0x0203D8C4  arm
 *   func_0203CEAC 0x0203CEAC arm
 *   func_02172C1C 0x02172C1C thumb ov012
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FBA0 0x0200FBA0 thumb
 *   func_0203CD98  0x0203CD98  arm
 *   func_0217778C  0x0217778C  thumb  ov014
 *   func_021730C8  0x021730C8  thumb  ov012
 *   func_0217303C  0x0217303C  thumb  ov012
 *   func_02172FF0  0x02172FF0  thumb  ov012
 *   func_02172EEC  0x02172EEC  thumb  ov012
 *   func_0203D378  0x0203D378  arm
 */
#include "../../matched/include/Obj09356.h"

struct Req;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Work_0 { u8 b[0x3570]; } Work_0;

typedef struct {
    u8 pad[0xC8];
    u8 f0 : 1;
    u8 f1 : 1;
} Obj;

typedef struct {
    u8 pad[0x2829];
    u8 f2829;
    u8 pad2[0x2831 - 0x282A];
    u8 f2831;
    u8 pad3[0x355C - 0x2832];
    Obj *obj;
} Work_02172E48;

extern Work_0 *func_02172BC0(u32 a);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern void func_0203D0FC(int a);
extern void func_0203D8C4(u32 a);
extern int func_0203CEAC(int a0);
extern void func_02172C1C(void *a, u8 *p);
extern u32 func_0200FB24(void);
extern void func_0200FBA0(void);
extern int func_0203CD98(void);
extern void func_0217778C(void);
extern void func_021730C8(u8 *self);
extern void func_0217303C(Work_02172E48 *w);
extern void func_02172FF0(u8 *w);
extern void func_02172EEC(Work_02172E48 *w);
extern u32 func_0203D378(void);
Work_0 *func_02172C4C(void *unused, u32 a);
/* * extent: existing matched follower ov012_func_02172C98.c */ int func_02172C78(void *a, void *b, u8 *p);
/* * note: unlabelled callback leaf (a .word run in the listing); passed as * a function pointer (pool words 0x02172C74 and 0x02172E44). */ void func_02172C98(u8 *p);
int func_02172CAC(void *a, void *b, u8 *p);
int func_02172CE8(void *a, void *b, u8 *p);
/* * extent: existing matched follower ov012_func_02172D20.c */ void func_02172D14(u8 *p);
/* * Unlabelled leaf (no push, so disasm.py printed it as a .word run); * called from ov019 func_0217C074. */ void func_02172D20(u8 *p);
void func_02172D38(u8 *p);
void func_02172D50(u8 *p);
/* * Unlabelled leaf (no push, so disasm.py printed it as a .word run); * called from ov019 func_0217C074. */ int func_02172D68(u8 *p);
int func_02172D7C(u8 *p);
void func_02172E48(int a, int b, Work_02172E48 *w);
extern char d_02175380[];




Work_0 *func_02172C4C(void *unused, u32 a) { Work_0 *p; p = func_02172BC0(a); p->b[0x3560] = 1; func_0203CBAC((struct Req *)d_02175380, (u32)func_02172C98, (u32)p); return p; }




/*
 * extent: existing matched follower ov012_func_02172C98.c
 */
int func_02172C78(void *a, void *b, u8 *p) { if (p[0x3560] >= 2) { p[0x3560] = 3; func_0203D0FC(0); return 1; } return 0; }





/*
 * note:     unlabelled callback leaf (a .word run in the listing); passed as
 *           a function pointer (pool words 0x02172C74 and 0x02172E44).
 */
void func_02172C98(u8 *p)
{
    p[0x3560] = 2;
    func_0203D8C4(0);
}




int func_02172CAC(void *a, void *b, u8 *p) { ((struct Obj09356 *)p)->f356C = 1; if (p[0x3560] < 3) return 0; p[0x3560] = 4; if (func_0203CEAC((int)func_02172D14) == 0) func_02172D14(p); return 1; }




int func_02172CE8(void *a, void *b, u8 *p) { if (p[0x3560] == 5) { func_02172C1C(b,p); if (func_0200FB24() != 0) func_0200FBA0(); return 1; } return 0; }




/*
 * extent: existing matched follower ov012_func_02172D20.c
 */
void func_02172D14(u8 *p) { p[0x3560] = 5; }





/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from ov019 func_0217C074.
 */
void func_02172D20(u8 *p)
{
    if (p[0x3561] == 0) {
        p[0x3561] = 1;
        p[0x3562] = 0;
    }
}





void func_02172D38(u8 *p)
{
    if (p[0x3561] == 0) {
        p[0x3561] = 1;
        p[0x3562] = 1;
    }
}





void func_02172D50(u8 *p)
{
    if (p[0x3561] == 0) {
        p[0x3561] = 1;
        p[0x3562] = 2;
    }
}




int func_02172D68(u8 *p)
{
    if (p[0x3561] != 0)
        return 1;
    return 0;
}




int func_02172D7C(u8 *p)
{
    switch (p[0x3561]) {
    case 0:
        if (p[0x3562] == 1) {
            return 1;
        }
        return 0;
    case 1:
        switch (p[0x3562]) {
        case 0:
        case 1:
            p[0x3561] = 2;
            break;
        case 2:
            p[0x3561] = 4;
            break;
        default:
            p[0x3561] = 0;
            break;
        }
        break;
    case 2:
        p[0x3560] = 4;
        if (func_0203CEAC((int)func_02172D14) == 0) {
            func_02172D14(p);
        }
        p[0x3561]++;
        break;
    case 3:
        if (p[0x3560] == 5) {
            if (p[0x3562] == 1) {
                p[0x3561] = 0;
            } else {
                p[0x3561]++;
            }
        }
        break;
    case 4:
        p[0x3560] = 1;
        func_0203CBAC((struct Req *)d_02175380, (u32)func_02172C98, (u32)p);
        p[0x3561]++;
        break;
    case 5:
        if (p[0x3560] >= 2) {
            p[0x3560] = 3;
            func_0203D0FC(0);
            p[0x3561] = 0;
        }
        break;
    }
    return 1;
}


void func_02172E48(int a, int b, Work_02172E48 *w)
{
    if (func_02172D7C((u8 *)w) == 1) {
        return;
    }
    if (func_0203CD98() == 0) {
        return;
    }
    if (w->f2829 == 1) {
        func_0217778C();
        w->f2829 = 0;
    }
    func_021730C8((u8 *)w);
    func_0217303C(w);
    func_02172FF0((u8 *)w);
    func_02172EEC(w);
    if (func_0200FB24() != 0 && func_0203D378() == 1 && w->obj != 0
        && w->obj->f0 == 1 && w->f2831 == 0x2a && w->obj->f1 == 0) {
        func_02172D38((u8 *)w);
        w->obj->f1 = 1;
    }
}
