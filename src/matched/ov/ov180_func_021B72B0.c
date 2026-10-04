/*
 * function: func_021B72B0
 * address: 0x021B72B0
 * packet: pkt_ov180_021B72B0
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B73E4 0x021B73E4 thumb ov180
 */
#include "../include/Obj03876.h"
extern void func_021B73E4(char *,int,short,short);
int func_021B72B0(char *p,int i) {
    if(((struct Obj03876 *)p)->f915F==8) {
        func_021B73E4(p,i,((struct Obj03876 *)p)->f9160,((struct Obj03876 *)p)->f9162);
        return 0;
    }
    func_021B73E4(p,i,((struct Obj03876 *)p)->f9160+*(short *)(p+0x9164+((struct Obj03876 *)p)->f915F*2),((struct Obj03876 *)p)->f9162+*(short *)(p+0x9174+((struct Obj03876 *)p)->f915F*2));
    (((struct Obj03876 *)p)->f915F)++;
    return 1;
}
