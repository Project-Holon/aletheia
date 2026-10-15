/*
 * function: UN_SELECT_SetActorPosEx
 * address: 0x021BA720
 * packet: pkt_ov218_021BA720
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
typedef unsigned char u8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;
struct Actor;struct Obj;typedef struct PtS{s16 x,y;} PtS;extern u32 CLACT_GetActorDrawEnable(struct Obj *);extern void CLACT_SetActorDrawEnable(struct Obj *,u32);extern void CLACT_GetActorSurfacePos(struct Actor *,PtS *,u32);extern void CLACT_AddActorSurfacePos(struct Obj *,const PtS *,u32);
int UN_SELECT_SetActorPosEx(u32 base,u32 i,u32 space,int y){PtS pos;int r;void *o;o=*(void **)(base+i*4);r=0;if(CLACT_GetActorDrawEnable(o)==0){CLACT_SetActorDrawEnable(o,1);r=1;CLACT_GetActorSurfacePos(o,&pos,space);pos.y=y;CLACT_AddActorSurfacePos(o,&pos,space);}return r;}
