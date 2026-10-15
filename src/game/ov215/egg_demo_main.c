/*
 * file:     egg_demo_main.c
 * unit:     yes
 * function: EGG_DEMO_MAIN_Create, EGG_DEMO_MAIN_Delete, EGG_DEMO_MAIN_Update, EGG_DEMO_MAIN_OnVBlank, EGG_DEMO_MAIN_Init, EGG_DEMO_MAIN_DeleteResources, EGG_DEMO_MAIN_LoadGraphics, EGG_DEMO_MAIN_Noop, EGG_DEMO_MAIN_InitActors, EGG_DEMO_MAIN_DeleteActors, EGG_DEMO_MAIN_StartActorAnims, EGG_DEMO_MAIN_AreActorAnimsDone, EGG_DEMO_MAIN_StartFadeOutBgm, EGG_DEMO_MAIN_NoopB, EGG_DEMO_MAIN_UpdateBgm, EGG_DEMO_MAIN_IsBgmFadeOut, EGG_DEMO_MAIN_PlayBgm, EGG_DEMO_MAIN_LoadBgm1, EGG_DEMO_MAIN_PushBgm, EGG_DEMO_MAIN_PopBgm, EGG_DEMO_MAIN_LoadBgm2, EGG_DEMO_MAIN_StopBgm
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
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   KEY_GetTrg 0x020362DC arm
 *   PROCSYS_Main 0x02031330 arm
 *   FADE_IsActive 0x0204E804 arm
 *   EGG_DEMO_VIEW_SetActive 0x021F6A3C thumb ov215
 *   EGG_DEMO_VIEW_GetActive 0x021F6A44 thumb ov215
 *   GAME_DATA_GetField114 0x020127A4 thumb
 *   func_02012944 0x02012944 thumb
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
 *   func_020355D8 0x020355D8 arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BEACON_GetBlock 0x0200C0F0 thumb
 *   NAMEIN_SETUP_CreateMonArgs 0x0216C028 thumb ov010
 *   PROCSYS_Push 0x02031348 arm
 *   gNameInProcData 0x021F5580 data ov194 a4
 *   NAMEIN_SETUP_IsCanceled 0x0216C0E4 thumb ov010
 *   STRBUF_Create 0x020457B0 arm
 *   NAMEIN_SETUP_CopyName 0x0216C0D4 thumb ov010
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   GAME_DATA_GetTrainerRecord 0x02012F2C thumb
 *   func_02008DF0 0x02008DF0 thumb
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
 *   func_02040588 0x02040588 arm
 *   EGG_DEMO_GRAPHIC_Create 0x021F63CC thumb ov215
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_020056A0 0x020056A0 thumb
 *   EGG_DEMO_MENU_Create 0x021F6060 thumb ov215
 *   EGG_DEMO_MENU_InitDialog 0x021F6280 thumb ov215
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   func_0207D63C 0x0207D63C arm
 *   BG_SYS_LoadPlttEntry 0x02040EBC arm
 *   EGG_DEMO_VIEW_Create 0x021F6720 thumb ov215
 *   EGG_DEMO_VIEW_Delete 0x021F67B0 thumb ov215
 *   EGG_DEMO_MENU_Noop 0x021F62C8 thumb ov215
 *   EGG_DEMO_MENU_Delete 0x021F6114 thumb ov215
 *   func_02030EAC 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   EGG_DEMO_GRAPHIC_Delete 0x021F6474 thumb ov215
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   EGG_DEMO_GRAPHIC_GetClactBank2 0x021F64FC thumb ov215
 *   table 0x021F7124 data ov215
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_SetActorAnimIndex 0x0204B908 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb
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

struct Proc;
struct S020314B8;
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
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,u32,u32);
extern void FADE_Start(u32,int,int,int);
extern void *PROCSYS_Create(int a0);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
extern void func_0203133C(struct S020314B8 *),func_020315D4(struct Proc *),GFL_HEAP_DeleteChecked(u32);
extern u32 KEY_GetTrg(void),PROCSYS_Main(void *);
extern int FADE_IsActive(void);
extern void EGG_DEMO_VIEW_SetActive(char *);
extern int EGG_DEMO_VIEW_GetActive(char *);
extern void *GAME_DATA_GetField114(struct SaveBlock *);
extern u8 *func_02012944(void *);
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *);
extern u32 ZONEDATA_GetPlaceNameId(u32);
extern void POKE_TOOL_HatchEgg(void *,u32,u32,u32);
extern void *ZUKAN_SAVE_GetFromGameData(void *);
extern void ZUKAN_SAVE_RegisterSeen(struct Blk37 *,void *),ZUKAN_SAVE_RegisterCaught(struct Blk37 *,void *);
extern void EGG_DEMO_VIEW_SetSpecies(char *p, int a);
extern int EGG_DEMO_VIEW_IsFadeDone(char *),EGG_DEMO_VIEW_IsFinished(char *);
extern void EGG_DEMO_MENU_SetText(char *,char *,u32);
extern int EGG_DEMO_MENU_WaitText(void *,char *),EGG_DEMO_MAIN_IsBgm2Loading(void *,char *),EGG_DEMO_MENU_CreateDialog(int,char *),EGG_DEMO_MENU_GetDialogResult(int,char *);
extern void EGG_DEMO_MAIN_StopBgm(void *,char *),func_020355D8(u8);
extern void *GAME_DATA_GetSaveControl(struct Big *),*BEACON_GetBlock(void *);
extern int *NAMEIN_SETUP_CreateMonArgs(u16,int,int,int,int);
extern void PROCSYS_Push(void *,u32,u32,u32);
extern int NAMEIN_SETUP_IsCanceled(int *);
extern struct U16Vec *STRBUF_Create(u32,u32);
extern void NAMEIN_SETUP_CopyName(int *,int),POKE_TOOL_SetPartyValue(void *,u32,u32),STRBUF_Delete(struct U16Vec *);
extern void *GAME_DATA_GetTrainerRecord(int *);
extern u32 func_02008DF0(struct Sub02008C20Obj *,int);
extern int NAMEIN_SETUP_FreeArgs(int a0);
extern void EGG_DEMO_MENU_FadeInBgm(u32 *,u32 *),EGG_DEMO_MAIN_UpdateBgm(u8 *,u8 *),EGG_DEMO_MENU_Main(void *,char *),EGG_DEMO_MENU_ProcessDialog(void *,char *);
extern void EGG_DEMO_VIEW_Update(char *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *);
extern void EGG_DEMO_GRAPHIC_Draw(char *),EGG_DEMO_GRAPHIC_Draw3d(char *),EGG_DEMO_VIEW_Draw(char *),EGG_DEMO_GRAPHIC_DrawEnd(char *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern char *EGG_DEMO_GRAPHIC_Create(u32,u16);
extern struct GfFont *GF_FONT_Create(int,int,int,int,u32);
extern u32 PRINTSYS_QUE_Create(void *);
extern void *func_020056A0(u32,u32,u32);
extern void EGG_DEMO_MENU_Create(int,char *);
extern void EGG_DEMO_MENU_InitDialog(int,u8 *);
extern void BG_SYS_SetVisibleLayer(int,u16);
extern void func_0207D63C(u32 *,u32,u32,int,int);
extern void BG_SYS_LoadPlttEntry(u32,u32);
extern char *EGG_DEMO_VIEW_Create(u32,void *);
extern void EGG_DEMO_VIEW_Delete(char *p);
extern void EGG_DEMO_MENU_Noop(int a0, char *a1);
extern void EGG_DEMO_MENU_Delete(void *unused, char *p);
extern void func_02030EAC(struct Node *n);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void EGG_DEMO_GRAPHIC_Delete(char *p);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short);
extern unsigned int func_02049658(void *a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, u16 g);
extern void func_020498F4(void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short);
extern void ARC_TOOL_DeleteHandle(void *);
extern void BG_SYS_PushTile(u32 index);
extern int CLACT_RegisterPaletteEx(void *, unsigned int, unsigned int, unsigned int, unsigned short, unsigned short, unsigned short);
extern int CLACT_RegisterCharacter(void *, unsigned int, unsigned int, unsigned int, unsigned short);
extern int CLACT_RegisterCellAnim(void *, unsigned int, unsigned int, unsigned int);
extern int EGG_DEMO_GRAPHIC_GetClactBank2(char *p);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorAutoAnim(struct Obj *p, unsigned int v);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCellAnim(unsigned);
extern void CLACT_ReleaseCharacter(unsigned);
extern void CLACT_ReleasePalette(unsigned);
extern void CLACT_SetActorAnimIndex(int a0, int a1);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void GFL_USE_FadeOutBgm(u32 a);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int  GFL_USE_IsBgmFading(void);
extern int GFL_USE_PushBgm(void);
extern int  GFL_USE_IsBgmPlaying(void);
extern u32 GFL_USE_StepBgmLoad(u8 *a0, u32 *a1, u32 a2);
extern void GFL_USE_CancelChangeAndPlayBgm(unsigned, unsigned);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_FadeInBgmFull(u32 a);
int EGG_DEMO_MAIN_Create(void *a,int unused,u32 c);
int EGG_DEMO_MAIN_Delete(struct Proc *task,int unused,u32 a,char *p);
int EGG_DEMO_MAIN_Update(u32 unused0,u32 unused1,u32 *a,u32 *p);
void EGG_DEMO_MAIN_OnVBlank(void *unused, char *p);
void EGG_DEMO_MAIN_Init(int a,char *p);
void EGG_DEMO_MAIN_DeleteResources(u32 a,char *p);
void EGG_DEMO_MAIN_LoadGraphics(int unused, char *p);
void EGG_DEMO_MAIN_Noop(int a0, char *a1);
void EGG_DEMO_MAIN_InitActors(int unused, struct EggDemoWork *p);
void EGG_DEMO_MAIN_DeleteActors(void *unused, char *p);
void EGG_DEMO_MAIN_StartActorAnims(int unused, struct EggDemoWork *p);
int EGG_DEMO_MAIN_AreActorAnimsDone(int unused, struct EggDemoWork *p);
int EGG_DEMO_MAIN_StartFadeOutBgm(int a, char *b);
void EGG_DEMO_MAIN_NoopB(u32 a, char *p);
void EGG_DEMO_MAIN_UpdateBgm(u8 *p, u8 *q);
int EGG_DEMO_MAIN_IsBgmFadeOut(void *unused,char *p);
void EGG_DEMO_MAIN_PlayBgm(void *unused, char *p);
int EGG_DEMO_MAIN_IsBgmPlaying(void *unused, char *p);
void EGG_DEMO_MAIN_LoadBgm1(void *unused, char *p);
int EGG_DEMO_MAIN_IsBgm1Loaded(void *unused, char *p);
void EGG_DEMO_MAIN_PushBgm(void *a0, void *a1);
void EGG_DEMO_MAIN_PopBgm(void *a0, void *a1);
void EGG_DEMO_MAIN_LoadBgm2(void *unused, char *p);
int EGG_DEMO_MAIN_IsBgm2Loading(void *unused, char *p);
void EGG_DEMO_MAIN_StopBgm(void *unused, char *p);
int EGG_DEMO_MAIN_IsBgmStopped(void *unused, char *p);
extern char gNameInProcData,abs_id_C2;
extern const unsigned int table[][2];


/*
 * Legacy void allocator/31324 returns consumed; preserve visible heap input.
 */
int EGG_DEMO_MAIN_Create(void *owner,int unused,u32 args)
{
    char *work;
    GFL_HEAP_CreateChildHeap(1,143,5<<16);
    work=PROCSYS_AllocProcWork(owner,140,143);
    MI_CpuFill8(work,0,140);
    ((struct EggDemoWork *)work)->heapId=143;
    ((struct EggDemoWork *)work)->state=0;
    ((struct EggDemoWork *)work)->fadeDelay=5;
    ((struct EggDemoWork *)work)->bgmState=0;
    ((struct EggDemoWork *)work)->bgmTimer=0;
    ((struct EggDemoWork *)work)->dialogState=0;
    EGG_DEMO_MAIN_Init(args,work);
    EGG_DEMO_MAIN_StartFadeOutBgm(args,work);
    FADE_Start(3,16,16,0);
    ((struct EggDemoWork *)work)->proc=(unsigned int)PROCSYS_Create(((struct EggDemoWork *)work)->heapId);
    GFL_NET_RestartWithDefaultTimeout(0,((struct EggDemoWork *)work)->heapId);
    return 1;
}


int EGG_DEMO_MAIN_Delete(struct Proc *task,int unused,u32 args,char *work) { func_0203133C(*(struct S020314B8 * *)&((struct EggDemoWork *)work)->proc);EGG_DEMO_MAIN_NoopB(args,work);if(((struct EggDemoWork *)work)->state!=17)EGG_DEMO_MAIN_DeleteResources(args,work);func_020315D4(task);GFL_HEAP_DeleteChecked(143);return 1; }


/*
 * prototypes: owning ARM9 units and ov215 sources; live r3 from C028 is
 * forwarded by 31348 into the four-argument 314F4 body.
 * lever: pooled overlay ID abs_id_C2 and branch-local else return preserve
 * case15 tail layout; direct 194 and early return produced DIFF97/896.
 * data: overlay ID 194 supplied to 31348 identifies ov194's process table
 * at 021F5580; own ov194 listing has three callback words there.
 */
int EGG_DEMO_MAIN_Update(u32 unused0,u32 unused1,u32 *args,u32 *work)
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
    case 1:if(!FADE_IsActive()){((struct EggDemoWork *)work)->state=2;EGG_DEMO_MAIN_StartActorAnims((int)args,(struct EggDemoWork *)work);}break;
    case 2:if(!EGG_DEMO_MAIN_IsBgmFadeOut(args,(char *)work)&&EGG_DEMO_MAIN_AreActorAnimsDone((int)args,(struct EggDemoWork *)work)){((struct EggDemoWork *)work)->state=3;EGG_DEMO_MAIN_PlayBgm(args,(char *)work);}break;
    case 3:if(!EGG_DEMO_MAIN_IsBgmPlaying(args,(char *)work)){((struct EggDemoWork *)work)->state=4;EGG_DEMO_MAIN_LoadBgm1(args,(char *)work);}break;
    case 4:if(EGG_DEMO_MAIN_IsBgm1Loaded(args,(char *)work)){((struct EggDemoWork *)work)->state=5;EGG_DEMO_VIEW_SetActive((char *)((struct EggDemoWork *)work)->view);}break;
    case 5:if(EGG_DEMO_VIEW_GetActive((char *)((struct EggDemoWork *)work)->view)){((struct EggDemoWork *)work)->state=6;EGG_DEMO_MAIN_PushBgm(args,work);}break;
    case 6:
        ((struct EggDemoWork *)work)->state=7;
        save=GAME_DATA_GetField114((struct SaveBlock *)args[0]);trainer=func_02012944((void *)args[0]);
        POKE_TOOL_HatchEgg((void *)args[1],(u32)trainer,ZONEDATA_GetPlaceNameId(GAME_DATA_GetPlayerZoneId(save)),((struct EggDemoWork *)work)->heapId);
        dex=ZUKAN_SAVE_GetFromGameData((void *)args[0]);ZUKAN_SAVE_RegisterSeen(dex,(void *)args[1]);ZUKAN_SAVE_RegisterCaught(dex,(void *)args[1]);
        EGG_DEMO_VIEW_SetSpecies((char *)((struct EggDemoWork *)work)->view,(int)((void *)args[1]));break;
    case 7:if(EGG_DEMO_VIEW_IsFadeDone((char *)((struct EggDemoWork *)work)->view)){((struct EggDemoWork *)work)->state=8;EGG_DEMO_VIEW_ResetAnimState((char *)((struct EggDemoWork *)work)->view);}break;
    case 8:if(EGG_DEMO_VIEW_IsFinished((char *)((struct EggDemoWork *)work)->view)){((struct EggDemoWork *)work)->state=9;EGG_DEMO_MENU_Draw(args,(char *)work);EGG_DEMO_MAIN_LoadBgm2(args,(char *)work);}break;
    case 9:((struct EggDemoWork *)work)->vblankFlag=1;((struct EggDemoWork *)work)->state=10;break;
    case 10:EGG_DEMO_MENU_SetText((char *)args,(char *)work,1);((struct EggDemoWork *)work)->state=11;break;
    case 11:if(EGG_DEMO_MENU_WaitText(args,(char *)work)&&!EGG_DEMO_MAIN_IsBgm2Loading(args,(char *)work)){((struct EggDemoWork *)work)->state=12;EGG_DEMO_MENU_SetText((char *)args,(char *)work,2);}break;
    case 12:if(EGG_DEMO_MENU_WaitText(args,(char *)work)){((struct EggDemoWork *)work)->state=13;EGG_DEMO_MENU_CreateDialog((int)args,(char *)work);}break;
    case 13:
        active=EGG_DEMO_MENU_GetDialogResult((int)args,(char *)work);
        if(active==0){((struct EggDemoWork *)work)->state=18;FADE_Start(3,0,16,2);EGG_DEMO_MAIN_StopBgm(args,(char *)work);func_020355D8(0);}
        else if(active==1){((struct EggDemoWork *)work)->state=14;FADE_Start(3,0,16,0);func_020355D8(0);}break;
    case 14:
        if(!FADE_IsActive()){
            block=BEACON_GetBlock(GAME_DATA_GetSaveControl((struct Big *)args[0]));
            EGG_DEMO_MAIN_DeleteResources((u32)args,(char *)work);((struct EggDemoWork *)work)->state=15;
            child=NAMEIN_SETUP_CreateMonArgs(((struct EggDemoWork *)work)->heapId,(int)args[1],10,0,(int)block);((struct EggDemoWork *)work)->nameChild=child;
            PROCSYS_Push((void *)((struct EggDemoWork *)work)->proc,(u32)&abs_id_C2,(u32)&gNameInProcData,(u32)child);
        }break;
    case 15:
        if(active!=1){
        if(!NAMEIN_SETUP_IsCanceled(((struct EggDemoWork *)work)->nameChild)){
            vec=STRBUF_Create(32,((struct EggDemoWork *)work)->heapId);NAMEIN_SETUP_CopyName(((struct EggDemoWork *)work)->nameChild,(int)vec);
            POKE_TOOL_SetPartyValue((void *)args[1],115,(u32)vec);STRBUF_Delete(vec);
            func_02008DF0(GAME_DATA_GetTrainerRecord((int *)args[0]),30);
        }
        NAMEIN_SETUP_FreeArgs((int)(((struct EggDemoWork *)work)->nameChild));((struct EggDemoWork *)work)->state=16;EGG_DEMO_MAIN_StopBgm(args,(char *)work);
        }else{return 0;}break;
    case 16:if(!EGG_DEMO_MAIN_IsBgmStopped(args,(char *)work)){((struct EggDemoWork *)work)->state=17;EGG_DEMO_MENU_FadeInBgm(args,work);return 1;}break;
    case 17:break;
    case 18:if(!EGG_DEMO_MAIN_IsBgmStopped(args,(char *)work)){((struct EggDemoWork *)work)->state=19;EGG_DEMO_MENU_FadeInBgm(args,work);}break;
    case 19:if(!FADE_IsActive()){((struct EggDemoWork *)work)->state=20;return 1;}break;
    }
    EGG_DEMO_MAIN_UpdateBgm((u8 *)args,(u8 *)work);
    if(((struct EggDemoWork *)work)->state!=15&&((struct EggDemoWork *)work)->state!=16&&((struct EggDemoWork *)work)->state!=17&&((struct EggDemoWork *)work)->state!=20){
        EGG_DEMO_MENU_Main(args,(char *)work);EGG_DEMO_MENU_ProcessDialog(args,(char *)work);EGG_DEMO_VIEW_Update((char *)((struct EggDemoWork *)work)->view);
        PRINTSYS_QUE_Main((struct PrintSys *)((struct EggDemoWork *)work)->printQue);EGG_DEMO_GRAPHIC_Draw((char *)((struct EggDemoWork *)work)->graphic);EGG_DEMO_GRAPHIC_Draw3d((char *)((struct EggDemoWork *)work)->graphic);
        EGG_DEMO_VIEW_Draw((char *)((struct EggDemoWork *)work)->view);EGG_DEMO_GRAPHIC_DrawEnd((char *)((struct EggDemoWork *)work)->graphic);
    }
    return 0;
}


void EGG_DEMO_MAIN_OnVBlank(void *unused, char *work)
{
    if (((struct EggDemoWork *)work)->vblankFlag) {
        func_02040588(1, 1);
        ((struct EggDemoWork *)work)->vblankFlag = 0;
    }
}


void EGG_DEMO_MAIN_Init(int args,char *work)
{
    u8 i;
    for (i=0;i<=7;i++) func_02040588(i,0);
    ((struct EggDemoWork *)work)->graphic=EGG_DEMO_GRAPHIC_Create(1,((struct EggDemoWork *)work)->heapId);
    ((struct EggDemoWork *)work)->font=GF_FONT_Create(23,0,0,0,((struct EggDemoWork *)work)->heapId);
    ((struct EggDemoWork *)work)->printQue=PRINTSYS_QUE_Create((void *)(u32)((struct EggDemoWork *)work)->heapId);
    ((struct EggDemoWork *)work)->vblankTask=func_020056A0((u32)EGG_DEMO_MAIN_OnVBlank,(u32)work,1);
    EGG_DEMO_MAIN_LoadGraphics(args,work);
    EGG_DEMO_MAIN_InitActors(args,(struct EggDemoWork *)work);
    EGG_DEMO_MENU_Create(args,work);
    EGG_DEMO_MENU_InitDialog(args,(u8 *)work);
    BG_SYS_SetVisibleLayer(0,2);
    BG_SYS_SetVisibleLayer(2,1);
    BG_SYS_SetVisibleLayer(1,0);
    BG_SYS_SetVisibleLayer(4,0);
    func_02040588(0,1);
    func_02040588(2,1);
    func_02040588(4,1);
    func_0207D63C((u32 *)0x04000050,1,47,0,0);
    BG_SYS_LoadPlttEntry(0,0x4210);
    BG_SYS_LoadPlttEntry(4,0);
    *(char * *)&((struct EggDemoWork *)work)->view=EGG_DEMO_VIEW_Create(((struct EggDemoWork *)work)->heapId,((struct EggDemoArgs *)((u32)args))->mon);
}


void EGG_DEMO_MAIN_DeleteResources(u32 args,char *work)
{
    EGG_DEMO_VIEW_Delete((char *)(((struct EggDemoWork *)work)->view));
    EGG_DEMO_MENU_Noop(args,work);
    EGG_DEMO_MENU_Delete((void *)args,work);
    EGG_DEMO_MAIN_DeleteActors((void *)args,work);
    EGG_DEMO_MAIN_Noop(args,work);
    func_02030EAC((struct Node *)(((struct EggDemoWork *)work)->vblankTask));
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct EggDemoWork *)work)->printQue));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct EggDemoWork *)work)->printQue));
    GF_FONT_Delete((void *)(((struct EggDemoWork *)work)->font));
    EGG_DEMO_GRAPHIC_Delete((char *)(((struct EggDemoWork *)work)->graphic));
}



void EGG_DEMO_MAIN_LoadGraphics(int unused, char *work)
{
    void *h = func_020490F4(189, ((struct EggDemoWork *)work)->heapId);
    func_02049B68(h, 3, 0, 0, 32, ((struct EggDemoWork *)work)->heapId);
    func_02049658(h, 5, 2, 0, 0, 0, ((struct EggDemoWork *)work)->heapId);
    func_020498F4(h, 4, 2, 0, 0, 0, ((struct EggDemoWork *)work)->heapId);
    ARC_TOOL_DeleteHandle(h);
    BG_SYS_PushTile(2);
}


void EGG_DEMO_MAIN_Noop(int a0, char *a1)
{

}


/*
 * lever: first types search split the full-word per-element pointer assignment and named the table address and resource result; declarations ported to block tops with initializer timing preserved.
 * checks: 1 own callee bodies prove 2/7/5/4/1/1/7/2 arities and visible full-word B294 return; 2 no ov214/215/216 constructor twin, own request builder read; 3 carried const/struct compiles remain exhausted2/2; 4 enum-zero, hoisted-zero, per-element pointer and byte-colour idioms read, manual order2/2 unchanged; 5 fresh full idiom inventory and own neighbours read. First types search stopped at200 with MATCH140; clean independent one EXACT140, all9 sites resolved. No manual scheduling variant added.
 * Return ABI: B294 original0204B314 calls CFDC then0204B318/31C returns without overwriting r0; CFDC0204D040 restores full object pointer. Caller021F5E20 stores this r0 and forwards it to B92C. Own B294 void declaration is superseded here by consumed return evidence.
 * Forwarding: 64FC adds4 to r0 and tails through6504 to662C;662C is ldr r0,[r0]; bx lr. All one full-word input/output.
 */
void EGG_DEMO_MAIN_InitActors(int unused, struct EggDemoWork *work)
{
    unsigned char i;
    void *h = func_020490F4(189, work->heapId);
    char *tmp1;
    unsigned int tmp2;
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
        unsigned int o;
        tmp1 = (char *)work;
        tmp1 = tmp1 + (i * 4);
        out = (struct EggDemoWork *)tmp1;
        tmp2 = (unsigned int)table[i];
        o = (unsigned int)CLACT_CreateActor((void *)EGG_DEMO_GRAPHIC_GetClactBank2((char *)work->graphic), work->charId, work->paletteId, work->cellAnimId, (const void *)tmp2, 0, work->heapId);
        out->actors[0] = (void *)o;
        CLACT_SetActorAutoAnim((struct Obj *)o, 0);
    }
}


void EGG_DEMO_MAIN_DeleteActors(void *unused, char *work)
{
    u8 i;
    for (i = 0; i < 6; i++) CLACT_DeleteActor(*(void **)(work + i * 4 + 0x38));
    CLACT_ReleaseCellAnim(((struct EggDemoWork *)work)->cellAnimId);
    CLACT_ReleaseCharacter(((struct EggDemoWork *)work)->charId);
    CLACT_ReleasePalette(((struct EggDemoWork *)work)->paletteId);
}



void EGG_DEMO_MAIN_StartActorAnims(int unused, struct EggDemoWork *work)
{
    unsigned char i;
    for (i = 0; i < 6; i++)
    {
        CLACT_SetActorAnimIndex((int)work->actors[i], 0);
        CLACT_SetActorAutoAnim(work->actors[i], 1);
    }
}



int EGG_DEMO_MAIN_AreActorAnimsDone(int unused, struct EggDemoWork *work)
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



int EGG_DEMO_MAIN_StartFadeOutBgm(int args, char *work)
{
    GFL_USE_FadeOutBgm(0x1e);
    ((struct EggDemoWork *)work)->bgmState = 1;
    return 1;
}


void EGG_DEMO_MAIN_NoopB(u32 args, char *work)
{

}



void EGG_DEMO_MAIN_UpdateBgm(u8 *args, u8 *work)
{
    switch (((struct EggDemoWork *)work)->bgmState) {
    case 0:
        break;
    case 1:
        if (GFL_USE_IsBgmFading() == 0) {
            GFL_USE_SetBgmPlayerParam((void *)1);
            GFL_USE_PushBgm();
            ((struct EggDemoWork *)work)->bgmState = 0;
        }
        break;
    case 2:
        if (GFL_USE_IsBgmPlaying() == 0)
            ((struct EggDemoWork *)work)->bgmState = 0;
        break;
    case 3:
        if (GFL_USE_StepBgmLoad((u8 *)0x3F3, (u32 *)(work + 0x24), 0) != 0)
            ((struct EggDemoWork *)work)->bgmState = 4;
        break;
    case 4:
        break;
    case 5:
        if (GFL_USE_StepBgmLoad((u8 *)0x519, (u32 *)(work + 0x24), 0) != 0)
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
    GFL_USE_StepBgmLoad((u8 *)0x3f3, (u32 *)(work + 0x24), 1);
    ((struct EggDemoWork *)work)->bgmState = 3;
}



int EGG_DEMO_MAIN_IsBgm1Loaded(void *unused, char *work)
{
    if (((struct EggDemoWork *)work)->bgmState == 4) return 1;
    return 0;
}



void EGG_DEMO_MAIN_PushBgm(void *a0, void *a1)
{
    GFL_USE_SetBgmPlayerParam((void *)1);
    GFL_USE_PushBgm();
}



void EGG_DEMO_MAIN_PopBgm(void *a0, void *a1)
{
    GFL_USE_PopBgm();
    GFL_USE_SetBgmPlayerParam(0);
    GFL_USE_FadeInBgmFull(6);
}


void EGG_DEMO_MAIN_LoadBgm2(void *unused, char *work)
{
    ((struct EggDemoWork *)work)->bgmLoadState = 0;
    GFL_USE_StepBgmLoad((u8 *)0x519, (u32 *)(work + 0x24), 1);
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
