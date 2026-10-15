/*
 * function: WF2DMAP_SCENE_CreateCellActors
 * address: 0x021D9AB0
 * packet: pkt_ov129_021D9AB0
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two bytes of zero alignment padding.
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   WF2DMAP_SCENE_GetCellAnim 0x021DA158 thumb ov129
 */
#include "../include/Obj02185.h"
#include "../include/Obj06481.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { u16 x,y,frame; u8 speed,flag; } Params;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern int WF2DMAP_SCENE_GetCellAnim(int x, int flag);
void WF2DMAP_SCENE_CreateCellActors(char *p)
{
    Params s;
    int j=0;
    int h=((struct Obj02185 *)p)->f25C;
    int i,k=0;
    unsigned q;
    s.x=0; s.y=0; s.frame=0; s.speed=10; s.flag=0;
    for(i=0;i<(int)((unsigned)((struct Obj02185 *)p)->f23C+2);i++) {
        q=(unsigned)p+(unsigned)k*28;
        if(i==(int)((unsigned)k+(unsigned)((struct Obj06481 *)q)->f150+1)) {
            s.x=76+(unsigned)i*8; s.y=24; s.frame=22;
            ((struct Obj06481 *)q)->f15C=(int)CLACT_CreateActor((void *)h,((struct Obj02185 *)p)->f26C,((struct Obj02185 *)p)->f260,((struct Obj02185 *)p)->f284,&s,0,50);
            k++;
        } else {
            s.x=76+(unsigned)i*8; s.y=24;
            q=(unsigned)p+(unsigned)j*28;
            s.frame=WF2DMAP_SCENE_GetCellAnim(((struct Obj06481 *)q)->f0,((struct Obj06481 *)q)->f8);
            ((struct Obj06481 *)q)->fC=(int)CLACT_CreateActor((void *)h,((struct Obj02185 *)p)->f26C,((struct Obj02185 *)p)->f260,((struct Obj02185 *)p)->f284,&s,0,50);
            j++;
        }
    }
    if(((struct Obj02185 *)p)->f334==0 && ((struct Obj02185 *)p)->f338==0) {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj02185 *)p)->f15C,0);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj02185 *)p)->f178,0);
    }
}
