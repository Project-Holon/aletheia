/*
 * function: func_021D83A4
 * address: 0x021D83A4
 * packet: pkt_ov123_021D83A4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D834C 0x021D834C thumb ov123
 *   func_021D580C 0x021D580C thumb ov123
 */
#include "../include/Obj22967.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D834C(char *);
extern int func_021D580C(char *);
void func_021D83A4(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj22967 *)p)->f18)) {
        func_021D6EE0((u8 *)p, (int)func_021D834C, 0x68d);
    }
}
