/*
 * file:     unit_021F36C0_p02.c
 * unit:     yes
 * function: func_021F3A08, func_021F3A88
 * address:  0x021F3A08
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F4694 0x021F4694 data a4
 *   func_0201210C 0x0201210C thumb
 *   func_021897BC 0x021897BC thumb
 *   func_02188CB4 0x02188CB4 thumb
 *   func_02188C80 0x02188C80 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_021A3050 0x021A3050 thumb ov021
 *   func_020122C0 0x020122C0 thumb
 *   func_021F3B3C 0x021F3B3C thumb ov038
 *   func_021F407C 0x021F407C thumb ov038
 *   func_021F3F40 0x021F3F40 thumb ov038
 */
#include "../../matched/include/G_S3A08.h"
#include "../../matched/include/Obj04317.h"

struct Ctx;
struct Big;
struct Desc;
struct Rec94;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed int     s32;

extern void *func_0201210C(const struct Ctx *p);
extern unsigned char *func_021897BC(void *, int);
extern void *func_02188CB4(unsigned char *p);
extern int func_02188C80(void *);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern u16 func_021A3050(u8 *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F3B3C(int a0, int *a1);
extern int func_021F407C(int a0, int *a1);
extern int func_021F3F40(int a0, int *a1);
int func_021F3A08(int *base, int x, int y, int *o1, int *o2);
int func_021F3A88(int a0, int a1, int a2);
extern struct S3A08 d_021F4694[];


int func_021F3A08(int *base, int x, int y, int *o1, int *o2)
{
    int f;
    int ax;
    int bz;
    int i;
    struct S3A08 *e;

    for (i = 0; i < 7; i++) {
        e = &d_021F4694[i];
        ax = e->a / 0x10000;
        bz = e->c / 0x10000;
        f = 0;
        if (ax == x && bz == y) {
            *o2 = 1;
            f = 1;
        } else if (ax - 1 == x && bz == y) {
            *o2 = 0;
            f = 1;
        } else if (ax + 1 == x && bz == y) {
            *o2 = 0;
            f = 1;
        }
        if (f != 0) {
            *o1 = *(int *)((char *)base + i * 4 + 0x48);
            return i;
        }
    }
    *o2 = 0;
    *o1 = 0;
    return 7;
}


int func_021F3A88(int a0, int a1, int a2)
{
    int o1;
    int o2;
    int r6; /* int-typed on purpose: pointer local changes codegen */
    int r7;
    unsigned char *r4;

    r6 = (int)func_0201210C((void *)a0);
    r4 = func_021897BC((void *)r6, 1);
    r6 = (int)func_02188CB4((void *)r6);
    r7 = (int)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((const struct Ctx *)func_02188C80(func_0201210C((void *)a0)))), 6);
    r6 = func_021A3050((u8 *)r6);
    if (r6 != 0 && r6 != 1)
        return 0;
    r7 = func_021F3A08((int *)r7, a1, a2, &o1, &o2);
    if (r7 < 7) {
        if (o2 != 0) {
            if (o1 == 1)
                func_020122C0((void *)a0, 0, func_021F3B3C, 0);
            else
                func_020122C0((void *)a0, 0, func_021F407C, 0);
        } else {
            func_020122C0((void *)a0, 0, func_021F3F40, 0);
        }
    } else {
        return 0;
    }
    r4[5] = 0;
    r4[7] = 0;
    r4[6] = r6;
    r4[3] = r7;
    ((struct Obj04317 *)r4)->f14 = 0;
    ((struct Obj04317 *)r4)->f18 = 0;
    ((struct Obj04317 *)r4)->f1C = 0;
}
