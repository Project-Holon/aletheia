/*
 * file:     gsync_menu.c
 * unit:     yes
 * function: GSYNC_MENU_SetStateFunc, GSYNC_MENU_ChangeState, GSYNC_MENU_InitBgLayers, GSYNC_MENU_RestartTimeIcon, GSYNC_MENU_AddPaletteEntries, GSYNC_MENU_StateStartFadeOut, GSYNC_MENU_StateWaitMenuSelect, GSYNC_MENU_StateOpenYesNoAfterMessage, GSYNC_MENU_OnButtonAnimEnd, GSYNC_MENU_NoOp, GSYNC_MENU_CreateButtonWindows, GSYNC_MENU_DeleteButtonWindows, GSYNC_MENU_RunButtonCallback, GSYNC_MENU_CreateActors, GSYNC_MENU_LoadResources, GSYNC_MENU_StateSetupButtons, GSYNC_MENU_FreeResources, GSYNC_MENU_StateWaitFadeOut, GSYNC_MENU_StateWaitTouchAfterMessage, GSYNC_MENU_StatePlayButtonAnim, GSYNC_MENU_OnButtonPressed, GSYNC_MENU_SetCursorAnimIfChanged, GSYNC_MENU_UpdateCursorAnimFromKeys, GSYNC_MENU_StateButtonsActive, GSYNC_MENU_FadePaletteSlot, GSYNC_MENU_SetPaletteFade, GSYNC_MENU_OpenYesNoMenu, GSYNC_MENU_HideMessage, GSYNC_MENU_DeleteMessageWindow, GSYNC_MENU_UpdateMessageStream, GSYNC_MENU_PrintMessage, GSYNC_MENU_PrintMessageNoStream, GSYNC_MENU_StatePrintConfirmMessage, GSYNC_MENU_StateSaveFinish, GSYNC_MENU_StateSaveStart, GSYNC_MENU_StateConfirmSelect, GSYNC_MENU_StateOpenConfirmMenu, GSYNC_MENU_VBlank, GSYNC_MENU_ProcInit, GSYNC_MENU_ProcMain, GSYNC_MENU_ProcExit
 * address:  0x021D4240
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from gsync_state.c by tools/splitfile.py.
 *
 * symbols:
 *   d_021DA690 0x021DA690 data a4
 *   d_021DA6B0 0x021DA6B0 data a4
 *   d_021DA6D0 0x021DA6D0 data a4
 *   d_021DA6F0 0x021DA6F0 data a4
 *   d_021DA710 0x021DA710 data a4
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   TIME_ICON_CreateNode 0x0202EE8C thumb
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   CLACT_ResetActorAnimCommand 0x0204BA10 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   ARC_UTIL_UploadPaletteFromArchiveWhole  0x02049B40  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   GF_FONT_MeasureWidestLine  0x0201D304  thumb
 *   GF_FONT_CountLines  0x0201D42C  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BUTTON_MAN_Delete  0x02051C6C  arm
 *   BG_SYS_SetFlagField06 0x02041B6C arm
 *   d_021DA638 0x021DA638 data a1
 *   d_021DA634 0x021DA634 data a1
 *   d_021DA63C 0x021DA63C data a1
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   STRBUF_Create 0x020457B0 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   ARC_UTIL_RegisterObjCharFromHandle 0x02049740 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   d_021DA9D0 0x021DA9D0 data a4
 *   BUTTON_MAN_Create 0x02051B84 arm
 *   sGsyncMenuButtonWinDefs 0x021DA9C0 data a4
 *   d_021DA640 0x021DA640 data a4
 *   d_021DA648 0x021DA648 data a4
 *   BG_SYS_SetTileUnit 0x02040DA8 arm
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   STRBUF_Delete 0x02045808 arm
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   ICA_ANIME_GetField24 0x02012138 thumb
 *   GAME_COMM_GetKind 0x02026454 thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CLACT_ApplyActorAnimCommand 0x0204BA00 arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   BUTTON_MAN_UpdateSlots  0x02051C88  arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   PALANM_BlendChannel 0x02021FD8 thumb
 *   PALANM_GetTransWork 0x02021730 thumb
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   GXS_LoadOBJPltt 0x0207E5D0 arm
 *   GXS_LoadBGPltt 0x0207E468 arm
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   APP_TASKMENU_SetDisableKey 0x02027CD8 thumb
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BG_SYS_ClearLayerEx 0x02041570 arm
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   GX_DispOn 0x0207D46C arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   TCBL_Create 0x0203101C arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   UI_SetInputMode 0x020355D8 arm
 *   d_021DA9F0 0x021DA9F0 data a4
 *   d_021DA680 0x021DA680 data a4
 *   d_021DA658 0x021DA658 data a4
 *   d_021DAA20 0x021DAA20 data a1
 *   ICA_ANIME_GetUnk330 0x02012204 thumb
 *   TCBL_Main 0x020310C4 arm
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   TCBL_Destroy 0x02031140 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   STRBUF_Clear 0x0204581C arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIH_DWC_PollStatus  0x0201058C  thumb  arm9
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb  arm9
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb  arm9
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb  arm9
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb  arm9
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb  arm9
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb  arm9
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb  arm9
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 *   APP_KEYCURSOR_Delete  0x02028604  thumb  arm9
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 *   GF_FONT_InitTextColor  0x0201DD60  thumb  arm9
 *   APP_KEYCURSOR_CreateDefault  0x02028590  thumb  arm9
 *   SAVE_CONTROL_WouldOverwriteSave  0x020071F0  thumb  arm9
 */
#include "gsync_menu_types.h"

/* Window rectangle of a button, in tiles. */
typedef struct ButtonWinDef {
    u32 x;
    u32 y;
    u32 width;
    u32 height;
} ButtonWinDef;

/* Actor spawn position for the menu actors (same 8-byte layout as ActorSpawnPos). */
struct MenuActorSpawnPos { u16 x, y, z; u8 mode, space; };

/* Three one-byte coordinates of one menu actor, read from the per-actor tables. */
struct ActorCoordTriple { u8 coords[3]; };

struct DispConfigWords { u32 words[4]; };

extern void BG_SYS_InitBgLayer(u32, const struct BgTemplate *, u32);

extern void BG_SYS_FreeSlot(u32);

extern void BG_SYS_PushTile(u32);

extern void BG_SYS_SetVisibleLayer(int, u16);

extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);

extern void BG_SYS_Init(u32, u32, u32, u32);

extern void BG_SYS_SetTileEntry(u32, u32, u32, u32, u8, u8, u8);

extern void TIME_ICON_Delete(u8 *);

extern u8 *TIME_ICON_CreateNode(void *tcbl, void *window, u8, u8, u16 heapId);

extern void WIPE_SYS_Start(void *, u32, u32, u32, u32, u32, u32);

extern int GFL_NET_GetRunState(void);

extern void *ICA_ANIME_GetField24(void *gameSystem);

extern void GAME_COMM_RequestExitNoCallback(void *gameComm);

extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);

extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);

extern void BG_SYS_ClearSlot(u32 i);

extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);

extern void CLACT_ResetActorAnimCommand(struct Actor *a);

extern void CLACT_SetActorAutoAnim(struct ClActor *p, u32 v);

extern u32 BMP_WIN_Delete(void *d);

extern int OS_IsRunOnTwl(void);

extern int MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);

extern void GF_FONT_SetDefaultTextColor(void);

extern void BMP_WIN_ClearScreen(void *d);

extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);

extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32 h, u32 a, u32 c, u32 d, u32 e, u16 heap);

extern void *BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

extern void *BMP_WIN_GetBmp(void *p);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);

extern u32 GF_FONT_MeasureWidestLine(struct StrObj *s, u32 a, u32 b);

extern u32 GF_FONT_CountLines(struct StrObj *s, void *font);

extern void PRINTSYS_Print(void *x, short y, short z, void *s, void *w);

extern void BMP_WIN_TransferChars(void *d);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern void BUTTON_MAN_Delete(void *p);

extern void BG_SYS_SetFlagField06(u32 bit);

extern struct ClActor *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);

extern void CLACT_SetActorDrawEnable(struct ClActor *p, u32 v);

extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);

extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *, u32, u32, u32, u32, u16);

extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);

extern void MI_CpuCopy8(const void *, void *, u32);

extern u32 GFL_HEAP_Free(void *p);

extern u32 ARC_UTIL_RegisterObjCharFromHandle(void *, u32, u32, u32, u32, u16);

extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);

extern void ARC_TOOL_DeleteHandle(void *);

extern void *BMP_MENUWORK_LoadFrameGfx(void *, u32, u32, u32);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void *BUTTON_MAN_Create(const void *rects, void (*callback)(int, int, void *), void *work, u32 heapId);

extern void BG_SYS_SetTileUnit(u32 idx, u32 count, u32 tile);

extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);

extern void BG_SYS_FreeLayerBuf(u32 i);

extern u32 MSGDATA_Delete(void *rec);

extern u32 GF_FONT_Delete(void *ptr);

extern void STRBUF_Delete(struct U16Vec *vec);

extern u32 WIPE_SYS_EndCheck(void);

extern u32 GAME_COMM_GetKind(void *obj);

extern int TOUCHPANEL_GetTrg(void);

extern void GFL_USE_PlaySeDefaultVolume(u32 a);

extern void CLACT_ApplyActorAnimCommand(void *actor, const GsyncActorAnimCallback *callback);

extern void CLACT_RestartActorAnim(struct Actor *a);

extern void CLACT_SetActorAnimSeq(struct ClActor *p, u16 value);

extern u16 CLACT_GetActorAnimSeq(struct ClActor *);

extern s32 BUTTON_MAN_UpdateSlots(struct Ctx *c);

extern void *PALANM_Create(u32 heap);

extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);

extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);

extern void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);

extern int PALANM_GetTransWork(char *p, int i);

extern void DWCi_ScreenDC_FlushRange(void *, int);

extern void GXS_LoadOBJPltt(void *, int, int);

extern void GXS_LoadBGPltt(void *, int, int);

extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);

extern u32 PALANM_Delete(void *a0);

extern void *APP_TASKMENU_OpenMenu(TaskMenuTmpl *tmpl, void *res);

extern int APP_TASKMENU_SetDisableKey(int a0, int a1);

extern void APP_KEYCURSOR_Update(u32 keyCursor, void *printStream, void *window);

extern u32 PRINTSYS_PrintStreamGetState(void *p);

extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);

extern void PRINTSYS_PrintStreamReleasePause(void *);

extern void PRINTSYS_PrintStreamShortWait(void *p, s32 v);

extern int TOUCHPANEL_GetCont(void);

extern signed char MSG_SPEED_GetWait(void);

extern void *PRINTSYS_PrintStream(void *, int, int, void *, void *, int textSpeed, void *tcbl, int, u16 heapId, int);

extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);

extern void BG_SYS_ClearLayerEx(int channel, u16 val);

extern int GAME_DATA_SaveMain(u8 *p);

extern int GAME_DATA_SaveStart(int a0);

extern void *GAME_DATA_GetSaveControl(struct Big *p);

extern int SAVE_CONTROL_WouldOverwriteSave(struct Sub020071E4Ctrl *ctrl);

extern void CLACT_VBlankSystem(void);

extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);

extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);

extern void MI_CpuFill8(void *,u8,u32);

extern void BMP_SetDisplaySwap(u32 swap);

extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);

extern void GX_DispOn(void);

extern void BG_SYS_Create(u16 heapId);

extern void BMP_WIN_Init(u16);

extern void GF_FONT_InitTextColor(void);

extern void BG_SYS_SetVramBanks(const struct DispVram *c);

extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);

extern void BG_SYS_SetMainVisiblePlanes(u32);

extern void BG_SYS_SetSubVisiblePlanes(u32);

extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern void *GFL_USE_AddMainTask(void *,void *,int);

extern void *GFL_HEAP_Alloc(u32,u32,int,const char *,u16);

extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);

extern u32 APP_KEYCURSOR_CreateDefault(u32,u32,u32,u32);

extern void *PRINTSYS_QUE_Create(u32 heapId);

extern void *APP_TASKMENU_RES_Create(u16 a0, u16 a1, void *font, void *printQue, u16 heap);

extern void G2x_SetBlendAlpha_(void *,int,int,int,int);

extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);

extern void UI_SetInputMode(u8 v);

extern void APP_TASKMENU_UpdateMenu(void *);

extern u32 WIH_DWC_PollStatus(void *key);

extern void TCBL_Main(struct Tcbl *p);

extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);

extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);

extern void CLACT_DrawSystem(void);

extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);

extern u32 ICA_ANIME_GetUnk330(const struct Ctx *p);

extern void WIPE_SetBrightnessFadeOut(unsigned int,unsigned int);

extern void CLACT_DeleteActor(struct ClActor *p);

extern void CLACT_ReleasePalette(u32 i);

extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleaseCellAnim(u32 i);

extern void TCB_DeleteTask(struct Node *n);

extern u32 CLACT_DeleteUnit(struct Bank *bank);

extern void CLACT_ExitSystem(void);

extern int APP_KEYCURSOR_Delete(int a0);

extern void PRINTSYS_QUE_Clear(struct PrintSys *p);

extern void PRINTSYS_QUE_Delete(struct PrintSys *p);

extern void TCBL_Destroy(struct S02031140 *p);

extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);

extern void BMP_WIN_Exit(void);

extern void BG_SYS_Delete(void);

extern void PROCSYS_FreeProcWork(struct Proc *p);

extern void GFL_HEAP_DeleteChecked(unsigned int);

/* Sets the function the proc main runs each frame. */
void GSYNC_MENU_SetStateFunc(GsyncMenuStateFunc *slot, GsyncMenuStateFunc func);
/* lineNo is the source line of the call site in the original (unused in the retail build). */
void GSYNC_MENU_ChangeState(GsyncMenuWork *work, GsyncMenuStateFunc func, int lineNo);
void GSYNC_MENU_InitBgLayers(GsyncMenuWork *work);
void GSYNC_MENU_RestartTimeIcon(GsyncMenuWork *work);
void GSYNC_MENU_AddPaletteEntries(u16 *palette, const u16 *add, int rowCount);
void GSYNC_MENU_StateStartFadeOut(GsyncMenuWork *work);
void GSYNC_MENU_StateWaitMenuSelect(GsyncMenuWork *work);
void GSYNC_MENU_StateOpenYesNoAfterMessage(GsyncMenuWork *work);
void GSYNC_MENU_OnButtonAnimEnd(GsyncMenuWork *work);
void GSYNC_MENU_NoOp(void);
void GSYNC_MENU_CreateButtonWindows(int count, u32 *messageIds, GsyncMenuWork *work, ButtonWinDef *defs, u32 *centerX, u32 *centerY);
void GSYNC_MENU_DeleteButtonWindows(GsyncMenuWork *work);
void GSYNC_MENU_RunButtonCallback(int buttonIndex, int event, void *work);
void GSYNC_MENU_CreateActors(GsyncMenuWork *work);
void GSYNC_MENU_LoadResources(GsyncMenuWork *work);
void GSYNC_MENU_StateSetupButtons(GsyncMenuWork *work);
void GSYNC_MENU_FreeResources(GsyncMenuWork *work);
void GSYNC_MENU_StateWaitFadeOut(GsyncMenuWork *work);
void GSYNC_MENU_StateWaitTouchAfterMessage(GsyncMenuWork *work);
void GSYNC_MENU_StatePlayButtonAnim(GsyncMenuWork *work);
int GSYNC_MENU_OnButtonPressed(int button, GsyncMenuWork *work);
void GSYNC_MENU_SetCursorAnimIfChanged(GsyncMenuWork *work, int animSeq);
void GSYNC_MENU_UpdateCursorAnimFromKeys(GsyncMenuWork *work);
void GSYNC_MENU_StateButtonsActive(GsyncMenuWork *work);
void GSYNC_MENU_FadePaletteSlot(GsyncMenuWork *work, int palSlot, int rowCount);
void GSYNC_MENU_SetPaletteFade(GsyncMenuWork *work, int enable);
void GSYNC_MENU_OpenYesNoMenu(GsyncMenuWork *work);
void GSYNC_MENU_HideMessage(GsyncMenuWork *work);
void GSYNC_MENU_DeleteMessageWindow(GsyncMenuWork *work);
int GSYNC_MENU_UpdateMessageStream(GsyncMenuWork *work);
void GSYNC_MENU_PrintMessage(GsyncMenuWork *work, int lineCount, int stream);
void GSYNC_MENU_PrintMessageNoStream(GsyncMenuWork *work);
void GSYNC_MENU_StatePrintConfirmMessage(GsyncMenuWork *work);
void GSYNC_MENU_StateSaveFinish(GsyncMenuWork *work);
void GSYNC_MENU_StateSaveStart(GsyncMenuWork *work);
void GSYNC_MENU_StateConfirmSelect(GsyncMenuWork *work);
void GSYNC_MENU_StateOpenConfirmMenu(GsyncMenuWork *work);
void GSYNC_MENU_VBlank(void);
int GSYNC_MENU_ProcInit(void *proc, int seq, GsyncProcParam *param);
int GSYNC_MENU_ProcMain(int unused0, int unused1, int unused2, GsyncMenuWork *work);
int GSYNC_MENU_ProcExit(void *proc, int seq, GsyncProcParam *param, GsyncMenuWork *work);

extern const struct BgTemplate d_021DA690;
extern const struct BgTemplate d_021DA6B0;
extern const struct BgTemplate d_021DA6D0;
extern const struct BgTemplate d_021DA6F0;
extern const struct BgTemplate d_021DA710;
extern const struct ActorCoordTriple d_021DA638;
extern const struct ActorCoordTriple d_021DA634;
extern const struct ActorCoordTriple d_021DA63C;
extern const char d_021DA9D0[];
extern char sGsyncMenuButtonWinDefs[];
extern int d_021DA640[];
extern int d_021DA648[];
extern const struct DispConfigWords d_021DA680;
extern const u32 d_021DA9F0[];
extern const u32 d_021DA658[];
extern const char d_021DAA20[];

void GSYNC_MENU_SetStateFunc(GsyncMenuStateFunc *slot, GsyncMenuStateFunc func)
{
    *slot = func;
}

void GSYNC_MENU_ChangeState(GsyncMenuWork *work, GsyncMenuStateFunc func, int lineNo)
{
    GSYNC_MENU_SetStateFunc(&work->stateFunc, func);
}

/* Sets up BG 0 and BGs 4 to 7 of the sub screen from the layer templates. */
void GSYNC_MENU_InitBgLayers(GsyncMenuWork *work)
{
    struct BgTemplate bgTemplates[5];
    bgTemplates[4] = d_021DA690;
    BG_SYS_InitBgLayer(0, &bgTemplates[4], 0);
    BG_SYS_FreeSlot(0);
    BG_SYS_PushTile(0);
    BG_SYS_SetVisibleLayer(0, 0);
    BG_SYS_SetPlaneVisible(0, 1);
    bgTemplates[3] = d_021DA6B0;
    BG_SYS_InitBgLayer(4, &bgTemplates[3], 0);
    BG_SYS_SetPlaneVisible(4, 1);
    BG_SYS_PushTile(4);
    bgTemplates[2] = d_021DA6D0;
    BG_SYS_InitBgLayer(5, &bgTemplates[2], 0);
    BG_SYS_Init(5, 0, 1, 0);
    BG_SYS_SetTileEntry(5, 0, 0, 0, 32, 32, 17);
    BG_SYS_PushTile(5);
    BG_SYS_SetPlaneVisible(5, 1);
    bgTemplates[1] = d_021DA6F0;
    BG_SYS_InitBgLayer(6, &bgTemplates[1], 0);
    BG_SYS_SetPlaneVisible(6, 1);
    BG_SYS_PushTile(6);
    bgTemplates[0] = d_021DA710;
    BG_SYS_InitBgLayer(7, &bgTemplates[0], 0);
    BG_SYS_SetPlaneVisible(7, 1);
    BG_SYS_PushTile(7);
}

void GSYNC_MENU_RestartTimeIcon(GsyncMenuWork *work)
{
    if (work->timeIcon) {
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
    work->timeIcon = TIME_ICON_CreateNode(work->tcbl, work->msgWin, 15, 16, work->heapId);
}

/* Adds add[column] to the three color channels of every entry in rowCount palette rows of 16 colors, clamped to 31. */
void GSYNC_MENU_AddPaletteEntries(u16 *palette, const u16 *add, int rowCount)
{
    int row, col;
    u16 *rowColors;
    u16 red, green, blue;
    for (row = 0; row < rowCount; row++) {
        rowColors = palette + row * 16;
        for (col = 0; col < 16; col++) {
            red = rowColors[col] & 31;
            green = (rowColors[col] & 0x3e0) >> 5;
            blue = (rowColors[col] & 0x7c00) >> 10;
            red += add[col];
            green += add[col];
            blue += add[col];
            if (red > 31) red = 31;
            if (green > 31) green = 31;
            if (blue > 31) blue = 31;
            rowColors[col] = red + (green << 5) + (blue << 10);
        }
    }
}

/* Starts the fade out; after a button choice the link session is closed first. */
void GSYNC_MENU_StateStartFadeOut(GsyncMenuWork *work)
{
    work->exiting = 1;
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, work->heapId);
    switch (work->exitMode) {
    case GSYNC_MENU_EXIT_BUTTON_0:
    case GSYNC_MENU_EXIT_BUTTON_1:
        if (GFL_NET_GetRunState())
            GAME_COMM_RequestExitNoCallback(ICA_ANIME_GetField24(work->gameSystem));
        break;
    }
    GSYNC_MENU_ChangeState(work, GSYNC_MENU_StateWaitFadeOut, 0x1aa);
}

void GSYNC_MENU_StateWaitMenuSelect(GsyncMenuWork *work)
{
    if (APP_TASKMENU_IsFinish(work->taskMenu)) {
        if (!APP_TASKMENU_GetCursorPos(work->taskMenu)) {
            GSYNC_MENU_ChangeState(work, GSYNC_MENU_StatePrintConfirmMessage, 0x1b6);
        } else {
            BG_SYS_ClearSlot(5);
            work->exitMode = GSYNC_MENU_EXIT_NONE;
            GSYNC_MENU_ChangeState(work, GSYNC_MENU_StateSetupButtons, 0x1bb);
        }
        APP_TASKMENU_CloseMenu(work->taskMenu);
        work->taskMenu = 0;
        GSYNC_MENU_SetPaletteFade(work, 0);
    }
}

void GSYNC_MENU_StateOpenYesNoAfterMessage(GsyncMenuWork *work)
{
    if (GSYNC_MENU_UpdateMessageStream(work)) {
        GSYNC_MENU_OpenYesNoMenu(work);
        GSYNC_MENU_ChangeState(work, GSYNC_MENU_StateWaitMenuSelect, 0x1c9);
    }
}

/*
 * extent: follower 021D45F0 already filed separately.
 */
/* Animation end callback of the cursor sprite: moves on according to the chosen button. */
void GSYNC_MENU_OnButtonAnimEnd(GsyncMenuWork *work)
{
    CLACT_ResetActorAnimCommand(work->actors[work->pressedButton]);
    CLACT_SetActorAutoAnim(work->actors[work->pressedButton], 0);
    if (work->exitMode == GSYNC_MENU_EXIT_BUTTON_1) {
        if (work->msgWin) {
            BMP_WIN_Delete(work->msgWin);
            work->msgWin = 0;
        }
        if (OS_IsRunOnTwl()) {
            MSGDATA_ReadString(work->msgBankSub, 0x20, work->msgBuf);
            GSYNC_MENU_PrintMessage(work, 10, 0);
            GSYNC_MENU_SetPaletteFade(work, 1);
            GSYNC_MENU_ChangeState(work, GSYNC_MENU_StateWaitTouchAfterMessage, 0x1df);
        } else {
            MSGDATA_ReadString(work->msgBank, 7, work->msgBuf);
            GSYNC_MENU_PrintMessageNoStream(work);
            GSYNC_MENU_SetPaletteFade(work, 1);
            GSYNC_MENU_ChangeState(work, GSYNC_MENU_StateOpenYesNoAfterMessage, 0x1e6);
        }
    } else if (work->exitMode == GSYNC_MENU_EXIT_BUTTON_0 || work->exitMode == GSYNC_MENU_EXIT_BUTTON_1) {
        GSYNC_MENU_ChangeState(work, GSYNC_MENU_StatePrintConfirmMessage, 0x1f2);
    } else {
        GSYNC_MENU_ChangeState(work, GSYNC_MENU_StateStartFadeOut, 0x1f5);
    }
}

/*
 * extent: bx lr callback stub, two zero alignment bytes, then labelled GSYNC_MENU_CreateButtonWindows.
 */
void GSYNC_MENU_NoOp(void) {}

/*
 * note 2026-10-05 (wD6 lane17): closed by the real callee prototypes: GF_FONT_SetDefaultTextColor takes no
 *   argument (so count is spilled and reloaded for the +0x25C store) and the record pointer is not
 *   const (the a/b/c loads stay after the outgoing stack-argument stores).
 */
/* Replaces the button windows: one window per definition, each with its text centered on (centerX, centerY). */
void GSYNC_MENU_CreateButtonWindows(int count, u32 *messageIds, GsyncMenuWork *work, ButtonWinDef *defs, u32 *centerX, u32 *centerY)
{
    int buttonIndex;
    int defIndex;
    int textX;
    int textY;
    work->buttonCount = count;
    GF_FONT_SetDefaultTextColor();
    for (buttonIndex = 0; buttonIndex < 4; buttonIndex++) {
        if (work->buttonWins[buttonIndex] != 0) {
            BMP_WIN_ClearScreen(work->buttonWins[buttonIndex]);
            BMP_MENUWORK_DrawWindowBorder(work->buttonWins[buttonIndex], 2);
            BMP_WIN_Delete(work->buttonWins[buttonIndex]);
        }
        work->buttonWins[buttonIndex] = 0;
    }
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x100, 0x20, work->heapId);
    for (defIndex = 0; defIndex < count; defIndex++) {
        ButtonWinDef *def = &defs[defIndex];
        work->buttonWins[defIndex] = BMP_WIN_Create(7, (u8)def->x, (u8)def->y, (u8)def->width, (u8)def->height, 8, 0);
        BMP_Clear(BMP_WIN_GetBmp(work->buttonWins[defIndex]), 0);
        MSGDATA_ReadString(work->msgBank, messageIds[defIndex], work->msgBuf);
        GF_FONT_SetTextColor(0xF, 2, 0);
        if (centerX != 0)
            textX = centerX[defIndex] - GF_FONT_MeasureWidestLine(work->msgBuf, (u32)work->font, 0) / 2;
        else
            textX = 0;
        if (centerY != 0)
            textY = centerY[defIndex] - GF_FONT_CountLines(work->msgBuf, work->font) / 2;
        else
            textY = 0;
        PRINTSYS_Print(BMP_WIN_GetBmp(work->buttonWins[defIndex]), (short)textX, (short)textY, work->msgBuf, work->font);
        BMP_WIN_TransferChars(work->buttonWins[defIndex]);
        BMP_WIN_MakeScreen(work->buttonWins[defIndex]);
    }
    if (work->buttonMan != 0)
        BUTTON_MAN_Delete(work->buttonMan);
    work->buttonMan = 0;
    BG_SYS_PushTile(7);
}

void GSYNC_MENU_DeleteButtonWindows(GsyncMenuWork *work)
{
    int buttonIndex;
    if (work->buttonMan)
        BUTTON_MAN_Delete(work->buttonMan);
    work->buttonMan = 0;
    for (buttonIndex = 0; buttonIndex < 4; buttonIndex++) {
        if (work->buttonWins[buttonIndex]) {
            BMP_WIN_ClearScreen(work->buttonWins[buttonIndex]);
            BG_SYS_SetFlagField06(5);
            BMP_MENUWORK_DrawWindowBorder(work->buttonWins[buttonIndex], 2);
            BMP_WIN_Delete(work->buttonWins[buttonIndex]);
        }
        work->buttonWins[buttonIndex] = 0;
    }
    work->buttonCount = 0;
}

/* Button manager callback: forwards a press (event 0) to the work's button callback. */
void GSYNC_MENU_RunButtonCallback(int buttonIndex, int event, void *work)
{
    GsyncMenuWork *menu = work;
    if (event)
        return;
    if (!menu->buttonCallback)
        return;
    if (menu->buttonCallback(buttonIndex, menu))
        return;
}

/*
 * lever: seven independent offset locals each receive 0x2ac then their final literal; both spill stores survive.
 * note 2026-10-05 (wave D9r lane 131): removed the 7 dead first assignments
 * (`o1 = 0x2ac;` before `o1 = 0x294;`; `o2 = 0x2ac;` before `o2 = 0x290;`
 * and 5 more). Game code has no line table, so these were stand-ins. The
 * plain single assignment gives EXACT in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void GSYNC_MENU_CreateActors(GsyncMenuWork *work)
{
    struct ActorCoordTriple xCoords, yCoords, zCoords;
    struct MenuActorSpawnPos pt;
    int actorIndex;
    xCoords = d_021DA638;
    yCoords = d_021DA634;
    zCoords = d_021DA63C;
    for (actorIndex = 0; actorIndex < 3; actorIndex++) {
        pt.x = xCoords.coords[actorIndex]; pt.y = yCoords.coords[actorIndex]; pt.z = zCoords.coords[actorIndex];
        pt.mode = 0; pt.space = 2;
        work->actors[actorIndex] = CLACT_CreateActor(work->clactUnit, work->charHandle, work->palHandle, work->cellHandle, &pt, 1, work->heapId);
        CLACT_SetActorAutoAnim(work->actors[actorIndex], 0);
        CLACT_SetActorDrawEnable(work->actors[actorIndex], 1);
        CLACT_SetActorObjMode(work->actors[actorIndex], 1);
    }
}

/*
 * interface: 02049990 arg5 is u16 at both original call-site truncations; 02049F78 arg3 is an unchanged address payload passed to 02062A98, whose body stores through it.
 */
void GSYNC_MENU_LoadResources(GsyncMenuWork *work)
{
    void *arc;
    void *paletteBlock;
    GsyncPaletteData *paletteData;
    work->msgBuf = STRBUF_Create(300, work->heapId);
    work->font = GF_FONT_Create(23, 0, 0, 0, work->heapId);
    work->msgBank = MSGDATA_CreateFromArchive(0, 2, 39, work->heapId);
    work->msgBankSub = MSGDATA_CreateFromArchive(0, 2, 232, work->heapId);
    arc = ARC_TOOL_CreateHandle(29, work->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc, 1, 4, 0, 0, work->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc, 0, 0, 0, 0, work->heapId);
    paletteBlock = ARC_UTIL_LoadPaletteBlockFromHandle(arc, 1, (u32)(&paletteData), work->heapId);
    MI_CpuCopy8(paletteData->rawData, work->palette, 0xe0);
    MI_CpuCopy8(paletteData->rawData, work->paletteDim, 0xe0);
    GSYNC_MENU_AddPaletteEntries(work->paletteDim, (const u16 *)d_021DA9D0, 7);
    GFL_HEAP_Free(paletteBlock);
    work->charBase = ARC_UTIL_RegisterObjCharFromHandle(arc, 4, 4, 0, 0, work->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arc, 9, 4, 0, (u16)(work->charBase), 0, 0, work->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(arc, 14, 6, 0, (u16)(work->charBase), 0, 0, work->heapId);
    ARC_TOOL_DeleteHandle(arc);
    work->bgFrame = (u32)BMP_MENUWORK_LoadFrameGfx((void *)5, 12, 0, work->heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23, 5, 4, 0x1a0, 32, work->heapId);
    arc = ARC_TOOL_CreateHandle(29, work->heapId);
    work->charHandle = CLACT_RegisterCharacter(arc, 5, 0, 1, work->heapId);
    work->palHandle = CLACT_RegisterPaletteEx(arc, 3, 1, 0, 0, 10, work->heapId);
    work->cellHandle = CLACT_RegisterCellAnim(arc, 7, 16, work->heapId);
    ARC_TOOL_DeleteHandle(arc);
    GSYNC_MENU_CreateActors(work);
}

/* Creates the button windows and the touch button manager for the main screen of the menu. */
void GSYNC_MENU_StateSetupButtons(GsyncMenuWork *work)
{
    /* one-entry message id table; the struct form keeps the original stack layout */
    struct { int id; } messageIds = {0};
    GSYNC_MENU_CreateButtonWindows(1, (u32 *)&messageIds, work, (ButtonWinDef *)sGsyncMenuButtonWinDefs, (u32 *)d_021DA640, (u32 *)(d_021DA640 + 1));
    work->buttonMan = BUTTON_MAN_Create((u8 *)d_021DA648, GSYNC_MENU_RunButtonCallback, work, work->heapId);
    work->buttonCallback = GSYNC_MENU_OnButtonPressed;
    GSYNC_MENU_ChangeState(work, GSYNC_MENU_StateButtonsActive, 0x321);
}

void GSYNC_MENU_FreeResources(GsyncMenuWork *work)
{
    GF_FONT_SetDefaultTextColor();
    GSYNC_MENU_DeleteButtonWindows(work);
    BG_SYS_SetTileUnit(5, 1, 0);
    BG_SYS_DeleteHalf((int)5, (u16)(work->bgFrame), (u16)(work->bgFrame >> 16));
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(4);
    MSGDATA_Delete(work->msgBank);
    MSGDATA_Delete(work->msgBankSub);
    GF_FONT_Delete(work->font);
    STRBUF_Delete(work->msgBuf);
}

/* Waits for the fade out to end, then leaves the proc state loop. */
void GSYNC_MENU_StateWaitFadeOut(GsyncMenuWork *work)
{
    if (WIPE_SYS_EndCheck() != 0) {
        switch (work->exitMode) {
        case GSYNC_MENU_EXIT_BUTTON_0:
        case GSYNC_MENU_EXIT_BUTTON_1:
            if (GAME_COMM_GetKind(ICA_ANIME_GetField24(work->gameSystem)) == 0)
                GSYNC_MENU_ChangeState(work, 0, 0x345);
            break;
        default:
            GSYNC_MENU_ChangeState(work, 0, 0x349);
            break;
        }
    }
}

void GSYNC_MENU_StateWaitTouchAfterMessage(GsyncMenuWork *work)
{
    if (GSYNC_MENU_UpdateMessageStream(work) != 0 && TOUCHPANEL_GetTrg() != 0) {
        GSYNC_MENU_DeleteMessageWindow(work);
        work->keyPrev = 0;
        GFL_USE_PlaySeDefaultVolume(0x73b);
        GSYNC_MENU_SetPaletteFade(work, 0);
        GSYNC_MENU_ChangeState(work, GSYNC_MENU_StateSetupButtons, 0x360);
    }
}

/*
 * evidence: callback 0x021D45F0 resolved by its verified ov123 shard.
 */
/* Plays the press animation of the chosen button; its end callback is GSYNC_MENU_OnButtonAnimEnd. */
void GSYNC_MENU_StatePlayButtonAnim(GsyncMenuWork *work)
{
    GsyncActorAnimCallback cb;
    cb.frame = 0;
    cb.work = work;
    cb.callback = GSYNC_MENU_OnButtonAnimEnd;
    CLACT_SetActorAutoAnim(work->actors[work->pressedButton], 1);
    CLACT_ApplyActorAnimCommand(work->actors[work->pressedButton], &cb);
    CLACT_RestartActorAnim(work->actors[work->pressedButton]);
    GSYNC_MENU_ChangeState(work, (GsyncMenuStateFunc)GSYNC_MENU_NoOp, 0x376);
}

/* Button callback: 0 and 1 are the two buttons, 2 is the back button. Returns 1. */
int GSYNC_MENU_OnButtonPressed(int button, GsyncMenuWork *work)
{
    work->pressedButton = button;
    switch (button) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x73b);
        CLACT_SetActorAnimSeq(work->actors[0], 14);
        GSYNC_MENU_ChangeState(work, GSYNC_MENU_StatePlayButtonAnim, 0x389);
        work->exitMode = GSYNC_MENU_EXIT_BUTTON_0;
        break;
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x73b);
        work->exitMode = GSYNC_MENU_EXIT_BUTTON_1;
        GSYNC_MENU_ChangeState(work, GSYNC_MENU_StatePlayButtonAnim, 0x393);
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x73c);
        work->exitMode = GSYNC_MENU_EXIT_NONE;
        GSYNC_MENU_ChangeState(work, GSYNC_MENU_StatePlayButtonAnim, 0x399);
        break;
    }
    return 1;
}

void GSYNC_MENU_SetCursorAnimIfChanged(GsyncMenuWork *work, int animSeq)
{
    if (animSeq != CLACT_GetActorAnimSeq(work->actors[0])) {
        CLACT_SetActorAutoAnim(work->actors[0], 1);
        CLACT_SetActorAnimSeq(work->actors[0], animSeq);
    }
}

/* Picks the first cursor sprite animation from the direction keys held. */
void GSYNC_MENU_UpdateCursorAnimFromKeys(GsyncMenuWork *work)
{
    u32 keys = work->keyNow;
    if (keys != work->keyPrev) {
        if (keys & GSYNC_KEY_UP) GSYNC_MENU_SetCursorAnimIfChanged(work, 0x18);
        else if (keys & GSYNC_KEY_DOWN) GSYNC_MENU_SetCursorAnimIfChanged(work, 0x16);
        else if (keys & GSYNC_KEY_R) GSYNC_MENU_SetCursorAnimIfChanged(work, 0x15);
        else if (keys & GSYNC_KEY_L) GSYNC_MENU_SetCursorAnimIfChanged(work, 0x15);
        else GSYNC_MENU_SetCursorAnimIfChanged(work, 0xe);
    }
}

/*
 * Addresses are Black-image addresses.
 */
void GSYNC_MENU_StateButtonsActive(GsyncMenuWork *work)
{
    if (WIPE_SYS_EndCheck() != 0)
        BUTTON_MAN_UpdateSlots(work->buttonMan);
    GSYNC_MENU_UpdateCursorAnimFromKeys(work);
}

/*
 * extent: two zero padding bytes at 0x021D4D3E before next labelled function.
 */
/* Fades rowCount rows of palette slot palSlot toward the target color and uploads the result to palette RAM. */
void GSYNC_MENU_FadePaletteSlot(GsyncMenuWork *work, int palSlot, int rowCount)
{
    void *palAnm;
    void *transBuf;
    int byteSize;
    palAnm = PALANM_Create(work->heapId);
    PALANM_AllocSlotBuffers(palAnm, palSlot, 0x200, work->heapId);
    byteSize = rowCount * 32;
    PALANM_CopyHwPaletteToSlot(palAnm, palSlot, 0, byteSize);
    PALANM_BlendChannel(palAnm, (int)palSlot, (int)0, (u16)(rowCount * 16), (int)6, (int)0);
    transBuf = (void *)PALANM_GetTransWork(palAnm, palSlot);
    DWCi_ScreenDC_FlushRange(transBuf, byteSize);
    switch (palSlot) {
    case 3: GXS_LoadOBJPltt(transBuf, 0, byteSize); break;
    case 1: GXS_LoadBGPltt(transBuf, 0, byteSize); break;
    }
    PALANM_FreeSlotBuffers(palAnm, palSlot);
    PALANM_Delete(palAnm);
}

/* enable: save the palette RAM and fade it; otherwise restore the saved palettes. */
void GSYNC_MENU_SetPaletteFade(GsyncMenuWork *work, int enable)
{
    if (enable) {
        MI_CpuCopy8((void *)0x05000600, work->palBufMain, 0x200);
        MI_CpuCopy8((void *)0x05000400, work->palBufSub, 0x200);
        GSYNC_MENU_FadePaletteSlot(work, 3, 14);
        GSYNC_MENU_FadePaletteSlot(work, 1, 9);
    } else {
        GXS_LoadOBJPltt(work->palBufMain, 0, 0x1c0);
        GXS_LoadBGPltt(work->palBufSub, 0, 0x120);
    }
}

/* Opens the two entry Yes/No task menu below the message window. */
void GSYNC_MENU_OpenYesNoMenu(GsyncMenuWork *work)
{
    TaskMenuTmpl tmpl;
    tmpl.heapId = work->heapId;
    tmpl.itemNum = 2;
    tmpl.items = work->menuItems;
    tmpl.posType = 1;
    tmpl.charPosX = 32;
    tmpl.charPosY = 14;
    tmpl.width = 13;
    tmpl.height = 3;
    work->menuItems[0].text = STRBUF_Create(100, work->heapId);
    MSGDATA_ReadString(work->msgBank, 4, work->menuItems[0].text);
    work->menuItems[0].color = 0x39e0;
    work->menuItems[1].text = STRBUF_Create(100, work->heapId);
    MSGDATA_ReadString(work->msgBank, 5, work->menuItems[1].text);
    work->menuItems[1].color = 0x39e0;
    work->taskMenu = APP_TASKMENU_OpenMenu(&tmpl, work->taskMenuRes);
    APP_TASKMENU_SetDisableKey((int)(work->taskMenu), 1);
    STRBUF_Delete(work->menuItems[0].text);
    STRBUF_Delete(work->menuItems[1].text);
}

void GSYNC_MENU_HideMessage(GsyncMenuWork *work)
{
    if (work->timeIcon) {
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
    BMP_MENUWORK_DrawWindowBorder(work->msgWin, 2);
    BMP_WIN_ClearScreen(work->msgWin);
    BG_SYS_SetFlagField06(5);
}

void GSYNC_MENU_DeleteMessageWindow(GsyncMenuWork *work)
{
    GSYNC_MENU_HideMessage(work);
    BMP_WIN_Delete(work->msgWin);
    work->msgWin = 0;
}

/* Runs the message print stream; returns 1 when no stream is active any more. */
int GSYNC_MENU_UpdateMessageStream(GsyncMenuWork *work)
{
    if (work->printStream) {
        if (work->msgWin)
            APP_KEYCURSOR_Update(work->keyCursor, work->printStream, work->msgWin);
        switch (PRINTSYS_PrintStreamGetState(work->printStream)) {
        case 2:
            PRINTSYS_PrintStreamDelete(work->printStream);
            work->printStream = 0;
            break;
        case 1:
            if (TOUCHPANEL_GetTrg()) {
                GFL_USE_PlaySeDefaultVolume(0x547);
                PRINTSYS_PrintStreamReleasePause(work->printStream);
            }
            break;
        case 0:
            if (TOUCHPANEL_GetCont()) PRINTSYS_PrintStreamShortWait(work->printStream, 0);
            break;
        }
        return 0;
    }
    return 1;
}

/* Prints msgBuf into the message window (created on first use, lineCount tiles high); stream: print one character at a time. */
void GSYNC_MENU_PrintMessage(GsyncMenuWork *work, int lineCount, int stream)
{
    void *win;
    if (work->msgWin == 0)
        work->msgWin = BMP_WIN_Create(5, 1, 3, 30, (u8)lineCount, 13, 1);
    win = work->msgWin;
    BMP_Clear(BMP_WIN_GetBmp(win), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    if (stream) {
        int textSpeed;
        textSpeed = MSG_SPEED_GetWait();
        work->printStream = PRINTSYS_PrintStream(win, 0, 0, work->msgBuf, work->font, textSpeed, work->tcbl, 2, work->heapId, 15);
    } else {
        PRINTSYS_Print(BMP_WIN_GetBmp(win), 0, 0, work->msgBuf, work->font);
    }
    BMP_MENUWORK_DrawWindow(win, 1, (u16)(work->bgFrame), 12);
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    BG_SYS_SetFlagField06(5);
}

void GSYNC_MENU_PrintMessageNoStream(GsyncMenuWork *work)
{
    GSYNC_MENU_PrintMessage(work, 4, 1);
}

/* Prints the confirmation text and waits for it to finish before the Yes/No menu opens. */
void GSYNC_MENU_StatePrintConfirmMessage(GsyncMenuWork *work)
{
    GSYNC_MENU_SetPaletteFade(work, 1);
    BG_SYS_ClearLayerEx(5, 0);
    MSGDATA_ReadString(work->msgBank, 3, work->msgBuf);
    GSYNC_MENU_PrintMessageNoStream(work);
    GSYNC_MENU_ChangeState(work, GSYNC_MENU_StateOpenConfirmMenu, 0x4d0);
}

void GSYNC_MENU_StateSaveFinish(GsyncMenuWork *work)
{
    if (GAME_DATA_SaveMain(work->gameData) == 2) {
        GSYNC_MENU_DeleteMessageWindow(work);
        GSYNC_MENU_SetPaletteFade(work, 0);
        GSYNC_MENU_ChangeState(work, GSYNC_MENU_StateStartFadeOut, 0x4ea);
    }
}

void GSYNC_MENU_StateSaveStart(GsyncMenuWork *work)
{
    if (GSYNC_MENU_UpdateMessageStream(work)) {
        GAME_DATA_SaveStart((int)(work->gameData));
        GSYNC_MENU_ChangeState(work, GSYNC_MENU_StateSaveFinish, 0x4fa);
    }
}

/* Handles the answer of the confirmation menu: Yes saves (or reports that saving is impossible), No returns to the buttons. */
void GSYNC_MENU_StateConfirmSelect(GsyncMenuWork *work)
{
    if (APP_TASKMENU_IsFinish(work->taskMenu)) {
        if (!APP_TASKMENU_GetCursorPos(work->taskMenu)) {
            if (SAVE_CONTROL_WouldOverwriteSave(GAME_DATA_GetSaveControl(work->gameData))) {
                MSGDATA_ReadString(work->msgBank, 46, work->msgBuf);
                GSYNC_MENU_PrintMessageNoStream(work);
                GSYNC_MENU_ChangeState(work, GSYNC_MENU_StateWaitTouchAfterMessage, 0x50d);
            } else {
                MSGDATA_ReadString(work->msgBank, 6, work->msgBuf);
                GSYNC_MENU_PrintMessage(work, 4, 0);
                GSYNC_MENU_RestartTimeIcon(work);
                GSYNC_MENU_ChangeState(work, GSYNC_MENU_StateSaveStart, 0x519);
            }
        } else {
            BG_SYS_ClearSlot(5);
            work->exitMode = GSYNC_MENU_EXIT_NONE;
            GSYNC_MENU_ChangeState(work, GSYNC_MENU_StateSetupButtons, 0x51f);
            GSYNC_MENU_SetPaletteFade(work, 0);
        }
        APP_TASKMENU_CloseMenu(work->taskMenu);
        work->taskMenu = 0;
    }
}

void GSYNC_MENU_StateOpenConfirmMenu(GsyncMenuWork *work)
{
    if (GSYNC_MENU_UpdateMessageStream(work)) {
        GSYNC_MENU_OpenYesNoMenu(work);
        GSYNC_MENU_ChangeState(work, GSYNC_MENU_StateConfirmSelect, 0x536);
    }
}

/*
 * evidence: root claimed this sole blocker of 021D5128; target's matched
 * definition and original body read no incoming argument registers.
 */
void GSYNC_MENU_VBlank(void)
{
    CLACT_VBlankSystem();
}

/*
 * evidence: sole callback blocker ov123 021D5120 filed and verified before
 * caller recheck; ABS32 at +01E0 now resolves through its matched shard.
 * volatile: display register 04001000 read/write at 021D5198/021D519C.
 * interface: 0203159C leaves its allocation result in r0, which is used
 * throughout this caller; its legacy matched definition is void.
 */
int GSYNC_MENU_ProcInit(void *proc, int seq, GsyncProcParam *param)
{
    GsyncMenuWork *work;
    int bright;
    int color;
    struct DispConfigWords cfg;
    GFL_HEAP_CreateChildHeap(1, 31, 0x18000);
    work = PROCSYS_AllocProcWork(proc, 0x2b4, 31);
    MI_CpuFill8(work, 0, 0x2b4);
    work->heapId = 31;
    work->gameData = param->gameData;
    work->gameSystem = param->gameSystem;
    BMP_SetDisplaySwap(1);
    if (param->fadeFromWhite) bright = 16; else bright = -16;
    GXx_SetMasterBrightness_((void *)0x0400006c, bright);
    GXx_SetMasterBrightness_((void *)0x0400106c, bright);
    *(volatile u32 *)0x04001000 |= 0x10000;
    GX_DispOn();
    BG_SYS_Create(work->heapId);
    BMP_WIN_Init(work->heapId);
    GF_FONT_InitTextColor();
    BG_SYS_SetVramBanks((const struct DispVram *)d_021DA9F0);
    cfg = d_021DA680;
    BG_SYS_SetGraphicsMode((struct DispConfig *)(&cfg));
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    CLACT_InitSystem((const struct Cfg *)d_021DA658, (u32)d_021DA9F0, work->heapId);
    work->clactUnit = CLACT_CreateUnit(40, 0, work->heapId);
    work->vblankTcb = GFL_USE_AddMainTask(GSYNC_MENU_VBlank, work, 0);
    GSYNC_MENU_InitBgLayers(work);
    GSYNC_MENU_LoadResources(work);
    work->palBufMain = GFL_HEAP_Alloc(work->heapId, 0x200, 0, d_021DAA20, 0x5a6);
    work->palBufSub = GFL_HEAP_Alloc(work->heapId, 0x200, 0, d_021DAA20, 0x5a7);
    work->tcbl = TCBL_Create(work->heapId, work->heapId, 3, 0);
    work->keyCursor = APP_KEYCURSOR_CreateDefault(15, 0, 1, work->heapId);
    work->printQue = PRINTSYS_QUE_Create(work->heapId);
    work->taskMenuRes = APP_TASKMENU_RES_Create(5, 9, work->font, work->printQue, work->heapId);
    G2x_SetBlendAlpha_((void *)0x04001050, 4, 1, 15, 4);
    color = 0;
    if (param->fadeFromWhite) color = 0x7fff;
    WIPE_SYS_Start(0, 1, 1, (u16)color, 6, 1, work->heapId);
    param->fadeFromWhite = 0;
    BG_SYS_SetSubVisiblePlanes(31);
    GSYNC_MENU_ChangeState(work, GSYNC_MENU_StateSetupButtons, 0x5bf);
    work->param = param;
    GFL_NET_RestartWithDefaultTimeout(0, work->heapId);
    UI_SetInputMode(1);
    return 1;
}

/*
 * extent: two bytes zero alignment padding follow the return.
 */
/* Proc main: runs the state function, polls the keys, draws; returns 1 when the proc is done. */
int GSYNC_MENU_ProcMain(int unused0, int unused1, int unused2, GsyncMenuWork *work)
{
    int result = 1;
    if (work->stateFunc) {
        work->stateFunc(work);
        result = 0;
    }
    if (work->taskMenu) APP_TASKMENU_UpdateMenu(work->taskMenu);
    if (GFL_NET_GetRunState()) {
        work->keyPrev = work->keyNow;
        work->keyNow = WIH_DWC_PollStatus(0);
    }
    TCBL_Main(work->tcbl);
    PRINTSYS_QUE_Main(work->printQue);
    BG_SYS_FillScrollArea(4, 3, work->bgScrollY);
    --work->bgScrollY;
    CLACT_DrawSystem();
    if (!work->exiting) GAMESYSTEM_TryStartAutoComm(work->gameSystem);
    if (WIPE_SYS_EndCheck() && ICA_ANIME_GetUnk330(work->gameSystem)) {
        work->exitMode = GSYNC_MENU_EXIT_NONE;
        result = 1;
        WIPE_SetBrightnessFadeOut(0, 0);
        WIPE_SetBrightnessFadeOut(1, 0);
    }
    return result;
}

/*
 * extent: two zero alignment bytes at 021D54DE follow the return.
 */
int GSYNC_MENU_ProcExit(void *proc, int seq, GsyncProcParam *param, GsyncMenuWork *work)
{
    int actorIndex;
    if (!WIPE_SYS_EndCheck()) return 0;
    for (actorIndex = 0; actorIndex < 3; actorIndex++) CLACT_DeleteActor(work->actors[actorIndex]);
    CLACT_ReleasePalette(work->palHandle);
    CLACT_ReleaseCharacter(work->charHandle);
    CLACT_ReleaseCellAnim(work->cellHandle);
    TCB_DeleteTask(work->vblankTcb);
    CLACT_DeleteUnit(work->clactUnit);
    CLACT_ExitSystem();
    if (work->timeIcon) {
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
    if (work->printStream) PRINTSYS_PrintStreamDelete(work->printStream);
    if (work->taskMenu) {
        APP_TASKMENU_CloseMenu(work->taskMenu);
        work->taskMenu = 0;
    }
    GSYNC_MENU_FreeResources(work);
    param->result = work->exitMode;
    GFL_HEAP_Free(work->palBufMain);
    GFL_HEAP_Free(work->palBufSub);
    APP_KEYCURSOR_Delete(work->keyCursor);
    BG_SYS_FreeLayerBuf(5);
    PRINTSYS_QUE_Clear(work->printQue);
    PRINTSYS_QUE_Delete(work->printQue);
    if (work->msgWin) BMP_WIN_Delete(work->msgWin);
    TCBL_Destroy(work->tcbl);
    APP_TASKMENU_RES_Delete(work->taskMenuRes);
    BMP_WIN_Exit();
    BG_SYS_Delete();
    PROCSYS_FreeProcWork(proc);
    GFL_HEAP_DeleteChecked(31);
    return 1;
}
