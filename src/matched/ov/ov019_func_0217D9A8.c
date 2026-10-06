/*
 * function: func_0217D9A8
 * address:  0x0217D9A8
 * packet:   pkt_ov019_0217D9A8
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02034714  0x02034714  arm
 *   func_0203D378  0x0203D378  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_0203D1E8  0x0203D1E8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02012944  0x02012944  thumb
 *   func_0217BB20  0x0217BB20  thumb  ov019
 *   func_0217F074  0x0217F074  thumb  ov019
 *   func_0217F060  0x0217F060  thumb  ov019
 *   func_0217F210  0x0217F210  thumb  ov019
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 *   func_0217BAF0  0x0217BAF0  thumb  ov019
 *   func_0217DC64  0x0217DC64  thumb  ov019
 *   func_0217DC94  0x0217DC94  thumb  ov019
 *   func_02173CB4  0x02173CB4  thumb  ov012
 *   func_021736E0  0x021736E0  thumb  ov012
 *   func_021CD48C  0x021CD48C  thumb  ov021
 *   func_021CD5A4  0x021CD5A4  thumb  ov021
 *   func_021CD60C  0x021CD60C  thumb  ov021
 *   func_021CD688  0x021CD688  thumb  ov021
 *   d_021807E4     0x021807E4  data  a4
 */
#include "../include/Obj07386.h"

typedef unsigned char u8;

typedef struct {
    u8 f00;
    u8 pad01[0x2d - 1];
    u8 f2d;
    u8 pad2e[0x5a - 0x2e];
    u8 b0 : 1;
    u8 b1 : 1;
} Obj;

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

struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_0203D1A4(int a);
extern void func_02034714(void *a, int b, void *c);
typedef unsigned int   u32;
extern u32 func_0203D378(void);
extern void func_0203D7BC(int a);
extern void func_0203D1E8(int a, int b);
struct Link;
extern void func_02039C68(struct Link *a, unsigned int b, unsigned int c);
extern unsigned int func_02039CB4(struct Link *a, unsigned int b, unsigned int c);
extern u8 *func_02012944(void *p);
extern int func_0217BB20(char *p);
extern void func_0217F074(void *p);
extern int func_0217F060(int i);
extern void func_0217F210(Ctx *ctx, int a, int msg);
extern int func_0217F1EC(Ctx *ctx);
extern int func_0217B8E4(char *p, char v);
extern void func_0217BAF0(char *p, int x, unsigned int v);
extern void func_0217DC64(u8 *base, int obj, int x);
extern void func_0217DC94(u8 *base, int obj, int x);
extern int func_02173CB4(void);
extern void func_021736E0(unsigned int x);
extern int func_021CD48C(int a, int b, int c, int d, int e, int f, int g, int h);
extern u8 func_021CD5A4(int h);
extern void func_021CD60C(int h, void *a, void *b, void *c);
extern int func_021CD688(int h);
extern u8 d_021807E4[];

int func_0217D9A8(Ctx *ctx, Obj *obj, int a2, u8 *state)
{
    Work *w = *(Work * *)&((struct Obj07386 *)ctx)->f355C;
    int r;

    func_0203D1A4((int)func_020399A8());
    if (w == 0)
        func_02034714(d_021807E4, 0, d_021807E4);

    if (func_0217BB20((char *)ctx) == 1) {
        if (w->f168 != 0)
            func_021CD5A4(w->f168);
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
            w->f168 = func_021CD48C((int)func_02012944((void *)ctx->sys->f8), a2,
                                    func_0217F060(obj->f2d),
                                    func_0217F060(obj->f2d), 0x41, 0, 0, 0);
            func_021CD60C(w->f168, ctx, func_0217DC64, func_0217DC94);
        } else if (obj->b1 == 0) {
            w->f168 = func_021CD48C((int)func_02012944((void *)ctx->sys->f8), a2,
                                    func_0217F060(obj->f2d),
                                    func_0217F060(obj->f2d), 0x41, 2, 0, 0);
        } else {
            w->f168 = func_021CD48C((int)func_02012944((void *)ctx->sys->f8), a2,
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
                func_0203D1E8((int)func_020399A8(), 1);
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
        r = func_021CD688(w->f168);
        if (r != 0) {
            w->f16e = func_021CD5A4(w->f168);
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
                func_02034714(d_021807E4, 0, d_021807E4);
                break;
            }
        }
        break;
    case 4:
        break;
    case 100:
        w->fde = 1;
        func_0217B8E4((char *)ctx, 0x29);
        return 1;
    case 200:
        func_0217F210(ctx, a2, 0x14c);
        w->fde = 2;
        (*state)++;
        break;
    case 201:
        if (func_0217F1EC(ctx) == 1) {
            func_0217B8E4((char *)ctx, 0x32);
            func_0217BAF0((char *)ctx, a2, 1);
            return 1;
        }
        break;
    case 300:
        w->fde = 2;
        func_0217B8E4((char *)ctx, 0x32);
        func_0217BAF0((char *)ctx, a2, 1);
        return 1;
    }
    return 0;
}
