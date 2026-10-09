/*
 * file:     unit_021DBE6C.c
 * unit:     yes
 * function: func_021DBE6C, func_021DBF1C, func_021DBF28, func_021DBF58, func_021DBF84, func_021DBF9C, func_021DBFD4, func_021DC054, func_021DC0B0
 * address:  0x021DBE6C
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5D14  0x021D5D14  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 *   d_021F0D14 0x021F0D14 data a4
 *   func_0201C1BC  0x0201C1BC  thumb
 *   func_0201BD28  0x0201BD28  thumb
 *   func_0201C020  0x0201C020  thumb
 *   func_0201C0BC  0x0201C0BC  thumb
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   d_021F07D0     0x021F07D0  data   ov093  a4
 *   d_021F0688     0x021F0688  data   ov093  a4
 */
#include "../../matched/include/Obj02789.h"
#include "../../matched/include/Obj05217.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5D14(s8 *p, int i, int sign);
extern int func_021D5B68(void *m);
extern void func_021C88B4(void *a, int k, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021D7704(int,int);
extern int func_021D76BC(int,unsigned int);
extern u32 func_0201C1BC(u16 id);
extern u32 func_0201BD28(u16 id, u32 field);
extern u8 func_0201C020(u16 id);
extern u8 func_0201C0BC(u16 id, u32 idx, s32 *out);
extern int func_021B9A24(u32 a, u32 b);
void func_021DBE6C(int u, void *a, u32 b);
int *func_021DBF1C(int *p);
void func_021DBF28(int a,int b,int c);
void func_021DBF58(int a,int b,int c);
void func_021DBF84(int a, int b, int c);
void func_021DBF9C(int a,int b,int c);
int *func_021DBFC8(int *p);
int func_021DBFD4(u16 id);
void func_021DC054(int u, void *a, u32 b);
int *func_021DC0B0(int *p);
extern int d_021F0D14;
extern int d_021F07D0[];
extern int d_021F0688[];


void func_021DBE6C(int u, void *a, u32 b)
{
    u8 *e;
    void *m;
    int ok;
    if (b != func_021D775C(4)) {
        return;
    }
    if (func_021D775C(0x1a) != 1) {
        return;
    }
    if (func_021D775C(0x46) != 0) {
        return;
    }
    m = func_021C7CF4((int *)((int)a), b);
    ok = 0;
    if (func_021D5D14(m, 2, -1) != 0 || func_021D5D14(m, 5, 1) != 0) {
        ok = 1;
    }
    if (ok == 0) {
        return;
    }
    if (func_021D5B68(m) != 0) {
        return;
    }
    func_021C88B4(a, 2, b);
    e = func_021C88A4(a, 0xe, b);
    e[0xf] = 1;
    e[0x10] = b;
    e[0xe] = 1;
    ((struct Obj02789 *)e)->f4 = 2;
    *(s8 *)&((struct Obj02789 *)e)->fC = -1;
    func_021C88C8(a, e);
    e = func_021C88A4(a, 0xe, b);
    e[0xf] = 1;
    e[0x10] = b;
    e[0xe] = 1;
    ((struct Obj02789 *)e)->f4 = 5;
    e[0xc] = 1;
    func_021C88C8(a, e);
    func_021C88B4(a, 3, b);
}


int *func_021DBF1C(int *p)
{
    *p = 1;
    return d_021F07D0;
}


void func_021DBF28(int a,int b,int c) { if(c==func_021D775C(3) && func_021DBFD4(func_021D775C(0x12))) func_021D7704(0x31,0x14cd); }



void func_021DBF58(int a,int b,int c) { if(c==func_021D775C(3) && func_021DBFD4(func_021D775C(0x12))) func_021D76BC(0x41,1); }




/* 021DBF84  shape F1: gate on func_021D775C(3) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #3; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021DBF9A; movs r0, #0x41; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */
void func_021DBF84(int a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021D76BC(0x41, 1);
}



void func_021DBF9C(int a,int b,int c) { if(c==func_021D775C(3) && func_021DBFD4(func_021D775C(0x12))) func_021D76BC(0x48,1); }



int *func_021DBFC8(int *p) { *p=5; return &d_021F0D14; }




int func_021DBFD4(u16 id)
{
    u32 t = func_0201C1BC(id);
    if (func_0201BD28(id, 10) != 0) {
        return 1;
    }
    switch (t) {
    case 4:
        if (func_0201BD28(id, 11) == 8) {
            return 0;
        }
    case 6:
        return 1;
    case 7: {
        u32 n;
        u32 i;
        s32 out;
        n = func_0201C020(id);
        for (i = 0; i < n; i++) {
            func_0201C0BC(id, i, &out);
            if (out < 0) {
                return 0;
            }
        }
        return 1;
    }
    default:
        if (id == 0x122) {
            return 1;
        }
        return 0;
    }
}




void func_021DC054(int u, void *a, u32 b)
{
    u8 *e;
    u8 v;
    if (b == func_021D775C(2)
        && (v = func_021D775C(3), func_021B9A24(b, v)) == 0
        && func_021D775C(0x20) < 0) {
        e = func_021C88A4(a, 0xe, b);
        ((struct Obj05217 *)e)->f0 |= 0x20 << 18;
        ((struct Obj05217 *)e)->f4 = 1;
        e[0xc] = 2;
        e[0xe] = 1;
        e[0xf] = 1;
        e[0x10] = b;
        func_021C88C8(a, e);
    }
}


int *func_021DC0B0(int *p)
{
    *p = 1;
    return d_021F0688;
}
