/*
 * function: func_021BA720
 * address: 0x021BA720
 * packet: pkt_ov218_021BA720
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 */
typedef unsigned char u8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;
struct Actor;struct Obj;typedef struct PtS{s16 x,y;} PtS;extern u32 func_0204B3F4(struct Obj *);extern void func_0204B3DC(struct Obj *,u32);extern void CLACT_GetActorSurfacePos(struct Actor *,PtS *,u32);extern void func_0204B404(struct Obj *,const PtS *,u32);
int func_021BA720(u32 base,u32 i,u32 space,int y){PtS pos;int r;void *o;o=*(void **)(base+i*4);r=0;if(func_0204B3F4(o)==0){func_0204B3DC(o,1);r=1;CLACT_GetActorSurfacePos(o,&pos,space);pos.y=y;func_0204B404(o,&pos,space);}return r;}
