/*
 * file:     field_player_grid_event_p20.c
 * unit:     yes
 * function: func_021C1228, func_021C12C4, func_021C12D0, func_021C12E4
 * address:  0x021C1228
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
 *   func_02030734  0x02030734  arm
 *   d_021DE3AC     0x021DE3AC  data  ov021  a4
 *   func_021A3068  0x021A3068  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02164208  0x02164208  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_021A36E0  0x021A36E0  thumb  ov021
 *   func_02188D30  0x02188D30  thumb  ov021
 *   func_02030DA8  0x02030DA8  arm
 *   func_021C1988  0x021C1988  thumb  ov021
 *   func_02030EE8  0x02030EE8  arm
 *   func_0216D8E0  0x0216D8E0  thumb  ov010
 */
#include "../../matched/include/Obj03610.h"
#include "../../matched/include/Obj18276.h"

struct Actor;
struct VecFx32;
struct S02030EE8;
struct Node;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec3;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { int x, y, z; } V3;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_021A3068(u8 *p);
extern void *func_021A3074(unsigned char *p);
extern u32 func_021A36E0(u8 *p);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern void func_02164208(int dir, int *p, int amt);
extern void func_02163E58(void *a, Vec3 *v, int *out);
extern u32 func_02188D30(u8 *p);
extern void func_02030DA8(u32, void (*)(), u8 *, u32);
extern void func_021C1988(void *a, u16 *s);
extern u32 func_02030EE8(struct S02030EE8 *p);
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
extern void func_0216D8E0(u32 a, V3 *v);
void func_021C1228(u32 a, u16 b, u32 c, u32 d);
int func_021C12C4(void *a);
void func_021C12D0(void *h);
void func_021C12E4(u32 a, const V3 *v);
extern u8 d_021DE3AC;


/*
 * Addresses are Black-image addresses.
 */
void func_021C1228(u32 a, u16 b, u32 c, u32 d)
{
    u8 *r;
    void *r7;
    Vec3 va;
    Vec3 vb;
    int out;

    r = func_02030734((u16)(0x8000 | (d & 0x7fff)), 0x4c, 1, (const char *)&d_021DE3AC, 0x2b3);
    ((struct Obj03610 *)r)->f4 = b;
    ((struct Obj03610 *)r)->f3C = a;
    ((struct Obj03610 *)r)->f40 = func_021A3068((u8 *)a);
    r7 = func_021A3074((void *)a);
    func_0216D88C(r7, (struct VecFx32 *)&va);
    vb = va;
    func_02164208(((struct Obj03610 *)r)->f4, (int *)(&vb), 0x20000);
    func_02163E58(r7, &vb, &out);
    if (out > va.y)
        ((struct Obj03610 *)r)->f0 = 1;
    ((struct Obj03610 *)r)->f44 = func_021A36E0((u8 *)(((struct Obj03610 *)r)->f3C));
    func_02030DA8(func_02188D30((u8 *)(((struct Obj03610 *)r)->f40)), func_021C1988, r, 0);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C12C4(void *a)
{
return ((struct Obj18276 *)((u8 *)(func_02030EE8((struct S02030EE8 *)a))))->f6;
}


void func_021C12D0(void *h)
{
    func_020307B0((void *)func_02030EE8(h));
    func_02030EAC(h);
}


/*
 * Offsets a position by (0, 1.0, 5.0) fx32 and applies it.
 */
void func_021C12E4(u32 a, const V3 *v)
{
    V3 t = *v;

    t.y += 0x1000;
    t.z += 0x5000;
    func_0216D8E0(a, &t);
}
