/*
 * Bag screen (ITEMMENU) work area, shared by the whole overlay 070.
 *
 * One object is allocated in ITEMMENU init (0x874 bytes, zero filled) and
 * passed to every task function and callback of the screen.
 */
#ifndef ITEMMENU_TYPES_H
#define ITEMMENU_TYPES_H

#include "../arm9/myitem_savedata_types.h"

/* Text window handle plus a flag: set when the window still has to be
 * flushed to VRAM after printing. */
typedef struct ItemMenuWindow {
    struct BmpWin *window;
    unsigned char isDirty;
    unsigned char reserved[3];
} ItemMenuWindow;

/* One row of the pop-up action list: label text, color and a user value. */
typedef struct ItemMenuListEntry {
    void *text;
    unsigned short color;
    int extra;
} ItemMenuListEntry;

struct Actor;
struct BmpWin;
struct Bmp;
struct BlinkPalAnm;
struct MsgBank;
struct WordSet;
struct Strbuf;
struct GameData;
struct MyStatus;
struct PaletteFade;
struct PrintSys;
struct TaskMenuRes;
struct Tcbl;
struct KeyCursor;
struct TextStream;
struct TcbTask;
struct ButtonMan;
struct TaskMenu;
struct ItemMenuWork;
typedef void (*ItemMenuTaskFn)(struct ItemMenuWork *);

#define ITEMMENU_POCKET_ITEM_COUNT 310
#define ITEMMENU_LIST_WINDOW_COUNT 9
#define ITEMMENU_TYPE_ACTOR_COUNT 17

/* Index of each window in ItemMenuWork.listWindows. */
enum {
    ITEMMENU_WINDOW_ITEM_NAME = 0,
    ITEMMENU_WINDOW_ITEM_COUNT = 1,
    ITEMMENU_WINDOW_ITEM_PRICE = 2,
    ITEMMENU_WINDOW_ITEM_DESC = 3,
    ITEMMENU_WINDOW_MENU_0 = 4,
    ITEMMENU_WINDOW_MENU_1 = 5,
    ITEMMENU_WINDOW_MENU_2 = 6,
    ITEMMENU_WINDOW_MENU_3 = 7,
    ITEMMENU_WINDOW_MENU_4 = 8
};

/* Sound effect ids used by the bag screen. */
#define ITEMMENU_SE_CURSOR 0x548
#define ITEMMENU_SE_SELECT 0x54C
#define ITEMMENU_SE_CANCEL 0x551
#define ITEMMENU_SE_REGISTER 0x7CD

/* Key bits as returned by the key repeat and trigger readers. */
#define ITEMMENU_KEY_A 0x1
#define ITEMMENU_KEY_B 0x2
#define ITEMMENU_KEY_SELECT 0x4
#define ITEMMENU_KEY_UP 0x40
#define ITEMMENU_KEY_DOWN 0x80
#define ITEMMENU_KEY_R 0x100
#define ITEMMENU_KEY_L 0x200

typedef struct ItemMenuWork {
    /* 0x000 */ struct GameData *saveData;
    /* 0x004 */ void *optionsSave;
    /* 0x008 */ struct MyStatus *myStatus;
    /* 0x00C */ void *actionPermissions;
    /* 0x010 */ int bagMode;
    /* 0x014 */ void *bagCursor;
    /* 0x018 */ void *bag;
    /* 0x01C */ int bagFilter;
    /* 0x020 */ BagSlot items[ITEMMENU_POCKET_ITEM_COUNT];
    /* 0x4F8 */ ItemMenuTaskFn taskFn;
    /* 0x4FC */ ItemMenuWindow messageWindows[2];
    /* 0x50C */ struct PrintSys *printSys;
    /* 0x510 */ struct TextStream *messageWindow;
    /* 0x514 */ int messageWindowOpen;
    /* 0x518 */ struct KeyCursor *itemDescWindow;
    /* 0x51C */ struct MsgBank *msgBank;
    /* 0x520 */ struct WordSet *wordSet;
    /* 0x524 */ struct Strbuf *tempString;
    /* 0x528 */ struct Strbuf *messageString;
    /* 0x52C */ struct Strbuf *listStrings;
    /* 0x530 */ unsigned int menuTaskArg;
    /* 0x534 */ unsigned char reserved534[0x10];
    /* 0x544 */ unsigned short heapId;
    /* 0x546 */ unsigned char reserved546[0x2];
    /* 0x548 */ int cellRes;
    /* 0x54C */ int cellAnimRes;
    /* 0x550 */ int cellTransRes;
    /* 0x554 */ int bagCharRes;
    /* 0x558 */ unsigned char reserved558[0x4];
    /* 0x55C */ int iconCharRes;
    /* 0x560 */ int bagPaletteRes;
    /* 0x564 */ int iconPaletteRes;
    /* 0x568 */ int bagCellRes;
    /* 0x56C */ int bagAnimRes;
    /* 0x570 */ int iconCellRes;
    /* 0x574 */ int pocketCharRes;
    /* 0x578 */ int pocketPaletteRes;
    /* 0x57C */ int pocketCellRes;
    /* 0x580 */ unsigned int cursorCharRes;
    /* 0x584 */ unsigned int cursorPaletteRes;
    /* 0x588 */ int barCharRes;
    /* 0x58C */ unsigned int cursorCellRes;
    /* 0x590 */ int tabCharRes;
    /* 0x594 */ int tabPaletteRes;
    /* 0x598 */ int tabCellRes;
    /* 0x59C */ unsigned int typeIconRes[ITEMMENU_TYPE_ACTOR_COUNT];
    /* 0x5E0 */ unsigned int cursorCharRes2;
    /* 0x5E4 */ unsigned int cursorPaletteRes2;
    /* 0x5E8 */ unsigned int slotCharRes[3];
    /* 0x5F4 */ unsigned int slotPaletteRes[8];
    /* 0x614 */ struct Bmp *slotBitmap[8];
    /* 0x634 */ struct Actor *slotActorA[8];
    /* 0x654 */ unsigned int slotAnimIndex[8];
    /* 0x674 */ struct Actor *slotActorC[8];
    /* 0x694 */ struct ButtonMan *taskSys;
    /* 0x698 */ struct TcbTask *unitList;
    /* 0x69C */ void *clactSys;
    /* 0x6A0 */ struct Actor *movingCursorActor;
    /* 0x6A4 */ struct Actor *selectorActor;
    /* 0x6A8 */ struct Actor *cursorActor;
    /* 0x6AC */ struct Actor *tabActor[5];
    /* 0x6C0 */ struct Actor *damageClassActors[3];
    /* 0x6CC */ struct Actor *typeActors[ITEMMENU_TYPE_ACTOR_COUNT];
    /* 0x710 */ struct Actor *sideActor[5];
    /* 0x724 */ struct Actor *listWindowA;
    /* 0x728 */ struct Actor *listWindowB;
    /* 0x72C */ struct Actor *inputGuard;
    /* 0x730 */ struct Tcbl *touchTask;
    /* 0x734 */ ItemMenuWindow listWindows[ITEMMENU_LIST_WINDOW_COUNT];
    /* 0x77C */ struct TaskMenu *menuList;
    /* 0x780 */ ItemMenuListEntry listEntries[8];
    /* 0x7E0 */ struct TaskMenuRes *taskMenuState;
    /* 0x7E4 */ unsigned char reserved7E4[0x8];
    /* 0x7EC */ int listMode;
    /* 0x7F0 */ int repeatCount;
    /* 0x7F4 */ int listCount;
    /* 0x7F8 */ int frameCounter;
    /* 0x7FC */ unsigned int bgPaletteA;
    /* 0x800 */ unsigned int bgPaletteB;
    /* 0x804 */ unsigned int bgPaletteC;
    /* 0x808 */ unsigned int bgPaletteD;
    /* 0x80C */ int currentPocket;
    /* 0x810 */ int cursorRow;
    /* 0x814 */ int scrollOffset;
    /* 0x818 */ int shownItemId;
    /* 0x81C */ unsigned int usingWorkCopy;
    /* 0x820 */ unsigned char reserved820[0x8];
    /* 0x828 */ unsigned int menuActionTable[4];
    /* 0x838 */ unsigned int keyRepeatPacked;
    /* 0x83C */ unsigned short busyCount;
    /* 0x83E */ unsigned short listDirty;
    /* 0x840 */ int screenState;
    /* 0x844 */ unsigned int nextState;
    /* 0x848 */ unsigned int usageContext;
    /* 0x84C */ int selectedItemId;
    /* 0x850 */ struct BlinkPalAnm *blinkPalAnm;
    /* 0x854 */ struct PaletteFade *palAnmSlot;
    /* 0x858 */ int currentPage;
    /* 0x85C */ unsigned int isTouchActive;
    /* 0x860 */ unsigned int isDraggingItem;
    /* 0x864 */ unsigned short fadeStep;
    /* 0x866 */ unsigned short fadeTimer;
    /* 0x868 */ ItemMenuTaskFn fadeCallback;
    /* 0x86C */ unsigned int keyRepeatDelay;
    /* 0x870 */ unsigned int keyRepeatInterval;
} ItemMenuWork;

#endif
