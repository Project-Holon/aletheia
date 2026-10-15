/*
 * file:     pdwacc_disp.c
 * unit:     yes
 * function: PDWACC_DISP_Init, PDWACC_DISP_Draw, PDWACC_DISP_Exit, PDWACC_DISP_InitBgLayers, PDWACC_DISP_VBlankTask, PDWACC_DISP_LoadResources, PDWACC_DISP_PaletteTask, PDWACC_DISP_DeleteActors, PDWACC_STATE_HandleHttpError, PDWACC_STATE_SetState, PDWACC_STATE_ChangeState, PDWACC_STATE_StateWaitFade, PDWACC_STATE_StateFadeOutBgm, PDWACC_STATE_StateWaitInputStream, PDWACC_STATE_StateSaveMainWait, PDWACC_STATE_StateSaveStart, PDWACC_STATE_StateRestartTimeIcon, PDWACC_STATE_StateWaitInputClearWindow, PDWACC_STATE_StateWaitInputPrintNumbers, PDWACC_STATE_StatePrintNumbersMessage, PDWACC_STATE_StateWaitInput, PDWACC_STATE_StatePrintError, PDWACC_STATE_StateWaitStreamThenSendRequest, PDWACC_STATE_StateTimeIconMessage, PDWACC_STATE_StateConfirmMenuSelect, PDWACC_STATE_StateOpenConfirmMenu, PDWACC_STATE_StatePrintIntroMessage, PDWACC_STATE_StateReceiveResponse, PDWACC_STATE_StateSendRequest, PDWACC_STATE_StateWaitFadeClearNumbers, PDWACC_STATE_StatePrintResultMessage, PDWACC_STATE_DestroyHttpConnection, PDWACC_STATE_ProcInit, PDWACC_STATE_ProcMain, PDWACC_STATE_ProcExit
 * address:  0x021D9958
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
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049F78 0x02049F78 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_SetTileUnit 0x02040DA8 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   func_0207E468 0x0207E468 arm
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   GX_DispOn 0x0207D46C arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   func_02030734 0x02030734 arm
 *   func_0207D63C 0x0207D63C arm
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   func_020315D4 0x020315D4 arm
 *   ov067_id 0x00000043 data
 *   func_02034AC4 0x02034AC4 arm
 *   gGsyncClactConfig 0x020A1464 data a4
 *   func_02034A5C 0x02034A5C arm
 *   ov_id 0x00000043 data
 *   GX_LoadBGPltt 0x0207E3D0 arm
 *   KEY_GetTrg  0x020362DC  arm
 *   GAME_DATA_SaveCancel  0x02012E08  thumb
 *   NHTTP_RAP_DeleteConnection 0x021B9774 thumb ov114
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   NHTTP_RAP_GetResultCode 0x021B99DC thumb ov114
 *   NHTTP_RAP_PollConnection 0x021B9790 thumb ov114
 *   NHTTP_RAP_GetRecvBuffer 0x021B97F4 thumb ov114
 *   NHTTP_RAP_CreateRequest 0x021B95D4 thumb ov114
 *   NHTTP_RAP_GetConnection 0x021B973C thumb ov114
 *   NHTTP_RAP_StartConnection 0x021B9748 thumb ov114
 *   NHTTP_AddPostDataRaw 0x021BE79C arm ov114
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_020092E0 0x020092E0 thumb
 *   SAVE_CONTROL_GetWorkArea 0x020071D8 thumb
 *   NHTTP_RAP_Destroy  0x021B9838  thumb  ov114
 *   ov114_id 0x00000072 data
 *   NHTTP_RAP_Create 0x021B9800 thumb ov114
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   func_0200FB24 0x0200FB24 thumb
 *   d_021DABFC 0x021DABFC data a1
 *   d_021DABCC 0x021DABCC data a4
 *   d_021DABBC 0x021DABBC data a4
 *   d_021DA8A8      0x021DA8A8  data
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   PALANM_BlendColors 0x02021F64 thumb
 *   func_020056A0 0x020056A0 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   func_02009448 0x02009448 thumb
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb  arm9
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb  arm9
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb  arm9
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb  arm9
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb  arm9
 *   PDWACC_MESSAGE_InitSystem 0x021D92CC thumb ov123
 *   PDWACC_MESSAGE_UpdateSystem 0x021D9404 thumb ov123
 *   PDWACC_MESSAGE_ExitSystem 0x021D941C thumb ov123
 *   PDWACC_MESSAGE_PrintStream 0x021D9514 thumb ov123
 *   PDWACC_MESSAGE_RestartTimeIcon 0x021D95B4 thumb ov123
 *   PDWACC_MESSAGE_UpdateStream 0x021D95F0 thumb ov123
 *   PDWACC_MESSAGE_ClearStream 0x021D9634 thumb ov123
 *   PDWACC_MESSAGE_OpenYesNoMenu 0x021D9670 thumb ov123
 *   PDWACC_MESSAGE_PrintInWindow 0x021D9730 thumb ov123
 *   PDWACC_MESSAGE_ClearWindow 0x021D97B0 thumb ov123
 *   PDWACC_MESSAGE_PrintNumberWindows 0x021D9844 thumb ov123
 *   PDWACC_MESSAGE_DeleteNumberWindows 0x021D9918 thumb ov123
 */
#include "pdwacc_disp_types.h"


extern void BG_SYS_InitBgLayer(u32, const struct BgTemplate *, u32);

extern void BG_SYS_PushTile(u32);

extern void func_02040588(unsigned char which, unsigned char enable);

extern void BG_SYS_Init(u32, u32, u32, u32);

extern void BG_SYS_SetTileEntry(u32, u32, u32, u32, u8, u8, u8);

extern void WIPE_SYS_Start(void *, u32, u32, u32, u32, u32, u32);

extern int GFL_NET_GetRunState(void);

extern u32 APP_TASKMENU_IsFinish(void *m);

extern u8 APP_TASKMENU_GetCursorPos(const void *menu);

extern void APP_TASKMENU_CloseMenu(void *m);

extern void *func_020490F4(u32 id, u32 heap);

extern void func_02049B68(void *, u32, u32, u32, u32, u16);

extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);

extern void MI_CpuCopy8(const void *, void *, u32);

extern u32 func_020307B0(void *p);

extern void ARC_TOOL_DeleteHandle(void *);

extern void BG_SYS_SetTileUnit(u32 idx, u32 count, u32 tile);

extern void BG_SYS_FreeLayerBuf(u32 i);

extern u32 WIPE_SYS_EndCheck(void);

extern void DWCi_ScreenDC_FlushRange(void *, int);

extern void func_0207E468(void *, int, int);

extern int GAME_DATA_SaveMain(void *gameData);

extern int GAME_DATA_SaveStart(void *gameData);

extern void *GAME_DATA_GetSaveControl(void *p);

extern void CLACT_VBlankSystem(void);

extern void *PROCSYS_AllocProcWork(void *obj, u32 size, u32 heap);

extern void MI_CpuFill8(void *,u8,u32);

extern void BMP_SetDisplaySwap(u32 swap);

extern void GX_DispOn(void);

extern void BG_SYS_Create(u16 heapId);

extern void BG_SYS_SetVramBanks(const void *c);

extern void BG_SYS_SetGraphicsMode(const void *cfg);

extern void BG_SYS_SetMainVisiblePlanes(u32);

extern void BG_SYS_SetSubVisiblePlanes(u32);

extern void CLACT_InitSystem(const void *cfg, u32 arg, u32 heapId);

extern void *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern void *func_020056A0(void *,void *,int);

extern void *func_02030734(u32,u32,int,const char *,u16);

extern void func_0207D63C(void *,int,int,int,int);

extern void APP_TASKMENU_UpdateMenu(void *);

extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);

extern void CLACT_DrawSystem(void);

extern void WIPE_SetBrightnessFadeOut(unsigned int,unsigned int);

extern void CLACT_DeleteActor(struct ClActor *p);

extern void CLACT_ReleasePalette(u32 i);

extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleaseCellAnim(u32 i);

extern void func_02030EAC(void *n);

extern u32 CLACT_DeleteUnit(void *bank);

extern void CLACT_ExitSystem(void);

extern void BG_SYS_Delete(void);

extern void func_020315D4(void *p);

extern int func_02034AC4(int);

extern void func_02034A5C(int);

extern void GX_LoadBGPltt(const void *, int, int);

extern u32 KEY_GetTrg(void);

extern void GAME_DATA_SaveCancel(void *gameData);

extern void NHTTP_RAP_DeleteConnection(u8 *p);

extern void GFL_USE_CancelChangeAndPlayBgm(int, int);

extern void *func_02009448(void *sys);

extern int NHTTP_RAP_GetResultCode(u8 *p);

extern int NHTTP_RAP_PollConnection(u8 *p);

extern u8 *NHTTP_RAP_GetRecvBuffer(u8 *p);

extern int NHTTP_RAP_CreateRequest(int index, u8 *p);

extern int NHTTP_RAP_GetConnection(char *p);

extern int NHTTP_RAP_StartConnection(u8 *p);

extern int NHTTP_AddPostDataRaw(void *handle, void *value_p, unsigned long length);

extern void func_020092E0(void *obj, u8 value);

extern u8 *func_02012944(void *p);

extern u32 func_0200853C(const void *obj);

extern void *SAVE_CONTROL_GetWorkArea(void *ctrl, int *out);

extern void NHTTP_RAP_Destroy(u8 *p);

extern u8 *NHTTP_RAP_Create(int,int,int);

extern void DWC_RAP_SetErrorCallback(int,int);

extern u32 func_0200FB24(void);

extern int DWC_RAPCOMMON_HandleNetError(int a0, int a1);

extern u32 func_02049658(void *, u32, u32, u32, u32, u32, u16);

extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);

extern void PALANM_BlendColors(u16 *, u16 *, int, u8, u16);

extern void GFL_USE_FadeOutBgm(u32 a);

PdwaccMessageWork *PDWACC_MESSAGE_InitSystem(u32 heap, u32 bank);
void PDWACC_MESSAGE_UpdateSystem(PdwaccMessageWork *work);
void PDWACC_MESSAGE_ExitSystem(PdwaccMessageWork *work);
void PDWACC_MESSAGE_PrintStream(PdwaccMessageWork *work, int msgId);
void PDWACC_MESSAGE_RestartTimeIcon(PdwaccMessageWork *work);
int PDWACC_MESSAGE_UpdateStream(PdwaccMessageWork *work);
void PDWACC_MESSAGE_ClearStream(PdwaccMessageWork *work);
void *PDWACC_MESSAGE_OpenYesNoMenu(PdwaccMessageWork *work, int layout);
void PDWACC_MESSAGE_PrintInWindow(PdwaccMessageWork *work, int msgId);
void PDWACC_MESSAGE_ClearWindow(PdwaccMessageWork *work);
void PDWACC_MESSAGE_PrintNumberWindows(PdwaccMessageWork *work, int value, int unused);
void PDWACC_MESSAGE_DeleteNumberWindows(PdwaccMessageWork *work);

PdwaccDispWork *PDWACC_DISP_Init(int heap);
void PDWACC_DISP_Draw(PdwaccDispWork *disp);
void PDWACC_DISP_Exit(PdwaccDispWork *disp);
void PDWACC_DISP_InitBgLayers(PdwaccDispWork *disp);
void PDWACC_DISP_VBlankTask(void);
void PDWACC_DISP_LoadResources(PdwaccDispWork *disp);
void PDWACC_DISP_PaletteTask(void *unused, PdwaccPaletteAnim *palette);
void PDWACC_DISP_DeleteActors(PdwaccDispWork *disp);
int PDWACC_STATE_HandleHttpError(PdwaccProc *proc, int httpStatus);
void PDWACC_STATE_SetState(PdwaccProc *proc, PdwaccStateFunc state, int line);
void PDWACC_STATE_ChangeState(PdwaccProc *proc, PdwaccStateFunc state, int line);
void PDWACC_STATE_StateWaitFade(PdwaccProc *proc);
void PDWACC_STATE_StateFadeOutBgm(PdwaccProc *proc);
void PDWACC_STATE_StateWaitInputStream(PdwaccProc *proc);
void PDWACC_STATE_StateSaveMainWait(PdwaccProc *proc);
void PDWACC_STATE_StateSaveStart(PdwaccProc *proc);
void PDWACC_STATE_StateRestartTimeIcon(PdwaccProc *proc);
void PDWACC_STATE_StateWaitInputClearWindow(PdwaccProc *proc);
void PDWACC_STATE_StateWaitInputPrintNumbers(PdwaccProc *proc);
void PDWACC_STATE_StatePrintNumbersMessage(PdwaccProc *proc);
void PDWACC_STATE_StateWaitInput(PdwaccProc *proc);
void PDWACC_STATE_StatePrintError(PdwaccProc *proc);
void PDWACC_STATE_StateWaitStreamThenSendRequest(PdwaccProc *proc);
void PDWACC_STATE_StateTimeIconMessage(PdwaccProc *proc);
void PDWACC_STATE_StateConfirmMenuSelect(PdwaccProc *proc);
void PDWACC_STATE_StateOpenConfirmMenu(PdwaccProc *proc);
void PDWACC_STATE_StatePrintIntroMessage(PdwaccProc *proc);
void PDWACC_STATE_StateReceiveResponse(PdwaccProc *proc);
void PDWACC_STATE_StateSendRequest(PdwaccProc *proc);
void PDWACC_STATE_StateWaitFadeClearNumbers(PdwaccProc *proc);
void PDWACC_STATE_StatePrintResultMessage(PdwaccProc *proc);
void PDWACC_STATE_DestroyHttpConnection(PdwaccProc *proc);
int PDWACC_STATE_ProcInit(void *procSys, int unused, PdwaccProcParam *param);
int PDWACC_STATE_ProcMain(int unused0, int unused1, PdwaccProcParam *param, PdwaccProc *proc);
int PDWACC_STATE_ProcExit(int procHandle, int unused0, int unused1, PdwaccProc *proc);

extern char ov067_id[];

extern const u32 gGsyncClactConfig[];

extern unsigned char ov_id[];

extern char ov114_id[];

extern const char d_021DABFC[];

extern const u32 d_021DABCC[];

extern const u32 d_021DABBC[];

extern const struct BgTemplate d_021DA8A8[8];

/*
 * evidence: ov123 021D9D34 callback stub filed and verified before caller rerun.
 * volatile: hardware register 04001000 is read then written at 021D9990/021D9994.
 */
PdwaccDispWork *PDWACC_DISP_Init(int heap)
{
    PdwaccDispWork *disp;
    disp=(PdwaccDispWork *) func_02030734(heap,0xb70,1,d_021DABFC,201);
    disp->heap=heap;
    func_02034AC4((int)ov067_id);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    BMP_SetDisplaySwap(1);
    *(volatile u32 *)0x04001000|=0x10000;
    GX_DispOn();
    BG_SYS_Create(disp->heap);
    CLACT_InitSystem(gGsyncClactConfig,(u32)d_021DABCC,disp->heap);
    disp->clactUnit=CLACT_CreateUnit(40,0,disp->heap);
    BG_SYS_SetVramBanks(d_021DABCC);
    BG_SYS_SetGraphicsMode(d_021DABBC);
    PDWACC_DISP_InitBgLayers(disp);
    PDWACC_DISP_LoadResources(disp);
    disp->vblankTask=func_020056A0(PDWACC_DISP_VBlankTask,disp,0);
    BG_SYS_SetSubVisiblePlanes(31);
    BG_SYS_SetMainVisiblePlanes(27);
    return disp;
}

void PDWACC_DISP_Draw(PdwaccDispWork *disp) { CLACT_DrawSystem(); }

void PDWACC_DISP_Exit(PdwaccDispWork *disp)
{
    int resourceIndex;
    PDWACC_DISP_DeleteActors(disp);
    if (disp->palette.task) {
        func_02030EAC(disp->palette.task);
        disp->palette.task=0;
        disp->palette.enabled=0;
    }
    resourceIndex=0;
    do { if (disp->clactResources[resourceIndex]) CLACT_ReleasePalette((unsigned int)disp->clactResources[resourceIndex]); resourceIndex++; } while(resourceIndex<3);
    for(;resourceIndex<6;resourceIndex++) if (disp->clactResources[resourceIndex]) CLACT_ReleaseCharacter((unsigned int)disp->clactResources[resourceIndex]);
    for(;resourceIndex<9;resourceIndex++) if (disp->clactResources[resourceIndex]) CLACT_ReleaseCellAnim((unsigned int)disp->clactResources[resourceIndex]);
    if (disp->unusedTask) func_02030EAC(disp->unusedTask);
    func_02030EAC(disp->vblankTask);
    CLACT_DeleteUnit(disp->clactUnit);
    CLACT_ExitSystem();
    BG_SYS_SetTileUnit(1,1,0);
    BG_SYS_SetTileUnit(6,1,0);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(4);
    func_02040588(5,0);
    BG_SYS_Delete();
    func_020307B0(disp);
    func_02034A5C((int)ov_id);
}

/*
 * BG-layer init, same shape as GTSNEGO_DISP_InitBgLayers (ov120) with its own template
 * table at 0x021DA8A8 (index order 1,4,3,7,5,0,6,2) and slight per-layer
 * differences in the enable/fill sequence.
 */
void PDWACC_DISP_InitBgLayers(PdwaccDispWork *disp)
{
    struct BgTemplate bgTemplates[8];

    bgTemplates[7] = d_021DA8A8[1];
    BG_SYS_InitBgLayer(0, (const struct BgTemplate *)(&bgTemplates[7]), 0);
    func_02040588(0, 1);
    BG_SYS_PushTile(0);

    bgTemplates[6] = d_021DA8A8[4];
    BG_SYS_InitBgLayer(1, (const struct BgTemplate *)(&bgTemplates[6]), 0);
    func_02040588(1, 1);
    BG_SYS_Init(1, 0, 1, 0);
    BG_SYS_SetTileEntry(1, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(1);

    bgTemplates[5] = d_021DA8A8[3];
    BG_SYS_InitBgLayer(2, (const struct BgTemplate *)(&bgTemplates[5]), 0);
    func_02040588(2, 1);
    BG_SYS_SetTileEntry(2, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(2);

    bgTemplates[4] = d_021DA8A8[7];
    BG_SYS_InitBgLayer(3, (const struct BgTemplate *)(&bgTemplates[4]), 0);
    func_02040588(3, 1);
    BG_SYS_Init(3, 0, 1, 0);
    BG_SYS_SetTileEntry(3, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(3);

    bgTemplates[3] = d_021DA8A8[5];
    BG_SYS_InitBgLayer(4, (const struct BgTemplate *)(&bgTemplates[3]), 0);
    func_02040588(4, 1);
    BG_SYS_PushTile(4);

    bgTemplates[2] = d_021DA8A8[0];
    BG_SYS_InitBgLayer(5, (const struct BgTemplate *)(&bgTemplates[2]), 0);
    func_02040588(5, 1);
    BG_SYS_Init(5, 0, 1, 0);
    BG_SYS_SetTileEntry(5, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(5);

    bgTemplates[1] = d_021DA8A8[6];
    BG_SYS_InitBgLayer(6, (const struct BgTemplate *)(&bgTemplates[1]), 0);
    func_02040588(6, 1);
    BG_SYS_Init(6, 0, 1, 0);
    BG_SYS_SetTileEntry(6, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(6);

    bgTemplates[0] = d_021DA8A8[2];
    BG_SYS_InitBgLayer(7, (const struct BgTemplate *)(&bgTemplates[0]), 0);
    func_02040588(7, 1);
    BG_SYS_Init(7, 0, 1, 0);
    BG_SYS_SetTileEntry(7, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(7);
}

/*
 * leaf: sole blocker of owned ov123 021D9958; parent ownership audit passed.
 * extent: 8-byte tailcall stub; next labelled function 021D9D3C follows.
 */
void PDWACC_DISP_VBlankTask(void)
{
    CLACT_VBlankSystem();
}

/*
 * note 2026-10-05 (wD9r lane50): closed. func_02049658 returns a value (it ends in a call whose r0 it
 *   keeps; ov110 func_021BB328 declares it u32); declared void, it moved the constant 3 into r5 and
 *   tied the late zero arguments to j. The two palette bases are assigned inside the outer loop (mwcc
 *   hoists them after i = 0), and the source row is written inline in the 02021F64 call.
 */
void PDWACC_DISP_LoadResources(PdwaccDispWork *disp)
{
    struct { u8 pad[0xc]; void *data; } *record;
    u16 *base0;
    u16 *base1;
    void *archiveHandle;
    int finished;
    int blendStep;
    int blendRow;
    int rowIndex;
    u16 *srcRow;
    void *allocated;
    int colorIndex;
    int nextRow;
    u16 *dstRow;
    u16 heap;
    archiveHandle = func_020490F4(0x91, disp->heap);
    blendRow = 0;
    func_02049B68(archiveHandle, 3, 4, 0, blendRow, disp->heap);
    func_02049658(archiveHandle, 4, 4, 0, blendRow, blendRow, disp->heap);
    func_020498F4(archiveHandle, 6, 4, 0, blendRow, blendRow, disp->heap);
    func_02049B68(archiveHandle, 3, 0, 0, blendRow, disp->heap);
    func_02049658(archiveHandle, 4, 0, 0, blendRow, blendRow, disp->heap);
    func_020498F4(archiveHandle, 5, 0, 0, blendRow, blendRow, disp->heap);
    func_02049658(archiveHandle, 4, 3, 0, blendRow, blendRow, disp->heap);
    func_020498F4(archiveHandle, 7, 3, 0, blendRow, blendRow, disp->heap);
    heap = disp->heap;
    MI_CpuFill8(&disp->palette, 0, sizeof(disp->palette));
    allocated = func_02049F78(archiveHandle, 2, (u32)&record, heap);
    MI_CpuCopy8(record->data, disp->palette.basePalettes, 0x1e0);
    MI_CpuCopy8(record->data, disp->palette.blendedPalettes, 0x1e0);
    func_020307B0(allocated);
    for (rowIndex = 0; rowIndex < 15; rowIndex++) {
        base1 = (u16 *)disp->palette.blendedPalettes;
        base0 = (u16 *)disp->palette.basePalettes;
        nextRow = rowIndex + 1;
        if (nextRow >= 15) nextRow -= 15;
        blendStep = 0;
        finished = 0;
        srcRow = disp->palette.basePalettes[nextRow] - 8;
        while (1) {
            dstRow = base0 + rowIndex * 16;
            for (colorIndex = 4; colorIndex < 11; colorIndex++) {
                PALANM_BlendColors(dstRow + colorIndex, base1 + blendRow * 16 + colorIndex, 1, (u8)(blendStep >> 8), srcRow[colorIndex + 8]);
            }
            blendRow++;
            if (finished == 1) break;
            blendStep += 0x600;
            if (blendStep >= 0x1000) {
                blendStep = 0x1000;
                finished = 1;
            }
        }
    }
    DWCi_ScreenDC_FlushRange(disp->palette.blendedPalettes, sizeof(disp->palette.blendedPalettes));
    disp->palette.enabled = 1;
    disp->palette.task = func_020056A0((void *)PDWACC_DISP_PaletteTask, &disp->palette, 0x14);
    func_0207D63C((void *)0x04000050, 1, 8, 8, 0x10);
    disp->palette.bgLayer = 0;
    ARC_TOOL_DeleteHandle(archiveHandle);
}

void PDWACC_DISP_PaletteTask(void *unused, PdwaccPaletteAnim *palette)
{
    if (palette->enabled) {
        palette->halfStep^=1;
        if (!(*(volatile u8 *)&palette->halfStep&1)) {
            GX_LoadBGPltt(&palette->blendedPalettes[palette->frame][4],40,14);
            func_0207E468(&palette->blendedPalettes[palette->frame][4],40,14);
            ++palette->frame;
            if (palette->frame>=60) palette->frame=0;
            BG_SYS_FillScrollArea(palette->bgLayer,2,7);
        }
    }
}

/*
 * lever: A named unsigned cursor q preserves counter r4 and cursor r5.
 */
void PDWACC_DISP_DeleteActors(PdwaccDispWork *disp) { int slotIndex; unsigned int actorCursor; for(slotIndex=0;slotIndex<PDWACC_ACTOR_COUNT;slotIndex++) { actorCursor=(unsigned int)disp+(unsigned)slotIndex*4; if(((PdwaccDispWork *)actorCursor)->actors[0]) { CLACT_DeleteActor(((PdwaccDispWork *)actorCursor)->actors[0]); ((PdwaccDispWork *)actorCursor)->actors[0]=0; } } }

/*
 * extent: lead with store-and-return follower 021DA030 and tailcall follower 021DA034.
 */
int PDWACC_STATE_HandleHttpError(PdwaccProc *proc, int resultCode)
{
    switch (resultCode) {
    case 503:
        proc->errorCode=0xfff1;
        PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StatePrintError,0x99);
        return 1;
    case 502:
        proc->errorCode=0xfff2;
        PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StatePrintError,0x9d);
        return 1;
    default:
        if (resultCode>=400) {
            proc->errorCode=0xfff3;
            PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StatePrintError,0xa3);
            return 1;
        }
        return 0;
    }
}

void PDWACC_STATE_SetState(PdwaccProc *proc, PdwaccStateFunc state, int line)
{
    proc->state=state;
}

void PDWACC_STATE_ChangeState(PdwaccProc *proc, PdwaccStateFunc state, int line)
{
    PDWACC_STATE_SetState(proc,state,line);
}

void PDWACC_STATE_StateWaitFade(PdwaccProc *proc)
{
    if (WIPE_SYS_EndCheck() != 0)
        PDWACC_STATE_ChangeState(proc, 0, 0xd5);
}

void PDWACC_STATE_StateFadeOutBgm(PdwaccProc *proc) { WIPE_SYS_Start(0,0,0,0x7fff,6,1,proc->heap); GFL_USE_FadeOutBgm(6); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateWaitFade,0xe7); }

void PDWACC_STATE_StateWaitInputStream(PdwaccProc *proc) { if(PDWACC_MESSAGE_UpdateStream(proc->message) && KEY_GetTrg()!=0) PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateFadeOutBgm,0xf1); }

/*
 * lever: Unsigned result-minus-two range test emits subs/cmp/bhi.
 */
void PDWACC_STATE_StateSaveMainWait(PdwaccProc *proc) { if((unsigned int)(GAME_DATA_SaveMain(proc->gameData)-2)<=1) { proc->saving=0; PDWACC_MESSAGE_PrintStream(proc->message,11); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateWaitInputStream,0xfe); } }

void PDWACC_STATE_StateSaveStart(PdwaccProc *proc) { if(PDWACC_MESSAGE_UpdateStream(proc->message)) { proc->saving=1; GAME_DATA_SaveStart(proc->gameData); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateSaveMainWait,0x109); } }

void PDWACC_STATE_StateRestartTimeIcon(PdwaccProc *proc) { PDWACC_MESSAGE_PrintStream(proc->message,6); PDWACC_MESSAGE_RestartTimeIcon(proc->message); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateSaveStart,0x112); }

void PDWACC_STATE_StateWaitInputClearWindow(PdwaccProc *proc) { if(KEY_GetTrg()) { PDWACC_MESSAGE_ClearWindow(proc->message); func_020092E0(func_02009448(proc->saveControl),1); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateRestartTimeIcon,0x11a); } }

void PDWACC_STATE_StateWaitInputPrintNumbers(PdwaccProc *proc) { if(KEY_GetTrg()) { PDWACC_MESSAGE_PrintNumberWindows(proc->message,proc->profileId,proc->profileId); PDWACC_MESSAGE_PrintInWindow(proc->message,9); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateWaitInputClearWindow,0x12a); } }

void PDWACC_STATE_StatePrintNumbersMessage(PdwaccProc *proc) { PDWACC_MESSAGE_PrintNumberWindows(proc->message,proc->profileId,proc->profileId); PDWACC_MESSAGE_PrintInWindow(proc->message,8); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateWaitInputPrintNumbers,0x13c); }

void PDWACC_STATE_StateWaitInput(PdwaccProc *proc) { if(KEY_GetTrg() & 3) PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateFadeOutBgm,0x14b); }

void PDWACC_STATE_StatePrintError(PdwaccProc *proc)
{
    unsigned messageId;
    messageId = proc->errorCode + 11;
    if (proc->connection) NHTTP_RAP_DeleteConnection(proc->connection);
    if (proc->errorCode == 0xfff1) messageId = 22;
    else if (proc->errorCode == 0xfff2) messageId = 23;
    else if (proc->errorCode == 0xfff3) messageId = 20;
    else if (proc->errorCode >= 10) messageId = 20;
    PDWACC_MESSAGE_PrintInWindow(proc->message,messageId);
    PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateWaitInput,0x167);
}

void PDWACC_STATE_StateWaitStreamThenSendRequest(PdwaccProc *proc) { if(PDWACC_MESSAGE_UpdateStream(proc->message)) PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateSendRequest,0x172); }

void PDWACC_STATE_StateTimeIconMessage(PdwaccProc *proc) { PDWACC_MESSAGE_PrintStream(proc->message,3); PDWACC_MESSAGE_RestartTimeIcon(proc->message); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateWaitStreamThenSendRequest,0x17b); }

void PDWACC_STATE_StateConfirmMenuSelect(PdwaccProc *proc)
{
    if (APP_TASKMENU_IsFinish(proc->yesNoMenu)) {
        if (!APP_TASKMENU_GetCursorPos(proc->yesNoMenu))
            PDWACC_STATE_ChangeState(proc, PDWACC_STATE_StateTimeIconMessage, 0x18d);
        else
            PDWACC_STATE_ChangeState(proc, PDWACC_STATE_StateFadeOutBgm, 0x190);
        PDWACC_MESSAGE_ClearStream(proc->message);
        APP_TASKMENU_CloseMenu(proc->yesNoMenu);
        proc->yesNoMenu = 0;
    }
}

void PDWACC_STATE_StateOpenConfirmMenu(PdwaccProc *proc) { if(PDWACC_MESSAGE_UpdateStream(proc->message)) { proc->yesNoMenu=PDWACC_MESSAGE_OpenYesNoMenu(proc->message,0); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateConfirmMenuSelect,0x1a6); } }

void PDWACC_STATE_StatePrintIntroMessage(PdwaccProc *proc) { PDWACC_MESSAGE_PrintStream(proc->message,2); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateOpenConfirmMenu,0x1b7); }

void PDWACC_STATE_StateReceiveResponse(PdwaccProc *proc)
{
    int *response;
    if (GFL_NET_GetRunState() && !PDWACC_STATE_HandleHttpError(proc,NHTTP_RAP_GetResultCode(proc->connection)) && !NHTTP_RAP_PollConnection(proc->connection)) {
        response = (int *)(char *)NHTTP_RAP_GetRecvBuffer((u8 *)(proc->connection));
        PDWACC_MESSAGE_ClearStream(proc->message);
        if (*response == 2) { PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StatePrintNumbersMessage,0x1d4); return; }
        if (*response == 0) { PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StatePrintNumbersMessage,0x1d7); return; }
        proc->errorCode = *response;
        PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StatePrintError,0x1db);
    }
}

/*
 *   in scratch blocker071d8-r1.log, 12 bytes. the integrator owns filing it.
 *   extern unsigned BACKUP_SYSTEM_GetWork(void *, unsigned *);
 * evidence: 0x021B973C ov114 Thumb leaf now has S23's verified EXACT
 *   pkt_ov114_021B973C shard; no caller retry because ARM9 still blocks it.
 */
void PDWACC_STATE_StateSendRequest(PdwaccProc *proc)
{
    int workAreaSize;
    unsigned workArea;
    if (GFL_NET_GetRunState()) {
        if (NHTTP_RAP_CreateRequest(9,proc->connection)) {
            workArea = (unsigned int)SAVE_CONTROL_GetWorkArea(proc->saveControl,&workAreaSize);
            NHTTP_AddPostDataRaw((void *)NHTTP_RAP_GetConnection(proc->connection),(void *)workArea,0x80000);
            if (!NHTTP_RAP_StartConnection(proc->connection)) {
                PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateReceiveResponse,0x1f6);
                return;
            }
        }
    } else if (KEY_GetTrg()) {
        PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateReceiveResponse,0x1fc);
    }
}

void PDWACC_STATE_StateWaitFadeClearNumbers(PdwaccProc *proc) { if(WIPE_SYS_EndCheck() && KEY_GetTrg()) { PDWACC_MESSAGE_DeleteNumberWindows(proc->message); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateFadeOutBgm,0x22c); } }

void PDWACC_STATE_StatePrintResultMessage(PdwaccProc *proc) { PDWACC_MESSAGE_PrintNumberWindows(proc->message,proc->profileId,proc->profileId); PDWACC_MESSAGE_PrintInWindow(proc->message,7); PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StateWaitFadeClearNumbers,0x23c); }

void PDWACC_STATE_DestroyHttpConnection(PdwaccProc *proc) { if(proc->connection) { NHTTP_RAP_DeleteConnection(proc->connection); NHTTP_RAP_Destroy(proc->connection); proc->connection=0; } }

/*
 * interface: 0203159C retains the allocator result in r0; caller consumes that return.
 */
int PDWACC_STATE_ProcInit(void *procSys,int unused,PdwaccProcParam *param)
{
    PdwaccProc *proc;
    func_02034AC4((int)ov114_id);
    proc=(PdwaccProc *) PROCSYS_AllocProcWork(procSys,0x74,param->heap);
    MI_CpuFill8(proc,0,0x74);
    proc->heap=param->heap;
    proc->saveControl=GAME_DATA_GetSaveControl(param->gameData);
    proc->gameData=param->gameData;
    proc->profileId=func_0200853C((const void *)func_02012944(param->gameData));
    if(GFL_NET_GetRunState()) {
        proc->connection=NHTTP_RAP_Create(param->heap,proc->profileId,param->connectionArg);
        DWC_RAP_SetErrorCallback((int)PDWACC_STATE_DestroyHttpConnection,(int)proc);
    }
    proc->disp=PDWACC_DISP_Init(proc->heap);
    proc->message=PDWACC_MESSAGE_InitSystem(proc->heap,87);
    WIPE_SYS_Start(0,1,1,0,6,1,proc->heap);
    GFL_USE_CancelChangeAndPlayBgm(0x483,0xffff);
    switch(param->startMode) {
    case 0: PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StatePrintIntroMessage,0x276); break;
    case 1: PDWACC_STATE_ChangeState(proc,PDWACC_STATE_StatePrintResultMessage,0x279); break;
    }
    param->finished=0;
    return 1;
}

int PDWACC_STATE_ProcMain(int unused0,int unused1,PdwaccProcParam *param,PdwaccProc *proc)
{
    PdwaccStateFunc state;
    int result;
    state = proc->state;
    result = 1;
    if (state) {
        if (!func_0200FB24()) state(proc);
        result = 0;
    }
    if (proc->yesNoMenu) APP_TASKMENU_UpdateMenu(proc->yesNoMenu);
    PDWACC_DISP_Draw(proc->disp);
    PDWACC_MESSAGE_UpdateSystem(proc->message);
    if (WIPE_SYS_EndCheck()) {
        if (func_0200FB24()) {
            NHTTP_RAP_DeleteConnection(proc->connection);
            if (proc->saving) {
                GAME_DATA_SaveCancel(proc->gameData);
                proc->saving = 0;
            }
            WIPE_SetBrightnessFadeOut(0,0);
            WIPE_SetBrightnessFadeOut(1,0);
            result = 1;
            DWC_RAPCOMMON_HandleNetError(1,0);
            param->finished = 1;
        }
    } else if (func_0200FB24()) result = 1;
    return result;
}

int PDWACC_STATE_ProcExit(int procHandle, int unused0, int unused1, PdwaccProc *proc)
{
    if (proc->yesNoMenu)
        APP_TASKMENU_CloseMenu(proc->yesNoMenu);
    PDWACC_MESSAGE_ExitSystem(proc->message);
    PDWACC_DISP_Exit(proc->disp);
    if (proc->unusedAlloc04)
        func_020307B0(proc->unusedAlloc04);
    if (proc->unusedAlloc24)
        func_020307B0(proc->unusedAlloc24);
    if (proc->connection) {
        NHTTP_RAP_Destroy(proc->connection);
        proc->connection = 0;
    }
    if (GFL_NET_GetRunState())
        DWC_RAP_SetErrorCallback(0, 0);
    func_020315D4((void *)procHandle);
    func_02034A5C((int)ov114_id);
    return 1;
}
