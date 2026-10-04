/*
 * function: func_021BAD60
 * address:  0x021BAD60
 * packet:   pkt_ov068_021BAD60
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_021BA1C4  0x021BA1C4  thumb  ov068
 */
#include "../include/Obj02763.h"
#include "../include/Obj09871.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void  func_02082BCC(void *p, u32 v, u32 n);
struct MsgBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_021BA1C4(u8 *p, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u16 s2);

void func_021BAD60(u8 *p, u32 a, u32 b, void *c, u32 s0, u32 s1, u32 s2, u16 s3)
{
    int i;

    func_02082BCC(p, 0, 0x70);
    ((struct Obj02763 *)p)->f54 = 0;
    ((struct Obj02763 *)p)->f6C = s1;
    func_021BA1C4(p, a, b, (u32)c, s0, s2, s3);
    for (i = 0; i < 2; i++) {
        u8 *e = p + i * 12;

        ((struct Obj09871 *)e)->f3C = func_02045EC0(c, i + 0x22);
        ((struct Obj09871 *)e)->f40 = 0x39E3;
        ((struct Obj09871 *)e)->f44 = 0;
    }
    ((struct Obj02763 *)p)->f58 = s3;
    ((struct Obj02763 *)p)->f5C = 2;
    *(u8 * *)&((struct Obj02763 *)p)->f60 = p + 0x3c;
    ((struct Obj02763 *)p)->f64 = 1;
    ((struct Obj02763 *)p)->f68 = 0x20;
    ((struct Obj02763 *)p)->f69 = 0xc;
    ((struct Obj02763 *)p)->f6A = 0xd;
    ((struct Obj02763 *)p)->f6B = 3;
}
