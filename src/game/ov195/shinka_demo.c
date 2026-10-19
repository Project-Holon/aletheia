/*
 * file:     shinka_demo.c
 * unit:     yes
 * function: SHINKA_DEMO_Create, SHINKA_DEMO_Destroy, SHINKA_DEMO_Main, SHINKA_DEMO_SetupScene, SHINKA_DEMO_DeleteScene, SHINKA_DEMO_StartBgm, SHINKA_DEMO_Noop, SHINKA_DEMO_UpdateBgm, SHINKA_DEMO_IsBgmState1, SHINKA_DEMO_RestoreBgm, SHINKA_DEMO_PlayEvolutionBgm, SHINKA_DEMO_IsBgmState2, SHINKA_DEMO_StartEvolutionBgm, SHINKA_DEMO_PushBgm, SHINKA_DEMO_PopBgm, SHINKA_DEMO_IsBgmState4, SHINKA_DEMO_FadeOutBgm, SHINKA_DEMO_IsBgmState6, SHINKA_DEMO_StartResultBgm, SHINKA_DEMO_IsBgmState7Or8, SHINKA_DEMO_PlayResultBgm, SHINKA_DEMO_StopBgm, SHINKA_DEMO_LoadSprites, SHINKA_DEMO_Noop2, SHINKA_DEMO_CreateActors, SHINKA_DEMO_DeleteActors, SHINKA_DEMO_ResetActorAnims, SHINKA_DEMO_AreActorAnimsDone, SHINKA_DEMO_MainTask, SHINKA_DEMO_SetupWindows, SHINKA_DEMO_DeleteWindows, SHINKA_DEMO_UpdateWindows, SHINKA_DEMO_PrintStreamCallback, SHINKA_DEMO_PrintText, SHINKA_DEMO_AdvanceText, SHINKA_DEMO_IsConfirmPressed, SHINKA_DEMO_ClearText, SHINKA_DEMO_SetupMessageBox, SHINKA_DEMO_CreateConfirmMenu, SHINKA_DEMO_DeleteConfirmMenu, SHINKA_DEMO_SetMenuText, SHINKA_DEMO_BuildString, SHINKA_DEMO_AddShedinja, SHINKA_DEMO_ClearHeldItem, SHINKA_DEMO_Setup3d
 * address:  0x02203FA0
 * region:   ov195
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
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   FADE_Start 0x0204E720 arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   PROCSYS_Create 0x02031324 arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   d_02208F40 0x02208F40 data a4
 *   PROCSYS_Delete 0x0203133C arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   PROCSYS_Main 0x02031330 arm
 *   PROCSYS_Push 0x02031348 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   SYSTEM_DATA_GetConfig 0x0200873C thumb
 *   RECORD_AddOne 0x02008DF0 thumb
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   ZUKAN_SAVE_RegisterSeen 0x0200CFA0 thumb
 *   ZUKAN_SAVE_RegisterCaught 0x0200CDE0 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   GAME_DATA_GetTrainerRecord 0x02012F2C thumb
 *   POKE_TOOL_ChangeSpecies 0x020178D8 thumb
 *   POKE_TOOL_SetMoveSlot 0x020181F4 thumb
 *   POKE_TOOL_LearnLevelUpMove 0x02018328 thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   GAME_BEACON_SetPokeEvolution 0x020272A4 thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   TCB_GetTaskOffset 0x02030CB0 arm
 *   TCB_Init 0x02030CBC arm
 *   TCB_Main 0x02030D28 arm
 *   TCB_Noop 0x02030DA4 arm
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   UI_GetInputMode 0x020355C4 arm
 *   UI_SetInputMode 0x020355D8 arm
 *   KEY_GetTrg 0x020362DC arm
 *   FADE_IsActive 0x0204E804 arm
 *   YESNO_MENU_Create 0x021B6DC0 thumb ov067
 *   YESNO_MENU_Delete 0x021B709C thumb ov067
 *   YESNO_MENU_Start 0x021B70F4 thumb ov067
 *   YESNO_MENU_Close 0x021B72DC thumb ov067
 *   YESNO_MENU_Update 0x021B7378 thumb ov067
 *   YESNO_MENU_GetAnswer 0x021B76B0 thumb ov067
 *   gPokeStatusProcData 0x021DC800 data a4 ov131
 *   ov131_id 0x00000083 data a1
 *   ov196_id 0x000000C4 data a1
 *   ov198_id 0x000000C6 data a1
 *   B_PLIST_MAIN_Create 0x0220F3E8 thumb ov198
 *   SHINKA_DEMO_GRAPHIC_Draw 0x022059FC thumb ov195
 *   SHINKA_DEMO_GRAPHIC_Update 0x02205A10 thumb ov195
 *   SHINKA_DEMO_GRAPHIC_DrawEnd 0x02205A1C thumb ov195
 *   SHINKA_DEMO_GRAPHIC_GetCamera 0x02205A28 thumb ov195
 *   SHINKA_DEMO_GRAPHIC_SetupSubBg 0x02205A34 thumb ov195
 *   SHINKA_DEMO_GRAPHIC_ReleaseSubBg 0x02205A84 thumb ov195
 *   SHINKA_DEMO_VIEW_Main 0x02205D50 thumb ov195
 *   SHINKA_DEMO_VIEW_Draw 0x0220602C thumb ov195
 *   SHINKA_DEMO_VIEW_RequestStart 0x02206044 thumb ov195
 *   SHINKA_DEMO_VIEW_IsStartDone 0x0220604C thumb ov195
 *   SHINKA_DEMO_VIEW_RequestConfirm 0x02206050 thumb ov195
 *   SHINKA_DEMO_VIEW_IsConfirmDone 0x02206058 thumb ov195
 *   SHINKA_DEMO_VIEW_RequestEvolve 0x0220605C thumb ov195
 *   SHINKA_DEMO_VIEW_RequestFadeOut 0x02206064 thumb ov195
 *   SHINKA_DEMO_VIEW_IsEvolveReady 0x0220606C thumb ov195
 *   SHINKA_DEMO_VIEW_IsEvolveStarted 0x02206070 thumb ov195
 *   SHINKA_DEMO_VIEW_IsEvolveDone 0x02206074 thumb ov195
 *   SHINKA_DEMO_VIEW_TrySecondForm 0x02206078 thumb ov195
 *   SHINKA_DEMO_EFFECT_Main 0x0220878C thumb ov195
 *   SHINKA_DEMO_EFFECT_Draw 0x02208804 thumb ov195
 *   SHINKA_DEMO_EFFECT_Trigger 0x02208814 thumb ov195
 *   SHINKA_DEMO_EFFECT_StartIntro 0x0220882C thumb ov195
 *   SHINKA_DEMO_EFFECT_AdvanceState 0x02208844 thumb ov195
 *   SHINKA_DEMO_EFFECT_IsState4 0x02208850 thumb ov195
 *   SHINKA_DEMO_EFFECT_IsCameraReady 0x02208860 thumb ov195
 *   ov067_id 0x00000043 data
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_SetPriority 0x0204047C arm
 *   BG_SYS_LoadPlttEntry 0x02040EBC arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   SHINKA_DEMO_GRAPHIC_Create 0x022058F8 thumb ov195
 *   SHINKA_DEMO_VIEW_Create 0x02205C74 thumb ov195
 *   SHINKA_DEMO_EFFECT_Create 0x0220871C thumb ov195
 *   SHINKA_DEMO_EFFECT_Destroy  0x02208770  thumb
 *   SHINKA_DEMO_VIEW_Destroy  0x02205D28  thumb
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   SHINKA_DEMO_GRAPHIC_Destroy  0x022059A0  thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_IsBgmPlaying 0x02005F38 thumb
 *   GFL_USE_SetBgmPaused 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   GFL_USE_StepBgmLoad 0x020063B4 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   d_02208C4C 0x02208C4C data a4
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   TCBL_Create 0x0203101C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   APP_KEYCURSOR_CreateDefault 0x02028590 thumb
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   TCBL_Main 0x020310C4 arm
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 *   GFL_USE_IsAnySeBusy 0x02006238 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStreamCallBack 0x0201CD10 thumb
 *   KEY_GetCont  0x0203630C  arm
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotTag 0x0201EE0C thumb
 *   WORDSET_SetSlotMonSpeciesName 0x0201EE84 thumb
 *   WORDSET_SetSlotMonNickname 0x0201EEF4 thumb
 *   WORDSET_SetSlotFromMsgCB 0x0201EF34 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   WORDSET_Delete 0x0201ED04 thumb
 *   gSpeciesNameBank 0x020A7370 data a4
 *   GAME_DATA_GetMyItem 0x0201292C thumb
 *   POKEPARTY_GetCapacity 0x0201AA14 thumb
 *   MYITEM_SAVEDATA_HasItem 0x02007F68 thumb
 *   MYITEM_SAVEDATA_RemoveItem 0x02007F1C thumb
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   POKE_TOOL_CopyPartyPokemon 0x02019CE0 thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   MAIL_Create 0x02008F08 thumb
 *   POKEPARTY_Add 0x0201A98C thumb
 *   d_02208CCC 0x02208CCC data a4
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb  arm9
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb  arm9
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb  arm9
 */

#define W(n) (*(u32 *)(s+(n)))
#define P(n) (*(void **)(s+(n)))
#define H(n) (*(u16 *)(s+(n)))
#define B(n) (*(u8 *)(s+(n)))
#define A(n) (*(u32 *)(a+(n)))
#define AH(n) (*(u16 *)(a+(n)))
#define AB(n) (*(u8 *)(a+(n)))
#define REG_BG0CNT     (*(volatile u16 *)0x04000008)
#define REG_DISP3DCNT  (*(volatile u16 *)0x04000060)
#define REG_VIEWPORT   (*(volatile u32 *)0x04000580)
struct U16Vec;
struct App;
struct Scene;
struct Node;
struct Anim;
struct Big;
struct Blk37;
struct Ctx;
struct Owner;
struct PalAnmSlot;
struct PrintSys;
struct YesNoMenu;
struct GfFont;
struct Obj;
struct Actor;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct Tcbl;
struct Rec3;
struct Rec;
struct WordSet;
struct BigObj;
struct RecDC;
struct Party;
struct PartyMon;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct App {
    u32 gameData;     /* 0x00 */
    void *party;      /* 0x04: party data */
    u16 f08;          /* 0x08 */
    u8 partyIndex;    /* 0x0a */
    u8 f0b;           /* 0x0b */
    u32 flag0C;       /* 0x0c */
    u32 f10;          /* 0x10 */
} App;

typedef struct Scene {
    u16 mainHeap;              /* 0x000: 0x94 work heap */
    u16 heap;                  /* 0x002: 0x68 scene heap */
    void *graphic;             /* 0x004: SHINKA_DEMO_GRAPHIC context */
    u32 font;                  /* 0x008: GF_FONT handle */
    u32 printQue;              /* 0x00c: PRINTSYS queue */
    void *partyMon;            /* 0x010: party member the demo evolves */
    void *strbuf;              /* 0x014: name strbuf */
    u8 pad18[0x0c];            /* 0x018 */
    u32 secondForm;            /* 0x024: second-form requested flag */
    u32 state;                 /* 0x028: main state */
    u32 timer;                 /* 0x02c: state timer */
    u32 bgmState;              /* 0x030: BGM state machine */
    u32 bgmTimer;              /* 0x034: BGM load timer */
    void *task;                /* 0x038: main task handle */
    u32 character;             /* 0x03c: CLACT character handle */
    u32 palette;               /* 0x040: CLACT palette handle */
    u32 cellAnim;              /* 0x044: CLACT cell-anim handle */
    u32 actors[6];             /* 0x048: actor handles */
    u32 actorsReady;           /* 0x060 */
    u32 printStream;           /* 0x064: PRINTSYS stream */
    u32 tcbl;                  /* 0x068: TCBL handle */
    u32 menuWindow;            /* 0x06c: BMP menu window */
    u32 window;                /* 0x070: BMP window */
    u32 frameGfx;              /* 0x074: loaded frame gfx handle */
    void *msgBankA;            /* 0x078: MSGDATA bank A */
    void *msgBankB;            /* 0x07c: MSGDATA bank B */
    u32 strbufA;               /* 0x080: message strbuf */
    u32 keyCursor;             /* 0x084: APP_KEYCURSOR handle */
    u32 windowState;           /* 0x088: window transition state */
    u32 subBgVisible;          /* 0x08c: sub BG visible */
    u32 confirmMsgBank;        /* 0x090: confirm menu MSGDATA bank */
    u32 strbufC;               /* 0x094: confirm strbuf C */
    u32 strbufD;               /* 0x098: confirm strbuf D */
    u32 yesNoMenu;             /* 0x09c: YESNO_MENU handle */
    u32 ctx;                   /* 0x0a0: TCB context */
    u32 heapBlock;             /* 0x0a4: TCB heap block */
    void *palAnm;              /* 0x0a8: PALANM handle */
    u8 bgFlag;                 /* 0x0ac */
    u8 padAD[0x100 - 0xad];    /* 0x0ad */
    void *procData;            /* 0x100: PROCSYS_Push payload */
    void *view;                /* 0x104: SHINKA_DEMO_VIEW object */
    void *effect;              /* 0x108: SHINKA_DEMO_EFFECT object */
    u32 flag10C;               /* 0x10c */
    u32 flag110;               /* 0x110 */
    u32 flag114;               /* 0x114 */
    u32 flag118;               /* 0x118 */
    u32 proc;                  /* 0x11c: PROCSYS child */
} Scene;

typedef signed int     s32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    u32 kind;
    u32 val;
} Param;

extern void GFL_HEAP_CreateChildHeap(u32 src, u32 dst, u32 size);
extern void *PROCSYS_AllocProcWork(void *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,u32,u32);
extern void *POKEPARTY_GetMember(void *,u32);
extern struct U16Vec *STRBUF_Create(u32,u32);
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
extern void *GFL_HEAP_Alloc(u32,u32,int,const char *,u16);
extern void FADE_Start(u32,int,int,int);
extern void *GFL_USE_AddMainTask(u32,u32,u32);
extern void *PROCSYS_Create(int heapId);
extern void GFL_NET_RefreshWmIconAtTopRight(u32,u32);
extern void PROCSYS_Delete(void *);
extern void TCB_DeleteTask(struct Node *);
extern u32 GFL_HEAP_Free(void *p);
extern void STRBUF_Delete(struct U16Vec *);
extern void PROCSYS_FreeProcWork(void *);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern u32 PROCSYS_Main(void *);
/* Original explicitly prepares all four registers, despite the current forwarding own source. */
extern void PROCSYS_Push(void *,int,void *,void *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void *SYSTEM_DATA_GetConfig(void *sys);
extern u32 RECORD_AddOne(void *obj, int i);
extern void *ZUKAN_SAVE_GetFromGameData(void *);
extern void ZUKAN_SAVE_RegisterSeen(struct Blk37 *p, void *m);
extern void ZUKAN_SAVE_RegisterCaught(struct Blk37 *p, void *m);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern void POKE_TOOL_ChangeSpecies(void *,u32);
extern void POKE_TOOL_SetMoveSlot(void *,u16,u32);
extern u16 POKE_TOOL_LearnLevelUpMove(void *,u32 *,u32);
extern u32 POKEPARTY_GetCount(void *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void *PALANM_Create(u32);
extern u32 PALANM_Delete(void *ctx);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern void PALANM_SetAutoTransfer(void *o, int v);
/* Caller narrows only r0; r1 retains the full word, copied to the callee's u16 store. */
extern void GAME_BEACON_SetPokeEvolution(u16,u32);
extern void *GFL_HEAP_Alloc(u32,u32,int,const char *,u16);
extern u32 GFL_HEAP_Free(void *p);
extern u32 TCB_GetTaskOffset(u32);
extern struct Ctx *TCB_Init(u32 capacity, struct Ctx *c);
extern void TCB_Main(struct Ctx *c);
extern void TCB_Noop(void *);
extern int GF_OVERLAY_Load(int);
extern void GF_OVERLAY_Unload(int);
extern u8 UI_GetInputMode(void);
extern void UI_SetInputMode(u32);
extern u32 KEY_GetTrg(void);
extern int FADE_IsActive(void);
extern void *YESNO_MENU_Create(u16,u32,u32,u32,u8,u32,u32,u32,u32);
extern void YESNO_MENU_Delete(u8 *p);
extern void YESNO_MENU_Start(struct YesNoMenu *s, u32 a1, u32 a2);
extern void YESNO_MENU_Close(struct YesNoMenu *s);
extern void YESNO_MENU_Update(struct YesNoMenu *p);
extern int YESNO_MENU_GetAnswer(struct YesNoMenu *p);
extern void B_PLIST_MAIN_Create(u8 *);
extern void SHINKA_DEMO_GRAPHIC_Draw(char *a);
extern void SHINKA_DEMO_GRAPHIC_Update(char *a);
extern void SHINKA_DEMO_GRAPHIC_DrawEnd(char *a);
extern void SHINKA_DEMO_GRAPHIC_SetupSubBg();
extern void SHINKA_DEMO_GRAPHIC_ReleaseSubBg(int unused);
extern void SHINKA_DEMO_VIEW_Main(char *p);
extern void SHINKA_DEMO_VIEW_Draw(struct Owner *o);
extern int SHINKA_DEMO_GRAPHIC_GetCamera(char *a);
extern void SHINKA_DEMO_VIEW_RequestStart(int *p);
extern void SHINKA_DEMO_VIEW_RequestConfirm(int *p);
extern void SHINKA_DEMO_VIEW_RequestEvolve(int *p);
extern void SHINKA_DEMO_VIEW_RequestFadeOut(int *p);
extern void SHINKA_DEMO_EFFECT_Main(struct Anim *p);
extern void SHINKA_DEMO_EFFECT_Draw(char *a);
extern void SHINKA_DEMO_EFFECT_Trigger(char *a);
extern void SHINKA_DEMO_EFFECT_StartIntro(int *p);
extern void SHINKA_DEMO_EFFECT_AdvanceState(int *p);
extern int SHINKA_DEMO_VIEW_IsStartDone(int *p);
extern int SHINKA_DEMO_VIEW_IsConfirmDone(int *p);
extern int SHINKA_DEMO_VIEW_IsEvolveReady(int *p);
extern int SHINKA_DEMO_VIEW_IsEvolveStarted(int *p);
extern int SHINKA_DEMO_VIEW_IsEvolveDone(int *p);
extern int SHINKA_DEMO_VIEW_TrySecondForm(int *p);
extern int SHINKA_DEMO_EFFECT_IsState4(int *p);
extern int SHINKA_DEMO_EFFECT_IsCameraReady(int *p);
extern void GFL_HEAP_CreateChildHeap(u32 parent, u32 id, u32 size);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void BG_SYS_SetPriority(int idx, unsigned short val);
extern void BG_SYS_LoadPlttEntry(u32 bgId, u32 color);
extern void G2x_SetBlendAlpha_(int, int, int, int, int);
extern struct GfFont *GF_FONT_Create(int archiveId, int fileId, int format, int isFixedWidth, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *p);
extern char *SHINKA_DEMO_GRAPHIC_Create(u32 a, u32 b);
extern struct Owner *SHINKA_DEMO_VIEW_Create(u16 heap, u32 f08, void *res0, u16 f0c);
extern struct Anim *SHINKA_DEMO_EFFECT_Create(u16 heap, u32 x);
extern void SHINKA_DEMO_EFFECT_Destroy(char *a);
extern void SHINKA_DEMO_VIEW_Destroy(char *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void SHINKA_DEMO_GRAPHIC_Destroy(char *p);
extern void GFL_USE_FadeOutBgm(u32);
extern int GFL_USE_IsBgmFading(void);
extern int GFL_USE_IsBgmPlaying(void);
extern void GFL_USE_SetBgmPaused(void *p);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern u32 GFL_USE_StepBgmLoad(u8 *bgmNo, u32 *step, u32 abort);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void GFL_USE_CancelChangeAndPlayBgm(int, int);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_UTIL_UploadBgPaletteFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_TOOL_DeleteHandle(void *);
extern void BG_SYS_PushTile(u32 index);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 vram_mode, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj *CLACT_CreateActor(void *, u32, u32, u32, const void *, u16, u16);
extern void CLACT_SetActorAutoAnim(struct Obj *, u32);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCellAnim(u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleasePalette(u32);
extern void CLACT_SetActorAnimIndex(int, int);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void PALANM_TransferPalettes(void *p);
extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *buf, int value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_MarkTileDirty(u32);
extern void *BMP_MENUWORK_LoadFrameGfx(void *layer, u32 palSlot, u32 frameId, u32 heapId);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern u32 APP_KEYCURSOR_CreateDefault(int, int, int, u16);
extern int APP_KEYCURSOR_Delete(int);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void TCBL_Destroy(void *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern void BG_SYS_FreeTileRun(u32 layer, u32 offset, u32 size);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void TCBL_Main(struct Tcbl *p);
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern int GFL_USE_IsAnySeBusy(void);
extern signed char MSG_SPEED_GetWait(void);
extern struct Rec *PRINTSYS_PrintStreamCallBack(u32 win, s16 x, s16 y, u32 str, u32 font, s32 wait, u32 tcbl, u32 priority, u32 heap, u16 fillColor, u32 a10);
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern void PRINTSYS_PrintStreamReleasePause(void *p);
extern unsigned int KEY_GetCont(void);
extern int TOUCHPANEL_GetCont(void);
extern int TOUCHPANEL_GetTrg(void);
extern void BMP_MENUWORK_DrawWindow(void *win, int commitMode, int tileBase, int palette);
extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void WORDSET_SetSlotMonSpeciesName(struct WordSet *p, u32 i, void *mon);
extern void WORDSET_SetSlotMonNickname(struct WordSet *p, u32 i, void *mon);
extern void WORDSET_SetSlotFromMsgCB(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern u32 WORDSET_Delete(struct WordSet *p);
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern u32 POKEPARTY_GetCapacity(void *p);
extern u32 MYITEM_SAVEDATA_HasItem(u8 *base, u16 id, u16 qty, u16 d);
extern u32 MYITEM_SAVEDATA_RemoveItem(u8 *base, u16 id, u16 qty, u16 d);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void POKE_TOOL_CopyPartyPokemon(const struct RecDC *src, struct RecDC *dest);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern void *MAIL_Create(int heapId);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void G3X_SetFog(int, int, int, int);
extern void G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);
int SHINKA_DEMO_Create(void *owner,int unused,u8 *app);
int SHINKA_DEMO_Destroy(void *a, int unused, int b, int *p);
int SHINKA_DEMO_Main(int unused0,int unused1,char *a,char *s);
void SHINKA_DEMO_SetupScene(App *a, Scene *s);
void SHINKA_DEMO_DeleteScene(int a, int *p);
void SHINKA_DEMO_StartBgm(u8 *p, u8 *q);
void SHINKA_DEMO_Noop(int unused0, int *unused1);
void SHINKA_DEMO_UpdateBgm(char *a, char *b);
int SHINKA_DEMO_IsBgmState1(int a, int *p);
void SHINKA_DEMO_RestoreBgm(char *a, char *b);
void SHINKA_DEMO_PlayEvolutionBgm(int a, int *p);
int SHINKA_DEMO_IsBgmState2(int a, int *p);
void SHINKA_DEMO_StartEvolutionBgm(int unused, char *p);
void SHINKA_DEMO_PushBgm(int a, int *b);
void SHINKA_DEMO_PopBgm(int a, int *p);
int SHINKA_DEMO_IsBgmState4(int a, int *p);
void SHINKA_DEMO_FadeOutBgm(int a, char *b);
int SHINKA_DEMO_IsBgmState6(int a, char *b);
void SHINKA_DEMO_StartResultBgm(int a, int *p);
int SHINKA_DEMO_IsBgmState7Or8(int a, int *p);
void SHINKA_DEMO_PlayResultBgm(int a, int *p);
void SHINKA_DEMO_StopBgm(int a, char *b);
void SHINKA_DEMO_LoadSprites(int a, char *b);
void SHINKA_DEMO_Noop2(int unused0, int *unused1);
void SHINKA_DEMO_CreateActors(int a, char *b);
void SHINKA_DEMO_DeleteActors(void *unused,char *p);
void SHINKA_DEMO_ResetActorAnims(int a, int *p);
int SHINKA_DEMO_AreActorAnimsDone(int a, int *p);
void SHINKA_DEMO_MainTask(int task, char *p);
void SHINKA_DEMO_SetupWindows(int a, char *b);
void SHINKA_DEMO_DeleteWindows(int task, int *p);
void SHINKA_DEMO_UpdateWindows(int a, char *b);
int SHINKA_DEMO_PrintStreamCallback(int a);
void SHINKA_DEMO_PrintText(char *a, u32 b, u32 c, u32 d, u32 k0, u32 v0, u32 k1, u32 v1);
int SHINKA_DEMO_AdvanceText(char *a);
int SHINKA_DEMO_IsConfirmPressed(char *s);
void SHINKA_DEMO_ClearText(char *a, int b);
void SHINKA_DEMO_SetupMessageBox(int a, int *p, int flag);
void SHINKA_DEMO_CreateConfirmMenu(int a, char *b);
void SHINKA_DEMO_DeleteConfirmMenu(void *unused,char *p);
void SHINKA_DEMO_SetMenuText(char *a, u32 msgBankC, u32 msgIdC, u32 k0, u32 v0, u32 k1, u32 v1, u32 b1, u32 b2, u32 m0, u32 w0, u32 m1, u32 w1);
u32 SHINKA_DEMO_BuildString(u32 heap, u32 a, u32 b, u32 k0, u32 v0, u32 k1, u32 v1);
void SHINKA_DEMO_AddShedinja(u32 *a, char *b);
void SHINKA_DEMO_ClearHeldItem(int a, char *b);
void SHINKA_DEMO_Setup3d(void);
extern const char d_02208F40[];
extern u8 gPokeStatusProcData[];
extern const char ov131_id[];
extern const char ov196_id[];
extern const char ov198_id[];
extern u8 ov067_id[];
extern u8 d_02208C4C[];
extern u32 gSpeciesNameBank;
extern u8 d_02208CCC[];




/*
 * ABI: 0203159C and 02031324 own files return void; caller consumes r0.
 * ABI: 02031324 also receives the heap in r0, preserved in this extern.
 */
int SHINKA_DEMO_Create(void *owner,int unused,u8 *app)
{
    char *p;
    GFL_HEAP_CreateChildHeap(1,0x94,0x10000);
    p=PROCSYS_AllocProcWork(owner,0x120,0x94);
    MI_CpuFill8(p,0,0x120);
    ((struct Scene *)p)->mainHeap=0x94;
    ((struct Scene *)p)->state=0;
    ((struct Scene *)p)->timer=5;
    ((struct Scene *)p)->bgmState=0;
    ((struct Scene *)p)->partyMon=POKEPARTY_GetMember(((struct App *)app)->party,app[0xa]);
    *(struct U16Vec * *)&((struct Scene *)p)->strbuf=STRBUF_Create(0x100,((struct Scene *)p)->mainHeap);
    POKE_TOOL_GetPartyValue(((struct Scene *)p)->partyMon,0x73,*(u32 *)&((struct Scene *)p)->strbuf);
    ((struct Scene *)p)->secondForm=0;
    ((struct Scene *)p)->ctx=0;
    ((struct Scene *)p)->heapBlock=0;
    ((struct Scene *)p)->palAnm=0;
    ((struct Scene *)p)->bgFlag=0;
    ((struct Scene *)p)->procData=GFL_HEAP_Alloc(((struct Scene *)p)->mainHeap,0x28,1,d_02208F40,0x242);
    FADE_Start(3,16,16,-16);
    SHINKA_DEMO_StartBgm(app,(u8 *)p);
    ((struct Scene *)p)->task=GFL_USE_AddMainTask((u32)SHINKA_DEMO_MainTask,(u32)p,1);
    ((struct Scene *)p)->flag10C=0;
    ((struct Scene *)p)->flag110=0;
    ((struct Scene *)p)->flag114=0;
    ((struct Scene *)p)->flag118=0;
    ((struct Scene *)p)->proc=(unsigned int)PROCSYS_Create(((struct Scene *)p)->mainHeap);
    SHINKA_DEMO_SetupScene((App *)((struct App *)app), (Scene *)((struct Scene *)p));
    GFL_NET_RefreshWmIconAtTopRight(0,((struct Scene *)p)->mainHeap);
    return 1;
}




/*
 * Padding: two zero bytes at 0x022040DE, then a function prologue.
 */
int SHINKA_DEMO_Destroy(void *a, int unused, int b, int *scene)
{
    SHINKA_DEMO_DeleteScene(b, scene);
    PROCSYS_Delete(*(void * *)&((struct Scene *)scene)->proc);
    TCB_DeleteTask(*(struct Node * *)&((struct Scene *)scene)->task);
    SHINKA_DEMO_Noop(b, scene);
    GFL_HEAP_Free(((struct Scene *)scene)->procData);
    STRBUF_Delete(*(struct U16Vec * *)&((struct Scene *)scene)->strbuf);
    PROCSYS_FreeProcWork(a);
    GFL_HEAP_DeleteChecked(0x94);
    return 1;
}



/*
 * note: 2026-10-05 wave P23 closed EXACT*. Case 34 also calls SHINKA_DEMO_PlayResultBgm(a,s) after SHINKA_DEMO_PrintText (same as case 18), so the tails cross-jump into case 18's copy; case 39 reads W(0x90) into a local once for both SHINKA_DEMO_SetMenuText arguments (ldr before the s+0x1c add). Older 5-byte DIFF came from those two points.
 * checks: 1 fresh own callee definitions and same-overlay callers confirm arities; unit355C4 setteru8 widened tou32 because caller sends only0/1 without truncation; caller-loaded forwarder args and272A4 wide-r1 payload preserved; 2 matched03FA0/05384/055BC/056E8 and loader twins read; 3 u16 keys (only bit2 used) regresses699, a/s writable so no const; 4 Boolean call/inline-wrapper and flag-ternary idioms read; 5 fresh unfiltered idioms and04DE0/04FC4/math neighbours.
 * extent: 02204B66 and 02204BB2 are internal shared tails; true end 02204C24 (2884B).
 */
int SHINKA_DEMO_Main(int unused0,int unused1,char *a,char *s)
{
    u32 tick,keys,result;
    u8 *q;
    void *v;
    tick=PROCSYS_Main(P(0x11c));if(tick==1)return 0;
    switch(W(0x28)){
    case 0:if(W(0x2c)==0){W(0x28)=1;FADE_Start(3,16,0,-16);}else W(0x2c)--;break;
    case 1:if(!FADE_IsActive()){W(0x28)=2;SHINKA_DEMO_ResetActorAnims((int)a,(int *)s);}break;
    case 2:if(!SHINKA_DEMO_IsBgmState1((int)a,(int *)s)&&SHINKA_DEMO_AreActorAnimsDone((int)a,(int *)s)){if(W(0x8c))W(0x28)=4;else{W(0x28)=3;SHINKA_DEMO_SetupMessageBox((int)a,(int *)s,1);}}break;
    case 3:W(0x88)=1;W(0x28)=4;break;
    case 4:SHINKA_DEMO_PrintText(s,W(0x78),0,0,2,W(0x10),4,0);W(0x28)=5;break;
    case 5:if(SHINKA_DEMO_AdvanceText(s)&&SHINKA_DEMO_IsConfirmPressed(s)){SHINKA_DEMO_SetupMessageBox((int)a,(int *)s,0);W(0x28)=6;SHINKA_DEMO_VIEW_RequestStart(P(0x104));}break;
    case 6:if(SHINKA_DEMO_VIEW_IsStartDone(P(0x104))){W(0x28)=7;SHINKA_DEMO_PlayEvolutionBgm((int)a,(int *)s);}break;
    case 7:if(!SHINKA_DEMO_IsBgmState2((int)a,(int *)s)){W(0x28)=8;SHINKA_DEMO_VIEW_RequestConfirm(P(0x104));SHINKA_DEMO_EFFECT_StartIntro(P(0x108));GFL_USE_PlaySeDefaultVolume(0x7dc);W(0x10c)=1;W(0x2c)=0;}break;
    case 8:
        keys=KEY_GetTrg();
        if(SHINKA_DEMO_VIEW_IsEvolveReady(P(0x104))){if(W(0x24))W(0x28)=13;else W(0x28)=9;break;}
        if(SHINKA_DEMO_VIEW_IsEvolveStarted(P(0x104)))SHINKA_DEMO_StartEvolutionBgm((int)a,s);
        if(SHINKA_DEMO_VIEW_IsEvolveDone(P(0x104)))SHINKA_DEMO_PushBgm((int)a,(int *)s);
        if(SHINKA_DEMO_VIEW_IsConfirmDone(P(0x104))){SHINKA_DEMO_EFFECT_AdvanceState(P(0x108));if(!W(0x110)){GFL_USE_PlaySeDefaultVolume(0x7df);W(0x10c)=0;W(0x110)=1;}}
        if(SHINKA_DEMO_EFFECT_IsState4(P(0x108)))SHINKA_DEMO_VIEW_RequestEvolve(P(0x104));
        if(SHINKA_DEMO_EFFECT_IsCameraReady(P(0x108))){SHINKA_DEMO_VIEW_RequestFadeOut(P(0x104));if(!W(0x114)){if(!W(0x24))W(0x10c)=1;W(0x114)=1;}}
        if(W(0x10c)){
            if(!W(0x118)&&W(0x2c)>=90){if(SHINKA_DEMO_IsBgmState4((int)a,(int *)s)){GFL_USE_PlaySeDefaultVolume(0x7dd);W(0x118)=1;}}
            else if(W(0x2c)==0x212||W(0x2c)==0x249||W(0x2c)==0x280||W(0x2c)==0x2b7)GFL_USE_PlaySeDefaultVolume(0x7de);
            else if(W(0x2c)==0x2e4)GFL_USE_PlaySeDefaultVolume(0x7e0);
            W(0x2c)++;
        }
        if(A(0x10)&&SHINKA_DEMO_IsBgmState4((int)a,(int *)s)&&!W(0x24)&&(keys&2)&&SHINKA_DEMO_VIEW_TrySecondForm(P(0x104))){W(0x24)=1;UI_SetInputMode(0);SHINKA_DEMO_EFFECT_Trigger(P(0x108));}break;
    case 9:
        POKE_TOOL_ChangeSpecies(P(0x10),AH(8));
        if(A(0)){v=ZUKAN_SAVE_GetFromGameData((void *)A(0));ZUKAN_SAVE_RegisterSeen(v,P(0x10));ZUKAN_SAVE_RegisterCaught(v,P(0x10));}
        SHINKA_DEMO_StartResultBgm((int)a,(int *)s);if(W(0x8c))W(0x28)=11;else{SHINKA_DEMO_SetupMessageBox((int)a,(int *)s,1);W(0x28)=10;}break;
    case 10:W(0x88)=1;W(0x28)=11;break;
    case 11:SHINKA_DEMO_PrintText(s,W(0x78),2,0,0,W(0x14),1,W(0x10));W(0x28)=12;break;
    case 12:if(SHINKA_DEMO_AdvanceText(s)&&!SHINKA_DEMO_IsBgmState7Or8((int)a,(int *)s)&&SHINKA_DEMO_IsConfirmPressed(s)){GAME_BEACON_SetPokeEvolution((u16)POKE_TOOL_GetPartyValue(P(0x10),5,0),W(0x14));v=GAME_DATA_GetTrainerRecord((void *)A(0));RECORD_AddOne(v,10);RECORD_AddOne(v,88);W(0x28)=17;}break;
    case 13:if(W(0x24))SHINKA_DEMO_StopBgm((int)a,s);else SHINKA_DEMO_PopBgm((int)a,(int *)s);if(W(0x8c))W(0x28)=15;else{SHINKA_DEMO_SetupMessageBox((int)a,(int *)s,1);W(0x28)=14;}break;
    case 14:W(0x88)=1;W(0x28)=15;break;
    case 15:SHINKA_DEMO_PrintText(s,W(0x78),1,0,2,W(0x10),4,0);W(0x28)=16;break;
    case 16:if(SHINKA_DEMO_AdvanceText(s)&&SHINKA_DEMO_IsConfirmPressed(s))W(0x28)=42;break;
    case 17:switch(AB(11)){case 14:SHINKA_DEMO_AddShedinja((u32 *)a,s);break;case 6:case 19:case 20:SHINKA_DEMO_ClearHeldItem((int)a,s);break;}W(0x28)=18;W(0x20)=0;break;
    case 18:
        H(0x1c)=POKE_TOOL_LearnLevelUpMove(P(0x10),(u32 *)(s+0x20),H(0));
        if(!H(0x1c))W(0x28)=42;else if(H(0x1c)!=0xfffe){if(H(0x1c)&0x8000){H(0x1c)&=0x7fff;W(0x28)=20;}else{W(0x28)=19;SHINKA_DEMO_PrintText(s,W(0x7c),3,0,2,W(0x10),3,(u32)(s+0x1c));SHINKA_DEMO_PlayResultBgm((int)a,(int *)s);}}break;
    case 19:if(SHINKA_DEMO_AdvanceText(s)&&SHINKA_DEMO_IsConfirmPressed(s))W(0x28)=18;break;
    case 20:W(0x28)=21;SHINKA_DEMO_PrintText(s,W(0x7c),4,0,2,W(0x10),3,(u32)(s+0x1c));break;
    case 21:if(SHINKA_DEMO_AdvanceText(s)){W(0x28)=22;SHINKA_DEMO_SetMenuText(s,W(0x90),2,4,0,4,0,W(0x90),3,4,0,4,0);YESNO_MENU_Start(P(0x9c),W(0x94),W(0x98));}break;
    case 22:
        result=YESNO_MENU_GetAnswer(P(0x9c));if(result==2)break;
        if(result==1){if(A(0xc)){W(0x28)=23;FADE_Start(3,0,16,0);}else{W(0x28)=27;FADE_Start(2,0,16,0);}}
        else if(!result)W(0x28)=36;
        YESNO_MENU_Close(P(0x9c));break;
    case 23:
        if(FADE_IsActive())break;
        SHINKA_DEMO_DeleteScene((int)a,(int *)s);W(0x28)=24;
        v=GAME_DATA_GetSaveControl((void *)A(0));
        ((u8 *)P(0x100))[0xc]=1;*(u32 *)((char *)P(0x100)+8)=A(0);*(u32 *)((char *)P(0x100)+0x24)=0;*(u32 *)P(0x100)=A(4);
        *(void **)((char *)P(0x100)+4)=SYSTEM_DATA_GetConfig(v);((u8 *)P(0x100))[0xe]=POKEPARTY_GetCount((void *)A(4));((u8 *)P(0x100))[0xf]=AB(0xa);*(u16 *)((char *)P(0x100)+0x14)=H(0x1c);
        ((u8 *)P(0x100))[0xd]=2;((u8 *)P(0x100))[0x10]=1;*(u32 *)((char *)P(0x100)+0x20)=0;
        GF_OVERLAY_Load((int)ov131_id);PROCSYS_Push(P(0x11c),-1,gPokeStatusProcData,P(0x100));break;
    case 24:if(tick!=1)W(0x28)=25;else return 0;break;
    case 25:GF_OVERLAY_Unload((int)ov131_id);W(0x28)=26;SHINKA_DEMO_SetupScene((App *)((struct App *)a), (Scene *)((struct Scene *)s));GFL_NET_RefreshWmIconAtTopRight(0,H(0));FADE_Start(3,16,0,0);break;
    case 26:
        if(!FADE_IsActive()){q=P(0x100);switch(q[0x12]){case 0:result=q[0x11];B(0x1a)=result;H(0x18)=POKE_TOOL_GetPartyValue(P(0x10),result+0x36,0);W(0x28)=31;break;case 1:case 2:default:W(0x28)=36;break;}}break;
    case 27:
        if(FADE_IsActive())break;
        W(0x28)=28;YESNO_MENU_Delete(P(0x9c));W(0x9c)=0;SHINKA_DEMO_GRAPHIC_ReleaseSubBg((int)P(4));B(0xac)=UI_GetInputMode()==0;
        P(0xa4)=GFL_HEAP_Alloc(H(0),TCB_GetTaskOffset(8),0,(char *)d_02208F40,0x548);
        MI_CpuFill8(P(0xa4),0,TCB_GetTaskOffset(8));P(0xa0)=TCB_Init(8,P(0xa4));P(0xa8)=PALANM_Create(H(0));PALANM_SetAutoTransfer(P(0xa8),1);
        PALANM_AllocSlotBuffers(P(0xa8),1,0x1e0,H(0));PALANM_AllocSlotBuffers(P(0xa8),3,0x1e0,H(0));
        W(0xb0)=A(0);W(0xb4)=A(4);W(0xbc)=W(8);H(0xc0)=H(0);B(0xcf)=4;B(0xfc)=0;B(0xd0)=AB(0xa);H(0xd6)=H(0x1c);W(0xc4)=0;P(0xf4)=s+0xac;W(0xd8)=W(0xa0);W(0xdc)=W(0xa8);W(0xf0)=1;
        GF_OVERLAY_Load((int)ov196_id);GF_OVERLAY_Load((int)ov198_id);B_PLIST_MAIN_Create((u8 *)(s+0xb0));FADE_Start(2,16,0,0);break;
    case 28:TCB_Main(P(0xa0));if(B(0xfc)){W(0x28)=29;FADE_Start(2,0,16,0);}break;
    case 29:
        if(FADE_IsActive())break;
        W(0x28)=30;GF_OVERLAY_Unload((int)ov196_id);GF_OVERLAY_Unload((int)ov198_id);PALANM_FreeSlotBuffers(P(0xa8),1);PALANM_FreeSlotBuffers(P(0xa8),3);PALANM_Delete(P(0xa8));TCB_Noop(P(0xa0));GFL_HEAP_Free(P(0xa4));W(0xa0)=0;W(0xa4)=0;W(0xa8)=0;
        SHINKA_DEMO_GRAPHIC_SetupSubBg(P(4));P(0x9c)=YESNO_MENU_Create(H(0),5,0,1,0,SHINKA_DEMO_GRAPHIC_GetCamera(P(4)),W(8),W(0xc),0);GFL_NET_RefreshWmIconAtTopRight(0,H(0));FADE_Start(2,16,0,0);break;
    case 30:
        if(FADE_IsActive())break;
        B(0x1a)=B(0xfb);if(B(0x1a)==4)W(0x28)=36;else{H(0x18)=POKE_TOOL_GetPartyValue(P(0x10),B(0x1a)+0x36,0);W(0x28)=31;}
        UI_SetInputMode(B(0xac)?0:1);break;
    case 31:if(W(0x8c))W(0x28)=33;else{W(0x28)=32;SHINKA_DEMO_SetupMessageBox((int)a,(int *)s,1);}break;
    case 32:W(0x88)=1;W(0x28)=33;break;
    case 33:SHINKA_DEMO_PrintText(s,W(0x7c),5,(u32)SHINKA_DEMO_PrintStreamCallback,2,W(0x10),3,(u32)(s+0x18));W(0x28)=34;break;
    case 34:if(SHINKA_DEMO_AdvanceText(s)){POKE_TOOL_SetMoveSlot(P(0x10),H(0x1c),B(0x1a));W(0x28)=35;SHINKA_DEMO_PrintText(s,W(0x7c),6,0,2,W(0x10),3,(u32)(s+0x1c));SHINKA_DEMO_PlayResultBgm((int)a,(int *)s);}break;
    case 35:if(SHINKA_DEMO_AdvanceText(s))W(0x28)=18;break;
    case 36:if(W(0x8c))W(0x28)=38;else{W(0x28)=37;SHINKA_DEMO_SetupMessageBox((int)a,(int *)s,1);}break;
    case 37:W(0x88)=1;W(0x28)=38;break;
    case 38:SHINKA_DEMO_PrintText(s,W(0x7c),7,0,4,0,3,(u32)(s+0x1c));W(0x28)=39;break;
    case 39:if(SHINKA_DEMO_AdvanceText(s)){W(0x28)=40;{u32 w=W(0x90);SHINKA_DEMO_SetMenuText(s,w,4,3,(u32)(s+0x1c),4,0,w,5,3,(u32)(s+0x1c),4,0);}YESNO_MENU_Start(P(0x9c),W(0x94),W(0x98));}break;
    case 40:
        result=YESNO_MENU_GetAnswer(P(0x9c));if(result==2)break;
        if(result==1){W(0x28)=41;SHINKA_DEMO_PrintText(s,W(0x7c),8,0,2,W(0x10),3,(u32)(s+0x1c));}else if(!result)W(0x28)=20;
        YESNO_MENU_Close(P(0x9c));break;
    case 41:if(SHINKA_DEMO_AdvanceText(s))W(0x28)=18;break;
    case 42:if(W(0x24)){FADE_Start(3,0,16,2);W(0x28)=43;}else if(SHINKA_DEMO_IsBgmState4((int)a,(int *)s)){SHINKA_DEMO_FadeOutBgm((int)a,s);FADE_Start(3,0,16,2);W(0x28)=43;}break;
    case 43:if(!SHINKA_DEMO_IsBgmState6((int)a,s)){W(0x28)=44;SHINKA_DEMO_RestoreBgm(a,s);}break;
    case 44:if(!FADE_IsActive()){W(0x28)=45;return 1;}break;
    case 45:return 1;
    }
    SHINKA_DEMO_UpdateBgm(a,s);
    if(W(0x28)!=24&&W(0x28)!=25){
        if(P(0x9c))YESNO_MENU_Update(P(0x9c));
        SHINKA_DEMO_UpdateWindows((int)a,s);PRINTSYS_QUE_Main(P(0xc));SHINKA_DEMO_VIEW_Main(P(0x104));SHINKA_DEMO_EFFECT_Main(P(0x108));SHINKA_DEMO_GRAPHIC_Draw(P(4));SHINKA_DEMO_GRAPHIC_Update(P(4));SHINKA_DEMO_EFFECT_Draw(P(0x108));SHINKA_DEMO_VIEW_Draw(P(0x104));SHINKA_DEMO_GRAPHIC_DrawEnd(P(4));
    }
    return 0;
}








void SHINKA_DEMO_SetupScene(App *a, Scene *s)
{
    u8 i;
    u8 b;

    GFL_HEAP_CreateChildHeap(1, 0x68, 0x70000);
    s->heap = 0x68;
    GF_OVERLAY_Load((u32)ov067_id);
    for (i = 0; i <= 7; i++)
        BG_SYS_SetPlaneVisible(i, 0);
    s->graphic = SHINKA_DEMO_GRAPHIC_Create(1, s->heap);
    SHINKA_DEMO_GRAPHIC_SetupSubBg();
    s->font = (u32)GF_FONT_Create(0x17, 0, 0, 0, s->heap);
    s->printQue = PRINTSYS_QUE_Create((void *)s->heap);
    SHINKA_DEMO_SetupWindows((int)a, (char *)s);
    s->yesNoMenu = 0;
    SHINKA_DEMO_CreateConfirmMenu((int)a, (char *)s);
    SHINKA_DEMO_LoadSprites((int)a, (char *)s);
    s->actorsReady = 0;
    if (s->state == 0)
        SHINKA_DEMO_CreateActors((int)a, (char *)s);
    BG_SYS_SetPriority(0, 2);
    BG_SYS_SetPriority(2, 1);
    BG_SYS_SetPriority(1, 0);
    BG_SYS_SetPriority(4, 2);
    BG_SYS_SetPlaneVisible(0, 1);
    BG_SYS_SetPlaneVisible(2, 1);
    BG_SYS_SetPlaneVisible(4, 1);
    BG_SYS_LoadPlttEntry(0, 0);
    BG_SYS_LoadPlttEntry(4, 0);
    if (s->state == 0) {
        b = a->f0b;
        if (b == 8 || (u8)(b + 0xef) <= 1)
            a->f10 = 0;
    }
    if (s->state == 0)
        s->view = SHINKA_DEMO_VIEW_Create(s->heap, 0, s->partyMon, a->f08);
    else
        s->view = SHINKA_DEMO_VIEW_Create(s->heap, 1, s->partyMon, a->f08);
    if (s->state == 0)
        s->effect = SHINKA_DEMO_EFFECT_Create(s->heap, 0);
    else
        s->effect = SHINKA_DEMO_EFFECT_Create(s->heap, 1);
    G2x_SetBlendAlpha_(0x04000050, 1, 0x3e, 0, 0);
}








/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: the scene object's teardown.
 * It releases the two +0x104/+0x108 sub-objects, tears the controller links
 * down, then frees the +0x0c/+0x08/+0x04 allocations and drops the 0x43 /
 * 0x68 pools.
 */
void SHINKA_DEMO_DeleteScene(int unused, int *scene)
{
    SHINKA_DEMO_EFFECT_Destroy((char *)scene[0x42]);
    SHINKA_DEMO_VIEW_Destroy((char *)scene[0x41]);
    SHINKA_DEMO_DeleteActors((void *)unused, (char *)scene);
    SHINKA_DEMO_Noop2(unused, scene);
    SHINKA_DEMO_DeleteConfirmMenu((void *)unused, (char *)scene);
    SHINKA_DEMO_DeleteWindows(unused, scene);
    PRINTSYS_QUE_Clear((struct PrintSys *)scene[3]);
    PRINTSYS_QUE_Delete((struct PrintSys *)scene[3]);
    GF_FONT_Delete((void *)scene[2]);
    SHINKA_DEMO_GRAPHIC_ReleaseSubBg(scene[1]);
    SHINKA_DEMO_GRAPHIC_Destroy((char *)scene[1]);
    GF_OVERLAY_Unload((int)ov067_id);
    GFL_HEAP_DeleteChecked(0x68);
}








/*
 * Addresses are Black-image addresses.
 */
void SHINKA_DEMO_StartBgm(u8 *app, u8 *scene)
{
    if (((struct App *)app)->flag0C != 0) {
        GFL_USE_FadeOutBgm(0x1e);
    }
    ((struct Scene *)scene)->bgmState = 1;
}







void SHINKA_DEMO_Noop(int unused0, int *unused1) {}








void SHINKA_DEMO_UpdateBgm(char *app, char *scene)
{
    switch (((struct Scene *)scene)->bgmState) {
    case 0:
        break;
    case 1:
        if (GFL_USE_IsBgmFading() == 0) {
            if (((struct App *)app)->flag0C != 0) {
                GFL_USE_SetBgmPaused((void *)1);
                GFL_USE_PushBgm();
            }
            ((struct Scene *)scene)->bgmState = 0;
        }
        break;
    case 2:
        if (GFL_USE_IsBgmPlaying() == 0)
            ((struct Scene *)scene)->bgmState = 0;
        break;
    case 3:
        if (GFL_USE_StepBgmLoad((u8 *)0x3f3, (u32 *)(scene + 0x34), 0) != 0)
            ((struct Scene *)scene)->bgmState = 4;
        break;
    case 4:
    case 5:
        break;
    case 6:
        if (GFL_USE_IsBgmFading() == 0) {
            GFL_USE_CancelChangeAndStopBgm();
            ((struct Scene *)scene)->bgmState = 0;
        }
        break;
    case 7:
        if (GFL_USE_StepBgmLoad((u8 *)0x519, (u32 *)(scene + 0x34), 0) != 0)
            ((struct Scene *)scene)->bgmState = 8;
        break;
    case 8:
        if (GFL_USE_IsBgmPlaying() == 0)
            SHINKA_DEMO_PopBgm((int)app, (int *)scene);
        break;
    case 9:
        if (GFL_USE_IsBgmPlaying() == 0)
            SHINKA_DEMO_PopBgm((int)app, (int *)scene);
        break;
    }
}







/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: true when the scene object's
 * state word +0x30 is 1.  Unlabelled in the listing (a leaf that saves no
 * lr), so region-qualified.
 */
int SHINKA_DEMO_IsBgmState1(int unused, int *scene)
{
    return scene[0xc] == 1;
}








void SHINKA_DEMO_RestoreBgm(char *app, char *scene)
{
    if (((struct Scene *)scene)->bgmState == 0 && ((struct App *)app)->flag0C != 0) {
        GFL_USE_PopBgm();
        GFL_USE_SetBgmPaused(0);
        GFL_USE_FadeInBgmFull(0x3c);
    }
}








/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: when the scene object sits in
 * state word +0x30 == 0, play cue 0x3f2 and move it to state 2.
 */
void SHINKA_DEMO_PlayEvolutionBgm(int unused, int *scene)
{
    if (scene[0xc] == 0) {
        GFL_USE_CancelChangeAndPlayBgm(0x3f2, 0xffff);
        scene[0xc] = 2;
    }
}






/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: true when the scene object's
 * state word +0x30 is 2.  Unlabelled in the listing (a leaf that saves no
 * lr), so region-qualified.
 */
int SHINKA_DEMO_IsBgmState2(int unused, int *scene)
{
    return scene[0xc] == 2;
}







void SHINKA_DEMO_StartEvolutionBgm(int unused, char *scene)
{
    if (((struct Scene *)scene)->bgmState == 0)
    {
        ((struct Scene *)scene)->bgmTimer = 0;
        GFL_USE_StepBgmLoad((void *)0x3f3, (u32 *)(scene + 0x34), 1);
        ((struct Scene *)scene)->bgmState = 3;
    }
}







void SHINKA_DEMO_PushBgm(int unused, int *scene)
{
    if (((struct Scene *)scene)->bgmState == 4) {
        GFL_USE_SetBgmPaused((void *)1);
        GFL_USE_PushBgm();
        ((struct Scene *)scene)->bgmState = 5;
    }
}







/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: when the scene object sits in
 * state 5 or in state 8/9, run the cue trio and drop it into state 4.
 */
void SHINKA_DEMO_PopBgm(int unused, int *scene)
{
    int s = scene[0xc];

    if (s == 5 || (unsigned)(s - 8) <= 1) {
        GFL_USE_PopBgm();
        GFL_USE_SetBgmPaused(0);
        GFL_USE_FadeInBgmFull(6);
        scene[0xc] = 4;
    }
}






/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: true when the scene object's
 * state word +0x30 is 4.  Unlabelled in the listing (a leaf that saves no
 * lr), so region-qualified.
 */
int SHINKA_DEMO_IsBgmState4(int unused, int *scene)
{
    return scene[0xc] == 4;
}







void SHINKA_DEMO_FadeOutBgm(int unused, char *scene)
{
    if (((struct Scene *)scene)->bgmState == 4) {
        GFL_USE_FadeOutBgm(0x3c);
        ((struct Scene *)scene)->bgmState = 6;
    }
}







int SHINKA_DEMO_IsBgmState6(int unused, char *scene)
{
    if (((struct Scene *)scene)->bgmState == 6)
        return 1;
    return 0;
}







/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: when the scene object sits in
 * state word +0x30 == 5, clear word +0x34, arm a 1-flag timer on it and move
 * to state 7.
 */
void SHINKA_DEMO_StartResultBgm(int unused, int *scene)
{
    if (scene[0xc] == 5) {
        scene[0xd] = 0;
        GFL_USE_StepBgmLoad((unsigned char *)0x519, (u32 *)(&scene[0xd]), 1);
        scene[0xc] = 7;
    }
}






/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: true when the scene object's
 * state word +0x30 is 7 or 8.
 */
int SHINKA_DEMO_IsBgmState7Or8(int unused, int *scene)
{
    return scene[0xc] == 7 || scene[0xc] == 8;
}







/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: when the scene object sits in
 * state word +0x30 == 4, hand it to SHINKA_DEMO_PushBgm and play cue 0x515, then
 * park it in state 9.  First argument is forwarded untouched.
 */
void SHINKA_DEMO_PlayResultBgm(int unused, int *scene)
{
    if (scene[0xc] == 4) {
        SHINKA_DEMO_PushBgm(unused, scene);
        GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
        scene[0xc] = 9;
    }
}







void SHINKA_DEMO_StopBgm(int unused, char *scene)
{
    if (((struct Scene *)scene)->bgmState == 5) {
        GFL_USE_PopBgm();
        GFL_USE_CancelChangeAndStopBgm();
        ((struct Scene *)scene)->bgmState = 0;
    }
}






void SHINKA_DEMO_LoadSprites(int unused, char *scene)
{
    void *h = ARC_TOOL_CreateHandle(0xb6, ((struct Scene *)scene)->heap);

    ARC_UTIL_UploadPaletteFromHandleWhole(h, 3, 0, 0, 0x20, ((struct Scene *)scene)->heap);
    ARC_UTIL_UploadBgCharFromHandle(h, 5, 2, 0, 0, 0, ((struct Scene *)scene)->heap);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 4, 2, 0, 0, 0, ((struct Scene *)scene)->heap);
    ARC_TOOL_DeleteHandle(h);
    BG_SYS_PushTile(2);
}





void SHINKA_DEMO_Noop2(int unused0, int *unused1) {}






void SHINKA_DEMO_CreateActors(int unused, char *scene)
{
    void *h;
    u8 i;
    int z;

    h = ARC_TOOL_CreateHandle(0xb6, ((struct Scene *)scene)->heap);
    i = 0;
    ((struct Scene *)scene)->palette = CLACT_RegisterPaletteEx(h, 3, 0, 0, i, 1, ((struct Scene *)scene)->heap);
    ((struct Scene *)scene)->character = CLACT_RegisterCharacter(h, 2, 0, 0, ((struct Scene *)scene)->heap);
    ((struct Scene *)scene)->cellAnim = CLACT_RegisterCellAnim(h, 1, 0, ((struct Scene *)scene)->heap);
    ARC_TOOL_DeleteHandle(h);
    for (z = i; i < 6; i++) {
        char *e = scene + i * 4;
        ((struct Scene *)scene)->actors[i] = (u32)CLACT_CreateActor((void *)SHINKA_DEMO_GRAPHIC_GetCamera((char *)(((struct Scene *)scene)->graphic)), ((struct Scene *)scene)->character, ((struct Scene *)scene)->palette,
                                           ((struct Scene *)scene)->cellAnim, d_02208C4C + i * 8, z, ((struct Scene *)scene)->heap);
        CLACT_SetActorAutoAnim((struct Obj *)((struct Scene *)scene)->actors[i], z);
    }
    ((struct Scene *)scene)->actorsReady = 1;
}





void SHINKA_DEMO_DeleteActors(void *unused,char *scene) {u8 i;if(((struct Scene *)scene)->actorsReady){for(i=0;i<6;i++)CLACT_DeleteActor((struct Obj *)(*(u32 *)(scene+0x48+i*4)));CLACT_ReleaseCellAnim(((struct Scene *)scene)->cellAnim);CLACT_ReleaseCharacter(((struct Scene *)scene)->character);CLACT_ReleasePalette(((struct Scene *)scene)->palette);((struct Scene *)scene)->actorsReady=0;}}






/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: when the scene object has the
 * +0x60 pointer set, tear down the six +0x48 handles.
 */
void SHINKA_DEMO_ResetActorAnims(int unused, int *scene)
{
    unsigned char i;

    if (scene[0x18] == 0)
        return;
    for (i = 0; i < 6; i++) {
        CLACT_SetActorAnimIndex(scene[0x12 + i], 0);
        CLACT_SetActorAutoAnim((struct Obj *)scene[0x12 + i], 1);
    }
}






/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: probe all six +0x48 handles;
 * if every one is idle, hand the scene object to SHINKA_DEMO_DeleteActors.  A missing
 * +0x60 pointer reports success without probing.
 */
int SHINKA_DEMO_AreActorAnimsDone(int unused, int *scene)
{
    unsigned char i;

    if (scene[0x18] != 0) {
        int ok = 1;

        for (i = 0; i < 6; i++) {
            if (CLACT_IsActorAnimActive((struct Actor *)scene[0x12 + i]) != 0) {
                ok = 0;
                break;
            }
        }
        if (ok)
            SHINKA_DEMO_DeleteActors((void *)unused, (char *)scene);
        return ok;
    }
    return 1;
}





/*
 * extent: 82 code bytes followed by two zero alignment bytes at 0x022051FA.
 */
void SHINKA_DEMO_MainTask(int task, char *scene)
{
    switch (((struct Scene *)scene)->windowState) {
    case 1:
        BG_SYS_SetPlaneVisible(1, 1);
        ((struct Scene *)scene)->subBgVisible = 1;
        ((struct Scene *)scene)->windowState = 0;
        break;
    case 2:
        BG_SYS_SetPlaneVisible(1, 0);
        ((struct Scene *)scene)->subBgVisible = 0;
        ((struct Scene *)scene)->windowState = 0;
        break;
    }
    if (((struct Scene *)scene)->palAnm)
        PALANM_TransferPalettes(((struct Scene *)scene)->palAnm);
}






void SHINKA_DEMO_SetupWindows(int unused, char *scene)
{
    u32 p;

    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x20, 0x20, ((struct Scene *)scene)->heap);
    ((struct Scene *)scene)->window = BMP_WIN_Create(1, 0, 0, 1, 1, 1, 0);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Scene *)scene)->window)), 0);
    BMP_WIN_TransferChars((struct Descriptor *)((struct Scene *)scene)->window);
    ((struct Scene *)scene)->menuWindow = BMP_WIN_Create(1, 1, 0x13, 0x1e, 4, 1, 1);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Scene *)scene)->menuWindow)), 0);
    p = ((struct Scene *)scene)->menuWindow;
    BMP_WIN_TransferChars((struct Descriptor *)p);
    BMP_WIN_MakeScreen((struct Cfg *)p);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct Descriptor *)p));
    ((struct Scene *)scene)->frameGfx = (u32)BMP_MENUWORK_LoadFrameGfx((void *)1, 2, 0, ((struct Scene *)scene)->heap);
    ((struct Scene *)scene)->msgBankA = MSGDATA_CreateFromArchive(0, 2, 0xac, ((struct Scene *)scene)->heap);
    ((struct Scene *)scene)->msgBankB = MSGDATA_CreateFromArchive(0, 2, 0xcc, ((struct Scene *)scene)->heap);
    ((struct Scene *)scene)->tcbl = (u32)TCBL_Create(((struct Scene *)scene)->heap, ((struct Scene *)scene)->heap, 1, 0);
    GF_FONT_SetTextColor(1, 2, 0xf);
    ((struct Scene *)scene)->strbufA = 0;
    ((struct Scene *)scene)->printStream = 0;
    ((struct Scene *)scene)->keyCursor = APP_KEYCURSOR_CreateDefault(0xf, 1, 1, ((struct Scene *)scene)->heap);
    ((struct Scene *)scene)->windowState = 0;
    BG_SYS_SetPlaneVisible(1, 0);
    ((struct Scene *)scene)->subBgVisible = 0;
}





void SHINKA_DEMO_DeleteWindows(int task, int *scene)
{
    APP_KEYCURSOR_Delete(((struct Scene *)scene)->keyCursor);
    if (((struct Scene *)scene)->printStream) PRINTSYS_PrintStreamDelete((struct Rec3 *)(((struct Scene *)scene)->printStream));
    TCBL_Destroy((void *)(((struct Scene *)scene)->tcbl));
    if (((struct Scene *)scene)->strbufA) STRBUF_Delete((struct U16Vec *)(((struct Scene *)scene)->strbufA));
    MSGDATA_Delete(((struct Scene *)scene)->msgBankA);
    MSGDATA_Delete(((struct Scene *)scene)->msgBankB);
    BG_SYS_FreeTileRun(1, (unsigned short)(((struct Scene *)scene)->frameGfx), (unsigned short)(((struct Scene *)scene)->frameGfx >> 16));
    BMP_WIN_Delete((struct Descriptor *)(((struct Scene *)scene)->menuWindow));
    BMP_WIN_Delete((struct Descriptor *)(((struct Scene *)scene)->window));
}






void SHINKA_DEMO_UpdateWindows(int unused, char *scene)
{
    TCBL_Main((struct Tcbl *)(((struct Scene *)scene)->tcbl));
    if (((struct Scene *)scene)->printStream != 0)
        APP_KEYCURSOR_Update((struct Ctx *)(((struct Scene *)scene)->keyCursor), (void *)(((struct Scene *)scene)->printStream), (void *)(((struct Scene *)scene)->menuWindow));
}






int SHINKA_DEMO_PrintStreamCallback(int a)
{
    switch (a) {
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x56b);
        break;
    case 5:
        return GFL_USE_IsAnySeBusy();
    }
    return 0;
}





void SHINKA_DEMO_PrintText(char *scene, u32 msgBank, u32 msgId, u32 callback, u32 kind0, u32 value0, u32 kind1, u32 value1)
{
    SHINKA_DEMO_ClearText(scene, 0xf);
    *(u32 *)&((struct Scene *)scene)->strbufA = SHINKA_DEMO_BuildString(((struct Scene *)scene)->heap, msgBank, msgId, kind0, value0, kind1, value1);
    *(u32 *)&((struct Scene *)scene)->printStream = (u32)PRINTSYS_PrintStreamCallBack(*(u32 *)&((struct Scene *)scene)->menuWindow, 0, 0, *(u32 *)&((struct Scene *)scene)->strbufA, ((struct Scene *)scene)->font,
                                       MSG_SPEED_GetWait(), ((struct Scene *)scene)->tcbl, 2, ((struct Scene *)scene)->heap, 0xf, callback);
}





/*
 * The `(x & 3) != 0 ? 0 : 1` call arguments must be written as an explicit
 * if/else. The ternary makes mwccarm pick the opposite branch polarity and
 * then colour the pointer r5/result r4 the other way; the if/else gives the
 * original pointer r4 / result r5 split and the shared return. See
 * docs/idioms/a-ternary-constant-call-argument-takes-the-opposite-branch-polarity.md.
 */
int SHINKA_DEMO_AdvanceText(char *scene)
{
    int r = 0;

    switch (PRINTSYS_PrintStreamGetState((void *)(((struct Scene *)scene)->printStream))) {
    case 0:
        if ((KEY_GetCont() & 3) != 0 || TOUCHPANEL_GetCont() != 0) {
            PRINTSYS_PrintStreamShortWait((struct Rec *)(((struct Scene *)scene)->printStream), 0);
            if ((KEY_GetCont() & 3) != 0)
                UI_SetInputMode(0);
            else
                UI_SetInputMode(1);
        }
        break;
    case 1:
        if ((KEY_GetTrg() & 3) != 0 || TOUCHPANEL_GetTrg() != 0) {
            GFL_USE_PlaySeDefaultVolume(0x547);
            PRINTSYS_PrintStreamReleasePause((void *)(((struct Scene *)scene)->printStream));
            if ((KEY_GetTrg() & 3) != 0)
                UI_SetInputMode(0);
            else
                UI_SetInputMode(1);
        }
        break;
    case 2:
        r = 1;
        break;
    }
    return r;
}





/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: a confirm gate.  True once the
 * action key is held (KEY_GetTrg & 3) or the touch probe fires; it hands
 * the pressed/released flag to UI_SetInputMode.  The two arms must be separate
 * call statements, not a selected value: only then does mwccarm tail-merge
 * them with the original's `beq`-to-true orientation.
 */
int SHINKA_DEMO_IsConfirmPressed(char *unused)
{
    if ((KEY_GetTrg() & 3) != 0 || TOUCHPANEL_GetTrg() != 0) {
        if ((KEY_GetTrg() & 3) != 0)
            UI_SetInputMode(0);
        else
            UI_SetInputMode(1);
        return 1;
    }
    return 0;
}




void SHINKA_DEMO_ClearText(char *scene, int fillColor)
{
    int p;

    BMP_Clear((struct CharBuf *)BMP_WIN_GetBmp((struct Descriptor *)((struct Scene *)scene)->menuWindow), fillColor);
    p = ((struct Scene *)scene)->menuWindow;
    BMP_WIN_TransferChars((struct Descriptor *)p);
    BMP_WIN_MakeScreen((struct Cfg *)p);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct Descriptor *)p));
    if (((struct Scene *)scene)->printStream != 0)
        PRINTSYS_PrintStreamDelete((struct Rec3 *)(((struct Scene *)scene)->printStream));
    if (((struct Scene *)scene)->strbufA != 0)
        STRBUF_Delete((struct U16Vec *)(((struct Scene *)scene)->strbufA));
    ((struct Scene *)scene)->printStream = 0;
    ((struct Scene *)scene)->strbufA = 0;
}





/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: either build the +0x6c render
 * node from the +0x74 id (and flush the +0x104/+0x108 stage), or arm the
 * +0x88 transition word with 2.
 */
void SHINKA_DEMO_SetupMessageBox(int unused, int *p, int flag)
{
    if (flag != 0) {
        int *q;

        BMP_MENUWORK_DrawWindow((void *)p[0x1b], 0, (unsigned short)p[0x1d], 2);
        BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)p[0x1b])), 0xf);
        q = (int *)p[0x1b];
        BMP_WIN_TransferChars((struct Descriptor *)q);
        BMP_WIN_MakeScreen((struct Cfg *)((int)q));
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)((int)q)));
    } else {
        p[0x22] = 2;
    }
}





void SHINKA_DEMO_CreateConfirmMenu(int unused, char *scene)
{
    ((struct Scene *)scene)->confirmMsgBank = (u32)MSGDATA_CreateFromArchive(0, 2, 0xe9, ((struct Scene *)scene)->heap);
    ((struct Scene *)scene)->yesNoMenu = (u32)YESNO_MENU_Create(((struct Scene *)scene)->heap, 5, 0, 1, 0, SHINKA_DEMO_GRAPHIC_GetCamera((char *)(((struct Scene *)scene)->graphic)),
                                       ((struct Scene *)scene)->font, ((struct Scene *)scene)->printQue, 0);
    ((struct Scene *)scene)->strbufC = 0;
    ((struct Scene *)scene)->strbufD = 0;
}



void SHINKA_DEMO_DeleteConfirmMenu(void *unused,char *scene) {YESNO_MENU_Delete(*(u8 * *)&((struct Scene *)scene)->yesNoMenu);*(u32 *)&((struct Scene *)scene)->yesNoMenu=0;if(((struct Scene *)scene)->strbufC)STRBUF_Delete((struct U16Vec *)(((struct Scene *)scene)->strbufC));if(((struct Scene *)scene)->strbufD)STRBUF_Delete((struct U16Vec *)(((struct Scene *)scene)->strbufD));MSGDATA_Delete(*(struct Rec * *)&((struct Scene *)scene)->confirmMsgBank);}




void SHINKA_DEMO_SetMenuText(char *scene, u32 msgBankC, u32 msgIdC, u32 kindC0, u32 valueC0, u32 kindC1, u32 valueC1,
                   u32 msgBankD, u32 msgIdD, u32 kindD0, u32 valueD0, u32 kindD1, u32 valueD1)
{
    if (((struct Scene *)scene)->strbufC != 0)
        STRBUF_Delete((struct U16Vec *)(((struct Scene *)scene)->strbufC));
    if (((struct Scene *)scene)->strbufD != 0)
        STRBUF_Delete((struct U16Vec *)(((struct Scene *)scene)->strbufD));
    ((struct Scene *)scene)->strbufC = SHINKA_DEMO_BuildString(((struct Scene *)scene)->heap, msgBankC, msgIdC, kindC0, valueC0, kindC1, valueC1);
    ((struct Scene *)scene)->strbufD = SHINKA_DEMO_BuildString(((struct Scene *)scene)->heap, msgBankD, msgIdD, kindD0, valueD0, kindD1, valueD1);
}




u32 SHINKA_DEMO_BuildString(u32 heap, u32 msgBank, u32 msgId, u32 kind0, u32 value0, u32 kind1, u32 value1)
{
    Param p[2];
    u32 src, w, r, i;
    int z;

    if (kind0 == 4 && kind1 == 4) {
        r = (u32)MSGDATA_AllocString((struct MsgBank *)msgBank, msgId);
    } else {
        src = (u32)MSGDATA_AllocString((struct MsgBank *)msgBank, msgId);
        w = (u32)WORDSET_CreateDefault(heap);
        p[0].kind = kind0;
        p[0].val = value0;
        p[1].kind = kind1;
        p[1].val = value1;
        for (i = 0, z = i; i < 2; i++) {
            switch (p[i].kind) {
            case 0:
                WORDSET_SetSlotTag((struct WordSet *)w, i, (const void *)p[i].val, z, 1, z);
                break;
            case 1:
                WORDSET_SetSlotMonSpeciesName((void *)w, i, (void *)p[i].val);
                break;
            case 2:
                WORDSET_SetSlotMonNickname((void *)w, i, (void *)p[i].val);
                break;
            case 3:
                WORDSET_SetSlotFromMsgCB((struct WordSet *)w, i, *(u16 *)p[i].val);
                break;
            }
        }
        r = (u32)STRBUF_Create(0x100, heap);
        WORDSET_CopyTaggedText((struct WordSet *)w, (void *)r, (void *)src);
        STRBUF_Delete((struct U16Vec *)src);
        WORDSET_Delete((struct WordSet *)w);
    }
    return r;
}




void SHINKA_DEMO_AddShedinja(u32 *app, char *scene)
{
    void *save;
    u32 p, q, v;
    int i;

    save = GAME_DATA_GetMyItem((const struct BigObj *)app[0]);
    if ((int)POKEPARTY_GetCount((void *)app[1]) >= (int)POKEPARTY_GetCapacity((void *)app[1]))
        return;
    if (MYITEM_SAVEDATA_HasItem(save, 4, 1, ((struct Scene *)scene)->mainHeap) == 0)
        return;
    p = (u32)GFL_HEAP_Alloc(((struct Scene *)scene)->mainHeap, POKE_TOOL_GetPartyParamSize(), 1, (const char *)d_02208F40, 0xaf5);
    POKE_TOOL_CopyPartyPokemon((const struct RecDC *)(((struct Scene *)scene)->partyMon), (struct RecDC *)p);
    POKE_TOOL_ChangeSpecies((void *)p, 0x124);
    POKE_TOOL_SetPartyValue((void *)p, 0x98, 4);
    POKE_TOOL_SetPartyValue((void *)p, 6, 0);
    POKE_TOOL_SetPartyValue((void *)p, 0xb, 0);
    for (i = 0x19; i < 0x36; i++)
        POKE_TOOL_SetPartyValue((void *)p, i, 0);
    for (i = 0x4d; i < 0x6d; i++)
        POKE_TOOL_SetPartyValue((void *)p, i, 0);
    for (i = 0x78; i < 0x8d; i++)
        POKE_TOOL_SetPartyValue((void *)p, i, 0);
    v = (u32)MSGDATA_AllocString((struct MsgBank *)gSpeciesNameBank, POKE_TOOL_GetPartyValue((void *)p, 5, 0));
    POKE_TOOL_SetPartyValue((void *)p, 0x73, v);
    STRBUF_Delete((struct U16Vec *)v);
    POKE_TOOL_SetPartyValue((void *)p, 0x9d, 0);
    v = (u32)MAIL_Create(((struct Scene *)scene)->mainHeap);
    POKE_TOOL_SetPartyValue((void *)p, 0xa7, v);
    GFL_HEAP_Free((void *)v);
    POKE_TOOL_SetPartyValue((void *)p, 0x9f, 0);
    POKEPARTY_Add((void *)app[1], (void *)p);
    MYITEM_SAVEDATA_RemoveItem(save, 4, 1, ((struct Scene *)scene)->mainHeap);
    GFL_HEAP_Free((void *)p);
    q = (u32)ZUKAN_SAVE_GetFromGameData((void *)app[0]);
    ZUKAN_SAVE_RegisterSeen((struct Blk37 *)q, (void *)p);
    ZUKAN_SAVE_RegisterCaught((struct Blk37 *)q, (void *)p);
    q = (u32)GAME_DATA_GetTrainerRecord((int *)app[0]);
    RECORD_AddOne((void *)q, 10);
    RECORD_AddOne((void *)q, 0x58);
}




void SHINKA_DEMO_ClearHeldItem(int unused, char *scene)
{
    POKE_TOOL_SetPartyValue((void *)(((struct Scene *)scene)->partyMon), 6, 0);
}




void SHINKA_DEMO_Setup3d(void)
{
    u32 i;

    BG_SYS_SetMainPlaneVisible(1, 1);
    REG_BG0CNT = REG_BG0CNT & ~3;
    REG_DISP3DCNT = (REG_DISP3DCNT & ~0x3002) | 2;
    REG_DISP3DCNT &= ~0x3010;
    REG_DISP3DCNT &= ~0x3004;
    REG_DISP3DCNT = (REG_DISP3DCNT & ~0x3000) | 8;
    REG_DISP3DCNT &= ~0x3020;
    G3X_SetFog(0, 0, 0, 0);
    i = 0;
    G3X_SetClearColor(0, 0, 0x7fff, 0x3f, i);
    REG_VIEWPORT = 0xbfff0000;
    for (; i < 4; i++)
        G3D_SYSTEM_SetLight((u8)i, (const u16 *)(d_02208CCC + i * 8));
    G3D_SYSTEM_SetSwapBuffersMode(1, 0);
}
