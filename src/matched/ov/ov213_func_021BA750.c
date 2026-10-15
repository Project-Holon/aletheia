/*
 * function: COMM_BTL_DEMO_MAIN_CreateSideActor
 * address: 0x021BA750
 * packet: pkt_ov213_021BA750
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   COMM_BTL_DEMO_MAIN_CreateActor 0x021BA71C thumb ov213
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 */
struct Obj;
extern void *COMM_BTL_DEMO_MAIN_CreateActor(char *p, int a, int b, unsigned short c);extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v),CLACT_SetActorDrawPriority(void *,unsigned);
void *COMM_BTL_DEMO_MAIN_CreateSideActor(void *p,int kind,unsigned a){int x,y;void *v;if(kind==0){x=206;y=152;}else{x=50;y=40;}v=COMM_BTL_DEMO_MAIN_CreateActor(p,x,y,a);CLACT_SetActorDrawEnable(v,0);CLACT_SetActorDrawPriority(v,1);return v;}
