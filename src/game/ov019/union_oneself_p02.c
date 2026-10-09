/*
 * file:     union_oneself_p02.c
 * unit:     yes
 * function: func_0217C88C, func_0217CAAC, func_0217CEB8, func_0217CFA8, func_0217D18C, func_0217D314, func_0217D51C, func_0217D5B8, func_0217D7A4, func_0217D890, func_0217D9A8, func_0217DC64
 * address:  0x0217C88C
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
 *   func_0217BB04  0x0217BB04  thumb ov019
 *   func_0217F1EC  0x0217F1EC  thumb ov019
 *   func_0217F5E0  0x0217F5E0  thumb ov019
 *   func_0217F624  0x0217F624  thumb ov019
 *   func_0217F388  0x0217F388  thumb ov019
 *   func_0217F4B4  0x0217F4B4  thumb ov019
 *   func_0217F4AC  0x0217F4AC  thumb ov019
 *   func_0217BA10  0x0217BA10  thumb ov019
 *   func_0217BAA8  0x0217BAA8  thumb ov019
 *   func_0217F210  0x0217F210  thumb ov019
 *   func_0217B8E4  0x0217B8E4  thumb ov019
 *   func_0217B974  0x0217B974  thumb ov019
 *   func_0217F640  0x0217F640  thumb ov019
 *   func_0217F794  0x0217F794  thumb ov019
 *   func_0217F7B8  0x0217F7B8  thumb ov019
 *   func_0217EC88  0x0217EC88  thumb ov019
 *   func_020362DC  0x020362DC  arm
 *   func_0217AEFC 0x0217AEFC thumb ov019
 *   func_0217ED04 0x0217ED04 thumb ov019
 *   func_0217ED10 0x0217ED10 thumb ov019
 *   func_0217ECE8 0x0217ECE8 thumb ov019
 *   func_0217ED80 0x0217ED80 thumb ov019
 *   func_0217ED8C 0x0217ED8C thumb ov019
 *   func_0217ED64 0x0217ED64 thumb ov019
 *   func_0217ED98 0x0217ED98 thumb ov019
 *   func_0217ED2C 0x0217ED2C thumb ov019
 *   func_0217ED48 0x0217ED48 thumb ov019
 *   func_0217EDA4 0x0217EDA4 thumb ov019
 *   func_0217EE28 0x0217EE28 thumb ov019
 *   func_0217EDBC 0x0217EDBC thumb ov019
 *   func_0217EDB0 0x0217EDB0 thumb ov019
 *   func_0217EE04 0x0217EE04 thumb ov019
 *   func_0217EDD4 0x0217EDD4 thumb ov019
 *   func_0217EDC8 0x0217EDC8 thumb ov019
 *   func_0217EDE0 0x0217EDE0 thumb ov019
 *   func_0217F060 0x0217F060 thumb ov019
 *   func_0217F22C 0x0217F22C thumb ov019
 *   func_0217F268 0x0217F268 thumb ov019
 *   func_0217F24C 0x0217F24C thumb ov019
 *   func_02012934 0x02012934 thumb
 *   func_0201AAD4 0x0201AAD4 thumb
 *   func_0201AA88 0x0201AA88 thumb
 *   func_0217AF04  0x0217AF04  thumb ov019
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
 *   func_021736E0  0x021736E0  thumb  ov012
 *   func_0203D14C  0x0203D14C  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_021734A8  0x021734A8  thumb  ov012
 *   func_0217EE40  0x0217EE40  thumb  ov019
 *   func_0217EE1C  0x0217EE1C  thumb  ov019
 *   func_0217EDF8  0x0217EDF8  thumb  ov019
 *   func_02172D20  0x02172D20  thumb  ov012
 *   func_02172D68  0x02172D68  thumb  ov012
 *   func_02172EDC  0x02172EDC  thumb  ov012
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_02173650  0x02173650  thumb  ov012
 *   func_02172D50  0x02172D50  thumb  ov012
 *   func_02012F2C  0x02012F2C  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02173D38  0x02173D38  thumb  ov012
 *   func_0217EE10  0x0217EE10  thumb  ov019
 *   func_0217EDEC  0x0217EDEC  thumb  ov019
 *   func_02174F4C  0x02174F4C  thumb  ov012
 *   func_0217EC94  0x0217EC94  thumb  ov019
 *   func_0217BAF0  0x0217BAF0  thumb  ov019
 *   func_0217EE34  0x0217EE34  thumb  ov019
 *   func_0203D1E8  0x0203D1E8  arm
 *   func_02012944  0x02012944  thumb
 *   func_0217BB20  0x0217BB20  thumb  ov019
 *   func_0217F074  0x0217F074  thumb  ov019
 *   func_0217DC94  0x0217DC94  thumb  ov019
 *   func_02173CB4  0x02173CB4  thumb  ov012
 *   func_021CD48C  0x021CD48C  thumb  ov021
 *   func_021CD5A4  0x021CD5A4  thumb  ov021
 *   func_021CD60C  0x021CD60C  thumb  ov021
 *   func_021CD688  0x021CD688  thumb  ov021
 *   func_02008554  0x02008554  thumb
 *   func_02008550  0x02008550  thumb
 *   func_0217357C  0x0217357C  thumb  ov012
 */
#include "../../matched/include/Obj00610.h"
#include "../../matched/include/Obj07385.h"
#include "../../matched/include/Obj00033.h"
#include "../../matched/include/Obj09412.h"
#include "../../matched/include/Obj09414.h"
#include "../../matched/include/Obj07386.h"

struct Self;
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
struct BigObj;
typedef unsigned char u8;

typedef short s16;

typedef unsigned int u32;

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
    u8 pad2e[0x60 - 0x2e];
    int f60;
    int f64;
    int f68;
    u8 pad6c[0x6e - 0x6c];
    s16 f6e;
} Obj_0217C88C;

typedef unsigned short u16;

typedef struct { u8 pad[7]; u8 lo:3; u8 flag:1; } Sub_0217CAAC;

typedef struct {
    u8 pad00[0x14]; Sub_0217CAAC *f14;
    u8 pad18[0x2d-0x18]; u8 f2d, f2e;
    u8 pad2f[0x58-0x2f]; u16 f58;
    u8 pad5a[0x64-0x5a]; int f64, f68;
} Obj_0217CAAC;

typedef struct { u8 count:3; u8 flag:1; } Bits;

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

typedef struct {
    u8 pad00[7];
    u8 x0 : 3;
    u8 b3 : 1;
} Sub_0217CEB8;

typedef struct {
    u8 pad00[0x14];
    Sub_0217CEB8 *f14;
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
    Sub_0217CEB8 *f14;
    u8 pad18[0x5a - 0x18];
    u8 b0 : 1;
    u8 b1 : 1;
} Obj_0217D5B8;

typedef struct {
    u8 pad00[0x14];
    Sub_0217CEB8 *f14;
    u8 pad18[0x2d - 0x18];
    u8 f2d;
    u8 pad2e[0x5a - 0x2e];
    u8 b0 : 1;
    u8 b1 : 1;
} Obj_0217D7A4;

typedef struct {
    u8 pad00[0x14];
    Sub_0217CEB8 *f14;
    u8 pad18[0x2d - 0x18];
    u8 f2d;
    u8 pad2e[0x5a - 0x2e];
    u8 b0 : 1;
    u8 b1 : 1;
} Obj_0217D890;

typedef struct {
    u8 f00;
    u8 pad01[0x2d - 1];
    u8 f2d;
    u8 pad2e[0x5a - 0x2e];
    u8 b0 : 1;
    u8 b1 : 1;
} Obj_0217D9A8;

typedef struct {
    u8 pad00[8];
    int f8;
} Sys;

typedef struct {
    Sys *sys;
} Ctx;

typedef struct {
    u8 pad000[0xde];
    u8 fde;
    u8 pad0df[0x168 - 0xdf];
    int f168;
    u8 pad16c[0x16e - 0x16c];
    u8 f16e;
} Work;

int func_0217BB04(char *p);
u32 func_0217F1EC(u8 *p);
void func_0217F5E0(char *p, u32 a1);
void func_0217F624(char *p);
void func_0217F388(char *p, int a1, int kind, u8 *arg);
int func_0217F4B4(char *p, int *hit, u8 *st, int *flag, u32 a4);
void func_0217F4AC(void *ctx);
void func_0217BA10(char *p, int x);
int func_0217BAA8(int a, int b, int *p, int *q);
void func_0217F210(u8 *p, u8 *a, u32 b);
int func_0217B8E4(char *p, int v);
int func_0217B974(int id);
void func_0217F640(struct Self *self, u32 a1, u32 mask, int mode, int msg);
u32 func_0217F794(char *p, u32 a);
void func_0217F7B8(char *p);
u16 func_0217EC88(int i);
u32 func_020362DC(void);
u16 func_0217AEFC(u32);
u16 func_0217ED04(int);
u16 func_0217ED10(int);
u16 func_0217ECE8(int);
u16 func_0217ED80(int);
u16 func_0217ED8C(int);
u16 func_0217ED64(int);
u16 func_0217ED98(int);
u16 func_0217ED2C(int);
u16 func_0217ED48(int);
u16 func_0217EDA4(int);
u16 func_0217EE28(int);
u16 func_0217EDBC(int);
u16 func_0217EDB0(int);
u16 func_0217EE04(int);
u16 func_0217EDD4(int);
u16 func_0217EDC8(int);
u16 func_0217EDE0(int);
int func_0217F060(int i);
void func_0217F22C(u8 *, u32);
int func_0217F268(u8 *, u32 *);
void func_0217F24C(u8 *);
void *func_02012934(void *);
u32 func_0201AAD4(void *p);
int func_0201AA88(void *);
int func_0217AF04(u8 *a, u16 key);
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
extern void func_021736E0(unsigned int x);
extern void func_0203D14C(int a, int b, u8 *c);
extern int func_0203D1B4(void);
extern void func_0203D7BC(u8 a0);
extern void func_021734A8(u8 *self, u32 id, u32 v);
extern u16 func_0217EE40(int i);
extern u16 func_0217EE1C(int i);
extern u16 func_0217EDF8(int i);
extern void func_02172D20(u8 *a);
extern int func_02172D68(u8 *a);
extern void func_02172EDC(u8 *a);
extern int func_0203CDBC(void);
extern void func_02173650(int a, u8 *b);
extern void func_02172D50(u8 *a);
extern void *func_02012F2C(int *p);
extern u32 func_0200FB24(void);
extern u32 func_02173D38(u8 *p);
extern u16 func_0217EE10(int i);
extern u16 func_0217EDEC(int i);
extern int func_02174F4C(int a, int b, int c, int d);
extern u16 func_0217EC94(int i);
extern void func_0217BAF0(char *p, int x, unsigned int v);
extern u16 func_0217EE34(int i);
extern void func_0203D1E8(u32 unused, void *arg);
extern u8 *func_02012944(void *p);
extern int func_0217BB20(char *p);
extern void func_0217F074(void *p);
extern void func_0217DC94(u8 *base, int obj, int x);
extern int func_02173CB4(void);
extern int func_021CD48C(int a, int b, int c, int d, int e, int f, int g, int h);
extern u32 func_021CD5A4(u32 *p);
extern void func_021CD60C(int h, void *a, void *b, void *c);
extern u32 func_021CD688(u8 *p);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_0217357C(u8 *p, int a, int b, int c);
int func_0217C88C(void *ctx, Obj_0217C88C *obj, u8 *a2, u8 *state);
int func_0217CAAC(u8 *ctx, Obj_0217CAAC *obj, u8 *a, u8 *state);
int func_0217CEB8(void *ctx, Obj_0217CEB8 *obj, u8 *a2, u8 *state);
int func_0217CFA8(u8 *a, Obj_0217CFA8 *b, u8 *c, u8 *d);
int func_0217D18C(u8 *a, int b, u8 *c, u8 *d);
int func_0217D314(u8 *a, Obj_0217D314 *b, u8 *c, u8 *d);
int func_0217D51C(u8 *a, int *b, int c, u8 *d);
int func_0217D5B8(u8 *a, Obj_0217D5B8 *b, u8 *c, u8 *d);
int func_0217D7A4(u8 *a, Obj_0217D7A4 *b, u8 *c, u8 *d);
int func_0217D890(u8 *a, Obj_0217D890 *b, u8 *c, u8 *d);
int func_0217D9A8(Ctx *ctx, Obj_0217D9A8 *obj, u8 *a2, u8 *state);
void func_0217DC64(u8 *base, int obj, int x);
extern u8 d_021807E4[];
extern u8 d_021807E8[];


int func_0217C88C(void *ctx, Obj_0217C88C *obj, u8 *a2, u8 *state)
{
    int f0c;
    int f08;
    int r;

    if (func_0217BB04(ctx) == 1)
        return 1;
    if (func_0217F1EC(ctx) == 0)
        return 0;

    switch (*state) {
    case 0:
        obj->f6e = 0;
        (*state)++;
        break;
    case 1:
        if (obj->f6e == 5)
            func_0217F5E0(ctx, (u32)a2);
        else if (obj->f6e == 0)
            func_0217F624(ctx);
        func_0217F388(ctx, (int)a2, obj->f6e, (u8 *)(&obj->f60));
        (*state)++;
        break;
    case 2:
        r = func_0217F4B4(ctx, &f0c, (u8 *)(&obj->f60), &f08, (u32)a2);
        if (f0c == 1) {
            obj->f6e = r;
            func_0217F4AC(ctx);
            (*state)--;
        } else if (r == -2 || r == 0) {
            func_0217F4AC(ctx);
            if (obj->f6e > 0) {
                obj->f6e = 0;
                (*state)--;
            } else {
                func_0217F624(ctx);
                func_0217B8E4(ctx, 7);
                return 1;
            }
        } else if (f08 == 1) {
            func_0217F624(ctx);
            func_0217F4AC(ctx);
            func_0217BA10(ctx, r);
            obj->f2d = r;
            *state = 3;
        } else if (r != -1) {
            func_0217F624(ctx);
            func_0217F4AC(ctx);
            if (func_0217BAA8((int)ctx, r, &obj->f64, &obj->f68) == 0) {
                func_0217F210(ctx, a2, 0x13e);
                *state = 5;
            } else {
                obj->f2d = r;
                func_0217B8E4(ctx, 8);
                return 1;
            }
        }
        break;
    case 3:
        func_0217F640(ctx, (u32)a2, 0, func_0217B974(obj->f2d), 0);
        (*state)++;
        break;
    case 4:
        if (func_0217F794(ctx, (u32)a2) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8(ctx);
            *state = 1;
        }
        break;
    case 5:
        func_0217F640(ctx, (u32)a2, obj->f64, func_0217B974(obj->f2d), 1);
        (*state)++;
        break;
    case 6:
        if (func_0217F794(ctx, (u32)a2) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8(ctx);
            if (obj->f68 == -1)
                *state = 9;
            else
                (*state)++;
        }
        break;
    case 7:
        func_0217F640(ctx, (u32)a2, obj->f64, func_0217B974(obj->f2d), 2);
        (*state)++;
        break;
    case 8:
        if (func_0217F794(ctx, (u32)a2) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8(ctx);
            *state = 9;
        }
        break;
    case 9:
        func_0217F210(ctx, a2, func_0217EC88(obj->f14->flag));
        *state = 0;
        break;
    }
    return 0;
}


int func_0217CAAC(u8 *ctx, Obj_0217CAAC *obj, u8 *a, u8 *state)
{
    int offset, id;
    u32 selected, selected2;
    void *save;
    offset = func_0217AEFC(obj->f58) * 0x8c;
    id = (ctx + offset)[0x291b];
    switch (*state) {
    case 0:
        obj->f2d = id;
        switch (id) {
        case 1: func_0217F210(ctx,a,func_0217ED04(obj->f14->flag)); func_0217B8E4((char *)ctx, 0); *state=2; goto done;
        case 2: func_0217F210(ctx,a,func_0217ED10(obj->f14->flag)); func_0217B8E4((char *)ctx, 0); *state=2; goto done;
        case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11:
        case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
            func_0217F210(ctx,a,func_0217ECE8(obj->f14->flag)); func_0217B8E4((char *)ctx, 0); *state=2; goto done;
        case 20: case 21: case 22: case 23:
            if ((int)((Bits *)((ctx + offset) + 0x2916))->count < func_0217F060(id)) {
                func_0217F210(ctx,a,func_0217ED80(obj->f14->flag));
                func_0217BA10((char *)ctx,id);
                func_0217F640((struct Self *)ctx,(int)a,(int)0,func_0217B974(id),0);
                *state = 3;
                goto done;
            }
            func_0217F210(ctx,a,func_0217ECE8(obj->f14->flag));
            func_0217B8E4((char *)ctx, 0); *state=2; goto done;
        case 25:
            if ((int)((Bits *)(ctx + 0x2916 + offset))->count < func_0217F060(id) &&
                ((Bits *)(ctx + 0x2916 + offset))->flag == 0) {
                func_0217F210(ctx,a,func_0217ED8C(obj->f14->flag));
                *state = 10;
                goto done;
            }
            func_0217F210(ctx,a,func_0217ED64(obj->f14->flag)); func_0217B8E4((char *)ctx, 0); *state=2; goto done;
        case 3:
            if ((int)((Bits *)((ctx + offset) + 0x2916))->count < func_0217F060(id)) {
                func_0217F210(ctx,a,func_0217ED98(obj->f14->flag));
                *state = 10;
                goto done;
            }
            func_0217F210(ctx,a,func_0217ED2C(obj->f14->flag)); func_0217B8E4((char *)ctx, 0); *state=2; goto done;
        case 24: func_0217F210(ctx,a,func_0217ED48(obj->f14->flag)); func_0217B8E4((char *)ctx, 0); *state=2; goto done;
        case 0: default: func_0217F210(ctx,a,0x151); func_0217B8E4((char *)ctx, 0); *state=2; goto done;
        }
        break;
    case 2:
        if (func_0217F1EC(ctx) == 1 && (func_020362DC() & 0xf3)) return 1;
        break;
    case 1:
        if (func_0217F1EC(ctx) == 1) return 1;
        break;
    case 3:
        if (func_0217F794((char *)ctx,(u32)a) == 1) *state = 4;
        break;
    case 4:
        if (func_0217F1EC(ctx) == 1) {
            func_0217F7B8((char *)ctx); func_0217F22C(ctx,(u32)a); (*state)++;
        }
        break;
    case 5:
        if (func_0217F268(ctx,&selected) == 1) {
            func_0217F24C(ctx);
            if (selected == 0) {
                func_0217F210(ctx,a,func_0217EDA4(obj->f14->flag));
                func_0217B8E4((char *)ctx, 0); *state = 2;
            } else if (func_0217BAA8((int)ctx,obj->f2d,&obj->f64,&obj->f68) == 0) {
                func_0217F210(ctx,a,0x13e); func_0217B8E4((char *)ctx, 0); *state = 6;
            } else {
                obj->f2e = selected; func_0217B8E4((char *)ctx, 0x26);
                func_0217F210(ctx,a,func_0217EE28(obj->f14->flag)); *state = 1;
            }
        }
        break;
    case 6:
        if (func_0217F1EC(ctx) == 1) return 1;
        func_0217F640((struct Self *)ctx,(int)a,(int)obj->f64,func_0217B974(obj->f2d),1); (*state)++;
        break;
    case 7:
        if (func_0217F794((char *)ctx,(u32)a) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8((char *)ctx);
            if (obj->f68 == -1) *state = 1; else (*state)++;
        }
        break;
    case 8:
        func_0217F640((struct Self *)ctx,(int)a,(int)obj->f64,func_0217B974(obj->f2d),2); (*state)++;
        break;
    case 9:
        if (func_0217F794((char *)ctx,(u32)a) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8((char *)ctx); *state = 1;
        }
        break;
    case 10:
        if (func_0217F1EC(ctx) == 1) {
            func_0217F22C(ctx,(u32)a); (*state)++;
        }
        break;
    case 11:
        if (func_0217F268(ctx,&selected2) == 1) {
            func_0217F24C(ctx);
            if (selected2 == 0) {
                switch (obj->f2d) {
                case 3: func_0217F210(ctx,a,func_0217EDBC(obj->f14->flag)); break;
                case 25: func_0217F210(ctx,a,func_0217EDB0(obj->f14->flag)); break;
                }
                func_0217B8E4((char *)ctx, 0); *state = 2;
            } else {
                obj->f2e = selected2; func_0217B8E4((char *)ctx, 0x26); *state = 1;
                switch (obj->f2d) {
                case 3: func_0217F210(ctx,a,func_0217EE04(obj->f14->flag)); break;
                case 25:
                    save = func_02012934((void *)(*(u32 **)ctx)[2]);
                    if ((int)func_0201AAD4(save) > 0) {
                        func_0217F210(ctx,a,func_0217EDD4(obj->f14->flag));
                        func_0217B8E4((char *)ctx, 0); *state = 2;
                    } else if (func_0201AA88(save) == 0) {
                        func_0217F210(ctx,a,func_0217EDC8(obj->f14->flag));
                        func_0217B8E4((char *)ctx, 0); *state = 2;
                    } else func_0217F210(ctx,a,func_0217EDE0(obj->f14->flag));
                    break;
                }
            }
        }
        break;
    }
done:
    return 0;
}







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
        func_0217B8E4((char *)((u8 *)ctx), 0);
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
                func_0217B8E4((char *)((u8 *)((char *)a)), 7);
            else
                func_0217B8E4((char *)((u8 *)((char *)a)), 9);
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
                func_0217B8E4((char *)((u8 *)((char *)a)), 7);
            else
                func_0217B8E4((char *)((u8 *)((char *)a)), 9);
            return 1;
        }
        break;
    }
    return 0;
}







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
                    func_0217B8E4((char *)((u8 *)((char *)a)), (int)0x1f);
                    break;
                case 0x15:
                    func_0217B8E4((char *)((u8 *)((char *)a)), (int)0x20);
                    break;
                case 0x16:
                    func_0217B8E4((char *)((u8 *)((char *)a)), (int)0x21);
                    break;
                case 0x17:
                    func_0217B8E4((char *)((u8 *)((char *)a)), (int)0x22);
                    break;
                case 3:
                    func_0217B8E4((char *)((u8 *)((char *)a)), (int)0xe);
                    break;
                case 0x19:
                    func_0217B8E4((char *)((u8 *)((char *)a)), (int)0x24);
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
                func_0217B8E4((char *)((u8 *)((char *)a)), (int)0);
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
                func_0217B8E4((char *)((u8 *)((char *)a)), 1);
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
            func_0217B8E4((char *)((u8 *)((char *)a)), 0x28);
            return 1;
        }
        break;
    }
    return 0;
}






int func_0217D890(u8 *a, Obj_0217D890 *b, u8 *c, u8 *d)
{
    int *p;
    if (*d < 4 && func_0217BB04((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        if (b->b1 == 0)
            func_0217F210(a, c, func_0217EC94(b->f14->b3));
        else
            func_0217F210(a, c, func_0217EE34(b->f14->b3));
        (*d)++;
        break;
    case 1:
        if (func_0217F1EC(a) == 1)
            (*d)++;
        break;
    case 2:
        if (b->b1 == 0)
            func_02039C68((struct Link *)func_020399A8(), 0xb, 0x14);
        (*d)++;
        break;
    case 3:
        if (b->b1 == 0) {
            if (func_02039CB4((struct Link *)func_020399A8(), 0xb, 0x14) == 1)
                (*d)++;
        } else {
            (*d)++;
        }
        break;
    case 4:
        func_0217422C(a, b->f2d + 1, 0);
        (*d)++;
        break;
    case 5:
        if (func_02174268(a) == 0) {
            if (((struct Obj09414 *)a)->f355C != 0)
                func_02034714((const char *)d_021807E4, 0, (const char *)d_021807E4);
            p = *(int * *)&((struct Obj09414 *)a)->f0;
            ((struct Obj09414 *)a)->f355C = func_02174F4C(p[2], p[3], p[0], b->b1);
            func_0217BAF0((char *)a, (int)c, 1);
            func_0217B8E4((char *)((u8 *)((char *)a)), 0x28);
            return 1;
        }
        break;
    }
    return 0;
}






int func_0217D9A8(Ctx *ctx, Obj_0217D9A8 *obj, u8 *a2, u8 *state)
{
    Work *w = *(Work * *)&((struct Obj07386 *)ctx)->f355C;
    int r;

    func_0203D1A4((struct Link *)func_020399A8());
    if (w == 0)
        func_02034714((const char *)d_021807E4, 0, (const char *)d_021807E4);

    if (func_0217BB20((char *)ctx) == 1) {
        if (w->f168 != 0)
            func_021CD5A4((u32 *)w->f168);
        func_0217F074(ctx);
        return 1;
    }

    switch (*state) {
    case 0:
        if (func_0217F060(obj->f2d) == 2) {
            w->fde = 1;
            if (func_0203D378() == 1) {
                if (func_02173CB4() == 1)
                    *state = 100;
            } else {
                *state = 100;
            }
            break;
        }
        func_0203D7BC(0);
        if (func_0203D378() == 1) {
            w->f168 = func_021CD48C((int)func_02012944((void *)ctx->sys->f8), (int)a2,
                                    func_0217F060(obj->f2d),
                                    func_0217F060(obj->f2d), 0x41, 0, 0, 0);
            func_021CD60C(w->f168, ctx, func_0217DC64, func_0217DC94);
        } else if (obj->b1 == 0) {
            w->f168 = func_021CD48C((int)func_02012944((void *)ctx->sys->f8), (int)a2,
                                    func_0217F060(obj->f2d),
                                    func_0217F060(obj->f2d), 0x41, 2, 0, 0);
        } else {
            w->f168 = func_021CD48C((int)func_02012944((void *)ctx->sys->f8), (int)a2,
                                    func_0217F060(obj->f2d),
                                    func_0217F060(obj->f2d), 0x41, 3, 0, 0);
        }
        if (obj->b1 == 0) {
            func_021736E0(obj->f00);
            func_02039C68((struct Link *)func_020399A8(), 0xc, 0x14);
        }
        (*state)++;
        break;
    case 1:
        if (obj->b1 == 0) {
            if (func_02039CB4((struct Link *)func_020399A8(), 0xc, 0x14) == 1) {
                func_0203D1E8((int)func_020399A8(), (void *)1);
                (*state)++;
            }
        } else {
            (*state)++;
        }
        break;
    case 2:
        (*state)++;
        break;
    case 3:
        r = func_021CD688((u8 *)w->f168);
        if (r != 0) {
            w->f16e = func_021CD5A4((u32 *)w->f168);
            w->f168 = 0;
            switch (r) {
            case 1:
                *state = 100;
                func_0203D7BC(1);
                break;
            case 2:
                *state = 200;
                break;
            case 3:
                *state = 200;
                break;
            case 4:
                *state = 200;
                break;
            default:
                func_02034714((const char *)d_021807E4, 0, (const char *)d_021807E4);
                break;
            }
        }
        break;
    case 4:
        break;
    case 100:
        w->fde = 1;
        func_0217B8E4((char *)((u8 *)((char *)ctx)), 0x29);
        return 1;
    case 200:
        func_0217F210((u8 *)ctx, a2, 0x14c);
        w->fde = 2;
        (*state)++;
        break;
    case 201:
        if (func_0217F1EC((u8 *)ctx) == 1) {
            func_0217B8E4((char *)((u8 *)((char *)ctx)), 0x32);
            func_0217BAF0((char *)ctx, (int)a2, 1);
            return 1;
        }
        break;
    case 300:
        w->fde = 2;
        func_0217B8E4((char *)((u8 *)((char *)ctx)), 0x32);
        func_0217BAF0((char *)ctx, (int)a2, 1);
        return 1;
    }
    return 0;
}




void func_0217DC64(u8 *base, int obj, int x)
{
    int a = func_02008554((const struct Sub0200852CObj *)obj);
    int b = func_02008550((const struct Sub0200852CObj *)obj);
    func_0217357C(base + 0x2844, x, a, (u8)b);
}
