/*
 * function: func_021B9D34
 * address: 0x021B9D34
 * packet: pkt_ov181_021B9D34
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Padding: two zero bytes at 0x021B9DAE, then the next function.
 * symbols:
 *   func_02045088 0x02045088 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj03327.h"
extern void func_02045088(unsigned short);
extern unsigned func_020450F0(unsigned, unsigned, unsigned, unsigned, unsigned char, unsigned char, unsigned char);
struct Descriptor;
extern void func_02045334(struct Descriptor *);
typedef unsigned char  u8;
struct Cfg;
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(unsigned);
void func_021B9D34(char *p)
{
    unsigned h;
    func_02045088(0x8E);
    ((struct Obj03327 *)p)->f2BC = func_020450F0(1, 0, 0, 0x20, 0x19, 0xF, 1);
    ((struct Obj03327 *)p)->f2C4 = func_020450F0(5, 0, 0, 0x20, 0x1C, 0xF, 1);
    h = ((struct Obj03327 *)p)->f2BC;
    func_02045334((struct Descriptor *)h);
    func_02045374((struct Cfg *)h);
    func_020409B4(func_02045730((struct Descriptor *)h));
    h = ((struct Obj03327 *)p)->f2C4;
    func_02045334((struct Descriptor *)h);
    func_02045374((struct Cfg *)h);
    func_020409B4(func_02045730((struct Descriptor *)h));
}
