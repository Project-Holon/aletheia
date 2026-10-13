/*
 * function: func_021D4BA8
 * address: 0x021D4BA8
 * packet: pkt_ov123_021D4BA8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_021D4244 0x021D4244 thumb ov123
 *   func_021D4B44 0x021D4B44 thumb ov123
 */
#include "../include/Obj06458.h"
typedef unsigned int u32;
typedef unsigned short u16;
struct Obj;
extern void func_020061E4(u32 a);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void func_021D4244(char *, void *, int);
extern void func_021D4B44(char *);
int func_021D4BA8(int n, char *p)
{
    ((struct Obj06458 *)p)->f270 = n;
    switch (n) {
    case 0:
        func_020061E4(0x73b);
        CLACT_SetActorAnimSeq(((struct Obj06458 *)p)->f2A0, 14);
        func_021D4244(p, func_021D4B44, 0x389);
        ((struct Obj06458 *)p)->f8 = 2;
        break;
    case 1:
        func_020061E4(0x73b);
        ((struct Obj06458 *)p)->f8 = 3;
        func_021D4244(p, func_021D4B44, 0x393);
        break;
    case 2:
        func_020061E4(0x73c);
        ((struct Obj06458 *)p)->f8 = 0;
        func_021D4244(p, func_021D4B44, 0x399);
        break;
    }
    return 1;
}
