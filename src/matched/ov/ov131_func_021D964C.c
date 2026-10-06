/*
 * function: func_021D964C
 * address: 0x021D964C
 * packet: pkt_ov131_021D964C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020452E8 0x020452E8 arm
 */
#include "../include/Obj05394.h"
typedef unsigned char u8;
struct Descriptor;
typedef unsigned int   u32;
extern u32 func_020452E8(struct Descriptor *d);
void func_021D964C(u8 *a,u8 *p)
{
    if(((struct Obj05394 *)p)->f20!=0) {
        func_020452E8(((struct Obj05394 *)p)->f20);
        ((struct Obj05394 *)p)->f20=0;
    }
    if(((struct Obj05394 *)p)->f24!=0) {
        func_020452E8(((struct Obj05394 *)p)->f24);
        ((struct Obj05394 *)p)->f24=0;
    }
}
