/*
 * file:     zknsearch_main_p05.c
 * unit:     yes
 * function: func_021BF55C, func_021BF5B8, func_021BF618, func_021BF658, func_021BF6E0, func_021BF728, func_021BF7B0, func_021BF81C, func_021BF85C, func_021BF89C
 * address:  0x021BF55C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BEDF0 0x021BEDF0 thumb ov210
 *   func_021BEE38 0x021BEE38 thumb ov210
 *   func_021BED98 0x021BED98 thumb ov210
 *   func_021B93B8 0x021B93B8 thumb ov067
 *   func_021BFB8C 0x021BFB8C thumb ov210
 *   func_021BEE58 0x021BEE58 thumb ov210
 *   func_021B8AE4 0x021B8AE4 thumb ov067
 *   func_021B93B0  0x021B93B0  thumb ov067
 *   func_021B93C0  0x021B93C0  thumb ov067
 *   func_021BEDB8  0x021BEDB8  thumb ov210
 *   func_021BEDD0  0x021BEDD0  thumb ov210
 *   func_021BCEF0 0x021BCEF0 thumb
 */
#include "../../matched/include/Obj14678.h"
#include "../../matched/include/Obj25628.h"
#include "../../matched/include/Obj25629.h"
#include "../../matched/include/Obj08414.h"
#include "../../matched/include/Obj04619.h"

struct S;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef signed short s16;

extern void func_021BEDF0(int p, int i, int v);
extern void func_021BEE38(char *p, int idx, int a, short b, unsigned short c);
extern void func_021BED98(char *, int, int);
extern int func_021B93B8(char *);
extern void func_021BFB8C(char *ctx, unsigned long slot, int y, int flag);
extern void func_021BEE58(char *, int, short *, short *, unsigned short);
extern int func_021B8AE4(struct S *, unsigned int);
extern int func_021B93B0(char *p);
extern int func_021B93C0(char *p);
extern void func_021BEDB8(int p, int i, int v);
extern int func_021BEDD0(int p, int i);
extern u32 func_021BCEF0(u32 a, u32 b);
void func_021BF55C(char *p);
void func_021BF5B8(char *p);
void func_021BF618(char *p);
void func_021BF658(char *p);
void func_021BF6E0(char *p);
void func_021BF728(u8 *p, int a);
void func_021BF7B0(char *p, int idx, int y, int flag);
void func_021BF81C(char *p);
void func_021BF85C(char *p, int i, int flag);
void func_021BF89C(char *p, u8 a, u8 b);

void func_021BF55C(char *p)
{
    func_021BEDF0((int)p, 3, 0);
    func_021BEDF0((int)p, 4, 0);
    func_021BEDF0((int)p, 2, 1);
    func_021BEDF0((int)p, 5, 1);
    func_021BEDF0((int)p, 6, 1);
    func_021BEDF0((int)p, 0, 1);
    func_021BEDF0((int)p, 1, 1);
    func_021BEE38(p, 0, 0xfc, 12, 0);
}

void func_021BF5B8(char *p)
{
    func_021BEDF0((int)p, 3, 0);
    func_021BEDF0((int)p, 4, 0);
    func_021BEDF0((int)p, 2, 1);
    func_021BEDF0((int)p, 5, 1);
    func_021BEDF0((int)p, 6, 1);
    func_021BEDF0((int)p, 0, 1);
    func_021BEDF0((int)p, 1, 1);
    func_021BEE38(p, 0, 0xfc, 12, 0);
    func_021BF618(p);
}

void func_021BF618(char *p)
{
    unsigned char v = (*(unsigned char **)(*(char * *)&((struct Obj14678 *)p)->f0 + 8))[6];
    if (v != 0xff) {
        func_021BED98(p, 7, v);
        func_021BEE38(p, 7, 0x40, 0x68, 0);
        func_021BEDF0((int)p, 7, 1);
    } else {
        func_021BEDF0((int)p, 7, 0);
    }
}

void func_021BF658(char *p)
{
    short base = func_021B93B8(*(char * *)&((struct Obj25628 *)p)->f1E0);
    short i;
    for (i = 0; i < 14; i++) {
        func_021BEDF0((int)p, i + 15, 0);
        func_021BEDF0((int)p, i + 29, 0);
        func_021BEDF0((int)p, i + 43, 0);
    }
    for (i = 0; i < 5; i++) {
        func_021BFB8C(p, (unsigned short)(base + i), (short)(i * 40), 1);
        if (base - (i + 1) >= 0)
            func_021BFB8C(p, (unsigned short)(base - (i + 1)), (short)(192 - (i + 1) * 40), 0);
    }
}

void func_021BF6E0(char *p)
{
    short pos[2];
    unsigned int y;
    func_021BEE58(p, 0, &pos[1], &pos[0], 0);
    y = func_021B8AE4(*(struct S * *)&((struct Obj25629 *)p)->f1E0, pos[0]);
    if (y < 12) y = 12;
    else if (y > 156) y = 156;
    func_021BEE38(p, 0, 0xfc, (short)y, 0);
}


void func_021BF728(u8 *p, int a)
{
    int r6 = func_021B93B0((char *)(((struct Obj08414 *)p)->f1E0));

    if (func_021BEDD0((int)p, 6) != 0xC || a == 0) {
        if (func_021B93B8((char *)(((struct Obj08414 *)p)->f1E0)) == 0 && r6 == 0)
            func_021BEDB8((int)p, 6, 0x12);
        else
            func_021BEDB8((int)p, 6, 4);
    }
    if (func_021BEDD0((int)p, 5) != 0xD || a == 0) {
        if (func_021B93C0((char *)(((struct Obj08414 *)p)->f1E0)) == 0 &&
            r6 == ((struct Obj08414 *)p)->f2AC - 1)
            func_021BEDB8((int)p, 5, 0x13);
        else
            func_021BEDB8((int)p, 5, 5);
    }
}

void func_021BF7B0(char *p, int idx, int y, int flag)
{
    int index;
    int coord;
    if (flag == 1) {
        index = idx + 9;
        func_021BEDF0((int)p, index, 1);
        coord = y + 12;
        func_021BEE38(p, index, 0x8c, coord, 0);
    } else {
        int other = idx + 11;
        func_021BEDF0((int)p, other, 1);
        coord = y + 12;
        func_021BEE38(p, other, 0x8c, coord, 1);
        index = idx + 13;
        func_021BEDF0((int)p, index, 1);
        func_021BEE38(p, index, 0x8c, coord, 1);
    }
}

void func_021BF81C(char *p)
{
    func_021BEDF0((int)p, 9, 0);
    func_021BEDF0((int)p, 10, 0);
    func_021BEDF0((int)p, 11, 0);
    func_021BEDF0((int)p, 12, 0);
    func_021BEDF0((int)p, 13, 0);
    func_021BEDF0((int)p, 14, 0);
}

/*
 * Caller sign-extends r3 to 16 bits before EE38; existing callee uses u16.
 */
void func_021BF85C(char *p, int i, int flag)
{
    func_021BEDF0((int)p, 9, flag);
    func_021BEDF0((int)p, 11, 0);
    func_021BEDF0((int)p, 13, 0);
    if (flag == 1)
        func_021BEE38(p, 9, 0x8c, (short)(i * 24 + 12), 0);
}


void func_021BF89C(char *p, u8 a, u8 b)
{
    u8 cur = (u8)func_021B93B8(((struct Obj04619 *)p)->f1E0);
    u8 d;
    int y;

    func_021BEDF0((int)p, 9, 0);
    func_021BEDF0((int)p, 0xA, 0);
    func_021BEDF0((int)p, 0xB, 0);
    func_021BEDF0((int)p, 0xC, 0);
    func_021BEDF0((int)p, 0xD, 0);
    func_021BEDF0((int)p, 0xE, 0);
    if (a != 0xFF) {
        a = (u8)func_021BCEF0((u32)p, a);
        d = (u8)(a - cur < 0 ? -(a - cur) : a - cur);
        if (a < cur) {
            if (d <= 8) {
                func_021BEDF0((int)p, 0xB, 1);
                y = (8 - d) * 0x18 + 0xC;
                func_021BEE38(p, 0xB, 0x8C, (s16)y, 1);
                func_021BEDF0((int)p, 0xD, 1);
                func_021BEE38(p, 0xD, 0x8C, (s16)y, 1);
            }
        } else if (d <= 7) {
            func_021BEDF0((int)p, 9, 1);
            func_021BEE38(p, 9, 0x8C, (s16)(d * 0x18 + 0xC), 0);
        }
    }
    if (b != 0xFF) {
        b = (u8)func_021BCEF0((u32)p, b);
        d = (u8)(b - cur < 0 ? -(b - cur) : b - cur);
        if (b < cur) {
            if (d <= 8) {
                func_021BEDF0((int)p, 0xC, 1);
                y = (8 - d) * 0x18 + 0xC;
                func_021BEE38(p, 0xC, 0x8C, (s16)y, 1);
                func_021BEDF0((int)p, 0xE, 1);
                func_021BEE38(p, 0xE, 0x8C, (s16)y, 1);
            }
        } else if (d <= 7) {
            func_021BEDF0((int)p, 0xA, 1);
            func_021BEE38(p, 0xA, 0x8C, (s16)(d * 0x18 + 0xC), 0);
        }
    }
}
