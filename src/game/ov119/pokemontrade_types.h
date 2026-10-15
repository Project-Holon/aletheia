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

/* Graphic load result written by func_02049DF4; the data pointer is at 0x14. */
struct GfxLoadResult {
    unsigned char pad_0[20];
    void * data;                /* 0x14 */
};

/* Work area of the Pokemon trade scene (overlay 119). One object, fields by byte offset. */
typedef struct TradeWork {
    void * f0;
    unsigned char pad_4[4];
    struct TradeRequest * request;
    struct ParticleManager * particleManager;
    unsigned char pad_10[1452];
    int  f5BC;
    int  f5C0;
    unsigned char pad_5C4[16];
    int  f5D4;
    int  f5D8;
    void * f5DC;
    void * f5E0;
    unsigned char pad_5E4[8];
    int  f5EC;
    void * timeIcon;
    unsigned short  heapId;
    unsigned char pad_5F6[22];
    void * f60C;
    void * f610;
    void * f614;
    void * f618;
    void * f61C;
    void * f620;
    void * f624;
    unsigned char pad_628[4];
    int  f62C;
    int  partyBoxId;
    int  f634;
    int  f638;
    int  f63C;
    unsigned char pad_640[4];
    unsigned int  f644;
    void * taskMenuWindow;
    int  taskMenu;
    void * messageBuffer;
    unsigned short  f654;
    unsigned char pad_656[2];
    int  f658;
    unsigned char pad_65C[84];
    void * taskMenuRes;
    int  f6B4;
    unsigned char pad_6B8[100];
    int  f71C;
    int  messageBank;
    int  f724;
    void * f728;
    int  printStream;
    int  f730;
    int  f734;
    int  f738;
    void * f73C;
    void * printQueue;
    void * f744;
    unsigned char pad_748[4];
    void * keyCursor;
    unsigned char pad_750[176];
    int  f800;
    unsigned char pad_804[12];
    int  camera;
    unsigned char pad_814[12];
    void * g3dUtil;
    unsigned short  g3dUnitHandle;
    unsigned char pad_826[2];
    int  gameData;
    void * f82C;
    int  f830;
    int  f834;
    void * f838;
    void * subCamera;
    void * mcssSystem;
    void * mcssPokemon[4];
    unsigned int  mcssAnimStopped;
    unsigned char pad_858[4];
    void * f85C;
    unsigned char pad_860[12];
    int  f86C;
    unsigned int  f870;
    unsigned int  f874;
    unsigned char pad_878[4];
    void * f87C;
    int  f880;
    int  f884;
    int  f888;
    unsigned int  f88C;
    void * f890;
    int  f894;
    int  f898;
    int  f89C;
    int  f8A0;
    int  f8A4;
    unsigned int  f8A8;
    void * f8AC;
    int  f8B0;
    int  f8B4;
    int  f8B8;
    unsigned int  f8BC;
    void * f8C0;
    unsigned char pad_8C4[216];
    int  f99C;
    unsigned char pad_9A0[32];
    int  touchbar;
    int  clactSystem;
    void * f9C8;
    void * f9CC;
    unsigned char pad_9D0[240];
    void * fAC0;
    unsigned char pad_AC4[236];
    void * fBB0;
    unsigned char pad_BB4[536];
    short  fDCC;
    short  fDCE;
    unsigned char pad_DD0[296];
    int  fEF8;
    unsigned char pad_EFC[8];
    int  fF04;
    void * fF08;
    int  fF0C;
    int  fF10;
    int  fF14;
    int  fF18;
    unsigned char pad_F1C[4];
    int  fF20;
    int  fF24;
    unsigned char pad_F28[4];
    int  fF2C;
    unsigned char pad_F30[36];
    int  fF54;
    int  fF58;
    int  fF5C;
    int  fF60;
    short  fF64;
    short  fF66;
    short  fF68;
    short  fF6A;
    short  fF6C;
    short  fF6E;
    int  fF70;
    int  fF74;
    int  fF78;
    int  fF7C;
    int  fF80;
    int  selectedSlot;
    int  selectedBox;
    unsigned char pad_F8C[8];
    int  peerSelectedSlot;
    int  peerSelectedBox;
    int  fF9C;
    int  fFA0;
    /* Offer table: [side][index]; side 0 = own offers, side 1 = partner offers, three entries per side. */
    int offerSlot[2][3];
    int offerBox[2][3];
    void * pickedIconActor;
    void * offerMon[2][3];
    int offerReceivedValue[2][3];
    void * offerIconActor[2][3];
    int offerIconCharRes[2][3];
    void * f1038;
    unsigned char pad_103C[12];
    int  f1048;
    unsigned char pad_104C[4];
    int  f1050;
    unsigned char pad_1054[12];
    int  f1060;
    unsigned char pad_1064[8];
    void * f106C;
    unsigned char pad_1070[4];
    int  f1074;
    short  f1078;
    short  f107A;
    short  f107C;
    short  f107E;
    short  f1080;
    unsigned char pad_1082[2];
    int  f1084;
    int  f1088;
    int  f108C;
    int  f1090;
    int  f1094;
    unsigned short  f1098;
    unsigned short  f109A;
    unsigned int  f109C;
    int  cursorIndex;
    void * subObjPaletteCopy;
    void * subBgPaletteCopy;
    unsigned char pad_10AC[64];
    int  f10EC;
    unsigned int  f10F0;
    unsigned char pad_10F4[40];
    int  f111C;
    unsigned char pad_1120[20];
    unsigned short  f1134;
    unsigned char pad_1136[30];
    unsigned short  f1154;
    unsigned char pad_1156[30];
    void * f1174;
    void * f1178;
    void * f117C;
    void * f1180;
    void * f1184;
    unsigned char pad_1188[4];
    int  f118C;
    BezierCurve bezierCurve;
    unsigned char pad_11D4[8];
    short  f11DC;
    short  f11DE;
    unsigned char  f11E0;
    unsigned char  f11E1;
    unsigned char pad_11E2[4];
    unsigned char  f11E6;
    unsigned char  f11E7;
    unsigned char  f11E8;
    unsigned char  f11E9;
    unsigned char  f11EA;
    unsigned char  f11EB;
    unsigned char  f11EC;
    unsigned char pad_11ED[1];
    unsigned char  f11EE;
    unsigned char pad_11EF[2];
    unsigned char  f11F1;
    unsigned char  f11F2;
    signed char  f11F3;
    unsigned char  f11F4;
    signed char  f11F5;
    unsigned char  nationalDexEnabled;
    signed char  f11F7;
    unsigned char  sceneState;
    unsigned char  f11F9;
    unsigned char  f11FA;
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

typedef struct {
    char pad0[0x5f4];
    u16 heap;
    char pad5f6[0x840 - 0x5f6];
    void *res;
    void *obj[4];
    char pad854[0x118c - 0x854];
    int mode;
} Work_021E3004;

/* shared with pokemontrade_3d */
struct Personal;

#endif
