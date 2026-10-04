/*
 * function: func_021BA37C
 * address:  0x021BA37C
 * packet:   pkt_ov068_021BA37C
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The u16 stack parameter is re-read per call because both callees take it
 * as u16 (docs/idioms/a-u16-stack-parameter-reloaded-per-call-means-u16-callee-parameters.md).
 * Locals: the 64-byte table copy is declared before the 32-byte request so the
 * request sits at the lower address.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B62E0  0x021B62E0  thumb  ov067
 *   func_021BA6B8  0x021BA6B8  thumb  ov068
 *   func_02012BF8  0x02012BF8  thumb
 *   func_021B6598  0x021B6598  thumb  ov067
 *   d_021BB5D4     0x021BB5D4  data  a4
 */
#include "../include/Obj02762.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 w[16]; } Tbl;
typedef struct { u32 w[8]; } Req;

extern void func_02082BCC(void *p, u32 a, u32 b);
extern u32  func_021B62E0(Req *r, u16 a);
extern void func_021BA6B8(u8 *p, u32 arg);
extern int func_02012BF8(int a0, int a1);
extern void func_021B6598(unsigned char *p, unsigned int id, unsigned int v);
extern Tbl  d_021BB5D4;

void func_021BA37C(u8 *p, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, u16 s3)
{
    Tbl t;
    Req r;

    func_02082BCC(p, 0, 0x44);
    ((struct Obj02762 *)p)->fC = 3;
    ((struct Obj02762 *)p)->f0 = a2;
    ((struct Obj02762 *)p)->f14 = s1;
    ((struct Obj02762 *)p)->f18 = s0;
    ((struct Obj02762 *)p)->f4 = a3;
    ((struct Obj02762 *)p)->f3C = s2;
    t = d_021BB5D4;
    func_02082BCC(&r, 0, 0x20);
    r.w[0] = (u32)&t;
    r.w[1] = 2;
    r.w[2] = a1;
    r.w[5] = 8;
    r.w[7] = 1;
    r.w[6] = 2;
    ((struct Obj02762 *)p)->f8 = func_021B62E0(&r, s3);
    func_021BA6B8(p, s3);
    if (func_02012BF8(((struct Obj02762 *)p)->f3C, 0x18) != 0) {
        func_021B6598((unsigned char *)(((struct Obj02762 *)p)->f8), 6, 1);
    } else {
        func_021B6598((unsigned char *)(((struct Obj02762 *)p)->f8), 6, 0);
    }
}
