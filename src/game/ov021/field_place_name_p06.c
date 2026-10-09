/*
 * file:     field_place_name_p06.c
 * unit:     yes
 * function: func_021BD904, func_021BD93C, func_021BD94C, func_021BD96C, func_021BD988, func_021BD9BC, func_021BDA30, func_021BDA70, func_021BDAA8, func_021BDB1C, func_021BDB5C, func_021BDB9C, func_021BDBF8, func_021BDC0C
 * address:  0x021BD904
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
 *   func_02012134  0x02012134  thumb
 *   func_0202B580  0x0202B580  thumb
 *   func_0202B434  0x0202B434  thumb
 *   func_0202B438  0x0202B438  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   d_021D9BC8     0x021D9BC8  data  ov021  a4
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021BDC2C  0x021BDC2C  thumb  ov021
 *   func_021BDC80  0x021BDC80  thumb  ov021
 *   func_021A7B20  0x021A7B20  thumb  ov021
 *   func_021618E0  0x021618E0  thumb  ov010
 *   func_021BF644  0x021BF644  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012A30  0x02012A30  thumb
 *   func_02029D7C  0x02029D7C  thumb
 */
#include "../../matched/include/Obj18244.h"
#include "../../matched/include/Obj20137.h"
#include "../../matched/include/Obj07540.h"
#include "../../matched/include/Obj12894.h"
#include "../../matched/include/Obj09653.h"
#include "../../matched/include/Obj02661.h"

struct Obj00020;
struct BigObj;
struct Evt;
struct Desc;
struct Obj;
struct Args;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u32 x0;
    u32 x4;
    u8 pad8[0x10];
    u16 h18;
    u8 pad1a[6];
    u16 h20;
} Ent;

typedef struct {
    u32 x0;
    u32 x4;
    Ent *e;
} Obj_021BD904;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    char pad[8];
    void *f8;
    char pad2[0x14];
    u16 h20;
    char pad3[0x23];
    u8 b45;
    char pad4[2];
    int f48;
} Inner_021BD904;

typedef struct {
    char pad[8];
    Inner_021BD904 *f8;
} Obj_021BD93C;

typedef struct {
    char pad[4];
    void *f4;
    char pad2[0x44];
    int f4C;
} Inner_021BD96C;

typedef struct {
    char pad[8];
    Inner_021BD96C *f8;
} Obj_021BD96C;

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

typedef struct { u32 v[6]; } T6;

typedef struct {
    int pad0;
    void *f4;
    void *f8;
} Inner;

typedef struct {
    Inner *f0;
} Obj;

extern u32 func_02012134(u32 *p);
extern u32 func_0202B580(void *obj);
extern u32 func_0202B434(u8 *p);
extern u32 func_0202B438(u8 *p, u32 id);
extern void *func_02188CB4(struct Obj00020 *p);
extern u32 func_021A3098(u8 *p);
extern u32 func_02012A30(const struct BigObj *p);
extern void func_02029D44(u32 a, u32 b, u16 c, u8 d);
extern u8 *func_0202952C(u8 *p, u32 a);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern struct Desc *func_020122C0(void *, void *, void *, u32);
extern void *func_020124E8(struct Obj *);
extern void func_021BDC2C(u32 *, u32);
extern void func_021BDC80(u32 *);
extern void *func_021A7B20(struct Args *a);
extern void *func_021618E0(void *a, void *b);
extern int func_021BF644(int a, int b, int c);
extern void *func_02188C58(void *p);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern u32 func_02029D7C(u32, u32);
extern u8 *func_020294C0(u8 *p, u32 a);
int func_021BD904(Obj_021BD904 *o);
void func_021BD93C(u32 a, u32 b, u32 c, u32 d);
void func_021BD94C(Obj_021BD93C *p);
void func_021BD96C(Obj_021BD96C *p, void *b);
void func_021BD988(Obj_021BD988 *o, int b);
int func_021BD9BC(u32 *p);
u32 func_021BDA30(u32 a, int *st, u32 *ctx);
u32 func_021BDA70(u32 a, u32 *st, u32 *p);
u32 func_021BDAA8(u32 a, int *st, u32 *ctx);
u32 func_021BDB1C(u32 a, int *st, u32 *ctx);
u32 func_021BDB5C(u32 a, int *st, u32 *ctx);
u32 func_021BDB9C(u32 a, int *st, u32 *ctx);
int func_021BDBF8(u32 a);
void func_021BDC0C(Obj *p, void *b);
extern const T6 d_021D9BC8;





int func_021BD904(Obj_021BD904 *o)
{
    Ent *e = o->e;
    void *s = (void *)func_0202B580((void *)func_02012134((u32 *)e->x4));

    if (func_0202B434(s) && func_0202B438(s, e->h18) && func_0202B438(s, e->h20)) {
        return 1;
    }
    return 0;
}






/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD93C(u32 a, u32 b, u32 c, u32 d)
{
func_021A3098(func_02188CB4((struct Obj00020 *)(*(u32 *)((u8 *)(((struct Obj18244 *)((u8 *)(a)))->f8) + 12))));
}






void func_021BD94C(Obj_021BD93C *p)
{
    Inner_021BD904 *q = p->f8;
    void *r = q->f8;

    func_02029D44(func_02012A30(r), (u32)r, q->h20, q->b45);
    q->f48 = 1;
}





void func_021BD96C(Obj_021BD96C *p, void *b)
{
    Inner_021BD96C *q = p->f8;

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
            func_021BDC0C((Obj *)ctx, (void *)a);
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




u32 func_021BDB1C(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[0];
    u32 x = ((struct Obj12894 *)p)->f4;
    u32 y = ((struct Obj12894 *)p)->fC;

    switch (*st) {
    case 0:
        func_02012374((struct Evt *)a, (struct Evt **)func_021BF644(0, x, y));
        (*st)++;
        break;
    case 1:
        func_021BDC80(ctx);
        return 1;
    }
    return 0;
}




u32 func_021BDB5C(u32 a, int *st, u32 *ctx)
{
    u32 *p = (u32 *)ctx[0];

    func_02188C58((void *)p[3]);
    switch (*st) {
    case 0:
        func_02012374((struct Evt *)a, func_021A7B20((struct Args *)((u32)p)));
        (*st)++;
        break;
    case 1:
        func_021BDC80(ctx);
        return 1;
    }
    return 0;
}




u32 func_021BDB9C(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[0];
    u32 x = ((struct Obj09653 *)p)->f4;
    u32 y = ((struct Obj09653 *)p)->fC;

    switch (*st) {
    case 0:
        if (((struct Obj09653 *)p)->f48 != 0)
            func_021BDBF8((u32)ctx);
        (*st)++;
        break;
    case 1:
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)x, y, 2, 0, 0, 0, 0));
        (*st)++;
        break;
    case 2:
        func_021BDC80(ctx);
        return 1;
    }
    return 0;
}



int func_021BDBF8(u32 a)
{
return func_02029D7C(func_02012A30((const struct BigObj *)*(u32 *)((u8 *)(*(u32 *)&((struct Obj02661 *)((u8 *)(a)))->f0) + 8)), *(u32 *)((u8 *)(*(u32 *)&((struct Obj02661 *)((u8 *)(a)))->f0) + 8));
}



void func_021BDC0C(Obj *p, void *b)
{
    Inner *q = p->f0;
    void *r = q->f4;

    func_02012A30(q->f8);
    func_02012374(b, (struct Evt **)func_020294C0(r, 6));
}
