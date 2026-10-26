#ifndef GAME_OV186_BR_PROC_SYS_TYPES_H
#define GAME_OV186_BR_PROC_SYS_TYPES_H

#include "../types.h"

struct ProcSys;
struct ProcData;
struct BrProcSys;

/* One screen record of the process system table (0x14 bytes). */
struct BrProcOps {
    const struct ProcData *procData;   /* 0x00 process data of the screen */
    u32 size;                          /* 0x04 work size */
    u32 overlayId;                     /* 0x08 overlay holding the screen */
    void (*init)(void *work, struct BrProcSys *screen, void *oldWork, int mode); /* 0x0C builds the work */
    void (*update)(void *work, struct BrProcSys *screen); /* 0x10 */
};

/* One slot of the process system: a table record with its work and the record index (0x10 bytes). */
struct BrProcSlot {
    u32 active;                        /* 0x00 */
    void *work;                        /* 0x04 */
    const struct BrProcOps *ops;       /* 0x08 */
    int arg;                           /* 0x0C record index, or the previous arg */
};

/* State of the battle recorder process system (BR_PROC_SYS_Create), 0x70 bytes. */
struct BrProcSysContext {
    struct ProcSys *object;        /* 0x00 process-system object */
    const struct BrProcOps *base;  /* 0x04 record array base */
    unsigned short count;          /* 0x08 record count */
    unsigned short pad0;           /* 0x0A */
    struct BrProcSys *arg;         /* 0x0C screen object */
    unsigned short heap;           /* 0x10 heap id */
    unsigned short pad1;           /* 0x12 */
    int done;                      /* 0x14 set when the running slot completes */
    int state;                     /* 0x18 slot state machine */
    struct BrProcSlot old;         /* 0x1C */
    struct BrProcSlot current;     /* 0x2C */
    struct BrProcSlot next;        /* 0x3C */
    unsigned pending[6];           /* 0x4C pending record indices */
    unsigned pendingCount;            /* 0x64 */
    unsigned *list;                /* 0x68 loaded index list */
    int loaded;                    /* 0x6C */
};

/* The record cache of the battle recorder, 0x58 bytes (BR_PROC_SYS_LoadRecords). */
struct BrProcRecords {
    u32 present[4];                /* 0x00 slot holds a record */
    struct Strbuf *name[4];        /* 0x10 name of the record owner */
    u32 eggFlag[4];                /* 0x20 */
    u64 header[4];                 /* 0x30 header parameter */
    u32 musicalShow;               /* 0x50 */
    u32 loaded;                    /* 0x54 */
};

/* One stored battle record (0xC4 bytes): the uploader profile, then the record header. */
struct BrCachedRecord {
    u8 profile[0x80];                  /* 0x00 */
    u8 header[0x44];                   /* 0x80 BattleRecHeader */
};

/* The record list cache at the start of the recorder data block (0x1720 bytes). */
struct BrRecCache {
    struct BrCachedRecord entry[30];   /* 0x0000 */
    u8 saved[0x20];                    /* 0x16F8 per entry: the record was saved */
    u32 itemCount;                     /* 0x1718 */
    u32 selection;                     /* 0x171C */
};

/* Selection state of the type screens (4 bytes). */
struct BrTypeState {
    u16 selection;                     /* 0x00 row selected on the list */
    u16 pad02;                         /* 0x02 */
};

/* The data block of the battle recorder (BrMainWork.data, 0x17C8 bytes).  Every screen record points into it. */
struct BrRecorderData {
    struct BrRecCache cache;           /* 0x0000 */
    s64 selectedId;                    /* 0x1720 id of the selected video */
    unsigned list[7];                  /* 0x1728 pending screen list for BR_PROC_SYS_Create */
    int screenMode;                    /* 0x1744 mode of the battle record screens */
    struct BrProcRecords records;      /* 0x1748 */
    u8 choice[0x1C];                   /* 0x17A0 */
    int hidePlayerNames;               /* 0x17BC */
    struct BrTypeState typeRec;        /* 0x17C0 */
    int typeMode;                      /* 0x17C4 */
};

struct Strbuf;
struct BrFade;
struct BrRes;
struct BrSidebar;
struct BrNet;
struct BrProcSysContext;
struct Unit;
struct GameData;
struct BsubwayScoreData;
struct BrGraphic;

/* The argument records the process system builds for its screens (BR_PROC_SYS_Build*Record, Copy*Record).
 * Every record starts from the screen resources of struct BrProcSys; the builders differ in what follows. */

/* Four-word record: fade, actor unit, resources and process handle. */
struct BrProcArgHead {
    struct BrFade *fade;                 /* 0x00 */
    struct Unit *unit;                   /* 0x04 */
    struct BrRes *res;                   /* 0x08 */
    struct BrProcSysContext *proc;       /* 0x0C */
    u64 result;                          /* 0x10 value a screen hands back (the code entry screen) */
};

/* The sidebar screen record. */
struct BrProcArgBasic {
    int mode;                            /* 0x00 */
    struct Unit *unit;                   /* 0x04 */
    struct BrFade *fade;                 /* 0x08 */
    struct BrRes *res;                   /* 0x0C */
    struct BrProcSysContext *proc;       /* 0x10 */
    struct BrSidebar *sidebar;           /* 0x14 */
};

/* The record of the screens that show the player's profile and bsubway score. */
struct BrProcArgProfile {
    struct BrFade *fade;                 /* 0x00 */
    struct Unit *unit;                   /* 0x04 */
    struct BrRes *res;                   /* 0x08 */
    struct BrProcSysContext *proc;       /* 0x0C */
    void *block;                         /* 0x10 save block 0x3A (bsubway score data) */
    struct GameData *gameData;           /* 0x14 */
};

/* The record of the screens that show the live battle match stats. */
struct BrProcArgStats {
    struct Unit *unit;                   /* 0x00 */
    struct BrFade *fade;                 /* 0x04 */
    struct BrRes *res;                   /* 0x08 */
    struct BrProcSysContext *proc;       /* 0x0C */
    struct GameData *gameData;           /* 0x10 */
    void *stats;                         /* 0x14 */
};

/* The record of the video list screens: head plus game data. */
struct BrProcArgSave {
    struct BrFade *fade;                 /* 0x00 */
    struct Unit *unit;                   /* 0x04 */
    struct BrRes *res;                   /* 0x08 */
    struct BrProcSysContext *proc;       /* 0x0C */
    struct GameData *gameData;           /* 0x10 */
    u16 species;                         /* 0x14 chosen species, written by the code screen */
    u8 language;                         /* 0x16 */
    u8 version;                          /* 0x17 */
    int category;                        /* 0x18 */
};

/* The same record with the network handle before the game data. */
struct BrProcArgNet {
    struct BrFade *fade;                 /* 0x00 */
    struct Unit *unit;                   /* 0x04 */
    struct BrRes *res;                   /* 0x08 */
    struct BrProcSysContext *proc;       /* 0x0C */
    struct BrNet *net;                   /* 0x10 */
    struct GameData *gameData;           /* 0x14 */
};

/* The record of the match record screens, 0x1C bytes. */
struct BrProcArgRecord {
    int mode;                            /* 0x00 */
    struct BrFade *fade;                 /* 0x04 */
    struct Unit *unit;                   /* 0x08 */
    struct BrRes *res;                   /* 0x0C */
    struct BrProcSysContext *proc;       /* 0x10 */
    struct GameData *gameData;           /* 0x14 */
    struct BrProcRecords *rec;           /* 0x18 battle record cache */
    int saved;                           /* 0x1C set when the video was saved, written by the save screen */
};

/* The record of the result screens, 0x30 bytes. */
struct BrProcArgResult {
    struct BrFade *fade;                 /* 0x00 */
    struct Unit *unit;                   /* 0x04 */
    struct BrRes *res;                   /* 0x08 */
    struct BrNet *net;                   /* 0x0C */
    struct BrProcSysContext *proc;       /* 0x10 */
    struct GameData *gameData;           /* 0x14 */
    struct BrProcRecords *rec;           /* 0x18 battle record cache */
    int value1;                          /* 0x1C */
    int value2;                          /* 0x20 */
    int kind;                            /* 0x24 */
    int saved;                           /* 0x28 set when the screen saved the video */
    int savedSlot;                       /* 0x2C slot the video was saved to */
};

/* The record of the choice screens, 0x2C bytes. */
struct BrProcArgChoice {
    int mode;                            /* 0x00 */
    int reserved04;                      /* 0x04 */
    int selection;                       /* 0x08 option chosen on the screen, read by the next screen builders */
    int flag;                            /* 0x0C */
    struct BrFade *fade;                 /* 0x10 */
    struct Unit *unit;                   /* 0x14 */
    struct BrRes *res;                   /* 0x18 */
    struct BrProcSysContext *proc;       /* 0x1C */
    struct BrProcRecords *recA;          /* 0x20 battle record cache */
    u8 *recB;                            /* 0x24 */
    int *sharedFlag;                     /* 0x28 */
};

/* The record of the battle screens, 0x40 bytes. */
struct BrProcArgBattle {
    int result;                          /* 0x00 set when the screen hands a result back */
    int kind;                            /* 0x04 video kind: the header parameter 5 of the shown record, or 1 */
    int mode;                            /* 0x08 */
    struct BrFade *fade;                 /* 0x0C */
    struct BrRes *res;                   /* 0x10 */
    struct BrProcSysContext *proc;       /* 0x14 */
    struct Unit *unit;                   /* 0x18 */
    u32 value[2];                        /* 0x1C 64-bit value, low word first */
    struct BrNet *net;                   /* 0x24 */
    struct GameData *gameData;           /* 0x28 */
    s64 *recA;                           /* 0x2C */
    struct BrRecCache *recB;             /* 0x30 */
    int flag;                            /* 0x34 */
    struct BrProcRecords *rec;           /* 0x38 */
    int *recC;                           /* 0x3C */
};

/* The record of the type screens, 0x2C bytes. */
struct BrProcArgType {
    int mode;                            /* 0x00 */
    int flag;                            /* 0x04 */
    struct BrFade *fade;                 /* 0x08 */
    struct Unit *unit;                   /* 0x0C */
    struct BrRes *res;                   /* 0x10 */
    struct BrProcSysContext *proc;       /* 0x14 */
    struct BrNet *net;                   /* 0x18 */
    struct BrRecorderData *data;         /* 0x1C */
    u32 valueA;                          /* 0x20 */
    u32 valueB;                          /* 0x24 */
    struct BrTypeState *rec;             /* 0x28 */
};

/* The record of the zukan search screen (BR_PROC_SYS_CopyWordsA), 0x1C bytes. */
struct BrProcArgSearch {
    struct BrFade *fade;                 /* 0x00 */
    struct BrSidebar *sidebar;           /* 0x04 */
    struct BrGraphic *graphic;           /* 0x08 */
    struct BrRes *res;                   /* 0x0C */
    struct BrProcSysContext *proc;       /* 0x10 */
    struct BrNet *net;                   /* 0x14 */
    struct GameData *gameData;           /* 0x18 zukan save source */
};

/* The record of the download screen (BR_PROC_SYS_CopyWordsB): the search record plus the choice flag. */
struct BrProcArgDownload {
    struct BrFade *fade;                 /* 0x00 */
    struct BrSidebar *sidebar;           /* 0x04 */
    struct BrGraphic *graphic;           /* 0x08 */
    struct BrRes *res;                   /* 0x0C */
    struct BrProcSysContext *proc;       /* 0x10 */
    struct BrNet *net;                   /* 0x14 */
    struct GameData *gameData;           /* 0x18 zukan save source */
    int downloadMode;                    /* 0x1C 0 or 1, set when a choice is tapped */
};

#endif
