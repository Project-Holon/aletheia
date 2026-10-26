#ifndef BTLV_INPUT_SHARED_TYPES_H
#define BTLV_INPUT_SHARED_TYPES_H

#include "../arm9/palanm.h"
#include "../ov094/btlv_effvm_types.h"

typedef struct BtlvInputTouchTable {
    void *key;          /* 0x00 */
    int reserved04;
    int *vals;          /* 0x08 */
} BtlvInputTouchTable;

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
    struct { u8 kind; u8 animSeq; u8 data[10]; } b;
} BtlvInputSlotInfo;

typedef struct BtlvInputActor {
    void *actor;
    int unused;
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
    /* 0x64 */ PaletteFade *palAnm;
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

typedef char BtlvInputOff_taskMgr[(BW_OFFSETOF(BtlvInput, taskMgr) == 0x0) ? 1 : -1];
typedef char BtlvInputOff_arc[(BW_OFFSETOF(BtlvInput, arc) == 0x48) ? 1 : -1];
typedef char BtlvInputOff_screen[(BW_OFFSETOF(BtlvInput, screen) == 0x58) ? 1 : -1];
typedef char BtlvInputOff_palAnm[(BW_OFFSETOF(BtlvInput, palAnm) == 0x64) ? 1 : -1];
typedef char BtlvInputOff_flags[(BW_OFFSETOF(BtlvInput, flags) == 0x68) ? 1 : -1];
typedef char BtlvInputOff_flags2[(BW_OFFSETOF(BtlvInput, flags2) == 0x6c) ? 1 : -1];
typedef char BtlvInputOff_pending[(BW_OFFSETOF(BtlvInput, pending) == 0x70) ? 1 : -1];
typedef char BtlvInputOff_slotInfo[(BW_OFFSETOF(BtlvInput, slotInfo) == 0x74) ? 1 : -1];
typedef char BtlvInputOff_resCommonChr[(BW_OFFSETOF(BtlvInput, resCommonChr) == 0x104) ? 1 : -1];
typedef char BtlvInputOff_unitButtons[(BW_OFFSETOF(BtlvInput, unitButtons) == 0x118) ? 1 : -1];
typedef char BtlvInputOff_cursorA[(BW_OFFSETOF(BtlvInput, cursorA) == 0x11c) ? 1 : -1];
typedef char BtlvInputOff_cursorB[(BW_OFFSETOF(BtlvInput, cursorB) == 0x14c) ? 1 : -1];
typedef char BtlvInputOff_unitCursors[(BW_OFFSETOF(BtlvInput, unitCursors) == 0x17c) ? 1 : -1];
typedef char BtlvInputOff_targets[(BW_OFFSETOF(BtlvInput, targets) == 0x180) ? 1 : -1];
typedef char BtlvInputOff_pokeChr[(BW_OFFSETOF(BtlvInput, pokeChr) == 0x1b0) ? 1 : -1];
typedef char BtlvInputOff_pokePal[(BW_OFFSETOF(BtlvInput, pokePal) == 0x1bc) ? 1 : -1];
typedef char BtlvInputOff_unitPoke[(BW_OFFSETOF(BtlvInput, unitPoke) == 0x1c4) ? 1 : -1];
typedef char BtlvInputOff_pokeIcons[(BW_OFFSETOF(BtlvInput, pokeIcons) == 0x1c8) ? 1 : -1];
typedef char BtlvInputOff_typeChr[(BW_OFFSETOF(BtlvInput, typeChr) == 0x1e0) ? 1 : -1];
typedef char BtlvInputOff_unitWaza[(BW_OFFSETOF(BtlvInput, unitWaza) == 0x1f8) ? 1 : -1];
typedef char BtlvInputOff_wazaActors[(BW_OFFSETOF(BtlvInput, wazaActors) == 0x1fc) ? 1 : -1];
typedef char BtlvInputOff_unitStatus[(BW_OFFSETOF(BtlvInput, unitStatus) == 0x20c) ? 1 : -1];
typedef char BtlvInputOff_unitBack[(BW_OFFSETOF(BtlvInput, unitBack) == 0x218) ? 1 : -1];
typedef char BtlvInputOff_struggle[(BW_OFFSETOF(BtlvInput, struggle) == 0x220) ? 1 : -1];
typedef char BtlvInputOff_font[(BW_OFFSETOF(BtlvInput, font) == 0x224) ? 1 : -1];
typedef char BtlvInputOff_infoWinTask[(BW_OFFSETOF(BtlvInput, infoWinTask) == 0x238) ? 1 : -1];
typedef char BtlvInputOff_heap[(BW_OFFSETOF(BtlvInput, heap) == 0x240) ? 1 : -1];
typedef char BtlvInputOff_lastChoice[(BW_OFFSETOF(BtlvInput, lastChoice) == 0x242) ? 1 : -1];
typedef char BtlvInputOff_enabled[(BW_OFFSETOF(BtlvInput, enabled) == 0x25a) ? 1 : -1];
typedef char BtlvInputOff_lastMove[(BW_OFFSETOF(BtlvInput, lastMove) == 0x266) ? 1 : -1];
typedef char BtlvInputOff_moveIds[(BW_OFFSETOF(BtlvInput, moveIds) == 0x26c) ? 1 : -1];
typedef char BtlvInputOff_cursorVisible[(BW_OFFSETOF(BtlvInput, cursorVisible) == 0x274) ? 1 : -1];
typedef char BtlvInputOff_battlePos[(BW_OFFSETOF(BtlvInput, battlePos) == 0x278) ? 1 : -1];
typedef char BtlvInputOff_transformed[(BW_OFFSETOF(BtlvInput, transformed) == 0x280) ? 1 : -1];
typedef char BtlvInputOff_palBackup[(BW_OFFSETOF(BtlvInput, palBackup) == 0x284) ? 1 : -1];
typedef char BtlvInputOff_pokeParam[(BW_OFFSETOF(BtlvInput, pokeParam) == 0x2a4) ? 1 : -1];
typedef char BtlvInputOff_moveFlags[(BW_OFFSETOF(BtlvInput, moveFlags) == 0x2b0) ? 1 : -1];

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
