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
 *   ICA_ANIME_GetField24  0x02012138  thumb
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   PMS_DRAW_Create  0x0202DB0C  thumb
 *   PMS_DRAW_SetNullColorPalette  0x0202DE5C  thumb
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   UNION_MAIN_GetAppealNo  0x02173940  thumb  ov012
 *   UNION_SUBDISP_DrawVisibleChatLines  0x021F09A0  thumb  ov031
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   GFL_NET_WM_ICON_EasyObjWindowOn  0x02037174  arm
 *   sUnionSubdispFileName   0x021F10C0  data  ov031  a1
 *   sUnionSubdispAppealNo     0x021F1038  data  ov031  a1
 *   PMS_DRAW_Delete  0x0202DC08  thumb
 *   func_020307B0  0x020307B0  arm
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
 *   func_02045B38 0x02045B38 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   BG_SYS_GetBuf  0x0204162C  arm
 *   func_02049EF4  0x02049EF4  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02040588  0x02040588  arm
 *   sUnionSubdispBgTemplate5     0x021F1050  data  ov031  a4
 *   sUnionSubdispBgTemplate6     0x021F1070  data  ov031  a4
 *   sUnionSubdispBgTemplate7     0x021F1090  data  ov031  a4
 *   func_020403F4 0x020403F4 arm
 *   BG_SYS_CreateRun  0x0203FA08  arm
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
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
 *   func_02034714  0x02034714  arm
 *   sUnionSubdispEmptyStr     0x021F10D0  data  a4
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   PMS_DRAW_IsActive  0x0202DCC4  thumb
 *   PMS_DRAW_Clear  0x0202DC9C  thumb
 *   BMP_Clear  0x02043B5C  arm
 *   PMS_DRAW_PrintOffset  0x0202DC60  thumb
 *   func_02045EC0  0x02045EC0  arm
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
 *   func_0209C2B0 0x0209C2B0 arm
 *   KEY_GetRepeat  0x0203633C  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;
typedef struct VecFx32 {
    s32 x, y, z;
} VecFx32;

#include "../ov012/union_comm_types.h"
#include "union_subdisp_types.h"

#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_WINOUT_SUB     (*(volatile u16 *)0x0400104A)
#define REG_DB_BLDCNT_SUB  (*(volatile u16 *)0x04001050)

#define UNION_SUBDISP_VRAM_SUB_BG ((void *)0x06200000)

struct BgTemplate;

extern struct GameComm *ICA_ANIME_GetField24(const struct GameSystem *gameSystem);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern void *func_020490F4(u32 id, u32 heapId);
extern void ARC_TOOL_DeleteHandle(void *archive);
extern struct PmsDraw *PMS_DRAW_Create(struct ClactUnit *unit, u32 b, struct PrintSys *printSys, struct GfFont *font, u8 e0, u8 e1, u16 heapId);
extern void PMS_DRAW_SetNullColorPalette(struct PmsDraw *pmsDraw, u8 v);
extern UnionRoomWork *GAME_COMM_GetWork(struct GameComm *gameComm);
extern u8 UNION_MAIN_GetAppealNo(UnionRoomWork *work);
extern void CLACT_SetActorPaletteOffset(struct ClactActor *actor, u32 v, u32 flag);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void GFL_NET_WM_ICON_EasyObjWindowOn(void);
extern void PMS_DRAW_Delete(struct PmsDraw *pmsDraw);
extern u32 func_020307B0(void *p);
extern void GFL_NET_WM_ICON_EasyObjWindowOff(void);
extern void G2x_SetBlendBrightness_(volatile u16 *reg, int plane, int brightness);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *printSys);
extern void PMS_DRAW_Main(struct PmsDraw *pmsDraw);
extern void *BMP_WIN_GetBmp(struct BmpWin *win);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *printSys, void *bmp);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern u32 GAME_COMM_GetKind(struct GameComm *gameComm);
extern void UNION_CHAT_LOG_Add(UnionRoomWork *work, void *src, UnionPmsData *pms, u8 kind);
extern void CLACT_SetActorDrawEnable(struct ClactActor *actor, unsigned int visible);
extern void UNION_COMM_SetChatType(UnionRoomWork *work, int chatType);
extern void UNION_MAIN_SetAppealNo(UnionRoomWork *work, int appealNo);
extern struct ClactUnit *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern struct PrintSys *PRINTSYS_QUE_Create(u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern unsigned int MSGDATA_Delete(struct MsgBank *msgData);
extern u32 GF_FONT_Delete(struct GfFont *font);
extern void PRINTSYS_QUE_Clear(struct PrintSys *printSys);
extern void PRINTSYS_QUE_Delete(struct PrintSys *printSys);
extern u32 CLACT_DeleteUnit(struct ClactUnit *unit);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern u32 func_02049658(void *archive, u32 b, u32 c, u32 d, u32 e, u32 f, u16 heapId);
extern void func_020498F4(void *archive, u32 b, u32 c, u32 d, u32 e, u32 f, u16 heapId);
extern u32 BG_SYS_GetBuf(int channel);
extern void *func_02049EF4(void *archive, u32 a, u32 b, void **out, u16 heapId);
extern void MI_CpuCopy8(void *src, void *dst, int n);
extern void func_02049B68(void *archive, u32 b, u32 c, u32 d, u32 e, u16 heapId);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 heapId);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(unsigned int);
extern u32 BG_SYS_CreateRun(u32 a, u32 b, u32 c);
extern void BG_SYS_DeleteHalf(u32, u32, u32);
extern struct BmpWin *BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 BMP_WIN_Delete(struct BmpWin *win);
extern struct ClactRes *CLACT_RegisterPaletteEx(void *archive, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern struct ClactRes *CLACT_RegisterCharacter(void *archive, u32 b, u32 c, u32 a3, u16 flags);
extern struct ClactRes *CLACT_RegisterCellAnim(void *archive, u32 first, u32 second, u32 mode);
extern void CLACT_ReleasePalette(struct ClactRes *);
extern void CLACT_ReleaseCharacter(struct ClactRes *);
extern void CLACT_ReleaseCellAnim(struct ClactRes *);
extern struct ClactActor *CLACT_CreateActor(struct ClactUnit *, struct ClactRes *, struct ClactRes *, struct ClactRes *, const UnionSubdispActorParam *, unsigned short, unsigned short);
extern void CLACT_DeleteActor(struct ClactActor *actor);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern void CLACT_GetActorSurfacePos(struct ClactActor *actor, UnionSubdispPos *out, u16 space);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
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
extern const UnionSubdispActorParam sUnionSubdispButtonActorParam;

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

extern u32 PMS_DRAW_IsPrintEnd(struct PmsDraw *pmsDraw);
extern UnionChatEntry *UNION_CHAT_LOG_GetLine(UnionChatLog *log, u32 index);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 bit);
extern u32 PMS_DRAW_IsActive(const struct PmsDraw *pmsDraw, u32 id);
extern void PMS_DRAW_Clear(struct PmsDraw *pmsDraw, int id, u32 isTrans);
extern void BMP_Clear(void *bmp, u8 value);
extern void PMS_DRAW_PrintOffset(struct PmsDraw *pmsDraw, struct BmpWin *win, void *pms, u32 id, const void *offset);
extern struct Strbuf *func_02045EC0(struct MsgBank *msgData, u32 index);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);
extern void PRINTSYS_PrintQueColor(struct PrintSys *printSys, void *bmp, s16 x, s16 y, struct Strbuf *str, struct GfFont *font, u16 color);
extern void STRBUF_Delete(struct Strbuf *str);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_SetString(struct Strbuf *str, const u16 *src);
extern void PMS_DRAW_Copy(struct PmsDraw *pmsDraw, u32 srcId, u32 dstId);
extern void BMP_CopyPixels(const void *src, void *dst);
extern u32 TOUCHPANEL_GetPointCont(u32 *outX, u32 *outY);
extern int TOUCHPANEL_GetTrg(void);
extern void CLACT_AddActorSurfacePos(struct ClactActor *actor, const UnionSubdispPos *pos, u32 which);
extern u32 func_0209C2B0(u32 a, u32 b);

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

/* Both arguments of the assertion failure call are the empty string of the build. */
#define UNION_SUBDISP_ASSERT_FAIL() func_02034714(sUnionSubdispEmptyStr, 0, sUnionSubdispEmptyStr)

/*
 * The 0/1 flag the loop tests (movs r0,#1 / movs r0,#0 / cmp r0,#0) is a
 * `!field` returned from an inline helper: the same test written in place,
 * as a ternary, an if/else local, or a helper returning `== 0` or a ternary,
 * all fold into a direct bne.
 */
static inline int UNION_SUBDISP_PollLineTransfer(UnionSubdispWork *work, int lineNo)
{
    struct PrintSys *printSys = work->printSys;
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

    gameComm = ICA_ANIME_GetField24(gameSystem);
    work = func_02030734(UNION_SUBDISP_HEAP_ID, 0x80, 1, sUnionSubdispFileName, 0x10F);
    work->gameSystem = gameSystem;
    archive = func_020490F4(0x59, UNION_SUBDISP_HEAP_ID);
    UNION_SUBDISP_CreateSystems(work);
    UNION_SUBDISP_InitBgs(work, archive);
    UNION_SUBDISP_CreateLineWindows(work);
    UNION_SUBDISP_LoadActorRes(work, archive);
    UNION_SUBDISP_CreateActors(work, archive);
    UNION_SUBDISP_LoadFrameBg(work);
    ARC_TOOL_DeleteHandle(archive);
    work->pmsDraw = PMS_DRAW_Create(work->clactUnit, 1, work->printSys, work->font, 9, 3, UNION_SUBDISP_HEAP_ID);
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
                if (sUnionSubdispAppealNo[i] == *((u8 *)work + 0x30)) {
                    CLACT_SetActorPaletteOffset(work->actor[i], 1, 1);
                    break;
                }
            }
        }
    }
    GFL_NET_RestartWithDefaultTimeout(0, UNION_SUBDISP_HEAP_ID);
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

    unionWork = GAME_COMM_GetWork(ICA_ANIME_GetField24(work->gameSystem));
    if (unionWork != 0)
        unionWork->talkCancel = 0;
    PMS_DRAW_Delete(work->pmsDraw);
    UNION_SUBDISP_FreeFrameBgChar(work);
    UNION_SUBDISP_DeleteActors(work);
    UNION_SUBDISP_DeleteActorRes(work);
    UNION_SUBDISP_DeleteLineWindows(work);
    UNION_SUBDISP_ExitBgs(work);
    UNION_SUBDISP_DeleteSystems(work);
    func_020307B0(work);
    REG_DB_BLDCNT_SUB = 0;
    GFL_NET_WM_ICON_EasyObjWindowOff();
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
}



void UNION_SUBDISP_Draw(UnionSubdispWork *work, int mode)
{
    int i;

    GAME_COMM_GetWork(ICA_ANIME_GetField24(work->gameSystem));
    GFL_NET_WM_ICON_EasyObjWindowOn();
    if (mode == 1)
        REG_DB_BLDCNT_SUB = 0;
    else
        G2x_SetBlendBrightness_(&REG_DB_BLDCNT_SUB, 0x3F, -8);
    PRINTSYS_QUE_Main(work->printSys);
    PMS_DRAW_Main(work->pmsDraw);
    for (i = 0; i < UNION_SUBDISP_LINE_COUNT; i++) {
        if (work->lineKind[i] == UNION_SUBDISP_LINE_TEXT) {
            /* the local keeps the print system load ahead of the transfer test */
            struct PrintSys *printSys = work->printSys;
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

    gameComm = ICA_ANIME_GetField24(work->gameSystem);
    unionWork = GAME_COMM_GetWork(gameComm);
    if (unionWork != 0) {
        mySituation = &unionWork->mySituation;
        if (mySituation->chatUpdated == 1) {
            UNION_CHAT_LOG_Add(unionWork, 0, &mySituation->chatPms, mySituation->chatType);
            mySituation->chatUpdated = 0;
        }
        UNION_SUBDISP_UpdateChatLines(work, &unionWork->chatLog);
        if (unionWork->chatLog.newestIndex >= 3)
            CLACT_SetActorDrawEnable(work->actor[UNION_SUBDISP_ACTOR_SCROLL_KNOB], 1);
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
    work->printSys = PRINTSYS_QUE_Create(UNION_SUBDISP_HEAP_ID);
    work->font = GF_FONT_Create(23, 0, 0, 0, UNION_SUBDISP_HEAP_ID);
    work->msgData = func_02045B38(0, 2, 201, UNION_SUBDISP_HEAP_ID);
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
    func_02082A7C(0, UNION_SUBDISP_VRAM_SUB_BG, 0x20000);
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
    REG_DB_BLDCNT_SUB = 0;
    func_02049658(archive, 0xF, 7, 0, 0, 0, UNION_SUBDISP_HEAP_ID);
    func_020498F4(archive, 0x11, 7, 0, 0x800, 0, UNION_SUBDISP_HEAP_ID);
    palette = (u16 *)BG_SYS_GetBuf(6);
    palFile = func_02049EF4(archive, 0x12, 0, (void **)&palData, UNION_SUBDISP_HEAP_ID);
    MI_CpuCopy8(palData + 0xC, palette, 0x1C0);
    func_020307B0(palFile);
    func_02049B68(archive, 0x10, 4, 0, 0xA0, UNION_SUBDISP_HEAP_ID);
    func_02049B40(0x17, 5, 4, 0x1E0, 0x20, UNION_SUBDISP_HEAP_ID);
    func_02040588(4, 0);
    func_02040588(7, 1);
    func_02040588(6, 1);
    func_02040588(5, 1);
}


void UNION_SUBDISP_ExitBgs(UnionSubdispWork *work)
{
    func_02040588(5, 0);
    func_02040588(6, 0);
    func_02040588(7, 0);
    func_020403F4(5);
    func_020403F4(6);
    func_020403F4(7);
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

    archive = func_020490F4(0x53, UNION_SUBDISP_HEAP_ID);
    charOffset = BG_SYS_CreateRun(5, 0x80, 1);
    work->bgCharOffset = charOffset;
    func_02049658(archive, 0x1C, 5, charOffset, 0x80, 0, UNION_SUBDISP_HEAP_ID);
    screen = (u16 *)BG_SYS_GetBuf(5);
    screenFile = func_02049EF4(archive, 0x1D, 0, (void **)&screenData, UNION_SUBDISP_HEAP_ID);
    MI_CpuCopy8((u16 *)(screenData + 0xC) + 0x2A0, screen + 0x2A0, 0xC0);
    func_020307B0(screenFile);
    for (i = 0; i < 0x60; i++)
        screen[0x2A0 + i] = (screen[0x2A0 + i] & 0xFFF) + charOffset + 0xD000;
    func_02049B68(archive, 0x1B, 4, 0x1A0, 0x20, UNION_SUBDISP_HEAP_ID);
    ARC_TOOL_DeleteHandle(archive);
}


void UNION_SUBDISP_FreeFrameBgChar(UnionSubdispWork *work)
{
    BG_SYS_DeleteHalf(5, work->bgCharOffset, 128);
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
    CLACT_ReleasePalette(work->palRes);
    CLACT_ReleaseCharacter(work->charRes);
    CLACT_ReleaseCellAnim(work->cellRes);
}



void UNION_SUBDISP_CreateActors(UnionSubdispWork *work, void *archive)
{
    UnionSubdispActorParam param;
    int i;

    param = sUnionSubdispButtonActorParam;
    for (i = 0; i <= 4; i++) {
        param.x = i * 0x30 + 0x20;
        param.anim = i;
        work->actor[i] = CLACT_CreateActor(work->clactUnit, work->charRes, work->palRes, work->cellRes, &param, 1, UNION_SUBDISP_HEAP_ID);
    }
    param.anim = 5;
    param.x = 0xF4;
    param.y = 0x9C;
    work->actor[UNION_SUBDISP_ACTOR_SCROLL_KNOB] = CLACT_CreateActor(work->clactUnit, work->charRes, work->palRes, work->cellRes, &param, 1, UNION_SUBDISP_HEAP_ID);
    CLACT_SetActorDrawEnable(work->actor[UNION_SUBDISP_ACTOR_SCROLL_KNOB], 0);
}


void UNION_SUBDISP_DeleteActors(UnionSubdispWork *work)
{
    int i;

    for (i = 0; i < UNION_SUBDISP_ACTOR_COUNT; i++)
        CLACT_DeleteActor(work->actor[i]);
}



int UNION_SUBDISP_CheckTouch(UnionSubdispWork *work, UnionRoomWork *unionWork)
{
    u32 touchX;
    u32 touchY;
    UnionSubdispPos pos;
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
            CLACT_SetActorPaletteOffset(work->actor[i], 1, 1);
        else
            CLACT_SetActorPaletteOffset(work->actor[i], 0, 1);
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
                entry = UNION_CHAT_LOG_GetLine(log, i);
                if (entry == 0)
                    UNION_SUBDISP_ASSERT_FAIL();
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
    struct PrintSys *printSys;
    int offset;

    screen = (u16 *)BG_SYS_GetBuf(UNION_SUBDISP_BG_CHAT);
    offset = (lineNo * UNION_SUBDISP_LINE_COPY_STRIDE) << 1;
    palette = UNION_SUBDISP_GetLinePalette(entry);
    MI_CpuCopy8(screen, (u8 *)screen + offset, UNION_SUBDISP_LINE_COPY_SIZE);
    func_020413B0(UNION_SUBDISP_BG_CHAT, 0, lineNo * UNION_SUBDISP_ROWS_PER_LINE, 0x20, UNION_SUBDISP_ROWS_PER_LINE, palette);
    func_02041B6C(UNION_SUBDISP_BG_CHAT);
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
            text = func_02045EC0(work->msgData, UNION_SUBDISP_MSG_TYPE1);
            break;
        case 2:
            text = func_02045EC0(work->msgData, UNION_SUBDISP_MSG_TYPE2);
            break;
        case 3:
            text = func_02045EC0(work->msgData, UNION_SUBDISP_MSG_TYPE3);
            break;
        case 4:
            text = func_02045EC0(work->msgData, UNION_SUBDISP_MSG_TYPE4);
            break;
        case 5:
            text = func_02045EC0(work->msgData, UNION_SUBDISP_MSG_TYPE5);
            break;
        case 0:
            return;
        default:
            return;
        }
        BMP_WIN_MakeScreen(work->lineWin[lineNo]);
        func_02041B6C(BMP_WIN_GetBgLayer(work->lineWin[lineNo]));
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
        name = func_02045EC0(work->msgData, (entry->relation == 1) ? UNION_SUBDISP_MSG_FRIEND : UNION_SUBDISP_MSG_KNOWN);
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
        entry = UNION_CHAT_LOG_GetLine(log, i);
        if (entry == 0)
            UNION_SUBDISP_ASSERT_FAIL();
        if (lineNo <= -1)
            UNION_SUBDISP_ASSERT_FAIL();
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
    dst = (u16 *)((u32)screen + destOffset);
    src = (u16 *)((u32)screen + sourceOffset);
    MI_CpuCopy8(src, dst, UNION_SUBDISP_LINE_COPY_SIZE);
    func_02041B6C(UNION_SUBDISP_BG_CHAT);
    if (work->lineKind[srcLine] == UNION_SUBDISP_LINE_PMS && work->lineKind[dstLine] == UNION_SUBDISP_LINE_PMS) {
        PMS_DRAW_Copy(work->pmsDraw, srcLine, dstLine);
        return;
    }
    if (work->lineKind[srcLine] == UNION_SUBDISP_LINE_TEXT && work->lineKind[dstLine] == UNION_SUBDISP_LINE_TEXT) {
        BMP_CopyPixels(BMP_WIN_GetBmp(work->lineWin[srcLine]), BMP_WIN_GetBmp(work->lineWin[dstLine]));
        BMP_WIN_TransferChars(work->lineWin[dstLine]);
        return;
    }
    UNION_SUBDISP_DrawChatLine(work, UNION_CHAT_LOG_GetLine(log, oldBottomIndex - 2 + srcLine), dstLine);
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
            entry = UNION_CHAT_LOG_GetLine(log, log->scrollIndex - 2 + dstLine);
            if (entry == 0)
                UNION_SUBDISP_ASSERT_FAIL();
            UNION_SUBDISP_DrawChatLine(work, entry, (u8)dstLine);
        }
    } else {
        for (i = delta + 2, dstLine = 2; i > -1; i--) {
            UNION_SUBDISP_MoveChatLine(work, i, dstLine, log, log->scrollIndex - delta);
            dstLine--;
        }
        for (dstLine = -1 - delta; dstLine > -1; dstLine--) {
            entry = UNION_CHAT_LOG_GetLine(log, log->scrollIndex - 2 + dstLine);
            if (entry == 0)
                UNION_SUBDISP_ASSERT_FAIL();
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
    UnionSubdispPos pos;
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
    UnionSubdispPos pos;
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
    UnionSubdispPos pos;
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
    return func_0209C2B0(0x8000, range);
}

/* A new touch on the scroll bar moves the knob there. Returns 1 when it did. */
int UNION_SUBDISP_CheckTrackTouch(UnionSubdispWork *work)
{
    UnionSubdispPos pos;
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
        entry = UNION_CHAT_LOG_GetLine(log, lineNo);
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
    UNION_SUBDISP_ASSERT_FAIL();
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
    func_020413B0(UNION_SUBDISP_BG_CHAT, 0, lineNo * UNION_SUBDISP_ROWS_PER_LINE, 0x20, UNION_SUBDISP_ROWS_PER_LINE, palette);
    func_02041B6C(UNION_SUBDISP_BG_CHAT);
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
