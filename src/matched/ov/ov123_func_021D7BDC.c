/*
 * function: func_021D7BDC
 * address: 0x021D7BDC
 * packet: pkt_ov123_021D7BDC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D7B68 0x021D7B68 thumb ov123
 *   func_021D746C 0x021D746C thumb ov123
 */
#include "../include/Obj05366.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D7B68(char *p);
extern void func_021D746C(int a);
void func_021D7BDC(char *p)
{
    if (((struct Obj05366 *)p)->fA5) {
        p[0xa7] = 0;
        func_021D6EE0((u8 *)p, (int)func_021D7B68, 0x465);
        return;
    }
    if (((struct Obj05366 *)p)->fA4) {
        p[0xa7] = 1;
        func_021D6EE0((u8 *)p, (int)func_021D7B68, 0x46a);
        return;
    }
    if (((struct Obj05366 *)p)->fA6) {
        p[0xa7] = 2;
        func_021D6EE0((u8 *)p, (int)func_021D7B68, 0x46f);
        return;
    }
    func_021D6EE0((u8 *)p, (int)func_021D746C, 0x472);
}
