/*
 * function: func_0217C2AC
 * address:  0x0217C2AC
 * packet:   pkt_ov019_0217C2AC
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0217BB04  0x0217BB04  thumb ov019
 *   func_0217EC1C  0x0217EC1C  thumb ov019
 *   func_0217EC88  0x0217EC88  thumb ov019
 *   func_0217EC28  0x0217EC28  thumb ov019
 *   func_0217ECA0  0x0217ECA0  thumb ov019
 *   func_0217ECAC  0x0217ECAC  thumb ov019
 *   func_0217ECB8  0x0217ECB8  thumb ov019
 *   func_0217F210  0x0217F210  thumb ov019
 *   func_0217F1EC  0x0217F1EC  thumb ov019
 *   func_0217F360  0x0217F360  thumb ov019
 *   func_0217F378  0x0217F378  thumb ov019
 *   func_0217F380  0x0217F380  thumb ov019
 *   func_0217B8E4  0x0217B8E4  thumb ov019
 *   func_02012934  0x02012934  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201AA1C  0x0201AA1C  thumb
 *   func_0201AAD4  0x0201AAD4  thumb
 *   func_0201AA88  0x0201AA88  thumb
 */

typedef unsigned char u8;
typedef short s16;

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

int func_0217BB04(Ctx *ctx);
typedef unsigned short u16;
typedef unsigned int   u32;
struct BigObj;
u16 func_0217EC1C(int i);
u16 func_0217EC88(int i);
u16 func_0217EC28(int i);
u16 func_0217ECA0(int i);
u16 func_0217ECAC(int i);
int func_0217ECB8(Ctx *ctx);
void func_0217F210(Ctx *ctx, int a, int msg);
int func_0217F1EC(Ctx *ctx);
void func_0217F360(Ctx *ctx, int a);
void func_0217F378(void *p);
int func_0217F380(void *ctx, int a);
int func_0217B8E4(Ctx *ctx, int v);
void *func_02012934(const struct BigObj *p);
struct Ctx;
void *func_020120F4(const struct Ctx *p);
int func_0201AA1C(void *a);
int func_0201AAD4(void *a);
u32 func_0201AA88(void *p);

int func_0217C2AC(Ctx *ctx, Obj *obj, int a2, u8 *state)
{
    void *h;
    int r;

    if (func_0217BB04(ctx) == 1)
        return 1;

    switch (*state) {
    case 0:
        if (obj->f6e == 1) {
            obj->f6e = 0;
        } else if (obj->f5c == 0) {
            func_0217F210(ctx, a2, func_0217EC1C(obj->f14->flag));
            obj->f5c++;
        } else {
            func_0217F210(ctx, a2, func_0217EC88(obj->f14->flag));
        }
        (*state)++;
        break;
    case 1:
        if (func_0217F1EC(ctx) == 1)
            (*state)++;
        break;
    case 2:
        func_0217F360(ctx, a2);
        (*state)++;
        break;
    case 3:
        h = func_02012934((void *)ctx->sys->f8);
        r = func_0217F380(ctx, a2);
        if (r == -1)
            break;
        func_0217F378(ctx);
        if (r == -2 || r == 0) {
            func_0217F210(ctx, a2, func_0217EC28(obj->f14->flag));
            obj->f2d = 0;
            func_0217B8E4(ctx, 8);
            return 1;
        }
        if (r == 0x18) {
            func_020120F4((const struct Ctx *)ctx->sys->fc);
            if (func_0201AA1C(h) < 2) {
                func_0217F210(ctx, a2, func_0217ECA0(obj->f14->flag));
                *state = 4;
                break;
            }
        } else if (r == 0x19) {
            if (func_0201AAD4(h) > 0) {
                func_0217F210(ctx, a2, func_0217ECB8(ctx));
                *state = 4;
                break;
            } else if (func_0201AA88(h) == 0) {
                func_0217F210(ctx, a2, func_0217ECAC(obj->f14->flag));
                *state = 4;
                break;
            }
        }
        if (r == 0x1b) {
            func_0217B8E4(ctx, 10);
            return 1;
        }
        obj->f2d = r;
        func_0217B8E4(ctx, 8);
        return 1;
    case 4:
        if (func_0217F1EC(ctx) == 1)
            *state = 0;
        break;
    }
    return 0;
}
