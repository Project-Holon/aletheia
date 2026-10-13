/*
 * file:     report.c
 * unit:     yes
 * function: func_021EFEC0, func_021EFF34, func_021EFF5C, func_021EFFB4, func_021F0044, func_021F0058, func_021F009C, func_021F00BC, func_021F00F0, func_021F0108, func_021F0114, func_021F01F8, func_021F0228, func_021F0284, func_021F0700, func_021F0724, func_021F0930
 * address:  0x021EFEC0
 * region:   ov034
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021F0B20    0x021F0B20 data ov034 a1
 *   func_0203D34C 0x0203D34C arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021F09BC 0x021F09BC thumb ov034
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012934 0x02012934 thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02040588 0x02040588 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200723C 0x0200723C thumb
 *   _s32_div_f    0x0209C2B0 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021F0AA0 0x021F0AA0 data ov034 a4
 *   d_021F0AC0 0x021F0AC0 data ov034 a4
 *   d_021F0AE0 0x021F0AE0 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02040EBC 0x02040EBC arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02012944 0x02012944 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_020120F8 0x020120F8 thumb
 *   func_02012AC8 0x02012AC8 thumb
 *   func_02013E4C 0x02013E4C thumb
 *   func_0201F158 0x0201F158 thumb
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C258 0x0200C258 thumb
 *   func_0201296C 0x0201296C thumb
 *   func_020142E8 0x020142E8 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200D0AC 0x0200D0AC thumb
 *   func_02012FCC 0x02012FCC thumb
 *   func_0200864C 0x0200864C thumb
 *   func_02008650 0x02008650 thumb
 *   func_020071F0 0x020071F0 thumb
 *   func_020071EC 0x020071EC thumb
 *   func_02008748 0x02008748 thumb
 *   func_020086C8 0x020086C8 thumb
 *   func_020086D0 0x020086D0 thumb
 *   func_020086D8 0x020086D8 thumb
 *   func_020086E0 0x020086E0 thumb
 *   func_020086E8 0x020086E8 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045B38 0x02045B38 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_02088864 0x02088864 arm
 *   func_0208890C 0x0208890C arm
 *   func_02045C04 0x02045C04 arm
 *   d_021F0A70 0x021F0A70 data a1
 *   func_0201D83C 0x0201D83C thumb
 *   func_020452E8 0x020452E8 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0204B100 0x0204B100 arm
 *   func_0201AB28 0x0201AB28 thumb
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   func_0201BA68 0x0201BA68 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204B294 0x0204B294 arm
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02043598 0x02043598 arm
 *   d_021F0A60    0x021F0A60 data a2
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 */
#include "report_types.h"

struct Task;
struct GameData;
struct PrintQue;
struct PartyHolder;
struct ClactActor;
struct ClactUnit;
struct SaveControl;
struct PlayTime;
struct WordSet;
struct Strbuf;
struct MsgBank;
struct GfFont;
struct CharBuf;
struct CharRes;
struct PalRes;
struct CellRes;
struct ArcHandle;
struct PartyMon;

typedef signed short s16;
typedef signed int s32;

struct BgTemplate {
    u32 scrollX;
    u32 scrollY;
    u32 bufSize;
    u32 baseTile;
    u8 screenSize;
    u8 colorMode;
    u8 screenBase;
    u8 charBase;
    u32 extPaletteSlot;
    u8 priority;
    u8 areaOver;
    u8 dummy;
    u8 mosaicFlag;
    u32 mosaic;
};

struct RTCDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
};

struct RTCTime {
    u32 hour;
    u32 minute;
    u32 second;
};

typedef struct {
    s16 x;
    s16 y;
    u16 width;
    u16 height;
} Rect;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0203D34C(u32 a, u32 b);
extern struct Task *func_020056A0(void (*proc)(struct Task *, ReportWork *), ReportWork *work, int priority);
extern void func_021F09BC(struct Task *task, ReportWork *work);
extern void func_02030EAC(struct Task *task);
extern u32 func_020307B0(void *p);
extern u32 func_0201C6B4(const struct PrintQue *printQue);
extern struct GameData *func_020120F4(const void *gameSystem);
extern struct PartyHolder *func_02012934(const struct GameData *gameData);
extern unsigned int func_0201AA18(struct PartyHolder *party);
extern void func_0204B3DC(struct ClactActor *actor, unsigned int visible);
extern void func_02040588(unsigned char layer, unsigned char enable);
extern void func_02045374(struct BmpWin *bmpWin);
extern void func_02041B6C(u32 bit);
extern u32 func_0201C4E4(struct PrintQue *printQue);
extern void *func_02045770(struct BmpWin *bmpWin);
extern u32 func_0201C6C4(struct PrintQue *printQue, void *bitmap);
extern void func_02045334(struct BmpWin *bmpWin);
extern struct SaveControl *func_02012EBC(struct GameData *gameData);
extern void func_0200723C(struct SaveControl *saveControl, u32 *current, u32 *max);
extern void func_020456F8(struct BmpWin *bmpWin);
extern u8 func_02045730(struct BmpWin *bmpWin);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_020409B4(u32 layer);
extern void func_020403F4(u32 i);
extern struct ArcHandle *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(struct ArcHandle *, int, int, int, int, int);
extern void func_02040EBC(u32 a0, u32 a1);
extern void func_02049658(struct ArcHandle *, int, int, int, int, int, int);
extern void func_020498F4(struct ArcHandle *, int, int, int, int, int, int);
extern void func_02049238(struct ArcHandle *);
extern struct PrintQue *func_0201C440(u32 heapId);
extern struct BmpWin *func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern struct Strbuf *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02012944(struct GameData *gameData);
extern void func_0201F02C(struct WordSet *wordSet, u32 i, void *playerName);
extern void func_0201F250(struct WordSet *wordSet, struct Strbuf *dst, struct Strbuf *src);
extern void func_0201C724(struct PrintQue *printQue, void *bitmap, u32 x, u32 y, struct Strbuf *text, struct GfFont *font, u16 color);
extern void func_02045808(struct Strbuf *text);
extern int func_02088864(struct RTCDate *date);
extern int func_0208890C(struct RTCTime *time);
extern void func_0201EFA4(struct WordSet *wordSet, u32 i, u32 value, u32 digits, u32 padding, u32 numberType);
extern u8 *func_020120F8(const void *gameSystem);
extern u16 func_02012AC8(const u8 *playerState);
extern u32 func_02013E4C(u32 zoneId);
extern void func_0201F158(struct WordSet *wordSet, u32 i, u32 msgId);
extern void *func_02012F08(struct GameData *gameData);
extern u32 func_0200C258(void *badgeData);
extern void *func_0201296C(const struct GameData *gameData);
extern u32 func_020142E8(void *eventWork, int flagId);
extern void *func_0200CA1C(struct GameData *gameData);
extern u32 func_0200D0AC(void *pokedex, u32 heap);
extern struct PlayTime *func_02012FCC(struct GameData *gameData);
extern u16 func_0200864C(const struct PlayTime *playTime);
extern u8 func_02008650(const struct PlayTime *playTime);
extern int func_020071F0(struct SaveControl *saveControl);
extern u8 func_020071EC(const struct SaveControl *saveControl);
extern struct PlayTime *func_02008748(struct SaveControl *saveControl);
extern u32 func_020086C8(const struct PlayTime *playTime);
extern u32 func_020086D0(const struct PlayTime *playTime);
extern u32 func_020086D8(const struct PlayTime *playTime);
extern u32 func_020086E0(const struct PlayTime *playTime);
extern u32 func_020086E8(const struct PlayTime *playTime);
extern u32 func_0201ED04(struct WordSet *wordSet);
extern u32 func_02045C04(struct MsgBank *bank);
extern u32 func_0201D83C(struct GfFont *font);
extern u32 func_020452E8(struct BmpWin *bmpWin);
extern void func_0201C4C0(struct PrintQue *printQue);
extern struct ClactUnit *func_0204B100(int count, u8 flag, u32 heapId);
extern struct PartyMon *func_0201AB28(struct PartyHolder *party, u32 i);
extern void *POKE_TOOL_GetBoxParam(struct PartyMon *mon);
extern u32 func_0201BA68(void *boxParam);
extern struct CharRes *func_0204A6C8(struct ArcHandle *arc, u32 fileId, u32 compressed, u32 vramType, u16 heapId);
extern int func_0201BC3C(void);
extern struct PalRes *func_0204ACEC(struct ArcHandle *arc, u32 fileId, u32 vramType, u32 palOffset, u16 heapId);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern struct CellRes *func_0204AF28(struct ArcHandle *arc, u32 cellFileId, u32 animFileId, u32 heapId);
extern struct PalRes *func_0204AC18(struct ArcHandle *arc, u32 fileId, u32 vramType, u32 count, u16 palOffset, u16 pad, u16 heapId);
extern struct ClactActor *func_0204B294(struct ClactUnit *unit, struct CharRes *charRes, struct PalRes *palRes, struct CellRes *cellRes, const Rect *position, unsigned short space, unsigned short heapId);
extern int POKE_TOOL_GetIconPalette(void *boxParam);
extern void func_0204B6F4(struct ClactActor *actor, u32 paletteIndex, u32 flag);
extern void func_02043598(u32 mask, u32 enable);
extern void func_0204B3B4(struct ClactActor *actor);
extern void func_0204A8D4(struct CharRes *charRes);
extern void func_0204ADA4(struct PalRes *palRes);
extern void func_0204AFD8(struct CellRes *cellRes);
extern u32 func_0204B1CC(struct ClactUnit *unit);

ReportWork *func_021EFEC0(void *gameSystem, int heapId);
void func_021EFF34(ReportWork *work);
void func_021EFF5C(ReportWork *work);
void func_021EFFB4(ReportWork *work);
int func_021F0044(ReportWork *work);
void func_021F0058(ReportWork *work);
unsigned func_021F009C(ReportWork *work);
void func_021F00BC(ReportWork *work);
int func_021F00F0(ReportWork *work);
void func_021F0108(ReportWork *work);
void func_021F0114(u32 heapId);
void func_021F01F8(void);
void func_021F0228(int heapId);
void func_021F0284(ReportWork *work);
void func_021F0700(ReportWork *work);
void func_021F0724(ReportWork *work);
void func_021F0930(ReportWork *work);
extern char d_021F0B20[];
extern struct BgTemplate d_021F0AA0;
extern struct BgTemplate d_021F0AC0;
extern struct BgTemplate d_021F0AE0;
extern const u8 d_021F0A70[];
extern const Rect d_021F0A60[2];


ReportWork *func_021EFEC0(void *gameSystem, int heapId)
{
    ReportWork *work = func_02030734(heapId, 0x130, 0, d_021F0B20, 0x114);
    work->gameSystem = gameSystem;
    work->heapId = heapId;
    work->saveAnimRunning = 0;
    work->shownFlags = 0;
    func_021F0114(work->heapId);
    func_021F0228(work->heapId);
    func_021F0724(work);
    func_021F0284(work);
    func_0203D34C(0, heapId);
    work->tcb = func_020056A0(func_021F09BC, work, 0);
    return work;
}

void func_021EFF34(ReportWork *work)
{
    func_02030EAC(work->tcb);
    func_021F0700(work);
    func_021F0930(work);
    func_021F01F8();
    func_020307B0(work);
}


void func_021EFF5C(ReportWork *work)
{
    unsigned int i;
    struct PartyHolder *party;

    if (!(work->shownFlags & REPORT_SHOWN_ICONS) && func_0201C6B4(work->printQue) == 1) {
        party = func_02012934(func_020120F4(work->gameSystem));
        for (i = 0; i < func_0201AA18(party); i++)
            func_0204B3DC(work->actors[i], 1);
        work->shownFlags |= REPORT_SHOWN_ICONS;
    }
}


/*
 * note:     `printQue = work->printQue` must be assigned before the window is
 *           read in the second loop; the other order swaps work and the
 *           second counter between r5 and r6.
 *           EXACT* for the unlabelled follower at 0x021F0044.
 */
void func_021EFFB4(ReportWork *work)
{
    unsigned int i;
    struct PrintQue *printQue;

    if (!(work->shownFlags & REPORT_SHOWN_WINDOWS) && func_0201C6B4(work->printQue) == 1) {
        func_02040588(4, 1);
        func_02040588(5, 1);
        func_02040588(6, 1);
        for (i = 0; i < REPORT_WINDOW_COUNT; i++)
            func_02045374(work->windows[i].bmpWin);
        func_02041B6C(5);
        work->shownFlags |= REPORT_SHOWN_WINDOWS;
    }
    func_0201C4E4(work->printQue);
    for (i = 0; i < REPORT_WINDOW_COUNT; i++) {
        printQue = work->printQue;
        if (work->windows[i].printPending) {
            if (func_0201C6C4(printQue, func_02045770(work->windows[i].bmpWin)) == 0) {
                func_02045334(work->windows[i].bmpWin);
                work->windows[i].printPending = 0;
            }
        }
    }
}

/*
 * True when both shown bits (icons and windows) are set, which is the state
 * word at +0x128 being 3.
 * Region ov034: of the ten overlays mapped here, ov034 holds a Thumb leaf at
 * this address inside the same work struct as its matched neighbours
 * func_021F0058 / func_021F00BC, and the ov021 wrapper family at
 * 0x021A1500..0x021A15F4 already resolves its other callees to ov034
 * (wave A1 witness).
 * Addresses are Black-image addresses.
 */
int func_021F0044(ReportWork *work)
{
    if (work->shownFlags == REPORT_SHOWN_ALL) {
        return 1;
    }
    return 0;
}


void func_021F0058(ReportWork *work)
{
    int step;
    struct SaveControl *saveControl;

    saveControl = func_02012EBC(func_020120F4(work->gameSystem));
    work->saveControl = saveControl;
    func_0200723C(saveControl, &work->saveCountCurrent, &work->saveCountMax);
    step = (work->saveCountCurrent << 9) / 10;
    work->progressStep = step;
    work->progressTarget = step;
    work->barPiecesLit = 0;
    work->pieceFrameDelay = 0;
}

unsigned func_021F009C(ReportWork *work) { return work->saveCountCurrent >= work->saveCountMax / 3; }


void func_021F00BC(ReportWork *work)
{
    struct BmpWin *saveWindow = work->windows[7].bmpWin;
    unsigned int i;

    func_020456F8(saveWindow);
    func_02041B6C(func_02045730(saveWindow));
    for (i = 6; i <= 15; i++)
        func_0204B3DC(work->actors[i], 1);
    work->saveAnimRunning = 1;
}


/*
 * When the halfword counter at +0x124 reaches 10, clears the flag at +0x110
 * (set by func_021F00BC) and returns true.
 * Region ov034: of the ten overlays mapped here, ov034 holds a Thumb leaf at
 * this address inside the same work struct as its matched neighbours
 * func_021F0058 / func_021F00BC, and the ov021 wrapper family at
 * 0x021A1500..0x021A15F4 already resolves its other callees to ov034
 * (wave A1 witness).
 * Addresses are Black-image addresses.
 */
int func_021F00F0(ReportWork *work)
{
    if (work->barPiecesLit == REPORT_BAR_PIECE_COUNT) {
        work->saveAnimRunning = 0;
        return 1;
    }
    return 0;
}

/*
 * Clears the flag at +0x110 that func_021F00BC sets.
 * Region ov034: of the ten overlays mapped here, ov034 holds a Thumb leaf at
 * this address inside the same work struct as its matched neighbours
 * func_021F0058 / func_021F00BC, and the ov021 wrapper family at
 * 0x021A1500..0x021A15F4 already resolves its other callees to ov034
 * (wave A1 witness).
 * Addresses are Black-image addresses.
 */
void func_021F0108(ReportWork *work)
{
    work->saveAnimRunning = 0;
}


void func_021F0114(u32 heapId)
{
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 0);
    func_02040588(7, 0);
    {
        struct BgTemplate bgTemplate = d_021F0AE0;

        func_0203FCA0(4, &bgTemplate, 0);
    }
    func_020414EC(4);
    func_02040B94(4, 0x20, 0, heapId);
    func_020409B4(4);
    {
        struct BgTemplate bgTemplate = d_021F0AC0;

        func_0203FCA0(5, &bgTemplate, 0);
    }
    func_020414EC(5);
    func_02040B94(5, 0x20, 0, heapId);
    func_020409B4(5);
    {
        struct BgTemplate bgTemplate = d_021F0AA0;

        func_0203FCA0(6, &bgTemplate, 0);
    }
    func_020414EC(6);
    func_02040B94(6, 0x20, 0, heapId);
    func_020409B4(6);
}

void func_021F01F8(void) { func_02040588(6,0); func_02040588(5,0); func_02040588(4,0); func_020403F4(6); func_020403F4(5); func_020403F4(4); }


void func_021F0228(int heapId)
{
    struct ArcHandle *arc = func_020490F4(0xC4, heapId);

    func_02049B68(arc, 2, 4, 0, 0x60, heapId);
    func_02040EBC(4, 0);
    func_02049658(arc, 1, 4, 0, 0, 1, heapId);
    func_020498F4(arc, 0, 4, 0, 0, 1, heapId);
    func_02049238(arc);
}

static inline void printRecordLine(ReportWork *work, u32 index, struct Strbuf *buf, struct Strbuf *msg, u32 y, u16 color, u32 pending)
{
    struct PrintQue *printQue = work->printQue;
    func_0201C724(printQue, func_02045770(work->windows[index].bmpWin), 0, y, buf, work->font, color);
    work->windows[index].printPending = pending;
    func_02045808(msg);
}

/*
 * lever: inline printRecordLine binds printQue before the bitmap getter; named one
 * remains live across the repeated blocks and pins their distinct spill slots.
 */
void func_021F0284(ReportWork *work)
{
    u32 i, one = 1;
    struct MsgBank *msgBank;
    struct WordSet *wordSet;
    struct Strbuf *buf;
    struct GameData *gameData;
    struct SaveControl *saveControl;
    struct Strbuf *msgPlayer, *msgDate, *msgTime, *msgLocation, *msgBadges, *msgPokedex, *msgPlayTime, *msgLastSave;
    struct PlayTime *playTime;
    struct PlayTime *currentPlayTime;
    struct RTCDate date;
    struct RTCTime clock;
    work->printQue = func_0201C440(work->heapId);
    for (i = 0; i < REPORT_WINDOW_COUNT; i++) {
        const u8 *layout = d_021F0A70 + i * 6;
        work->windows[i].bmpWin = func_020450F0(layout[0], layout[1], layout[2], layout[3], layout[4], layout[5], one);
        func_02043B5C(func_02045770(work->windows[i].bmpWin), 0);
    }
    work->font = func_0201D7EC(23, 0, 0, 0, work->heapId);
    msgBank = func_02045B38(0, 2, 168, work->heapId);
    wordSet = func_0201EC64(work->heapId);
    buf = func_020457B0(256, work->heapId);
    gameData = func_020120F4(work->gameSystem);
    saveControl = func_02012EBC(gameData);
    msgPlayer = func_02045EC0(msgBank, 0);
    func_0201F02C(wordSet, 0, func_02012944(gameData));
    func_0201F250(wordSet, buf, msgPlayer);
    printRecordLine(work, 0, buf, msgPlayer, 4, 0x3580, one);
    msgDate = func_02045EC0(msgBank, 1);
    func_02088864(&date);
    func_0201EFA4(wordSet, 0, date.year, 2, 2, one);
    func_0201EFA4(wordSet, one, date.month, 2, 0, one);
    func_0201EFA4(wordSet, 2, date.day, 2, 0, one);
    func_0201F250(wordSet, buf, msgDate);
    printRecordLine(work, 1, buf, msgDate, 0, 0x3DC0, one);
    msgTime = func_02045EC0(msgBank, 2);
    func_0208890C(&clock);
    func_0201EFA4(wordSet, 0, clock.hour, 2, 0, one);
    func_0201EFA4(wordSet, one, clock.minute, 2, 2, one);
    func_0201F250(wordSet, buf, msgTime);
    printRecordLine(work, 2, buf, msgTime, 0, 0x3DC0, one);
    msgLocation = func_02045EC0(msgBank, 3);
    func_0201F158(wordSet, 0, func_02013E4C(func_02012AC8(func_020120F8(work->gameSystem))));
    func_0201F250(wordSet, buf, msgLocation);
    printRecordLine(work, 3, buf, msgLocation, 0, 0x3DC0, one);
    msgBadges = func_02045EC0(msgBank, 4);
    func_0201EFA4(wordSet, 0, func_0200C258(func_02012F08(gameData)), 2, 0, 1);
    func_0201F250(wordSet, buf, msgBadges);
    printRecordLine(work, 4, buf, msgBadges, 0, 0x3DC0, one);
    if (func_020142E8(func_0201296C(func_020120F4(work->gameSystem)), 0x962) == 1) {
        msgPokedex = func_02045EC0(msgBank, 5);
        func_0201EFA4(wordSet, 0, func_0200D0AC(func_0200CA1C(gameData), work->heapId), 3, 0, 1);
        func_0201F250(wordSet, buf, msgPokedex);
        printRecordLine(work, 5, buf, msgPokedex, 0, 0x3DC0, one);
    }
    msgPlayTime = func_02045EC0(msgBank, 6);
    currentPlayTime = func_02012FCC(gameData);
    func_0201EFA4(wordSet, 0, func_0200864C(currentPlayTime), 3, 0, 1);
    func_0201EFA4(wordSet, 1, func_02008650(currentPlayTime), 2, 2, 1);
    func_0201F250(wordSet, buf, msgPlayTime);
    printRecordLine(work, 6, buf, msgPlayTime, 0, 0x3DC0, one);
    if (func_020071F0(saveControl) == 0 && func_020071EC(saveControl) == 1) {
        playTime = func_02008748(saveControl);
        msgLastSave = func_02045EC0(msgBank, 7);
        func_0201EFA4(wordSet, 0, func_020086C8(playTime), 2, 2, 1);
        func_0201EFA4(wordSet, 1, func_020086D0(playTime), 2, 0, 1);
        func_0201EFA4(wordSet, 2, func_020086D8(playTime), 2, 0, 1);
        func_0201EFA4(wordSet, 3, func_020086E0(playTime), 2, 0, 1);
        func_0201EFA4(wordSet, 4, func_020086E8(playTime), 2, 2, 1);
        func_0201F250(wordSet, buf, msgLastSave);
        printRecordLine(work, 7, buf, msgLastSave, 4, 0x3580, one);
    } else func_02045334(work->windows[7].bmpWin);
    func_02045808(buf);
    func_0201ED04(wordSet);
    func_02045C04(msgBank);
}

void func_021F0700(ReportWork *work)
{
    unsigned i;
    func_0201D83C(work->font);
    for (i = 0; i < REPORT_WINDOW_COUNT; i++)
        func_020452E8(work->windows[i].bmpWin);
    func_0201C4C0(work->printQue);
}


void func_021F0724(ReportWork *work)
{
    struct PartyHolder *party;
    unsigned int partyCount;
    unsigned int i;
    struct ArcHandle *arc;
    u32 cellFileId;
    struct PartyMon *mon;
    Rect position;

    party = func_02012934(func_020120F4(work->gameSystem));
    partyCount = func_0201AA18(party);
    work->unit = func_0204B100(0x10, 0, work->heapId);
    arc = func_020490F4(7, work->heapId);
    for (i = 0; i < partyCount; i++)
        work->partyCharRes[i] = func_0204A6C8(arc, func_0201BA68(POKE_TOOL_GetBoxParam(func_0201AB28(party, i))), 0, 1,
                                    work->heapId);
    work->partyPalRes = func_0204ACEC(arc, func_0201BC3C(), 1, 0, work->heapId);
    cellFileId = func_0201BC40();
    work->partyCellRes = func_0204AF28(arc, cellFileId, func_0201BCB4(), work->heapId);
    func_02049238(arc);
    arc = func_020490F4(0xC4, work->heapId);
    work->barCharRes = func_0204A6C8(arc, 3, 1, 1, work->heapId);
    work->barPalRes = func_0204AC18(arc, 4, 1, 0x60, 0, 1, work->heapId);
    work->barCellRes = func_0204AF28(arc, 5, 6, work->heapId);
    func_02049238(arc);
    position = d_021F0A60[0];
    for (i = 0; i < partyCount; i++) {
        mon = func_0201AB28(party, i);
        work->actors[i] = func_0204B294(work->unit, work->partyCharRes[i], work->partyPalRes, work->partyCellRes, &position, 1,
                                    work->heapId);
        func_0204B3DC(work->actors[i], 0);
        position.x += 0x20;
        func_0204B6F4(work->actors[i], POKE_TOOL_GetIconPalette(POKE_TOOL_GetBoxParam(mon)), 1);
    }
    position = d_021F0A60[1];
    for (i = 6; i <= 15; i++) {
        work->actors[i] = func_0204B294(work->unit, work->barCharRes, work->barPalRes, work->barCellRes, &position, 1,
                                    work->heapId);
        func_0204B3DC(work->actors[i], 0);
        position.x += 0xC;
    }
    func_02043598(0x10, 1);
}


void func_021F0930(ReportWork *work)
{
    unsigned int i;
    struct PartyHolder *party;

    party = func_02012934(func_020120F4(work->gameSystem));
    for (i = 0; i < func_0201AA18(party); i++) {
        func_0204B3B4(work->actors[i]);
        func_0204A8D4(work->partyCharRes[i]);
    }
    for (i = 6; i <= 15; i++)
        func_0204B3B4(work->actors[i]);
    func_0204A8D4(work->barCharRes);
    func_0204ADA4(work->partyPalRes);
    func_0204ADA4(work->barPalRes);
    func_0204AFD8(work->partyCellRes);
    func_0204AFD8(work->barCellRes);
    func_0204B1CC(work->unit);
    func_02043598(0x10, 0);
}
