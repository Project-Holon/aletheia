/*
 * function: func_0217CEB8
 * address:  0x0217CEB8
 * packet:   pkt_ov019_0217CEB8
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[0x58];
    u16 f58;
} Obj;

int func_0217AF04(u8 *a, u16 key);
u16 func_0217AEFC(unsigned int x);
u16 func_0217ED04(int i);
u16 func_0217ED10(int i);
u16 func_0217ECE8(int i);
u16 func_0217ED64(int i);
u16 func_0217ED2C(int i);
u16 func_0217ED48(int i);
void func_0217F210(u8 *p, int a, u32 b);
int func_0217B8E4(char *p, char v);
u32 func_0217F1EC(u8 *p);
u32 func_020362DC(void);

int func_0217CEB8(void *ctx, Obj *obj, int a2, u8 *state)
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
