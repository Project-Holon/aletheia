/*
 * file:     union_oneself_p07.c
 * unit:     yes
 * function: func_0217DE88, func_0217DEA0, func_0217DFB4, func_0217E0A4, func_0217E188, func_0217E378, func_0217E440, func_0217E5A0, func_0217E838
 * address:  0x0217DE88
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217F074 0x0217F074 thumb ov019
 *   func_0217BAF0 0x0217BAF0 thumb ov019
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_0217BB20  0x0217BB20  thumb  ov019
 *   func_0217F060  0x0217F060  thumb  ov019
 *   func_0217FE44  0x0217FE44  thumb  ov019
 *   func_021750B0  0x021750B0  thumb  ov012
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 *   func_0217FEF4  0x0217FEF4  thumb  ov019
 *   func_0217FF14  0x0217FF14  thumb  ov019
 *   func_020362DC  0x020362DC  arm
 *   func_021A3460  0x021A3460  thumb  ov021
 *   func_021679A4  0x021679A4  thumb  ov010
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_02174CE4  0x02174CE4  thumb  ov012
 *   func_021750D0  0x021750D0  thumb  ov012
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BBA8  0x0200BBA8  thumb
 *   func_0217BA48  0x0217BA48  thumb  ov019
 *   func_0217BA6C  0x0217BA6C  thumb  ov019
 *   func_0217B9CC  0x0217B9CC  thumb  ov019
 *   func_02012934  0x02012934  thumb
 *   func_021CC720  0x021CC720  thumb  ov021
 *   func_021CC810  0x021CC810  thumb  ov021
 *   func_021CC7B4  0x021CC7B4  thumb  ov021
 *   func_0217B9F4  0x0217B9F4  thumb  ov019
 *   func_0217F098  0x0217F098  thumb  ov019
 *   func_0217B974  0x0217B974  thumb  ov019
 *   func_0217F640  0x0217F640  thumb  ov019
 *   func_0217F794  0x0217F794  thumb  ov019
 *   func_0217F210  0x0217F210  thumb  ov019
 *   func_0217F7B8  0x0217F7B8  thumb  ov019
 *   func_02174E20  0x02174E20  thumb  ov012
 *   func_02174E64  0x02174E64  thumb  ov012
 *   func_0217FE38  0x0217FE38  thumb  ov019
 *   func_0217FE24  0x0217FE24  thumb  ov019
 *   func_02175240  0x02175240  thumb  ov012
 *   func_02175208  0x02175208  thumb  ov012
 *   func_02175214  0x02175214  thumb  ov012
 *   func_02174D98  0x02174D98  thumb  ov012
 *   func_02174DF0  0x02174DF0  thumb  ov012
 *   func_0201AC2C  0x0201AC2C  thumb
 *   func_0201A2A8  0x0201A2A8  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0203D378  0x0203D378  arm
 *   func_0217422C  0x0217422C  thumb  ov012
 *   func_02174268  0x02174268  thumb  ov012
 *   func_0201292C  0x0201292C  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021807E8     0x021807E8  data  a4
 *   func_0217F22C  0x0217F22C  thumb  ov019
 *   func_0217F268  0x0217F268  thumb  ov019
 *   func_0217F24C  0x0217F24C  thumb  ov019
 */
#include "../../matched/include/Obj12527.h"
#include "../../matched/include/Obj19419.h"
#include "../../matched/include/Obj19422.h"
#include "../../matched/include/Obj19424.h"
#include "../../matched/include/Obj19428.h"
#include "../../matched/include/Obj09416.h"
#include "../../matched/include/Obj03570.h"

struct Obj00020;
struct Obj_0217E188;
struct Self;
struct Big;
struct BigObj;
struct Link;
struct Rec534;
struct Entry;
struct Sub0200852CObj;
struct Sub02008700Obj;
typedef unsigned char u8;

typedef short s16;

typedef unsigned int u32;

typedef struct {
    u8 pad00[0x2d];
    u8 f2d;
} Obj_0217DEA0;

typedef unsigned short u16;

typedef struct {
    u8 pad00[0x2d];
    u8 f2d;
} Obj_0217DFB4;

typedef struct {
    u8 pad00[0x2d];
    u8 f2d;
} Obj_0217E0A4;

typedef struct {
    u8 f00;
    u8 pad01[0x6e - 1];
    s16 f6e;
} Obj_0217E188;

typedef struct {
    u8 pad00[8];
    int f8;
} Sys_0217E188;

typedef struct {
    Sys_0217E188 *sys;
    u8 pad04[0x3534 - 4];
    int f3534;
    int f3538;
    u8 pad353c[0x355c - 0x353c];
    u8 *w;
} Ctx;

typedef struct {
    int f0;
    int f4;
    void *f8;
} Sys_0217E440;

typedef struct {
    int f0;
    int f4;
    int f8;
} Sys_0217E5A0;

typedef struct {
    int f68;
    int f6c;
    u8 f70;
} Ent;

typedef struct {
    int f0;
    void *f4;
    int f8;
    int fc;
    int f10;
    int f14;
    u8 pad18[0x34 - 0x18];
    int f34;
    u8 pad38[0x60 - 0x38];
    u16 f60;
    u8 pad62[0x64 - 0x62];
    int f64;
    Ent ent[3];
    int f8c;
    int f90;
    u8 pad94[0xc0 - 0x94];
    int *fc0;
} Req;

extern void func_0217F074(void *ctx);
extern void func_0217BAF0(char *p, int x, unsigned int v);
extern void *func_02188CB4(struct Obj00020 *p);
extern int func_0217BB20(char *p);
extern int func_0217F060(int i);
extern int func_0217FE44(int a, int mode, unsigned *out);
extern void func_021750B0(u8 *p, int v);
extern int func_0217B8E4(char *p, int v);
extern int func_0217FEF4(u8 *p);
extern int func_0217FF14(void *a);
extern u32 func_020362DC(void);
extern int func_021A3460(u32 a, u32 b, u32 c, u32 d);
extern int func_021679A4(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void *func_021A3074(u8 *p);
extern u32 func_0217F1EC(u8 *p);
extern u32 func_02174CE4(char *p);
extern u8 func_021750D0(u8 *p);
extern int func_0216D3CC(int a0);
extern void func_0216D410(void *h, u16 v);
extern int func_0216D454(void *h);
extern int func_0216D480(char *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200BAC8(void *p);
extern u32 func_0200BBA8(void *a);
extern int func_0217BA48(char *p, unsigned int *mask);
extern int func_0217BA6C(char *p, unsigned int *mask);
extern void *func_0217B9CC(char *p);
extern void *func_02012934(const struct BigObj *p);
extern struct Obj_0217E188 *func_021CC720(u32 a, u32 b, u32 c, u32 d, u32 e, u16 heap);
extern int func_021CC810(struct Obj_0217E188 *p);
extern u32 func_021CC7B4(struct Obj_0217E188 *p, u32 *out);
extern void func_0217B9F4(void *p);
extern void func_0217F098(unsigned char *base, u8 *x);
extern int func_0217B974(int id);
extern void func_0217F640(struct Self *self, u32 a1, u32 mask, int mode, int msg);
extern u32 func_0217F794(char *p, u32 a);
extern void func_0217F210(u8 *p, u8 *a, u32 b);
extern void func_0217F7B8(char *p);
u32 func_02174E20(void);
u32 func_02174E64(void);
void func_0217FE38(u8 *p);
int func_0217FE24(u8 *p);
void func_02175240(u8 *p, int v);
void func_02175208(u8 *p);
int func_02175214(u8 *p);
u32 func_02174D98(u32 p);
int func_02174DF0(u32 v);
void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
void func_0201A2A8(void *a0, void *a1);
struct Entry *func_020399A8(void);
u32 func_0203D1A4(struct Link *p);
void func_02039C68(struct Link *a, unsigned int b, unsigned int c);
unsigned int func_02039CB4(struct Link *a, unsigned int b, unsigned int c);
u32 func_0203D378(void);
void func_0217422C(u8 *p, int a, int b);
int func_02174268(u8 *w);
void *func_0201292C(const struct BigObj *p);
struct Sub02008700Obj *func_0200873C(void *sys);
const void *func_020084F4(const void *p);
u8 func_02008550(const struct Sub0200852CObj *obj);
int func_0203D1B4(void);
void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
u32 func_020307B0(void *p);
void func_0217F22C(u8 *p, u32 a);
int func_0217F268(char *p, u32 *out);
void func_0217F24C(u8 *w);
int func_0217DE88(void *ctx, void *unused, int a);
int func_0217DEA0(void *ctx, Obj_0217DEA0 *obj, int a2, u8 *state);
int func_0217DFB4(void *ctx, Obj_0217DFB4 *obj, int a2, u8 *state);
int func_0217E0A4(void *ctx, Obj_0217E0A4 *obj, int a2, u8 *state);
int func_0217E188(Ctx *ctx, Obj_0217E188 *obj, u8 *a2, u8 *state);
int func_0217E378(u8 *w, void *obj, u8 *a2, u8 *state);
int func_0217E440(u8 *w, void *obj, int a2, u8 *state);
int func_0217E5A0(u8 *w, u8 *obj, u8 *a2, u8 *state);
int func_0217E838(u8 *w, void *obj, void *a2, u8 *state);
extern int d_021807E8[];

int func_0217DE88(void *ctx, void *unused, int a)
{
    func_0217F074(ctx);
    func_0217BAF0(ctx, a, 0);
    return 1;
}


int func_0217DEA0(void *ctx, Obj_0217DEA0 *obj, int a2, u8 *state)
{
    u8 *w = *(u8 * *)&((struct Obj19419 *)ctx)->f355C;
    void *a;
    int m;
    unsigned out;
    int k;
    s16 v[3];

    a = func_02188CB4((void *)a2);
    if (func_0217BB20(ctx) == 1) {
        func_0217F074(ctx);
        return 1;
    }

    if (*state == 0) {
        if (func_0217FE44(a2, func_0217F060(obj->f2d), &out) == 1) {
            func_021750B0(w, out);
            func_0217B8E4(ctx, 0x2b);
            func_0217BAF0(ctx, a2, 1);
            return 1;
        }
        if (func_0217FEF4(w) == 1) {
            func_0217B8E4(ctx, 0x32);
            func_0217BAF0(ctx, a2, 1);
            return 1;
        }
        if (func_0217FF14((void *)a2) == 1) {
            func_0217B8E4(ctx, 0x31);
            func_0217BAF0(ctx, a2, 1);
            return 1;
        }
        if (func_020362DC() & 1) {
            k = 0;
            func_021A3460((u32)a, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
            if (func_021679A4((void *)(((struct Obj12527 *)w)->f0), v[2], v[1], v[0], (int)(&m), (int)(&k)) == 1) {
                w[0x16c] = m;
                func_0217B8E4(ctx, 0x33);
                func_0217BAF0(ctx, a2, 1);
                return 1;
            }
        }
    }
    return 0;
}


int func_0217DFB4(void *ctx, Obj_0217DFB4 *obj, int a2, u8 *state)
{
    void *w = ((struct Obj19422 *)ctx)->f355C;
    void *h;
    unsigned out;
    int r;

    if (func_0217BB20(ctx) == 1) {
        func_0217F074(ctx);
        return 1;
    }

    switch (*state) {
    case 0:
        (*state)++;
        break;
    case 1:
        if (func_02174CE4(w) == 1)
            (*state)++;
        break;
    case 2:
        if (func_0217F1EC(ctx) != 0) {
            r = func_021750D0(w);
            if (r == 1) {
                (*state)++;
            } else if (r == 0) {
                func_0217B8E4(ctx, 0x2c);
                return 1;
            }
        }
        break;
    case 3:
        h = func_021A3074(func_02188CB4((void *)a2));
        if (func_0216D3CC((int)h) == 1) {
            func_0217FE44(a2, func_0217F060(obj->f2d), &out);
            func_0216D410(h, (out & 1) ? 2 : 3);
            (*state)++;
        }
        break;
    case 4:
        h = func_021A3074(func_02188CB4((void *)a2));
        if (func_0216D454(h) == 1) {
            func_0216D480(h);
            func_0217B8E4(ctx, 0x2d);
            return 1;
        }
        break;
    }
    return 0;
}


int func_0217E0A4(void *ctx, Obj_0217E0A4 *obj, int a2, u8 *state)
{
    void *w = ((struct Obj19424 *)ctx)->f355C;
    void *h;
    unsigned out;

    h = func_021A3074(func_02188CB4((void *)a2));
    if (func_0217BB20(ctx) == 1) {
        func_0217F074(ctx);
        return 1;
    }

    switch (*state) {
    case 0:
        func_021750B0(w, 0xff);
        (*state)++;
        break;
    case 1:
        if (func_02174CE4(w) == 1)
            (*state)++;
        break;
    case 2:
        if (func_021750D0(w) != 0xff)
            (*state)++;
        break;
    case 3:
        func_0217F074(ctx);
        (*state)++;
        break;
    case 4:
        if (func_0216D3CC((int)h) == 1) {
            func_0217FE44(a2, func_0217F060(obj->f2d), &out);
            func_0216D410(h, (out & 1) ? 0xb : 0xa);
            (*state)++;
        }
        break;
    case 5:
        if (func_0216D454(h) == 1) {
            func_0216D480(h);
            func_0217B8E4(ctx, 0x2a);
            return 1;
        }
        break;
    }
    return 0;
}


int func_0217E188(Ctx *ctx, Obj_0217E188 *obj, u8 *a2, u8 *state)
{
    u8 *w = ctx->w;
    int o1c;
    int o18;
    int o14;
    int o10;
    int f1;
    int f2;
    int r;

    if (func_0217F1EC((u8 *)ctx) == 0)
        return 0;

    switch (*state) {
    case 0:
        obj->f6e = 0;
        (*state)++;
    case 1:
        if (func_0200BBA8(func_0200BAC8(func_02012EBC((struct Big *)ctx->sys->f8))) == 1) {
            (*state)++;
        } else {
            w[0x16d] = 0;
            obj->f6e++;
            *state = 4;
        }
        break;
    case 2:
        func_0217F074(ctx);
        func_0217BA48((char *)ctx, (unsigned int *)(&o1c));
        func_0217BA6C((char *)ctx, (unsigned int *)(&o18));
        f1 = o1c != 0;
        f2 = o18 != 0;
        ctx->f3538 = (int)func_0217B9CC((char *)ctx);
        ctx->f3534 = (int)func_021CC720((u32)a2, (u32)func_02012934((void *)ctx->sys->f8), ctx->f3538, f1, f2, 0x15);
        (*state)++;
        break;
    case 3:
        if (func_021CC810((struct Obj_0217E188 *)ctx->f3534) == 1) {
            r = func_021CC7B4((struct Obj_0217E188 *)ctx->f3534, (u32 *)(&o14));
            ctx->f3534 = 0;
            if (r == 2) {
                func_0217B9F4((void *)ctx->f3538);
                ctx->f3538 = 0;
                func_0217B8E4((char *)ctx, 0x2c);
                return 1;
            }
            switch (r) {
            case 0:
                w[0x16d] = 0;
                break;
            case 1:
                w[0x16d] = 1;
                break;
            }
            func_0217B9F4((void *)ctx->f3538);
            ctx->f3538 = 0;
            (*state)++;
        }
        break;
    case 4:
        o10 = 0;
        if (w[0x16d] == 0) {
            func_0217BA48((char *)ctx, (unsigned int *)(&o10));
            f1 = 1;
        } else {
            func_0217BA6C((char *)ctx, (unsigned int *)(&o10));
            f1 = 2;
        }
        if (o10 != 0) {
            func_0217F098((unsigned char *)ctx, a2);
            func_0217F640((struct Self *)ctx, (u32)a2, o10, func_0217B974(obj->f00), f1);
            *state = 5;
        } else {
            func_0217B8E4((char *)ctx, 0x2e);
            return 1;
        }
        break;
    case 5:
        if (func_0217F794((char *)ctx, (u32)a2) == 1) {
            func_0217F210((u8 *)ctx, (u8 *)a2, 0x115);
            (*state)++;
        }
        break;
    case 6:
        if (func_020362DC() & 3) {
            func_0217F7B8((char *)ctx);
            if (obj->f6e == 0) {
                *state = 0;
            } else {
                func_0217B8E4((char *)ctx, 0x2c);
                return 1;
            }
        }
        break;
    }
    return 0;
}


int func_0217E378(u8 *w, void *obj, u8 *a2, u8 *state)
{
    u8 *p;

    p = *(u8 * *)&((struct Obj19428 *)w)->f355C;
    if (func_0217BB20((char *)w) == 1) {
        func_0217F074(w);
        return 1;
    }
    if (p[0xcb] == 1) {
        func_0217B8E4((char *)w, 0x2f);
        p[0xcb] = 0;
        p[0xdf] = 0;
        return 1;
    }
    switch (*state) {
    case 0:
        func_0217F210(w, a2, 0x116);
        (*state)++;
        break;
    case 1:
        if (func_02174E20() == 1) {
            p[0xdf] = 1;
            (*state)++;
        }
        break;
    case 2:
        if (func_0217F1EC(w) == 1 && (func_020362DC() & 2))
            *state = 100;
        break;
    case 100:
        if (func_02174E64() == 1)
            (*state)++;
        break;
    case 101:
        if (p[0xdf] == 0) {
            func_0217B8E4((char *)w, 0x2c);
            return 1;
        }
        break;
    }
    return 0;
}


int func_0217E440(u8 *w, void *obj, int a2, u8 *state)
{
    u8 *p;
    int idx;
    void *h;

    p = *(u8 * *)&((struct Obj09416 *)w)->f355C;
    idx = func_0203D1A4((struct Link *)((int)func_020399A8()));
    if (func_0217BB20((char *)w) == 1) {
        func_0217F074(w);
        return 1;
    }
    switch (*state) {
    case 0:
        switch (p[0x16d]) {
        case 0:
        default:
            func_0201AC2C(func_02012934((*(Sys_0217E440 * *)&((struct Obj09416 *)w)->f0)->f8), (struct Rec534 *)(((int *)(p + 0x148))[idx]));
            break;
        case 1:
            h = func_0217B9CC((char *)w);
            func_0201AC2C(h, (struct Rec534 *)(((int *)(p + 0x148))[idx]));
            func_0217B9F4(h);
            break;
        }
        func_0201A2A8((void *)(((struct Obj09416 *)w)->f352C), (void *)(((int *)(p + 0x148))[idx]));
        (*state)++;
        break;
    case 1:
        func_02175240(p, 1);
        func_0217FE38(p);
        func_02175208(p);
        func_02039C68((struct Link *)func_020399A8(), 0x14, 0x14);
        (*state)++;
        break;
    case 2:
        if (func_02039CB4((struct Link *)func_020399A8(), 0x14, 0x14) == 1)
            (*state)++;
        break;
    case 3:
        if (func_02174D98(((int *)(p + 0x148))[idx]) == 1)
            (*state)++;
        break;
    case 4:
        if (func_02175214(p) == 1)
            (*state)++;
        break;
    case 5:
        func_02039C68((struct Link *)func_020399A8(), 0x10, 0x14);
        (*state)++;
        break;
    case 6:
        if (func_02039CB4((struct Link *)func_020399A8(), 0x10, 0x14) == 1)
            (*state)++;
        break;
    case 7:
        if (func_0203D378() == 1) {
            if (func_02174DF0((u32)(p + 0xcc)) == 1)
                (*state)++;
        } else {
            (*state)++;
        }
        break;
    case 8:
        if (func_0217FE24(p) == 1) {
            func_0217B8E4((char *)w, 0x30);
            return 1;
        }
        break;
    }
    return 0;
}


int func_0217E5A0(u8 *w, u8 *obj, u8 *a2, u8 *state)
{
    u8 *p;
    int idx;
    int msg;
    Req *q;
    int i;
    int cnt;
    int k;

    p = *(u8 * *)&((struct Obj03570 *)w)->f355C;
    idx = func_0203D1A4((struct Link *)((int)func_020399A8()));
    if (*state < 3 && func_0217BB20((char *)w) == 1) {
        func_0217F074(w);
        return 1;
    }
    switch (*state) {
    case 0:
        if (func_0217F1EC(w) != 1)
            break;
        switch (obj[0x2d]) {
        default:
            msg = 0x117;
            break;
        case 6:
        case 7:
        case 22:
        case 23:
            msg = 0x118;
            break;
        case 20:
        case 21:
            msg = 0x11b;
            break;
        case 10:
        case 11:
        case 18:
        case 19:
            msg = 0x119;
            break;
        case 14:
        case 15:
            msg = 0x11a;
            break;
        }
        func_0217F210(w, a2, msg);
        (*state)++;
        break;
    case 1:
        if (func_0217F1EC(w) == 1) {
            func_02039C68((struct Link *)func_020399A8(), 0x11, 0x14);
            (*state)++;
        }
        break;
    case 2:
        if (func_02039CB4((struct Link *)func_020399A8(), 0x11, 0x14) == 1) {
            func_0217F074(w);
            (*state)++;
        }
        break;
    case 3:
        q = func_02030734(0x41, 0xc4, 1, (const char *)d_021807E8, 0x10c4);
        q->f0 = ((int *)(p + 0x148))[idx];
        q->f4 = func_0201292C((const struct BigObj *)((*(Sys_0217E5A0 * *)&((struct Obj03570 *)w)->f0)->f8));
        q->fc = (int)func_0200873C(func_02012EBC((struct Big *)((*(Sys_0217E5A0 * *)&((struct Obj03570 *)w)->f0)->f8)));
        q->f34 = 0x1a;
        q->f14 = ((struct Obj03570 *)w)->f352C;
        q->fc0 = func_02030734(0x41, 0x70, 1, (const char *)d_021807E8, 0x10ce);
        cnt = 0;
        for (i = 0; i < func_0203D1B4(); i++) {
            if (i == idx)
                continue;
            if ((p[idx + 0x15c] & 1) == (p[i + 0x15c] & 1))
                k = 0;
            else
                k = ++cnt;
            q->ent[k].f68 = ((int *)(p + 0x148))[i];
            q->ent[k].f6c = (int)func_020084F4(p + 0x18 + i * 0x2c);
            q->ent[k].f70 = func_02008550((const struct Sub0200852CObj *)(p + 0x18 + i * 0x2c));
        }
        switch (obj[0x2d]) {
        case 20:
        case 21:
        case 22:
        case 23:
            q->f64 = 2;
            break;
        default:
            q->f64 = 1;
            break;
        }
        q->f8c = 1;
        q->f90 = 0;
        q->f60 = 0;
        *(Req * *)&((struct Obj03570 *)w)->f3558 = q;
        func_0217422C(w, 0x1a, (int)q);
        (*state)++;
        break;
    case 4:
        if (func_02174268(w) == 1)
            break;
        func_020307B0((*(Req * *)&((struct Obj03570 *)w)->f3558)->fc0);
        func_020307B0(*(Req * *)&((struct Obj03570 *)w)->f3558);
        *(Req * *)&((struct Obj03570 *)w)->f3558 = 0;
        func_0217B8E4((char *)w, 0x2c);
        return 1;
    }
    return 0;
}


int func_0217E838(u8 *w, void *obj, void *a2, u8 *state)
{
    void *h;
    int flag;

    h = func_021A3074(func_02188CB4(a2));
    if (func_0217BB20((char *)w) == 1) {
        func_0217F074(w);
        return 1;
    }
    switch (*state) {
    case 0:
        func_0217F210(w, (u8 *)a2, 0x14e);
        (*state)++;
        break;
    case 1:
        if (func_0217F1EC(w) != 0) {
            func_0217F22C(w, (u32)a2);
            (*state)++;
        }
        break;
    case 2:
        if (func_0217F268((char *)w, (u32 *)(&flag)) == 1) {
            func_0217F24C(w);
            if (flag == 0) {
                *state = 3;
            } else {
                func_0217B8E4((char *)w, 0x32);
                return 1;
            }
        }
        break;
    case 3:
        if (func_0216D3CC((int)h) == 1) {
            func_0216D410(h, 8);
            (*state)++;
        }
        break;
    case 4:
        if (func_0216D454(h) == 1) {
            func_0216D480(h);
            func_0217B8E4((char *)w, 0x2a);
            return 1;
        }
        break;
    }
    return 0;
}
