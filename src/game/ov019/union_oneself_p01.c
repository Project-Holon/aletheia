/*
 * file:     union_oneself_p01.c
 * unit:     yes
 * function: func_0217BD9C, func_0217BE44, func_0217BE64, func_0217C03C, func_0217C04C, func_0217C074, func_0217C1F0, func_0217C200, func_0217C2AC
 * address:  0x0217BD9C
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
 *   func_020061E4  0x020061E4  thumb
 *   func_02030734  0x02030734  arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0217422C  0x0217422C  thumb  ov012
 *   func_02174268  0x02174268  thumb  ov012
 *   func_021736A0  0x021736A0  thumb  ov012
 *   func_020307B0  0x020307B0  arm
 *   d_021807E8     0x021807E8  data  a4
 *   func_0217F210 0x0217F210 thumb ov019
 *   func_0217BB04  0x0217BB04  thumb  ov019
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 *   func_0217EC04  0x0217EC04  thumb  ov019
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_02172D20  0x02172D20  thumb  ov012
 *   func_02172D68  0x02172D68  thumb  ov012
 *   func_021734A8  0x021734A8  thumb  ov012
 *   func_02173AFC  0x02173AFC  thumb  ov012
 *   func_0203D14C  0x0203D14C  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_0203D1E8  0x0203D1E8  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_020392B8  0x020392B8  arm
 *   func_020399A8  0x020399A8  arm
 *   func_020362DC  0x020362DC  arm
 *   memcmp         0x0203EFC8  arm
 *   func_0217BAF0 0x0217BAF0 thumb ov019
 *   d_021807E4     0x021807E4  data a1
 *   func_02034714  0x02034714  arm
 *   func_02173A90  0x02173A90  thumb ov012
 *   func_02173518  0x02173518  thumb  ov012
 *   func_021735FC  0x021735FC  thumb  ov012
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02173B4C  0x02173B4C  thumb  ov012
 *   func_02080D24  0x02080D24  arm
 *   func_0217EC1C  0x0217EC1C  thumb ov019
 *   func_0217EC88  0x0217EC88  thumb ov019
 *   func_0217EC28  0x0217EC28  thumb ov019
 *   func_0217ECA0  0x0217ECA0  thumb ov019
 *   func_0217ECAC  0x0217ECAC  thumb ov019
 *   func_0217ECB8  0x0217ECB8  thumb ov019
 *   func_0217F360  0x0217F360  thumb ov019
 *   func_0217F378  0x0217F378  thumb ov019
 *   func_0217F380  0x0217F380  thumb ov019
 *   func_02012934  0x02012934  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201AA1C  0x0201AA1C  thumb
 *   func_0201AAD4  0x0201AAD4  thumb
 *   func_0201AA88  0x0201AA88  thumb
 */
#include "../../matched/include/Obj04183.h"
#include "../../matched/include/Obj05947.h"

struct Big;
struct Entry;
struct Link;
struct BigObj;
struct Ctx;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef short          s16;

typedef struct Obj_0217BE64 {
    u8   pad00[0x18];
    u8  *p18;
    u8   pad1C[0x24 - 0x1C];
    u8   addr[6];
    u8   b2A;
    u8   pad2B[0x6C - 0x2B];
    s16  s6C;
} Obj_0217BE64;

typedef struct {
    u8 pad00[0x1c];
    u8 *f1c;
    u8 pad20[0x5a - 0x20];
    u8 lo5a : 2;
    u8 mode : 2;
    u8 pad5b[0x6c - 0x5b];
    s16 f6c;
} Obj_0217C074;

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
    u8 pad2e[0x5c - 0x2e];
    u8 f5c;
    u8 pad5d[0x6e - 0x5d];
    s16 f6e;
} Obj_0217C2AC;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
} Sys;

typedef struct {
    Sys *sys;
} Ctx;

extern void func_020061E4(u32 a);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void *func_02012EBC(struct Big *p);
extern void func_0217422C(u8 *p, int a, int b);
extern int func_02174268(u8 *a);
extern void func_021736A0(u8 *a, volatile u16 *s);
extern u32 func_020307B0(void *p);
extern void func_0217F210(u8 *p, u8 *a, u32 b);
extern int func_0217BB04(char *p);
extern int func_0217B8E4(char *p, int v);
extern u16 func_0217EC04(void ***ctx);
extern u32 func_0217F1EC(u8 *p);
extern void func_02172D20(u8 *p);
extern int func_02172D68(u8 *p);
extern void func_021734A8(u8 *self, u32 id, u32 v);
extern int  func_02173AFC(int v);
extern void func_0203D14C(int a, int b, void *c);
extern int  func_0203D1B4(void);
extern u32 func_0203D1C0(u32 index);
extern void func_0203D1E8(u32 unused, void *arg);
extern void func_0203D7BC(u8 a0);
extern int  func_020392B8(void);
extern struct Entry *func_020399A8(void);
extern u32 func_020362DC(void);
extern int  memcmp(const void *a, const void *b, u32 n);
extern void func_0217BAF0(char *p, int x, unsigned int v);
void func_02034714(const char *expr, u32 line, const char *file);
int func_02173A90(void);
extern void func_02173518(u8 *a);
extern int func_021735FC(u8 *self, const struct Entry *p);
extern void func_02039C68(struct Link *a, u32 b, u32 c);
extern u32 func_02039CB4(struct Link *a, u32 b, u32 c);
extern int func_02173B4C(u8 *a);
extern unsigned int func_02080D24(int a);
u16 func_0217EC1C(int i);
u16 func_0217EC88(int i);
u16 func_0217EC28(int i);
u16 func_0217ECA0(int i);
u16 func_0217ECAC(int i);
u16 func_0217ECB8(void ***ctx);
void func_0217F360(char *p, u32 a);
void func_0217F378(void *p);
int func_0217F380(void *ctx, int a);
void *func_02012934(const struct BigObj *p);
void *func_020120F4(const struct Ctx *p);
u32 func_0201AA1C(void *p);
u32 func_0201AAD4(void *p);
u32 func_0201AA88(void *p);
int func_0217BD9C(u8 *a, int b, int c, u8 *d);
int func_0217BE44(void *ctx, void *unused, u8 *a);
int func_0217BE64(void *w, Obj_0217BE64 *obj, u8 *a2, u8 *state);
int func_0217C03C(u8 *self);
int func_0217C04C(void *ctx, void *unused, u8 *a);
int func_0217C074(void *ctx, Obj_0217C074 *obj, u8 *a2, u8 *state);
int func_0217C1F0(u8 *self);
int func_0217C200(u8 *a, u8 *b, int c, u8 *d);
int func_0217C2AC(Ctx *ctx, Obj_0217C2AC *obj, u8 *a2, u8 *state);
extern int d_021807E8[];
extern char d_021807E4[];


/*
 * func_021736A0 is an unlabelled ov012 thumb leaf, now filed as
 * src/matched/ov/ov012_func_021736A0.c (pkt_ov012_021736A0), which resolves its call.
 */
int func_0217BD9C(u8 *a, int b, int c, u8 *d)
{
    int *p;
    int *q;
    int x, y;
    switch (*d) {
    case 0:
        if (a[0x282E] == 0)
            return 1;
        a[0x282E] = 0;
        func_020061E4(0x54B);
        p = func_02030734(4, 12, 1, (const char *)d_021807E8, 0x41A);
        *p = (int)func_02012EBC((struct Big *)(*(int *)(((struct Obj04183 *)a)->f0 + 8)));
        *(int * *)&((struct Obj04183 *)a)->f3558 = p;
        func_0217422C(a, 0x1d, (int)p);
        (*d)++;
        break;
    case 1:
        if (func_02174268(a) == 0)
            (*d)++;
        break;
    case 2:
        q = *(int * *)&((struct Obj04183 *)a)->f3558;
        x = q[2];
        y = q[1];
        if (y == 0)
            func_021736A0(a, (volatile u16 *)x);
        func_020307B0(*(int **)(a + 0x3558));
        *(int **)(a + 0x3558) = 0;
        return 1;
    }
    return 0;
}

int func_0217BE44(void *ctx, void *unused, u8 *a)
{
    func_020061E4(0x547);
    func_0217F210(ctx, a, 0xE2);
    return 1;
}


/*
 * Addresses are Black-image addresses.
 */
int func_0217BE64(void *w, Obj_0217BE64 *obj, u8 *a2, u8 *state)
{
    int i;

    if (func_0217BB04(w) == 1) {
        return 1;
    }
    switch (*state) {
    case 0:
        func_0203D14C(1, 1, 0);
        obj->s6C = 0;
        (*state)++;
        break;
    case 1:
        if (func_0217F1EC(w) == 0) {
            break;
        }
        if (func_0203D1B4() > 1) {
            for (i = 2; i < 5; i++) {
                if ((int)func_0203D1C0((u8)i) == 1) {
                    break;
                }
            }
            if (i < 5 || func_020392B8() > 2) {
                func_0217F210(w, a2, func_0217EC04(w));
                func_0217B8E4(w, 0);
                func_02172D20(w);
                *state = 4;
            } else {
                func_0203D7BC(1);
                func_0203D1E8((u32)func_020399A8(), 0);
                *state = 2;
            }
        } else {
            obj->s6C++;
            if (obj->s6C > 600 || (func_020362DC() & 2)) {
                func_02172D20(w);
                func_0217B8E4(w, 0);
                func_021734A8(w, 1, 0);
                if (obj->s6C > 600) {
                    func_0217F210(w, a2, func_0217EC04(w));
                } else {
                    func_0217F210(w, a2, 10);
                }
                *state = 5;
            }
        }
        break;
    case 2:
        if (obj->b2A == 1) {
            if (memcmp(obj->addr, obj->p18 + 0x64, 6) != 0) {
                if (func_02173AFC(2) == 1) {
                    func_0203D7BC(0);
                    *state = 6;
                }
            } else {
                if (func_02173AFC(1) == 1) {
                    func_020061E4(0x806);
                    func_0217B8E4(w, 7);
                    func_021734A8(w, 3, (u32)obj->p18);
                    func_021734A8(w, 1, 0);
                    *state = 3;
                }
            }
        }
        break;
    case 3:
        if (func_0217F1EC(w) == 1) {
            return 1;
        }
        break;
    case 4:
        if (func_0217F1EC(w) == 1 && (func_020362DC() & 0xF3)) {
            return 1;
        }
        break;
    case 5:
        if (func_02172D68(w) == 0) {
            *state = 4;
        }
        break;
    case 6:
        if (func_020392B8() <= 1) {
            func_02172D20(w);
            (*state)++;
        }
        break;
    case 7:
        if (func_02172D68(w) == 0) {
            obj->b2A = 0;
            *state = 0;
        }
        break;
    }
    return 0;
}

/*
 * Remaining two bytes are alignment padding.
 */
int func_0217C03C(u8 *self)
{
    func_021734A8(self, 1, 0);
    return 1;
}

int func_0217C04C(void *ctx, void *unused, u8 *a)
{
    func_020061E4(0x806);
    func_0217F210(ctx, a, 7);
    func_0217BAF0(ctx, (int)a, 1);
    return 1;
}


int func_0217C074(void *ctx, Obj_0217C074 *obj, u8 *a2, u8 *state)
{
    if (func_0217BB04(ctx) == 1)
        return 1;

    switch (*state) {
    case 0:
        if (obj->f1c == 0)
            func_02034714(d_021807E4, 0, d_021807E4);
        func_0203D14C(2, 1, obj->f1c + 0x64);
        obj->f6c = 0;
        *state = 1;
        break;
    case 1:
        if (func_0203D1B4() > 1) {
            func_0203D7BC(1);
            *state = 3;
            break;
        }
        obj->f6c++;
        if (obj->f6c > 600 || (func_020362DC() & 2)) {
            func_02172D20(ctx);
            func_0217B8E4(ctx, 0);
            func_021734A8(ctx, 2, 0);
            if (obj->f6c > 600)
                func_0217F210(ctx, a2, 8);
            else
                func_0217F210(ctx, a2, 10);
            *state = 2;
        }
        break;
    case 2:
        if (func_02172D68(ctx) == 0 && func_0217F1EC(ctx) == 1 && (func_020362DC() & 0xf3))
            return 1;
        break;
    case 3:
        if (func_02173A90() == 1)
            *state = 4;
        break;
    case 4:
        switch (obj->mode) {
        case 1:
            func_021734A8(ctx, 3, (u32)obj->f1c);
            func_021734A8(ctx, 2, 0);
            func_0217B8E4(ctx, 9);
            return 1;
        case 2:
            func_021734A8(ctx, 2, 0);
            func_0217F210(ctx, a2, 8);
            func_02172D20(ctx);
            *state = 5;
            break;
        }
        break;
    case 5:
        if (func_02172D68(ctx) == 0 && func_0217F1EC(ctx) == 1 && (func_020362DC() & 0xf3)) {
            func_0217B8E4(ctx, 0);
            return 1;
        }
        break;
    }
    return 0;
}

int func_0217C1F0(u8 *self)
{
    func_021734A8(self, 2, 0);
    return 1;
}


int func_0217C200(u8 *a, u8 *b, int c, u8 *d)
{
    int r;
    if (func_0217BB04((char *)a) == 1)
        return 1;
    if (b[0x70] == 10) {
        ((struct Obj05947 *)b)->f6E = 1;
        return 1;
    }
    ((struct Obj05947 *)b)->f6E = 0;
    switch (*d) {
    case 0:
        func_02173518(b + 0x14);
        func_021734A8(a, 4, 1);
        func_021735FC(b + 0x14, (const struct Entry *)(((struct Obj05947 *)b)->f20));
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


int func_0217C2AC(Ctx *ctx, Obj_0217C2AC *obj, u8 *a2, u8 *state)
{
    void *h;
    int r;

    if (func_0217BB04((char *)ctx) == 1)
        return 1;

    switch (*state) {
    case 0:
        if (obj->f6e == 1) {
            obj->f6e = 0;
        } else if (obj->f5c == 0) {
            func_0217F210((u8 *)ctx, a2, func_0217EC1C(obj->f14->flag));
            obj->f5c++;
        } else {
            func_0217F210((u8 *)ctx, a2, func_0217EC88(obj->f14->flag));
        }
        (*state)++;
        break;
    case 1:
        if (func_0217F1EC((u8 *)ctx) == 1)
            (*state)++;
        break;
    case 2:
        func_0217F360((char *)ctx, (u32)a2);
        (*state)++;
        break;
    case 3:
        h = func_02012934((void *)ctx->sys->f8);
        r = func_0217F380(ctx, (int)a2);
        if (r == -1)
            break;
        func_0217F378(ctx);
        if (r == -2 || r == 0) {
            func_0217F210((u8 *)ctx, a2, func_0217EC28(obj->f14->flag));
            obj->f2d = 0;
            func_0217B8E4((char *)ctx, 8);
            return 1;
        }
        if (r == 0x18) {
            func_020120F4((const struct Ctx *)ctx->sys->fc);
            if ((int)func_0201AA1C(h) < 2) {
                func_0217F210((u8 *)ctx, a2, func_0217ECA0(obj->f14->flag));
                *state = 4;
                break;
            }
        } else if (r == 0x19) {
            if ((int)func_0201AAD4(h) > 0) {
                func_0217F210((u8 *)ctx, a2, func_0217ECB8((void ***)ctx));
                *state = 4;
                break;
            } else if (func_0201AA88(h) == 0) {
                func_0217F210((u8 *)ctx, a2, func_0217ECAC(obj->f14->flag));
                *state = 4;
                break;
            }
        }
        if (r == 0x1b) {
            func_0217B8E4((char *)ctx, 10);
            return 1;
        }
        obj->f2d = r;
        func_0217B8E4((char *)ctx, 8);
        return 1;
    case 4:
        if (func_0217F1EC((u8 *)ctx) == 1)
            *state = 0;
        break;
    }
    return 0;
}
