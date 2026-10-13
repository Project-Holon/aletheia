/*
 * file:     fld_faceup.c
 * unit:     yes
 * function: FLD_FACEUP_Create, FLD_FACEUP_OpenEventMain, FLD_FACEUP_SetupBg, FLD_FACEUP_StartClose, FLD_FACEUP_Delete, FLD_FACEUP_ResumeLipSync, FLD_FACEUP_CloseEventMain, FLD_FACEUP_Release, FLD_FACEUP_SaveBgPriorities, FLD_FACEUP_SaveVisiblePlanes, FLD_FACEUP_RestoreBgPriorities, FLD_FACEUP_RestoreVisiblePlanes, FLD_FACEUP_StepFadeIn, FLD_FACEUP_UpdateTaskMain, FLD_FACEUP_VBlankUpload, FLD_FACEUP_StepAnim
 * address:  0x021F5260
 * region:   ov082
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   func_02030734  0x02030734  arm
 *   FIELDMAP_GetFaceUpWorkPtr  0x02189A60  thumb  ov021
 *   FLD_FACEUP_InitAnim  0x021F58C0  thumb  ov082
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   CONFIG_GetTextSpeed  0x02008374  thumb
 *   func_020122C0  0x020122C0  thumb
 *   FIELDMAP_GetTcblSys  0x02188D30  thumb  ov021
 *   func_02030DA8  0x02030DA8  arm
 *   func_020056A0  0x020056A0  thumb
 *   gFldFaceupFileName     0x021F5920  data  a1
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   func_0207D63C  0x0207D63C  arm
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_ReleaseSysFrame  0x02190378  thumb  ov021
 *   FIELD_MSGBG_RequestSysFrame  0x021904D0  thumb  ov021
 *   func_020403F4  0x020403F4  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   func_02062A4C  0x02062A4C  arm
 *   func_02062B30  0x02062B30  arm
 *   func_02062A98  0x02062A98  arm
 *   func_02040B1C  0x02040B1C  arm
 *   func_020409E0  0x020409E0  arm
 *   func_02040E78  0x02040E78  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0204047C  0x0204047C  arm
 *   func_02040588  0x02040588  arm
 *   gFldFaceupBgTemplate     0x021F58F4  data  a4
 *   func_02030EAC  0x02030EAC  arm
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb  ov021
 *   func_020414AC  0x020414AC  arm
 *   FIELD_PLACE_NAME_RestoreWindow  0x021BC5D4  thumb  ov021
 *   func_020416D4 0x020416D4 arm
 *   BG_SYS_GetMainVisiblePlanes  0x02043658  arm
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   SCRIPT_WORK_CheckFlag  0x02159190  thumb  ov010
 *   SCRCMD_WORK_GetMsgWindow  0x0215A61C  thumb  ov010
 *   FIELD_MSGBG_GetPlainWinStreamState  0x021917C0  thumb  ov021
 *   func_020056EC  0x020056EC  thumb
 *   gFldFaceupMouthFrames     0x021F58D0  data  a4
 *   gFldFaceupBlinkFrames     0x021F58E0  data  a4
 */
#include "fld_faceup_types.h"

#define reg_G2_BG3CNT  (*(volatile u16 *)0x0400000E)
#define reg_G2_BLDCNT  (*(volatile u16 *)0x04000050)

#define FACEUP_HEAP_ID      0x50
#define FACEUP_BG_HEAP_ID   0x8015
#define FACEUP_ARC_ID       0xbb

struct GameSystem;
struct GameEvent;
struct FieldMap;
struct FieldMsgBg;
struct FieldPlaceName;
struct FieldMsgWindow;
struct GameData;
struct SaveControl;
struct Config;
struct TcbSys;

typedef struct FaceupBgTemplate {
    u32 word[8];
} FaceupBgTemplate;

/* Unpacked character, screen and palette resources (NCGR, NSCR, NCLR). */
typedef struct UnpackedCharData {
    u8 pad00[0x10];
    u32 size;
    void *data;
} UnpackedCharData;

typedef struct UnpackedScreenData {
    u8 pad00[8];
    u32 size;
    u8 data[4];
} UnpackedScreenData;

typedef struct UnpackedPaletteData {
    u8 pad00[0xc];
    void *data;
} UnpackedPaletteData;

typedef enum { GX_BG_SCRSIZE_TEXT_256x256 = 0 } GXBGScrSizeText;

typedef enum { GX_BG_COLORMODE_16 = 0, GX_BG_COLORMODE_256 = 1 } GXBGColorMode;

typedef enum { GX_BG_SCRBASE_0x0000 = 0, GX_BG_SCRBASE_0x1000 = 2 } GXBGScrBase;

typedef enum { GX_BG_CHARBASE_0x00000 = 0, GX_BG_CHARBASE_0x04000 = 1 } GXBGCharBase;

extern struct FieldMap *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern FaceupWork **FIELDMAP_GetFaceUpWorkPtr(struct FieldMap *fieldMap);
extern void FLD_FACEUP_InitAnim(FaceupAnim *anim);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern struct Config *func_0200873C(struct SaveControl *saveControl);
extern unsigned int CONFIG_GetTextSpeed(struct Config *config);
extern struct GameEvent *func_020122C0(const struct GameSystem *gameSystem, struct GameEvent *parent,
                                       int (*proc)(struct GameEvent *event, int *seq), u32 size);
extern struct TcbSys *FIELDMAP_GetTcblSys(struct FieldMap *fieldMap);
extern void *func_02030DA8(struct TcbSys *tcbSys, void (*proc)(void *tcb, FaceupWork *work), FaceupWork *work, int priority);
extern void *func_020056A0(void (*proc)(void *tcb, FaceupWork *work), FaceupWork *work, int priority);
extern struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event);
extern void FADE_Start(u32 screens, s32 start, s32 end, s32 speed);
extern int FADE_IsActive(void);
extern void func_0207D63C(volatile void *reg, int plane1, int plane2, int ev1, int ev2);
extern struct FieldMsgBg *FIELDMAP_GetMsgBg(struct FieldMap *fieldMap);
extern int FIELD_MSGBG_ReleaseSysFrame(struct FieldMsgBg *msgBg);
extern void FIELD_MSGBG_RequestSysFrame(struct FieldMsgBg *msgBg);
extern void func_020403F4(u32 bgId);
extern void func_0203FCA0(u32 bgId, const FaceupBgTemplate *bgTemplate, u32 type);
extern void *ARC_TOOL_LoadMember(u32 archiveId, u32 member, u32 heapId);
extern s32 func_02062A4C(void *file, UnpackedCharData **out);
extern int func_02062B30(void *file, UnpackedScreenData **out);
extern s32 func_02062A98(void *file, UnpackedPaletteData **out);
extern void func_02040B1C(int bgId, const void *src, u32 size, u32 tileOffset);
extern void func_020409E0(u32 bgId, const void *src, u32 size, u32 mapOffset);
extern void func_02040E78(u32 bgId, void *src, u32 size, u32 offset);
extern u32 func_020307B0(void *work);
extern void func_0204047C(int bgId, unsigned short priority);
extern void func_02040588(unsigned char bgId, unsigned char enable);
extern void func_02030EAC(void *tcb);
extern struct FieldPlaceName *FIELDMAP_GetPlaceName(struct FieldMap *fieldMap);
extern void func_020414AC(int bgId);
extern void FIELD_PLACE_NAME_RestoreWindow(struct FieldPlaceName *placeName);
extern u8 func_020416D4(u32 bgId);
u32 BG_SYS_GetMainVisiblePlanes(void);
void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern int SCRIPT_WORK_CheckFlag(int flagId);
extern struct FieldMsgWindow *SCRCMD_WORK_GetMsgWindow(void *scrcmdWork);
extern int FIELD_MSGBG_GetPlainWinStreamState(struct FieldMsgWindow *window);
extern u32 func_020056EC(u32 range);
struct GameEvent *FLD_FACEUP_Create(int faceType, int unusedVariant, int fadeBothScreens, struct GameSystem *gameSystem, void *scrcmdWork);
int FLD_FACEUP_OpenEventMain(struct GameEvent *event, int *seq);
void FLD_FACEUP_SetupBg(FaceupWork *work, struct FieldMap *fieldMap);
struct GameEvent *FLD_FACEUP_StartClose(struct GameSystem *gameSystem);
void FLD_FACEUP_Delete(struct FieldMap *fieldMap);
void FLD_FACEUP_ResumeLipSync(struct FieldMap *fieldMap);
int FLD_FACEUP_CloseEventMain(struct GameEvent *event, int *seq);
void FLD_FACEUP_Release(struct FieldMap *fieldMap, FaceupWork *work);
void FLD_FACEUP_SaveBgPriorities(FaceupWork *work);
void FLD_FACEUP_SaveVisiblePlanes(FaceupWork *work);
void FLD_FACEUP_RestoreBgPriorities(FaceupWork *work);
void FLD_FACEUP_RestoreVisiblePlanes(FaceupWork *work);
int FLD_FACEUP_StepFadeIn(FaceupWork *work);
void FLD_FACEUP_UpdateTaskMain(void *tcb, FaceupWork *work);
void FLD_FACEUP_VBlankUpload(void *tcb, FaceupWork *work);
void FLD_FACEUP_StepAnim(const FaceupAnimFrame *frames, unsigned frameCount, unsigned firstTile, unsigned tileStride, unsigned long tileWidth, FaceupAnim *anim);
extern const char gFldFaceupFileName[];
extern const FaceupBgTemplate gFldFaceupBgTemplate;
extern const FaceupAnimFrame gFldFaceupMouthFrames[];
extern const FaceupAnimFrame gFldFaceupBlinkFrames[];





struct GameEvent *FLD_FACEUP_Create(int faceType, int unusedVariant, int fadeBothScreens, struct GameSystem *gameSystem, void *scrcmdWork)
{
    FaceupWork *work;
    struct FieldMap *fieldMap;
    u32 textSpeed;
    struct GameEvent *event;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    work = func_02030734(FACEUP_HEAP_ID, 0x78, 1, gFldFaceupFileName, 0xa2);
    if (*FIELDMAP_GetFaceUpWorkPtr(fieldMap) != 0)
        return 0;
    *FIELDMAP_GetFaceUpWorkPtr(fieldMap) = work;
    work->faceType = faceType;
    work->scrcmdWork = scrcmdWork;
    work->fadeBothScreens = fadeBothScreens;
    FLD_FACEUP_InitAnim(&work->blink);
    FLD_FACEUP_InitAnim(&work->mouth);
    textSpeed = CONFIG_GetTextSpeed(func_0200873C(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem))));
    if (textSpeed == 0)
        work->mouth.delayReload = 3;
    else if (textSpeed == 1)
        work->mouth.delayReload = 2;
    else
        work->mouth.delayReload = 1;
    work->blink.delayReload = 2;
    event = func_020122C0(gameSystem, 0, FLD_FACEUP_OpenEventMain, 0);
    work->updateTask = func_02030DA8(FIELDMAP_GetTcblSys(fieldMap), FLD_FACEUP_UpdateTaskMain, work, 0);
    work->vblankTask = func_020056A0(FLD_FACEUP_VBlankUpload, work, 1);
    work->lipSyncStopped = 0;
    work->waitingForText = 1;
    return event;
}





int FLD_FACEUP_OpenEventMain(struct GameEvent *event, int *seq)
{
    struct FieldMap *fieldMap;
    FaceupWork *work;

    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    work = *FIELDMAP_GetFaceUpWorkPtr(fieldMap);
    switch (*seq) {
    case 0:
        FADE_Start(1, 0, 0x10, 0);
        (*seq)++;
        break;
    case 1:
        if (FADE_IsActive() == 0) {
            FLD_FACEUP_SetupBg(work, fieldMap);
            FADE_Start(1, 0x10, 0, 0);
            (*seq)++;
        }
        break;
    case 2:
        if (FADE_IsActive() == 0) {
            work->fadeFrame = 0;
            (*seq)++;
        }
        break;
    case 3:
        if (FLD_FACEUP_StepFadeIn(work) != 0)
            return 1;
        break;
    }
    return 0;
}





static inline void G2_SetBG3ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode,
                                        GXBGScrBase screenBase, GXBGCharBase charBase)
{
    reg_G2_BG3CNT = (u16)((reg_G2_BG3CNT & 0x43) | (screenSize << 14) |
                          (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}





void FLD_FACEUP_SetupBg(FaceupWork *work, struct FieldMap *fieldMap)
{
    FaceupBgTemplate bgTemplate;
    UnpackedCharData *faceChar;
    UnpackedScreenData *faceScreen;
    UnpackedPaletteData *facePalette;
    UnpackedCharData *partsChar;
    UnpackedScreenData *partsScreen;
    void *file;
    struct FieldMsgBg *msgBg;
    int faceCharIndex;
    int faceScreenIndex;
    int facePaletteIndex;

    FLD_FACEUP_SaveBgPriorities(work);
    FLD_FACEUP_SaveVisiblePlanes(work);
    work->savedBg3Control.raw = reg_G2_BG3CNT;
    G2_SetBG3ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_256,
                         GX_BG_SCRBASE_0x1000, GX_BG_CHARBASE_0x04000);
    func_0207D63C(&reg_G2_BLDCNT, 8, 4, 0, 16);
    msgBg = FIELDMAP_GetMsgBg(fieldMap);
    if (FIELD_MSGBG_ReleaseSysFrame(msgBg) != 0)
        FIELD_MSGBG_RequestSysFrame(msgBg);
    else
        func_020403F4(2);
    bgTemplate = gFldFaceupBgTemplate;
    func_0203FCA0(2, &bgTemplate, 0);
    if (work->faceType == 0) {
        faceCharIndex = 4;
        faceScreenIndex = 8;
        facePaletteIndex = 0;
    } else if (work->faceType == 1) {
        faceCharIndex = 5;
        faceScreenIndex = 9;
        facePaletteIndex = 1;
    } else {
        faceCharIndex = 6;
        faceScreenIndex = 10;
        facePaletteIndex = 2;
    }
    file = ARC_TOOL_LoadMember(FACEUP_ARC_ID, faceCharIndex, FACEUP_BG_HEAP_ID);
    func_02062A4C(file, &faceChar);
    func_02040B1C(2, faceChar->data, faceChar->size, 0);
    func_020307B0(file);
    file = ARC_TOOL_LoadMember(FACEUP_ARC_ID, faceScreenIndex, FACEUP_BG_HEAP_ID);
    func_02062B30(file, &faceScreen);
    func_020409E0(2, faceScreen->data, faceScreen->size, 0);
    func_020307B0(file);
    file = ARC_TOOL_LoadMember(FACEUP_ARC_ID, facePaletteIndex, FACEUP_BG_HEAP_ID);
    func_02062A98(file, &facePalette);
    func_02040E78(2, facePalette->data, 0x140, 0);
    func_020307B0(file);
    file = ARC_TOOL_LoadMember(FACEUP_ARC_ID, 7, FACEUP_BG_HEAP_ID);
    func_02062A4C(file, &partsChar);
    func_02040B1C(3, partsChar->data, partsChar->size, 0);
    func_020307B0(file);
    file = ARC_TOOL_LoadMember(FACEUP_ARC_ID, 11, FACEUP_BG_HEAP_ID);
    func_02062B30(file, &partsScreen);
    func_020409E0(3, partsScreen->data, partsScreen->size, 0);
    func_020307B0(file);
    func_0204047C(0, 3);
    func_0204047C(1, 0);
    func_0204047C(2, 2);
    func_0204047C(3, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
}




struct GameEvent *FLD_FACEUP_StartClose(struct GameSystem *gameSystem)
{
    struct FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);

    if (*FIELDMAP_GetFaceUpWorkPtr(fieldMap) == 0)
        return 0;
    return func_020122C0(gameSystem, 0, FLD_FACEUP_CloseEventMain, 0);
}




void FLD_FACEUP_Delete(struct FieldMap *fieldMap)
{
    FaceupWork *work = *FIELDMAP_GetFaceUpWorkPtr(fieldMap);

    FLD_FACEUP_Release(fieldMap, work);
}




void FLD_FACEUP_ResumeLipSync(struct FieldMap *fieldMap)
{
    FaceupWork *work = *FIELDMAP_GetFaceUpWorkPtr(fieldMap);

    work->lipSyncStopped = 0;
    work->waitingForText = 1;
}



int FLD_FACEUP_CloseEventMain(struct GameEvent *event, int *seq)
{
    struct FieldMap *fieldMap;
    FaceupWork *work;
    int fadeBothScreens;

    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    work = *FIELDMAP_GetFaceUpWorkPtr(fieldMap);
    switch (*seq) {
    case 0:
        if (work->fadeBothScreens != 0)
            FADE_Start(3, 0, 0x10, -8);
        else
            FADE_Start(1, 0, 0x10, 0);
        (*seq)++;
        break;
    case 1:
        if (FADE_IsActive() != 0)
            break;
        func_02030EAC(work->updateTask);
        (*seq)++;
        break;
    case 2:
        if (work->blink.uploadPending != 0)
            break;
        if (work->mouth.uploadPending != 0)
            break;
        func_02030EAC(work->vblankTask);
        fadeBothScreens = work->fadeBothScreens;
        FLD_FACEUP_Release(fieldMap, work);
        if (fadeBothScreens != 0)
            return 1;
        FADE_Start(1, 0x10, 0, 0);
        (*seq)++;
        break;
    case 3:
        if (FADE_IsActive() == 0)
            return 1;
        break;
    }
    return 0;
}





/*
 * volatile: BG3CNT 0x0400000E read-modify-written by the SDK inline G2_SetBG3ControlText; BLDCNT 0x04000050 store
 */
void FLD_FACEUP_Release(struct FieldMap *fieldMap, FaceupWork *work)
{
    struct FieldPlaceName *placeName = FIELDMAP_GetPlaceName(fieldMap);

    func_020414AC(2);
    G2_SetBG3ControlText(work->savedBg3Control.bits.screenSize, work->savedBg3Control.bits.colorMode,
                         work->savedBg3Control.bits.screenBase, work->savedBg3Control.bits.charBase);
    FIELD_PLACE_NAME_RestoreWindow(placeName);
    FIELD_MSGBG_RequestSysFrame(FIELDMAP_GetMsgBg(fieldMap));
    reg_G2_BLDCNT = 0;
    FLD_FACEUP_RestoreBgPriorities(work);
    FLD_FACEUP_RestoreVisiblePlanes(work);
    func_020307B0(work);
    *FIELDMAP_GetFaceUpWorkPtr(fieldMap) = 0;
}





void FLD_FACEUP_SaveBgPriorities(FaceupWork *work)
{
    int bgId;

    for (bgId = 0; bgId < 4; bgId++)
        work->savedBgPriority[bgId] = func_020416D4((u8)bgId);
}






void FLD_FACEUP_SaveVisiblePlanes(FaceupWork *work)
{
    work->savedVisiblePlanes = BG_SYS_GetMainVisiblePlanes();
}





void FLD_FACEUP_RestoreBgPriorities(FaceupWork *work)
{
    int bgId;

    for (bgId = 0; bgId < 4; bgId++)
        func_0204047C((u8)bgId, work->savedBgPriority[bgId]);
}






void FLD_FACEUP_RestoreVisiblePlanes(FaceupWork *work)
{
    BG_SYS_SetMainVisiblePlanes(work->savedVisiblePlanes);
}





int FLD_FACEUP_StepFadeIn(FaceupWork *work)
{
    int blendLevel;

    work->fadeFrame = work->fadeFrame + 1;
    blendLevel = (work->fadeFrame << 4) / 30;
    func_0207D63C(&reg_G2_BLDCNT, 8, 4, blendLevel, 16 - blendLevel);
    if (work->fadeFrame >= 30)
        return 1;
    return 0;
}





void FLD_FACEUP_UpdateTaskMain(void *tcb, FaceupWork *work)
{
    struct FieldMsgWindow *msgWindow;
    int printState;

    if (work->lipSyncStopped == 0 && SCRIPT_WORK_CheckFlag(3) != 0) {
        msgWindow = SCRCMD_WORK_GetMsgWindow(work->scrcmdWork);
        if (msgWindow != 0) {
            printState = FIELD_MSGBG_GetPlainWinStreamState(msgWindow);
            if (printState == 0) {
                work->mouth.idle = 0;
                work->waitingForText = 0;
            } else if (printState == 2 && work->waitingForText == 0) {
                work->lipSyncStopped = 1;
            }
        }
    }
    FLD_FACEUP_StepAnim(gFldFaceupMouthFrames, 4, 0x184, 8, 4, &work->mouth);
    if (work->blinkTimer == 0) {
        work->blink.idle = 0;
        work->blinkTimer = func_020056EC(0x14) + 0x50;
    } else {
        work->blinkTimer = work->blinkTimer - 1;
    }
    FLD_FACEUP_StepAnim(gFldFaceupBlinkFrames, 5, 0x160, 0xC, 6, &work->blink);
}




void FLD_FACEUP_VBlankUpload(void *tcb, FaceupWork *work)
{
    FaceupAnim *blink = &work->blink;
    FaceupAnim *mouth;

    if (blink->uploadPending != 0) {
        func_020409E0(3, blink->tiles[0], 0xC, 0x10D);
        func_020409E0(3, blink->tiles[1], 0xC, 0x12D);
        blink->uploadPending = 0;
    }
    mouth = &work->mouth;
    if (mouth->uploadPending != 0) {
        func_020409E0(3, mouth->tiles[0], 8, 0x16E);
        func_020409E0(3, mouth->tiles[1], 8, 0x18E);
        mouth->uploadPending = 0;
    }
}




/*
 * lever: unsigned long fifth argument restores parameter homes; nested zero-delay guard and i*e operand order fix the multiply copy. Extent ends with two alignment bytes.
 */
void FLD_FACEUP_StepAnim(const FaceupAnimFrame *frames, unsigned frameCount, unsigned firstTile, unsigned tileStride, unsigned long tileWidth, FaceupAnim *anim)
{
    int row;
    unsigned col;
    unsigned baseTile;

    if (anim->uploadPending != 0)
        return;
    if (anim->delay == 0) {
        if (anim->frame == 0 && anim->idle != 0)
            return;
        anim->uploadPending = 1;
        baseTile = firstTile + tileStride * frames[anim->frame].imageIndex;
        for (row = 0; row < 2; row++) {
            for (col = 0; col < tileWidth; col++) {
                anim->tiles[row][col] = (u16)(baseTile + row * tileWidth + col);
            }
        }
        anim->delay = anim->delayReload;
        anim->frame++;
        if (anim->frame >= frameCount) {
            anim->frame = 0;
            anim->idle = 1;
        }
    } else {
        anim->delay--;
    }
}
