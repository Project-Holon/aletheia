/*
 * file:     unit_021BA81C_p08.c
 * unit:     yes
 * function: func_021BB42C, func_021BB460
 * address:  0x021BB42C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_0204B3B4  0x0204B3B4  arm
 *   sub_0204A8D4  0x0204A8D4  arm
 *   sub_0204ADA4  0x0204ADA4  arm
 *   sub_0204AFD8  0x0204AFD8  arm
 *   d_021C388C     0x021C388C  data   ov099  a4
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B62E0  0x021B62E0  thumb  ov067
 *   func_021B6578  0x021B6578  thumb  ov067
 */
#include "../../matched/include/Obj07942.h"

struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021BB42C;

typedef signed short   s16;

typedef int BOOL;

typedef struct {
    char pad[0x180];
    void *f180;
    void *f184;
    void *f188;
    void *f18C;
} S;

typedef unsigned int u32_021BB460;

typedef struct {
    int v[8];
} T8;

typedef struct {
    void *f0;
    u32_021BB460 f4;
    int f8;
    u32_021BB460 fC;
    u32_021BB460 f10;
    u32_021BB460 f14;
    int f18;
    int f1c;
} A;

extern void sub_0204B3B4(struct Obj *p);
extern void sub_0204A8D4(u32_021BB42C i);
extern void sub_0204ADA4(u32_021BB42C i);
extern void sub_0204AFD8(u32_021BB42C i);
extern void func_02082BCC(void *p, u32_021BB460 v, u32_021BB460 n);
extern void *func_021B62E0(A *a, int heap);
extern void func_021B6578(unsigned char *p, unsigned int id, int v);
void func_021BB42C(S *s);
void func_021BB460(char *p, int x);
extern const T8 d_021C388C;


void func_021BB42C(S *s)
{
    if (s->f180 != 0) {
        sub_0204B3B4(s->f180);
        sub_0204A8D4((u32_021BB42C)s->f184);
        sub_0204ADA4((u32_021BB42C)s->f188);
        sub_0204AFD8((u32_021BB42C)s->f18C);
        s->f180 = 0;
    }
}


void func_021BB460(char *p, int x)
{
    T8 t;
    A a;
    void *r;

    t = d_021C388C;
    if (((struct Obj07942 *)p)->f9AC == 0) {
        func_02082BCC(&a, 0, 0x20);
        a.f0 = &t;
        a.f4 = 1;
        a.f8 = ((struct Obj07942 *)p)->f110;
        a.f1c = 0;
        a.fC = 4;
        a.f10 = 0xC;
        a.f14 = 0xC;
        a.f18 = 2;
        r = func_021B62E0(&a, x);
        ((struct Obj07942 *)p)->f9AC = r;
        func_021B6578(r, 1, 0);
    }
}
