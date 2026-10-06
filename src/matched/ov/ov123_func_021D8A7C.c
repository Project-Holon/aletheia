/*
 * function: func_021D8A7C
 * address: 0x021D8A7C
 * packet: pkt_ov123_021D8A7C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8A38 0x021D8A38 thumb ov123
 *   func_021D580C 0x021D580C thumb ov123
 */
#include "../include/Obj22981.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D8A38(char *);
extern int func_021D580C(char *);
void func_021D8A7C(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj22981 *)p)->f18)) {
        func_021D6EE0((u8 *)p, (int)func_021D8A38, 0x8a0);
    }
}
