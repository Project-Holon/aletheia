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

#include "../types.h"

/* Parameters handed to the box application by its parent. */
typedef struct BoxParam {
    void * gameData;
    void * boxSave;
    void * party;
    void * config;
    unsigned char pad_10[0x4];
    int linkMode;
    unsigned char pad_18[0x8];
    void * extra;
    int mode;
    unsigned short swapMode;
    unsigned char savedBox;
    unsigned char savedSlot;
} BoxParam;

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

/* The sequence block at BoxWork + 0x58. */
typedef struct BoxSeq {
    int resetValue;
    int param;
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
    int sys;
} BoxOamSys;

/* A text list entry: index at +0x4, value at +0x6. */
typedef struct BoxTextEntry {
    unsigned char pad_0[0x4];
    unsigned short idx;
    unsigned short value;
} BoxTextEntry;

/* An actor scale animation state: step at +0x7, scale at +0x8. */
typedef struct BoxActorScale {
    void * actor;
    unsigned char pad_4[0x3];
    unsigned char step;
    float scale;
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
    void * cursorMove;
    struct BgWinFrmWork * winMgr;
    unsigned int font;
    void * fontAlt;
    void * msgBank;
    struct WordSet * wordSet;
    void * strbuf;
    void * printQue;
    unsigned char pad_90[0x4];
    BoxObjSlot windows[10];
    BoxObjSlot iconSlots[10];
    int portraitWin;
    unsigned char pad_138[0x4];
    int nameWin;
    unsigned char pad_140[0x4];
    void * infoWin;
    unsigned char pad_148[0x30];
    int dexFormId;
    unsigned int nationalDexEnabled;
    unsigned short * formTable;
    unsigned char taskMenuItems[24];
    void * taskMenuRes;
    void * taskMenu;
    unsigned short menuSelection;
    BoxFade fade;
    unsigned char pad_1AE[0x2];
    void * arcHandle;
    unsigned char pad_1B4[0x3C1E];
    unsigned char cursorTable[0x24];
    unsigned char cursorActorId;
    unsigned char pad_3DF7[0x79];
    unsigned char charPool[24][0x400];
    void * clactUnit;
    void * actors[10];
    void * cursorActor;
    int cursorActorDrawn;
    int cursorActorAnim;
    unsigned char pad_9EA8[0x80];
    void * partyActors[6];
    void * boxSlotActors[0x25];
    void * actorResource;
    unsigned char pad_9FD8[0xB0];
    int iconChar[2];
    unsigned char pad_A090[0x68];
    void * iconCellRes;
    unsigned char pad_A0FC[0xC];
    void * iconAnimRes;
    int iconCell[2];
    void * iconPlttRes;
    unsigned char pad_A118[0x8];
    unsigned int iconFlags;
    void * iconCharRes;
    unsigned char pad_A128[0xC];
    void * iconPlttImage;
    int iconAnim[2];
    unsigned char pad_A140[0x14];
    void * iconObjects;
    unsigned char pad_A158[0xC];
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
    unsigned char pad_A17B[0x1];
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

#endif
