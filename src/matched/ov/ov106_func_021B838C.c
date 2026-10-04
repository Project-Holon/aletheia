/*
 * function: func_021B838C
 * address: 0x021B838C
 * packet: pkt_ov106_021B838C
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_021B8524 0x021B8524 thumb ov106
 */
#include "../include/Obj02814.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
extern void func_021B8524(u8 *);
void func_021B838C(u8 *p) {
    int value;
    if(((struct Obj02814 *)p)->f594==0)return;
    ((struct Obj02814 *)p)->f594=0;
    value=((struct Obj02814 *)p)->f556;
    if(value%24==0) {
        if(((struct Obj02814 *)p)->f55C!=value/24)func_020061E4(1605);
        ((struct Obj02814 *)p)->f55C=((struct Obj02814 *)p)->f556/24;
        ((struct Obj02814 *)p)->f564=-40;
        ((struct Obj02814 *)p)->f566=24;
        func_021B8524(p);
        ((struct Obj02814 *)p)->f590=1;
    } else ((struct Obj02814 *)p)->f598=1;
}
