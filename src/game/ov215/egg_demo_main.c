/*
 * file:     egg_demo_main.c
 * unit:     yes
 * function: EGG_DEMO_MAIN_Create, EGG_DEMO_MAIN_Delete, EGG_DEMO_MAIN_Update, EGG_DEMO_MAIN_OnVBlank, EGG_DEMO_MAIN_Init, EGG_DEMO_MAIN_DeleteResources, EGG_DEMO_MAIN_LoadGraphics, EGG_DEMO_MAIN_Noop, EGG_DEMO_MAIN_InitActors, EGG_DEMO_MAIN_DeleteActors, EGG_DEMO_MAIN_StartActorAnims, EGG_DEMO_MAIN_AreActorAnimsDone, EGG_DEMO_MAIN_StartFadeOutBgm, EGG_DEMO_MAIN_NoopB, EGG_DEMO_MAIN_UpdateBgm, EGG_DEMO_MAIN_IsBgmFadeOut, EGG_DEMO_MAIN_PlayBgm, EGG_DEMO_MAIN_IsBgmPlaying, EGG_DEMO_MAIN_LoadBgm1, EGG_DEMO_MAIN_IsBgm1Loaded, EGG_DEMO_MAIN_PushBgm, EGG_DEMO_MAIN_PopBgm, EGG_DEMO_MAIN_LoadBgm2, EGG_DEMO_MAIN_IsBgm2Loading, EGG_DEMO_MAIN_StopBgm, EGG_DEMO_MAIN_IsBgmStopped
 * address:  0x021F57E0
 * region:   ov215
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   FADE_Start 0x0204E720 arm
 *   PROCSYS_Create 0x02031324 arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   PROCSYS_Delete 0x0203133C arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   KEY_GetTrg 0x020362DC arm
 *   PROCSYS_Main 0x02031330 arm
 *   FADE_IsActive 0x0204E804 arm
 *   EGG_DEMO_VIEW_SetActive 0x021F6A3C thumb ov215
 *   EGG_DEMO_VIEW_GetActive 0x021F6A44 thumb ov215
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
 *   EGG_DEMO_MENU_SetText 0x021F6194 thumb ov215
 *   EGG_DEMO_MENU_WaitText 0x021F6228 thumb ov215
 *   EGG_DEMO_MENU_CreateDialog 0x021F62FC thumb ov215
 *   EGG_DEMO_MENU_GetDialogResult 0x021F6324 thumb ov215
 *   UI_SetInputMode 0x020355D8 arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   MISC_GetBlock 0x0200C0F0 thumb
 *   NAMEIN_SETUP_CreateMonArgs 0x0216C028 thumb ov010
 *   PROCSYS_Push 0x02031348 arm
 *   gNameInProcData 0x021F5580 data ov194 a4
 *   NAMEIN_SETUP_IsCanceled 0x0216C0E4 thumb ov010
 *   STRBUF_Create 0x020457B0 arm
 *   NAMEIN_SETUP_CopyName 0x0216C0D4 thumb ov010
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   GAME_DATA_GetTrainerRecord 0x02012F2C thumb
 *   RECORD_AddOne 0x02008DF0 thumb
 *   NAMEIN_SETUP_FreeArgs 0x0216C0C0 thumb ov010
 *   EGG_DEMO_MENU_FadeInBgm 0x021F604C thumb ov215
 *   EGG_DEMO_MENU_Main 0x021F6158 thumb ov215
 *   EGG_DEMO_MENU_ProcessDialog 0x021F62CC thumb ov215
 *   EGG_DEMO_VIEW_Update 0x021F67E0 thumb ov215
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   EGG_DEMO_GRAPHIC_Draw 0x021F64D0 thumb ov215
 *   EGG_DEMO_GRAPHIC_Draw3d 0x021F64E4 thumb ov215
 *   EGG_DEMO_VIEW_Draw 0x021F6A24 thumb ov215
 *   EGG_DEMO_GRAPHIC_DrawEnd 0x021F64F0 thumb ov215
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   EGG_DEMO_GRAPHIC_Create 0x021F63CC thumb ov215
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   EGG_DEMO_MENU_Create 0x021F6060 thumb ov215
 *   EGG_DEMO_MENU_InitDialog 0x021F6280 thumb ov215
 *   BG_SYS_SetPriority 0x0204047C arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   BG_SYS_LoadPlttEntry 0x02040EBC arm
 *   EGG_DEMO_VIEW_Create 0x021F6720 thumb ov215
 *   EGG_DEMO_VIEW_Delete 0x021F67B0 thumb ov215
 *   EGG_DEMO_MENU_Noop 0x021F62C8 thumb ov215
 *   EGG_DEMO_MENU_Delete 0x021F6114 thumb ov215
 *   TCB_DeleteTask 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   EGG_DEMO_GRAPHIC_Delete 0x021F6474 thumb ov215
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   EGG_DEMO_GRAPHIC_GetClactBank2 0x021F64FC thumb ov215
 *   sEggDemoMainTable 0x021F7124 data ov215
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_SetActorAnimIndex 0x0204B908 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb
 *   GFL_USE_SetBgmPaused  0x02005DE4  thumb
 *   GFL_USE_IsBgmFading  0x02005E50  thumb
 *   GFL_USE_PushBgm  0x02005E64  thumb
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb
 *   GFL_USE_StepBgmLoad  0x020063B4  thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   abs_id_C2 0xC2 data
 */

#include "egg_demo_types.h"
#include "../sdk_ioreg.h"
#include "egg_demo_view.h"
#include "egg_demo_menu.h"

struct Proc;
struct ProcSys;
struct Proc;
struct SaveBlock;
struct Rec44;
struct Blk37;
struct Big;
struct U16Vec;
struct Sub02008C20Obj;
struct PrintSys;
struct GfFont;
struct Node;
struct Obj;
struct Actor;
#include "../types.h"

#include "../arm9/gfl_use.h"
#include "../arm9/clact.h"
#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
#include "../arm9/fade.h"
#include "../arm9/net.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/procsys.h"
#include "../arm9/key.h"
struct GameData;
struct PlayerWork;
extern struct PlayerWork *GAME_DATA_GetMyPlayerWork(struct GameData *gameData);
struct MyStatus;
extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gd);
extern u16 GAME_DATA_GetPlayerZoneId(struct PlayerWork *player);
#include "../arm9/zonedata.h"
struct PokemonParam;
#include "../arm9/poke_tool.h"
extern void *ZUKAN_SAVE_GetFromGameData(void *);
extern void ZUKAN_SAVE_RegisterSeen(struct Blk37 *,void *),ZUKAN_SAVE_RegisterCaught(struct Blk37 *,void *);
#include "../arm9/ui.h"
extern void *GAME_DATA_GetSaveControl(struct Big *),*MISC_GetBlock(void *);
struct Strbuf;
struct NameInArgs;
extern struct NameInArgs *NAMEIN_SETUP_CreateMonArgs(unsigned short heapId, void *mon, int maxLen, struct Strbuf *initialName, void *pokedex);
extern int NAMEIN_SETUP_IsCanceled(struct NameInArgs *args);
extern struct Strbuf *STRBUF_Create(u32,u32);
extern void NAMEIN_SETUP_CopyName(int *,int),STRBUF_Delete(struct U16Vec *);
extern void *GAME_DATA_GetTrainerRecord(struct GameData *gd);
#include "../arm9/record.h"
extern void NAMEIN_SETUP_FreeArgs(struct NameInArgs *args);
struct PrintQueue;
#include "../arm9/printsys.h"
#include "../arm9/bg_sys.h"
#include "egg_demo_graphic.h"
#include "../arm9/gf_font.h"
#include "../arm9/g2.h"
struct TcbTask;
#include "../arm9/tcb_list.h"
#include "../arm9/arc_tool.h"
#include "../arm9/arc_util.h"
int EGG_DEMO_MAIN_Create(void *owner,int unused,struct EggDemoArgs *args);
int EGG_DEMO_MAIN_Delete(struct Proc *task,int unused,struct EggDemoArgs *args,char *work);
int EGG_DEMO_MAIN_Update(u32 unused0,u32 unused1,struct EggDemoArgs *args,u32 *work);
void EGG_DEMO_MAIN_OnVBlank(struct TcbTask *unused, void *p);
void EGG_DEMO_MAIN_Init(struct EggDemoArgs *args,char *work);
void EGG_DEMO_MAIN_DeleteResources(struct EggDemoArgs *args,char *work);
void EGG_DEMO_MAIN_LoadGraphics(void *unused, char *p);
void EGG_DEMO_MAIN_Noop(struct EggDemoArgs *args, char *work);
void EGG_DEMO_MAIN_InitActors(void *unused, struct EggDemoWork *p);
void EGG_DEMO_MAIN_DeleteActors(void *unused, char *p);
void EGG_DEMO_MAIN_StartActorAnims(void *unused, struct EggDemoWork *p);
int EGG_DEMO_MAIN_AreActorAnimsDone(void *unused, struct EggDemoWork *p);
int EGG_DEMO_MAIN_StartFadeOutBgm(struct EggDemoArgs *a, char *b);
void EGG_DEMO_MAIN_NoopB(struct EggDemoArgs *a, char *p);
void EGG_DEMO_MAIN_UpdateBgm(u8 *p, u8 *q);
int EGG_DEMO_MAIN_IsBgmFadeOut(void *unused,char *p);
void EGG_DEMO_MAIN_PlayBgm(void *unused, char *p);
int EGG_DEMO_MAIN_IsBgmPlaying(void *unused, char *p);
void EGG_DEMO_MAIN_LoadBgm1(void *unused, char *p);
int EGG_DEMO_MAIN_IsBgm1Loaded(void *unused, char *p);
void EGG_DEMO_MAIN_PushBgm(void *args, void *work);
void EGG_DEMO_MAIN_PopBgm(void *args, void *work);
void EGG_DEMO_MAIN_LoadBgm2(void *unused, char *p);
int EGG_DEMO_MAIN_IsBgm2Loading(void *unused, char *p);
void EGG_DEMO_MAIN_StopBgm(void *unused, char *p);
int EGG_DEMO_MAIN_IsBgmStopped(void *unused, char *p);
extern char gNameInProcData,abs_id_C2;
extern const unsigned int sEggDemoMainTable[][2];

/*
 * Legacy void allocator/31324 returns consumed; preserve visible heap input.
 */
int EGG_DEMO_MAIN_Create(void *owner,int unused,struct EggDemoArgs *args)
{
    char *work;
    GFL_HEAP_CreateChildHeap(1,143,5<<16);
    work=PROCSYS_AllocProcWork(owner,sizeof(struct EggDemoWork),143);
    MI_CpuFill8(work,0,sizeof(struct EggDemoWork));
    ((struct EggDemoWork *)work)->heapId=143;
    ((struct EggDemoWork *)work)->state=0;
    ((struct EggDemoWork *)work)->fadeDelay=5;
    ((struct EggDemoWork *)work)->bgmState=0;
    ((struct EggDemoWork *)work)->bgmTimer=0;
    ((struct EggDemoWork *)work)->dialogState=0;
    EGG_DEMO_MAIN_Init(args,work);
    EGG_DEMO_MAIN_StartFadeOutBgm(args,work);
    FADE_Start(3,16,16,0);
    ((struct EggDemoWork *)work)->proc=PROCSYS_Create(((struct EggDemoWork *)work)->heapId);
    GFL_NET_RefreshWmIconAtTopRight(0,((struct EggDemoWork *)work)->heapId);
    return 1;
}

int EGG_DEMO_MAIN_Delete(struct Proc *task,int unused,struct EggDemoArgs *args,char *work) { PROCSYS_Delete(*(struct ProcSys * *)&((struct EggDemoWork *)work)->proc);EGG_DEMO_MAIN_NoopB(args,work);if(((struct EggDemoWork *)work)->state!=17)EGG_DEMO_MAIN_DeleteResources(args,work);PROCSYS_FreeProcWork(task);GFL_HEAP_DeleteChecked(143);return 1; }

/*
 * prototypes: owning ARM9 units and ov215 sources; live r3 from C028 is
 * forwarded by 31348 into the four-argument 314F4 body.
 * lever: pooled overlay ID abs_id_C2 and branch-local else return preserve
 * case15 tail layout; direct 194 and early return produced DIFF97/896.
 * data: overlay ID 194 supplied to 31348 identifies ov194's process table
 * at 021F5580; own ov194 listing has three callback words there.
 */
int EGG_DEMO_MAIN_Update(u32 unused0,u32 unused1,struct EggDemoArgs *args,u32 *work)
{
    u32 active;
    struct Rec44 *save;
    u8 *trainer;
    struct Blk37 *dex;
    void *block;
    int *child;
    struct U16Vec *vec;
    KEY_GetTrg();
    active=PROCSYS_Main((void *)((struct EggDemoWork *)work)->proc);
    if(active==1)return 0;
    switch(((struct EggDemoWork *)work)->state) {
    case 0:
        if(((struct EggDemoWork *)work)->fadeDelay==0){((struct EggDemoWork *)work)->state=1;FADE_Start(3,16,0,-16);}
        else (((struct EggDemoWork *)work)->fadeDelay)--;
        break;
    case 1:if(!FADE_IsActive()){((struct EggDemoWork *)work)->state=2;EGG_DEMO_MAIN_StartActorAnims(args,(struct EggDemoWork *)work);}break;
    case 2:if(!EGG_DEMO_MAIN_IsBgmFadeOut(args,(char *)work)&&EGG_DEMO_MAIN_AreActorAnimsDone(args,(struct EggDemoWork *)work)){((struct EggDemoWork *)work)->state=3;EGG_DEMO_MAIN_PlayBgm(args,(char *)work);}break;
    case 3:if(!EGG_DEMO_MAIN_IsBgmPlaying(args,(char *)work)){((struct EggDemoWork *)work)->state=4;EGG_DEMO_MAIN_LoadBgm1(args,(char *)work);}break;
    case 4:if(EGG_DEMO_MAIN_IsBgm1Loaded(args,(char *)work)){((struct EggDemoWork *)work)->state=5;EGG_DEMO_VIEW_SetActive((char *)((struct EggDemoWork *)work)->view);}break;
    case 5:if(EGG_DEMO_VIEW_GetActive((char *)((struct EggDemoWork *)work)->view)){((struct EggDemoWork *)work)->state=6;EGG_DEMO_MAIN_PushBgm(args,work);}break;
    case 6:
        ((struct EggDemoWork *)work)->state=7;
        save=(struct Rec44 *)GAME_DATA_GetMyPlayerWork((struct GameData *)((struct EggDemoArgs *)args)->gameData);trainer=(unsigned char *)GAME_DATA_GetMyStatus(((struct EggDemoArgs *)args)->gameData);
        POKE_TOOL_HatchEgg(((struct EggDemoArgs *)args)->mon,(uptr)trainer,ZONEDATA_GetPlaceNameId(GAME_DATA_GetPlayerZoneId((struct PlayerWork *)save)),((struct EggDemoWork *)work)->heapId);
        dex=ZUKAN_SAVE_GetFromGameData(((struct EggDemoArgs *)args)->gameData);ZUKAN_SAVE_RegisterSeen(dex,((struct EggDemoArgs *)args)->mon);ZUKAN_SAVE_RegisterCaught(dex,((struct EggDemoArgs *)args)->mon);
        EGG_DEMO_VIEW_SetSpecies((char *)((struct EggDemoWork *)work)->view,(((struct EggDemoArgs *)args)->mon));break;
    case 7:if(EGG_DEMO_VIEW_IsFadeDone((char *)((struct EggDemoWork *)work)->view)){((struct EggDemoWork *)work)->state=8;EGG_DEMO_VIEW_ResetAnimState((char *)((struct EggDemoWork *)work)->view);}break;
    case 8:if(EGG_DEMO_VIEW_IsFinished((char *)((struct EggDemoWork *)work)->view)){((struct EggDemoWork *)work)->state=9;EGG_DEMO_MENU_Draw(args,(char *)work);EGG_DEMO_MAIN_LoadBgm2(args,(char *)work);}break;
    case 9:((struct EggDemoWork *)work)->vblankFlag=1;((struct EggDemoWork *)work)->state=10;break;
    case 10:EGG_DEMO_MENU_SetText(args,(char *)work,1);((struct EggDemoWork *)work)->state=11;break;
    case 11:if(EGG_DEMO_MENU_WaitText(args,(char *)work)&&!EGG_DEMO_MAIN_IsBgm2Loading(args,(char *)work)){((struct EggDemoWork *)work)->state=12;EGG_DEMO_MENU_SetText(args,(char *)work,2);}break;
    case 12:if(EGG_DEMO_MENU_WaitText(args,(char *)work)){((struct EggDemoWork *)work)->state=13;EGG_DEMO_MENU_CreateDialog(args,(char *)work);}break;
    case 13:
        active=EGG_DEMO_MENU_GetDialogResult(args,(char *)work);
        if(active==0){((struct EggDemoWork *)work)->state=18;FADE_Start(3,0,16,2);EGG_DEMO_MAIN_StopBgm(args,(char *)work);UI_SetInputMode(0);}
        else if(active==1){((struct EggDemoWork *)work)->state=14;FADE_Start(3,0,16,0);UI_SetInputMode(0);}break;
    case 14:
        if(!FADE_IsActive()){
            block=MISC_GetBlock(GAME_DATA_GetSaveControl((struct Big *)((struct EggDemoArgs *)args)->gameData));
            EGG_DEMO_MAIN_DeleteResources(args,(char *)work);((struct EggDemoWork *)work)->state=15;
            child=(int *)NAMEIN_SETUP_CreateMonArgs(((struct EggDemoWork *)work)->heapId,((struct EggDemoArgs *)args)->mon,10,0,block);((struct EggDemoWork *)work)->nameChild=child;
            PROCSYS_Push(((struct EggDemoWork *)work)->proc,(uptr)&abs_id_C2,(const struct ProcData *)&gNameInProcData,(void *)child);
        }break;
    case 15:
        if(active!=1){
        if(!NAMEIN_SETUP_IsCanceled((struct NameInArgs *)(((struct EggDemoWork *)work)->nameChild))){
            vec=(struct U16Vec *)STRBUF_Create(32,((struct EggDemoWork *)work)->heapId);NAMEIN_SETUP_CopyName(((struct EggDemoWork *)work)->nameChild,(sptr)vec);
            POKE_TOOL_SetPartyValue(((struct EggDemoArgs *)args)->mon,115,(uptr)vec);STRBUF_Delete(vec);
            RECORD_AddOne(GAME_DATA_GetTrainerRecord((struct GameData *)((struct EggDemoArgs *)args)->gameData),30);
        }
        NAMEIN_SETUP_FreeArgs((struct NameInArgs *)((((struct EggDemoWork *)work)->nameChild)));((struct EggDemoWork *)work)->state=16;EGG_DEMO_MAIN_StopBgm(args,(char *)work);
        }else{return 0;}break;
    case 16:if(!EGG_DEMO_MAIN_IsBgmStopped(args,(char *)work)){((struct EggDemoWork *)work)->state=17;EGG_DEMO_MENU_FadeInBgm(args,work);return 1;}break;
    case 17:break;
    case 18:if(!EGG_DEMO_MAIN_IsBgmStopped(args,(char *)work)){((struct EggDemoWork *)work)->state=19;EGG_DEMO_MENU_FadeInBgm(args,work);}break;
    case 19:if(!FADE_IsActive()){((struct EggDemoWork *)work)->state=20;return 1;}break;
    }
    EGG_DEMO_MAIN_UpdateBgm((u8 *)args,(u8 *)work);
    if(((struct EggDemoWork *)work)->state!=15&&((struct EggDemoWork *)work)->state!=16&&((struct EggDemoWork *)work)->state!=17&&((struct EggDemoWork *)work)->state!=20){
        EGG_DEMO_MENU_Main(args,(char *)work);EGG_DEMO_MENU_ProcessDialog(args,(char *)work);EGG_DEMO_VIEW_Update((char *)((struct EggDemoWork *)work)->view);
        PRINTSYS_QUE_Main(((struct EggDemoWork *)work)->printQue);EGG_DEMO_GRAPHIC_Draw((char *)((struct EggDemoWork *)work)->graphic);EGG_DEMO_GRAPHIC_Draw3d((char *)((struct EggDemoWork *)work)->graphic);
        EGG_DEMO_VIEW_Draw((char *)((struct EggDemoWork *)work)->view);EGG_DEMO_GRAPHIC_DrawEnd((char *)((struct EggDemoWork *)work)->graphic);
    }
    return 0;
}

void EGG_DEMO_MAIN_OnVBlank(struct TcbTask *unused, void *work)
{
    if (((struct EggDemoWork *)work)->vblankFlag) {
        BG_SYS_SetPlaneVisible(1, 1);
        ((struct EggDemoWork *)work)->vblankFlag = 0;
    }
}

void EGG_DEMO_MAIN_Init(struct EggDemoArgs *args,char *work)
{
    u8 i;
    for (i=0;i<=7;i++) BG_SYS_SetPlaneVisible(i,0);
    ((struct EggDemoWork *)work)->graphic=EGG_DEMO_GRAPHIC_Create(1,((struct EggDemoWork *)work)->heapId);
    ((struct EggDemoWork *)work)->font=GF_FONT_Create(23,0,0,0,((struct EggDemoWork *)work)->heapId);
    ((struct EggDemoWork *)work)->printQue=PRINTSYS_QUE_Create((unsigned int)(u32)((struct EggDemoWork *)work)->heapId);
    ((struct EggDemoWork *)work)->vblankTask=GFL_USE_AddMainTask(EGG_DEMO_MAIN_OnVBlank, work,1);
    EGG_DEMO_MAIN_LoadGraphics(args,work);
    EGG_DEMO_MAIN_InitActors(args,(struct EggDemoWork *)work);
    EGG_DEMO_MENU_Create(args,work);
    EGG_DEMO_MENU_InitDialog(args,(u8 *)work);
    BG_SYS_SetPriority(0,2);
    BG_SYS_SetPriority(2,1);
    BG_SYS_SetPriority(1,0);
    BG_SYS_SetPriority(4,0);
    BG_SYS_SetPlaneVisible(0,1);
    BG_SYS_SetPlaneVisible(2,1);
    BG_SYS_SetPlaneVisible(4,1);
    G2x_SetBlendAlpha_((u32 *)REG_BLDCNT_ADDR,1,47,0,0);
    BG_SYS_LoadPlttEntry(0,0x4210);
    BG_SYS_LoadPlttEntry(4,0);
    *(char * *)&((struct EggDemoWork *)work)->view=EGG_DEMO_VIEW_Create(((struct EggDemoWork *)work)->heapId,args->mon);
}

void EGG_DEMO_MAIN_DeleteResources(struct EggDemoArgs *args,char *work)
{
    EGG_DEMO_VIEW_Delete((char *)(((struct EggDemoWork *)work)->view));
    EGG_DEMO_MENU_Noop(args,work);
    EGG_DEMO_MENU_Delete(args,work);
    EGG_DEMO_MAIN_DeleteActors(args,work);
    EGG_DEMO_MAIN_Noop(args,work);
    TCB_DeleteTask((struct TcbTask *)(((struct EggDemoWork *)work)->vblankTask));
    PRINTSYS_QUE_Clear((struct PrintQueue *)(((struct EggDemoWork *)work)->printQue));
    PRINTSYS_QUE_Delete((struct PrintQueue *)(((struct EggDemoWork *)work)->printQue));
    GF_FONT_Delete((void *)(((struct EggDemoWork *)work)->font));
    EGG_DEMO_GRAPHIC_Delete((char *)(((struct EggDemoWork *)work)->graphic));
}

void EGG_DEMO_MAIN_LoadGraphics(void *unused, char *work)
{
    void *h = ARC_TOOL_CreateHandle(189, ((struct EggDemoWork *)work)->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(h, 3, 0, 0, 32, ((struct EggDemoWork *)work)->heapId);
    ARC_UTIL_UploadBgCharFromHandle(h, 5, 2, 0, 0, 0, ((struct EggDemoWork *)work)->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 4, 2, 0, 0, 0, ((struct EggDemoWork *)work)->heapId);
    ARC_TOOL_DeleteHandle(h);
    BG_SYS_PushTile(2);
}

void EGG_DEMO_MAIN_Noop(struct EggDemoArgs *args, char *work)
{

}

/*
 * lever: first types search split the full-word per-element pointer assignment and named the table address and resource result; declarations ported to block tops with initializer timing preserved.
 * checks: 1 own callee bodies prove 2/7/5/4/1/1/7/2 arities and visible full-word B294 return; 2 no ov214/215/216 constructor twin, own request builder read; 3 carried const/struct compiles remain exhausted2/2; 4 enum-zero, hoisted-zero, per-element pointer and byte-colour idioms read, manual order2/2 unchanged; 5 fresh full idiom inventory and own neighbours read. First types search stopped at200 with MATCH140; clean independent one EXACT140, all9 sites resolved. No manual scheduling variant added.
 * Return ABI: B294 original0204B314 calls CFDC then0204B318/31C returns without overwriting r0; CFDC0204D040 restores full object pointer. Caller021F5E20 stores this r0 and forwards it to B92C. Own B294 void declaration is superseded here by consumed return evidence.
 * Forwarding: 64FC adds4 to r0 and tails through6504 to662C;662C is ldr r0,[r0]; bx lr. All one full-word input/output.
 */
void EGG_DEMO_MAIN_InitActors(void *unused, struct EggDemoWork *work)
{
    unsigned char i;
    void *h = ARC_TOOL_CreateHandle(189, work->heapId);
    char *slotBase;
    uptr actorTemplate;
    int tmp;
    work->paletteId = CLACT_RegisterPaletteEx(h, 3, 0, 0, 0, 1, work->heapId);
    tmp = CLACT_RegisterCharacter(h, 2, 0, 0, work->heapId);
    if (unused) {
    }
    work->charId = tmp;
    work->cellAnimId = CLACT_RegisterCellAnim(h, 1, 0, work->heapId);
    ARC_TOOL_DeleteHandle(h);
    for (i = 0; i < 6; i++) {
        struct EggDemoWork *out;
        uptr o;
        slotBase = (char *)work;
        slotBase = slotBase + (i * 4);
        out = (struct EggDemoWork *)slotBase;
        actorTemplate = (uptr)sEggDemoMainTable[i];
        o = (uptr)CLACT_CreateActor((void *)EGG_DEMO_GRAPHIC_GetClactBank2((char *)work->graphic), work->charId, work->paletteId, work->cellAnimId, (const void *)actorTemplate, 0, work->heapId);
        out->actors[0] = (void *)o;
        CLACT_SetActorAutoAnim((struct ClactActor *)o, 0);
    }
}

void EGG_DEMO_MAIN_DeleteActors(void *unused, char *work)
{
    u8 i;
    for (i = 0; i < 6; i++) CLACT_DeleteActor(((struct EggDemoWork *)work)->actors[i]);
    CLACT_ReleaseCellAnim(((struct EggDemoWork *)work)->cellAnimId);
    CLACT_ReleaseCharacter(((struct EggDemoWork *)work)->charId);
    CLACT_ReleasePalette(((struct EggDemoWork *)work)->paletteId);
}

void EGG_DEMO_MAIN_StartActorAnims(void *unused, struct EggDemoWork *work)
{
    unsigned char i;
    for (i = 0; i < 6; i++)
    {
        CLACT_SetActorAnimIndex(work->actors[i], 0);
        CLACT_SetActorAutoAnim(work->actors[i], 1);
    }
}

int EGG_DEMO_MAIN_AreActorAnimsDone(void *unused, struct EggDemoWork *work)
{
    unsigned char i;
    int r = 1;
    for (i = 0; i < 6; i++)
    {
        if (CLACT_IsActorAnimActive(work->actors[i]) != 0)
        {
            r = 0;
            break;
        }
    }
    return r;
}

int EGG_DEMO_MAIN_StartFadeOutBgm(struct EggDemoArgs *args, char *work)
{
    GFL_USE_FadeOutBgm(0x1e);
    ((struct EggDemoWork *)work)->bgmState = 1;
    return 1;
}

void EGG_DEMO_MAIN_NoopB(struct EggDemoArgs *args, char *work)
{

}

void EGG_DEMO_MAIN_UpdateBgm(u8 *args, u8 *work)
{
    switch (((struct EggDemoWork *)work)->bgmState) {
    case 0:
        break;
    case 1:
        if (GFL_USE_IsBgmFading() == 0) {
            GFL_USE_SetBgmPaused((unsigned int)1);
            GFL_USE_PushBgm();
            ((struct EggDemoWork *)work)->bgmState = 0;
        }
        break;
    case 2:
        if (GFL_USE_IsBgmPlaying() == 0)
            ((struct EggDemoWork *)work)->bgmState = 0;
        break;
    case 3:
        if (GFL_USE_StepBgmLoad((unsigned int)0x3F3, (u32 *)(&((struct EggDemoWork *)work)->bgmLoadState), 0) != 0)
            ((struct EggDemoWork *)work)->bgmState = 4;
        break;
    case 4:
        break;
    case 5:
        if (GFL_USE_StepBgmLoad((unsigned int)0x519, (u32 *)(&((struct EggDemoWork *)work)->bgmLoadState), 0) != 0)
            ((struct EggDemoWork *)work)->bgmState = 6;
        break;
    case 6:
        if (GFL_USE_IsBgmPlaying() == 0) {
            EGG_DEMO_MAIN_PopBgm(args, work);
            ((struct EggDemoWork *)work)->bgmState = 4;
        }
        break;
    case 7:
        if (GFL_USE_IsBgmFading() == 0) {
            GFL_USE_CancelChangeAndStopBgm();
            ((struct EggDemoWork *)work)->bgmState = 0;
        }
        break;
    }
}

/*
 * leaf: sole blocker set of concrete MATCH900 ov215021F5884; parent claim.
 * extent: 14-byte predicate then two zero alignment bytes at 021F5F82.
 */
int EGG_DEMO_MAIN_IsBgmFadeOut(void *unused,char *work)
{
    if(((struct EggDemoWork *)work)->bgmState==1)return 1;
    return 0;
}

void EGG_DEMO_MAIN_PlayBgm(void *unused, char *work)
{
    GFL_USE_CancelChangeAndPlayBgm(0x3f2, 0xffff);
    ((struct EggDemoWork *)work)->bgmState = 2;
}

int EGG_DEMO_MAIN_IsBgmPlaying(void *unused, char *work)
{
    if (((struct EggDemoWork *)work)->bgmState == 2) return 1;
    return 0;
}

void EGG_DEMO_MAIN_LoadBgm1(void *unused, char *work)
{
    ((struct EggDemoWork *)work)->bgmLoadState = 0;
    GFL_USE_StepBgmLoad((unsigned int)0x3f3, (u32 *)(&((struct EggDemoWork *)work)->bgmLoadState), 1);
    ((struct EggDemoWork *)work)->bgmState = 3;
}

int EGG_DEMO_MAIN_IsBgm1Loaded(void *unused, char *work)
{
    if (((struct EggDemoWork *)work)->bgmState == 4) return 1;
    return 0;
}

void EGG_DEMO_MAIN_PushBgm(void *args, void *work)
{
    GFL_USE_SetBgmPaused((unsigned int)1);
    GFL_USE_PushBgm();
}

void EGG_DEMO_MAIN_PopBgm(void *args, void *work)
{
    GFL_USE_PopBgm();
    GFL_USE_SetBgmPaused(0);
    GFL_USE_FadeInBgmFull(6);
}

void EGG_DEMO_MAIN_LoadBgm2(void *unused, char *work)
{
    ((struct EggDemoWork *)work)->bgmLoadState = 0;
    GFL_USE_StepBgmLoad((unsigned int)0x519, (u32 *)(&((struct EggDemoWork *)work)->bgmLoadState), 1);
    ((struct EggDemoWork *)work)->bgmState = 5;
}

int EGG_DEMO_MAIN_IsBgm2Loading(void *unused, char *work)
{
    int state = ((struct EggDemoWork *)work)->bgmState;
    int result = 1;
    if (state != 5 && state != 6) result = 0;
    return result;
}

void EGG_DEMO_MAIN_StopBgm(void *unused, char *work)
{
    GFL_USE_FadeOutBgm(0x3c);
    ((struct EggDemoWork *)work)->bgmState = 7;
}

int EGG_DEMO_MAIN_IsBgmStopped(void *unused, char *work)
{
    if (((struct EggDemoWork *)work)->bgmState == 7) return 1;
    return 0;
}
