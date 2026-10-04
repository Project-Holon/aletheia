/*
 * function: func_021D7B68
 * address: 0x021D7B68
 * packet: pkt_ov123_021D7B68
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200C6E4 0x0200C6E4 thumb
 *   func_021D5B10 0x021D5B10 thumb ov123
 *   func_021D5BD4 0x021D5BD4 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D7A5C 0x021D7A5C thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 */
#include "../include/Obj03271.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_0200C6E4(void);
extern u32 func_0200E8B0(void);
extern char *func_021D5B10(int heap, int size);
extern int func_021D5BD4(char *p);
extern void func_021D6EE0(char *, int, int);
extern void func_021D7A5C(u8 *p);
extern void func_021D6FF0(char *p);
void func_021D7B68(char *p)
{
    switch (((struct Obj03271 *)p)->fA7) {
    case 0: ((struct Obj03271 *)p)->f8 = func_021D5B10(((struct Obj03271 *)p)->f0, func_0200C6E4() + 4); break;
    case 1: ((struct Obj03271 *)p)->f8 = func_021D5B10(((struct Obj03271 *)p)->f0, 0x20000); break;
    case 2: ((struct Obj03271 *)p)->f8 = func_021D5B10(((struct Obj03271 *)p)->f0, func_0200E8B0() + 4); break;
    }
    if (func_021D5BD4(((struct Obj03271 *)p)->f8)) {
        func_021D6EE0(p, (int)func_021D7A5C, 0x458);
        return;
    }
    ((struct Obj03271 *)p)->f80 = 0xfff0;
    func_021D6EE0(p, (int)func_021D6FF0, 0x45c);
}
