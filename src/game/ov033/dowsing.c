/*
 * file:     dowsing.c
 * unit:     yes
 * function: func_021EFEC0, func_021EFEE4, func_021EFEEC, func_021EFF40, func_021EFF48, func_021F000C, func_021F0124, func_021F0174, func_021F05A4, func_021F0674, func_021F06AC, func_021F0738, func_021F0760, func_021F07DC, func_021F07F4, func_021F08EC, func_021F0924, func_021F0A90, func_021F0AC4, func_021F0B74, func_021F0C0C, func_021F0C44
 * address:  0x021EFEC0
 * region:   ov033
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
 *   d_021F0E60 0x021F0E60 data ov033 a1
 *   func_020307B0 0x020307B0 arm
 *   func_020142E8 0x020142E8 thumb
 *   func_021CFAC0 0x021CFAC0 thumb ov021
 *   func_0216476C 0x0216476C thumb ov010
 *   func_021CFB68 0x021CFB68 thumb ov021
 *   func_0204A298 0x0204A298 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_0201296C 0x0201296C thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BE48 0x0200BE48 thumb
 *   func_0207D63C 0x0207D63C arm
 *   func_0203D34C 0x0203D34C arm
 *   func_02030EAC 0x02030EAC arm
 *   func_02024ABC 0x02024ABC thumb
 *   func_02159C48 0x02159C48 thumb ov010
 *   func_02159BD4 0x02159BD4 thumb ov010
 *   func_020120F8 0x020120F8 thumb
 *   func_02012AA0 0x02012AA0 thumb
 *   func_02012974 0x02012974 thumb
 *   func_02013E7C 0x02013E7C thumb
 *   func_02013D74 0x02013D74 thumb
 *   func_02006148 0x02006148 thumb
 *   func_0200616C 0x0200616C thumb
 *   GFL_USE_SetSeSlotParams 0x02006268 thumb
 *   func_02006224 0x02006224 thumb
 *   func_020061E4 0x020061E4 thumb
 *   d_021F0DC8 0x021F0DC8 data ov033 a4
 *   func_021F0C44 0x021F0C44 thumb ov033
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   func_02040588 0x02040588 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040618 0x02040618 arm
 *   func_0204B100 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   func_02043598 0x02043598 arm
 *   d_021F0DF0 0x021F0DF0 data ov033 a4
 *   func_0204B1CC 0x0204B1CC arm
 *   func_020403F4 0x020403F4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B688 0x0204B688 arm
 *   d_021F0DBC 0x021F0DBC data ov033 a1
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_02024A20 0x02024A20 thumb
 *   func_020275E4 0x020275E4 thumb
 *   func_02027624 0x02027624 thumb
 *   func_02027628 0x02027628 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_02049B68 0x02049B68 arm
 *   func_02049EF4 0x02049EF4 arm
 *   func_020410D0 0x020410D0 arm
 *   func_0204B954 0x0204B954 arm
 *   func_02024DCC 0x02024DCC thumb
 *   func_02035D20 0x02035D20 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020362DC 0x020362DC arm
 *   func_0204B98C 0x0204B98C arm
 *   func_021A0F30 0x021A0F30 thumb ov021
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_02021518 0x02021518 thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_02030DA4 0x02030DA4 arm
 *   func_02030D28 0x02030D28 arm
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   PALANM_RequestFade 0x0202173C thumb
 *   CLACT_StartActorAnim 0x0204B95C arm
 *   CLACT_StopActorAnim 0x0204B974 arm
 */
#include "../ov021/field_subscreen_types.h"
#include "dowsing_types.h"

#define DOWSING_ARC_ID 0xC3
#define DOWSING_HIDDEN_ITEM_FLAG_BASE 0x384
#define DOWSING_SCAN_ALL 0xFFFF
#define DOWSING_SCAN_PER_UPDATE 11
#define DOWSING_ZONE_NONE 0xFFFF
#define DOWSING_KEY_CLOSE 0x400
#define SCAN_BEST 0
#define SCAN_CURRENT 1

#define reg_GXS_DB_BLDCNT (*(volatile u16 *)0x04001050)

struct FieldSystem;
struct GameData;
struct PlayerAvatar;
struct BgTemplate;
struct Vec3Fx;

typedef struct Vec3Fx {
    int x, y, z;
} Vec3Fx;

extern void *func_02030734(u32 heapId, u32 size, int align, const char *file, u16 line);
extern u32 func_020307B0(void *mem);
extern u32 func_020142E8(void *flagBitmap, s32 flagId);
extern int func_021CFAC0(void *eventData, int zoneId, int x, int y, int z);
extern const DowsingHiddenItem *func_0216476C(u16 *count);
extern const DowsingMapEvent *func_021CFB68(void *eventData, unsigned *index);
extern void *func_0204A298(u32 arcId, u32 fileId, int compressed, u32 heapId, u32 *outSize);
extern struct Task *func_020056A0(void (*proc)(int, DowsingWork *), DowsingWork *work, u32 priority);
extern struct FieldSystem *func_02188C80(void *fieldMap);
extern struct GameData *func_020120F4(const struct FieldSystem *fieldSystem);
extern void *func_0201296C(const struct GameData *gameData);
extern void *func_02012EBC(struct GameData *gameData);
extern void *func_0200BE48(void *sys);
extern void func_0207D63C(u32 reg, int plane1, int plane2, int ev1, int ev2);
extern void func_0203D34C(u32, u32);
extern void func_02030EAC(struct Task *task);
extern void func_02024ABC(void);
extern struct PlayerAvatar *func_020120F8(const struct FieldSystem *fieldSystem);
extern const Vec3Fx *func_02012AA0(const struct PlayerAvatar *player);
extern u32 func_02012974(const struct GameData *gameData);
extern int func_02159C48(int mapId, int x, int z);
extern int func_02159BD4(int mapId, int x, int z);
extern u32 func_02013E7C(u32 zoneId);
extern int func_02013D74(u32 zoneId);
extern int func_02006148(u32 se);
extern void func_0200616C(u32 se, int handle);
extern void GFL_USE_SetSeSlotParams(int handle, u32 volume, u32 pitch, u32 pan);
extern int func_02006224(u32 handle);
extern void func_020061E4(u32 se);
extern void func_021F0C44(DowsingWork *work);
extern void func_02030D28(struct TaskSys *taskSys);
extern u32 PALANM_GetFadeRequestBits(const struct PalAnm *palAnm);
extern int PALANM_RequestFade(struct PalAnm *palAnm, u16 slotMask, u16 paletteMask, s16 wait, u8 startLevel, u8 endLevel, u16 color, struct TaskSys *taskSys);
extern void CLACT_StartActorAnim(struct ClactActor *actor);
extern void CLACT_StopActorAnim(struct ClactActor *actor);
extern void func_0204B3DC(struct ClactActor *actor, u32 visible);
extern void func_0204B404(struct ClactActor *actor, const ScreenPos *pos, u32 which);
extern void func_0204B878(struct ClactActor *actor, u16 anim);
extern void func_0204B92C(struct ClactActor *actor, u32 enable);
extern void CLACT_SetActorAnimFrame(struct ClactActor *actor, u32 frame);
extern void PALANM_TransferPalettes(struct PalAnm *palAnm);
extern void func_02040588(unsigned char bgId, unsigned char visible);
extern void func_0203FCA0(unsigned int bgId, const struct BgTemplate *bgTemplate, unsigned int bgType);
extern void func_020414AC(unsigned char bgId);
extern void func_02040618(unsigned char bgId, unsigned attr, unsigned value);
extern struct ClactUnit *func_0204B100(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct ClactUnit *unit);
extern void func_02043598(unsigned, unsigned);
extern unsigned int func_0204B1CC(struct ClactUnit *unit);
extern void func_020403F4(u32 bgId);
extern void *func_020490F4(unsigned int arcId, unsigned int heapId);
extern void func_02049BDC(void *archive, u32 fileId, u32 bgId, u32 offset, u32 size, u32 palSize, u16 heapId);
extern u32 func_02049740(void *archive, u32 fileId, u32 bgId, u32 offset, u32 size, u16 heapId);
extern u32 func_02049990(void *archive, u32 fileId, u32 bgId, u32 offset, u32 charRegion, u32 x, u32 y, u16 heapId);
extern void func_02049238(void *archive);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(unsigned bgId);
extern void func_0203FB44(u32 bgId, u32 offset, u32 size);
extern s32 func_0204AC18(void *archive, u32 fileId, u32 slotCount, u32 offset, u16 e, u16 f, u16 heapId);
extern s32 func_0204A6C8(void *archive, u32 fileId, u32 compressed, u32 mode, u16 heapId);
extern s32 func_0204AF28(void *archive, u32 cellFileId, u32 animFileId, u32 heapId);
extern struct ClactActor *func_0204B294(struct ClactUnit *unit, s32 charRes, s32 palRes, s32 cellRes, const ClactSetup *setup, unsigned short mode, unsigned short heapId);
extern void func_0204B688(struct ClactActor *actor, u32 value);
extern void func_0204B3B4(struct ClactActor *actor);
extern void func_0204AFD8(s32 cellRes);
extern void func_0204A8D4(s32 charRes);
extern void func_0204ADA4(s32 palRes);
extern void func_02024A20(u8 a0, u8 a1, struct GameData *gameData, u16 heapId);
extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern void func_02049B68(void *archive, u32 fileId, u32 bgId, u32 offset, u32 size, u16 heapId);
extern void *func_02049EF4(void *archive, u32 fileId, u32 compressed, void **outData, u16 heapId);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_0204B954(struct ClactActor *actor, u32 value);
extern int func_02024DCC(void);
extern u32 func_02035D20(u32 *outX, u32 *outY);
extern void func_020355D8(u8 touchMode);
extern u32 func_020362DC(void);
extern u32 func_0204B98C(struct ClactActor *actor);
extern int func_021A0F30(FieldSubscreen *subscreen, u32 mode);
extern unsigned func_02030CB0(unsigned);
extern struct TaskSys *func_02030CBC(u32 capacity, void *mem);
extern struct PalAnm *func_02021518(u32 heapId);
extern void PALANM_SetAutoTransfer(struct PalAnm *palAnm, int enable);
extern void func_0202155C(struct PalAnm *palAnm, u32 slot, u32 size, u32 heapId);
extern void func_020216D4(struct PalAnm *palAnm, u32 slot, u32 offset, u32 size);
extern void func_020215A0(struct PalAnm *palAnm, u32 slot);
extern u32 func_02021540(struct PalAnm *palAnm);
extern void func_02030DA4(struct TaskSys *taskSys);

DowsingSearch *func_021EFEC0(u32 heapId, void *eventFlags, void *eventData);
void func_021EFEE4(DowsingSearch *search);
int func_021EFEEC(DowsingSearch *search, DowsingTarget *target);
void func_021EFF40(DowsingSearch *search);
int func_021EFF48(DowsingSearch *search, DowsingTarget *out, int mode);
DowsingWork *func_021F000C(u32 heapId, u32 ownerHeapId, FieldSubscreen *subscreen, void *fieldMap);
void func_021F0124(DowsingWork *work);
void func_021F0174(DowsingWork *work, int isOn);
void func_021F05A4(DowsingWork *work, int draw);
void func_021F0674(int taskId, DowsingWork *work);
void func_021F06AC(DowsingWork *work);
void func_021F0738(DowsingWork *work);
void func_021F0760(DowsingWork *work);
void func_021F07DC(DowsingWork *work);
void func_021F07F4(DowsingWork *work);
void func_021F08EC(DowsingWork *work);
void func_021F0924(DowsingWork *work);
void func_021F0A90(DowsingWork *work);
void func_021F0AC4(DowsingWork *work);
void func_021F0B74(DowsingWork *work);
void func_021F0C0C(DowsingWork *work);
extern const char d_021F0E60[];
extern const DowsingLevelEntry d_021F0DC8[];
extern DowsingBgSetup d_021F0DF0[];
extern const DowsingPartIds d_021F0DBC[];

DowsingSearch *func_021EFEC0(u32 heapId, void *eventFlags, void *eventData)
{
    DowsingSearch *search;
    search = func_02030734(heapId, sizeof(DowsingSearch), 1, d_021F0E60, 0x8d);
    search->eventFlags = eventFlags;
    search->itemIndex = 0;
    search->eventData = eventData;
    search->eventIndex = 0;
    return search;
}

void func_021EFEE4(DowsingSearch *search)
{
    func_020307B0(search);
}

/* Is the target still there: item not picked up yet, object still on the map. */
int func_021EFEEC(DowsingSearch *search, DowsingTarget *target)
{
    int available;
    if (target->kind == DOWSING_TARGET_HIDDEN_ITEM) {
        const DowsingHiddenItem *item = target->item;
        return func_020142E8(search->eventFlags, (u16)(item->flagIndex + DOWSING_HIDDEN_ITEM_FLAG_BASE)) == 0;
    }
    if (target->kind == DOWSING_TARGET_MAP_EVENT) {
        const DowsingMapEvent *event = target->event;
        available = 0;
        if (func_021CFAC0(search->eventData, (unsigned short)event->zoneId, event->x, event->y, event->z) != 0xFF)
            available = 1;
        return available;
    }
    return 0;
}

void func_021EFF40(DowsingSearch *search)
{
    search->itemIndex = 0;
    search->eventIndex = 0;
}

/*
 * Moves the cursor to the next available target of the kinds that mode
 * allows (0 both, 1 hidden items, 2 map events). Returns 1 and fills out,
 * or returns 0 with out->kind cleared when the end is reached.
 */
int func_021EFF48(DowsingSearch *search, DowsingTarget *out, int mode)
{
    u16 itemCount;
    unsigned eventIndex;
    DowsingTarget candidate;
    const DowsingHiddenItem *items;
    const DowsingMapEvent *event;
    int found;

    found = 0;
    items = func_0216476C(&itemCount);
    eventIndex = search->eventIndex;
    if (mode == 0 || mode == 1) {
        while (search->itemIndex < itemCount) {
            candidate.kind = DOWSING_TARGET_HIDDEN_ITEM;
            candidate.item = items + search->itemIndex;
            if (func_021EFEEC(search, &candidate)) {
                out->kind = candidate.kind;
                out->item = candidate.item;
                found = 1;
            }
            search->itemIndex++;
            if (found)
                return 1;
        }
    }
    if (mode == 0 || mode == 2) {
        event = func_021CFB68(search->eventData, &eventIndex);
        search->eventIndex = eventIndex;
        while (event != 0) {
            candidate.event = event;
            candidate.kind = DOWSING_TARGET_MAP_EVENT;
            if (func_021EFEEC(search, &candidate)) {
                out->kind = candidate.kind;
                out->event = candidate.event;
                found = 1;
            }
            if (found)
                return 1;
            event = func_021CFB68(search->eventData, &eventIndex);
            search->eventIndex = eventIndex;
        }
    }
    out->kind = DOWSING_TARGET_NONE;
    return 0;
}

DowsingWork *func_021F000C(u32 heapId, u32 ownerHeapId, FieldSubscreen *subscreen, void *fieldMap)
{
    DowsingWork *work;
    u32 size;
    struct GameData *gameData;
    void *eventFlags;

    work = func_02030734(heapId, sizeof(DowsingWork), 1, d_021F0E60, 0x272);
    work->heapId = heapId;
    work->ownerHeapId = ownerHeapId;
    work->subscreen = subscreen;
    work->fieldMap = fieldMap;
    func_021F06AC(work);
    func_021F0760(work);
    func_021F07F4(work);
    func_021F0924(work);
    work->levelGrid = func_0204A298(DOWSING_ARC_ID, 0xD, 0, work->heapId, &size);
    work->task = func_020056A0(func_021F0674, work, 1);
    work->tick = 0;
    work->isOn = 1;
    func_021F0B74(work);
    work->prevLevel = 10;
    work->level = DOWSING_LEVEL_NONE;
    work->shownLevel = 10;
    work->prevTarget.kind = 0;
    work->target.kind = 0;
    work->gridX = 0;
    work->gridY = 0;
    work->gridZ = 0;
    work->hasSearched = 0;
    work->seStarted = 0;
    work->restartFoundAnim = 0;
    func_021F05A4(work, 1);
    work->needReset = 1;
    work->needFullScan = 1;
    gameData = func_020120F4(func_02188C80(work->fieldMap));
    eventFlags = func_0201296C(gameData);
    work->search = func_021EFEC0(work->heapId, eventFlags, func_0200BE48(func_02012EBC(gameData)));
    func_0207D63C((u32)&reg_GXS_DB_BLDCNT, 0x10, 0x18, 1, 7);
    func_0203D34C(0, work->heapId);
    return work;
}

void func_021F0124(DowsingWork *work)
{
    reg_GXS_DB_BLDCNT = 0;
    func_021EFEE4(work->search);
    func_021F0C0C(work);
    func_02030EAC(work->task);
    func_020307B0(work->levelGrid);
    func_021F0A90(work);
    func_021F08EC(work);
    func_021F07DC(work);
    func_021F0738(work);
    func_020307B0(work);
}

/*
 * Per-frame update while the screen runs. When the machine is on it finds
 * the nearest target within the 32 x 24 window around the player, reads the
 * level of that cell and plays the proximity sounds.
 */
void func_021F0174(DowsingWork *work, int isOn)
{
    DowsingTarget scan[2]; /* SCAN_BEST, SCAN_CURRENT */
    int playLevelSound;
    int levelChanged;
    int prevX;
    u32 mapId;
    struct FieldSystem *fieldSystem;
    int gridX, gridY, gridZ;
    int zoneId;
    int zoneFlag;
    u32 scanCount;
    int minX, maxX, minZ, maxZ;
    int bestDist;
    u16 bestCell;
    const DowsingHiddenItem *item;
    const DowsingMapEvent *event;
    int newX, newZ;
    const Vec3Fx *pos;
    int runScan;
    int startSe;
    u16 targetIndex;
    int x, z;
    int dx, dz;
    u16 cell;
    u32 dist;
    int handle;
    int pan;
    int level;
    u32 kind;

    work->isOn = isOn;
    if (isOn)
        work->fadeRequest = DOWSING_FADE_IN;
    else
        work->fadeRequest = DOWSING_FADE_OUT;
    func_02024ABC();
    if (isOn == 0)
        return;
    work->prevLevel = work->level;
    work->prevTarget.kind = work->target.kind;
    if (work->prevTarget.kind == DOWSING_TARGET_HIDDEN_ITEM)
        work->prevTarget.item = work->target.item;
    else if (work->prevTarget.kind == DOWSING_TARGET_MAP_EVENT)
        work->prevTarget.event = work->target.event;
    fieldSystem = func_02188C80(work->fieldMap);
    pos = func_02012AA0(func_020120F8(fieldSystem));
    gridX = (pos->x >> 4) / 4096;
    gridY = (pos->y >> 4) / 4096;
    gridZ = (pos->z >> 4) / 4096;
    mapId = func_02012974(func_020120F4(fieldSystem));
    zoneId = DOWSING_ZONE_NONE;
    zoneFlag = 0;
    if (func_02159C48((int)mapId, pos->x, pos->z) == 1) {
        zoneId = func_02159BD4((int)mapId, pos->x, pos->z);
        zoneFlag = (int)func_02013E7C((u16)zoneId);
    }
    /* Both branches scan; the flag only records that a scan happened. */
    if (work->hasSearched == 0) {
        work->hasSearched = 1;
        runScan = 1;
    } else {
        runScan = 1;
    }
    if (runScan) {
        minX = gridX - 15;
        maxX = gridX + 17;
        minZ = gridZ - 11;
        maxZ = gridZ + 13;
        bestDist = -1;
        scan[SCAN_BEST].kind = DOWSING_TARGET_NONE;
        if (work->needReset != 0) {
            func_021EFF40(work->search);
            work->needReset = 0;
        }
        if (work->needFullScan != 0) {
            scanCount = DOWSING_SCAN_ALL;
            work->needFullScan = 0;
        } else {
            scanCount = DOWSING_SCAN_PER_UPDATE;
        }
        for (targetIndex = 0; targetIndex < scanCount; targetIndex++) {
            if (targetIndex == 0) {
                if (work->prevTarget.kind != DOWSING_TARGET_NONE) {
                    if (func_021EFEEC(work->search, &work->prevTarget)) {
                        scan[SCAN_CURRENT].kind = work->prevTarget.kind;
                        if (scan[SCAN_CURRENT].kind == DOWSING_TARGET_HIDDEN_ITEM)
                            scan[SCAN_CURRENT].item = work->prevTarget.item;
                        else if (scan[SCAN_CURRENT].kind == DOWSING_TARGET_MAP_EVENT)
                            scan[SCAN_CURRENT].event = work->prevTarget.event;
                    } else {
                        work->needReset = 1;
                        work->needFullScan = 1;
                        break;
                    }
                }
            } else {
                if ((work->needReset = func_021EFF48(work->search, &scan[SCAN_CURRENT], 0) ? 0 : 1) != 0)
                    break;
            }
            if (zoneId == DOWSING_ZONE_NONE)
                continue;
            if (scan[SCAN_CURRENT].kind == DOWSING_TARGET_HIDDEN_ITEM) {
                item = scan[SCAN_CURRENT].item;
                if (zoneId != item->zoneId) {
                    if (item->crossZone == 0)
                        continue;
                    if (zoneFlag == 0)
                        continue;
                    if (func_02013D74(item->zoneId) != 0)
                        continue;
                }
                x = item->x;
                z = item->z;
            } else if (scan[SCAN_CURRENT].kind == DOWSING_TARGET_MAP_EVENT) {
                event = scan[SCAN_CURRENT].event;
                if ((int)func_02013E7C((u16)event->zoneId) == 0)
                    continue;
                if (zoneFlag == 0)
                    continue;
                x = event->x;
                z = event->z;
            }
            if (minX <= x && x < maxX && minZ <= z && z < maxZ) {
                dz = z - gridZ;
                dx = x - gridX;
                cell = (u16)(dx + 15 + (dz + 11) * 32);
                if (work->levelGrid[cell] == DOWSING_LEVEL_NONE)
                    continue;
                dist = dx * dx + dz * dz;
                if (dist < (u32)bestDist) {
                    bestCell = cell;
                    bestDist = dist;
                    scan[SCAN_BEST].kind = scan[SCAN_CURRENT].kind;
                    if (scan[SCAN_CURRENT].kind == DOWSING_TARGET_HIDDEN_ITEM)
                        scan[SCAN_BEST].item = scan[SCAN_CURRENT].item;
                    else if (scan[SCAN_CURRENT].kind == DOWSING_TARGET_MAP_EVENT)
                        scan[SCAN_BEST].event = scan[SCAN_CURRENT].event;
                }
            }
        }
        kind = scan[SCAN_BEST].kind;
        work->target.kind = kind;
        if (kind != DOWSING_TARGET_NONE) {
            work->level = work->levelGrid[bestCell];
            if (kind == DOWSING_TARGET_HIDDEN_ITEM)
                work->target.item = scan[SCAN_BEST].item;
            else if (kind == DOWSING_TARGET_MAP_EVENT)
                work->target.event = scan[SCAN_BEST].event;
        } else {
            work->level = DOWSING_LEVEL_NONE;
        }
    }
    playLevelSound = 1;
    if (work->level == DOWSING_LEVEL_ON_TARGET) {
        startSe = 0;
        if (work->seStarted == 0) {
            startSe = 1;
            work->seStarted = 1;
        } else if (work->seTimer == 6) {
            if (func_02006224(work->seHandle) == 0)
                work->seTimer--;
        } else if (work->seTimer == 0) {
            startSe = 1;
        } else {
            work->seTimer--;
        }
        if (startSe) {
            work->seHandle = func_02006148(DOWSING_SE_PROXIMITY);
            func_0200616C(DOWSING_SE_PROXIMITY, work->seHandle);
            GFL_USE_SetSeSlotParams(work->seHandle, -1, 0x180, -1);
            work->seTimer = 6;
            work->restartFoundAnim = 1;
        }
        playLevelSound = 0;
    } else {
        work->seStarted = 0;
    }
    if (playLevelSound && (level = work->level) != DOWSING_LEVEL_ON_TARGET && work->target.kind != DOWSING_TARGET_NONE) {
        levelChanged = 0;
        if (work->prevTarget.kind == DOWSING_TARGET_HIDDEN_ITEM) {
            item = work->prevTarget.item;
            prevX = item->x;
            z = item->z;
        } else if (work->prevTarget.kind == DOWSING_TARGET_MAP_EVENT) {
            event = work->prevTarget.event;
            prevX = event->x;
            z = event->z;
        } else {
            levelChanged = 1;
            goto done;
        }
        if (work->target.kind == DOWSING_TARGET_HIDDEN_ITEM) {
            item = work->target.item;
            newX = item->x;
            newZ = item->z;
        } else if (work->target.kind == DOWSING_TARGET_MAP_EVENT) {
            event = work->target.event;
            newX = event->x;
            newZ = event->z;
        }
        if ((prevX != newX || z != newZ) && work->prevLevel != level)
            levelChanged = 1;
    done:
        if (levelChanged) {
            handle = func_02006148(DOWSING_SE_PROXIMITY);
            pan = ((int)d_021F0DC8[work->level].pan - 8) * 16;
            if (pan < -127)
                pan = -127;
            else if (pan > 127)
                pan = 127;
            func_0200616C(DOWSING_SE_PROXIMITY, handle);
            GFL_USE_SetSeSlotParams(handle, -1, -1, pan);
            playLevelSound = 0;
        }
    }
    if (playLevelSound && work->prevLevel != work->level)
        func_020061E4(DOWSING_SE_LEVEL_CHANGE);
    work->gridX = gridX;
    work->gridY = gridY;
    work->gridZ = gridZ;
    func_021F0AC4(work);
}

/* Redraws the sprites after the level changed and runs the fade. */
void func_021F05A4(DowsingWork *work, int draw)
{
    ScreenPos pos;

    func_021F0C44(work);
    if (draw == 0)
        return;
    if (work->shownLevel != work->level) {
        func_0204B3DC(work->parts[DOWSING_PART_DIRECTION].actor,
                      (work->level == DOWSING_LEVEL_ON_TARGET || work->level == DOWSING_LEVEL_NONE) ? 0 : 1);
        func_0204B3DC(work->parts[DOWSING_PART_FOUND_MARK].actor, work->level == DOWSING_LEVEL_ON_TARGET);
        pos.x = d_021F0DC8[work->level].directionX;
        pos.y = d_021F0DC8[work->level].directionY;
        func_0204B404(work->parts[DOWSING_PART_DIRECTION].actor, &pos, 1);
        func_0204B878(work->parts[DOWSING_PART_LEFT_GAUGE].actor, d_021F0DC8[work->level].leftAnim);
        func_0204B878(work->parts[DOWSING_PART_RIGHT_GAUGE].actor, d_021F0DC8[work->level].rightAnim);
        func_0204B878(work->parts[DOWSING_PART_DIRECTION].actor, d_021F0DC8[work->level].directionAnim);
        work->shownLevel = work->level;
    }
    if (work->level == DOWSING_LEVEL_ON_TARGET && work->restartFoundAnim != 0) {
        func_0204B878(work->parts[DOWSING_PART_FOUND_MARK].actor, 0);
        func_0204B92C(work->parts[DOWSING_PART_FOUND_MARK].actor, 1);
        CLACT_SetActorAnimFrame(work->parts[DOWSING_PART_FOUND_MARK].actor, 0);
        work->restartFoundAnim = 0;
    }
}

/* Task that transfers the palettes every frame and ticks the counter. */
void func_021F0674(int taskId, DowsingWork *work)
{
    PALANM_TransferPalettes(work->palAnm);
    if (work->isOn != 0) {
        if (work->tick >= 4)
            work->tick = 0;
        work->tick++;
    }
}

/* Hides BG 4 to 7, sets up the two screen layers and the actor unit. */
void func_021F06AC(DowsingWork *work)
{
    int i;
    unsigned bgId;
    DowsingBgSetup *setup;
    unsigned j;
    for (i = 4; i <= 7; i++)
        func_02040588((unsigned char)i, (unsigned char)0);
    for (j = 0; j < 2; j++) {
        setup = &d_021F0DF0[j];
        bgId = setup->bgId;
        func_0203FCA0((unsigned char)bgId, (const struct BgTemplate *)setup->bgTemplate, (unsigned char)setup->bgType);
        func_020414AC(bgId);
        func_02040588((unsigned char)bgId, (unsigned char)setup->visible);
        func_02040618(bgId, 0, 0);
        func_02040618(bgId, 3, 0);
    }
    work->clactUnit = func_0204B100(8, 0, work->heapId);
    CLACT_SetUnitDefaultRenderer(work->clactUnit);
    func_02043598(0x10, 1);
}

void func_021F0738(DowsingWork *work)
{
    unsigned i;
    func_0204B1CC(work->clactUnit);
    for (i = 0; i < 2; i++)
        func_020403F4((unsigned char)d_021F0DF0[i].bgId);
}

/* Loads palette, tiles and screen of BG 7 from the archive. */
void func_021F0760(DowsingWork *work)
{
    unsigned heapId = work->ownerHeapId;
    void *archive = func_020490F4(DOWSING_ARC_ID, heapId);
    unsigned charRegion;
    func_02049BDC(archive, 0, 4, 0, 0, 0x40, heapId);
    charRegion = func_02049740(archive, 2, 7, 0, 0, heapId);
    func_02049990(archive, 7, 7, 0, (unsigned short)charRegion, 0, 0, heapId);
    func_02049238(archive);
    func_020413B0(7, 0, 0, 0x20, 0x18, 1);
    func_02041B6C(7);
    work->bgCharRegion7 = charRegion;
}

void func_021F07DC(DowsingWork *work)
{
    unsigned region = work->bgCharRegion7;
    func_0203FB44(7, (unsigned short)region, (unsigned short)(region >> 16));
}

/*
 * Creates the four sprite parts. The right gauge (part 1) shares the
 * resources of the left gauge.
 *
 * note:     the four `strh #0` at the loop top are `ClactSetup setup = {0};`
 *           declared in the loop body (field-by-field zeroing ends in two
 *           strb), and `pos` lives in its own block after the loop so it
 *           takes the lower slot (sp+0x10) below `setup` (sp+0x14).
 */
void func_021F07F4(DowsingWork *work)
{
    void *archive;
    u8 i;

    archive = func_020490F4(DOWSING_ARC_ID, work->ownerHeapId);
    work->partsPalRes = func_0204AC18(archive, 1, 1, 0, 0, 1, work->heapId);
    for (i = 0; i < DOWSING_PART_COUNT; i++) {
        ClactSetup setup = {0};
        if (i == DOWSING_PART_RIGHT_GAUGE) {
            work->parts[i].charRes = work->parts[DOWSING_PART_LEFT_GAUGE].charRes;
            work->parts[i].cellRes = work->parts[DOWSING_PART_LEFT_GAUGE].cellRes;
        } else {
            work->parts[i].charRes = func_0204A6C8(archive, d_021F0DBC[i].charId, 0, 1, work->heapId);
            work->parts[i].cellRes = func_0204AF28(archive, d_021F0DBC[i].cellId, d_021F0DBC[i].animId, work->heapId);
        }
        setup.priority = i;
        work->parts[i].actor = func_0204B294(work->clactUnit, work->parts[i].charRes, work->partsPalRes, work->parts[i].cellRes, &setup, 1, work->heapId);
        func_0204B92C(work->parts[i].actor, 1);
        func_0204B688(work->parts[i].actor, 1);
    }
    func_02049238(archive);
    {
        ScreenPos pos;

        pos.x = 0x50;
        pos.y = 0x60;
        func_0204B404(work->parts[DOWSING_PART_LEFT_GAUGE].actor, &pos, 1);
        pos.x = 0xB0;
        pos.y = 0x60;
        func_0204B404(work->parts[DOWSING_PART_RIGHT_GAUGE].actor, &pos, 1);
        pos.x = 0x80;
        pos.y = 0x60;
        func_0204B404(work->parts[DOWSING_PART_FOUND_MARK].actor, &pos, 1);
    }
}

void func_021F08EC(DowsingWork *work)
{
    unsigned char i;
    for (i = 0; i < DOWSING_PART_COUNT; i++) {
        func_0204B3B4(work->parts[i].actor);
        if (i != DOWSING_PART_RIGHT_GAUGE) {
            func_0204AFD8(work->parts[i].cellRes);
            func_0204A8D4(work->parts[i].charRes);
        }
    }
    func_0204ADA4(work->partsPalRes);
}

/*
 * Builds the close button (BG 4 panel and one actor).
 *
 * note:     the four `strh #0` after func_02024A20 are `ClactSetup setup = {0};`
 *           opening an inner block there; declared at the top they land
 *           before the first call.
 */
void func_021F0924(DowsingWork *work)
{
    ScreenData *screen;
    u32 ownerHeapId;

    ownerHeapId = work->ownerHeapId;
    func_02024A20(4, 3, func_020120F4(func_02188C80(work->fieldMap)), work->heapId);
    {
        ClactSetup setup = {0};
        void *screenFile;
        void *archive;
        u16 *tiles;
        u16 i;
        u16 base;

        archive = func_020490F4(func_020275E4(), ownerHeapId);
        func_02049B68(archive, func_02027624(), 4, 0x40, 0x20, ownerHeapId);
        work->bgCharRegion4 = func_02049740(archive, func_02027628(), 4, 0, 0, ownerHeapId);
        screenFile = func_02049EF4(archive, func_0202762C(), 0, (void **)&screen, ownerHeapId);
        base = work->bgCharRegion4;
        tiles = screen->tiles;
        for (i = 0; i < 0x300; i++) {
            tiles[i] &= 0xFFF;
            tiles[i] = (base + tiles[i]) | 0x2000;
        }
        func_020410D0(4, 0, 0x15, 0x20, 3, (u32)screen->tiles, 0, 0x15, 0x20, 0x18);
        func_02041B6C(4);
        func_020307B0(screenFile);
        work->buttonPalRes = func_0204AC18(archive, func_02027614(), 1, 0x20, 0, 3, work->heapId);
        work->buttonCharRes = func_0204A6C8(archive, func_02027618(), 0, 1, work->heapId);
        work->buttonCellRes = func_0204AF28(archive, func_0202761C(0), func_02027620(0), work->heapId);
        setup.x = 0xE8;
        setup.y = 0xA8;
        work->buttonActor = func_0204B294(work->clactUnit, work->buttonCharRes, work->buttonPalRes, work->buttonCellRes, &setup, 1, work->heapId);
        func_0204B92C(work->buttonActor, 1);
        func_0204B954(work->buttonActor, 0x2000);
        func_0204B878(work->buttonActor, 0);
        func_02049238(archive);
        work->buttonState = DOWSING_BUTTON_IDLE;
    }
}

void func_021F0A90(DowsingWork *work)
{
    unsigned region;
    func_0204B3B4(work->buttonActor);
    func_0204AFD8(work->buttonCellRes);
    func_0204A8D4(work->buttonCharRes);
    func_0204ADA4(work->buttonPalRes);
    region = work->bgCharRegion4;
    func_0203FB44(4, (unsigned short)region, (unsigned short)(region >> 16));
    func_02024DCC();
}

/* Close button: touch box or key press, press animation, then the mode change. */
void func_021F0AC4(DowsingWork *work)
{
    unsigned touchX;
    unsigned touchY;
    int pressed;

    switch (work->buttonState) {
    case DOWSING_BUTTON_IDLE:
        pressed = 0;
        if (func_02035D20(&touchX, &touchY) != 0) {
            if (touchX >= 0xE8 && touchX < 0x100 && touchY >= 0xA8 && touchY < 0xC0) {
                func_020355D8(1);
                pressed = 1;
            }
        }
        if (pressed == 0) {
            if (func_020362DC() & DOWSING_KEY_CLOSE) {
                func_020355D8(0);
                pressed = 1;
            }
        }
        if (pressed != 0) {
            work->buttonState = DOWSING_BUTTON_PRESSED;
            func_0204B878(work->buttonActor, 8);
            func_020061E4(DOWSING_SE_CLOSE);
            return;
        }
        break;
    case DOWSING_BUTTON_PRESSED:
        if (func_0204B98C(work->buttonActor) == 0) {
            work->buttonState = DOWSING_BUTTON_RELEASED;
            func_0204B878(work->buttonActor, 0);
            return;
        }
        break;
    case DOWSING_BUTTON_RELEASED:
        func_021A0F30(work->subscreen, 0);
        work->buttonState = DOWSING_BUTTON_CLOSE_REQUESTED;
        break;
    case DOWSING_BUTTON_CLOSE_REQUESTED:
        break;
    }
}

/*
 * note:     func_02030CBC takes (n, mem) (GFL_USE_InitSystem): the 0xB8 result
 *           left in r1 before `blx func_02030CBC` is its second argument.
 */
void func_021F0B74(DowsingWork *work)
{
    work->fadeTaskMem = func_02030734(work->heapId, func_02030CB0(2), 1, d_021F0E60, 0x6DF);
    work->fadeTaskSys = func_02030CBC(2, work->fadeTaskMem);
    work->palAnm = func_02021518(work->heapId);
    PALANM_SetAutoTransfer(work->palAnm, 1);
    func_0202155C(work->palAnm, 1, 0x60, work->heapId);
    func_0202155C(work->palAnm, 3, 0x80, work->heapId);
    func_020216D4(work->palAnm, 1, 0, 0x60);
    func_020216D4(work->palAnm, 3, 0, 0x80);
    work->fadeRequest = DOWSING_FADE_NONE;
    work->fadeState = 0;
}

void func_021F0C0C(DowsingWork *work)
{
    func_020215A0(work->palAnm, 1);
    func_020215A0(work->palAnm, 3);
    func_02021540(work->palAnm);
    func_02030DA4(work->fadeTaskSys);
    func_020307B0(work->fadeTaskMem);
}

/*
 * Runs the fade task system and, once the previous fade is done, applies the
 * requested fade of the two palette slots: in shows the sprites and starts
 * their animations, out darkens them and stops the animations.
 */
void func_021F0C44(DowsingWork *work)
{
    u16 paletteMask;
    u8 i;

    func_02030D28(work->fadeTaskSys);
    if (work->fadeRequest == DOWSING_FADE_NONE || PALANM_GetFadeRequestBits(work->palAnm) != 0)
        return;
    switch (work->fadeRequest) {
    case DOWSING_FADE_IN:
        if (work->fadeState != 0) {
            paletteMask = 0;
            for (i = 0; i < 3; i++)
                paletteMask |= (u16)(1 << i);
            PALANM_RequestFade(work->palAnm, 2, paletteMask, 0, 0, 0, 0, work->fadeTaskSys);
            paletteMask = 0;
            for (i = 0; i < 4; i++)
                paletteMask |= (u16)(1 << i);
            PALANM_RequestFade(work->palAnm, 8, paletteMask, 0, 0, 0, 0, work->fadeTaskSys);
            work->fadeState = 0;
            for (i = 0; i < DOWSING_PART_COUNT; i++)
                CLACT_StartActorAnim(work->parts[i].actor);
        }
        break;
    case DOWSING_FADE_OUT:
        if (work->fadeState != 1) {
            paletteMask = 0;
            for (i = 0; i < 3; i++)
                paletteMask |= (u16)(1 << i);
            PALANM_RequestFade(work->palAnm, 2, paletteMask, 0, 8, 8, 0, work->fadeTaskSys);
            paletteMask = 0;
            for (i = 0; i < 4; i++)
                paletteMask |= (u16)(1 << i);
            PALANM_RequestFade(work->palAnm, 8, paletteMask, 0, 8, 8, 0, work->fadeTaskSys);
            work->fadeState = 1;
            for (i = 0; i < DOWSING_PART_COUNT; i++)
                CLACT_StopActorAnim(work->parts[i].actor);
        }
        break;
    }
    work->fadeRequest = DOWSING_FADE_NONE;
}
