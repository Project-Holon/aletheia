/*
 * function: func_0217C074
 * address:  0x0217C074
 * packet:   pkt_ov019_0217C074
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0217BB04  0x0217BB04  thumb ov019
 *   d_021807E4     0x021807E4  data a1
 *   func_02034714  0x02034714  arm
 *   func_0203D14C  0x0203D14C  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_020362DC  0x020362DC  arm
 *   func_02172D20  0x02172D20  thumb ov012
 *   func_02172D68  0x02172D68  thumb ov012
 *   func_021734A8  0x021734A8  thumb ov012
 *   func_02173A90  0x02173A90  thumb ov012
 *   func_0217B8E4  0x0217B8E4  thumb ov019
 *   func_0217F210  0x0217F210  thumb ov019
 *   func_0217F1EC  0x0217F1EC  thumb ov019
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[0x1c];
    u8 *f1c;
    u8 pad20[0x5a - 0x20];
    u8 lo5a : 2;
    u8 mode : 2;
    u8 pad5b[0x6c - 0x5b];
    s16 f6c;
} Obj;

extern char d_021807E4[];

int func_0217BB04(char *p);
void func_02034714(const char *expr, u32 line, const char *file);
void func_0203D14C(int a, int b, void *c);
int func_0203D1B4(void);
void func_0203D7BC(u8 a0);
u32 func_020362DC(void);
void func_02172D20(u8 *p);
int func_02172D68(u8 *p);
void func_021734A8(u8 *self, u32 id, u32 v);
int func_02173A90(void);
int func_0217B8E4(char *p, char v);
void func_0217F210(u8 *p, int a, u32 b);
u32 func_0217F1EC(u8 *p);

int func_0217C074(void *ctx, Obj *obj, int a2, u8 *state)
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
