#ifndef GAME_OV069_BSUBWAY_RECORD_LIST_TYPES_H
#define GAME_OV069_BSUBWAY_RECORD_LIST_TYPES_H

/* ov069: Battle Subway Wi-Fi record list screen. It shows the record list
 * of the Battle Subway save block (BSUBWAY_SAVEDATA_AllocHistoryCopy), ten entries per page,
 * with a row cursor and previous/next page arrows. bsubway_record_list.c holds
 * the screen entry points (Init, Main, Exit) and the setup and teardown of
 * the work; the same file holds the page drawing and the input states. */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed int     s32;

struct GameData;
struct WinMgr;
struct MsgBank;
struct WordSet;
struct Strbuf;
struct Bank;
struct BmpWin;
struct GfFont;
struct PrintSys;
struct Actor;
struct CursorMove;

#define BSUBWAY_RECORD_LIST_ENTRIES_PER_PAGE 10
#define BSUBWAY_RECORD_LIST_MESSAGE_COUNT    7

/* PMS (easy chat) sentence data, 8 bytes. */
typedef struct BsubwayPmsData {
    u16 sentenceType;
    u16 sentenceId;
    u16 words[2];
} BsubwayPmsData;

/* One record of the Battle Subway record list, 0x22 bytes. */
typedef struct BsubwayWifiRecord {
    u16 trainerName[9];             /* 0x00 name text, terminated */
    u8 trainerClass;                /* 0x12 */
    u8 trainerIndex;                /* 0x13 index of the trainer inside the class */
    u8 scoreLe[4];                  /* 0x14 score, little endian bytes */
    BsubwayPmsData greeting;        /* 0x18 */
    u8 isMultiBattle : 1;           /* 0x20 bit 0 */
    u8 isFemale : 1;                /* 0x20 bit 1 selects the name text colour */
    u8 flagsReserved : 6;
    u8 padding;                     /* 0x21 */
} BsubwayWifiRecord;

typedef struct BsubwayWifiRecordList {
    BsubwayWifiRecord records[30];
} BsubwayWifiRecordList;

/* Pending text of one BMP window. */
typedef struct BsubwayRecordListPrintJob {
    struct BmpWin *window;
    u8 isPending;
} BsubwayRecordListPrintJob;

/* Window indexes: 0..9 are the row windows (one name per row). */
enum {
    BSUBWAY_RECORD_LIST_WIN_TITLE = BSUBWAY_RECORD_LIST_ENTRIES_PER_PAGE,
    BSUBWAY_RECORD_LIST_WIN_SUMMARY,
    BSUBWAY_RECORD_LIST_WIN_TRAINER_LINE,
    BSUBWAY_RECORD_LIST_WIN_NAME,
    BSUBWAY_RECORD_LIST_WIN_LABEL_B,
    BSUBWAY_RECORD_LIST_WIN_SCORE,
    BSUBWAY_RECORD_LIST_WIN_LABEL_C,
    BSUBWAY_RECORD_LIST_WIN_GREETING,
    BSUBWAY_RECORD_LIST_WIN_COUNT
};

/* Actor indexes. */
enum {
    BSUBWAY_RECORD_LIST_ACTOR_CURSOR,
    BSUBWAY_RECORD_LIST_ACTOR_BACK,
    BSUBWAY_RECORD_LIST_ACTOR_PREV_ARROW,
    BSUBWAY_RECORD_LIST_ACTOR_NEXT_ARROW
};

/* Input states (index into the state function table). */
enum {
    BSUBWAY_RECORD_LIST_STATE_FADE_IN,
    BSUBWAY_RECORD_LIST_STATE_INPUT,
    BSUBWAY_RECORD_LIST_STATE_BACK_ANIM,
    BSUBWAY_RECORD_LIST_STATE_FADE_OUT_START,
    BSUBWAY_RECORD_LIST_STATE_FADE_OUT_WAIT
};

/* Screen argument, owned by the caller. */
typedef struct BsubwayRecordListArgs {
    struct GameData *gameData;
    u32 wordNumber0;    /* 0x04 number set in message word slot 0 */
    u32 wordNumber1;    /* 0x08 number set in message word slot 1 */
} BsubwayRecordListArgs;

/* Screen work, 0x168 bytes, allocated by the Init function. */
typedef struct BsubwayRecordListWork {
    void *arcHandle;                /* 0x000 UI archive (graphics) */
    struct WinMgr *frameMgr;        /* 0x004 BGWINFRM manager, ten frames */
    struct BsubwayWifiRecordList *recordList; /* 0x008 copy of the save records, 0x22 bytes per entry */
    struct GfFont *font;            /* 0x00C */
    struct BmpWin *windows[BSUBWAY_RECORD_LIST_WIN_COUNT]; /* 0x010 */
    BsubwayRecordListPrintJob printJobs[BSUBWAY_RECORD_LIST_WIN_COUNT]; /* 0x058 one per window */
    struct PrintSys *printSys;      /* 0x0E8 text printer system */
    u8 unusedEC[8];                 /* 0x0EC nothing reads these */
    struct MsgBank *msgBank;        /* 0x0F4 message bank (arc 2, file 0x39) */
    struct WordSet *wordSet;        /* 0x0F8 */
    struct Strbuf *textBuf;         /* 0x0FC scratch string buffer, 0x40 chars */
    void *messages[BSUBWAY_RECORD_LIST_MESSAGE_COUNT]; /* 0x100 */
    struct Bank *actorBank;         /* 0x11C bank of four actors */
    struct Bank *subActorBank;      /* 0x120 bank of two actors */
    struct Actor *actors[4];              /* 0x124 row cursor, selection marker, previous arrow, next arrow */
    int spriteRes[6];               /* 0x134 resource handles: three per archive, in load order */
    struct CursorMove *cursorMove;  /* 0x14C row cursor with touch rectangles */
    void *vblankTask;               /* 0x150 per-frame task (VBlank upload) */
    BsubwayRecordListArgs *args;    /* 0x154 */
    int state;                      /* 0x158 index of the input state function */
    u32 chosenEntry;                /* 0x15C cleared at start, nothing reads it */
    u16 page;                       /* 0x160 current page */
    u16 pageCount;                  /* 0x162 */
    int entryCount;                 /* 0x164 */
} BsubwayRecordListWork;

#endif
