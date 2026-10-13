/*
 * Types of overlay 83, the G-Power events: activating a G-Power, the flash
 * and sound that go with it, and the window that lists the active G-Powers
 * with their minutes left. Needs u8, u16, u32 and s32 from the including
 * file.
 */
#ifndef UNIT_021F5260_TYPES_H
#define UNIT_021F5260_TYPES_H

struct GameSystem;
struct GameData;
struct FieldMap;
struct FieldMsgBg;
struct FldMmdlSys;
struct InfoMsgWin;
struct InfoSysWin;
struct MsgData;
struct WordSet;
struct GPowerTable;
struct Strbuf;

/* Power id that means "no G-Power". Valid ids are 0 to 0x2D. */
#define GPOWER_ID_NONE      0x30
#define GPOWER_ID_LAST      0x2D

/* Heap of the events, and the same heap allocating from the end. */
#define GPOWER_EVENT_HEAP_ID        0x15
#define GPOWER_EVENT_HEAP_ID_BACK   0x8015

/* Item that pays for a G-Power. */
#define GPOWER_COST_ITEM_ID 0x23F

/* Parameter of the activate event, passed through the overlay's create function. */
typedef struct GPowerActivateParam {
    int powerId;        /* 0x00: ids above GPOWER_ID_LAST become 0 */
    int payWithItems;   /* 0x04: not 0 = take the power's cost in items */
} GPowerActivateParam;

/* Work of the flash event (0x0C bytes). Written when the event starts; the event function reads neither field. */
typedef struct GPowerFlashWork {
    u32 pad0;
    struct GameSystem *gameSystem;  /* 0x04 */
    struct GameData *gameData;      /* 0x08 */
} GPowerFlashWork;

/* Work of the list event (0x3C bytes): the window that lists the active G-Powers. */
typedef struct GPowerListWork {
    u16 pad0;
    u16 heapId;                         /* 0x02 */
    u16 heapIdBack;                     /* 0x04: heapId with the high bit set */
    u16 pad6;
    struct GameSystem *gameSystem;      /* 0x08 */
    struct GameData *gameData;          /* 0x0C */
    struct FieldMap *fieldMap;          /* 0x10 */
    struct FieldMsgBg *msgBg;           /* 0x14 */
    struct InfoMsgWin *infoMsgWin;      /* 0x18: the list text */
    struct FldMmdlSys *mmdlSys;         /* 0x1C: field objects, paused while the list shows */
    struct InfoSysWin *infoSysWin;      /* 0x20: opening window */
    u32 pad24;
    struct MsgData *msgData;            /* 0x28 */
    struct WordSet *wordSet;            /* 0x2C */
    struct GPowerTable *powerTable;     /* 0x30 */
    struct Strbuf *templateStr;         /* 0x34: message template */
    struct Strbuf *lineStr;             /* 0x38: expanded line */
} GPowerListWork;

#endif
