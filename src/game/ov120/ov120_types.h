#ifndef OV120_TYPES_H
#define OV120_TYPES_H

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
    void *rowAHandle;
    unsigned int rowBHandle;
    void *rowCHandle;
    void *messageWindow;
    void *extraWindow;
    void *rowWindow;
    unsigned char pad_3C[44];
    void *statusWindow;
    void *listWindow;
    unsigned char pad_70[16];
    void *lastListWindow;
    void *entryWindow;
    void *drawWindow;
    void *pairWindowTop;
    void *pairWindowBottom;
    void *tooltipWindow;
    void *singleWindow;
    void *printStream;
    void *tcbList;
    void *printQueue;
    void *menuEntryText0;
    unsigned short menuEntryColor0;
    unsigned char pad_AE[2];
    int menuEntryType0;
    void *menuEntryText1;
    unsigned short menuEntryColor1;
    unsigned char pad_BA[2];
    void *menuEntryType1;
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
    void *bgCharLayer7;
    void *touchbar;
    void *clactUnit;
    void *vblankTask;
    void *uiPalette;
    void *idlePalette;
    void *listPalette;
    void *cursorPalette;
    unsigned int uiChar;
    void *idleChar;
    void *listChars[16];
    void *cursorChar;
    unsigned int uiCellAnim;
    void *idleCellAnim;
    void *listCellAnims[16];
    void *cursorCellAnim;
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
    void *iconActor;
    unsigned char pad_144[8];
    void *listActorFirst;
    unsigned char pad_150[16];
    void *listActorLast;
};

/* Screen data loaded for the party tile rows; only the blank tile entry is read. */
struct GtsnegoTileScreen {
    unsigned char pad_0[62];
    unsigned short blankTile;
};

#endif
