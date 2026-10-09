/*
 * file:     unit_021DB650.c
 * unit:     yes
 * function: func_021DB650, func_021DB6A4, func_021DB6C0, func_021DB6E4, func_021DB6FC, func_021DB734, func_021DB774, func_021DB7DC, func_021DB7E8, func_021DB854, func_021DB87C, func_021DB8D0, func_021DB8DC, func_021DB8E8, func_021DB93C
 * address:  0x021DB650
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
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D70AC  0x021D70AC  thumb  ov093
 *   d_021F0B78     0x021F0B78  data   a2
 *   func_021D7320 0x021D7320 thumb ov093
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7324   0x021D7324  thumb
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F0D9C     0x021F0D9C  data   ov093  a4
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   sub_0201C1BC   0x0201C1BC  thumb
 *   func_021DB99C  0x021DB99C  thumb  ov093
 *   d_021F0AA0     0x021F0AA0  data   ov093  a4
 *   d_021F0AB8     0x021F0AB8  data   ov093  a4
 */
#include "../../matched/include/Obj13478.h"
#include "../../matched/include/Obj21330.h"
#include "../../matched/include/Obj21331.h"
#include "../../matched/include/Obj21333.h"

struct Unk021D62A8;
struct QS;
struct QI;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void *func_021C7CF4(int *p, int i);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern unsigned char func_021D70AC(unsigned char *p);
extern void func_021D7320(struct QS *p, u32 v);
extern int func_021D775C(int);
extern u16 func_021D5B40(struct QI *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *,void *);
extern int func_021D76BC(int key, u32 val);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88B4(void *a, int k, int b);
extern int func_021B9A24(u32 a, u32 b);
extern int func_021E85F8(int c);
extern u32 sub_0201C1BC(u16 move);
extern int func_021DB99C(int t);
int func_021DB650(int a, int b, int c, int d, int e, u8 g);
void func_021DB6A4(void *a, int b, int c, int *d);
void func_021DB6C0(void *a,int b,int c,int *d);
void func_021DB6E4(int a, int b, int c);
void func_021DB6FC(int a,void *b,int c);
void func_021DB734(int a, int b, int c, int d);
void func_021DB774(void *a, void *p, int id, int *s);
int *func_021DB7DC(int *p);
void func_021DB7E8(void *a, void *p, int id);
void func_021DB854(int a,int b,int c,int *d);
void func_021DB87C(void *a, void *p, int id, int *s);
int *func_021DB8D0(int *p);
int *func_021DB8DC(int *p);
void func_021DB8E8(void *a, void *p, int id);
void func_021DB93C(int a, int b, int x);
extern const u16 d_021F0B78[];
extern int d_021F0D9C[];
extern int d_021F0AA0[];
extern int d_021F0AB8[];




int func_021DB650(int a, int b, int c, int d, int e, u8 g)
{
    u32 i;

    if (func_021D62C4(func_021C7CF4((int *)b, g), 0x10) != 0)
        return 0;
    if (c == 5 && g == func_021D70AC((unsigned char *)a)) {
        for (i = 0; i < 13; i++) {
            if (e == d_021F0B78[i])
                return 0;
        }
        return 1;
    }
    return 0;
}




void func_021DB6A4(void *a, int b, int c, int *d)
{
    if (*d == 0) {
        func_021D7320(a, (u32)func_021DB650);
        *d = 1;
    }
}



void func_021DB6C0(void *a,int b,int c,int *d) { if(c==func_021D775C(2)) func_021DB6A4(a,b,c,d); }




/* 021DB6E4  shape F3: gate on func_021D775C(2) then func_021D7324 */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r3, r4, r5, lr}; adds r5, r0, #0; movs r0, #2; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021DB6FA; adds r0, r5, #0; bl func_021D7324; pop {r3, r4, r5, pc}.
 */
void func_021DB6E4(int a, int b, int c)
{
    if (c == func_021D775C(2))
        func_021D7324(a);
}



void func_021DB6FC(int a,void *b,int c) { unsigned char *p; if(c==func_021D775C(2) && func_021D5B40(func_021C7CF4(b,c))) { p=func_021C88A4(b,0x21,c); p[4]=c; func_021C88C8(b,p); } }




void func_021DB734(int a, int b, int c, int d)
{
    if (c == func_021D775C(2)) {
        unsigned short t = (unsigned short)func_021D775C(0x12);
        ((struct Obj13478 *)d)->f8 = 0;
        if (t == 0x16b && c == func_021D775C(2))
            ((struct Obj13478 *)d)->f8 = func_021D76BC(0x22, 0x13);
    }
}



void func_021DB774(void *a, void *p, int id, int *s)
{
    u8 *r;

    if (id == func_021D775C(2) && s[2] != 0) {
        func_021D775C(2);
        r = (u8 *)func_021C88A4(p, 4, id);
        ((struct Obj21330 *)r)->f0 |= 0x800000;
        func_021C8838(r + 4, 2, 0x389);
        func_021C8860((struct S *)(r + 4), id);
        func_021C8860((struct S *)(r + 4), func_021D775C(0x12));
        func_021C88C8(p, r);
        s[2] = 0;
    }
}



int *func_021DB7DC(int *p)
{
    *p = 7;
    return d_021F0D9C;
}



void func_021DB7E8(void *a, void *p, int id)
{
    u16 t;
    u8 *r;

    if (id == func_021D775C(4)) {
        t = func_021D775C(0x12);
        if (t == 0x10f || t == 0x19f) {
            if (func_021D76BC(0x40, 1) != 0) {
                r = (u8 *)func_021C88A4(p, 4, id);
                ((struct Obj21331 *)r)->f0 |= 0x800000;
                func_021C8838(r + 4, 2, 0xd2);
                func_021C8860((struct S *)(r + 4), id);
                func_021C88C8(p, r);
            }
        }
    }
}




void func_021DB854(int a,int b,int c,int *d) { if(c==func_021D775C(2) && func_021D775C(0x2d)==0) *d=func_021D76BC(0x41,1); }




void func_021DB87C(void *a, void *p, int id, int *s)
{
    u8 *r;

    if (id == func_021D775C(2) && s[0] != 0) {
        r = (u8 *)func_021C88A4(p, 4, id);
        ((struct Obj21333 *)r)->f0 |= 0x800000;
        func_021C8838(r + 4, 2, 0x1ed);
        func_021C8860((struct S *)(r + 4), id);
        func_021C88C8(p, r);
        s[0] = 0;
    }
}



int *func_021DB8D0(int *p)
{
    *p = 3;
    return d_021F0AA0;
}



int *func_021DB8DC(int *p)
{
    *p = 3;
    return d_021F0AB8;
}



void func_021DB8E8(void *a, void *p, int id)
{
    u8 *r;

    if (id == func_021D775C(2)) {
        func_021C88B4(p, 2, id);
        r = (u8 *)func_021C88A4(p, 4, id);
        func_021C8838(r + 4, 2, 0x1e7);
        func_021C8860((struct S *)(r + 4), id);
        func_021C88C8(p, r);
        func_021C88B4(p, 3, id);
    }
}




static inline void set8(int k, u8 v)
{
    func_021D76BC(k, v);
}




void func_021DB93C(int a, int b, int x)
{
    int ok;
    u16 t;

    if (func_021B9A24((u8)func_021D775C(3), x) == 0) {
        ok = 0;
        if (func_021E85F8(x) != 0) {
            ok = 1;
        } else {
            t = func_021D775C(0x12);
            if (sub_0201C1BC(t) == 10)
                ok = 1;
            else if (func_021DB99C(t) != 0)
                ok = 1;
        }
        if (ok != 0)
            set8(0x20, func_021D775C(0x20) + 1);
    }
}
