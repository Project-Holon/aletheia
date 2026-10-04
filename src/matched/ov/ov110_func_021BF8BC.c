/*
 * function: func_021BF8BC
 * address: 0x021BF8BC
 * packet: pkt_ov110_021BF8BC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: two trailing zero alignment bytes.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj03755.h"
typedef unsigned char u8;
struct Obj;
struct U16Vec;
struct Descriptor;
extern void func_0204B3B4(struct Obj *),func_02045808(struct U16Vec *),func_020452E8(struct Descriptor *),func_020307B0(void *);
void func_021BF8BC(u8 *p) {
    if(*(struct Obj * *)&((struct Obj03755 *)p)->f14) func_0204B3B4(*(struct Obj * *)&((struct Obj03755 *)p)->f14);
    if(*(struct Obj * *)&((struct Obj03755 *)p)->f1C) func_0204B3B4(*(struct Obj * *)&((struct Obj03755 *)p)->f1C);
    if(*(struct U16Vec * *)&((struct Obj03755 *)p)->f48) func_02045808(*(struct U16Vec * *)&((struct Obj03755 *)p)->f48);
    func_020452E8(*(struct Descriptor * *)&((struct Obj03755 *)p)->f10);
    func_020452E8(*(struct Descriptor * *)&((struct Obj03755 *)p)->fC);
    func_020307B0(p);
}
