/*
 * function: func_021D8154
 * address: 0x021D8154
 * packet: pkt_ov123_021D8154
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D57B8 0x021D57B8 thumb ov123
 *   func_021D5A7C 0x021D5A7C thumb ov123
 *   func_021D62E0 0x021D62E0 thumb ov123
 *   func_021D65F4 0x021D65F4 thumb ov123
 *   func_021D6650 0x021D6650 thumb ov123
 *   func_021D62BC 0x021D62BC thumb ov123
 *   func_021D62B4 0x021D62B4 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8130 0x021D8130 thumb ov123
 */
#include "../include/Obj03795.h"
typedef unsigned char u8;
extern void func_021D57B8(char *, int);
extern void func_021D5A7C(char *);
extern void func_021D62E0(u8 *, int);
extern void func_021D65F4(u8 *p);
extern void func_021D6650(u8 *p, int flag);
extern void func_021D62BC(u8 *, int, unsigned int);
extern void func_021D62B4(u8 *p, unsigned int i);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D8130(char *p);
void func_021D8154(char *p)
{
    func_021D57B8(*(char * *)&((struct Obj03795 *)p)->f18, 11);
    func_021D5A7C(*(char * *)&((struct Obj03795 *)p)->f18);
    func_021D62E0(*(u8 * *)&((struct Obj03795 *)p)->f14, 8);
    func_021D65F4((u8 *)(*(char * *)&((struct Obj03795 *)p)->f14));
    func_021D6650((u8 *)(*(char * *)&((struct Obj03795 *)p)->f14), 1);
    func_021D62BC(*(u8 * *)&((struct Obj03795 *)p)->f14, 6, 5);
    func_021D62B4((u8 *)(*(char * *)&((struct Obj03795 *)p)->f14), 0);
    func_021D62B4((u8 *)(*(char * *)&((struct Obj03795 *)p)->f14), 12);
    func_020061E4(0x657);
    func_021D6EE0((u8 *)p, (int)func_021D8130, 0x5c3);
}
