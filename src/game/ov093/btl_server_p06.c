/*
 * file:     btl_server_p06.c
 * unit:     yes
 * function: func_021B9E38, func_021B9E7C
 * address:  0x021B9E38
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0200846C  0x0200846C  thumb
 *   func_02008494  0x02008494  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008510  0x02008510  thumb
 *   func_0202428C  0x0202428C  thumb
 *   func_02045874  0x02045874  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02024570  0x02024570  thumb
 */
#include "../../matched/include/Obj01371.h"

struct Sub0200852CObj;
struct U16Vec;
struct Rec8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct H {
    u16 a, b, c, d;
};

struct A {
    int vt;
    int q;
    u16 h8;
    u16 ha;
    int c;
    u16 h[4];
    struct H s18;
    struct H s20;
};

struct B {
    int f0;
    int f4;
    int f8;
    char b[8];
    int f14;
    struct H s18;
    struct H s20;
};

extern void *func_0200846C(int a);
extern void func_02008494(void *src, void *dst);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_02008510(void *a, int tag);
extern void func_0202428C(void *a);
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
extern void func_02082D44(void *, void *, int);
extern void func_02024570(struct Rec8 *dst, const struct Rec8 *src);
void func_021B9E38(char *p, int a, int b);
void func_021B9E7C(struct A *p, struct B *src);


void func_021B9E38(char *p, int a, int b)
{
    u16 f;

    void *h = func_0200846C(a);

    ((struct Obj01371 *)p)->f0 = h;
    func_02008494((void *)b, h);
    f = 0;
    ((struct Obj01371 *)p)->fA = 0;
    if (func_02008550(((struct Obj01371 *)p)->f0))
        f = 1;
    ((struct Obj01371 *)p)->f8 = f;
    ((struct Obj01371 *)p)->f4 = (int)func_02008510(((struct Obj01371 *)p)->f0, 0x12);
    func_0202428C(p + 0x18);
    func_0202428C(p + 0x20);
}


void func_021B9E7C(struct A *p, struct B *src)
{
    unsigned int i;

    p->vt = 0;
    if (src) {
        p->ha = src->f0;
        p->h8 = src->f4;
        p->q = (int)func_02045874((struct U16Vec *)src->f14, 0x12);
        p->c = src->f8;
        func_02082D44(src->b, p->h, 8);
        func_02024570((struct Rec8 *)(&p->s18), (const struct Rec8 *)(&src->s18));
        func_02024570((struct Rec8 *)(&p->s20), (const struct Rec8 *)(&src->s20));
    } else {
        p->ha = 0;
        p->h8 = 0;
        p->q = 0;
        for (i = 0; i < 4; i++) {
            p->h[i] = 0;
        }
        func_0202428C(&p->s18);
        func_0202428C(&p->s20);
    }
}
