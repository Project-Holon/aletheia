/*
 * file:     field_place_name_p22.c
 * unit:     yes
 * function: func_021BD96C, func_021BD988, func_021BD9BC, func_021BDA30, func_021BDA70, func_021BDAA8
 * address:  0x021BD96C
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
 *   func_02012374  0x02012374  thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   d_021D9BC8     0x021D9BC8  data  ov021  a4
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021BDBF8  0x021BDBF8  thumb  ov021
 *   func_021BDC2C  0x021BDC2C  thumb  ov021
 *   func_021BDC80  0x021BDC80  thumb  ov021
 *   func_021A7B20  0x021A7B20  thumb  ov021
 *   func_021BDC0C  0x021BDC0C  thumb  ov021
 *   func_021618E0  0x021618E0  thumb  ov010
 */
#include "../../matched/include/Obj20137.h"
#include "../../matched/include/Obj07540.h"

struct Evt;
struct Desc;
struct Obj;
struct Args;
typedef struct {
    char pad[4];
    void *f4;
    char pad2[0x44];
    int f4C;
} Inner;

typedef struct {
    char pad[8];
    Inner *f8;
} Obj_021BD96C;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct {
    int f0;
    void *f4;
    int f8;
    int fC;
    char pad10[0x28];
    int f38;
    int f3C;
    int f40;
} Sub;

typedef struct {
    int f0;
    int f4;
    Sub *f8;
} Obj_021BD988;

typedef unsigned short u16;

typedef struct { u32 v[6]; } T6;

extern u8 *func_0202952C(u8 *p, u32 a);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern struct Desc *func_020122C0(void *, void *, void *, u32);
extern void *func_020124E8(struct Obj *);
extern int func_021BDBF8(u32 a);
extern void func_021BDC2C(u32 *, u32);
extern void func_021BDC80(u32 *);
extern void *func_021A7B20(struct Args *a);
extern void func_021BDC0C(u32 *, u32);
extern void *func_021618E0(void *a, void *b);
void func_021BD96C(Obj_021BD96C *p, void *b);
void func_021BD988(Obj_021BD988 *o, int b);
int func_021BD9BC(u32 *p);
u32 func_021BDA30(u32 a, int *st, u32 *ctx);
u32 func_021BDA70(u32 a, u32 *st, u32 *p);
u32 func_021BDAA8(u32 a, int *st, u32 *ctx);
extern const T6 d_021D9BC8;


void func_021BD96C(Obj_021BD96C *p, void *b)
{
    Inner *q = p->f8;

    func_02012374(b, (struct Evt **)func_0202952C(q->f4, 0x1E));
    q->f4C = 1;
}


void func_021BD988(Obj_021BD988 *o, int b)
{
    Sub *s = o->f8;
    int sel = s->f40;
    void *p = s->f4;
    int c = s->fC;

    if (sel != 0) {
        func_02012374((struct Evt *)b, (struct Evt **)func_021BE8D4(p, c, 0, 0));
    } else {
        func_02012374((struct Evt *)b, (struct Evt **)func_021BE8D4(p, c, s->f38, 0));
    }
}


/*
 * Addresses are Black-image addresses.
 */
int func_021BD9BC(u32 *p)
{
    T6 t = d_021D9BC8;
    u32 i;
    u32 r;

    switch (p[5]) {
    case 0:
        i = 0;
        break;
    case 1:
        i = 0;
        break;
    case 2:
        i = 2;
        break;
    case 3:
        i = 1;
        break;
    case 4:
        i = 2;
        break;
    case 5:
        i = 3;
        break;
    case 6:
        i = 5;
        break;
    default:
        i = 4;
        break;
    }
    r = (u32)func_020122C0((void *)p[1], (void *)p[0], (void *)t.v[i], 4);
    *(u32 *)func_020124E8((struct Obj *)r) = (u32)p;
    return r;
}


u32 func_021BDA30(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[0];

    switch (*st) {
    case 0:
        if (((struct Obj20137 *)p)->f48 != 0)
            func_021BDBF8((u32)ctx);
        func_021BDC2C(ctx, a);
        (*st)++;
        break;
    case 1:
        func_021BDC80(ctx);
        return 1;
    }
    return 0;
}

u32 func_021BDA70(u32 a, u32 *st, u32 *p)
{
    u32 v = p[0];
    switch (st[0]) {
    case 0:
        func_02012374((struct Evt *)a, func_021A7B20((struct Args *)v));
        st[0]++;
        break;
    case 1:
        func_021BDC80(p);
        return 1;
    }
    return 0;
}


u32 func_021BDAA8(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[0];
    u32 x = ((struct Obj07540 *)p)->f4;
    u32 y = ((struct Obj07540 *)p)->fC;

    switch (*st) {
    case 0:
        func_021BDC2C(ctx, a);
        (*st)++;
        break;
    case 1:
        if (((struct Obj07540 *)p)->f48 != 0)
            func_021BDBF8((u32)ctx);
        else if (((struct Obj07540 *)p)->f4C != 0)
            func_021BDC0C(ctx, a);
        (*st)++;
        break;
    case 2:
        func_02012374((struct Evt *)a, (struct Evt **)func_021618E0((void *)x, (void *)y));
        (*st)++;
        break;
    case 3:
        func_021BDC80(ctx);
        return 1;
    }
    return 0;
}
