/*
 * file:     unit_021B7560_p08.c
 * unit:     yes
 * function: func_021B87FC, func_021B8810
 * address:  0x021B87FC
 * region:   ov102
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B8A40  0x021B8A40  thumb  ov102
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204B878  0x0204B878  arm
 *   func_021B88F8  0x021B88F8  thumb  ov102
 *   func_0204B404  0x0204B404  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_02005728  0x02005728  thumb
 *   func_0204B8C4  0x0204B8C4  arm
 */
#include "../../matched/include/Obj04424.h"

struct Obj;
struct Vec2;
typedef unsigned short u16;

typedef unsigned int u32;

extern void func_021B8A40(int *p, int a, int b, int n);
extern void func_02082BCC(int a, int b, int c);
extern void func_0204B878(int p, int a);
extern void func_021B88F8(int *p);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B3DC(struct Obj *p, unsigned int a);
extern u32 func_02005728(u32 range);
extern void func_0204B8C4(struct Obj *p, u32 value);
void func_021B87FC(int *p);
void func_021B8810(int a0, int b, int c, int a3);


void func_021B87FC(int *p)
{
    p[6] = 1;
    func_021B8A40(p, 0, 0x58, 0x78);
}


void func_021B8810(int a0, int b, int c, int a3)
{
    u16 tmp[2];

    func_02082BCC(a0, 0, 0x1c);
    ((struct Obj04424 *)a0)->f18 = b;
    func_0204B878(((struct Obj04424 *)a0)->f18, c != 0 ? 0xd : 0xc);
    func_021B88F8((int *)a0);
    tmp[0] = (u16)((struct Obj04424 *)a0)->f8;
    tmp[1] = (u16)((struct Obj04424 *)a0)->fC;
    func_0204B404((struct Obj *)(((struct Obj04424 *)a0)->f18), (const struct Vec2 *)tmp, 1);
    func_0204B3DC((struct Obj *)((struct Obj04424 *)a0)->f18, 1);
    func_0204B8C4((struct Obj *)(((struct Obj04424 *)a0)->f18), func_02005728(0x2000));
}
