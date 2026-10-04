/*
 * function: func_021D7A18
 * address: 0x021D7A18
 * packet: pkt_ov123_021D7A18
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5CF8 0x021D5CF8 thumb ov123
 *   func_021D79A4 0x021D79A4 thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 */
#include "../include/Obj13989.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_021D5CF8(char *p);
extern void func_021D79A4(int a);
extern void func_021D6FF0(char *p);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
void func_021D7A18(int a)
{
    if (func_021D5CF8((char *)(((struct Obj13989 *)a)->f8))) {
        func_021D6EE0((u8 *)a, (int)func_021D79A4, 0x415);
        return;
    }
    ((struct Obj13989 *)a)->f80 = 0xfff0;
    func_021D6EE0((u8 *)a, (int)func_021D6FF0, 0x419);
}
