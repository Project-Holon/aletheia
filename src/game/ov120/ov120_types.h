#ifndef OV120_TYPES_H
#define OV120_TYPES_H

#include "../arm9/app_taskmenu.h"

struct GtsnegoMsgCtx;
struct GtsnegoActorSys;
struct GtsnegoTileScreen;

/* Text and window state of the negotiation screens (allocated by GTSNEGO_MSG_Create, 0xD0 bytes). */
struct GtsnegoMsgCtx {
    unsigned int sysFrameTiles;
    unsigned int windowFrameTiles;
    void *buttonMan;
    void *msgData;
    void *wordSet;
    void *font;
    void *srcText;
    void *windowText;
    void *expandedText;
    unsigned int rowAHandle;
    unsigned int rowBHandle;
    unsigned int rowCHandle;
    void *messageWindow;
    void *extraWindow;
    void *rowWindows[12];
    void *statusWindow;
    void *listWindows[6];
    void *entryWindow;
    void *drawWindow;
    void *pairWindowTop;
    void *pairWindowBottom;
    void *tooltipWindow;
    void *singleWindow;
    void *printStream;
    void *tcbList;
    void *printQueue;
    TaskMenuItem menuEntries[2];
    void *taskMenuRes;
    void *taskMenuWin;
    unsigned short heapId;
    unsigned char pad_CA[2];
    void *pmsDraw;
};

/* Sprite, palette and background resources of the negotiation screens (allocated by GTSNEGO_DISP_CreateMsgSystem, 0x164 bytes). */
struct GtsnegoActorSys {
    unsigned int bgCharLayer4;
    unsigned int bgCharLayer0;
    unsigned int bgCharLayer7;
    void *touchbar;
    void *clactUnit;
    void *vblankTask;
    int uiPalette;
    int idlePalette;
    int listPalette;
    int cursorPalette;
    unsigned int uiChar;
    int idleChar;
    int listChars[16];
    int cursorChar;
    unsigned int uiCellAnim;
    int idleCellAnim;
    int listCellAnims[16];
    int cursorCellAnim;
    unsigned char pad_C0[4];
    void *slotActors[12];
    unsigned short heapId;
    unsigned char pad_F6[2];
    void *blinkAnimA;
    void *blinkAnimB;
    int scrollDirty;
    int scrollOffset;
    int scrollState;
    unsigned int scrollTarget;
    unsigned int idleFadePos;
    unsigned int idleFadeActive;
    void *gameData;
    void *tileScreen;
    void *tileScreenBuf;
    void *savedObjPltt;
    void *savedBgPltt;
    void *idleFrameActor;
    void *idleCharActor;
    void *cursorActor;
    void *selectorActor;
    unsigned char pad_13C[4];
    void *iconActors[3];
    void *listActors[6];
};

/* Screen data loaded for the party tile rows; only the blank tile entry is read. */
struct GtsnegoTileScreen {
    unsigned char pad_0[62];
    unsigned short blankTile;
};

#endif
