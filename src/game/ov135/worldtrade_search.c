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
 *   GFL_HEAP_Free 0x020307B0 arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   GF_PANIC_Fail 0x02034714 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   WORLDTRADE_TITLE_ScrollBg 0x021FFFE8 thumb ov135
 *   GXx_GetMasterBrightness_ 0x0207D55C arm
 *   WORLDTRADE_TITLE_ExitBgPlanes 0x022000E4 thumb ov135
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BG_SYS_GetSubVisiblePlanes  0x02043668  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   BG_SYS_InitRun  0x02040B94  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   WORLDTRADE_TITLE_LoadSubBgSwap 0x02200B34 thumb ov135
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   UI_GetInputMode  0x020355C4  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   WORLDTRADE_INPUT_PrintStringAlignedLine  0x021F91A0  thumb
 *   WORLDTRADE_TITLE_CreateMenuWindow  0x02200BAC  thumb
 *   WORLDTRADE_ADAPTER_DeletePrintStream 0x02202940 thumb ov135
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STRBUF_Create 0x020457B0 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   WORLDTRADE_ADAPTER_IsStreamBusy  0x02202840  thumb  ov135
 *   BMP_WIN_GetBmp   0x02045770  arm
 *   BMP_Clear   0x02043B5C  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   WORLDTRADE_ADAPTER_QueuePrintDefaultColor  0x02202858  thumb  ov135
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WORLDTRADE_INPUT_MenuCreate 0x021F9890 thumb ov135
 *   WORLDTRADE_INPUT_MenuDelete 0x021F99D0 thumb ov135
 *   BMP_WIN_Create 0x020450F0 arm
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   WORLDTRADE_DEPOSIT_ClearListRange 0x021F8990 thumb ov135
 *   WORLDTRADE_INPUT_MenuSetMode  0x021F9968  thumb  ov135
 *   WORLDTRADE_INPUT_MenuUpdate 0x021F99F0 thumb ov135
 *   WORLDTRADE_DEPOSIT_SetListRangeEntry 0x021F89A8 thumb ov135
 *   POKE_PERSONAL_Create 0x0201ADE4 thumb
 *   POKE_PERSONAL_GetParam 0x0201AE1C thumb
 *   POKE_PERSONAL_Delete 0x0201AE14 thumb
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   TOUCHPANEL_HitTrg  0x02035C08  arm  arm9
 *   TOUCHPANEL_GetTrg  0x02035C60  arm  arm9
 *   CLACT_IsActorAnimActive  0x0204B98C  arm  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   WORLDTRADE_AdvanceScreenId  0x021F4EC8  thumb  ov135
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb
 *   WORLDTRADE_CancelSave  0x021F513C  thumb  ov135
 *   WORLDTRADE_DeleteTimeIcon  0x021F4FC4  thumb  ov135
 *   DPW_TR_IsAsyncEnd  0x021C866C  arm
 *   DPW_TR_GetAsyncResult  0x021C86A8  arm
 *   DPW_TR_End 0x021C8658 arm ov114
 *   BG_SYS_Init  0x02040C14  arm
 *   BG_SYS_FreeTiles  0x02040DA8  arm
 *   WORLDTRADE_SetActorPos  0x021F4FF4  thumb
 *   UI_SetInputMode  0x020355D8  arm
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm  arm9
 *   WORLDTRADE_ADAPTER_QueueMessagePrint  0x02202B20  thumb
 *   WORLDTRADE_DEPOSIT_FindLevelBracketIndex 0x021F886C thumb ov135
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   WORLDTRADE_UpdateTaskMenuYesNo 0x021F4D14 thumb ov135
 *   WORLDTRADE_CloseTaskMenu 0x021F4CE4 thumb ov135
 *   WORLDTRADE_SetActorSurfacePos 0x021F4EA0 thumb ov135
 *   WORLDTRADE_INPUT_PrintStringAlignedWrapped  0x021F91DC  thumb
 *   BG_SYS_ChangeScrollImmediate  0x02040618  arm
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
 *   WORLDTRADE_DEPOSIT_CreateSpeciesFlagTable  0x021F84EC  thumb
 *   g_02203E18     0x02203E18  data  ov135
 *   g_022037D4  0x022037D4  data  ov135
 *   WORLDTRADE_DEPOSIT_SetGenderFromEvent 0x021F7B9C thumb ov135
 *   tbl_02203D46   0x02203D46  data  a2
 *   DPW_TR_DownloadMatchDataAsync 0x021C8B18 arm ov114
 *   DPW_TR_DownloadMatchDataRawAsync 0x021C8BC4 arm ov114
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   GFL_NET_ERR_WaitLinkClosed  0x0200FBB0  thumb
 *   GFL_NET_ERR_ResetState  0x0200FBA0  thumb
 *   GFL_NET_STATE_SetWifiError  0x0203CA04  arm
 *   GFL_NET_STATE_ClearErrorMode  0x0203C968  arm
 *   WORLDTRADE_DEPOSIT_GetLevelBracket 0x021F882C thumb ov135
 *   WORLDTRADE_DEPOSIT_SetCountryFilter 0x021F88B0 thumb ov135
 *   d_02202EAC 0x02202EAC data a4
 *   WORLDTRADE_OpenTaskMenuYesNoDefault  0x021F4BE0  thumb  ov135
 *   d_02203D4A 0x02203D4A data a2
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   WORLDTRADE_SUBLCD_CheckButtonTouch 0x021FFB00 thumb ov135
 *   WORLDTRADE_SUBLCD_UpdateSlotAnims 0x021FFBC8 thumb ov135
 *   G2x_SetBlendBrightness_  0x0207D658  arm  arm9
 */
#include "worldtrade_types.h"
#include "../sdk_ioreg.h"

#include "../arm9/mi_memory.h"

#include "../arm9/gfl_heap_wrap.h"


#include "../arm9/gf_panic.h"

#include "../arm9/arc_tool.h"

#include "../arm9/msgdata.h"

#include "../arm9/strbuf.h"

#include "../arm9/bmp_win.h"


#include "../arm9/g2.h"

#include "../arm9/bg_sys.h"






#include "../arm9/arc_util.h"


#include "../arm9/bmp_menuwork.h"



#include "../arm9/clact.h"


#include "../arm9/ui.h"




typedef short s16_p07;
#include "../arm9/bmp.h"





#include "../arm9/key.h"


#include "../arm9/touchpanel.h"




#include "worldtrade_input.h"


#include "worldtrade_deposit.h"


#include "../arm9/poke_personal.h"




#include "worldtrade.h"

#include "../ov114/dpw_tr.h"



#include "../arm9/net.h"




typedef struct { u16 x, y, a, b; } SelCell;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 bgPriority;
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
    u16 anim;
    u16 anim2;
} CurPos_vE338;

typedef struct { short id; s8 a, b, c, d; u8 mode, flag; } DownloadRequest;



#include "../arm9/wipe.h"








#include "../arm9/gfl_use.h"









#include "../arm9/gx.h"




















#include "../arm9/net_err.h"


#include "../arm9/net_state.h"








int WORLDTRADE_SEARCH_Init(WorldtradeWork *p);

int WORLDTRADE_SEARCH_Main(WorldtradeWork *p);

int WORLDTRADE_SEARCH_Exit(WorldtradeWork *p);

void WORLDTRADE_SEARCH_SetupBgPlanes(void);

void WORLDTRADE_SEARCH_ExitBgPlanes(void);

void WORLDTRADE_SEARCH_LoadBgGraphics(WorldtradeWork *p);

void WORLDTRADE_SEARCH_CreateActors(WorldtradeWork *p);

void WORLDTRADE_SEARCH_DeleteActors(WorldtradeWork *p);

void WORLDTRADE_SEARCH_CreateWindows(WorldtradeWork *p);

void WORLDTRADE_SEARCH_DeleteWindows(unsigned char *p);

void WORLDTRADE_SEARCH_CreateStrings(WorldtradeWork *p);

void WORLDTRADE_SEARCH_DeleteStrings(WorldtradeWork *p);

int WORLDTRADE_SEARCH_UpdateCursorVisibility(WorldtradeWork *p);

int WORLDTRADE_SEARCH_HitTestButtons(void);

void WORLDTRADE_SEARCH_HandleButton(WorldtradeWork *p, int mode);

int WORLDTRADE_SEARCH_StateMainInput(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateConfirmSearch(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StartDownloadMatchData(WorldtradeWork *p);

int WORLDTRADE_SEARCH_WaitDownloadResult(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateUpdateHistorySlots(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateShowEmptyHistoryMessage(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateCountdownMessage(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateShowClearedMessage(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StatePrintMessage171(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StatePrintMessage172(WorldtradeWork *p);

int WORLDTRADE_SEARCH_GetSelectedButton(WorldtradeWork *p);

void WORLDTRADE_SEARCH_UpdateKeyCursor(WorldtradeWork *p);

void WORLDTRADE_SEARCH_SelectButton(WorldtradeWork *p, int i);

int WORLDTRADE_SEARCH_StateStartWipeOutPage(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateStartWipeOutDisconnect(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StatePrintNamePrompt(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateOpenNameMenu(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateNameMenuInput(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StatePrintGenderPrompt(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateOpenGenderMenu(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateGenderMenuInput(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StatePrintLevelPrompt(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateOpenLevelMenu(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateLevelMenuInput(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StatePrintConditionPrompt(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateOpenConditionMenu(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateConditionMenuInput(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateOpenClearConfirm(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateClearConfirmInput(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateReturnToMain(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StatePrintMessage9E(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateWaitMessage(u8 *p);

int WORLDTRADE_SEARCH_StateWaitMessageOrKey(u8 *p);

int WORLDTRADE_SEARCH_StateWaitMessageTimed(u8 *p);

int WORLDTRADE_SEARCH_StateScrollOut(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateWaitWipeIn(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateHistoryInput(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateCursorAnimA(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateCursorAnimB(WorldtradeWork *p);

int WORLDTRADE_SEARCH_StateCursorAnimC(WorldtradeWork *p);

void WORLDTRADE_SEARCH_PrintMessage(u8 *p, u32 k, int b, int c, int d);

void WORLDTRADE_SEARCH_DrawFormLabels(void **win, void **win2, void *bank, void *g);

void WORLDTRADE_SEARCH_DrawHistoryHeader(void *win, void *bank, int flag, void *g);

int WORLDTRADE_SEARCH_CompareRecords(WorldtradeRec *x, WorldtradeRec *y, int m, int n);

void WORLDTRADE_SEARCH_ScrollBgs(WorldtradeWork *p);

void WORLDTRADE_SEARCH_SetBlendEffect(u32 v);

#include "worldtrade_sublcd.h"



#include "worldtrade_title.h"




#include "worldtrade_adapter.h"



extern const SelCell d_02203D46[];

extern struct DispConfig g_022037F4;

extern struct BgTemplate g_02203844;

extern struct BgTemplate g_02203864;

extern struct BgTemplate g_02203804;

extern struct BgTemplate g_02203824;

extern const SelTbl tbl_02203D38;

extern const WorldtradePos tbl_022037A8[];

extern const WorldtradePos tbl_022037B0[];

extern const WorldtradePos tbl_022037BC[];

extern u8 g_02203E18[];

extern char g_022037D4[];

extern const CurPos_vE338 tbl_02203D46[];

extern const int d_02202EAC;

extern const u16 d_02203D4A[][4];

int WORLDTRADE_SEARCH_Init(WorldtradeWork *p)
{
    WorldtradeInputInit init;

    WORLDTRADE_SEARCH_CreateStrings(p);
    WORLDTRADE_SEARCH_SetupBgPlanes();
    WORLDTRADE_SEARCH_LoadBgGraphics(p);
    WORLDTRADE_SEARCH_CreateWindows((WorldtradeWork *)p);
    WORLDTRADE_SEARCH_CreateActors((WorldtradeWork *)p);
    WORLDTRADE_TITLE_ScrollBg(p, 0, 0);
    WORLDTRADE_TITLE_LoadSubBgSwap(p);
    WORLDTRADE_TITLE_CreateMenuWindow(p, 4);
    p->keepBgLayers = 0;
    init.w00 = (uptr)p->menuWins;
    init.w04 = (uptr)p->menuInitArg;
    init.obj = (uptr)p->mark;
    init.w0c = (uptr)p->btn[0];
    init.w10 = (uptr)p->btn[1];
    init.w14 = (uptr)p->cursor_p;
    init.w18 = (uptr)p->bank;
    init.w1c = (uptr)p->names;
    init.w20 = (uptr)p->msg_p;
    init.w24 = p->ctx->zukanSave_u;
    init.w28 = p->aux->speciesFlags;
    p->menu = WORLDTRADE_INPUT_MenuCreate(&init, 2, 1);
    WORLDTRADE_SEARCH_DrawFormLabels(p->win_p4, p->win2, p->bank, p->printerBlock);
    WORLDTRADE_SEARCH_DrawHistoryHeader(p->wDB0, p->bank, p->historyFlag, p->printerBlock);
    WORLDTRADE_DEPOSIT_PrintName(p->win_p4[1], p->names, p->rec.name, 0, 0, 0x3C40, p->printerBlock);
    WORLDTRADE_DEPOSIT_PrintModeLabelAligned(p->win_p4[3], p->bank, p->rec.mode, 1, 0, 0, 0x3C40, p->printerBlock);
    WORLDTRADE_DEPOSIT_PrintLevelRange(p->wDA4, p->bank, WORLDTRADE_DEPOSIT_FindLevelBracketIndex(p->rec.key, p->rec.val, 1), 0, 0, 0x3C40, 1, p->printerBlock);
    WORLDTRADE_DEPOSIT_PrintMessageLine(p->win2[1], p->msg_p, p->bank, p->countryFilter, 0, 0, 0x3C40, p->printerBlock);
    p->vblank = WORLDTRADE_SEARCH_ScrollBgs;
    if (p->kind == 0xd) {
        WIPE_SYS_Start((void *)3, 1, 1, 0, 6, 1, 0x48);
    }
    p->state = 0;
    return 1;
}

extern int (*const d_02203D80[])(void *);

int WORLDTRADE_SEARCH_Main(WorldtradeWork *p)
{
    int result;
    int i;
    int x, y;
    result = d_02203D80[p->state_i]((unsigned char *)p);
    for (i = 0; i < 8; ++i)
        WORLDTRADE_SetActorSurfacePos(*(void **)((unsigned char *)p + i * 4 + 0xd0c), *(short *)((unsigned char *)p + i * 4 + 0xec4), *(short *)((unsigned char *)p + i * 4 + 0xec6) + p->scroll);
    x = WORLDTRADE_SEARCH_GetSelectedButton((WorldtradeWork *)p);
    y = WORLDTRADE_SEARCH_GetSelectedButton((WorldtradeWork *)p);
    WORLDTRADE_SetActorPos(p->cursor, d_02203D46[x].x, d_02203D46[y].y - p->scroll);
    WORLDTRADE_SetActorSurfacePos((void *)p->scrollBarObj, 55, p->scroll + 168);
    return result;
}

int WORLDTRADE_SEARCH_Exit(WorldtradeWork *p)
{
    (*(int *)&p->every) = 0;
    WORLDTRADE_INPUT_MenuDelete(p->menu);
    WORLDTRADE_SEARCH_DeleteActors(p);
    WORLDTRADE_SEARCH_DeleteStrings(p);
    WORLDTRADE_SEARCH_DeleteWindows((unsigned char *)p);
    WORLDTRADE_SEARCH_ExitBgPlanes();
    if (*(int *)&p->nextScreenId == 1)
        *(int *)&p->keepBgLayers = 1;
    WORLDTRADE_TITLE_ExitBgPlanes(p);
    CLACT_SetActorDrawEnable((struct ClactActor *)((struct WorldtradeObj *)((struct WorldtradeObj *)*(u32 *)(void * *)&p->scrollBarObj)), 0);
    WORLDTRADE_AdvanceScreenId(p);
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

    BG_SYS_SetGraphicsMode(&c);
    BG_SYS_SetSubVisiblePlanes(v);
    {
        struct BgTemplate t = g_02203844;
        BG_SYS_InitBgLayer(0, &t, 0);
    }
    BG_SYS_ClearSlot(0);
    BG_SYS_SetPlaneVisible(0, 1);
    {
        struct BgTemplate t = g_02203864;
        BG_SYS_InitBgLayer(1, &t, 0);
    }
    BG_SYS_ClearSlot(1);
    BG_SYS_SetPlaneVisible(1, 1);
    {
        struct BgTemplate t = g_02203804;
        BG_SYS_InitBgLayer(2, &t, 0);
    }
    BG_SYS_ClearSlot(2);
    BG_SYS_SetPlaneVisible(2, 1);
    {
        struct BgTemplate t = g_02203824;
        BG_SYS_InitBgLayer(3, &t, 0);
    }
    BG_SYS_ClearSlot(3);
    BG_SYS_SetPlaneVisible(3, 1);
    BG_SYS_InitRun(2, 0x20, 0, 0x48);
    BG_SYS_InitRun(0, 0x20, 0, 0x48);
    BG_SYS_InitRun(3, 0x20, 0, 0x48);
}

/*
 * Poke the channel-selection helper with 2, 1, 0, 3 in turn.
 */
void WORLDTRADE_SEARCH_ExitBgPlanes(void)
{
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_FreeLayerBuf(3);
}

/*
 * The parameterless member: handle open, the B68 and B40 window calls, two
 * F5BC text calls, three 49658/498F4 draws and the second B40 pair, then
 * the 49238 release.  Contents 166 of 168 bytes (pool pad).
 */
void WORLDTRADE_SEARCH_LoadBgGraphics(WorldtradeWork *p)
{
    void *h = ARC_TOOL_CreateHandle(0x60, 0x48);

    ARC_UTIL_UploadPaletteFromHandleWhole(h, 2, 0, 0, 0x60, 0x48);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    BMP_MENUWORK_LoadCharAndPltt(0, 1, 0xe, 0, 0x48);
    BMP_MENUWORK_LoadCharAndPltt(0, 0x1f, 0xb, 0, 0x48);
    ARC_UTIL_UploadBgCharFromHandle(h, 0xb, 1, 0, 0, 1, 0x48);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 0x17, 1, 0, 0, 1, 0x48);
    ARC_UTIL_UploadBgCharFromHandle(h, 0xc, 2, 0, 0, 1, 0x48);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x20, 0x20, 0x48);
    ARC_TOOL_DeleteHandle(h);
}

void WORLDTRADE_SEARCH_CreateActors(WorldtradeWork *p)
{
    ObjPos_vD924 pos;

    MI_CpuFill8(&pos, 0, sizeof(pos));
    pos.x = tbl_02203D38.cur[0].x;
    pos.y = tbl_02203D38.cur[0].y;
    p->cursor_p = CLACT_CreateActor((struct Unit *)p->res, (uptr)p->set2, (uptr)p->set[1], (uptr)p->set3, (const struct ActorInitParam *)&pos, 0, 0x48);
    CLACT_SetActorAutoAnim(p->cursor_p, 1);
    CLACT_SetActorAnimSeq(p->cursor_p, tbl_02203D38.cur[0].anim);
    CLACT_SetActorBgPriority(p->cursor_p, 1);
    if (UI_GetInputMode() == 1) {
        CLACT_SetActorDrawEnable(p->cursor_p, 0);
    } else {
        CLACT_SetActorDrawEnable(p->cursor_p, 1);
    }
    pos.x = 0xA0;
    pos.y = 0x20;
    p->mark = CLACT_CreateActor((struct Unit *)p->res, (uptr)p->set2, (uptr)p->set[1], (uptr)p->set3, (const struct ActorInitParam *)&pos, 0, 0x48);
    CLACT_SetActorAnimSeq(p->mark, 4);
    CLACT_SetActorDrawEnable(p->mark, 0);
    pos.x = 0xE4;
    pos.y = 0x75;
    p->btn[0] = CLACT_CreateActor((struct Unit *)p->res, (uptr)p->set[0], (uptr)p->set[1], (uptr)p->set[2], (const struct ActorInitParam *)&pos, 0, 0x48);
    CLACT_SetActorAnimSeq(p->btn[0], 0x26);
    CLACT_SetActorDrawEnable((struct ClactActor *)p->btn[0], 0);
    pos.x = 0x8C;
    p->btn[1] = CLACT_CreateActor((struct Unit *)p->res, (uptr)p->set[0], (uptr)p->set[1], (uptr)p->set[2], (const struct ActorInitParam *)&pos, 0, 0x48);
    CLACT_SetActorAnimSeq(p->btn[1], 0x27);
    CLACT_SetActorDrawEnable(p->btn[1], 0);
    GFL_NET_RefreshWmIconAtTopRight(0, 0x48);
}

void WORLDTRADE_SEARCH_DeleteActors(WorldtradeWork *p) {CLACT_DeleteActor((struct ClactActor *)((struct WorldtradeObj *)(*(struct WorldtradeObj * *)&p->cursor_p)));CLACT_DeleteActor((struct ClactActor *)((struct WorldtradeObj *)(*(struct WorldtradeObj * *)&p->mark)));CLACT_DeleteActor((struct ClactActor *)((struct WorldtradeObj *)(*(struct WorldtradeObj * *)&p->btn[0])));CLACT_DeleteActor((struct ClactActor *)((struct WorldtradeObj *)(*(struct WorldtradeObj * *)&p->btn[1])));}

void WORLDTRADE_SEARCH_CreateWindows(WorldtradeWork *p)
{
    int i;
    struct BmpWin *v;

    p->frame = BMP_WIN_Create(0, (u8)2, (u8)0x15, (u8)0x1b, 2, 0xd, (u16)1);
    BMP_Clear((struct Bmp *)((struct CharBuf *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->frame))), 0);
    v = p->frame;
    BMP_WIN_TransferChars((struct BmpWin *)v);
    BMP_WIN_MakeScreen((struct BmpWin *)v);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)v));
    BG_SYS_Init(3, 0, 1, 0);
    for (i = 0; i < 6; i++) {
        p->item_u6[i] = BMP_WIN_Create(3, (u8)tbl_022037BC[i].x, (u8)tbl_022037BC[i].y, (u8)0xb, 2, 0xd, (u16)0);
        BMP_Clear((struct Bmp *)((struct CharBuf *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->item_u6[i]))), 0);
        v = p->item_u6[i];
        BMP_WIN_TransferChars((struct BmpWin *)v);
        BMP_WIN_MakeScreen((struct BmpWin *)v);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)v));
    }
    for (i = 0; i < 2; i++) {
        p->tab[i] = BMP_WIN_Create(3, (u8)tbl_022037A8[i].x, (u8)tbl_022037A8[i].y, (u8)0x1c, 2, 0xd, (u16)0);
        BMP_Clear((struct Bmp *)((struct CharBuf *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->tab[i]))), 0);
        v = p->tab[i];
        BMP_WIN_TransferChars((struct BmpWin *)v);
        BMP_WIN_MakeScreen((struct BmpWin *)v);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)v));
    }
    for (i = 0; i < 3; i++) {
        p->page[i] = BMP_WIN_Create(3, (u8)tbl_022037B0[i].x, (u8)tbl_022037B0[i].y, (u8)0xa, 2, 0xd, (u16)0);
        BMP_Clear((struct Bmp *)((struct CharBuf *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)p->page[i]))), 0);
        v = p->page[i];
        BMP_WIN_TransferChars((struct BmpWin *)v);
        BMP_WIN_MakeScreen((struct BmpWin *)v);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)v));
    }
}

void WORLDTRADE_SEARCH_DeleteWindows(unsigned char *p)
{
    int i;
    WORLDTRADE_ADAPTER_DeletePrintStream((struct WorldtradeObj *)((struct WorldtradeObj *)(p + 0xfa0)));
    BMP_WIN_Delete(((WorldtradeWork *)p)->msgWin);
    BMP_WIN_Delete(((WorldtradeWork *)p)->d40);
    for (i = 0; i < 9; ++i)
        BMP_WIN_Delete(*(void **)(p + i * 4 + 0xd90));
    for (i = 0; i < 2; ++i)
        BMP_WIN_Delete(*(void **)(p + i * 4 + 0xdd8));
    BG_SYS_FreeTiles(3, 1, 0);
}

void WORLDTRADE_SEARCH_CreateStrings(WorldtradeWork *p)
{
    p->str = STRBUF_Create(0xb4, 0x48);
    p->titleStr = MSGDATA_AllocString(p->bank, 0x30);
    (*(void **)&p->st) = GFL_HEAP_Alloc(0x48, 0x30, 0, (const char *)g_02203E18, 0x351);
    MIi_CpuClearFast(0, (void *)p->st, 0x30);
    *(u8 * *)&((DepositState *)(*(u8 * *)(void **)&p->st))->speciesFlags = WORLDTRADE_DEPOSIT_CreateSpeciesFlagTable(0x48);
    WORLDTRADE_DEPOSIT_ClearListRange((SelTable *)((u8 *)p + 0xeec));
}

void WORLDTRADE_SEARCH_DeleteStrings(WorldtradeWork *p) {GFL_HEAP_Free((void *)(((DepositState *)(*(char * *)(void **)&p->st))->speciesFlags));GFL_HEAP_Free((void *)p->st);STRBUF_Delete((struct Strbuf *)(*(struct U16Vec * *)&p->str));STRBUF_Delete((struct Strbuf *)(*(struct U16Vec * *)&p->titleStr));}

int WORLDTRADE_SEARCH_UpdateCursorVisibility(WorldtradeWork *p)
{
    if (UI_GetInputMode() == 1)
        CLACT_SetActorDrawEnable((struct ClactActor *)((struct WorldtradeObj *)((struct WorldtradeObj *)p->cursor)), 0);
    else
        CLACT_SetActorDrawEnable((struct ClactActor *)((struct WorldtradeObj *)((struct WorldtradeObj *)p->cursor)), 1);
    if (p->kind == 15) {
        if ((*(int *)&p->d0) != 0)
            WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 38, 0, 0, 0xf0f);
        else
            WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 8, 1, 0, 0xf0f);
        if (GXx_GetMasterBrightness_((u16 *)REG_MASTER_BRIGHT_ADDR) == -16) {
            WIPE_SYS_Start(0, 1, 1, 0, 16, 1, 0x48);
            *(int *)&p->state = 33;
        } else {
            *(int *)&p->state = 1;
        }
    } else {
        WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 8, 1, 0, 0xf0f);
        WORLDTRADE_SetNextState(p, 23, 1);
    }
    CLACT_SetActorDrawEnable((struct ClactActor *)((struct WorldtradeObj *)((struct WorldtradeObj *)p->scrollBarObj)), 1);
    return 2;
}

int WORLDTRADE_SEARCH_HitTestButtons(void)
{
    return TOUCHPANEL_HitTrg((const TouchHitTable *)g_022037D4);
}

void WORLDTRADE_SEARCH_HandleButton(WorldtradeWork *p, int mode)
{
    u32 v; uptr h;
    switch(mode) {
    case 0: p->state=4; break;
    case 1:
        if(p->rec.name!=0) {
            h=(uptr)POKE_PERSONAL_Create((u16)p->rec.name,0,0x48);
            v=POKE_PERSONAL_GetParam((const struct PersonalData *)h,0x14);
            POKE_PERSONAL_Delete((void *)h);
            p->st->genderEvent=v;
            if(WORLDTRADE_DEPOSIT_SetGenderFromEvent((u8 *)p+0xB56,p->st->genderEvent)) break;
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
 * WorldtradeMenu input handler. A touch on an entry (WORLDTRADE_SEARCH_HitTestButtons) selects it and
 * acts at once; otherwise the d-pad moves the cursor (WORLDTRADE_SEARCH_UpdateKeyCursor) and A
 * acts on the current entry, B jumps to the last entry of page 1. WorldtradeEntry 1
 * hands the +0xB56 record to WORLDTRADE_DEPOSIT_SetGenderFromEvent, entry 5 compares the two
 * records, entry 4 depends on the +0xD0 word; every path picks the next
 * state (+0x28) and a sound. Always returns 2.
 */
int WORLDTRADE_SEARCH_StateMainInput(WorldtradeWork *p)
{
    int sel = WORLDTRADE_SEARCH_HitTestButtons();

    if (sel != -1) {
        UI_SetInputMode(1);
        WORLDTRADE_SEARCH_SelectButton(p, sel);
        sel = WORLDTRADE_SEARCH_GetSelectedButton(p);
        switch (sel) {
        case 1:
            if (p->rec_rec2[0].name != 0) {
                u32 h = (uptr)POKE_PERSONAL_Create((u16)p->rec_rec2[0].name, 0, 0x48);
                u32 v = POKE_PERSONAL_GetParam((const struct PersonalData *)h, 0x14);
                POKE_PERSONAL_Delete((void *)h);
                p->st->genderEvent = v;
                if (WORLDTRADE_DEPOSIT_SetGenderFromEvent((u8 *)(&p->rec_rec2[0]), p->st->genderEvent) != 0) {
                    CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
                    CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                    GFL_USE_PlaySeDefaultVolume(0x557);
                    return 2;
                }
            }
            CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
            GFL_USE_PlaySeDefaultVolume(0x54C);
            CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
            p->state_i = 0x23;
            break;
        case 5:
            if (p->rec_rec2[0].name == 0 || WORLDTRADE_SEARCH_CompareRecords(&p->rec_rec2[0], &p->rec_rec2[1], p->countryFilter, p->lastCountryFilter) != 0) {
                GFL_USE_PlaySeDefaultVolume(0x557);
            } else {
                GFL_USE_PlaySeDefaultVolume(0x54C);
            }
            CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
            CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
            p->state_i = 0x23;
            break;
        case 4:
            if (p->d0 != 0) {
                CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
                GFL_USE_PlaySeDefaultVolume(0x54C);
                CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                p->state_i = 0x23;
            } else {
                CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
                CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                GFL_USE_PlaySeDefaultVolume(0x557);
                p->state_i = 0x25;
            }
            break;
        default:
            CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
            if (sel == 6) {
                GFL_USE_PlaySeDefaultVolume(0x551);
            } else {
                GFL_USE_PlaySeDefaultVolume(0x54C);
            }
            CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
            p->state_i = 0x23;
            break;
        }
    } else if (KEY_GetTrg() != 0 && UI_GetInputMode() == 1) {
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        UI_SetInputMode(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return 2;
    } else {
        WORLDTRADE_SEARCH_UpdateKeyCursor(p);
        if (KEY_GetTrg() & 1) {
            sel = WORLDTRADE_SEARCH_GetSelectedButton(p);
            switch (sel) {
            case 1:
                if (p->rec_rec2[0].name != 0) {
                    u32 h = (uptr)POKE_PERSONAL_Create((u16)p->rec_rec2[0].name, 0, 0x48);
                    u32 v = POKE_PERSONAL_GetParam((const struct PersonalData *)h, 0x14);
                    POKE_PERSONAL_Delete((void *)h);
                    p->st->genderEvent = v;
                    if (WORLDTRADE_DEPOSIT_SetGenderFromEvent((u8 *)(&p->rec_rec2[0]), p->st->genderEvent) != 0) {
                        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
                        CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                        GFL_USE_PlaySeDefaultVolume(0x557);
                        return 2;
                    }
                }
                CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
                GFL_USE_PlaySeDefaultVolume(0x54C);
                CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                p->state_i = 0x23;
                break;
            case 5:
                if (p->rec_rec2[0].name == 0 || WORLDTRADE_SEARCH_CompareRecords(&p->rec_rec2[0], &p->rec_rec2[1], p->countryFilter, p->lastCountryFilter) != 0) {
                    GFL_USE_PlaySeDefaultVolume(0x557);
                } else {
                    GFL_USE_PlaySeDefaultVolume(0x54C);
                }
                CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                p->state_i = 0x23;
                break;
            case 4:
                if (p->d0 != 0) {
                    GFL_USE_PlaySeDefaultVolume(0x54C);
                    CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                    p->state_i = 0x23;
                } else {
                    CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
                    CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
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
                CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
                p->state_i = 0x23;
                break;
            }
        } else if (KEY_GetTrg() & 2) {
            p->st->cursorColumn = 1;
            p->st->rightRow = 2;
            CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton(p)].anim2);
            p->state_i = 0x24;
            GFL_USE_PlaySeDefaultVolume(0x551);
        }
    }
    return 2;
}

int WORLDTRADE_SEARCH_StateConfirmSearch(WorldtradeWork *p)
{
    if (p->rec.name == 0) {
        WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 12, 1, 0, 0xf0f);
        WORLDTRADE_SetNextState(p, 23, 1);
    } else {
        if (WORLDTRADE_SEARCH_CompareRecords((WorldtradeRec *)((unsigned char *)p + 0xb56), (WorldtradeRec *)((unsigned char *)p + 0xb5c), p->countryFilter, p->lastCountryFilter)) {
            WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 39, 1, 0, 0xf0f);
            WORLDTRADE_SetNextState(p, 23, 1);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x63f);
            p->countdownFrames = 0x76;
            WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 13, 1, 0, 0xf0f);
            WORLDTRADE_SetNextState(p, 23, 17);
            if ((*(int *)&p->d0) > 0)
                WORLDTRADE_SUBLCD_UpdateSlotAnims(p);
        }
    }
    return 2;
}

int WORLDTRADE_SEARCH_StartDownloadMatchData(WorldtradeWork *p)
{
    DownloadRequest q;
    if (p->countryFilter == 0) {
        DPW_TR_DownloadMatchDataAsync((const DpwTrSearchKey *)((u8 *)p + 0xb56), 7, (u8 *)p + 0x20c);
    } else {
        MI_CpuFill8(&q, 0, 8);
        q.id = p->rec_rec2[0].name;
        q.a = p->rec_rec2[0].mode;
        q.b = p->rec_rec2[0].key;
        q.c = p->rec_rec2[0].val;
        q.d = *(s8 *)((u8 *)p + 0xb5b);
        q.mode = 7;
        q.flag = p->countryFilter;
        DPW_TR_DownloadMatchDataRawAsync((const void *)&q, (u8 *)((uptr)((u8 *)p + 0x20c)));
    }
    *(u16 *)&p->rec_rec2[1].name = *(u16 *)&p->rec_rec2[0].name;
    *(u16 *)&p->rec_rec2[1].mode = *(u16 *)&p->rec_rec2[0].mode;
    *(u16 *)&p->rec_rec2[1].val = *(u16 *)&p->rec_rec2[0].val;
    p->lastCountryFilter = p->countryFilter;
    p->wait = 0;
    p->state = 18;
    p->historyFlag = 0;
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
 * UNBLOCKED: DPW_TR_IsAsyncEnd(0x021C866C) and DPW_TR_GetAsyncResult
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int WORLDTRADE_SEARCH_WaitDownloadResult(WorldtradeWork *p)
{
    s32 n;

    if (DPW_TR_IsAsyncEnd() != 0) {
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
            GFL_NET_ERR_WaitLinkClosed();
            GFL_NET_STATE_SetWifiError();
            GFL_NET_ERR_ResetState();
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

int WORLDTRADE_SEARCH_StateUpdateHistorySlots(WorldtradeWork *p)
{
    if (p->countdownFrames == 0) {
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

int WORLDTRADE_SEARCH_StateShowEmptyHistoryMessage(WorldtradeWork *p)
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

int WORLDTRADE_SEARCH_StateCountdownMessage(WorldtradeWork *p)
{
    if (++p->cnt > 45) {
        WORLDTRADE_SEARCH_PrintMessage((unsigned char *)p, 38, 1, 0, 0xf0f);
        WORLDTRADE_SetNextState(p, 23, 1);
        p->historyFlag = 1;
    }
    return 2;
}

int WORLDTRADE_SEARCH_StateShowClearedMessage(WorldtradeWork *p)
{
    p->rec2Name = 0;
    WORLDTRADE_SEARCH_PrintMessage((unsigned char *)p, 44, 1, 0, 0xf0f);
    WORLDTRADE_SetNextState(p, 23, 1);
    GFL_USE_PlaySeDefaultVolume(0x557);
    (*(int *)&p->d0) = 0;
    WORLDTRADE_SEARCH_DrawHistoryHeader(p->wDB0, p->bank, 0, (char *)p + 0xfa0);
    return 2;
}

int WORLDTRADE_SEARCH_StatePrintMessage171(WorldtradeWork *p) {WORLDTRADE_SEARCH_PrintMessage((u8 *)p,171,4,0,0xf0f);WORLDTRADE_SetNextState(p,24,31);(*(unsigned int *)&p->cnt)=0;GFL_USE_PlaySeDefaultVolume(0x557);return 2;}

int WORLDTRADE_SEARCH_StatePrintMessage172(WorldtradeWork *p) {WORLDTRADE_SEARCH_PrintMessage((u8 *)p,172,4,0,0xf0f);WORLDTRADE_SetNextState(p,24,3);WORLDTRADE_SetStateAndReturn(p,0,21);GFL_USE_PlaySeDefaultVolume(0x557);return 2;}

/*
 * Return the current cursor slot of the state block at +0xE00: the +0x28
 * word while the +0x24 flag is clear, else the +0x2C word plus four.
 * A slot of seven or more reports through GF_PANIC_Fail (the raw-address
 * assert shape; 0x02203E2C is a plain constant, as in WORLDTRADE_ADAPTER_QueueMessagePrint).
 */
int WORLDTRADE_SEARCH_GetSelectedButton(WorldtradeWork *p)
{
    WorldtradeState *s = p->st;
    int r;

    if (s->cursorColumn == 0) {
        r = s->leftRow;
    } else {
        r = s->rightRow + 4;
    }
    if (r >= 7) {
        GF_PANIC_Fail((void *)0x02203E2C, 0, (void *)0x02203E2C);
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
void WORLDTRADE_SEARCH_UpdateKeyCursor(WorldtradeWork *p)
{
    int a;
    int b;

    if (KEY_GetTrg() & 0x40) {
        if (p->st->cursorColumn == 0) {
            if (p->st->leftRow > 0) {
                p->st->leftRow--;
                GFL_USE_PlaySeDefaultVolume(0x548);
                CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton((WorldtradeWork *)p)].anim);
            }
        } else {
            if (p->st->rightRow > 0) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                p->st->rightRow--;
                CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton((WorldtradeWork *)p)].anim);
            }
        }
    } else if (KEY_GetTrg() & 0x80) {
        if (p->st->cursorColumn == 0) {
            if (p->st->leftRow < 3) {
                p->st->leftRow++;
                GFL_USE_PlaySeDefaultVolume(0x548);
                CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton((WorldtradeWork *)p)].anim);
            }
        } else {
            if (p->st->rightRow < 2) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                p->st->rightRow++;
                CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton((WorldtradeWork *)p)].anim);
            }
        }
    } else if (KEY_GetTrg() & 0x10) {
        if (p->st->cursorColumn != 1) {
            p->st->cursorColumn = 1;
            GFL_USE_PlaySeDefaultVolume(0x548);
            CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton((WorldtradeWork *)p)].anim);
        } else {
            p->st->cursorColumn = 1;
        }
    } else if (KEY_GetTrg() & 0x20) {
        if (p->st->cursorColumn != 0) {
            p->st->cursorColumn = 0;
            GFL_USE_PlaySeDefaultVolume(0x548);
            CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, tbl_02203D46[WORLDTRADE_SEARCH_GetSelectedButton((WorldtradeWork *)p)].anim);
        } else {
            p->st->cursorColumn = 0;
        }
    }
    a = WORLDTRADE_SEARCH_GetSelectedButton((WorldtradeWork *)p);
    b = WORLDTRADE_SEARCH_GetSelectedButton((WorldtradeWork *)p);
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
void WORLDTRADE_SEARCH_SelectButton(WorldtradeWork *p, int button)
{
    int a;
    int b;

    if (tbl_02203D38.sel[button].page == 0) {
        p->st->cursorColumn = 0;
        p->st->leftRow = tbl_02203D38.sel[button].slot;
    } else {
        p->st->cursorColumn = 1;
        p->st->rightRow = tbl_02203D38.sel[button].slot;
    }
    a = WORLDTRADE_SEARCH_GetSelectedButton((WorldtradeWork *)p);
    b = WORLDTRADE_SEARCH_GetSelectedButton((WorldtradeWork *)p);
    WORLDTRADE_SetActorPos(p->cursor, tbl_02203D46[a].x, tbl_02203D46[b].y);
}

/*
 * When the countdown at +0xd3c is spent, run the fixed 3/6/1/0x48 opener, then state 0.
 */
int WORLDTRADE_SEARCH_StateStartWipeOutPage(WorldtradeWork *p)
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
 * DPW_TR_End, which has no independent witness outside 0x021FEB84..0x021FEBB6; the
 * resolver reports "(arm, from name) ... 8 overlays overlap this address
 * (ov016, ov021, ov093, ov111, ov114, ov128, ov172, ov208), none resolvable
 * without a region hint on the symbols: line".  Naming one of those eight
 * regions would be a guess, so the site stays parked.
 *
 * Shape: two hand-overs, then the fixed 6/1/0x48 opener, state 0, return 3.
 */
int WORLDTRADE_SEARCH_StateStartWipeOutDisconnect(WorldtradeWork *p)
{
    DPW_TR_End();
    WORLDTRADE_DeleteTimeIcon(p);
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x48);
    p->state = 0;
    return 3;
}

/*
 * Build through WORLDTRADE_SEARCH_PrintMessage and publish the 0x10/0x5 pair.
 */
int WORLDTRADE_SEARCH_StatePrintNamePrompt(WorldtradeWork *p)
{
    WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 0x9, 1, 0, 0xf0f);
    WORLDTRADE_SetNextState((WorldtradeWork *)p, 0x17, 0x5);
    return 2;
}

/*
 * Publish +0xde4, kick helper 9, latch state 6.
 */
int WORLDTRADE_SEARCH_StateOpenNameMenu(WorldtradeWork *p)
{
    WORLDTRADE_INPUT_MenuSetMode((WorldtradeMenu *)((u8 *)((*(unsigned int *)&p->menu))), 0);
    WORLDTRADE_SEARCH_SetBlendEffect(9);
    p->state = 6;
    return 2;
}

int WORLDTRADE_SEARCH_StateNameMenuInput(WorldtradeWork *p)
{
    int r = WORLDTRADE_INPUT_MenuUpdate(p->menu);
    uptr h;
    u32 v;

    switch (r) {
    case -2:
        WORLDTRADE_SEARCH_SetBlendEffect(0);
        p->state = 0;
        WORLDTRADE_DEPOSIT_SetListRangeEntry((SelTable *)p->area, p->target->menuScroll + p->target->menuRow, p->target->restoreScroll, p->target->restoreRow);
        break;
    case -1:
        break;
    default:
        WORLDTRADE_SEARCH_SetBlendEffect(0);
        p->sel_h = r;
        p->state = 0;
        BMP_Clear(BMP_WIN_GetBmp(p->winA), 0);
        WORLDTRADE_DEPOSIT_PrintName((void *)p->winA, (void *)p->names, r, 0, 0, 0x3C40, (void *)p->printerBlock);
        h = (uptr)POKE_PERSONAL_Create((u16)r, 0, 0x48);
        v = POKE_PERSONAL_GetParam((const struct PersonalData *)h, 0x14);
        POKE_PERSONAL_Delete((struct PersonalData *)h);
        p->target->genderEvent = v;
        WORLDTRADE_DEPOSIT_SetListRangeEntry((SelTable *)p->area, p->target->menuScroll + p->target->menuRow, p->target->restoreScroll, p->target->restoreRow);
        if (WORLDTRADE_DEPOSIT_SetGenderFromEvent((u8 *)(&p->sel_h), p->target->genderEvent) != 0) {
            BMP_Clear(BMP_WIN_GetBmp(p->winB), 0);
            WORLDTRADE_DEPOSIT_PrintModeLabelAligned(p->winB, p->bank, p->mode_sb, 1, 0, 0, 0x3C40, p->printerBlock);
        }
        break;
    }
    return 2;
}

/*
 * Build through WORLDTRADE_SEARCH_PrintMessage and publish the 0x10/0x8 pair.
 */
int WORLDTRADE_SEARCH_StatePrintGenderPrompt(WorldtradeWork *p)
{
    WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 0xa, 1, 0, 0xf0f);
    WORLDTRADE_SetNextState((WorldtradeWork *)p, 0x17, 0x8);
    return 2;
}

/*
 * Publish the +0xde4 slot, kick helper 9 and latch state 9.
 */
int WORLDTRADE_SEARCH_StateOpenGenderMenu(WorldtradeWork *p)
{
    WORLDTRADE_INPUT_MenuSetMode((WorldtradeMenu *)((u8 *)((*(unsigned int *)&p->menu))), 1);
    WORLDTRADE_SEARCH_SetBlendEffect(9);
    p->state = 9;
    return 2;
}

int WORLDTRADE_SEARCH_StateGenderMenuInput(WorldtradeWork *p)
{
    unsigned r;
    void *w;
    r = WORLDTRADE_INPUT_MenuUpdate(p->menu);
    switch (r) {
    case -2:
        WORLDTRADE_SEARCH_SetBlendEffect(0);
        BMP_MENUWORK_DrawWindowBorder(p->d40, 0);
        w = p->d40;
        BMP_WIN_TransferChars(w);
        BMP_WIN_MakeScreen(w);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(w));
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
int WORLDTRADE_SEARCH_StatePrintLevelPrompt(WorldtradeWork *p)
{
    WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 0xb, 1, 0, 0xf0f);
    WORLDTRADE_SetNextState((WorldtradeWork *)p, 0x17, 0xb);
    return 2;
}

/*
 * Sentinel at +0xbc, publish +0xde4, kick helper 9, latch state 0xc.
 */
int WORLDTRADE_SEARCH_StateOpenLevelMenu(WorldtradeWork *p)
{
    p->menuChoice = 0xffff;
    WORLDTRADE_INPUT_MenuSetMode((WorldtradeMenu *)((u8 *)((*(unsigned int *)&p->menu))), 2);
    WORLDTRADE_SEARCH_SetBlendEffect(9);
    p->state = 0xc;
    return 2;
}

int WORLDTRADE_SEARCH_StateLevelMenuInput(WorldtradeWork *p)
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
int WORLDTRADE_SEARCH_StatePrintConditionPrompt(WorldtradeWork *p)
{
    WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 0xbe, 1, 0, 0xf0f);
    WORLDTRADE_SetNextState((WorldtradeWork *)p, 0x17, 0xe);
    return 2;
}

/*
 * Sentinel at +0xbc, publish +0xde4, kick helper 9, latch state 0xf.
 */
int WORLDTRADE_SEARCH_StateOpenConditionMenu(WorldtradeWork *p)
{
    p->menuChoice = 0xffff;
    WORLDTRADE_INPUT_MenuSetMode((WorldtradeMenu *)((u8 *)((*(unsigned int *)&p->menu))), 3);
    WORLDTRADE_SEARCH_SetBlendEffect(9);
    p->state = 0xf;
    return 2;
}

int WORLDTRADE_SEARCH_StateConditionMenuInput(WorldtradeWork *p)
{
    int r;
    void *w;
    r = WORLDTRADE_INPUT_MenuUpdate(p->menu);
    if (r == -1) {
    } else if (r == -2 || r == d_02202EAC + 1) {
        WORLDTRADE_SEARCH_SetBlendEffect(0);
        BMP_MENUWORK_DrawWindowBorder(p->d40, 0);
        w = p->d40;
        BMP_WIN_TransferChars(w);
        BMP_WIN_MakeScreen(w);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(w));
        p->state_i = 0;
    } else {
        WORLDTRADE_SEARCH_SetBlendEffect(0);
        WORLDTRADE_DEPOSIT_SetCountryFilter(p, r);
        p->state_i = 0;
        BMP_Clear(BMP_WIN_GetBmp(p->win2[1]), 0);
        WORLDTRADE_DEPOSIT_PrintMessageLine(p->win2[1], p->msg_p, p->bank, p->countryFilter, 0, 0, 0x3c40, (char *)p + 0xfa0);
    }
    return 2;
}

int WORLDTRADE_SEARCH_StateOpenClearConfirm(WorldtradeWork *p)
{
    WORLDTRADE_OpenTaskMenuYesNoDefault((WorldtradeWork *)((uptr)p), 0x14, 0x120, 0x3, 0x1);
    p->state = 0x1b;
    return 2;
}

int WORLDTRADE_SEARCH_StateClearConfirmInput(WorldtradeWork *p)
{
    unsigned r = WORLDTRADE_UpdateTaskMenuYesNo((WorldtradeWork *)p);
    if (r == 1) {
        WORLDTRADE_CloseTaskMenu((WorldtradeWork *)p);
        *(int *)&p->state = 2;
        WORLDTRADE_SetStateAndReturn(p, 1, 0);
        if ((*(int *)&p->d0) > 0) WORLDTRADE_SUBLCD_UpdateSlotAnims(p);
        (*(int *)&p->d0) = 0;
    } else if (r == 2) {
        WORLDTRADE_CloseTaskMenu((WorldtradeWork *)p);
        *(int *)&p->state = 0;
    }
    return 2;
}

int WORLDTRADE_SEARCH_StateReturnToMain(WorldtradeWork *p)
{
    p->state_i = 1;
    return 2;
}

/*
 * Build through WORLDTRADE_SEARCH_PrintMessage and publish the 0x10/0x1 pair.
 */
int WORLDTRADE_SEARCH_StatePrintMessage9E(WorldtradeWork *p)
{
    WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 0x9e, 1, 0, 0xf0f);
    WORLDTRADE_SetNextState((WorldtradeWork *)p, 0x17, 0x1);
    return 2;
}

int WORLDTRADE_SEARCH_StateWaitMessage(u8 *p)
{
    if (WORLDTRADE_ADAPTER_IsStreamBusy((PrintStreamCtx *)(p + 0xfa0)) == 0) {
        ((WorldtradeWork *)p)->state = ((WorldtradeWork *)p)->returnState;
    }
    return 2;
}

/*
 * When the build query answers 0 and either probe is set, roll the state word over.
 */
int WORLDTRADE_SEARCH_StateWaitMessageOrKey(u8 *p)
{
    if (WORLDTRADE_ADAPTER_IsStreamBusy((PrintStreamCtx *)(p + 0xfa0)) == 0) {
        if (KEY_GetTrg() != 0 || TOUCHPANEL_GetTrg() != 0) {
            ((WorldtradeWork *)p)->state = ((WorldtradeWork *)p)->returnState;
        }
    }
    return 2;
}

/*
 * When the build query answers 0, bump the countdown at +0xdfc and roll state when it passes 0x2d.
 */
int WORLDTRADE_SEARCH_StateWaitMessageTimed(u8 *p)
{
    if (WORLDTRADE_ADAPTER_IsStreamBusy((PrintStreamCtx *)(p + 0xfa0)) == 0) {
        if (++((WorldtradeWork *)p)->cnt > 0x2d) {
            ((WorldtradeWork *)p)->cnt = 0;
            ((WorldtradeWork *)p)->state = ((WorldtradeWork *)p)->returnState;
        }
    }
    return 2;
}

/*
 * volatile: 021FF12E reads hardware register 04000304.
 */
int WORLDTRADE_SEARCH_StateScrollOut(WorldtradeWork *p)
{
    ++p->scroll;
    if (WIPE_SYS_EndCheck()) {
        *(volatile u16 *)0x04000304 |= 0x8000;
        p->scroll = -16;
        if (p->historyFlag) {
            p->state_i = 2;
            WORLDTRADE_SetStateAndReturn(p, 3, 16);
            p->cur = 0;
        }
        CLACT_SetActorDrawEnable((struct ClactActor *)p->scrollBarObj, 0);
    }
    return 2;
}

/*
 * Decrement the countdown at +0xd3c and, when the tick returns non-zero, zero it and latch state 1.
 */
int WORLDTRADE_SEARCH_StateWaitWipeIn(WorldtradeWork *p)
{
    u32 v = p->pageNum - 1;

    p->pageNum = v;
    if (WIPE_SYS_EndCheck() != 0) {
        p->pageNum = 0;
        p->state = 1;
    }
    return 2;
}

int WORLDTRADE_SEARCH_StateHistoryInput(WorldtradeWork *p)
{
    int r;
    if (KEY_GetTrg() & 1) {
        WIPE_SYS_Start(0, 0, 0, 0, 16, 1, 72);
    } else {
        r = WORLDTRADE_SUBLCD_CheckButtonTouch((*(int *)&p->d0));
        if (p->historyFlag && r >= 0) {
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct WorldtradeObj *)(*(unsigned *)((char *)p + 0xd0c + (r + 1) * 4))), (u16)(16 + r * 4));
            p->state_i = 2;
            WORLDTRADE_SetStateAndReturn(p, 3, 0);
            p->cur = r;
            GFL_USE_PlaySeDefaultVolume(0x54c);
        }
    }
    return 2;
}

int WORLDTRADE_SEARCH_StateCursorAnimA(WorldtradeWork *p)
{
    if (CLACT_IsActorAnimActive((struct ClactActor *)((struct Actor *)(p->cursor))) == 0) {
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct WorldtradeObj *)(p->cursor)), d_02203D4A[WORLDTRADE_SEARCH_GetSelectedButton((WorldtradeWork *)p)][0]);
        if (UI_GetInputMode() == 1)
            CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 0);
        else
            CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        WORLDTRADE_SEARCH_HandleButton(p, WORLDTRADE_SEARCH_GetSelectedButton((WorldtradeWork *)p));
    }
    return 2;
}

int WORLDTRADE_SEARCH_StateCursorAnimB(WorldtradeWork *p)
{
    if (CLACT_IsActorAnimActive((struct ClactActor *)((struct Actor *)(p->cursor))) == 0) {
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct WorldtradeObj *)(p->cursor)), d_02203D4A[WORLDTRADE_SEARCH_GetSelectedButton((WorldtradeWork *)p)][0]);
        if (UI_GetInputMode() == 1)
            CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 0);
        else
            CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        WORLDTRADE_SEARCH_PrintMessage((u8 *)p, 15, 1, 0, 0xf0f);
        WORLDTRADE_SetNextState((WorldtradeWork *)((char *)((u8 *)p)), 23, 26);
    }
    return 2;
}

int WORLDTRADE_SEARCH_StateCursorAnimC(WorldtradeWork *p)
{
    if (CLACT_IsActorAnimActive((struct ClactActor *)((struct Actor *)(p->cursor))) == 0) {
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct WorldtradeObj *)(p->cursor)), d_02203D4A[WORLDTRADE_SEARCH_GetSelectedButton((WorldtradeWork *)((char *)p))][0]);
        if (UI_GetInputMode() == 1) {
            CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 0);
        } else {
            CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        }
        p->state = 1;
    }
    return 2;
}

/*
 * Tear the object down: unhook the two sub-objects, release the +0xd40 resource, wire the 0/1/e quad, then drain the four engine hooks.
 */
void WORLDTRADE_SEARCH_PrintMessage(u8 *p, u32 msgId, int unused1, int unused2, int unused3)
{
    struct BmpWin *v;

    MSGDATA_ReadString((struct MsgBank *)(*(u32 *)&((WorldtradeWork *)p)->bank_u), msgId, (struct Strbuf *)((void *)(*(u32 *)(p + 0xb6c + 0x1c))));
    BMP_Clear((struct Bmp *)((struct CharBuf *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)((struct Descriptor *)((WorldtradeWork *)p)->frame)))), 0xf);
    BMP_MENUWORK_DrawWindow((void *)(((WorldtradeWork *)p)->frame), 0, 1, 0xe);
    WORLDTRADE_ADAPTER_QueuePrintDefaultColor((void *)(((WorldtradeWork *)p)->frame), 0, (void *)(*(u32 *)(p + 0xb6c + 0x1c)), 0, 0, (void *)(p + 0xfa0));
    v = ((WorldtradeWork *)p)->frame;
    BMP_WIN_TransferChars((struct BmpWin *)v);
    BMP_WIN_MakeScreen((struct BmpWin *)v);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)v));
}

/*
 * note: pass 2 2026-10-06 P2L19: closed from 8 B off (238 B). The print callees WORLDTRADE_INPUT_PrintStringAlignedLine and
 *   WORLDTRADE_INPUT_PrintStringAlignedWrapped are declared void here. Their bodies end in a call and never set r0 themselves, so the
 *   image does not decide between int and void, and no caller reads the result. With int, the six stack
 *   zeros and the six 0x440 stores tie and the zero takes r7; with void the colour 0x440 takes r7 and
 *   the zero is rematerialised per call, as in the image. Plain literals, no pragma.
 */
void WORLDTRADE_SEARCH_DrawFormLabels(void **win, void **win2, void *bank, void *printer)
{
    void *s1, *s2, *s3, *s4, *s5, *s6;

    s1 = MSGDATA_AllocString(bank, 0x43);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[0], s1, 0, 0, 0, 0x440, printer);
    STRBUF_Delete(s1);

    s2 = MSGDATA_AllocString(bank, 0x45);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[2], s2, 0, 0, 0, 0x440, printer);
    STRBUF_Delete(s2);

    s3 = MSGDATA_AllocString(bank, 0x47);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[4], s3, 0, 0, 0, 0x440, printer);
    STRBUF_Delete(s3);

    s4 = MSGDATA_AllocString(bank, 0xB9);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win2[0], s4, 0, 0, 0, 0x440, printer);
    STRBUF_Delete(s4);

    s5 = MSGDATA_AllocString(bank, 0x49);
    WORLDTRADE_INPUT_PrintStringAlignedWrapped(win[6], s5, 0, 0, 0, 0x440, printer);
    STRBUF_Delete(s5);

    s6 = MSGDATA_AllocString(bank, 0xFC);
    WORLDTRADE_INPUT_PrintStringAlignedWrapped(win[7], s6, 0, 0, 0, 0x440, printer);
    STRBUF_Delete(s6);
}

void WORLDTRADE_SEARCH_DrawHistoryHeader(void *win, void *bank, int flag, void *printer)
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
    BG_SYS_FillTileMap(1, 0x11, 2, 0xF, 4, pal);
    BG_SYS_PushTile(1);
    str = MSGDATA_AllocString(bank, 0x4B);
    WORLDTRADE_INPUT_PrintStringAlignedWrapped(win, (void *)str, 0, 0, 0, color, (void *)printer);
    STRBUF_Delete(str);
}

/*
 * True when two {s16, s8, s8, s8}
/*
 * True when two {s16, s8, s8, s8} records are equal field by field and
 * the two trailing arguments are equal.
 */
int WORLDTRADE_SEARCH_CompareRecords(WorldtradeRec *x, WorldtradeRec *y, int m, int n)
{
    if (x->name == y->name && x->mode == y->mode && x->key == y->key && x->val == y->val && m == n) {
        return 1;
    }
    return 0;
}

void WORLDTRADE_SEARCH_ScrollBgs(WorldtradeWork *p)
{
    BG_SYS_ChangeScrollImmediate(0, 3, p->scroll);
    BG_SYS_ChangeScrollImmediate(1, 3, p->scroll);
    BG_SYS_ChangeScrollImmediate(2, 3, p->scroll);
    BG_SYS_ChangeScrollImmediate(3, 3, p->scroll);
    BG_SYS_ChangeScrollImmediate(4, 3, -p->scroll);
    BG_SYS_ChangeScrollImmediate(5, 3, -p->scroll);
    BG_SYS_ChangeScrollImmediate(6, 3, -p->scroll);
    BG_SYS_ChangeScrollImmediate(7, 3, -p->scroll);
}

/*
 * Program the 0x04000050 display register from the flag, or clear it.
 */
void WORLDTRADE_SEARCH_SetBlendEffect(u32 brightness)
{
    if (brightness != 0) {
        G2x_SetBlendBrightness_(REG_BLDCNT_ADDR, 0xa, brightness);
    } else {
        *(u16 *)0x04000050 = 0;
    }
}
