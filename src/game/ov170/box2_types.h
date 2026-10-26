/*
 * Shared object layouts of the ov170 box application (box2_main.c, box2_ui.c,
 * box2_seq.c). Owner header: other files extend it, they do not copy it.
 *
 * BoxTask   the 0x30-byte task object that the proc table functions
 *           (Init 021DC860, Main 021DC900, Exit 021DC924) pass around.
 * BoxParam  the parent parameters behind BoxTask.params.
 * BoxWork   the work area behind BoxTask.work. Only offsets the code reads
 *           or writes are named; the gaps are padding between them.
 */
#ifndef OV170_BOX2_TYPES_H
#define OV170_BOX2_TYPES_H

struct Node;
struct PaletteFade;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct PrintSys;
struct Rec;
struct Sound;
struct TaskMenu;
struct BgWinFrmWork;
struct CursorMoveObj; /* the CURSOR_MOVE cursor object */
struct Sav;
struct GfFont;
struct Strbuf;
struct PrintQueue;
struct Cursor;
struct ClactActor;
struct BmpOamSys;

#include "../types.h"
#include "../arm9/app_taskmenu.h"

#include "box2_param_types.h"

/* The task object (0x30 bytes). */
typedef struct BoxTask {
    BoxParam * params;
    void * procSys;
    int subState;
    void * subArgs;
    unsigned short subResult;
    unsigned char pad_12;
    unsigned char menuMode;
    unsigned char curBox;
    unsigned char boxLimit;
    unsigned char cursorSlot;
    unsigned char heldSlot;
    unsigned char handMode;
    unsigned char prevBox;
    unsigned char phase;
    unsigned char barOpenFlag;
    unsigned char listState : 4;
    unsigned char exitFlag : 4;
    unsigned char listCursorId;
    unsigned char barFlag;
    unsigned char slot6Mode;
    unsigned char slot7Mode;
    unsigned char slot8Mode;
    unsigned char pad_22[0x2];
    int pickedSlot;
    int state;
    struct BoxWork * work;
} BoxTask;

/* A pointer with one word of data, eight bytes apart in BoxWork arrays. */
typedef struct BoxObjSlot {
    void * obj;
    void * aux;
} BoxObjSlot;

/* State block of the box UI scene, allocated into BoxWork.seq.entry (0xB8 bytes). */
typedef struct BoxUiScene {
    unsigned char pad_00[0xAC];
    unsigned int savedCursor;            /* cursor slot to restore when the scene closes */
    unsigned char pad_B0[0x8];
} BoxUiScene;

/* A step handler the box state machine runs each frame; 0 when none is installed. */
typedef int (*BoxSeqStepFunc)(struct BoxTask *task);

/* The sequence block at BoxWork + 0x58. */
typedef struct BoxSeq {
    BoxSeqStepFunc stepFunc;      /* handler StateRunStep calls until it returns 0 */
    BoxSeqStepFunc restartFunc;   /* handler BOX2_MAIN_RestartSeq installs again */
    void * entry;
    unsigned short state;
    unsigned short timer;
} BoxSeq;

typedef struct BoxFade {
    unsigned char flag : 1;
    unsigned char id : 7;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char state;
    unsigned char count;
    unsigned char x;
    unsigned char y;
    unsigned char w;
    unsigned char h;
} BoxFade;

/* A party or box slot reference passed to the box helpers. */
typedef struct BoxMonRef {
    unsigned short pad_0;
    unsigned short pos;
    unsigned short slot;
} BoxMonRef;

/* An archive-loaded screen resource; its data pointer sits at +0x14. */
typedef struct BoxArcRes {
    unsigned char pad_0[0x14];
    void * data;
} BoxArcRes;

/* An archive-loaded tile block; size at +0x10, data pointer at +0x14. */
typedef struct BoxArcTile {
    unsigned char pad_0[0x10];
    unsigned int size;
    void * data;
} BoxArcTile;

/* The NAMEIN_SETUP args object: done flag at +0x1C, text handle at +0x20. */
typedef struct BoxNameArgs {
    unsigned char pad_0[0x1C];
    unsigned int done;
    void * text;
} BoxNameArgs;

/* The BMP_OAM system handle. */
typedef struct BoxOamSys {
    struct BmpOamSys * sys;
} BoxOamSys;

/* A text list entry: index at +0x4, value at +0x6. */
typedef struct BoxTextEntry {
    unsigned char pad_0[0x4];
    unsigned short idx;
    unsigned short value;
} BoxTextEntry;

/* The scroll record: the cursor (index, flags) and the actor scale animation state (step, scale) share it. */
typedef struct BoxActorScale {
    void * actor;           /* 0x00 */
    unsigned short index;   /* 0x04 */
    unsigned char flags;    /* 0x06 */
    unsigned char step;     /* 0x07 */
    float scale;            /* 0x08 */
} BoxActorScale;

/* The whole flag word at BoxMotor + 0x18 (BoxMotor models it as two bits). */
typedef struct BoxMotorFlags {
    unsigned char pad_0[0x18];
    unsigned int flags;
} BoxMotorFlags;

typedef struct BoxWork {
    void * oamSys;
    BoxObjSlot oamSlots[9];
    unsigned int keyRepeatDelay;
    unsigned int keyRepeatInterval;
    struct TcbTask * vblankTask;
    BoxSeq seq;
    int waitFrames;
    void * palAnm;
    struct Cursor * cursorMove;
    struct BgWinFrmWork * winMgr;
    struct GfFont * font;
    struct GfFont * fontAlt;
    void * msgBank;
    struct WordSet * wordSet;
    struct Strbuf * strbuf;
    struct PrintQueue * printQue;
    unsigned char pad_90[0x4];
    BoxObjSlot windows[28];              /* 0x94: text windows; aux holds the dirty flag byte */
    unsigned char dirtyBits[4];          /* 0x174: one bit per window */
    int dexFormId;
    unsigned int nationalDexEnabled;
    unsigned short * formTable;
    struct TaskMenuItem taskMenuItems[2];
    void * taskMenuRes;
    void * taskMenu;
    unsigned short menuSelection;
    BoxFade fade;
    unsigned char pad_1AE[0x2];
    void * arcHandle;
    unsigned char iconTiles[30][0x200];  /* 0x1B4 */
    unsigned char iconPalette[30];       /* 0x3DB4 */
    unsigned char cursorTable[0x25];     /* slot actors, entry 0x24 is the hand slot */
    unsigned char pad_3DF7[1];
    int iconLoaded[30];                  /* 0x3DF8 */
    unsigned char charPool[24][0x400];
    void * clactUnit;
    struct ClactActor * actors[0x60];                 /* 0x9E74: CLACT actor slots */
    int charRes[0x45];                   /* 0x9FF4: CLACT character resource handles */
    int palRes[0xB];                     /* 0xA108: CLACT palette resource handles */
    int cellRes[0xC];                    /* 0xA134: CLACT cell animation resource handles */
    unsigned short toggle;
    unsigned char pad_A166[0x2];
    int heldSlot;
    unsigned short counter;
    unsigned short cursorIndex;
    unsigned char releaseFlag;
    unsigned char touchState;
    unsigned char cancelFlag;
    unsigned char result;
    unsigned int selectMask;
    signed char scrollOffset;
    unsigned char scrollDir;
    unsigned char busyFlag;
    unsigned char wallpaper;
    unsigned char selectKind;
    unsigned char pad_A17D[0x1];
    unsigned char targetBox;
    unsigned char currentBox;
    int cursorX;
    int cursorY;
    int wipeNextState;
    int count;
    void * scroll;
    int seqStep;
    int nextState;
} BoxWork;

typedef struct Box2Entry {
    unsigned short idx;
    unsigned short slot;
} Box2Entry;

/* Actor placement record read by BOX2_SEQ_CreateActorFromDesc (0x18 bytes). */
typedef struct {
    short x;
    short y;
    unsigned char pad4[2];
    unsigned char b6;
    unsigned char b7;
    int a;
    int b;
    int c;
    unsigned short e;
    unsigned short d;
} Box2SeqDesc;

#endif
