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
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
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
 *   WORLDTRADE_ADAPTER_IsStreamBusy  0x02202840  thumb  ov135
 *   BMP_WIN_GetBmp   0x02045770  arm
 *   BMP_Clear   0x02043B5C  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   WORLDTRADE_ADAPTER_QueuePrintDefaultColor  0x02202858  thumb  ov135
 *   MSGDATA_ReadString  0x02045CAC  arm
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
 *   WORLDTRADE_AdvanceScreenId  0x021F4EC8  thumb  ov135
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb
 *   WORLDTRADE_SetActorPos  0x021F4FF4  thumb
 *   UI_SetInputMode  0x020355D8  arm
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm  arm9
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   WORLDTRADE_UpdateTaskMenuYesNo 0x021F4D14 thumb ov135
 *   WORLDTRADE_CloseTaskMenu 0x021F4CE4 thumb ov135
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
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
 *   WORLDTRADE_GetMessageWait 0x021F4ED4 thumb ov135
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
#include "../sdk_ioreg.h"

#include "../arm9/arc_tool.h"
struct MsgBank;
struct Strbuf;

#include "../arm9/msgdata.h"

#include "../arm9/strbuf.h"
struct BmpWin;

#include "../arm9/bmp_win.h"


#include "../arm9/bg_sys.h"

#include "worldtrade_input.h"







#include "../arm9/arc_util.h"


#include "../arm9/bmp_menuwork.h"



#include "../arm9/clact.h"
struct Actor;


#include "../arm9/ui.h"


struct Bmp;


typedef short s16_p07;
#include "../arm9/bmp.h"






#include "../arm9/key.h"





#include "worldtrade.h"

#include "../arm9/net.h"





#include "../arm9/wipe.h"








#include "../arm9/gfl_use.h"








#include "../arm9/gx.h"




#include "../arm9/touchpanel.h"










#include "worldtrade_sublcd.h"




int WORLDTRADE_TITLE_Init(WorldtradeWork *p);

int WORLDTRADE_TITLE_CallStateHandler(u8 *p);

int WORLDTRADE_TITLE_Exit(WorldtradeWork *p);

void WORLDTRADE_TITLE_SetupBgPlanes(void);

void WORLDTRADE_TITLE_ScrollBg(WorldtradeWork *p, u32 a, u32 b);

void WORLDTRADE_TITLE_ExitBgPlanes(WorldtradeWork *p);

void WORLDTRADE_TITLE_ExitBgPlanesSub(void);

void WORLDTRADE_TITLE_SetBgVisible(WorldtradeWork *p);

void WORLDTRADE_TITLE_LoadBgGraphics(WorldtradeWork *p);

void WORLDTRADE_TITLE_CreateActors(WorldtradeWork *p);

void WORLDTRADE_TITLE_DeleteActors(WorldtradeWork *p);

void WORLDTRADE_TITLE_CreateWindows(u8 *p);

void WORLDTRADE_TITLE_DeleteWindows(u8 *p);

void WORLDTRADE_TITLE_CreateStrings(WorldtradeWork *p);

void WORLDTRADE_TITLE_DeleteStrings(WorldtradeWork *p);

int WORLDTRADE_TITLE_StateHideForExit(WorldtradeWork *p);

int WORLDTRADE_TITLE_StateAdvance(u8 *p);

int WORLDTRADE_TITLE_StateStartWipeIn(WorldtradeWork *p);

int WORLDTRADE_TITLE_StateWaitWipeIn(WorldtradeWork *p);

int WORLDTRADE_TITLE_StateWaitWipeInAlt(WorldtradeWork *p);

int WORLDTRADE_TITLE_StateStartCursorAnim(WorldtradeWork *p);

int WORLDTRADE_TITLE_HitTestMenu(void);

void WORLDTRADE_TITLE_HandleSelection(WorldtradeWork *p, int mode);

int WORLDTRADE_TITLE_StateMainInput(WorldtradeWork *p);

int WORLDTRADE_TITLE_StateRequestExit(WorldtradeWork *p);

int WORLDTRADE_TITLE_StateWaitActive(WorldtradeWork *p);

int WORLDTRADE_TITLE_StateStartWipeOut(WorldtradeWork *p);

int WORLDTRADE_TITLE_StateOpenConfirm(WorldtradeWork *p);

int WORLDTRADE_TITLE_StateConfirmYesNoInput(WorldtradeWork *p);

int WORLDTRADE_TITLE_StateUpdateCursorAnim(WorldtradeWork *p);

int WORLDTRADE_TITLE_StateWaitMessage(u8 *p);

int WORLDTRADE_TITLE_StateWaitMessageTimed(u8 *p);

void WORLDTRADE_TITLE_DrawMenuLabels(WorldtradeWork *p);

void WORLDTRADE_TITLE_PrintMessage(u8 *p, u32 n, int unused1, int unused2, int unused3);

void WORLDTRADE_TITLE_PrintMessageSub(u8 *p, int k, int unused1, int unused2, int unused3);

void WORLDTRADE_TITLE_PrintBankString(void *p,void *bank,u32 b,u32 id,u32 fifth,void *out,u16 se);

void WORLDTRADE_TITLE_LoadMainBgSwap(WorldtradeWork *p);

void WORLDTRADE_TITLE_LoadSubBgSwap(WorldtradeWork *p);

void WORLDTRADE_TITLE_CreateMenuWindow(WorldtradeWork *p, u32 k);

#include "worldtrade_adapter.h"




extern int (*g_02203E58[])(u8 *);

extern struct DispConfig g_02203914;

extern struct BgTemplate g_022039A4;

extern struct BgTemplate g_02203984;

extern struct BgTemplate g_022039C4;

extern struct BgTemplate g_02203944;

extern struct BgTemplate g_02203924;

extern struct BgTemplate g_02203964;

extern struct BgTemplate g_022039E4;

extern const WorldtradePos d_022038E0[];

extern char g_022038EC[];

extern const WorldtradePos tbl_022038E0[];

extern const u32 d_022038FC[][3];

/*
 * volatile: hardware display control 0x04000304 read and written at 0x021FFDB6..0x021FFDBA.
 */
int WORLDTRADE_TITLE_Init(WorldtradeWork *p)
{
    u32 control;
    WORLDTRADE_TITLE_CreateStrings(p);
    control=*(volatile u16 *)REG_POWCNT1_ADDR;
    control &= ~0x8000;
    *(volatile u16 *)REG_POWCNT1_ADDR=control;
    WORLDTRADE_TITLE_SetupBgPlanes();
    WORLDTRADE_TITLE_LoadBgGraphics(p);
    WORLDTRADE_TITLE_CreateWindows((u8 *)p);
    WORLDTRADE_TITLE_ScrollBg(p,0,0);
    WORLDTRADE_TITLE_LoadMainBgSwap(p);
    if(p->titleEntered==0) BG_SYS_SetPlaneVisible(4,0);
    else {WORLDTRADE_TITLE_LoadSubBgSwap(p);BG_SYS_SetPlaneVisible(4,1);}
    WORLDTRADE_TITLE_CreateMenuWindow(p,0);
    p->keepBgLayers=0;
    WORLDTRADE_TITLE_CreateActors(p);
    WORLDTRADE_ENTER_RestartNetTimeout((u8 *)p);
    WORLDTRADE_TITLE_DrawMenuLabels((WorldtradeWork *)p);
    if(p->titleEntered==0) {
        WORLDTRADE_TITLE_SetBgVisible(p);
        WIPE_SYS_Start(0,1,1,0,6,1,0x48);
        p->state=0;
        p->titleEntered=1;
        WORLDTRADE_SUBLCD_StartAnimTaskA(p);
    } else {
        if(p->eb4==1 && GXx_GetMasterBrightness_((u16 *)REG_DB_MASTER_BRIGHT_ADDR)!=0) {
            WORLDTRADE_SUBLCD_SetSlotActorPositions(p);
            WIPE_SYS_Start(0,1,1,0,6,1,0x48);
        } else WIPE_SYS_Start((void *)3,1,1,0,6,1,0x48);
        p->state=5;
    }
    p->eb4=0;
#if LANGUAGE != LANGUAGE_JAPANESE
    WORLDTRADE_SUBLCD_UpdateSlotAnims(p);
#endif
    return 1;
}

/*
 * WorldtradeState-table dispatch through the table at 0x02203E58.
 */
int WORLDTRADE_TITLE_CallStateHandler(u8 *p)
{
    return g_02203E58[((WorldtradeWork *)p)->state](p);
}

int WORLDTRADE_TITLE_Exit(WorldtradeWork *p)
{
    WORLDTRADE_TITLE_DeleteActors(p);
    WORLDTRADE_TITLE_DeleteStrings(p);
    WORLDTRADE_TITLE_DeleteWindows((u8 *)p);
    WORLDTRADE_TITLE_ExitBgPlanesSub();
    if (p->nextScreenId == 4 || p->nextScreenId == 5) p->keepBgLayers = 1;
    WORLDTRADE_TITLE_ExitBgPlanes(p);
    CLACT_SetActorDrawEnable((struct ClactActor *)(*(struct Actor **)(void * *)&p->scrollBarObj), 0);
    WORLDTRADE_AdvanceScreenId(p);
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
void WORLDTRADE_TITLE_ScrollBg(WorldtradeWork *p, u32 scrollY, u32 keepLayer6)
{
    if (p->bgLayersLoaded == 0) {
        struct BgTemplate t4;
        struct BgTemplate t6;
        struct BgTemplate t5;
        struct BgTemplate t7;

        p->bgLayersLoaded = 1;
        t4 = g_02203944;
        BG_SYS_InitBgLayer(4, &t4, 0);
        BG_SYS_ClearLayerEx(4, 0);
        t6 = g_02203924;
        BG_SYS_InitBgLayer(6, &t6, 0);
        if (keepLayer6 == 0) {
            BG_SYS_ClearLayerEx(6, 0);
        }
        t5 = g_02203964;
        t5.scrollY = scrollY;
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

void WORLDTRADE_TITLE_ExitBgPlanes(WorldtradeWork *p) {if(p->bgLayersLoaded==1 && p->keepBgLayers==0) {p->bgLayersLoaded=0;BG_SYS_FreeLayerBuf(6);BG_SYS_FreeLayerBuf(5);BG_SYS_FreeLayerBuf(4);BG_SYS_FreeLayerBuf(7);}}

/*
 * Poke channels 2, 1 and 0 in that order.
 */
void WORLDTRADE_TITLE_ExitBgPlanesSub(void)
{
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(0);
}

void WORLDTRADE_TITLE_SetBgVisible(WorldtradeWork *p) {BG_SYS_SetMainPlaneVisible(1,0);BG_SYS_SetMainPlaneVisible(2,0);BG_SYS_SetMainPlaneVisible(4,0);CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)(*(struct WorldtradeObj * *)&p->cursor_p)),0);}

/*
 * Straight-line six-argument window setup over a 0x60x0x48 handle: the
 * handle open, three B40/B68 window calls, two F5BC text calls and two
 * 498F4 draws, ending with the 49238 release.  No parameters.
 */
void WORLDTRADE_TITLE_LoadBgGraphics(WorldtradeWork *p)
{
    void *h = ARC_TOOL_CreateHandle(0x60, 0x48);

    ARC_UTIL_UploadPaletteFromHandleWhole(h, 3, 0, 0, 0x60, 0x48);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    BMP_MENUWORK_LoadCharAndPltt(0, 1, 0xe, 0, 0x48);
    BMP_MENUWORK_LoadCharAndPltt(0, 0x1f, 0xb, 0, 0x48);
    ARC_UTIL_UploadBgCharFromHandle(h, 0xd, 1, 0, 0, 1, 0x48);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 0x20, 1, 0, 0x600, 1, 0x48);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 0x1f, 2, 0, 0x600, 1, 0x48);
    ARC_TOOL_DeleteHandle(h);
}

void WORLDTRADE_TITLE_CreateActors(WorldtradeWork *p)
{
    WorldtradeObjPos pos;
    pos.x = d_022038E0[p->sel].x;
    pos.y = d_022038E0[p->sel].y;
    pos.z = 0;
    pos.pri = 0;
    pos.bgPriority = 1;
    p->cursor_p = CLACT_CreateActor((struct Unit *)p->res, (uptr)p->set2, (uptr)p->set[1], (uptr)p->set3, (const struct ActorInitParam *)&pos, 0, 0x48);
    CLACT_SetActorAutoAnim(p->cursor_p, 1);
    CLACT_SetActorAnimSeq(p->cursor_p, 0);
    if (UI_GetInputMode() == 1) {
        CLACT_SetActorDrawEnable(p->cursor_p, 0);
    } else {
        CLACT_SetActorAnimSeq(p->cursor_p, 0);
        CLACT_SetActorDrawEnable(p->cursor_p, 1);
    }
    GFL_NET_RefreshWmIconAtTopRight(0, 0x48);
}

/*
 * Tail call into CLACT_DeleteActor with the pointer held at +0xbf4.
 */
void WORLDTRADE_TITLE_DeleteActors(WorldtradeWork *p)
{
    CLACT_DeleteActor((struct ClactActor *)((struct Actor *)(p->cursor)));
}

/*
 * lever: full-word int cast on the window-read address breaks the loop register tie; unsigned base/index addition happens before the cast.
 */
void WORLDTRADE_TITLE_CreateWindows(u8 *p)
{
    int i;
    void *w;
    ((WorldtradeWork *)p)->titleWin=(void *)BMP_WIN_Create(1,(u8)2,(u8)1,(u8)0x1C,2,1,(u16)1);
    BMP_Clear(BMP_WIN_GetBmp(((WorldtradeWork *)p)->titleWin),0xA);
    w=((WorldtradeWork *)p)->titleWin;
    BMP_WIN_TransferChars(w); BMP_WIN_MakeScreen(w); BG_SYS_PushTile(BMP_WIN_GetBgLayer(w));
    WORLDTRADE_ADAPTER_PrintQueColor((void *)(((WorldtradeWork *)p)->titleWin), 0, ((WorldtradeWork *)p)->titleStr, 0, 2, 0, 0x35CA, (Printer *)((u8 *)&((struct WorldtradeWork *)p)->printer));
    for(i=0;i<3;i++) {
        void *window;
        ((WorldtradeWork *)p)->win[i]=(void *)BMP_WIN_Create(1,(u8)9,(u8)(i*5+6),(u8)0xF,2,1,(u16)1);
        BMP_Clear(BMP_WIN_GetBmp(((WorldtradeWork *)p)->win[i]),1);
        window=((WorldtradeWork *)p)->win[i];
        BMP_WIN_TransferChars(window); BMP_WIN_MakeScreen(window); BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
    }
    ((WorldtradeWork *)p)->d40=(void *)BMP_WIN_Create(0,(u8)2,(u8)0x15,(u8)0x1B,2,0xD,(u16)1);
    BMP_Clear(BMP_WIN_GetBmp(((WorldtradeWork *)p)->d40),0xF);
    ((WorldtradeWork *)p)->dd0=(void *)BMP_WIN_Create(0,(u8)2,(u8)0x13,(u8)0x1B,4,0xD,(u16)1);
    BMP_Clear(BMP_WIN_GetBmp(((WorldtradeWork *)p)->dd0),0xF);
}

void WORLDTRADE_TITLE_DeleteWindows(u8 *p)
{
    int i;
    WORLDTRADE_ADAPTER_DeletePrintStream((struct WorldtradeObj *)((struct WorldtradeObj *)((u8 *)&((struct WorldtradeWork *)p)->printer)));
    BMP_WIN_Delete(((WorldtradeWork *)p)->msgWin);
    BMP_WIN_Delete(((WorldtradeWork *)p)->dd0);
    BMP_WIN_Delete(((WorldtradeWork *)p)->d40);
    for (i = 0; i < 3; i++) BMP_WIN_Delete(((WorldtradeWork *)p)->win[i]);
    BMP_WIN_Delete(((WorldtradeWork *)p)->titleWin);
}

/*
 * Claim the 0xb4/0x48 resource into +0xb88 and the 0x2d transfer into +0xb8c.
 */
void WORLDTRADE_TITLE_CreateStrings(WorldtradeWork *p)
{
    (*(unsigned int *)&p->str) = (uptr)STRBUF_Create(0xb4, 0x48);
    (*(unsigned int *)&p->titleStr) = (uptr)MSGDATA_AllocString((struct MsgBank *)(p->bank_u), 0x2d);
}

/*
 * Release the two +0xb88/+0xb8c handles.
 */
void WORLDTRADE_TITLE_DeleteStrings(WorldtradeWork *p)
{
    STRBUF_Delete(*(struct Strbuf **)&p->str);
    STRBUF_Delete(*(struct Strbuf **)&p->titleStr);
}

/*
 * When the u16 at +0xe18 is set, kick the three half-shades, set 7/0xb and roll to state 9.
 */
int WORLDTRADE_TITLE_StateHideForExit(WorldtradeWork *p)
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
    WORLDTRADE_SetNextState((WorldtradeWork *)p, 0xa, 2);
    return 2;
}

/*
 * Push the fixed 6/1/0x48 request and stamp 3.
 */
int WORLDTRADE_TITLE_StateStartWipeIn(WorldtradeWork *p)
{
    WIPE_SYS_Start((void *)3, 1, 1, 0, 6, 1, 0x48);
    p->state = 3;
    return 2;
}

/*
 * Probe the parent object; on success stamp 5 into +0x28 and report 2.
 */
int WORLDTRADE_TITLE_StateWaitWipeIn(WorldtradeWork *p)
{
    if (WIPE_SYS_EndCheck()) {
        p->state = 5;
    }
    return 2;
}

int WORLDTRADE_TITLE_StateWaitWipeInAlt(WorldtradeWork *p)
{
    if (WIPE_SYS_EndCheck()) {
        p->state = 5;
    }
    return 2;
}

int WORLDTRADE_TITLE_StateStartCursorAnim(WorldtradeWork *p) {WORLDTRADE_TITLE_PrintMessage((u8 *)p,4,1,0,0xf0f);WORLDTRADE_SetNextState((WorldtradeWork *)p,10,6);CLACT_SetActorAutoAnim((struct ClactActor *)((struct Actor *)(*(struct WorldtradeObj * *)&p->cursor_p)),1);WORLDTRADE_ClearSelectedSpecies((WorldtradeWork *)p);return 2;}

/*
 * Tail call into TOUCHPANEL_HitTrg with the overlay's own state object.
 */
int WORLDTRADE_TITLE_HitTestMenu(void)
{
    return TOUCHPANEL_HitTrg((const TouchHitTable *)g_022038EC);
}

void WORLDTRADE_TITLE_HandleSelection(WorldtradeWork *p, int mode)
{
    switch (mode) {
    case 0:
        if (p->busy == 0) {
            WORLDTRADE_SetStateAndReturn(p, 5, 5);
            p->state = 9;
        } else if (p->cooldownFrames == 0) {
            WORLDTRADE_SetStateAndReturn(p, 7, 11);
            p->f18_u = 2;
            p->state = 9;
            p->cooldownFrames = 0xE10;
        } else {
            WORLDTRADE_TITLE_PrintMessage((u8 *)p, 40, 1, 0, 0xF0F);
            WORLDTRADE_SetNextState(p, 11, 5);
            GFL_USE_PlaySeDefaultVolume(0x557);
            (p->cnt) = 0;
        }
        break;
    case 1:
        p->historyFlag = 0;
        WORLDTRADE_SetStateAndReturn(p, 4, 13);
        p->state = 9;
        break;
    case 2:
        WORLDTRADE_TITLE_PrintMessageSub((u8 *)p, 7, WORLDTRADE_GetMessageWait(), 0, 0xF0F);
        WORLDTRADE_SetNextState(p, 10, 12);
        break;
    }
}

int WORLDTRADE_TITLE_StateMainInput(WorldtradeWork *p)
{
    int r;

    r = WORLDTRADE_TITLE_HitTestMenu();
    if (r != -1) {
        p->sel = r;
        GFL_USE_PlaySeDefaultVolume(0x548);
        WORLDTRADE_SetActorPos((struct ClactActor *)p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, 1);
        p->state_i = 0xE;
        UI_SetInputMode(1);
        if (p->sel == 2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x54C);
        }
        return 2;
    }
    if (KEY_GetTrg() != 0 && UI_GetInputMode() == 1) {
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        UI_SetInputMode(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return 2;
    }
    if (KEY_GetTrg() & 2) {
        p->sel = 2;
        WORLDTRADE_SetActorPos((struct ClactActor *)p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, 1);
        p->state_i = 0xE;
        GFL_USE_PlaySeDefaultVolume(0x551);
    } else if (KEY_GetTrg() & 1) {
        CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)p->cursor, 1);
        p->state_i = 0xE;
        GFL_USE_PlaySeDefaultVolume(0x54C);
    } else if (KEY_GetTrg() & 0x40) {
        if (p->sel != 0) {
            p->sel--;
            GFL_USE_PlaySeDefaultVolume(0x548);
            CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
            CLACT_RestartActorAnim((struct ClactActor *)p->cursor);
            WORLDTRADE_SetActorPos((struct ClactActor *)p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        }
    } else if (KEY_GetTrg() & 0x80) {
        if (p->sel < 2) {
            p->sel++;
            GFL_USE_PlaySeDefaultVolume(0x548);
            CLACT_SetActorDrawEnable((struct ClactActor *)p->cursor, 1);
            CLACT_RestartActorAnim((struct ClactActor *)p->cursor);
            WORLDTRADE_SetActorPos((struct ClactActor *)p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        }
    }
    return 2;
}

/*
 * Reset, latch state 8 and clear the u16 slot at +0xe18.
 */
int WORLDTRADE_TITLE_StateRequestExit(WorldtradeWork *p)
{
    WORLDTRADE_SUBLCD_StartAnimTaskB(p);
    p->state = 8;
    p->active = 0;
    return 2;
}

int WORLDTRADE_TITLE_StateWaitActive(WorldtradeWork *p)
{
    if (p->active != 0) {
        p->state_i = 9;
    }
    return 2;
}

/*
 * One of the two fixed 0/3 openers, then state 0.
 */
int WORLDTRADE_TITLE_StateStartWipeOut(WorldtradeWork *p)
{
    if (p->nextScreenId == 0) {
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x48);
    } else {
        WIPE_SYS_Start((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    p->state = 0;
    return 3;
}

/*
 * WorldtradeState setter: build with the fixed 0x12/0x102/0x3/0x1 argument pair and latch state 0xd.
 */
int WORLDTRADE_TITLE_StateOpenConfirm(WorldtradeWork *p)
{
    WORLDTRADE_OpenTaskMenuYesNoDefault((WorldtradeWork *)(p), 0x12, 0x102, 0x3, 0x1);
    p->state = 0xd;
    return 2;
}

/*
 * lever: if/else dispatch retains the compare after the first full arm.
 */
int WORLDTRADE_TITLE_StateConfirmYesNoInput(WorldtradeWork *p)
{
    uptr w;
    u32 state;
    state = WORLDTRADE_UpdateTaskMenuYesNo((WorldtradeWork *)p);
    if (state == 1) {
        WORLDTRADE_CloseTaskMenu((WorldtradeWork *)p);
        BMP_MENUWORK_DrawWindowBorder(*(void **)&p->dd0, 2);
        w = *(u32 *)&p->dd0;
        BMP_WIN_ClearScreen((struct BmpWin *)w);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)w));
        w = (*(unsigned int *)&p->msgWin);
        BMP_WIN_ClearScreen((struct BmpWin *)w);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)w));
        BG_SYS_SetPlaneVisible(6, 0);
        CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->scrollBarObj)), 0);
        WORLDTRADE_SetStateAndReturn(p, 0, 0x14);
        p->state = 7;
    } else if (state == 2) {
        WORLDTRADE_CloseTaskMenu((WorldtradeWork *)p);
        BMP_MENUWORK_DrawWindowBorder(*(void **)&p->dd0, 2);
        w = *(u32 *)&p->dd0;
        BMP_WIN_ClearScreen((struct BmpWin *)w);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)w));
        CLACT_SetActorAutoAnim((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 1);
        p->state = 5;
        CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 1);
    }
    return 2;
}

int WORLDTRADE_TITLE_StateUpdateCursorAnim(WorldtradeWork *p)
{
    if (CLACT_IsActorAnimActive((struct ClactActor *)((struct Actor *)(p->cursor))) == 0) {
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)(p->cursor))), 0);
        if (UI_GetInputMode() == 1)
            CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 0);
        else
            CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->cursor)), 1);
        WORLDTRADE_TITLE_HandleSelection(p, p->sel);
    }
    return 2;
}

/*
 * When the sub-object at +0xfa0 is idle, re-arm the state word from +0x2c.
 */
int WORLDTRADE_TITLE_StateWaitMessage(u8 *p)
{
    if (WORLDTRADE_ADAPTER_IsStreamBusy((PrintStreamCtx *)((u8 *)&((struct WorldtradeWork *)p)->printer)) == 0) {
        ((WorldtradeWork *)p)->state = ((WorldtradeWork *)p)->returnState;
    }
    return 2;
}

int WORLDTRADE_TITLE_StateWaitMessageTimed(u8 *p)
{
    if (WORLDTRADE_ADAPTER_IsStreamBusy((PrintStreamCtx *)((u8 *)&((struct WorldtradeWork *)p)->printer)) == 0) {
        if (++((WorldtradeWork *)p)->cnt > 0x2d) {
            ((WorldtradeWork *)p)->cnt = 0;
            ((WorldtradeWork *)p)->state = ((WorldtradeWork *)p)->returnState;
        }
    }
    return 2;
}

/*
 * lever: struct window array avoids hoisting its base; initialize i before q.
 */
void WORLDTRADE_TITLE_DrawMenuLabels(WorldtradeWork *p)
{
    void *q;
    const u32 *t;
    int i;
    t = d_022038FC[p->busy];
    i = 0;
    q = p->queue;
    for (; i < 3; i++) {
        BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)p->win[i])), 1);
        WORLDTRADE_TITLE_PrintBankString((void *)p->win[i], (void *)p->bank_u, 0, t[i], 0, q, 0x3dc1);
    }
}

void WORLDTRADE_TITLE_PrintMessage(u8 *p, u32 msgId, int unused1, int unused2, int unused3)
{
    struct BmpWin *w;
    MSGDATA_ReadString((struct MsgBank *)(((WorldtradeWork *)p)->bank_u), msgId, ((WorldtradeWork *)p)->str);
    BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)((WorldtradeWork *)p)->frame)), 0xf);
    w = ((WorldtradeWork *)p)->frame;
    BMP_WIN_TransferChars((struct BmpWin *)w);
    BMP_WIN_MakeScreen((struct BmpWin *)w);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)w));
    BMP_MENUWORK_DrawWindow((void *)(((WorldtradeWork *)p)->frame), 0, 1, 0xe);
    WORLDTRADE_ADAPTER_QueuePrintDefaultColor((void *)(((WorldtradeWork *)p)->frame), 0, ((WorldtradeWork *)p)->str, 0, 0, (u8 *)&((struct WorldtradeWork *)p)->printer);
}

/*
 * Tear the object down: unhook the two sub-objects, release the +0xdd0 resource, wire the 0/1/e quad, then drain the four engine hooks.
 */
void WORLDTRADE_TITLE_PrintMessageSub(u8 *p, int msgId, int unused1, int unused2, int unused3)
{
    void *v;

    MSGDATA_ReadString((struct MsgBank *)(((WorldtradeWork *)p)->bank_u), msgId, ((WorldtradeWork *)p)->str);
    BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp(((WorldtradeWork *)p)->dd0)), 0xf);
    BMP_MENUWORK_DrawWindow(((WorldtradeWork *)p)->dd0, 0, 1, 0xe);
    WORLDTRADE_ADAPTER_QueuePrintDefaultColor(((WorldtradeWork *)p)->dd0, 0, ((WorldtradeWork *)p)->str, 0, 0, (u8 *)&((struct WorldtradeWork *)p)->printer);
    v = ((WorldtradeWork *)p)->dd0;
    BMP_WIN_TransferChars(v);
    BMP_WIN_MakeScreen(v);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(v));
}

void WORLDTRADE_TITLE_PrintBankString(void *win,void *bank,u32 unused1,u32 id,u32 unused2,void *printer,u16 color) { void *s=MSGDATA_AllocString(bank,id); WORLDTRADE_ADAPTER_PrintQueColor(win,unused1,s,0,0,0,color,(Printer *)printer); STRBUF_Delete(s); }

void WORLDTRADE_TITLE_LoadMainBgSwap(WorldtradeWork *p)
{
    void *h;
    if (p->bgLayersLoaded == 1 && p->keepBgLayers == 0) {
        h = ARC_TOOL_CreateHandle(0x60, 0x48);
        ARC_UTIL_UploadPaletteFromHandle(h, 4, 4, 0x160, 0x160, 0xa0, 0x48);
        ARC_UTIL_UploadBgCharFromHandle(h, 0xe, 5, 0, 0x1c00, 0, 0x48);
        ARC_UTIL_UploadBgPaletteAddFromHandleExt(h, 0x21, 5, 0, 0, 0, 0, 0x48);
        ARC_TOOL_DeleteHandle(h);
        ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x20, 0x20, 0x48);
    }
}

void WORLDTRADE_TITLE_LoadSubBgSwap(WorldtradeWork *p)
{
    void *h;

    if (p->bgLayersLoaded == 1 && p->keepBgLayers == 0) {
        h = ARC_TOOL_CreateHandle(0x60, 0x48);
        ARC_UTIL_UploadPaletteFromHandleWhole(h, 5, 4, 0, 0x20, 0x48);
        ARC_UTIL_UploadBgCharFromHandle(h, 0xf, 6, 0, 0, 0, 0x48);
        ARC_UTIL_UploadBgPaletteAddFromHandleExt(h, 0x22, 6, 0, 0, 0, 0, 0x48);
        ARC_TOOL_DeleteHandle(h);
    }
    CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)((struct WorldtradeObj *)p->scrollBarObj)), 1);
}

void WORLDTRADE_TITLE_CreateMenuWindow(WorldtradeWork *p, u32 labelIdx)
{
    uptr v;

    (*(unsigned int *)&p->msgWin) = (uptr)BMP_WIN_Create((unsigned int)4, (unsigned int)0xc, (unsigned int)0x13, 0x12, 4, 1, 1);
    BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp(*(struct BmpWin **)&p->msgWin)), 0);
    WORLDTRADE_INPUT_PrintCentered(*(void **)&p->msgWin, (void *)(p->bank_u), labelIdx, (u8 *)&((struct WorldtradeWork *)p)->printer);
    v = (*(unsigned int *)&p->msgWin);
    BMP_WIN_TransferChars((struct BmpWin *)v);
    BMP_WIN_MakeScreen((struct BmpWin *)v);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)v));
}
