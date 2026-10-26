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

#define REG_BG0CNT     (*(volatile u16 *)REG_BG0CNT_ADDR)
#define REG_DISP3DCNT  (*(volatile u16 *)REG_DISP3DCNT_ADDR)
#define REG_VIEWPORT   (*(volatile u32 *)REG_VIEWPORT_ADDR)
struct U16Vec;
struct App;
struct Scene;
struct ShinkaDemoGraphicNode;
struct Anim;
struct Big;
struct Blk37;
struct Ctx;
struct Owner;
struct PaletteFade;
struct PrintSys;
struct YesNoMenu;
struct GfFont;
struct ClactActor;
struct ClactActor;
struct Descriptor;
struct Cfg;
struct Bmp;
struct MsgBank;
struct Tcbl;
struct Rec3;
struct TextPrinter;
struct WordSet;
struct BigObj;
struct RecDC;
struct Party;
struct PartyMon;
#include "../types.h"
#include "../sdk_ioreg.h"

#include "../ov198/b_plist_types.h"
#include "../ov131/p_status_types.h"
#include "../ov067/yesno_menu_types.h"
#include "../arm9/palanm.h"
#include "shinka_demo_graphic_shared_types.h"

typedef struct App {
    struct GameData *gameData;     /* 0x00 */
    void *party;      /* 0x04: party data */
    u16 evolvedSpecies;          /* 0x08 */
    u8 partyIndex;    /* 0x0a */
    u8 evoKind;           /* 0x0b */
    u32 flag0C;       /* 0x0c */
    u32 reserved10;          /* 0x10 */
} App;

typedef struct Scene {
    u16 mainHeap;              /* 0x000: 0x94 work heap */
    u16 heap;                  /* 0x002: 0x68 scene heap */
    ShinkaGraphic *graphic;    /* 0x004: SHINKA_DEMO_GRAPHIC context */
    struct GfFont *font;                  /* 0x008: GF_FONT handle */
    struct PrintQueue *printQue;          /* 0x00c: PRINTSYS queue */
    void *partyMon;            /* 0x010: party member the demo evolves */
    struct Strbuf *strbuf;     /* 0x014: name strbuf */
    u16 replacedMove;          /* 0x018: move the player picks to forget */
    u8 moveSlot;               /* 0x01a: slot of the move to replace */
    u8 pad1B;                  /* 0x01b */
    u16 learnMove;             /* 0x01c: move being learned */
    u16 pad1E;                 /* 0x01e */
    u32 learnIndex;            /* 0x020: level-up learn cursor */
    u32 secondForm;            /* 0x024: second-form requested flag */
    u32 state;                 /* 0x028: main state */
    u32 timer;                 /* 0x02c: state timer */
    u32 bgmState;              /* 0x030: BGM state machine */
    u32 bgmTimer;              /* 0x034: BGM load timer */
    void *task;                /* 0x038: main task handle */
    u32 character;             /* 0x03c: CLACT character handle */
    u32 palette;               /* 0x040: CLACT palette handle */
    u32 cellAnim;              /* 0x044: CLACT cell-anim handle */
    struct ClactActor *actors[6];             /* 0x048: actor handles */
    u32 actorsReady;           /* 0x060 */
    struct TextPrinter *printStream;          /* 0x064: PRINTSYS stream */
    void *tcbl;                /* 0x068: TCBL handle */
    struct BmpWin *menuWindow;            /* 0x06c: BMP menu window */
    struct BmpWin *window;                /* 0x070: BMP window */
    u32 frameGfx;              /* 0x074: loaded frame gfx handle */
    struct MsgBank *msgBankA;  /* 0x078: MSGDATA bank A */
    struct MsgBank *msgBankB;  /* 0x07c: MSGDATA bank B */
    struct Strbuf *strbufA;    /* 0x080: message strbuf */
    struct KeyCursor *keyCursor;          /* 0x084: APP_KEYCURSOR handle */
    u32 windowState;           /* 0x088: window transition state */
    u32 subBgVisible;          /* 0x08c: sub BG visible */
    struct MsgBank *confirmMsgBank;       /* 0x090: confirm menu MSGDATA bank */
    struct Strbuf *strbufC;    /* 0x094: confirm strbuf C */
    struct Strbuf *strbufD;    /* 0x098: confirm strbuf D */
    YesNoMenu *yesNoMenu;      /* 0x09c: YESNO_MENU handle */
    struct TcbSystem *ctx;     /* 0x0a0: TCB context */
    void *heapBlock;           /* 0x0a4: TCB heap block */
    PaletteFade *palAnm;       /* 0x0a8: PALANM handle */
    u8 bgFlag;                 /* 0x0ac */
    u8 padAD[3];               /* 0x0ad */
    struct B_PlistHost plistArg;          /* 0x0b0: argument of the party list screen */
    PStatusProcParam *procData;           /* 0x100: PROCSYS_Push payload */
    void *view;                /* 0x104: SHINKA_DEMO_VIEW object */
    void *effect;              /* 0x108: SHINKA_DEMO_EFFECT object */
    u32 flag10C;               /* 0x10c */
    u32 flag110;               /* 0x110 */
    u32 flag114;               /* 0x114 */
    u32 flag118;               /* 0x118 */
    struct ProcSys *proc;      /* 0x11c: PROCSYS child */
} Scene;

typedef struct {
    u32 kind;
    void *val;
} Param;

#include "../arm9/nns_g3d_anm_calc_types.h"
#include "../arm9/nns_g3d_anm_types.h"
#include "../sdk_nnsfnd.h"
#include "../arm9/gfl_heap.h"
struct Proc;
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
struct PokemonParam;
#include "../arm9/pokeparty.h"
struct Strbuf;
#include "../arm9/strbuf.h"
#include "../arm9/poke_tool.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/fade.h"
#include "../arm9/gfl_use.h"
#include "../arm9/net.h"
struct TcbTask;
#include "../arm9/tcb_list.h"
/* Original explicitly prepares all four registers, despite the current forwarding own source. */
struct RecordBlock;
#include "../arm9/system_data.h"
#include "../arm9/record.h"
#include "../arm9/zukan_save.h"
struct ZukanSave;
struct GameData;
struct SaveControl;
#include "../arm9/game_data.h"
struct PrintQueue;
#include "../arm9/printsys.h"
#include "../arm9/palanm.h"
/* palanm.h does not declare these yet */
/* palanm.h does not declare these yet */
/* Caller narrows only r0; r1 retains the full word, copied to the callee's u16 store. */
#include "../arm9/game_beacon.h"
struct TcbSystem;
#include "../arm9/gf_overlay.h"
#include "../arm9/ui.h"
#include "../arm9/key.h"
/* The DS code passes a ninth argument to YESNO_MENU_Create (the definition takes eight); the host build drops it. */
#ifdef __MWERKS__
#define YESNO_MENU_Create YESNO_MENU_Create_header
#endif
#include "../ov067/yesno_menu.h"
#ifdef __MWERKS__
#undef YESNO_MENU_Create
extern YesNoMenu *YESNO_MENU_Create(u16 heapId, u32 textBgLayer, u32 actorPriority, u32 plttSlot, u8 actorPlttSlot, void *actorSys, struct GfFont *font, struct PrintQueue *printer, int extra);
#endif
#include "../ov198/b_plist_main.h"
/* The DS code passes the work pointer to SHINKA_DEMO_GRAPHIC_SetupSubBg in one place (the definition takes no argument); the host build drops it. */
#ifdef __MWERKS__
#define SHINKA_DEMO_GRAPHIC_SetupSubBg SHINKA_DEMO_GRAPHIC_SetupSubBg_header
#endif
#include "shinka_demo_graphic.h"
#ifdef __MWERKS__
#undef SHINKA_DEMO_GRAPHIC_SetupSubBg
extern void SHINKA_DEMO_GRAPHIC_SetupSubBg();
#endif
#include "shinka_demo_view.h"
struct EffectModel;
#include "shinka_demo_effect.h"
#include "../arm9/bg_sys.h"
#include "../arm9/g2.h"
/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define WORDSET_CreateDefault WORDSET_CreateDefault_header
#endif
#include "../arm9/gf_font.h"
#ifdef __MWERKS__
#undef WORDSET_CreateDefault
extern struct WordSet * WORDSET_CreateDefault(u32);
#endif
#include "../arm9/arc_tool.h"
#include "../arm9/arc_util.h"
#include "../arm9/clact.h"
struct BmpWin;
#include "../arm9/bmp_win.h"
struct Bmp;
typedef short s16_p07;
/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define BMP_Clear BMP_Clear_header
#endif
#include "../arm9/bmp.h"
#ifdef __MWERKS__
#undef BMP_Clear
extern void BMP_Clear(struct Bmp *, int);
#endif
#include "../arm9/bmp_menuwork.h"
#include "../arm9/msgdata.h"
struct TcblSystem;
#include "../arm9/tcbl.h"
struct KeyCursor;
#include "../arm9/app_keycursor.h"
struct TextPrinter;
#include "../arm9/msg_speed.h"
#include "../arm9/touchpanel.h"
#include "../arm9/wordset.h"
struct MyItem;
#include "../arm9/myitem_savedata.h"
struct PartyPokemon;
struct Mail;
#include "../arm9/mail.h"
#include "../arm9/g3x.h"
struct G3dLight;
#include "../arm9/g3d_system.h"
int SHINKA_DEMO_Create(void *owner,int unused,App *app);
int SHINKA_DEMO_Destroy(void *a, int unused, App *b, Scene *p);
int SHINKA_DEMO_Main(int unused0,int unused1,App *a,Scene *s);
void SHINKA_DEMO_SetupScene(App *a, Scene *s);
void SHINKA_DEMO_DeleteScene(App *a, Scene *p);
void SHINKA_DEMO_StartBgm(App *p, Scene *q);
void SHINKA_DEMO_Noop(App *unused0, Scene *unused1);
void SHINKA_DEMO_UpdateBgm(App *a, Scene *b);
int SHINKA_DEMO_IsBgmState1(App *a, Scene *p);
void SHINKA_DEMO_RestoreBgm(App *a, Scene *b);
void SHINKA_DEMO_PlayEvolutionBgm(App *a, Scene *p);
int SHINKA_DEMO_IsBgmState2(App *a, Scene *p);
void SHINKA_DEMO_StartEvolutionBgm(App *unused, Scene *p);
void SHINKA_DEMO_PushBgm(App *a, Scene *b);
void SHINKA_DEMO_PopBgm(App *a, Scene *p);
int SHINKA_DEMO_IsBgmState4(App *a, Scene *p);
void SHINKA_DEMO_FadeOutBgm(App *a, Scene *b);
int SHINKA_DEMO_IsBgmState6(App *a, Scene *b);
void SHINKA_DEMO_StartResultBgm(App *a, Scene *p);
int SHINKA_DEMO_IsBgmState7Or8(App *a, Scene *p);
void SHINKA_DEMO_PlayResultBgm(App *a, Scene *p);
void SHINKA_DEMO_StopBgm(App *a, Scene *b);
void SHINKA_DEMO_LoadSprites(App *a, Scene *b);
void SHINKA_DEMO_Noop2(App *unused0, Scene *unused1);
void SHINKA_DEMO_CreateActors(App *a, Scene *b);
void SHINKA_DEMO_DeleteActors(App *unused,Scene *p);
void SHINKA_DEMO_ResetActorAnims(App *a, Scene *p);
int SHINKA_DEMO_AreActorAnimsDone(App *a, Scene *p);
void SHINKA_DEMO_MainTask(struct TcbTask *task, void *p);
void SHINKA_DEMO_SetupWindows(App *a, Scene *b);
void SHINKA_DEMO_DeleteWindows(App *task, Scene *p);
void SHINKA_DEMO_UpdateWindows(App *a, Scene *b);
int SHINKA_DEMO_PrintStreamCallback(int a);
#ifndef __MWERKS__
static u8 SHINKA_DEMO_PrintStreamCallbackU8(u32 a)
{
    return (u8)SHINKA_DEMO_PrintStreamCallback((int)a);
}
#endif
void SHINKA_DEMO_PrintText(Scene *a, struct MsgBank *b, u32 c, PrintCallback d, u32 k0, void *v0, u32 k1, void *v1);
int SHINKA_DEMO_AdvanceText(Scene *a);
int SHINKA_DEMO_IsConfirmPressed(Scene *s);
void SHINKA_DEMO_ClearText(Scene *a, int b);
void SHINKA_DEMO_SetupMessageBox(App *a, Scene *p, int flag);
void SHINKA_DEMO_CreateConfirmMenu(App *a, Scene *b);
void SHINKA_DEMO_DeleteConfirmMenu(App *unused,Scene *p);
void SHINKA_DEMO_SetMenuText(Scene *a, struct MsgBank *msgBankC, u32 msgIdC, u32 k0, void *v0, u32 k1, void *v1, struct MsgBank *b1, u32 b2, u32 m0, void *w0, u32 m1, void *w1);
struct Strbuf *SHINKA_DEMO_BuildString(u32 heap, struct MsgBank *a, u32 b, u32 k0, void *v0, u32 k1, void *v1);
void SHINKA_DEMO_AddShedinja(App *a, Scene *b);
void SHINKA_DEMO_ClearHeldItem(App *a, Scene *b);
void SHINKA_DEMO_Setup3d(void);
extern const char d_02208F40[];
extern u8 gPokeStatusProcData[];
extern const char ov131_id[];
extern const char ov196_id[];
extern const char ov198_id[];
extern u8 ov067_id[];
extern u8 d_02208C4C[];
extern struct MsgBank *gSpeciesNameBank;
extern u8 d_02208CCC[];

/*
 * ABI: 0203159C and 02031324 own files return void; caller consumes r0.
 * ABI: 02031324 also receives the heap in r0, preserved in this extern.
 */
int SHINKA_DEMO_Create(void *owner,int unused,App *app)
{
    Scene *p;
    GFL_HEAP_CreateChildHeap(1,0x94,0x10000);
    p=PROCSYS_AllocProcWork(owner,sizeof(*p),0x94);
    MI_CpuFill8(p,0,sizeof(*p));
    p->mainHeap=0x94;
    p->state=0;
    p->timer=5;
    p->bgmState=0;
    p->partyMon=POKEPARTY_GetMember(app->party,app->partyIndex);
    *(struct U16Vec * *)&p->strbuf=(struct U16Vec *)STRBUF_Create(0x100,p->mainHeap);
    POKE_TOOL_GetPartyValue(p->partyMon,0x73,*(u32 *)&p->strbuf);
    p->secondForm=0;
    p->ctx=0;
    p->heapBlock=0;
    p->palAnm=0;
    p->bgFlag=0;
    p->procData=GFL_HEAP_Alloc(p->mainHeap,sizeof(*p->procData),1,d_02208F40,0x242);
    FADE_Start(3,16,16,-16);
    SHINKA_DEMO_StartBgm(app,p);
    p->task=GFL_USE_AddMainTask(SHINKA_DEMO_MainTask, p,1);
    p->flag10C=0;
    p->flag110=0;
    p->flag114=0;
    p->flag118=0;
    p->proc=PROCSYS_Create(p->mainHeap);
    SHINKA_DEMO_SetupScene((App *)app, (Scene *)p);
    GFL_NET_RefreshWmIconAtTopRight(0,p->mainHeap);
    return 1;
}

/*
 * Padding: two zero bytes at 0x022040DE, then a function prologue.
 */
int SHINKA_DEMO_Destroy(void *a, int unused, App *b, Scene *scene)
{
    SHINKA_DEMO_DeleteScene(b, scene);
    PROCSYS_Delete(*(void * *)&scene->proc);
    TCB_DeleteTask((struct TcbTask *)(*(struct ShinkaDemoGraphicNode * *)&scene->task));
    SHINKA_DEMO_Noop(b, scene);
    GFL_HEAP_Free(scene->procData);
    STRBUF_Delete((struct Strbuf *)(*(struct U16Vec * *)&scene->strbuf));
    PROCSYS_FreeProcWork(a);
    GFL_HEAP_DeleteChecked(0x94);
    return 1;
}

/*
 * note: 2026-10-05 wave P23 closed EXACT*. Case 34 also calls SHINKA_DEMO_PlayResultBgm(a,s) after SHINKA_DEMO_PrintText (same as case 18), so the tails cross-jump into case 18's copy; case 39 reads s->confirmMsgBank into a local once for both SHINKA_DEMO_SetMenuText arguments (ldr before the s+0x1c add). Older 5-byte DIFF came from those two points.
 * checks: 1 fresh own callee definitions and same-overlay callers confirm arities; unit355C4 setteru8 widened tou32 because caller sends only0/1 without truncation; caller-loaded forwarder args and272A4 wide-r1 payload preserved; 2 matched03FA0/05384/055BC/056E8 and loader twins read; 3 u16 keys (only bit2 used) regresses699, a/s writable so no const; 4 Boolean call/inline-wrapper and flag-ternary idioms read; 5 fresh unfiltered idioms and04DE0/04FC4/math neighbours.
 * extent: 02204B66 and 02204BB2 are internal shared tails; true end 02204C24 (2884B).
 */
int SHINKA_DEMO_Main(int unused0,int unused1,App *a,Scene *s)
{
    u32 tick,keys,result;
    PStatusProcParam *q;
    void *v;
    tick=PROCSYS_Main(s->proc);if(tick==1)return 0;
    switch(s->state){
    case 0:if(s->timer==0){s->state=1;FADE_Start(3,16,0,-16);}else s->timer--;break;
    case 1:if(!FADE_IsActive()){s->state=2;SHINKA_DEMO_ResetActorAnims(a,s);}break;
    case 2:if(!SHINKA_DEMO_IsBgmState1(a,s)&&SHINKA_DEMO_AreActorAnimsDone(a,s)){if(s->subBgVisible)s->state=4;else{s->state=3;SHINKA_DEMO_SetupMessageBox(a,s,1);}}break;
    case 3:s->windowState=1;s->state=4;break;
    case 4:SHINKA_DEMO_PrintText(s,s->msgBankA,0,0,2,s->partyMon,4,0);s->state=5;break;
    case 5:if(SHINKA_DEMO_AdvanceText(s)&&SHINKA_DEMO_IsConfirmPressed(s)){SHINKA_DEMO_SetupMessageBox(a,s,0);s->state=6;SHINKA_DEMO_VIEW_RequestStart(s->view);}break;
    case 6:if(SHINKA_DEMO_VIEW_IsStartDone(s->view)){s->state=7;SHINKA_DEMO_PlayEvolutionBgm(a,s);}break;
    case 7:if(!SHINKA_DEMO_IsBgmState2(a,s)){s->state=8;SHINKA_DEMO_VIEW_RequestConfirm(s->view);SHINKA_DEMO_EFFECT_StartIntro(s->effect);GFL_USE_PlaySeDefaultVolume(0x7dc);s->flag10C=1;s->timer=0;}break;
    case 8:
        keys=KEY_GetTrg();
        if(SHINKA_DEMO_VIEW_IsEvolveReady(s->view)){if(s->secondForm)s->state=13;else s->state=9;break;}
        if(SHINKA_DEMO_VIEW_IsEvolveStarted(s->view))SHINKA_DEMO_StartEvolutionBgm(a,s);
        if(SHINKA_DEMO_VIEW_IsEvolveDone(s->view))SHINKA_DEMO_PushBgm(a,s);
        if(SHINKA_DEMO_VIEW_IsConfirmDone(s->view)){SHINKA_DEMO_EFFECT_AdvanceState(s->effect);if(!s->flag110){GFL_USE_PlaySeDefaultVolume(0x7df);s->flag10C=0;s->flag110=1;}}
        if(SHINKA_DEMO_EFFECT_IsState4(s->effect))SHINKA_DEMO_VIEW_RequestEvolve(s->view);
        if(SHINKA_DEMO_EFFECT_IsCameraReady(s->effect)){SHINKA_DEMO_VIEW_RequestFadeOut(s->view);if(!s->flag114){if(!s->secondForm)s->flag10C=1;s->flag114=1;}}
        if(s->flag10C){
            if(!s->flag118&&s->timer>=90){if(SHINKA_DEMO_IsBgmState4(a,s)){GFL_USE_PlaySeDefaultVolume(0x7dd);s->flag118=1;}}
            else if(s->timer==0x212||s->timer==0x249||s->timer==0x280||s->timer==0x2b7)GFL_USE_PlaySeDefaultVolume(0x7de);
            else if(s->timer==0x2e4)GFL_USE_PlaySeDefaultVolume(0x7e0);
            s->timer++;
        }
        if(a->reserved10&&SHINKA_DEMO_IsBgmState4(a,s)&&!s->secondForm&&(keys&2)&&SHINKA_DEMO_VIEW_TrySecondForm(s->view)){s->secondForm=1;UI_SetInputMode(0);SHINKA_DEMO_EFFECT_Trigger(s->effect);}break;
    case 9:
        POKE_TOOL_ChangeSpecies(s->partyMon,a->evolvedSpecies);
        if(a->gameData){v=ZUKAN_SAVE_GetFromGameData((void *)a->gameData);ZUKAN_SAVE_RegisterSeen(v,s->partyMon);ZUKAN_SAVE_RegisterCaught(v,s->partyMon);}
        SHINKA_DEMO_StartResultBgm(a,s);if(s->subBgVisible)s->state=11;else{SHINKA_DEMO_SetupMessageBox(a,s,1);s->state=10;}break;
    case 10:s->windowState=1;s->state=11;break;
    case 11:SHINKA_DEMO_PrintText(s,s->msgBankA,2,0,0,s->strbuf,1,s->partyMon);s->state=12;break;
    case 12:if(SHINKA_DEMO_AdvanceText(s)&&!SHINKA_DEMO_IsBgmState7Or8(a,s)&&SHINKA_DEMO_IsConfirmPressed(s)){GAME_BEACON_SetPokeEvolution((u16)POKE_TOOL_GetPartyValue(s->partyMon,5,0),(struct Strbuf *)(s->strbuf));v=GAME_DATA_GetTrainerRecord((void *)a->gameData);RECORD_AddOne(v,10);RECORD_AddOne(v,88);s->state=17;}break;
    case 13:if(s->secondForm)SHINKA_DEMO_StopBgm(a,s);else SHINKA_DEMO_PopBgm(a,s);if(s->subBgVisible)s->state=15;else{SHINKA_DEMO_SetupMessageBox(a,s,1);s->state=14;}break;
    case 14:s->windowState=1;s->state=15;break;
    case 15:SHINKA_DEMO_PrintText(s,s->msgBankA,1,0,2,s->partyMon,4,0);s->state=16;break;
    case 16:if(SHINKA_DEMO_AdvanceText(s)&&SHINKA_DEMO_IsConfirmPressed(s))s->state=42;break;
    case 17:switch(a->evoKind){case 14:SHINKA_DEMO_AddShedinja(a,s);break;case 6:case 19:case 20:SHINKA_DEMO_ClearHeldItem(a,s);break;}s->state=18;s->learnIndex=0;break;
    case 18:
        s->learnMove=POKE_TOOL_LearnLevelUpMove(s->partyMon,&s->learnIndex,s->mainHeap);
        if(!s->learnMove)s->state=42;else if(s->learnMove!=0xfffe){if(s->learnMove&0x8000){s->learnMove&=0x7fff;s->state=20;}else{s->state=19;SHINKA_DEMO_PrintText(s,s->msgBankB,3,0,2,s->partyMon,3,&s->learnMove);SHINKA_DEMO_PlayResultBgm(a,s);}}break;
    case 19:if(SHINKA_DEMO_AdvanceText(s)&&SHINKA_DEMO_IsConfirmPressed(s))s->state=18;break;
    case 20:s->state=21;SHINKA_DEMO_PrintText(s,s->msgBankB,4,0,2,s->partyMon,3,&s->learnMove);break;
    case 21:if(SHINKA_DEMO_AdvanceText(s)){s->state=22;SHINKA_DEMO_SetMenuText(s,s->confirmMsgBank,2,4,0,4,0,s->confirmMsgBank,3,4,0,4,0);YESNO_MENU_Start((YesNoMenu *)(s->yesNoMenu),(struct Strbuf *)(s->strbufC),(struct Strbuf *)(s->strbufD));}break;
    case 22:
        result=YESNO_MENU_GetAnswer(s->yesNoMenu);if(result==2)break;
        if(result==1){if(a->flag0C){s->state=23;FADE_Start(3,0,16,0);}else{s->state=27;FADE_Start(2,0,16,0);}}
        else if(!result)s->state=36;
        YESNO_MENU_Close(s->yesNoMenu);break;
    case 23:
        if(FADE_IsActive())break;
        SHINKA_DEMO_DeleteScene(a,s);s->state=24;
        v=GAME_DATA_GetSaveControl((void *)a->gameData);
        s->procData->ppt=1;s->procData->config=a->gameData;s->procData->forceExit=0;s->procData->ppd=a->party;
        s->procData->callerData=SYSTEM_DATA_GetConfig(v);s->procData->max=POKEPARTY_GetCount((void *)a->party);s->procData->pos=a->partyIndex;s->procData->newMove=s->learnMove;
        s->procData->mode=2;s->procData->page=1;s->procData->canUseButtons=0;
        GF_OVERLAY_Load((sptr)ov131_id);PROCSYS_Push(s->proc,-1,(const struct ProcData *)gPokeStatusProcData,s->procData);break;
    case 24:if(tick!=1)s->state=25;else return 0;break;
    case 25:GF_OVERLAY_Unload((sptr)ov131_id);s->state=26;SHINKA_DEMO_SetupScene((App *)a, (Scene *)s);GFL_NET_RefreshWmIconAtTopRight(0,s->mainHeap);FADE_Start(3,16,0,0);break;
    case 26:
        if(!FADE_IsActive()){q=s->procData;switch(q->retSel){case 0:result=q->retMovePos;s->moveSlot=result;s->replacedMove=POKE_TOOL_GetPartyValue(s->partyMon,result+0x36,0);s->state=31;break;case 1:case 2:default:s->state=36;break;}}break;
    case 27:
        if(FADE_IsActive())break;
        s->state=28;YESNO_MENU_Delete((YesNoMenu *)(s->yesNoMenu));s->yesNoMenu=0;SHINKA_DEMO_GRAPHIC_ReleaseSubBg((void *)(s->graphic));s->bgFlag=UI_GetInputMode()==0;
        s->heapBlock=GFL_HEAP_Alloc(s->mainHeap,TCB_GetTaskOffset(8),0,(char *)d_02208F40,0x548);
        MI_CpuFill8(s->heapBlock,0,TCB_GetTaskOffset(8));s->ctx=TCB_Init(8,s->heapBlock);s->palAnm=PALANM_Create(s->mainHeap);PALANM_SetAutoTransfer(s->palAnm,1);
        PALANM_AllocSlotBuffers(s->palAnm,1,0x1e0,s->mainHeap);PALANM_AllocSlotBuffers(s->palAnm,3,0x1e0,s->mainHeap);
        s->plistArg.gameData=a->gameData;s->plistArg.party=a->party;s->plistArg.font=s->font;s->plistArg.heapId=s->mainHeap;s->plistArg.listType=4;s->plistArg.done=0;s->plistArg.orderIndex=a->partyIndex;s->plistArg.moveId=s->learnMove;s->plistArg.rule=0;s->plistArg.syncFlagPtr=&s->bgFlag;s->plistArg.fadeContext=s->ctx;s->plistArg.palAnm=s->palAnm;s->plistArg.seEnabled=1;
        GF_OVERLAY_Load((sptr)ov196_id);GF_OVERLAY_Load((sptr)ov198_id);B_PLIST_MAIN_Create(&s->plistArg);FADE_Start(2,16,0,0);break;
    case 28:TCB_Main(s->ctx);if(s->plistArg.done){s->state=29;FADE_Start(2,0,16,0);}break;
    case 29:
        if(FADE_IsActive())break;
        s->state=30;GF_OVERLAY_Unload((sptr)ov196_id);GF_OVERLAY_Unload((sptr)ov198_id);PALANM_FreeSlotBuffers(s->palAnm,1);PALANM_FreeSlotBuffers(s->palAnm,3);PALANM_Delete(s->palAnm);TCB_Noop(s->ctx);GFL_HEAP_Free(s->heapBlock);s->ctx=0;s->heapBlock=0;s->palAnm=0;
#ifdef __MWERKS__
        SHINKA_DEMO_GRAPHIC_SetupSubBg(s->graphic);
#else
        SHINKA_DEMO_GRAPHIC_SetupSubBg();
#endif
#ifdef __MWERKS__
        s->yesNoMenu=YESNO_MENU_Create(s->mainHeap,5,0,1,0,(void *)(SHINKA_DEMO_GRAPHIC_GetCamera(s->graphic)),(struct GfFont *)s->font,(struct PrintQueue *)(s->printQue),0);
#else
        s->yesNoMenu=YESNO_MENU_Create(s->mainHeap,5,0,1,0,(void *)(SHINKA_DEMO_GRAPHIC_GetCamera(s->graphic)),(struct GfFont *)s->font,(struct PrintQueue *)(s->printQue));
#endif
        GFL_NET_RefreshWmIconAtTopRight(0,s->mainHeap);FADE_Start(2,16,0,0);break;
    case 30:
        if(FADE_IsActive())break;
        s->moveSlot=s->plistArg.order[3];if(s->moveSlot==4)s->state=36;else{s->replacedMove=POKE_TOOL_GetPartyValue(s->partyMon,s->moveSlot+0x36,0);s->state=31;}
        UI_SetInputMode(s->bgFlag?0:1);break;
    case 31:if(s->subBgVisible)s->state=33;else{s->state=32;SHINKA_DEMO_SetupMessageBox(a,s,1);}break;
    case 32:s->windowState=1;s->state=33;break;
#ifdef __MWERKS__
    case 33:SHINKA_DEMO_PrintText(s,s->msgBankB,5,(PrintCallback)SHINKA_DEMO_PrintStreamCallback,2,s->partyMon,3,&s->replacedMove);s->state=34;break;
#else
    case 33:SHINKA_DEMO_PrintText(s,s->msgBankB,5,SHINKA_DEMO_PrintStreamCallbackU8,2,s->partyMon,3,&s->replacedMove);s->state=34;break;
#endif
    case 34:if(SHINKA_DEMO_AdvanceText(s)){POKE_TOOL_SetMoveSlot(s->partyMon,s->learnMove,s->moveSlot);s->state=35;SHINKA_DEMO_PrintText(s,s->msgBankB,6,0,2,s->partyMon,3,&s->learnMove);SHINKA_DEMO_PlayResultBgm(a,s);}break;
    case 35:if(SHINKA_DEMO_AdvanceText(s))s->state=18;break;
    case 36:if(s->subBgVisible)s->state=38;else{s->state=37;SHINKA_DEMO_SetupMessageBox(a,s,1);}break;
    case 37:s->windowState=1;s->state=38;break;
    case 38:SHINKA_DEMO_PrintText(s,s->msgBankB,7,0,4,0,3,&s->learnMove);s->state=39;break;
    case 39:if(SHINKA_DEMO_AdvanceText(s)){s->state=40;{struct MsgBank *w=s->confirmMsgBank;SHINKA_DEMO_SetMenuText(s,w,4,3,&s->learnMove,4,0,w,5,3,&s->learnMove,4,0);}YESNO_MENU_Start((YesNoMenu *)(s->yesNoMenu),(struct Strbuf *)(s->strbufC),(struct Strbuf *)(s->strbufD));}break;
    case 40:
        result=YESNO_MENU_GetAnswer(s->yesNoMenu);if(result==2)break;
        if(result==1){s->state=41;SHINKA_DEMO_PrintText(s,s->msgBankB,8,0,2,s->partyMon,3,&s->learnMove);}else if(!result)s->state=20;
        YESNO_MENU_Close(s->yesNoMenu);break;
    case 41:if(SHINKA_DEMO_AdvanceText(s))s->state=18;break;
    case 42:if(s->secondForm){FADE_Start(3,0,16,2);s->state=43;}else if(SHINKA_DEMO_IsBgmState4(a,s)){SHINKA_DEMO_FadeOutBgm(a,s);FADE_Start(3,0,16,2);s->state=43;}break;
    case 43:if(!SHINKA_DEMO_IsBgmState6(a,s)){s->state=44;SHINKA_DEMO_RestoreBgm(a,s);}break;
    case 44:if(!FADE_IsActive()){s->state=45;return 1;}break;
    case 45:return 1;
    }
    SHINKA_DEMO_UpdateBgm(a,s);
    if(s->state!=24&&s->state!=25){
        if(s->yesNoMenu)YESNO_MENU_Update(s->yesNoMenu);
        SHINKA_DEMO_UpdateWindows(a,s);PRINTSYS_QUE_Main(s->printQue);SHINKA_DEMO_VIEW_Main(s->view);SHINKA_DEMO_EFFECT_Main(s->effect);SHINKA_DEMO_GRAPHIC_Draw(s->graphic);SHINKA_DEMO_GRAPHIC_Update(s->graphic);SHINKA_DEMO_EFFECT_Draw(s->effect);SHINKA_DEMO_VIEW_Draw(s->view);SHINKA_DEMO_GRAPHIC_DrawEnd(s->graphic);
    }
    return 0;
}

void SHINKA_DEMO_SetupScene(App *a, Scene *s)
{
    u8 i;
    u8 b;

    GFL_HEAP_CreateChildHeap(1, 0x68, 0x70000);
    s->heap = 0x68;
    GF_OVERLAY_Load((uptr)ov067_id);
    for (i = 0; i <= 7; i++)
        BG_SYS_SetPlaneVisible(i, 0);
    s->graphic = SHINKA_DEMO_GRAPHIC_Create(1, s->heap);
    SHINKA_DEMO_GRAPHIC_SetupSubBg();
    s->font = GF_FONT_Create(0x17, 0, 0, 0, s->heap);
    s->printQue = PRINTSYS_QUE_Create((unsigned int)s->heap);
    SHINKA_DEMO_SetupWindows(a,s);
    s->yesNoMenu = 0;
    SHINKA_DEMO_CreateConfirmMenu(a,s);
    SHINKA_DEMO_LoadSprites(a,s);
    s->actorsReady = 0;
    if (s->state == 0)
        SHINKA_DEMO_CreateActors(a,s);
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
        b = a->evoKind;
        if (b == 8 || (u8)(b + 0xef) <= 1)
            a->reserved10 = 0;
    }
    if (s->state == 0)
        s->view = SHINKA_DEMO_VIEW_Create(s->heap, 0, s->partyMon, a->evolvedSpecies);
    else
        s->view = SHINKA_DEMO_VIEW_Create(s->heap, 1, s->partyMon, a->evolvedSpecies);
    if (s->state == 0)
        s->effect = SHINKA_DEMO_EFFECT_Create(s->heap, 0);
    else
        s->effect = SHINKA_DEMO_EFFECT_Create(s->heap, 1);
    G2x_SetBlendAlpha_((unsigned int *)REG_BLDCNT_ADDR, 1, 0x3e, 0, 0);
}

/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: the scene object's teardown.
 * It releases the two +0x104/+0x108 sub-objects, tears the controller links
 * down, then frees the +0x0c/+0x08/+0x04 allocations and drops the 0x43 /
 * 0x68 pools.
 */
void SHINKA_DEMO_DeleteScene(App *unused, Scene *scene)
{
    SHINKA_DEMO_EFFECT_Destroy(scene->effect);
    SHINKA_DEMO_VIEW_Destroy(scene->view);
    SHINKA_DEMO_DeleteActors(unused, scene);
    SHINKA_DEMO_Noop2(unused, scene);
    SHINKA_DEMO_DeleteConfirmMenu(unused, scene);
    SHINKA_DEMO_DeleteWindows(unused, scene);
    PRINTSYS_QUE_Clear(scene->printQue);
    PRINTSYS_QUE_Delete(scene->printQue);
    GF_FONT_Delete(scene->font);
    SHINKA_DEMO_GRAPHIC_ReleaseSubBg(scene->graphic);
    SHINKA_DEMO_GRAPHIC_Destroy(scene->graphic);
    GF_OVERLAY_Unload((sptr)ov067_id);
    GFL_HEAP_DeleteChecked(0x68);
}

/*
 * Addresses are Black-image addresses.
 */
void SHINKA_DEMO_StartBgm(App *app, Scene *scene)
{
    if (app->flag0C != 0) {
        GFL_USE_FadeOutBgm(0x1e);
    }
    scene->bgmState = 1;
}

void SHINKA_DEMO_Noop(App *unused0, Scene *unused1) {}

void SHINKA_DEMO_UpdateBgm(App *app, Scene *scene)
{
    switch (scene->bgmState) {
    case 0:
        break;
    case 1:
        if (GFL_USE_IsBgmFading() == 0) {
            if (app->flag0C != 0) {
                GFL_USE_SetBgmPaused((unsigned int)1);
                GFL_USE_PushBgm();
            }
            scene->bgmState = 0;
        }
        break;
    case 2:
        if (GFL_USE_IsBgmPlaying() == 0)
            scene->bgmState = 0;
        break;
    case 3:
        if (GFL_USE_StepBgmLoad((unsigned int)0x3f3, &scene->bgmTimer, 0) != 0)
            scene->bgmState = 4;
        break;
    case 4:
    case 5:
        break;
    case 6:
        if (GFL_USE_IsBgmFading() == 0) {
            GFL_USE_CancelChangeAndStopBgm();
            scene->bgmState = 0;
        }
        break;
    case 7:
        if (GFL_USE_StepBgmLoad((unsigned int)0x519, &scene->bgmTimer, 0) != 0)
            scene->bgmState = 8;
        break;
    case 8:
        if (GFL_USE_IsBgmPlaying() == 0)
            SHINKA_DEMO_PopBgm(app, scene);
        break;
    case 9:
        if (GFL_USE_IsBgmPlaying() == 0)
            SHINKA_DEMO_PopBgm(app, scene);
        break;
    }
}

/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: true when the scene object's
 * state word +0x30 is 1.  Unlabelled in the listing (a leaf that saves no
 * lr), so region-qualified.
 */
int SHINKA_DEMO_IsBgmState1(App *unused, Scene *scene)
{
    return scene->bgmState == 1;
}

void SHINKA_DEMO_RestoreBgm(App *app, Scene *scene)
{
    if (scene->bgmState == 0 && app->flag0C != 0) {
        GFL_USE_PopBgm();
        GFL_USE_SetBgmPaused(0);
        GFL_USE_FadeInBgmFull(0x3c);
    }
}

/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: when the scene object sits in
 * state word +0x30 == 0, play cue 0x3f2 and move it to state 2.
 */
void SHINKA_DEMO_PlayEvolutionBgm(App *unused, Scene *scene)
{
    if (scene->bgmState == 0) {
        GFL_USE_CancelChangeAndPlayBgm(0x3f2, 0xffff);
        scene->bgmState = 2;
    }
}

/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: true when the scene object's
 * state word +0x30 is 2.  Unlabelled in the listing (a leaf that saves no
 * lr), so region-qualified.
 */
int SHINKA_DEMO_IsBgmState2(App *unused, Scene *scene)
{
    return scene->bgmState == 2;
}

void SHINKA_DEMO_StartEvolutionBgm(App *unused, Scene *scene)
{
    if (scene->bgmState == 0)
    {
        scene->bgmTimer = 0;
        GFL_USE_StepBgmLoad((unsigned int)0x3f3, &scene->bgmTimer, 1);
        scene->bgmState = 3;
    }
}

void SHINKA_DEMO_PushBgm(App *unused, Scene *scene)
{
    if (scene->bgmState == 4) {
        GFL_USE_SetBgmPaused((unsigned int)1);
        GFL_USE_PushBgm();
        scene->bgmState = 5;
    }
}

/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: when the scene object sits in
 * state 5 or in state 8/9, run the cue trio and drop it into state 4.
 */
void SHINKA_DEMO_PopBgm(App *unused, Scene *scene)
{
    int s = scene->bgmState;

    if (s == 5 || (unsigned)(s - 8) <= 1) {
        GFL_USE_PopBgm();
        GFL_USE_SetBgmPaused(0);
        GFL_USE_FadeInBgmFull(6);
        scene->bgmState = 4;
    }
}

/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: true when the scene object's
 * state word +0x30 is 4.  Unlabelled in the listing (a leaf that saves no
 * lr), so region-qualified.
 */
int SHINKA_DEMO_IsBgmState4(App *unused, Scene *scene)
{
    return scene->bgmState == 4;
}

void SHINKA_DEMO_FadeOutBgm(App *unused, Scene *scene)
{
    if (scene->bgmState == 4) {
        GFL_USE_FadeOutBgm(0x3c);
        scene->bgmState = 6;
    }
}

int SHINKA_DEMO_IsBgmState6(App *unused, Scene *scene)
{
    if (scene->bgmState == 6)
        return 1;
    return 0;
}

/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: when the scene object sits in
 * state word +0x30 == 5, clear word +0x34, arm a 1-flag timer on it and move
 * to state 7.
 */
void SHINKA_DEMO_StartResultBgm(App *unused, Scene *scene)
{
    if (scene->bgmState == 5) {
        scene->bgmTimer = 0;
        GFL_USE_StepBgmLoad((unsigned int)0x519, &scene->bgmTimer, 1);
        scene->bgmState = 7;
    }
}

/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: true when the scene object's
 * state word +0x30 is 7 or 8.
 */
int SHINKA_DEMO_IsBgmState7Or8(App *unused, Scene *scene)
{
    return scene->bgmState == 7 || scene->bgmState == 8;
}

/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: when the scene object sits in
 * state word +0x30 == 4, hand it to SHINKA_DEMO_PushBgm and play cue 0x515, then
 * park it in state 9.  First argument is forwarded untouched.
 */
void SHINKA_DEMO_PlayResultBgm(App *unused, Scene *scene)
{
    if (scene->bgmState == 4) {
        SHINKA_DEMO_PushBgm(unused, scene);
        GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
        scene->bgmState = 9;
    }
}

void SHINKA_DEMO_StopBgm(App *unused, Scene *scene)
{
    if (scene->bgmState == 5) {
        GFL_USE_PopBgm();
        GFL_USE_CancelChangeAndStopBgm();
        scene->bgmState = 0;
    }
}

void SHINKA_DEMO_LoadSprites(App *unused, Scene *scene)
{
    void *h = ARC_TOOL_CreateHandle(0xb6, scene->heap);

    ARC_UTIL_UploadPaletteFromHandleWhole(h, 3, 0, 0, 0x20, scene->heap);
    ARC_UTIL_UploadBgCharFromHandle(h, 5, 2, 0, 0, 0, scene->heap);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 4, 2, 0, 0, 0, scene->heap);
    ARC_TOOL_DeleteHandle(h);
    BG_SYS_PushTile(2);
}

void SHINKA_DEMO_Noop2(App *unused0, Scene *unused1) {}

void SHINKA_DEMO_CreateActors(App *unused, Scene *scene)
{
    void *h;
    u8 i;
    int z;

    h = ARC_TOOL_CreateHandle(0xb6, scene->heap);
    i = 0;
    scene->palette = CLACT_RegisterPaletteEx(h, 3, 0, 0, i, 1, scene->heap);
    scene->character = CLACT_RegisterCharacter(h, 2, 0, 0, scene->heap);
    scene->cellAnim = CLACT_RegisterCellAnim(h, 1, 0, scene->heap);
    ARC_TOOL_DeleteHandle(h);
    for (z = i; i < 6; i++) {
                scene->actors[i] = CLACT_CreateActor((struct Unit *)((void *)SHINKA_DEMO_GRAPHIC_GetCamera(scene->graphic)), scene->character, scene->palette,
                                           scene->cellAnim, (const struct ActorInitParam *)(d_02208C4C + i * 8), z, scene->heap);
        CLACT_SetActorAutoAnim(scene->actors[i], z);
    }
    scene->actorsReady = 1;
}

void SHINKA_DEMO_DeleteActors(App *unused,Scene *scene) {u8 i;if(scene->actorsReady){for(i=0;i<6;i++)CLACT_DeleteActor(scene->actors[i]);CLACT_ReleaseCellAnim(scene->cellAnim);CLACT_ReleaseCharacter(scene->character);CLACT_ReleasePalette(scene->palette);scene->actorsReady=0;}}

/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: when the scene object has the
 * +0x60 pointer set, tear down the six +0x48 handles.
 */
void SHINKA_DEMO_ResetActorAnims(App *unused, Scene *scene)
{
    unsigned char i;

    if (scene->actorsReady == 0)
        return;
    for (i = 0; i < 6; i++) {
        CLACT_SetActorAnimIndex(scene->actors[i], 0);
        CLACT_SetActorAutoAnim(scene->actors[i], 1);
    }
}

/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: probe all six +0x48 handles;
 * if every one is idle, hand the scene object to SHINKA_DEMO_DeleteActors.  A missing
 * +0x60 pointer reports success without probing.
 */
int SHINKA_DEMO_AreActorAnimsDone(App *unused, Scene *scene)
{
    unsigned char i;

    if (scene->actorsReady != 0) {
        int ok = 1;

        for (i = 0; i < 6; i++) {
            if (CLACT_IsActorAnimActive(scene->actors[i]) != 0) {
                ok = 0;
                break;
            }
        }
        if (ok)
            SHINKA_DEMO_DeleteActors(unused, scene);
        return ok;
    }
    return 1;
}

/*
 * extent: 82 code bytes followed by two zero alignment bytes at 0x022051FA.
 */
void SHINKA_DEMO_MainTask(struct TcbTask *task, void *sceneArg)
{
    Scene * scene = sceneArg;
    switch (scene->windowState) {
    case 1:
        BG_SYS_SetPlaneVisible(1, 1);
        scene->subBgVisible = 1;
        scene->windowState = 0;
        break;
    case 2:
        BG_SYS_SetPlaneVisible(1, 0);
        scene->subBgVisible = 0;
        scene->windowState = 0;
        break;
    }
    if (scene->palAnm)
        PALANM_TransferPalettes(scene->palAnm);
}

void SHINKA_DEMO_SetupWindows(App *unused, Scene *scene)
{
    struct BmpWin *p;

    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x20, 0x20, scene->heap);
    scene->window = BMP_WIN_Create((unsigned int)1, (unsigned int)0, (unsigned int)0, 1, 1, 1, 0);
    BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp(scene->window)), 0);
    BMP_WIN_TransferChars(scene->window);
    scene->menuWindow = BMP_WIN_Create((unsigned int)1, (unsigned int)1, (unsigned int)0x13, 0x1e, 4, 1, 1);
    BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp(scene->menuWindow)), 0);
    p = scene->menuWindow;
    BMP_WIN_TransferChars((struct BmpWin *)p);
    BMP_WIN_MakeScreen((struct BmpWin *)p);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)p));
    scene->frameGfx = BMP_MENUWORK_LoadFrameGfx(1, 2, 0, scene->heap);
    scene->msgBankA = MSGDATA_CreateFromArchive(0, 2, 0xac, scene->heap);
    scene->msgBankB = MSGDATA_CreateFromArchive(0, 2, 0xcc, scene->heap);
    scene->tcbl = TCBL_Create(scene->heap, scene->heap, 1, 0);
    GF_FONT_SetTextColor(1, 2, 0xf);
    scene->strbufA = 0;
    scene->printStream = 0;
    scene->keyCursor = APP_KEYCURSOR_CreateDefault((unsigned int)0xf, (unsigned int)1, (unsigned int)1, scene->heap);
    scene->windowState = 0;
    BG_SYS_SetPlaneVisible(1, 0);
    scene->subBgVisible = 0;
}

void SHINKA_DEMO_DeleteWindows(App *task, Scene *scene)
{
    APP_KEYCURSOR_Delete((struct KeyCursor *)(scene->keyCursor));
    if (scene->printStream) PRINTSYS_PrintStreamDelete((struct TextPrinter *)(scene->printStream));
    TCBL_Destroy((void *)(scene->tcbl));
    if (scene->strbufA) STRBUF_Delete((struct Strbuf *)(scene->strbufA));
    MSGDATA_Delete(scene->msgBankA);
    MSGDATA_Delete(scene->msgBankB);
    BG_SYS_FreeTileRun(1, (unsigned short)(scene->frameGfx), (unsigned short)(scene->frameGfx >> 16));
    BMP_WIN_Delete((struct BmpWin *)(scene->menuWindow));
    BMP_WIN_Delete((struct BmpWin *)(scene->window));
}

void SHINKA_DEMO_UpdateWindows(App *unused, Scene *scene)
{
    TCBL_Main((struct TcblSystem *)(scene->tcbl));
    if (scene->printStream != 0)
        APP_KEYCURSOR_Update((struct KeyCursor *)(scene->keyCursor), (void *)(scene->printStream), (void *)(scene->menuWindow));
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

void SHINKA_DEMO_PrintText(Scene *scene, struct MsgBank *msgBank, u32 msgId, PrintCallback callback, u32 kind0, void *value0, u32 kind1, void *value1)
{
    SHINKA_DEMO_ClearText(scene, 0xf);
    scene->strbufA = SHINKA_DEMO_BuildString(scene->heap, msgBank, msgId, kind0, value0, kind1, value1);
    scene->printStream = PRINTSYS_PrintStreamCallBack(*(struct BmpWin **)&scene->menuWindow, 0, 0, *(struct Strbuf **)&scene->strbufA, (struct GfFont *)(scene->font),
                                       MSG_SPEED_GetWait(), (struct Tcbl *)(scene->tcbl), 2, scene->heap, 0xf, callback);
}

/*
 * The `(x & 3) != 0 ? 0 : 1` call arguments must be written as an explicit
 * if/else. The ternary makes mwccarm pick the opposite branch polarity and
 * then colour the pointer r5/result r4 the other way; the if/else gives the
 * original pointer r4 / result r5 split and the shared return. See
 * docs/idioms/a-ternary-constant-call-argument-takes-the-opposite-branch-polarity.md.
 */
int SHINKA_DEMO_AdvanceText(Scene *scene)
{
    int r = 0;

    switch (PRINTSYS_PrintStreamGetState((void *)(scene->printStream))) {
    case 0:
        if ((KEY_GetCont() & 3) != 0 || TOUCHPANEL_GetCont() != 0) {
            PRINTSYS_PrintStreamShortWait((struct TextPrinter *)(scene->printStream), 0);
            if ((KEY_GetCont() & 3) != 0)
                UI_SetInputMode(0);
            else
                UI_SetInputMode(1);
        }
        break;
    case 1:
        if ((KEY_GetTrg() & 3) != 0 || TOUCHPANEL_GetTrg() != 0) {
            GFL_USE_PlaySeDefaultVolume(0x547);
            PRINTSYS_PrintStreamReleasePause((void *)(scene->printStream));
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
int SHINKA_DEMO_IsConfirmPressed(Scene *unused)
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

void SHINKA_DEMO_ClearText(Scene *scene, int fillColor)
{
    struct BmpWin *p;

    BMP_Clear((struct Bmp *)BMP_WIN_GetBmp(scene->menuWindow), fillColor);
    p = scene->menuWindow;
    BMP_WIN_TransferChars((struct BmpWin *)p);
    BMP_WIN_MakeScreen((struct BmpWin *)p);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)p));
    if (scene->printStream != 0)
        PRINTSYS_PrintStreamDelete((struct TextPrinter *)(scene->printStream));
    if (scene->strbufA != 0)
        STRBUF_Delete((struct Strbuf *)(scene->strbufA));
    scene->printStream = 0;
    scene->strbufA = 0;
}

/*
 * Leaf of the SHINKA_DEMO_Main dependency tree: either build the +0x6c render
 * node from the +0x74 id (and flush the +0x104/+0x108 stage), or arm the
 * +0x88 transition word with 2.
 */
void SHINKA_DEMO_SetupMessageBox(App *unused, Scene *p, int flag)
{
    if (flag != 0) {
        struct BmpWin *q;

        BMP_MENUWORK_DrawWindow(p->menuWindow, 0, (unsigned short)p->frameGfx, 2);
        BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp(p->menuWindow)), 0xf);
        q = p->menuWindow;
        BMP_WIN_TransferChars(q);
        BMP_WIN_MakeScreen(q);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(q));
    } else {
        p->windowState = 2;
    }
}

void SHINKA_DEMO_CreateConfirmMenu(App *unused, Scene *scene)
{
    scene->confirmMsgBank = MSGDATA_CreateFromArchive(0, 2, 0xe9, scene->heap);
#ifdef __MWERKS__
    scene->yesNoMenu = YESNO_MENU_Create(scene->heap, 5, 0, 1, 0, (void *)(SHINKA_DEMO_GRAPHIC_GetCamera(scene->graphic)),
                                       scene->font, (struct PrintQueue *)(scene->printQue), 0);
#else
    scene->yesNoMenu = YESNO_MENU_Create(scene->heap, 5, 0, 1, 0, (void *)(SHINKA_DEMO_GRAPHIC_GetCamera(scene->graphic)),
                                       scene->font, (struct PrintQueue *)(scene->printQue));
#endif
    scene->strbufC = 0;
    scene->strbufD = 0;
}

void SHINKA_DEMO_DeleteConfirmMenu(App *unused,Scene *scene) {YESNO_MENU_Delete((YesNoMenu *)(*(u8 * *)&scene->yesNoMenu));*(u32 *)&scene->yesNoMenu=0;if(scene->strbufC)STRBUF_Delete((struct Strbuf *)(scene->strbufC));if(scene->strbufD)STRBUF_Delete((struct Strbuf *)(scene->strbufD));MSGDATA_Delete((struct MsgBank *)(*(struct TextPrinter * *)&scene->confirmMsgBank));}

void SHINKA_DEMO_SetMenuText(Scene *scene, struct MsgBank *msgBankC, u32 msgIdC, u32 kindC0, void *valueC0, u32 kindC1, void *valueC1,
                   struct MsgBank *msgBankD, u32 msgIdD, u32 kindD0, void *valueD0, u32 kindD1, void *valueD1)
{
    if (scene->strbufC != 0)
        STRBUF_Delete((struct Strbuf *)(scene->strbufC));
    if (scene->strbufD != 0)
        STRBUF_Delete((struct Strbuf *)(scene->strbufD));
    scene->strbufC = SHINKA_DEMO_BuildString(scene->heap, msgBankC, msgIdC, kindC0, valueC0, kindC1, valueC1);
    scene->strbufD = SHINKA_DEMO_BuildString(scene->heap, msgBankD, msgIdD, kindD0, valueD0, kindD1, valueD1);
}

struct Strbuf *SHINKA_DEMO_BuildString(u32 heap, struct MsgBank *msgBank, u32 msgId, u32 kind0, void *value0, u32 kind1, void *value1)
{
    Param p[2];
    struct Strbuf *src, *r; struct WordSet *w; u32 i;
    int z;

    if (kind0 == 4 && kind1 == 4) {
        r = MSGDATA_AllocString(msgBank, msgId);
    } else {
        src = MSGDATA_AllocString(msgBank, msgId);
        w = WORDSET_CreateDefault(heap);
        p[0].kind = kind0;
        p[0].val = value0;
        p[1].kind = kind1;
        p[1].val = value1;
        for (i = 0, z = i; i < 2; i++) {
            switch (p[i].kind) {
            case 0:
                WORDSET_SetSlotTag((struct WordSet *)w, i, (struct Strbuf *)p[i].val, z, 1, z);
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
        r = STRBUF_Create(0x100, heap);
        WORDSET_CopyTaggedText((struct WordSet *)w, (void *)r, (void *)src);
        STRBUF_Delete((struct Strbuf *)src);
        WORDSET_Delete((struct WordSet *)w);
    }
    return r;
}

void SHINKA_DEMO_AddShedinja(App *app, Scene *scene)
{
    void *save;
    struct PokemonParam *p;
    void *q, *v;
    int i;

    save = GAME_DATA_GetMyItem(app->gameData);
    if ((int)POKEPARTY_GetCount(app->party) >= (int)POKEPARTY_GetCapacity(app->party))
        return;
    if (MYITEM_SAVEDATA_HasItem(save, 4, 1, scene->mainHeap) == 0)
        return;
    p = GFL_HEAP_Alloc(scene->mainHeap, POKE_TOOL_GetPartyParamSize(), 1, (const char *)d_02208F40, 0xaf5);
    POKE_TOOL_CopyPartyPokemon((struct PartyPokemon *)(scene->partyMon), (struct PartyPokemon *)p);
    POKE_TOOL_ChangeSpecies(p, 0x124);
    POKE_TOOL_SetPartyValue(p, 0x98, 4);
    POKE_TOOL_SetPartyValue(p, 6, 0);
    POKE_TOOL_SetPartyValue(p, 0xb, 0);
    for (i = 0x19; i < 0x36; i++)
        POKE_TOOL_SetPartyValue(p, i, 0);
    for (i = 0x4d; i < 0x6d; i++)
        POKE_TOOL_SetPartyValue(p, i, 0);
    for (i = 0x78; i < 0x8d; i++)
        POKE_TOOL_SetPartyValue(p, i, 0);
    v = MSGDATA_AllocString((struct MsgBank *)gSpeciesNameBank, POKE_TOOL_GetPartyValue(p, 5, 0));
    POKE_TOOL_SetPartyValue(p, 0x73, (uptr)v);
    STRBUF_Delete(v);
    POKE_TOOL_SetPartyValue(p, 0x9d, 0);
    v = MAIL_Create(scene->mainHeap);
    POKE_TOOL_SetPartyValue(p, 0xa7, (uptr)v);
    GFL_HEAP_Free(v);
    POKE_TOOL_SetPartyValue(p, 0x9f, 0);
    POKEPARTY_Add(app->party, p);
    MYITEM_SAVEDATA_RemoveItem(save, 4, 1, scene->mainHeap);
    GFL_HEAP_Free(p);
    q = ZUKAN_SAVE_GetFromGameData(app->gameData);
    ZUKAN_SAVE_RegisterSeen(q, p);
    ZUKAN_SAVE_RegisterCaught(q, p);
    q = GAME_DATA_GetTrainerRecord(app->gameData);
    RECORD_AddOne(q, 10);
    RECORD_AddOne(q, 0x58);
}

void SHINKA_DEMO_ClearHeldItem(App *unused, Scene *scene)
{
    POKE_TOOL_SetPartyValue((scene->partyMon), 6, 0);
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
        G3D_SYSTEM_SetLight((u8)i, (struct G3dLight *)(d_02208CCC + i * 8));
    G3D_SYSTEM_SetSwapBuffersMode(1, 0);
}
