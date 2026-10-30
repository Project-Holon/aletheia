/*
 * file:     worldtrade_detail.c
 * unit:     yes
 * function: WORLDTRADE_DETAIL_Init, WORLDTRADE_DETAIL_CallStateHandler, WORLDTRADE_DETAIL_Exit, WORLDTRADE_DETAIL_SetupBgPlanes, WORLDTRADE_DETAIL_ExitBgPlanes, WORLDTRADE_DETAIL_LoadBgGraphics, WORLDTRADE_DETAIL_CreateActors, WORLDTRADE_DETAIL_DeleteActors, WORLDTRADE_DETAIL_CreateWindows, WORLDTRADE_DETAIL_DeleteWindows, WORLDTRADE_DETAIL_CreateStrings, WORLDTRADE_DETAIL_DeleteStrings, WORLDTRADE_DETAIL_StateStart, WORLDTRADE_DETAIL_StateMainInput, WORLDTRADE_DETAIL_StateStartWipeOut, WORLDTRADE_DETAIL_StateOpenConfirm, WORLDTRADE_DETAIL_StateConfirmYesNoInput, WORLDTRADE_DETAIL_StateCreateMenu, WORLDTRADE_DETAIL_StateMenuInput, WORLDTRADE_DETAIL_StateWaitMessage, WORLDTRADE_DETAIL_StateWaitMessageTimed, WORLDTRADE_DETAIL_PrintMessage, WORLDTRADE_DETAIL_GetModeColor, WORLDTRADE_DETAIL_PrintMonInfo, WORLDTRADE_DETAIL_PrintMonName, WORLDTRADE_DETAIL_LoadMonGraphics, WORLDTRADE_DETAIL_DrawRequestWindow
 * address:  0x021FC06C
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
 *   GFL_HEAP_Free 0x020307B0 arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   MI_CpuFill8 0x02082BCC arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   WORLDTRADE_TITLE_ScrollBg 0x021FFFE8 thumb ov135
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
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   WORLDTRADE_INPUT_PrintStringAlignedLine  0x021F91A0  thumb
 *   WORLDTRADE_TITLE_CreateMenuWindow  0x02200BAC  thumb
 *   WORLDTRADE_ADAPTER_DeletePrintStream 0x02202940 thumb ov135
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORLDTRADE_ADAPTER_IsStreamBusy  0x02202840  thumb  ov135
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   BMP_WIN_GetBmp   0x02045770  arm
 *   BMP_Clear   0x02043B5C  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   WORLDTRADE_ADAPTER_QueuePrintDefaultColor  0x02202858  thumb  ov135
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   WORLDTRADE_NoOp  0x0200ADB4  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   tbl_02202EB0   0x02202EB0  data
 *   WORLDTRADE_ADAPTER_CreateString  0x02202670  thumb
 *   BMP_MENUWORK_Create  0x0201F81C  thumb  arm9
 *   BMP_MENUWORK_Delete  0x0201F868  thumb  arm9
 *   BMP_MENUWORK_AddMsgItem  0x0201F878  thumb  arm9
 *   TOUCHPANEL_GetTrg  0x02035C60  arm  arm9
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   WORLDTRADE_AdvanceScreenId  0x021F4EC8  thumb  ov135
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm  arm9
 *   POKE_TOOL_CastToBoxParam 0x020185F0 thumb
 *   MYSTATUS_GetName 0x020084F4 thumb
 *   WORLDTRADE_DEPOSIT_FindLevelBracketIndex 0x021F886C thumb ov135
 *   WORLDTRADE_DEPOSIT_DrawRequestWindowAlt 0x021F8290 thumb ov135
 *   g_02203CF0  0x02203CF0  data  ov135
 *   g_022034AC  0x022034AC  data  ov135
 *   g_022034DC  0x022034DC  data  ov135
 *   g_022034BC  0x022034BC  data  ov135
 *   g_022034FC  0x022034FC  data  ov135
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   tbl_0220351C 0x0220351C data a4
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   WORLDTRADE_OpenTaskMenuYesNo  0x021F4BF8  thumb  ov135
 *   WORLDTRADE_ClearBlendRegs  0x021F5060  thumb  ov135
 *   WORLDTRADE_SetBrightnessOut  0x021F5034  thumb  ov135
 *   WORLDTRADE_UpdateTaskMenuYesNo 0x021F4D14 thumb ov135
 *   WORLDTRADE_CloseTaskMenu 0x021F4CE4 thumb ov135
 *   WORLDTRADE_OpenTaskMenuList 0x021F4D50 thumb ov135
 *   WORLDTRADE_UpdateTaskMenuList 0x021F4E30 thumb ov135
 *   WORLDTRADE_CloseTaskMenuList 0x021F4E64 thumb ov135
 *   WORLDTRADE_BOX_IsHoldingMail 0x021F6DE8 thumb ov135
 *   WORDSET_SetSlotMonSpeciesName  0x0201EE84  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   FILE_UTIL_ReadString  0x02020F84  thumb
 *   STRBUF_SetString  0x02045924  arm
 *   POKEGRA_LoadCharDataPP  0x0202D6F4  thumb
 *   DC_FlushRange  0x020862F0  arm
 *   GX_LoadOBJ  0x0207E780  arm
 *   POKEGRA_GetArcID  0x0202D060  thumb
 *   POKE_TOOL_IsShiny  0x02017EAC  thumb
 *   POKEGRA_GetPalArcIndex  0x0202D0D4  thumb
 */
#include "worldtrade_types.h"

#include "../arm9/mi_memory.h"

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/arc_tool.h"
struct MsgBank;
struct Strbuf;

#include "../arm9/msgdata.h"

#include "../arm9/strbuf.h"
struct BmpWin;

#include "../arm9/bmp_win.h"


#include "../arm9/bg_sys.h"






#include "../arm9/arc_util.h"


#include "../arm9/bmp_menuwork.h"



#include "../arm9/clact.h"
struct Actor;



struct Bmp;

struct Bmp;

typedef short s16_p07;
#include "../arm9/bmp.h"




#include "../arm9/key.h"


struct BoxPokemon;

#include "../arm9/poke_tool.h"

#include "../arm9/pokeparty.h"

#include "../arm9/touchpanel.h"
struct WordSet;


#include "../arm9/wordset.h"






extern const u32 tbl_02202EB0[];


#include "worldtrade.h"

#include "../arm9/net.h"


typedef struct {u32 x,y,w,h;} WorldtradeWinDef;



#include "../arm9/worldtrade.h"


#include "../arm9/mystatus.h"

/* Original DS prototype: the header returns void; the definition returns int (r0 holds the last value). */
#ifdef __MWERKS__
#define WIPE_SYS_Start WIPE_SYS_Start_header
#endif
#include "../arm9/wipe.h"
#ifdef __MWERKS__
#undef WIPE_SYS_Start
extern int WIPE_SYS_Start(void *divisionMode, u32 mainPattern, u32 subPattern, u32 color, u32 frames, u32 wait, u32 heapId);
#endif

#include "worldtrade_deposit.h"









#include "../arm9/gfl_use.h"










#include "worldtrade_box.h"






#include "../arm9/file_util.h"

#include "worldtrade_input.h"

struct PokemonParam;


#include "../arm9/pokegra.h"

#include "../arm9/os_cache.h"

#include "../arm9/gx_load2d.h"





int WORLDTRADE_DETAIL_Init(WorldtradeWork *p);

int WORLDTRADE_DETAIL_CallStateHandler(u8 *p);

int WORLDTRADE_DETAIL_Exit(WorldtradeWork *p);

void WORLDTRADE_DETAIL_SetupBgPlanes(void);

void WORLDTRADE_DETAIL_ExitBgPlanes(void);

void WORLDTRADE_DETAIL_LoadBgGraphics(WorldtradeWork *p);

void WORLDTRADE_DETAIL_CreateActors(WorldtradeWork *p);

void WORLDTRADE_DETAIL_DeleteActors(WorldtradeWork *p);

void WORLDTRADE_DETAIL_CreateWindows(WorldtradeWork *p);

void WORLDTRADE_DETAIL_DeleteWindows(char *p);

void WORLDTRADE_DETAIL_CreateStrings(WorldtradeWork *p);

void WORLDTRADE_DETAIL_DeleteStrings(WorldtradeWork *p);

int WORLDTRADE_DETAIL_StateStart(WorldtradeWork *p);

int WORLDTRADE_DETAIL_StateMainInput(WorldtradeWork *p);

int WORLDTRADE_DETAIL_StateStartWipeOut(WorldtradeWork *p, int unused1);

int WORLDTRADE_DETAIL_StateOpenConfirm(WorldtradeWork *p);

int WORLDTRADE_DETAIL_StateConfirmYesNoInput(WorldtradeWork *p);

int WORLDTRADE_DETAIL_StateCreateMenu(WorldtradeWork *p);

int WORLDTRADE_DETAIL_StateMenuInput(WorldtradeWork *p);

int WORLDTRADE_DETAIL_StateWaitMessage(u8 *p);

int WORLDTRADE_DETAIL_StateWaitMessageTimed(u8 *p);

void WORLDTRADE_DETAIL_PrintMessage(u8 *p, u32 b, u32 c, u32 d, u32 e, void *sel);

u16 WORLDTRADE_DETAIL_GetModeColor(int mode);

void WORLDTRADE_DETAIL_PrintMonInfo(void *bank, void *names, void *words, void **win, void *mon, WorldtradeRec *rec, void *g);

void WORLDTRADE_DETAIL_PrintMonName(void *bank, Pane2 *pane, const u16 *name, void *mon, Pane2 *pane2, void *g);

void WORLDTRADE_DETAIL_LoadMonGraphics(void *mon);

void WORLDTRADE_DETAIL_DrawRequestWindow(WorldtradeWork *p);

#include "worldtrade_title.h"




#include "worldtrade_adapter.h"
#include "../version.h"




extern int (*g_02203CF0[])(u8 *);

extern struct DispConfig g_022034AC;

extern struct BgTemplate g_022034DC;

extern struct BgTemplate g_022034BC;

extern struct BgTemplate g_022034FC;

extern const WorldtradeWinDef tbl_0220351C[];

/*
 * note: 2026-10-05 recoup: WIPE_SYS_Start declared with an int return (first-check lever). With struct the
 *   literal 1 stayed in r4 for the stack store, r1, r2 and the return (4 B differ); with int the
 *   constants are rematerialised as in the original. The other callees stay void as in their matched files.
 */
int WORLDTRADE_DETAIL_Init(WorldtradeWork *p)
{
    void *mon;
    int index;
    mon=WORLDTRADE_NoOp(*(void **)(*(u8 **)p));
    WORLDTRADE_DETAIL_CreateStrings(p);
    WORLDTRADE_DETAIL_SetupBgPlanes();
    WORLDTRADE_TITLE_ScrollBg(p,0,0);
    WORLDTRADE_DETAIL_LoadBgGraphics(p);
    WORLDTRADE_DETAIL_CreateWindows((WorldtradeWork *)p);
    WORLDTRADE_DETAIL_CreateActors(p);
    WORLDTRADE_DETAIL_PrintMonInfo(((struct WorldtradeWork *)p)->bank,((struct WorldtradeWork *)p)->msg[1],((struct WorldtradeWork *)p)->words,(void **)((u8 *)&((struct WorldtradeWork *)p)->win_u16),POKE_TOOL_CastToBoxParam(mon),(WorldtradeRec *)((struct WorldtradeWork *)p)->ent[0].rec,(u8 *)&((struct WorldtradeWork *)p)->printer);
    WORLDTRADE_DETAIL_PrintMonName(((struct WorldtradeWork *)p)->bank,(Pane2 *)((u8 *)&((struct WorldtradeWork *)p)->pane2),MYSTATUS_GetName(((struct WorldtradeWork *)p)->ctx->myStatus),mon,(Pane2 *)((u8 *)&((struct WorldtradeWork *)p)->pane3),(u8 *)&((struct WorldtradeWork *)p)->printer);
    index=WORLDTRADE_DEPOSIT_FindLevelBracketIndex((*(s8 *)&((struct WorldtradeWork *)p)->padE4[243]),(*(s8 *)&((struct WorldtradeWork *)p)->padE4[244]),0);
    WORLDTRADE_DEPOSIT_DrawRequestWindowAlt((void *)(((struct WorldtradeWork *)p)->bank),(void *)(((struct WorldtradeWork *)p)->msg[1]),((struct WorldtradeWork *)p)->words,(void **)((u8 *)&((struct WorldtradeWork *)p)->title),*(s16 *)&((struct WorldtradeWork *)p)->ent[0].rec[4],(*(s8 *)&((struct WorldtradeWork *)p)->padE4[242]),index,(void *)((u8 *)&((struct WorldtradeWork *)p)->printer));
    WORLDTRADE_DETAIL_LoadMonGraphics(mon);
    WIPE_SYS_Start((void *)3,1,1,0,6,1,0x48);
    p->state=0;
    p->keepBgLayers=0;
    return 1;
}

/*
 * WorldtradeState-table dispatch through the table at 0x02203CF0.
 */
int WORLDTRADE_DETAIL_CallStateHandler(u8 *p)
{
    return g_02203CF0[((struct WorldtradeWork *)p)->state](p);
}

int WORLDTRADE_DETAIL_Exit(WorldtradeWork *p) {WORLDTRADE_DETAIL_DeleteActors(p);WORLDTRADE_DETAIL_DeleteStrings(p);WORLDTRADE_DETAIL_DeleteWindows((char *)p);WORLDTRADE_DETAIL_ExitBgPlanes();WORLDTRADE_TITLE_ExitBgPlanes(p);CLACT_SetActorDrawEnable((*(void * *)&p->scrollBarObj),0);WORLDTRADE_AdvanceScreenId(p);return 0;}

/*
 * Three-layer bring-up after the display restore, with engine-B plane 0x16
 * toggled and layers 2 and 3 both 020414EC'd and tilemap-cleared.
 */
void WORLDTRADE_DETAIL_SetupBgPlanes(void)
{
    struct DispConfig c = g_022034AC;
    u32 v = BG_SYS_GetSubVisiblePlanes();

    BG_SYS_SetGraphicsMode(&c);
    BG_SYS_SetSubVisiblePlanes(v);
    BG_SYS_SetSubPlaneVisible(0x16, 1);
    {
        struct BgTemplate t = g_022034DC;
        BG_SYS_InitBgLayer(2, &t, 0);
    }
    BG_SYS_ClearSlot(2);
    BG_SYS_SetPlaneVisible(2, 1);
    {
        struct BgTemplate t = g_022034BC;
        BG_SYS_InitBgLayer(1, &t, 0);
    }
    BG_SYS_SetPlaneVisible(1, 1);
    {
        struct BgTemplate t = g_022034FC;
        BG_SYS_InitBgLayer(3, &t, 0);
    }
    BG_SYS_ClearSlot(3);
    BG_SYS_SetPlaneVisible(3, 1);
    BG_SYS_InitRun(2, 0x20, 0, 0x48);
    BG_SYS_InitRun(3, 0x20, 0, 0x48);
}

/*
 * Poke the channel-selection helper with 0, 1, 2, 3 in turn.
 */
void WORLDTRADE_DETAIL_ExitBgPlanes(void)
{
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(3);
}

void WORLDTRADE_DETAIL_LoadBgGraphics(WorldtradeWork *p)
{
    void *h;
    h = ARC_TOOL_CreateHandle(0x60, 0x48);
    ARC_UTIL_UploadPaletteFromHandleWhole(h, 6, 0, 0, 0x60, 0x48);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    BMP_MENUWORK_LoadCharAndPltt(2, 1, 0xe, 0, 0x48);
    BMP_MENUWORK_LoadCharAndPltt(2, 0x1f, 0xb, 0, 0x48);
    ARC_UTIL_UploadBgCharFromHandle(h, 0x10, 1, 0, 0, 1, 0x48);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 0x16, 1, 0, 0x600, 1, 0x48);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x20, 0x20, 0x48);
    WORLDTRADE_TITLE_LoadSubBgSwap(p);
    ARC_TOOL_DeleteHandle(h);
}

void WORLDTRADE_DETAIL_CreateActors(WorldtradeWork *p)
{
    WorldtradeObjPos pos;
    MI_CpuFill8(&pos, 0, sizeof(pos));
    pos.x = 0xd0;
    pos.y = 0x3a;
    p->obj = CLACT_CreateActor((struct Unit *)p->res, (uptr)p->set[0], (uptr)p->set[1], (uptr)p->set[2], (const struct ActorInitParam *)&pos, 0, 0x48);
    CLACT_SetActorAutoAnim(p->obj, 1);
    CLACT_SetActorAnimSeq(p->obj, 0x24);
    CLACT_SetActorBgPriority(p->obj, 1);
    CLACT_SetActorDrawEnable(p->obj, 1);
    GFL_NET_RefreshWmIconAtTopRight(0, 0x48);
}

/*
 * Tail call into CLACT_DeleteActor with the pointer held at +0xd08.
 */
void WORLDTRADE_DETAIL_DeleteActors(WorldtradeWork *p)
{
    CLACT_DeleteActor((struct ClactActor *)(*(struct Actor **)&p->obj));
}

void WORLDTRADE_DETAIL_CreateWindows(WorldtradeWork *p)
{
    int i;
    struct BmpWin *w;
    p->frame=BMP_WIN_Create(2,(u8)2,(u8)21,(u8)27,2,13,(u16)1);
    BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)p->frame)),0);
    w=p->frame;
    BMP_WIN_TransferChars((struct BmpWin *)w);
    BMP_WIN_MakeScreen((struct BmpWin *)w);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)w));
    p->side=BMP_WIN_Create(2,(u8)21,(u8)15,(u8)10,4,13,(u16)1);
    w=p->side;
    BMP_WIN_TransferChars((struct BmpWin *)w);
    BMP_WIN_MakeScreen((struct BmpWin *)w);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)w));
    for(i=0;i<14;i++) {
        p->item_u14[i]=BMP_WIN_Create(3,(u8)tbl_0220351C[i].x,(u8)tbl_0220351C[i].y,(u8)tbl_0220351C[i].w,tbl_0220351C[i].h,13,(u16)1);
        BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)p->item_u14[i])),0);
        w=p->item_u14[i];
        BMP_WIN_TransferChars((struct BmpWin *)w);
        BMP_WIN_MakeScreen((struct BmpWin *)w);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)w));
    }
    WORLDTRADE_TITLE_CreateMenuWindow(p,2);
}

/*
 * tail: 021FC526..021FC528 is two zero alignment bytes.
 */
void WORLDTRADE_DETAIL_DeleteWindows(char *p)
{
    int i;
    WORLDTRADE_ADAPTER_DeletePrintStream((struct WorldtradeObj *)((struct Actor *)((u8 *)&((struct WorldtradeWork *)p)->printer)));
    BMP_WIN_Delete(((WorldtradeWork *)p)->msgWin);
    BMP_WIN_Delete(((WorldtradeWork *)p)->d40);
    BMP_WIN_Delete(((WorldtradeWork *)p)->side_p2[0]);
    for (i = 0; i < 14; i++) {
        BMP_WIN_Delete(((struct WorldtradeWork *)p)->win_u16[i]);
    }
}

void WORLDTRADE_DETAIL_CreateStrings(WorldtradeWork *p)
{
    int i;
    p->str = STRBUF_Create(0xb4, 0x48);
    p->titleStr = MSGDATA_AllocString(p->bank, 0x2d);
    for (i = 0; i < 10; i++) {
        p->nameStr[i] = STRBUF_Create(0x14, 0x48);
    }
}

void WORLDTRADE_DETAIL_DeleteStrings(WorldtradeWork *p) {int i;for(i=0;i<10;i++) STRBUF_Delete((struct Strbuf *)p->nameStr[i]);STRBUF_Delete(*(struct Strbuf * *)&p->str);STRBUF_Delete(*(struct Strbuf * *)&p->titleStr);}

int WORLDTRADE_DETAIL_StateStart(WorldtradeWork *p) {p->state=1;return 2;}

int WORLDTRADE_DETAIL_StateMainInput(WorldtradeWork *p)
{
    void *q;
    q = WORLDTRADE_NoOp(**(void ** *)(void **)&p->ctx);
    if ((KEY_GetTrg() & 1) || TOUCHPANEL_GetTrg()) {
        WORLDTRADE_DETAIL_PrintMessage((u8 *)p, 5, 1, 0, 0xf0f, q);
        WORLDTRADE_SetNextState(p, 3, 7);
        GFL_USE_PlaySeDefaultVolume(0x54c);
    } else if (KEY_GetTrg() & 2) {
        p->state = 2;
        WORLDTRADE_SetStateAndReturn(p, 1, 0);
        GFL_USE_PlaySeDefaultVolume(0x551);
    }
    return 2;
}

int WORLDTRADE_DETAIL_StateStartWipeOut(WorldtradeWork *p, int unused1)
{
    WIPE_SYS_Start((void *)3, 0, 0, 0, 6, 1, 0x48);
    p->state = 0;
    return 3;
}

/*
 * Build, kick the two fixed helpers and latch state 6.
 */
int WORLDTRADE_DETAIL_StateOpenConfirm(WorldtradeWork *p)
{
    WORLDTRADE_OpenTaskMenuYesNo(p, 0x14, 0x16a, 8, 2, 1);
    WORLDTRADE_ClearBlendRegs();
    WORLDTRADE_SetBrightnessOut(1);
    p->state = 6;
    return 2;
}

/*
 * spelling: if/else keeps the first arm before the second compare; switch moved both compares ahead.
 */
int WORLDTRADE_DETAIL_StateConfirmYesNoInput(WorldtradeWork *p)
{
    unsigned r;
    r = WORLDTRADE_UpdateTaskMenuYesNo((WorldtradeWork *)p);
    if (r == 1) {
        WORLDTRADE_CloseTaskMenu((WorldtradeWork *)p);
        p->state_i = 2;
        (p->eb4) = 1;
        WORLDTRADE_SetStateAndReturn(p, 7, 8);
        WORLDTRADE_DETAIL_DrawRequestWindow(p);
    } else if (r == 2) {
        WORLDTRADE_CloseTaskMenu((WorldtradeWork *)p);
        p->state_i = 0;
        BMP_MENUWORK_DrawWindowBorder(p->d40, 0);
        WORLDTRADE_DETAIL_DrawRequestWindow(p);
    }
    return 2;
}

int WORLDTRADE_DETAIL_StateCreateMenu(WorldtradeWork *p)
{
    p->de8 = BMP_MENUWORK_Create(2, 0x48);
    BMP_MENUWORK_AddMsgItem((BmpMenuWork *)p->de8, (struct MsgBank *)((p->bank)), 0x3d, 1, 0x48);
    BMP_MENUWORK_AddMsgItem((BmpMenuWork *)p->de8, (struct MsgBank *)((p->bank)), 0x3e, 2, 0x48);
    WORLDTRADE_OpenTaskMenuList(p, 2, 2, 0x14);
    WORLDTRADE_SetBrightnessOut(1);
    p->state = 8;
    return 2;
}

int WORLDTRADE_DETAIL_StateMenuInput(WorldtradeWork *p)
{
    int r;
    void *q;
    r = WORLDTRADE_UpdateTaskMenuList((WorldtradeWork *)p);
    if (r == 1) {
        WORLDTRADE_CloseTaskMenuList((WorldtradeWork *)p);
        BMP_MENUWORK_Delete(p->de8);
        q = WORLDTRADE_NoOp(**(void ** *)(void **)&p->ctx);
        if (WORLDTRADE_BOX_IsHoldingMail(q) && POKEPARTY_GetCount(p->ctx->party) == 6) {
            WORLDTRADE_DETAIL_PrintMessage((u8 *)p, 0x2a, 1, 0, 0xf0f, q);
            WORLDTRADE_SetNextState(p, 3, 1);
            return 2;
        }
        WORLDTRADE_DETAIL_PrintMessage((u8 *)p, 6, 1, 0, 0xf0f, q);
        WORLDTRADE_SetNextState(p, 3, 5);
        WORLDTRADE_DETAIL_DrawRequestWindow(p);
    } else if (r == 2 || r == -2) {
        WORLDTRADE_CloseTaskMenuList((WorldtradeWork *)p);
        BMP_MENUWORK_Delete(p->de8);
        p->state = 2;
        WORLDTRADE_SetStateAndReturn(p, 1, 0);
        WORLDTRADE_DETAIL_DrawRequestWindow(p);
    }
    return 2;
}

int WORLDTRADE_DETAIL_StateWaitMessage(u8 *p)
{
    if (WORLDTRADE_ADAPTER_IsStreamBusy((PrintStreamCtx *)((u8 *)&((struct WorldtradeWork *)p)->printer)) == 0) {
        ((WorldtradeWork *)p)->state = ((WorldtradeWork *)p)->returnState;
    }
    return 2;
}

/*
 * When the build query answers 0, bump the countdown at +0xdfc and roll state when it passes 0x2d.
 */
int WORLDTRADE_DETAIL_StateWaitMessageTimed(u8 *p)
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
 * The two-parameter member of the 021F7538 family: an extra 0201EE84 call
 * keyed by the sixth argument, the same 0xb6c/0xb88 fields and the same
 * p+0xd40 window group in the other order.
 */
void WORLDTRADE_DETAIL_PrintMessage(u8 *p, u32 msgId, u32 unused1, u32 unused2, u32 unused3, void *mon)
{
    struct Strbuf *v;
    struct BmpWin *h;

    WORDSET_SetSlotMonSpeciesName(((WorldtradeWork *)p)->words, 0, (void *)mon);
    v = MSGDATA_AllocString(((WorldtradeWork *)p)->bank_u, msgId);
    WORDSET_CopyTaggedText(*(struct WordSet **)&((WorldtradeWork *)p)->words, (void *)(((WorldtradeWork *)p)->str), (void *)v);
    BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)((WorldtradeWork *)p)->frame)), 0xf);
    BMP_MENUWORK_DrawWindow((void *)(((WorldtradeWork *)p)->frame), 0, 1, 0xe);
    h = ((WorldtradeWork *)p)->frame;
    BMP_WIN_TransferChars((struct BmpWin *)h);
    BMP_WIN_MakeScreen((struct BmpWin *)h);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)h));
    WORLDTRADE_ADAPTER_QueuePrintDefaultColor((void *)(((WorldtradeWork *)p)->frame), 0, (void *)(((WorldtradeWork *)p)->str), 0, 0, (u8 *)&((struct WorldtradeWork *)p)->printer);
    STRBUF_Delete(v);
}

/*
 * Mode table: 0 -> 0, 1 -> 0x14c0, 2 -> 0xc80, anything else 0.
 */
u16 WORLDTRADE_DETAIL_GetModeColor(int mode)
{
    switch (mode) {
    case 0:
        return 0;
    case 1:
        return 0x53 << 6;
    case 2:
        return 0x32 << 6;
    default:
        return 0;
    }
}

void WORLDTRADE_DETAIL_PrintMonInfo(void *bank, void *names, void *words, void **win, void *mon, WorldtradeRec *rec, void *printer)
{
    u32 lv;
    void *sname;
    void *smode;
    void *s70;
    void *s71;
    void *s4f;
    void *s41;
    void *nick;
    void *ot;
    int mode;
    int name;
    u32 flag;
    int key;
    int i;

    nick = STRBUF_Create(0x1a, 0x48);
    ot = STRBUF_Create(0x26, 0x48);
    POKE_TOOL_GetBoxValue(mon, 0x73, (uptr)nick);
    name = rec->name;
    mode = rec->mode;
    key = rec->key;
    lv = POKE_TOOL_GetBoxValue(mon, 6, 0);
    flag = POKE_TOOL_GetBoxValue(mon, 0xAD, 0);
    s4f = MSGDATA_AllocString(bank, 0x4F);
    smode = MSGDATA_AllocString(bank, tbl_02202EB0[mode]);
    s70 = MSGDATA_AllocString(bank, 0x70);
    WORDSET_SetSlotNumber(words, 3, key, 3, 0, PM_LANG_HALF_WIDTH_DIGITS);
    s71 = WORLDTRADE_ADAPTER_CreateString(words, bank, 0x71, 0x48);
    sname = MSGDATA_AllocString(names, name);
    FILE_UTIL_ReadString(ot, (u16)lv, 0x48);
    s41 = MSGDATA_AllocString(bank, 0x41);
    for (i = 0; i < 6; i++) {
        BMP_Clear(BMP_WIN_GetBmp(win[i]), 0);
    }
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[0], nick, 0, 0, 0, 0x440, printer);
    if (mode != 3 && flag != 0) {
        WORLDTRADE_INPUT_PrintStringAlignedLine(win[0], smode, 0x40, 0, 0, WORLDTRADE_DETAIL_GetModeColor(mode), printer);
    }
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[1], sname, PM_LANG_JA(1, 0), 0, 0, 0x440, printer);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[2], s70, 0, 0, 0, 0x440, printer);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[3], s71, 0, 0, 0, 0x440, printer);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[4], s4f, 0, 0, 0, 0x3C40, printer);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[5], ot, PM_LANG_JA(1, 0), 0, 0, 0x440, printer);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[6], s41, 0, 0, 0, 0x3C40, printer);
    STRBUF_Delete(s4f);
    STRBUF_Delete(ot);
    STRBUF_Delete(s70);
    STRBUF_Delete(s71);
    STRBUF_Delete(smode);
    STRBUF_Delete(nick);
    STRBUF_Delete(sname);
    STRBUF_Delete(s41);
}

void WORLDTRADE_DETAIL_PrintMonName(void *bank, Pane2 *pane, const u16 *name, void *mon, Pane2 *pane2, void *printer)
{
    void *s0;
    void *s1;
    void *t0;
    void *t1;

    s0 = STRBUF_Create(0x22, 0x48);
    s1 = STRBUF_Create(0x22, 0x48);
    t0 = MSGDATA_AllocString(bank, 0x37);
    STRBUF_SetString(s0, name);
    t1 = MSGDATA_AllocString(bank, WORLDTRADE_MSG(0xC2));
    POKE_TOOL_GetPartyValue(mon, 0x8D, (uptr)s1);
    WORLDTRADE_INPUT_PrintStringAlignedLine(pane->win0, t0, 0, 0, 0, 0x3C40, printer);
    WORLDTRADE_INPUT_PrintStringAlignedLine(pane->win1, s0, 0, 0, 0, 0x440, printer);
    WORLDTRADE_INPUT_PrintStringAlignedLine(pane2->win0, t1, 0, 0, 0, 0x3C40, printer);
    WORLDTRADE_INPUT_PrintStringAlignedLine(pane2->win1, s1, PM_LANG_JA(1, 0), 0, 0, 0x440, printer);
    STRBUF_Delete(t0);
    STRBUF_Delete(s0);
    STRBUF_Delete(t1);
    STRBUF_Delete(s1);
}

void WORLDTRADE_DETAIL_LoadMonGraphics(void *mon)
{
    NNSG2dCharacterData *pal;
    void *h;
    u32 arc;
    u32 species;
    u32 form;
    u32 shiny;
    u32 id;

    h = (void *)POKEGRA_LoadCharDataPP(&pal, POKE_TOOL_CastToBoxParam(mon), 0, 0x48);
    DC_FlushRange(pal->pRawData, 0x1200);
    GX_LoadOBJ(pal->pRawData, 0x3F80, 0x1200);
    GFL_HEAP_Free(h);
    arc = POKEGRA_GetArcID();
    species = POKE_TOOL_GetPartyValue(mon, 5, 0);
    form = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
    shiny = POKE_TOOL_GetPartyValue(mon, 0x6E, 0);
    id = POKEGRA_GetPalArcIndex(arc, species, form, shiny, POKE_TOOL_IsShiny(mon), 0, 0);
    ARC_UTIL_UploadPaletteFromArchiveWhole(POKEGRA_GetArcID(), id, 1, 0x1A0, 0x20, 0x48);
}

void WORLDTRADE_DETAIL_DrawRequestWindow(WorldtradeWork *p)
{
    int n;
    n = WORLDTRADE_DEPOSIT_FindLevelBracketIndex(((Deposit *)&p->single)->want.levelMin, ((Deposit *)&p->single)->want.levelMax, 0);
    WORLDTRADE_DEPOSIT_DrawRequestWindowAlt((void *)p->bank, (void *)p->names, (void *)((p->words)), (void **)((u8 *)((u8 *)&((struct WorldtradeWork *)p)->title)), ((Deposit *)&p->single)->want.species, ((Deposit *)&p->single)->want.form, n, (void *)((u8 *)&((struct WorldtradeWork *)p)->printer));
}
