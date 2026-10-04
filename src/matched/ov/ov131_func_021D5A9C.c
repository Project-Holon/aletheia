/*
 * function: func_021D5A9C
 * address: 0x021D5A9C
 * packet: pkt_ov131_021D5A9C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021D62E4 0x021D62E4 thumb ov131
 */
#include "../include/Obj00136.h"
typedef unsigned int   u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern int func_021D62E4(char *p);
void func_021D5A9C(char *p,int a)
{
    *(int *)&((struct Obj00136 *)p)->f44=a;
    if(a==0){
        func_0204B3DC(((struct Obj00136 *)p)->f178,0);
        func_0204B3DC(((struct Obj00136 *)p)->f17C,0);
        func_0204B3DC(((struct Obj00136 *)p)->f180,0);
        func_0204B3DC(((struct Obj00136 *)p)->f184,0);
        func_0204B3DC(((struct Obj00136 *)p)->f188,0);
        func_0204B3DC(((struct Obj00136 *)p)->f18C,0);
        func_0204B3DC(((struct Obj00136 *)p)->f190,0);
    }else{
        func_0204B3DC(((struct Obj00136 *)p)->f178,1);
        func_0204B3DC(((struct Obj00136 *)p)->f17C,1);
        if(((struct Obj00136 *)p)->f40==1) func_0204B3DC(((struct Obj00136 *)p)->f180,1);
        func_0204B3DC(((struct Obj00136 *)p)->f188,1);
        func_0204B3DC(((struct Obj00136 *)p)->f18C,1);
        if(func_021D62E4(p)==1){
            func_0204B3DC(((struct Obj00136 *)p)->f184,1);
            func_0204B3DC(((struct Obj00136 *)p)->f190,1);
        }
    }
}
