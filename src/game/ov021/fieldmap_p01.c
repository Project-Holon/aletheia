/*
 * file:     fieldmap_p01.c
 * unit:     yes
 * function: func_02187F00, func_02187FD0, func_02187FE8
 * address:  0x02187F00
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
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02189BBC  0x02189BBC  thumb
 *   func_0203064C  0x0203064C  arm
 *   func_02030678  0x02030678  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02188030  0x02188030  thumb
 *   func_02012110  0x02012110  thumb
 *   func_0201214C  0x0201214C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   d_021DE700     0x021DE700  data
 *   func_02188B58  0x02188B58  thumb  ov021
 *   func_021880A4  0x021880A4  thumb  ov021
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 */
#include "../../matched/include/Obj17856.h"

struct Ctx;
struct Rec44;
struct Obj0203159C;
struct Comm;
struct S020315D4;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

unsigned char *func_020120F8(const struct Ctx *x);
unsigned short func_02012AC8(const struct Rec44 *x);
int func_02189BBC(int x);
void func_0203064C(unsigned int src, unsigned int dst, unsigned int size);
void func_02030678(void *a, u32 b, u32 c);
void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
void *func_02188030(int a, int b);
void func_02012110(struct Ctx *p, void *v);
unsigned int func_0201214C(const struct Ctx *x);
unsigned int func_02012138(const struct Ctx *x);
u32 func_02026454(void *obj);
void func_02026400(struct Comm *p);
extern u32 func_02188B58(void *a, u8 *b, u32 a2, u32 a3);
void func_021880A4(int *p);
void func_020315D4(struct S020315D4 *p);
void func_020306F0(unsigned int heap);
int func_02187F00(struct Obj0203159C *a, int *state, int b);
int func_02187FD0(u32 a, u32 b, u32 c, u32 d);
int func_02187FE8(int a, int unused, int b, int *c);
extern char d_021DE700[];


int func_02187F00(struct Obj0203159C *a, int *state, int b)
{
    switch (*state) {
    case 0:
        {
            int sz = func_02189BBC(func_02012AC8((const struct Rec44 *)func_020120F8((const struct Ctx *)b))) - 0xD000;
            func_0203064C(1, 0x15, sz);
        }
        func_0203064C(1, 0x70, 0xD000);
        func_0203064C(0x15, 0x50, 0xC000);
        func_02030678(d_021DE700, 0x10000, 0x89);
        func_0203064C(0x89, 0x92, 0x6400);
        func_0203064C(0x89, 0x93, 0x7400);
        func_0203064C(0x89, 0x96, 0x500);
        {
            void **w = (void **)func_0203159C(a, 4, 0x15);
            void *p = func_02188030(b, 0x15);
            *w = p;
            func_02012110((void *)b, p);
        }
        (*state)++;
        break;
    case 1:
        if (func_0201214C((const struct Ctx *)b) == 0) {
            int t = func_02012138((const struct Ctx *)b);
            switch (func_02026454((void *)t)) {
            case 1:
            case 2:
                func_02026400((struct Comm *)t);
                break;
            }
        }
        return 1;
    }
    return 0;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02187FD0(u32 a, u32 b, u32 c, u32 d)
{
if (func_02188B58((void *)c, (u8 *)(((struct Obj17856 *)((u8 *)(d)))->f0), c, d) == 1) {
    return 1;
}
return 0;
}


int func_02187FE8(int a, int unused, int b, int *c)
{
    func_021880A4((int *)(*c));
    func_02012110((void *)b, 0);
    func_020315D4((struct S020315D4 *)a);
    func_020306F0(0x96);
    func_020306F0(0x92);
    func_020306F0(0x93);
    func_020306F0(0x89);
    func_020306F0(0x50);
    func_020306F0(0x70);
    func_020306F0(0x15);
    return 1;
}
