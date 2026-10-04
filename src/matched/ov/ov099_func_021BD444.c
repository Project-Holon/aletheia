/*
 * function: func_021BD444
 * address:  0x021BD444
 * packet:   pkt_ov099_021BD444
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C282C  0x021C282C  thumb  ov099
 *   d_021C38EC     0x021C38EC  data  ov099  a4
 *   func_021BC104  0x021BC104  thumb  ov099
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   func_021C18C8  0x021C18C8  thumb  ov099
 */
#include "../include/Obj06357.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

typedef struct { u32 v[8]; } Tbl8;

extern int func_021C282C(u8 *p);
extern void func_021BC104(char *p);
extern void func_021BA8EC(char *p);
extern void func_021C18C8(char *p, int kind, int value);
extern const Tbl8 d_021C38EC;

int func_021BD444(char *p)
{
    Tbl8 t;
    u32 s;

    func_021C282C(*(u8 * *)&((struct Obj06357 *)p)->f8);
    ((struct Obj06357 *)p)->f1351 = 0;
    t = d_021C38EC;
    s = t.v[((struct Obj06357 *)p)->f134E + ((struct Obj06357 *)p)->f134C * 2];
    ((struct Obj06357 *)p)->f1D0 = s;
    func_021BC104(p);
    func_021BA8EC(p);
    func_021C18C8(p, 4, s);
    return 2;
}
