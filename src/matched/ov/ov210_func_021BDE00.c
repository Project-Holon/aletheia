/*
 * function: func_021BDE00
 * address:  0x021BDE00
 * packet:   pkt_ov210_021BDE00
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FRAME_LIST_Update  0x021B7AB0  thumb  ov067
 *   func_020355C4  0x020355C4  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   func_021BE290  0x021BE290  thumb  ov210
 *   func_021BF728  0x021BF728  thumb  ov210
 *   func_021BEDB8  0x021BEDB8  thumb  ov210
 *   func_021BE2F4  0x021BE2F4  thumb  ov210
 *   func_021BF658  0x021BF658  thumb  ov210
 *   func_021BF81C  0x021BF81C  thumb  ov210
 *   func_021BFB24  0x021BFB24  thumb  ov210
 *   func_021C01C0  0x021C01C0  thumb  ov210
 *   func_021BE2DC  0x021BE2DC  thumb  ov210
 *   func_021BF6E0  0x021BF6E0  thumb  ov210
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00085.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
struct S;
extern int FRAME_LIST_Update(struct S *p);
extern u8 func_020355C4(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern void func_021BE290(u8 *p, int index);
extern void func_021BF728(u8 *p, int a);
extern void func_021BEDB8(int p, int i, int v);
extern u32 func_021BE2F4(u8 *p, u32 a, u32 b, u32 c);
extern void func_021BF81C(char *p);
extern void func_021BFB24(char *ctx);
extern void func_021BF658(char *p);
extern int func_021C01C0(char *ctx);
extern void func_021BE2DC(u8 *p);
extern void func_021BF6E0(char *p);

u32 func_021BDE00(u8 *p)
{
    u32 r5;
    u32 ret = 22;

    r5 = FRAME_LIST_Update((struct S *)(*(u32 *)&((struct Obj00085 *)p)->f1E0));

    switch (r5) {
    case 0:
    case 1:
    case 2:
    case 3:
        if (func_020355C4() == 0) {
            GFL_USE_PlaySeDefaultVolume(0x54c);
            func_021BE290(p, r5);
        }
        break;
    case (u32)-12:
        break;
    case (u32)-11:
    case (u32)-10:
    case (u32)-9:
    case (u32)-8:
        func_021BF728(p, 0);
        break;
    case (u32)-7:
        func_021BEDB8((int)p, 6, 12);
        p[0x2c1] = 6;
        ((struct Obj00085 *)p)->f14 = 0;
        ((struct Obj00085 *)p)->f18 = ret;
        ret = 0x18;
        break;
    case (u32)-6:
        func_021BEDB8((int)p, 5, 13);
        p[0x2c1] = 5;
        ((struct Obj00085 *)p)->f14 = 0;
        ((struct Obj00085 *)p)->f18 = ret;
        ret = 0x18;
        break;
    case (u32)-5:
        func_021BEDB8((int)p, 6, 12);
        return func_021BE2F4(p, 1, 6, 22);
    case (u32)-4:
        func_021BEDB8((int)p, 5, 13);
        return func_021BE2F4(p, 1, 5, 22);
    case (u32)-3:
    case (u32)-2:
        func_021BF658((char *)p);
        func_021BF81C((char *)p);
        func_021BFB24((char *)p);
        p[0x2c1] = 0x39;
        ((struct Obj00085 *)p)->f14 = 1;
        ((struct Obj00085 *)p)->f18 = ret;
        ret = 0x18;
        break;
    case (u32)-1:
        r5 = func_021C01C0((char *)p);
        switch (r5) {
        case 0:
            GFL_USE_PlaySeDefaultVolume(0x551);
            func_021BEDB8((int)p, 2, 9);
            return func_021BE2F4(p, 1, 2, 0x17);
        case 8:
            GFL_USE_PlaySeDefaultVolume(0x551);
            func_021BEDB8((int)p, 2, 9);
            return func_021BE2F4(p, 1, 2, 0x17);
        case 9:
            GFL_USE_PlaySeDefaultVolume(0x54c);
            func_021BE2DC(p);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            GFL_USE_PlaySeDefaultVolume(0x54c);
            func_021BF728(p, 0);
            func_021BE290(p, r5 - 1);
            break;
        }
        break;
    }
    func_021BF6E0((char *)p);
    return ret;
}
