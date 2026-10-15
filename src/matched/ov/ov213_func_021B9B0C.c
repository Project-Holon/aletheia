/*
 * function: COMM_BTL_DEMO_MAIN_UpdateBattle
 * address: 0x021B9B0C
 * packet: pkt_ov213_021B9B0C
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 * UI_SCENE_GetPhaseFrame 0x021B61FC thumb ov067
 * UI_SCENE_AdvancePhaseFrame 0x021B6200 thumb ov067
 * COMM_BTL_DEMO_MAIN_UpdateRows 0x021BA444 thumb ov213
 * COMM_BTL_DEMO_MAIN_UpdateBattleActors 0x021BA650 thumb ov213
 * COMM_BTL_DEMO_MAIN_IsFullPartyMode 0x021B9E50 thumb ov213
 * COMM_BTL_DEMO_MAIN_LoadObject 0x021BA95C thumb ov213
 * COMM_BTL_DEMO_MAIN_InitEffect 0x021BA81C thumb ov213
 * COMM_BTL_DEMO_MAIN_MarkRowsDone 0x021BA480 thumb ov213
 * COMM_BTL_DEMO_MAIN_UpdateObjectAnime 0x021BA9D0 thumb ov213
 * COMM_BTL_DEMO_MAIN_GetSoundId 0x021B98DC thumb ov213
 * GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 * COMM_BTL_DEMO_MAIN_ShowBattleActor 0x021BA68C thumb ov213
 * CLACT_SetActorDrawEnable 0x0204B3DC arm
 * FADE_Start 0x0204E720 arm
 * COMM_BTL_DEMO_MAIN_StartEffect 0x021BA8E8 thumb ov213
 * d0 0x021BB0D4 data a4
 * d1 0x021BB0E0 data ov213
 * d2 0x021BB068 data ov213
 * d3 0x021BB074 data ov213
 * d4 0x021BB080 data ov213
 * d5 0x021BB098 data a4
 */
#include "../include/Obj01295.h"
#include "../include/Obj25690.h"
typedef unsigned int u32;
struct V {int x,y,z;};
extern const struct V d0,d1,d2,d3,d4,d5;
extern u32 UI_SCENE_GetPhaseFrame(const unsigned char*);
extern void UI_SCENE_AdvancePhaseFrame(unsigned char*);
extern void COMM_BTL_DEMO_MAIN_UpdateRows(void*);
extern void COMM_BTL_DEMO_MAIN_UpdateBattleActors(char *p);
extern int COMM_BTL_DEMO_MAIN_IsFullPartyMode(u32);
extern void COMM_BTL_DEMO_MAIN_LoadObject(unsigned char*,int),COMM_BTL_DEMO_MAIN_InitEffect(unsigned char*,u32),COMM_BTL_DEMO_MAIN_MarkRowsDone(void*);
extern int COMM_BTL_DEMO_MAIN_UpdateObjectAnime(unsigned char*),COMM_BTL_DEMO_MAIN_GetSoundId(int,int);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
struct Obj;
extern void COMM_BTL_DEMO_MAIN_ShowBattleActor(char *p, unsigned i, int kind);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void FADE_Start(u32,int,int,int);
extern int COMM_BTL_DEMO_MAIN_StartEffect(char *p, int b, int c);
int COMM_BTL_DEMO_MAIN_UpdateBattle(unsigned char *state,unsigned char *p)
{
    int stage,x,y,index;
    struct V v0,v1,v2,v3,v4,v5;
    stage=UI_SCENE_GetPhaseFrame(state);
    COMM_BTL_DEMO_MAIN_UpdateRows(p);COMM_BTL_DEMO_MAIN_UpdateBattleActors((char *)(p+0x498c));
    switch(stage){
    case 0:
        if(COMM_BTL_DEMO_MAIN_IsFullPartyMode(p[0x49c8]))COMM_BTL_DEMO_MAIN_LoadObject(p+0x24,1);
        else COMM_BTL_DEMO_MAIN_LoadObject(p+0x24,3);
        COMM_BTL_DEMO_MAIN_InitEffect(p+0x24,0xd);
        COMM_BTL_DEMO_MAIN_MarkRowsDone(p);UI_SCENE_AdvancePhaseFrame(state);break;
    case 1:
        if(COMM_BTL_DEMO_MAIN_UpdateObjectAnime(p+0x24)==0){
            if(((struct Obj01295 *)p)->f49CC==2)return 1;
            ((struct Obj01295 *)p)->f49D0=0;
            COMM_BTL_DEMO_MAIN_InitEffect(p+0x24,0xc);UI_SCENE_AdvancePhaseFrame(state);
        }break;
    case 2:
        if(((struct Obj01295 *)p)->f49D0==15){
            index=((struct Obj01295 *)p)->f49CC!=0;
            GFL_USE_PlaySeDefaultVolume(COMM_BTL_DEMO_MAIN_GetSoundId(2,((struct Obj25690 *)(*(unsigned char* *)&((struct Obj01295 *)p)->f4))->f50));
            COMM_BTL_DEMO_MAIN_ShowBattleActor((char *)(p+0x498c),index,0);
        }else if(((struct Obj01295 *)p)->f49D0==24){
            index=((struct Obj01295 *)p)->f49CC!=0;
            CLACT_SetActorDrawEnable(*(void**)((u32)p+(u32)index*4+0x499c),0);
        }else if(((struct Obj01295 *)p)->f49D0==45){
            index=((struct Obj01295 *)p)->f49CC!=1;
            COMM_BTL_DEMO_MAIN_ShowBattleActor((char *)(p+0x498c),index,1);
        }else if(((struct Obj01295 *)p)->f49D0==54){
            index=((struct Obj01295 *)p)->f49CC!=1;
            CLACT_SetActorDrawEnable(*(void**)((u32)p+(u32)index*4+0x499c),0);
        }else if(((struct Obj01295 *)p)->f49D0==120)FADE_Start(3,0,16,-3);
        else if(((struct Obj01295 *)p)->f49D0==128)return 1;
        if(((struct Obj01295 *)p)->f49D0%180==0){
            if(((struct Obj01295 *)p)->f49CC==1){x=-0x2800;y=0x2000;}
            else{x=0x2800;y=-0x1800;}
            v0=d0;v0.x=x;v0.y=y;COMM_BTL_DEMO_MAIN_StartEffect((char *)(p+0x24),0,(int)(&v0));
            v1=d1;v1.x=x;v1.y=y;COMM_BTL_DEMO_MAIN_StartEffect((char *)(p+0x24),1,(int)(&v1));
            v2=d2;v2.x=x;v2.y=y;COMM_BTL_DEMO_MAIN_StartEffect((char *)(p+0x24),2,(int)(&v2));
            v3=d3;v3.x=x;v3.y=y;COMM_BTL_DEMO_MAIN_StartEffect((char *)(p+0x24),3,(int)(&v3));
            v4=d4;v4.x=x;v4.y=y;COMM_BTL_DEMO_MAIN_StartEffect((char *)(p+0x24),4,(int)(&v4));
            v5=d5;v5.x=x;v5.y=y;COMM_BTL_DEMO_MAIN_StartEffect((char *)(p+0x24),5,(int)(&v5));
        }
        (((struct Obj01295 *)p)->f49D0)++;break;
    }
    return 0;
}
