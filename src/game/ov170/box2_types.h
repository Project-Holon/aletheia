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
struct PalAnmSlot;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct PrintSys;
struct Rec;
struct Sound;
struct TaskMenu;
struct WinMgr;
struct Struct_02025CD0;
struct Sav;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed int s32;

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
    unsigned char b13;
    unsigned char curBox;
    unsigned char boxLimit;
    unsigned char cursorSlot;
    unsigned char heldSlot;
    unsigned char b18;
    unsigned char b19;
    unsigned char phase;
    unsigned char b1B;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char b1D;
    unsigned char b1E;
    unsigned char b1F;
    unsigned char b20;
    unsigned char b21;
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

typedef struct BoxWork {
    void * oamSys;
    BoxObjSlot oamSlots[9];
    unsigned int keyRepeatDelay;
    unsigned int keyRepeatInterval;
    void * vblankTask;
    BoxSeq seq;
    int waitFrames;
    void * palAnm;
    void * sound;
    struct WinMgr * winMgr;
    unsigned int heapId;
    unsigned char pad_7C[0x4];
    void * fontRes;
    void * font;
    void * msgData;
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
    unsigned char cursorTable;
    unsigned char pad_3DD3[0x23];
    unsigned char cursorActorId;
    unsigned char pad_3DF7[0x79];
    unsigned char charPool[24][0x400];
    int clactUnit;
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
    unsigned char pad_A188[0x8];
    void * scroll;
    int seqStep;
    int nextState;
} BoxWork;

typedef struct Entry {
    unsigned short idx;
    unsigned short slot;
} Entry;

#endif
