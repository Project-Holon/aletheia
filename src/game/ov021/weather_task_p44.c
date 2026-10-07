/*
 * file:     weather_task_p44.c
 * unit:     yes
 * function: func_021A408C, func_021A40A8, func_021A4114
 * address:  0x021A408C
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
 *   func_021A3D50  0x021A3D50  thumb  ov021
 *   func_021A3D6C  0x021A3D6C  thumb  ov021
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_02164240  0x02164240  thumb  ov010
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_0219F5C8  0x0219F5C8  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02029D8C  0x02029D8C  thumb
 */
#include "../../matched/include/Obj09563.h"

struct Ctx;
struct BigObj;
typedef unsigned char u8;

typedef struct {
    u8 pad[0x30];
    short step;
} Obj021A408C;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed short   s16;

int func_021A3D50(u32 a, u32 b);
extern void func_021A3D6C(u8 *, int);
extern u32 func_021A3974(u8 *p);
extern void *func_021A3960(u8 *p);
extern void *func_0216D67C(void *a0);
extern int func_0216D83C(void *);
extern int func_0216D86C(void *);
extern void func_02164240(int dir, s16 *x, s16 *z, s16 amt);
extern void *func_0216DDC0(u32 a, u32 b, u32 c, u32 d);
extern void func_0219F5C8(void *, int);
void *func_02188C80(void *p);
void *func_020120F4(const struct Ctx *p);
u32 func_02012A30(const struct BigObj *x);
u16 func_02188C9C(u8 *p);
void func_02029D8C(u32 a0, u32 a1, u32 a2);
int func_021A408C(Obj021A408C *p);
int func_021A40A8(u8 *p);
void func_021A4114(u32 *p);


int func_021A408C(Obj021A408C *p)
{
    if (func_021A3D50((u32)p, 8) != 1)
        p->step++;
    return 0;
}


int func_021A40A8(u8 *p)
{
    s16 v[2];
    int f;
    void *a;
    u32 b;

    func_021A3D6C(p, 8);
    if (((struct Obj09563 *)p)->f32 == 1 && func_021A3974(p) == 2) {
        f = 0;
        a = func_021A3960(p);
        b = (u32)func_0216D67C(a);
        v[1] = func_0216D83C(a);
        v[0] = func_0216D86C(a);
        func_02164240(1, &v[1], &v[0], 1);
        if (func_0216DDC0(b, v[1], v[0], 1) != 0) {
            f = 1;
        }
        func_0219F5C8(a, f);
    }
    return 0;
}


void func_021A4114(u32 *p)
{
    int a = (int)func_020120F4(func_02188C80((void *)p[2]));
    int b = func_02012A30((const struct BigObj *)a);

    func_02029D8C(b, a, (u16)(int)func_02188C9C((u8 *)p[2]));
}
