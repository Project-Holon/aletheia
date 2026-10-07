/*
 * file:     unit_021BB954_p17.c
 * unit:     yes
 * function: func_021BCC58, func_021BCCB8
 * address:  0x021BCC58
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021C3A30  0x021C3A30  data  a4
 *   func_021BCBD8  0x021BCBD8  thumb  ov099
 *   func_021BDDF4  0x021BDDF4  thumb  ov099
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_021BA874  0x021BA874  thumb  ov099
 *   func_021BC090  0x021BC090  thumb  ov099
 */
#include "../../matched/include/Obj07944.h"
#include "../../matched/include/Obj22032.h"
#include "../../matched/include/Obj03732.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32;

extern u32 func_021BCBD8(char *p, int m);
extern int func_021BDDF4(char *p);
extern void func_021BAAB8(char *p, int a, int b);
extern void func_021BA874(char *p, int id);
extern void func_021BC090(char *p);
void func_021BCC58(char *p, u32 x);
int func_021BCCB8(char *p, int v);
extern const u32 d_021C3A30[];


void func_021BCC58(char *p, u32 x)
{
    u32 m;
    int i;

    ((struct Obj22032 *)(*(char * *)&((struct Obj07944 *)p)->f248))->f48 = (x & 0x80000000) != 0;
    m = x & 0x0fffffff;
    for (i = 0; i < 8u; i++) {
        if (m == d_021C3A30[i]) {
            ((struct Obj07944 *)p)->f134C = i % 4;
            ((struct Obj07944 *)p)->f134E = i / 4;
        }
    }
}


int func_021BCCB8(char *p, int v)
{
    int m;
    u8 *q;

    m = ((struct Obj03732 *)p)->f135C;
    if (m == 3 || m == 1) {
        func_021BCBD8(p, 1);
    } else {
        func_021BCBD8(p, 0);
    }
    if (func_021BDDF4(p) == 0) {
        func_021BAAB8(p, 0x68, 0);
        ((struct Obj03732 *)p)->f1CC = 0x63;
        return v;
    }
    ((struct Obj03732 *)p)->f1352 = 7;
    q = *(u8 * *)&((struct Obj03732 *)p)->f248;
    if (q[0x44] != q[0x45]) {
        ((struct Obj03732 *)p)->f1CC = 0x7D;
    } else {
        ((struct Obj03732 *)p)->f1CC = 0x81;
    }
    func_021BA874(p, ((struct Obj03732 *)p)->f242 - 1);
    if (((struct Obj03732 *)p)->f135C - 3 <= 1u) {
        func_021BAAB8(p, 0xE, 0);
    } else {
        func_021BAAB8(p, 0x4C, 0);
    }
    func_021BC090(p);
    return v;
}
