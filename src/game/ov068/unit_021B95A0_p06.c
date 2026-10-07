/*
 * file:     unit_021B95A0_p06.c
 * unit:     yes
 * function: func_021BA31C, func_021BA37C
 * address:  0x021BA31C
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02028484  0x02028484  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045770  0x02045770  arm
 *   func_02045334  0x02045334  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B62E0  0x021B62E0  thumb  ov067
 *   func_021BA6B8  0x021BA6B8  thumb  ov068
 *   func_02012BF8  0x02012BF8  thumb
 *   func_021B6598  0x021B6598  thumb  ov067
 *   d_021BB5D4     0x021BB5D4  data  a4
 */
#include "../../matched/include/Obj03658.h"
#include "../../matched/include/Obj02762.h"

struct Blk;
struct PrintSys;
struct Descriptor;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef signed int     s32;

typedef unsigned short u16;

typedef struct { u32 w[16]; } Tbl;

typedef struct { u32 w[8]; } Req;

extern s32 func_02028484(struct Blk *blk, void *h);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void *func_02045770(struct Descriptor *p);
extern void func_02045334(struct Descriptor *d);
extern void func_02082BCC(void *p, u32 a, u32 b);
extern u32  func_021B62E0(Req *r, u16 a);
extern void func_021BA6B8(u8 *p, u32 arg);
extern int func_02012BF8(int a0, int a1);
extern void func_021B6598(unsigned char *p, unsigned int id, unsigned int v);
int func_021BA31C(u8 *p);
void func_021BA37C(u8 *p, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, u16 s3);
extern Tbl  d_021BB5D4;


int func_021BA31C(u8 *p)
{
    u32 t;

    switch (((struct Obj03658 *)p)->f28) {
    case 0:
    default:
        return 1;
    case 2:
        t = ((struct Obj03658 *)p)->f24;
        if (p[0x20] != 0) {
            if (func_0201C6C4((struct PrintSys *)t, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj03658 *)p)->f1C))) == 0) {
                func_02045334((struct Descriptor *)((struct Obj03658 *)p)->f1C);
                p[0x20] = 0;
            }
        }
        if (p[0x20] == 0) {
            return 1;
        }
        return 0;
    case 1:
        return func_02028484((struct Blk *)(p + 0x2c), (void *)(((struct Obj03658 *)p)->f8));
    }
}


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
