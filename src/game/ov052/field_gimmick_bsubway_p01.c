/*
 * file:     field_gimmick_bsubway_p01.c
 * unit:     yes
 * function: func_021F36C0, func_021F3724
 * address:  0x021F36C0
 * region:   ov052
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_021F3998  0x021F3998  thumb  ov052
 *   func_0200B3A4  0x0200B3A4  thumb
 *   d_021F3A2C     0x021F3A2C  data  a4
 */
#include "../../matched/include/Obj05135.h"
#include "../../matched/include/G_021F3A2C.h"

struct Big;
struct Ctx;
struct Rec94;
typedef unsigned short u16;

typedef unsigned char  u8;

typedef signed int     s32;

typedef unsigned int   u32;

extern u16 func_02188C84(u8 *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern u16 func_02188C9C(u8 *p);
extern void func_021F3998(int, int *, int *);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
void func_021F36C0(void *a);
void func_021F3724(void *a);
extern struct G_021F3A2C d_021F3A2C[];


void func_021F36C0(void *a)
{
    int s1;
    int s0;
    int r4;
    int r6;
    int r7;
    unsigned h;
    char *p;
    void (*f)(void *, void *);

    r4 = func_02188C84(a);
    r6 = (int)func_02188C80(a);
    h = (unsigned int)func_02012EC4(func_020120F4((const struct Ctx *)r6));
    r7 = func_02188C9C(a);
    func_021F3998(r7, &s0, &s1);
    p = (char *)func_0200B3A4((struct Rec94 *)h, s0);
    ((struct Obj05135 *)p)->f2 = s1;
    ((struct Obj05135 *)p)->f4 = s0;
    ((struct Obj05135 *)p)->f8 = r7;
    ((struct Obj05135 *)p)->fC = r4;
    ((struct Obj05135 *)p)->f1C = r6;
    ((struct Obj05135 *)p)->f20 = a;
    f = d_021F3A2C[*(unsigned short *)(p + 2)].f0;
    if (f)
        f(p, a);
}


void func_021F3724(void *a)
{
    int s1;
    int s0;
    unsigned h;
    unsigned short *p;
    void (*f)(void *, void *);

    func_02188C84(a);
    h = (unsigned int)func_02012EC4(func_020120F4(func_02188C80(a)));
    func_021F3998(func_02188C9C(a), &s0, &s1);
    p = (short unsigned int *)func_0200B3A4((struct Rec94 *)h, s0);
    f = d_021F3A2C[p[1]].f1;
    if (f)
        f(p, a);
}
