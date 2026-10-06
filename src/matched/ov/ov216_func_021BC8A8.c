/*
 * function: func_021BC8A8
 * address: 0x021BC8A8
 * packet: pkt_ov216_021BC8A8
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020452E8 0x020452E8 arm
 */
#include "../include/Obj01437.h"
#include "../include/Obj05553.h"
typedef unsigned int   u32;
struct Descriptor;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0202DC08(struct Obj *p);
void func_021BC8A8(char *p)
{
    int i=0,j;
    char *base=p+0x15c;
    for(;i<2;i++) {
        char *q=base+i*128;
        func_0204B3DC(((struct Obj05553 *)q)->f78,0); func_0204B3B4(((struct Obj05553 *)q)->f78);
        func_0204B3DC(((struct Obj05553 *)q)->f74,0); func_0204B3B4(((struct Obj05553 *)q)->f74);
        func_020452E8(((struct Obj05553 *)q)->f60);
        for(j=0;j<2;j++) func_020452E8(*(void **)(q+0x40+j*16));
        for(j=0;j<4;j++) func_020452E8(*(void **)(q+j*16));
        func_020452E8(((struct Obj05553 *)q)->f70);
    }
    func_0202DC08(((struct Obj01437 *)p)->f158);
}
