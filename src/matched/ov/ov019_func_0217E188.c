/*
 * function: func_0217E188
 * address:  0x0217E188
 * packet:   pkt_ov019_0217E188
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BBA8  0x0200BBA8  thumb
 *   func_0217F074  0x0217F074  thumb  ov019
 *   func_0217BA48  0x0217BA48  thumb  ov019
 *   func_0217BA6C  0x0217BA6C  thumb  ov019
 *   func_0217B9CC  0x0217B9CC  thumb  ov019
 *   func_02012934  0x02012934  thumb
 *   func_021CC720  0x021CC720  thumb  ov021
 *   func_021CC810  0x021CC810  thumb  ov021
 *   func_021CC7B4  0x021CC7B4  thumb  ov021
 *   func_0217B9F4  0x0217B9F4  thumb  ov019
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 *   func_0217F098  0x0217F098  thumb  ov019
 *   func_0217B974  0x0217B974  thumb  ov019
 *   func_0217F640  0x0217F640  thumb  ov019
 *   func_0217F794  0x0217F794  thumb  ov019
 *   func_0217F210  0x0217F210  thumb  ov019
 *   func_020362DC  0x020362DC  arm
 *   func_0217F7B8  0x0217F7B8  thumb  ov019
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    u8 f00;
    u8 pad01[0x6e - 1];
    s16 f6e;
} Obj;

typedef struct {
    u8 pad00[8];
    int f8;
} Sys;

typedef struct {
    Sys *sys;
    u8 pad04[0x3534 - 4];
    int f3534;
    int f3538;
    u8 pad353c[0x355c - 0x353c];
    u8 *w;
} Ctx;

extern int func_0217F1EC(Ctx *ctx);
typedef unsigned short u16;
struct Big;
struct Obj;
extern void *func_02012EBC(struct Big *p);
extern void *func_0200BAC8(void *p);
extern u32 func_0200BBA8(void *a);
struct BigObj;
extern void func_0217F074(void *p);
extern void func_0217BA48(Ctx *ctx, int *out);
extern void func_0217BA6C(Ctx *ctx, int *out);
extern int func_0217B9CC(Ctx *ctx);
extern void *func_02012934(const struct BigObj *p);
extern struct Obj *func_021CC720(u32 a, u32 b, u32 c, u32 d, u32 e, u16 heap);
extern int func_021CC810(struct Obj *p);
extern int func_021CC7B4(int h, int *out);
extern void func_0217B9F4(void *p);
extern int func_0217B8E4(Ctx *ctx, int v);
extern void func_0217F098(Ctx *ctx, int a);
extern int func_0217B974(int id);
extern void func_0217F640(Ctx *ctx, int a, int b, int c, int d);
extern int func_0217F794(Ctx *ctx, int a);
extern void func_0217F210(Ctx *ctx, int a, int msg);
extern u32 func_020362DC(void);
extern void func_0217F7B8(Ctx *ctx);

int func_0217E188(Ctx *ctx, Obj *obj, int a2, u8 *state)
{
    u8 *w = ctx->w;
    int o1c;
    int o18;
    int o14;
    int o10;
    int f1;
    int f2;
    int r;

    if (func_0217F1EC(ctx) == 0)
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
        func_0217BA48(ctx, &o1c);
        func_0217BA6C(ctx, &o18);
        f1 = o1c != 0;
        f2 = o18 != 0;
        ctx->f3538 = func_0217B9CC(ctx);
        ctx->f3534 = (int)func_021CC720(a2, (u32)func_02012934((void *)ctx->sys->f8), ctx->f3538, f1, f2, 0x15);
        (*state)++;
        break;
    case 3:
        if (func_021CC810((struct Obj *)ctx->f3534) == 1) {
            r = func_021CC7B4(ctx->f3534, &o14);
            ctx->f3534 = 0;
            if (r == 2) {
                func_0217B9F4((void *)ctx->f3538);
                ctx->f3538 = 0;
                func_0217B8E4(ctx, 0x2c);
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
            func_0217BA48(ctx, &o10);
            f1 = 1;
        } else {
            func_0217BA6C(ctx, &o10);
            f1 = 2;
        }
        if (o10 != 0) {
            func_0217F098(ctx, a2);
            func_0217F640(ctx, a2, o10, func_0217B974(obj->f00), f1);
            *state = 5;
        } else {
            func_0217B8E4(ctx, 0x2e);
            return 1;
        }
        break;
    case 5:
        if (func_0217F794(ctx, a2) == 1) {
            func_0217F210(ctx, a2, 0x115);
            (*state)++;
        }
        break;
    case 6:
        if (func_020362DC() & 3) {
            func_0217F7B8(ctx);
            if (obj->f6e == 0) {
                *state = 0;
            } else {
                func_0217B8E4(ctx, 0x2c);
                return 1;
            }
        }
        break;
    }
    return 0;
}
