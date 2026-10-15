/*
 * function: COMM_BTL_DEMO_MAIN_UpdateEnd
 * address: 0x021B9D80
 * packet: pkt_ov213_021B9D80
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UI_SCENE_GetPhaseFrame 0x021B61FC thumb ov067
 *   UI_SCENE_AdvancePhaseFrame 0x021B6200 thumb ov067
 *   COMM_BTL_DEMO_MAIN_UpdateRows 0x021BA444 thumb ov213
 *   COMM_BTL_DEMO_MAIN_UpdateBattleActors 0x021BA650 thumb ov213
 *   COMM_BTL_DEMO_MAIN_LoadObject 0x021BA95C thumb ov213
 *   COMM_BTL_DEMO_MAIN_ShowBattleActor 0x021BA68C thumb ov213
 *   COMM_BTL_DEMO_MAIN_UpdateObjectAnime 0x021BA9D0 thumb ov213
 *   FADE_Start 0x0204E720 arm
 */
#include "../include/Obj14693.h"
extern unsigned UI_SCENE_GetPhaseFrame(const unsigned char *p);
extern int COMM_BTL_DEMO_MAIN_UpdateObjectAnime(unsigned char *p);
extern void UI_SCENE_AdvancePhaseFrame(unsigned char *p);
extern void COMM_BTL_DEMO_MAIN_UpdateRows(void *);
extern void COMM_BTL_DEMO_MAIN_UpdateBattleActors(char *p);
extern void COMM_BTL_DEMO_MAIN_LoadObject(unsigned char *p, int index);
extern void COMM_BTL_DEMO_MAIN_ShowBattleActor(char *p, unsigned i, int kind);
extern void FADE_Start(unsigned,int,int,int);
int COMM_BTL_DEMO_MAIN_UpdateEnd(void *state,char *p)
{
    int stage;
    stage=UI_SCENE_GetPhaseFrame(state);
    COMM_BTL_DEMO_MAIN_UpdateRows(p);COMM_BTL_DEMO_MAIN_UpdateBattleActors(p+0x498C);
    switch(stage) {
    case 0:
        COMM_BTL_DEMO_MAIN_LoadObject((unsigned char *)(p+0x24),5);((struct Obj14693 *)p)->f49D0=0;UI_SCENE_AdvancePhaseFrame(state);break;
    case 1:
        if((((struct Obj14693 *)p)->f49D0)++==30) COMM_BTL_DEMO_MAIN_ShowBattleActor(p+0x498C,2,2);
        if(COMM_BTL_DEMO_MAIN_UpdateObjectAnime((unsigned char *)(p+0x24))==0) {FADE_Start(3,0,16,-3);return 1;}
        break;
    case 2:break;
    }
    return 0;
}
