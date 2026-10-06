/*
 * function: func_021B8CB4
 * address: 0x021B8CB4
 * packet: pkt_ov070_021B8CB4
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B98C 0x0204B98C arm
 *   func_021B6100 0x021B6100 thumb ov070
 */
#include "../include/Obj00002.h"
typedef unsigned short u16;
typedef void (*Callback)(void *);
typedef unsigned int   u32;
struct Actor;
extern u32 func_0204B98C(struct Actor *a);
extern void func_021B6100(char *p, int k);
void func_021B8CB4(char *p)
{
    if (func_0204B98C((struct Actor *)(*(int *)(p + 0x710 + ((struct Obj00002 *)p)->f864 * 4))) == 0) {
        ((struct Obj00002 *)p)->f864 = 0;
        func_021B6100(p, (int)(*(Callback *)&((struct Obj00002 *)p)->f868));
    }
}
