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
extern void func_021D6EE0(char *, int, int);
extern void func_021D8A38(char *);
extern int func_021D580C(char *);
void func_021D8A7C(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj22981 *)p)->f18)) {
        func_021D6EE0(p, (int)func_021D8A38, 0x8a0);
    }
}
