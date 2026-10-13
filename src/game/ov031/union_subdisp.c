/*
 * file:     union_subdisp.c
 * unit:     yes
 * function: func_021EFEC0, func_021EFFE8, func_021F0054, func_021F00D4, func_021F01F0, func_021F022C, func_021F0250, func_021F0348, func_021F0378, func_021F0420, func_021F0430, func_021F0478, func_021F0490, func_021F04D4, func_021F04EC, func_021F056C, func_021F0584, func_021F0628, func_021F0680, func_021F07AC, func_021F09A0, func_021F0A04, func_021F0AA0, func_021F0B98, func_021F0C34, func_021F0C60, func_021F0CEC, func_021F0D40, func_021F0D58, func_021F0D64, func_021F0DB0, func_021F0E64, func_021F0ED8, func_021F0EF4, func_021F0F40, func_021F0F68, func_021F0FE0
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
 *   func_02012138  0x02012138  thumb
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
 *   PMS_DRAW_Create  0x0202DB0C  thumb
 *   PMS_DRAW_SetNullColorPalette  0x0202DE5C  thumb
 *   func_02026474  0x02026474  thumb
 *   UNION_MAIN_GetAppealNo  0x02173940  thumb  ov012
 *   func_021F09A0  0x021F09A0  thumb  ov031
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_02037174  0x02037174  arm
 *   str_021F10C0   0x021F10C0  data  ov031  a1
 *   d_021F1038     0x021F1038  data  ov031  a1
 *   PMS_DRAW_Delete  0x0202DC08  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02037190  0x02037190  arm
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   func_0201C4E4  0x0201C4E4  thumb
 *   PMS_DRAW_Main  0x0202DBC4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02026454  0x02026454  thumb
 *   func_021BBA70  0x021BBA70  thumb  ov021
 *   func_021F0680  0x021F0680  thumb  ov031
 *   func_0204B3DC  0x0204B3DC  arm
 *   UNION_COMM_SetChatType  0x021736C8  thumb  ov012
 *   func_021F0B98  0x021F0B98  thumb  ov031
 *   func_021F0D64  0x021F0D64  thumb  ov031
 *   func_021F0FE0  0x021F0FE0  thumb  ov031
 *   func_021F0C34  0x021F0C34  thumb  ov031
 *   func_021F0DB0  0x021F0DB0  thumb  ov031
 *   func_021F0EF4  0x021F0EF4  thumb  ov031
 *   UNION_MAIN_SetAppealNo  0x02173934  thumb  ov012
 *   func_0204B100 0x0204B100 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_0204162C  0x0204162C  arm
 *   func_02049EF4  0x02049EF4  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02040588  0x02040588  arm
 *   d_021F1050     0x021F1050  data  ov031  a4
 *   d_021F1070     0x021F1070  data  ov031  a4
 *   d_021F1090     0x021F1090  data  ov031  a4
 *   func_020403F4 0x020403F4 arm
 *   func_0203FA08  0x0203FA08  arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020450F0  0x020450F0  arm
 *   func_020452E8 0x020452E8 arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B294  0x0204B294  arm
 *   d_021F1048     0x021F1048  data  a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02035D20  0x02035D20  arm
 *   func_0204B454  0x0204B454  arm
 *   func_020061E4  0x020061E4  thumb
 *   PMS_DRAW_IsPrintEnd  0x0202DC98  thumb
 *   func_021BBC2C  0x021BBC2C  thumb  ov021
 *   func_02034714  0x02034714  arm
 *   d_021F10D0     0x021F10D0  data  a4
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   PMS_DRAW_IsActive  0x0202DCC4  thumb
 *   PMS_DRAW_Clear  0x0202DC9C  thumb
 *   func_02043B5C  0x02043B5C  arm
 *   PMS_DRAW_PrintOffset  0x0202DC60  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045924  0x02045924  arm
 *   d_021F1040     0x021F1040  data  ov031  a4
 *   PMS_DRAW_Copy  0x0202DD24  thumb
 *   func_02043814  0x02043814  arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   func_02035C60  0x02035C60  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0209C2B0 0x0209C2B0 arm
 *   func_0203633C  0x0203633C  arm
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

extern struct GameComm *func_02012138(const struct GameSystem *gameSystem);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern void *func_020490F4(u32 id, u32 heapId);
extern void func_02049238(void *archive);
extern struct PmsDraw *PMS_DRAW_Create(struct ClactUnit *unit, u32 b, struct PrintSys *printSys, struct GfFont *font, u8 e0, u8 e1, u16 heapId);
extern void PMS_DRAW_SetNullColorPalette(struct PmsDraw *pmsDraw, u8 v);
extern UnionRoomWork *func_02026474(struct GameComm *gameComm);
extern u8 UNION_MAIN_GetAppealNo(UnionRoomWork *work);
extern void func_0204B6F4(struct ClactActor *actor, u32 v, u32 flag);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02037174(void);
extern void PMS_DRAW_Delete(struct PmsDraw *pmsDraw);
extern u32 func_020307B0(void *p);
extern void func_02037190(void);
extern void G2x_SetBlendBrightness_(volatile u16 *reg, int plane, int brightness);
extern u32 func_0201C4E4(struct PrintSys *printSys);
extern void PMS_DRAW_Main(struct PmsDraw *pmsDraw);
extern void *func_02045770(struct BmpWin *win);
extern u32 func_0201C6C4(struct PrintSys *printSys, void *bmp);
extern void func_02045334(struct BmpWin *win);
extern u32 func_02026454(struct GameComm *gameComm);
extern void func_021BBA70(UnionRoomWork *work, void *src, UnionPmsData *pms, u8 kind);
extern void func_0204B3DC(struct ClactActor *actor, unsigned int visible);
extern void UNION_COMM_SetChatType(UnionRoomWork *work, int chatType);
extern void UNION_MAIN_SetAppealNo(UnionRoomWork *work, int appealNo);
extern struct ClactUnit *func_0204B100(int count, u8 flag, u32 heapId);
extern struct PrintSys *func_0201C440(u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern unsigned int func_02045C04(struct MsgBank *msgData);
extern u32 func_0201D83C(struct GfFont *font);
extern void func_0201C6EC(struct PrintSys *printSys);
extern void func_0201C4C0(struct PrintSys *printSys);
extern u32 func_0204B1CC(struct ClactUnit *unit);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern u32 func_02049658(void *archive, u32 b, u32 c, u32 d, u32 e, u32 f, u16 heapId);
extern void func_020498F4(void *archive, u32 b, u32 c, u32 d, u32 e, u32 f, u16 heapId);
extern u32 func_0204162C(int channel);
extern void *func_02049EF4(void *archive, u32 a, u32 b, void **out, u16 heapId);
extern void func_02082D44(void *src, void *dst, int n);
extern void func_02049B68(void *archive, u32 b, u32 c, u32 d, u32 e, u16 heapId);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 heapId);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(unsigned int);
extern u32 func_0203FA08(u32 a, u32 b, u32 c);
extern void func_0203FB44(u32, u32, u32);
extern struct BmpWin *func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 func_020452E8(struct BmpWin *win);
extern struct ClactRes *func_0204AC18(void *archive, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern struct ClactRes *func_0204A6C8(void *archive, u32 b, u32 c, u32 a3, u16 flags);
extern struct ClactRes *func_0204AF28(void *archive, u32 first, u32 second, u32 mode);
extern void func_0204ADA4(struct ClactRes *);
extern void func_0204A8D4(struct ClactRes *);
extern void func_0204AFD8(struct ClactRes *);
extern struct ClactActor *func_0204B294(struct ClactUnit *, struct ClactRes *, struct ClactRes *, struct ClactRes *, const UnionSubdispActorParam *, unsigned short, unsigned short);
extern void func_0204B3B4(struct ClactActor *actor);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_0204B454(struct ClactActor *actor, UnionSubdispPos *out, u16 space);
extern void func_020061E4(u32 se);
UnionSubdispWork *func_021EFEC0(struct GameSystem *gameSystem);
void func_021EFFE8(UnionSubdispWork *work);
void func_021F0054(UnionSubdispWork *work, int mode);
void func_021F00D4(UnionSubdispWork *work, int mode);
void func_021F01F0(UnionSubdispWork *work);
void func_021F022C(UnionSubdispWork *work);
void func_021F0250(UnionSubdispWork *work, void *archive);
void func_021F0348(UnionSubdispWork *work);
void func_021F0378(UnionSubdispWork *work);
void func_021F0420(UnionSubdispWork *work);
void func_021F0430(UnionSubdispWork *work);
void func_021F0478(UnionSubdispWork *work);
void func_021F0490(UnionSubdispWork *work, void *archive);
void func_021F04D4(UnionSubdispWork *work);
void func_021F04EC(UnionSubdispWork *work, void *archive);
void func_021F056C(UnionSubdispWork *work);
int func_021F0584(UnionSubdispWork *work, UnionRoomWork *unionWork);
void func_021F0628(UnionSubdispWork *work, int sel);
extern char str_021F10C0[];
extern u8 d_021F1038[];
extern const u8 d_021F1050[];
extern const u8 d_021F1070[];
extern const u8 d_021F1090[];
extern const UnionSubdispActorParam d_021F1048;

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
extern UnionChatEntry *func_021BBC2C(UnionChatLog *log, u32 index);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 bit);
extern u32 PMS_DRAW_IsActive(const struct PmsDraw *pmsDraw, u32 id);
extern void PMS_DRAW_Clear(struct PmsDraw *pmsDraw, int id, u32 isTrans);
extern void func_02043B5C(void *bmp, u8 value);
extern void PMS_DRAW_PrintOffset(struct PmsDraw *pmsDraw, struct BmpWin *win, void *pms, u32 id, const void *offset);
extern struct Strbuf *func_02045EC0(struct MsgBank *msgData, u32 index);
extern void func_02045374(struct BmpWin *win);
extern u8 func_02045730(struct BmpWin *win);
extern void func_0201C724(struct PrintSys *printSys, void *bmp, s16 x, s16 y, struct Strbuf *str, struct GfFont *font, u16 color);
extern void func_02045808(struct Strbuf *str);
extern struct Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045924(struct Strbuf *str, const u16 *src);
extern void PMS_DRAW_Copy(struct PmsDraw *pmsDraw, u32 srcId, u32 dstId);
extern void func_02043814(const void *src, void *dst);
extern u32 TOUCHPANEL_GetPointCont(u32 *outX, u32 *outY);
extern int func_02035C60(void);
extern void func_0204B404(struct ClactActor *actor, const UnionSubdispPos *pos, u32 which);
extern u32 func_0209C2B0(u32 a, u32 b);

void func_021F0680(UnionSubdispWork *work, UnionChatLog *log);
void func_021F07AC(UnionSubdispWork *work, const UnionChatEntry *entry, u8 lineNo);
void func_021F09A0(UnionSubdispWork *work, UnionChatLog *log);
void func_021F0A04(UnionSubdispWork *work, u8 srcLine, u8 dstLine, UnionChatLog *log, int oldBottomIndex);
void func_021F0AA0(UnionSubdispWork *work, UnionChatLog *log, int delta);
int func_021F0B98(UnionSubdispWork *work);
void func_021F0C34(UnionRoomWork *room, UnionSubdispWork *work);
void func_021F0C60(UnionSubdispWork *work, UnionChatLog *log);
void func_021F0CEC(UnionSubdispWork *work, UnionChatLog *log);
int func_021F0D40(UnionChatLog *log);
u32 func_021F0D58(void *unused, u32 range);
int func_021F0D64(UnionSubdispWork *work);
int func_021F0DB0(UnionRoomWork *room, UnionSubdispWork *work, UnionChatLog *log);
UnionSubdispLineSlot *func_021F0E64(UnionSubdispWork *work, UnionChatLog *log, int entryIndex);
int func_021F0ED8(UnionSubdispWork *work, UnionChatLog *log, int entryIndex);
void func_021F0EF4(UnionSubdispWork *work, UnionChatLog *log);
void func_021F0F40(UnionSubdispWork *work, UnionChatLog *unused, int entryIndex);
int func_021F0F68(UnionSubdispWork *unused, int lineNo, int highlighted);
extern const char d_021F10D0[];
extern const UnionSubdispTextOffset d_021F1040;

/* Both arguments of the assertion failure call are the empty string of the build. */
#define UNION_SUBDISP_ASSERT_FAIL() func_02034714(d_021F10D0, 0, d_021F10D0)

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
        if (func_0201C6C4(printSys, func_02045770(work->winSlot[lineNo].win)) == 0) {
            func_02045334(work->winSlot[lineNo].win);
            work->winSlot[lineNo].transferPending = 0;
        }
    }
    return !work->winSlot[lineNo].transferPending;
}
void func_021F0FE0(UnionSubdispWork *unused, UnionRoomWork *room);




UnionSubdispWork *func_021EFEC0(struct GameSystem *gameSystem)
{
    struct GameComm *gameComm;
    UnionSubdispWork *work;
    void *archive;
    UnionRoomWork *unionWork;
    u32 i;
    u32 winOut;

    gameComm = func_02012138(gameSystem);
    work = func_02030734(UNION_SUBDISP_HEAP_ID, 0x80, 1, str_021F10C0, 0x10F);
    work->gameSystem = gameSystem;
    archive = func_020490F4(0x59, UNION_SUBDISP_HEAP_ID);
    func_021F01F0(work);
    func_021F0250(work, archive);
    func_021F0430(work);
    func_021F0490(work, archive);
    func_021F04EC(work, archive);
    func_021F0378(work);
    func_02049238(archive);
    work->pmsDraw = PMS_DRAW_Create(work->clactUnit, 1, work->printSys, work->font, 9, 3, UNION_SUBDISP_HEAP_ID);
    PMS_DRAW_SetNullColorPalette(work->pmsDraw, 0);
    unionWork = func_02026474(gameComm);
    if (unionWork != 0) {
        work->appealNo = UNION_MAIN_GetAppealNo(unionWork);
        func_021F09A0(work, &unionWork->chatLog);
        if (work->appealNo != 0) {
            for (i = 0; (i < UNION_SUBDISP_APPEAL_COUNT) ? 1 : 0; i++) {
                /*
                 * stand-in: written as work->appealNo the compiler keeps the
                 * first load in a register across the loop; the original
                 * reloads it each pass. The `? 1 : 0` loop test keeps the
                 * entry branch to the bottom test (a plain `<` is 8 bytes
                 * shorter).
                 */
                if (d_021F1038[i] == *((u8 *)work + 0x30)) {
                    func_0204B6F4(work->actor[i], 1, 1);
                    break;
                }
            }
        }
    }
    func_0203D34C(0, UNION_SUBDISP_HEAP_ID);
    func_02037174();
    REG_WINOUT_SUB = (u16)((REG_WINOUT_SUB & ~0x3F00) | (0x1F << 8));
    winOut = (REG_WINOUT_SUB & ~0x3F) | 0x1F;
    winOut |= 0x20;
    REG_WINOUT_SUB = (u16)winOut;
    REG_DB_DISPCNT_SUB = (REG_DB_DISPCNT_SUB & ~0xE000) | 0x8000;
    return work;
}



void func_021EFFE8(UnionSubdispWork *work)
{
    UnionRoomWork *unionWork;

    unionWork = func_02026474(func_02012138(work->gameSystem));
    if (unionWork != 0)
        unionWork->talkCancel = 0;
    PMS_DRAW_Delete(work->pmsDraw);
    func_021F0420(work);
    func_021F056C(work);
    func_021F04D4(work);
    func_021F0478(work);
    func_021F0348(work);
    func_021F022C(work);
    func_020307B0(work);
    REG_DB_BLDCNT_SUB = 0;
    func_02037190();
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
}



void func_021F0054(UnionSubdispWork *work, int mode)
{
    int i;

    func_02026474(func_02012138(work->gameSystem));
    func_02037174();
    if (mode == 1)
        REG_DB_BLDCNT_SUB = 0;
    else
        G2x_SetBlendBrightness_(&REG_DB_BLDCNT_SUB, 0x3F, -8);
    func_0201C4E4(work->printSys);
    PMS_DRAW_Main(work->pmsDraw);
    for (i = 0; i < UNION_SUBDISP_LINE_COUNT; i++) {
        if (work->lineKind[i] == UNION_SUBDISP_LINE_TEXT) {
            /* the local keeps the print system load ahead of the transfer test */
            struct PrintSys *printSys = work->printSys;
            if (work->winSlot[i].transferPending != 0) {
                if (func_0201C6C4(printSys, func_02045770(work->winSlot[i].win)) == 0) {
                    func_02045334(work->winSlot[i].win);
                    work->winSlot[i].transferPending = 0;
                }
            }
        }
    }
}



void func_021F00D4(UnionSubdispWork *work, int mode)
{
    struct GameComm *gameComm;
    UnionRoomWork *unionWork;
    UnionMySituation *mySituation;
    int touched;

    gameComm = func_02012138(work->gameSystem);
    unionWork = func_02026474(gameComm);
    if (unionWork != 0) {
        mySituation = &unionWork->mySituation;
        if (mySituation->chatUpdated == 1) {
            func_021BBA70(unionWork, 0, &mySituation->chatPms, mySituation->chatType);
            mySituation->chatUpdated = 0;
        }
        func_021F0680(work, &unionWork->chatLog);
        if (unionWork->chatLog.newestIndex >= 3)
            func_0204B3DC(work->actor[UNION_SUBDISP_ACTOR_SCROLL_KNOB], 1);
    }
    if (mode == 1) {
        touched = func_021F0584(work, unionWork);
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
        work->inputResult = func_021F0B98(work);
        if (work->inputResult == 0)
            work->inputResult = func_021F0D64(work);
        if (work->inputResult == 0 && unionWork != 0)
            func_021F0FE0(work, unionWork);
    }
    if (unionWork != 0) {
        func_021F0C34(unionWork, work);
        if (mode == 1)
            func_021F0DB0(unionWork, work, &unionWork->chatLog);
        func_021F0EF4(work, &unionWork->chatLog);
    }
    if (func_02026454(gameComm) == 3 && unionWork != 0)
        UNION_MAIN_SetAppealNo(unionWork, work->appealNo);
}


/*
 * extent: trailing two-byte zero alignment padding.
 */
void func_021F01F0(UnionSubdispWork *work)
{
    work->clactUnit = func_0204B100(12, 5, UNION_SUBDISP_HEAP_ID);
    work->printSys = func_0201C440(UNION_SUBDISP_HEAP_ID);
    work->font = func_0201D7EC(23, 0, 0, 0, UNION_SUBDISP_HEAP_ID);
    work->msgData = func_02045B38(0, 2, 201, UNION_SUBDISP_HEAP_ID);
}


void func_021F022C(UnionSubdispWork *work)
{
    func_02045C04(work->msgData);
    func_0201D83C(work->font);
    func_0201C6EC(work->printSys);
    func_0201C4C0(work->printSys);
    func_0204B1CC(work->clactUnit);
}



/*
 * volatile: 0x021F0288 ldr / 0x021F028E str of 0x04001000 (REG_DB_DISPCNT_SUB read-modify-write); 0x021F0294 strh to 0x04001050 (hardware registers)
 */
void func_021F0250(UnionSubdispWork *work, void *archive)
{
    u16 *palette;
    u8 *palData;
    void *palFile;

    func_0203FCA0(5, (const struct BgTemplate *)d_021F1050, 0);
    func_0203FCA0(6, (const struct BgTemplate *)d_021F1070, 0);
    func_0203FCA0(7, (const struct BgTemplate *)d_021F1090, 0);
    func_02082A7C(0, UNION_SUBDISP_VRAM_SUB_BG, 0x20000);
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
    REG_DB_BLDCNT_SUB = 0;
    func_02049658(archive, 0xF, 7, 0, 0, 0, UNION_SUBDISP_HEAP_ID);
    func_020498F4(archive, 0x11, 7, 0, 0x800, 0, UNION_SUBDISP_HEAP_ID);
    palette = (u16 *)func_0204162C(6);
    palFile = func_02049EF4(archive, 0x12, 0, (void **)&palData, UNION_SUBDISP_HEAP_ID);
    func_02082D44(palData + 0xC, palette, 0x1C0);
    func_020307B0(palFile);
    func_02049B68(archive, 0x10, 4, 0, 0xA0, UNION_SUBDISP_HEAP_ID);
    func_02049B40(0x17, 5, 4, 0x1E0, 0x20, UNION_SUBDISP_HEAP_ID);
    func_02040588(4, 0);
    func_02040588(7, 1);
    func_02040588(6, 1);
    func_02040588(5, 1);
}


void func_021F0348(UnionSubdispWork *work)
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
void func_021F0378(UnionSubdispWork *work)
{
    void *archive;
    u32 charOffset;
    u16 *screen;
    void *screenFile;
    u8 *screenData;
    int i;

    archive = func_020490F4(0x53, UNION_SUBDISP_HEAP_ID);
    charOffset = func_0203FA08(5, 0x80, 1);
    work->bgCharOffset = charOffset;
    func_02049658(archive, 0x1C, 5, charOffset, 0x80, 0, UNION_SUBDISP_HEAP_ID);
    screen = (u16 *)func_0204162C(5);
    screenFile = func_02049EF4(archive, 0x1D, 0, (void **)&screenData, UNION_SUBDISP_HEAP_ID);
    func_02082D44((u16 *)(screenData + 0xC) + 0x2A0, screen + 0x2A0, 0xC0);
    func_020307B0(screenFile);
    for (i = 0; i < 0x60; i++)
        screen[0x2A0 + i] = (screen[0x2A0 + i] & 0xFFF) + charOffset + 0xD000;
    func_02049B68(archive, 0x1B, 4, 0x1A0, 0x20, UNION_SUBDISP_HEAP_ID);
    func_02049238(archive);
}


void func_021F0420(UnionSubdispWork *work)
{
    func_0203FB44(5, work->bgCharOffset, 128);
}



/*
 * Re-reading the just-stored work->lineWin[i] as the source of the second
 * store (instead of a local or a chained assignment) is what makes the
 * compiler form &work->lineWin[i] before the call in a callee-saved register,
 * which in turn leaves room for only the first stack constant (7) to be
 * hoisted.
 */
void func_021F0430(UnionSubdispWork *work)
{
    int i;

    for (i = 0; i < UNION_SUBDISP_LINE_COUNT; i++) {
        work->lineWin[i] = func_020450F0(5, 1, (u8)(i * 0x38 / 8), 0x1D, 7, 0xF, 1);
        work->winSlot[i].win = work->lineWin[i];
        work->winSlot[i].transferPending = 0;
    }
}


void func_021F0478(UnionSubdispWork *work)
{
    int i;
    for (i = 0; i < UNION_SUBDISP_LINE_COUNT; i++) {
        func_020452E8(work->lineWin[i]);
    }
}



void func_021F0490(UnionSubdispWork *work, void *archive)
{
    work->palRes = func_0204AC18(archive, 0x13, 1, 0, 0, 3, UNION_SUBDISP_HEAP_ID);
    work->charRes = func_0204A6C8(archive, 0xE, 0, 1, UNION_SUBDISP_HEAP_ID);
    work->cellRes = func_0204AF28(archive, 0xC, 0xD, UNION_SUBDISP_HEAP_ID);
}


void func_021F04D4(UnionSubdispWork *work)
{
    func_0204ADA4(work->palRes);
    func_0204A8D4(work->charRes);
    func_0204AFD8(work->cellRes);
}



void func_021F04EC(UnionSubdispWork *work, void *archive)
{
    UnionSubdispActorParam param;
    int i;

    param = d_021F1048;
    for (i = 0; i <= 4; i++) {
        param.x = i * 0x30 + 0x20;
        param.anim = i;
        work->actor[i] = func_0204B294(work->clactUnit, work->charRes, work->palRes, work->cellRes, &param, 1, UNION_SUBDISP_HEAP_ID);
    }
    param.anim = 5;
    param.x = 0xF4;
    param.y = 0x9C;
    work->actor[UNION_SUBDISP_ACTOR_SCROLL_KNOB] = func_0204B294(work->clactUnit, work->charRes, work->palRes, work->cellRes, &param, 1, UNION_SUBDISP_HEAP_ID);
    func_0204B3DC(work->actor[UNION_SUBDISP_ACTOR_SCROLL_KNOB], 0);
}


void func_021F056C(UnionSubdispWork *work)
{
    int i;

    for (i = 0; i < UNION_SUBDISP_ACTOR_COUNT; i++)
        func_0204B3B4(work->actor[i]);
}



int func_021F0584(UnionSubdispWork *work, UnionRoomWork *unionWork)
{
    u32 touchX;
    u32 touchY;
    UnionSubdispPos pos;
    int i;
    s16 left;
    s16 right;
    s16 top;
    s16 bottom;

    if (func_02035D20(&touchX, &touchY) == 0)
        return 0;
    for (i = 0; i <= 4; i++) {
        func_0204B454(work->actor[i], &pos, 1);
        top = pos.y - 10;
        bottom = pos.y + 10;
        right = pos.x + 10;
        left = pos.x - 10;
        if (left < touchX && right > touchX && top < touchY && bottom > touchY) {
            if (i == 0 && unionWork != 0) {
                unionWork->talkCancel = 1;
                return 0;
            }
            func_021F0628(work, i);
            func_020061E4(0x54B);
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
void func_021F0628(UnionSubdispWork *work, int sel)
{
    int i;
    int appealNo;

    appealNo = d_021F1038[sel];
    if (appealNo == work->appealNo)
        work->appealNo = 0;
    else
        work->appealNo = appealNo;
    for (i = 0; (i <= 4) ? 1 : 0; i++) {
        if (i == sel && work->appealNo != 0)
            func_0204B6F4(work->actor[i], 1, 1);
        else
            func_0204B6F4(work->actor[i], 0, 1);
    }
}


/* Redraws the lines whose content changed since the last call. */
void func_021F0680(UnionSubdispWork *work, UnionChatLog *log)
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
                entry = func_021BBC2C(log, i);
                if (entry == 0)
                    UNION_SUBDISP_ASSERT_FAIL();
                func_021F07AC(work, entry, i);
            }
        }
    } else {
        delta = log->scrollIndex - log->drawnIndex;
        if (((delta < 0) ? -delta : delta) >= 3 || log->drawnIndex < 2)
            func_021F09A0(work, log);
        else
            func_021F0AA0(work, log, delta);
        scrolled = 1;
    }
    if (scrolled == 1)
        func_020061E4(UNION_SUBDISP_SE_SCROLL);
    log->drawnIndex = log->scrollIndex;
}

static inline int UNION_SUBDISP_GetLinePalette(const UnionChatEntry *entry)
{
    if (entry->sex == 0) return 0;
    return 2;
}

/* Draws one chat log entry into line lineNo: background, text and sender name. */
void func_021F07AC(UnionSubdispWork *work, const UnionChatEntry *entry, u8 lineNo)
{
    u16 *screen;
    int palette;
    UnionSubdispTextOffset textOffset;
    struct Strbuf *text;
    struct Strbuf *name;
    struct PrintSys *printSys;
    int offset;

    screen = (u16 *)func_0204162C(UNION_SUBDISP_BG_CHAT);
    offset = (lineNo * UNION_SUBDISP_LINE_COPY_STRIDE) << 1;
    palette = UNION_SUBDISP_GetLinePalette(entry);
    func_02082D44(screen, (u8 *)screen + offset, UNION_SUBDISP_LINE_COPY_SIZE);
    func_020413B0(UNION_SUBDISP_BG_CHAT, 0, lineNo * UNION_SUBDISP_ROWS_PER_LINE, 0x20, UNION_SUBDISP_ROWS_PER_LINE, palette);
    func_02041B6C(UNION_SUBDISP_BG_CHAT);
    textOffset = d_021F1040;
    if (work->lineKind[lineNo] == UNION_SUBDISP_LINE_PMS) {
        if (PMS_DRAW_IsActive(work->pmsDraw, lineNo) == 1)
            PMS_DRAW_Clear(work->pmsDraw, lineNo, 1);
    } else if (work->lineKind[lineNo] == UNION_SUBDISP_LINE_TEXT) {
        func_02043B5C(func_02045770(work->lineWin[lineNo]), 0);
        func_02045334(work->lineWin[lineNo]);
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
        func_02045374(work->lineWin[lineNo]);
        func_02041B6C(func_02045730(work->lineWin[lineNo]));
        printSys = work->printSys;
        func_0201C724(printSys, func_02045770(work->winSlot[lineNo].win), 0, textOffset.y, text, work->font, UNION_SUBDISP_PRINT_COLOR);
        work->winSlot[lineNo].transferPending = 1;
        func_02045808(text);
        work->lineKind[lineNo] = UNION_SUBDISP_LINE_TEXT;
    }
    name = func_020457B0(UNION_SUBDISP_NAME_CHARS, UNION_SUBDISP_HEAP_ID);
    func_02045924(name, entry->name);
    func_0201C724(work->printSys, func_02045770(work->lineWin[lineNo]), 0, 0, name, work->font, UNION_SUBDISP_PRINT_COLOR);
    func_02045808(name);
    if (entry->relation != 0) {
        name = func_02045EC0(work->msgData, (entry->relation == 1) ? UNION_SUBDISP_MSG_FRIEND : UNION_SUBDISP_MSG_KNOWN);
        func_0201C724(work->printSys, func_02045770(work->lineWin[lineNo]), 0x74, 0, name, work->font, UNION_SUBDISP_PRINT_COLOR);
        func_02045808(name);
    }
}

/* Draws the three lines that end at the scroll position. */
void func_021F09A0(UnionSubdispWork *work, UnionChatLog *log)
{
    int lineNo;
    int i = log->scrollIndex;
    int stop = i - 3;
    UnionChatEntry *entry;

    if (stop < 0)
        stop = -1;
    lineNo = i - stop - 1;
    for (; i > stop; i--, lineNo--) {
        entry = func_021BBC2C(log, i);
        if (entry == 0)
            UNION_SUBDISP_ASSERT_FAIL();
        if (lineNo <= -1)
            UNION_SUBDISP_ASSERT_FAIL();
        func_021F07AC(work, entry, (u8)lineNo);
    }
}

/*
 * Moves the screen rows and the content of line srcLine to line dstLine. A
 * line without a copy source is drawn again from the chat log.
 *
 * lever: enum byte-offset locals, product by 0xE0 then separate <<= 1, recover sequential source/destination scaling and entry copies; integer offsets and enum halfword indexes do not.
 * extent: 154 instruction bytes followed by two zero alignment bytes; the next function is separately matched.
 */
void func_021F0A04(UnionSubdispWork *work, u8 srcLine, u8 dstLine, UnionChatLog *log, int oldBottomIndex)
{
    u16 *screen;
    u16 *dst;
    u16 *src;
    /* stand-in: enum byte offsets are the only form that matches the scaling of the two line offsets */
    RowOffset destOffset;
    RowOffset sourceOffset;

    screen = (u16 *)func_0204162C(UNION_SUBDISP_BG_CHAT);
    destOffset = dstLine * UNION_SUBDISP_LINE_COPY_STRIDE;
    destOffset <<= 1;
    sourceOffset = srcLine * UNION_SUBDISP_LINE_COPY_STRIDE;
    sourceOffset <<= 1;
    dst = (u16 *)((u32)screen + destOffset);
    src = (u16 *)((u32)screen + sourceOffset);
    func_02082D44(src, dst, UNION_SUBDISP_LINE_COPY_SIZE);
    func_02041B6C(UNION_SUBDISP_BG_CHAT);
    if (work->lineKind[srcLine] == UNION_SUBDISP_LINE_PMS && work->lineKind[dstLine] == UNION_SUBDISP_LINE_PMS) {
        PMS_DRAW_Copy(work->pmsDraw, srcLine, dstLine);
        return;
    }
    if (work->lineKind[srcLine] == UNION_SUBDISP_LINE_TEXT && work->lineKind[dstLine] == UNION_SUBDISP_LINE_TEXT) {
        func_02043814(func_02045770(work->lineWin[srcLine]), func_02045770(work->lineWin[dstLine]));
        func_02045334(work->lineWin[dstLine]);
        return;
    }
    func_021F07AC(work, func_021BBC2C(log, oldBottomIndex - 2 + srcLine), dstLine);
}

/*
 * Scrolls the three lines by delta lines: the lines that stay are moved, the
 * lines that come into view are drawn from the chat log.
 */
void func_021F0AA0(UnionSubdispWork *work, UnionChatLog *log, int delta)
{
    long i; /* stand-in: long (not int) is what matches the register use of the loop counter */
    int dstLine;
    UnionChatEntry *entry;

    if (delta > 0) {
        for (i = delta, dstLine = 0; i < 3; i++) {
            func_021F0A04(work, i, dstLine, log, log->scrollIndex - delta);
            dstLine++;
        }
        for (dstLine = 3 - delta; dstLine < 3; dstLine++) {
            entry = func_021BBC2C(log, log->scrollIndex - 2 + dstLine);
            if (entry == 0)
                UNION_SUBDISP_ASSERT_FAIL();
            func_021F07AC(work, entry, (u8)dstLine);
        }
    } else {
        for (i = delta + 2, dstLine = 2; i > -1; i--) {
            func_021F0A04(work, i, dstLine, log, log->scrollIndex - delta);
            dstLine--;
        }
        for (dstLine = -1 - delta; dstLine > -1; dstLine--) {
            entry = func_021BBC2C(log, log->scrollIndex - 2 + dstLine);
            if (entry == 0)
                UNION_SUBDISP_ASSERT_FAIL();
            func_021F07AC(work, entry, (u8)dstLine);
        }
    }
}

/*
 * Keeps the scroll knob under the stylus while it is held. Returns 1 while
 * the knob is dragged.
 */
int func_021F0B98(UnionSubdispWork *work)
{
    UnionSubdispPos pos;
    u32 x;
    u32 y;
    int touched;

    if (TOUCHPANEL_GetPointCont(&x, &y) == 0)
        return 0;
    touched = 1;
    func_0204B454(work->actor[UNION_SUBDISP_ACTOR_SCROLL_KNOB], &pos, 1);
    if (work->inputResult == 0) {
        if (func_02035C60() == 0)
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
        func_0204B404(work->actor[UNION_SUBDISP_ACTOR_SCROLL_KNOB], &pos, 1);
        return 1;
    }
    return 0;
}

/* While the knob is dragged the scroll position follows it, otherwise the knob follows the scroll position. */
void func_021F0C34(UnionRoomWork *room, UnionSubdispWork *work)
{
    if (work->inputResult == 1)
        func_021F0C60(work, &room->chatLog);
    else
        func_021F0CEC(work, &room->chatLog);
}

/*
 * Sets the scroll position of the chat log from the position of the knob.
 * func_021F0D58 is filed as a 12-byte tail stub (r0 = 0x8000, r1 kept); the
 * call sites pass (log, range), so it is declared with two arguments here.
 */
void func_021F0C60(UnionSubdispWork *work, UnionChatLog *log)
{
    UnionSubdispPos pos;
    int range;
    int knobY;
    int step;
    int position;
    int j;

    func_0204B454(work->actor[UNION_SUBDISP_ACTOR_SCROLL_KNOB], &pos, 1);
    knobY = (pos.y - UNION_SUBDISP_KNOB_Y_MIN) << 8;
    range = func_021F0D40(log);
    step = func_021F0D58(log, range);
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
void func_021F0CEC(UnionSubdispWork *work, UnionChatLog *log)
{
    UnionSubdispPos pos;
    int range;
    int step;

    range = func_021F0D40(log);
    step = func_021F0D58(log, range);
    if (log->newestIndex - log->scrollIndex > 0x1B)
        log->scrollIndex = log->newestIndex - 0x1B;
    pos.y = UNION_SUBDISP_KNOB_Y_MAX - ((u32)((log->newestIndex - log->scrollIndex) * step) >> 8);
    pos.x = UNION_SUBDISP_KNOB_X;
    func_0204B404(work->actor[UNION_SUBDISP_ACTOR_SCROLL_KNOB], &pos, 1);
}

/*
 * Number of scroll steps of the knob: the lines of the log (at most 0x1D)
 * minus the two lines that are always visible above the bottom line.
 * Unlabelled leaf (no lr push) sitting in a word run; filed as a blocker of
 * the two knob functions above.
 */
int func_021F0D40(UnionChatLog *log)
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
u32 func_021F0D58(void *unused, u32 range)
{
    return func_0209C2B0(0x8000, range);
}

/* A new touch on the scroll bar moves the knob there. Returns 1 when it did. */
int func_021F0D64(UnionSubdispWork *work)
{
    UnionSubdispPos pos;
    u32 x;
    u32 y;

    if (func_02035D20(&x, &y) == 0)
        return 0;
    if (x >= UNION_SUBDISP_TRACK_X_MIN && x <= UNION_SUBDISP_TRACK_X_MAX && y >= UNION_SUBDISP_KNOB_Y_MIN && y <= UNION_SUBDISP_KNOB_Y_MAX) {
        pos.x = UNION_SUBDISP_KNOB_X;
        pos.y = y;
        func_0204B404(work->actor[UNION_SUBDISP_ACTOR_SCROLL_KNOB], &pos, 1);
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
int func_021F0DB0(UnionRoomWork *room, UnionSubdispWork *work, UnionChatLog *log)
{
    u32 x;
    u32 y;
    int lineNo;
    int entryIndex;
    UnionChatEntry *entry;

    if (func_02035D20(&x, &y) == 0)
        return 0;
    if (x <= UNION_SUBDISP_LIST_TOUCH_X_MAX) {
        for (lineNo = 0; lineNo < 3; lineNo++) {
            if (y >= (u32)(lineNo * UNION_SUBDISP_LINE_TOUCH_HEIGHT) && y <= (u32)(lineNo * UNION_SUBDISP_LINE_TOUCH_HEIGHT + UNION_SUBDISP_LINE_TOUCH_HEIGHT))
                break;
        }
    }
    if (lineNo >= 3 || lineNo > log->newestIndex)
        return 0;
    if (func_021F0F68(work, lineNo, 1) == 1) {
        entryIndex = lineNo;
        lineNo = log->scrollIndex;
        if (lineNo >= 3)
            lineNo = lineNo - 2 + entryIndex;
        else
            lineNo = entryIndex;
        func_021F0ED8(work, log, lineNo);
        entry = func_021BBC2C(log, lineNo);
        if (entry != 0)
            func_02082D44(entry->senderMac, room->mySituation.focusMac, 6);
        func_021F0F40(work, log, lineNo);
        func_020061E4(UNION_SUBDISP_SE_SELECT_LINE);
        return 1;
    }
    return 0;
}

/*
 * Finds the highlight slot for a chat log entry: the slot that already holds
 * it, else a free slot, else a slot whose entry has scrolled out of view.
 */
UnionSubdispLineSlot *func_021F0E64(UnionSubdispWork *work, UnionChatLog *log, int entryIndex)
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
int func_021F0ED8(UnionSubdispWork *work, UnionChatLog *log, int entryIndex)
{
    UnionSubdispLineSlot *slot;
    slot = func_021F0E64(work, log, entryIndex);
    if (!slot)
        return 0;
    slot->timer = UNION_SUBDISP_HIGHLIGHT_FRAMES;
    slot->entryIndex = entryIndex;
    return 1;
}

/* Counts the highlight timers down; a line whose timer ends gets its normal colour back. */
void func_021F0EF4(UnionSubdispWork *work, UnionChatLog *log)
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
                    func_021F0F68(work, lineNo, 0);
            }
        }
    }
}

/* Ends the highlight of every entry except entryIndex at the next frame. */
void func_021F0F40(UnionSubdispWork *work, UnionChatLog *unused, int entryIndex)
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
int func_021F0F68(UnionSubdispWork *unused, int lineNo, int highlighted)
{
    u16 *screen;
    int palette;

    screen = (u16 *)func_0204162C(UNION_SUBDISP_BG_CHAT);
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
void func_021F0FE0(UnionSubdispWork *unused, UnionRoomWork *room)
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
    if (func_0203633C() & 0x200) {
        scroll -= 3;
        if (scroll < minScroll)
            scroll = minScroll;
    } else if (func_0203633C() & 0x100) {
        scroll += 3;
        if (scroll > newest)
            scroll = newest;
    }
    room->chatLog.scrollIndex = scroll;
}
