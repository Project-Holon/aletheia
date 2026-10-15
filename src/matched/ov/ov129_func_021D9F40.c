/*
 * function: WF2DMAP_SCENE_UpdateCursorAnim
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
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   WF2DMAP_SCENE_SetCursorVisible 0x021D9E48 thumb ov129
 */
#include "../include/Obj14060.h"
typedef unsigned short u16;
typedef unsigned int   u32;
struct Actor;
struct Obj;
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void WF2DMAP_SCENE_SetCursorVisible(char *,int,int);
void WF2DMAP_SCENE_UpdateCursorAnim(char *p)
{
    int i;
    for(i=1;i<3;i++){
        int a=CLACT_GetActorAnimSeq(*(void **)(p+i*0x1c+0x194));
        if(a==3){
            if(CLACT_IsActorAnimActive(*(void **)(p+i*0x1c+0x194))==0){
                CLACT_SetActorAnimSeq(*(void **)(p+i*0x1c+0x194),*(int *)(p+i*0x1c+0x188));
                if(((struct Obj14060 *)p)->f2FC==1) WF2DMAP_SCENE_SetCursorVisible(p,1,0);
                else WF2DMAP_SCENE_SetCursorVisible(p,1,1);
                WF2DMAP_SCENE_SetCursorVisible(p,2,0);
            }
        }else{
            if(a!=*(int *)(p+i*0x1c+0x188)) CLACT_SetActorAnimSeq(*(void **)(p+i*0x1c+0x194),*(int *)(p+i*0x1c+0x188));
            if(CLACT_GetActorAnimSeq(*(void **)(p+i*0x1c+0x194))!=3){
                if(((struct Obj14060 *)p)->f2FC==1) WF2DMAP_SCENE_SetCursorVisible(p,1,0);
                else WF2DMAP_SCENE_SetCursorVisible(p,1,1);
            }
        }
    }
}
