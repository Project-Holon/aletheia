/*
 * function: func_021BA7C0
 * address:  0x021BA7C0
 * packet:   pkt_ov068_021BA7C0
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The 0/1/2 test on func_021BB0D8's result is a switch with three empty
 * labels: `r == 0 || r == 1 || r == 2` folds to one unsigned `cmp #2`.
 *
 * symbols:
 *   func_021BA190  0x021BA190  thumb  ov068
 *   func_021BA194  0x021BA194  thumb  ov068
 *   func_02040804  0x02040804  arm
 *   func_021BAA0C  0x021BAA0C  thumb  ov068
 *   func_020061E4  0x020061E4  thumb
 *   func_021BAD38  0x021BAD38  thumb  ov068
 *   func_021BAC70  0x021BAC70  thumb  ov068
 *   func_021B9964  0x021B9964  thumb  ov068
 *   func_020355C4  0x020355C4  arm
 *   func_020355D8  0x020355D8  arm
 *   func_021BAD14  0x021BAD14  thumb  ov068
 *   func_021BB0D8  0x021BB0D8  thumb  ov068
 *   func_021BB0D0  0x021BB0D0  thumb  ov068
 *   func_02040588  0x02040588  arm
 *   func_021BA278  0x021BA278  thumb  ov068
 *   func_021BA31C  0x021BA31C  thumb  ov068
 *   func_021BAD58  0x021BAD58  thumb  ov068
 *   d_021BB570     0x021BB570  data  a4
 */
#include "../include/Obj00103.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021BA190(const int *p);
extern void func_021BA194(const u8 *p, int which, int *out);
extern u32 func_02040804(u32 layer);
extern void func_021BAA0C(u8 *p, int flag);
extern void func_020061E4(u32 id);
extern int  func_021BAD38(u8 *p, int *pos);
extern void func_021BAC70(u8 *p, void *b);
extern void func_021B9964(char *p);
extern u8 func_020355C4(void);
extern void func_020355D8(u8 v);
extern void func_021BAD14(u8 *p, u32 v);
extern int  func_021BB0D8(void *p);
extern u32  func_021BB0D0(void *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021BA278(u8 *p, u32 a, u32 b, u32 c);
extern int func_021BA31C(u8 *p);
extern void func_021BAD58(void *p);
extern const u16 d_021BB570[][4];

void func_021BA7C0(u8 *p, void *a1, void *a2, void *a3, void *a4)
{
    int pos[2];
    int r;
    int s;
    u32 t;

    r = func_021BA190(a1);
    func_02040804(((struct Obj00103 *)p)->f2);
    switch (r) {
    case 14:
        ((struct Obj00103 *)p)->f4 = ((struct Obj00103 *)p)->f4 > 6 ? 6 : (((struct Obj00103 *)p)->f4 < 0 ? 0 : ((struct Obj00103 *)p)->f4);
        func_021BAA0C(p, 1);
        ((struct Obj00103 *)p)->f50 = 1;
        break;
    case 10:
        if ((((struct Obj00103 *)p)->f38)++ < 10)
            break;
    case 4:
        ((struct Obj00103 *)p)->f38 = 0;
        ((struct Obj00103 *)p)->f4 = ((struct Obj00103 *)p)->f4 == 0 ? 6 : ((struct Obj00103 *)p)->f4 - 1;
        ((struct Obj00103 *)p)->f50 = 1;
        func_020061E4(0x548);
        func_021BAA0C(p, 1);
        func_021B9964(a3);
        break;
    case 11:
        if ((((struct Obj00103 *)p)->f38)++ < 10)
            break;
    case 5:
        ((struct Obj00103 *)p)->f38 = 0;
        if (((struct Obj00103 *)p)->f4 == 6)
            ((struct Obj00103 *)p)->f4 = 0;
        else
            (((struct Obj00103 *)p)->f4)++;
        ((struct Obj00103 *)p)->f50 = 1;
        func_020061E4(0x548);
        func_021BAA0C(p, 1);
        func_021B9964(a3);
        break;
    case 3:
        func_021BA194(a1, 0, pos);
        if (pos[1] < 0x18 || pos[1] > 0xA8)
            break;
        ((struct Obj00103 *)p)->f4 = func_021BAD38(p, pos);
        func_021BAC70(p, pos);
        func_021BAA0C(p, 0);
        func_021B9964(a3);
        ((struct Obj00103 *)p)->f50 = 1;
        if (func_020355C4() == 0)
            func_020355D8(1);
        break;
    case 6:
        if (((struct Obj00103 *)p)->f4 < 5) {
            func_020061E4(0x548);
            func_021BAD14(p, 1);
            func_021BAA0C(p, 1);
            func_021B9964(a3);
        } else if (((struct Obj00103 *)p)->f4 == 5) {
            (((struct Obj00103 *)p)->f4)++;
            func_020061E4(0x548);
            ((struct Obj00103 *)p)->f4 = ((struct Obj00103 *)p)->f4 > 6 ? 6 : (((struct Obj00103 *)p)->f4 < 0 ? 0 : ((struct Obj00103 *)p)->f4);
        }
        break;
    case 7:
        if (((struct Obj00103 *)p)->f4 < 5) {
            func_020061E4(0x548);
            func_021BAD14(p, -1);
            func_021BAA0C(p, 1);
            func_021B9964(a3);
        } else if (((struct Obj00103 *)p)->f4 == 6) {
            (((struct Obj00103 *)p)->f4)--;
            func_020061E4(0x548);
            ((struct Obj00103 *)p)->f4 = ((struct Obj00103 *)p)->f4 > 6 ? 6 : (((struct Obj00103 *)p)->f4 < 0 ? 0 : ((struct Obj00103 *)p)->f4);
        }
        break;
    case 12:
        func_021BAA0C(p, 1);
        break;
    case 8:
    case 9:
        func_021BAA0C(p, 0);
        break;
    }
    switch (func_021BB0D8(p + 0x44)) {
    case 0:
    case 1:
    case 2:
        ((struct Obj00103 *)p)->f50 = 1;
        break;
    }
    if (((struct Obj00103 *)p)->f50) {
        if (((struct Obj00103 *)p)->f4 >= 0 && ((struct Obj00103 *)p)->f4 < 5) {
            if (((struct Obj00103 *)p)->f4 == 0) {
                s = 1;
                t = func_021BB0D0(p + 0x44);
            } else {
                s = 0;
                t = 0;
            }
            func_02040588(4, 1);
            func_021BA278(a2, d_021BB570[((struct Obj00103 *)p)->f4][0], t, s);
        } else {
            func_02040588(4, 0);
        }
        ((struct Obj00103 *)p)->f50 = 0;
    }
    func_021BA31C(a2);
    func_021BAD58(p);
}
