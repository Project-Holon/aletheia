/*
 * function: func_021B7FD0
 * address: 0x021B7FD0
 * packet: pkt_ov173_021B7FD0
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B878 0x0204B878 arm
 *   func_0204B8C4 0x0204B8C4 arm
 */
#include "../include/Obj02506.h"
#include "../include/Obj24192.h"
#include "../include/Obj24193.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B8C4(struct Obj *p, u32 value);
void func_021B7FD0(u8 *p,int direction)
{
    func_0204B8C4(((struct Obj02506 *)p)->f108,0);
    func_0204B8C4(((struct Obj02506 *)p)->f104,0);
    if(direction>0) {
        if(((struct Obj24192 *)(*(u8 * *)&((struct Obj02506 *)p)->f0))->f16+4 < ((struct Obj02506 *)p)->f1B8) func_0204B878(((struct Obj02506 *)p)->f104,10);
        else func_0204B878(((struct Obj02506 *)p)->f104,23);
        func_0204B878(((struct Obj02506 *)p)->f108,3);
    } else {
        if(((struct Obj24193 *)(*(u8 * *)&((struct Obj02506 *)p)->f0))->f16==0) func_0204B878(((struct Obj02506 *)p)->f108,24);
        else func_0204B878(((struct Obj02506 *)p)->f108,11);
        func_0204B878(((struct Obj02506 *)p)->f104,2);
    }
}
