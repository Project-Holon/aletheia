/*
 * function: func_021C0EB0
 * address: 0x021C0EB0
 * packet: pkt_ov110_021C0EB0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035CB8 0x02035CB8 arm
 *   func_0204B550 0x0204B550 arm
 *   func_021C0E3C 0x021C0E3C thumb ov110
 */
#include "../include/Obj05301.h"
typedef unsigned int   u32;
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern void func_0204B550(void *,int,int);
extern void func_021C0E3C(unsigned y, int count, short *out, short *pos);
int func_021C0EB0(char *p) {
    unsigned x,y;
    unsigned short index;
    short pos;
    if(!func_02035CB8(&x,&y)) {
        ((struct Obj05301 *)p)->f99=(((struct Obj05301 *)p)->f99&~1);
        return 0;
    }
    func_021C0E3C(y,((struct Obj05301 *)p)->f98,(short int *)(&index),&pos);
    func_0204B550(((struct Obj05301 *)p)->f8,pos,1);
    if((unsigned short)index!=((struct Obj05301 *)p)->f96) {
        ((struct Obj05301 *)p)->f96=index;
        return 1;
    }
    return 0;
}
