/*
 * file:     wifilogin_message.c
 * unit:     yes
 * function: WIFILOGIN_MSG_Create, WIFILOGIN_MSG_Run, WIFILOGIN_MSG_Delete, WIFILOGIN_MSG_Draw, WIFILOGIN_MSG_DrawWindow, WIFILOGIN_MSG_SetMessage, WIFILOGIN_MSG_SetMessageWithIcon, WIFILOGIN_MSG_IsPrintDone, WIFILOGIN_MSG_RedrawWindow, WIFILOGIN_MSG_ShowMessage, WIFILOGIN_MSG_CloseMessage, WIFILOGIN_MSG_OpenTask, WIFILOGIN_MSG_CloseTask, WIFILOGIN_MSG_UpdateTask, WIFILOGIN_MSG_IsTaskFinish, WIFILOGIN_MSG_GetTaskCursor, WIFILOGIN_MSG_PrintMessage, WIFILOGIN_MSG_RedrawBorder, WIFILOGIN_MSG_GetFrameIdA, WIFILOGIN_MSG_GetFrameIdB, WIFILOGIN_MSG_CreateYesNo, WIFILOGIN_MSG_CreateWork, WIFILOGIN_MSG_DeleteWork, WIFILOGIN_MSG_Update, WIFILOGIN_MSG_SetStepHandler, WIFILOGIN_MSG_RunStep, WIFILOGIN_MSG_CallStep, WIFILOGIN_MSG_StepWipe, WIFILOGIN_MSG_StepWaitWipe, WIFILOGIN_MSG_StepMessage, WIFILOGIN_MSG_StepWaitMessage, WIFILOGIN_MSG_StepExit, WIFILOGIN_MSG_StepWaitExit, WIFILOGIN_MSG_StepMessage2, WIFILOGIN_MSG_StepWaitMessage2, WIFILOGIN_MSG_StepWipe2, WIFILOGIN_MSG_StepFinish, WIFILOGIN_MSG_SetExitFlag
 * address:  0x021D5984
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from wifilogin_disp.c by tools/splitfile.py.
 *
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   GFL_NET_STATE_SetWifiError 0x0203CA04 arm
 *   GFL_NET_ERR_ResetState 0x0200FBA0 thumb
 *   GFL_NET_STATE_ClearErrorMode 0x0203C968 arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GF_PANIC_Fail 0x02034714 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   TCBL_Create 0x0203101C arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   d_021D6628 0x021D6628 data a4
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   WORDSET_Delete 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   PRINTSYS_CTRL_Init 0x02028470 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   GFL_USE_GetMainTaskList 0x020056BC thumb
 *   TIME_ICON_Create 0x0202EE30 thumb
 *   PRINTSYS_CTRL_Update 0x02028484 thumb
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   APP_TASKMENU_SetCursorPos 0x02027CFC thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   BMP_MENU_ProcessYesNo 0x0201FEBC thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   d_021D663C 0x021D663C data a1
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   STRBUF_Clone 0x02045874 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   d_021D6544 0x021D6544 data a2
 *   BMP_MENU_CreateYesNo 0x0201FDA0 thumb
 *   GFL_NET_ClearExitFlag 0x0203CF04 arm
 *   GFL_NET_IRC_WIRELESS_Exit 0x0203D0D0 arm
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 *   GFL_NET_Exit 0x0203CEAC arm
 *   WIFILOGIN_MSG_SetExitFlag 0x021D6328 thumb ov115
 *   WIFILOGIN_DISP_CreateDisplay 0x021D4D38 thumb ov115
 *   WIFILOGIN_DISP_Draw 0x021D4DF4 thumb ov115
 *   WIFILOGIN_DISP_DeleteDisplay 0x021D4E04 thumb ov115
 */
#include "ov115_types.h"
#include "../sdk_ioreg.h"

struct Tcbl;

struct U16Vec;

struct GfFont;

struct MsgBank;

struct WordSet;

struct TaskMenuRes;

struct PrintSys;

struct Descriptor;

struct Rec;

struct Rec3;

struct S02031140;

struct TaskMenuState;

struct CharBuf;

struct TaskMenu;

struct TaskMenuTmpl;

typedef void (*StepFn)(u8 *);

typedef struct Blk {u8 first,pad[3]; u32 flags;} Blk;

typedef struct {
    u32 heap;
    u8 count, pad[3];
    const void *items;
    u32 param;
    u8 x, y, a, b;
} Template;

enum WifiloginMessageKind { K0,K1 };

typedef struct { u8 a, b, c, d; u16 e; } WifiloginMessageRecord;

#include "../types.h"

typedef enum { FALSE, TRUE } WifiloginMessageBool;

#include "../arm9/bmp_menu.h"
#include "../arm9/wipe.h"

#include "../arm9/net.h"

#include "../arm9/net_err.h"

#include "../arm9/net_state.h"




#include "../arm9/gfl_use.h"

#include "../arm9/gf_panic.h"

#include "../arm9/gfl_heap.h"

#include "../arm9/procsys.h"

#include "../arm9/mi_memory.h"



#include "../arm9/gfl_heap_wrap.h"



#include "../arm9/bmp_win.h"

#include "../arm9/gf_font.h"
struct TcblSystem;

#include "../arm9/tcbl.h"
struct PrintQueue;

#include "../arm9/printsys.h"
struct Strbuf;

#include "../arm9/strbuf.h"


#include "../arm9/msgdata.h"

struct GFont;

#include "../arm9/app_taskmenu.h"

#include "../arm9/bmp_menuwork.h"

#include "../arm9/arc_util.h"


struct TimeIcon;

#include "../arm9/time_icon.h"


#include "../arm9/bg_sys.h"


#include "../arm9/wordset.h"







struct BmpWin;




struct Bmp;

struct Bmp;

typedef short s16_p07;
#include "../arm9/bmp.h"


#include "../arm9/app_keycursor.h"

#include "../arm9/msg_speed.h"





struct TcbList;


struct TextPrinter;
struct PrintStreamCtrl;




struct TaskMenuInitWork;
struct TaskMenuWork;


#include "../arm9/g2.h"















extern void WIFILOGIN_MSG_SetExitFlag(void *userArg);

#include "wifilogin_disp.h"



u8 *WIFILOGIN_MSG_Create(u32 heap, u32 bank, u32 mode);

void WIFILOGIN_MSG_Run(u8 *p);

void WIFILOGIN_MSG_Delete(u8 *p);

void WIFILOGIN_MSG_Draw(void *p, int b);

void WIFILOGIN_MSG_DrawWindow(char *p, struct MsgBank *a, int b);

void WIFILOGIN_MSG_SetMessage(void *p, int b);

void WIFILOGIN_MSG_SetMessageWithIcon(u8 *p, struct MsgBank *a, int b);

int WIFILOGIN_MSG_IsPrintDone(u8 *p);

void WIFILOGIN_MSG_RedrawWindow(u8 *p);

void WIFILOGIN_MSG_ShowMessage(u8 *p, u32 n);

void WIFILOGIN_MSG_CloseMessage(u8 *p);

void *WIFILOGIN_MSG_OpenTask(u8 *p, int mode, int flag, int selected);

void WIFILOGIN_MSG_CloseTask(u8 *p);

void WIFILOGIN_MSG_UpdateTask(u8 *p);

int WIFILOGIN_MSG_IsTaskFinish(u8 *p);

u8 WIFILOGIN_MSG_GetTaskCursor(u8 *p);

void WIFILOGIN_MSG_PrintMessage(u8 *p,u32 n);

void WIFILOGIN_MSG_RedrawBorder(u8 *p);

u32 WIFILOGIN_MSG_GetFrameIdA(u32 a);

u32 WIFILOGIN_MSG_GetFrameIdB(u32 a);

void *WIFILOGIN_MSG_CreateYesNo(u8 *p, int mode, int n);

int WIFILOGIN_MSG_CreateWork(void *ctx,int unused,u8 *q);

int WIFILOGIN_MSG_DeleteWork(void *a,int b,u8 *c,u8 *p);

int WIFILOGIN_MSG_Update(int a,int b,int c,u8 *p);

void WIFILOGIN_MSG_SetStepHandler(u8 *p, void (*v)(u8 *));

void WIFILOGIN_MSG_RunStep(void *p, StepFn fn, int line);

int WIFILOGIN_MSG_CallStep(u8 *p);

void WIFILOGIN_MSG_StepWipe(u8 *p);

void WIFILOGIN_MSG_StepWaitWipe(u8 *p);

void WIFILOGIN_MSG_StepMessage(u8 *p);

void WIFILOGIN_MSG_StepWaitMessage(u8 *p);

void WIFILOGIN_MSG_StepExit(u8 *p);

void WIFILOGIN_MSG_StepWaitExit(u8 *p);

void WIFILOGIN_MSG_StepMessage2(u8 *p);

void WIFILOGIN_MSG_StepWaitMessage2(u8 *p);

void WIFILOGIN_MSG_StepWipe2(u8 *p);

void WIFILOGIN_MSG_StepFinish(u8 *p);

extern const char d_021D6628[];

extern const char d_021D663C[];

extern const WifiloginMessageRecord d_021D6544;

/*
 * ABI: DD60 and its forwarding chain ignore the live r0 from45088;
 *   45B38 explicitly truncates its third argument to16 at this call.
 */
u8 *WIFILOGIN_MSG_Create(u32 heap, u32 bank, u32 mode)
{
    u8 *p;
    u32 sel;
    p = GFL_HEAP_Alloc(heap, 132, 1, d_021D6628, 135);
    ((struct WifiloginMsg *)p)->heapId = heap;
    ((struct WifiloginMsg *)p)->mode = mode;
    BMP_WIN_Init(((struct WifiloginMsg *)p)->heapId);
    GF_FONT_InitTextColor();
    *(struct Tcbl * *)&((struct WifiloginMsg *)p)->tcbl = (struct Tcbl *)TCBL_Create(((struct WifiloginMsg *)p)->heapId, ((struct WifiloginMsg *)p)->heapId, 1, 0);
    ((struct WifiloginMsg *)p)->printsysQue = (void *)PRINTSYS_QUE_Create((u32)((struct WifiloginMsg *)p)->heapId);
    *(struct U16Vec * *)&((struct WifiloginMsg *)p)->strbuf = (struct U16Vec *)STRBUF_Create(400, ((struct WifiloginMsg *)p)->heapId);
    *(struct GfFont * *)&((struct WifiloginMsg *)p)->gfFont = GF_FONT_Create(23, 0, 0, 0, ((struct WifiloginMsg *)p)->heapId);
    *(struct MsgBank * *)&((struct WifiloginMsg *)p)->msgBank = MSGDATA_CreateFromArchive(0, 2, (u16)bank, ((struct WifiloginMsg *)p)->heapId);
    *(struct WordSet * *)&((struct WifiloginMsg *)p)->wordSet = WORDSET_CreateDefault(((struct WifiloginMsg *)p)->heapId);
    *(struct TaskMenuRes * *)&((struct WifiloginMsg *)p)->task.taskMenuRes = APP_TASKMENU_RES_Create(5, 9, (struct GFont *)(((struct WifiloginMsg *)p)->gfFont), (struct PrintQueue *)((struct WifiloginMsg *)p)->printsysQue, ((struct WifiloginMsg *)p)->heapId);
    ((struct WifiloginMsg *)p)->frameGfx0 = BMP_MENUWORK_LoadFrameGfx(WIFILOGIN_MSG_GetFrameIdA(((struct WifiloginMsg *)p)->mode), 12, 0, ((struct WifiloginMsg *)p)->heapId);
    ((struct WifiloginMsg *)p)->frameGfx1 = BMP_MENUWORK_LoadFrameGfx(WIFILOGIN_MSG_GetFrameIdB(((struct WifiloginMsg *)p)->mode), 12, 0, ((struct WifiloginMsg *)p)->heapId);
    sel = 0;
    if (((struct WifiloginMsg *)p)->mode == 0) sel = 4;
    ARC_UTIL_UploadPaletteFromArchiveWhole(23, 5, sel, 352, 32, ((struct WifiloginMsg *)p)->heapId);
    return p;
}

void WIFILOGIN_MSG_Run(u8 *p) { TCBL_Main(((struct WifiloginMsg *)p)->tcbl); PRINTSYS_QUE_Main((struct PrintQueue *)(*(struct PrintSys * *)&((struct WifiloginMsg *)p)->printsysQue)); }

void WIFILOGIN_MSG_Delete(u8 *p) {
    u32 n;
    if (((struct WifiloginMsg *)p)->timeIcon) { TIME_ICON_Delete(((struct WifiloginMsg *)p)->timeIcon); ((struct WifiloginMsg *)p)->timeIcon=0; }
    if (((struct WifiloginMsg *)p)->printStream) { PRINTSYS_PrintStreamDelete(((struct WifiloginMsg *)p)->printStream); ((struct WifiloginMsg *)p)->printStream=0; }
    WIFILOGIN_MSG_CloseMessage(p);
    n=((struct WifiloginMsg *)p)->frameGfx0;
    BG_SYS_FreeTileRun(WIFILOGIN_MSG_GetFrameIdA(((struct WifiloginMsg *)p)->mode),(u16)n,(u16)(n>>16));
    n=((struct WifiloginMsg *)p)->frameGfx1;
    BG_SYS_FreeTileRun(WIFILOGIN_MSG_GetFrameIdB(((struct WifiloginMsg *)p)->mode),(u16)n,(u16)(n>>16));
    GF_FONT_SetDefaultTextColor();
    WORDSET_Delete(((struct WifiloginMsg *)p)->wordSet);
    MSGDATA_Delete(((struct WifiloginMsg *)p)->msgBank);
    GF_FONT_Delete(((struct WifiloginMsg *)p)->gfFont);
    STRBUF_Delete(((struct WifiloginMsg *)p)->strbuf);
    APP_TASKMENU_RES_Delete(((struct WifiloginMsg *)p)->task.taskMenuRes);
    TCBL_Destroy(((struct WifiloginMsg *)p)->tcbl);
    PRINTSYS_QUE_Clear(((struct WifiloginMsg *)p)->printsysQue);
    PRINTSYS_QUE_Delete(((struct WifiloginMsg *)p)->printsysQue);
    if (((struct WifiloginMsg *)p)->window) { BMP_WIN_Delete(((struct WifiloginMsg *)p)->window); ((struct WifiloginMsg *)p)->window=0; }
    if (((struct WifiloginMsg *)p)->window2) { BMP_WIN_Delete(((struct WifiloginMsg *)p)->window2); ((struct WifiloginMsg *)p)->window2=0; }
    BMP_WIN_Exit();
    GFL_HEAP_Free(p);
}

void WIFILOGIN_MSG_Draw(void *p, int b) { WIFILOGIN_MSG_DrawWindow(p, (struct MsgBank *)(((struct WifiloginMsg *)p)->msgBank), b); }

/*
 * note 2026-10-05 (wD9r lane A6): first read of the field at +0x50 is an int read, later reads u32; the same-type form gets CSE'd and loads r1 for +0x2c. Row set after the first call.
 */
void WIFILOGIN_MSG_DrawWindow(char *p, struct MsgBank *a, int b)
{
    int row;
    int kind;
    uptr w;
    MSGDATA_ReadString(a, b, ((struct WifiloginMsg *)p)->strbuf);
    row = 1;
    if (*(int *)&((struct WifiloginMsg *)p)->mode != 0) row = 19;
    if (((struct WifiloginMsg *)p)->window == 0) {
        ((struct WifiloginMsg *)p)->window = BMP_WIN_Create(WIFILOGIN_MSG_GetFrameIdA(((struct WifiloginMsg *)p)->mode), 1, row, 30, 4, 11, 1);
    }
    w = (uptr)((struct WifiloginMsg *)p)->window;
    BMP_Clear((struct Bmp *)BMP_WIN_GetBmp((struct BmpWin *)w), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    kind = 2;
    if (((struct WifiloginMsg *)p)->mode == 0) kind = 6;
    PRINTSYS_CTRL_Init((PrintStreamCtrl *)((struct WifiloginMsg *)p)->printCtrl, (int)kind);
    if (((struct WifiloginMsg *)p)->printStream != 0) PRINTSYS_PrintStreamDelete((struct TextPrinter *)((struct WifiloginMsg *)p)->printStream);
    ((struct WifiloginMsg *)p)->printStream = PRINTSYS_PrintStream((struct BmpWin *)w, 0, 0, (struct Strbuf *)((struct WifiloginMsg *)p)->strbuf, (struct GfFont *)((struct WifiloginMsg *)p)->gfFont, MSG_SPEED_GetWait(), (struct Tcbl *)((struct WifiloginMsg *)p)->tcbl, 2, ((struct WifiloginMsg *)p)->heapId, 15);
    BMP_MENUWORK_DrawWindow((void *)w, 1, (u16)((struct WifiloginMsg *)p)->frameGfx0, 12);
    BMP_WIN_TransferChars((struct BmpWin *)w);
    BMP_WIN_MakeScreen((struct BmpWin *)w);
    BG_SYS_MarkTileDirty(WIFILOGIN_MSG_GetFrameIdA(((struct WifiloginMsg *)p)->mode));
}

void WIFILOGIN_MSG_SetMessage(void *p, int b) { WIFILOGIN_MSG_SetMessageWithIcon(p, ((struct WifiloginMsg *)p)->msgBank, b); }

void WIFILOGIN_MSG_SetMessageWithIcon(u8 *p, struct MsgBank *a, int b) {
    WIFILOGIN_MSG_DrawWindow((char *)p, a, b);
    if (((struct WifiloginMsg *)p)->timeIcon) {
        TIME_ICON_Delete(((struct WifiloginMsg *)p)->timeIcon);
        ((struct WifiloginMsg *)p)->timeIcon = 0;
    }
    ((struct WifiloginMsg *)p)->timeIcon = TIME_ICON_Create((void *)GFL_USE_GetMainTaskList(), ((struct WifiloginMsg *)p)->window, 15, 16, ((struct WifiloginMsg *)p)->heapId);
}

int WIFILOGIN_MSG_IsPrintDone(u8 *p) { int result=1; if(((struct WifiloginMsg *)p)->printStream) { result=PRINTSYS_CTRL_Update((struct PrintStreamCtrl *)((struct WifiloginMsg *)p)->printCtrl,((struct WifiloginMsg *)p)->printStream); if(result) { PRINTSYS_PrintStreamDelete(((struct WifiloginMsg *)p)->printStream); ((struct WifiloginMsg *)p)->printStream=0; } } return result; }

void WIFILOGIN_MSG_RedrawWindow(u8 *p) { if(*(u8 * *)&((struct WifiloginMsg *)p)->timeIcon) { TIME_ICON_Delete((struct TimeIcon *)(*(u8 * *)&((struct WifiloginMsg *)p)->timeIcon)); *(u8 * *)&((struct WifiloginMsg *)p)->timeIcon=0; } if(((struct WifiloginMsg *)p)->window) { BMP_MENUWORK_DrawWindowBorder(((struct WifiloginMsg *)p)->window,2); BMP_WIN_ClearScreen(((struct WifiloginMsg *)p)->window); BG_SYS_MarkTileDirty(WIFILOGIN_MSG_GetFrameIdA(((struct WifiloginMsg *)p)->mode)); } }

void WIFILOGIN_MSG_ShowMessage(u8 *p, u32 n) {
    void *w;
    if (((struct WifiloginMsg *)p)->window3==0) ((struct WifiloginMsg *)p)->window3=(void *)BMP_WIN_Create(1,4,7,24,2,11,1);
    w=((struct WifiloginMsg *)p)->window3;
    BMP_Clear(BMP_WIN_GetBmp(w),0);
    MSGDATA_ReadString(((struct WifiloginMsg *)p)->msgBank,n,((struct WifiloginMsg *)p)->strbuf);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(w),0,0,((struct WifiloginMsg *)p)->strbuf,((struct WifiloginMsg *)p)->gfFont,0x3cc0);
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    BG_SYS_MarkTileDirty(1);
}

void WIFILOGIN_MSG_CloseMessage(u8 *p) { if(((struct WifiloginMsg *)p)->window3) { BMP_WIN_ClearScreen(((struct WifiloginMsg *)p)->window3); BMP_WIN_Delete(((struct WifiloginMsg *)p)->window3); ((struct WifiloginMsg *)p)->window3=0; BG_SYS_MarkTileDirty(1); } }

/*
 * evidence: 5FE8 forwards the pointer returned by matched 0201FDA0;
 * this caller consumes that return. All six observed ov115 caller sites
 * (45F8,4630,46F4,47AE,488E,4926) set mode to literal0/1, so meaningful
 * Template fields are initialized on reachable case0. Complete original
 * contexts/reference search: B10/5D5C-interface-proof.txt; body unchanged.
 */
void *WIFILOGIN_MSG_OpenTask(u8 *p, int mode, int flag, int selected)
{
    struct WifiloginMsgTask *q = &((struct WifiloginMsg *)p)->task;
    Template t;
    q->kind = ((struct WifiloginMsg *)p)->mode;
    switch (q->kind) {
    case 0:
        t.heap = ((struct WifiloginMsg *)p)->heapId;
        t.count = 2;
        t.items = q->items;
        switch (mode) {
        case 0: t.x = 32; t.y = 13; t.param = 1; break;
        case 1: t.x = 32; t.y = 24; t.param = 1; break;
        }
        t.a = 13;
        t.b = 3;
        q->items[0].strbuf = STRBUF_Create(100, ((struct WifiloginMsg *)p)->heapId);
        MSGDATA_ReadString(((struct WifiloginMsg *)p)->msgBank, 28, q->items[0].strbuf);
        q->items[0].color = 0x39e0;
        q->items[1].strbuf = STRBUF_Create(100, ((struct WifiloginMsg *)p)->heapId);
        MSGDATA_ReadString(((struct WifiloginMsg *)p)->msgBank, 29, q->items[1].strbuf);
        q->items[1].color = 0x39e0;
        q->taskMenu = APP_TASKMENU_OpenMenu((struct TaskMenuInitWork *)(&t), q->taskMenuRes);
        STRBUF_Delete(q->items[0].strbuf);
        STRBUF_Delete(q->items[1].strbuf);
        if (flag != 0) G2x_SetBlendBrightness_(REG_DB_BLDCNT_ADDR, 17, -8);
        APP_TASKMENU_SetCursorPos((struct TaskMenuWork *)q->taskMenu, selected);
        break;
    case 1:
        q->yesNo = WIFILOGIN_MSG_CreateYesNo(p, mode, selected);
        q->answer = -1;
        break;
    }
    return q;
}

void WIFILOGIN_MSG_CloseTask(u8 *p) { switch(((struct WifiloginMsgTask *)p)->kind) { case K0: APP_TASKMENU_CloseMenu((struct TaskMenuWork *)(*(struct TaskMenu * *)&((struct WifiloginMsgTask *)p)->taskMenu)); break; case K1: break; } }

void WIFILOGIN_MSG_UpdateTask(u8 *p) { switch(((struct WifiloginMsgTask *)p)->kind) { case 0: APP_TASKMENU_UpdateMenu((struct TaskMenuWork *)(*(struct ClactActor * *)&((struct WifiloginMsgTask *)p)->taskMenu)); break; case 1: ((struct WifiloginMsgTask *)p)->answer=BMP_MENU_ProcessYesNo((struct BmpMenu *)*(u8 * *)&((struct WifiloginMsgTask *)p)->yesNo); break; } }

int WIFILOGIN_MSG_IsTaskFinish(u8 *p) { switch(((struct WifiloginMsgTask *)p)->kind) { case 0: return APP_TASKMENU_IsFinish(((struct WifiloginMsgTask *)p)->taskMenu); case 1: if(((struct WifiloginMsgTask *)p)->answer!=-1) return 1; else return 0; default: GF_PANIC_Fail(d_021D663C,0,d_021D663C); return 0; } }

u8 WIFILOGIN_MSG_GetTaskCursor(u8 *p) { switch(((struct WifiloginMsgTask *)p)->kind) { case 0: return APP_TASKMENU_GetCursorPos((struct TaskMenuWork *)(*(const u8 * *)&((struct WifiloginMsgTask *)p)->taskMenu)); case 1: return (u8)((struct WifiloginMsgTask *)p)->answer; default: GF_PANIC_Fail(d_021D663C,0,d_021D663C); return 0; } }

void WIFILOGIN_MSG_PrintMessage(u8 *p,u32 n) {
    void *w;
    void *s;
    MSGDATA_ReadString(((struct WifiloginMsg *)p)->msgBank,n,((struct WifiloginMsg *)p)->strbuf);
    s=STRBUF_Clone(((struct WifiloginMsg *)p)->strbuf,((struct WifiloginMsg *)p)->heapId);
    WORDSET_CopyTaggedText(((struct WifiloginMsg *)p)->wordSet,((struct WifiloginMsg *)p)->strbuf,s);
    if (((struct WifiloginMsg *)p)->window2==0) ((struct WifiloginMsg *)p)->window2=(void *)BMP_WIN_Create(WIFILOGIN_MSG_GetFrameIdB(((struct WifiloginMsg *)p)->mode),1,1,30,16,11,1);
    w=((struct WifiloginMsg *)p)->window2;
    BMP_Clear(BMP_WIN_GetBmp(w),15);
    GF_FONT_SetTextColor(1,2,15);
    PRINTSYS_Print(BMP_WIN_GetBmp(w),0,0,((struct WifiloginMsg *)p)->strbuf,((struct WifiloginMsg *)p)->gfFont);
    BMP_MENUWORK_DrawWindow(w,(u32)1,(u16)(((struct WifiloginMsg *)p)->frameGfx1),(u32)12);
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    BG_SYS_MarkTileDirty(WIFILOGIN_MSG_GetFrameIdB(((struct WifiloginMsg *)p)->mode));
    STRBUF_Delete(s);
}

void WIFILOGIN_MSG_RedrawBorder(u8 *p) { if(((struct WifiloginMsg *)p)->window2){BMP_MENUWORK_DrawWindowBorder(((struct WifiloginMsg *)p)->window2,2);BMP_WIN_ClearScreen(((struct WifiloginMsg *)p)->window2);BG_SYS_MarkTileDirty(WIFILOGIN_MSG_GetFrameIdB(((struct WifiloginMsg *)p)->mode));} }

u32 WIFILOGIN_MSG_GetFrameIdA(u32 a) { switch(a){case 1:return 1;case 0:return 5;default:GF_PANIC_Fail(d_021D663C,0,d_021D663C);return 0;} }

u32 WIFILOGIN_MSG_GetFrameIdB(u32 a) { switch(a){case 1:return 2;case 0:return 5;default:GF_PANIC_Fail(d_021D663C,0,d_021D663C);return 0;} }

void *WIFILOGIN_MSG_CreateYesNo(u8 *p, int mode, int n) {
    WifiloginMessageRecord r = d_021D6544;
    r.e = ((struct WifiloginMsg *)p)->frameGfx0;
    switch (mode) {
    case 0: r.b = 24; r.c = 13; break;
    case 1: r.b = 24; r.c = 19; break;
    }
    return BMP_MENU_CreateYesNo((const struct WinDat *)&r, r.e, 12, n, ((struct WifiloginMsg *)p)->heapId);
}

int WIFILOGIN_MSG_CreateWork(void *ctx,int unused,u8 *q) {
    u8 *p;
    WifiloginMessageBool flag;
    GFL_HEAP_CreateChildHeap(1,121,0x18000);
    p=PROCSYS_AllocProcWork(ctx,32,121);
    MI_CpuFill8(p,0,32);
    *(u8 * *)&((struct WifiloginMsgWork *)p)->state=q;
    ((struct WifiloginMsgWork *)p)->heapId=121;
    if(((struct WifiloginState *)q)->waiting==0) ((struct WifiloginState *)q)->waiting=6;
    ((struct WifiloginMsgWork *)p)->disp=WIFILOGIN_DISP_CreateDisplay(((struct WifiloginMsgWork *)p)->heapId,((struct WifiloginState *)q)->mode,((struct WifiloginState *)q)->reconnect);
    ((struct WifiloginMsgWork *)p)->message=WIFILOGIN_MSG_Create(((struct WifiloginMsgWork *)p)->heapId,232,((struct WifiloginState *)q)->reconnect);
    WIFILOGIN_MSG_RunStep(p,WIFILOGIN_MSG_StepWipe,173);
    if(((struct WifiloginState *)q)->mode==0) {
        WIFILOGIN_MSG_ShowMessage(((struct WifiloginMsgWork *)p)->message,36);
        if(((struct WifiloginState *)q)->dialogId==0) GFL_USE_CancelChangeAndPlayBgm(1153,65535);
    }
    if(((struct WifiloginState *)q)->reconnect==0) flag=FALSE; else flag=TRUE;
    GFL_NET_RefreshWmIconAtTopRight(flag,((struct WifiloginMsgWork *)p)->heapId);
    return 1;
}

int WIFILOGIN_MSG_DeleteWork(void *a,int b,u8 *c,u8 *p) { if(!((struct WifiloginState *)c)->mode)WIFILOGIN_MSG_CloseMessage(((struct WifiloginMsgWork *)p)->message);WIFILOGIN_MSG_Delete(*(u8 * *)&((struct WifiloginMsgWork *)p)->message);WIFILOGIN_DISP_DeleteDisplay(*(u8 * *)&((struct WifiloginMsgWork *)p)->disp);PROCSYS_FreeProcWork(a);GFL_HEAP_DeleteChecked(121);return 1; }

int WIFILOGIN_MSG_Update(int a,int b,int c,u8 *p) { int result;if(((struct WifiloginMsgWork *)p)->task)WIFILOGIN_MSG_UpdateTask(((struct WifiloginMsgWork *)p)->task);WIFILOGIN_DISP_Draw(((struct WifiloginMsgWork *)p)->disp);WIFILOGIN_MSG_Run(((struct WifiloginMsgWork *)p)->message);result=0;if(WIFILOGIN_MSG_CallStep(p))result=1;return result; }

void WIFILOGIN_MSG_SetStepHandler(u8 *p, void (*v)(u8 *))
{
    ((struct WifiloginMsgWork *)p)->stateHandler = v;
}

/*
 * Byte-correct but witness-blocked (MATCH).
 * +0004 ABS32 WIFILOGIN_MSG_SetStepHandler          -> unresolved: 021D6130 (arm, from name) has no witness outside 021D6134..021D613C; 9 overlays overlap this address (ov016, ov021, ov093, ov115, ov118, ov120, ov123, ov131, ov175), none resolvable without a region hint on the symbols: line
 */
void WIFILOGIN_MSG_RunStep(void *p, StepFn fn, int line) { WIFILOGIN_MSG_SetStepHandler(p, fn); }

int WIFILOGIN_MSG_CallStep(u8 *p) { void (*cb)(u8 *);cb=((struct WifiloginMsgWork *)p)->stateHandler;if(cb){cb(p);return 0;}return 1; }

void WIFILOGIN_MSG_StepWipe(u8 *p) {
    int color;
    if (((struct WifiloginMsgWork *)p)->state->waiting & 8) color = 0x7fff;
    else color = 0;
    WIPE_SYS_Start(0, 1, 1, (u16)color, 6, 1, ((struct WifiloginMsgWork *)p)->heapId);
    WIFILOGIN_MSG_RunStep(p, WIFILOGIN_MSG_StepWaitWipe, 0x15b);
}

void WIFILOGIN_MSG_StepWaitWipe(u8 *p) { if(WIPE_SYS_EndCheck())WIFILOGIN_MSG_RunStep(p,WIFILOGIN_MSG_StepMessage,0x169); }

void WIFILOGIN_MSG_StepMessage(u8 *p) { WIFILOGIN_MSG_SetMessage(((struct WifiloginMsgWork *)p)->message,26);WIFILOGIN_MSG_RunStep(p, WIFILOGIN_MSG_StepWaitMessage, 0x194); }

void WIFILOGIN_MSG_StepWaitMessage(u8 *p) { if(WIFILOGIN_MSG_IsPrintDone(((struct WifiloginMsgWork *)p)->message))WIFILOGIN_MSG_RunStep(p,WIFILOGIN_MSG_StepExit,0x1a2); }

void WIFILOGIN_MSG_StepExit(u8 *p) {
    if (GFL_NET_ERR_GetErrorLevel()) {
        GFL_NET_ClearExitFlag(); GFL_NET_IRC_WIRELESS_Exit(); GFL_NET_STATE_ClearErrorMode(); GFL_NET_STATE_SetWifiError(); GFL_NET_ERR_ResetState();
    }
    if (GFL_NET_IsSessionNull()) {
        WIFILOGIN_MSG_RunStep(p,WIFILOGIN_MSG_StepMessage2,0x1bf);
        return;
    }
    if (GFL_NET_Exit(WIFILOGIN_MSG_SetExitFlag)) WIFILOGIN_MSG_RunStep(p,WIFILOGIN_MSG_StepWaitExit,0x1c7);
}

void WIFILOGIN_MSG_StepWaitExit(u8 *p) { if(((struct WifiloginMsgWork *)p)->flag18)WIFILOGIN_MSG_RunStep(p,WIFILOGIN_MSG_StepMessage2,0x1d8); }

void WIFILOGIN_MSG_StepMessage2(u8 *p) { WIFILOGIN_MSG_SetMessage(((struct WifiloginMsgWork *)p)->message,27);WIFILOGIN_MSG_RunStep(p,WIFILOGIN_MSG_StepWaitMessage2,0x1e6); }

void WIFILOGIN_MSG_StepWaitMessage2(u8 *p) { if(WIFILOGIN_MSG_IsPrintDone(((struct WifiloginMsgWork *)p)->message))WIFILOGIN_MSG_RunStep(p,WIFILOGIN_MSG_StepWipe2,0x1f4); }

void WIFILOGIN_MSG_StepWipe2(u8 *p) {
    int color;
    u8 *q = *(u8 * *)&((struct WifiloginMsgWork *)p)->state;
    if (((struct WifiloginState *)q)->waiting & 16) color = 0x7fff;
    else color = 0;
    if (((struct WifiloginState *)q)->dialogId == 0) GFL_USE_FadeOutBgm(6);
    WIPE_SYS_Start(0, 0, 0, (u16)color, 6, 1, ((struct WifiloginMsgWork *)p)->heapId);
    WIFILOGIN_MSG_RunStep(p, WIFILOGIN_MSG_StepFinish, 0x213);
}

void WIFILOGIN_MSG_StepFinish(u8 *p)
{
    if (WIPE_SYS_EndCheck())
        WIFILOGIN_MSG_RunStep(p, 0, 0x221);
}

void WIFILOGIN_MSG_SetExitFlag(void *userArg) { u8 *p = userArg; ((struct WifiloginMsgWork *)p)->flag18=1; }
