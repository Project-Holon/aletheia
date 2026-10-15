/*
 * file:     ircbattlemenu.c
 * unit:     yes
 * function: IRCBATTLEMENU_StoreSeqFunc, IRCBATTLEMENU_SetSeq, IRCBATTLEMENU_InitBgLayers, IRCBATTLEMENU_FadePaletteBank, IRCBATTLEMENU_SetSubPaletteActive, IRCBATTLEMENU_CreateTimeIcon, IRCBATTLEMENU_ClearMessageWindow, IRCBATTLEMENU_DeleteMsgWin, IRCBATTLEMENU_CreateButtonWindows, IRCBATTLEMENU_DeleteButtonWindows, IRCBATTLEMENU_TouchCallback, IRCBATTLEMENU_BrightenPalette, IRCBATTLEMENU_LoadMenuGraphics, IRCBATTLEMENU_LoadSubBgScreen, IRCBATTLEMENU_SeqSetupTopMenu, IRCBATTLEMENU_FreeMenuGraphics, IRCBATTLEMENU_SeqWaitFadeEnd, IRCBATTLEMENU_SeqStartFadeOut, IRCBATTLEMENU_HookTopMenuPressed, IRCBATTLEMENU_SeqIdleTop, IRCBATTLEMENU_SeqPressTopButton, IRCBATTLEMENU_SeqWaitNotEnoughMsg, IRCBATTLEMENU_TouchTopMenu, IRCBATTLEMENU_SeqUpdateTouchTop, IRCBATTLEMENU_SeqSetupKindMenu, IRCBATTLEMENU_HookKindMenuPressed, IRCBATTLEMENU_SeqIdleKind, IRCBATTLEMENU_SeqPressKindButton, IRCBATTLEMENU_HookKindBackPressed, IRCBATTLEMENU_SeqIdleKindBack, IRCBATTLEMENU_SeqPressKindBack, IRCBATTLEMENU_TouchKindMenu, IRCBATTLEMENU_SeqSetupRuleMenu, IRCBATTLEMENU_HookPartyMenuPressed, IRCBATTLEMENU_SeqIdleParty, IRCBATTLEMENU_SeqPressPartyButton, IRCBATTLEMENU_SeqUpdateTouchParty, IRCBATTLEMENU_TouchPartyMenu, IRCBATTLEMENU_SeqSetupPartyMenu, IRCBATTLEMENU_HookRuleMenuPressed, IRCBATTLEMENU_SeqIdleRule, IRCBATTLEMENU_SeqPressRuleButton, IRCBATTLEMENU_TouchRuleMenu, IRCBATTLEMENU_SeqUpdateTouchSub, IRCBATTLEMENU_LoadActorResources, IRCBATTLEMENU_DeleteMenuActors, IRCBATTLEMENU_CreateTopMenuActors, IRCBATTLEMENU_CreateKindMenuActors, IRCBATTLEMENU_CreateMainMenuActors, IRCBATTLEMENU_CreateSubMenuActors, IRCBATTLEMENU_CreateDecoration, IRCBATTLEMENU_DeleteClact, IRCBATTLEMENU_OpenYesNoMenu, IRCBATTLEMENU_IsMessageEnd, IRCBATTLEMENU_PrintMessage, IRCBATTLEMENU_SeqSaveQuestion, IRCBATTLEMENU_SeqSaveMain, IRCBATTLEMENU_SeqSaveStart, IRCBATTLEMENU_SeqWaitTouchExit, IRCBATTLEMENU_SeqSaveYesNo, IRCBATTLEMENU_SeqSaveQuestionWait, IRCBATTLEMENU_VBlankTask, IRCBATTLEMENU_Init, IRCBATTLEMENU_Main, IRCBATTLEMENU_Exit, IRCBATTLEMENU_CreateMainMenuActors, IRCBATTLEMENU_CreateSubMenuActors, IRCBATTLEMENU_CreateDecoration, IRCBATTLEMENU_DeleteClact, IRCBATTLEMENU_OpenYesNoMenu, IRCBATTLEMENU_IsMessageEnd, IRCBATTLEMENU_PrintMessage, IRCBATTLEMENU_SeqSaveQuestion, IRCBATTLEMENU_SeqSaveMain, IRCBATTLEMENU_SeqSaveStart, IRCBATTLEMENU_SeqWaitTouchExit, IRCBATTLEMENU_SeqSaveYesNo, IRCBATTLEMENU_SeqSaveQuestionWait, IRCBATTLEMENU_VBlankTask, IRCBATTLEMENU_Init, IRCBATTLEMENU_Main, IRCBATTLEMENU_Exit
 * address:  0x02196030
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_020490F4  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm  arm9
 *   MI_CpuCopy8  0x02082D44  arm  arm9
 *   func_020409B4  0x020409B4  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   func_02049B40  0x02049B40  arm
 *   DC_FlushRange  0x020862F0  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_FreeSlot  0x020414AC  arm
 *   func_02040588  0x02040588  arm
 *   BG_SYS_Init  0x02040C14  arm
 *   sBgTemplateMain0     0x021D40A0  data  ov021  a4
 *   sBgTemplateMain1     0x021D40C0  data  ov021  a4
 *   sBgTemplateSub0     0x021D40E0  data  ov021  a4
 *   sBgTemplateSub1     0x021D4100  data  ov021  a4
 *   sBgTemplateSub2     0x021D4120  data  ov021  a4
 *   sBgTemplateSub3     0x021D4140  data  ov021  a4
 *   PALANM_Create  0x02021518  thumb
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb
 *   PALANM_CopyHwPaletteToSlot  0x020216D4  thumb
 *   PALANM_BlendChannel  0x02021FD8  thumb
 *   PALANM_GetTransWork  0x02021730  thumb
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb
 *   PALANM_Delete  0x02021540  thumb
 *   func_0207E5D0  0x0207E5D0  arm
 *   func_0207E468  0x0207E468  arm
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   TIME_ICON_CreateNode  0x0202EE8C  thumb
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_0201D42C  0x0201D42C  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   BUTTON_MAN_Delete  0x02051C6C  arm
 *   STRBUF_Create  0x020457B0  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049740  0x02049740  arm
 *   func_02049990  0x02049990  arm
 *   func_02049F78  0x02049F78  arm
 *   BMP_MENUWORK_LoadFrameGfx  0x0201F5DC  thumb
 *   sMenuPlttRowOffsets     0x021DDAD4  data  ov021  a2
 *   BUTTON_MAN_Create  0x02051B84  arm
 *   sTopMenuMsgIds     0x021D4070  data  a4
 *   sTopMenuTextCenterX     0x021D4014  data  a4
 *   sTopMenuTextCenterY     0x021D4024  data  a4
 *   sTopMenuTouchRects     0x021D404C  data  a4
 *   sTopMenuWinDescs     0x021DDB84  data  a4
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb
 *   BG_SYS_SetTileUnit  0x02040DA8  arm
 *   BG_SYS_DeleteHalf  0x0203FB44  arm
 *   func_020403F4  0x020403F4  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   IRC_BATTLE_ENTRY_GetGameSys  0x02155A90  thumb  ov010
 *   ICA_ANIME_GetField24  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   IRC_BATTLE_ENTRY_GetSaveControl  0x02155A94  thumb  ov010
 *   func_0200873C  0x0200873C  thumb
 *   CONFIG_GetButtonMode  0x02008428  thumb
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   func_0204BA00  0x0204BA00  arm
 *   CLACT_RestartActorAnim  0x0204B9A0  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetNonEggCount  0x0201AA1C  thumb
 *   BUTTON_MAN_UpdateSlots  0x02051C88  arm
 *   sKindMenuMsgIds     0x021D3FE0  data  ov021  a4
 *   sKindMenuTouchRects     0x021D3FF4  data  ov021  a4
 *   sKindMenuWinDescs     0x021DDAF4  data  ov021  a4
 *   BATTLE_BOX_GetFromSave  0x0200BAC8  thumb
 *   BATTLE_BOX_HasMon  0x0200BBA8  thumb
 *   sRuleMenuMsgIds     0x021D4080  data  ov021  a4
 *   sRuleMenuTouchRects     0x021D4034  data  ov021  a4
 *   sRuleMenuWinDescs     0x021DDB44  data  ov021  a4
 *   sPartyMenuActorIndex     0x021D3F9C  data  ov021  a1
 *   sPartyMenuMsgIds     0x021D3FD8  data  ov021  a4
 *   sPartyMenuTouchRects     0x021D4004  data  ov021  a4
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorObjMode  0x0204B688  arm
 *   sTopMenuActorPosX     0x021D3FC8  data  ov021  a1
 *   sTopMenuActorPosY     0x021D3FB0  data  ov021  a1
 *   sTopMenuActorAnim     0x021D3FA8  data  ov021  a1
 *   sKindMenuActorPosX     0x021D3FA0  data   a1
 *   sKindMenuActorPosY     0x021D3F8C  data   a1
 *   sKindMenuActorAnim     0x021D3F94  data   a1
 *   sMainMenuActorPosX     0x021D3FC0  data   a1
 *   sMainMenuActorPosY     0x021D3FD0  data   a1
 *   sMainMenuActorAnim     0x021D3FB8  data   a1
 *   sSubMenuActorPosX     0x021D3F98  data   a1
 *   sSubMenuActorPosY     0x021D3FA4  data   a1
 *   sSubMenuActorAnim     0x021D3F90  data   a1
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb
 *   APP_TASKMENU_SetDisableKey  0x02027CD8  thumb
 *   APP_KEYCURSOR_Update  0x020286C4  thumb
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   BG_SYS_ClearLayerEx  0x02041570  arm
 *   GAME_DATA_SaveMain  0x02012DD0  thumb
 *   GAME_DATA_SaveStart  0x02012DAC  thumb
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_020071F0  0x020071F0  thumb
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BMP_WIN_Init  0x02045088  arm
 *   GF_FONT_InitTextColor  0x0201DD60  thumb
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   sVramBank     0x021DDB14  data   ov021  a4
 *   sGraphicsMode     0x021D4090  data   ov021  a4
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   gClActorInitParam     0x020A1448  data   a4
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   func_020056A0  0x020056A0  thumb
 *   sIrcBattleMenuFileName     0x021DDBC4  data   ov021  a4
 *   func_02030734  0x02030734  arm
 *   TCBL_Create  0x0203101C  arm
 *   func_02028590  0x02028590  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   func_0207D63C  0x0207D63C  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   GAME_DATA_GetField1A0  0x0201283C  thumb
 *   WIH_DWC_PollStatus  0x0201058C  thumb
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb
 *   func_02040618  0x02040618  arm
 *   TCBL_Main  0x020310C4  arm
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   CLACT_DrawSystem  0x0204A600  arm
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb
 *   ICA_ANIME_GetUnk330  0x02012204  thumb
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb
 *   IRC_BATTLE_ENTRY_SetMode  0x02155A8C  thumb  ov010
 *   APP_KEYCURSOR_Delete  0x02028604  thumb
 *   TCBL_Destroy  0x02031140  arm
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   func_020315D4  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   FLDMMDL_BLACT_Exit  0x0219C5D0  thumb  ov021
 *   FLDMMDL_SysGetG3dObjCont  0x0216D528  thumb
 *   FLDMMDL_G3DOBJ_Delete  0x0219D488  thumb  ov021
 *   FLDMMDL_SysSetDrawInit  0x0216D95C  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysCheckStatusBit  0x0216D4D4  thumb  ov010
 *   FLDMMDL_CheckMoveBitDrawInitComp  0x0216DAA0  thumb  ov010
 *   FLDMMDL_CallDrawProc  0x0216D758  thumb  ov010
 *   FLDMMDL_CheckMoveBitMovePause  0x0216DB10  thumb  ov010
 *   FLDMMDL_CheckMoveBitAcmd  0x0216DC4C  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_GetDrawOffset  0x0216D8B0  thumb  ov010
 *   FLDMMDL_GetDrawOffsetOutside  0x0216D8D0  thumb  ov010
 *   FLDMMDL_GetAttrOffset  0x0216D8F0  thumb  ov010
 *   FLDMMDL_GetModelOffset  0x0216D92C  thumb  ov010
 *   FLDMMDL_SysGetHeapId  0x0216D4F8  thumb  ov010
 *   FLDMMDL_SysGetTcbPriority  0x0216D4F4  thumb  ov010
 *   FLDMMDL_SysGetTcbSys  0x0216D514  thumb  ov010
 *   func_02030DA8  0x02030DA8  arm
 *   d_021DDBE0     0x021DDBE0  data  a4
 *   TCBL_GetTaskUserData  0x02030EE8  arm
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 *   d_021D4A50     0x021D4A50  data  a4
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   d_021D5D6C     0x021D5D6C  data  a4
 *   FLDMMDL_GetAcmdCode  0x0216D7C4  thumb  ov010
 *   FLDMMDL_GetAcmdSeq  0x0216D7D4  thumb  ov010
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   FLDMMDL_ClearMoveBit  0x0216D570  thumb  ov010
 *   FLDMMDL_SetAcmdCode  0x0216D7C0  thumb  ov010
 *   FLDMMDL_SetAcmdSeq  0x0216D7C8  thumb  ov010
 *   d_021D624C     0x021D624C  data  a4
 *   d_021D5F58     0x021D5F58  data  a4
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_MOVE_UpdateOldGridPos  0x02163F10  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 *   FLDMMDL_InitMoveCmdWork  0x0216D6BC  thumb  ov010
 *   FLDMMDL_MOVE_UpdateGridPosDir  0x02163E7C  thumb  ov010
 *   FLDMMDL_SetDirAll  0x0216D60C  thumb  ov010
 *   FLDMMDL_GetMoveCmdWork  0x0216D6D4  thumb  ov010
 *   FLDMMDL_MOVE_AddDirVectorPos  0x02163FC0  thumb  ov010
 *   FLDMMDL_MOVE_UpdateHeight  0x02164010  thumb  ov010
 *   d_021DDBD4     0x021DDBD4  data   ov021  a4
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 *   FLDMMDL_ClearStatusBit  0x0216D550  thumb  ov010
 *   FLDMMDL_SysGetFieldMap  0x0216D534  thumb  ov010
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDEFF_GYOE_SetMMdl  0x021BB528  thumb  ov021
 *   FLDEFF_GYOE_IsFinished  0x021BB5C8  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;

#include "ircbattlemenu_types.h"

/* Init data of one cell actor (CLACT_CreateActor). */
typedef struct ClactActorInit {
    u16 posX;
    u16 posY;
    u16 anim;
    u8 softPri;
    u8 bgPri;
} ClactActorInit;

/* Init data of a task menu (TaskMenuInitWork in app_taskmenu.c). */
typedef struct TaskMenuInit {
    u32 heapId;
    u8 itemNum;
    IrcBattleMenuItem *itemWork;
    u32 posType;
    u8 charPosX;
    u8 charPosY;
    u8 width;
    u8 height;
} TaskMenuInit;

typedef struct { u8 v[5]; } ActorRow5;
typedef struct { u8 v[3]; } ActorRow3;
typedef struct { u32 w[4]; } DispSetup;

/* Partial view: the full type is in ov010 musical_dressup_sys.c. */
typedef struct IrcBattleEntryWork {
    u8 padding0[0x4C];
    void *saveData;                     /* 0x4C */
    u8 padding50[8];
    u32 partyMode;                      /* 0x58 */
} IrcBattleEntryWork;

struct ProcWork;
struct DispVram;
struct DispConfig;
struct ClactSysInit;
struct GameSystem;
struct WifiList;
struct Bmp;
struct TaskNode;

extern struct ClactActor *CLACT_CreateActor(struct ClactUnit *unit, u32 charRes, u32 plttRes, u32 cellRes, const ClactActorInit *init, u16 drawArea, u16 heapId);
extern void CLACT_SetActorAutoAnim(struct ClactActor *actor, u32 flag);
extern void CLACT_SetActorDrawEnable(struct ClactActor *actor, u32 flag);
extern void CLACT_SetActorObjMode(struct ClactActor *actor, u32 mode);
extern void CLACT_DeleteActor(struct ClactActor *actor);
extern void CLACT_ReleasePalette(u32 res);
extern void CLACT_ReleaseCharacter(u32 res);
extern void CLACT_ReleaseCellAnim(u32 res);
extern struct StrBuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgData *msgData, u32 strId, struct StrBuf *dest);
extern struct TaskMenuWork *APP_TASKMENU_OpenMenu(TaskMenuInit *init, struct TaskMenuRes *res);
extern int APP_TASKMENU_SetDisableKey(struct TaskMenuWork *menu, int pos);
extern void STRBUF_Delete(struct StrBuf *str);
extern void APP_KEYCURSOR_Update(struct AppKeyCursor *cursor, struct PrintStream *stream, struct BmpWin *win);
extern u32 PRINTSYS_PrintStreamGetState(struct PrintStream *stream);
extern void PRINTSYS_PrintStreamDelete(struct PrintStream *stream);
extern void PRINTSYS_PrintStreamReleasePause(struct PrintStream *stream);
extern void PRINTSYS_PrintStreamShortWait(struct PrintStream *stream, s32 wait);
extern int TOUCHPANEL_GetTrg(void);
extern int TOUCHPANEL_GetCont(void);
extern void GFL_USE_PlaySeDefaultVolume();
extern struct BmpWin *BMP_WIN_Create(u32 bgFrame, u32 posX, u32 posY, u32 width, u8 height, u8 palNo, u8 dir);
extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);
extern void BMP_Clear(struct Bmp *bmp, u8 color);
extern void GF_FONT_SetTextColor(u32 letter, u32 shadow, u32 back);
extern signed char MSG_SPEED_GetWait(void);
extern struct PrintStream *PRINTSYS_PrintStream(struct BmpWin *win, u32 x, u32 y, struct StrBuf *str, struct GfFont *font, u32 wait, struct Tcbl *tcbl, u32 pri, u32 heapId, u32 back);
extern void PRINTSYS_Print(struct Bmp *bmp, s16 x, s16 y, struct StrBuf *str, struct GfFont *font);
extern void BMP_MENUWORK_DrawWindow(struct BmpWin *win, int transfer, int frameChar, int palNo);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern void func_02041B6C(u32 frame);
extern void BG_SYS_ClearLayerEx(int frame, u16 value);
extern int GAME_DATA_SaveMain(struct GameData *gameData);
extern void BMP_MENUWORK_DrawWindowBorder(struct BmpWin *win, u32 transfer);
extern void BMP_WIN_ClearScreen(struct BmpWin *win);
extern int GAME_DATA_SaveStart(struct GameData *gameData);
extern void BG_SYS_ClearSlot(u32 frame);
extern u32 APP_TASKMENU_IsFinish(struct TaskMenuWork *menu);
extern u8 APP_TASKMENU_GetCursorPos(const struct TaskMenuWork *menu);
extern void *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern u32 func_020071F0(void);
extern void APP_TASKMENU_CloseMenu(struct TaskMenuWork *menu);
extern void CLACT_VBlankSystem(void);
extern void GFL_HEAP_CreateChildHeap(u32 parentHeap, u32 heapId, u32 size);
extern void *PROCSYS_AllocProcWork(struct ProcWork *proc, u32 size, u32 heapId);
extern void MI_CpuFill8(void *dest, u32 value, u32 size);
extern void BG_SYS_Create(u16 heapId);
extern void BMP_WIN_Init(u16 heapId);
extern void GF_FONT_InitTextColor(void);
extern void BG_SYS_SetVramBanks(const struct DispVram *vram);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void CLACT_InitSystem(const struct ClactSysInit *init, const struct DispVram *vram, u32 heapId);
extern struct ClactUnit *CLACT_CreateUnit(int actorMax, u8 pri, u32 heapId);
extern u32 func_020056A0(void (*task)(void), void *work, u32 pri);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern struct Tcbl *TCBL_Create(u16 heapId, u16 tcbHeapId, u32 count, u32 workSize);
extern struct AppKeyCursor *func_02028590(u32 palNo, u32 isWin, u32 isFrame, u32 heapId);
extern struct PrintQue *PRINTSYS_QUE_Create(u32 heapId);
extern struct TaskMenuRes *APP_TASKMENU_RES_Create(u16 bgFrame, u16 palNo, struct GfFont *font, struct PrintQue *printQue, u16 heapId);
extern void WIPE_SYS_Start(u32 pattern0, u32 pattern1, u32 pattern2, u32 color, u32 div, u32 sync, u32 heapId);
extern struct GameSystem *IRC_BATTLE_ENTRY_GetGameSys(IrcBattleEntryWork *entry);
extern struct GameData *ICA_ANIME_GetField1C(const struct GameSystem *gameSys);
extern void func_0207D63C(u32 reg, u32 plane1, u32 plane2, u32 ev1, u32 ev2);
extern void GFL_NET_RestartWithDefaultTimeout(u32 type, u32 heapId);
extern struct WifiList *GAME_DATA_GetField1A0(const struct GameData *gameData);
extern u32 WIH_DWC_PollStatus(struct WifiList *wifiList);
extern void APP_TASKMENU_UpdateMenu(struct TaskMenuWork *menu);
extern void APP_TASKMENU_WIN_Update(struct TaskMenuWin *win);
extern void func_02040618(u32 frame, u32 op, u32 value);
extern void TCBL_Main(struct Tcbl *tcbl);
extern u32 PRINTSYS_QUE_Main(struct PrintQue *printQue);
extern void CLACT_DrawSystem(void);
extern u32 GAMESYSTEM_TryStartAutoComm(struct GameSystem *gameSys);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 ICA_ANIME_GetUnk330(const struct GameSystem *gameSys);
extern void WIPE_SetBrightnessFadeOut(u32 screen, u32 value);
extern void IRC_BATTLE_ENTRY_SetMode(IrcBattleEntryWork *entry, u32 mode);
extern void TIME_ICON_Delete(struct TimeIcon *icon);
extern u32 func_020307B0(void *ptr);
extern int APP_KEYCURSOR_Delete(struct AppKeyCursor *cursor);
extern void TCBL_Destroy(struct Tcbl *tcbl);
extern void func_020403F4(u32 frame);
extern void PRINTSYS_QUE_Clear(struct PrintQue *printQue);
extern void PRINTSYS_QUE_Delete(struct PrintQue *printQue);
extern u32 BMP_WIN_Delete(struct BmpWin *win);
extern void APP_TASKMENU_WIN_Delete(struct TaskMenuWin *win);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuRes *res);
extern void func_02030EAC(struct TaskNode *task);
extern u32 CLACT_DeleteUnit(struct ClactUnit *unit);
extern void CLACT_ExitSystem(void);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void func_020315D4(struct ProcWork *proc);
extern void GFL_HEAP_DeleteChecked(u32 heapId);


extern const ActorRow5 sMainMenuActorPosX;
extern const ActorRow5 sMainMenuActorPosY;
extern const ActorRow5 sMainMenuActorAnim;
extern const ActorRow3 sSubMenuActorPosX;
extern const ActorRow3 sSubMenuActorPosY;
extern const ActorRow3 sSubMenuActorAnim;
extern u8 sVramBank[];
extern const DispSetup sGraphicsMode;
extern u8 gClActorInitParam[];
extern u8 sIrcBattleMenuFileName[];

/* Window description of a button window (position and size in characters). */
typedef struct IrcBattleWinDesc {
    u32 posX;
    u32 posY;
    u32 width;
    u32 height;
} IrcBattleWinDesc;

/* BG layer template (eight settings words, not read here). */
typedef struct BgTemplate {
    u32 settings[8];
} BgTemplate;

/* Message ids of the buttons of a menu. */
typedef struct MsgIdRow2 { u32 id[2]; } MsgIdRow2;
typedef struct MsgIdRow4 { u32 id[4]; } MsgIdRow4;

/* Request passed to the cell actor animation: runs callback(work) when the animation ends. */
typedef struct ClactAnimEndHook {
    u16 type;
    IrcBattleMenuWork *work;
    void (*callback)(IrcBattleMenuWork *work);
} ClactAnimEndHook;

/* Palette resource data (rawData at +0xC). */
struct PaletteData {
    u32 format;
    u32 isExtended;
    u32 size;
    void *rawData;
};

struct PlttFade;
struct ArcHandle;
struct CommSys;
struct PartyInfo;

extern struct ArcHandle *func_020490F4(u32 arcId, u32 heapId);
extern void ARC_TOOL_DeleteHandle(struct ArcHandle *arc);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u32 func_020409B4(u32 bgId);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 heapId);
extern void DC_FlushRange(void *p, u32 size);
extern void BG_SYS_SetTileEntry(u8 layer, u16 tile, u8 x, u8 y, u8 w, u8 h, u8 mode);
extern void BG_SYS_InitBgLayer(unsigned int bgId, const BgTemplate *tmpl, unsigned int type);
extern void BG_SYS_FreeSlot(int bgId);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);
extern struct PlttFade *PALANM_Create(u32 heapId);
extern void PALANM_AllocSlotBuffers(struct PlttFade *fade, u32 bank, u32 size, u32 heapId);
extern void PALANM_CopyHwPaletteToSlot(struct PlttFade *fade, u32 bank, u32 offset, u32 size);
extern void PALANM_BlendChannel(struct PlttFade *fade, u32 bank, u32 start, u32 count, u8 weight, u16 color);
extern u16 *PALANM_GetTransWork(struct PlttFade *fade, int bank);
extern void PALANM_FreeSlotBuffers(struct PlttFade *fade, u32 bank);
extern u32 PALANM_Delete(struct PlttFade *fade);
extern void func_0207E5D0(void *dst, u32 value, u32 size);
extern void func_0207E468(void *dst, u32 value, u32 size);
extern struct TimeIcon *TIME_ICON_CreateNode(struct Tcbl *tcbl, struct BmpWin *win, u8 a, u8 b, u16 heapId);
extern u32 func_0201D304(struct StrBuf *str, struct GfFont *font, u32 a);
extern u32 func_0201D42C(struct StrBuf *str, struct GfFont *font);
extern void BUTTON_MAN_Delete(struct TouchSwitch *touchSw);
extern struct GfFont *GF_FONT_Create(int a, int b, int c, int d, u32 heapId);
extern struct MsgData *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02049B68(struct ArcHandle *arc, u32 a, u32 b, u32 c, u32 d, u16 heapId);
extern u32 func_02049740(struct ArcHandle *arc, u32 a, u32 b, u32 c, u32 d, u16 heapId);
extern u32 func_02049990(struct ArcHandle *arc, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 heapId);
extern void *func_02049F78(struct ArcHandle *arc, u32 id, struct PaletteData **out, u32 heapId);
extern u32 BMP_MENUWORK_LoadFrameGfx(u32 a, u32 b, u32 c, u32 heapId);
extern struct TouchSwitch *BUTTON_MAN_Create(const u8 *table, void (*callback)(u32 index, int event, IrcBattleMenuWork *work), IrcBattleMenuWork *work, int heapId);
extern s32 BUTTON_MAN_UpdateSlots(struct TouchSwitch *touchSw);
extern void GF_FONT_SetDefaultTextColor(void);
extern void BG_SYS_SetTileUnit(u32 a, u32 b, u32 c);
extern void BG_SYS_DeleteHalf(u32 a, u32 b, u32 c);
extern u32 MSGDATA_Delete(struct MsgData *msgData);
extern u32 GF_FONT_Delete(struct GfFont *font);
extern struct CommSys *ICA_ANIME_GetField24(const struct GameSystem *gameSys);
extern u32 GAME_COMM_GetKind(struct CommSys *comm);
extern void GAME_COMM_RequestExitNoCallback(struct CommSys *comm);
extern void *IRC_BATTLE_ENTRY_GetSaveControl(IrcBattleEntryWork *entry);
extern struct PartyInfo *func_0200873C(void *sys);
extern int CONFIG_GetButtonMode(struct PartyInfo *info);
extern void *GAME_DATA_GetMyParty(const struct GameData *gameData);
extern u32 POKEPARTY_GetNonEggCount(void *party);
extern void *BATTLE_BOX_GetFromSave(void *saveData);
extern u32 BATTLE_BOX_HasMon(void *data);
extern s32 CLACT_RegisterCharacter(struct ArcHandle *arc, u32 a, u32 b, u32 c, u16 heapId);
extern s32 CLACT_RegisterPaletteEx(struct ArcHandle *arc, u32 a, u32 b, u32 c, u16 d, u16 e, u16 heapId);
extern s32 CLACT_RegisterCellAnim(struct ArcHandle *arc, u32 a, u32 b, u32 heapId);
extern void func_0204BA00(struct ClactActor *actor, const ClactAnimEndHook *hook);
extern void CLACT_RestartActorAnim(struct ClactActor *actor);
extern const BgTemplate sBgTemplateMain0;
extern const BgTemplate sBgTemplateMain1;
extern const BgTemplate sBgTemplateSub0;
extern const BgTemplate sBgTemplateSub1;
extern const BgTemplate sBgTemplateSub2;
extern const BgTemplate sBgTemplateSub3;
extern const u16 sMenuPlttRowOffsets[];
extern const MsgIdRow4 sTopMenuMsgIds;
extern int sTopMenuTextCenterX[];
extern int sTopMenuTextCenterY[];
extern const u8 sTopMenuTouchRects[];
extern IrcBattleWinDesc sTopMenuWinDescs[];
extern const MsgIdRow2 sKindMenuMsgIds;
extern const u8 sKindMenuTouchRects[];
extern IrcBattleWinDesc sKindMenuWinDescs[];
extern const MsgIdRow4 sRuleMenuMsgIds;
extern const u8 sRuleMenuTouchRects[];
extern IrcBattleWinDesc sRuleMenuWinDescs[];
extern const ActorRow3 sPartyMenuActorIndex;
extern const MsgIdRow2 sPartyMenuMsgIds;
extern const u8 sPartyMenuTouchRects[];
extern const ActorRow5 sTopMenuActorPosX;
extern const ActorRow5 sTopMenuActorPosY;
extern const ActorRow5 sTopMenuActorAnim;
extern const ActorRow3 sKindMenuActorPosX;
extern const ActorRow3 sKindMenuActorPosY;
extern const ActorRow3 sKindMenuActorAnim;

void IRCBATTLEMENU_StoreSeqFunc(IrcBattleMenuSeqFunc *dest, IrcBattleMenuSeqFunc seq);
void IRCBATTLEMENU_SetSeq(IrcBattleMenuWork *work, IrcBattleMenuSeqFunc seq, u32 line);
void IRCBATTLEMENU_InitBgLayers(IrcBattleMenuWork *work);
void IRCBATTLEMENU_FadePaletteBank(IrcBattleMenuWork *work, u32 bank, u32 rows);
void IRCBATTLEMENU_SetSubPaletteActive(IrcBattleMenuWork *work, int isActive);
void IRCBATTLEMENU_CreateTimeIcon(IrcBattleMenuWork *work);
void IRCBATTLEMENU_ClearMessageWindow(IrcBattleMenuWork *work);
void IRCBATTLEMENU_DeleteMsgWin(IrcBattleMenuWork *work);
void IRCBATTLEMENU_CreateButtonWindows(int count, u32 *msgIds, IrcBattleMenuWork *work, IrcBattleWinDesc *descs, int *centerX, int *centerY);
void IRCBATTLEMENU_DeleteButtonWindows(IrcBattleMenuWork *work);
void IRCBATTLEMENU_TouchCallback(u32 index, int event, IrcBattleMenuWork *work);
void IRCBATTLEMENU_BrightenPalette(u16 (*pltt)[16], const u16 *rowOffsets, int rows);
void IRCBATTLEMENU_LoadMenuGraphics(IrcBattleMenuWork *work);
void IRCBATTLEMENU_LoadSubBgScreen(IrcBattleMenuWork *work, u32 screenId);
void IRCBATTLEMENU_SeqSetupTopMenu(IrcBattleMenuWork *work);
void IRCBATTLEMENU_FreeMenuGraphics(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqWaitFadeEnd(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqStartFadeOut(IrcBattleMenuWork *work);
void IRCBATTLEMENU_HookTopMenuPressed(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqIdleTop(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqPressTopButton(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqWaitNotEnoughMsg(IrcBattleMenuWork *work);
int IRCBATTLEMENU_TouchTopMenu(u32 index, IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqUpdateTouchTop(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqSetupKindMenu(IrcBattleMenuWork *work);
void IRCBATTLEMENU_HookKindMenuPressed(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqIdleKind(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqPressKindButton(IrcBattleMenuWork *work);
void IRCBATTLEMENU_HookKindBackPressed(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqIdleKindBack(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqPressKindBack(IrcBattleMenuWork *work);
int IRCBATTLEMENU_TouchKindMenu(u32 index, IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqSetupRuleMenu(IrcBattleMenuWork *work);
void IRCBATTLEMENU_HookPartyMenuPressed(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqIdleParty(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqPressPartyButton(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqUpdateTouchParty(IrcBattleMenuWork *work);
int IRCBATTLEMENU_TouchPartyMenu(u32 index, IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqSetupPartyMenu(IrcBattleMenuWork *work);
void IRCBATTLEMENU_HookRuleMenuPressed(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqIdleRule(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqPressRuleButton(IrcBattleMenuWork *work);
int IRCBATTLEMENU_TouchRuleMenu(u32 index, IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqUpdateTouchSub(IrcBattleMenuWork *work);
void IRCBATTLEMENU_LoadActorResources(IrcBattleMenuWork *work);
void IRCBATTLEMENU_DeleteMenuActors(IrcBattleMenuWork *work);
void IRCBATTLEMENU_CreateTopMenuActors(IrcBattleMenuWork *work);
void IRCBATTLEMENU_CreateKindMenuActors(IrcBattleMenuWork *work);
void IRCBATTLEMENU_CreateMainMenuActors(IrcBattleMenuWork *work);
void IRCBATTLEMENU_CreateSubMenuActors(IrcBattleMenuWork *work);
void IRCBATTLEMENU_CreateDecoration(IrcBattleMenuWork *work, u32 posX, u32 posY, u32 index, u32 anim);
void IRCBATTLEMENU_DeleteClact(IrcBattleMenuWork *work);
void IRCBATTLEMENU_OpenYesNoMenu(IrcBattleMenuWork *work);
int IRCBATTLEMENU_IsMessageEnd(IrcBattleMenuWork *work);
void IRCBATTLEMENU_PrintMessage(IrcBattleMenuWork *work, u32 isInstant);
void IRCBATTLEMENU_SeqSaveQuestion(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqSaveMain(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqSaveStart(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqWaitTouchExit(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqSaveYesNo(IrcBattleMenuWork *work);
void IRCBATTLEMENU_SeqSaveQuestionWait(IrcBattleMenuWork *work);
void IRCBATTLEMENU_VBlankTask(void);
int IRCBATTLEMENU_Init(struct ProcWork *proc, u32 seq, IrcBattleEntryWork *param);
u32 IRCBATTLEMENU_Main(u32 proc, u32 seq, u32 param, IrcBattleMenuWork *work);
int IRCBATTLEMENU_Exit(struct ProcWork *proc, u32 seq, IrcBattleEntryWork *param, IrcBattleMenuWork *work);

/* Stores the current sequence function; SetSeq passes work->seqFunc and the new function. */
void IRCBATTLEMENU_StoreSeqFunc(IrcBattleMenuSeqFunc *dest, IrcBattleMenuSeqFunc seq)
{
    *dest = seq;
}

/* Sets the next sequence function. The line argument is the call site's source line and is not used. */
void IRCBATTLEMENU_SetSeq(IrcBattleMenuWork *work, IrcBattleMenuSeqFunc seq, u32 line)
{
    IRCBATTLEMENU_StoreSeqFunc(&work->seqFunc, seq);
}

/* Sets up the six BG layers of the menu (main 0, 1 and sub 4 to 7) from their templates. */
void IRCBATTLEMENU_InitBgLayers(IrcBattleMenuWork *work)
{
    BgTemplate mainBg0;
    BgTemplate mainBg1;
    BgTemplate subBg0;
    BgTemplate subBg1;
    BgTemplate subBg2;
    BgTemplate subBg3;

    mainBg0 = sBgTemplateMain0;
    BG_SYS_InitBgLayer(0, &mainBg0, 0);
    BG_SYS_FreeSlot(0);
    func_020409B4(0);
    func_02040588(0, 1);
    mainBg1 = sBgTemplateMain1;
    BG_SYS_InitBgLayer(1, &mainBg1, 0);
    BG_SYS_FreeSlot(1);
    func_020409B4(1);
    func_02040588(1, 1);
    subBg0 = sBgTemplateSub0;
    BG_SYS_InitBgLayer(4, &subBg0, 0);
    func_02040588(4, 1);
    func_020409B4(4);
    subBg1 = sBgTemplateSub1;
    BG_SYS_InitBgLayer(5, &subBg1, 0);
    func_02040588(5, 1);
    BG_SYS_Init(5, 0, 1, 0);
    BG_SYS_SetTileEntry(5, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(5);
    subBg2 = sBgTemplateSub2;
    BG_SYS_InitBgLayer(6, &subBg2, 0);
    func_02040588(6, 1);
    func_020409B4(6);
    subBg3 = sBgTemplateSub3;
    BG_SYS_InitBgLayer(7, &subBg3, 0);
    func_02040588(7, 1);
    func_020409B4(7);
}

/* Loads palette bank "bank" (1: BG, 3: OBJ) through the palette fade system, dimmed over "rows" rows of 16 colors. */
void IRCBATTLEMENU_FadePaletteBank(IrcBattleMenuWork *work, u32 bank, u32 rows)
{
    struct PlttFade *fade;
    u32 size;
    u16 *buf;

    fade = PALANM_Create(work->heapId);
    PALANM_AllocSlotBuffers(fade, bank, 0x200, work->heapId);
    size = rows << 5;
    PALANM_CopyHwPaletteToSlot(fade, bank, 0, size);
    PALANM_BlendChannel(fade, bank, 0, (rows << 20) >> 16, 6, 0);
    buf = PALANM_GetTransWork(fade, bank);
    DC_FlushRange(buf, size);
    if (bank != 1) {
        if (bank == 3)
            func_0207E5D0(buf, 0, size);
    } else {
        func_0207E468(buf, 0, size);
    }
    PALANM_FreeSlotBuffers(fade, bank);
    PALANM_Delete(fade);
}

/* isActive 1: copies the saved palettes to 0x05000600 and 0x05000400 and fades both banks; 0: clears the saved copies. */
void IRCBATTLEMENU_SetSubPaletteActive(IrcBattleMenuWork *work, int isActive)
{
    if (isActive) {
        MI_CpuCopy8((void *)0x05000600, work->subObjPlttCopy, 0x200);
        MI_CpuCopy8((void *)0x05000400, work->subBgPlttCopy, 0x200);
        IRCBATTLEMENU_FadePaletteBank(work, 3, 0xE);
        IRCBATTLEMENU_FadePaletteBank(work, 1, 9);
    } else {
        func_0207E5D0(work->subObjPlttCopy, 0, 0x1C0);
        func_0207E468(work->subBgPlttCopy, 0, 0x120);
    }
}

/* Deletes the time icon if present and creates a new one on the message window. */
void IRCBATTLEMENU_CreateTimeIcon(IrcBattleMenuWork *work)
{
    if (work->timeIcon != 0) {
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
    work->timeIcon = TIME_ICON_CreateNode(work->tcbl, work->msgWin, 15, 16, work->heapId);
}

/* Deletes the time icon and clears the message window. */
void IRCBATTLEMENU_ClearMessageWindow(IrcBattleMenuWork *work)
{
    if (work->timeIcon != 0) {
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
    BMP_MENUWORK_DrawWindowBorder(work->msgWin, 2);
    BMP_WIN_ClearScreen(work->msgWin);
    func_02041B6C(5);
}

/* Closes the message window. */
void IRCBATTLEMENU_DeleteMsgWin(IrcBattleMenuWork *work)
{
    IRCBATTLEMENU_ClearMessageWindow(work);
    BMP_WIN_Delete(work->msgWin);
    work->msgWin = 0;
}

/*
 * Creates "count" button windows on BG 7, each holding the text msgIds[i]
 * centered on (centerX[i], centerY[i]) when those arrays are given.
 */
void IRCBATTLEMENU_CreateButtonWindows(int count, u32 *msgIds, IrcBattleMenuWork *work, IrcBattleWinDesc *descs, int *centerX, int *centerY)
{
    int i;
    int x;
    int y;

    BG_SYS_ClearSlot(7);
    work->menuWinCount = count;
    func_02049B40(0x17, 5, 4, 0x100, 0x20, work->heapId);
    for (i = 0; i < 4; i++) {
        if (work->menuWins[i] != 0) {
            BMP_WIN_ClearScreen(work->menuWins[i]);
            BMP_MENUWORK_DrawWindowBorder(work->menuWins[i], 2);
            BMP_WIN_Delete(work->menuWins[i]);
        }
        work->menuWins[i] = 0;
    }
    for (i = 0; i < count; i++) {
        GF_FONT_SetTextColor(15, 2, 0);
        work->menuWins[i] = BMP_WIN_Create(7, (u8)descs[i].posX, (u8)descs[i].posY, (u8)descs[i].width, (u8)descs[i].height, 8, 0);
        BMP_Clear(BMP_WIN_GetBmp(work->menuWins[i]), 0);
        func_02045CAC(work->msgData, msgIds[i], work->message);
        if (centerX != 0) {
            x = centerX[i] - (func_0201D304(work->message, work->font, 0) >> 1);
        } else {
            x = 0;
        }
        if (centerY != 0) {
            y = centerY[i] - (func_0201D42C(work->message, work->font) >> 1);
        } else {
            y = 0;
        }
        PRINTSYS_Print(BMP_WIN_GetBmp(work->menuWins[i]), x, y, work->message, work->font);
        BMP_WIN_TransferChars(work->menuWins[i]);
        BMP_WIN_MakeScreen(work->menuWins[i]);
    }
    if (work->touchSw != 0) {
        BUTTON_MAN_Delete(work->touchSw);
    }
    work->touchSw = 0;
    func_02041B6C(7);
    func_02040588(7, 1);
}

/* Deletes the touch switch and the button windows. */
void IRCBATTLEMENU_DeleteButtonWindows(IrcBattleMenuWork *work)
{
    int i;

    if (work->touchSw != 0)
        BUTTON_MAN_Delete(work->touchSw);
    work->touchSw = 0;
    for (i = 0; i < 4; i++) {
        if (work->menuWins[i] != 0) {
            BMP_WIN_ClearScreen(work->menuWins[i]);
            func_02041B6C(5);
            BMP_MENUWORK_DrawWindowBorder(work->menuWins[i], 2);
            BMP_WIN_Delete(work->menuWins[i]);
        }
        work->menuWins[i] = 0;
    }
    work->menuWinCount = 0;
}

/* Touch switch callback: for event 0 forwards the button index to work->touchFunc. */
void IRCBATTLEMENU_TouchCallback(u32 index, int event, IrcBattleMenuWork *work)
{
    if (event == 0 && work->touchFunc != 0 && work->touchFunc(index, work) != 0) {
        return;
    }
}

/* Adds rowOffsets[j] to the r, g and b value of color j of each of "rows" palette rows, clamped to 31. */
void IRCBATTLEMENU_BrightenPalette(u16 (*pltt)[16], const u16 *rowOffsets, int rows)
{
    int i;
    int j;
    u16 color;
    u16 red;
    u16 green;
    u16 blue;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < 16; j++) {
            color = pltt[i][j];
            red = color & 0x1F;
            green = (color & 0x3E0) >> 5;
            blue = (color & 0x7C00) >> 10;
            red += rowOffsets[j];
            green += rowOffsets[j];
            blue += rowOffsets[j];
            if (red > 31) {
                red = 31;
            }
            if (green > 31) {
                green = 31;
            }
            if (blue > 31) {
                blue = 31;
            }
            pltt[i][j] = (blue << 10) + (red + (green << 5));
        }
    }
}

/* Loads the message data, font, menu graphics and palettes; the counterpart of IRCBATTLEMENU_FreeMenuGraphics. */
void IRCBATTLEMENU_LoadMenuGraphics(IrcBattleMenuWork *work)
{
    struct ArcHandle *arc;
    void *plttRes;
    struct PaletteData *plttData;

    work->isSaveDone = 0;
    work->message = STRBUF_Create(0x12C, work->heapId);
    work->font = GF_FONT_Create(0x17, 0, 0, 0, work->heapId);
    work->msgData = func_02045B38(0, 2, 0x2E, work->heapId);
    arc = func_020490F4(0x1C, work->heapId);
    func_02049B68(arc, 1, 0, 0, 0, work->heapId);
    work->mainBgChar = func_02049740(arc, 6, 0, 0, 0, work->heapId);
    func_02049990(arc, 0xD, 0, 0, (u16)work->mainBgChar, 0, 0, work->heapId);
    ARC_TOOL_DeleteHandle(arc);
    arc = func_020490F4(0x1D, work->heapId);
    func_02049B68(arc, 2, 4, 0, 0, work->heapId);
    plttRes = func_02049F78(arc, 2, &plttData, work->heapId);
    MI_CpuCopy8(plttData->rawData, work->menuPltt, 0x100);
    MI_CpuCopy8(plttData->rawData, work->menuPlttBright, 0x100);
    IRCBATTLEMENU_BrightenPalette(work->menuPlttBright, sMenuPlttRowOffsets, 8);
    func_020307B0(plttRes);
    func_02049B68(arc, 0, 0, 0, 0, work->heapId);
    work->subBgChar = func_02049740(arc, 4, 4, 0, 0, work->heapId);
    func_02049990(arc, 9, 4, 0, (u16)work->subBgChar, 0, 0, work->heapId);
    func_02049990(arc, 0xB, 6, 0, (u16)work->subBgChar, 0, 0, work->heapId);
    ARC_TOOL_DeleteHandle(arc);
    work->winFrameChar = BMP_MENUWORK_LoadFrameGfx(5, 0xC, 0, work->heapId);
    func_02049B40(0x17, 5, 4, 0x160, 0x20, work->heapId);
}

/* Loads sub BG 6 screen "screenId" from the menu graphics archive. */
void IRCBATTLEMENU_LoadSubBgScreen(IrcBattleMenuWork *work, u32 screenId)
{
    struct ArcHandle *arc;

    arc = func_020490F4(0x1D, work->heapId);
    func_02049990(arc, screenId, 6, 0, (u16)work->subBgChar, 0, 0, work->heapId);
    ARC_TOOL_DeleteHandle(arc);
    func_02040588(6, 1);
}

/* Sequence: builds the top menu (four buttons, five actors). */
void IRCBATTLEMENU_SeqSetupTopMenu(IrcBattleMenuWork *work)
{
    MsgIdRow4 msgIds = sTopMenuMsgIds;

    IRCBATTLEMENU_LoadSubBgScreen(work, 0xB);
    IRCBATTLEMENU_CreateTopMenuActors(work);
    IRCBATTLEMENU_CreateButtonWindows(4, msgIds.id, work, sTopMenuWinDescs, sTopMenuTextCenterX, sTopMenuTextCenterY);
    work->touchSw = BUTTON_MAN_Create(sTopMenuTouchRects, IRCBATTLEMENU_TouchCallback, work, work->heapId);
    work->touchFunc = IRCBATTLEMENU_TouchTopMenu;
    IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqUpdateTouchTop, 0x340);
}

/* Frees what IRCBATTLEMENU_LoadMenuGraphics loaded and resets the BG layers. */
void IRCBATTLEMENU_FreeMenuGraphics(IrcBattleMenuWork *work)
{
    u32 frameChar;

    GF_FONT_SetDefaultTextColor();
    IRCBATTLEMENU_DeleteButtonWindows(work);
    BG_SYS_SetTileUnit(5, 1, 0);
    frameChar = work->winFrameChar;
    BG_SYS_DeleteHalf(5, (u16)frameChar, (u16)(frameChar >> 16));
    func_020403F4(5);
    func_020403F4(4);
    MSGDATA_Delete(work->msgData);
    GF_FONT_Delete(work->font);
    STRBUF_Delete(work->message);
    func_02040588(5, 0);
}

/* Sequence: once the screen fade is done, ends the sequences. */
void IRCBATTLEMENU_SeqWaitFadeEnd(IrcBattleMenuWork *work)
{
    if (WIPE_SYS_EndCheck()) {
        if (work->mode != 0xC) {
            if (GAME_COMM_GetKind(ICA_ANIME_GetField24(IRC_BATTLE_ENTRY_GetGameSys(work->param))) == 0)
                IRCBATTLEMENU_SetSeq(work, 0, 0x361);
        } else {
            IRCBATTLEMENU_SetSeq(work, 0, 0x365);
        }
    }
}

/* Sequence: disables auto comm, starts the screen fade and closes the connection unless the user went back. */
void IRCBATTLEMENU_SeqStartFadeOut(IrcBattleMenuWork *work)
{
    work->noAutoComm = 1;
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, work->heapId);
    if (work->mode != 0xC) {
        if (GAME_COMM_GetKind(ICA_ANIME_GetField24(IRC_BATTLE_ENTRY_GetGameSys(work->param))) != 0) {
            GAME_COMM_RequestExitNoCallback(ICA_ANIME_GetField24(IRC_BATTLE_ENTRY_GetGameSys(work->param)));
        }
    }
    IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqWaitFadeEnd, 0x37C);
}

/* Animation end hook of the top menu: picks the next sequence from the chosen mode. */
void IRCBATTLEMENU_HookTopMenuPressed(IrcBattleMenuWork *work)
{
    if (work->mode == 0xC) {
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqStartFadeOut, 0x38C);
        return;
    }
    if (CONFIG_GetButtonMode(func_0200873C(IRC_BATTLE_ENTRY_GetSaveControl(work->param))) == 1) {
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqSaveQuestion, 0x38F);
        return;
    }
    if (work->mode - 6 <= 2) {
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqStartFadeOut, 0x394);
        return;
    }
    IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqSetupKindMenu, 0x397);
}

/* Sequence: waits for the actor animation. */
void IRCBATTLEMENU_SeqIdleTop(IrcBattleMenuWork *work)
{
}

/* Sequence: plays the press animation of the touched top menu button, then runs IRCBATTLEMENU_HookTopMenuPressed. */
void IRCBATTLEMENU_SeqPressTopButton(IrcBattleMenuWork *work)
{
    ClactAnimEndHook hook;
    u32 i;

    i = work->touchIndex;
    hook.type = 0;
    hook.work = work;
    hook.callback = IRCBATTLEMENU_HookTopMenuPressed;
    if (i == 5) {
        i = 0;
    } else if (i == 6) {
        i = 1;
    } else if (i == 7) {
        i = 3;
    }
    CLACT_SetActorAutoAnim(work->menuActors[i], 1);
    func_0204BA00(work->menuActors[i], &hook);
    CLACT_RestartActorAnim(work->menuActors[i]);
    IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqIdleTop, 0x3BF);
}

/* Sequence: after the "not enough Pokemon" message, closes it and returns to touch input. */
void IRCBATTLEMENU_SeqWaitNotEnoughMsg(IrcBattleMenuWork *work)
{
    if (IRCBATTLEMENU_IsMessageEnd(work) != 0 && TOUCHPANEL_GetTrg() != 0) {
        IRCBATTLEMENU_DeleteMsgWin(work);
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqUpdateTouchTop, 0x3CB);
    }
}

/* Touch handler of the top menu: sets the mode from the pressed button. */
int IRCBATTLEMENU_TouchTopMenu(u32 index, IrcBattleMenuWork *work)
{
    int taken = 0;

    work->touchIndex = index;
    switch (index) {
    case 0:
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x73B);
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqPressTopButton, 0x3DE);
        taken = 1;
        work->mode = 1;
        break;
    case 1:
    case 6:
        if ((int)POKEPARTY_GetNonEggCount(GAME_DATA_GetMyParty(work->gameData)) < 2) {
            func_02045CAC(work->msgData, 0x2C, work->message);
            IRCBATTLEMENU_PrintMessage(work, 0);
            IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqWaitNotEnoughMsg, 0x3EA);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x73B);
            work->mode = 6;
            IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqPressTopButton, 0x3F0);
            taken = 1;
        }
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x73B);
        work->mode = 8;
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqPressTopButton, 0x3F6);
        taken = 1;
        break;
    case 3:
    case 7:
        GFL_USE_PlaySeDefaultVolume(0x73B);
        work->mode = 7;
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqPressTopButton, 0x3FD);
        taken = 1;
        break;
    case 4:
        GFL_USE_PlaySeDefaultVolume(0x73C);
        work->mode = 0xC;
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqPressTopButton, 0x404);
        break;
    }
    return taken;
}

/* Sequence: updates the touch switch each frame once the screen fade is done. */
void IRCBATTLEMENU_SeqUpdateTouchTop(IrcBattleMenuWork *work)
{
    if (WIPE_SYS_EndCheck() != 0) {
        BUTTON_MAN_UpdateSlots(work->touchSw);
    }
}

/* Sequence: builds the kind menu (two buttons, three actors). */
void IRCBATTLEMENU_SeqSetupKindMenu(IrcBattleMenuWork *work)
{
    MsgIdRow2 msgIds = sKindMenuMsgIds;

    IRCBATTLEMENU_CreateKindMenuActors(work);
    IRCBATTLEMENU_LoadSubBgScreen(work, 0xC);
    IRCBATTLEMENU_CreateButtonWindows(2, msgIds.id, work, sKindMenuWinDescs, 0, 0);
    work->touchSw = BUTTON_MAN_Create(sKindMenuTouchRects, IRCBATTLEMENU_TouchCallback, work, work->heapId);
    work->touchFunc = IRCBATTLEMENU_TouchKindMenu;
    IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqUpdateTouchSub, 0x432);
}

/* Animation end hook of the kind menu: picks the next menu from the mode and the party check. */
void IRCBATTLEMENU_HookKindMenuPressed(IrcBattleMenuWork *work)
{
    if (work->mode == 5) {
        if (BATTLE_BOX_HasMon(BATTLE_BOX_GetFromSave(work->param->saveData)) != 0) {
            IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqSetupPartyMenu, 0x443);
        } else {
            IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqStartFadeOut, 0x446);
        }
    } else {
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqSetupRuleMenu, 0x44D);
    }
}

/* Sequence: waits for the actor animation. */
void IRCBATTLEMENU_SeqIdleKind(IrcBattleMenuWork *work)
{
}

/* Sequence: plays the press animation of the kind menu button, then runs IRCBATTLEMENU_HookKindMenuPressed. */
void IRCBATTLEMENU_SeqPressKindButton(IrcBattleMenuWork *work)
{
    ClactAnimEndHook hook;
    int i;

    i = 0;
    if (work->mode == 5) {
        i = 1;
    }
    hook.type = 0;
    hook.work = work;
    hook.callback = IRCBATTLEMENU_HookKindMenuPressed;
    CLACT_SetActorAutoAnim(work->menuActors[i], 1);
    func_0204BA00(work->menuActors[i], &hook);
    CLACT_RestartActorAnim(work->menuActors[i]);
    IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqIdleKind, 0x471);
}

/* Animation end hook of the kind menu back button: returns to the top menu. */
void IRCBATTLEMENU_HookKindBackPressed(IrcBattleMenuWork *work)
{
    IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqSetupTopMenu, 0x47A);
}

/* Sequence: waits for the actor animation. */
void IRCBATTLEMENU_SeqIdleKindBack(IrcBattleMenuWork *work)
{
}

/* Sequence: plays the press animation of the pressed button, then runs IRCBATTLEMENU_HookKindBackPressed. */
void IRCBATTLEMENU_SeqPressKindBack(IrcBattleMenuWork *work)
{
    ClactAnimEndHook hook;

    hook.type = 0;
    hook.work = work;
    hook.callback = IRCBATTLEMENU_HookKindBackPressed;
    CLACT_SetActorAutoAnim(work->menuActors[work->touchIndex], 1);
    func_0204BA00(work->menuActors[work->touchIndex], &hook);
    CLACT_RestartActorAnim(work->menuActors[work->touchIndex]);
    IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqIdleKindBack, 0x492);
}

/* Touch handler of the kind menu. */
int IRCBATTLEMENU_TouchKindMenu(u32 index, IrcBattleMenuWork *work)
{
    int taken = 1;

    work->touchIndex = index;
    switch (index) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x73B);
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqPressKindButton, 0x4A3);
        break;
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x73B);
        work->mode = 5;
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqPressKindButton, 0x4A9);
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x73C);
        work->mode = 0xC;
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqPressKindBack, 0x4AF);
        break;
    default:
        taken = 1;
        break;
    }
    return taken;
}

/* Sequence: builds the rule menu (four buttons, five actors). */
void IRCBATTLEMENU_SeqSetupRuleMenu(IrcBattleMenuWork *work)
{
    MsgIdRow4 msgIds = sRuleMenuMsgIds;

    IRCBATTLEMENU_CreateMainMenuActors(work);
    IRCBATTLEMENU_LoadSubBgScreen(work, 0xD);
    IRCBATTLEMENU_CreateButtonWindows(4, msgIds.id, work, sRuleMenuWinDescs, 0, 0);
    work->touchSw = BUTTON_MAN_Create(sRuleMenuTouchRects, IRCBATTLEMENU_TouchCallback, work, work->heapId);
    work->touchFunc = IRCBATTLEMENU_TouchRuleMenu;
    IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqUpdateTouchSub, 0x4CC);
}

/* Animation end hook of the party menu: picks the next menu from the party mode. */
void IRCBATTLEMENU_HookPartyMenuPressed(IrcBattleMenuWork *work)
{
    if (work->partyMode == 2) {
        if (work->mode == 5) {
            work->mode = 1;
            IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqSetupKindMenu, 0x4DD);
        } else {
            IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqSetupRuleMenu, 0x4E1);
        }
    } else {
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqStartFadeOut, 0x4E5);
    }
}

/* Sequence: waits for the actor animation. */
void IRCBATTLEMENU_SeqIdleParty(IrcBattleMenuWork *work)
{
}

/* Sequence: plays the press animation of the party menu button, then runs IRCBATTLEMENU_HookPartyMenuPressed. */
void IRCBATTLEMENU_SeqPressPartyButton(IrcBattleMenuWork *work)
{
    ActorRow3 actorIndex = sPartyMenuActorIndex;
    ClactAnimEndHook hook;
    int i;

    i = actorIndex.v[work->partyMode];
    hook.type = 0;
    hook.work = work;
    hook.callback = IRCBATTLEMENU_HookPartyMenuPressed;
    CLACT_SetActorAutoAnim(work->menuActors[i], 1);
    func_0204BA00(work->menuActors[i], &hook);
    CLACT_RestartActorAnim(work->menuActors[i]);
    IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqIdleParty, 0x504);
}

/* Sequence: updates the touch switch each frame. */
void IRCBATTLEMENU_SeqUpdateTouchParty(IrcBattleMenuWork *work)
{
    BUTTON_MAN_UpdateSlots(work->touchSw);
}

/* Touch handler of the party menu: sets the party mode from the pressed button. */
int IRCBATTLEMENU_TouchPartyMenu(u32 index, IrcBattleMenuWork *work)
{
    int taken = 0;

    work->touchIndex = index;
    switch (index) {
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x73B);
        work->partyMode = 0;
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqPressPartyButton, 0x524);
        taken = 1;
        break;
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x73B);
        taken = 1;
        work->partyMode = 1;
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqPressPartyButton, 0x52A);
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x73C);
        work->partyMode = 2;
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqPressPartyButton, 0x530);
        break;
    }
    return taken;
}

/* Sequence: builds the party menu (two buttons, three actors). */
void IRCBATTLEMENU_SeqSetupPartyMenu(IrcBattleMenuWork *work)
{
    MsgIdRow2 msgIds = sPartyMenuMsgIds;

    IRCBATTLEMENU_CreateSubMenuActors(work);
    IRCBATTLEMENU_LoadSubBgScreen(work, 0xD);
    IRCBATTLEMENU_CreateButtonWindows(2, msgIds.id, work, sKindMenuWinDescs, 0, 0);
    work->touchSw = BUTTON_MAN_Create(sPartyMenuTouchRects, IRCBATTLEMENU_TouchCallback, work, work->heapId);
    work->touchFunc = IRCBATTLEMENU_TouchPartyMenu;
    IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqUpdateTouchParty, 0x54D);
}

/* Animation end hook of the rule menu: picks the next menu from the mode and the party check. */
void IRCBATTLEMENU_HookRuleMenuPressed(IrcBattleMenuWork *work)
{
    if (work->mode == 0xC) {
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqSetupKindMenu, 0x558);
    } else {
        if (BATTLE_BOX_HasMon(BATTLE_BOX_GetFromSave(work->param->saveData)) != 0) {
            IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqSetupPartyMenu, 0x55D);
        } else {
            IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqStartFadeOut, 0x560);
        }
    }
}

/* Sequence: waits for the actor animation. */
void IRCBATTLEMENU_SeqIdleRule(IrcBattleMenuWork *work)
{
}

/* Sequence: plays the press animation of the rule menu button for the chosen mode, then runs IRCBATTLEMENU_HookRuleMenuPressed. */
void IRCBATTLEMENU_SeqPressRuleButton(IrcBattleMenuWork *work)
{
    ClactAnimEndHook hook;
    int i;

    switch (work->mode) {
    case 1:
        i = 0;
        break;
    case 2:
        i = 1;
        break;
    case 3:
        i = 2;
        break;
    case 4:
        i = 3;
        break;
    default:
        i = 4;
        break;
    }
    hook.type = 0;
    hook.work = work;
    hook.callback = IRCBATTLEMENU_HookRuleMenuPressed;
    CLACT_SetActorAutoAnim(work->menuActors[i], 1);
    func_0204BA00(work->menuActors[i], &hook);
    CLACT_RestartActorAnim(work->menuActors[i]);
    IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqIdleRule, 0x58F);
}

/* Touch handler of the rule menu: sets the mode (1 to 4, or 12 for back) from the pressed button. */
int IRCBATTLEMENU_TouchRuleMenu(u32 index, IrcBattleMenuWork *work)
{
    int taken = 0;

    work->touchIndex = index;
    switch (index) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x73B);
        taken = 1;
        work->mode = 1;
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqPressRuleButton, 0x5B1);
        break;
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x73B);
        work->mode = 2;
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqPressRuleButton, 0x5B7);
        taken = 1;
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x73B);
        work->mode = 3;
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqPressRuleButton, 0x5BD);
        taken = 1;
        break;
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x73B);
        work->mode = 4;
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqPressRuleButton, 0x5C3);
        taken = 1;
        break;
    case 4:
        GFL_USE_PlaySeDefaultVolume(0x73C);
        work->mode = 0xC;
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqPressRuleButton, 0x5C9);
        break;
    }
    return taken;
}

/* Sequence: updates the touch switch each frame. */
void IRCBATTLEMENU_SeqUpdateTouchSub(IrcBattleMenuWork *work)
{
    BUTTON_MAN_UpdateSlots(work->touchSw);
}

/* Loads the actor resources: character, palette and cell animation (stored in res[3], res[1], res[5]). */
void IRCBATTLEMENU_LoadActorResources(IrcBattleMenuWork *work)
{
    struct ArcHandle *arc;

    arc = func_020490F4(0x1D, work->heapId);
    work->res[3] = CLACT_RegisterCharacter(arc, 5, 0, 1, work->heapId);
    work->res[1] = CLACT_RegisterPaletteEx(arc, 3, 1, 0, 0, 0xA, work->heapId);
    work->res[5] = CLACT_RegisterCellAnim(arc, 7, 0x10, work->heapId);
    ARC_TOOL_DeleteHandle(arc);
}

/* Deletes the menu actors. */
void IRCBATTLEMENU_DeleteMenuActors(IrcBattleMenuWork *work)
{
    int i;

    for (i = 0; i < 5; i++) {
        if (work->menuActors[i] != 0) {
            CLACT_DeleteActor(work->menuActors[i]);
            work->menuActors[i] = 0;
        }
    }
}

/* Creates the five actors of the top menu. */
void IRCBATTLEMENU_CreateTopMenuActors(IrcBattleMenuWork *work)
{
    ActorRow5 posX = sTopMenuActorPosX;
    ActorRow5 posY = sTopMenuActorPosY;
    ActorRow5 anim = sTopMenuActorAnim;
    ClactActorInit init;
    int i;

    IRCBATTLEMENU_DeleteMenuActors(work);
    for (i = 0; i < 5; i++) {
        init.posX = posX.v[i];
        init.posY = posY.v[i];
        init.anim = anim.v[i];
        init.softPri = 0;
        init.bgPri = 1;
        work->menuActors[i] = CLACT_CreateActor(work->clactUnit, work->res[3], work->res[1], work->res[5], &init, 1, work->heapId);
        CLACT_SetActorAutoAnim(work->menuActors[i], 0);
        CLACT_SetActorDrawEnable(work->menuActors[i], 1);
        CLACT_SetActorObjMode(work->menuActors[i], 1);
    }
}

/* Creates the three actors of the kind menu. */
void IRCBATTLEMENU_CreateKindMenuActors(IrcBattleMenuWork *work)
{
    ActorRow3 posX = sKindMenuActorPosX;
    ActorRow3 posY = sKindMenuActorPosY;
    ActorRow3 anim = sKindMenuActorAnim;
    ClactActorInit init;
    int i;

    IRCBATTLEMENU_DeleteMenuActors(work);
    for (i = 0; i < 3; i++) {
        init.posX = posX.v[i];
        init.posY = posY.v[i];
        init.anim = anim.v[i];
        init.softPri = 0;
        init.bgPri = 1;
        work->menuActors[i] = CLACT_CreateActor(work->clactUnit, work->res[3], work->res[1], work->res[5], &init, 1, work->heapId);
        CLACT_SetActorAutoAnim(work->menuActors[i], 0);
        CLACT_SetActorDrawEnable(work->menuActors[i], 1);
        CLACT_SetActorObjMode(work->menuActors[i], 1);
    }
}

/*
 * Creates the five actors of the main menu screen from the position and
 * animation rows sMainMenuActorPosX (x), sMainMenuActorPosY (y) and sMainMenuActorAnim (animation).
 */
void IRCBATTLEMENU_CreateMainMenuActors(IrcBattleMenuWork *work)
{
    ActorRow5 posX = sMainMenuActorPosX;
    ActorRow5 posY = sMainMenuActorPosY;
    ActorRow5 anim = sMainMenuActorAnim;
    ClactActorInit init;
    int i;

    IRCBATTLEMENU_DeleteMenuActors(work);
    for (i = 0; i < 5; i++) {
        init.posX = posX.v[i];
        init.posY = posY.v[i];
        init.anim = anim.v[i];
        init.softPri = 0;
        init.bgPri = 1;
        work->menuActors[i] = CLACT_CreateActor(work->clactUnit, work->res[3], work->res[1], work->res[5], &init, 1, work->heapId);
        CLACT_SetActorAutoAnim(work->menuActors[i], 0);
        CLACT_SetActorDrawEnable(work->menuActors[i], 1);
        CLACT_SetActorObjMode(work->menuActors[i], 1);
    }
}

/* Same as IRCBATTLEMENU_CreateMainMenuActors for the three actors of the second menu screen. */
void IRCBATTLEMENU_CreateSubMenuActors(IrcBattleMenuWork *work)
{
    ActorRow3 posX = sSubMenuActorPosX;
    ActorRow3 posY = sSubMenuActorPosY;
    ActorRow3 anim = sSubMenuActorAnim;
    ClactActorInit init;
    int i;

    IRCBATTLEMENU_DeleteMenuActors(work);
    for (i = 0; i < 3; i++) {
        init.posX = posX.v[i];
        init.posY = posY.v[i];
        init.anim = anim.v[i];
        init.softPri = 0;
        init.bgPri = 1;
        work->menuActors[i] = CLACT_CreateActor(work->clactUnit, work->res[3], work->res[1], work->res[5], &init, 1, work->heapId);
        CLACT_SetActorAutoAnim(work->menuActors[i], 0);
        CLACT_SetActorDrawEnable(work->menuActors[i], 1);
        CLACT_SetActorObjMode(work->menuActors[i], 1);
    }
}

/* An empty function: the decoration it would create was left out. */
void IRCBATTLEMENU_CreateDecoration(IrcBattleMenuWork *work, u32 posX, u32 posY, u32 index, u32 anim)
{
}

/* Deletes all actors and releases the six cell resources (palette, character, cell animation). */
void IRCBATTLEMENU_DeleteClact(IrcBattleMenuWork *work)
{
    int i;

    for (i = 0; i < 5; i++) {
        if (work->menuActors[i] != 0) {
            CLACT_DeleteActor(work->menuActors[i]);
            work->menuActors[i] = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (work->extraActors[i] != 0) {
            CLACT_DeleteActor(work->extraActors[i]);
            work->extraActors[i] = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (work->res[i] != 0) {
            CLACT_ReleasePalette(work->res[i]);
        }
    }
    for (; i < 4; i++) {
        if (work->res[i] != 0) {
            CLACT_ReleaseCharacter(work->res[i]);
        }
    }
    for (; i < 6; i++) {
        if (work->res[i] != 0) {
            CLACT_ReleaseCellAnim(work->res[i]);
        }
    }
}

/* Opens the yes/no task menu (strings 26 and 27). */
void IRCBATTLEMENU_OpenYesNoMenu(IrcBattleMenuWork *work)
{
    TaskMenuInit init;

    init.heapId = work->heapId;
    init.itemNum = 2;
    init.itemWork = work->yesNoItems;
    init.posType = 1;
    init.charPosX = 0x20;
    init.charPosY = 0xE;
    init.width = 0xD;
    init.height = 3;
    work->yesNoItems[0].str = STRBUF_Create(100, work->heapId);
    func_02045CAC(work->msgData, 26, work->yesNoItems[0].str);
    work->yesNoItems[0].msgColor = 0x39E3;
    work->yesNoItems[1].str = STRBUF_Create(100, work->heapId);
    func_02045CAC(work->msgData, 27, work->yesNoItems[1].str);
    work->yesNoItems[1].msgColor = 0x39E3;
    work->yesNoItems[0].type = 0;
    work->yesNoItems[1].type = 0;
    work->yesNoMenu = APP_TASKMENU_OpenMenu(&init, work->taskMenuRes);
    APP_TASKMENU_SetDisableKey(work->yesNoMenu, 1);
    STRBUF_Delete(work->yesNoItems[0].str);
    STRBUF_Delete(work->yesNoItems[1].str);
}

/*
 * Runs the message print stream; returns 1 when no stream is active.
 */
int IRCBATTLEMENU_IsMessageEnd(IrcBattleMenuWork *work)
{
    if (work->printStream != 0) {
        if (work->msgWin != 0)
            APP_KEYCURSOR_Update(work->keyCursor, work->printStream, work->msgWin);
        switch (PRINTSYS_PrintStreamGetState(work->printStream)) {
        case 2:
            PRINTSYS_PrintStreamDelete(work->printStream);
            work->printStream = 0;
            break;
        case 1:
            if (TOUCHPANEL_GetTrg() != 0) {
                GFL_USE_PlaySeDefaultVolume(0x547);
                PRINTSYS_PrintStreamReleasePause(work->printStream);
            }
            break;
        case 0:
            if (TOUCHPANEL_GetCont() != 0)
                PRINTSYS_PrintStreamShortWait(work->printStream, 0);
            break;
        }
        return 0;
    }
    return 1;
}

/* Prints work->message in the message window, streamed or at once. */
void IRCBATTLEMENU_PrintMessage(IrcBattleMenuWork *work, u32 isInstant)
{
    struct BmpWin *win;

    if (work->msgWin == 0) {
        work->msgWin = BMP_WIN_Create(5, 1, 3, 30, 4, 11, 1);
    }
    win = work->msgWin;
    BMP_Clear(BMP_WIN_GetBmp(win), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    if (isInstant == 0) {
        work->printStream = PRINTSYS_PrintStream(win, 0, 0, work->message, work->font, MSG_SPEED_GetWait(), work->tcbl, 2, work->heapId, 15);
    } else {
        PRINTSYS_Print(BMP_WIN_GetBmp(win), 0, 0, work->message, work->font);
        work->printStream = 0;
    }
    BMP_MENUWORK_DrawWindow(win, 1, (u16)work->winFrameChar, 12);
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    func_02041B6C(5);
}

/* Shows the save question (string 25). */
void IRCBATTLEMENU_SeqSaveQuestion(IrcBattleMenuWork *work)
{
    IRCBATTLEMENU_SetSubPaletteActive(work, 1);
    BG_SYS_ClearLayerEx(5, 0);
    func_02045CAC(work->msgData, 25, work->message);
    IRCBATTLEMENU_PrintMessage(work, 0);
    IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqSaveQuestionWait, 0x761);
}

/* Runs the save; when it ends, goes on to the chosen battle mode. */
void IRCBATTLEMENU_SeqSaveMain(IrcBattleMenuWork *work)
{
    if (GAME_DATA_SaveMain(work->gameData) == 2) {
        IRCBATTLEMENU_SetSubPaletteActive(work, 0);
        BMP_MENUWORK_DrawWindowBorder(work->msgWin, 2);
        BMP_WIN_ClearScreen(work->msgWin);
        func_02041B6C(5);
        if (work->mode == 1) {
            IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqSetupKindMenu, 0x776);
        } else {
            IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqStartFadeOut, 0x779);
        }
        work->isSaveDone = 1;
    }
}

/* Waits for the "saving" message, then starts the save. */
void IRCBATTLEMENU_SeqSaveStart(IrcBattleMenuWork *work)
{
    if (IRCBATTLEMENU_IsMessageEnd(work) != 0) {
        GAME_DATA_SaveStart(work->gameData);
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqSaveMain, 0x78E);
    }
}

/* Waits for the message and a touch, then leaves the menu (mode 12). */
void IRCBATTLEMENU_SeqWaitTouchExit(IrcBattleMenuWork *work)
{
    if (IRCBATTLEMENU_IsMessageEnd(work) != 0 && TOUCHPANEL_GetTrg() != 0) {
        IRCBATTLEMENU_SetSubPaletteActive(work, 0);
        BG_SYS_ClearSlot(3);
        IRCBATTLEMENU_DeleteMsgWin(work);
        work->mode = 12;
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqUpdateTouchTop, 0x7a2);
    }
}

/* Handles the yes/no answer to the save question. */
void IRCBATTLEMENU_SeqSaveYesNo(IrcBattleMenuWork *work)
{
    if (APP_TASKMENU_IsFinish(work->yesNoMenu) != 0) {
        if (APP_TASKMENU_GetCursorPos(work->yesNoMenu) == 0) {
            GAME_DATA_GetSaveControl(work->gameData);
            if (func_020071F0() != 0) {
                func_02045CAC(work->msgData, 0x2d, work->message);
                IRCBATTLEMENU_PrintMessage(work, 0);
                IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqWaitTouchExit, 0x7b9);
            } else {
                func_02045CAC(work->msgData, 0x1c, work->message);
                IRCBATTLEMENU_PrintMessage(work, 1);
                IRCBATTLEMENU_CreateTimeIcon(work);
                IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqSaveStart, 0x7bf);
            }
        } else {
            IRCBATTLEMENU_SetSubPaletteActive(work, 0);
            BG_SYS_ClearSlot(3);
            IRCBATTLEMENU_DeleteMsgWin(work);
            work->mode = 12;
            IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqUpdateTouchTop, 0x7c7);
        }
        APP_TASKMENU_CloseMenu(work->yesNoMenu);
        work->yesNoMenu = 0;
    }
}

/* Waits for the save question, then opens the yes/no menu. */
void IRCBATTLEMENU_SeqSaveQuestionWait(IrcBattleMenuWork *work)
{
    if (IRCBATTLEMENU_IsMessageEnd(work) != 0) {
        IRCBATTLEMENU_OpenYesNoMenu(work);
        IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqSaveYesNo, 0x7DC);
    }
}

/* VBlank task: tail call into the ARM9 cell actor system. */
void IRCBATTLEMENU_VBlankTask(void)
{
    CLACT_VBlankSystem();
}

/* Proc init: heap, display, cell actors, print system, first sequence. */
int IRCBATTLEMENU_Init(struct ProcWork *proc, u32 seq, IrcBattleEntryWork *param)
{
    IrcBattleMenuWork *work;

    GFL_HEAP_CreateChildHeap(1, 0x1f, 0x18000);
    work = PROCSYS_AllocProcWork(proc, 0x308, 0x1f);
    MI_CpuFill8(work, 0, 0x308);
    work->heapId = 0x1f;
    BG_SYS_Create(work->heapId);
    BMP_WIN_Init(work->heapId);
    GF_FONT_InitTextColor();
    BG_SYS_SetVramBanks((const struct DispVram *)sVramBank);
    {
        DispSetup setup = sGraphicsMode;
        BG_SYS_SetGraphicsMode((struct DispConfig *)(&setup));
    }
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    CLACT_InitSystem((const struct ClactSysInit *)gClActorInitParam, (const struct DispVram *)sVramBank, work->heapId);
    work->clactUnit = CLACT_CreateUnit(0x28, 0, work->heapId);
    work->vblankTask = func_020056A0(IRCBATTLEMENU_VBlankTask, work, 0);
    IRCBATTLEMENU_InitBgLayers(work);
    IRCBATTLEMENU_LoadMenuGraphics(work);
    work->subObjPlttCopy = func_02030734(work->heapId, 0x200, 0, (const char *)sIrcBattleMenuFileName, 0x829);
    work->subBgPlttCopy = func_02030734(work->heapId, 0x200, 0, (const char *)sIrcBattleMenuFileName, 0x82A);
    work->tcbl = TCBL_Create(work->heapId, work->heapId, 2, 0);
    work->keyCursor = func_02028590(0xf, 0, 1, work->heapId);
    work->printQue = PRINTSYS_QUE_Create(work->heapId);
    work->taskMenuRes = APP_TASKMENU_RES_Create(5, 9, work->font, work->printQue, work->heapId);
    IRCBATTLEMENU_LoadActorResources(work);
    IRCBATTLEMENU_CreateDecoration(work, 0x39, 0x9a, 0, 10);
    IRCBATTLEMENU_CreateDecoration(work, 0xc8, 0x26, 1, 11);
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, work->heapId);
    IRCBATTLEMENU_SetSeq(work, IRCBATTLEMENU_SeqSetupTopMenu, 0x83B);
    work->param = (struct IrcBattleEntryWork *)param;
    work->gameData = ICA_ANIME_GetField1C(IRC_BATTLE_ENTRY_GetGameSys((IrcBattleEntryWork *)work->param));
    func_0207D63C(0x04001050, 4, 1, 0xf, 4);
    GFL_NET_RestartWithDefaultTimeout(0, work->heapId);
    BG_SYS_SetMainVisiblePlanes(0x13);
    BG_SYS_SetSubVisiblePlanes(0x17);
    func_0207D63C(0x04000050, 0x10, 3, 9, 0xe);
    return 1;
}

/* Proc main: runs the current sequence until it clears seqFunc. */
u32 IRCBATTLEMENU_Main(u32 proc, u32 seq, u32 param, IrcBattleMenuWork *work)
{
    u32 ret;
    IrcBattleMenuSeqFunc seqFunc;

    seqFunc = work->seqFunc;
    ret = 1;
    WIH_DWC_PollStatus(GAME_DATA_GetField1A0(work->gameData));
    if (seqFunc != 0) {
        seqFunc(work);
        ret = 0;
    }
    if (work->yesNoMenu != 0) {
        APP_TASKMENU_UpdateMenu(work->yesNoMenu);
    }
    if (work->taskMenuWin != 0) {
        APP_TASKMENU_WIN_Update(work->taskMenuWin);
    }
    func_02040618(4, 3, work->bgAnimCount);
    work->bgAnimCount = work->bgAnimCount - 1;
    TCBL_Main(work->tcbl);
    PRINTSYS_QUE_Main(work->printQue);
    CLACT_DrawSystem();
    if (work->noAutoComm == 0) {
        GAMESYSTEM_TryStartAutoComm(IRC_BATTLE_ENTRY_GetGameSys((IrcBattleEntryWork *)work->param));
    }
    if (WIPE_SYS_EndCheck() != 0) {
        if (ICA_ANIME_GetUnk330(IRC_BATTLE_ENTRY_GetGameSys((IrcBattleEntryWork *)work->param)) != 0) {
            work->mode = 12;
            ret = 1;
            WIPE_SetBrightnessFadeOut(0, 0);
            WIPE_SetBrightnessFadeOut(1, 0);
        }
    }
    return ret;
}

/* Proc exit: hands the result to the entry event and frees everything. */
int IRCBATTLEMENU_Exit(struct ProcWork *proc, u32 seq, IrcBattleEntryWork *param, IrcBattleMenuWork *work)
{
    if (!WIPE_SYS_EndCheck()) {
        return 0;
    }
    IRCBATTLEMENU_FreeMenuGraphics(work);
    IRC_BATTLE_ENTRY_SetMode(param, work->mode);
    param->partyMode = work->partyMode;
    if (work->timeIcon != 0) {
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
    func_020307B0(work->subObjPlttCopy);
    func_020307B0(work->subBgPlttCopy);
    IRCBATTLEMENU_DeleteClact(work);
    if (work->printStream != 0) {
        PRINTSYS_PrintStreamDelete(work->printStream);
    }
    APP_KEYCURSOR_Delete(work->keyCursor);
    TCBL_Destroy(work->tcbl);
    func_020403F4(7);
    PRINTSYS_QUE_Clear(work->printQue);
    PRINTSYS_QUE_Delete(work->printQue);
    if (work->msgWin != 0) {
        BMP_WIN_Delete(work->msgWin);
    }
    if (work->yesNoMenu != 0) {
        APP_TASKMENU_CloseMenu(work->yesNoMenu);
        work->yesNoMenu = 0;
    }
    if (work->taskMenuWin != 0) {
        APP_TASKMENU_WIN_Delete(work->taskMenuWin);
    }
    APP_TASKMENU_RES_Delete(work->taskMenuRes);
    func_02030EAC((struct TaskNode *)work->vblankTask);
    CLACT_DeleteUnit(work->clactUnit);
    CLACT_ExitSystem();
    BMP_WIN_Exit();
    BG_SYS_Delete();
    func_020315D4(proc);
    GFL_HEAP_DeleteChecked(0x1f);
    return 1;
}
