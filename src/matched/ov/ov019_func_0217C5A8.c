/*
 * function: func_0217C5A8
 * address:  0x0217C5A8
 * packet:   pkt_ov019_0217C5A8
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0217BB04  0x0217BB04  thumb ov019
 *   func_0217F1EC  0x0217F1EC  thumb ov019
 *   func_0217F210  0x0217F210  thumb ov019
 *   func_0217EC34  0x0217EC34  thumb ov019
 *   func_0217EC68  0x0217EC68  thumb ov019
 *   func_0217EC78  0x0217EC78  thumb ov019
 *   func_0217ECD0  0x0217ECD0  thumb ov019
 *   func_0217B8E4  0x0217B8E4  thumb ov019
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
    u8 f2e;
    u8 pad2f[0x64 - 0x2f];
    int f64;
    int f68;
    u8 pad6c[0x6e - 0x6c];
    s16 f6e;
} Obj;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
} Sys;

typedef struct {
    Sys *sys;
} Ctx;

struct Self;
int func_0217BB04(char *p);
u32 func_0217F1EC(u8 *p);
void func_0217F210(u8 *p, int a, u32 b);
typedef unsigned short u16;
struct BigObj;
u16 func_0217EC34(int i);
u16 func_0217EC68(int i);
u16 func_0217EC78(int i);
int func_0217ECD0(Ctx *ctx);
int func_0217B8E4(Ctx *ctx, int v);
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
struct Ctx;
void *func_020120F4(const struct Ctx *p);
u32 func_0201AA1C(void *p);
u32 func_0201AAD4(void *p);
u32 func_0201AA88(void *p);
u32 func_020362DC(void);

int func_0217C5A8(Ctx *ctx, Obj *obj, int a2, u8 *state)
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
            func_0217B8E4(ctx, 0x27);
            return 1;
        }
        if (obj->f2d < 0x1b) {
            func_0217F210((u8 *)ctx, a2, func_0217EC68(obj->f2d));
            if (func_0217B9BC(obj->f2d) == 1) {
                func_0217BA10((char *)ctx, obj->f2d);
                func_0217F640((struct Self *)ctx, a2, 0, func_0217B974(obj->f2d), 0);
                *state = 2;
            } else {
                *state = 3;
            }
        } else if (func_02173A48(0) == 1) {
            func_0217F210((u8 *)ctx, a2, 0x13d);
            func_0217B8E4(ctx, 0x27);
            return 1;
        }
        break;
    case 2:
        if (func_0217F794((char *)ctx, a2) == 1)
            *state = 3;
        break;
    case 3:
        func_0217F7B8((char *)ctx);
        func_0217F22C((u8 *)ctx, a2);
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
        func_0217F640((struct Self *)ctx, a2, obj->f64, func_0217B974(obj->f2d), 1);
        (*state)++;
        break;
    case 7:
        if (func_0217F794((char *)ctx, a2) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8((char *)ctx);
            if (obj->f68 == -1)
                *state = 10;
            else
                (*state)++;
        }
        break;
    case 8:
        func_0217F640((struct Self *)ctx, a2, obj->f64, func_0217B974(obj->f2d), 2);
        (*state)++;
        break;
    case 9:
        if (func_0217F794((char *)ctx, a2) == 1 && (func_020362DC() & 3)) {
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
                func_0217F210((u8 *)ctx, a2, func_0217ECD0(ctx));
            else
                func_0217F210((u8 *)ctx, a2, func_0217EC78(obj->f2d));
            func_0217B8E4(ctx, 0x27);
            return 1;
        }
        func_0217B8E4(ctx, obj->f2d + 11);
        *state = 11;
        break;
    case 11:
        return 1;
    }
    return 0;
}
