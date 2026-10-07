/*
 * file:     union_oneself_p04.c
 * unit:     yes
 * function: func_0217D314, func_0217D51C, func_0217D5B8, func_0217D7A4
 * address:  0x0217D314
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
 *   func_0217AEFC  0x0217AEFC  thumb  ov019
 *   func_0217BB04  0x0217BB04  thumb  ov019
 *   func_021736E0  0x021736E0  thumb  ov012
 *   func_0203D14C  0x0203D14C  arm
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_0217F060  0x0217F060  thumb  ov019
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_021734A8  0x021734A8  thumb  ov012
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 *   func_02034714  0x02034714  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0217EE40  0x0217EE40  thumb  ov019
 *   func_0217EE1C  0x0217EE1C  thumb  ov019
 *   func_0217EDF8  0x0217EDF8  thumb  ov019
 *   func_0217F210  0x0217F210  thumb  ov019
 *   func_02172D20  0x02172D20  thumb  ov012
 *   func_02172D68  0x02172D68  thumb  ov012
 *   d_021807E4     0x021807E4  data  a4
 *   func_02172EDC  0x02172EDC  thumb  ov012
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_02173650  0x02173650  thumb  ov012
 *   func_02172D50  0x02172D50  thumb  ov012
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02030734  0x02030734  arm
 *   func_02012934  0x02012934  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_0217422C  0x0217422C  thumb  ov012
 *   func_02174268  0x02174268  thumb  ov012
 *   func_020307B0  0x020307B0  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02173D38  0x02173D38  thumb  ov012
 *   func_0217EE10  0x0217EE10  thumb  ov019
 *   func_0217EDEC  0x0217EDEC  thumb  ov019
 *   d_021807E8     0x021807E8  data  a4
 *   func_02174F4C  0x02174F4C  thumb  ov012
 *   func_0217EC94  0x0217EC94  thumb  ov019
 *   func_0217BAF0  0x0217BAF0  thumb  ov019
 */
#include "../../matched/include/Obj00033.h"
#include "../../matched/include/Obj09412.h"

struct Link;
struct Entry;
struct BigObj;
struct Big;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

typedef struct {
    u8 pad00[7];
    u8 x0 : 3;
    u8 b3 : 1;
} Sub;

typedef struct {
    u8 pad00[0x14];
    Sub *f14;
    u8 pad18[0x2d - 0x18];
    u8 f2d;
    u8 pad2e[0x58 - 0x2e];
    u16 f58;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 pad5b[0x6c - 0x5b];
    s16 f6c;
} Obj_0217D314;

typedef struct {
    u8 f00;
    u8 f01;
    u8 pad02[0x14 - 0x02];
    Sub *f14;
    u8 pad18[0x5a - 0x18];
    u8 b0 : 1;
    u8 b1 : 1;
} Obj_0217D5B8;

typedef struct {
    u8 pad00[0x14];
    Sub *f14;
    u8 pad18[0x2d - 0x18];
    u8 f2d;
    u8 pad2e[0x5a - 0x2e];
    u8 b0 : 1;
    u8 b1 : 1;
} Obj_0217D7A4;

extern u16 func_0217AEFC(unsigned int x);
extern int func_0217BB04(char *p);
extern void func_021736E0(unsigned int x);
extern void func_0203D14C(int a, int b, u8 *c);
extern u32 func_0217F1EC(u8 *p);
extern int func_0203D1B4(void);
extern void func_0203D7BC(u8 a0);
extern int func_0217F060(int i);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern void func_021734A8(u8 *self, u32 id, u32 v);
extern int func_0217B8E4(char *p, int v);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_020362DC(void);
extern u16 func_0217EE40(int i);
extern u16 func_0217EE1C(int i);
extern u16 func_0217EDF8(int i);
extern void func_0217F210(u8 *p, u8 *a, u32 b);
extern void func_02172D20(u8 *a);
extern int func_02172D68(u8 *a);
extern void func_02172EDC(u8 *a);
extern int func_0203CDBC(void);
extern void func_02173650(int a, u8 *b);
extern void func_02172D50(u8 *a);
extern void func_02039C68(struct Link *a, unsigned int b, unsigned int c);
extern unsigned int func_02039CB4(struct Link *a, unsigned int b, unsigned int c);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
extern void *func_02012934(const struct BigObj *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_02012F2C(int *p);
extern void func_0217422C(u8 *p, int a, int b);
extern int func_02174268(u8 *a);
extern u32 func_020307B0(void *p);
extern u32 func_0200FB24(void);
extern u32 func_02173D38(u8 *p);
extern u16 func_0217EE10(int i);
extern u16 func_0217EDEC(int i);
extern int func_02174F4C(int a, int b, int c, int d);
extern u16 func_0217EC94(int i);
extern void func_0217BAF0(char *p, int x, unsigned int v);
int func_0217D314(u8 *a, Obj_0217D314 *b, u8 *c, u8 *d);
int func_0217D51C(u8 *a, int *b, int c, u8 *d);
int func_0217D5B8(u8 *a, Obj_0217D5B8 *b, u8 *c, u8 *d);
int func_0217D7A4(u8 *a, Obj_0217D7A4 *b, u8 *c, u8 *d);
extern u8 d_021807E4[];
extern u8 d_021807E8[];


int func_0217D314(u8 *a, Obj_0217D314 *b, u8 *c, u8 *d)
{
    int idx;
    int n;
    idx = func_0217AEFC(b->f58);
    if (func_0217BB04((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        b->b0 = 1;
        func_021736E0(b->f2d);
        func_0203D14C(2, 1, a + 0x2974 + idx * 0x8c);
        b->f6c = 0;
        (*d)++;
        break;
    case 1:
        if (func_0217F1EC(a) == 0)
            break;
        if (func_0203D1B4() > 1) {
            func_0203D7BC(1);
            n = func_0217F060(b->f2d);
            if (n <= (int)func_0203D1A4((struct Link *)((int)func_020399A8()))) {
                *d = 4;
            } else {
                func_021734A8(a, 3, (u32)(a + 0x2910 + idx * 0x8c));
                b->b1 = 1;
                switch (b->f2d) {
                case 0x14:
                    func_0217B8E4((char *)a, (int)0x1f);
                    break;
                case 0x15:
                    func_0217B8E4((char *)a, (int)0x20);
                    break;
                case 0x16:
                    func_0217B8E4((char *)a, (int)0x21);
                    break;
                case 0x17:
                    func_0217B8E4((char *)a, (int)0x22);
                    break;
                case 3:
                    func_0217B8E4((char *)a, (int)0xe);
                    break;
                case 0x19:
                    func_0217B8E4((char *)a, (int)0x24);
                    break;
                default:
                    func_02034714((const char *)d_021807E4, (int)0, (const char *)d_021807E4);
                    break;
                }
                *d = 3;
            }
        } else {
            b->f6c++;
            if (b->f6c > 600 || (func_020362DC() & 2)) {
                b->b0 = 0;
                func_0217B8E4((char *)a, (int)0);
                *d = 4;
            }
        }
        break;
    case 2:
        switch (b->f2d) {
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
            func_0217F210(a, c, func_0217EE40(b->f14->b3));
            break;
        case 3:
            func_0217F210(a, c, func_0217EE1C(b->f14->b3));
            break;
        case 0x19:
            func_0217F210(a, c, func_0217EDF8(b->f14->b3));
            break;
        }
        *d = 3;
        break;
    case 3:
        if (func_0217F1EC(a) == 1)
            return 1;
        break;
    case 4:
        func_02172D20(a);
        (*d)++;
        break;
    case 5:
        if (func_02172D68(a) == 0)
            *d = 2;
        break;
    }
    return 0;
}


int func_0217D51C(u8 *a, int *b, int c, u8 *d)
{
    int r, t;
    if (*d < 3 && func_0217BB04((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        func_02172EDC(a);
        (*d)++;
        break;
    case 1:
        if (func_02172D68(a) != 0)
            break;
        r = func_0203CDBC();
        if (r == 1) {
            t = b[8];
            if (t != 0) {
                func_02173650((int)((u8 *)(b + 5)), (u8 *)t);
                func_021734A8(a, 3, 0);
            }
            func_02172D50(a);
            (*d)++;
        }
        break;
    case 2:
        if (func_02172D68(a) == 0)
            (*d)++;
        break;
    case 3:
        if (func_0217F1EC(a) == 1) {
            if (func_020362DC() & 0xf3)
                return 1;
        }
        break;
    }
    return 0;
}


int func_0217D5B8(u8 *a, Obj_0217D5B8 *b, u8 *c, u8 *d)
{
    int *p;
    if (*d != 4 && *d != 5 && *d != 8 && func_0217BB04((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        if (b->b1 == 1)
            *d = 6;
        else
            (*d)++;
        break;
    case 1:
        func_02039C68((struct Link *)func_020399A8(), 8, 0x14);
        (*d)++;
        break;
    case 2:
        if (func_02039CB4((struct Link *)func_020399A8(), 8, 0x14) == 1)
            (*d)++;
        break;
    case 3:
        if (func_0217F1EC(a) == 1) {
            if (b->f01 == 0xe) {
                p = func_02030734(0x41, 8, 1, (const char *)d_021807E8, 0xB9A);
                p[1] = (*(int **)a)[2];
                *(int * *)&((struct Obj00033 *)a)->f3558 = p;
                func_0217422C(a, 3, (int)p);
            } else {
                p = func_02030734(0x41, 0x18, 1, (const char *)d_021807E8, 0xBA2);
                p[1] = (*(int **)a)[2];
                p[2] = (int)func_02012934((void *)(*(int **)a)[2]);
                p[3] = (int)func_02012EBC((struct Big *)((*(int **)a)[2]));
                p[4] = (int)func_02012F2C((int *)((*(int **)a)[2]));
                *(int * *)&((struct Obj00033 *)a)->f3558 = p;
                func_0217422C(a, 4, (int)p);
            }
            (*d)++;
        }
        break;
    case 4:
        if (func_02174268(a) == 0) {
            func_020307B0(*(int * *)&((struct Obj00033 *)a)->f3558);
            *(int * *)&((struct Obj00033 *)a)->f3558 = 0;
            if (func_0200FB24() != 0) {
                func_0217B8E4((char *)a, 1);
                return 1;
            }
            func_02172D50(a);
            (*d)++;
        }
        break;
    case 5:
        if (func_02172D68(a) == 0)
            return 1;
        break;
    case 6:
        if (func_02173D38(a) == 1)
            (*d)++;
        break;
    case 7:
        switch (a[0x282B]) {
        case 1:
            if (b->f01 == 0xe)
                func_0217F210(a, c, func_0217EE10(b->f14->b3));
            else
                func_0217F210(a, c, func_0217EDEC(b->f14->b3));
            *d = 3;
            break;
        case 2:
            if (b->f01 == 0xe)
                func_0217F210(a, c, func_0217EE1C(b->f14->b3));
            else
                func_0217F210(a, c, func_0217EDF8(b->f14->b3));
            func_02172D20(a);
            *d = 8;
            break;
        }
        break;
    case 8:
        if (func_0217F1EC(a) == 1 && func_02172D68(a) == 0) {
            func_021734A8(a, 3, 0);
            return 1;
        }
        break;
    }
    return 0;
}


int func_0217D7A4(u8 *a, Obj_0217D7A4 *b, u8 *c, u8 *d)
{
    int *p;
    if (*d < 4 && func_0217BB04((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        if (((struct Obj09412 *)a)->f355C != 0)
            func_02034714((const char *)d_021807E4, 0, (const char *)d_021807E4);
        p = *(int * *)&((struct Obj09412 *)a)->f0;
        ((struct Obj09412 *)a)->f355C = func_02174F4C(p[2], p[3], p[0], b->b1);
        func_0217F210(a, c, func_0217EC94(b->f14->b3));
        (*d)++;
        break;
    case 1:
        if (func_0217F1EC(a) == 1)
            (*d)++;
        break;
    case 2:
        func_02039C68((struct Link *)func_020399A8(), 0xb, 0x14);
        (*d)++;
        break;
    case 3:
        if (func_02039CB4((struct Link *)func_020399A8(), 0xb, 0x14) == 1)
            (*d)++;
        break;
    case 4:
        func_0217422C(a, b->f2d + 1, 0);
        (*d)++;
        break;
    case 5:
        if (func_02174268(a) == 0) {
            func_0217BAF0((char *)a, (int)c, 1);
            func_0217B8E4((char *)a, 0x28);
            return 1;
        }
        break;
    }
    return 0;
}
