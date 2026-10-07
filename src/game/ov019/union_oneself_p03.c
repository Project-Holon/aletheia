/*
 * file:     union_oneself_p03.c
 * unit:     yes
 * function: func_0217CEB8, func_0217CFA8, func_0217D18C
 * address:  0x0217CEB8
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
 *   func_0217AF04  0x0217AF04  thumb ov019
 *   func_0217AEFC  0x0217AEFC  thumb ov019
 *   func_0217ED04  0x0217ED04  thumb ov019
 *   func_0217ED10  0x0217ED10  thumb ov019
 *   func_0217ECE8  0x0217ECE8  thumb ov019
 *   func_0217ED64  0x0217ED64  thumb ov019
 *   func_0217ED2C  0x0217ED2C  thumb ov019
 *   func_0217ED48  0x0217ED48  thumb ov019
 *   func_0217F210  0x0217F210  thumb ov019
 *   func_0217B8E4  0x0217B8E4  thumb ov019
 *   func_0217F1EC  0x0217F1EC  thumb ov019
 *   func_020362DC  0x020362DC  arm
 *   func_0217BB04  0x0217BB04  thumb  ov019
 *   func_02034714  0x02034714  arm
 *   func_02030734  0x02030734  arm
 *   func_0216F40C  0x0216F40C  thumb  ov010
 *   func_02082D44  0x02082D44  arm
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0217EE4C  0x0217EE4C  thumb  ov019
 *   func_02173BB0  0x02173BB0  thumb  ov012
 *   func_0216F7F4  0x0216F7F4  thumb  ov010
 *   func_0217422C  0x0217422C  thumb  ov012
 *   func_02174268  0x02174268  thumb  ov012
 *   func_020307B0  0x020307B0  arm
 *   func_0203D378  0x0203D378  arm
 *   d_021807E4     0x021807E4  data  a4
 *   d_021807E8     0x021807E8  data  a4
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200ED48  0x0200ED48  thumb
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02012950  0x02012950  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0200ED54  0x0200ED54  thumb
 *   func_0201A920  0x0201A920  thumb
 */
#include "../../matched/include/Obj00610.h"
#include "../../matched/include/Obj07385.h"

struct Profile;
struct Entry;
struct Link;
struct Big;
struct Ctx;
struct L0200ED54;
struct Party;
struct Rec44;
struct Sub0200852CObj;
struct Sub24;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 pad00[0x58];
    u16 f58;
} Obj_0217CEB8;

typedef struct {
    u8 pad00[0x14];
    u8 *f14;
    u8 pad18[0x5d - 0x18];
    u8 f5d;
} Obj_0217CFA8;

typedef struct {
    int f00;
    int f04;
    u16 f08;
    u8 f0a;
    u8 f0b;
    int f0c;
    int f10;
} Rec14;

typedef struct {
    u8 pad00[8];
    int f08;
    u8 pad0c[0x14 - 0x0c];
    int f14;
    int pad18;
    int f1c;
    Rec14 *f20;
} Rec30;

int func_0217AF04(u8 *a, u16 key);
u16 func_0217AEFC(unsigned int x);
u16 func_0217ED04(int i);
u16 func_0217ED10(int i);
u16 func_0217ECE8(int i);
u16 func_0217ED64(int i);
u16 func_0217ED2C(int i);
u16 func_0217ED48(int i);
void func_0217F210(u8 *p, u8 *a, u32 b);
int func_0217B8E4(char *p, int v);
u32 func_0217F1EC(u8 *p);
u32 func_020362DC(void);
extern int func_0217BB04(char *p);
extern void func_02034714(const char *expr, unsigned int line, const char *file);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void func_0216F40C(struct Profile *out, void *save, int mode, int flag, volatile u16 heap);
extern void func_02082D44(void *a, void *b, int c);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *a, unsigned int b, unsigned int c);
extern unsigned int func_02039CB4(struct Link *a, unsigned int b, unsigned int c);
extern int func_0217EE4C(int **p, int x, int y);
extern u32 func_02173BB0(unsigned char *p);
extern void *func_0216F7F4(int a, void *b, int c);
extern void func_0217422C(u8 *p, int a, int b);
extern int func_02174268(u8 *a);
extern u32 func_020307B0(void *p);
extern u32 func_0203D378(void);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200ED48(void *p);
extern u32 func_0203D1A4(struct Link *p);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
extern struct Party *func_0201A920(u32 heap);
int func_0217CEB8(void *ctx, Obj_0217CEB8 *obj, u8 *a2, u8 *state);
int func_0217CFA8(u8 *a, Obj_0217CFA8 *b, u8 *c, u8 *d);
int func_0217D18C(u8 *a, int b, u8 *c, u8 *d);
extern u8 d_021807E4[];
extern u8 d_021807E8[];


int func_0217CEB8(void *ctx, Obj_0217CEB8 *obj, u8 *a2, u8 *state)
{
    int r;

    switch (*state) {
    case 0:
        r = func_0217AF04(ctx, obj->f58);
        switch (((u8 *)ctx + func_0217AEFC(obj->f58) * 0x8c)[0x291b]) {
        case 1:
            func_0217F210(ctx, a2, func_0217ED04(r));
            break;
        case 2:
            func_0217F210(ctx, a2, func_0217ED10(r));
            break;
        case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11:
        case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
        case 20: case 21: case 22: case 23:
            func_0217F210(ctx, a2, func_0217ECE8(r));
            break;
        case 25:
            func_0217F210(ctx, a2, func_0217ED64(r));
            break;
        case 3:
            func_0217F210(ctx, a2, func_0217ED2C(r));
            break;
        case 24:
            func_0217F210(ctx, a2, func_0217ED48(r));
            break;
        case 0:
        default:
            func_0217F210(ctx, a2, 0x151);
            break;
        }
        func_0217B8E4(ctx, 0);
        (*state)++;
        break;
    case 1:
        if (func_0217F1EC(ctx) == 1 && (func_020362DC() & 0xf3))
            return 1;
        break;
    }
    return 0;
}


int func_0217CFA8(u8 *a, Obj_0217CFA8 *b, u8 *c, u8 *d)
{
    u8 *q;
    if (func_0217BB04((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        if (((struct Obj00610 *)a)->f3540 != 0 || ((struct Obj00610 *)a)->f3544 != 0)
            func_02034714((const char *)d_021807E4, 0, (const char *)d_021807E4);
        ((struct Obj00610 *)a)->f3540 = func_02030734(0x41, 0x678, 1, (const char *)d_021807E8, 0x9B3);
        ((struct Obj00610 *)a)->f3544 = func_02030734(0x41, 0x678, 1, (const char *)d_021807E8, 0x9B5);
        func_0216F40C(((struct Obj00610 *)a)->f3540, (void *)((*(int **)a)[2]), 1, 0, 0x41);
        func_02082D44(((struct Obj00610 *)a)->f3540, ((struct Obj00610 *)a)->f3544, 0x678);
        func_02039C68((struct Link *)func_020399A8(), 3, 0x14);
        func_0217F210(a, c, func_0217EE4C((int **)a, b->f14[0x26], b->f14[0x27]));
        (*d)++;
        break;
    case 1:
        if (func_02039CB4((struct Link *)func_020399A8(), 3, 0x14) == 1)
            (*d)++;
        break;
    case 2:
        if (func_02173BB0(a) == 1)
            (*d)++;
        break;
    case 3:
        if (b->f5d == 1 && func_0217F1EC(a) == 1) {
            q = *(u8 * *)&((struct Obj00610 *)a)->f3544;
            q[4] |= 0x20;
            ((struct Obj00610 *)a)->f353C = func_0216F7F4((*(int **)a)[2], ((struct Obj00610 *)a)->f3544, 0x41);
            (*d)++;
        }
        break;
    case 4:
        func_02039C68((struct Link *)func_020399A8(), 4, 0x14);
        (*d)++;
        break;
    case 5:
        if (func_02039CB4((struct Link *)func_020399A8(), 4, 0x14) == 1)
            (*d)++;
        break;
    case 6:
        func_0217422C(a, 1, (int)(((struct Obj00610 *)a)->f353C));
        (*d)++;
        break;
    case 7:
        if (func_02174268(a) == 0)
            (*d)++;
        break;
    case 8:
        func_0217F210(a, c, 0x10);
        func_02039C68((struct Link *)func_020399A8(), 5, 0x14);
        (*d)++;
        break;
    case 9:
        if (func_0217F1EC(a) != 0 && func_02039CB4((struct Link *)func_020399A8(), 5, 0x14) == 1) {
            func_020307B0(((struct Obj00610 *)a)->f3540);
            func_020307B0(((struct Obj00610 *)a)->f3544);
            ((struct Obj00610 *)a)->f353C = 0;
            ((struct Obj00610 *)a)->f3540 = 0;
            ((struct Obj00610 *)a)->f3544 = 0;
            if (func_0203D378() == 1)
                func_0217B8E4((char *)a, 7);
            else
                func_0217B8E4((char *)a, 9);
            return 1;
        }
        break;
    }
    return 0;
}


int func_0217D18C(u8 *a, int b, u8 *c, u8 *d)
{
    int x, y;
    Rec30 *p;
    Rec14 *q;
    if (*d != 4 && func_0217BB04((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        func_0217F210(a, c, 0x26);
        (*d)++;
        break;
    case 1:
        if (func_0217F1EC(a) == 1) {
            func_02039C68((struct Link *)func_020399A8(), 6, 0x14);
            (*d)++;
        }
        break;
    case 2:
        if (func_02039CB4((struct Link *)func_020399A8(), 6, 0x14) == 1) {
            x = (int)func_020120F4((const struct Ctx *)((*(int **)a)[3]));
            y = (int)func_0200ED48(func_02012EBC((struct Big *)x));
            func_0200ED54((struct L0200ED54 *)y, func_02008530((const struct Sub0200852CObj *)func_02012950((struct Sub24 *)x, func_0203D1A4((struct Link *)((int)func_020399A8())) ^ 1)));
            (*d)++;
        }
        break;
    case 3:
        p = func_02030734(0x41, 0x30, 1, (const char *)d_021807E8, 0xA54);
        p->f14 = (int)func_020120F4((const struct Ctx *)((*(int **)a)[3]));
        p->f1c = (int)func_0201A920(0x41);
        q = func_02030734(4, 0x14, 0, (const char *)d_021807E8, 0xA5B);
        q->f00 = p->f14;
        q->f04 = p->f1c;
        q->f08 = 0;
        q->f0a = 0;
        q->f0b = 0;
        q->f0c = 1;
        q->f10 = 0;
        p->f20 = q;
        p->f08 = 0;
        *(Rec30 * *)&((struct Obj07385 *)a)->f3558 = p;
        func_0217422C(a, 2, (int)p);
        (*d)++;
        break;
    case 4:
        if (func_02174268(a) == 0) {
            p = *(Rec30 * *)&((struct Obj07385 *)a)->f3558;
            func_020307B0(p->f20);
            func_020307B0((void *)p->f1c);
            func_020307B0(*(Rec30 * *)&((struct Obj07385 *)a)->f3558);
            *(Rec30 * *)&((struct Obj07385 *)a)->f3558 = 0;
            (*d)++;
        }
        break;
    case 5:
        func_0217F210(a, c, 0x10);
        func_02039C68((struct Link *)func_020399A8(), 7, 0x14);
        (*d)++;
        break;
    case 6:
        if (func_0217F1EC(a) != 0 && func_02039CB4((struct Link *)func_020399A8(), 7, 0x14) == 1) {
            if (func_0203D378() == 1)
                func_0217B8E4((char *)a, 7);
            else
                func_0217B8E4((char *)a, 9);
            return 1;
        }
        break;
    }
    return 0;
}
