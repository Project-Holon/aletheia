/*
 * function: func_021BA734
 * address:  0x021BA734
 * packet:   pkt_ov068_021BA734
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * a1/a2 are u16 parameters (stored with strh); as u32 the strh of a1 is
 * scheduled after the struct-copy source load.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B9944  0x021B9944  thumb  ov068
 *   func_021BABE0  0x021BABE0  thumb  ov068
 *   func_020355C4  0x020355C4  arm
 *   func_021BAA0C  0x021BAA0C  thumb  ov068
 */
#include "../../../matched/include/Obj00103.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 a; u32 b; u32 c; } Blk;

extern void func_02082BCC(void *p, u32 a, u32 b);
extern int func_021B9944(void *p, int i);
extern void func_021BABE0(u8 *p, int a, int b, int c);
extern u8 func_020355C4(void);
extern void func_021BAA0C(u8 *p, int flag);

void func_021BA734(u8 *p, u16 a1, u16 a2, u32 a3, Blk *src)
{
    int i;

    func_02082BCC(p, 0, 0x58);
    ((struct Obj00103 *)p)->f0 = a1;
    ((struct Obj00103 *)p)->f2 = a2;
    ((struct Obj00103 *)p)->f34 = 0x10;
    *(Blk *)(p + 0x44) = *src;
    for (i = 0; i < 11; i++) {
        *(u32 *)(p + i * 4 + 8) = func_021B9944((void *)a3, i + 2);
    }
    func_021BABE0(p, -8, -192, 192);
    if (func_020355C4() == 1) {
        ((struct Obj00103 *)p)->f4 = -1;
        func_021BAA0C(p, 0);
        *(u32 *)&((struct Obj00103 *)p)->f50 = 0;
    } else {
        *(u32 *)&((struct Obj00103 *)p)->f4 = 0;
        func_021BAA0C(p, 1);
        *(u32 *)&((struct Obj00103 *)p)->f50 = 1;
    }
}
