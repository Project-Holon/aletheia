/*
 * function: func_0217C450
 * address:  0x0217C450
 * packet:   pkt_ov019_0217C450
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0217BB04  0x0217BB04  thumb ov019
 *   func_02173A04  0x02173A04  thumb ov012
 *   func_0217B8E4  0x0217B8E4  thumb ov019
 *   func_0217EC40  0x0217EC40  thumb ov019
 *   func_0217EC54  0x0217EC54  thumb ov019
 *   func_0217F210  0x0217F210  thumb ov019
 *   func_0217F1EC  0x0217F1EC  thumb ov019
 */

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
} Obj;

int func_0217BB04(void *ctx);
int func_02173A04(int a, ...);
int func_0217B8E4(void *ctx, int v);
int func_0217EC40(int a, int b);
int func_0217EC54(int a, int b);
void func_0217F210(void *ctx, int a, int msg);
int func_0217F1EC(void *ctx);

int func_0217C450(void *ctx, Obj *obj, int a2, u8 *state)
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
