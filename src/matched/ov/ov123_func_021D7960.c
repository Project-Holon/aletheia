/*
 * function: func_021D7960
 * address: 0x021D7960
 * packet: pkt_ov123_021D7960
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5D24 0x021D5D24 thumb ov123
 *   func_021D7910 0x021D7910 thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 */
#include "../include/Obj13988.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_021D5D24(char *p);
extern void func_021D7910(int a);
extern void func_021D6FF0(char *p);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
void func_021D7960(int a)
{
    if (func_021D5D24((char *)(((struct Obj13988 *)a)->f8))) {
        func_021D6EE0((u8 *)a, (int)func_021D7910, 0x3f1);
        return;
    }
    ((struct Obj13988 *)a)->f80 = 0xfff0;
    func_021D6EE0((u8 *)a, (int)func_021D6FF0, 0x3f5);
}
