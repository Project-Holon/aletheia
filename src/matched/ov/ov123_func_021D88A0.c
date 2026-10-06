/*
 * function: func_021D88A0
 * address: 0x021D88A0
 * packet: pkt_ov123_021D88A0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D885C 0x021D885C thumb ov123
 *   func_021D57B8 0x021D57B8 thumb ov123
 */
#include "../include/Obj22977.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D885C(char *);
extern void func_021D57B8(char *, int);
void func_021D88A0(char *p)
{
    func_021D57B8(*(char * *)&((struct Obj22977 *)p)->f18, 19);
    func_021D6EE0((u8 *)p, (int)func_021D885C, 0x817);
}
