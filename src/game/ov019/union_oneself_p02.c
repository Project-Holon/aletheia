/*
 * file:     union_oneself_p02.c
 * unit:     yes
 * function: func_0217C444, func_0217C450, func_0217C518, func_0217C5A8
 * address:  0x0217C444
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
 *   func_0217F378  0x0217F378  thumb ov019
 *   func_0217BB04  0x0217BB04  thumb ov019
 *   func_02173A04  0x02173A04  thumb ov012
 *   func_0217B8E4  0x0217B8E4  thumb ov019
 *   func_0217EC40  0x0217EC40  thumb ov019
 *   func_0217EC54  0x0217EC54  thumb ov019
 *   func_0217F210  0x0217F210  thumb ov019
 *   func_0217F1EC  0x0217F1EC  thumb ov019
 *   func_02173518  0x02173518  thumb  ov012
 *   func_021734A8  0x021734A8  thumb  ov012
 *   func_021735FC  0x021735FC  thumb  ov012
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02173B4C  0x02173B4C  thumb  ov012
 *   func_02080D24  0x02080D24  arm
 *   func_0217EC34  0x0217EC34  thumb ov019
 *   func_0217EC68  0x0217EC68  thumb ov019
 *   func_0217EC78  0x0217EC78  thumb ov019
 *   func_0217ECD0  0x0217ECD0  thumb ov019
 *   func_0217B9BC  0x0217B9BC  thumb ov019
 *   func_0217BA10  0x0217BA10  thumb ov019
 *   func_0217B974  0x0217B974  thumb ov019
 *   func_0217BAA8  0x0217BAA8  thumb ov019
 *   func_0217F640  0x0217F640  thumb ov019
 *   func_0217F794  0x0217F794  thumb ov019
 *   func_0217F7B8  0x0217F7B8  thumb ov019
 *   func_0217F22C  0x0217F22C  thumb ov019
 *   func_0217F268  0x0217F268  thumb ov019
 *   func_0217F24C  0x0217F24C  thumb ov019
 *   func_02173A48  0x02173A48  thumb ov012
 *   func_02012934  0x02012934  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201AA1C  0x0201AA1C  thumb
 *   func_0201AAD4  0x0201AAD4  thumb
 *   func_0201AA88  0x0201AA88  thumb
 *   func_020362DC  0x020362DC  arm
 */
#include "../../matched/include/Obj12524.h"

struct Entry;
struct Link;
struct Self;
struct BigObj;
struct Ctx;
typedef unsigned char u8;

typedef struct {
    u8 pad[7];
    u8 lo : 3;
    u8 flag : 1;
} Sub;

typedef struct {
    u8 pad00[0x14];
    Sub *f14;
    u8 pad18[0x2d - 0x18];
    u8 f2d;
    u8 f2e;
} Obj_0217C450;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short s16;

typedef struct {
    u8 pad00[0x14];
    Sub *f14;
    u8 pad18[0x2d - 0x18];
    u8 f2d;
    u8 f2e;
    u8 pad2f[0x64 - 0x2f];
    int f64;
    int f68;
    u8 pad6c[0x6e - 0x6c];
    s16 f6e;
} Obj_0217C5A8;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
} Sys;

typedef struct {
    Sys *sys;
} Ctx;

void func_0217F378(void *p);
int func_0217BB04(char *p);
int func_02173A04(int a, ...);
int func_0217B8E4(char *p, int v);
u16 func_0217EC40(int i, int j);
u16 func_0217EC54(int i, int j);
void func_0217F210(u8 *p, u8 *a, u32 b);
u32 func_0217F1EC(u8 *p);
extern void func_02173518(u8 *a);
extern void func_021734A8(u8 *self, u32 id, u32 v);
extern int func_021735FC(u8 *self, const struct Entry *p);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *a, u32 b, u32 c);
extern u32 func_02039CB4(struct Link *a, u32 b, u32 c);
extern int func_02173B4C(u8 *a);
extern unsigned int func_02080D24(int a);
u16 func_0217EC34(int i);
u16 func_0217EC68(int i);
u16 func_0217EC78(int i);
u16 func_0217ECD0(void ***ctx);
int func_0217B9BC(unsigned int x);
void func_0217BA10(char *p, int x);
int func_0217B974(int id);
int func_0217BAA8(int a, int b, int *p, int *q);
void func_0217F640(struct Self *self, u32 a1, u32 mask, int mode, int msg);
u32 func_0217F794(char *p, u32 a);
void func_0217F7B8(char *p);
void func_0217F22C(u8 *p, u32 a);
int func_0217F268(char *p, u32 *out);
void func_0217F24C(u8 *p);
int func_02173A48(int a, ...);
void *func_02012934(const struct BigObj *p);
void *func_020120F4(const struct Ctx *p);
u32 func_0201AA1C(void *p);
u32 func_0201AAD4(void *p);
u32 func_0201AA88(void *p);
u32 func_020362DC(void);
int func_0217C444(void *p);
int func_0217C450(void *ctx, Obj_0217C450 *obj, u8 *a2, u8 *state);
int func_0217C518(u8 *a, u8 *b, int c, u8 *d);
int func_0217C5A8(Ctx *ctx, Obj_0217C5A8 *obj, u8 *a2, u8 *state);


int func_0217C444(void *p)
{
    func_0217F378(p);
    return 1;
}


int func_0217C450(void *ctx, Obj_0217C450 *obj, u8 *a2, u8 *state)
{
    if (func_0217BB04(ctx) == 1)
        return 1;

    switch (*state) {
    case 0:
        if (func_02173A04(obj->f2d) == 1) {
            if (obj->f2d == 0) {
                func_0217B8E4(ctx, 0x27);
                return 1;
            }
            func_0217F210(ctx, a2, func_0217EC40(obj->f2d, obj->f14->flag));
            (*state)++;
        }
        break;
    case 1:
        if (func_0217F1EC(ctx) != 0) {
            if (obj->f2e == 1) {
                func_0217B8E4(ctx, obj->f2d + 11);
                (*state)++;
            } else if (obj->f2e == 0) {
                func_0217B8E4(ctx, 0x27);
                func_0217F210(ctx, a2, func_0217EC54(obj->f2d, obj->f14->flag));
                return 1;
            }
        }
        break;
    case 2:
        if (func_0217F1EC(ctx) == 1)
            return 1;
        break;
    }
    return 0;
}


int func_0217C518(u8 *a, u8 *b, int c, u8 *d)
{
    int r;
    if (func_0217BB04((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        func_02173518(b + 0x14);
        func_021734A8(a, 4, 1);
        func_021735FC(b + 0x14, (const struct Entry *)(((struct Obj12524 *)b)->f20));
        r = (int)func_020399A8();
        func_02039C68((struct Link *)r, 2, 0x14);
        (*d)++;
        break;
    case 1:
        r = (int)func_020399A8();
        if (func_02039CB4((struct Link *)r, 2, 0x14) == 1)
            (*d)++;
        break;
    case 2:
        if (func_02173B4C(a) == 1)
            (*d)++;
        break;
    case 3:
        if (func_02080D24(b[0x5b]) > 1)
            return 1;
        break;
    }
    return 0;
}


int func_0217C5A8(Ctx *ctx, Obj_0217C5A8 *obj, u8 *a2, u8 *state)
{
    int flag;
    void *h;

    if (func_0217BB04((char *)ctx) == 1)
        return 1;
    if (func_0217F1EC((u8 *)ctx) == 0)
        return 0;

    switch (*state) {
    case 0:
        func_0217F210((u8 *)ctx, a2, 9);
        (*state)++;
        break;
    case 1:
        if (obj->f2d == 0xff)
            break;
        if (obj->f2d == 0) {
            func_0217F210((u8 *)ctx, a2, func_0217EC34(obj->f14->flag));
            func_0217B8E4((char *)ctx, 0x27);
            return 1;
        }
        if (obj->f2d < 0x1b) {
            func_0217F210((u8 *)ctx, a2, func_0217EC68(obj->f2d));
            if (func_0217B9BC(obj->f2d) == 1) {
                func_0217BA10((char *)ctx, obj->f2d);
                func_0217F640((struct Self *)ctx, (u32)a2, 0, func_0217B974(obj->f2d), 0);
                *state = 2;
            } else {
                *state = 3;
            }
        } else if (func_02173A48(0) == 1) {
            func_0217F210((u8 *)ctx, a2, 0x13d);
            func_0217B8E4((char *)ctx, 0x27);
            return 1;
        }
        break;
    case 2:
        if (func_0217F794((char *)ctx, (u32)a2) == 1)
            *state = 3;
        break;
    case 3:
        func_0217F7B8((char *)ctx);
        func_0217F22C((u8 *)ctx, (u32)a2);
        (*state)++;
        break;
    case 4:
        obj->f6e = 0;
        if (func_0217F268((char *)ctx, (u32 *)(&flag)) != 1)
            break;
        h = func_02012934((void *)ctx->sys->f8);
        func_0217F24C((u8 *)ctx);
        if (func_0217BAA8((int)ctx, obj->f2d, &obj->f64, &obj->f68) == 0) {
            func_0217F210((u8 *)ctx, a2, 0x13e);
            flag = 0;
        } else if (obj->f2d == 0x18 && flag == 1) {
            func_020120F4((const struct Ctx *)ctx->sys->fc);
            if ((int)func_0201AA1C(h) < 2) {
                flag = 0;
                obj->f6e = 1;
            }
        } else if (obj->f2d == 0x19 && flag == 1) {
            if ((int)func_0201AAD4(h) > 0) {
                flag = 0;
                obj->f6e = 3;
            } else if (func_0201AA88(h) == 0) {
                flag = 0;
                obj->f6e = 2;
            }
        }
        obj->f2e = flag;
        (*state)++;
        break;
    case 5:
        if (func_02173A48(obj->f2e) == 1) {
            if (obj->f64 != 0 && obj->f68 != 0)
                *state = 6;
            else
                *state = 10;
        }
        break;
    case 6:
        func_0217F640((struct Self *)ctx, (u32)a2, obj->f64, func_0217B974(obj->f2d), 1);
        (*state)++;
        break;
    case 7:
        if (func_0217F794((char *)ctx, (u32)a2) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8((char *)ctx);
            if (obj->f68 == -1)
                *state = 10;
            else
                (*state)++;
        }
        break;
    case 8:
        func_0217F640((struct Self *)ctx, (u32)a2, obj->f64, func_0217B974(obj->f2d), 2);
        (*state)++;
        break;
    case 9:
        if (func_0217F794((char *)ctx, (u32)a2) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8((char *)ctx);
            *state = 10;
        }
        break;
    case 10:
        if (obj->f2e == 0) {
            if (obj->f6e == 1)
                func_0217F210((u8 *)ctx, a2, 0x28);
            else if (obj->f6e == 2)
                func_0217F210((u8 *)ctx, a2, 0x2f);
            else if (obj->f6e == 3)
                func_0217F210((u8 *)ctx, a2, func_0217ECD0((void ***)ctx));
            else
                func_0217F210((u8 *)ctx, a2, func_0217EC78(obj->f2d));
            func_0217B8E4((char *)ctx, 0x27);
            return 1;
        }
        func_0217B8E4((char *)ctx, obj->f2d + 11);
        *state = 11;
        break;
    case 11:
        return 1;
    }
    return 0;
}
