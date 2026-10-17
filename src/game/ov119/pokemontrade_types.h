#ifndef POKEMONTRADE_TYPES_H
#define POKEMONTRADE_TYPES_H

/* Fixed-point position used by the icon flight path. */
typedef struct { int x, y, z; } VecFx32;

/* 20.12 fixed-point cubic Bezier curve used to fly an icon to the box. */
typedef struct BezierCurve {
    VecFx32 out;
    VecFx32 p[4];
    int idx;
    int count;
} BezierCurve;

/*
 * Cross-overlay trade request. A caller overlay (ov117/ov118) allocates it and
 * passes it to POKETRADE_PROC_StartRequestN. Overlay 119 keeps it at
 * TradeWork::request and reads/writes its state while the request runs.
 */
struct TradeRequest {
    unsigned char pad_0[8];
    int state;                  /* 0x08: 0 idle, 1 cancel requested, 3 finished */
    unsigned int evolveResult;  /* 0x0C: SHINKA_CHECK result */
    unsigned int evolveOut;     /* 0x10: SHINKA_CHECK output */
    void * gameData;            /* 0x14: GAME_DATA handle */
    void * context;             /* 0x18: struct TradeContext */
    void * party;               /* 0x1C: POKEPARTY handle */
    unsigned char pad_20[4];
    int httpParam;              /* 0x24: third argument of NHTTP_RAP_Create */
    unsigned short box;         /* 0x28 */
    unsigned short slot;        /* 0x2A */
    unsigned char pad_2C[2];
    unsigned short setupParam;  /* 0x2E: second argument of SetupGameData (unused) */
    void * gameDataSource;      /* 0x30: gameData for the McssPokemon request types */
    void * monA;                /* 0x34: first party mon data */
    void * monB;                /* 0x38: second party mon data */
    int trainerValue;           /* 0x3C: copied to TradeWork::f830 */
    int playerStatus;           /* 0x40: copied to TradeWork::f834 */
};

/* Trade context pointed to by TradeRequest::context. */
struct TradeContext {
    unsigned char pad_0[432];
    int entryCount;             /* 0x1B0 */
};

/* One embedded UI scene slot; a CLACT actor handle lives at 0x10. */
struct UiScene {
    unsigned char pad_0[16];
    void * actor;               /* 0x10 */
};

/* Graphic load result written by ARC_UTIL_LoadBgCharDataFromHandle; the data pointer is at 0x14. */
struct GfxLoadResult {
    unsigned char pad_0[20];
    void * data;                /* 0x14 */
};

/* Work area of the Pokemon trade scene (overlay 119). One object, fields by byte offset. */
typedef struct TradeWork {
    void * httpRap;
    unsigned char pad_4[4];
    struct TradeRequest * request;
    struct ParticleManager * particleManager;
    unsigned char pad_10[1452];
    int  statusWin0;
    int  statusWin1;
    unsigned char pad_5C4[16];
    int  nameRowWin;
    int  valueRowWin;
    void * monABuf;
    void * monBBuf;
    unsigned char pad_5E4[8];
    int  stepFunc;
    void * timeIcon;
    unsigned short  heapId;
    unsigned char pad_5F6[22];
    void * saveControlBackup;
    void * trainerRecordBackup;
    void * savedSaveControl;
    void * savedZukan;
    void * savedBlock1F;
    void * partyBackup;
    void * boxBackup;
    unsigned char pad_628[4];
    int  boxSaveDirty;
    int  partyBoxId;
    int  slotCount;
    int  columnWrap;
    int  gridOriginX;
    unsigned char pad_640[4];
    unsigned int  fontBgHandle;
    void * taskMenuWindow;
    void * taskMenu;
    void * messageBuffer;
    unsigned short  magicValue;
    unsigned char pad_656[2];
    int  magicValue2;
    unsigned char pad_65C[84];
    void * taskMenuRes;
    int  subWin;
    unsigned char pad_6B8[100];
    int  messageWin;
    int  messageBank;
    int  wordSet;
    void * font;
    int  printStream;
    int  infoTextOut;
    int  infoTextIn;
    int  messageText;
    void * messageTemplate;
    void * printQueue;
    void * tcbl;
    unsigned char pad_748[4];
    void * keyCursor;
    unsigned char pad_750[176];
    int  filterIndex;
    unsigned char pad_804[12];
    int  camera;
    unsigned char pad_814[4];
    void * gfxWorkBuf;
    unsigned char pad_81C[4];
    void * g3dUtil;
    unsigned short  g3dUnitHandle;
    unsigned char pad_826[2];
    int  boxManager;
    void * gameData;
    int  trainerRecord;
    int  playerStatus;
    void * partyData;
    void * subCamera;
    void * mcssSystem;
    void * mcssPokemon[4];
    unsigned int  mcssAnimStopped;
    unsigned char pad_858[4];
    void * sceneBuf;
    unsigned char pad_860[12];
    int  subBgHandle;
    unsigned int  mainBgHandle;
    unsigned int  boxBgHandle;
    unsigned char pad_878[4];
    void * iconPalette;
    int  actorPalette;
    int  paletteB;
    int  iconPaletteEx;
    unsigned int  paletteSpare;
    void * iconPaletteComp;
    int  actorChar;
    int  charA;
    int  charB;
    int  charC;
    int  charD;
    unsigned int  cellAnimB;
    void * cellAnimC;
    int  actorCellAnim;
    int  cellAnimD;
    int  cellAnimE;
    unsigned int  cellAnimSpare;
    void * cellAnimF;
    unsigned char pad_8C4[216];
    int  subScreenActive;
    unsigned char pad_9A0[32];
    void * touchbar;
    int  clactSystem;
    void * nodeA;
    void * charE;
    unsigned char pad_9D0[240];
    void * boxIconActor;
    unsigned char pad_AC4[236];
    void * boxIconActorAlt;
    unsigned char pad_BB4[536];
    short  iconX;
    short  iconY;
    unsigned char pad_DD0[296];
    int  netSave;
    unsigned char pad_EFC[8];
    void * cursorActor;
    void * actorF08;
    int  actorF0C;
    int  iconActorA;
    int  iconActorB;
    int  actorF18;
    unsigned char pad_F1C[4];
    int  iconActorC;
    int  iconActorD;
    unsigned char pad_F28[4];
    int  waitCounter;
    unsigned char pad_F30[4];
    int  prevTouch;
    unsigned char pad_F38[28];
    int  iconPosX;
    int  iconPosY;
    int  dragMoved;
    int  dragActor;
    short  targetX;
    short  targetY;
    short  offsetX;
    short  offsetY;
    short  originX;
    short  originY;
    int  dragHold;
    int  cursorSlot;
    int  cursorColumn;
    int  highlightSlot;
    int  highlightBox;
    int  selectedSlot;
    int  selectedBox;
    unsigned char pad_F8C[8];
    int  peerSelectedSlot;
    int  peerSelectedBox;
    int  pendingSideMon;
    int  offerCount;
    /* Offer table: [side][index]; side 0 = own offers, side 1 = partner offers, three entries per side. */
    int offerSlot[2][3];
    int offerBox[2][3];
    void * pickedIconActor;
    void * offerMon[2][3];
    int offerReceivedValue[2][3];
    void * offerIconActor[2][3];
    int offerIconCharRes[2][3];
    void * windowF;
    unsigned char pad_103C[12];
    int  peerMsgIndex;
    unsigned char pad_104C[4];
    int  ownMsgIndex;
    unsigned char pad_1054[12];
    int  netFlag;
    unsigned char pad_1064[8];
    void * sendBuf;
    unsigned char pad_1070[4];
    int  redrawFlag;
    short  dragX;
    short  dragVelocity;
    short  scrollX;
    short  scrollY;
    short  cursorRow;
    unsigned char pad_1082[2];
    int  redrawNeeded;
    int  dragging;
    int  scrollSub;
    int  drawColumn;
    int  repeatCounter;
    unsigned short  summaryFlag;
    unsigned short  markerFlag;
    unsigned int  animIndex;
    int  cursorIndex;
    void * subObjPaletteCopy;
    void * subBgPaletteCopy;
    unsigned char pad_10AC[64];
    int  paletteE;
    unsigned int  cellAnimG;
    unsigned char pad_10F4[40];
    int  cellAnimH;
    unsigned char pad_1120[20];
    unsigned short  colorBitsA;
    unsigned char pad_1136[30];
    unsigned short  colorBitsB;
    unsigned char pad_1156[30];
    void * tilemapE;
    void * tilemapF;
    void * tilemap19;
    void * tilemap1A;
    void * vramBuf;
    unsigned char pad_1188[4];
    int  tradeState;
    BezierCurve bezierCurve;
    unsigned char pad_11D4[8];
    short  flightTimer;
    short  fadeLevel;
    unsigned char  peerChoiceA;
    unsigned char  peerChoiceB;
    unsigned char pad_11E2[4];
    unsigned char  peerStateA;
    unsigned char  peerStateByte;
    unsigned char  labelStateA;
    unsigned char  labelStateB;
    unsigned char  labelsReady;
    unsigned char  markerHandled;
    unsigned char  summaryActive;
    unsigned char pad_11ED[1];
    unsigned char  offlineFlag;
    unsigned char pad_11EF[2];
    unsigned char  cancelTimer;
    unsigned char  storedBoxIndex;
    unsigned char  sideMonSent;
    unsigned char  peerBoxValue;
    unsigned char  cursorAnimDone;
    unsigned char  nationalDexEnabled;
    unsigned char  wipeStarted;
    unsigned char  sceneState;
    unsigned char  wipeDone;
    unsigned char  netExitCount;
    union {
        unsigned char byte;
        struct {
            unsigned char sendBusy:4;
            unsigned char replyPending:4;
        } bits;
    } stateFlags;
} TradeWork;

/* Timed slide of one MCSS sprite from its current position to a target (heap block of 0x38 bytes). */
typedef struct McssSlideVec {
    int x;
    int y;
    int z;
} McssSlideVec;

typedef struct McssSlide {
    void * mcss;
    int frameCount;
    int frame;
    int fC;
    int f10;
    unsigned short wobblePhase;
    unsigned short wobbleEnabled;
    int f18;
    McssSlideVec start;
    McssSlideVec target;
    McssSlideVec * offsetTable;
} McssSlide;

/* shared with pokemontrade_proc */
struct Sub02008F80Obj;

/* Particle and ICA animation manager, allocated separately and owned by TradeWork. */
struct ParticleManager;

struct Actor;

struct PtS;

struct Obj;

struct Vec2;

struct Node;

struct Sub020079BCEntry;

struct Entry;

struct Link;

struct Big;

struct Sub02009470Obj;

struct Sub0200852CObj;

struct MsgBank;

struct TaskMenu;

struct WordSet;

struct Bank;

struct Blk37;

struct Light;

struct Tcbl;

struct PrintSys;

struct Sav;

typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;




/* shared with pokemontrade_nego */
struct BigObj;

struct Cfg;

struct Descriptor;

struct Rec;

struct U16Vec;









/* shared with pokemontrade_mcss */



/* shared with pokemontrade_save */
struct CharBuf;

struct Ctx;

struct IcaAnime;

typedef struct Descriptor {int a,b,c,d,e,f,g;u8 h,i,j,k;} Descriptor;


typedef struct {
    u16 a;
    u16 b;
    int amount;
    unsigned int c;
} Cfg;

/* shared with pokemontrade_3d */
struct Personal;

#endif
