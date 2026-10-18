/*
 * file:     report.c
 * unit:     yes
 * function: REPORT_Create, REPORT_Delete, REPORT_ShowPartyIcons, REPORT_UpdateWindows, REPORT_IsReady, REPORT_PrepareSave, REPORT_CheckSaveCounter, REPORT_StartSaveAnim, REPORT_IsSaveAnimDone, REPORT_StopSaveAnim, REPORT_InitBgs, REPORT_ExitBgs, REPORT_LoadBgGraphics, REPORT_InitWindows, REPORT_ExitWindows, REPORT_InitActors, REPORT_ExitActors, REPORT_UpdateSaveAnim
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
 * blocker:  label (arm9 leaf). Every byte agrees; the one wildcard is the
 *   bl to SAVE_CONTROL_GetWrittenSize, an unlabelled arm9 Thumb tail-call stub
 *   (ldr r0,[r0,#0x10]; ldr r3,[pc]; bx r3; .word 0x02031E69) with no
 *   witness outside this range. It is the integrator's. Verified leaf C
 *   (match.py one --thumb, no --region: MATCH, byte-correct, its own
 *   pool word to BACKUP_SYSTEM_GetWrittenSize unwitnessed):
 *     extern u32 BACKUP_SYSTEM_GetWrittenSize(void *p);
 *     u32 SAVE_CONTROL_GetWrittenSize(char *p) { return BACKUP_SYSTEM_GetWrittenSize(*(void **)(p + 0x10)); }
 * note 2026-10-05: the blocker leaf is now filed as src/matched/arm9/SAVE_CONTROL_GetWrittenSize.c
 * (EXACT, verified with match.py one; its pool word to BACKUP_SYSTEM_GetWrittenSize needs the arm symbols line). This
 * file stays MATCH until the integrator regenerates the manifest so the witness resolves;
 * then it is EXACT with no change to the C.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   sReportAllocSite    0x021F0B20 data ov034 a1
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   ICA_ANIME_GetField1C 0x020120F4 thumb
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BG_SYS_SetFlagField06 0x02041B6C arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   SAVE_CONTROL_GetDiffSize 0x0200723C thumb
 *   _s32_div_f    0x0209C0A4 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   sReportBgTemplate6 0x021F0AA0 data ov034 a4
 *   sReportBgTemplate5 0x021F0AC0 data ov034 a4
 *   sReportBgTemplate4 0x021F0AE0 data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   BG_SYS_LoadPlttEntry 0x02040EBC arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   ICA_ANIME_GetField114 0x020120F8 thumb
 *   GAME_DATA_GetPlayerZoneId 0x02012AC8 thumb
 *   ZONEDATA_GetPlaceNameId 0x02013E4C thumb
 *   WORDSET_SetSlotFromMsg59 0x0201F158 thumb
 *   GAME_DATA_GetMiscSave 0x02012F08 thumb
 *   BEACON_CountFlags 0x0200C258 thumb
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   ZUKAN_SAVE_CountSeen 0x0200D0AC thumb
 *   GAME_DATA_GetPlayTime 0x02012FCC thumb
 *   PLAYTIME_GetHours 0x0200864C thumb
 *   PLAYTIME_GetMinutes 0x02008650 thumb
 *   SAVE_CONTROL_WouldOverwriteSave 0x020071F0 thumb
 *   SAVE_CONTROL_HasFlashSave 0x020071EC thumb
 *   SYSTEM_DATA_GetPlayTime 0x02008748 thumb
 *   PLAYTIME_GetStampYear 0x020086C8 thumb
 *   PLAYTIME_GetStampMonth 0x020086D0 thumb
 *   PLAYTIME_GetStampDay 0x020086D8 thumb
 *   PLAYTIME_GetStampHour 0x020086E0 thumb
 *   PLAYTIME_GetStampMinute 0x020086E8 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   RTC_GetDate 0x02088864 arm
 *   RTC_GetTime 0x0208890C arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   sReportWindowLayouts 0x021F0A70 data a1
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   CLACT_CreateUnit 0x0204B100 arm
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   POKE_TOOL_GetGraphicIndex 0x0201BA68 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   POKE_TOOL_GetIconPaletteArcId 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   POKE_TOOL_GetIconCellArcId 0x0201BC40 thumb
 *   POKE_TOOL_GetIconCellEntryId 0x0201BCB4 thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   sReportActorPositions    0x021F0A60 data a2
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   SAVE_CONTROL_GetWrittenSize 0x020071C0 thumb
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
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
    u32 x;                  /* 0x00 */
    u32 y;                  /* 0x04 */
    u32 bufSize;            /* 0x08 */
    u32 baseTile;           /* 0x0C */
    u8 screenSize;          /* 0x10 */
    u8 colorMode;           /* 0x11 */
    u8 screenBase;          /* 0x12 */
    u8 charBase;            /* 0x13 */
    u32 extPaletteSlot;     /* 0x14 */
    u8 priority;            /* 0x18 */
    u8 areaOver;            /* 0x19 */
    u8 dummy;               /* 0x1A */
    u8 mosaic;              /* 0x1B */
    u32 bgType;             /* 0x1C */
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

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern struct Task *GFL_USE_AddMainTask(void (*proc)(struct Task *, ReportWork *), ReportWork *work, int priority);
extern void TCB_DeleteTask(struct Task *task);
extern u32 GFL_HEAP_Free(void *p);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintQue *printQue);
extern struct GameData *ICA_ANIME_GetField1C(const void *gameSystem);
extern struct PartyHolder *GAME_DATA_GetMyParty(const struct GameData *gameData);
extern unsigned int POKEPARTY_GetCount(struct PartyHolder *party);
extern void CLACT_SetActorDrawEnable(struct ClactActor *actor, unsigned int visible);
extern void BG_SYS_SetPlaneVisible(unsigned char layer, unsigned char enable);
extern void BMP_WIN_MakeScreen(struct BmpWin *bmpWin);
extern void BG_SYS_SetFlagField06(u32 bit);
extern u32 PRINTSYS_QUE_Main(struct PrintQue *printQue);
extern void *BMP_WIN_GetBmp(struct BmpWin *bmpWin);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintQue *printQue, void *bitmap);
extern void BMP_WIN_TransferChars(struct BmpWin *bmpWin);
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern void SAVE_CONTROL_GetDiffSize(struct SaveControl *saveControl, u32 *current, u32 *max);
extern void BMP_WIN_ClearScreen(struct BmpWin *bmpWin);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *bmpWin);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_ClearSlot(u32 i);
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);
extern void BG_SYS_PushTile(u32 layer);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern struct ArcHandle *ARC_TOOL_CreateHandle(unsigned int id, unsigned int heap);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(struct ArcHandle *, int, int, int, int, int);
extern void BG_SYS_LoadPlttEntry(u32 a0, u32 a1);
extern void ARC_UTIL_UploadBgCharFromHandle(struct ArcHandle *, int, int, int, int, int, int);
extern void ARC_UTIL_UploadBgPaletteFromHandle(struct ArcHandle *, int, int, int, int, int, int);
extern void ARC_TOOL_DeleteHandle(struct ArcHandle *);
extern struct PrintQue *PRINTSYS_QUE_Create(u32 heapId);
extern struct BmpWin *BMP_WIN_Create(u32, u32, u32, u32, u8, u8, u8);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern struct Strbuf *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern void *GAME_DATA_GetMyStatus(struct GameData *gameData);
extern void WORDSET_SetSlotMyStatus(struct WordSet *wordSet, u32 i, void *playerName);
extern void WORDSET_CopyTaggedText(struct WordSet *wordSet, struct Strbuf *dst, struct Strbuf *src);
extern void PRINTSYS_PrintQueColor(struct PrintQue *printQue, void *bitmap, u32 x, u32 y, struct Strbuf *text, struct GfFont *font, u16 color);
extern void STRBUF_Delete(struct Strbuf *text);
extern int RTC_GetDate(struct RTCDate *date);
extern int RTC_GetTime(struct RTCTime *time);
extern void WORDSET_SetSlotNumber(struct WordSet *wordSet, u32 i, u32 value, u32 digits, u32 padding, u32 numberType);
extern u8 *ICA_ANIME_GetField114(const void *gameSystem);
extern u16 GAME_DATA_GetPlayerZoneId(const u8 *playerState);
extern u32 ZONEDATA_GetPlaceNameId(u32 zoneId);
extern void WORDSET_SetSlotFromMsg59(struct WordSet *wordSet, u32 i, u32 msgId);
extern void *GAME_DATA_GetMiscSave(struct GameData *gameData);
extern u32 BEACON_CountFlags(void *badgeData);
extern void *GAME_DATA_GetEventWork(const struct GameData *gameData);
extern u32 ZONEDATA_CheckEventFlag(void *eventWork, int flagId);
extern void *ZUKAN_SAVE_GetFromGameData(struct GameData *gameData);
extern u32 ZUKAN_SAVE_CountSeen(void *pokedex, u32 heap);
extern struct PlayTime *GAME_DATA_GetPlayTime(struct GameData *gameData);
extern u16 PLAYTIME_GetHours(const struct PlayTime *playTime);
extern u8 PLAYTIME_GetMinutes(const struct PlayTime *playTime);
extern int SAVE_CONTROL_WouldOverwriteSave(struct SaveControl *saveControl);
extern u8 SAVE_CONTROL_HasFlashSave(const struct SaveControl *saveControl);
extern struct PlayTime *SYSTEM_DATA_GetPlayTime(struct SaveControl *saveControl);
extern u32 PLAYTIME_GetStampYear(const struct PlayTime *playTime);
extern u32 PLAYTIME_GetStampMonth(const struct PlayTime *playTime);
extern u32 PLAYTIME_GetStampDay(const struct PlayTime *playTime);
extern u32 PLAYTIME_GetStampHour(const struct PlayTime *playTime);
extern u32 PLAYTIME_GetStampMinute(const struct PlayTime *playTime);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *wordSet);
extern u32 MSGDATA_Delete(struct MsgBank *bank);
extern u32 GF_FONT_Delete(struct GfFont *font);
extern u32 BMP_WIN_Delete(struct BmpWin *bmpWin);
extern void PRINTSYS_QUE_Delete(struct PrintQue *printQue);
extern struct ClactUnit *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern struct PartyMon *POKEPARTY_GetMember(struct PartyHolder *party, u32 i);
extern void *POKE_TOOL_GetBoxParam(struct PartyMon *mon);
extern u32 POKE_TOOL_GetGraphicIndex(void *boxParam);
extern struct CharRes *CLACT_RegisterCharacter(struct ArcHandle *arc, u32 fileId, u32 compressed, u32 vramType, u16 heapId);
extern int POKE_TOOL_GetIconPaletteArcId(void);
extern struct PalRes *CLACT_RegisterPaletteCompressed(struct ArcHandle *arc, u32 fileId, u32 vramType, u32 palOffset, u16 heapId);
extern int POKE_TOOL_GetIconCellArcId(void);
extern int POKE_TOOL_GetIconCellEntryId(void);
extern struct CellRes *CLACT_RegisterCellAnim(struct ArcHandle *arc, u32 cellFileId, u32 animFileId, u32 heapId);
extern struct PalRes *CLACT_RegisterPaletteEx(struct ArcHandle *arc, u32 fileId, u32 vramType, u32 count, u16 palOffset, u16 pad, u16 heapId);
extern struct ClactActor *CLACT_CreateActor(struct ClactUnit *unit, struct CharRes *charRes, struct PalRes *palRes, struct CellRes *cellRes, const Rect *position, unsigned short space, unsigned short heapId);
extern int POKE_TOOL_GetIconPalette(void *boxParam);
extern void CLACT_SetActorPaletteOffset(struct ClactActor *actor, u32 paletteIndex, u32 flag);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void CLACT_DeleteActor(struct ClactActor *actor);
extern void CLACT_ReleaseCharacter(struct CharRes *charRes);
extern void CLACT_ReleasePalette(struct PalRes *palRes);
extern void CLACT_ReleaseCellAnim(struct CellRes *cellRes);
extern u32 CLACT_DeleteUnit(struct ClactUnit *unit);
extern u32 SAVE_CONTROL_GetWrittenSize(void *saveControl);
extern void CLACT_SetActorAnimFrame(struct ClactActor *actor, u32 value);
extern void CLACT_SetActorAnimSeq(struct ClactActor *actor, u16 value);
extern void CLACT_SetActorAutoAnim(struct ClactActor *actor, u32 v);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
ReportWork *REPORT_Create(void *gameSystem, int heapId);
void REPORT_Delete(ReportWork *work);
void REPORT_ShowPartyIcons(ReportWork *work);
void REPORT_UpdateWindows(ReportWork *work);
int REPORT_IsReady(ReportWork *work);
void REPORT_PrepareSave(ReportWork *work);
unsigned REPORT_CheckSaveCounter(ReportWork *work);
void REPORT_StartSaveAnim(ReportWork *work);
int REPORT_IsSaveAnimDone(ReportWork *work);
void REPORT_StopSaveAnim(ReportWork *work);
void REPORT_InitBgs(u32 heapId);
void REPORT_ExitBgs(void);
void REPORT_LoadBgGraphics(int heapId);
void REPORT_InitWindows(ReportWork *work);
void REPORT_ExitWindows(ReportWork *work);
void REPORT_InitActors(ReportWork *work);
void REPORT_ExitActors(ReportWork *work);
void REPORT_UpdateSaveAnim(struct Task *task, ReportWork *work);
extern char sReportAllocSite[];
extern struct BgTemplate sReportBgTemplate6;
extern struct BgTemplate sReportBgTemplate5;
extern struct BgTemplate sReportBgTemplate4;
extern const u8 sReportWindowLayouts[];
extern const Rect sReportActorPositions[2];



ReportWork *REPORT_Create(void *gameSystem, int heapId)
{
    ReportWork *work = GFL_HEAP_Alloc(heapId, 0x130, 0, sReportAllocSite, 0x114);
    work->gameSystem = gameSystem;
    work->heapId = heapId;
    work->saveAnimRunning = 0;
    work->shownFlags = 0;
    REPORT_InitBgs(work->heapId);
    REPORT_LoadBgGraphics(work->heapId);
    REPORT_InitActors(work);
    REPORT_InitWindows(work);
    GFL_NET_RestartWithDefaultTimeout(0, heapId);
    work->tcb = GFL_USE_AddMainTask(REPORT_UpdateSaveAnim, work, 0);
    return work;
}


void REPORT_Delete(ReportWork *work)
{
    TCB_DeleteTask(work->tcb);
    REPORT_ExitWindows(work);
    REPORT_ExitActors(work);
    REPORT_ExitBgs();
    GFL_HEAP_Free(work);
}



void REPORT_ShowPartyIcons(ReportWork *work)
{
    unsigned int i;
    struct PartyHolder *party;

    if (!(work->shownFlags & REPORT_SHOWN_ICONS) && PRINTSYS_QUE_IsFinished(work->printQue) == 1) {
        party = GAME_DATA_GetMyParty(ICA_ANIME_GetField1C(work->gameSystem));
        for (i = 0; i < POKEPARTY_GetCount(party); i++)
            CLACT_SetActorDrawEnable(work->actors[i], 1);
        work->shownFlags |= REPORT_SHOWN_ICONS;
    }
}



/*
 * note:     `printQue = work->printQue` must be assigned before the window is
 *           read in the second loop; the other order swaps work and the
 *           second counter between r5 and r6.
 *           EXACT* for the unlabelled follower at 0x021F0044.
 */
void REPORT_UpdateWindows(ReportWork *work)
{
    unsigned int i;
    struct PrintQue *printQue;

    if (!(work->shownFlags & REPORT_SHOWN_WINDOWS) && PRINTSYS_QUE_IsFinished(work->printQue) == 1) {
        BG_SYS_SetPlaneVisible(4, 1);
        BG_SYS_SetPlaneVisible(5, 1);
        BG_SYS_SetPlaneVisible(6, 1);
        for (i = 0; i < REPORT_WINDOW_COUNT; i++)
            BMP_WIN_MakeScreen(work->windows[i].bmpWin);
        BG_SYS_SetFlagField06(5);
        work->shownFlags |= REPORT_SHOWN_WINDOWS;
    }
    PRINTSYS_QUE_Main(work->printQue);
    for (i = 0; i < REPORT_WINDOW_COUNT; i++) {
        printQue = work->printQue;
        if (work->windows[i].printPending) {
            if (PRINTSYS_QUE_IsExistTarget(printQue, BMP_WIN_GetBmp(work->windows[i].bmpWin)) == 0) {
                BMP_WIN_TransferChars(work->windows[i].bmpWin);
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
 * REPORT_PrepareSave / REPORT_StartSaveAnim, and the ov021 wrapper family at
 * 0x021A1500..0x021A15F4 already resolves its other callees to ov034
 * (wave A1 witness).
 * Addresses are Black-image addresses.
 */
int REPORT_IsReady(ReportWork *work)
{
    if (work->shownFlags == REPORT_SHOWN_ALL) {
        return 1;
    }
    return 0;
}



void REPORT_PrepareSave(ReportWork *work)
{
    int step;
    struct SaveControl *saveControl;

    saveControl = GAME_DATA_GetSaveControl(ICA_ANIME_GetField1C(work->gameSystem));
    work->saveControl = saveControl;
    SAVE_CONTROL_GetDiffSize(saveControl, &work->saveCountCurrent, &work->saveCountMax);
    step = (work->saveCountCurrent << 9) / 10;
    work->progressStep = step;
    work->progressTarget = step;
    work->barPiecesLit = 0;
    work->pieceFrameDelay = 0;
}


unsigned REPORT_CheckSaveCounter(ReportWork *work) { return work->saveCountCurrent >= work->saveCountMax / 3; }



void REPORT_StartSaveAnim(ReportWork *work)
{
    struct BmpWin *saveWindow = work->windows[7].bmpWin;
    unsigned int i;

    BMP_WIN_ClearScreen(saveWindow);
    BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer(saveWindow));
    for (i = 6; i <= 15; i++)
        CLACT_SetActorDrawEnable(work->actors[i], 1);
    work->saveAnimRunning = 1;
}



/*
 * When the halfword counter at +0x124 reaches 10, clears the flag at +0x110
 * (set by REPORT_StartSaveAnim) and returns true.
 * Region ov034: of the ten overlays mapped here, ov034 holds a Thumb leaf at
 * this address inside the same work struct as its matched neighbours
 * REPORT_PrepareSave / REPORT_StartSaveAnim, and the ov021 wrapper family at
 * 0x021A1500..0x021A15F4 already resolves its other callees to ov034
 * (wave A1 witness).
 * Addresses are Black-image addresses.
 */
int REPORT_IsSaveAnimDone(ReportWork *work)
{
    if (work->barPiecesLit == REPORT_BAR_PIECE_COUNT) {
        work->saveAnimRunning = 0;
        return 1;
    }
    return 0;
}


/*
 * Clears the flag at +0x110 that REPORT_StartSaveAnim sets.
 * Region ov034: of the ten overlays mapped here, ov034 holds a Thumb leaf at
 * this address inside the same work struct as its matched neighbours
 * REPORT_PrepareSave / REPORT_StartSaveAnim, and the ov021 wrapper family at
 * 0x021A1500..0x021A15F4 already resolves its other callees to ov034
 * (wave A1 witness).
 * Addresses are Black-image addresses.
 */
void REPORT_StopSaveAnim(ReportWork *work)
{
    work->saveAnimRunning = 0;
}



void REPORT_InitBgs(u32 heapId)
{
    BG_SYS_SetPlaneVisible(4, 0);
    BG_SYS_SetPlaneVisible(5, 0);
    BG_SYS_SetPlaneVisible(6, 0);
    BG_SYS_SetPlaneVisible(7, 0);
    {
        struct BgTemplate bgTemplate = sReportBgTemplate4;

        BG_SYS_InitBgLayer(4, &bgTemplate, 0);
    }
    BG_SYS_ClearSlot(4);
    BG_SYS_InitRun(4, 0x20, 0, heapId);
    BG_SYS_PushTile(4);
    {
        struct BgTemplate bgTemplate = sReportBgTemplate5;

        BG_SYS_InitBgLayer(5, &bgTemplate, 0);
    }
    BG_SYS_ClearSlot(5);
    BG_SYS_InitRun(5, 0x20, 0, heapId);
    BG_SYS_PushTile(5);
    {
        struct BgTemplate bgTemplate = sReportBgTemplate6;

        BG_SYS_InitBgLayer(6, &bgTemplate, 0);
    }
    BG_SYS_ClearSlot(6);
    BG_SYS_InitRun(6, 0x20, 0, heapId);
    BG_SYS_PushTile(6);
}


void REPORT_ExitBgs(void) { BG_SYS_SetPlaneVisible(6,0); BG_SYS_SetPlaneVisible(5,0); BG_SYS_SetPlaneVisible(4,0); BG_SYS_FreeLayerBuf(6); BG_SYS_FreeLayerBuf(5); BG_SYS_FreeLayerBuf(4); }



void REPORT_LoadBgGraphics(int heapId)
{
    struct ArcHandle *arc = ARC_TOOL_CreateHandle(0xC4, heapId);

    ARC_UTIL_UploadPaletteFromHandleWhole(arc, 2, 4, 0, 0x60, heapId);
    BG_SYS_LoadPlttEntry(4, 0);
    ARC_UTIL_UploadBgCharFromHandle(arc, 1, 4, 0, 0, 1, heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(arc, 0, 4, 0, 0, 1, heapId);
    ARC_TOOL_DeleteHandle(arc);
}


static inline void printRecordLine(ReportWork *work, u32 index, struct Strbuf *buf, struct Strbuf *msg, u32 y, u16 color, u32 pending)
{
    struct PrintQue *printQue = work->printQue;
    PRINTSYS_PrintQueColor(printQue, BMP_WIN_GetBmp(work->windows[index].bmpWin), 0, y, buf, work->font, color);
    work->windows[index].printPending = pending;
    STRBUF_Delete(msg);
}


/*
 * lever: inline printRecordLine binds printQue before the bitmap getter; named one
 * remains live across the repeated blocks and pins their distinct spill slots.
 */
void REPORT_InitWindows(ReportWork *work)
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
    work->printQue = PRINTSYS_QUE_Create(work->heapId);
    for (i = 0; i < REPORT_WINDOW_COUNT; i++) {
        const u8 *layout = sReportWindowLayouts + i * 6;
        work->windows[i].bmpWin = BMP_WIN_Create(layout[0], layout[1], layout[2], layout[3], layout[4], layout[5], one);
        BMP_Clear(BMP_WIN_GetBmp(work->windows[i].bmpWin), 0);
    }
    work->font = GF_FONT_Create(23, 0, 0, 0, work->heapId);
    msgBank = MSGDATA_CreateFromArchive(0, 2, 168, work->heapId);
    wordSet = WORDSET_CreateDefault(work->heapId);
    buf = STRBUF_Create(256, work->heapId);
    gameData = ICA_ANIME_GetField1C(work->gameSystem);
    saveControl = GAME_DATA_GetSaveControl(gameData);
    msgPlayer = MSGDATA_AllocString(msgBank, 0);
    WORDSET_SetSlotMyStatus(wordSet, 0, GAME_DATA_GetMyStatus(gameData));
    WORDSET_CopyTaggedText(wordSet, buf, msgPlayer);
    printRecordLine(work, 0, buf, msgPlayer, 4, 0x3580, one);
    msgDate = MSGDATA_AllocString(msgBank, 1);
    RTC_GetDate(&date);
    WORDSET_SetSlotNumber(wordSet, 0, date.year, 2, 2, one);
    WORDSET_SetSlotNumber(wordSet, one, date.month, 2, 0, one);
    WORDSET_SetSlotNumber(wordSet, 2, date.day, 2, 0, one);
    WORDSET_CopyTaggedText(wordSet, buf, msgDate);
    printRecordLine(work, 1, buf, msgDate, 0, 0x3DC0, one);
    msgTime = MSGDATA_AllocString(msgBank, 2);
    RTC_GetTime(&clock);
    WORDSET_SetSlotNumber(wordSet, 0, clock.hour, 2, 0, one);
    WORDSET_SetSlotNumber(wordSet, one, clock.minute, 2, 2, one);
    WORDSET_CopyTaggedText(wordSet, buf, msgTime);
    printRecordLine(work, 2, buf, msgTime, 0, 0x3DC0, one);
    msgLocation = MSGDATA_AllocString(msgBank, 3);
    WORDSET_SetSlotFromMsg59(wordSet, 0, ZONEDATA_GetPlaceNameId(GAME_DATA_GetPlayerZoneId(ICA_ANIME_GetField114(work->gameSystem))));
    WORDSET_CopyTaggedText(wordSet, buf, msgLocation);
    printRecordLine(work, 3, buf, msgLocation, 0, 0x3DC0, one);
    msgBadges = MSGDATA_AllocString(msgBank, 4);
    WORDSET_SetSlotNumber(wordSet, 0, BEACON_CountFlags(GAME_DATA_GetMiscSave(gameData)), 2, 0, 1);
    WORDSET_CopyTaggedText(wordSet, buf, msgBadges);
    printRecordLine(work, 4, buf, msgBadges, 0, 0x3DC0, one);
    if (ZONEDATA_CheckEventFlag(GAME_DATA_GetEventWork(ICA_ANIME_GetField1C(work->gameSystem)), 0x962) == 1) {
        msgPokedex = MSGDATA_AllocString(msgBank, 5);
        WORDSET_SetSlotNumber(wordSet, 0, ZUKAN_SAVE_CountSeen(ZUKAN_SAVE_GetFromGameData(gameData), work->heapId), 3, 0, 1);
        WORDSET_CopyTaggedText(wordSet, buf, msgPokedex);
        printRecordLine(work, 5, buf, msgPokedex, 0, 0x3DC0, one);
    }
    msgPlayTime = MSGDATA_AllocString(msgBank, 6);
    currentPlayTime = GAME_DATA_GetPlayTime(gameData);
    WORDSET_SetSlotNumber(wordSet, 0, PLAYTIME_GetHours(currentPlayTime), 3, 0, 1);
    WORDSET_SetSlotNumber(wordSet, 1, PLAYTIME_GetMinutes(currentPlayTime), 2, 2, 1);
    WORDSET_CopyTaggedText(wordSet, buf, msgPlayTime);
    printRecordLine(work, 6, buf, msgPlayTime, 0, 0x3DC0, one);
    if (SAVE_CONTROL_WouldOverwriteSave(saveControl) == 0 && SAVE_CONTROL_HasFlashSave(saveControl) == 1) {
        playTime = SYSTEM_DATA_GetPlayTime(saveControl);
        msgLastSave = MSGDATA_AllocString(msgBank, 7);
        WORDSET_SetSlotNumber(wordSet, 0, PLAYTIME_GetStampYear(playTime), 2, 2, 1);
        WORDSET_SetSlotNumber(wordSet, 1, PLAYTIME_GetStampMonth(playTime), 2, 0, 1);
        WORDSET_SetSlotNumber(wordSet, 2, PLAYTIME_GetStampDay(playTime), 2, 0, 1);
        WORDSET_SetSlotNumber(wordSet, 3, PLAYTIME_GetStampHour(playTime), 2, 0, 1);
        WORDSET_SetSlotNumber(wordSet, 4, PLAYTIME_GetStampMinute(playTime), 2, 2, 1);
        WORDSET_CopyTaggedText(wordSet, buf, msgLastSave);
        printRecordLine(work, 7, buf, msgLastSave, 4, 0x3580, one);
    } else BMP_WIN_TransferChars(work->windows[7].bmpWin);
    STRBUF_Delete(buf);
    WORDSET_DeleteStrbufED04(wordSet);
    MSGDATA_Delete(msgBank);
}


void REPORT_ExitWindows(ReportWork *work)
{
    unsigned i;
    GF_FONT_Delete(work->font);
    for (i = 0; i < REPORT_WINDOW_COUNT; i++)
        BMP_WIN_Delete(work->windows[i].bmpWin);
    PRINTSYS_QUE_Delete(work->printQue);
}



void REPORT_InitActors(ReportWork *work)
{
    struct PartyHolder *party;
    unsigned int partyCount;
    unsigned int i;
    struct ArcHandle *arc;
    u32 cellFileId;
    struct PartyMon *mon;
    Rect position;

    party = GAME_DATA_GetMyParty(ICA_ANIME_GetField1C(work->gameSystem));
    partyCount = POKEPARTY_GetCount(party);
    work->unit = CLACT_CreateUnit(0x10, 0, work->heapId);
    arc = ARC_TOOL_CreateHandle(7, work->heapId);
    for (i = 0; i < partyCount; i++)
        work->partyCharRes[i] = CLACT_RegisterCharacter(arc, POKE_TOOL_GetGraphicIndex(POKE_TOOL_GetBoxParam(POKEPARTY_GetMember(party, i))), 0, 1,
                                    work->heapId);
    work->partyPalRes = CLACT_RegisterPaletteCompressed(arc, POKE_TOOL_GetIconPaletteArcId(), 1, 0, work->heapId);
    cellFileId = POKE_TOOL_GetIconCellArcId();
    work->partyCellRes = CLACT_RegisterCellAnim(arc, cellFileId, POKE_TOOL_GetIconCellEntryId(), work->heapId);
    ARC_TOOL_DeleteHandle(arc);
    arc = ARC_TOOL_CreateHandle(0xC4, work->heapId);
    work->barCharRes = CLACT_RegisterCharacter(arc, 3, 1, 1, work->heapId);
    work->barPalRes = CLACT_RegisterPaletteEx(arc, 4, 1, 0x60, 0, 1, work->heapId);
    work->barCellRes = CLACT_RegisterCellAnim(arc, 5, 6, work->heapId);
    ARC_TOOL_DeleteHandle(arc);
    position = sReportActorPositions[0];
    for (i = 0; i < partyCount; i++) {
        mon = POKEPARTY_GetMember(party, i);
        work->actors[i] = CLACT_CreateActor(work->unit, work->partyCharRes[i], work->partyPalRes, work->partyCellRes, &position, 1,
                                    work->heapId);
        CLACT_SetActorDrawEnable(work->actors[i], 0);
        position.x += 0x20;
        CLACT_SetActorPaletteOffset(work->actors[i], POKE_TOOL_GetIconPalette(POKE_TOOL_GetBoxParam(mon)), 1);
    }
    position = sReportActorPositions[1];
    for (i = 6; i <= 15; i++) {
        work->actors[i] = CLACT_CreateActor(work->unit, work->barCharRes, work->barPalRes, work->barCellRes, &position, 1,
                                    work->heapId);
        CLACT_SetActorDrawEnable(work->actors[i], 0);
        position.x += 0xC;
    }
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}



void REPORT_ExitActors(ReportWork *work)
{
    unsigned int i;
    struct PartyHolder *party;

    party = GAME_DATA_GetMyParty(ICA_ANIME_GetField1C(work->gameSystem));
    for (i = 0; i < POKEPARTY_GetCount(party); i++) {
        CLACT_DeleteActor(work->actors[i]);
        CLACT_ReleaseCharacter(work->partyCharRes[i]);
    }
    for (i = 6; i <= 15; i++)
        CLACT_DeleteActor(work->actors[i]);
    CLACT_ReleaseCharacter(work->barCharRes);
    CLACT_ReleasePalette(work->partyPalRes);
    CLACT_ReleasePalette(work->barPalRes);
    CLACT_ReleaseCellAnim(work->partyCellRes);
    CLACT_ReleaseCellAnim(work->barCellRes);
    CLACT_DeleteUnit(work->unit);
    BG_SYS_SetSubPlaneVisible(0x10, 0);
}


void REPORT_UpdateSaveAnim(struct Task *task, ReportWork *work)
{
    u32 writtenSize;

    if (work->saveAnimRunning != 0) {
        writtenSize = SAVE_CONTROL_GetWrittenSize(work->saveControl) << 8;
        if (work->pieceFrameDelay != 8)
            work->pieceFrameDelay++;
        if (writtenSize >= work->progressTarget && work->pieceFrameDelay == 8
            && work->barPiecesLit < REPORT_BAR_PIECE_COUNT) {
            work->progressTarget += work->progressStep;
            work->pieceFrameDelay = 0;
            CLACT_SetActorAnimFrame(work->actors[work->barPiecesLit + 6], 0);
            CLACT_SetActorAnimSeq(work->actors[work->barPiecesLit + 6], 1);
            CLACT_SetActorAutoAnim(work->actors[work->barPiecesLit + 6], 1);
            work->barPiecesLit++;
        }
        CLACT_DrawSystem();
        CLACT_VBlankSystem();
    }
}
