/*
 * file:     weather_task_p43.c
 * unit:     yes
 * function: func_021A3E14, func_021A3E48, func_021A3E54, func_021A3EE0, func_021A3F10, func_021A3F48, func_021A3F64, func_021A3F70, func_021A3F8C, func_021A3F98, func_021A3FB4, func_021A3FC0, func_021A3FDC, func_021A3FE8
 * address:  0x021A3E14
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
 *   func_021A398C  0x021A398C  thumb  ov021
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021A3980  0x021A3980  thumb  ov021
 *   func_021A4114  0x021A4114  thumb  ov021
 *   func_021A3D50  0x021A3D50  thumb  ov021
 *   func_021A3D6C  0x021A3D6C  thumb
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_021A3AD8  0x021A3AD8  thumb  ov021
 *   func_021A3190  0x021A3190  thumb  ov021
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A3AD4  0x021A3AD4  thumb  ov021
 *   func_021A3AD0  0x021A3AD0  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021ACB38  0x021ACB38  thumb  ov021
 *   func_021A31A4  0x021A31A4  thumb  ov021
 *   func_021A3D08  0x021A3D08  thumb  ov021
 *   func_021A3B94  0x021A3B94  thumb  ov021
 *   func_021D05D8  0x021D05D8  thumb  ov021
 *   func_021ACBC8  0x021ACBC8  thumb  ov021
 */
#include "../../matched/include/Obj12732.h"
#include "../../matched/include/Obj05025.h"

struct Actor;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u8 pad[0x24];
    u32 mask;
    u8 pad28[4];
    u16 timer;
    u16 count;
    short step;
    u16 done;
} Obj021A3E14;

typedef int BOOL;

typedef struct {
    u8 pad[0x24];
    u32 mask;
    u8 pad28[4];
    u16 timer;
    u16 count;
    short step;
    u16 done;
} Obj021A3EE0;

typedef struct {
    u8 pad[0x24];
    u32 mask;
    u8 pad28[4];
    u16 timer;
    u16 count;
    short step;
    u16 done;
} Obj021A3F10;

typedef struct {
    u8 pad[0x30];
    short step;
} Obj021A3F48;

typedef struct {
    u8 pad[0x30];
    short step;
} Obj021A3F70;

typedef struct {
    u8 pad[0x30];
    short step;
} Obj021A3F98;

typedef struct {
    u8 pad[0x30];
    short step;
} Obj021A3FC0;

u32 func_021A398C(u8 *p);
void *func_021A3960(u8 *p);
void func_021A3980(u8 *p, u32 a1);
void func_021A4114(u32 *p);
int func_021A3D50(u32 a, u32 b);
extern void func_021A3D6C(u32 a1, u32 a2);
extern u16 func_0216D598(void *p);
extern void func_021A3AD8(u8 *p, int a);
extern u16 func_021A3190(int, int);
extern u32 func_021A3974(u8 *p);
extern u32 func_021A3AD4(u8 *);
extern void func_021A3AD0(u8 *, u32);
extern u32 func_02188CD0(u8 *p);
extern u16 func_0216D5F8(void *p);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern u32 func_021ACB38(u32, u32, u32 *, void *, int);
int func_021A31A4(int i, int v);
int func_021A3D08(u8 *p, u32 v);
int func_021A3B94(u32 *p);
extern void func_021D05D8(void *a, void *b);
extern void func_021ACBC8(u32, int);
int func_021A3E14(Obj021A3E14 *p);
u32 func_021A3E48(u32 a1);
int func_021A3E54(u8 *p);
int func_021A3EE0(Obj021A3EE0 *p);
int func_021A3F10(Obj021A3F10 *p);
int func_021A3F48(Obj021A3F48 *p);
u32 func_021A3F64(u32 a1);
int func_021A3F70(Obj021A3F70 *p);
u32 func_021A3F8C(u32 a1);
int func_021A3F98(Obj021A3F98 *p);
u32 func_021A3FB4(u32 a1);
int func_021A3FC0(Obj021A3FC0 *p);
u32 func_021A3FDC(u32 a1);
int func_021A3FE8(u8 *p);


int func_021A3E14(Obj021A3E14 *p)
{
    func_021A398C((u8 *)p);
    func_021A3960((u8 *)p);
    func_021A3980((u8 *)p, 1);
    func_021A4114((u32 *)p);
    if (func_021A3D50((u32)p, 1) != 1)
        p->step++;
    return 0;
}


/*
 * Calls func_021A3D6C(its own argument 1, 0x1) and returns 0x0.
 */
u32 func_021A3E48(u32 a1)
{
    func_021A3D6C(a1, 0x1);

    return 0x0;
}


int func_021A3E54(u8 *p)
{
    u32 buf[3];
    u32 a;
    void *b;
    u32 c;
    u32 d;

    a = func_021A398C(p);
    b = func_021A3960(p);
    a = func_021A3190(a, 2);
    if (a != func_0216D598(b)) {
        func_021A3AD8(p, a);
    }
    if (func_021A3974(p) != 2) {
        func_021A3980(p, 2);
    }
    func_021A4114((u32 *)p);
    if (func_021A3AD4(p) == 0) {
        c = func_02188CD0((u8 *)(((struct Obj12732 *)p)->f8));
        d = func_0216D5F8(b);
        func_0216D88C(b, (struct VecFx32 *)buf);
        func_021A3AD0(p, func_021ACB38(c, d, buf, b, 1));
    }
    ((struct Obj12732 *)p)->f32 = 1;
    return 0;
}


int func_021A3EE0(Obj021A3EE0 *p)
{
    int a = func_021A3974((u8 *)p);

    if (func_021A3D08((u8 *)p, func_021A31A4(func_021A398C((u8 *)p), a)) != 1)
        p->step++;
    return 0;
}


int func_021A3F10(Obj021A3F10 *p)
{
    int a;

    if (func_021A3B94((u32 *)p) == 1) {
        p->count++;
        a = func_021A3974((u8 *)p);
        func_021A3AD8((u8 *)p, func_021A31A4(func_021A398C((u8 *)p), a));
        p->done = 1;
    }
    return 0;
}


int func_021A3F48(Obj021A3F48 *p)
{
    if (func_021A3D50((u32)p, 4) != 1)
        p->step++;
    return 0;
}


/*
 * Calls func_021A3D6C(its own argument 1, 0x4) and returns 0x0.
 */
u32 func_021A3F64(u32 a1)
{
    func_021A3D6C(a1, 0x4);

    return 0x0;
}


int func_021A3F70(Obj021A3F70 *p)
{
    if (func_021A3D50((u32)p, 5) != 1)
        p->step++;
    return 0;
}


/*
 * Calls func_021A3D6C(its own argument 1, 0x5) and returns 0x0.
 */
u32 func_021A3F8C(u32 a1)
{
    func_021A3D6C(a1, 0x5);

    return 0x0;
}


int func_021A3F98(Obj021A3F98 *p)
{
    if (func_021A3D50((u32)p, 6) != 1)
        p->step++;
    return 0;
}


/*
 * Calls func_021A3D6C(its own argument 1, 0x6) and returns 0x0.
 */
u32 func_021A3FB4(u32 a1)
{
    func_021A3D6C(a1, 0x6);

    return 0x0;
}


int func_021A3FC0(Obj021A3FC0 *p)
{
    if (func_021A3D50((u32)p, 9) != 1)
        p->step++;
    return 0;
}


/*
 * Calls func_021A3D6C(its own argument 1, 0x9) and returns 0x0.
 */
u32 func_021A3FDC(u32 a1)
{
    func_021A3D6C(a1, 0x9);

    return 0x0;
}


int func_021A3FE8(u8 *p)
{
    u32 buf[3];
    u32 a;
    void *b;
    u32 c;
    u32 d;
    u32 e;

    e = func_02188CD0((u8 *)(((struct Obj05025 *)p)->f8));
    a = func_021A398C(p);
    b = func_021A3960(p);
    a = func_021A3190(a, 3);
    if (a != func_0216D598(b)) {
        func_021A3AD8(p, a);
    }
    if (func_021A3974(p) != 3) {
        func_021A3980(p, 3);
    }
    if (func_021A3AD4(p) == 0) {
        c = func_02188CD0((u8 *)(((struct Obj05025 *)p)->f8));
        d = func_0216D5F8(b);
        func_0216D88C(b, (struct VecFx32 *)buf);
        func_021A3AD0(p, func_021ACB38(c, d, buf, b, 1));
    }
    func_021D05D8((void *)(((struct Obj05025 *)p)->f1C), (void *)e);
    if (((struct Obj05025 *)p)->f28 != 0) {
        func_021ACBC8(((struct Obj05025 *)p)->f28, 0);
    }
    ((struct Obj05025 *)p)->f32 = 1;
    return 0;
}
