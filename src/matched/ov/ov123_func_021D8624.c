/*
 * function: func_021D8624
 * address: 0x021D8624
 * packet: pkt_ov123_021D8624
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D85F0 0x021D85F0 thumb ov123
 *   func_021D580C 0x021D580C thumb ov123
 *   func_021D57B8 0x021D57B8 thumb ov123
 */
#include "../include/Obj13996.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D85F0(char *);
extern int func_021D580C(char *);
extern void func_021D57B8(char *, int);
void func_021D8624(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj13996 *)p)->f18)) {
        func_021D57B8(*(char * *)&((struct Obj13996 *)p)->f18, 20);
        func_021D6EE0((u8 *)p, (int)func_021D85F0, 0x758);
    }
}
