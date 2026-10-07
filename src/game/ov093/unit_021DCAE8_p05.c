/*
 * file:     unit_021DCAE8_p05.c
 * unit:     yes
 * function: func_021DD080, func_021DD08C, func_021DD0A4, func_021DD0B0, func_021DD0C8, func_021DD0D4, func_021DD0EC, func_021DD0F8, func_021DD110, func_021DD11C, func_021DD134, func_021DD140, func_021DD158, func_021DD19C
 * address:  0x021DD080
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
 *   d_021F1AEC 0x021F1AEC data a4
 *   d_021F1DE4 0x021F1DE4 data a4
 *   d_021F1B14 0x021F1B14 data a4
 *   d_021F1B3C 0x021F1B3C data a4
 *   d_021F1B64 0x021F1B64 data a4
 *   d_021F1B8C 0x021F1B8C data a4
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D778C  0x021D778C  thumb  ov093
 *   func_021DD1D8  0x021DD1D8  thumb  ov093
 *   func_021DD044  0x021DD044  thumb  ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 */
#include "../../matched/include/Obj10066.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021D778C(int key, int *out);
extern int func_021DD1D8(u8 *b, int c, int d);
extern void func_021DD044(void *a, void *b, int c);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *, void *);
void func_021DD080(int a, int b, int c);
void func_021DD08C(void *a, void *b, int c);
const void *func_021DD098(int *p);
void func_021DD0A4(int a, int b, int c);
void func_021DD0B0(void *a, void *b, int c);
const void *func_021DD0BC(int *p);
void func_021DD0C8(int a, int b, int c);
void func_021DD0D4(void *a, void *b, int c);
const void *func_021DD0E0(int *p);
void func_021DD0EC(int a, int b, int c);
void func_021DD0F8(void *a, void *b, int c);
const void *func_021DD104(int *p);
void func_021DD110(int a, int b, int c);
void func_021DD11C(void *a, void *b, int c);
const void *func_021DD128(int *p);
void func_021DD134(int a, int b, int c);
void func_021DD140(void *a, void *b, int c);
const void *func_021DD14C(int *p);
void func_021DD158(u8 *a, u8 *b, int c, int d);
void func_021DD19C(void *a, u8 *b, int c, int d);
extern const unsigned char d_021F1AEC[];
extern const unsigned char d_021F1DE4[];
extern const unsigned char d_021F1B14[];
extern const unsigned char d_021F1B3C[];
extern const unsigned char d_021F1B64[];
extern const unsigned char d_021F1B8C[];


void func_021DD080(int a, int b, int c)
{
    func_021DD158((u8 *)a, (u8 *)b, c, 2);
}

void func_021DD08C(void *a, void *b, int c)
{
    func_021DD19C(a, b, c, 2);
}

const void *func_021DD098(int *p)
{
    *p = 5;
    return d_021F1AEC;
}


void func_021DD0A4(int a, int b, int c)
{
    func_021DD158((u8 *)a, (u8 *)b, c, 4);
}

void func_021DD0B0(void *a, void *b, int c)
{
    func_021DD19C(a, b, c, 4);
}

const void *func_021DD0BC(int *p)
{
    *p = 5;
    return d_021F1DE4;
}


void func_021DD0C8(int a, int b, int c)
{
    func_021DD158((u8 *)a, (u8 *)b, c, 3);
}

void func_021DD0D4(void *a, void *b, int c)
{
    func_021DD19C(a, b, c, 3);
}

const void *func_021DD0E0(int *p)
{
    *p = 5;
    return d_021F1B14;
}


void func_021DD0EC(int a, int b, int c)
{
    func_021DD158((u8 *)a, (u8 *)b, c, 6);
}

void func_021DD0F8(void *a, void *b, int c)
{
    func_021DD19C(a, b, c, 6);
}

const void *func_021DD104(int *p)
{
    *p = 5;
    return d_021F1B3C;
}


void func_021DD110(int a, int b, int c)
{
    func_021DD158((u8 *)a, (u8 *)b, c, 5);
}

void func_021DD11C(void *a, void *b, int c)
{
    func_021DD19C(a, b, c, 5);
}

const void *func_021DD128(int *p)
{
    *p = 5;
    return d_021F1B64;
}


void func_021DD134(int a, int b, int c)
{
    func_021DD158((u8 *)a, (u8 *)b, c, 0x25);
}

void func_021DD140(void *a, void *b, int c)
{
    func_021DD19C(a, b, c, 37);
}

const void *func_021DD14C(int *p)
{
    *p = 5;
    return d_021F1B8C;
}


void func_021DD158(u8 *a, u8 *b, int c, int d)
{
    int loc;
    if (c == func_021D775C(2)) {
        if (func_021D778C(0x2e, &loc) == 0 || loc == 3 || loc == 0) {
            if (func_021DD1D8(b, c, d) != 0)
                func_021DD044(a, b, c);
        }
    }
}

void func_021DD19C(void *a, u8 *b, int c, int d)
{
    u8 *p;
    if (c == func_021D775C(2) && func_021DD1D8(b, c, d)) {
        p = func_021C88A4((char *)b, 11, c);
        ((struct Obj10066 *)p)->f4 = d;
        p[0x14] = 1;
        p[8] = c;
        func_021C88C8(b, p);
    }
}
