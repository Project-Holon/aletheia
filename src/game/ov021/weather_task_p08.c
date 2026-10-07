/*
 * file:     weather_task_p08.c
 * unit:     yes
 * function: func_021A2160, func_021A2170, func_021A2180, func_021A2190, func_021A21A0, func_021A21B0, func_021A21B8, func_021A21BC, func_021A21C8, func_021A21E0, func_021A21F8, func_021A2228, func_021A223C, func_021A2248
 * address:  0x021A2160
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
 *   func_021A16D4 0x021A16D4 thumb ov021
 *   func_021A16E4 0x021A16E4 thumb ov021
 *   func_021A16E8 0x021A16E8 thumb ov021
 *   func_021A16DC 0x021A16DC thumb ov021
 *   func_021A16E0 0x021A16E0 thumb ov021
 *   func_021A273C  0x021A273C  thumb
 *   func_021A274C  0x021A274C  thumb  ov021
 *   func_021A277C  0x021A277C  thumb  ov021
 *   func_021A2BC4  0x021A2BC4  thumb  ov021
 *   func_021A27B8  0x021A27B8  thumb  ov021
 *   func_021A2A84  0x021A2A84  thumb  ov021
 *   func_021A2AAC  0x021A2AAC  thumb  ov021
 *   func_021A2AB8 0x021A2AB8 thumb ov021
 *   func_021A2B8C 0x021A2B8C thumb ov021
 */
#include "../../matched/include/Obj19731.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_021A16D4(unsigned char *p, unsigned int v);
extern void func_021A16E4(unsigned char *p, unsigned int v);
extern void func_021A16E8(unsigned char *p, unsigned int v);
extern void func_021A16DC(unsigned char *p, unsigned int v);
extern void func_021A16E0(unsigned char *p, unsigned int v);
extern u8 func_021A273C(u8 *p);
void *func_021A274C(void *p);
void func_021A277C(void *p, void *q);
int func_021A2BC4(u32 a);
void func_021A27B8(u32 x, u32 *p);
int func_021A2A84(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1, u32 e2, u32 e3, u32 e4, u32 e5);
void func_021A2AAC(char *p, int a, int b, int c, int d);
extern int func_021A2AB8(unsigned char *o, int arg);
extern int func_021A2B8C(unsigned char *o, int arg);
void func_021A2160(unsigned char *o, unsigned int v, int i);
void func_021A2170(unsigned char *o, unsigned int v, int i);
void func_021A2180(unsigned char *o, unsigned int v, int i);
void func_021A2190(unsigned char *o, unsigned int v, int i);
void func_021A21A0(unsigned char *o, unsigned int v, int i);
int func_021A21B0(u8 *a0);
int *func_021A21B8(int *p);
int func_021A21BC(unsigned char *o);
void *func_021A21C8(void *p, int a1);
void func_021A21E0(u32 *p);
void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
void func_021A2228(u8 *p, int a, int b, int c, int d);
int func_021A223C(unsigned char *o, int arg);
int func_021A2248(unsigned char *o, int arg);


/*
 * Unlabelled tail-call stub, filed for the ov026 lane.
 */
void func_021A2160(unsigned char *o, unsigned int v, int i)
{
    func_021A16D4((*(unsigned char ***)(o + 0x18))[i], v);
}


void func_021A2170(unsigned char *o, unsigned int v, int i)
{
    func_021A16E4((*(unsigned char ***)(o + 0x18))[i], v);
}


void func_021A2180(unsigned char *o, unsigned int v, int i)
{
    func_021A16E8((*(unsigned char ***)(o + 0x18))[i], v);
}


void func_021A2190(unsigned char *o, unsigned int v, int i)
{
    func_021A16DC((*(unsigned char ***)(o + 0x18))[i], v);
}


void func_021A21A0(unsigned char *o, unsigned int v, int i)
{
    func_021A16E0((*(unsigned char ***)(o + 0x18))[i], v);
}


/*
 * Tail-call thunk: forwards to func_021A273C with no argument change.
 *
 * Addresses are Black-image addresses.
 */
int func_021A21B0(u8 *a0)
{
    return func_021A273C(a0);
}

/*
 * Unlabelled 4-byte leaf: returns field 0x3c (ldr r0,[r0,#0x3c]).
 */
int *func_021A21B8(int *p)
{
    return (int *)p[15];
}


/*
 * Unlabelled leaf (ldr r1,[pc]; ldr r0,[r0,r1]; bx lr; pool 0x778), filed
 * for lane S30 (callee of ov027/ov028 functions).
 */
int func_021A21BC(unsigned char *o)
{
    return ((struct Obj19731 *)o)->f778;
}


void *func_021A21C8(void *p, int a1)
{
    void *r = func_021A274C(p);

    if (r != 0)
        func_021A277C(p, r);
    return r;
}


void func_021A21E0(u32 *p)
{
    if (func_021A2BC4((u32)p) != 0)
        func_021A27B8(p[0], p);
}


void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h)
{
    func_021A2A84((u32)(p + 0x4C), (u32)p, b, a, c, d, e, f, g, h);
}


void func_021A2228(u8 *p, int a, int b, int c, int d)
{
    func_021A2AAC((char *)(p + 0x4C), a, b, c, d);
}


int func_021A223C(unsigned char *o, int arg)
{
    return func_021A2AB8(o + 0x4C, arg);
}


/*
 * Unlabelled tail-call stub, filed for lane S30 (callee of ov027 functions).
 */
int func_021A2248(unsigned char *o, int arg)
{
    return func_021A2B8C(o + 0x4C, arg);
}
