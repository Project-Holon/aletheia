#ifndef BEACON_VIEW_TYPES_H
#define BEACON_VIEW_TYPES_H

#include "../types.h"

struct TcblTask;

struct PaletteFade;
struct GameData;
struct GameSystem;
struct FieldMap;
struct FldVReq;
struct MiscSave;
struct MyItem;
struct GameComm;
struct GPowerData;
struct BeaconStatus;
struct GameBeaconInfoTable;
struct GameBeaconInfo;
struct GfFont;
struct PrintQueue;
struct TaskMenuRes;
struct TaskMenuWin;
struct KeyCursor;
struct WordSet;
struct MsgBank;
struct Strbuf;
struct ClactActor;
struct NNSG2dCharacterData;
struct BmpOam;
struct Bmp;
struct BmpWin;
struct GameEvent;
struct TcbTask;
struct TcblSystem;

/* Beacon list view: the work area allocated in BEACON_VIEW_Create and the structs it holds.
   The including file defines u8, u16 and u32 first. */

typedef struct BeaconViewResEntry {
    struct NNSG2dCharacterData *data; /* 0x00 */
    void *file; /* 0x04 */
} BeaconViewResEntry;
typedef char BeaconViewResEntry_SizeCheck[(sizeof(void *) != 4 || ((sizeof(BeaconViewResEntry) == 0x8))) ? 1 : -1];

typedef struct BeaconViewSlot {
    struct TaskMenuWin *taskMenu; /* 0x00 */
    struct Strbuf *label; /* 0x04 */
    u16 textColor; /* 0x08 */
    u8 pad0A[0x2];
    int labelId; /* 0x0C */
} BeaconViewSlot;
typedef char BeaconViewSlot_SizeCheck[(sizeof(void *) != 4 || ((sizeof(BeaconViewSlot) == 0x10))) ? 1 : -1];

typedef struct BeaconViewWindow {
    void *handle; /* 0x00 */
    void *bitmap; /* 0x04 */
    void *layout; /* 0x08 */
    u8 drawn; /* 0x0C */
    u8 pad0D[0x7];
} BeaconViewWindow;
typedef char BeaconViewWindow_SizeCheck[(sizeof(void *) != 4 || ((sizeof(BeaconViewWindow) == 0x14))) ? 1 : -1];

typedef struct BeaconViewEntry {
    u8 index; /* 0x00 */
    u8 peerSlot; /* 0x01 */
    u8 state; /* 0x02 */
    u8 flags; /* 0x03 */
    u8 gender; /* 0x04 */
    u8 frequent; /* 0x05 */
    u16 trainerId; /* 0x06 */
    short x; /* 0x08 */
    short y; /* 0x0A */
    struct ClactActor *panelActor; /* 0x0C */
    struct ClactActor *iconActor; /* 0x10 */
    struct ClactActor *statusActor; /* 0x14 */
    struct BmpOam *textWindow; /* 0x18 */
    struct Bmp *textBitmap; /* 0x1C */
    struct Strbuf *nameString; /* 0x20 */
    struct Strbuf *messageString; /* 0x24 */
    struct PrintQueue *sharedValue; /* 0x28 */
    struct TcblTask *busy; /* 0x2C */
    struct TcblTask *activeTask; /* 0x30 */
} BeaconViewEntry;
typedef char BeaconViewEntry_SizeCheck[(sizeof(void *) != 4 || ((sizeof(BeaconViewEntry) == 0x34))) ? 1 : -1];

typedef struct BeaconViewResList {
    u32 count; /* 0x00 */
    u32 *items; /* 0x04 */
} BeaconViewResList;
typedef char BeaconViewResList_SizeCheck[(sizeof(void *) != 4 || ((sizeof(BeaconViewResList) == 0x8))) ? 1 : -1];

typedef struct BeaconViewResSet {
    BeaconViewResList palettes; /* 0x00 */
    BeaconViewResList images; /* 0x08 */
    BeaconViewResList cells; /* 0x10 */
} BeaconViewResSet;
typedef char BeaconViewResSet_SizeCheck[(sizeof(void *) != 4 || ((sizeof(BeaconViewResSet) == 0x18))) ? 1 : -1];

typedef struct BeaconViewPaletteFile {
    u8 *header; /* 0x00 */
    u16 *data; /* 0x04 */
    void *res; /* 0x08 */
} BeaconViewPaletteFile;
typedef char BeaconViewPaletteFile_SizeCheck[(sizeof(void *) != 4 || ((sizeof(BeaconViewPaletteFile) == 0xC))) ? 1 : -1];

typedef struct BeaconViewWork {
    struct GameSystem *fieldSystem; /* 0x00 */
    struct GameData *saveInfo; /* 0x04 */
    struct FieldMap *sessionInfo; /* 0x08 */
    void *initArg; /* 0x0C */
    struct FldVReq *bgConfig; /* 0x10 */
    struct MiscSave *playerBlock; /* 0x14 */
    struct MyItem *myItem; /* 0x18 */
    struct GameComm *playerProfile; /* 0x1C */
    void *optionData; /* 0x20 */
    struct GPowerData *powerRecord; /* 0x24 */
    int powerId; /* 0x28 */
    u32 profileId; /* 0x2C */
    u8 gender; /* 0x30 */
    u8 languageId; /* 0x31 */
    u8 styleId; /* 0x32 */
    u8 pad33;
    struct BeaconStatus *beaconStatus; /* 0x34 */
    struct GameBeaconInfoTable *receiveQueue; /* 0x38 */
    struct GameBeaconInfoTable *recordLog; /* 0x3C */
    struct GameBeaconInfo *recordBuffer; /* 0x40 */
    struct GameBeaconInfo *ownRecord; /* 0x44 */
    u16 tagBuffer; /* 0x48 */
    u16 currentTag; /* 0x4A */
    struct GameBeaconInfo *currentRecord; /* 0x4C */
    BeaconViewEntry *currentEntry; /* 0x50 */
    u8 currentIndex; /* 0x54 */
    u8 currentId; /* 0x55 */
    u8 pad56;
    u8 previousCount; /* 0x57 */
    u8 previousIdA; /* 0x58 */
    u8 previousIdB; /* 0x59 */
    u8 pad5A[0x2];
    int addedCount; /* 0x5C */
    int lastRequest; /* 0x60 */
    u8 pad64[0x4];
    int mode; /* 0x68 */
    int step; /* 0x6C */
    u16 eventFlags; /* 0x70 */
    u16 endRequest; /* 0x72 */
    int waitFrames; /* 0x74 */
    u8 languageCode; /* 0x78 */
    char resetFlag; /* 0x79 */
    u8 windowShown; /* 0x7A */
    u8 recordCount; /* 0x7B */
    u8 scrollTop; /* 0x7C */
    u8 visibleRows; /* 0x7D */
    u8 touchedRow; /* 0x7E */
    char powerIdArg; /* 0x7F */
    char powerFlagArg; /* 0x80 */
    char animActive; /* 0x81 */
    u8 fadeStarted; /* 0x82 */
    u8 fadeResult; /* 0x83 */
    int slideTarget; /* 0x84 */
    int slideTimer; /* 0x88 */
    u8 historyCount; /* 0x8C */
    u8 historyIds[7]; /* 0x8D */
    u16 tempHeapId; /* 0x94 */
    u16 uiHeapId; /* 0x96 */
    u16 mainHeapId; /* 0x98 */
    u8 pad9A[0x2];
    void *bgResource; /* 0x9C */
    struct TcblSystem *taskList; /* 0xA0 */
    struct TcbTask *updateTask; /* 0xA4 */
    int busyCount; /* 0xA8 */
    struct PaletteFade *paletteAnim; /* 0xAC */
    struct GfFont *font; /* 0xB0 */
    struct PrintQueue *printQueue; /* 0xB4 */
    struct TaskMenuRes *taskMenuState; /* 0xB8 */
    struct KeyCursor *taskMenuCursor; /* 0xBC */
    BeaconViewSlot slots[5]; /* 0xC0 */
    struct WordSet *wordSet; /* 0x110 */
    struct MsgBank *messageBank; /* 0x114 */
    struct Strbuf *messageBuffer; /* 0x118 */
    struct Strbuf *formatBuffer; /* 0x11C */
    struct Strbuf *stringList; /* 0x120 */
    void *actorSystem; /* 0x124 */
    void *actorBank; /* 0x128 */
    void *actorResource; /* 0x12C */
    u8 pad130[0x4];
    BeaconViewResSet panelLists; /* 0x134 */
    BeaconViewResSet iconLists; /* 0x14C */
    BeaconViewResSet statusLists; /* 0x164 */
    BeaconViewWindow windows[3]; /* 0x17C */
    BeaconViewEntry icons[5]; /* 0x1B8 */
    struct ClactActor *actors[6]; /* 0x2BC */
    u32 playTime; /* 0x2D4 */
    BeaconViewResEntry statusRes[12]; /* 0x2D8 */
    BeaconViewResEntry iconRes[16]; /* 0x338 */
    BeaconViewPaletteFile iconPalette; /* 0x3B8 */
    BeaconViewPaletteFile panelPalette; /* 0x3C4 */
} BeaconViewWork;
typedef char BeaconViewWork_SizeCheck[(sizeof(void *) != 4 || ((sizeof(BeaconViewWork) == 0x3D0))) ? 1 : -1];

typedef struct BeaconViewIconMoveTask {
    u8 phase; /* 0x00 */
    u8 slot; /* 0x01 */
    u8 pad02[0x2];
    int mode; /* 0x04 */
    BeaconViewEntry *entry; /* 0x08 */
    BeaconViewWork *work; /* 0x0C */
    int timer; /* 0x10 */
    int *busyCounter; /* 0x14 */
} BeaconViewIconMoveTask;
typedef char BeaconViewIconMoveTask_SizeCheck[(sizeof(void *) != 4 || ((sizeof(BeaconViewIconMoveTask) == 0x18))) ? 1 : -1];

typedef struct BeaconViewIconSlideTask {
    int phase; /* 0x00 */
    BeaconViewWork *work; /* 0x04 */
    BeaconViewEntry *entry; /* 0x08 */
    u8 mode; /* 0x0C */
    u8 delay; /* 0x0D */
    u8 steps; /* 0x0E */
    u8 step; /* 0x0F */
    short targetX; /* 0x10 */
    short targetY; /* 0x12 */
    int x; /* 0x14 */
    int y; /* 0x18 */
    int deltaX; /* 0x1C */
    int deltaY; /* 0x20 */
    int *busyCounter; /* 0x24 */
} BeaconViewIconSlideTask;
typedef char BeaconViewIconSlideTask_SizeCheck[(sizeof(void *) != 4 || ((sizeof(BeaconViewIconSlideTask) == 0x28))) ? 1 : -1];

typedef struct BeaconViewScrollStepTask {
    u8 phase; /* 0x00 */
    u8 steps; /* 0x01 */
    u8 step; /* 0x02 */
    u8 position; /* 0x03 */
    u8 delta; /* 0x04 */
    u8 pad05[0x3];
    int *busyCounter; /* 0x08 */
} BeaconViewScrollStepTask;
typedef char BeaconViewScrollStepTask_SizeCheck[(sizeof(void *) != 4 || ((sizeof(BeaconViewScrollStepTask) == 0xC))) ? 1 : -1];

typedef struct BeaconViewFadeTask {
    u8 phase; /* 0x00 */
    u8 duration; /* 0x01 */
    u8 pad02[0x2];
    int frames; /* 0x04 */
    BeaconViewWork *work; /* 0x08 */
    int *busyCounter; /* 0x0C */
} BeaconViewFadeTask;
typedef char BeaconViewFadeTask_SizeCheck[(sizeof(void *) != 4 || ((sizeof(BeaconViewFadeTask) == 0x10))) ? 1 : -1];

typedef struct BeaconViewPowerAnimTask {
    u8 phase; /* 0x00 */
    u8 pad01;
    u8 duration; /* 0x02 */
    u8 mode; /* 0x03 */
    u8 pad04;
    u8 result; /* 0x05 */
    u8 pad06[0x2];
    int timer; /* 0x08 */
    int powerId; /* 0x0C */
    u16 nameStringId; /* 0x10 */
    u16 cost; /* 0x12 */
    u16 minutesLeft; /* 0x14 */
    u16 hours; /* 0x16 */
    u16 minutes; /* 0x18 */
    u8 pad1A[0x2];
    BeaconViewWork *work; /* 0x1C */
    int *busyCounter; /* 0x20 */
} BeaconViewPowerAnimTask;
typedef char BeaconViewPowerAnimTask_SizeCheck[(sizeof(void *) != 4 || ((sizeof(BeaconViewPowerAnimTask) == 0x24))) ? 1 : -1];

typedef struct BeaconViewIconWaitTask {
    u8 phase; /* 0x00 */
    u8 delay; /* 0x01 */
    u8 pad02[0x6];
    BeaconViewEntry *entry; /* 0x08 */
    u32 timer; /* 0x0C */
    BeaconViewWork *work; /* 0x10 */
} BeaconViewIconWaitTask;
typedef char BeaconViewIconWaitTask_SizeCheck[(sizeof(void *) != 4 || ((sizeof(BeaconViewIconWaitTask) == 0x14))) ? 1 : -1];

typedef struct BeaconViewWindowATask {
    u8 phase; /* 0x00 */
    u8 counter; /* 0x01 */
    u8 interval; /* 0x02 */
    u8 paletteOffset; /* 0x03 */
    u8 pad04[0x4];
    BeaconViewEntry *entry; /* 0x08 */
    BeaconViewWork *work; /* 0x0C */
    int *busyCounter; /* 0x10 */
} BeaconViewWindowATask;
typedef char BeaconViewWindowATask_SizeCheck[(sizeof(void *) != 4 || ((sizeof(BeaconViewWindowATask) == 0x14))) ? 1 : -1];

typedef struct BeaconViewWindowBTask {
    u8 pad00[0x4];
    BeaconViewWindow *window; /* 0x04 */
    BeaconViewWork *work; /* 0x08 */
    int *busyCounter; /* 0x0C */
} BeaconViewWindowBTask;
typedef char BeaconViewWindowBTask_SizeCheck[(sizeof(void *) != 4 || ((sizeof(BeaconViewWindowBTask) == 0x10))) ? 1 : -1];

typedef struct BeaconViewWindowCTask {
    BeaconViewEntry *entry; /* 0x00 */
    void **windowRef; /* 0x04 */
    BeaconViewWork *work; /* 0x08 */
    int *busyCounter; /* 0x0C */
} BeaconViewWindowCTask;
typedef char BeaconViewWindowCTask_SizeCheck[(sizeof(void *) != 4 || ((sizeof(BeaconViewWindowCTask) == 0x10))) ? 1 : -1];

/* Work of the event task created by BEACON_VIEW_CreateTaskProc (0x1C bytes). The param is an
   arrow index in mode 0 and a task menu window in mode 2. */
typedef struct BeaconTaskWork {
    int state; /* 0x00 */
    struct GameSystem *fieldSystem; /* 0x04 */
    struct FieldMap *sessionInfo; /* 0x08 */
    BeaconViewWork *owner; /* 0x0C */
    struct GameEvent *eventDesc; /* 0x10 */
    unsigned mode; /* 0x14 */
    uptr param; /* 0x18 */
} BeaconTaskWork;
typedef char BeaconTaskWork_SizeCheck[(sizeof(void *) != 4 || ((sizeof(BeaconTaskWork) == 0x1C))) ? 1 : -1];

#endif
