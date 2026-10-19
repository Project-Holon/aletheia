#ifndef OV183_BR_CODEIN_TYPES_H
#define OV183_BR_CODEIN_TYPES_H

struct CodeinWorkA {
    void * oamSys;
    void * printQue;
    void * textWin;
    void * backButton;
    void * recordTapFx;
    void * statPrintQue;
    unsigned char  moveFrames;
    unsigned char pad_19[3];
    char * ctx;
    char * saveCtx;
    void * statWin;
    char * noticeText;
    unsigned char pad_2C[8];
    void * listText;
    void * codeWin;
    char * menuCtx;
    int  tapFx;
    int  codeOamSys;
    void * codePrintQue;
    int  stage;
    int  nextStage;
    unsigned short  heapId;
    unsigned char pad_56[14];
    void * resultFx;
    int  resultChoice;
    unsigned short  resultHeapId;
    unsigned char pad_6E[6];
    void * listFx;
    int  listChoice;
    unsigned short  listHeapId;
    unsigned char pad_7E[50];
    int  profileScreenShown;
    unsigned short  recordHeapId;
    unsigned char pad_B6[22];
    int  hasSecondButton;
    char * recordCtx;
    unsigned char pad_D4[4];
    int  buttonsLoaded;
    unsigned char pad_DC[36];
    int  listCreated;
    int  spriteLoaded;
    char * statCtx;
    unsigned char pad_10C[124];
    int  selectedIndex;
    unsigned char pad_18C[8];
    void * cursorActor;
    unsigned char pad_198[24];
    void * markerActor;
    unsigned char pad_1B4[40];
    int  recordsApplied;
    unsigned char pad_1E0[8];
    void * prevArrowActor;
    unsigned char pad_1EC[8];
    signed char  lastMoveFrames;
    unsigned char pad_1F5[15];
    void * nextArrowActor;
    unsigned char pad_208[36];
    int  animSeq;
    int  f230;
    int  phase;
    int  phaseTimer;
    int  recordCount;
    int  animState;
    int  prevAnimState;
    int  rangeAFirst;
    int  rangeAEnd;
    int  rangeBFirst;
    int  rangeBEnd;
    void * arcHandle;
    void * actorSys;
    int  sprite11PaletteId;
    unsigned int  sprite6PaletteId;
    int  sprite12PaletteId;
    int  sprite11CharId;
    unsigned int  sprite6CharId;
    int  sprite12CharId;
    unsigned char pad_278[12];
    int  sprite11CellAnimId;
    unsigned int  sprite6CellAnimId;
    int  sprite12CellAnimId;
    unsigned char pad_290[4];
    void * buttonMan;
    unsigned char  rectTop;
    unsigned char  rectBottom;
    unsigned char  rectLeft;
    unsigned char  rectRight;
    unsigned char pad_29C[84];
    unsigned char  prevArrowY;
    unsigned char pad_2F1[1];
    unsigned char  prevArrowX;
    unsigned char pad_2F3[1];
    unsigned char  nextArrowY;
    unsigned char pad_2F5[1];
    unsigned char  nextArrowX;
    unsigned char pad_2F7[1];
    unsigned char  pressedButton;
    unsigned char pad_2F9[3];
    int  markerHidden;
    void * profileOamSys;
    void * nameGrid;
    void * valueGrid;
    unsigned char pad_30C[4];
    int  font;
    void * task;
    int  pendingStep;
    int  pendingKey;
    int  pendingKeyIsRecord;
    unsigned char pad_324[32];
    void * res;
    unsigned char pad_348[4];
    unsigned short  profileHeapId;
    unsigned char pad_34E[2];
    int  state;
    unsigned char pad_354[12];
    unsigned long long  result;
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

struct CodeinWorkB {
    int  task;
    int  printQue;
    void * recordTask;
    int  button;
    int  screenFade;
    void * menuWork;
    void * textWin;
    unsigned int  procQuery;
    int  f20;
    char * categoryText;
    void * noticeText;
    char * speciesText;
    unsigned char pad_30[4];
    char * versionText;
    void * codeWin;
    unsigned char pad_3C[4];
    int  tapFx;
    int  profileScreen;
    int  paletteRes;
    int  cellAnimRes;
    int  nextStage;
    unsigned short  heapId;
    unsigned char pad_56[90];
    int  profileScreenShown;
    unsigned short  recordHeapId;
    unsigned char pad_B6[18];
    int  savedActorSys;
    unsigned char pad_CC[4];
    char * recordCtx;
    int  actorsLoaded;
    int  buttonsLoaded;
    int  profileScreenLoaded;
    int  textWinCreated;
    int  textWinSetup;
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

struct CodeinWorkC {
    int  printQue;
    void * textWin;
    int  task;
    void * bodyText;
    void * resultText;
    int  introFx;
    int  tapFx;
    unsigned short  heapId;
    unsigned char pad_1E[2];
    char * saveCtx;
    unsigned int  buttonText;
    void * captionText;
    unsigned char pad_2C[4];
    void * profileText;
    void * rowText;
    unsigned char pad_38[24];
    int  charRes;
    unsigned char pad_54[44];
    void * actor;
};

struct CodeinWorkD {
    void * oamSys;
    void * backButton;
    void * headerText;
    void * titleText;
    void * task;
    void * printQue;
    unsigned short  heapId;
    unsigned char pad_1A[2];
    void * listParam;
    int  tapFx;
    void * textWin;
    unsigned char pad_28[16];
    unsigned short  soclHeapId;
    unsigned char pad_3A[2];
    char * arg;
    unsigned char pad_40[20];
    int  f54;
    void * f58;
    unsigned char pad_5C[116];
    void * fD0;
    unsigned char pad_D4[44];
    int  listCreated;
    int  spriteLoaded;
    char * statCtx;
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

struct CodeinWorkE {
    unsigned char pad_0[4];
    unsigned short  heapId;
    unsigned char pad_6[2];
    void * noticeText;
    void * printQue;
    unsigned char pad_10[4];
    int  fxCenter;
    int  fxTop;
    char * ctx;
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

struct CodeinSlotA {
    unsigned char pad_0[28];
    void * rowText;
};

struct CodeinStateA {
    void * task;
    unsigned short  heapId;
    unsigned char pad_6[6];
    void * printQue;
    unsigned char pad_10[4];
    void * handlesMain;
    void * handlesSub;
    char * work;
};

struct CodeinSubB {
    unsigned char pad_0[16];
    unsigned short  f10;
};

struct CodeinStateB {
    int  button;
    int  handles;
    unsigned char pad_8[4];
    char * work;
    unsigned char pad_10[4];
    unsigned short  heapId;
};

struct CodeinArgC {
    int  kind;
    int  actorSys;
    int  res;
    int  procQuery;
    int  saveProcQuery;
    unsigned char pad_14[4];
    unsigned int  f18;
};

struct CodeinWorkG {
    void * menuWork;
    void * listMenu;
    void * wordSet;
    unsigned char pad_C[8];
    unsigned short  paletteRes;
    unsigned short  cellAnimRes;
    unsigned short  f18;
    unsigned char pad_1A[62];
    void * f58;
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

struct CodeinDataA {
    unsigned char pad_0[56];
    void * codeWin;
    unsigned char pad_3C[8];
    void * codeOamSys;
    void * codePrintQue;
};

struct CodeinArgD {
    int  f0;
    unsigned char pad_4[8];
    int  fC;
    unsigned long long  result;
};

struct CodeinA1A {
    unsigned char pad_0[12];
    int  res;
};

/* The option-menu sub-state of the battle recorder code input screen
 * (br_codein_rec.c): a text window, four option buttons, two effect handles
 * and the heap the window is created in. */
struct CodeinMenuState {
    int  kind;                  /* 0x00 handed to BR_BTN_CreateObject */
    void * owner;               /* 0x04 text window owner */
    void * textWin;             /* 0x08 */
    unsigned char pad_0C[8];    /* 0x0C */
    void * buttons[4];          /* 0x14 first three option buttons, then the message button */
    unsigned char pad_24[12];   /* 0x24 */
    int  effectShow;            /* 0x30 effect played when the text appears */
    int  effectHit;             /* 0x34 effect played on an option hit */
    unsigned short heapId;      /* 0x38 */
    unsigned char pad_3A[2];    /* 0x3A */
    void * sub;                 /* 0x3C resource handle owner */
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
    unsigned int f0;            /* 0x00 */
    unsigned int present[3];    /* 0x04 */
    unsigned int pad_10;        /* 0x10 */
    char * text[3];             /* 0x14 */
    unsigned int pad_20;        /* 0x20 */
    unsigned int length[3];     /* 0x24 */
};

/* The handle holder behind CodeinMenuState.sub. */
struct CodeinMenuSub {
    unsigned char pad_0[8];
    int  handle;                /* 0x08 */
};

#endif
