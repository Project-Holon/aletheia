/*
 * Types of the union room drawing board (oekaki.c and the code behind it in
 * ov023).  The work is allocated in OEKAKI_Init (0x9E84 bytes) and is the
 * argument of every state step.  Fields at offsets that the code never reads
 * are padding; they keep the names pad<offset>.
 * Needs u8, u16, u32, s32 from the including file.
 * The including file also needs the opaque types used below declared
 * (struct BmpWin, ClActor, TextPrinter, TcbList, StrBuf, TaskMenu,
 * TaskMenuRes, WordSet, MsgBank, GfFont) and UnionAppWork/UnionAppEntry
 * from ../ov022/union_app_types.h.
 */
#ifndef OEKAKI_TYPES_H
#define OEKAKI_TYPES_H

#define OEKAKI_MEMBER_MAX      5      /* members of the drawing room */
#define OEKAKI_QUEUE_SIZE      100    /* stroke groups in the ring buffer */
#define OEKAKI_STROKE_COUNT_MAX 2     /* points a stroke record holds */
#define OEKAKI_WORK_SIZE       0x9E84
#define OEKAKI_CANVAS_BYTES    0x3840 /* 4 bit pixels of the drawing area */
#define OEKAKI_CHUNK_BYTES     1000   /* canvas bytes in one net chunk */

/* Net commands of the application (command table in the ov023 data). */
#define OEKAKI_CMD_CANVAS_CHUNK   0x2900
#define OEKAKI_CMD_STROKE         0x2901
#define OEKAKI_CMD_STROKES        0x2902
#define OEKAKI_CMD_MEMBER_JOINED  0x2903
#define OEKAKI_CMD_CANVAS_DONE    0x2904
#define OEKAKI_CMD_SYNC_MESSAGE   0x2905

/* OekakiSyncMsg.kind */
#define OEKAKI_SYNC_CHECK         0
#define OEKAKI_SYNC_STATUS        1

struct OekakiWork;

/* What the host passes to OEKAKI_Init. */
typedef struct OekakiParam {
    UnionAppWork *app;   /* 0x00 the union room application */
    void *gameData;      /* 0x04 owner of the save data the met-player list lives in */
} OekakiParam;

/* One stroke segment as it travels over the net (6 bytes). */
typedef struct StrokeRec {
    u8 startX;               /* 0x00 first point x (canvas x + 9) */
    u8 endX;               /* 0x01 last point x */
    u8 startY;               /* 0x02 first point y (canvas y + 0x11) */
    u8 endY;               /* 0x03 last point y */
    u8 color : 3;        /* 0x04 pen colour 0..7 */
    u8 count : 3;        /* 0x04 points in the record: 0 none, 1 dot, 2 line */
    u8 size : 2;         /* 0x04 pen size 0..2 */
    u8 syncMode;         /* 0x05 OekakiWork.syncMode of the sender (read from record 0 only) */
} StrokeRec;

/* Message of net command 0x2905, sent by the host and answered by the members (4 bytes). */
typedef struct OekakiSyncMsg {
    u8 netId;            /* 0x00 member that asked, then the member that is answered */
    u8 memberCount;      /* 0x01 members the sender counts */
    u8 kind;             /* 0x02 0 membership check, 1 status */
    u8 accepted;         /* 0x03 answer of the host: 1 the membership agrees */
} OekakiSyncMsg;

/* A part of the canvas as it travels over the net (0x3F0 bytes, net command 0x2900). */
typedef struct CanvasChunk {
    u8  data[OEKAKI_CHUNK_BYTES]; /* 0x000 */
    u32 checksum;                 /* 0x3E8 xor of the data words */
    u8  index;                    /* 0x3EC number of the chunk */
    u8  pad3ED[3];
} CanvasChunk;

/* One record per member (30 bytes). */
typedef struct StrokeGroup {
    StrokeRec rec[OEKAKI_MEMBER_MAX];
} StrokeGroup;

/* Ring buffer of the strokes waiting to be sent (head = next to send, tail = next to fill). */
typedef struct StrokeQueue {
    StrokeGroup group[OEKAKI_QUEUE_SIZE];  /* 0x000 */
    int head;                              /* 0xBB8 */
    int tail;                              /* 0xBBC */
} StrokeQueue;

/* One sampled touch point; element 0 also holds the number of valid points. */
typedef struct TouchPoint {
    u16 count;
    u16 x;
    u16 y;
    u16 pad;
} TouchPoint;

typedef struct TouchPath {
    TouchPoint pt[8];
    u16 tail;
} TouchPath;

/* Last point of the stroke a member drew in the previous frame. */
typedef struct LastPoint {
    u8  x;
    u8  y;
    u16 count;           /* number of points of that stroke */
} LastPoint;

/* A text window that is printed asynchronously. */
typedef struct PrintJob {
    struct BmpWin *window;
    u8 busy;             /* the printer still works on the window */
} PrintJob;

/* Entry of the member list, kept for two frames to detect changes. */
typedef struct MemberSlot {
    UnionAppEntry *current;   /* 0x00 */
    UnionAppEntry *previous;  /* 0x04 */
} MemberSlot;

/* One item of the yes/no menu. */
typedef struct MenuItem {
    StrBuf *text;        /* 0x00 */
    u16 color;           /* 0x04 */
    u32 result;          /* 0x08 value the menu returns for this item */
} MenuItem;

/* Template of the yes/no menu. */
typedef struct MenuTemplate {
    u32 heapId;          /* 0x00 */
    u8  itemCount;       /* 0x04 */
    u8  pad05[3];
    MenuItem *items;     /* 0x08 */
    u32 flags;           /* 0x0C */
    u8  x;               /* 0x10 */
    u8  y;               /* 0x11 */
    u8  width;           /* 0x12 */
    u8  height;          /* 0x13 */
} MenuTemplate;

/* Resources of one sprite set: character, palette and cell data. */
typedef struct SpriteResSet {
    s32 plttRes;         /* 0x00 loaded second, passed second to the actor creation */
    s32 charRes;         /* 0x04 loaded first, passed first to the actor creation */
    s32 cellRes;         /* 0x08 */
} SpriteResSet;

typedef struct OekakiWork {
    u8  pad00[4];
    OekakiParam *param;              /* 0x004 */
    void *vblankTask;                /* 0x008 task that runs every vertical blank */
    void *font;                      /* 0x00C GfFont */
    struct WordSet *wordSet;         /* 0x010 */
    struct MsgBank *msgBank;         /* 0x014 */
    StrBuf *playerName[OEKAKI_MEMBER_MAX]; /* 0x018 name of each member */
    StrBuf *labelText;               /* 0x02C message 7, 10 characters */
    StrBuf *messageText;             /* 0x030 expanded message */
    u8  pad34[4];
    void *clactSys;                  /* 0x038 */
    SpriteResSet cursorRes;          /* 0x03C */
    SpriteResSet buttonRes;          /* 0x048 */
    SpriteResSet nameTagRes;         /* 0x054 */
    ClActor *cursorActor[OEKAKI_MEMBER_MAX];  /* 0x060 pen cursor of each member */
    u8  pad74[0x98 - 0x74];
    ClActor *nameTagActor[OEKAKI_MEMBER_MAX]; /* 0x098 shown while the member is present */
    u8  padAC[0xD0 - 0xAC];
    ClActor *colorButton[8];         /* 0x0D0 */
    ClActor *clearButton;            /* 0x0F0 */
    ClActor *sizeButton[3];          /* 0x0F4 */
    ClActor *quitButton;             /* 0x100 */
    struct BmpWin *nameWindow[OEKAKI_MEMBER_MAX]; /* 0x104 */
    struct BmpWin *canvasWindow;     /* 0x118 */
    struct BmpWin *messageWindow;    /* 0x11C */
    u8  pad120[0xC];
    PrintJob printJob[7];            /* 0x12C 0..4 name plates, 6 message window */
    TextPrinter *namePrinter;        /* 0x164 */
    TextPrinter *messagePrinter;     /* 0x168 */
    void *messageStream;             /* 0x16C running message print, 0 if none */
    TcbList *taskList;               /* 0x170 */
    TaskMenuRes *menuRes;            /* 0x174 */
    TaskMenu *menu;                  /* 0x178 yes/no menu, 0 if closed */
    MenuItem menuItem[2];            /* 0x17C */
    int state;                       /* 0x194 state of the main step */
    int scene;                       /* 0x198 current step (index of the step table) */
    int nextScene;                   /* 0x19C */
    u8  pad1A0[4];
    int timer;                       /* 0x1A4 frame counter of the waiting steps */
    int lastMemberCount;             /* 0x1A8 */
    int baseMemberCount;             /* 0x1AC member count when the canvas was last synced */
    int baseJoinedBits;              /* 0x1B0 joined bits when the canvas was last synced */
    int painterNetId;                /* 0x1B4 */
    u8  pad1B8[0x10];
    MemberSlot memberSlot[OEKAKI_MEMBER_MAX]; /* 0x1C8 */
    u8  pad1F0[0x4208 - 0x1F0];
    u16 paletteAngle;                /* 0x4208 */
    u8  penColor;                    /* 0x420A */
    u8  penSize;                     /* 0x420B */
    StrokeRec localStroke;           /* 0x420C stroke of this frame, sent to the host */
    StrokeRec remoteStroke[OEKAKI_MEMBER_MAX]; /* 0x4212 strokes of all members, from the host */
    LastPoint lastPoint[OEKAKI_MEMBER_MAX];    /* 0x4230 */
    TouchPath touchPath;             /* 0x4244 */
    u8  pad4286[2];
    void *tempBuf;                   /* 0x4288 */
    int nextChunk;                   /* 0x428C next canvas chunk to send */
    u8  canvas[OEKAKI_CANVAS_BYTES]; /* 0x4290 */
    CanvasChunk sendChunk;           /* 0x7AD0 */
    CanvasChunk recvChunk[OEKAKI_MEMBER_MAX]; /* 0x7EC0 */
    u32 pendingCommand;              /* 0x9270 net command waiting to be sent, 0 none */
    u8  pendingArg;                  /* 0x9274 */
    u8  pad9275[3];
    OekakiSyncMsg stateMsg;          /* 0x9278 payload of command 0x2905 */
    int waitMemberCount;             /* 0x927C */
    int waitMemberBits;              /* 0x9280 */
    u16 agreedMemberCount;           /* 0x9284 */
    u16 waitFrames;                  /* 0x9286 */
    u16 quitting;                    /* 0x9288 */
    u16 canvasReceived;              /* 0x928A the host sent the whole canvas */
    StrokeQueue strokeQueue;         /* 0x928C */
    StrokeGroup sendPacket;          /* 0x9E4C group sent to the members */
    u8  pad9E6A[2];
    int syncMode;                    /* 0x9E6C 1 normal, 2 a new member needs the canvas */
    int menuOpen;                    /* 0x9E70 */
    int leaveRequested;              /* 0x9E74 */
    int memberLeft;                  /* 0x9E78 */
    int newMemberPending;            /* 0x9E7C */
    int newMemberBits;               /* 0x9E80 */
} OekakiWork;

/* Entry of the scene table (indexed by OekakiWork.scene). */
typedef struct OekakiSceneStep {
    int (*handler)(OekakiWork *work, int state);
    void *runsInWait;    /* not 0: the handler also runs in main state 2 */
} OekakiSceneStep;

#endif
