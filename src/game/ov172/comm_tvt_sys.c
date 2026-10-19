/*
 * file:     comm_tvt_sys.c
 * unit:     yes
 * function: COMM_TVT_SYS_GetCamView, COMM_TVT_SYS_GetComm, COMM_TVT_SYS_GetTalkStatus, COMM_TVT_SYS_GetSprites, COMM_TVT_SYS_GetLaunchParams, COMM_TVT_SYS_GetHeapId, COMM_TVT_SYS_GetArc, COMM_TVT_SYS_GetResId, COMM_TVT_SYS_GetClactUnit, COMM_TVT_SYS_GetReturnedFromChild, COMM_TVT_SYS_SetReturnedFromChild, COMM_TVT_SYS_GetFont, COMM_TVT_SYS_GetMsgData, COMM_TVT_SYS_GetPrintQue, COMM_TVT_SYS_GetTaskMenu, COMM_TVT_SYS_GetMemberCount, COMM_TVT_SYS_SetMemberCount, COMM_TVT_SYS_GetLayoutMode, COMM_TVT_SYS_GetHalfRes, COMM_TVT_SYS_ApplyHalfRes, COMM_TVT_SYS_ToggleHalfRes, COMM_TVT_SYS_SetHalfRes, COMM_TVT_SYS_GetSelfSlot, COMM_TVT_SYS_SetSelfSlot, COMM_TVT_SYS_GetMessageActive, COMM_TVT_SYS_SetMessageActive, COMM_TVT_SYS_GetViewSwapped, COMM_TVT_SYS_ToggleViewSwapped, COMM_TVT_SYS_GetInputLocked, COMM_TVT_SYS_SetInputLocked, COMM_TVT_SYS_GetEndRequested, COMM_TVT_SYS_SetEndRequested, COMM_TVT_SYS_IsLaunchModeCall, COMM_TVT_SYS_GetHostBusy, COMM_TVT_SYS_ClearHostBusy, COMM_TVT_SYS_GetCameraBusy, COMM_TVT_SYS_SetCameraBusy, COMM_TVT_SYS_IsNetIdle, COMM_TVT_SYS_OpenConfirmMenu, COMM_TVT_SYS_ClearNameWindows, COMM_TVT_SYS_ClearAndTransferNameWindows, COMM_TVT_SYS_PlaceSlotMarker, COMM_TVT_SYS_HideSlotMarker, COMM_TVT_SYS_SavePeerRecord, COMM_TVT_SYS_CreateTimeIcon, COMM_TVT_SYS_DeleteTimeIcon, COMM_TVT_SYS_ProcInit, COMM_TVT_SYS_ProcExit, COMM_TVT_SYS_ProcMain
 * address:  0x021BDFDC
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from draw_system.c, ctvt_comm.c, ctvt_draw.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   COMM_TVT_SYS_GetArc 0x021BE010 thumb ov172
 *   COMM_TVT_SYS_IsNetIdle 0x021BE100 thumb ov172
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   COMM_TVT_SYS_GetLayoutMode 0x021BE05C thumb ov172
 *   COMM_TVT_SYS_GetHalfRes 0x021BE078 thumb ov172
 *   COMM_TVT_SYS_GetComm 0x021BDFE4 thumb ov172
 *   COMM_TVT_SYS_GetMemberCount 0x021BE054 thumb ov172
 *   COMM_TVT_SYS_ClearAndTransferNameWindows 0x021BE1E4 thumb ov172
 *   CTVT_COMM_GetSlotConnected 0x021B8B8C thumb ov172
 *   COMM_TVT_SYS_GetCamView 0x021BDFDC thumb ov172
 *   COMM_TVT_SYS_GetSelfSlot 0x021BE0A4 thumb ov172
 *   COMM_TVT_SYS_GetMessageActive 0x021BE0AC thumb ov172
 *   COMM_TVT_SYS_GetViewSwapped 0x021BE0B4 thumb ov172
 *   COMM_TVT_SYS_GetCameraBusy 0x021BE0F8 thumb ov172
 *   COMM_TVT_SYS_SetCameraBusy 0x021BE0FC thumb ov172
 *   CTVT_COMM_IsSlotActive 0x021B8BA4 thumb ov172
 *   COMM_TVT_SYS_IsLaunchModeCall 0x021BE0D8 thumb ov172
 *   COMM_TVT_SYS_GetLaunchParams 0x021BE004 thumb ov172
 *   COMM_TVT_SYS_GetHeapId 0x021BE00C thumb ov172
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   COMM_TVT_SYS_ClearNameWindows 0x021BE1A4 thumb ov172
 *   COMM_TVT_SYS_SetMemberCount 0x021BE058 thumb ov172
 *   COMM_TVT_SYS_SetSelfSlot 0x021BE0A8 thumb ov172
 *   COMM_TVT_SYS_SavePeerRecord 0x021BE2F0 thumb ov172
 *   COMM_TVT_SYS_PlaceSlotMarker 0x021BE210 thumb ov172
 *   COMM_TVT_SYS_GetTalkStatus 0x021BDFEC thumb ov172
 *   COMM_TVT_SYS_HideSlotMarker 0x021BE2E0 thumb ov172
 *   COMM_TVT_SYS_GetSprites 0x021BDFFC thumb ov172
 *   COMM_TVT_SYS_SetInputLocked 0x021BE0CC thumb ov172
 *   COMM_TVT_SYS_SetHalfRes 0x021BE0A0 thumb ov172
 *   COMM_TVT_SYS_SetEndRequested 0x021BE0D4 thumb ov172
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   COMM_TVT_SYS_GetResId 0x021BE018 thumb ov172
 *   COMM_TVT_SYS_GetClactUnit 0x021BE024 thumb ov172
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   COMM_TVT_SYS_GetReturnedFromChild 0x021BE02C thumb ov172
 *   COMM_TVT_SYS_SetReturnedFromChild 0x021BE030 thumb ov172
 *   COMM_TVT_SYS_SetMessageActive 0x021BE0B0 thumb ov172
 *   COMM_TVT_SYS_GetPrintQue 0x021BE044 thumb ov172
 *   COMM_TVT_SYS_CreateTimeIcon 0x021BE318 thumb ov172
 *   COMM_TVT_SYS_DeleteTimeIcon 0x021BE34C thumb ov172
 *   KEY_GetCont 0x0203630C arm
 *   COMM_TVT_SYS_ToggleViewSwapped 0x021BE0B8 thumb ov172
 *   COMM_TVT_SYS_ToggleHalfRes 0x021BE08C thumb ov172
 *   COMM_TVT_SYS_GetFont 0x021BE034 thumb ov172
 *   COMM_TVT_SYS_GetMsgData 0x021BE03C thumb ov172
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   COMM_TVT_SYS_OpenConfirmMenu 0x021BE11C thumb ov172
 *   COMM_TVT_SYS_GetEndRequested  0x021BE0D0  thumb  ov172
 *   CLACT_RestartActorAnim  0x0204B9A0  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   MYSTATUS_GetId  0x02008530  thumb
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   CTVT_COMM_GetSlotParam 0x021B8B94 thumb ov172
 *   MYSTATUS_CreateNameStrbuf 0x02008510 thumb
 *   GF_FONT_MeasureWidestLine 0x0201D304 thumb
 *   CTVT_TALK_GetMic  0x021B9F98  thumb
 *   CTVT_COMM_SendSlotHit 0x021B8720 thumb ov172
 *   APP_ENV_IsRunOnTwl  0x0202EB0C  thumb
 *   unit_0202EB14  0x0202EB14  thumb
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   d_021C7048 0x021C7048 data ov172
 *   d_021C704C 0x021C704C data ov172
 *   MET_TRAINERS_GetFromSave 0x0200ED48 thumb
 *   TIME_ICON_CreateNode  0x0202EE8C  thumb
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   GAME_DATA_Create 0x020124F4 thumb
 *   d_021C724C 0x021C724C data a4
 *   GFL_NET_ERR_RequestScreen 0x0200FB38 thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 *   CTVT_CALL_WorkInit 0x021BD1AC thumb ov172
 *   CTVT_CALL_WorkDelete 0x021BD3B8 thumb ov172
 *   CTVT_CALL_WorkMain 0x021BD43C thumb ov172
 *   MET_TRAINERS_Insert  0x0200ED54  thumb  arm9
 *   PROCSYS_FreeProcWork  0x020315D4  arm  arm9
 */
#include "ctvt_types.h"

struct ProcSys;
struct SaveControl;
struct SaveRecord;
struct PeerObj;

typedef struct CtvtMenuItem {
    struct StrBuf *label;
    u16 value;              /* text color word */
    u16 pad;                /* alignment before the next word */
    u32 reserved;
} CtvtMenuItem;

typedef struct CtvtMenuTemplate {
    u32 heapId;
    u8 itemCount;
    u8 pad[3];              /* alignment before the pointer */
    CtvtMenuItem *items;
    u32 reserved;
    u8 x;
    u8 y;
    u8 width;
    u8 height;
} CtvtMenuTemplate;

typedef struct CtvtByte4 { u8 b[4]; } CtvtByte4;

/* Placement of the slot marker: result position and the two byte tables it is taken from. */
typedef struct CtvtMarkerPlace {
    u16 x;
    u16 y;
    CtvtByte4 yTable;
    CtvtByte4 xTable;
} CtvtMarkerPlace;

extern u32 CTVT_COMM_GetSlotConnected(CtvtWork *work, struct CtvtComm *comm, int slot);
extern u32 CTVT_COMM_IsSlotActive(CtvtWork *work, struct CtvtComm *comm, int slot);
extern struct StrBuf *CTVT_COMM_GetSlotParam(CtvtWork *work, struct CtvtComm *comm, int slot);
extern int CTVT_TALK_GetMic(CtvtWork *work, struct CtvtTalk *talk);
extern void CTVT_COMM_SendSlotHit(CtvtWork *work, struct CtvtComm *comm, s32 halfRes);
extern void BMP_Clear(void *bmp, u8 value);
extern void BMP_WIN_ClearScreen(struct BmpWin *win);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern void *BMP_WIN_GetBmp(struct BmpWin *win);
extern void STRBUF_Delete(struct StrBuf *str);
extern struct StrBuf *MSGDATA_AllocString(struct MsgData *msg, u32 index);
extern void *GFL_HEAP_Alloc(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void GFL_HEAP_Free(void *p);
extern void CLACT_SetActorDrawEnable(struct ClActor *actor, u32 enable);
extern void CLACT_RestartActorAnim(struct ClActor *actor);
extern void CLACT_AddActorSurfacePos(struct ClActor *actor, const void *delta, u32 space);
extern u32 MYSTATUS_GetId(const struct PeerObj *obj);
extern struct StrBuf *MYSTATUS_CreateNameStrbuf(struct StrBuf *src, int heapId);
extern u32 GF_FONT_MeasureWidestLine(struct StrBuf *str, u32 font, u32 flags);
extern void TIME_ICON_Delete(struct TimeIcon *icon);
extern struct TimeIcon *TIME_ICON_CreateNode(void *src, void *arg, u8 x, u8 y, u16 heapId);
extern u32 APP_ENV_IsRunOnTwl(void);
extern int unit_0202EB14(void);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(CtvtMenuTemplate *tmpl, struct TaskMenu *res);
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *data);
extern struct SaveRecord *MET_TRAINERS_GetFromSave(struct SaveControl *save);
extern void MET_TRAINERS_Insert(struct SaveRecord *record, u32 value);
extern void GFL_HEAP_CreateChildHeap(unsigned int, unsigned int, unsigned int);
extern void *PROCSYS_AllocProcWork(struct ProcSys *proc, u32 size, u32 heapId);
extern struct GameData *GAME_DATA_Create(u16 heapId);
extern unsigned int KEY_GetCont(void);
extern void PROCSYS_FreeProcWork(struct ProcSys *proc);
extern void GFL_HEAP_DeleteChecked(unsigned int heapId);
extern u32 GFL_NET_ERR_GetErrorLevel(void);
extern void GFL_NET_ERR_RequestScreen(void);
extern void CTVT_CALL_WorkInit(CtvtWork *work);
extern void CTVT_CALL_WorkDelete(CtvtWork *work);
extern int CTVT_CALL_WorkMain(CtvtWork *work);

void COMM_TVT_SYS_DeleteTimeIcon(CtvtWork *work);

extern const CtvtByte4 d_021C7048;
extern const CtvtByte4 d_021C704C;
extern u8 d_021C724C[];

CtvtCamView *COMM_TVT_SYS_GetCamView(CtvtWork *work)
{
    return work->camView;
}

struct CtvtComm *COMM_TVT_SYS_GetComm(CtvtWork *work)
{
    return work->comm;
}

/* Tail call into the talk module with the talk record. */
int COMM_TVT_SYS_GetTalkStatus(CtvtWork *work)
{
    return CTVT_TALK_GetMic(work, work->talk);
}

struct CtvtSprites *COMM_TVT_SYS_GetSprites(CtvtWork *work)
{
    return work->sprites;
}

CtvtLaunchParams *COMM_TVT_SYS_GetLaunchParams(CtvtWork *work)
{
    return work->launch;
}

u16 COMM_TVT_SYS_GetHeapId(CtvtWork *work)
{
    return work->heapId;
}

struct ArcHandle *COMM_TVT_SYS_GetArc(CtvtWork *work)
{
    return work->arc;
}

u32 COMM_TVT_SYS_GetResId(CtvtWork *work, int index)
{
    return work->resId[index];
}

struct ClActUnit *COMM_TVT_SYS_GetClactUnit(CtvtWork *work)
{
    return work->clactUnit;
}

s32 COMM_TVT_SYS_GetReturnedFromChild(CtvtWork *work)
{
    return work->returnedFromChild;
}

void COMM_TVT_SYS_SetReturnedFromChild(CtvtWork *work, s32 value)
{
    work->returnedFromChild = value;
}

u32 COMM_TVT_SYS_GetFont(CtvtWork *work)
{
    return work->font;
}

struct MsgData *COMM_TVT_SYS_GetMsgData(CtvtWork *work)
{
    return work->msgData;
}

struct PrintQue *COMM_TVT_SYS_GetPrintQue(CtvtWork *work)
{
    return work->printQue;
}

struct TaskMenu *COMM_TVT_SYS_GetTaskMenu(CtvtWork *work)
{
    return work->taskMenu;
}

u8 COMM_TVT_SYS_GetMemberCount(CtvtWork *work)
{
    return work->memberCount;
}

void COMM_TVT_SYS_SetMemberCount(CtvtWork *work, u32 count)
{
    work->memberCount = count;
}

/* 1 while one or two members are present, else 2. */
int COMM_TVT_SYS_GetLayoutMode(CtvtWork *work)
{
    u8 count = COMM_TVT_SYS_GetMemberCount(work);
    if (count == 1) {
        return 1;
    }
    if (count == 2) {
        return 1;
    }
    return 2;
}

s32 COMM_TVT_SYS_GetHalfRes(CtvtWork *work)
{
    return work->halfRes;
}

/* Sends the new resolution mode to the comm record. */
void COMM_TVT_SYS_ApplyHalfRes(CtvtWork *work, s32 halfRes)
{
    CTVT_COMM_SendSlotHit(work, work->comm, halfRes);
}

/* Toggles the resolution mode. */
void COMM_TVT_SYS_ToggleHalfRes(CtvtWork *work)
{
    u32 value = work->halfRes;
    if (value == 0) {
        value = 1;
    } else {
        value = 0;
    }
    COMM_TVT_SYS_ApplyHalfRes(work, value);
}

void COMM_TVT_SYS_SetHalfRes(CtvtWork *work, s32 halfRes)
{
    work->halfRes = halfRes;
}

u8 COMM_TVT_SYS_GetSelfSlot(CtvtWork *work)
{
    return work->selfSlot;
}

void COMM_TVT_SYS_SetSelfSlot(CtvtWork *work, u32 slot)
{
    work->selfSlot = slot;
}

s32 COMM_TVT_SYS_GetMessageActive(CtvtWork *work)
{
    return work->messageActive;
}

void COMM_TVT_SYS_SetMessageActive(CtvtWork *work, s32 value)
{
    work->messageActive = value;
}

s32 COMM_TVT_SYS_GetViewSwapped(CtvtWork *work)
{
    return work->viewSwapped;
}

/* Inverts the view swap flag. */
void COMM_TVT_SYS_ToggleViewSwapped(CtvtWork *work)
{
    u32 value = work->viewSwapped;
    if (value == 0) {
        value = 1;
    } else {
        value = 0;
    }
    work->viewSwapped = value;
}

s32 COMM_TVT_SYS_GetInputLocked(CtvtWork *work)
{
    return work->inputLocked;
}

void COMM_TVT_SYS_SetInputLocked(CtvtWork *work, s32 value)
{
    work->inputLocked = value;
}

s32 COMM_TVT_SYS_GetEndRequested(CtvtWork *work)
{
    return work->endRequested;
}

void COMM_TVT_SYS_SetEndRequested(CtvtWork *work, s32 value)
{
    work->endRequested = value;
}

/* 1 when the overlay was started in mode 3. */
int COMM_TVT_SYS_IsLaunchModeCall(CtvtWork *work)
{
    CtvtLaunchParams *launch = work->launch;
    if (launch->mode == 3) {
        return 1;
    }
    return 0;
}

s32 COMM_TVT_SYS_GetHostBusy(CtvtWork *work)
{
    return work->hostBusy;
}

void COMM_TVT_SYS_ClearHostBusy(CtvtWork *work)
{
    work->hostBusy = 0;
}

s32 COMM_TVT_SYS_GetCameraBusy(CtvtWork *work)
{
    return work->cameraBusy;
}

void COMM_TVT_SYS_SetCameraBusy(CtvtWork *work, s32 value)
{
    work->cameraBusy = value;
}

int COMM_TVT_SYS_IsNetIdle(void)
{
    if (APP_ENV_IsRunOnTwl() == 1 && unit_0202EB14() == 0) {
        return 1;
    }
    return 0;
}

/* Opens the two entry confirmation menu (messages 34 and 35). */
struct TaskMenu *COMM_TVT_SYS_OpenConfirmMenu(CtvtWork *work)
{
    CtvtMenuTemplate menu = {0};
    CtvtMenuItem items[2] = {0};
    struct TaskMenu *result;
    items[0].label = MSGDATA_AllocString(work->msgData, 34);
    items[1].label = MSGDATA_AllocString(work->msgData, 35);
    items[0].value = 14819;
    items[1].value = 14819;
    items[0].reserved = 0;
    items[1].reserved = 0;
    menu.heapId = work->heapId;
    menu.itemCount = 2;
    menu.items = items;
    menu.x = 24;
    menu.y = 6;
    menu.width = 8;
    menu.height = 3;
    menu.reserved = 0;
    result = APP_TASKMENU_OpenMenu(&menu, work->taskMenu);
    STRBUF_Delete(items[0].label);
    STRBUF_Delete(items[1].label);
    return result;
}

/* Clears the four name windows and the two slot flags; the windows leave the screen too
 * unless the draw screen is running. */
void COMM_TVT_SYS_ClearNameWindows(CtvtWork *work)
{
    u8 i;

    work->slotFlagA = 0;
    work->slotFlagB = 0;
    for (i = 0; i < 4; i++) {
        BMP_Clear(BMP_WIN_GetBmp(work->bmpWin[i]), 0);
        if (work->screen != CTVT_SCREEN_DRAW) {
            BMP_WIN_ClearScreen(work->bmpWin[i]);
        }
    }
}

/* Clears the four name windows and transfers them. */
void COMM_TVT_SYS_ClearAndTransferNameWindows(CtvtWork *work)
{
    u8 i;
    for (i = 0; i < 4; i++) {
        BMP_Clear(BMP_WIN_GetBmp(work->bmpWin[i]), 0);
        BMP_WIN_TransferChars(work->bmpWin[i]);
    }
}

/* Places the slot marker next to the name of member idx: the marker index is idx, or 2 and
 * 3 for slots 0 and 1 in layout mode 1; the checks run through CTVT_COMM_IsSlotActive and
 * CTVT_COMM_GetSlotConnected, then the position comes from the x and y byte tables.
 * idx is a u8 slot index (the sibling CTVT_CALL_UpdateMemberWindows walks the same slots with a u8 i). The u8
 * parameter is what keeps the third-call idx reload after the byte copies. */
void COMM_TVT_SYS_PlaceSlotMarker(CtvtWork *work, u8 idx)
{
    CtvtMarkerPlace place;
    struct StrBuf *name;
    u32 nameWidth;
    int mode;
    u32 markerIndex;
    mode = COMM_TVT_SYS_GetLayoutMode(work);
    markerIndex = idx;
    if (work->screen == 3) return;
    if (mode == 1) markerIndex = (markerIndex == 0) ? 2 : 3;
    if (CTVT_COMM_IsSlotActive(work, work->comm, idx) != 1) return;
    if (CTVT_COMM_GetSlotConnected(work, work->comm, idx) != 1) return;
    place.xTable = d_021C704C;
    place.yTable = d_021C7048;
    name = MYSTATUS_CreateNameStrbuf(CTVT_COMM_GetSlotParam(work, work->comm, idx), work->heapId);
    nameWidth = (u8)GF_FONT_MeasureWidestLine(name, work->font, 0);
    STRBUF_Delete(name);
    { u32 baseX = place.xTable.b[markerIndex]; place.x = baseX + (nameWidth >> 1); }
    place.y = place.yTable.b[markerIndex];
    CLACT_AddActorSurfacePos(work->marker, &place, 0);
    CLACT_SetActorDrawEnable(work->marker, 1);
    CLACT_RestartActorAnim(work->marker);
}

void COMM_TVT_SYS_HideSlotMarker(CtvtWork *work)
{
    CLACT_SetActorDrawEnable(work->marker, 0);
}

/* Stores the peer record value in the save data. */
void COMM_TVT_SYS_SavePeerRecord(CtvtWork *work, struct PeerObj *peer)
{
    struct SaveRecord *record = MET_TRAINERS_GetFromSave(GAME_DATA_GetSaveControl(work->launch->gameData));
    MET_TRAINERS_Insert(record, MYSTATUS_GetId(peer));
}

/* Rebuilds the time icon, retiring the old one first. */
void COMM_TVT_SYS_CreateTimeIcon(CtvtWork *work, void *arg)
{
    if (work->timeIcon != 0)
        COMM_TVT_SYS_DeleteTimeIcon(work);

    work->timeIcon =
        TIME_ICON_CreateNode(work->timeIconSrc, arg, 0xf, 0x10, work->heapId);
}

void COMM_TVT_SYS_DeleteTimeIcon(CtvtWork *work)
{
    struct TimeIcon *icon = work->timeIcon;
    if (icon != 0) {
        TIME_ICON_Delete(icon);
        work->timeIcon = 0;
    }
}

/* Process init: allocates the work record and starts the first screen. */
int COMM_TVT_SYS_ProcInit(struct ProcSys *proc, int unused, CtvtLaunchParams *launch)
{
    CtvtWork *work;
    if (launch && launch->mode == 3) GFL_HEAP_CreateChildHeap(1, 109, 0xd0000);
    else GFL_HEAP_CreateChildHeap(1, 109, 0xe8000);
    work = PROCSYS_AllocProcWork(proc, 0x1fc, 109);
    work->heapId = 109;
    if (launch == 0) {
        work->launch = GFL_HEAP_Alloc(1, 16, 1, (const char *)d_021C724C, 1357);
        work->launch->gameData = GAME_DATA_Create(1);
        work->launch->mode = 0;
        if (KEY_GetCont() & 0x100) work->launch->mode = 1;
        if (KEY_GetCont() & 0x400) work->launch->mode = 2;
    } else work->launch = launch;
    work->netErrorPending = 0;
    CTVT_CALL_WorkInit(work);
    return 1;
}

/* Process exit: tears the screens down; generated launch params go with it. */
int COMM_TVT_SYS_ProcExit(struct ProcSys *proc, void *unused, int keepLaunch, CtvtWork *work)
{
    CTVT_CALL_WorkDelete(work);
    if (keepLaunch == 0) {
        GFL_HEAP_Free(work->launch);
    }
    PROCSYS_FreeProcWork(proc);
    GFL_HEAP_DeleteChecked(0x6d);
    return 1;
}

/* Process main: forwards to the running screen and shows the network error screen once. */
int COMM_TVT_SYS_ProcMain(void *proc, void *unused1, void *unused2, CtvtWork *work)
{
    if (GFL_NET_ERR_GetErrorLevel() != 0 && work->netErrorPending == 0) {
        GFL_NET_ERR_RequestScreen();
        work->netErrorPending = 1;
    }
    if (CTVT_CALL_WorkMain(work) == 1) {
        return 1;
    }
    return 0;
}
