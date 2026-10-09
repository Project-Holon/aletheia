/*
 * file:     btl_server_p42.c
 * unit:     yes
 * function: func_021C1C88, func_021C1CCC, func_021C1CE4
 * address:  0x021C1C88
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021C7664 0x021C7664 thumb ov093
 *   func_021C1D60 0x021C1D60 thumb ov093
 *   func_021C1D30  0x021C1D30  thumb  ov093
 *   func_021C1D40  0x021C1D40  thumb  ov093
 *   func_021C1D50  0x021C1D50  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D6D7C  0x021D6D7C  thumb  ov093
 *   func_021C557C  0x021C557C  thumb  ov093
 */
#include "../../matched/include/Obj21079.h"

struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int line);
extern int func_021C7664(u8 *, u32, u8 *);
extern int func_021C1D60(u8 *, u8 *, u32);
extern void func_021C1D30(u8 *w);
extern u8 *func_021C1D40(u8 *w);
extern u8 *func_021C1D50(u8 *w);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern u32 func_021D6D7C(u8 *p);
extern void func_021C557C(u8 *p, u8 *a, int k, int flag);
void func_021C1C88(u8 *p, u8 *a, u32 unused, u8 *q, u32 v);
int func_021C1CCC(u8 *p, u16 *x, u8 *a, u8 *q);
void func_021C1CE4(u8 *p, u8 *q, u32 unused, u8 *w);


void func_021C1C88(u8 *p, u8 *a, u32 unused, u8 *q, u32 v)
{
    func_021D74F8(7009);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x4d, v);
    func_021D75EC(0x12, ((struct Obj21079 *)q)->f0);
    func_021D70F0(p, 0x88);
    func_021D7540(7014);
}


int func_021C1CCC(u8 *p, u16 *x, u8 *a, u8 *q)
{
    int n;
    n = func_021C7664(p, *x, a);
    return func_021C1D60(p, q, n);
}



void func_021C1CE4(u8 *p, u8 *q, u32 unused, u8 *w)
{
    u8 *t;
    if (q[6] == 9) {
        func_021C1D30(w);
        t = func_021C1D40(w);
        while (t) {
            int k = 3;
            if (func_021D62A8((struct Unk021D62A8 *)t) == 3 && func_021D6D7C(t) == 0) {
                func_021C557C(p, t, k, 1);
            }
            t = func_021C1D50(w);
        }
    }
}
