/*
 * function: func_021BB2CC
 * address: 0x021BB2CC
 * packet: pkt_ov110_021BB2CC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero padding
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj03752.h"
typedef unsigned char u8;
struct Descriptor;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_020452E8(struct Descriptor *d);
extern void func_020307B0(void *);
void func_021BB2CC(u8 *p) {
    u8 i;
    if(((struct Obj03752 *)p)->f54) func_0204B3B4(((struct Obj03752 *)p)->f54);
    for(i=0;i<12;i++) if(*(void **)(p+0x60+i*4)) func_020452E8(*(void **)(p+0x60+i*4));
    if(((struct Obj03752 *)p)->f90) func_020452E8(((struct Obj03752 *)p)->f90);
    if(((struct Obj03752 *)p)->f94) func_020452E8(((struct Obj03752 *)p)->f94);
    if(((struct Obj03752 *)p)->f98) func_020452E8(((struct Obj03752 *)p)->f98);
    func_020307B0(p);
}
