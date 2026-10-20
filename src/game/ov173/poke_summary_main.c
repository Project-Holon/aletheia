/*
 * file:     poke_summary_main.c
 * unit:     yes
 * function: POKE_SUMMARY_MAIN_Create, POKE_SUMMARY_MAIN_Update, POKE_SUMMARY_MAIN_Delete, POKE_SUMMARY_MAIN_CreateTaskMenu, POKE_SUMMARY_MAIN_DeleteTaskMenu, POKE_SUMMARY_MAIN_UpdateTaskMenu, POKE_SUMMARY_MAIN_InitScreen, POKE_SUMMARY_MAIN_ExitScreen, POKE_SUMMARY_MAIN_VBlankCallback, POKE_SUMMARY_MAIN_SetVramBanks, POKE_SUMMARY_MAIN_InitDisplay, POKE_SUMMARY_MAIN_ExitDisplay, POKE_SUMMARY_MAIN_CreateMsgWindows, POKE_SUMMARY_MAIN_DeleteMsgWindow, POKE_SUMMARY_MAIN_CreateBmpWindows, POKE_SUMMARY_MAIN_DeleteBmpWindows, POKE_SUMMARY_MAIN_CreateText, POKE_SUMMARY_MAIN_DeleteText, POKE_SUMMARY_MAIN_WaitWipe, POKE_SUMMARY_MAIN_HandleInput, POKE_SUMMARY_MAIN_UpdateText, POKE_SUMMARY_MAIN_OpenMenu, POKE_SUMMARY_MAIN_UpdateMenu, POKE_SUMMARY_MAIN_ApplyMove, POKE_SUMMARY_MAIN_ShowTextKind6, POKE_SUMMARY_MAIN_ShowMoveText, POKE_SUMMARY_MAIN_StartWipe, POKE_SUMMARY_MAIN_RefreshMoveList, POKE_SUMMARY_MAIN_PrintAligned, POKE_SUMMARY_MAIN_PrintValue, POKE_SUMMARY_MAIN_DrawMovesPage, POKE_SUMMARY_MAIN_CountMoves, POKE_SUMMARY_MAIN_DrawMoveRow, POKE_SUMMARY_MAIN_RedrawMoveList, POKE_SUMMARY_MAIN_BuildMoveList, POKE_SUMMARY_MAIN_DeleteMoveList, POKE_SUMMARY_MAIN_DrawMoveDetail, POKE_SUMMARY_MAIN_SetTextByKind, POKE_SUMMARY_MAIN_GetRecordWord, POKE_SUMMARY_MAIN_GetMoveWord, POKE_SUMMARY_MAIN_StartTextStream, POKE_SUMMARY_MAIN_ClearWindow, POKE_SUMMARY_MAIN_SoundStateCallback, POKE_SUMMARY_MAIN_CountFreeMoves, POKE_SUMMARY_MAIN_ShowTextKind3, POKE_SUMMARY_MAIN_ClearWindowWaitA, POKE_SUMMARY_MAIN_SetFlagReturn8, POKE_SUMMARY_MAIN_ClearWindowWaitB, POKE_SUMMARY_MAIN_Finish
 * address:  0x021B6100
 * region:   ov173
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
 *   GF_FONT_Create 0x0201D7EC thumb
 *   TCBL_Create 0x0203101C arm
 *   POKE_SUMMARY_ACTOR_PositionMonActor 0x021B7ADC thumb ov173
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   POKE_SUMMARY_ACTOR_StartWipe 0x021B7B60 thumb ov173
 *   POKE_SUMMARY_ACTOR_StartProc 0x021B7B8C thumb ov173
 *   POKE_SUMMARY_ACTOR_StartNetRestart 0x021B7C00 thumb ov173
 *   POKE_SUMMARY_ACTOR_WaitDecide 0x021B8110 thumb ov173
 *   POKE_SUMMARY_ACTOR_ShowTextKind2 0x021B815C thumb ov173
 *   POKE_SUMMARY_ACTOR_ShowTextKind1Or4 0x021B817C thumb ov173
 *   CLACT_DrawSystem 0x0204A600 arm
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   d_021B81FC 0x021B81FC data a4
 *   d_021B81EC 0x021B81EC data a4
 *   POKE_SUMMARY_ACTOR_ToggleTaskMenu 0x021B7EB0 thumb ov173
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   POKE_SUMMARY_ACTOR_CreateActors  0x021B7A00  thumb  ov173
 *   POKE_SUMMARY_ACTOR_CreateSound  0x021B7C44  thumb  ov173
 *   POKE_SUMMARY_ACTOR_SetIdleAnim  0x021B8040  thumb  ov173
 *   POKE_SUMMARY_ACTOR_UpdateSound 0x021B7C7C thumb ov173
 *   POKE_SUMMARY_ACTOR_DeleteSystem 0x021B7694 thumb ov173
 *   TCB_DeleteTask 0x02030EAC arm
 *   POKE_SUMMARY_ACTOR_FlushPendingTransfers 0x021B7908 thumb ov173
 *   BG_SYS_Update 0x020419E4 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   d_02FE0000 0x02FE0000 data a4
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   d_021B8280 0x021B8280 data a4
 *   d_021B82F0 0x021B82F0 data a4
 *   d_021B8330 0x021B8330 data a4
 *   d_021B8290 0x021B8290 data a4
 *   d_021B82B0 0x021B82B0 data a4
 *   d_021B82D0 0x021B82D0 data a4
 *   d_021B8310 0x021B8310 data a4
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole  0x02049B68  arm
 *   ARC_UTIL_LoadPaletteDataFromHandle  0x02049EF4  arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole  0x02049B40  arm
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   d_021B8420 0x021B8420 data a4
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   APP_KEYCURSOR_CreateDefault 0x02028590 thumb
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   POKE_SUMMARY_ACTOR_IsTaskMenuOpen 0x021B7F50 thumb ov173
 *   POKE_SUMMARY_ACTOR_ConfirmDecideById 0x021B80EC thumb ov173
 *   POKE_SUMMARY_ACTOR_OpenDecideWin 0x021B80A4 thumb ov173
 *   POKE_SUMMARY_ACTOR_ConfirmDecide 0x021B80C4 thumb ov173
 *   POKE_SUMMARY_ACTOR_UpdateScrollArrows 0x021B7F64 thumb ov173
 *   POKE_SUMMARY_ACTOR_SetScrollAnim 0x021B7FD0 thumb ov173
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   POKE_SUMMARY_ACTOR_SetSubBrightness 0x021B81B0 thumb ov173
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   d_021B8228 0x021B8228 data a4
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   WAZA_TOOL_GetMaxPP 0x0201C158 thumb
 *   POKE_SUMMARY_ACTOR_LayoutMoveActors 0x021B7968 thumb ov173
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   WORDSET_SetSlotMonNickname 0x0201EEF4 thumb
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   POKE_TOOL_GetBoxValue 0x02017E88 thumb
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   POKE_SUMMARY_ACTOR_SetMoveIcon 0x021B78CC thumb ov173
 *   WORDSET_SetSlotMonSpeciesName 0x0201EE84 thumb
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   WAZA_TOOL_GetParam 0x0201BD28 thumb
 *   WAZA_TOOL_IsAlwaysHit 0x0201C1F4 thumb
 *   POKE_SUMMARY_ACTOR_SetMoveAnim 0x021B79E0 thumb ov173
 *   WORDSET_SetSlotFromMsgCB 0x0201EF34 thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   d_021B8350 0x021B8350 data a4
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStreamCallBack 0x0201CD10 thumb
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   GFL_USE_IsAnySeBusy 0x02006238 thumb
 *   GFL_USE_SetBgmPaused 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_IsBgmPlaying 0x02005F38 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   APP_KEYCURSOR_Update  0x020286C4  thumb  arm9
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb  arm9
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   KEY_GetCont  0x0203630C  arm  arm9
 */

#include "poke_summary_types.h"

struct ProcOwner;
struct GfFont;
struct Tcbl;
struct PrintSys;
struct TcblWork;
struct ProcOwner;
struct MsgBank;
struct TaskMenuRes;
struct TaskMenuState;
struct U16Vec;
struct Node;
struct DispVram;
struct PokeSummaryMainDescriptor;
struct CharBuf;
struct WordSet;
struct TextPrinter;
struct Sound;
struct Ctx;
struct Rec3;
struct TaskMenu;
struct TaskMenuTmpl;
struct StrObj;
struct Cfg;
struct Obj;
struct ScanContext;
struct Slot;
#include "../types.h"

typedef struct {u32 id,value;} Row;

typedef enum { FLAGS_OFFSET=0x3ff8, OFFSET_FORCE_UNSIGNED=0xffffffffu } SharedOffset;

#include "../arm9/bg_sys.h"


typedef struct { u32 a,b,c,d,e,f,g; } PokeSummaryMainEntry;

typedef struct { u32 heap; u8 count; u8 pad[3]; void *items; u32 zero; u8 a,b,c,d; } PokeSummaryMainDescriptor;

typedef int (*Callback)(u8 *);

typedef struct { Callback a,b; } PokeSummaryMainPair;

struct ScanOwner { u8 pad[16]; u16 *table; };

struct ScanContext { struct ScanOwner *owner; };

#include "../arm9/gfl_heap.h"
struct Proc;
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
#include "../arm9/gf_font.h"
struct TcblSystem;
#include "../arm9/tcbl.h"
#include "poke_summary_actor.h"
#include "../arm9/net.h"
#include "../arm9/clact.h"
struct PrintQueue;
#include "../arm9/printsys.h"
#include "../arm9/gfl_heap_wrap.h"
struct GFont;
#include "../arm9/app_taskmenu.h"
struct Strbuf;
#include "../arm9/msgdata.h"
#include "../arm9/strbuf.h"
struct TaskMenuWin;
#include "../arm9/arc_tool.h"
#include "../arm9/wipe.h"
struct TcbTask;
#include "../arm9/gfl_use.h"
struct TcbTask;
#include "../arm9/tcb_list.h"
#include "../arm9/arc_util.h"
#include "../arm9/bmp_menuwork.h"
struct BmpWin;
struct Bmp;
typedef short s16_p07;
#include "../arm9/bmp.h"
struct KeyCursor;
#include "../arm9/app_keycursor.h"
#include "../arm9/wordset.h"
struct Cursor;
#include "../arm9/cursor_move.h"
#include "../arm9/touchpanel.h"
#include "../arm9/bmp_win.h"
struct TextPrinter;
#include "../arm9/key.h"
struct TaskMenuInitWork;
struct TaskMenuWork;
struct PokemonParam;
#include "../arm9/poke_tool.h"
/* The DS code was built against a prototype with a halfword move id; the host build uses the header. */
#ifdef __MWERKS__
#define WAZA_TOOL_GetParam WAZA_TOOL_GetParam_header
#endif
#include "../arm9/waza_tool.h"
#ifdef __MWERKS__
#undef WAZA_TOOL_GetParam
extern u32 WAZA_TOOL_GetParam(u16 move, u32 param);
#endif
struct BoxPokemon;
struct Actor;
struct BmpMenuWork;
#include "../arm9/msg_speed.h"
int POKE_SUMMARY_MAIN_Create(struct ProcOwner *obj, int unused, u8 *input);
int POKE_SUMMARY_MAIN_Update(void *unused0,u32 *state,void *unused2,u8 *p);
int POKE_SUMMARY_MAIN_Delete(void *p,u32 a,u32 b,char *ctx);
void POKE_SUMMARY_MAIN_CreateTaskMenu(u8 *p);
void POKE_SUMMARY_MAIN_DeleteTaskMenu(u8 *p);
void POKE_SUMMARY_MAIN_UpdateTaskMenu(int *p);
void POKE_SUMMARY_MAIN_InitScreen(u8 *p);
void POKE_SUMMARY_MAIN_ExitScreen(char *p);
void POKE_SUMMARY_MAIN_VBlankCallback(struct TcbTask *unused, void *p);
void POKE_SUMMARY_MAIN_SetVramBanks(void);
void POKE_SUMMARY_MAIN_InitDisplay(void);
void POKE_SUMMARY_MAIN_ExitDisplay(void);
void POKE_SUMMARY_MAIN_CreateMsgWindows(u8 *p, u8 *q);
int POKE_SUMMARY_MAIN_DeleteMsgWindow(int *p);
void POKE_SUMMARY_MAIN_CreateBmpWindows(u8 *p);
void POKE_SUMMARY_MAIN_DeleteBmpWindows(char *p);
void POKE_SUMMARY_MAIN_CreateText(char *p);
void POKE_SUMMARY_MAIN_DeleteText(char *p);
int POKE_SUMMARY_MAIN_WaitWipe(int *p);
int POKE_SUMMARY_MAIN_HandleInput(char *p);
int POKE_SUMMARY_MAIN_UpdateText(char *p);
int POKE_SUMMARY_MAIN_OpenMenu(u8 *p);
int POKE_SUMMARY_MAIN_UpdateMenu(u8 *p);
int POKE_SUMMARY_MAIN_ApplyMove(char **p);
int POKE_SUMMARY_MAIN_ShowTextKind6(int *p);
int POKE_SUMMARY_MAIN_ShowMoveText(char *p);
int POKE_SUMMARY_MAIN_StartWipe(char *p);
void POKE_SUMMARY_MAIN_RefreshMoveList(char *p);
void POKE_SUMMARY_MAIN_PrintAligned(char *p, int index, u32 font, u16 w, int align, u8 y);
void POKE_SUMMARY_MAIN_PrintValue(char *p,u32 idx,u32 a,u32 b,u8 c);
void POKE_SUMMARY_MAIN_DrawMovesPage(char *p);
u32 POKE_SUMMARY_MAIN_CountMoves(struct ScanContext *p);
void POKE_SUMMARY_MAIN_DrawMoveRow(char *p,u8 first,u8 row);
void POKE_SUMMARY_MAIN_RedrawMoveList(char *p);
void POKE_SUMMARY_MAIN_BuildMoveList(char *p);
void POKE_SUMMARY_MAIN_DeleteMoveList(char *p);
void POKE_SUMMARY_MAIN_DrawMoveDetail(char *p,int move);
void POKE_SUMMARY_MAIN_SetTextByKind(char *p, u32 kind);
u16 POKE_SUMMARY_MAIN_GetRecordWord(char **p);
unsigned short POKE_SUMMARY_MAIN_GetMoveWord(int *p);
void POKE_SUMMARY_MAIN_StartTextStream(char *p, u32 kind);
void POKE_SUMMARY_MAIN_ClearWindow(char *p);
int POKE_SUMMARY_MAIN_SoundStateCallback(unsigned int state);
u8 POKE_SUMMARY_MAIN_CountFreeMoves(void ***p);
int POKE_SUMMARY_MAIN_ShowTextKind3(u8 *p);
int POKE_SUMMARY_MAIN_ClearWindowWaitA(char *p);
int POKE_SUMMARY_MAIN_ClearWindowWaitB(char *p);
extern Row d_021B81EC[];
extern const Row d_021B81FC[];
extern u8 d_02FE0000[];
extern const struct DispConfig d_021B8280;
extern const struct BgTemplate d_021B82F0,d_021B8330,d_021B8290,d_021B82B0,d_021B82D0,d_021B8310;
extern const PokeSummaryMainEntry d_021B8420[];
extern PokeSummaryMainPair d_021B8228[];
extern const u32 d_021B8350[][11];

int POKE_SUMMARY_MAIN_Create(struct ProcOwner *obj, int unused, u8 *input)
{
    u8 *p;
    GFL_HEAP_CreateChildHeap(1,79,0x50000);
    p=PROCSYS_AllocProcWork((struct Proc *)obj,0x228,79);
    MI_CpuFill8(p,0,0x228);
    ((struct PokeSummaryWork *)p)->mon=(struct PokeSummaryMon *)input;
    ((struct PokeSummaryWork *)p)->font=(void *)GF_FONT_Create(23,0,0,0,79);
    ((struct PokeSummaryWork *)p)->tcbl=(void *)TCBL_Create(79,79,32,32);
    POKE_SUMMARY_MAIN_InitScreen(p);
    POKE_SUMMARY_ACTOR_PositionMonActor(p,(u8)(((struct PokeSummaryWork *)p)->mon->selectedIndex),3);
    ((struct PokeSummaryWork *)p)->state=1;
    GFL_NET_RefreshWmIconAtTopRight(1,79);
    return 1;
}

/*
 * extent: final 2 bytes are alignment padding
 */
int POKE_SUMMARY_MAIN_Update(void *unused0,u32 *state,void *unused2,u8 *work)
{
    switch(*state) {
    case 0: *state=POKE_SUMMARY_MAIN_WaitWipe((int *)work);break;
    case 1: *state=POKE_SUMMARY_MAIN_HandleInput((char *)work);break;
    case 2: *state=POKE_SUMMARY_MAIN_UpdateText((char *)work);break;
    case 3: *state=POKE_SUMMARY_MAIN_OpenMenu(work);break;
    case 4: *state=POKE_SUMMARY_MAIN_UpdateMenu(work);break;
    case 5: *state=POKE_SUMMARY_MAIN_ApplyMove((char **)work);break;
    case 6: *state=POKE_SUMMARY_MAIN_ShowTextKind6((int *)work);break;
    case 7: *state=POKE_SUMMARY_MAIN_ShowMoveText((char *)work);break;
    case 8: *state=POKE_SUMMARY_MAIN_StartWipe((char *)work);break;
    case 9: return 1;
    case 10: *state=POKE_SUMMARY_ACTOR_StartWipe(work);break;
    case 11: *state=POKE_SUMMARY_ACTOR_StartProc((char *)work);return 0;
    case 12: *state=POKE_SUMMARY_ACTOR_StartNetRestart(work);return 0;
    case 13: *state=POKE_SUMMARY_ACTOR_WaitDecide(work);break;
    case 14: *state=POKE_SUMMARY_ACTOR_ShowTextKind2((char *)work);break;
    case 15: *state=POKE_SUMMARY_ACTOR_ShowTextKind1Or4((char *)work);break;
    }
    POKE_SUMMARY_MAIN_UpdateTaskMenu((int *)work);
    CLACT_DrawSystem();
    TCBL_Main(((struct PokeSummaryWork *)work)->tcbl);
    PRINTSYS_QUE_Main(((struct PokeSummaryWork *)work)->printQueue);
    return 0;
}

int POKE_SUMMARY_MAIN_Delete(void *work,u32 unused,u32 args,char *ctx) { POKE_SUMMARY_MAIN_ExitScreen(ctx); TCBL_Destroy(((struct PokeSummaryWork *)ctx)->tcbl); GF_FONT_Delete(((struct PokeSummaryWork *)ctx)->font); PROCSYS_FreeProcWork(work); GFL_HEAP_DeleteChecked(79); return 1; }

void POKE_SUMMARY_MAIN_CreateTaskMenu(u8 *work)
{
    int i;
    const Row *r;
    ((struct PokeSummaryWork *)work)->printQueue=(void *)PRINTSYS_QUE_Create((unsigned int)79);
    ((struct PokeSummaryWork *)work)->taskMenuRes=APP_TASKMENU_RES_Create(4,10,((struct PokeSummaryWork *)work)->font,((struct PokeSummaryWork *)work)->printQueue,79);
    for(i=0;i<2;i++) {
        r=&d_021B81FC[i];
        ((struct PokeSummaryWork *)work)->moveEntries[i].text=MSGDATA_AllocString(((struct PokeSummaryWork *)work)->msgBank,r->id);
        ((struct PokeSummaryWork *)work)->moveEntries[i].number=14819;
        ((struct PokeSummaryWork *)work)->moveEntries[i].value=r->value;
    }
    for(i=0;i<2;i++) {
        r=&((Row *)d_021B81EC)[i];
        ((struct PokeSummaryWork *)work)->moveEntries[2+i].text=MSGDATA_AllocString(((struct PokeSummaryWork *)work)->msgBank,r->id);
        ((struct PokeSummaryWork *)work)->moveEntries[2+i].number=14819;
        ((struct PokeSummaryWork *)work)->moveEntries[2+i].value=r->value;
    }
    ((struct PokeSummaryWork *)work)->taskMenuWindows[0]=0;((struct PokeSummaryWork *)work)->taskMenuWindows[1]=0;
}

/*
 * Extent remainder: two zero alignment bytes at 021B638E.
 */
void POKE_SUMMARY_MAIN_DeleteTaskMenu(u8 *work)
{
    POKE_SUMMARY_ACTOR_ToggleTaskMenu((char *)work, 0);
    STRBUF_Delete((struct Strbuf *)(((struct PokeSummaryWork *)work)->moveEntries[0].text));
    STRBUF_Delete((struct Strbuf *)(((struct PokeSummaryWork *)work)->moveEntries[1].text));
    STRBUF_Delete((struct Strbuf *)(((struct PokeSummaryWork *)work)->moveEntries[2].text));
    STRBUF_Delete((struct Strbuf *)(((struct PokeSummaryWork *)work)->moveEntries[3].text));
    APP_TASKMENU_RES_Delete((struct TaskMenuRes *)(((struct PokeSummaryWork *)work)->taskMenuRes));
    PRINTSYS_QUE_Delete((struct PrintQueue *)(((struct PokeSummaryWork *)work)->printQueue));
}

void POKE_SUMMARY_MAIN_UpdateTaskMenu(int *work)
{
    if (((struct PokeSummaryWork *)work)->taskMenuWindows[0]) {
        APP_TASKMENU_WIN_Update((struct TaskMenuWin *)(((struct PokeSummaryWork *)work)->taskMenuWindows[0]));
        APP_TASKMENU_WIN_Update((struct TaskMenuWin *)(((struct PokeSummaryWork *)work)->taskMenuWindows[1]));
    }
}

void POKE_SUMMARY_MAIN_InitScreen(u8 *work)
{
    u8 *q;

    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile u32 *)0x04000000 &= 0xffffe0ff;
    *(volatile u32 *)0x04001000 &= 0xffffe0ff;
    q = ARC_TOOL_CreateHandle(0x7c, 0x4f);
    POKE_SUMMARY_MAIN_SetVramBanks();
    POKE_SUMMARY_MAIN_InitDisplay();
    POKE_SUMMARY_MAIN_CreateMsgWindows(work, q);
    POKE_SUMMARY_ACTOR_CreateActors((char *)work, q);
    POKE_SUMMARY_MAIN_CreateText((char *)work);
    POKE_SUMMARY_MAIN_CreateBmpWindows(work);
    POKE_SUMMARY_MAIN_BuildMoveList((char *)work);
    POKE_SUMMARY_MAIN_RefreshMoveList((char *)work);
    POKE_SUMMARY_MAIN_DrawMovesPage((char *)work);
    POKE_SUMMARY_ACTOR_CreateSound(work);
    POKE_SUMMARY_ACTOR_SetIdleAnim(work);
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x4f);
    BG_SYS_SetLcdSwap(1);
    ((struct PokeSummaryWork *)work)->vblankTask = GFL_USE_AddMainTask(POKE_SUMMARY_MAIN_VBlankCallback, work, 0x10);
    ARC_TOOL_DeleteHandle(q);
    POKE_SUMMARY_MAIN_CreateTaskMenu(work);
}

void POKE_SUMMARY_MAIN_ExitScreen(char *work) { POKE_SUMMARY_MAIN_DeleteTaskMenu((u8 *)work); POKE_SUMMARY_ACTOR_UpdateSound((int *)work); POKE_SUMMARY_MAIN_DeleteMoveList(work); POKE_SUMMARY_MAIN_DeleteBmpWindows(work); POKE_SUMMARY_MAIN_DeleteMsgWindow((int *)work); POKE_SUMMARY_MAIN_ExitDisplay(); POKE_SUMMARY_MAIN_DeleteText(work); POKE_SUMMARY_ACTOR_DeleteSystem((u8 *)work); TCB_DeleteTask(((struct PokeSummaryWork *)work)->vblankTask); }

static inline void setShared(u32 base,SharedOffset off) { *(u32 *)(base+off)|=1; }

void POKE_SUMMARY_MAIN_VBlankCallback(struct TcbTask *unused, void *workArg) { char * work = workArg; POKE_SUMMARY_ACTOR_FlushPendingTransfers(work); BG_SYS_Update(); CLACT_VBlankSystem(); setShared((uptr)d_02FE0000,FLAGS_OFFSET); }

void POKE_SUMMARY_MAIN_SetVramBanks(void)
{
    BG_SYS_SetVramBanks((void *)0x021B8250);
}

void POKE_SUMMARY_MAIN_InitDisplay(void)
{
    struct DispConfig cfg;
    struct BgTemplate a,b,c,d,e,f;
    BG_SYS_Create(79);BMP_WIN_Init(79);
    cfg=d_021B8280;BG_SYS_SetGraphicsMode(&cfg);
    a=d_021B82F0;BG_SYS_InitBgLayer(2,&a,0);BG_SYS_ClearSlot(2);
    b=d_021B8330;BG_SYS_InitBgLayer(3,&b,0);BG_SYS_ClearSlot(3);
    c=d_021B8290;BG_SYS_InitBgLayer(4,&c,0);BG_SYS_ClearSlot(4);
    d=d_021B82B0;BG_SYS_InitBgLayer(6,&d,0);BG_SYS_ClearSlot(6);
    e=d_021B82D0;BG_SYS_InitBgLayer(5,&e,0);BG_SYS_ClearSlot(5);
    f=d_021B8310;BG_SYS_InitBgLayer(7,&f,0);BG_SYS_ClearSlot(7);
    BG_SYS_SetPlaneVisible(2,1);BG_SYS_SetPlaneVisible(3,1);BG_SYS_SetPlaneVisible(4,1);
    BG_SYS_SetPlaneVisible(5,1);BG_SYS_SetPlaneVisible(6,1);BG_SYS_SetPlaneVisible(7,1);
    BG_SYS_InitRun(2,32,0,79);BG_SYS_InitRun(4,32,0,79);
    BG_SYS_InitRun(5,32,0,79);BG_SYS_InitRun(2,32,0,79);BG_SYS_InitRun(4,32,0,79);
    *(u16 *)0x04000050=0;*(u16 *)0x04001050=0;
}

/*
 * volatile: 021B66A8 reads and 021B66AE writes hardware halfword.
 */
void POKE_SUMMARY_MAIN_ExitDisplay(void)
{
    BG_SYS_SetSubPlaneVisible(29, 0);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(7);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(2);
    *(volatile unsigned short *)0x04000304 |= 0x8000;
    BG_SYS_Delete();
}

void POKE_SUMMARY_MAIN_CreateMsgWindows(u8 *work, u8 *archiveHandle)
{
    u32 v = 1 << 0xb;
    void *t;

    ARC_UTIL_UploadBgCharFromHandle(archiveHandle, 1, 3, 0, 0, 0, 0x4f);
    ARC_UTIL_UploadBgPaletteFromHandle(archiveHandle, 4, 3, 0, v, 0, 0x4f);
    ARC_UTIL_UploadPaletteFromHandleWhole(archiveHandle, 0, 0, 0, 0, 0x4f);
    ARC_UTIL_UploadBgCharFromHandle(archiveHandle, 1, 7, 0, 0, 0, 0x4f);
    ARC_UTIL_UploadBgPaletteFromHandle(archiveHandle, 2, 7, 0, v, 0, 0x4f);
    ARC_UTIL_UploadPaletteFromHandleWhole(archiveHandle, 0, 4, 0, 0, 0x4f);
    t = ARC_UTIL_LoadPaletteDataFromHandle(archiveHandle, 3, 0, (void **)&((struct PokeSummaryWork *)work)->tmpHandle, 0x4f);
    ((struct PokeSummaryWork *)work)->msgWindow = t;
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x1c0, 0x20, 0x4f);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x1e0, 0x20, 0x4f);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x1e0, 0x20, 0x4f);
    BMP_MENUWORK_LoadCharAndPltt(4, 1, 0xd, 0, 0x4f);
}

int POKE_SUMMARY_MAIN_DeleteMsgWindow(int *work)
{
    return GFL_HEAP_Free((void *)(((struct PokeSummaryWork *)work)->msgWindow));
}

void POKE_SUMMARY_MAIN_CreateBmpWindows(u8 *work)
{
    u32 i;
    uptr h;
    for (i=0;i<16;i++) {
        ((struct PokeSummaryWork *)work)->bmpWindows[i]=(void *)BMP_WIN_Create((u8)d_021B8420[i].a,(u8)d_021B8420[i].b,(u8)d_021B8420[i].c,(u8)d_021B8420[i].d,d_021B8420[i].e,d_021B8420[i].f,(int)1);
        BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)(struct PokeSummaryMainDescriptor *)((struct PokeSummaryWork *)work)->bmpWindows[i])),0);
    }
    h=(uptr)((struct PokeSummaryWork *)work)->bmpWindows[9];
    BMP_WIN_ClearScreen((struct BmpWin *)h);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)h));
    ((struct PokeSummaryWork *)work)->keyCursor=(void *)APP_KEYCURSOR_CreateDefault(15,1,1,79);
}

/*
 * extent: 2 zero alignment bytes at 0x021B684E follow the 38-byte function; no follower.
 */
void POKE_SUMMARY_MAIN_DeleteBmpWindows(char *work) { u32 i; APP_KEYCURSOR_Delete(((struct PokeSummaryWork *)work)->keyCursor); for(i=0;i<16;i++) BMP_WIN_Delete(((struct PokeSummaryWork *)work)->bmpWindows[i]); BMP_WIN_Exit(); }

void POKE_SUMMARY_MAIN_CreateText(char *work) { ((struct PokeSummaryWork *)work)->msgBank=MSGDATA_CreateFromArchive(0,2,204,79); ((struct PokeSummaryWork *)work)->wordSet=WORDSET_CreateDefault(79); ((struct PokeSummaryWork *)work)->strBufA=STRBUF_Create(256,79); ((struct PokeSummaryWork *)work)->strBufB=MSGDATA_AllocString(((struct PokeSummaryWork *)work)->msgBank,25); ((struct PokeSummaryWork *)work)->strBufC=MSGDATA_AllocString(((struct PokeSummaryWork *)work)->msgBank,31); }

void POKE_SUMMARY_MAIN_DeleteText(char *work) { MSGDATA_Delete(((struct PokeSummaryWork *)work)->msgBank); WORDSET_Delete(((struct PokeSummaryWork *)work)->wordSet); STRBUF_Delete(((struct PokeSummaryWork *)work)->strBufA); STRBUF_Delete(((struct PokeSummaryWork *)work)->strBufB); STRBUF_Delete(((struct PokeSummaryWork *)work)->strBufC); }

int POKE_SUMMARY_MAIN_WaitWipe(int *work)
{
    if (WIPE_SYS_EndCheck() == 1)
        return ((struct PokeSummaryWork *)work)->state;
    return 0;
}

int POKE_SUMMARY_MAIN_HandleInput(char *work)
{
    u32 v;
    ((struct PokeSummaryWork *)work)->cursorIndex=CURSOR_MOVE_GetCurrent((struct Cursor *)(*(struct Sound * *)&((struct PokeSummaryWork *)work)->sound));
    v=CURSOR_MOVE_PollRepeatInput((struct Cursor *)(*(struct Sound * *)&((struct PokeSummaryWork *)work)->sound));
    switch(v) {
    case 0:case 1:case 2:case 3:
        if(TOUCHPANEL_GetTrg()==0) {
            if(((struct PokeSummaryWork *)work)->mon->scrollIndex+v < ((struct PokeSummaryWork *)work)->moveCount) {
                GFL_USE_PlaySeDefaultVolume(0x54c);
                return POKE_SUMMARY_ACTOR_ShowTextKind1Or4(work);
            }
        } else {
            if(((struct PokeSummaryWork *)work)->mon->scrollIndex+v < ((struct PokeSummaryWork *)work)->moveCount)
                GFL_USE_PlaySeDefaultVolume(0x54c);
        }
        break;
    case 4:case 5:break;
    case 6:case 8:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        if(POKE_SUMMARY_ACTOR_IsTaskMenuOpen(work)) return POKE_SUMMARY_ACTOR_ConfirmDecideById(work,14);
        else return POKE_SUMMARY_ACTOR_OpenDecideWin(work,14);
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        POKE_SUMMARY_ACTOR_ToggleTaskMenu(work,0);
        return POKE_SUMMARY_ACTOR_OpenDecideWin(work,14);
    case 7:
        if(POKE_SUMMARY_ACTOR_IsTaskMenuOpen(work)) {
            GFL_USE_PlaySeDefaultVolume(0x54c);
            return POKE_SUMMARY_ACTOR_ConfirmDecide((u8 *)work,15);
        }
        break;
    case -8:
        if(((struct PokeSummaryWork *)work)->mon->scrollIndex!=0) {
            GFL_USE_PlaySeDefaultVolume(0x54c);
            --((struct PokeSummaryWork *)work)->mon->scrollIndex;
            POKE_SUMMARY_MAIN_DrawMoveDetail(work,POKE_SUMMARY_MAIN_GetRecordWord((char **)work));
            POKE_SUMMARY_MAIN_RedrawMoveList(work);
            POKE_SUMMARY_ACTOR_UpdateScrollArrows(work);
            POKE_SUMMARY_ACTOR_SetScrollAnim((u8 *)work,-1);
        }
        break;
    case -4:case -3:case -1:break;
    }
    return 1;
}

int POKE_SUMMARY_MAIN_UpdateText(char *work)
{
    u32 r = PRINTSYS_PrintStreamGetState(((struct PokeSummaryWork *)work)->printStream);
    APP_KEYCURSOR_Update(((struct PokeSummaryWork *)work)->keyCursor, ((struct PokeSummaryWork *)work)->printStream, ((struct PokeSummaryWork *)work)->bmpWindows[7]);
    if (r == 0) {
        if (KEY_GetCont() & 1)
            PRINTSYS_PrintStreamShortWait(((struct PokeSummaryWork *)work)->printStream, 0);
    } else if (r == 2) {
        PRINTSYS_PrintStreamDelete(((struct PokeSummaryWork *)work)->printStream);
        return (int)((struct PokeSummaryWork *)work)->state;
    } else if (r == 1) {
        if ((KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg()) {
            PRINTSYS_PrintStreamReleasePause(((struct PokeSummaryWork *)work)->printStream);
            GFL_USE_PlaySeDefaultVolume(0x547);
        }
    }
    return 2;
}

int POKE_SUMMARY_MAIN_OpenMenu(u8 *work)
{
    PokeSummaryMainDescriptor x;
    x.heap = 79;
    x.count = 2;
    x.items = &((struct PokeSummaryWork *)work)->moveEntries[2];
    x.zero = 0;
    x.a = 21;
    x.b = 8;
    x.c = 10;
    x.d = 3;
    ((struct PokeSummaryWork *)work)->taskMenu = (void *)APP_TASKMENU_OpenMenu((struct TaskMenuInitWork *)(&x), (void *)(((struct PokeSummaryWork *)work)->taskMenuRes));
    POKE_SUMMARY_ACTOR_SetSubBrightness(1);
    return 4;
}

int POKE_SUMMARY_MAIN_UpdateMenu(u8 *work)
{
    int result=4;
    if (APP_TASKMENU_IsFinish((struct TaskMenuWork *)(((struct PokeSummaryWork *)work)->taskMenu))) {
        if (APP_TASKMENU_GetCursorPos((struct TaskMenuWork *)(((struct PokeSummaryWork *)work)->taskMenu)) == 0)
            result=d_021B8228[((struct PokeSummaryWork *)work)->textKind].a(work);
        else
            result=d_021B8228[((struct PokeSummaryWork *)work)->textKind].b(work);
        POKE_SUMMARY_ACTOR_SetSubBrightness(0);
    }
    APP_TASKMENU_UpdateMenu(((struct PokeSummaryWork *)work)->taskMenu);
    if (result != 4) APP_TASKMENU_CloseMenu((struct TaskMenuWork *)(((struct PokeSummaryWork *)work)->taskMenu));
    return result;
}

int POKE_SUMMARY_MAIN_ApplyMove(char **work)
{
    char *q;
    u32 zero;
    q = *work;
    POKE_TOOL_SetPartyValue(((struct PokeSummaryMon *)q)->party, ((struct PokeSummaryMon *)q)->variant + 0x36, POKE_SUMMARY_MAIN_GetRecordWord(work));
    q = *work;
    zero = 0;
    POKE_TOOL_SetPartyValue(((struct PokeSummaryMon *)q)->party, ((struct PokeSummaryMon *)q)->variant + 0x3e, 0);
    q = *work;
    POKE_TOOL_SetPartyValue(((struct PokeSummaryMon *)q)->party, ((struct PokeSummaryMon *)q)->variant + 0x3a, WAZA_TOOL_GetMaxPP(POKE_SUMMARY_MAIN_GetRecordWord(work), 0));
    ((struct PokeSummaryMon *)(*work))->applyFlag = zero;
    return 8;
}

int POKE_SUMMARY_MAIN_ShowTextKind6(int *work)
{
    POKE_SUMMARY_MAIN_StartTextStream((char *)work, 6);
    ((struct PokeSummaryWork *)work)->state = 5;
    return 2;
}

int POKE_SUMMARY_MAIN_ShowMoveText(char *work)
{
    if (((struct PokeSummaryWork *)work)->mon->variant < 4) {
        POKE_SUMMARY_MAIN_StartTextStream(work, 10);
        ((struct PokeSummaryWork *)work)->textKind = 4;
    } else {
        POKE_SUMMARY_MAIN_StartTextStream(work, 7);
        ((struct PokeSummaryWork *)work)->textKind = 3;
    }
    ((struct PokeSummaryWork *)work)->state = 3;
    return 2;
}

int POKE_SUMMARY_MAIN_StartWipe(char *work) { WIPE_SYS_Start(0,0,0,0,6,1,79); ((struct PokeSummaryWork *)work)->state=9; return 0; }

void POKE_SUMMARY_MAIN_RefreshMoveList(char *work) { int n; n=POKE_SUMMARY_MAIN_GetRecordWord((char **)work); if(n!=65535) POKE_SUMMARY_MAIN_DrawMoveDetail(work,n); else POKE_SUMMARY_MAIN_DrawMoveDetail(work,-2); POKE_SUMMARY_ACTOR_LayoutMoveActors(work); }

/*
 * lever: separate u8 width result from u8 coordinate x; otherwise 16 bytes
 *   differ from index/font/x register rotation. Both cases preserve byte
 *   width narrowing and signed division by two before coordinate wrap.
 * domain: all nine direct ov173 calls use align 0..2; sites 021B6CE2=2,
 *   6D00=0,6D36=0,6D90=0,6E24=0,6F88=1,7242=1,728C=1,72B8=0.
 *   At 6DC4 r7 copies zero r4 and stays invariant; at 6F5E r4 becomes 1.
 *   No defined coordinate exists in the original outside this domain.
 * extent: 138 bytes code; +0x8A 00 00 alignment padding, next labelled
 *   function 021B6C84 at +0x8C. No follower or unit.
 */
void POKE_SUMMARY_MAIN_PrintAligned(char *work, int index, u32 font, u16 color, int align, u8 y)
{
    u8 x;
    u8 width;
    switch (align) {
    case 0: x = 0; break;
    case 1:
        width = (u8)PRINTSYS_MeasureWidestLine(((struct PokeSummaryWork *)work)->strBufA, (struct GfFont *)font, 0);
        x = (u8)((u8)(BMP_WIN_GetWidth(((struct PokeSummaryWork *)work)->bmpWindows[index]) * 8) - width);
        break;
    case 2:
        width = (u8)PRINTSYS_MeasureWidestLine(((struct PokeSummaryWork *)work)->strBufA, (struct GfFont *)font, 0);
        x = (u8)(((int)(u8)(BMP_WIN_GetWidth(((struct PokeSummaryWork *)work)->bmpWindows[index]) * 8) - width) / 2);
        break;
    }
    PRINTSYS_PrintColor((struct Bmp *)(BMP_WIN_GetBmp(((struct PokeSummaryWork *)work)->bmpWindows[index])), x, y, (struct Strbuf *)(((struct PokeSummaryWork *)work)->strBufA), (struct GfFont *)((void *)font), color);
}

void POKE_SUMMARY_MAIN_PrintValue(char *work,u32 idx,u32 number,u32 digits,u8 padding) { void *s; s=MSGDATA_AllocString(((struct PokeSummaryWork *)work)->msgBank,idx); WORDSET_SetSlotNumber(((struct PokeSummaryWork *)work)->wordSet,0,number,digits,padding,1); WORDSET_CopyTaggedText(((struct PokeSummaryWork *)work)->wordSet,((struct PokeSummaryWork *)work)->strBufA,s); STRBUF_Delete(s); }

static inline void flush(void *win)
{
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(win));
}

/*
 * lever: temp,bank,mon declarations restore stack homes; derived wide coord=y+16 restores both narrowing sites and the early coordinate update (existing derived-wide-local idiom).
 * blocker-C: 02045CAC verified EXACT, 344B, prior ov070 header arm9-blocker.log;
 * copied unchanged from unit_02045C44.c, using dsi/1.1p1 -O4,p --arm.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char MSGDATA_AllocSite[];
 * extern void *GFL_HEAP_Alloc(u32,u32,int,const char *,u16);
 * extern void GFL_HEAP_Free(void *);
 * extern void ARC_TOOL_ReadHandle(void *,u32,void *);
 * extern void ARC_TOOL_SeekHandle(void *,u32);
 * extern void STRBUF_Clear(void *);
 * extern void STRBUF_SetChars(void *,const void *,u16);
 * extern void MSGDATA_DecryptStrbuf(void *,u32);
 * extern void MSGDATA_RefreshLanguage(struct MsgBank *);
 * void MSGDATA_ReadString(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *     MSGDATA_RefreshLanguage(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         ARC_TOOL_SeekHandle(bank->stream,pos + (index * 8 + 4));
 *         ARC_TOOL_ReadHandle(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = GFL_HEAP_Alloc((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,MSGDATA_AllocSite,0xd6);
 *         if (buf != 0) {
 *             ARC_TOOL_SeekHandle(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream,size,buf);
 *             STRBUF_SetChars(dest,buf,e->len);
 *             GFL_HEAP_Free(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     MSGDATA_DecryptStrbuf(dest,index);
 * }
 * abi: 6BF8 font widened to u32 because original forwards a full word without truncation; 185F4 bare return preserves the visibly loaded pointer argument and live r0 result.
 */
void POKE_SUMMARY_MAIN_DrawMovesPage(char *work)
{
    u32 i;
    u16 move;
    int y;
    int coord;
    void *temp;
    void *bank;
    void *mon;
    MSGDATA_ReadString(((struct PokeSummaryWork *)work)->msgBank,0x23,((struct PokeSummaryWork *)work)->strBufA);
    POKE_SUMMARY_MAIN_PrintAligned(work,9,(uptr)((struct PokeSummaryWork *)work)->font,0x3c40,2,4);
    MSGDATA_ReadString(((struct PokeSummaryWork *)work)->msgBank,0x17,((struct PokeSummaryWork *)work)->strBufA);
    POKE_SUMMARY_MAIN_PrintAligned(work,2,(uptr)((struct PokeSummaryWork *)work)->font,0x440,0,0);
    flush(((struct PokeSummaryWork *)work)->bmpWindows[2]);
    MSGDATA_ReadString(((struct PokeSummaryWork *)work)->msgBank,0x18,((struct PokeSummaryWork *)work)->strBufA);
    POKE_SUMMARY_MAIN_PrintAligned(work,3,(uptr)((struct PokeSummaryWork *)work)->font,0x440,0,0);
    flush(((struct PokeSummaryWork *)work)->bmpWindows[3]);
    temp=STRBUF_Create(256,79);
    MSGDATA_ReadString(((struct PokeSummaryWork *)work)->msgBank,0x27,temp);
    WORDSET_SetSlotMonNickname(((struct PokeSummaryWork *)work)->wordSet,0,((struct PokeSummaryWork *)work)->mon->party);
    WORDSET_CopyTaggedText(((struct PokeSummaryWork *)work)->wordSet,((struct PokeSummaryWork *)work)->strBufA,temp);
    POKE_SUMMARY_MAIN_PrintAligned(work,13,(uptr)((struct PokeSummaryWork *)work)->font,0x3c40,0,4);
    flush(((struct PokeSummaryWork *)work)->bmpWindows[13]);
    bank=MSGDATA_CreateFromArchive(0,2,0xcb,79);
    mon=POKE_TOOL_GetBoxParam(((struct PokeSummaryWork *)work)->mon->party);
    for(i=0;i<4;i++) {
        move=POKE_TOOL_GetBoxValue(mon,0x36+i,0);
        if(move==0) CLACT_SetActorDrawEnable(((struct PokeSummaryWork *)work)->actors[8+i],0);
        else {
            CLACT_SetActorDrawEnable(((struct PokeSummaryWork *)work)->actors[8+i],1);
            POKE_SUMMARY_ACTOR_SetMoveIcon((u8 *)work,move,i);
            MSGDATA_ReadString(bank,move,((struct PokeSummaryWork *)work)->strBufA);
            y=i*32;
            POKE_SUMMARY_MAIN_PrintAligned(work,14,(uptr)((struct PokeSummaryWork *)work)->font,0x3c40,0,y);
            coord=y+16;
            PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct PokeSummaryWork *)work)->bmpWindows[14]),8,coord,((struct PokeSummaryWork *)work)->strBufB,((struct PokeSummaryWork *)work)->font,0x440);
            flush(((struct PokeSummaryWork *)work)->bmpWindows[14]);
            WORDSET_SetSlotNumber(((struct PokeSummaryWork *)work)->wordSet,0,POKE_TOOL_GetBoxValue(mon,0x3a+i,0),2,1,1);
            WORDSET_SetSlotNumber(((struct PokeSummaryWork *)work)->wordSet,1,POKE_TOOL_GetBoxValue(mon,0x42+i,0),2,0,1);
            WORDSET_CopyTaggedText(((struct PokeSummaryWork *)work)->wordSet,((struct PokeSummaryWork *)work)->strBufA,((struct PokeSummaryWork *)work)->strBufC);
            PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct PokeSummaryWork *)work)->bmpWindows[14]),32,coord,((struct PokeSummaryWork *)work)->strBufA,((struct PokeSummaryWork *)work)->font,0x440);
            flush(((struct PokeSummaryWork *)work)->bmpWindows[14]);
        }
    }
    flush(((struct PokeSummaryWork *)work)->bmpWindows[14]);
    MSGDATA_ReadString(((struct PokeSummaryWork *)work)->msgBank,0x25,temp);
    WORDSET_SetSlotMonSpeciesName(((struct PokeSummaryWork *)work)->wordSet,0,((struct PokeSummaryWork *)work)->mon->party);
    WORDSET_CopyTaggedText(((struct PokeSummaryWork *)work)->wordSet,((struct PokeSummaryWork *)work)->strBufA,temp);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct PokeSummaryWork *)work)->bmpWindows[15]),0,0,((struct PokeSummaryWork *)work)->strBufA,((struct PokeSummaryWork *)work)->font,0x440);
    flush(((struct PokeSummaryWork *)work)->bmpWindows[15]);
    MSGDATA_ReadString(((struct PokeSummaryWork *)work)->msgBank,0x26,temp);
    WORDSET_SetSlotNumber(((struct PokeSummaryWork *)work)->wordSet,0,POKE_TOOL_GetBoxValue(mon,0x9e,0),3,1,1);
    WORDSET_CopyTaggedText(((struct PokeSummaryWork *)work)->wordSet,((struct PokeSummaryWork *)work)->strBufA,temp);
    POKE_SUMMARY_MAIN_PrintAligned(work,15,(uptr)((struct PokeSummaryWork *)work)->font,0x440,1,16);
    flush(((struct PokeSummaryWork *)work)->bmpWindows[15]);
    MSGDATA_Delete(bank);
    STRBUF_Delete(temp);
}

/*
 * Inline owner/table struct access restores the bound/index register allocation;
 * an extracted table pointer compiled 36 bytes with 18 concrete differences.
 */
u32 POKE_SUMMARY_MAIN_CountMoves(struct ScanContext *work) { u32 i;for(i=0;i<256;i++)if(work->owner->table[i]==0xffff)break;return i; }

void POKE_SUMMARY_MAIN_DrawMoveRow(char *work,u8 first,u8 row)
{
    int y;
    int index;
    u32 value;
    y=row*24;
    index=first+row;
    if(index>=((struct PokeSummaryWork *)work)->moveCount) return;
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct PokeSummaryWork *)work)->bmpWindows[11]),0,y,*(void **)(*(char * *)&((struct PokeSummaryWork *)work)->menuWork+index*8),((struct PokeSummaryWork *)work)->font,0x3c40);
    flush(((struct PokeSummaryWork *)work)->bmpWindows[11]);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct PokeSummaryWork *)work)->bmpWindows[11]),96,y,((struct PokeSummaryWork *)work)->strBufB,((struct PokeSummaryWork *)work)->font,0x440);
    flush(((struct PokeSummaryWork *)work)->bmpWindows[11]);
    value=WAZA_TOOL_GetMaxPP(*(u32 *)(*(char * *)&((struct PokeSummaryWork *)work)->menuWork+index*8+4),0);
    WORDSET_SetSlotNumber(((struct PokeSummaryWork *)work)->wordSet,0,value,2,1,1);
    WORDSET_SetSlotNumber(((struct PokeSummaryWork *)work)->wordSet,1,value,2,0,1);
    WORDSET_CopyTaggedText(((struct PokeSummaryWork *)work)->wordSet,((struct PokeSummaryWork *)work)->strBufA,((struct PokeSummaryWork *)work)->strBufC);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct PokeSummaryWork *)work)->bmpWindows[11]),120,y,((struct PokeSummaryWork *)work)->strBufA,((struct PokeSummaryWork *)work)->font,0x440);
    flush(((struct PokeSummaryWork *)work)->bmpWindows[11]);
}

void POKE_SUMMARY_MAIN_RedrawMoveList(char *work)
{
    u32 i;
    void *q;
    BMP_Clear(BMP_WIN_GetBmp(((struct PokeSummaryWork *)work)->bmpWindows[11]), 0);
    for (i = 0; i < 4; i++)
        POKE_SUMMARY_MAIN_DrawMoveRow(work, ((struct PokeSummaryWork *)work)->mon->scrollIndex, i);
    q = ((struct PokeSummaryWork *)work)->bmpWindows[11];
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(q));
    BG_SYS_MarkTileDirty(7);
    POKE_SUMMARY_ACTOR_LayoutMoveActors(work);
}

void POKE_SUMMARY_MAIN_BuildMoveList(char *work)
{
    u32 i;
    u16 move;
    void *bank;
    ((struct PokeSummaryWork *)work)->moveCount = POKE_SUMMARY_MAIN_CountMoves((struct ScanContext *)work);
    ((struct PokeSummaryWork *)work)->menuWork = BMP_MENUWORK_Create(((struct PokeSummaryWork *)work)->moveCount, 0x4f);
    i = 0;
    bank = MSGDATA_CreateFromArchive(0, 2, 0xcb, 0x4f);
    for (; i < ((struct PokeSummaryWork *)work)->moveCount; i++) {
        move = ((u16 *)((struct PokeSummaryWork *)work)->mon->moveList)[i];
        if (move != 0xffff) {
            BMP_MENUWORK_AddMsgItem(((struct PokeSummaryWork *)work)->menuWork, bank, move, move, 0x4f);
        } else {
            BMP_MENUWORK_AddMsgItem(((struct PokeSummaryWork *)work)->menuWork, (struct MsgBank *)(*(u32 *)&((struct PokeSummaryWork *)work)->msgBank), 0x20, -2, 0x4f);
            break;
        }
    }
    MSGDATA_Delete(bank);
    ((struct PokeSummaryWork *)work)->reserved1BB = 0;
    ((struct PokeSummaryWork *)work)->selectedRow = ((struct PokeSummaryWork *)work)->mon->selectedIndex;
    POKE_SUMMARY_MAIN_RedrawMoveList(work);
}

void POKE_SUMMARY_MAIN_DeleteMoveList(char *work)
{
    BMP_MENUWORK_Delete(((struct PokeSummaryWork *)work)->menuWork);
}

static inline void clear(void *win)
{
    BMP_WIN_ClearScreen(win);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(win));
}

/*
 * blocker-C: 02045CAC verified EXACT, 344B, prior ov070 header arm9-blocker.log;
 * copied unchanged from unit_02045C44.c, using dsi/1.1p1 -O4,p --arm.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char MSGDATA_AllocSite[];
 * extern void *GFL_HEAP_Alloc(u32,u32,int,const char *,u16);
 * extern void GFL_HEAP_Free(void *);
 * extern void ARC_TOOL_ReadHandle(void *,u32,void *);
 * extern void ARC_TOOL_SeekHandle(void *,u32);
 * extern void STRBUF_Clear(void *);
 * extern void STRBUF_SetChars(void *,const void *,u16);
 * extern void MSGDATA_DecryptStrbuf(void *,u32);
 * extern void MSGDATA_RefreshLanguage(struct MsgBank *);
 * void MSGDATA_ReadString(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *     MSGDATA_RefreshLanguage(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         ARC_TOOL_SeekHandle(bank->stream,pos + (index * 8 + 4));
 *         ARC_TOOL_ReadHandle(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = GFL_HEAP_Alloc((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,MSGDATA_AllocSite,0xd6);
 *         if (buf != 0) {
 *             ARC_TOOL_SeekHandle(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream,size,buf);
 *             STRBUF_SetChars(dest,buf,e->len);
 *             GFL_HEAP_Free(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     MSGDATA_DecryptStrbuf(dest,index);
 * }
 * abi: 6BF8 font extern widened to u32: the original forwards the full p+0x60 word without narrowing.
 */
void POKE_SUMMARY_MAIN_DrawMoveDetail(char *work,int move)
{
    u32 value;
    void *bank;
    int zero;
    zero=0;
    BMP_Clear(BMP_WIN_GetBmp(((struct PokeSummaryWork *)work)->bmpWindows[6]),0);
    BMP_Clear(BMP_WIN_GetBmp(((struct PokeSummaryWork *)work)->bmpWindows[4]),0);
    BMP_Clear(BMP_WIN_GetBmp(((struct PokeSummaryWork *)work)->bmpWindows[5]),0);
    CLACT_SetActorDrawEnable(((struct PokeSummaryWork *)work)->actors[3],0);
    if(move!=zero-2) {
        value=WAZA_TOOL_GetParam(move,3);
        if(value<=1) MSGDATA_ReadString(((struct PokeSummaryWork *)work)->msgBank,0x21,((struct PokeSummaryWork *)work)->strBufA);
        else POKE_SUMMARY_MAIN_PrintValue(work,0x1d,value,3,0);
        POKE_SUMMARY_MAIN_PrintAligned(work,4,(uptr)((struct PokeSummaryWork *)work)->font,0x440,1,0);
        value=WAZA_TOOL_GetParam(move,4);
        if(value==0 || WAZA_TOOL_IsAlwaysHit(move)!=0) MSGDATA_ReadString(((struct PokeSummaryWork *)work)->msgBank,0x21,((struct PokeSummaryWork *)work)->strBufA);
        else POKE_SUMMARY_MAIN_PrintValue(work,0x1e,value,3,0);
        POKE_SUMMARY_MAIN_PrintAligned(work,5,(uptr)((struct PokeSummaryWork *)work)->font,0x440,1,0);
        bank=MSGDATA_CreateFromArchive(0,2,0xca,79);
        MSGDATA_ReadString(bank,move,((struct PokeSummaryWork *)work)->strBufA);
        POKE_SUMMARY_MAIN_PrintAligned(work,6,(uptr)((struct PokeSummaryWork *)work)->font,0x440,0,0);
        MSGDATA_Delete(bank);
        POKE_SUMMARY_ACTOR_SetMoveAnim((u8 *)work,move);
        CLACT_SetActorDrawEnable(((struct PokeSummaryWork *)work)->actors[3],1);
        flush(((struct PokeSummaryWork *)work)->bmpWindows[2]);
        flush(((struct PokeSummaryWork *)work)->bmpWindows[3]);
    } else {
        clear(((struct PokeSummaryWork *)work)->bmpWindows[2]);
        clear(((struct PokeSummaryWork *)work)->bmpWindows[3]);
    }
    flush(((struct PokeSummaryWork *)work)->bmpWindows[6]);
    flush(((struct PokeSummaryWork *)work)->bmpWindows[4]);
    flush(((struct PokeSummaryWork *)work)->bmpWindows[5]);
}

void POKE_SUMMARY_MAIN_SetTextByKind(char *work, u32 kind)
{
    void *str;
    switch (kind) {
    case 0: WORDSET_SetSlotMonNickname(((struct PokeSummaryWork *)work)->wordSet, 0, ((struct PokeSummaryWork *)work)->mon->party); break;
    case 1: WORDSET_SetSlotFromMsgCB(((struct PokeSummaryWork *)work)->wordSet, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)work)); break;
    case 2: WORDSET_SetSlotMonNickname(((struct PokeSummaryWork *)work)->wordSet, 0, ((struct PokeSummaryWork *)work)->mon->party); break;
    case 3:
        WORDSET_SetSlotMonNickname(((struct PokeSummaryWork *)work)->wordSet, 0, ((struct PokeSummaryWork *)work)->mon->party);
        WORDSET_SetSlotFromMsgCB(((struct PokeSummaryWork *)work)->wordSet, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)work)); break;
    case 4:
        WORDSET_SetSlotMonNickname(((struct PokeSummaryWork *)work)->wordSet, 0, ((struct PokeSummaryWork *)work)->mon->party);
        WORDSET_SetSlotFromMsgCB(((struct PokeSummaryWork *)work)->wordSet, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)work)); break;
    case 5:
        WORDSET_SetSlotMonNickname(((struct PokeSummaryWork *)work)->wordSet, 0, ((struct PokeSummaryWork *)work)->mon->party);
        WORDSET_SetSlotFromMsgCB(((struct PokeSummaryWork *)work)->wordSet, 1, POKE_SUMMARY_MAIN_GetMoveWord((int *)work)); break;
    case 6:
        WORDSET_SetSlotMonNickname(((struct PokeSummaryWork *)work)->wordSet, 0, ((struct PokeSummaryWork *)work)->mon->party);
        WORDSET_SetSlotFromMsgCB(((struct PokeSummaryWork *)work)->wordSet, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)work)); break;
    case 7: WORDSET_SetSlotFromMsgCB(((struct PokeSummaryWork *)work)->wordSet, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)work)); break;
    case 8:
        WORDSET_SetSlotMonNickname(((struct PokeSummaryWork *)work)->wordSet, 0, ((struct PokeSummaryWork *)work)->mon->party);
        WORDSET_SetSlotFromMsgCB(((struct PokeSummaryWork *)work)->wordSet, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)work)); break;
    case 9: WORDSET_SetSlotMyStatus(((struct PokeSummaryWork *)work)->wordSet, 2, (void *)(((struct PokeSummaryWork *)work)->mon->myStatus)); break;
    case 10: WORDSET_SetSlotFromMsgCB(((struct PokeSummaryWork *)work)->wordSet, 0, POKE_SUMMARY_MAIN_GetMoveWord((int *)work)); break;
    }
    str = MSGDATA_AllocString(((struct PokeSummaryWork *)work)->msgBank, d_021B8350[((struct PokeSummaryWork *)work)->mon->messageTableIndex][kind]);
    WORDSET_CopyTaggedText(((struct PokeSummaryWork *)work)->wordSet, ((struct PokeSummaryWork *)work)->strBufA, str);
    STRBUF_Delete(str);
}

u16 POKE_SUMMARY_MAIN_GetRecordWord(char **work)
{
    struct PokeSummaryMon *q = (struct PokeSummaryMon *)*work;

    return *(u16 *)((char *)q->moveList + (q->scrollIndex + q->selectedIndex) * 2);
}

unsigned short POKE_SUMMARY_MAIN_GetMoveWord(int *work)
{
    struct PokeSummaryMon *q = ((struct PokeSummaryWork *)work)->mon;

    return POKE_TOOL_GetPartyValue((void *)q->party, q->variant + 0x36, 0);
}

void POKE_SUMMARY_MAIN_StartTextStream(char *work, u32 kind)
{
    u32 zero;
    int speed;
    void *q;
    BMP_Clear(BMP_WIN_GetBmp(((struct PokeSummaryWork *)work)->bmpWindows[7]), 15);
    zero = 0;
    BMP_MENUWORK_DrawWindow((struct BmpWin *)(((struct PokeSummaryWork *)work)->bmpWindows[7]), 0, 1, 13);
    POKE_SUMMARY_MAIN_SetTextByKind((char *)work, kind);
    speed = MSG_SPEED_GetWait();
    ((struct PokeSummaryWork *)work)->printStream = PRINTSYS_PrintStreamCallBack((struct BmpWin *)(*(u32 *)&((struct PokeSummaryWork *)work)->bmpWindows[7]), 0, 0, (struct Strbuf *)((uptr)((struct PokeSummaryWork *)work)->strBufA), (struct GfFont *)((uptr)((struct PokeSummaryWork *)work)->font), speed, (struct Tcbl *)((uptr)((struct PokeSummaryWork *)work)->tcbl), zero, 0x4f, 0xffff, (u8 (*)(u32 arg))((uptr)POKE_SUMMARY_MAIN_SoundStateCallback));
    q = ((struct PokeSummaryWork *)work)->bmpWindows[7];
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(q));
}

void POKE_SUMMARY_MAIN_ClearWindow(char *work)
{
    uptr x;

    BMP_MENUWORK_DrawWindowBorder((void *)(((struct PokeSummaryWork *)work)->bmpWindows[7]), 2);
    x = (uptr)((struct PokeSummaryWork *)work)->bmpWindows[7];
    BMP_WIN_ClearScreen((struct BmpWin *)x);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)x));
}

int POKE_SUMMARY_MAIN_SoundStateCallback(unsigned int state)
{
    switch (state) {
    case 1: return GFL_USE_IsAnySeBusy();
    case 2: return GFL_USE_IsAnySeBusy();
    case 3: GFL_USE_PlaySeDefaultVolume(0x56b); break;
    case 4:
        GFL_USE_SetBgmPaused((unsigned int)1);
        GFL_USE_PushBgm();
        GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
        break;
    case 5:
        if (GFL_USE_IsBgmPlaying() == 0) {
            GFL_USE_PopBgm();
            GFL_USE_SetBgmPaused(0);
        } else {
            return 1;
        }
        break;
    }
    return 0;
}

u8 POKE_SUMMARY_MAIN_CountFreeMoves(void ***work) {u8 i;for(i=0;i<4;i++)if(!POKE_TOOL_GetPartyValue(**work,i+54,0))break;return i;}

int POKE_SUMMARY_MAIN_ShowTextKind3(u8 *work) {POKE_SUMMARY_MAIN_StartTextStream((char *)work,3);(*(u8 **)work)[27]=POKE_SUMMARY_MAIN_CountFreeMoves((void ***)work);((struct PokeSummaryWork *)work)->state=5;return 2;}

/*
 * Extent runs long: 0x021B75BC is an unlabelled follower leaf, so EXACT*.
 */
int POKE_SUMMARY_MAIN_ClearWindowWaitA(char *work)
{
    POKE_SUMMARY_MAIN_ClearWindow(work);
    return 1;
}

int POKE_SUMMARY_MAIN_SetFlagReturn8(u8 **pp) { (*pp)[0x1a] = 1; return 8; }

/*
 * Extent runs long: 0x021B75D4 is an unlabelled follower leaf, so EXACT*.
 */
int POKE_SUMMARY_MAIN_ClearWindowWaitB(char *work)
{
    POKE_SUMMARY_MAIN_ClearWindow(work);
    return 1;
}

int POKE_SUMMARY_MAIN_Finish(u8 *work) { ((struct PokeSummaryWork *)work)->state = 10; return 0; }
