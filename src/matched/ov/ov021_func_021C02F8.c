/*
 * function: func_021C02F8
 * address:  0x021C02F8
 * packet:   pkt_ov021_021C02F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218FE80  0x0218FE80  thumb  ov021
 *   func_0218FEA0  0x0218FEA0  thumb  ov021
 *   func_0218FEA4  0x0218FEA4  thumb  ov021
 *   func_0218FE78  0x0218FE78  thumb  ov021
 *   func_0218FEC0  0x0218FEC0  thumb  ov021
 *   func_0218FF00  0x0218FF00  thumb  ov021
 */
#include "../include/Obj02724.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct { u32 w[8]; } Blk32;

extern void *func_02188C58(void *p);
extern void *func_0218FE80(void *a);
extern void func_0218FEA0(u8 *p, u32 v);
extern void func_0218FEA4(u32 a);
extern void func_0218FE78(u32 a, u8 *b);
extern void func_0218FEC0(u8 *o);
extern int func_0218FF00(u32 a);

void func_021C02F8(u8 *p)
{
    u32 a;
    u32 b;

    a = (u32)func_02188C58((void *)(((struct Obj02724 *)p)->f4));
    b = (u32)func_0218FE80((void *)(((struct Obj02724 *)p)->f4));
    ((struct Obj02724 *)p)->f24 = 0x3c;
    ((struct Obj02724 *)p)->f68 = 1;
    ((struct Obj02724 *)p)->f6C = 1;
    ((struct Obj02724 *)p)->f70 = b;
    func_0218FEA0((u8 *)b, (u32)(p + 0x24));
    func_0218FEA4(((struct Obj02724 *)p)->f70);
    func_0218FE78(a, p + 0x28);
    *(Blk32 *)(p + 0x48) = *(Blk32 *)(p + 0x28);
    ((struct Obj02724 *)p)->f4C -= 0x64000;
    func_0218FEC0((u8 *)(((struct Obj02724 *)p)->f70));
    func_0218FF00(((struct Obj02724 *)p)->f70);
}
