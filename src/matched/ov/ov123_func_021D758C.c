/*
 * function: func_021D758C
 * address: 0x021D758C
 * packet: pkt_ov123_021D758C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020090F8 0x020090F8 thumb
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D7560 0x021D7560 thumb ov123
 */
#include "../include/Obj13986.h"
struct Big;
struct Sub02009210Obj;
extern void *func_02012EBC(struct Big *p);
extern int func_02012E7C(char *p, int a1);
struct Sub02007324Ctrl;
extern void func_0200734C(struct Sub02007324Ctrl *,unsigned int);
extern struct Sub02009210Obj *func_02009210(void *sys);
struct Sub020090B0Obj;
extern void func_020090F8(struct Sub020090B0Obj *obj, unsigned char value);
typedef unsigned char  u8;
extern void func_021D7560(u8 *p);
typedef unsigned int   u32;
extern void func_021D6EE0(u8 *p, u32 v, int unused);
void func_021D758C(u8 *a)
{
    int b = (int)func_02012EBC((struct Big *)(((struct Obj13986 *)a)->f2C));
    if(func_02012E7C((char *)(((struct Obj13986 *)a)->f2C),4)==2) {
        func_0200734C((struct Sub02007324Ctrl *)b,4);
        func_020090F8((struct Sub020090B0Obj *)func_02009210((void *)b),1);
        func_021D6EE0(a,(int)func_021D7560,0x333);
    }
}
