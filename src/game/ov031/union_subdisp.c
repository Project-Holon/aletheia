/*
 * file:     union_subdisp.c
 * unit:     yes
 * function: UNION_SUBDISP_Create, UNION_SUBDISP_Delete, UNION_SUBDISP_Draw, UNION_SUBDISP_Update, UNION_SUBDISP_CreateSystems, UNION_SUBDISP_DeleteSystems, UNION_SUBDISP_InitBgs, UNION_SUBDISP_ExitBgs, UNION_SUBDISP_LoadFrameBg, UNION_SUBDISP_FreeFrameBgChar, UNION_SUBDISP_CreateLineWindows, UNION_SUBDISP_DeleteLineWindows, UNION_SUBDISP_LoadActorRes, UNION_SUBDISP_DeleteActorRes, UNION_SUBDISP_CreateActors, UNION_SUBDISP_DeleteActors, UNION_SUBDISP_CheckTouch, UNION_SUBDISP_SelectAppeal, UNION_SUBDISP_UpdateChatLines, UNION_SUBDISP_DrawChatLine, UNION_SUBDISP_DrawVisibleChatLines, UNION_SUBDISP_MoveChatLine, UNION_SUBDISP_ScrollChatLines, UNION_SUBDISP_UpdateKnobDrag, UNION_SUBDISP_SyncKnobAndScroll, UNION_SUBDISP_SetScrollFromKnob, UNION_SUBDISP_SetKnobFromScroll, UNION_SUBDISP_GetScrollRange, UNION_SUBDISP_GetKnobStep, UNION_SUBDISP_CheckTrackTouch, UNION_SUBDISP_CheckLineTouch, UNION_SUBDISP_FindHighlightSlot, UNION_SUBDISP_StartLineHighlight, UNION_SUBDISP_UpdateLineHighlights, UNION_SUBDISP_CancelOtherHighlights, UNION_SUBDISP_SetLinePalette, UNION_SUBDISP_PageScrollByButtons
 * address:  0x021EFEC0
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   PMS_DRAW_Create  0x0202DB0C  thumb
 *   PMS_DRAW_SetNullColorPalette  0x0202DE5C  thumb
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   UNION_MAIN_GetAppealNo  0x02173940  thumb  ov012
 *   UNION_SUBDISP_DrawVisibleChatLines  0x021F09A0  thumb  ov031
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm
 *   GFL_NET_WM_ICON_EasyObjWindowOn  0x02037174  arm
 *   sUnionSubdispFileName   0x021F10C0  data  ov031  a1
 *   sUnionSubdispAppealNo     0x021F1038  data  ov031  a1
 *   PMS_DRAW_Delete  0x0202DC08  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_NET_WM_ICON_EasyObjWindowOff  0x02037190  arm
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   PMS_DRAW_Main  0x0202DBC4  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   UNION_CHAT_LOG_Add  0x021BBA70  thumb  ov021
 *   UNION_SUBDISP_UpdateChatLines  0x021F0680  thumb  ov031
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   UNION_COMM_SetChatType  0x021736C8  thumb  ov012
 *   UNION_SUBDISP_UpdateKnobDrag  0x021F0B98  thumb  ov031
 *   UNION_SUBDISP_CheckTrackTouch  0x021F0D64  thumb  ov031
 *   UNION_SUBDISP_PageScrollByButtons  0x021F0FE0  thumb  ov031
 *   UNION_SUBDISP_SyncKnobAndScroll  0x021F0C34  thumb  ov031
 *   UNION_SUBDISP_CheckLineTouch  0x021F0DB0  thumb  ov031
 *   UNION_SUBDISP_UpdateLineHighlights  0x021F0EF4  thumb  ov031
 *   UNION_MAIN_SetAppealNo  0x02173934  thumb  ov012
 *   CLACT_CreateUnit 0x0204B100 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm
 *   BG_SYS_GetBuf  0x0204162C  arm
 *   ARC_UTIL_LoadPaletteDataFromHandle  0x02049EF4  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole  0x02049B68  arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole  0x02049B40  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   sUnionSubdispBgTemplate5     0x021F1050  data  ov031  a4
 *   sUnionSubdispBgTemplate6     0x021F1070  data  ov031  a4
 *   sUnionSubdispBgTemplate7     0x021F1090  data  ov031  a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_CreateRun  0x0203FA08  arm
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   sUnionSubdispButtonActorParam     0x021F1048  data  a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   PMS_DRAW_IsPrintEnd  0x0202DC98  thumb
 *   UNION_CHAT_LOG_GetLine  0x021BBC2C  thumb  ov021
 *   GF_PANIC_Fail  0x02034714  arm
 *   sUnionSubdispEmptyStr     0x021F10D0  data  a4
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   PMS_DRAW_IsActive  0x0202DCC4  thumb
 *   PMS_DRAW_Clear  0x0202DC9C  thumb
 *   BMP_Clear  0x02043B5C  arm
 *   PMS_DRAW_PrintOffset  0x0202DC60  thumb
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_SetString  0x02045924  arm
 *   sUnionSubdispChatTextOffset     0x021F1040  data  ov031  a4
 *   PMS_DRAW_Copy  0x0202DD24  thumb
 *   BMP_CopyPixels  0x02043814  arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   KEY_GetRepeat  0x0203633C  arm
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "../version.h"
#include "../types.h"
#include "../sdk_ioreg.h"
#include "../sdk_fx.h"

#include "../ov012/union_comm_types.h"
#include "union_subdisp_types.h"
#include "../arm9/key.h"

#define REG_DB_DISPCNT_SUB (*(volatile u32 *)REG_DB_DISPCNT_ADDR)
#define REG_WINOUT_SUB     (*(volatile u16 *)REG_DB_WINOUT_ADDR)
#define REG_DB_BLDCNT_SUB  (*(volatile u16 *)REG_DB_BLDCNT_ADDR)

#define UNION_SUBDISP_VRAM_SUB_BG ((void *)HW_DB_BG_VRAM)

struct BgTemplate;

#include "../arm9/gamesystem.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/arc_tool.h"
struct PmsDraw;
#include "../arm9/pms_draw.h"
#include "../arm9/game_comm.h"
#include "../ov012/union_main.h"
struct ClactActor;
#include "../arm9/clact.h"
#include "../arm9/net.h"
#include "../arm9/wm_icon.h"
#include "../arm9/g2.h"
struct PrintQueue;
#include "../arm9/printsys.h"
struct BmpWin;
struct Bmp;
#include "../arm9/bmp_win.h"
struct UnionBeaconPc;
struct UnionRoomWork;
#include "../ov021/union_chat_log.h"
#include "../ov012/union_comm.h"
#include "../arm9/gf_font.h"
#include "../arm9/msgdata.h"
#include "../arm9/bg_sys.h"
#include "../arm9/mi_memory.h"
#include "../arm9/arc_util.h"
#include "../arm9/touchpanel.h"
#include "../arm9/gfl_use.h"
UnionSubdispWork *UNION_SUBDISP_Create(struct GameSystem *gameSystem);
void UNION_SUBDISP_Delete(UnionSubdispWork *work);
void UNION_SUBDISP_Draw(UnionSubdispWork *work, int mode);
void UNION_SUBDISP_Update(UnionSubdispWork *work, int mode);
void UNION_SUBDISP_CreateSystems(UnionSubdispWork *work);
void UNION_SUBDISP_DeleteSystems(UnionSubdispWork *work);
void UNION_SUBDISP_InitBgs(UnionSubdispWork *work, void *archive);
void UNION_SUBDISP_ExitBgs(UnionSubdispWork *work);
void UNION_SUBDISP_LoadFrameBg(UnionSubdispWork *work);
void UNION_SUBDISP_FreeFrameBgChar(UnionSubdispWork *work);
void UNION_SUBDISP_CreateLineWindows(UnionSubdispWork *work);
void UNION_SUBDISP_DeleteLineWindows(UnionSubdispWork *work);
void UNION_SUBDISP_LoadActorRes(UnionSubdispWork *work, void *archive);
void UNION_SUBDISP_DeleteActorRes(UnionSubdispWork *work);
void UNION_SUBDISP_CreateActors(UnionSubdispWork *work, void *archive);
void UNION_SUBDISP_DeleteActors(UnionSubdispWork *work);
int UNION_SUBDISP_CheckTouch(UnionSubdispWork *work, UnionRoomWork *unionWork);
void UNION_SUBDISP_SelectAppeal(UnionSubdispWork *work, int sel);
extern char sUnionSubdispFileName[];
extern u8 sUnionSubdispAppealNo[];
extern const u8 sUnionSubdispBgTemplate5[];
extern const u8 sUnionSubdispBgTemplate6[];
extern const u8 sUnionSubdispBgTemplate7[];
extern const struct ActorInitParam sUnionSubdispButtonActorParam;

/*
 * The chat log part of the union room sub screen: the last three lines of
 * the chat log drawn on the touch screen, and the scroll bar at its right
 * edge. The work is UnionSubdispWork of union_subdisp.c.
 *
 * Chat log fields as this file uses them (UnionChatLog in
 * union_comm_types.h): newestIndex is the absolute index of the newest line,
 * scrollIndex (offset 0x440) is the index of the line at the bottom of the
 * screen, that is the scroll position, and drawnIndex (offset 0x444) is the
 * scroll position that was drawn last.
 */

struct Strbuf;
struct GfFont;

/* Position of the text inside a line window. */
typedef struct UnionSubdispTextOffset {
    int x;
    int y;
} UnionSubdispTextOffset;

typedef enum { RowZero } RowOffset;

/* Chat log screen geometry and other numbers. */
enum {
    UNION_SUBDISP_ROWS_PER_LINE = 7,          /* tile rows of one line on bg 6 */
    UNION_SUBDISP_LINE_TOUCH_HEIGHT = 0x38,
    UNION_SUBDISP_LINE_COPY_SIZE = 0x1C0,     /* bytes of the screen rows of one line */
    UNION_SUBDISP_LINE_COPY_STRIDE = 0xE0,    /* screen entries of one line */
    UNION_SUBDISP_KNOB_X = 0xF4,              /* the scroll knob moves on this column */
    UNION_SUBDISP_KNOB_Y_MIN = 0x1C,
    UNION_SUBDISP_KNOB_Y_MAX = 0x9C,
    UNION_SUBDISP_KNOB_GRAB_RADIUS = 0xB,
    UNION_SUBDISP_TRACK_X_MIN = 0xE9,         /* touch area of the scroll bar */
    UNION_SUBDISP_TRACK_X_MAX = 0xFF,
    UNION_SUBDISP_LIST_TOUCH_X_MAX = 0xE8,    /* touch area of the lines */
    UNION_SUBDISP_HIGHLIGHT_FRAMES = 0x5A,
    UNION_SUBDISP_SCROLL_RANGE_MAX = 0x1D,    /* lines the scroll bar can cover */
    UNION_SUBDISP_BG_CHAT = 6,                /* bg that holds the line backgrounds */
    UNION_SUBDISP_PRINT_COLOR = 0x440,
    UNION_SUBDISP_NAME_CHARS = 8,
    UNION_SUBDISP_HEAP_ID = 0x15,
    UNION_SUBDISP_SE_SCROLL = 0x548,
    UNION_SUBDISP_SE_SELECT_LINE = 0x54C
};

/* Fixed messages of the union message file: chatType 1..5 and the relation tags. */
enum {
    UNION_SUBDISP_MSG_TYPE1 = 6,
    UNION_SUBDISP_MSG_TYPE2 = 0,
    UNION_SUBDISP_MSG_TYPE3 = 1,
    UNION_SUBDISP_MSG_TYPE4 = 2,
    UNION_SUBDISP_MSG_TYPE5 = 3,
    UNION_SUBDISP_MSG_FRIEND = 4,
    UNION_SUBDISP_MSG_KNOWN = 5
};

struct UnionChatRing;
struct UnionChatLine;
#include "../arm9/gf_panic.h"
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/strbuf.h"

void UNION_SUBDISP_UpdateChatLines(UnionSubdispWork *work, UnionChatLog *log);
void UNION_SUBDISP_DrawChatLine(UnionSubdispWork *work, const UnionChatEntry *entry, u8 lineNo);
void UNION_SUBDISP_DrawVisibleChatLines(UnionSubdispWork *work, UnionChatLog *log);
void UNION_SUBDISP_MoveChatLine(UnionSubdispWork *work, u8 srcLine, u8 dstLine, UnionChatLog *log, int oldBottomIndex);
void UNION_SUBDISP_ScrollChatLines(UnionSubdispWork *work, UnionChatLog *log, int delta);
int UNION_SUBDISP_UpdateKnobDrag(UnionSubdispWork *work);
void UNION_SUBDISP_SyncKnobAndScroll(UnionRoomWork *room, UnionSubdispWork *work);
void UNION_SUBDISP_SetScrollFromKnob(UnionSubdispWork *work, UnionChatLog *log);
void UNION_SUBDISP_SetKnobFromScroll(UnionSubdispWork *work, UnionChatLog *log);
int UNION_SUBDISP_GetScrollRange(UnionChatLog *log);
u32 UNION_SUBDISP_GetKnobStep(void *unused, u32 range);
int UNION_SUBDISP_CheckTrackTouch(UnionSubdispWork *work);
int UNION_SUBDISP_CheckLineTouch(UnionRoomWork *room, UnionSubdispWork *work, UnionChatLog *log);
UnionSubdispLineSlot *UNION_SUBDISP_FindHighlightSlot(UnionSubdispWork *work, UnionChatLog *log, int entryIndex);
int UNION_SUBDISP_StartLineHighlight(UnionSubdispWork *work, UnionChatLog *log, int entryIndex);
void UNION_SUBDISP_UpdateLineHighlights(UnionSubdispWork *work, UnionChatLog *log);
void UNION_SUBDISP_CancelOtherHighlights(UnionSubdispWork *work, UnionChatLog *unused, int entryIndex);
int UNION_SUBDISP_SetLinePalette(UnionSubdispWork *unused, int lineNo, int highlighted);
extern const char sUnionSubdispEmptyStr[];
extern const UnionSubdispTextOffset sUnionSubdispChatTextOffset;

#if LANGUAGE == LANGUAGE_JAPANESE
extern const char str_ja_021F0FE0[];
extern const char str_ja_021F0FF0[];
extern const char str_ja_021F1000[];
extern const char str_ja_021F1010[];
extern const char str_ja_021F1038[];
/* The Japanese build keeps the file name, the line and a message. */
#define UNION_SUBDISP_ASSERT_FAIL(line, msg) GF_PANIC_Fail(str_ja_021F0FE0, line, msg)
#else
/* Both arguments of the assertion failure call are the empty string of the build. */
#define UNION_SUBDISP_ASSERT_FAIL(line, msg) GF_PANIC_Fail(sUnionSubdispEmptyStr, 0, sUnionSubdispEmptyStr)
#endif

/*
 * The 0/1 flag the loop tests (movs r0,#1 / movs r0,#0 / cmp r0,#0) is a
 * `!field` returned from an inline helper: the same test written in place,
 * as a ternary, an if/else local, or a helper returning `== 0` or a ternary,
 * all fold into a direct bne.
 */
static inline int UNION_SUBDISP_PollLineTransfer(UnionSubdispWork *work, int lineNo)
{
    struct PrintQueue *printSys = work->printSys;
    if (work->winSlot[lineNo].transferPending != 0) {
        if (PRINTSYS_QUE_IsExistTarget(printSys, BMP_WIN_GetBmp(work->winSlot[lineNo].win)) == 0) {
            BMP_WIN_TransferChars(work->winSlot[lineNo].win);
            work->winSlot[lineNo].transferPending = 0;
        }
    }
    return !work->winSlot[lineNo].transferPending;
}
void UNION_SUBDISP_PageScrollByButtons(UnionSubdispWork *unused, UnionRoomWork *room);

UnionSubdispWork *UNION_SUBDISP_Create(struct GameSystem *gameSystem)
{
    struct GameComm *gameComm;
    UnionSubdispWork *work;
    void *archive;
    UnionRoomWork *unionWork;
    u32 i;
    u32 winOut;

    gameComm = GAMESYSTEM_GetGameComm(gameSystem);
    work = GFL_HEAP_Alloc(UNION_SUBDISP_HEAP_ID, sizeof(*work), 1, PM_LANG_JA(sUnionSubdispFileName, str_ja_021F0FE0), 0x10F);
    work->gameSystem = gameSystem;
    archive = ARC_TOOL_CreateHandle(0x59, UNION_SUBDISP_HEAP_ID);
    UNION_SUBDISP_CreateSystems(work);
    UNION_SUBDISP_InitBgs(work, archive);
    UNION_SUBDISP_CreateLineWindows(work);
    UNION_SUBDISP_LoadActorRes(work, archive);
    UNION_SUBDISP_CreateActors(work, archive);
    UNION_SUBDISP_LoadFrameBg(work);
    ARC_TOOL_DeleteHandle(archive);
    work->pmsDraw = PMS_DRAW_Create(work->clactUnit, (u32)1, work->printSys, work->font, 9, 3, UNION_SUBDISP_HEAP_ID);
    PMS_DRAW_SetNullColorPalette(work->pmsDraw, 0);
    unionWork = GAME_COMM_GetWork(gameComm);
    if (unionWork != 0) {
        work->appealNo = UNION_MAIN_GetAppealNo(unionWork);
        UNION_SUBDISP_DrawVisibleChatLines(work, &unionWork->chatLog);
        if (work->appealNo != 0) {
            for (i = 0; (i < UNION_SUBDISP_APPEAL_COUNT) ? 1 : 0; i++) {
                /*
                 * stand-in: written as work->appealNo the compiler keeps the
                 * first load in a register across the loop; the original
                 * reloads it each pass. The `? 1 : 0` loop test keeps the
                 * entry branch to the bottom test (a plain `<` is 8 bytes
                 * shorter).
                 */
#ifdef __MWERKS__
                if (sUnionSubdispAppealNo[i] == *((u8 *)work + 0x30)) {
                    CLACT_SetActorPaletteOffset((struct ClactActor *)work->actor[i], 1, 1);
                    break;
                }
#else
                if (sUnionSubdispAppealNo[i] == work->appealNo) {
                    CLACT_SetActorPaletteOffset((struct ClactActor *)work->actor[i], 1, 1);
                    break;
                }
#endif
            }
        }
    }
    GFL_NET_RefreshWmIconAtTopRight(0, UNION_SUBDISP_HEAP_ID);
    GFL_NET_WM_ICON_EasyObjWindowOn();
    REG_WINOUT_SUB = (u16)((REG_WINOUT_SUB & ~0x3F00) | (0x1F << 8));
    winOut = (REG_WINOUT_SUB & ~0x3F) | 0x1F;
    winOut |= 0x20;
    REG_WINOUT_SUB = (u16)winOut;
    REG_DB_DISPCNT_SUB = (REG_DB_DISPCNT_SUB & ~0xE000) | 0x8000;
    return work;
}

void UNION_SUBDISP_Delete(UnionSubdispWork *work)
{
    UnionRoomWork *unionWork;

    unionWork = GAME_COMM_GetWork(GAMESYSTEM_GetGameComm(work->gameSystem));
    if (unionWork != 0)
        unionWork->talkCancel = 0;
    PMS_DRAW_Delete(work->pmsDraw);
    UNION_SUBDISP_FreeFrameBgChar(work);
    UNION_SUBDISP_DeleteActors(work);
    UNION_SUBDISP_DeleteActorRes(work);
    UNION_SUBDISP_DeleteLineWindows(work);
    UNION_SUBDISP_ExitBgs(work);
    UNION_SUBDISP_DeleteSystems(work);
    GFL_HEAP_Free(work);
    REG_DB_BLDCNT_SUB = 0;
    GFL_NET_WM_ICON_EasyObjWindowOff();
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
}

void UNION_SUBDISP_Draw(UnionSubdispWork *work, int mode)
{
    int i;

    GAME_COMM_GetWork(GAMESYSTEM_GetGameComm(work->gameSystem));
    GFL_NET_WM_ICON_EasyObjWindowOn();
    if (mode == 1)
        REG_DB_BLDCNT_SUB = 0;
    else
        G2x_SetBlendBrightness_((uptr)(&REG_DB_BLDCNT_SUB), 0x3F, -8);
    PRINTSYS_QUE_Main(work->printSys);
    PMS_DRAW_Main(work->pmsDraw);
    for (i = 0; i < UNION_SUBDISP_LINE_COUNT; i++) {
        if (work->lineKind[i] == UNION_SUBDISP_LINE_TEXT) {
            /* the local keeps the print system load ahead of the transfer test */
            struct PrintQueue *printSys = work->printSys;
            if (work->winSlot[i].transferPending != 0) {
                if (PRINTSYS_QUE_IsExistTarget(printSys, BMP_WIN_GetBmp(work->winSlot[i].win)) == 0) {
                    BMP_WIN_TransferChars(work->winSlot[i].win);
                    work->winSlot[i].transferPending = 0;
                }
            }
        }
    }
}

void UNION_SUBDISP_Update(UnionSubdispWork *work, int mode)
{
    struct GameComm *gameComm;
    UnionRoomWork *unionWork;
    UnionMySituation *mySituation;
    int touched;

    gameComm = GAMESYSTEM_GetGameComm(work->gameSystem);
    unionWork = GAME_COMM_GetWork(gameComm);
    if (unionWork != 0) {
        mySituation = &unionWork->mySituation;
        if (mySituation->chatUpdated == 1) {
            UNION_CHAT_LOG_Add(unionWork, 0, (u16 *)(&mySituation->chatPms), mySituation->chatType);
            mySituation->chatUpdated = 0;
        }
        UNION_SUBDISP_UpdateChatLines(work, &unionWork->chatLog);
        if (unionWork->chatLog.newestIndex >= 3)
            CLACT_SetActorDrawEnable((struct ClactActor *)work->actor[UNION_SUBDISP_ACTOR_SCROLL_KNOB], 1);
    }
    if (mode == 1) {
        touched = UNION_SUBDISP_CheckTouch(work, unionWork);
        if (unionWork != 0 && touched == 1) {
            switch (work->appealNo) {
            case 0:
                break;
            case 1:
                UNION_COMM_SetChatType(unionWork, 2);
                break;
            case 2:
                UNION_COMM_SetChatType(unionWork, 3);
                break;
            case 3:
                break;
            case 4:
                UNION_COMM_SetChatType(unionWork, 4);
                break;
            case 5:
                UNION_COMM_SetChatType(unionWork, 5);
                break;
            }
        }
        work->inputResult = UNION_SUBDISP_UpdateKnobDrag(work);
        if (work->inputResult == 0)
            work->inputResult = UNION_SUBDISP_CheckTrackTouch(work);
        if (work->inputResult == 0 && unionWork != 0)
            UNION_SUBDISP_PageScrollByButtons(work, unionWork);
    }
    if (unionWork != 0) {
        UNION_SUBDISP_SyncKnobAndScroll(unionWork, work);
        if (mode == 1)
            UNION_SUBDISP_CheckLineTouch(unionWork, work, &unionWork->chatLog);
        UNION_SUBDISP_UpdateLineHighlights(work, &unionWork->chatLog);
    }
    if (GAME_COMM_GetKind(gameComm) == 3 && unionWork != 0)
        UNION_MAIN_SetAppealNo(unionWork, work->appealNo);
}

/*
 * extent: trailing two-byte zero alignment padding.
 */
void UNION_SUBDISP_CreateSystems(UnionSubdispWork *work)
{
    work->clactUnit = CLACT_CreateUnit(12, 5, UNION_SUBDISP_HEAP_ID);
    work->printSys = (struct PrintQueue *)PRINTSYS_QUE_Create(UNION_SUBDISP_HEAP_ID);
    work->font = GF_FONT_Create(23, 0, 0, 0, UNION_SUBDISP_HEAP_ID);
    work->msgData = MSGDATA_CreateFromArchive(0, 2, 201, UNION_SUBDISP_HEAP_ID);
}

void UNION_SUBDISP_DeleteSystems(UnionSubdispWork *work)
{
    MSGDATA_Delete(work->msgData);
    GF_FONT_Delete(work->font);
    PRINTSYS_QUE_Clear(work->printSys);
    PRINTSYS_QUE_Delete(work->printSys);
    CLACT_DeleteUnit(work->clactUnit);
}

/*
 * volatile: 0x021F0288 ldr / 0x021F028E str of 0x04001000 (REG_DB_DISPCNT_SUB read-modify-write); 0x021F0294 strh to 0x04001050 (hardware registers)
 */
void UNION_SUBDISP_InitBgs(UnionSubdispWork *work, void *archive)
{
    u16 *palette;
    u8 *palData;
    void *palFile;

    BG_SYS_InitBgLayer(5, (const struct BgTemplate *)sUnionSubdispBgTemplate5, 0);
    BG_SYS_InitBgLayer(6, (const struct BgTemplate *)sUnionSubdispBgTemplate6, 0);
    BG_SYS_InitBgLayer(7, (const struct BgTemplate *)sUnionSubdispBgTemplate7, 0);
    MIi_CpuClear32(0, UNION_SUBDISP_VRAM_SUB_BG, 0x20000);
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
    REG_DB_BLDCNT_SUB = 0;
    ARC_UTIL_UploadBgCharFromHandle(archive, 0xF, 7, 0, 0, 0, UNION_SUBDISP_HEAP_ID);
    ARC_UTIL_UploadBgPaletteFromHandle(archive, 0x11, 7, 0, 0x800, 0, UNION_SUBDISP_HEAP_ID);
    palette = (u16 *)BG_SYS_GetBuf(6);
    palFile = ARC_UTIL_LoadPaletteDataFromHandle(archive, 0x12, 0, (void **)&palData, UNION_SUBDISP_HEAP_ID);
    MI_CpuCopy8(palData + 0xC, palette, 0x1C0);
    GFL_HEAP_Free(palFile);
    ARC_UTIL_UploadPaletteFromHandleWhole(archive, 0x10, 4, 0, 0xA0, UNION_SUBDISP_HEAP_ID);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x1E0, 0x20, UNION_SUBDISP_HEAP_ID);
    BG_SYS_SetPlaneVisible(4, 0);
    BG_SYS_SetPlaneVisible(7, 1);
    BG_SYS_SetPlaneVisible(6, 1);
    BG_SYS_SetPlaneVisible(5, 1);
}

void UNION_SUBDISP_ExitBgs(UnionSubdispWork *work)
{
    BG_SYS_SetPlaneVisible(5, 0);
    BG_SYS_SetPlaneVisible(6, 0);
    BG_SYS_SetPlaneVisible(7, 0);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(7);
}

/*
 * Both copy pointers are u16 element offsets (+0x2A0), not byte offsets:
 * `(u16 *)(screenData + 0xC) + 0x2A0` keeps the +0xC add apart, so the 0x540
 * byte offset is built as `lsls rN, r7, #6` off the register holding 0x15
 * instead of folding with 0xC into a pooled 0x54C.
 */
void UNION_SUBDISP_LoadFrameBg(UnionSubdispWork *work)
{
    void *archive;
    u32 charOffset;
    u16 *screen;
    void *screenFile;
    u8 *screenData;
    int i;

    archive = ARC_TOOL_CreateHandle(0x53, UNION_SUBDISP_HEAP_ID);
    charOffset = BG_SYS_CreateRun(5, 0x80, 1);
    work->bgCharOffset = charOffset;
    ARC_UTIL_UploadBgCharFromHandle(archive, 0x1C, 5, charOffset, 0x80, 0, UNION_SUBDISP_HEAP_ID);
    screen = (u16 *)BG_SYS_GetBuf(5);
    screenFile = ARC_UTIL_LoadPaletteDataFromHandle(archive, 0x1D, 0, (void **)&screenData, UNION_SUBDISP_HEAP_ID);
    MI_CpuCopy8((u16 *)(screenData + 0xC) + 0x2A0, screen + 0x2A0, 0xC0);
    GFL_HEAP_Free(screenFile);
    for (i = 0; i < 0x60; i++)
        screen[0x2A0 + i] = (screen[0x2A0 + i] & 0xFFF) + charOffset + 0xD000;
    ARC_UTIL_UploadPaletteFromHandleWhole(archive, 0x1B, 4, 0x1A0, 0x20, UNION_SUBDISP_HEAP_ID);
    ARC_TOOL_DeleteHandle(archive);
}

void UNION_SUBDISP_FreeFrameBgChar(UnionSubdispWork *work)
{
    BG_SYS_FreeTileRun(5, work->bgCharOffset, 128);
}

/*
 * Re-reading the just-stored work->lineWin[i] as the source of the second
 * store (instead of a local or a chained assignment) is what makes the
 * compiler form &work->lineWin[i] before the call in a callee-saved register,
 * which in turn leaves room for only the first stack constant (7) to be
 * hoisted.
 */
void UNION_SUBDISP_CreateLineWindows(UnionSubdispWork *work)
{
    int i;

    for (i = 0; i < UNION_SUBDISP_LINE_COUNT; i++) {
        work->lineWin[i] = BMP_WIN_Create(5, 1, (u8)(i * 0x38 / 8), 0x1D, 7, 0xF, 1);
        work->winSlot[i].win = work->lineWin[i];
        work->winSlot[i].transferPending = 0;
    }
}

void UNION_SUBDISP_DeleteLineWindows(UnionSubdispWork *work)
{
    int i;
    for (i = 0; i < UNION_SUBDISP_LINE_COUNT; i++) {
        BMP_WIN_Delete(work->lineWin[i]);
    }
}

void UNION_SUBDISP_LoadActorRes(UnionSubdispWork *work, void *archive)
{
    work->palRes = CLACT_RegisterPaletteEx(archive, 0x13, 1, 0, 0, 3, UNION_SUBDISP_HEAP_ID);
    work->charRes = CLACT_RegisterCharacter(archive, 0xE, 0, 1, UNION_SUBDISP_HEAP_ID);
    work->cellRes = CLACT_RegisterCellAnim(archive, 0xC, 0xD, UNION_SUBDISP_HEAP_ID);
}

void UNION_SUBDISP_DeleteActorRes(UnionSubdispWork *work)
{
    CLACT_ReleasePalette((u32)work->palRes);
    CLACT_ReleaseCharacter((u32)work->charRes);
    CLACT_ReleaseCellAnim((u32)work->cellRes);
}

void UNION_SUBDISP_CreateActors(UnionSubdispWork *work, void *archive)
{
    struct ActorInitParam param;
    int i;

    param = sUnionSubdispButtonActorParam;
    for (i = 0; i <= 4; i++) {
        param.x = i * 0x30 + 0x20;
        param.anim_seq = i;
        work->actor[i] = CLACT_CreateActor(work->clactUnit, work->charRes, work->palRes, work->cellRes, &param, 1, UNION_SUBDISP_HEAP_ID);
    }
    param.anim_seq = 5;
    param.x = 0xF4;
    param.y = 0x9C;
    work->actor[UNION_SUBDISP_ACTOR_SCROLL_KNOB] = CLACT_CreateActor(work->clactUnit, work->charRes, work->palRes, work->cellRes, &param, 1, UNION_SUBDISP_HEAP_ID);
    CLACT_SetActorDrawEnable((struct ClactActor *)work->actor[UNION_SUBDISP_ACTOR_SCROLL_KNOB], 0);
}

void UNION_SUBDISP_DeleteActors(UnionSubdispWork *work)
{
    int i;

    for (i = 0; i < UNION_SUBDISP_ACTOR_COUNT; i++)
        CLACT_DeleteActor((struct ClactActor *)work->actor[i]);
}

int UNION_SUBDISP_CheckTouch(UnionSubdispWork *work, UnionRoomWork *unionWork)
{
    u32 touchX;
    u32 touchY;
    struct ClactVec2 pos;
    int i;
    s16 left;
    s16 right;
    s16 top;
    s16 bottom;

    if (TOUCHPANEL_GetPointTrg(&touchX, &touchY) == 0)
        return 0;
    for (i = 0; i <= 4; i++) {
        CLACT_GetActorSurfacePos(work->actor[i], &pos, 1);
        top = pos.y - 10;
        bottom = pos.y + 10;
        right = pos.x + 10;
        left = pos.x - 10;
        if (left < touchX && right > touchX && top < touchY && bottom > touchY) {
            if (i == 0 && unionWork != 0) {
                unionWork->talkCancel = 1;
                return 0;
            }
            UNION_SUBDISP_SelectAppeal(work, i);
            GFL_USE_PlaySeDefaultVolume(0x54B);
            return 1;
        }
    }
    return 0;
}

/*
 * The store to appealNo is written in both arms of an if/else (keeps the
 * empty `b` to the next instruction), and the loop condition is a
 * `? 1 : 0` ternary (keeps the entry branch to the bottom test).
 */
void UNION_SUBDISP_SelectAppeal(UnionSubdispWork *work, int sel)
{
    int i;
    int appealNo;

    appealNo = sUnionSubdispAppealNo[sel];
    if (appealNo == work->appealNo)
        work->appealNo = 0;
    else
        work->appealNo = appealNo;
    for (i = 0; (i <= 4) ? 1 : 0; i++) {
        if (i == sel && work->appealNo != 0)
            CLACT_SetActorPaletteOffset((struct ClactActor *)work->actor[i], 1, 1);
        else
            CLACT_SetActorPaletteOffset((struct ClactActor *)work->actor[i], 0, 1);
    }
}

/* Redraws the lines whose content changed since the last call. */
void UNION_SUBDISP_UpdateChatLines(UnionSubdispWork *work, UnionChatLog *log)
{
    int scrolled;
    int i;
    int delta;
    UnionChatEntry *entry;

    scrolled = 0;
    if (log->drawnIndex == log->scrollIndex)
        return;
    if (PMS_DRAW_IsPrintEnd(work->pmsDraw) == 0)
        return;
    for (i = 0; i < 3; i++) {
        if (work->lineKind[i] == UNION_SUBDISP_LINE_TEXT) {
            if (UNION_SUBDISP_PollLineTransfer(work, i) == 0)
                return;
        }
    }
    if (log->newestIndex < 3) {
        for (i = log->drawnIndex; i <= log->scrollIndex; i++) {
            if (i > -1) {
                entry = (struct UnionChatEntry *)UNION_CHAT_LOG_GetLine((struct UnionChatRing *)log, i);
                if (entry == 0)
                    UNION_SUBDISP_ASSERT_FAIL(0x37C, str_ja_021F0FF0);
                UNION_SUBDISP_DrawChatLine(work, entry, i);
            }
        }
    } else {
        delta = log->scrollIndex - log->drawnIndex;
        if (((delta < 0) ? -delta : delta) >= 3 || log->drawnIndex < 2)
            UNION_SUBDISP_DrawVisibleChatLines(work, log);
        else
            UNION_SUBDISP_ScrollChatLines(work, log, delta);
        scrolled = 1;
    }
    if (scrolled == 1)
        GFL_USE_PlaySeDefaultVolume(UNION_SUBDISP_SE_SCROLL);
    log->drawnIndex = log->scrollIndex;
}

static inline int UNION_SUBDISP_GetLinePalette(const UnionChatEntry *entry)
{
    if (entry->sex == 0) return 0;
    return 2;
}

/* Draws one chat log entry into line lineNo: background, text and sender name. */
void UNION_SUBDISP_DrawChatLine(UnionSubdispWork *work, const UnionChatEntry *entry, u8 lineNo)
{
    u16 *screen;
    int palette;
    UnionSubdispTextOffset textOffset;
    struct Strbuf *text;
    struct Strbuf *name;
    struct PrintQueue *printSys;
    int offset;

    screen = (u16 *)BG_SYS_GetBuf(UNION_SUBDISP_BG_CHAT);
    offset = (lineNo * UNION_SUBDISP_LINE_COPY_STRIDE) << 1;
    palette = UNION_SUBDISP_GetLinePalette(entry);
    MI_CpuCopy8(screen, (u8 *)screen + offset, UNION_SUBDISP_LINE_COPY_SIZE);
    BG_SYS_FillTileMap(UNION_SUBDISP_BG_CHAT, 0, lineNo * UNION_SUBDISP_ROWS_PER_LINE, 0x20, UNION_SUBDISP_ROWS_PER_LINE, palette);
    BG_SYS_MarkTileDirty(UNION_SUBDISP_BG_CHAT);
    textOffset = sUnionSubdispChatTextOffset;
    if (work->lineKind[lineNo] == UNION_SUBDISP_LINE_PMS) {
        if (PMS_DRAW_IsActive(work->pmsDraw, lineNo) == 1)
            PMS_DRAW_Clear(work->pmsDraw, lineNo, 1);
    } else if (work->lineKind[lineNo] == UNION_SUBDISP_LINE_TEXT) {
        BMP_Clear(BMP_WIN_GetBmp(work->lineWin[lineNo]), 0);
        BMP_WIN_TransferChars(work->lineWin[lineNo]);
    }
    if (entry->chatType == 0) {
        PMS_DRAW_PrintOffset(work->pmsDraw, work->lineWin[lineNo], (void *)&entry->chatPms, lineNo, &textOffset);
        work->lineKind[lineNo] = UNION_SUBDISP_LINE_PMS;
    } else {
        switch (entry->chatType) {
        case 1:
            text = MSGDATA_AllocString(work->msgData, UNION_SUBDISP_MSG_TYPE1);
            break;
        case 2:
            text = MSGDATA_AllocString(work->msgData, UNION_SUBDISP_MSG_TYPE2);
            break;
        case 3:
            text = MSGDATA_AllocString(work->msgData, UNION_SUBDISP_MSG_TYPE3);
            break;
        case 4:
            text = MSGDATA_AllocString(work->msgData, UNION_SUBDISP_MSG_TYPE4);
            break;
        case 5:
            text = MSGDATA_AllocString(work->msgData, UNION_SUBDISP_MSG_TYPE5);
            break;
        case 0:
            return;
        default:
            return;
        }
        BMP_WIN_MakeScreen(work->lineWin[lineNo]);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(work->lineWin[lineNo]));
        printSys = work->printSys;
        PRINTSYS_PrintQueColor(printSys, BMP_WIN_GetBmp(work->winSlot[lineNo].win), 0, textOffset.y, text, work->font, UNION_SUBDISP_PRINT_COLOR);
        work->winSlot[lineNo].transferPending = 1;
        STRBUF_Delete(text);
        work->lineKind[lineNo] = UNION_SUBDISP_LINE_TEXT;
    }
    name = STRBUF_Create(UNION_SUBDISP_NAME_CHARS, UNION_SUBDISP_HEAP_ID);
    STRBUF_SetString(name, entry->name);
    PRINTSYS_PrintQueColor(work->printSys, BMP_WIN_GetBmp(work->lineWin[lineNo]), 0, 0, name, work->font, UNION_SUBDISP_PRINT_COLOR);
    STRBUF_Delete(name);
    if (entry->relation != 0) {
        name = MSGDATA_AllocString(work->msgData, (entry->relation == 1) ? UNION_SUBDISP_MSG_FRIEND : UNION_SUBDISP_MSG_KNOWN);
        PRINTSYS_PrintQueColor(work->printSys, BMP_WIN_GetBmp(work->lineWin[lineNo]), 0x74, 0, name, work->font, UNION_SUBDISP_PRINT_COLOR);
        STRBUF_Delete(name);
    }
}

/* Draws the three lines that end at the scroll position. */
void UNION_SUBDISP_DrawVisibleChatLines(UnionSubdispWork *work, UnionChatLog *log)
{
    int lineNo;
    int i = log->scrollIndex;
    int stop = i - 3;
    UnionChatEntry *entry;

    if (stop < 0)
        stop = -1;
    lineNo = i - stop - 1;
    for (; i > stop; i--, lineNo--) {
        entry = (struct UnionChatEntry *)UNION_CHAT_LOG_GetLine((struct UnionChatRing *)log, i);
        if (entry == 0)
            UNION_SUBDISP_ASSERT_FAIL(0x414, str_ja_021F0FF0);
        if (lineNo <= -1)
            UNION_SUBDISP_ASSERT_FAIL(0x415, str_ja_021F1000);
        UNION_SUBDISP_DrawChatLine(work, entry, (u8)lineNo);
    }
}

/*
 * Moves the screen rows and the content of line srcLine to line dstLine. A
 * line without a copy source is drawn again from the chat log.
 *
 * lever: enum byte-offset locals, product by 0xE0 then separate <<= 1, recover sequential source/destination scaling and entry copies; integer offsets and enum halfword indexes do not.
 * extent: 154 instruction bytes followed by two zero alignment bytes; the next function is separately matched.
 */
void UNION_SUBDISP_MoveChatLine(UnionSubdispWork *work, u8 srcLine, u8 dstLine, UnionChatLog *log, int oldBottomIndex)
{
    u16 *screen;
    u16 *dst;
    u16 *src;
    /* stand-in: enum byte offsets are the only form that matches the scaling of the two line offsets */
    RowOffset destOffset;
    RowOffset sourceOffset;

    screen = (u16 *)BG_SYS_GetBuf(UNION_SUBDISP_BG_CHAT);
    destOffset = dstLine * UNION_SUBDISP_LINE_COPY_STRIDE;
    destOffset <<= 1;
    sourceOffset = srcLine * UNION_SUBDISP_LINE_COPY_STRIDE;
    sourceOffset <<= 1;
    dst = (u16 *)((u8 *)screen + destOffset);
    src = (u16 *)((u8 *)screen + sourceOffset);
    MI_CpuCopy8(src, dst, UNION_SUBDISP_LINE_COPY_SIZE);
    BG_SYS_MarkTileDirty(UNION_SUBDISP_BG_CHAT);
    if (work->lineKind[srcLine] == UNION_SUBDISP_LINE_PMS && work->lineKind[dstLine] == UNION_SUBDISP_LINE_PMS) {
        PMS_DRAW_Copy(work->pmsDraw, srcLine, dstLine);
        return;
    }
    if (work->lineKind[srcLine] == UNION_SUBDISP_LINE_TEXT && work->lineKind[dstLine] == UNION_SUBDISP_LINE_TEXT) {
        BMP_CopyPixels(BMP_WIN_GetBmp(work->lineWin[srcLine]), BMP_WIN_GetBmp(work->lineWin[dstLine]));
        BMP_WIN_TransferChars(work->lineWin[dstLine]);
        return;
    }
    UNION_SUBDISP_DrawChatLine(work, (struct UnionChatEntry *)UNION_CHAT_LOG_GetLine((struct UnionChatRing *)log, oldBottomIndex - 2 + srcLine), dstLine);
}

/*
 * Scrolls the three lines by delta lines: the lines that stay are moved, the
 * lines that come into view are drawn from the chat log.
 */
void UNION_SUBDISP_ScrollChatLines(UnionSubdispWork *work, UnionChatLog *log, int delta)
{
    long i; /* stand-in: long (not int) is what matches the register use of the loop counter */
    int dstLine;
    UnionChatEntry *entry;

    if (delta > 0) {
        for (i = delta, dstLine = 0; i < 3; i++) {
            UNION_SUBDISP_MoveChatLine(work, i, dstLine, log, log->scrollIndex - delta);
            dstLine++;
        }
        for (dstLine = 3 - delta; dstLine < 3; dstLine++) {
            entry = (struct UnionChatEntry *)UNION_CHAT_LOG_GetLine((struct UnionChatRing *)log, log->scrollIndex - 2 + dstLine);
            if (entry == 0)
                UNION_SUBDISP_ASSERT_FAIL(0x45F, str_ja_021F0FF0);
            UNION_SUBDISP_DrawChatLine(work, entry, (u8)dstLine);
        }
    } else {
        for (i = delta + 2, dstLine = 2; i > -1; i--) {
            UNION_SUBDISP_MoveChatLine(work, i, dstLine, log, log->scrollIndex - delta);
            dstLine--;
        }
        for (dstLine = -1 - delta; dstLine > -1; dstLine--) {
            entry = (struct UnionChatEntry *)UNION_CHAT_LOG_GetLine((struct UnionChatRing *)log, log->scrollIndex - 2 + dstLine);
            if (entry == 0)
#if LANGUAGE == LANGUAGE_JAPANESE
                GF_PANIC_FailPrintf(str_ja_021F0FE0, 0x46F, str_ja_021F1010, log->scrollIndex, dstLine, delta);
#else
                UNION_SUBDISP_ASSERT_FAIL(0, 0);
#endif
            UNION_SUBDISP_DrawChatLine(work, entry, (u8)dstLine);
        }
    }
}

/*
 * Keeps the scroll knob under the stylus while it is held. Returns 1 while
 * the knob is dragged.
 */
int UNION_SUBDISP_UpdateKnobDrag(UnionSubdispWork *work)
{
    struct ClactVec2 pos;
    u32 x;
    u32 y;
    int touched;

    if (TOUCHPANEL_GetPointCont(&x, &y) == 0)
        return 0;
    touched = 1;
    CLACT_GetActorSurfacePos(work->actor[UNION_SUBDISP_ACTOR_SCROLL_KNOB], &pos, 1);
    if (work->inputResult == 0) {
        if (TOUCHPANEL_GetTrg() == 0)
            return 0;
        if ((u32)(pos.x - UNION_SUBDISP_KNOB_GRAB_RADIUS) <= x && (u32)(pos.x + UNION_SUBDISP_KNOB_GRAB_RADIUS) >= x &&
            (u32)(pos.y - UNION_SUBDISP_KNOB_GRAB_RADIUS) <= y && (u32)(pos.y + UNION_SUBDISP_KNOB_GRAB_RADIUS) >= y)
            return touched;
    } else {
        if (y < UNION_SUBDISP_KNOB_Y_MIN)
            y = UNION_SUBDISP_KNOB_Y_MIN;
        else if (y > UNION_SUBDISP_KNOB_Y_MAX)
            y = UNION_SUBDISP_KNOB_Y_MAX;
        pos.y = y;
        CLACT_AddActorSurfacePos(work->actor[UNION_SUBDISP_ACTOR_SCROLL_KNOB], &pos, 1);
        return 1;
    }
    return 0;
}

/* While the knob is dragged the scroll position follows it, otherwise the knob follows the scroll position. */
void UNION_SUBDISP_SyncKnobAndScroll(UnionRoomWork *room, UnionSubdispWork *work)
{
    if (work->inputResult == 1)
        UNION_SUBDISP_SetScrollFromKnob(work, &room->chatLog);
    else
        UNION_SUBDISP_SetKnobFromScroll(work, &room->chatLog);
}

/*
 * Sets the scroll position of the chat log from the position of the knob.
 * UNION_SUBDISP_GetKnobStep is filed as a 12-byte tail stub (r0 = 0x8000, r1 kept); the
 * call sites pass (log, range), so it is declared with two arguments here.
 */
void UNION_SUBDISP_SetScrollFromKnob(UnionSubdispWork *work, UnionChatLog *log)
{
    struct ClactVec2 pos;
    int range;
    int knobY;
    int step;
    int position;
    int j;

    CLACT_GetActorSurfacePos(work->actor[UNION_SUBDISP_ACTOR_SCROLL_KNOB], &pos, 1);
    knobY = (pos.y - UNION_SUBDISP_KNOB_Y_MIN) << 8;
    range = UNION_SUBDISP_GetScrollRange(log);
    step = UNION_SUBDISP_GetKnobStep(log, range);
    position = 0;
    knobY = knobY + (step >> 1);
    for (j = 0; j < range; j++) {
        if (knobY <= step * (position + 1))
            break;
        position++;
    }
    if (position >= range)
        position = range;
    log->scrollIndex = position + (log->newestIndex - range);
    if (log->scrollIndex < 3) {
        if (log->newestIndex < 3)
            log->scrollIndex = log->newestIndex;
        else
            log->scrollIndex = 2;
    }
    if (log->scrollIndex < 0 || log->scrollIndex > log->newestIndex)
        log->scrollIndex = log->newestIndex;
}

/* Moves the knob to the place of the scroll position. */
void UNION_SUBDISP_SetKnobFromScroll(UnionSubdispWork *work, UnionChatLog *log)
{
    struct ClactVec2 pos;
    int range;
    int step;

    range = UNION_SUBDISP_GetScrollRange(log);
    step = UNION_SUBDISP_GetKnobStep(log, range);
    if (log->newestIndex - log->scrollIndex > 0x1B)
        log->scrollIndex = log->newestIndex - 0x1B;
    pos.y = UNION_SUBDISP_KNOB_Y_MAX - ((u32)((log->newestIndex - log->scrollIndex) * step) >> 8);
    pos.x = UNION_SUBDISP_KNOB_X;
    CLACT_AddActorSurfacePos(work->actor[UNION_SUBDISP_ACTOR_SCROLL_KNOB], &pos, 1);
}

/*
 * Number of scroll steps of the knob: the lines of the log (at most 0x1D)
 * minus the two lines that are always visible above the bottom line.
 * Unlabelled leaf (no lr push) sitting in a word run; filed as a blocker of
 * the two knob functions above.
 */
int UNION_SUBDISP_GetScrollRange(UnionChatLog *log)
{
    int range = log->newestIndex;

    if (range >= UNION_SUBDISP_SCROLL_RANGE_MAX + 1)
        range = UNION_SUBDISP_SCROLL_RANGE_MAX;
    range -= 2;
    if (range < 0)
        range = 0;
    return range;
}

/* Height of one scroll step in 8.8 fixed point pixels: the knob travel of 0x80 pixels divided by the number of steps. */
u32 UNION_SUBDISP_GetKnobStep(void *unused, u32 range)
{
    return 0x8000 / range;
}

/* A new touch on the scroll bar moves the knob there. Returns 1 when it did. */
int UNION_SUBDISP_CheckTrackTouch(UnionSubdispWork *work)
{
    struct ClactVec2 pos;
    u32 x;
    u32 y;

    if (TOUCHPANEL_GetPointTrg(&x, &y) == 0)
        return 0;
    if (x >= UNION_SUBDISP_TRACK_X_MIN && x <= UNION_SUBDISP_TRACK_X_MAX && y >= UNION_SUBDISP_KNOB_Y_MIN && y <= UNION_SUBDISP_KNOB_Y_MAX) {
        pos.x = UNION_SUBDISP_KNOB_X;
        pos.y = y;
        CLACT_AddActorSurfacePos(work->actor[UNION_SUBDISP_ACTOR_SCROLL_KNOB], &pos, 1);
        return 1;
    }
    return 0;
}

/*
 * A new touch on one of the three lines highlights it and stores the sender
 * of the line as the member the field should show.
 * lineNo stays unset when the touch is right of the line area; the original
 * reads it in that case.
 */
int UNION_SUBDISP_CheckLineTouch(UnionRoomWork *room, UnionSubdispWork *work, UnionChatLog *log)
{
    u32 x;
    u32 y;
    int lineNo;
    int entryIndex;
    UnionChatEntry *entry;

    if (TOUCHPANEL_GetPointTrg(&x, &y) == 0)
        return 0;
    if (x <= UNION_SUBDISP_LIST_TOUCH_X_MAX) {
        for (lineNo = 0; lineNo < 3; lineNo++) {
            if (y >= (u32)(lineNo * UNION_SUBDISP_LINE_TOUCH_HEIGHT) && y <= (u32)(lineNo * UNION_SUBDISP_LINE_TOUCH_HEIGHT + UNION_SUBDISP_LINE_TOUCH_HEIGHT))
                break;
        }
    }
    if (lineNo >= 3 || lineNo > log->newestIndex)
        return 0;
    if (UNION_SUBDISP_SetLinePalette(work, lineNo, 1) == 1) {
        entryIndex = lineNo;
        lineNo = log->scrollIndex;
        if (lineNo >= 3)
            lineNo = lineNo - 2 + entryIndex;
        else
            lineNo = entryIndex;
        UNION_SUBDISP_StartLineHighlight(work, log, lineNo);
        entry = (struct UnionChatEntry *)UNION_CHAT_LOG_GetLine((struct UnionChatRing *)log, lineNo);
        if (entry != 0)
            MI_CpuCopy8(entry->senderMac, room->mySituation.focusMac, 6);
        UNION_SUBDISP_CancelOtherHighlights(work, log, lineNo);
        GFL_USE_PlaySeDefaultVolume(UNION_SUBDISP_SE_SELECT_LINE);
        return 1;
    }
    return 0;
}

/*
 * Finds the highlight slot for a chat log entry: the slot that already holds
 * it, else a free slot, else a slot whose entry has scrolled out of view.
 */
UnionSubdispLineSlot *UNION_SUBDISP_FindHighlightSlot(UnionSubdispWork *work, UnionChatLog *log, int entryIndex)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (work->lineSlot[i].timer != 0 && entryIndex == work->lineSlot[i].entryIndex)
            return &work->lineSlot[i];
    }
    for (i = 0; i < 3; i++) {
        if (work->lineSlot[i].timer == 0)
            return &work->lineSlot[i];
    }
    for (i = 0; i < 3; i++) {
        int slotEntry = work->lineSlot[i].entryIndex;
        if (slotEntry > log->scrollIndex || slotEntry <= log->scrollIndex - 3)
            return &work->lineSlot[i];
    }
    UNION_SUBDISP_ASSERT_FAIL(0x5AB, str_ja_021F1038);
    return 0;
}

/* Starts the highlight timer of a chat log entry. */
int UNION_SUBDISP_StartLineHighlight(UnionSubdispWork *work, UnionChatLog *log, int entryIndex)
{
    UnionSubdispLineSlot *slot;
    slot = UNION_SUBDISP_FindHighlightSlot(work, log, entryIndex);
    if (!slot)
        return 0;
    slot->timer = UNION_SUBDISP_HIGHLIGHT_FRAMES;
    slot->entryIndex = entryIndex;
    return 1;
}

/* Counts the highlight timers down; a line whose timer ends gets its normal colour back. */
void UNION_SUBDISP_UpdateLineHighlights(UnionSubdispWork *work, UnionChatLog *log)
{
    int i;
    int lineNo;
    int scrollPos;

    for (i = 0; i < 3; i++) {
        if (work->lineSlot[i].timer != 0) {
            work->lineSlot[i].timer--;
            if (work->lineSlot[i].timer == 0) {
                scrollPos = log->scrollIndex;
                if (scrollPos < 3)
                    lineNo = work->lineSlot[i].entryIndex;
                else
                    lineNo = work->lineSlot[i].entryIndex + 2 - scrollPos;
                if (lineNo >= 0 && lineNo < 3)
                    UNION_SUBDISP_SetLinePalette(work, lineNo, 0);
            }
        }
    }
}

/* Ends the highlight of every entry except entryIndex at the next frame. */
void UNION_SUBDISP_CancelOtherHighlights(UnionSubdispWork *work, UnionChatLog *unused, int entryIndex)
{
    int i;

    for (i = 0; i < 3; i++)
        if (work->lineSlot[i].timer != 0 && entryIndex != work->lineSlot[i].entryIndex)
            work->lineSlot[i].timer = 1;
}

/*
 * Sets the palette of the screen rows of a line: the line colour of its
 * entry (two palettes per colour) plus one when it is highlighted.
 */
int UNION_SUBDISP_SetLinePalette(UnionSubdispWork *unused, int lineNo, int highlighted)
{
    u16 *screen;
    int palette;

    screen = (u16 *)BG_SYS_GetBuf(UNION_SUBDISP_BG_CHAT);
    switch ((u16)(screen[lineNo * UNION_SUBDISP_LINE_COPY_STRIDE] >> 12)) {
    case 0:
    case 1:
        if (highlighted == 0)
            palette = 0;
        else
            palette = 1;
        break;
    case 2:
    case 3:
        if (highlighted == 0)
            palette = 2;
        else
            palette = 3;
        break;
    default:
        return 0;
    }
    BG_SYS_FillTileMap(UNION_SUBDISP_BG_CHAT, 0, lineNo * UNION_SUBDISP_ROWS_PER_LINE, 0x20, UNION_SUBDISP_ROWS_PER_LINE, palette);
    BG_SYS_MarkTileDirty(UNION_SUBDISP_BG_CHAT);
    return 1;
}

/* The L and R buttons scroll the chat log by a page of three lines. */
void UNION_SUBDISP_PageScrollByButtons(UnionSubdispWork *unused, UnionRoomWork *room)
{
    int minScroll;
    int newest;
    int scroll;

    if (!room)
        return;
    newest = room->chatLog.newestIndex;
    if (newest < 3)
        return;
    scroll = room->chatLog.scrollIndex;
    minScroll = newest - 0x1D;
    if (minScroll < 2)
        minScroll = 2;
    if (KEY_GetRepeat() & 0x200) {
        scroll -= 3;
        if (scroll < minScroll)
            scroll = minScroll;
    } else if (KEY_GetRepeat() & 0x100) {
        scroll += 3;
        if (scroll > newest)
            scroll = newest;
    }
    room->chatLog.scrollIndex = scroll;
}
