/*
 * file:     weather_task_p34.c
 * unit:     yes
 * function: func_021A3810, func_021A3818, func_021A3898, func_021A38A4
 * address:  0x021A3810
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
 *   func_020307B0  0x020307B0  arm
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D80C  0x0216D80C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D818  0x0216D818  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D824  0x0216D824  thumb  ov010
 *   func_0216D844  0x0216D844  thumb  ov010
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D874  0x0216D874  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 */
#include "../../matched/include/Obj18032.h"
#include "../../matched/include/Obj19775.h"

struct Actor;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A38A4;

extern u32 func_020307B0(void *p);
extern int func_0216D3CC(int a0);
extern int func_0216D454();
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
u16 func_0216D83C(u32 h);
void func_0216D80C(void *p, u16 v);
u16 func_0216D854(u32 h);
void func_0216D818(void *p, u16 v);
u16 func_0216D86C(u32 h);
void func_0216D824(void *p, u16 v);
void func_0216D844(void *p, short v);
void func_0216D85C(void *p, int v);
void func_0216D874(int a0, int a1);
void func_0216D89C(u32 h, Vec021A38A4 *v);
void func_021A3810(u32 a0);
void func_021A3818(u32 *p);
void func_021A3898(u8 *p, struct VecFx32 *out);
void func_021A38A4(u8 *p, Vec021A38A4 *v);


/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021A3810(u32 a0)
{
    func_020307B0((void *)a0);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A3818(u32 *p)
{
    u32 h = p[7];
    u32 m;
    u32 old = p[4];

    p[4] = 0;
    m = p[5];
    if (func_0216D3CC(h) == 0) {
        switch (m) {
        case 0:
            break;
        case 1:
            if (old == 0 || old == 3)
                p[4] = 1;
            else
                p[4] = 2;
            break;
        case 2:
            p[4] = 2;
            break;
        }
    } else if (func_0216D454(h) == 1) {
        switch (m) {
        case 0:
            break;
        case 1:
            if (old == 0)
                break;
            if (old == 3)
                p[4] = 0;
            else
                p[4] = 3;
            break;
        case 2:
            if (old == 0)
                break;
            if (old == 3)
                p[4] = 0;
            else
                p[4] = 3;
            break;
        }
    }
}


/*
 * Tail-call thunk: the object's word at +0x1c.
 *
 * Addresses are Black-image addresses.
 */
void func_021A3898(u8 *p, struct VecFx32 *out)
{
    func_0216D88C((const struct Actor *)((struct Obj18032 *)p)->f1C, out);
}


void func_021A38A4(u8 *p, Vec021A38A4 *v)
{
    int x = (v->x >> 4) / 4096;
    int y = (v->y >> 4) / 4096;
    int z = (v->z >> 4) / 4096;
    u32 h = ((struct Obj19775 *)p)->f1C;

    func_0216D80C((void *)h, func_0216D83C(h));
    func_0216D818((void *)h, func_0216D854(h));
    func_0216D824((void *)h, func_0216D86C(h));
    func_0216D844((void *)h, (short)x);
    func_0216D85C((void *)h, (short)y);
    func_0216D874(h, (short)z);
    func_0216D89C(h, v);
}
