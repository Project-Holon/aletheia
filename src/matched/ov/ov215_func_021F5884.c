/*
 * function: EGG_DEMO_MAIN_Update
 * address: 0x021F5884
 * packet: pkt_ov215_021F5884
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   PROCSYS_Main 0x02031330 arm
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   EGG_DEMO_MAIN_StartActorAnims 0x021F5E68 thumb ov215
 *   EGG_DEMO_MAIN_IsBgmFadeOut 0x021F5F74 thumb ov215
 *   EGG_DEMO_MAIN_AreActorAnimsDone 0x021F5E90 thumb ov215
 *   EGG_DEMO_MAIN_PlayBgm 0x021F5F84 thumb ov215
 *   EGG_DEMO_MAIN_IsBgmPlaying 0x021F5FA0 thumb ov215
 *   EGG_DEMO_MAIN_LoadBgm1 0x021F5FB0 thumb ov215
 *   EGG_DEMO_MAIN_IsBgm1Loaded 0x021F5FCC thumb ov215
 *   EGG_DEMO_VIEW_SetActive 0x021F6A3C thumb ov215
 *   EGG_DEMO_VIEW_GetActive 0x021F6A44 thumb ov215
 *   EGG_DEMO_MAIN_PushBgm 0x021F5FDC thumb ov215
 *   GAME_DATA_GetMyPlayerWork 0x020127A4 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   GAME_DATA_GetPlayerZoneId 0x02012AC8 thumb
 *   ZONEDATA_GetPlaceNameId 0x02013E4C thumb
 *   POKE_TOOL_HatchEgg 0x02017B24 thumb
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   ZUKAN_SAVE_RegisterSeen 0x0200CFA0 thumb
 *   ZUKAN_SAVE_RegisterCaught 0x0200CDE0 thumb
 *   EGG_DEMO_VIEW_SetSpecies 0x021F6A48 thumb ov215
 *   EGG_DEMO_VIEW_IsFadeDone 0x021F6A84 thumb ov215
 *   EGG_DEMO_VIEW_ResetAnimState 0x021F6A98 thumb ov215
 *   EGG_DEMO_VIEW_IsFinished 0x021F6AA4 thumb ov215
 *   EGG_DEMO_MENU_Draw 0x021F6164 thumb ov215
 *   EGG_DEMO_MAIN_LoadBgm2 0x021F6000 thumb ov215
 *   EGG_DEMO_MENU_SetText 0x021F6194 thumb ov215
 *   EGG_DEMO_MENU_WaitText 0x021F6228 thumb ov215
 *   EGG_DEMO_MAIN_IsBgm2Loading 0x021F601C thumb ov215
 *   EGG_DEMO_MENU_CreateDialog 0x021F62FC thumb ov215
 *   EGG_DEMO_MENU_GetDialogResult 0x021F6324 thumb ov215
 *   EGG_DEMO_MAIN_StopBgm 0x021F602C thumb ov215
 *   UI_SetInputMode 0x020355D8 arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   MISC_GetBlock 0x0200C0F0 thumb
 *   EGG_DEMO_MAIN_DeleteResources 0x021F5CFC thumb ov215
 *   NAMEIN_SETUP_CreateMonArgs 0x0216C028 thumb ov010
 *   PROCSYS_Push 0x02031348 arm
 *   gNameInProcData 0x021F5580 data ov194 a4
 *   abs_id_C2 0xC2 data
 *   NAMEIN_SETUP_IsCanceled 0x0216C0E4 thumb ov010
 *   STRBUF_Create 0x020457B0 arm
 *   NAMEIN_SETUP_CopyName 0x0216C0D4 thumb ov010
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   GAME_DATA_GetTrainerRecord 0x02012F2C thumb
 *   func_02008DF0 0x02008DF0 thumb
 *   NAMEIN_SETUP_FreeArgs 0x0216C0C0 thumb ov010
 *   EGG_DEMO_MAIN_IsBgmStopped 0x021F603C thumb ov215
 *   EGG_DEMO_MENU_FadeInBgm 0x021F604C thumb ov215
 *   EGG_DEMO_MAIN_UpdateBgm 0x021F5ECC thumb ov215
 *   EGG_DEMO_MENU_Main 0x021F6158 thumb ov215
 *   EGG_DEMO_MENU_ProcessDialog 0x021F62CC thumb ov215
 *   EGG_DEMO_VIEW_Update 0x021F67E0 thumb ov215
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   EGG_DEMO_GRAPHIC_Draw 0x021F64D0 thumb ov215
 *   EGG_DEMO_GRAPHIC_Draw3d 0x021F64E4 thumb ov215
 *   EGG_DEMO_VIEW_Draw 0x021F6A24 thumb ov215
 *   EGG_DEMO_GRAPHIC_DrawEnd 0x021F64F0 thumb ov215
 * prototypes: owning ARM9 units and ov215 sources; live r3 from C028 is
 * forwarded by 31348 into the four-argument 314F4 body.
 * lever: pooled overlay ID abs_id_C2 and branch-local else return preserve
 * case15 tail layout; direct 194 and early return produced DIFF97/896.
 * data: overlay ID 194 supplied to 31348 identifies ov194's process table
 * at 021F5580; own ov194 listing has three callback words there.
 */
#include "../include/Obj00186.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S021F5E68; struct SaveBlock; struct Rec44; struct Blk37; struct Big;
struct U16Vec; struct Sub02008C20Obj; struct PrintSys;
extern u32 KEY_GetTrg(void),PROCSYS_Main(void *);
extern void FADE_Start(u32,int,int,int);
extern int FADE_IsActive(void);
extern void EGG_DEMO_MAIN_StartActorAnims(int,struct S021F5E68 *);
extern int EGG_DEMO_MAIN_IsBgmFadeOut(void *,char *),EGG_DEMO_MAIN_AreActorAnimsDone(int,struct S021F5E68 *);
extern void EGG_DEMO_MAIN_PlayBgm(void *,char *),EGG_DEMO_MAIN_LoadBgm1(void *,char *);
extern int EGG_DEMO_MAIN_IsBgmPlaying(void *,char *),EGG_DEMO_MAIN_IsBgm1Loaded(void *,char *);
extern void EGG_DEMO_VIEW_SetActive(char *); extern int EGG_DEMO_VIEW_GetActive(char *);
extern void EGG_DEMO_MAIN_PushBgm(void *a0, void *a1);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *);
extern u8 *GAME_DATA_GetMyStatus(void *);
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *);
extern u32 ZONEDATA_GetPlaceNameId(u32);
extern void POKE_TOOL_HatchEgg(void *,u32,u32,u32);
extern void *ZUKAN_SAVE_GetFromGameData(void *);
extern void ZUKAN_SAVE_RegisterSeen(struct Blk37 *,void *),ZUKAN_SAVE_RegisterCaught(struct Blk37 *,void *);
extern void EGG_DEMO_VIEW_SetSpecies(char *p, int a);
extern int EGG_DEMO_VIEW_IsFadeDone(char *),EGG_DEMO_VIEW_IsFinished(char *);
extern void EGG_DEMO_VIEW_ResetAnimState(char *),EGG_DEMO_MENU_Draw(void *,char *),EGG_DEMO_MAIN_LoadBgm2(void *,char *);
extern void EGG_DEMO_MENU_SetText(char *,char *,u32);
extern int EGG_DEMO_MENU_WaitText(void *,char *),EGG_DEMO_MAIN_IsBgm2Loading(void *,char *),EGG_DEMO_MENU_CreateDialog(int,char *),EGG_DEMO_MENU_GetDialogResult(int,char *);
extern void EGG_DEMO_MAIN_StopBgm(void *,char *),UI_SetInputMode(u8);
extern void *GAME_DATA_GetSaveControl(struct Big *),*MISC_GetBlock(void *);
extern void EGG_DEMO_MAIN_DeleteResources(u32,char *);
extern int *NAMEIN_SETUP_CreateMonArgs(u16,int,int,int,int);
extern void PROCSYS_Push(void *,u32,u32,u32);
extern char gNameInProcData,abs_id_C2;
extern int NAMEIN_SETUP_IsCanceled(int *);
extern struct U16Vec *STRBUF_Create(u32,u32);
extern void NAMEIN_SETUP_CopyName(int *,int),POKE_TOOL_SetPartyValue(void *,u32,u32),STRBUF_Delete(struct U16Vec *);
extern void *GAME_DATA_GetTrainerRecord(int *);
extern u32 func_02008DF0(struct Sub02008C20Obj *,int);
extern int NAMEIN_SETUP_FreeArgs(int a0);
extern int EGG_DEMO_MAIN_IsBgmStopped(void *,char *);
extern void EGG_DEMO_MENU_FadeInBgm(u32 *,u32 *),EGG_DEMO_MAIN_UpdateBgm(u8 *,u8 *),EGG_DEMO_MENU_Main(void *,char *),EGG_DEMO_MENU_ProcessDialog(void *,char *);
extern void EGG_DEMO_VIEW_Update(char *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *);
extern void EGG_DEMO_GRAPHIC_Draw(char *),EGG_DEMO_GRAPHIC_Draw3d(char *),EGG_DEMO_VIEW_Draw(char *),EGG_DEMO_GRAPHIC_DrawEnd(char *);
int EGG_DEMO_MAIN_Update(u32 unused0,u32 unused1,u32 *a,u32 *p)
{
    u32 active;
    struct Rec44 *save;
    u8 *trainer;
    struct Blk37 *dex;
    void *block;
    int *child;
    struct U16Vec *vec;
    KEY_GetTrg();
    active=PROCSYS_Main((void *)p[34]);
    if(active==1)return 0;
    switch(p[4]) {
    case 0:
        if(((struct Obj00186 *)p)->f14==0){p[4]=1;FADE_Start(3,16,0,-16);}
        else (((struct Obj00186 *)p)->f14)--;
        break;
    case 1:if(!FADE_IsActive()){p[4]=2;EGG_DEMO_MAIN_StartActorAnims((int)a,(struct S021F5E68 *)p);}break;
    case 2:if(!EGG_DEMO_MAIN_IsBgmFadeOut(a,(char *)p)&&EGG_DEMO_MAIN_AreActorAnimsDone((int)a,(struct S021F5E68 *)p)){p[4]=3;EGG_DEMO_MAIN_PlayBgm(a,(char *)p);}break;
    case 3:if(!EGG_DEMO_MAIN_IsBgmPlaying(a,(char *)p)){p[4]=4;EGG_DEMO_MAIN_LoadBgm1(a,(char *)p);}break;
    case 4:if(EGG_DEMO_MAIN_IsBgm1Loaded(a,(char *)p)){p[4]=5;EGG_DEMO_VIEW_SetActive((char *)p[32]);}break;
    case 5:if(EGG_DEMO_VIEW_GetActive((char *)p[32])){p[4]=6;EGG_DEMO_MAIN_PushBgm(a,p);}break;
    case 6:
        p[4]=7;
        save=GAME_DATA_GetMyPlayerWork((struct SaveBlock *)a[0]);trainer=GAME_DATA_GetMyStatus((void *)a[0]);
        POKE_TOOL_HatchEgg((void *)a[1],(u32)trainer,ZONEDATA_GetPlaceNameId(GAME_DATA_GetPlayerZoneId(save)),((struct Obj00186 *)p)->f0);
        dex=ZUKAN_SAVE_GetFromGameData((void *)a[0]);ZUKAN_SAVE_RegisterSeen(dex,(void *)a[1]);ZUKAN_SAVE_RegisterCaught(dex,(void *)a[1]);
        EGG_DEMO_VIEW_SetSpecies((char *)p[32],(int)((void *)a[1]));break;
    case 7:if(EGG_DEMO_VIEW_IsFadeDone((char *)p[32])){p[4]=8;EGG_DEMO_VIEW_ResetAnimState((char *)p[32]);}break;
    case 8:if(EGG_DEMO_VIEW_IsFinished((char *)p[32])){p[4]=9;EGG_DEMO_MENU_Draw(a,(char *)p);EGG_DEMO_MAIN_LoadBgm2(a,(char *)p);}break;
    case 9:p[27]=1;p[4]=10;break;
    case 10:EGG_DEMO_MENU_SetText((char *)a,(char *)p,1);p[4]=11;break;
    case 11:if(EGG_DEMO_MENU_WaitText(a,(char *)p)&&!EGG_DEMO_MAIN_IsBgm2Loading(a,(char *)p)){p[4]=12;EGG_DEMO_MENU_SetText((char *)a,(char *)p,2);}break;
    case 12:if(EGG_DEMO_MENU_WaitText(a,(char *)p)){p[4]=13;EGG_DEMO_MENU_CreateDialog((int)a,(char *)p);}break;
    case 13:
        active=EGG_DEMO_MENU_GetDialogResult((int)a,(char *)p);
        if(active==0){p[4]=18;FADE_Start(3,0,16,2);EGG_DEMO_MAIN_StopBgm(a,(char *)p);UI_SetInputMode(0);}
        else if(active==1){p[4]=14;FADE_Start(3,0,16,0);UI_SetInputMode(0);}break;
    case 14:
        if(!FADE_IsActive()){
            block=MISC_GetBlock(GAME_DATA_GetSaveControl((struct Big *)a[0]));
            EGG_DEMO_MAIN_DeleteResources((u32)a,(char *)p);p[4]=15;
            child=NAMEIN_SETUP_CreateMonArgs(((struct Obj00186 *)p)->f0,(int)a[1],10,0,(int)block);p[33]=(u32)child;
            PROCSYS_Push((void *)p[34],(u32)&abs_id_C2,(u32)&gNameInProcData,(u32)child);
        }break;
    case 15:
        if(active!=1){
        if(!NAMEIN_SETUP_IsCanceled((int *)p[33])){
            vec=STRBUF_Create(32,((struct Obj00186 *)p)->f0);NAMEIN_SETUP_CopyName((int *)p[33],(int)vec);
            POKE_TOOL_SetPartyValue((void *)a[1],115,(u32)vec);STRBUF_Delete(vec);
            func_02008DF0(GAME_DATA_GetTrainerRecord((int *)a[0]),30);
        }
        NAMEIN_SETUP_FreeArgs((int)((int *)p[33]));p[4]=16;EGG_DEMO_MAIN_StopBgm(a,(char *)p);
        }else{return 0;}break;
    case 16:if(!EGG_DEMO_MAIN_IsBgmStopped(a,(char *)p)){p[4]=17;EGG_DEMO_MENU_FadeInBgm(a,p);return 1;}break;
    case 17:break;
    case 18:if(!EGG_DEMO_MAIN_IsBgmStopped(a,(char *)p)){p[4]=19;EGG_DEMO_MENU_FadeInBgm(a,p);}break;
    case 19:if(!FADE_IsActive()){p[4]=20;return 1;}break;
    }
    EGG_DEMO_MAIN_UpdateBgm((u8 *)a,(u8 *)p);
    if(p[4]!=15&&p[4]!=16&&p[4]!=17&&p[4]!=20){
        EGG_DEMO_MENU_Main(a,(char *)p);EGG_DEMO_MENU_ProcessDialog(a,(char *)p);EGG_DEMO_VIEW_Update((char *)p[32]);
        PRINTSYS_QUE_Main((struct PrintSys *)p[3]);EGG_DEMO_GRAPHIC_Draw((char *)p[1]);EGG_DEMO_GRAPHIC_Draw3d((char *)p[1]);
        EGG_DEMO_VIEW_Draw((char *)p[32]);EGG_DEMO_GRAPHIC_DrawEnd((char *)p[1]);
    }
    return 0;
}
