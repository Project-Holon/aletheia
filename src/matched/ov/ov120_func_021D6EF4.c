/*
 * function: GTSNEGO_MSG_CreateIconActors
 * address: 0x021D6EF4
 * packet: pkt_ov120_021D6EF4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: declarations x,y,z,b reproduce the descending stack slots; p+i*4+offset keeps the per-element pointer.
 * symbols:
 *   gGtsnegoIconX 0x021D892C data a2
 *   gGtsnegoIconY 0x021D8924 data a2
 *   gGtsnegoIconZ 0x021D893C data a2
 *   gGtsnegoIconW 0x021D8934 data a2
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj06439.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Triple { u16 a[3]; } Triple;
typedef struct Record { u16 x,y,z; u8 a,b; } Record;
extern const Triple gGtsnegoIconX,gGtsnegoIconY,gGtsnegoIconZ,gGtsnegoIconW;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *,u32,u32,u32,const void *,u16,u16);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void GTSNEGO_MSG_CreateIconActors(u8 *p,int flag)
{
    Record r;
    Triple x=gGtsnegoIconX;
    Triple y=gGtsnegoIconY;
    Triple z=gGtsnegoIconZ;
    Triple b=gGtsnegoIconW;
    int i;
    for(i=0;i<3;i++) {
        if(flag || i!=0) {
            r.x=x.a[i]; r.y=y.a[i]; r.z=z.a[i]; r.a=i; r.b=b.a[i];
            *(void **)(p+i*4+0x140)=CLACT_CreateActor((void *)((struct Obj06439 *)p)->f10,((struct Obj06439 *)p)->f28,((struct Obj06439 *)p)->f18,((struct Obj06439 *)p)->f74,&r,1,((struct Obj06439 *)p)->fF4);
            CLACT_SetActorAutoAnim(*(void **)(p+i*4+0x140),1);
            CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x140),1);
        }
    }
}
