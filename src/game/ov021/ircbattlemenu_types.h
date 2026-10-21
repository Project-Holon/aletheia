/*
 * ircbattlemenu_types.h: the IR battle menu proc work (0x308 bytes,
 * allocated by IRCBATTLEMENU_Init with PROCSYS_AllocProcWork).
 * Used by ircbattlemenu.c.
 */
#ifndef IRCBATTLEMENU_TYPES_H
#define IRCBATTLEMENU_TYPES_H

struct TcbTask;

struct IrcBattleMenuWork;
struct IrcBattleEntryWork;
struct GameData;
struct MsgBank;
struct Strbuf;
struct BmpWin;
struct TextPrinter;
struct PrintQue;
struct Tcbl;
struct TaskMenuWork;
struct TaskMenuRes;
struct TaskMenuWin;
struct AppKeyCursor;
struct TimeIcon;
struct Unit;
struct ClactActor;
struct GfFont;
struct TouchSwitch;

typedef void (*IrcBattleMenuSeqFunc)(struct IrcBattleMenuWork *work);
/* Touch callback: index of the pressed button, returns 1 when the press was taken. */
typedef int (*IrcBattleMenuTouchFunc)(unsigned int index, struct IrcBattleMenuWork *work);

/* One entry of the yes/no task menu (TaskMenuItem in app_taskmenu.c). */
typedef struct IrcBattleMenuItem {
    struct Strbuf *str;                 /* 0x00 */
    unsigned short msgColor;            /* 0x04 */
    unsigned short padding;             /* 0x06 */
    unsigned int type;                  /* 0x08 */
} IrcBattleMenuItem;

typedef struct IrcBattleMenuWork {
    IrcBattleMenuSeqFunc seqFunc;       /* 0x000: current sequence, NULL ends Main */
    IrcBattleMenuTouchFunc touchFunc;   /* 0x004: called by the touch switch with the button index */
    unsigned int mode;                  /* 0x008: result, copied to IrcBattleEntryWork.mode (12 = back) */
    unsigned int partyMode;             /* 0x00C: copied to IrcBattleEntryWork.partyMode */
    unsigned short heapId;              /* 0x010 */
    unsigned char padding12[2];
    struct BmpWin *menuWins[4];         /* 0x014: button windows, menuWinCount in use */
    struct TouchSwitch *touchSw;        /* 0x024: touch button set, updated each frame */
    struct MsgBank *msgData;            /* 0x028 */
    struct GfFont *font;                /* 0x02C */
    struct GameData *gameData;          /* 0x030 */
    unsigned char padding34[4];
    struct Strbuf *message;             /* 0x038: expanded text of the message window */
    unsigned int winFrameChar;          /* 0x03C: first character of the window frame */
    unsigned int subBgChar;             /* 0x040: char data slot of the sub BG layers */
    unsigned int mainBgChar;            /* 0x044: char data slot of the main BG layer */
    unsigned short menuPltt[8][16];     /* 0x048: palette rows of the menu screen */
    unsigned short menuPlttBright[8][16]; /* 0x148: copy of menuPltt with the row offsets added */
    unsigned char padding248[0x20];
    struct TcbTask *vblankTask;         /* 0x268: GFL_USE_AddMainTask handle */
    struct Unit *clactUnit;        /* 0x26C */
    unsigned int res[6];                /* 0x270: 0..1 palettes, 2..3 characters, 4..5 cell animations */
    unsigned int resSpare;              /* 0x288: never read here */
    struct ClactActor *extraActors[2];  /* 0x28C */
    struct ClactActor *menuActors[5];   /* 0x294 */
    struct AppKeyCursor *keyCursor;     /* 0x2A8 */
    unsigned int bgAnimCount;           /* 0x2AC: counts down each frame */
    struct BmpWin *msgWin;              /* 0x2B0 */
    struct TextPrinter *printStream;    /* 0x2B4 */
    struct Tcbl *tcbl;                  /* 0x2B8 */
    struct PrintQue *printQue;          /* 0x2BC */
    struct TaskMenuWork *yesNoMenu;     /* 0x2C0 */
    IrcBattleMenuItem yesNoItems[2];    /* 0x2C4 */
    struct TaskMenuRes *taskMenuRes;    /* 0x2DC */
    struct TaskMenuWin *taskMenuWin;    /* 0x2E0 */
    struct IrcBattleEntryWork *param;   /* 0x2E4: proc parameter */
    struct TimeIcon *timeIcon;          /* 0x2E8 */
    void *subObjPlttCopy;               /* 0x2EC: 0x200-byte copy of sub OBJ palette 0x05000600 */
    void *subBgPlttCopy;                /* 0x2F0: 0x200-byte copy of sub BG palette 0x05000400 */
    int menuWinCount;                   /* 0x2F4: windows of menuWins in use */
    unsigned int isSaveDone;            /* 0x2F8 */
    unsigned char padding2FC[4];
    unsigned int touchIndex;            /* 0x300: last button index given to touchFunc */
    unsigned char padding304[2];
    unsigned char noAutoComm;           /* 0x306: skips GAMESYSTEM_TryStartAutoComm */
    unsigned char padding307;
} IrcBattleMenuWork;

#endif
