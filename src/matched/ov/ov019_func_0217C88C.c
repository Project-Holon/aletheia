/*
 * function: func_0217C88C
 * address:  0x0217C88C
 * packet:   pkt_ov019_0217C88C
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
    u8 pad2e[0x60 - 0x2e];
    int f60;
    int f64;
    int f68;
    u8 pad6c[0x6e - 0x6c];
    s16 f6e;
} Obj;

typedef unsigned short u16;
int func_0217BB04(char *p);
u32 func_0217F1EC(u8 *p);
void func_0217F5E0(char *p, u32 a1);
void func_0217F624(char *p);
void func_0217F388(char *p, int a1, int kind, u8 *arg);
struct Self;
int func_0217F4B4(char *p, int *hit, u8 *st, int *flag, u32 a4);
void func_0217F4AC(void *ctx);
void func_0217BA10(char *p, int x);
int func_0217BAA8(int a, int b, int *p, int *q);
void func_0217F210(u8 *p, int a, u32 b);
int func_0217B8E4(char *p, char v);
int func_0217B974(int id);
void func_0217F640(struct Self *self, u32 a1, u32 mask, int mode, int msg);
u32 func_0217F794(char *p, u32 a);
void func_0217F7B8(char *p);
u16 func_0217EC88(int i);
u32 func_020362DC(void);

int func_0217C88C(void *ctx, Obj *obj, int a2, u8 *state)
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
            func_0217F5E0(ctx, a2);
        else if (obj->f6e == 0)
            func_0217F624(ctx);
        func_0217F388(ctx, a2, obj->f6e, (u8 *)(&obj->f60));
        (*state)++;
        break;
    case 2:
        r = func_0217F4B4(ctx, &f0c, (u8 *)(&obj->f60), &f08, a2);
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
        func_0217F640(ctx, a2, 0, func_0217B974(obj->f2d), 0);
        (*state)++;
        break;
    case 4:
        if (func_0217F794(ctx, a2) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8(ctx);
            *state = 1;
        }
        break;
    case 5:
        func_0217F640(ctx, a2, obj->f64, func_0217B974(obj->f2d), 1);
        (*state)++;
        break;
    case 6:
        if (func_0217F794(ctx, a2) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8(ctx);
            if (obj->f68 == -1)
                *state = 9;
            else
                (*state)++;
        }
        break;
    case 7:
        func_0217F640(ctx, a2, obj->f64, func_0217B974(obj->f2d), 2);
        (*state)++;
        break;
    case 8:
        if (func_0217F794(ctx, a2) == 1 && (func_020362DC() & 3)) {
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
