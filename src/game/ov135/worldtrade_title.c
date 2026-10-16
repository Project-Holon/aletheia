/*
 * file:     worldtrade_title.c
 * unit:     yes
 * function: WORLDTRADE_TITLE_Init, WORLDTRADE_TITLE_CallStateHandler, WORLDTRADE_TITLE_Exit, WORLDTRADE_TITLE_SetupBgPlanes, WORLDTRADE_TITLE_ScrollBg, WORLDTRADE_TITLE_ExitBgPlanes, WORLDTRADE_TITLE_ExitBgPlanesSub, WORLDTRADE_TITLE_SetBgVisible, WORLDTRADE_TITLE_LoadBgGraphics, WORLDTRADE_TITLE_CreateActors, WORLDTRADE_TITLE_DeleteActors, WORLDTRADE_TITLE_CreateWindows, WORLDTRADE_TITLE_DeleteWindows, WORLDTRADE_TITLE_CreateStrings, WORLDTRADE_TITLE_DeleteStrings, WORLDTRADE_TITLE_StateHideForExit, WORLDTRADE_TITLE_StateAdvance, WORLDTRADE_TITLE_StateStartWipeIn, WORLDTRADE_TITLE_StateWaitWipeIn, WORLDTRADE_TITLE_StateWaitWipeInAlt, WORLDTRADE_TITLE_StateStartCursorAnim, WORLDTRADE_TITLE_HitTestMenu, WORLDTRADE_TITLE_HandleSelection, WORLDTRADE_TITLE_StateMainInput, WORLDTRADE_TITLE_StateRequestExit, WORLDTRADE_TITLE_StateWaitActive, WORLDTRADE_TITLE_StateStartWipeOut, WORLDTRADE_TITLE_StateOpenConfirm, WORLDTRADE_TITLE_StateConfirmYesNoInput, WORLDTRADE_TITLE_StateUpdateCursorAnim, WORLDTRADE_TITLE_StateWaitMessage, WORLDTRADE_TITLE_StateWaitMessageTimed, WORLDTRADE_TITLE_DrawMenuLabels, WORLDTRADE_TITLE_PrintMessage, WORLDTRADE_TITLE_PrintMessageSub, WORLDTRADE_TITLE_PrintBankString, WORLDTRADE_TITLE_LoadMainBgSwap, WORLDTRADE_TITLE_LoadSubBgSwap, WORLDTRADE_TITLE_CreateMenuWindow
 * address:  0x021FFDA8
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
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   WORLDTRADE_TITLE_ScrollBg 0x021FFFE8 thumb ov135
 *   WORLDTRADE_SUBLCD_SetSlotActorPositions 0x021FFD44 thumb ov135
 *   GXx_GetMasterBrightness_ 0x0207D55C arm
 *   WORLDTRADE_ENTER_RestartNetTimeout 0x021F9254 thumb ov135
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
 *   func_02049B68 0x02049B68 arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   WORLDTRADE_TITLE_LoadMainBgSwap 0x02200AB4 thumb ov135
 *   WORLDTRADE_TITLE_LoadSubBgSwap 0x02200B34 thumb ov135
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   UI_GetInputMode  0x020355C4  arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   WORLDTRADE_TITLE_CreateMenuWindow  0x02200BAC  thumb
 *   WORLDTRADE_ADAPTER_DeletePrintStream 0x02202940 thumb ov135
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORLDTRADE_ADAPTER_IsStreamDone  0x02202840  thumb  ov135
 *   BMP_WIN_GetBmp   0x02045770  arm
 *   BMP_Clear   0x02043B5C  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   WORLDTRADE_ADAPTER_QueuePrintDefaultColor  0x02202858  thumb  ov135
 *   func_02045CAC  0x02045CAC  arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   WORLDTRADE_ADAPTER_PrintQueColor  0x022028C8  thumb
 *   TOUCHPANEL_HitTrg  0x02035C08  arm  arm9
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm  arm9
 *   CLACT_IsActorAnimActive  0x0204B98C  arm  arm9
 *   CLACT_RestartActorAnim  0x0204B9A0  arm  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm  arm9
 *   WORLDTRADE_ClearBusyFlag  0x021F4EC8  thumb  ov135
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb
 *   WORLDTRADE_SetActorPos  0x021F4FF4  thumb
 *   func_020355D8  0x020355D8  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm  arm9
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   WORLDTRADE_UpdateTaskMenuYesNo 0x021F4D14 thumb ov135
 *   WORLDTRADE_CloseTaskMenu 0x021F4CE4 thumb ov135
 *   BG_SYS_SetFlagField06  0x02041B6C  arm
 *   BMP_WIN_ClearScreen   0x020456F8  arm
 *   WORLDTRADE_OpenTaskMenuYesNoDefault  0x021F4BE0  thumb  ov135
 *   g_02203E58  0x02203E58  data  ov135
 *   g_02203914  0x02203914  data  ov135
 *   g_022039A4  0x022039A4  data  ov135
 *   g_02203984  0x02203984  data  ov135
 *   g_022039C4  0x022039C4  data  ov135
 *   BG_SYS_ClearLayerEx  0x02041570  arm
 *   g_02203944  0x02203944  data  ov135
 *   g_02203924  0x02203924  data  ov135
 *   g_02203964  0x02203964  data  ov135
 *   g_022039E4  0x022039E4  data  ov135
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   d_022038E0 0x022038E0 data a2
 *   WORLDTRADE_ClearSelectedSpecies 0x021F4F90 thumb ov135
 *   g_022038EC  0x022038EC  data  ov135
 *   WORLDTRADE_QueryGameData 0x021F4ED4 thumb ov135
 *   tbl_022038E0   0x022038E0  data  a2
 *   d_022038FC 0x022038FC data a4
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandleExt 0x020499D4 arm
 *   WORLDTRADE_INPUT_PrintCentered  0x021F9218  thumb
 *   WORLDTRADE_SUBLCD_StartAnimTaskA 0x021FF8B0 thumb ov135
 *   WORLDTRADE_SUBLCD_StartAnimTaskB 0x021FF9E0 thumb ov135
 *   WORLDTRADE_SUBLCD_UpdateSlotAnims 0x021FFBC8 thumb ov135
 */
#include "worldtrade_types.h"

extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);

extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);

extern void STRBUF_Delete(struct U16Vec *vec);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);

extern void BG_SYS_SetSubVisiblePlanes(u32 a);

extern void WORLDTRADE_ENTER_RestartNetTimeout(u8 *);

extern u32 BG_SYS_GetSubVisiblePlanes(void);

extern void BG_SYS_ClearSlot(u32 i);

extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);

extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);

extern void BG_SYS_ClearLayerEx(int channel, u16 val);

extern void BG_SYS_FreeLayerBuf(u32 i);

extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e);

extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void ARC_UTIL_UploadBgPaletteFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);

extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

extern u8 UI_GetInputMode(void);

extern void CLACT_DeleteActor(struct Obj *p);

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern void CLACT_RestartActorAnim(struct Actor *a);

extern void func_020355D8(u8 v);

extern u32 KEY_GetTrg(void);

extern u32 CLACT_IsActorAnimActive(struct Actor *a);


extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);

extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);

extern void WORLDTRADE_ClearBusyFlag(Work *p);

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

extern void BG_SYS_PushTile(u32 layer);

extern void WORLDTRADE_SetActorPos(u32 a, u32 b, u32 c);

extern void CLACT_SetActorDrawEnable(struct Obj *obj, unsigned int on);

extern void CLACT_SetActorAutoAnim(struct Obj *,u32);

extern int WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);

extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);

extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);

extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);

extern void ARC_TOOL_DeleteHandle(void *);

extern void WORLDTRADE_SetNextState(void *p, u32 a, u32 b);

extern void WORLDTRADE_SetStateAndReturn(void *p, u32 a, u32 b);

extern void GFL_USE_PlaySeDefaultVolume(unsigned);

extern int WORLDTRADE_UpdateTaskMenuYesNo(char *p);

extern void WORLDTRADE_CloseTaskMenu(char *p);

extern void BMP_MENUWORK_DrawWindowBorder(void *p, unsigned kind);





extern int GXx_GetMasterBrightness_(vu16 *reg);

extern void BG_SYS_SetFlagField06(u32 v);


extern void BMP_WIN_ClearScreen(struct Descriptor *d);

extern int TOUCHPANEL_HitTrg(const void *);

extern unsigned WIPE_SYS_EndCheck(void);

extern void WORLDTRADE_OpenTaskMenuYesNoDefault(u32 a, u32 b, u32 c, u32 d, u8 e);

extern void BG_SYS_FreeLayerBuf(unsigned);

extern void WORLDTRADE_ClearSelectedSpecies(void *);

extern int WORLDTRADE_QueryGameData(void);


extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);

extern u32 ARC_UTIL_UploadBgPaletteAddFromHandleExt(void *, u32, u32, u32, u32, u32, u32, u16);

extern void WORLDTRADE_INPUT_PrintCentered(void *win, void *bank, int idx, void *g);

void WORLDTRADE_SUBLCD_StartAnimTaskA(Work *p);

void WORLDTRADE_SUBLCD_StartAnimTaskB(Work *p);

void WORLDTRADE_SUBLCD_UpdateSlotAnims(Work *p);

void WORLDTRADE_SUBLCD_SetSlotActorPositions(Work *p);

int WORLDTRADE_TITLE_Init(Work *p);

void WORLDTRADE_TITLE_CallStateHandler(u8 *p);

int WORLDTRADE_TITLE_Exit(Work *p);

void WORLDTRADE_TITLE_SetupBgPlanes(void);

void WORLDTRADE_TITLE_ScrollBg(Work *p, u32 a, u32 b);

void WORLDTRADE_TITLE_ExitBgPlanes(Work *p);

void WORLDTRADE_TITLE_ExitBgPlanesSub(void);

void WORLDTRADE_TITLE_SetBgVisible(Work *p);

void WORLDTRADE_TITLE_LoadBgGraphics(Work *a0);

void WORLDTRADE_TITLE_CreateActors(Work *p);

void WORLDTRADE_TITLE_DeleteActors(Work *p);

void WORLDTRADE_TITLE_CreateWindows(u8 *p);

void WORLDTRADE_TITLE_DeleteWindows(u8 *p);

void WORLDTRADE_TITLE_CreateStrings(Work *p);

void WORLDTRADE_TITLE_DeleteStrings(Work *p);

int WORLDTRADE_TITLE_StateHideForExit(Work *p);

int WORLDTRADE_TITLE_StateAdvance(u8 *p);

int WORLDTRADE_TITLE_StateStartWipeIn(Work *p);

int WORLDTRADE_TITLE_StateWaitWipeIn(Work *p);

int WORLDTRADE_TITLE_StateWaitWipeInAlt(Work *p);

int WORLDTRADE_TITLE_StateStartCursorAnim(Work *p);

int WORLDTRADE_TITLE_HitTestMenu(void);

void WORLDTRADE_TITLE_HandleSelection(Work *p, int mode);

int WORLDTRADE_TITLE_StateMainInput(Work *p);

int WORLDTRADE_TITLE_StateRequestExit(Work *p);

int WORLDTRADE_TITLE_StateWaitActive(Work *p);

int WORLDTRADE_TITLE_StateStartWipeOut(Work *p);

int WORLDTRADE_TITLE_StateOpenConfirm(Work *p);

int WORLDTRADE_TITLE_StateConfirmYesNoInput(Work *p);

int WORLDTRADE_TITLE_StateUpdateCursorAnim(Work *p);

int WORLDTRADE_TITLE_StateWaitMessage(u8 *p);

int WORLDTRADE_TITLE_StateWaitMessageTimed(u8 *p);

void WORLDTRADE_TITLE_DrawMenuLabels(Work *p);

void WORLDTRADE_TITLE_PrintMessage(u8 *p, u32 n, int a2, int a3, int a4);

void WORLDTRADE_TITLE_PrintMessageSub(u8 *p, int k, int a2, int a3, int a4);

void WORLDTRADE_TITLE_PrintBankString(void *p,void *bank,u32 b,u32 id,u32 fifth,void *out,u16 se);

void WORLDTRADE_TITLE_LoadMainBgSwap(Work *p);

void WORLDTRADE_TITLE_LoadSubBgSwap(Work *p);

void WORLDTRADE_TITLE_CreateMenuWindow(Work *p, u32 k);

u32 WORLDTRADE_ADAPTER_IsStreamDone(PrintStreamCtx *p);

u32 WORLDTRADE_ADAPTER_QueuePrintDefaultColor(void *p,u8 b,void *s,u32 x,u32 y,void *out);

u32 WORLDTRADE_ADAPTER_PrintQueColor(void *win, u8 z, u32 str, u32 x, u32 y, u32 z2, u16 color, Printer *g);

void WORLDTRADE_ADAPTER_DeletePrintStream(struct Obj *p);

extern void (*g_02203E58[])(u8 *);

extern struct DispConfig g_02203914;

extern struct BgTemplate g_022039A4;

extern struct BgTemplate g_02203984;

extern struct BgTemplate g_022039C4;

extern struct BgTemplate g_02203944;

extern struct BgTemplate g_02203924;

extern struct BgTemplate g_02203964;

extern struct BgTemplate g_022039E4;

extern const Pos d_022038E0[];

extern char g_022038EC[];

extern const Pos tbl_022038E0[];

extern const u32 d_022038FC[][3];

/*
 * volatile: hardware display control 0x04000304 read and written at 0x021FFDB6..0x021FFDBA.
 */
int WORLDTRADE_TITLE_Init(Work *p)
{
    u32 control;
    WORLDTRADE_TITLE_CreateStrings(p);
    control=*(volatile u16 *)0x04000304;
    control &= ~0x8000;
    *(volatile u16 *)0x04000304=control;
    WORLDTRADE_TITLE_SetupBgPlanes();
    WORLDTRADE_TITLE_LoadBgGraphics(p);
    WORLDTRADE_TITLE_CreateWindows((u8 *)p);
    WORLDTRADE_TITLE_ScrollBg(p,0,0);
    WORLDTRADE_TITLE_LoadMainBgSwap(p);
    if(p->x30==0) BG_SYS_SetPlaneVisible(4,0);
    else {WORLDTRADE_TITLE_LoadSubBgSwap(p);BG_SYS_SetPlaneVisible(4,1);}
    WORLDTRADE_TITLE_CreateMenuWindow(p,0);
    p->f12E4=0;
    WORLDTRADE_TITLE_CreateActors(p);
    WORLDTRADE_ENTER_RestartNetTimeout((u8 *)p);
    WORLDTRADE_TITLE_DrawMenuLabels((Work *)p);
    if(p->x30==0) {
        WORLDTRADE_TITLE_SetBgVisible(p);
        WIPE_SYS_Start(0,1,1,0,6,1,0x48);
        p->state=0;
        p->x30=1;
        WORLDTRADE_SUBLCD_StartAnimTaskA(p);
    } else {
        if(p->eb4==1 && GXx_GetMasterBrightness_((u16 *)0x0400106C)!=0) {
            WORLDTRADE_SUBLCD_SetSlotActorPositions(p);
            WIPE_SYS_Start(0,1,1,0,6,1,0x48);
        } else WIPE_SYS_Start((void *)3,1,1,0,6,1,0x48);
        p->state=5;
    }
    p->eb4=0;
    WORLDTRADE_SUBLCD_UpdateSlotAnims(p);
    return 1;
}

/*
 * State-table dispatch through the table at 0x02203E58.
 */
void WORLDTRADE_TITLE_CallStateHandler(u8 *p)
{
    g_02203E58[*(u32 *)(p + 0x28)](p);
}

int WORLDTRADE_TITLE_Exit(Work *p)
{
    WORLDTRADE_TITLE_DeleteActors(p);
    WORLDTRADE_TITLE_DeleteStrings(p);
    WORLDTRADE_TITLE_DeleteWindows((u8 *)p);
    WORLDTRADE_TITLE_ExitBgPlanesSub();
    if (p->x14 == 4 || p->x14 == 5) p->f12E4 = 1;
    WORLDTRADE_TITLE_ExitBgPlanes(p);
    CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)(void * *)&p->fD38, 0);
    WORLDTRADE_ClearBusyFlag(p);
    return 0;
}

/*
 * Three-layer bring-up with layer 0's tilemap cleared and plane 0x10 turned
 * on through both 020434DC and 02043598.
 */
void WORLDTRADE_TITLE_SetupBgPlanes(void)
{
    struct DispConfig c = g_02203914;
    u32 v = BG_SYS_GetSubVisiblePlanes();

    BG_SYS_SetGraphicsMode(&c);
    BG_SYS_SetSubVisiblePlanes(v);
    {
        struct BgTemplate t = g_022039A4;
        BG_SYS_InitBgLayer(0, &t, 0);
    }
    BG_SYS_ClearSlot(0);
    BG_SYS_SetPlaneVisible(0, 1);
    {
        struct BgTemplate t = g_02203984;
        BG_SYS_InitBgLayer(1, &t, 0);
    }
    BG_SYS_SetPlaneVisible(1, 1);
    {
        struct BgTemplate t = g_022039C4;
        BG_SYS_InitBgLayer(2, &t, 0);
    }
    BG_SYS_SetPlaneVisible(2, 1);
    BG_SYS_InitRun(0, 0x20, 0, 0x48);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

/*
 * One-shot bring-up of layers 4..7 gated on the field at p+0x12e0: the
 * layer-4 clear, the layer-6 clear only when the second argument is zero,
 * layer 5 with its second word taken from the first argument, layer 7, then
 * the four enables.  The four templates are declared together in use order,
 * which is what fixes the stack slots to 0x60/0x40/0x20/0x00.
 */
void WORLDTRADE_TITLE_ScrollBg(Work *p, u32 a, u32 b)
{
    if (p->f12E0 == 0) {
        struct BgTemplate t4;
        struct BgTemplate t6;
        struct BgTemplate t5;
        struct BgTemplate t7;

        p->f12E0 = 1;
        t4 = g_02203944;
        BG_SYS_InitBgLayer(4, &t4, 0);
        BG_SYS_ClearLayerEx(4, 0);
        t6 = g_02203924;
        BG_SYS_InitBgLayer(6, &t6, 0);
        if (b == 0) {
            BG_SYS_ClearLayerEx(6, 0);
        }
        t5 = g_02203964;
        t5.unk_04 = a;
        BG_SYS_InitBgLayer(5, &t5, 0);
        BG_SYS_InitRun(4, 0x20, 0, 0x48);
        t7 = g_022039E4;
        BG_SYS_InitBgLayer(7, &t7, 0);
        BG_SYS_ClearLayerEx(7, 0);
    }
    BG_SYS_SetPlaneVisible(4, 1);
    BG_SYS_SetPlaneVisible(5, 1);
    BG_SYS_SetPlaneVisible(6, 1);
    BG_SYS_SetPlaneVisible(7, 1);
}

void WORLDTRADE_TITLE_ExitBgPlanes(Work *p) {if(p->f12E0==1 && p->f12E4==0) {p->f12E0=0;BG_SYS_FreeLayerBuf(6);BG_SYS_FreeLayerBuf(5);BG_SYS_FreeLayerBuf(4);BG_SYS_FreeLayerBuf(7);}}

/*
 * Poke channels 2, 1 and 0 in that order.
 */
void WORLDTRADE_TITLE_ExitBgPlanesSub(void)
{
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(0);
}

void WORLDTRADE_TITLE_SetBgVisible(Work *p) {BG_SYS_SetMainPlaneVisible(1,0);BG_SYS_SetMainPlaneVisible(2,0);BG_SYS_SetMainPlaneVisible(4,0);CLACT_SetActorDrawEnable(*(struct Obj * *)&p->cursor_p,0);}

/*
 * Straight-line six-argument window setup over a 0x60x0x48 handle: the
 * handle open, three B40/B68 window calls, two F5BC text calls and two
 * 498F4 draws, ending with the 49238 release.  No parameters.
 */
void WORLDTRADE_TITLE_LoadBgGraphics(Work *a0)
{
    void *h = ARC_TOOL_CreateHandle(0x60, 0x48);

    func_02049B68(h, 3, 0, 0, 0x60, 0x48);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    BMP_MENUWORK_LoadCharAndPltt(0, 1, 0xe, 0, 0x48);
    BMP_MENUWORK_LoadCharAndPltt(0, 0x1f, 0xb, 0, 0x48);
    ARC_UTIL_UploadBgCharFromHandle(h, 0xd, 1, 0, 0, 1, 0x48);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 0x20, 1, 0, 0x600, 1, 0x48);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 0x1f, 2, 0, 0x600, 1, 0x48);
    ARC_TOOL_DeleteHandle(h);
}

void WORLDTRADE_TITLE_CreateActors(Work *p)
{
    ObjPos pos;
    pos.x = d_022038E0[p->sel].x;
    pos.y = d_022038E0[p->sel].y;
    pos.z = 0;
    pos.pri = 0;
    pos.f7 = 1;
    p->cursor_p = CLACT_CreateActor(p->res, (unsigned int)p->set2, (unsigned int)p->set[1], (unsigned int)p->set3, &pos, 0, 0x48);
    CLACT_SetActorAutoAnim(p->cursor_p, 1);
    CLACT_SetActorAnimSeq(p->cursor_p, 0);
    if (UI_GetInputMode() == 1) {
        CLACT_SetActorDrawEnable(p->cursor_p, 0);
    } else {
        CLACT_SetActorAnimSeq(p->cursor_p, 0);
        CLACT_SetActorDrawEnable(p->cursor_p, 1);
    }
    GFL_NET_RestartWithDefaultTimeout(0, 0x48);
}

/*
 * Tail call into CLACT_DeleteActor with the pointer held at +0xbf4.
 */
void WORLDTRADE_TITLE_DeleteActors(Work *p)
{
    CLACT_DeleteActor((struct Obj *)(p->cursor));
}

/*
 * lever: full-word int cast on the window-read address breaks the loop register tie; unsigned base/index addition happens before the cast.
 */
void WORLDTRADE_TITLE_CreateWindows(u8 *p)
{
    int i;
    u32 w;
    ((Work *)p)->fD48=(void *)BMP_WIN_Create(1,(u8)2,(u8)1,(u8)0x1C,2,1,(u16)1);
    BMP_Clear(BMP_WIN_GetBmp(((Work *)p)->fD48),0xA);
    w=*(u32 *)&((Work *)p)->fD48;
    BMP_WIN_TransferChars((void *)w); BMP_WIN_MakeScreen((void *)w); BG_SYS_PushTile(BMP_WIN_GetBgLayer((void *)w));
    WORLDTRADE_ADAPTER_PrintQueColor((void *)(((Work *)p)->fD48), 0, (u32)((Work *)p)->fB8C, 0, 2, 0, 0x35CA, (Printer *)(p+0xFA0));
    for(i=0;i<3;i++) {
        u32 window;
        *(void **)((u32)p+i*4+0xD50)=(void *)BMP_WIN_Create(1,(u8)9,(u8)(i*5+6),(u8)0xF,2,1,(u16)1);
        BMP_Clear(BMP_WIN_GetBmp(*(void **)((int)((u32)p+i*4)+0xD50)),1);
        window=*(u32 *)((u32)p+i*4+0xD50);
        BMP_WIN_TransferChars((void *)window); BMP_WIN_MakeScreen((void *)window); BG_SYS_PushTile(BMP_WIN_GetBgLayer((void *)window));
    }
    ((Work *)p)->d40=(void *)BMP_WIN_Create(0,(u8)2,(u8)0x15,(u8)0x1B,2,0xD,(u16)1);
    BMP_Clear(BMP_WIN_GetBmp(((Work *)p)->d40),0xF);
    ((Work *)p)->dd0=(void *)BMP_WIN_Create(0,(u8)2,(u8)0x13,(u8)0x1B,4,0xD,(u16)1);
    BMP_Clear(BMP_WIN_GetBmp(((Work *)p)->dd0),0xF);
}

void WORLDTRADE_TITLE_DeleteWindows(u8 *p)
{
    int i;
    WORLDTRADE_ADAPTER_DeletePrintStream((struct Obj *)((struct Obj *)(p + 0xFA0)));
    BMP_WIN_Delete(((Work *)p)->fDE0);
    BMP_WIN_Delete(((Work *)p)->dd0);
    BMP_WIN_Delete(((Work *)p)->d40);
    for (i = 0; i < 3; i++) BMP_WIN_Delete(*(void **)(p + i * 4 + 0xD50));
    BMP_WIN_Delete(((Work *)p)->fD48);
}

/*
 * Claim the 0xb4/0x48 resource into +0xb88 and the 0x2d transfer into +0xb8c.
 */
void WORLDTRADE_TITLE_CreateStrings(Work *p)
{
    (*(unsigned int *)&p->str) = (u32)STRBUF_Create(0xb4, 0x48);
    (*(unsigned int *)&p->fB8C) = (u32)MSGDATA_AllocString((struct MsgBank *)(p->bank_u), 0x2d);
}

/*
 * Release the two +0xb88/+0xb8c handles.
 */
void WORLDTRADE_TITLE_DeleteStrings(Work *p)
{
    STRBUF_Delete((struct U16Vec *)((*(unsigned int *)&p->str)));
    STRBUF_Delete((struct U16Vec *)((*(unsigned int *)&p->fB8C)));
}

/*
 * When the u16 at +0xe18 is set, kick the three half-shades, set 7/0xb and roll to state 9.
 */
int WORLDTRADE_TITLE_StateHideForExit(Work *p)
{
    if (p->active != 0) {
        BG_SYS_SetMainPlaneVisible(1, 0);
        BG_SYS_SetMainPlaneVisible(2, 0);
        BG_SYS_SetMainPlaneVisible(4, 0);
        WORLDTRADE_SetStateAndReturn(p, 7, 0xb);
        p->f18_u = 1;
        p->state = 9;
    }
    return 2;
}

/*
 * Store the 0xa/2 pair and report 2.
 */
int WORLDTRADE_TITLE_StateAdvance(u8 *p)
{
    WORLDTRADE_SetNextState(p, 0xa, 2);
    return 2;
}

/*
 * Push the fixed 6/1/0x48 request and stamp 3.
 */
int WORLDTRADE_TITLE_StateStartWipeIn(Work *p)
{
    WIPE_SYS_Start((void *)3, 1, 1, 0, 6, 1, 0x48);
    p->state = 3;
    return 2;
}

/*
 * Probe the parent object; on success stamp 5 into +0x28 and report 2.
 */
int WORLDTRADE_TITLE_StateWaitWipeIn(Work *p)
{
    if (WIPE_SYS_EndCheck()) {
        p->state = 5;
    }
    return 2;
}

int WORLDTRADE_TITLE_StateWaitWipeInAlt(Work *p)
{
    if (WIPE_SYS_EndCheck()) {
        p->state = 5;
    }
    return 2;
}

int WORLDTRADE_TITLE_StateStartCursorAnim(Work *p) {WORLDTRADE_TITLE_PrintMessage((u8 *)p,4,1,0,0xf0f);WORLDTRADE_SetNextState(p,10,6);CLACT_SetActorAutoAnim(*(struct Obj * *)&p->cursor_p,1);WORLDTRADE_ClearSelectedSpecies(p);return 2;}

/*
 * Tail call into TOUCHPANEL_HitTrg with the overlay's own state object.
 */
int WORLDTRADE_TITLE_HitTestMenu(void)
{
    return TOUCHPANEL_HitTrg(g_022038EC);
}

void WORLDTRADE_TITLE_HandleSelection(Work *p, int mode)
{
    switch (mode) {
    case 0:
        if (p->busy == 0) {
            WORLDTRADE_SetStateAndReturn(p, 5, 5);
            p->state = 9;
        } else if (p->f36 == 0) {
            WORLDTRADE_SetStateAndReturn(p, 7, 11);
            p->f18_u = 2;
            p->state = 9;
            p->f36 = 0xE10;
        } else {
            WORLDTRADE_TITLE_PrintMessage((u8 *)p, 40, 1, 0, 0xF0F);
            WORLDTRADE_SetNextState(p, 11, 5);
            GFL_USE_PlaySeDefaultVolume(0x557);
            (*(unsigned int *)&p->cnt) = 0;
        }
        break;
    case 1:
        p->fE1A = 0;
        WORLDTRADE_SetStateAndReturn(p, 4, 13);
        p->state = 9;
        break;
    case 2:
        WORLDTRADE_TITLE_PrintMessageSub((u8 *)p, 7, WORLDTRADE_QueryGameData(), 0, 0xF0F);
        WORLDTRADE_SetNextState(p, 10, 12);
        break;
    }
}

int WORLDTRADE_TITLE_StateMainInput(Work *p)
{
    int r;

    r = WORLDTRADE_TITLE_HitTestMenu();
    if (r != -1) {
        p->sel = r;
        GFL_USE_PlaySeDefaultVolume(0x548);
        WORLDTRADE_SetActorPos(p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct Obj *)p->cursor, 1);
        p->state_i = 0xE;
        func_020355D8(1);
        if (p->sel == 2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x54C);
        }
        return 2;
    }
    if (KEY_GetTrg() != 0 && UI_GetInputMode() == 1) {
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        func_020355D8(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return 2;
    }
    if (KEY_GetTrg() & 2) {
        p->sel = 2;
        WORLDTRADE_SetActorPos(p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct Obj *)p->cursor, 1);
        p->state_i = 0xE;
        GFL_USE_PlaySeDefaultVolume(0x551);
    } else if (KEY_GetTrg() & 1) {
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct Obj *)p->cursor, 1);
        p->state_i = 0xE;
        GFL_USE_PlaySeDefaultVolume(0x54C);
    } else if (KEY_GetTrg() & 0x40) {
        if (p->sel != 0) {
            p->sel--;
            GFL_USE_PlaySeDefaultVolume(0x548);
            CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
            CLACT_RestartActorAnim((struct Actor *)p->cursor);
            WORLDTRADE_SetActorPos(p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        }
    } else if (KEY_GetTrg() & 0x80) {
        if (p->sel < 2) {
            p->sel++;
            GFL_USE_PlaySeDefaultVolume(0x548);
            CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
            CLACT_RestartActorAnim((struct Actor *)p->cursor);
            WORLDTRADE_SetActorPos(p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        }
    }
    return 2;
}

/*
 * Reset, latch state 8 and clear the u16 slot at +0xe18.
 */
int WORLDTRADE_TITLE_StateRequestExit(Work *p)
{
    WORLDTRADE_SUBLCD_StartAnimTaskB(p);
    p->state = 8;
    p->active = 0;
    return 2;
}

int WORLDTRADE_TITLE_StateWaitActive(Work *p)
{
    if (p->active != 0) {
        p->state_i = 9;
    }
    return 2;
}

/*
 * One of the two fixed 0/3 openers, then state 0.
 */
int WORLDTRADE_TITLE_StateStartWipeOut(Work *p)
{
    if (p->x14 == 0) {
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x48);
    } else {
        WIPE_SYS_Start((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    p->state = 0;
    return 3;
}

/*
 * State setter: build with the fixed 0x12/0x102/0x3/0x1 argument pair and latch state 0xd.
 */
int WORLDTRADE_TITLE_StateOpenConfirm(Work *p)
{
    WORLDTRADE_OpenTaskMenuYesNoDefault((u32)p, 0x12, 0x102, 0x3, 0x1);
    p->state = 0xd;
    return 2;
}

/*
 * lever: if/else dispatch retains the compare after the first full arm.
 */
int WORLDTRADE_TITLE_StateConfirmYesNoInput(Work *p)
{
    u32 w;
    u32 state;
    state = WORLDTRADE_UpdateTaskMenuYesNo((char *)p);
    if (state == 1) {
        WORLDTRADE_CloseTaskMenu((char *)p);
        BMP_MENUWORK_DrawWindowBorder((void *)(*(u32 *)&p->dd0), 2);
        w = *(u32 *)&p->dd0;
        BMP_WIN_ClearScreen((struct Descriptor *)w);
        BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer((struct Descriptor *)w));
        w = (*(unsigned int *)&p->fDE0);
        BMP_WIN_ClearScreen((struct Descriptor *)w);
        BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer((struct Descriptor *)w));
        BG_SYS_SetPlaneVisible(6, 0);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj *)p->fD38), 0);
        WORLDTRADE_SetStateAndReturn(p, 0, 0x14);
        p->state = 7;
    } else if (state == 2) {
        WORLDTRADE_CloseTaskMenu((char *)p);
        BMP_MENUWORK_DrawWindowBorder((void *)(*(u32 *)&p->dd0), 2);
        w = *(u32 *)&p->dd0;
        BMP_WIN_ClearScreen((struct Descriptor *)w);
        BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer((struct Descriptor *)w));
        CLACT_SetActorAutoAnim((struct Obj *)((struct Obj *)p->cursor), 1);
        p->state = 5;
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj *)p->cursor), 1);
    }
    return 2;
}

int WORLDTRADE_TITLE_StateUpdateCursorAnim(Work *p)
{
    if (CLACT_IsActorAnimActive((struct Actor *)(p->cursor)) == 0) {
        CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)(p->cursor)), 0);
        if (UI_GetInputMode() == 1)
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj *)p->cursor), 0);
        else
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj *)p->cursor), 1);
        WORLDTRADE_TITLE_HandleSelection(p, p->sel);
    }
    return 2;
}

/*
 * When the sub-object at +0xfa0 is idle, re-arm the state word from +0x2c.
 */
int WORLDTRADE_TITLE_StateWaitMessage(u8 *p)
{
    if (WORLDTRADE_ADAPTER_IsStreamDone((PrintStreamCtx *)(p + 0xfa0)) == 0) {
        ((Work *)p)->state = ((Work *)p)->returnState;
    }
    return 2;
}

int WORLDTRADE_TITLE_StateWaitMessageTimed(u8 *p)
{
    if (WORLDTRADE_ADAPTER_IsStreamDone((PrintStreamCtx *)(p + 0xfa0)) == 0) {
        if (++((Work *)p)->cnt > 0x2d) {
            ((Work *)p)->cnt = 0;
            ((Work *)p)->state = ((Work *)p)->returnState;
        }
    }
    return 2;
}

/*
 * lever: struct window array avoids hoisting its base; initialize i before q.
 */
void WORLDTRADE_TITLE_DrawMenuLabels(Work *p)
{
    void *q;
    const u32 *t;
    int i;
    t = d_022038FC[p->busy];
    i = 0;
    q = p->queue;
    for (; i < 3; i++) {
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[i])), 1);
        WORLDTRADE_TITLE_PrintBankString((void *)p->win[i], (void *)p->bank_u, 0, t[i], 0, q, 0x3dc1);
    }
}

void WORLDTRADE_TITLE_PrintMessage(u8 *p, u32 n, int a2, int a3, int a4)
{
    u32 w;
    func_02045CAC((struct MsgBank *)(((Work *)p)->bank_u), n, ((Work *)p)->str);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((Work *)p)->frame)), 0xf);
    w = ((Work *)p)->frame;
    BMP_WIN_TransferChars((struct Descriptor *)w);
    BMP_WIN_MakeScreen((struct Cfg *)w);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)w));
    BMP_MENUWORK_DrawWindow((void *)(((Work *)p)->frame), 0, 1, 0xe);
    WORLDTRADE_ADAPTER_QueuePrintDefaultColor((void *)(((Work *)p)->frame), 0, ((Work *)p)->str, 0, 0, p + 0xfa0);
}

/*
 * Tear the object down: unhook the two sub-objects, release the +0xdd0 resource, wire the 0/1/e quad, then drain the four engine hooks.
 */
void WORLDTRADE_TITLE_PrintMessageSub(u8 *p, int k, int a2, int a3, int a4)
{
    u32 v;

    func_02045CAC((struct MsgBank *)(((Work *)p)->bank_u), k, (void *)(*(u32 *)(p + 0xb6c + 0x1c)));
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((Work *)p)->dd0_u)), 0xf);
    BMP_MENUWORK_DrawWindow((void *)(((Work *)p)->dd0_u), 0, 1, 0xe);
    WORLDTRADE_ADAPTER_QueuePrintDefaultColor((void *)(((Work *)p)->dd0_u), 0, (void *)(*(u32 *)(p + 0xb6c + 0x1c)), 0, 0, p + 0xfa0);
    v = ((Work *)p)->dd0_u;
    BMP_WIN_TransferChars((struct Descriptor *)v);
    BMP_WIN_MakeScreen((struct Cfg *)v);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)v));
}

void WORLDTRADE_TITLE_PrintBankString(void *p,void *bank,u32 b,u32 id,u32 fifth,void *out,u16 se) { void *s=MSGDATA_AllocString(bank,id); WORLDTRADE_ADAPTER_PrintQueColor(p,b,(u32)s,0,0,0,se,(Printer *)out); STRBUF_Delete(s); }

void WORLDTRADE_TITLE_LoadMainBgSwap(Work *p)
{
    void *h;
    if (p->f12E0 == 1 && p->f12E4 == 0) {
        h = ARC_TOOL_CreateHandle(0x60, 0x48);
        ARC_UTIL_UploadPaletteFromHandle(h, 4, 4, 0x160, 0x160, 0xa0, 0x48);
        ARC_UTIL_UploadBgCharFromHandle(h, 0xe, 5, 0, 0x1c00, 0, 0x48);
        ARC_UTIL_UploadBgPaletteAddFromHandleExt(h, 0x21, 5, 0, 0, 0, 0, 0x48);
        ARC_TOOL_DeleteHandle(h);
        ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x20, 0x20, 0x48);
    }
}

void WORLDTRADE_TITLE_LoadSubBgSwap(Work *p)
{
    void *h;

    if (p->f12E0 == 1 && p->f12E4 == 0) {
        h = ARC_TOOL_CreateHandle(0x60, 0x48);
        func_02049B68(h, 5, 4, 0, 0x20, 0x48);
        ARC_UTIL_UploadBgCharFromHandle(h, 0xf, 6, 0, 0, 0, 0x48);
        ARC_UTIL_UploadBgPaletteAddFromHandleExt(h, 0x22, 6, 0, 0, 0, 0, 0x48);
        ARC_TOOL_DeleteHandle(h);
    }
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj *)p->fD38), 1);
}

void WORLDTRADE_TITLE_CreateMenuWindow(Work *p, u32 k)
{
    u32 v;

    (*(unsigned int *)&p->fDE0) = BMP_WIN_Create(4, 0xc, 0x13, 0x12, 4, 1, 1);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)(*(unsigned int *)&p->fDE0))), 0);
    WORLDTRADE_INPUT_PrintCentered((void *)((*(unsigned int *)&p->fDE0)), (void *)(p->bank_u), k, (u8 *)p + 0xfa0);
    v = (*(unsigned int *)&p->fDE0);
    BMP_WIN_TransferChars((struct Descriptor *)v);
    BMP_WIN_MakeScreen((struct Cfg *)v);
    BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer((struct Descriptor *)v));
}
