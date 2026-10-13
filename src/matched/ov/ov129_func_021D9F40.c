/*
 * function: func_021D9F40
 * address: 0x021D9F40
 * packet: pkt_ov129_021D9F40
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes at 0x021D9FEE.
 * symbols:
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B878 0x0204B878 arm
 *   func_021D9E48 0x021D9E48 thumb ov129
 */
#include "../include/Obj14060.h"
typedef unsigned short u16;
typedef unsigned int   u32;
struct Actor;
struct Obj;
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021D9E48(char *,int,int);
void func_021D9F40(char *p)
{
    int i;
    for(i=1;i<3;i++){
        int a=CLACT_GetActorAnimSeq(*(void **)(p+i*0x1c+0x194));
        if(a==3){
            if(func_0204B98C(*(void **)(p+i*0x1c+0x194))==0){
                func_0204B878(*(void **)(p+i*0x1c+0x194),*(int *)(p+i*0x1c+0x188));
                if(((struct Obj14060 *)p)->f2FC==1) func_021D9E48(p,1,0);
                else func_021D9E48(p,1,1);
                func_021D9E48(p,2,0);
            }
        }else{
            if(a!=*(int *)(p+i*0x1c+0x188)) func_0204B878(*(void **)(p+i*0x1c+0x194),*(int *)(p+i*0x1c+0x188));
            if(CLACT_GetActorAnimSeq(*(void **)(p+i*0x1c+0x194))!=3){
                if(((struct Obj14060 *)p)->f2FC==1) func_021D9E48(p,1,0);
                else func_021D9E48(p,1,1);
            }
        }
    }
}
