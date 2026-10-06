/*
 * function: func_021D6F04
 * address: 0x021D6F04
 * packet: pkt_ov123_021D6F04
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D580C 0x021D580C thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D6EE8 0x021D6EE8 thumb ov123
 */
#include "../include/Obj13984.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern int func_021D580C(char *);
extern void func_0202208C(void *, u32, u32, u32, u32, u32, u32);
typedef unsigned char  u8;
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D6EE8(char *);
void func_021D6F04(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj13984 *)p)->f18)) {
        func_0202208C(0,0,0,0,6,1,((struct Obj13984 *)p)->f0);
        func_021D6EE0((u8 *)p,(int)func_021D6EE8,0x16b);
    }
}
