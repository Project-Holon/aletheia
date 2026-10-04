/*
 * function: func_021BCCB8
 * address:  0x021BCCB8
 * packet:   pkt_ov099_021BCCB8
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BCBD8  0x021BCBD8  thumb  ov099
 *   func_021BDDF4  0x021BDDF4  thumb  ov099
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_021BA874  0x021BA874  thumb  ov099
 *   func_021BC090  0x021BC090  thumb  ov099
 */
#include "../include/Obj03732.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern void func_021BCBD8(char *p, int a);
extern int func_021BDDF4(char *p);
extern void func_021BAAB8(char *p, int a, int b);
extern void func_021BA874(char *p, int id);
extern void func_021BC090(char *p);

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
