#ifndef BTLV_INPUT_SHARED_TYPES_H
#define BTLV_INPUT_SHARED_TYPES_H

#include "btlv_effvm_types.h"

struct Cfg;

typedef struct { char pad[0x68]; unsigned int f68; } W_02206710;

typedef struct { s16 x, y, z; u8 pri, f7; } Cfg;

/* State word at BtlvInput+0x68. */
typedef struct BtlvInputFlags {
    u32 busy : 1;           /* a screen change is running; input is ignored */
    u32 animTasks : 3;      /* number of running animation tasks */
    u32 restrictedChoice : 1;
    u32 cursor : 4;         /* highlighted button */
    u32 prevCursor : 4;     /* 0xF: none */
    u32 redraw : 1;
    u32 doubleCursor : 1;   /* second cursor actor set in use */
    u32 fadeKind : 2;       /* 1: palette fade running, 2: screen fade running */
    u32 bits17 : 2;
    u32 slotIndex : 2;      /* which own Pokemon is selecting */
    u32 bits21 : 2;
    u32 fingerStep : 4;
    u32 fingerPos : 4;
    u32 inputLock : 1;
} BtlvInputFlags;

/* Second state word at BtlvInput+0x6c. */
typedef struct BtlvInputFlags2 {
    u32 inputEnabled : 1;
    u32 choiceMade : 1;
    u32 targetGroup : 8;
    u32 reserved : 22;
} BtlvInputFlags2;

typedef union BtlvInputSlotInfo {
    int w[3];
    struct { u8 unk0; u8 animSeq; u8 unk2[10]; } b;
} BtlvInputSlotInfo;

typedef struct BtlvInputActor {
    void *actor;
    int unk4;
} BtlvInputActor;

/* Work of the battle bottom-screen input (command, move, target... screens). */
typedef struct BtlvInput {
    /* 0x00 */ void *taskMgr;
    /* 0x04 */ void *taskMgrMem;
    /* 0x08 */ void *tasks[8];
    /* 0x28 */ void (*taskEnd[8])(void *);
    /* 0x48 */ void *arc;
    /* 0x4c */ void *infoWinParam;
    /* 0x50 */ int battleType;          /* 0 single, 1 double, 2 triple, 3 multi */
    /* 0x54 */ int seMode;              /* 3: sound effects muted */
    /* 0x58 */ int screen;
    /* 0x5c */ void *msgData;
    /* 0x60 */ void *fingerCursor;
    /* 0x64 */ void *palAnm;
    /* 0x68 */ BtlvInputFlags flags;
    /* 0x6c */ BtlvInputFlags2 flags2;
    /* 0x70 */ int pending;
    /* 0x74 */ BtlvInputSlotInfo slotInfo[2][6];
    /* 0x104 */ int resCommonChr;
    /* 0x108 */ int resCommonPal;
    /* 0x10c */ int resCommonCell;
    /* 0x110 */ int resButtonChr;
    /* 0x114 */ int resButtonCell;
    /* 0x118 */ void *unitButtons;
    /* 0x11c */ BtlvInputActor cursorA[6];
    /* 0x14c */ BtlvInputActor cursorB[6];
    /* 0x17c */ void *unitCursors;
    /* 0x180 */ BtlvInputActor targets[6];
    /* 0x1b0 */ int pokeChr[3];
    /* 0x1bc */ int pokePal;
    /* 0x1c0 */ int pokeCell;
    /* 0x1c4 */ void *unitPoke;
    /* 0x1c8 */ BtlvInputActor pokeIcons[3];
    /* 0x1e0 */ int typeChr[4];
    /* 0x1f0 */ int typePal;
    /* 0x1f4 */ int typeCell;
    /* 0x1f8 */ void *unitWaza;
    /* 0x1fc */ void *wazaActors[4];
    /* 0x20c */ void *unitStatus;
    /* 0x210 */ void *statusActors[2];
    /* 0x218 */ void *unitBack;
    /* 0x21c */ void *backActor;
    /* 0x220 */ int struggle;           /* 1: no usable move */
    /* 0x224 */ void *font;
    /* 0x228 */ void *bmpWinA;
    /* 0x22c */ void *bmpA;
    /* 0x230 */ void *bmpWinB;
    /* 0x234 */ void *bmpB;
    /* 0x238 */ void *infoWinTask;
    /* 0x23c */ int infoWinEnabled;
    /* 0x240 */ u16 heap;
    /* 0x242 */ u8 lastChoice[3][8];
    /* 0x25a */ u8 enabled[8];
    /* 0x262 */ u8 enabled2[4];
    /* 0x266 */ u16 lastMove[3];
    /* 0x26c */ u16 moveIds[4];
    /* 0x274 */ u8 *cursorVisible;
    /* 0x278 */ int battlePos;
    /* 0x27c */ int partyIdx;
    /* 0x280 */ int transformed;
    /* 0x284 */ u16 palBackup[16];
    /* 0x2a4 */ void *pokeParam[3];
    /* 0x2b0 */ int moveFlags[3][4];
} BtlvInput;

typedef char BtlvInputSizeCheck[(sizeof(BtlvInput) == 0x2e0) ? 1 : -1];

typedef char BtlvInputOff_taskMgr[((int)&((BtlvInput *)0)->taskMgr == 0x0) ? 1 : -1];
typedef char BtlvInputOff_arc[((int)&((BtlvInput *)0)->arc == 0x48) ? 1 : -1];
typedef char BtlvInputOff_screen[((int)&((BtlvInput *)0)->screen == 0x58) ? 1 : -1];
typedef char BtlvInputOff_palAnm[((int)&((BtlvInput *)0)->palAnm == 0x64) ? 1 : -1];
typedef char BtlvInputOff_flags[((int)&((BtlvInput *)0)->flags == 0x68) ? 1 : -1];
typedef char BtlvInputOff_flags2[((int)&((BtlvInput *)0)->flags2 == 0x6c) ? 1 : -1];
typedef char BtlvInputOff_pending[((int)&((BtlvInput *)0)->pending == 0x70) ? 1 : -1];
typedef char BtlvInputOff_slotInfo[((int)&((BtlvInput *)0)->slotInfo == 0x74) ? 1 : -1];
typedef char BtlvInputOff_resCommonChr[((int)&((BtlvInput *)0)->resCommonChr == 0x104) ? 1 : -1];
typedef char BtlvInputOff_unitButtons[((int)&((BtlvInput *)0)->unitButtons == 0x118) ? 1 : -1];
typedef char BtlvInputOff_cursorA[((int)&((BtlvInput *)0)->cursorA == 0x11c) ? 1 : -1];
typedef char BtlvInputOff_cursorB[((int)&((BtlvInput *)0)->cursorB == 0x14c) ? 1 : -1];
typedef char BtlvInputOff_unitCursors[((int)&((BtlvInput *)0)->unitCursors == 0x17c) ? 1 : -1];
typedef char BtlvInputOff_targets[((int)&((BtlvInput *)0)->targets == 0x180) ? 1 : -1];
typedef char BtlvInputOff_pokeChr[((int)&((BtlvInput *)0)->pokeChr == 0x1b0) ? 1 : -1];
typedef char BtlvInputOff_pokePal[((int)&((BtlvInput *)0)->pokePal == 0x1bc) ? 1 : -1];
typedef char BtlvInputOff_unitPoke[((int)&((BtlvInput *)0)->unitPoke == 0x1c4) ? 1 : -1];
typedef char BtlvInputOff_pokeIcons[((int)&((BtlvInput *)0)->pokeIcons == 0x1c8) ? 1 : -1];
typedef char BtlvInputOff_typeChr[((int)&((BtlvInput *)0)->typeChr == 0x1e0) ? 1 : -1];
typedef char BtlvInputOff_unitWaza[((int)&((BtlvInput *)0)->unitWaza == 0x1f8) ? 1 : -1];
typedef char BtlvInputOff_wazaActors[((int)&((BtlvInput *)0)->wazaActors == 0x1fc) ? 1 : -1];
typedef char BtlvInputOff_unitStatus[((int)&((BtlvInput *)0)->unitStatus == 0x20c) ? 1 : -1];
typedef char BtlvInputOff_unitBack[((int)&((BtlvInput *)0)->unitBack == 0x218) ? 1 : -1];
typedef char BtlvInputOff_struggle[((int)&((BtlvInput *)0)->struggle == 0x220) ? 1 : -1];
typedef char BtlvInputOff_font[((int)&((BtlvInput *)0)->font == 0x224) ? 1 : -1];
typedef char BtlvInputOff_infoWinTask[((int)&((BtlvInput *)0)->infoWinTask == 0x238) ? 1 : -1];
typedef char BtlvInputOff_heap[((int)&((BtlvInput *)0)->heap == 0x240) ? 1 : -1];
typedef char BtlvInputOff_lastChoice[((int)&((BtlvInput *)0)->lastChoice == 0x242) ? 1 : -1];
typedef char BtlvInputOff_enabled[((int)&((BtlvInput *)0)->enabled == 0x25a) ? 1 : -1];
typedef char BtlvInputOff_lastMove[((int)&((BtlvInput *)0)->lastMove == 0x266) ? 1 : -1];
typedef char BtlvInputOff_moveIds[((int)&((BtlvInput *)0)->moveIds == 0x26c) ? 1 : -1];
typedef char BtlvInputOff_cursorVisible[((int)&((BtlvInput *)0)->cursorVisible == 0x274) ? 1 : -1];
typedef char BtlvInputOff_battlePos[((int)&((BtlvInput *)0)->battlePos == 0x278) ? 1 : -1];
typedef char BtlvInputOff_transformed[((int)&((BtlvInput *)0)->transformed == 0x280) ? 1 : -1];
typedef char BtlvInputOff_palBackup[((int)&((BtlvInput *)0)->palBackup == 0x284) ? 1 : -1];
typedef char BtlvInputOff_pokeParam[((int)&((BtlvInput *)0)->pokeParam == 0x2a4) ? 1 : -1];
typedef char BtlvInputOff_moveFlags[((int)&((BtlvInput *)0)->moveFlags == 0x2b0) ? 1 : -1];

/* Context of the screen change tasks (0x24 bytes). */
typedef struct BtlvInputTask {
    BtlvInput *input;
    int state;
    int slot;
    int bgFile;
    int scrollX;
    int scrollY;
    int timer;
    void *text;
    int fromScreen;
} BtlvInputTask;

#endif
