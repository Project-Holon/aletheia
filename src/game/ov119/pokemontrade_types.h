#ifndef POKEMONTRADE_TYPES_H
#define POKEMONTRADE_TYPES_H

/* Small value types shared by the files of the trade scene. */
typedef enum { SHADING_TOON, SHADING_HIGHLIGHT } PokemontradeShading;

typedef struct { int a, b; } PokemontradeIntPair;

typedef struct { int a, b, c; } PokemontradeIntTriple;

/* Fixed-point position used by the icon flight path. */
#include "../types.h"
#include "../version.h"
#include "../sdk_fx.h"
#include "../arm9/g3d_util_types.h"
#include "../ov114/nhttp_rap_types.h"

struct ClactActor;
struct G3dCamera;

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
    char * httpParam;           /* 0x24: third argument of NHTTP_RAP_Create (profile data) */
    unsigned short box;         /* 0x28 */
    unsigned short slot;        /* 0x2A */
    unsigned short count;       /* 0x2C */
    unsigned short setupParam;  /* 0x2E: second argument of SetupGameData (unused) */
    void * gameDataSource;      /* 0x30: gameData for the McssPokemon request types */
    void * monA;                /* 0x34: first party mon data */
    void * monB;                /* 0x38: second party mon data */
    struct MyStatus *trainerValue;           /* 0x3C: copied to TradeWork::f830 */
    struct MyStatus *playerStatus;           /* 0x40: copied to TradeWork::f834 */
};

/* Trade context pointed to by TradeRequest::context. */
struct TradeContext {
    unsigned char pad_0[432];
    int entryCount;             /* 0x1B0 */
};

/* One embedded UI scene slot; a CLACT actor handle lives at 0x10. */
struct PokemontradeUiScene {
    unsigned char pad_0[16];
    void * actor;               /* 0x10 */
};

/* Graphic load result written by ARC_UTIL_LoadBgCharDataFromHandle; the data pointer is at 0x14. */
struct GfxLoadResult {
    unsigned char pad_0[20];
    void * data;                /* 0x14 */
};

#include "../arm9/app_taskmenu.h"
#include "../arm9/playtime_shared_types.h"
#include "../ov067/ui_scene_types.h"

struct Bmp;

/* Trade record of one party or box slot (4 bytes). */
typedef struct PokemontradeProcRecord {
    u16 value;
    u8 a;
    u8 b;
} PokemontradeProcRecord;

/* Timed slide of one MCSS sprite from its current position to a target (heap block of 0x38 bytes). */
struct NetSaveTask;

typedef struct McssSlideVec {
    int x;
    int y;
    int z;
} McssSlideVec;

typedef struct McssSlide {
    void * mcss;
    int frameCount;
    int frame;
    int reserved0C;
    int reserved10;
    unsigned short wobblePhase;
    unsigned short wobbleEnabled;
    int reserved18;
    McssSlideVec start;
    McssSlideVec target;
    McssSlideVec * offsetTable;
} McssSlide;

/* Summary page icons: the graphics set, a loaded flag and the eight actors (0x34 bytes on the DS). */
typedef struct TradeSummaryIcons {
    ActorGfxSet gfx;
    int loaded;
    struct ClactActor *actor[8];
} TradeSummaryIcons;

typedef struct {
    int x, y, z;
} PokemontradeDemoVec;

/*
 * Particle and ICA animation manager owned by TradeWork.particleManager.
 * Allocated and released by the caller; holds nine particle systems with
 * their backing heap blocks, the four ICA animation streams and the shared
 * particle archive member.
 */
typedef struct ParticleManager {
    void *system[9];          /* 0x000 particle systems */
    void *buffer[9];          /* 0x024 heap block backing each system */
    PokemontradeDemoVec position;       /* 0x048 */
    PokemontradeDemoVec scale;          /* 0x054 */
    PokemontradeDemoVec slotScale[4];   /* 0x060 per-mcss-slot scales */
    void *icaStream[4];       /* 0x090 ICA animation streams */
    void *emitter[2];         /* 0x0A0 emitters that follow stream 2 and stream 3 */
    int streamFrame[2];       /* 0x0A8 loop frame of stream 0 and stream 1 */
    void *actor;              /* 0x0B0 CLACT actor handle */
    void *archiveMember;      /* 0x0B4 shared particle archive member */
    unsigned char pad_B8[2];  /* 0x0B8 */
    u16 heap;                 /* 0x0BA owning heap id */
} ParticleManager;

/* Save data copies kept while a trade is written (0x24 bytes on the DS). */
typedef struct TradeSaveBackup {
    void * saveControlBackup;
    void * trainerRecordBackup;
    void * savedSaveControl;
    void * savedZukan;
    void * savedBlock1F;
    void * partyBackup;
    void * boxBackup;
    struct PlayTimeStamp playTimeStamp;         /* 0x1C */
    int  boxSaveDirty;
} TradeSaveBackup;

/* One icon slot of the trade scene: actor graphics set plus its actor (0x14 bytes on the DS). */
typedef struct TradeIconSlot {
    ActorGfxSet gfx;            /* 0x00 */
    struct ClactActor *actor;   /* 0x10 */
} TradeIconSlot;

/* Work area of the Pokemon trade scene (overlay 119). */
typedef struct TradeWork {
    NHTTPRapSession * httpRap;
    unsigned char pad_4[4];
    struct TradeRequest * request;
    struct ParticleManager * particleManager;
    unsigned char boxMarking[24][30];           /* 0x010: marking icons of the 24 boxes, sent to the partner */
    unsigned char partyMarking[6];              /* 0x2E0 */
    unsigned char texSource[0x2D0];             /* 0x2E6: source cells of the cube textures */
    unsigned char texHeader[6];                 /* 0x5B6 */
    union {
        struct BmpWin *statusWin[2];            /* 0x5BC */
        struct {
            struct BmpWin *statusWin0;
            struct BmpWin *statusWin1;
        };
    };
    struct BmpWin *levelWin[2];                 /* 0x5C4 */
    struct BmpWin *itemWin[2];                  /* 0x5CC */
    struct BmpWin *nameRowWin;
    struct BmpWin *valueRowWin;
    union {
        void *monBuf[2];                        /* 0x5DC */
        struct {
            void * monABuf;
            void * monBBuf;
        };
    };
    int sideValue[2];                           /* 0x5E4 */
    void (*stepFunc)(struct TradeWork *);        /* current step function */
    void * timeIcon;
    unsigned short  heapId;
    unsigned char pad_5F6[22];
    TradeSaveBackup backup;                     /* 0x60C */
    int  partyBoxId;
    int  slotCount;
    int  columnWrap;
    int  gridOriginX;
    unsigned char pad_640[4];
    unsigned int  fontBgHandle;
    void * taskMenuWindow;
    void * taskMenu;
    TaskMenuItem taskMenuItems[8];              /* 0x650 */
    void * taskMenuRes;
    struct BmpWin *subWin;
    struct BmpWin *boxNameWin[25];              /* 0x6B8 */
    struct BmpWin *messageWin;
    struct MsgBank *messageBank;
    struct WordSet *wordSet;
    struct GfFont *font;
    struct TextPrinter *printStream;
    struct Strbuf *infoTextOut;
    struct Strbuf *infoTextIn;
    struct Strbuf *messageText;
    struct Strbuf *messageTemplate;
    struct PrintQueue *printQueue;
    void * tcbl;
    unsigned char pad_748[4];
    void * keyCursor;
#if LANGUAGE == LANGUAGE_JAPANESE
    struct BmpWin *subScreenWin[44];            /* 0x750 */
#else
    struct BmpWin *subScreenWin[26];            /* 0x750 */
    unsigned char pad_7B8[72];
#endif
    int  filterIndex;
    unsigned char pad_804[12];
    struct G3dCamera * camera;
    unsigned char pad_814[4];
    signed char *fade;                          /* 0x818 four fade parameters (heap block) */
    unsigned char pad_81C[4];
    G3dUtil * g3dUtil;
    unsigned short  g3dUnitHandle;
    unsigned char pad_826[2];
    struct GameData *boxManager;
    void * gameData;
    struct MyStatus *trainerRecord;
    struct MyStatus *playerStatus;
    void * partyData;
    void * subCamera;
    void * mcssSystem;
    void * mcssPokemon[4];
    unsigned int  mcssAnimStopped;
    unsigned int  peerSceneStarted;
    McssSlide *slide[4];                        /* 0x85C own, peer, extra and current mcss slide */
    int  subBgHandle;
    unsigned int mainBgHandle;
    unsigned int boxBgHandle;
    unsigned char pad_878[4];
    union {
        int resourceHandle[18];                 /* 0x87C: palettes, characters, then cell animations */
        struct {
            int iconPalette;
            int  actorPalette;
            int  paletteB;
            int  iconPaletteEx;
            unsigned int  paletteSpare;
            int iconPaletteComp;
            int  actorChar;
            int  charA;
            int charB;
            int charC;
            int  charD;
            unsigned int  cellAnimB;
            int cellAnimC;
            int  actorCellAnim;
            int  cellAnimD;
            int  cellAnimE;
            unsigned int  cellAnimSpare;
            int cellAnimF;
        };
    };
    TradeIconSlot statusIcon[3];                /* 0x8C4 */
    TradeIconSlot typeIcon[4];                  /* 0x900 */
    TradeIconSlot markingIcon[3];               /* 0x950 */
    TradeSummaryIcons summary;                  /* 0x98C */
    void * touchbar;
    struct Unit *clactSystem;
    void * nodeA;
    int iconChar[12][5];                        /* 0x9CC */
    unsigned char pad_ABC[4];
    struct ClactActor *boxIconActors[12][5];    /* 0xAC0 */
    struct ClactActor *boxIconAlt[12][5];       /* 0xBB0 */
    unsigned short boxIconId[12][5];            /* 0xCA0 */
    unsigned char boxIconB2[12][5];             /* 0xD18 */
    unsigned char boxIconB3[12][5];             /* 0xD54 */
    unsigned char boxIconSlot[12][5];           /* 0xD90 */
    struct {
        short x;
        short y;
    } boxIconPos[12][5];                        /* 0xDCC */
    unsigned char boxIconShown[12][5];          /* 0xEBC */
    struct NetSaveTask *netSave;
    union {
        struct ClactActor *uiActor[10];         /* 0xEFC */
        struct {
            struct ClactActor *actorEFC;
            struct ClactActor *actorF00;
            struct ClactActor * cursorActor;
            struct ClactActor * actorF08;
            struct ClactActor *actorF0C;
            struct ClactActor *iconActorA;
            struct ClactActor *iconActorB;
            struct ClactActor *actorF18;
            struct ClactActor *actorF1C;
            struct ClactActor *iconActorC;
        };
    };
    struct ClactActor *iconActorD;
    unsigned char pad_F28[4];
    int  waitCounter;
    unsigned char pad_F30[4];
    int  prevTouch;
    unsigned char pad_F38[28];
    int  iconPosX;
    int  iconPosY;
    int  dragMoved;
    struct ClactActor *dragActor;
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
    struct ClactActor * pickedIconActor;
    void * offerMon[2][3];
    int offerReceivedValue[2][3];
    struct ClactActor * offerIconActor[2][3];
    int offerIconCharRes[2][3];
    struct BmpWin *offerListWin[4];             /* 0x1038 */
    int peerMsgIndex[2];                        /* 0x1048 */
    int ownMsgIndex[2];                         /* 0x1050 */
    unsigned char pad_1058[8];
    int  netFlag;
    union {
        void * tradeBuf[3];                     /* 0x1064 */
        struct {
            unsigned char pad_1064[8];
            void * sendBuf;
        };
    };
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
    union {
        struct ClactActor * markerActor[8];     /* 0x10AC */
        struct {
            struct ClactActor *markerButtonActor[4];
            struct ClactActor *markerIconActor[4];  /* 0x10BC */
        };
    };
    struct ClactActor *windowActor[8];          /* 0x10CC */
    int  paletteE;
    int  cellAnimG;
    struct Bmp *windowBmp[8];                   /* 0x10F4 */
    int windowChar[8];                          /* 0x1114 */
    unsigned short palettePageA[16];            /* 0x1134 */
    unsigned short palettePageB[16];            /* 0x1154 */
    union {
        void *tilemap[4];                       /* 0x1174 */
        struct {
            void * tilemapE;
            void * tilemapF;
            void * tilemap19;
            void * tilemap1A;
        };
    };
    void * vramBuf;
    unsigned char pad_1188[4];
    int  tradeState;
    BezierCurve bezierCurve;
    u32 printCtrl[2];                           /* 0x11D4 */
    short  flightTimer;
    short  fadeLevel;
    union {
        unsigned char choice[2];                /* 0x11E0 */
        struct {
            unsigned char peerChoiceA;
            unsigned char peerChoiceB;
        };
    };
    unsigned char slotTimer[2];                 /* 0x11E2 */
    unsigned char holdTimer[2];                 /* 0x11E4 */
    union {
        unsigned char peerState[2];             /* 0x11E6 */
        struct {
            unsigned char peerStateA;
            unsigned char peerStateByte;
        };
    };
    union {
        unsigned char labelState[2];            /* 0x11E8 */
        struct {
            unsigned char labelStateA;
            unsigned char labelStateB;
        };
    };
    unsigned char labelsReady;
    unsigned char markerHandled;
    unsigned char summaryActive;
    union {
        unsigned char compareResult[4];         /* 0x11ED */
        struct {
            unsigned char enemySameMon;
            unsigned char ownSameMon;
            unsigned char enemySpecialMon;
            unsigned char ownSpecialMon;
        };
    };
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
    PokemontradeProcRecord records[24 * 30 + 6]; /* 0x11FC */
} TradeWork;


/* shared with pokemontrade_proc */
struct Sub02008F80Obj;



struct ClactVec2;


struct ClactVec2;

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

#include "../types.h"

/* shared with pokemontrade_nego */
struct BigObj;

struct PokemontradeCfg;

struct PokemontradeDescriptor;

struct Rec;

struct U16Vec;

/* shared with pokemontrade_mcss */

/* shared with pokemontrade_save */
struct CharBuf;

struct Ctx;

struct IcaAnime;

typedef struct PokemontradeDescriptor {int a,b,c,d,e,f,g;u8 h,i,j,k;} PokemontradeDescriptor;

typedef struct {
    u16 a;
    u16 b;
    int amount;
    unsigned int c;
} PokemontradeCfg;

/* shared with pokemontrade_3d */
struct Personal;

#endif
