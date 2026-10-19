#ifndef OV183_BR_CODEIN_TYPES_H
#define OV183_BR_CODEIN_TYPES_H

struct CodeinButtonArg;

/* The work of the battle recorder result list process (BR_CODEIN_ResultCreate, 0x70 bytes). */
struct CodeinResultWork {
    void * oamSys;  /* 0x0 */
    void * printQue;  /* 0x4 */
    void * textWin;  /* 0x8 */
    void * backButton;  /* 0xC */
    void * buttonText[3];  /* 0x10 */
    void * rowText[18];  /* 0x1C */
    void * resultFx;  /* 0x64 */
    int resultChoice;  /* 0x68 */
    unsigned short heapId;  /* 0x6C */
    unsigned char pad_6E[2];
};

/* The actors of the battle point counter on the list screen: the frame and four digits (BR_CODEIN_ListCreateActor, 0x14 bytes). */
struct CodeinPointActors {
    void * frame;  /* 0x0 */
    void * digit[4];  /* 0x4 */
};

/* The work of the battle recorder score list process (BR_CODEIN_ListCreate, 0x80 bytes). */
struct CodeinListWork {
    void * oamSys;  /* 0x0 */
    void * printQue;  /* 0x4 */
    struct CodeinPointActors pointActors;  /* 0x8 */
    void * textWin;  /* 0x1C */
    void * backButton;  /* 0x20 */
    void * buttonText[4];  /* 0x24 */
    void * rowText[16];  /* 0x34 */
    void * listFx;  /* 0x74 */
    int listChoice;  /* 0x78 */
    unsigned short heapId;  /* 0x7C */
    unsigned char pad_7E[2];
};

/* One row text of the list work seen from its entry address (the work address plus four times the index). */
struct CodeinListRowSlot {
    unsigned char pad_0[52];
    void * rowText;  /* 0x34 */
};

/* One button text of the list work seen from its entry address. */
struct CodeinListButtonSlot {
    unsigned char pad_0[36];
    void * buttonText;  /* 0x24 */
};

/* The work of the battle recorder upload counter process (BR_CODEIN_UploadCreate, 0x20 bytes). */
struct CodeinUploadWork {
    int printQue;  /* 0x0 */
    int task;  /* 0x4 */
    unsigned short heapId;  /* 0x8 */
    unsigned char pad_A[2];
    int textWin;  /* 0xC */
    int introFx;  /* 0x10 */
    int tapFx;  /* 0x14 */
    char * ctx;  /* 0x18 */
    unsigned int frames;  /* 0x1C */
};

/* The work of the battle recorder code input screen (BR_CODEIN_CodeCreate, 0x58 bytes). */
struct CodeinCodeWork {
    void * buttonText[3];  /* 0x0 */
    void * button[2];  /* 0xC */
    void * menuWork;  /* 0x14 */
    void * listMenu;  /* 0x18 */
    char * pokeSearch;  /* 0x1C */
    void * text[6];  /* 0x20 */
    void * codeWin;  /* 0x38 */
    int fx;  /* 0x3C */
    int tapFx;  /* 0x40 */
    int oamSys;  /* 0x44 */
    void * printQue;  /* 0x48 */
    int stage;  /* 0x4C */
    int nextStage;  /* 0x50 */
    unsigned short heapId;  /* 0x54 */
    unsigned char pad_56[2];
};

/* The work of the battle recorder record view process (BR_CODEIN_RecordCreate, 0xE8 bytes). */
struct CodeinRecordWork {
    void * oamSys;  /* 0x0 */
    void * printQue;  /* 0x4 */
    void * task;  /* 0x8 */
    int introFx;  /* 0xC */
    int tapFx;  /* 0x10 */
    unsigned char pad_14[4];
    void * textWin;  /* 0x18 */
    void * button[2];  /* 0x1C */
    unsigned char pad_24[4];
    void * captionText[2];  /* 0x28 */
    void * profileText[5];  /* 0x30 */
    void * profileScreen;  /* 0x44 */
    int paletteRes;  /* 0x48 */
    int cellAnimRes;  /* 0x4C */
    int charRes[12];  /* 0x50 */
    void * actor[12];  /* 0x80 */
    int profileScreenShown;  /* 0xB0 */
    unsigned short heapId;  /* 0xB4 */
    unsigned char pad_B6[10];
    char * recData;  /* 0xC0 */
    char * header;  /* 0xC4 */
    int savedActorSys;  /* 0xC8 */
    int hasSecondButton;  /* 0xCC */
    char * ctx;  /* 0xD0 */
    int actorsLoaded;  /* 0xD4 */
    int buttonsLoaded;  /* 0xD8 */
    int profileScreenLoaded;  /* 0xDC */
    int textWinCreated;  /* 0xE0 */
    int textWinSetup;  /* 0xE4 */
};

/* The work of the battle recorder sidebar process (BR_CODEIN_SidebarCreate, 0x20 bytes). */
struct CodeinSidebarWork {
    void * task;  /* 0x0 */
    unsigned short heapId;  /* 0x4 */
    unsigned char pad_6[2];
    void * noticeText;  /* 0x8 */
    void * printQue;  /* 0xC */
    int slideTimer;  /* 0x10 */
    void * handlesMain;  /* 0x14 */
    void * handlesSub;  /* 0x18 */
    char * work;  /* 0x1C */
};

/* The work of the battle recorder button process (BR_CODEIN_ButtonCreate, 0x18 bytes). */
struct CodeinButtonWork {
    int button;  /* 0x0 */
    int handles;  /* 0x4 */
    unsigned char pad_8[4];
    struct CodeinButtonArg * work;  /* 0xC */
    unsigned char pad_10[4];
    unsigned short heapId;  /* 0x14 */
    unsigned char pad_16[2];
};

/* The creation argument of the battle recorder button process (BR_CODEIN_ButtonCreate, 0x2C bytes). */
struct CodeinButtonArg {
    int kind;  /* 0x0 */
    int placement;  /* 0x4 */
    int placementArg;  /* 0x8 */
    int fadeMode;  /* 0xC */
    int screenFade;  /* 0x10 */
    void * actorSys;  /* 0x14 */
    void * res;  /* 0x18 */
    unsigned int procQuery;  /* 0x1C */
    int dataId;  /* 0x20 */
    char * uiRes;  /* 0x24 */
    void * resultOut;  /* 0x28 */
};

/* The work of the battle recorder profile screen (BR_CODEIN_ProfileCreate, 0x368 bytes). */
struct CodeinProfileWork {
    void * oamSys;  /* 0x0 */
    unsigned char pad_4[20];
    unsigned char moveFrames;  /* 0x18 */
    unsigned char pad_19[367];
    int selectedIndex;  /* 0x188 */
    unsigned char pad_18C[8];
    void * cursorActor;  /* 0x194 */
    unsigned char pad_198[24];
    void * markerActor;  /* 0x1B0 */
    unsigned char pad_1B4[40];
    int recordsApplied;  /* 0x1DC */
    unsigned char pad_1E0[8];
    void * prevArrowActor;  /* 0x1E8 */
    unsigned char pad_1EC[24];
    void * nextArrowActor;  /* 0x204 */
    unsigned char pad_208[36];
    int animSeq;  /* 0x22C */
    int reserved230;  /* 0x230 */
    int phase;  /* 0x234 */
    int phaseTimer;  /* 0x238 */
    int recordCount;  /* 0x23C */
    int animState;  /* 0x240 */
    int prevAnimState;  /* 0x244 */
    int rangeAFirst;  /* 0x248 */
    int rangeAEnd;  /* 0x24C */
    int rangeBFirst;  /* 0x250 */
    int rangeBEnd;  /* 0x254 */
    void * arcHandle;  /* 0x258 */
    void * actorSys;  /* 0x25C */
    int sprite11PaletteId;  /* 0x260 */
    unsigned int sprite6PaletteId;  /* 0x264 */
    int sprite12PaletteId;  /* 0x268 */
    int sprite11CharId;  /* 0x26C */
    unsigned int sprite6CharId;  /* 0x270 */
    int sprite12CharId;  /* 0x274 */
    unsigned char pad_278[12];
    int sprite11CellAnimId;  /* 0x284 */
    unsigned int sprite6CellAnimId;  /* 0x288 */
    int sprite12CellAnimId;  /* 0x28C */
    unsigned char pad_290[4];
    void * buttonMan;  /* 0x294 */
    unsigned char rect[22][4];  /* 0x298 */
    unsigned char prevArrowY;  /* 0x2F0 */
    unsigned char pad_2F1[1];
    unsigned char prevArrowX;  /* 0x2F2 */
    unsigned char pad_2F3[1];
    unsigned char nextArrowY;  /* 0x2F4 */
    unsigned char pad_2F5[1];
    unsigned char nextArrowX;  /* 0x2F6 */
    unsigned char pad_2F7[1];
    unsigned char pressedButton;  /* 0x2F8 */
    unsigned char pad_2F9[3];
    int markerHidden;  /* 0x2FC */
    void * profileOamSys;  /* 0x300 */
    void * nameGrid;  /* 0x304 */
    void * valueGrid;  /* 0x308 */
    unsigned char pad_30C[4];
    int font;  /* 0x310 */
    void * task;  /* 0x314 */
    int pendingStep;  /* 0x318 */
    int pendingKey;  /* 0x31C */
    int pendingKeyIsRecord;  /* 0x320 */
    unsigned char pad_324[32];
    void * res;  /* 0x344 */
    unsigned char pad_348[4];
    unsigned short profileHeapId;  /* 0x34C */
    unsigned char pad_34E[2];
    int state;  /* 0x350 */
    unsigned char pad_354[12];
    unsigned long long result;  /* 0x360 */
};

/* The creation argument of the sidebar process (BR_CODEIN_SidebarCreate). */
struct CodeinSidebarArg {
    void * mode;
    void * actorSys;
    unsigned char pad_8[4];
    void * res;
    void * procQuery;
};

/* Two call-back slots stored in the work at +0x4C (BR_CODEIN_CallAndClearStepFn/B). */
struct CodeinStoredFns {
    void * stepFn;
    void * destroyFn;
};

struct CodeinArgA {
    int  screenFade;
    int  actorSys;
    int  res;
    void * procQuery;
    int  uiRes;
    int  bsubwaySave;
    unsigned short  heapId;
    unsigned char pad_1A[2];
    int  tapFx;
    unsigned char pad_20[4];
    int  textWin;
    unsigned char pad_28[224];
    char * statCtx;
    unsigned char pad_10C[80];
    void * slideActor;
};

struct CodeinSubA {
    unsigned char pad_0[4];
    int  saveFade;
    int * screenFade;
    int * subFade;
    int  res;
    int  procQuery;
    void * net;
    char * menuState;
    unsigned char pad_20[4];
    void * recordNet;
    void * gameData;
    unsigned char pad_2C[5868];
    unsigned int  itemCount;
    unsigned int  selection;
};

/* The work of the video save process (BR_CODEIN_SaveCreate, 0x28 bytes). */
struct CodeinSaveWork {
    int  printQue;              /* 0x00 */
    void * textWin;             /* 0x04 */
    int  task;                  /* 0x08 */
    void * bodyText[2];         /* 0x0C the two option captions */
    int  introFx;               /* 0x14 effect handle of the first resource handle set */
    int  tapFx;                 /* 0x18 effect handle of the second set */
    unsigned short  heapId;     /* 0x1C */
    unsigned char pad_1E[2];
    char * saveCtx;             /* 0x20 */
    unsigned int  videoFrames;  /* 0x24 frame counter of the save steps */
};

/* The option caption array of the save work seen from one entry (the entry
 * address is the work address plus four times the index). */
struct CodeinSaveSlot {
    unsigned char pad_0[12];
    void * bodyText;            /* 0x0C */
};

/* The work of the battle recorder stat screen process (BR_CODEIN_StatCreate, 0x10C bytes). */
struct CodeinStatWork {
    void * oamSys;              /* 0x00 */
    void * backButton;          /* 0x04 */
    void * headerText;          /* 0x08 */
    void * titleText;           /* 0x0C */
    void * task;                /* 0x10 */
    void * printQue;            /* 0x14 */
    unsigned short  heapId;     /* 0x18 */
    unsigned char pad_1A[2];
    void * listFx;              /* 0x1C effect handle of the first resource handle set */
    int  tapFx;                 /* 0x20 effect handle of the second set */
    void * textWin;             /* 0x24 */
    unsigned char list[216];    /* 0x28 the embedded list menu (BR_CODEIN_SearchCreateList) */
    int  listCreated;           /* 0x100 */
    int  spriteLoaded;          /* 0x104 */
    char * statCtx;             /* 0x108 */
};

/* The work of the battle recorder video download process (BR_CODEIN_SoclCreate, 0x54 bytes). */
struct CodeinSoclWork {
    void * oamSys;  /* 0x0 */
    void * printQue;  /* 0x4 */
    void * textWin;  /* 0x8 */
    void * task;  /* 0xC */
    unsigned int selectedIndex;  /* 0x10 */
    void * button[4];  /* 0x14 */
    unsigned char pad_24[4];
    void * text[2];  /* 0x28 */
    int introFx;  /* 0x30 */
    int tapFx;  /* 0x34 */
    unsigned short heapId;  /* 0x38 */
    unsigned char pad_3A[2];
    char * arg;  /* 0x3C */
    unsigned short saveStatus[2];  /* 0x40 */
    unsigned int frames;  /* 0x44 */
    unsigned int textFrames;  /* 0x48 */
    struct CodeinStoredFns fns;  /* 0x4C */
};


struct CodeinArgB {
    int  screenFade;
    void * actorSys;
    int  res;
    char * procQuery;
    void * gameData;
    unsigned short  species;
    unsigned char  language;
    unsigned char  version;
    int  category;
};

struct CodeinRecordA {
    int  tag;
    unsigned char pad_4[4];
    int  mode;
    void * actor;
    unsigned char pad_10[4];
    short  moveDx;
    short  moveDy;
    unsigned char  moveFrames;
    unsigned char  scaleStep;
    unsigned char pad_1A[322];
    void * slideActor;
    unsigned char pad_160[4];
    short  slideDx;
    short  slideDy;
    unsigned char  slideFrames;
};

struct CodeinWorkF {
    int  printQue;
    int  task;
    unsigned short  heapId;
    unsigned char pad_A[2];
    int  textWin;
    int  tapFx;
    unsigned short  fadeHeapId;
    unsigned char pad_16[2];
    char * ctx;
};

/* One row text of the result list work seen from its entry address (the work address plus four times the index). */
struct CodeinResultRowSlot {
    unsigned char pad_0[28];
    void * rowText;
};

struct CodeinArgC {
    int  kind;
    int  actorSys;
    int  res;
    int  procQuery;
    int  saveProcQuery;
    unsigned char pad_14[4];
    unsigned int  reserved18;
};

struct CodeinWorkG {
    void * menuWork;
    void * listMenu;
    void * wordSet;
    unsigned char pad_C[8];
    unsigned short  paletteRes;
    unsigned short  cellAnimRes;
    unsigned short  reserved18;
    unsigned char pad_1A[62];
    void * reserved58;
};

struct CodeinSpecialA {
    unsigned char pad_0[336];
    int  tag;
    unsigned char pad_154[8];
    void * slideActor;
    unsigned char pad_160[4];
    short  slideDx;
    short  slideDy;
    unsigned char  slideFrames;
};

struct CodeinArgD {
    int  reserved00;
    unsigned char pad_4[8];
    int  reserved0C;
    unsigned long long  result;
};

struct CodeinA1A {
    unsigned char pad_0[12];
    int  res;
};

struct CodeinMenuEntries;

/* The configuration the menu is built from (second argument of the
 * br_codein_rec.c functions). */
struct CodeinMenuArg {
    int  mode;                  /* 0x00 */
    int  windowKind;            /* 0x04 handed to BR_BTN_CreateObject */
    void * resource;            /* 0x08 font, message bank and word set source */
    unsigned char pad_0C[12];   /* 0x0C */
    struct CodeinMenuEntries * entries;  /* 0x18 */
};

/* The three option entries of the menu: a presence flag, the option text and
 * its length. */
struct CodeinMenuEntries {
    unsigned int reserved00;            /* 0x00 */
    unsigned int present[3];    /* 0x04 */
    unsigned int pad_10;        /* 0x10 */
    char * text[3];             /* 0x14 */
    unsigned int pad_20;        /* 0x20 */
    unsigned int length[3];     /* 0x24 */
};

/* The handle holder behind CodeinSoclWork.arg (the menu argument). */
struct CodeinMenuSub {
    unsigned char pad_0[8];
    int  handle;                /* 0x08 */
};

#endif
