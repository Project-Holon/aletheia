/*
 * file:     btl_server_p57.c
 * unit:     yes
 * function: func_021C4218, func_021C4268, func_021C4304
 * address:  0x021C4218
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
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021C43C0  0x021C43C0  thumb  ov093
 *   func_021C43D0  0x021C43D0  thumb  ov093
 *   func_021C43E0  0x021C43E0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88E4  0x021C88E4  thumb  ov093
 */
#include "../../matched/include/Obj07754.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D74F8(int line);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int line);
extern int func_021C43C0(u8 *c);
extern int func_021C43D0(u8 *c);
extern u8 *func_021C43E0(u8 *c, u8 i);
extern int func_021D775C(int key);
extern int func_021C88E4(u8 *p);
void func_021C4218(u8 *p, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3);
void func_021C4268(u8 *p, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3);
int func_021C4304(u8 *p, u16 *b, u8 *a, u8 *c, int *out);


void func_021C4218(u8 *p, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3)
{
    u32 s = func_021CC8D8(p + 0x1D74, 9310);
    func_021C4268(p, a, b, c, s0, s1, s2, s3);
    func_021CC95C((u32 *)(p + 0x1D74), s, 9313);
}



void func_021C4268(u8 *p, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3)
{
    u8 x = func_021D5440(b);
    func_021D74F8(9335);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, x);
    func_021D75EC(0x14, ((struct Obj07754 *)c)->f2);
    func_021D75EC(0x12, ((struct Obj07754 *)c)->f0);
    func_021D75EC(0x38, s0);
    func_021D75EC(0x16, c[6]);
    func_021D75EC(0x1a, ((struct Obj07754 *)c)->f8);
    func_021D75EC(0x32, s1);
    func_021D75EC(0x45, s2);
    func_021D75EC(0x46, s3);
    func_021D7630(0x47, 0);
    func_021D70F0(p, 0x4a);
    func_021D70F0(p, 0x4b);
    func_021D70F0(p, 0x4c);
    func_021D7540(9352);
}



int func_021C4304(u8 *p, u16 *b, u8 *a, u8 *c, int *out)
{
    u8 n1;
    u8 n2;
    u8 i;
    func_021D74F8(9370);
    func_021D75EC(3, func_021D5440(a));
    n1 = func_021C43C0(c);
    n2 = func_021C43D0(c);
    func_021D75EC(5, n2);
    func_021D7630(0x51, 1);
    for (i = 0; i < n2; i++) {
        func_021D75EC(i + 6, func_021D5440(func_021C43E0(c, i)));
    }
    func_021D75EC(0x12, *b);
    if (n1 != 0) {
        if (n2 != 0) {
            func_021D70F0(p, 0xa0);
        }
    } else {
        func_021D70F0(p, 0xa1);
    }
    *out = func_021D775C(0x51);
    func_021D7540(9402);
    if (func_021C88E4(p) != 0) {
        return 1;
    }
    return 0;
}
