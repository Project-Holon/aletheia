/*
 * function: func_021D78C0
 * address: 0x021D78C0
 * packet: pkt_ov123_021D78C0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D75D0 0x021D75D0 thumb ov123
 *   func_021D76F0 0x021D76F0 thumb ov123
 *   func_021D5D8C 0x021D5D8C thumb ov123
 *   func_021D77C4 0x021D77C4 thumb ov123
 */
#include "../include/Obj02837.h"
extern int func_021D5D8C(int);
extern void func_021D77C4(int,int);
extern void func_021D75D0(int a);
extern void func_021D76F0(int a);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021D6EE0(u8 *p, u32 v, int unused);
void func_021D78C0(int a)
{
    switch(((struct Obj02837 *)a)->fA7) {
    case 0: func_021D6EE0((u8 *)a,(int)func_021D75D0,0x3cb); break;
    case 1: func_021D77C4(a,func_021D5D8C(((struct Obj02837 *)a)->f8)-2); break;
    case 2: func_021D6EE0((u8 *)a,(int)func_021D76F0,0x3d1); break;
    }
}
