/*
 * function: func_021A1E08
 * address:  0x021A1E08
 * packet:   pkt_ov021_021A1E08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A2CF8  0x021A2CF8  thumb  ov021
 *   func_021A0244  0x021A0244  thumb  ov021
 *   func_021A2D04  0x021A2D04  thumb  ov021
 *   func_021A2CEC  0x021A2CEC  thumb  ov021
 *   func_021A282C  0x021A282C  thumb  ov021
 *   func_021A2860  0x021A2860  thumb  ov021
 *   func_021A28CC  0x021A28CC  thumb  ov021
 *   func_021A2968  0x021A2968  thumb  ov021
 *   func_021A2724  0x021A2724  thumb  ov021
 *   func_021A2C98  0x021A2C98  thumb  ov021
 *   func_021A27F8  0x021A27F8  thumb  ov021
 *   func_021A2970  0x021A2970  thumb  ov021
 *   func_021A2924  0x021A2924  thumb  ov021
 *   func_021A28A0  0x021A28A0  thumb  ov021
 *   func_021A284C  0x021A284C  thumb  ov021
 *   func_021A26D8  0x021A26D8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 *f20;
    u8 lo24 : 4;
    u8 hi24 : 4;
    u8 pad25;
    u8 state;
    u8 flag;
    u8 pad28[0x18];
    u8 sub40[4];
} Obj;

extern u8 func_021A2CF8(char *p);
extern int func_021A0244(u8 *p);
extern void func_021A2D04(Obj *o);
extern void func_021A2CEC(char *p);
extern void func_021A282C(Obj *o, s32 x);
extern void func_021A2860(Obj *o, s32 x);
extern void func_021A28CC(Obj *o, s32 x);
extern void func_021A2968(u8 *p);
extern s32 func_021A2724(Obj *o, u32 a, s32 x);
extern void func_021A2C98(void *p, u32 a);
extern void func_021A27F8(Obj *o);
extern u8 func_021A2970(u8 *p);
extern void func_021A2924(Obj *o);
extern void func_021A28A0(Obj *o);
extern void func_021A284C(Obj *o);
extern void func_021A26D8(int *p);

void func_021A1E08(Obj *o, s32 x)
{
    if (func_021A2CF8((char *)o) != 0 && func_021A0244((u8 *)o->f4) == 0) {
        func_021A2D04(o);
        func_021A2CEC((char *)o);
    }
    switch (((u8 *)o)[0x26]) {
    case 0:
        break;
    case 1:
        func_021A282C(o, x);
        func_021A2860(o, x);
        func_021A28CC(o, x);
        func_021A2968((u8 *)o);
        ((u8 *)o)[0x26] = 5;
        break;
    case 2:
        func_021A282C(o, x);
        ((u8 *)o)[0x26] = 3;
        break;
    case 3:
        func_021A2860(o, x);
        ((u8 *)o)[0x26] = 4;
        break;
    case 4:
        func_021A28CC(o, x);
        ((u8 *)o)[0x26] = 5;
        break;
    case 5:
        if (func_021A2724(o, o->f20[11], x) != 0) {
            ((u8 *)o)[0x26] = o->hi24 != 0 ? 6 : 7;
        }
        func_021A2C98(o->sub40, o->fC);
        func_021A2968((u8 *)o);
        break;
    case 6:
        if (func_021A2724(o, o->f20[12], x) != 0) {
            ((u8 *)o)[0x26] = 8;
        }
        func_021A27F8(o);
        func_021A2C98(o->sub40, o->fC);
        break;
    case 7:
        if (func_021A2724(o, o->f20[13], x) != 0) {
            ((u8 *)o)[0x26] = 8;
        }
        func_021A2C98(o->sub40, o->fC);
        break;
    case 8:
        func_021A2724(o, o->f20[14], x);
        func_021A27F8(o);
        func_021A2C98(o->sub40, o->fC);
        break;
    case 9:
        if (func_021A2724(o, o->f20[15], x) != 0) {
            ((u8 *)o)[0x26] = 10;
        }
        func_021A27F8(o);
        func_021A2C98(o->sub40, o->fC);
        break;
    case 10:
        if (func_021A2724(o, o->f20[16], x) != 0) {
            ((u8 *)o)[0x26] = 11;
        }
        func_021A27F8(o);
        func_021A2C98(o->sub40, o->fC);
        break;
    case 11:
        if (func_021A2970((u8 *)o) != 0) {
            func_021A2724(o, o->f20[17], x);
        }
        ((u8 *)o)[0x26] = 12;
        break;
    case 12:
        func_021A2924(o);
        func_021A28A0(o);
        func_021A284C(o);
        func_021A26D8((int *)o);
        ((u8 *)o)[0x26] = 0;
        break;
    }
}
