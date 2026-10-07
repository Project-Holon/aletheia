/*
 * file:     field_effect_p58.c
 * unit:     yes
 * function: func_021AC578, func_021AC62C
 * address:  0x021AC578
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
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D538  0x0216D538  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   _ll_mul        0x0209C054  arm
 *   tbl_020A1B38   0x020A1B38  data  a2
 *   d_021D90AC     0x021D90AC  data  a4
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021C6590  0x021C6590  thumb  ov021
 */
#include "../../matched/include/Obj05038.h"

struct Actor;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef int            s32;

typedef struct Vec3 { s32 x, y, z; } Vec3;

typedef struct Arg { u32 a; Vec3 v; } Arg;

extern void *func_0216D67C(void *a0);
extern u32 func_0216D538(u8 *p);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *v);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(u32 a, u8 *b, u32 c, u32 d, Arg *e, u32 f);
extern int func_021AC1AC(u32 a);
extern u32 func_021ABE18(u8 *p);
extern void func_021AC1CC(u32 a, u32 *b);
extern u32 func_021C6590(u32 a, u32 b, u32 c, u32 *d);
void func_021AC578(u32 a, u32 b);
void func_021AC62C(u32 a, u32 *b);
extern s16 tbl_020A1B38[];
extern u8 d_021D90AC[];


/*
 * Addresses are Black-image addresses.
 */
void func_021AC578(u32 a, u32 b)
{
    Vec3 v;
    Arg s;
    int i;
    i = func_0216D538(func_0216D67C((void *)a));
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&v);
    v.y += 0x1000;
    i = (i >> 4) * 2;
    v.z += (s32)(((long long)tbl_020A1B38[i + 1] * 0x6000 + 0x800) >> 12);
    v.x += (s32)(((long long)tbl_020A1B38[i] * 0x6000 + 0x800) >> 12);
    s.a = func_021ABEA0(b, 1);
    s.v = v;
    func_021ABFA8(b, d_021D90AC, 0, 0, &s, 0);
}


void func_021AC62C(u32 a, u32 *b)
{
    u32 *p = (u32 *)func_021AC1AC(a);
    b[0] = p[0];
    b[1] = func_021ABE18((u8 *)(*(u32 *)b[0]));
    func_021AC1CC(a, p + 1);
    ((struct Obj05038 *)b)->f8 = func_021C6590(b[1], *(u16 *)(b[0] + 4), 0, p + 1);
}
