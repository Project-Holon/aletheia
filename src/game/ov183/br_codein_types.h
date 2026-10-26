#ifndef OV183_BR_CODEIN_TYPES_H
#define OV183_BR_CODEIN_TYPES_H

#include "../ov186/br_proc_sys_types.h"

struct TcbTask;
struct BrUtilTask;
struct CodeinButtonArg;
struct BrProcArgBattle;
struct BrProcArgResult;
struct BrProcArgBasic;
struct BrProcArgRecord;
struct BrProcArgNet;
struct BrProcArgHead;
struct BrProcArgProfile;
struct BrProcArgSave;
struct BrProfileScreen;
struct BrFade;
struct BrRes;
struct Unit;
struct PrintQueue;
struct BrProcQuery;

/* The work of the battle recorder result list process (BR_CODEIN_ResultCreate, 0x70 bytes). */
struct CodeinResultWork {
    void * oamSys;  /* 0x0 */
    struct PrintQueue *printQue;  /* 0x4 */
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
    struct PrintQueue *printQue;  /* 0x4 */
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

/* The work of the battle recorder upload counter process (BR_CODEIN_UploadCreate, 0x20 bytes). */
struct CodeinUploadWork {
    struct PrintQueue *printQue;  /* 0x0 */
    struct BrUtilTask * task;  /* 0x4 */
    unsigned short heapId;  /* 0x8 */
    unsigned char pad_A[2];
    void * textWin;  /* 0xC */
    void * introFx;  /* 0x10 */
    void * tapFx;  /* 0x14 */
    struct BrProcArgNet * ctx;  /* 0x18 */
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
    void * fx;  /* 0x3C */
    void * tapFx;  /* 0x40 */
    void * oamSys;  /* 0x44 */
    struct PrintQueue *printQue;  /* 0x48 */
    int stage;  /* 0x4C */
    int nextStage;  /* 0x50 */
    unsigned short heapId;  /* 0x54 */
    unsigned char pad_56[2];
};

/* The work of the battle recorder record view process (BR_CODEIN_RecordCreate, 0xE8 bytes). */
struct CodeinRecordWork {
    void * oamSys;  /* 0x0 */
    struct PrintQueue *printQue;  /* 0x4 */
    struct BrUtilTask * task;  /* 0x8 */
    void * introFx;  /* 0xC */
    void * tapFx;  /* 0x10 */
    unsigned char pad_14[4];
    void * textWin;  /* 0x18 */
    void * button[2];  /* 0x1C */
    unsigned char pad_24[4];
    void * captionText[2];  /* 0x28 */
    void * profileText[5];  /* 0x30 */
    struct BrProfileScreen * profileScreen;  /* 0x44 */
    int paletteRes;  /* 0x48 */
    int cellAnimRes;  /* 0x4C */
    int charRes[12];  /* 0x50 */
    void * actor[12];  /* 0x80 */
    int profileScreenShown;  /* 0xB0 */
    unsigned short heapId;  /* 0xB4 */
    unsigned short saveCode;  /* 0xB6 */
    unsigned short saveStatus;  /* 0xB8 */
    unsigned char pad_BA[2];
    unsigned int waitFrames;  /* 0xBC */
    void * recData;  /* 0xC0 */
    void * header;  /* 0xC4 */
    int savedActorSys;  /* 0xC8 */
    int hasSecondButton;  /* 0xCC */
    struct BrProcArgBattle * ctx;  /* 0xD0 */
    int actorsLoaded;  /* 0xD4 */
    int buttonsLoaded;  /* 0xD8 */
    int profileScreenLoaded;  /* 0xDC */
    int textWinCreated;  /* 0xE0 */
    int textWinSetup;  /* 0xE4 */
};

/* The work of the battle recorder sidebar process (BR_CODEIN_SidebarCreate, 0x20 bytes). */
struct CodeinSidebarWork {
    struct BrUtilTask * task;  /* 0x0 */
    unsigned short heapId;  /* 0x4 */
    unsigned char pad_6[2];
    void * noticeText;  /* 0x8 */
    struct PrintQueue *printQue;  /* 0xC */
    int slideTimer;  /* 0x10 */
    void * handlesMain;  /* 0x14 */
    void * handlesSub;  /* 0x18 */
    struct BrProcArgBasic * work;  /* 0x1C */
};

/* The work of the battle recorder button process (BR_CODEIN_ButtonCreate, 0x18 bytes). */
struct CodeinButtonWork {
    void * button;  /* 0x0 */
    void * handles;  /* 0x4 */
    struct TcbTask * fadeTask;  /* 0x8 palette load task */
    struct CodeinButtonArg * work;  /* 0xC */
    int fadeDone;  /* 0x10 set by the palette load task */
    unsigned short heapId;  /* 0x14 */
    unsigned char pad_16[2];
};

/* The creation argument of the battle recorder button process (BR_CODEIN_ButtonCreate, 0x2C bytes). */
struct CodeinButtonArg {
    int kind;  /* 0x0 */
    int placement;  /* 0x4 */
    int placementArg;  /* 0x8 */
    int fadeMode;  /* 0xC */
    void *screenFade;  /* 0x10 */
    void *actorSys;  /* 0x14 */
    void *res;  /* 0x18 */
    void *procQuery;  /* 0x1C */
    int dataId;  /* 0x20 */
    void * uiRes;  /* 0x24 */
    void * resultOut;  /* 0x28 */
};

/* The object the profile screen is built from (BR_CODEIN_ProfileCreateObject, 40 bytes). */
struct BrCodeinObject {
    int capacity;  /* 0x00 */
    int entries[4];  /* 0x04 digits per group, the last repeats the third */
    int unused;  /* 0x14 */
    void * vector;  /* 0x18 string buffer */
    void * actorSys;  /* 0x1C */
    void * res;  /* 0x20 */
    void * handles;  /* 0x24 effect handles */
};

/* One actor slot of the profile screen, 28 bytes on the DS. The work holds 19 of them:
 * 12 record slots, 2 slide slots, 3 marker slots and 2 arrow slots. */
struct CodeinProfileSlot {
    int tag;  /* 0x00 record: group tag; slide slot: last record of the group; marker slot 0: selected index; marker slots 1 and 2: animation sequence */
    int group;  /* 0x04 record slots: group number (1 or 2) the record belongs to */
    int mode;  /* 0x08 record slots: nonzero when the record is in the highlighted range */
    void * actor;  /* 0x0C actor of the slot */
    unsigned char * rect;  /* 0x10 touch rectangle of the record (left, right, top, bottom) */
    short moveDx;  /* 0x14 step per frame while the actor slides */
    short moveDy;  /* 0x16 */
    unsigned char moveFrames;  /* 0x18 frames left in the slide */
    unsigned char scaleStep;  /* 0x19 step of the scale animation */
    unsigned char pad_1A[2];
};

#define CODEIN_PROFILE_SLOT_RECORD 0
#define CODEIN_PROFILE_SLOT_SLIDE 12
#define CODEIN_PROFILE_SLOT_MARKER 14
#define CODEIN_PROFILE_SLOT_ARROW 17
#define CODEIN_PROFILE_SLOT_COUNT 19

/* The work of the profile screen process (BR_CODEIN_ProfileScreenCreate, 24 bytes). */
struct CodeinWorkData {
    void * object;  /* 0x00 */
    void * profile;  /* 0x04 */
    void * textWin;  /* 0x08 */
    void * printQue;  /* 0x0C */
    unsigned short heap;  /* 0x10 */
    unsigned short pad;
    void * handles;  /* 0x14 */
};

/* The work of the battle recorder profile screen (BR_CODEIN_ProfileCreate, 0x368 bytes). */
struct CodeinProfileWork {
    struct CodeinProfileSlot slot[CODEIN_PROFILE_SLOT_COUNT];  /* 0x000 */
    unsigned short pos[4];  /* 0x214 x position of each record group per animation state */
    struct { unsigned short first; unsigned short end; } range[3];  /* 0x21C range of the highlighted records per animation state */
    unsigned char pad_228[4];
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
    void *actorSys;  /* 0x25C */
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
    unsigned char rect[24][4];  /* 0x298 touch rectangles: 12 records, 10 buttons, the two arrows (left, right, top, bottom) */
    unsigned char pressedButton;  /* 0x2F8 */
    unsigned char pad_2F9[3];
    int markerHidden;  /* 0x2FC */
    void * profileOamSys;  /* 0x300 */
    void * grid[2];  /* 0x304 name grid and value grid */
    unsigned char pad_30C[4];
    void * font;  /* 0x310 */
    struct TcbTask * task;  /* 0x314 */
    int pendingStep;  /* 0x318 */
    int pendingKey;  /* 0x31C */
    int pendingKeyIsRecord;  /* 0x320 */
    struct BrCodeinObject object;  /* 0x324 copy of the object the screen was created from */
    unsigned short profileHeapId;  /* 0x34C */
    unsigned char pad_34E[2];
    int state;  /* 0x350 */
    int digitValue[3];  /* 0x354 value typed so far per digit group */
    unsigned long long result;  /* 0x360 */
};

/* Two call-back slots stored in the work at +0x4C (BR_CODEIN_CallAndClearStepFn/B). */
typedef void (*CodeinHookFn)(void *work, void *arg);
struct CodeinStoredFns {
    CodeinHookFn stepFn;
    CodeinHookFn destroyFn;
};

/* The work of the video save process (BR_CODEIN_SaveCreate, 0x28 bytes). */
struct CodeinSaveWork {
    struct PrintQueue *printQue;              /* 0x00 */
    void * textWin;             /* 0x04 */
    struct BrUtilTask * task;                  /* 0x08 */
    void * bodyText[2];         /* 0x0C the two option captions */
    void * introFx;               /* 0x14 effect handle of the first resource handle set */
    void * tapFx;                 /* 0x18 effect handle of the second set */
    unsigned short  heapId;     /* 0x1C */
    unsigned char pad_1E[2];
    struct BrProcArgRecord * saveCtx;  /* 0x20 */
    unsigned int  videoFrames;  /* 0x24 frame counter of the save steps */
};

/* The work of the battle recorder stat screen process (BR_CODEIN_StatCreate, 0x10C bytes). */
/* The list menu of cached records with the row icons (0xD4 bytes), BR_CODEIN_SearchCreateList. */
struct CodeinSearchList {
    struct BmpMenuWorkSlot * menuWork;  /* 0x00 */
    void * listMenu;            /* 0x04 */
    void * wordSet;             /* 0x08 */
    void * listParam;           /* 0x0C */
    void * tapFx;               /* 0x10 */
    unsigned short paletteRes;  /* 0x14 */
    unsigned short cellAnimRes; /* 0x16 */
    unsigned short charRes[5][6]; /* 0x18 */
    int cursor;                 /* 0x54 */
    void * sprites[5][6];       /* 0x58 */
    struct BrRecCache * cache;  /* 0xD0 */
};

struct CodeinStatWork {
    void * oamSys;              /* 0x00 */
    void * backButton;          /* 0x04 */
    void * headerText;          /* 0x08 */
    void * titleText;           /* 0x0C */
    struct BrUtilTask * task;                /* 0x10 */
    struct PrintQueue *printQue;            /* 0x14 */
    unsigned short  heapId;     /* 0x18 */
    unsigned char pad_1A[2];
    void * listFx;              /* 0x1C effect handle of the first resource handle set */
    void * tapFx;                 /* 0x20 effect handle of the second set */
    void * textWin;             /* 0x24 */
    struct CodeinSearchList list;  /* 0x28 */
    unsigned int frames;        /* 0xFC */
    int  listCreated;           /* 0x100 */
    int  spriteLoaded;          /* 0x104 */
    struct BrProcArgType * statCtx;  /* 0x108 */
};

/* The work of the battle recorder video download process (BR_CODEIN_SoclCreate, 0x54 bytes). */
struct CodeinSoclWork {
    void * oamSys;  /* 0x0 */
    struct PrintQueue *printQue;  /* 0x4 */
    void * textWin;  /* 0x8 */
    struct BrUtilTask * task;  /* 0xC */
    unsigned int selectedIndex;  /* 0x10 */
    void * button[4];  /* 0x14 */
    unsigned char pad_24[4];
    void * text[2];  /* 0x28 */
    void * introFx;  /* 0x30 */
    void * tapFx;  /* 0x34 */
    unsigned short heapId;  /* 0x38 */
    unsigned char pad_3A[2];
    struct BrProcArgResult * arg;  /* 0x3C */
    unsigned short saveStatus[2];  /* 0x40 */
    unsigned int frames;  /* 0x44 */
    unsigned int textFrames;  /* 0x48 */
    struct CodeinStoredFns fns;  /* 0x4C */
};



/* One row text of the result list work seen from its entry address (the work address plus four times the index). */
struct CodeinResultRowSlot {
    unsigned char pad_0[28];
    void * rowText;
};



#endif
