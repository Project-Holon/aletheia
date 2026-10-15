/*
 * function: COMM_BTL_DEMO_MAIN_ShowBattleActor
 * address: 0x021BA68C
 * packet: pkt_ov213_021BA68C
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_ChangeActorAnimSeq 0x0204B8A0 arm
 */
struct Obj;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_ChangeActorAnimSeq(struct Obj *p, u16 v);
void COMM_BTL_DEMO_MAIN_ShowBattleActor(char *p,unsigned i,int kind){int n;switch(kind){case 0:n=7;break;case 1:n=8;break;case 2:n=9;break;}p+=24;CLACT_SetActorDrawEnable(*(void **)((unsigned)p+i*4),1);CLACT_SetActorAutoAnim(*(void **)((unsigned)p+i*4),1);CLACT_ChangeActorAnimSeq(*(void **)((unsigned)p+i*4),n);}
