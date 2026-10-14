/*
 * file:     worldtrade_search.c
 * unit:     yes
 * function: WORLDTRADE_SEARCH_Init, WORLDTRADE_SEARCH_Main, WORLDTRADE_SEARCH_Exit, WORLDTRADE_SEARCH_SetupBgPlanes, WORLDTRADE_SEARCH_ExitBgPlanes, WORLDTRADE_SEARCH_LoadBgGraphics, WORLDTRADE_SEARCH_CreateActors, WORLDTRADE_SEARCH_DeleteActors, WORLDTRADE_SEARCH_CreateWindows, WORLDTRADE_SEARCH_DeleteWindows, WORLDTRADE_SEARCH_CreateStrings, WORLDTRADE_SEARCH_DeleteStrings, WORLDTRADE_SEARCH_UpdateCursorVisibility, WORLDTRADE_SEARCH_HitTestButtons, WORLDTRADE_SEARCH_HandleButton, WORLDTRADE_SEARCH_StateMainInput, WORLDTRADE_SEARCH_StateConfirmSearch, WORLDTRADE_SEARCH_StartDownloadMatchData, WORLDTRADE_SEARCH_WaitDownloadResult, WORLDTRADE_SEARCH_StateUpdateHistorySlots, WORLDTRADE_SEARCH_StateShowEmptyHistoryMessage, WORLDTRADE_SEARCH_StateCountdownMessage, WORLDTRADE_SEARCH_StateShowClearedMessage, WORLDTRADE_SEARCH_StatePrintMessage171, WORLDTRADE_SEARCH_StatePrintMessage172, WORLDTRADE_SEARCH_GetSelectedButton, WORLDTRADE_SEARCH_UpdateKeyCursor, WORLDTRADE_SEARCH_SelectButton, WORLDTRADE_SEARCH_StateStartWipeOutPage, WORLDTRADE_SEARCH_StateStartWipeOutDisconnect, WORLDTRADE_SEARCH_StatePrintNamePrompt, WORLDTRADE_SEARCH_StateOpenNameMenu, WORLDTRADE_SEARCH_StateNameMenuInput, WORLDTRADE_SEARCH_StatePrintGenderPrompt, WORLDTRADE_SEARCH_StateOpenGenderMenu, WORLDTRADE_SEARCH_StateGenderMenuInput, WORLDTRADE_SEARCH_StatePrintLevelPrompt, WORLDTRADE_SEARCH_StateOpenLevelMenu, WORLDTRADE_SEARCH_StateLevelMenuInput, WORLDTRADE_SEARCH_StatePrintConditionPrompt, WORLDTRADE_SEARCH_StateOpenConditionMenu, WORLDTRADE_SEARCH_StateConditionMenuInput, WORLDTRADE_SEARCH_StateOpenClearConfirm, WORLDTRADE_SEARCH_StateClearConfirmInput, WORLDTRADE_SEARCH_StateReturnToMain, WORLDTRADE_SEARCH_StatePrintMessage9E, WORLDTRADE_SEARCH_StateWaitMessage, WORLDTRADE_SEARCH_StateWaitMessageOrKey, WORLDTRADE_SEARCH_StateWaitMessageTimed, WORLDTRADE_SEARCH_StateScrollOut, WORLDTRADE_SEARCH_StateWaitWipeIn, WORLDTRADE_SEARCH_StateHistoryInput, WORLDTRADE_SEARCH_StateCursorAnimA, WORLDTRADE_SEARCH_StateCursorAnimB, WORLDTRADE_SEARCH_StateCursorAnimC, WORLDTRADE_SEARCH_PrintMessage, WORLDTRADE_SEARCH_DrawFormLabels, WORLDTRADE_SEARCH_DrawHistoryHeader, WORLDTRADE_SEARCH_CompareRecords, WORLDTRADE_SEARCH_ScrollBgs, WORLDTRADE_SEARCH_SetBlendEffect
 * address:  0x021FD924
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from worldtrade_box.c, worldtrade_enter.c, worldtrade_adapter.c, WORLDTRADE_ADAPTER_QueueMessagePrint.c by tools/splitfile.py.
 *
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   WORLDTRADE_SUBLCD_UpdateSlotPalettes 0x021FFB20 thumb ov135
 *   func_020307B0 0x020307B0 arm
 *   func_020490F4  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_02034714 0x02034714 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   WORLDTRADE_TITLE_ScrollBg 0x021FFFE8 thumb ov135
 *   func_0207D55C 0x0207D55C arm
 *   WORLDTRADE_TITLE_ExitBgPlanes 0x022000E4 thumb ov135
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BG_SYS_GetSubVisiblePlanes  0x02043668  arm
 *   func_0203FC28  0x0203FC28  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040588  0x02040588  arm
 *   func_02040B94  0x02040B94  arm
 *   sub_020403F4  0x020403F4  arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   WORLDTRADE_TITLE_LoadSubBgSwap 0x02200B34 thumb ov135
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   func_020355C4  0x020355C4  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   WORLDTRADE_INPUT_PrintStringAlignedLine  0x021F91A0  thumb
 *   WORLDTRADE_TITLE_CreateMenuWindow  0x02200BAC  thumb
 *   WORLDTRADE_ADAPTER_DeletePrintStream 0x02202940 thumb ov135
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_02030734 0x02030734 arm
 *   WORLDTRADE_ADAPTER_IsStreamDone  0x02202840  thumb  ov135
 *   BMP_WIN_GetBmp   0x02045770  arm
 *   BMP_Clear   0x02043B5C  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   WORLDTRADE_ADAPTER_QueuePrintDefaultColor  0x02202858  thumb  ov135
 *   func_02045CAC  0x02045CAC  arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WORLDTRADE_INPUT_MenuCreate 0x021F9890 thumb ov135
 *   WORLDTRADE_INPUT_MenuDelete 0x021F99D0 thumb ov135
 *   BMP_WIN_Create 0x020450F0 arm
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   WORLDTRADE_ENTER_ClearListRange 0x021F8990 thumb ov135
 *   WORLDTRADE_INPUT_MenuSetMode  0x021F9968  thumb  ov135
 *   WORLDTRADE_INPUT_MenuUpdate 0x021F99F0 thumb ov135
 *   WORLDTRADE_ENTER_SetListRangeEntry 0x021F89A8 thumb ov135
 *   POKE_PERSONAL_Create 0x0201ADE4 thumb
 *   POKE_PERSONAL_GetParam 0x0201AE1C thumb
 *   POKE_PERSONAL_Delete 0x0201AE14 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   TOUCHPANEL_HitTrg  0x02035C08  arm  arm9
 *   TOUCHPANEL_GetTrg  0x02035C60  arm  arm9
 *   CLACT_IsActorAnimActive  0x0204B98C  arm  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   WORLDTRADE_ClearBusyFlag  0x021F4EC8  thumb  ov135
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb
 *   WORLDTRADE_CancelSave  0x021F513C  thumb  ov135
 *   WORLDTRADE_DeleteTimeIcon  0x021F4FC4  thumb  ov135
 *   DPW_TR_IsAsyncEnd  0x021C866C  arm
 *   DPW_TR_GetAsyncResult  0x021C86A8  arm
 *   func_021C8658 0x021C8658 arm ov114
 *   func_02040C14  0x02040C14  arm
 *   func_02040DA8  0x02040DA8  arm
 *   WORLDTRADE_SetActorPos  0x021F4FF4  thumb
 *   func_020355D8  0x020355D8  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm  arm9
 *   WORLDTRADE_ADAPTER_QueueMessagePrint  0x02202B20  thumb
 *   WORLDTRADE_DEPOSIT_GetConditionIndex 0x021F886C thumb ov135
 *   func_0201F5BC 0x0201F5BC thumb
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   WORLDTRADE_UpdateTaskMenuYesNo 0x021F4D14 thumb ov135
 *   WORLDTRADE_CloseTaskMenu 0x021F4CE4 thumb ov135
 *   WORLDTRADE_SetActorSurfacePos 0x021F4EA0 thumb ov135
 *   WORLDTRADE_INPUT_PrintStringAlignedWrapped  0x021F91DC  thumb
 *   func_02040618  0x02040618  arm
 *   WORLDTRADE_DEPOSIT_PrintName  0x021F7F9C  thumb
 *   WORLDTRADE_DEPOSIT_PrintModeLabelAligned  0x021F8098  thumb
 *   WORLDTRADE_DEPOSIT_PrintLevelRange  0x021F8154  thumb
 *   WORLDTRADE_DEPOSIT_PrintMessageLine  0x021F8010  thumb
 *   d_02203D80 0x02203D80 data a4
 *   d_02203D46 0x02203D46 data a2
 *   g_022037F4  0x022037F4  data  ov135
 *   g_02203844  0x02203844  data  ov135
 *   g_02203864  0x02203864  data  ov135
 *   g_02203804  0x02203804  data  ov135
 *   g_02203824  0x02203824  data  ov135
 *   tbl_02203D38   0x02203D38  data  a1
 *   tbl_022037A8   0x022037A8  data  a2
 *   tbl_022037B0   0x022037B0  data  a2
 *   tbl_022037BC   0x022037BC  data  a2
 *   WORLDTRADE_DEPOSIT_GetSpeciesFlag  0x021F84EC  thumb
 *   g_02203E18     0x02203E18  data  ov135
 *   g_022037D4  0x022037D4  data  ov135
 *   WORLDTRADE_DEPOSIT_CheckGenderEvent 0x021F7B9C thumb ov135
 *   tbl_02203D46   0x02203D46  data  a2
 *   DPW_TR_DownloadMatchDataAsync 0x021C8B18 arm ov114
 *   DPW_TR_DownloadMatchDataRawAsync 0x021C8BC4 arm ov114
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   GFL_NET_STATE_SetWifiError  0x0203CA04  arm
 *   GFL_NET_STATE_ClearErrorMode  0x0203C968  arm
 *   WORLDTRADE_DEPOSIT_GetLevelBracket 0x021F882C thumb ov135
 *   WORLDTRADE_ENTER_ClearFlags 0x021F88B0 thumb ov135
 *   d_02202EAC 0x02202EAC data a4
 *   WORLDTRADE_OpenTaskMenuYesNoDefault  0x021F4BE0  thumb  ov135
 *   d_02203D4A 0x02203D4A data a2
 *   func_020413B0  0x020413B0  arm
 *   WORLDTRADE_SUBLCD_CheckButtonTouch 0x021FFB00 thumb ov135
 *   WORLDTRADE_SUBLCD_UpdateSlotAnims 0x021FFBC8 thumb ov135
 */
#include "worldtrade_types.h"
#include "../../matched/include/Obj00018.h"
#include "../../matched/include/Obj14174.h"
#include "../../matched/include/Obj23412.h"
#include "../../matched/include/Obj23413.h"
#include "../../matched/include/Obj23414.h"
#include "../../matched/include/Obj23415.h"
#include "../../matched/include/Obj12216.h"
#include "../../matched/include/Obj12217.h"
#include "../../matched/include/Obj07250.h"

extern void MI_CpuFill8(void *p, u32 v, u32 n);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 func_020307B0(void *p);

extern void func_02034714(const char *expr, u32 line, const char *file);

extern void *func_020490F4(u32 id, u32 heap);

extern void *func_02045EC0(struct MsgBank *bank, u32 index);

extern void STRBUF_Delete(struct U16Vec *vec);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);

extern void func_0207D658(u32 addr, int plane, int brightness);

extern void BG_SYS_SetSubVisiblePlanes(u32 a);

extern u32 BG_SYS_GetSubVisiblePlanes(void);

extern void func_020414EC(u32 i);

extern void func_02040588(unsigned char which, unsigned char enable);

extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);

extern void sub_020403F4(u32 i);

extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);

extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);

extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

extern u8 func_020355C4(void);

extern void CLACT_DeleteActor(struct Obj *p);

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern void func_020355D8(u8 v);

extern u32 KEY_GetTrg(void);

extern u32 CLACT_IsActorAnimActive(struct Actor *a);

extern int TOUCHPANEL_GetTrg(void);

extern void BMP_WIN_TransferChars(struct Descriptor *a);

extern void func_0201F73C(void *a0, int a1, int a2, int a3);

extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);

extern void WORLDTRADE_INPUT_MenuDelete(u8 *p);

extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);

extern void WORLDTRADE_ENTER_ClearListRange(u8 *p);

extern void WORLDTRADE_INPUT_MenuSetMode(u8 *p, int mode);

extern void *POKE_PERSONAL_Create(u32,int,u32);

extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);

extern void POKE_PERSONAL_Delete(void *p);

extern void WORLDTRADE_ENTER_SetListRangeEntry(u8 *p, int i, u16 a, u16 b);

extern void WORLDTRADE_ClearBusyFlag(Work *p);

extern s32 DPW_TR_GetAsyncResult(void);

extern void WORLDTRADE_CancelSave(Work *p);

extern void WORLDTRADE_DeleteTimeIcon(Work *p);

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

extern void func_020409B4(u32 layer);

extern void WORLDTRADE_SetActorPos(u32 a, u32 b, u32 c);

typedef struct {
    void *w00;
    void *w04;
    void *obj;
    void *w0c;
    void *w10;
    void *w14;
    void *bank;
    void *names;
    void *w20;
    u32 w24;
    u32 w28;
    u32 arg;
} Init;

typedef struct { u16 x, y, a, b; } Pos_021FD924;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 f7;
} ObjPos_vD924;

typedef struct {
    u8 page;
    u8 slot;
} Sel;

typedef struct {
    u16 x;
    u16 y;
    u16 anim;
} CurPos_vD924;

typedef struct {
    Sel sel[7];
    CurPos_vD924 cur[1];
} SelTbl;

typedef struct {
    u16 x;
    u16 y;
} Pos_021FDB74;

typedef struct {
    u16 x;
    u16 y;
    u16 anim;
    u16 anim2;
} CurPos_vE338;

typedef struct { short id; s8 a, b, c, d; u8 mode, flag; } Request_021FB800;

extern void CLACT_SetActorDrawEnable(struct Obj *obj, unsigned int on);

extern void CLACT_SetActorAutoAnim(struct Obj *,u32);

extern int WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);

extern int WORLDTRADE_DEPOSIT_GetConditionIndex(int,int,int);

extern void func_0203FC28(struct DispConfig *cfg);

extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);

extern void ARC_TOOL_DeleteHandle(void *);

extern void CLACT_SetActorBgPriority(void *, int);

extern void WORLDTRADE_SetNextState(void *p, u32 a, u32 b);

extern void WORLDTRADE_SetStateAndReturn(void *p, u32 a, u32 b);

extern void GFL_USE_PlaySeDefaultVolume(unsigned);

extern int WORLDTRADE_UpdateTaskMenuYesNo(char *p);

extern void WORLDTRADE_CloseTaskMenu(char *p);

extern void func_0201F7A8(void *p, unsigned kind);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern void STRBUF_Delete(struct U16Vec *vec);

extern void WORLDTRADE_INPUT_PrintStringAlignedLine(void *p, void *b, u32 c, u32 d, u32 e, u16 f, void *g);

extern int func_0207D55C(vu16 *reg);

extern void WORLDTRADE_SetActorSurfacePos(void *, int, int);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern int TOUCHPANEL_HitTrg(const void *);

extern unsigned WIPE_SYS_EndCheck(void);

extern void WORLDTRADE_INPUT_PrintStringAlignedWrapped(void *p, void *b, u32 c, u32 d, u32 e, u16 f, void *g);

extern void func_02040618(u32 layer, u32 a, u32 b);

extern void *WORLDTRADE_INPUT_MenuCreate(Init *init, u32 a, u32 b);

extern void WORLDTRADE_DEPOSIT_PrintName(void *win, void *bank, u32 index, u32 y, u32 x, u16 color, void *g);

extern void WORLDTRADE_DEPOSIT_PrintModeLabelAligned(void *win, void *bank, int mode, int force, u32 x, int y, u16 color, void *g);

extern void WORLDTRADE_DEPOSIT_PrintLevelRange(void *win, void *bank, int idx, u32 e, u32 y, u16 color, int alt, void *g);

extern void WORLDTRADE_DEPOSIT_PrintMessageLine(void *win, void *bank, void *bank2, u32 index, u32 y, u32 x, u16 color, void *g);

extern void func_02040C14(u32 a, u32 b, u32 c, u32 d);

extern void func_02040DA8(u32 idx, u32 count, u32 tile);

extern u8 *WORLDTRADE_DEPOSIT_GetSpeciesFlag(u32 id);

extern int WORLDTRADE_DEPOSIT_CheckGenderEvent(u8 *p, int event);

extern void DPW_TR_DownloadMatchDataAsync(void *, int, void *);

extern void DPW_TR_DownloadMatchDataRawAsync(const void *p, unsigned int x);

extern int DPW_TR_IsAsyncEnd();

extern void GFL_USE_StopAllSe(void);

extern u32 func_0200FBB0(void);

extern void func_0200FBA0(void);

extern void GFL_NET_STATE_SetWifiError(void);

extern void GFL_NET_STATE_ClearErrorMode(void);

extern void func_021C8658(u8 *p);

extern int WORLDTRADE_INPUT_MenuUpdate(void *obj);

extern void WORLDTRADE_DEPOSIT_GetLevelBracket(u8 *dst, int i, int kind);

extern void WORLDTRADE_ENTER_ClearFlags(Work *p, u32 n);

extern void WORLDTRADE_OpenTaskMenuYesNoDefault(u32 a, u32 b, u32 c, u32 d, u8 e);

extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);

int WORLDTRADE_SEARCH_Init(Work *p);

int WORLDTRADE_SEARCH_Main(Work *p);

int WORLDTRADE_SEARCH_Exit(Work *p);

void WORLDTRADE_SEARCH_SetupBgPlanes(void);

void WORLDTRADE_SEARCH_ExitBgPlanes(void);

void WORLDTRADE_SEARCH_LoadBgGraphics(Work *p);

void WORLDTRADE_SEARCH_CreateActors(Work *p);

void WORLDTRADE_SEARCH_DeleteActors(Work *p);

void WORLDTRADE_SEARCH_CreateWindows(Work *p);

void WORLDTRADE_SEARCH_DeleteWindows(unsigned char *p);

void WORLDTRADE_SEARCH_CreateStrings(Work *p);

void WORLDTRADE_SEARCH_DeleteStrings(Work *p);

int WORLDTRADE_SEARCH_UpdateCursorVisibility(Work *p);

int WORLDTRADE_SEARCH_HitTestButtons(void);

void WORLDTRADE_SEARCH_HandleButton(Work *p, int mode);

int WORLDTRADE_SEARCH_StateMainInput(Work *p);

int WORLDTRADE_SEARCH_StateConfirmSearch(Work *p);

int WORLDTRADE_SEARCH_StartDownloadMatchData(WorldtradeAdapterObj3 *p);

int WORLDTRADE_SEARCH_WaitDownloadResult(Work *p);

int WORLDTRADE_SEARCH_StateUpdateHistorySlots(Work *p);

int WORLDTRADE_SEARCH_StateShowEmptyHistoryMessage(Work *p);

int WORLDTRADE_SEARCH_StateCountdownMessage(Work *p);

int WORLDTRADE_SEARCH_StateShowClearedMessage(Work *p);

int WORLDTRADE_SEARCH_StatePrintMessage171(Work *p);

int WORLDTRADE_SEARCH_StatePrintMessage172(Work *p);

int WORLDTRADE_SEARCH_GetSelectedButton(Work *p);

void WORLDTRADE_SEARCH_UpdateKeyCursor(Work *p);

void WORLDTRADE_SEARCH_SelectButton(Work *p, int i);

int WORLDTRADE_SEARCH_StateStartWipeOutPage(Work *p);

int WORLDTRADE_SEARCH_StateStartWipeOutDisconnect(Work *p);

int WORLDTRADE_SEARCH_StatePrintNamePrompt(Work *p);

int WORLDTRADE_SEARCH_StateOpenNameMenu(Work *p);

int WORLDTRADE_SEARCH_StateNameMenuInput(Work *p);

int WORLDTRADE_SEARCH_StatePrintGenderPrompt(Work *p);

int WORLDTRADE_SEARCH_StateOpenGenderMenu(Work *p);

int WORLDTRADE_SEARCH_StateGenderMenuInput(Work *p);

int WORLDTRADE_SEARCH_StatePrintLevelPrompt(Work *p);

int WORLDTRADE_SEARCH_StateOpenLevelMenu(Work *p);

int WORLDTRADE_SEARCH_StateLevelMenuInput(Work *p);

int WORLDTRADE_SEARCH_StatePrintConditionPrompt(Work *p);

int WORLDTRADE_SEARCH_StateOpenConditionMenu(Work *p);

int WORLDTRADE_SEARCH_StateConditionMenuInput(Work *p);

int WORLDTRADE_SEARCH_StateOpenClearConfirm(Work *p);

int WORLDTRADE_SEARCH_StateClearConfirmInput(Work *p);

int WORLDTRADE_SEARCH_StateReturnToMain(Work *p);

int WORLDTRADE_SEARCH_StatePrintMessage9E(Work *p);

int WORLDTRADE_SEARCH_StateWaitMessage(u8 *p);

int WORLDTRADE_SEARCH_StateWaitMessageOrKey(u8 *p);

int WORLDTRADE_SEARCH_StateWaitMessageTimed(u8 *p);

int WORLDTRADE_SEARCH_StateScrollOut(Work *p);

int WORLDTRADE_SEARCH_StateWaitWipeIn(Work *p);

int WORLDTRADE_SEARCH_StateHistoryInput(Work *p);

int WORLDTRADE_SEARCH_StateCursorAnimA(Work *p);

int WORLDTRADE_SEARCH_StateCursorAnimB(Work *p);

int WORLDTRADE_SEARCH_StateCursorAnimC(Work *p);

void WORLDTRADE_SEARCH_PrintMessage(u8 *p, u32 k, int b, int c, int d);

void WORLDTRADE_SEARCH_DrawFormLabels(void **win, void **win2, void *bank, void *g);

void WORLDTRADE_SEARCH_DrawHistoryHeader(void *win, void *bank, int flag, void *g);

int WORLDTRADE_SEARCH_CompareRecords(Rec *x, Rec *y, int m, int n);

void WORLDTRADE_SEARCH_ScrollBgs(Work *p);

void WORLDTRADE_SEARCH_SetBlendEffect(u32 v);

int WORLDTRADE_SUBLCD_CheckButtonTouch(int n);

void WORLDTRADE_SUBLCD_UpdateSlotPalettes(Work *p, int count, int flag);

void WORLDTRADE_SUBLCD_UpdateSlotAnims(Work *p);

void WORLDTRADE_TITLE_ScrollBg(Work *p, u32 a, u32 b);

void WORLDTRADE_TITLE_ExitBgPlanes(Work *p);

void WORLDTRADE_TITLE_LoadSubBgSwap(Work *p);

void WORLDTRADE_TITLE_CreateMenuWindow(Work *p, u32 k);

u32 WORLDTRADE_ADAPTER_IsStreamDone(PrintStreamCtx *p);

u32 WORLDTRADE_ADAPTER_QueuePrintDefaultColor(void *p,u8 b,void *s,u32 x,u32 y,void *out);

void WORLDTRADE_ADAPTER_DeletePrintStream(struct Obj *p);

extern const Pos_021FD924 d_02203D46[];

extern struct DispConfig g_022037F4;

extern struct BgTemplate g_02203844;

extern struct BgTemplate g_02203864;

extern struct BgTemplate g_02203804;

extern struct BgTemplate g_02203824;

extern const SelTbl tbl_02203D38;

extern const Pos_021FDB74 tbl_022037A8[];

extern const Pos_021FDB74 tbl_022037B0[];

extern const Pos_021FDB74 tbl_022037BC[];

extern u8 g_02203E18[];

extern char g_022037D4[];

extern const CurPos_vE338 tbl_02203D46[];

extern const int d_02202EAC;

extern const u16 d_02203D4A[][4];

int WORLDTRADE_SEARCH_Init(Work *p)
{
    Init init;

    WORLDTRADE_SEARCH_CreateStrings(p);
    WORLDTRADE_SEARCH_SetupBgPlanes();
    WORLDTRADE_SEARCH_LoadBgGraphics(p);
    WORLDTRADE_SEARCH_CreateWindows((Work *)p);
    WORLDTRADE_SEARCH_CreateActors((Work *)p);
    WORLDTRADE_TITLE_ScrollBg(p, 0, 0);
    WORLDTRADE_TITLE_LoadSubBgSwap(p);
    WORLDTRADE_TITLE_CreateMenuWindow(p, 4);
    p->f12E4 = 0;
    init.w00 = p->fD50;
    init.w04 = p->fDD4;
    init.obj = p->mark;
    init.w0c = p->btn[0];
    init.w10 = p->btn[1];
    init.w14 = p->cursor_p;
    init.bank = p->bank;
    init.names = p->names;
    init.w20 = p->msg_p;
    init.w24 = p->ctx->f10;
    init.w28 = p->aux->f14;
    p->menu = WORLDTRADE_INPUT_MenuCreate(&init, 2, 1);
    WORLDTRADE_SEARCH_DrawFormLabels(p->win_p4, p->win2, p->bank, p->fFA0);
    WORLDTRADE_SEARCH_DrawHistoryHeader(p->wDB0, p->bank, p->fE1A, p->fFA0);
    WORLDTRADE_DEPOSIT_PrintName(p->win_p4[1], p->names, p->rec.name, 0, 0, 0x3C40, p->fFA0);
    WORLDTRADE_DEPOSIT_PrintModeLabelAligned(p->win_p4[3], p->bank, p->rec.mode, 1, 0, 0, 0x3C40, p->fFA0);
    WORLDTRADE_DEPOSIT_PrintLevelRange(p->wDA4, p->bank, WORLDTRADE_DEPOSIT_GetConditionIndex(p->rec.key, p->rec.val, 1), 0, 0, 0x3C40, 1, p->fFA0);
    WORLDTRADE_DEPOSIT_PrintMessageLine(p->win2[1], p->msg_p, p->bank, p->fF84, 0, 0, 0x3C40, p->fFA0);
    p->vblank = WORLDTRADE_SEARCH_ScrollBgs;
    if (p->kind == 0xd) {
        WIPE_SYS_Start((void *)3, 1, 1, 0, 6, 1, 0x48);
    }
    p->state = 0;
    return 1;
}

extern int (*const d_02203D80[])(void *);

int WORLDTRADE_SEARCH_Main(Work *p)
{
    int result;
    int i;
    int x, y;
    result = d_02203D80[p->state_i]((unsigned char *)p);
    for (i = 0; i < 8; ++i)
        WORLDTRADE_SetActorSurfacePos(*(void **)((unsigned char *)p + i * 4 + 0xd0c), *(short *)((unsigned char *)p + i * 4 + 0xec4), *(short *)((unsigned char *)p + i * 4 + 0xec6) + p->scroll);
    x = WORLDTRADE_SEARCH_GetSelectedButton((Work *)p);
    y = WORLDTRADE_SEARCH_GetSelectedButton((Work *)p);
    WORLDTRADE_SetActorPos(p->cursor, d_02203D46[x].x, d_02203D46[y].y - p->scroll);
    WORLDTRADE_SetActorSurfacePos((void *)p->fD38, 55, p->scroll + 168);
    return result;
}

int WORLDTRADE_SEARCH_Exit(Work *p)
{
    (*(int *)&p->every) = 0;
    WORLDTRADE_INPUT_MenuDelete(p->menu);
    WORLDTRADE_SEARCH_DeleteActors(p);
    WORLDTRADE_SEARCH_DeleteStrings(p);
    WORLDTRADE_SEARCH_DeleteWindows((unsigned char *)p);
    WORLDTRADE_SEARCH_ExitBgPlanes();
    if (*(int *)&p->x14 == 1)
        *(int *)&p->f12E4 = 1;
    WORLDTRADE_TITLE_ExitBgPlanes(p);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj *)*(u32 *)(void * *)&p->fD38), 0);
    WORLDTRADE_ClearBusyFlag(p);
    return 0;
}

/*
 * Four-layer bring-up, every layer 020414EC'd, with the tilemap clears for
 * layers 2, 0 and 3 in that order.
 */
void WORLDTRADE_SEARCH_SetupBgPlanes(void)
{
    struct DispConfig c = g_022037F4;
    u32 v = BG_SYS_GetSubVisiblePlanes();

    func_0203FC28(&c);
    BG_SYS_SetSubVisiblePlanes(v);
    {
        struct BgTemplate t = g_02203844;
        func_0203FCA0(0, &t, 0);
    }
    func_020414EC(0);
    func_02040588(0, 1);
    {
        struct BgTemplate t = g_02203864;
        func_0203FCA0(1, &t, 0);
    }
    func_020414EC(1);
    func_02040588(1, 1);
    {
        struct BgTemplate t = g_02203804;
        func_0203FCA0(2, &t, 0);
    }
    func_020414EC(2);
    func_02040588(2, 1);
    {
        struct BgTemplate t = g_02203824;
        func_0203FCA0(3, &t, 0);
    }
    func_020414EC(3);
    func_02040588(3, 1);
    func_02040B94(2, 0x20, 0, 0x48);
    func_02040B94(0, 0x20, 0, 0x48);
    func_02040B94(3, 0x20, 0, 0x48);
}

/*
 * Poke the channel-selection helper with 2, 1, 0, 3 in turn.
 */
void WORLDTRADE_SEARCH_ExitBgPlanes(void)
{
    sub_020403F4(2);
    sub_020403F4(1);
    sub_020403F4(0);
    sub_020403F4(3);
}

/*
 * The parameterless member: handle open, the B68 and B40 window calls, two
 * F5BC text calls, three 49658/498F4 draws and the second B40 pair, then
 * the 49238 release.  Contents 166 of 168 bytes (pool pad).
 */
void WORLDTRADE_SEARCH_LoadBgGraphics(Work *p)
{
    void *h = func_020490F4(0x60, 0x48);

    func_02049B68(h, 2, 0, 0, 0x60, 0x48);
    func_02049B40(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    func_0201F5BC(0, 1, 0xe, 0, 0x48);
    func_0201F5BC(0, 0x1f, 0xb, 0, 0x48);
    func_02049658(h, 0xb, 1, 0, 0, 1, 0x48);
    func_020498F4(h, 0x17, 1, 0, 0, 1, 0x48);
    func_02049658(h, 0xc, 2, 0, 0, 1, 0x48);
    func_02049B40(0x17, 5, 4, 0x20, 0x20, 0x48);
    ARC_TOOL_DeleteHandle(h);
}

void WORLDTRADE_SEARCH_CreateActors(Work *p)
{
    ObjPos_vD924 pos;

    MI_CpuFill8(&pos, 0, sizeof(pos));
    pos.x = tbl_02203D38.cur[0].x;
    pos.y = tbl_02203D38.cur[0].y;
    p->cursor_p = CLACT_CreateActor(p->res, (u32)p->set2, (u32)p->set[1], (u32)p->set3, &pos, 0, 0x48);
    CLACT_SetActorAutoAnim(p->cursor_p, 1);
    CLACT_SetActorAnimSeq(p->cursor_p, tbl_02203D38.cur[0].anim);
    CLACT_SetActorBgPriority(p->cursor_p, 1);
    if (func_020355C4() == 1) {
        CLACT_SetActorDrawEnable(p->cursor_p, 0);
    } else {
        CLACT_SetActorDrawEnable(p->cursor_p, 1);
    }
    pos.x = 0xA0;
    pos.y = 0x20;
    p->mark = CLACT_CreateActor(p->res, (u32)p->set2, (u32)p->set[1], (u32)p->set3, &pos, 0, 0x48);
    CLACT_SetActorAnimSeq(p->mark, 4);
    CLACT_SetActorDrawEnable(p->mark, 0);
    pos.x = 0xE4;
    pos.y = 0x75;
    p->btn[0] = CLACT_CreateActor(p->res, (u32)p->set[0], (u32)p->set[1], (u32)p->set[2], &pos, 0, 0x48);
    CLACT_SetActorAnimSeq(p->btn[0], 0x26);
    CLACT_SetActorDrawEnable(p->btn[0], 0);
    pos.x = 0x8C;
    p->btn[1] = CLACT_CreateActor(p->res, (u32)p->set[0], (u32)p->set[1], (u32)p->set[2], &pos, 0, 0x48);
    CLACT_SetActorAnimSeq(p->btn[1], 0x27);
    CLACT_SetActorDrawEnable(p->btn[1], 0);
    GFL_NET_RestartWithDefaultTimeout(0, 0x48);
}

void WORLDTRADE_SEARCH_DeleteActors(Work *p) {CLACT_DeleteActor((struct Obj *)(*(struct Obj * *)&p->cursor_p));CLACT_DeleteActor((struct Obj *)(*(struct Obj * *)&p->mark));CLACT_DeleteActor((struct Obj *)(*(struct Obj * *)&p->btn[0]));CLACT_DeleteActor((struct Obj *)(*(struct Obj * *)&p->btn[1]));}

void WORLDTRADE_SEARCH_CreateWindows(Work *p)
{
    int i;
    u32 v;

    p->frame = BMP_WIN_Create(0, (u8)2, (u8)0x15, (u8)0x1b, 2, 0xd, (u16)1);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->frame)), 0);
    v = p->frame;
    BMP_WIN_TransferChars((struct Descriptor *)v);
    BMP_WIN_MakeScreen((struct Cfg *)v);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)v));
    func_02040C14(3, 0, 1, 0);
    for (i = 0; i < 6; i++) {
        p->item_u6[i] = BMP_WIN_Create(3, (u8)tbl_022037BC[i].x, (u8)tbl_022037BC[i].y, (u8)0xb, 2, 0xd, (u16)0);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->item_u6[i])), 0);
        v = p->item_u6[i];
        BMP_WIN_TransferChars((struct Descriptor *)v);
        BMP_WIN_MakeScreen((struct Cfg *)v);
        func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)v));
    }
    for (i = 0; i < 2; i++) {
        p->tab[i] = BMP_WIN_Create(3, (u8)tbl_022037A8[i].x, (u8)tbl_022037A8[i].y, (u8)0x1c, 2, 0xd, (u16)0);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->tab[i])), 0);
        v = p->tab[i];
        BMP_WIN_TransferChars((struct Descriptor *)v);
        BMP_WIN_MakeScreen((struct Cfg *)v);
        func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)v));
    }
    for (i = 0; i < 3; i++) {
        p->page[i] = BMP_WIN_Create(3, (u8)tbl_022037B0[i].x, (u8)tbl_022037B0[i].y, (u8)0xa, 2, 0xd, (u16)0);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->page[i])), 0);
        v = p->page[i];
        BMP_WIN_TransferChars((struct Descriptor *)v);
        BMP_WIN_MakeScreen((struct Cfg *)v);
        func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)v));
    }
}

void WORLDTRADE_SEARCH_DeleteWindows(unsigned char *p)
{
    int i;
    WORLDTRADE_ADAPTER_DeletePrintStream((struct Obj *)((struct Obj *)(p + 0xfa0)));
    BMP_WIN_Delete(((struct Obj14174 *)p)->fDE0);
    BMP_WIN_Delete(((struct Obj14174 *)p)->fD40);
    for (i = 0; i < 9; ++i)
        BMP_WIN_Delete(*(void **)(p + i * 4 + 0xd90));
    for (i = 0; i < 2; ++i)
        BMP_WIN_Delete(*(void **)(p + i * 4 + 0xdd8));
    func_02040DA8(3, 1, 0);
}

void WORLDTRADE_SEARCH_CreateStrings(Work *p)
{
    p->str = STRBUF_Create(0xb4, 0x48);
    p->fB8C = func_02045EC0(p->bank, 0x30);
    (*(void **)&p->st) = func_02030734(0x48, 0x30, 0, (const char *)g_02203E18, 0x351);
    MIi_CpuClearFast(0, (void *)p->st, 0x30);
    *(u8 * *)&((struct Obj23412 *)(*(u8 * *)(void **)&p->st))->f14 = WORLDTRADE_DEPOSIT_GetSpeciesFlag(0x48);
    WORLDTRADE_ENTER_ClearListRange((u8 *)p + 0xeec);
}

void WORLDTRADE_SEARCH_DeleteStrings(Work *p) {func_020307B0(((struct Obj23413 *)(*(char * *)(void **)&p->st))->f14);func_020307B0((void *)p->st);STRBUF_Delete(*(struct U16Vec * *)&p->str);STRBUF_Delete(*(struct U16Vec * *)&p->fB8C);}

int WORLDTRADE_SEARCH_UpdateCursorVisibility(Work *p)
{
    if (func_020355C4() == 1)
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj *)p->cursor), 0);
    else
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj *)p->cursor), 1);
    if (p->kind == 15) {
        if ((*(int *)&p->d0) != 0)
            WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 38, 0, 0, 0xf0f);
        else
            WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 8, 1, 0, 0xf0f);
        if (func_0207D55C((u16 *)0x0400006c) == -16) {
            WIPE_SYS_Start(0, 1, 1, 0, 16, 1, 0x48);
            *(int *)&p->state = 33;
        } else {
            *(int *)&p->state = 1;
        }
    } else {
        WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 8, 1, 0, 0xf0f);
        WORLDTRADE_SetNextState(p, 23, 1);
    }
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj *)p->fD38), 1);
    return 2;
}

int WORLDTRADE_SEARCH_HitTestButtons(void)
{
    return TOUCHPANEL_HitTrg(g_022037D4);
}

void WORLDTRADE_SEARCH_HandleButton(Work *p, int mode)
{
    u32 h,v;
    switch(mode) {
    case 0: p->state=4; break;
    case 1:
        if(p->rec.name!=0) {
            h=(u32)POKE_PERSONAL_Create((u16)p->rec.name,0,0x48);
            v=POKE_PERSONAL_GetParam((const struct Personal *)h,0x14);
            POKE_PERSONAL_Delete((void *)h);
            ((struct Obj23414 *)(*(u8 * *)(void **)&p->st))->f20=v;
            if(WORLDTRADE_DEPOSIT_CheckGenderEvent((u8 *)p+0xB56,((struct Obj23415 *)(*(u8 * *)(void **)&p->st))->f20)) break;
        }
        p->state=7;
        break;
    case 2: p->state=10; break;
    case 3: p->state=13; break;
    case 4:
        if(*(u32 *)(int *)&p->d0) {
            p->state=32;
            WIPE_SYS_Start(0,0,0,0,16,1,0x48);
        }
        break;
    case 5: p->state=16; break;
    case 6:
        WORLDTRADE_SEARCH_PrintMessage((u8 *)p,15,1,0,0xF0F);
        WORLDTRADE_SetNextState(p,23,26);
        break;
    }
}

/*
 * Menu input handler. A touch on an entry (WORLDTRADE_SEARCH_HitTestButtons) selects it and
 * acts at once; otherwise the d-pad moves the cursor (WORLDTRADE_SEARCH_UpdateKeyCursor) and A
 * acts on the current entry, B jumps to the last entry of page 1. Entry 1
 * hands the +0xB56 record to WORLDTRADE_DEPOSIT_CheckGenderEvent, entry 5 compares the two
 * records, entry 4 depends on the +0xD0 word; every path picks the next
 * state (+0x28) and a sound. Always returns 2.
 */
int WORLDTRADE_SEARCH_StateMainInput(Work *p)
{
    int sel = WORLDTRADE_SEARCH_HitTestButtons();

    if (sel != -1) {
        func_020355D8(1);
        WORLDTRADE_SEARCH_SelectButton(p, sel);
        sel = WORLDTRADE_SEARCH_GetSelectedButton(p);
        switch (sel) {
        case 1:
            if (p->rec_rec2[0].name != 0) {
                u32 h = (u32)POKE_PERSONAL_Create((u16)p->rec_rec2[0].name, 0, 0x48);
                u32 v = POKE_PERSONAL_GetParam((const struct Personal *)h, 0x14);
                POKE_PERSONAL_Delete((void *)h);
                p->st->f20 = v;
                if (WORLDTRADE_DEPOSIT_CheckGenderEvent((u8 *)(&p->rec_rec2[0]), p->st->f20) != 0) {
                    CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
                    CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                    GFL_USE_PlaySeDefaultVolume(0x557);
                    return 2;
                }
            }
            CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
            GFL_USE_PlaySeDefaultVolume(0x54C);
            CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
            p->state_i = 0x23;
            break;
        case 5:
            if (p->rec_rec2[0].name == 0 || WORLDTRADE_SEARCH_CompareRecords(&p->rec_rec2[0], &p->rec_rec2[1], p->fF84, p->fB64) != 0) {
                GFL_USE_PlaySeDefaultVolume(0x557);
            } else {
                GFL_USE_PlaySeDefaultVolume(0x54C);
            }
            CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
            CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
            p->state_i = 0x23;
            break;
        case 4:
            if (p->d0 != 0) {
                CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
                GFL_USE_PlaySeDefaultVolume(0x54C);
                CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                p->state_i = 0x23;
            } else {
                CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
                CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                GFL_USE_PlaySeDefaultVolume(0x557);
                p->state_i = 0x25;
            }
            break;
        default:
            CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
            if (sel == 6) {
                GFL_USE_PlaySeDefaultVolume(0x551);
            } else {
                GFL_USE_PlaySeDefaultVolume(0x54C);
            }
            CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
            p->state_i = 0x23;
            break;
        }
    } else if (KEY_GetTrg() != 0 && func_020355C4() == 1) {
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        func_020355D8(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return 2;
    } else {
        WORLDTRADE_SEARCH_UpdateKeyCursor(p);
        if (KEY_GetTrg() & 1) {
            sel = WORLDTRADE_SEARCH_GetSelectedButton(p);
            switch (sel) {
            case 1:
                if (p->rec_rec2[0].name != 0) {
                    u32 h = (u32)POKE_PERSONAL_Create((u16)p->rec_rec2[0].name, 0, 0x48);
                    u32 v = POKE_PERSONAL_GetParam((const struct Personal *)h, 0x14);
                    POKE_PERSONAL_Delete((void *)h);
                    p->st->f20 = v;
                    if (WORLDTRADE_DEPOSIT_CheckGenderEvent((u8 *)(&p->rec_rec2[0]), p->st->f20) != 0) {
                        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
                        CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                        GFL_USE_PlaySeDefaultVolume(0x557);
                        return 2;
                    }
                }
                CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
                GFL_USE_PlaySeDefaultVolume(0x54C);
                CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                p->state_i = 0x23;
                break;
            case 5:
                if (p->rec_rec2[0].name == 0 || WORLDTRADE_SEARCH_CompareRecords(&p->rec_rec2[0], &p->rec_rec2[1], p->fF84, p->fB64) != 0) {
                    GFL_USE_PlaySeDefaultVolume(0x557);
                } else {
                    GFL_USE_PlaySeDefaultVolume(0x54C);
                }
                CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                p->state_i = 0x23;
                break;
            case 4:
                if (p->d0 != 0) {
                    GFL_USE_PlaySeDefaultVolume(0x54C);
                    CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                    p->state_i = 0x23;
                } else {
                    CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
                    CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                    GFL_USE_PlaySeDefaultVolume(0x557);
                    p->state_i = 0x25;
                }
                break;
            default:
                if (sel == 6) {
                    GFL_USE_PlaySeDefaultVolume(0x551);
                } else {
                    GFL_USE_PlaySeDefaultVolume(0x54C);
                }
                CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                p->state_i = 0x23;
                break;
            }
        } else if (KEY_GetTrg() & 2) {
            p->st->f24 = 1;
            p->st->f2C = 2;
            CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
            p->state_i = 0x24;
            GFL_USE_PlaySeDefaultVolume(0x551);
        }
    }
    return 2;
}

int WORLDTRADE_SEARCH_StateConfirmSearch(Work *p)
{
    if (p->rec.name == 0) {
        WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 12, 1, 0, 0xf0f);
        WORLDTRADE_SetNextState(p, 23, 1);
    } else {
        if (WORLDTRADE_SEARCH_CompareRecords((Rec *)((unsigned char *)p + 0xb56), (Rec *)((unsigned char *)p + 0xb5c), p->fF84, p->fB64)) {
            WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 39, 1, 0, 0xf0f);
            WORLDTRADE_SetNextState(p, 23, 1);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x63f);
            p->f12E8 = 0x76;
            WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 13, 1, 0, 0xf0f);
            WORLDTRADE_SetNextState(p, 23, 17);
            if ((*(int *)&p->d0) > 0)
                WORLDTRADE_SUBLCD_UpdateSlotAnims(p);
        }
    }
    return 2;
}

int WORLDTRADE_SEARCH_StartDownloadMatchData(WorldtradeAdapterObj3 *p)
{
    Request_021FB800 q;
    if (p->fF84 == 0) {
        DPW_TR_DownloadMatchDataAsync((u8 *)p + 0xb56, 7, (u8 *)p + 0x20c);
    } else {
        MI_CpuFill8(&q, 0, 8);
        q.id = *(short *)&p->fB56;
        q.a = *(s8 *)&p->fB58;
        q.b = *(s8 *)((u8 *)p + 0xb59);
        q.c = *(s8 *)&p->fB5A;
        q.d = *(s8 *)((u8 *)p + 0xb5b);
        q.mode = 7;
        q.flag = p->fF84;
        DPW_TR_DownloadMatchDataRawAsync(&q, (unsigned int)((u8 *)p + 0x20c));
    }
    p->fB5C = p->fB56;
    p->fB5E = p->fB58;
    p->fB60 = p->fB5A;
    p->fB64 = *(u32 *)&p->fF84;
    p->fF8C = 0;
    p->f28 = 18;
    p->fE1A = 0;
    return 2;
}

/*
 * 23-slot switch on the 0x021C86A8 index (case value = index + 15, so the
 * bound is 22): the +0xd0 archive with state 0x13 for indexes 15..22, the
 * state-0x1e group with the four redraw calls for 1 and 13, the shared redraw
 * for 2 and the state-0x16 pair for 0 and 3; 4..12 and 14 are table holes.
 * The counter in the else arm compares against 0x1c20, not 0xe10.
 * Concrete bytes are identical to the image; the only wildcards are the two
 * BLX sites to 0x021C866C and 0x021C86A8, which carry no func_ label in any
 * overlay listing (match.py's `label` class needs exactly one listing to
 * carry the label, so no region hint can witness them).  One-line fix:
 * trace 0x021C866C / 0x021C86A8 in layout/function_starts.txt and this
 * promotes automatically.
 *
 * UNBLOCKED: DPW_TR_IsAsyncEnd (0x021C866C) and DPW_TR_GetAsyncResult
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int WORLDTRADE_SEARCH_WaitDownloadResult(Work *p)
{
    s32 n;

    if (DPW_TR_IsAsyncEnd((u8 *)p) != 0) {
        n = DPW_TR_GetAsyncResult();
        p->timer = 0;
        switch (n + 15) {
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
            p->d0 = n;
            p->state = 0x13;
            break;
        case 1:
        case 13:
            GFL_USE_StopAllSe();
            p->state = 0x1e;
            func_0200FBB0();
            GFL_NET_STATE_SetWifiError();
            func_0200FBA0();
            GFL_NET_STATE_ClearErrorMode();
            break;
        case 2:
            GFL_USE_StopAllSe();
            WORLDTRADE_CancelSave(p);
            break;
        case 0:
        case 3:
            GFL_USE_StopAllSe();
            p->state = 0x16;
            break;
        }
    } else {
        if (++p->timer == 0x1c20) {
            GFL_USE_StopAllSe();
            WORLDTRADE_CancelSave(p);
        }
    }
    return 2;
}

int WORLDTRADE_SEARCH_StateUpdateHistorySlots(Work *p)
{
    if (p->f12E8 == 0) {
        GFL_USE_StopAllSe();
        WORLDTRADE_SUBLCD_UpdateSlotPalettes(p, (*(int *)&p->d0), 1);
        if ((*(int *)&p->d0) == 0)
            WORLDTRADE_SEARCH_DrawHistoryHeader(p->wDB0, p->bank, 0, (char *)p + 0xfa0);
        else
            WORLDTRADE_SEARCH_DrawHistoryHeader(p->wDB0, p->bank, 1, (char *)p + 0xfa0);
        p->state_i = 20;
    }
    return 2;
}

int WORLDTRADE_SEARCH_StateShowEmptyHistoryMessage(Work *p)
{
    if ((*(int *)&p->d0) == 0) {
        WORLDTRADE_SEARCH_PrintMessage((unsigned char *)p, 14, 1, 0, 0xf0f);
        WORLDTRADE_SetNextState(p, 23, 1);
        GFL_USE_PlaySeDefaultVolume(0x557);
    } else {
        WORLDTRADE_SEARCH_PrintMessage((unsigned char *)p, 36, 1, 0, 0xf0f);
        WORLDTRADE_SetNextState(p, 23, 21);
        p->cnt = 0;
    }
    return 2;
}

int WORLDTRADE_SEARCH_StateCountdownMessage(Work *p)
{
    if (++p->cnt > 45) {
        WORLDTRADE_SEARCH_PrintMessage((unsigned char *)p, 38, 1, 0, 0xf0f);
        WORLDTRADE_SetNextState(p, 23, 1);
        p->fE1A = 1;
    }
    return 2;
}

int WORLDTRADE_SEARCH_StateShowClearedMessage(Work *p)
{
    p->xB5C = 0;
    WORLDTRADE_SEARCH_PrintMessage((unsigned char *)p, 44, 1, 0, 0xf0f);
    WORLDTRADE_SetNextState(p, 23, 1);
    GFL_USE_PlaySeDefaultVolume(0x557);
    (*(int *)&p->d0) = 0;
    WORLDTRADE_SEARCH_DrawHistoryHeader(p->wDB0, p->bank, 0, (char *)p + 0xfa0);
    return 2;
}

int WORLDTRADE_SEARCH_StatePrintMessage171(Work *p) {WORLDTRADE_SEARCH_PrintMessage((u8 *)p,171,4,0,0xf0f);WORLDTRADE_SetNextState(p,24,31);(*(unsigned int *)&p->cnt)=0;GFL_USE_PlaySeDefaultVolume(0x557);return 2;}

int WORLDTRADE_SEARCH_StatePrintMessage172(Work *p) {WORLDTRADE_SEARCH_PrintMessage((u8 *)p,172,4,0,0xf0f);WORLDTRADE_SetNextState(p,24,3);WORLDTRADE_SetStateAndReturn(p,0,21);GFL_USE_PlaySeDefaultVolume(0x557);return 2;}

/*
 * Return the current cursor slot of the state block at +0xE00: the +0x28
 * word while the +0x24 flag is clear, else the +0x2C word plus four.
 * A slot of seven or more reports through func_02034714 (the raw-address
 * assert shape; 0x02203E2C is a plain constant, as in WORLDTRADE_ADAPTER_QueueMessagePrint).
 */
int WORLDTRADE_SEARCH_GetSelectedButton(Work *p)
{
    State *s = p->st;
    int r;

    if (s->f24 == 0) {
        r = s->f28;
    } else {
        r = s->f2C + 4;
    }
    if (r >= 7) {
        func_02034714((void *)0x02203E2C, 0, (void *)0x02203E2C);
    }
    return r;
}

/*
 * Move the menu cursor by the pressed d-pad key: up and down step the
 * +0x28 row (page 0, rows 0..3) or the +0x2C row (page 1, rows 0..2),
 * right and left switch the +0x24 page. A real move plays sound 0x548
 * and sets the cursor sprite's animation from the position table; the
 * cursor is then placed at the table position of the current slot.
 */
void WORLDTRADE_SEARCH_UpdateKeyCursor(Work *p)
{
    int a;
    int b;

    if (KEY_GetTrg() & 0x40) {
        if (p->st->f24 == 0) {
            if (p->st->f28 > 0) {
                p->st->f28--;
                GFL_USE_PlaySeDefaultVolume(0x548);
                CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton((Work *)p)].anim);
            }
        } else {
            if (p->st->f2C > 0) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                p->st->f2C--;
                CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton((Work *)p)].anim);
            }
        }
    } else if (KEY_GetTrg() & 0x80) {
        if (p->st->f24 == 0) {
            if (p->st->f28 < 3) {
                p->st->f28++;
                GFL_USE_PlaySeDefaultVolume(0x548);
                CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton((Work *)p)].anim);
            }
        } else {
            if (p->st->f2C < 2) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                p->st->f2C++;
                CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton((Work *)p)].anim);
            }
        }
    } else if (KEY_GetTrg() & 0x10) {
        if (p->st->f24 != 1) {
            p->st->f24 = 1;
            GFL_USE_PlaySeDefaultVolume(0x548);
            CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton((Work *)p)].anim);
        } else {
            p->st->f24 = 1;
        }
    } else if (KEY_GetTrg() & 0x20) {
        if (p->st->f24 != 0) {
            p->st->f24 = 0;
            GFL_USE_PlaySeDefaultVolume(0x548);
            CLACT_SetActorAnimSeq((struct Obj *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton((Work *)p)].anim);
        } else {
            p->st->f24 = 0;
        }
    }
    a = WORLDTRADE_SEARCH_GetSelectedButton((Work *)p);
    b = WORLDTRADE_SEARCH_GetSelectedButton((Work *)p);
    WORLDTRADE_SetActorPos(p->cursor, tbl_02203D46[a].x, tbl_02203D46[b].y);
}

/*
 * Select cursor entry i from the {page, slot}
/*
 * Select cursor entry i from the {page, slot} byte table: page 0 stores
 * the slot at +0x28 of the state block, any other page sets the +0x24
 * flag and stores it at +0x2C. Then redraw the cursor sprite at +0xBF4
 * from the 8-byte position table.
 */
void WORLDTRADE_SEARCH_SelectButton(Work *p, int i)
{
    int a;
    int b;

    if (tbl_02203D38.sel[i].page == 0) {
        p->st->f24 = 0;
        p->st->f28 = tbl_02203D38.sel[i].slot;
    } else {
        p->st->f24 = 1;
        p->st->f2C = tbl_02203D38.sel[i].slot;
    }
    a = WORLDTRADE_SEARCH_GetSelectedButton((Work *)p);
    b = WORLDTRADE_SEARCH_GetSelectedButton((Work *)p);
    WORLDTRADE_SetActorPos(p->cursor, tbl_02203D46[a].x, tbl_02203D46[b].y);
}

/*
 * When the countdown at +0xd3c is spent, run the fixed 3/6/1/0x48 opener, then state 0.
 */
int WORLDTRADE_SEARCH_StateStartWipeOutPage(Work *p)
{
    if (p->pageNum == 0) {
        WIPE_SYS_Start((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    p->state = 0;
    return 3;
}

/*
 * Every concrete byte is reproduced (52 bytes of code; the listing's extra two
 * are alignment padding).  The one wildcard is the BLX at +0006 to
 * func_021C8658, which has no independent witness outside 0x021FEB84..0x021FEBB6; the
 * resolver reports "(arm, from name) ... 8 overlays overlap this address
 * (ov016, ov021, ov093, ov111, ov114, ov128, ov172, ov208), none resolvable
 * without a region hint on the symbols: line".  Naming one of those eight
 * regions would be a guess, so the site stays parked.
 *
 * Shape: two hand-overs, then the fixed 6/1/0x48 opener, state 0, return 3.
 */
int WORLDTRADE_SEARCH_StateStartWipeOutDisconnect(Work *p)
{
    func_021C8658((u8 *)p);
    WORLDTRADE_DeleteTimeIcon(p);
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x48);
    p->state = 0;
    return 3;
}

/*
 * Build through WORLDTRADE_SEARCH_PrintMessage and publish the 0x10/0x5 pair.
 */
int WORLDTRADE_SEARCH_StatePrintNamePrompt(Work *p)
{
    WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 0x9, 1, 0, 0xf0f);
    WORLDTRADE_SetNextState((char *)p, 0x17, 0x5);
    return 2;
}

/*
 * Publish +0xde4, kick helper 9, latch state 6.
 */
int WORLDTRADE_SEARCH_StateOpenNameMenu(Work *p)
{
    WORLDTRADE_INPUT_MenuSetMode((u8 *)((*(unsigned int *)&p->menu)), 0);
    WORLDTRADE_SEARCH_SetBlendEffect(9);
    p->state = 6;
    return 2;
}

int WORLDTRADE_SEARCH_StateNameMenuInput(Work *p)
{
    int r = WORLDTRADE_INPUT_MenuUpdate(p->menu);
    u32 h;
    u32 v;

    switch (r) {
    case -2:
        WORLDTRADE_SEARCH_SetBlendEffect(0);
        p->state = 0;
        WORLDTRADE_ENTER_SetListRangeEntry(p->area, p->target->x6 + p->target->x4, p->target->xA, p->target->x8);
        break;
    case -1:
        break;
    default:
        WORLDTRADE_SEARCH_SetBlendEffect(0);
        p->sel_h = r;
        p->state = 0;
        BMP_Clear(BMP_WIN_GetBmp(p->winA), 0);
        WORLDTRADE_DEPOSIT_PrintName(p->winA, p->names, r, 0, 0, 0x3C40, p->fFA0);
        h = (u32)POKE_PERSONAL_Create((u16)r, 0, 0x48);
        v = POKE_PERSONAL_GetParam((const struct Personal *)h, 0x14);
        POKE_PERSONAL_Delete((void *)h);
        p->target->x20 = v;
        WORLDTRADE_ENTER_SetListRangeEntry(p->area, p->target->x6 + p->target->x4, p->target->xA, p->target->x8);
        if (WORLDTRADE_DEPOSIT_CheckGenderEvent((u8 *)(&p->sel_h), p->target->x20) != 0) {
            BMP_Clear(BMP_WIN_GetBmp(p->winB), 0);
            WORLDTRADE_DEPOSIT_PrintModeLabelAligned(p->winB, p->bank, p->mode_sb, 1, 0, 0, 0x3C40, p->fFA0);
        }
        break;
    }
    return 2;
}

/*
 * Build through WORLDTRADE_SEARCH_PrintMessage and publish the 0x10/0x8 pair.
 */
int WORLDTRADE_SEARCH_StatePrintGenderPrompt(Work *p)
{
    WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 0xa, 1, 0, 0xf0f);
    WORLDTRADE_SetNextState((char *)p, 0x17, 0x8);
    return 2;
}

/*
 * Publish the +0xde4 slot, kick helper 9 and latch state 9.
 */
int WORLDTRADE_SEARCH_StateOpenGenderMenu(Work *p)
{
    WORLDTRADE_INPUT_MenuSetMode((u8 *)((*(unsigned int *)&p->menu)), 1);
    WORLDTRADE_SEARCH_SetBlendEffect(9);
    p->state = 9;
    return 2;
}

int WORLDTRADE_SEARCH_StateGenderMenuInput(Work *p)
{
    unsigned r;
    void *w;
    r = WORLDTRADE_INPUT_MenuUpdate(p->menu);
    switch (r) {
    case -2:
        WORLDTRADE_SEARCH_SetBlendEffect(0);
        func_0201F7A8(p->d40, 0);
        w = p->d40;
        BMP_WIN_TransferChars(w);
        BMP_WIN_MakeScreen(w);
        func_020409B4(BMP_WIN_GetBgLayer(w));
        p->state_i = 0;
        break;
    case 0:
    case 1:
    case 2:
        WORLDTRADE_SEARCH_SetBlendEffect(0);
        p->mode_sb = r + 1;
        p->state_i = 0;
        BMP_Clear(BMP_WIN_GetBmp(p->winB), 0);
        WORLDTRADE_DEPOSIT_PrintModeLabelAligned(p->winB, p->bank, p->mode_sb, 1, 0, 0, 0x3c40, (char *)p + 0xfa0);
        break;
    }
    return 2;
}

/*
 * Build through WORLDTRADE_SEARCH_PrintMessage and publish the 0x10/0xb pair.
 */
int WORLDTRADE_SEARCH_StatePrintLevelPrompt(Work *p)
{
    WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 0xb, 1, 0, 0xf0f);
    WORLDTRADE_SetNextState((char *)p, 0x17, 0xb);
    return 2;
}

/*
 * Sentinel at +0xbc, publish +0xde4, kick helper 9, latch state 0xc.
 */
int WORLDTRADE_SEARCH_StateOpenLevelMenu(Work *p)
{
    p->fBC = 0xffff;
    WORLDTRADE_INPUT_MenuSetMode((u8 *)((*(unsigned int *)&p->menu)), 2);
    WORLDTRADE_SEARCH_SetBlendEffect(9);
    p->state = 0xc;
    return 2;
}

int WORLDTRADE_SEARCH_StateLevelMenuInput(Work *p)
{
    unsigned r = WORLDTRADE_INPUT_MenuUpdate(p->menu);
    switch (r) {
    case 11:
    case -2:
        WORLDTRADE_SEARCH_SetBlendEffect(0);
        p->state_i = 0;
        break;
    case -1: break;
    default:
        WORLDTRADE_SEARCH_SetBlendEffect(0);
        WORLDTRADE_DEPOSIT_GetLevelBracket((u8 *)((char *)p + 0xb56), r, 1);
        p->state_i = 0;
        BMP_Clear(BMP_WIN_GetBmp(p->wDA4), 0);
        WORLDTRADE_DEPOSIT_PrintLevelRange(p->wDA4, p->bank, r, 0, 0, 0x3c40, 1, (char *)p + 0xfa0);
        break;
    }
    return 2;
}

/*
 * Build through WORLDTRADE_SEARCH_PrintMessage and publish the 0x10/0xe pair.
 */
int WORLDTRADE_SEARCH_StatePrintConditionPrompt(Work *p)
{
    WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 0xbe, 1, 0, 0xf0f);
    WORLDTRADE_SetNextState((char *)p, 0x17, 0xe);
    return 2;
}

/*
 * Sentinel at +0xbc, publish +0xde4, kick helper 9, latch state 0xf.
 */
int WORLDTRADE_SEARCH_StateOpenConditionMenu(Work *p)
{
    p->fBC = 0xffff;
    WORLDTRADE_INPUT_MenuSetMode((u8 *)((*(unsigned int *)&p->menu)), 3);
    WORLDTRADE_SEARCH_SetBlendEffect(9);
    p->state = 0xf;
    return 2;
}

int WORLDTRADE_SEARCH_StateConditionMenuInput(Work *p)
{
    int r;
    void *w;
    r = WORLDTRADE_INPUT_MenuUpdate(p->menu);
    if (r == -1) {
    } else if (r == -2 || r == d_02202EAC + 1) {
        WORLDTRADE_SEARCH_SetBlendEffect(0);
        func_0201F7A8(p->d40, 0);
        w = p->d40;
        BMP_WIN_TransferChars(w);
        BMP_WIN_MakeScreen(w);
        func_020409B4(BMP_WIN_GetBgLayer(w));
        p->state_i = 0;
    } else {
        WORLDTRADE_SEARCH_SetBlendEffect(0);
        WORLDTRADE_ENTER_ClearFlags(p, r);
        p->state_i = 0;
        BMP_Clear(BMP_WIN_GetBmp(p->win2[1]), 0);
        WORLDTRADE_DEPOSIT_PrintMessageLine(p->win2[1], p->msg_p, p->bank, p->fF84, 0, 0, 0x3c40, (char *)p + 0xfa0);
    }
    return 2;
}

int WORLDTRADE_SEARCH_StateOpenClearConfirm(Work *p)
{
    WORLDTRADE_OpenTaskMenuYesNoDefault((u32)p, 0x14, 0x120, 0x3, 0x1);
    p->state = 0x1b;
    return 2;
}

int WORLDTRADE_SEARCH_StateClearConfirmInput(Work *p)
{
    unsigned r = WORLDTRADE_UpdateTaskMenuYesNo((char *)p);
    if (r == 1) {
        WORLDTRADE_CloseTaskMenu((char *)p);
        *(int *)&p->state = 2;
        WORLDTRADE_SetStateAndReturn(p, 1, 0);
        if ((*(int *)&p->d0) > 0) WORLDTRADE_SUBLCD_UpdateSlotAnims(p);
        (*(int *)&p->d0) = 0;
    } else if (r == 2) {
        WORLDTRADE_CloseTaskMenu((char *)p);
        *(int *)&p->state = 0;
    }
    return 2;
}

int WORLDTRADE_SEARCH_StateReturnToMain(Work *p)
{
    p->state_i = 1;
    return 2;
}

/*
 * Build through WORLDTRADE_SEARCH_PrintMessage and publish the 0x10/0x1 pair.
 */
int WORLDTRADE_SEARCH_StatePrintMessage9E(Work *p)
{
    WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 0x9e, 1, 0, 0xf0f);
    WORLDTRADE_SetNextState((char *)p, 0x17, 0x1);
    return 2;
}

int WORLDTRADE_SEARCH_StateWaitMessage(u8 *p)
{
    if (WORLDTRADE_ADAPTER_IsStreamDone((PrintStreamCtx *)(p + 0xfa0)) == 0) {
        ((struct Obj12216 *)p)->f28 = ((struct Obj12216 *)p)->f2C;
    }
    return 2;
}

/*
 * When the build query answers 0 and either probe is set, roll the state word over.
 */
int WORLDTRADE_SEARCH_StateWaitMessageOrKey(u8 *p)
{
    if (WORLDTRADE_ADAPTER_IsStreamDone((PrintStreamCtx *)(p + 0xfa0)) == 0) {
        if (KEY_GetTrg() != 0 || TOUCHPANEL_GetTrg() != 0) {
            ((struct Obj12217 *)p)->f28 = ((struct Obj12217 *)p)->f2C;
        }
    }
    return 2;
}

/*
 * When the build query answers 0, bump the countdown at +0xdfc and roll state when it passes 0x2d.
 */
int WORLDTRADE_SEARCH_StateWaitMessageTimed(u8 *p)
{
    if (WORLDTRADE_ADAPTER_IsStreamDone((PrintStreamCtx *)(p + 0xfa0)) == 0) {
        if (++((struct Obj07250 *)p)->fDFC > 0x2d) {
            ((struct Obj07250 *)p)->fDFC = 0;
            ((struct Obj07250 *)p)->f28 = ((struct Obj07250 *)p)->f2C;
        }
    }
    return 2;
}

/*
 * volatile: 021FF12E reads hardware register 04000304.
 */
int WORLDTRADE_SEARCH_StateScrollOut(Work *p)
{
    ++p->scroll;
    if (WIPE_SYS_EndCheck()) {
        *(volatile u16 *)0x04000304 |= 0x8000;
        p->scroll = -16;
        if (p->fE1A) {
            p->state_i = 2;
            WORLDTRADE_SetStateAndReturn(p, 3, 16);
            p->cur = 0;
        }
        CLACT_SetActorDrawEnable((struct Obj *)p->fD38, 0);
    }
    return 2;
}

/*
 * Decrement the countdown at +0xd3c and, when the tick returns non-zero, zero it and latch state 1.
 */
int WORLDTRADE_SEARCH_StateWaitWipeIn(Work *p)
{
    u32 v = p->pageNum - 1;

    p->pageNum = v;
    if (WIPE_SYS_EndCheck() != 0) {
        p->pageNum = 0;
        p->state = 1;
    }
    return 2;
}

int WORLDTRADE_SEARCH_StateHistoryInput(Work *p)
{
    int r;
    if (KEY_GetTrg() & 1) {
        WIPE_SYS_Start(0, 0, 0, 0, 16, 1, 72);
    } else {
        r = WORLDTRADE_SUBLCD_CheckButtonTouch((*(int *)&p->d0));
        if (p->fE1A && r >= 0) {
            CLACT_SetActorAnimSeq((struct Obj *)(*(unsigned *)((char *)p + 0xd0c + (r + 1) * 4)), (u16)(16 + r * 4));
            p->state_i = 2;
            WORLDTRADE_SetStateAndReturn(p, 3, 0);
            p->cur = r;
            GFL_USE_PlaySeDefaultVolume(0x54c);
        }
    }
    return 2;
}

int WORLDTRADE_SEARCH_StateCursorAnimA(Work *p)
{
    if (CLACT_IsActorAnimActive((struct Actor *)(p->cursor)) == 0) {
        CLACT_SetActorAnimSeq((struct Obj *)(p->cursor), d_02203D4A[WORLDTRADE_SEARCH_GetSelectedButton((Work *)p)][0]);
        if (func_020355C4() == 1)
            CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 0);
        else
            CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        WORLDTRADE_SEARCH_HandleButton(p, WORLDTRADE_SEARCH_GetSelectedButton((Work *)p));
    }
    return 2;
}

int WORLDTRADE_SEARCH_StateCursorAnimB(Work *p)
{
    if (CLACT_IsActorAnimActive((struct Actor *)(p->cursor)) == 0) {
        CLACT_SetActorAnimSeq((struct Obj *)(p->cursor), d_02203D4A[WORLDTRADE_SEARCH_GetSelectedButton((Work *)p)][0]);
        if (func_020355C4() == 1)
            CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 0);
        else
            CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 15, 1, 0, 0xf0f);
        WORLDTRADE_SetNextState((char *)((u8 *)p), 23, 26);
    }
    return 2;
}

int WORLDTRADE_SEARCH_StateCursorAnimC(Work *p)
{
    if (CLACT_IsActorAnimActive((struct Actor *)(p->cursor)) == 0) {
        CLACT_SetActorAnimSeq((struct Obj *)(p->cursor), d_02203D4A[WORLDTRADE_SEARCH_GetSelectedButton((Work *)((char *)p))][0]);
        if (func_020355C4() == 1) {
            CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 0);
        } else {
            CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        }
        p->state = 1;
    }
    return 2;
}

/*
 * Tear the object down: unhook the two sub-objects, release the +0xd40 resource, wire the 0/1/e quad, then drain the four engine hooks.
 */
void WORLDTRADE_SEARCH_PrintMessage(u8 *p, u32 k, int b, int c, int d)
{
    u32 v;

    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00018 *)p)->fB6C), k, (void *)(*(u32 *)(p + 0xb6c + 0x1c)));
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00018 *)p)->fD40)), 0xf);
    func_0201F73C((void *)(((struct Obj00018 *)p)->fD40), 0, 1, 0xe);
    WORLDTRADE_ADAPTER_QueuePrintDefaultColor((void *)(((struct Obj00018 *)p)->fD40), 0, (void *)(*(u32 *)(p + 0xb6c + 0x1c)), 0, 0, p + 0xfa0);
    v = ((struct Obj00018 *)p)->fD40;
    BMP_WIN_TransferChars((struct Descriptor *)v);
    BMP_WIN_MakeScreen((struct Cfg *)v);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)v));
}

/*
 * note: pass 2 2026-10-06 P2L19: closed from 8 B off (238 B). The print callees WORLDTRADE_INPUT_PrintStringAlignedLine and
 *   WORLDTRADE_INPUT_PrintStringAlignedWrapped are declared void here. Their bodies end in a call and never set r0 themselves, so the
 *   image does not decide between int and void, and no caller reads the result. With int, the six stack
 *   zeros and the six 0x440 stores tie and the zero takes r7; with void the colour 0x440 takes r7 and
 *   the zero is rematerialised per call, as in the image. Plain literals, no pragma.
 */
void WORLDTRADE_SEARCH_DrawFormLabels(void **win, void **win2, void *bank, void *g)
{
    void *s1, *s2, *s3, *s4, *s5, *s6;

    s1 = func_02045EC0(bank, 0x43);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[0], s1, 0, 0, 0, 0x440, g);
    STRBUF_Delete(s1);

    s2 = func_02045EC0(bank, 0x45);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[2], s2, 0, 0, 0, 0x440, g);
    STRBUF_Delete(s2);

    s3 = func_02045EC0(bank, 0x47);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[4], s3, 0, 0, 0, 0x440, g);
    STRBUF_Delete(s3);

    s4 = func_02045EC0(bank, 0xB9);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win2[0], s4, 0, 0, 0, 0x440, g);
    STRBUF_Delete(s4);

    s5 = func_02045EC0(bank, 0x49);
    WORLDTRADE_INPUT_PrintStringAlignedWrapped(win[6], s5, 0, 0, 0, 0x440, g);
    STRBUF_Delete(s5);

    s6 = func_02045EC0(bank, 0xFC);
    WORLDTRADE_INPUT_PrintStringAlignedWrapped(win[7], s6, 0, 0, 0, 0x440, g);
    STRBUF_Delete(s6);
}

void WORLDTRADE_SEARCH_DrawHistoryHeader(void *win, void *bank, int flag, void *g)
{
    void *str;
    u16 color;
    u8 pal;

    color = 0x3C40;
    if (flag != 0) {
        color = 0x440;
        pal = 0;
    } else {
        pal = 2;
    }
    func_020413B0(1, 0x11, 2, 0xF, 4, pal);
    func_020409B4(1);
    str = func_02045EC0(bank, 0x4B);
    WORLDTRADE_INPUT_PrintStringAlignedWrapped(win, (void *)str, 0, 0, 0, color, (void *)g);
    STRBUF_Delete(str);
}

/*
 * True when two {s16, s8, s8, s8}
/*
 * True when two {s16, s8, s8, s8} records are equal field by field and
 * the two trailing arguments are equal.
 */
int WORLDTRADE_SEARCH_CompareRecords(Rec *x, Rec *y, int m, int n)
{
    if (x->name == y->name && x->mode == y->mode && x->key == y->key && x->val == y->val && m == n) {
        return 1;
    }
    return 0;
}

void WORLDTRADE_SEARCH_ScrollBgs(Work *p)
{
    func_02040618(0, 3, p->scroll);
    func_02040618(1, 3, p->scroll);
    func_02040618(2, 3, p->scroll);
    func_02040618(3, 3, p->scroll);
    func_02040618(4, 3, -p->scroll);
    func_02040618(5, 3, -p->scroll);
    func_02040618(6, 3, -p->scroll);
    func_02040618(7, 3, -p->scroll);
}

/*
 * Program the 0x04000050 display register from the flag, or clear it.
 */
void WORLDTRADE_SEARCH_SetBlendEffect(u32 v)
{
    if (v != 0) {
        func_0207D658(0x04000050, 0xa, v);
    } else {
        *(u16 *)0x04000050 = 0;
    }
}
