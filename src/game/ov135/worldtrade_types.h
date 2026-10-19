#ifndef WORLDTRADE_TYPES_H
#define WORLDTRADE_TYPES_H
/* ov135 world trade: types shared by every part of worldtrade_adapter,
 * worldtrade_box and worldtrade_enter. */

#ifndef OV135_BASIC_TYPES
#define OV135_BASIC_TYPES
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#endif

typedef struct {
    void *str;
    int val;
} Item;

typedef struct {
    void **wins;
    u8 pad4[8 - 4];
    u32 cursor;
    u32 up;
    u32 down;
    unsigned int rowCursor;
    void *mgr;
    void *bag;
    void *bank;
    void *msg;
    void *listMsg;
    u32 speciesFlags;
    Item *items;
    void *num;
    s16 layout;
    s16 start;
    short speciesResult;
    short conditionResult;
    s8 optionResult;
    s8 genderResult;
    u8 pad42[2];
    int pos;
    int state;
    int nextState;
    u32 layer;
    short mode;
    s16 page;
    int total;
    int listKind;
    u8 flags[0x7A - 0x60];
    u8 last;
    u8 pad7B;
    u8 g[4];
} Menu;

/* ---- canonical work block (generated) ---- */

typedef struct Work Work;
typedef void (*Cb)(Work *p);

typedef struct {
    union { /* +0x0 */
        u8 data[0x128];
        struct {
            u8 pad0[0xEC - 0x0];
            u8 rec[0x110 - 0xEC]; /* +0xEC */
            u8 name[0x128 - 0x110]; /* +0x110 */
        };
        struct {
            u8 pad0_[0xF0 - 0x0];
            u8 key[0x128 - 0xF0]; /* +0xF0 */
        };
        struct {
            u8 pad0__[0x120 - 0x0];
            u8 nation; /* +0x120 */
            u8 area; /* +0x121 */
        };
        struct {
            u8 padF6_[0xF6];
            u8 sex; /* +0xF6 */
            u8 ratingLevel; /* +0xF7 */
            u8 padF8_[0x108 - 0xF8];
            u32 profileId; /* +0x108 */
            u32 trainerId; /* +0x10C */
            u8 padName_[0x122 - 0x110];
            u8 trainerView; /* +0x122 */
            u8 pad123_;
            u8 romCode; /* +0x124 */
            u8 language; /* +0x125 */
            u8 greetingSet; /* +0x126 */
            u8 visitedCountryCount; /* +0x127 */
        };
    };
} Entry;

typedef struct {
    s16 name; /* +0x0 */
    s8 mode; /* +0x2 */
    s8 key; /* +0x3 */
    s8 val; /* +0x4 */
} Rec;

typedef struct {
    u8 pad0[0x14 - 0x0];
    u32 speciesFlags; /* +0x14 */
} Aux;

typedef struct {
    u8 pad0[0x4 - 0x0];
    u16 menuRow; /* +0x4 */
    u16 menuScroll; /* +0x6 */
    u16 restoreRow; /* +0x8 */
    u16 restoreScroll; /* +0xA */
    u8 padC[0x20 - 0xC];
    u32 genderEvent; /* +0x20 */
} Target;

typedef struct {
    u32 unit; /* +0x0 */
    u32 mainChar; /* +0x4 */
    u32 mainPlt; /* +0x8 */
    u32 mainCell; /* +0xC */
    u32 slotChar; /* +0x10 */
    u32 slotPlt; /* +0x14 */
    u32 slotCell; /* +0x18 */
    u32 primaryChar; /* +0x1C */
    u32 primaryPlt; /* +0x20 */
    u32 primaryCell; /* +0x24 */
    u32 mainIconChar; /* +0x28 */
    u32 mainIconPlt; /* +0x2C */
    u32 mainIconCell; /* +0x30 */
} Res;

typedef struct {
    s16 x; /* +0x0 */
    s16 y; /* +0x2 */
} SPos;

typedef struct {
    u8 pad0[0x14 - 0x0];
    void *pixels; /* +0x14 */
} CharData;

/* A loaded palette block (same layout as McssPlttData in arm9/mcss.c). */
typedef struct {
    u32 fmt; /* +0x0 */
    u32 extended; /* +0x4 */
    u32 byteSize; /* +0x8 */
    void *data; /* +0xC */
} McssPlttData;

typedef struct {
    void *sys; /* +0x0 */
    void *handle04; /* +0x4 */
    void *party; /* +0x8 */
    void *save; /* +0xC */
    u8 pad10[0x14 - 0x10];
    void *wifiList; /* +0x14 */
    void *wifiHistory; /* +0x18 */
    void *myStatus; /* +0x1C */
    void *statusConfig; /* +0x20 */
    void *record; /* +0x24 */
    u8 pad28[0x3C - 0x28];
    void *saveData; /* +0x3C */
} Args;

typedef struct {
    u32 unit; /* +0x0 */
    u32 mainChar; /* +0x4 */
    u32 mainPlt; /* +0x8 */
    u32 mainCell; /* +0xC */
    u8 pad10[0x28 - 0x10];
    u32 mainIconChar; /* +0x28 */
    u32 mainIconPlt; /* +0x2C */
    u32 mainIconCell; /* +0x30 */
    u32 slotCursorObj; /* +0x34 */
    u32 depositMarkObj; /* +0x38 */
    u32 boxMarkObj; /* +0x3C */
    u32 arrA[30]; /* +0x40 */
    u32 arrB[30]; /* +0xB8 */
} Sub;

typedef struct {
    u32 vram; /* +0x0 */
    u32 pal; /* +0x4 */
    u32 spr; /* +0x8 */
    u8 pixels[0x200]; /* +0xC */
} IconRec;

typedef struct {
    u16 species; /* +0x0 */
    s8 genderPlusOne; /* +0x2 */
    u8 notEgg; /* +0x3 */
} Info;

typedef struct {
    u8 pad0[0x20 - 0x0];
    u32 genderEvent; /* +0x20 */
    int cursorColumn; /* +0x24 */
    int leftRow; /* +0x28 */
    int rightRow; /* +0x2C */
} State;

typedef struct {
    void *evoGameData; /* +0x0 */
    void *list; /* +0x4 */
    u16 evoSpecies; /* +0x8 */
    u8 evoPartyPos; /* +0xA */
    u8 evoCondition; /* +0xB */
    u32 evoFlag; /* +0xC */
    u32 evoResult; /* +0x10 */
    u8 pad14[0x30 - 0x14];
    void *tradeGameData; /* +0x30 */
    void *ownMon; /* +0x34 */
    void *partnerMon; /* +0x38 */
    u32 myStatus; /* +0x3C */
    void *partnerStatus; /* +0x40 */
} Req;

/* Print stream state of the message window: font id, message data, then the stream. */
typedef struct {
    unsigned int font; /* +0x0 */
    unsigned int msgData; /* +0x4 */
    u8 pad8[8];
    void *stream; /* +0x10 */
    void *streamWin; /* +0x14 */
} PrintStreamCtx;

/* Two ten-entry u16 selection tables behind two header words. */
typedef struct {
    u16 reserved00; /* +0x0 */
    u16 reserved02; /* +0x2 */
    u16 a[10]; /* +0x4 */
    u16 b[10]; /* +0x18 */
} SelTable;

/* Arguments of the ov115 save-network process (gNetSaveMainProc), allocated by GFL_HEAP_Alloc. */
typedef struct {
    void *handle; /* +0x0 */
    u32 mode; /* +0x4 */
    u32 enabled; /* +0x8 */
    u32 timeout; /* +0xC */
    void *buf; /* +0x10 */
    u32 isTrade; /* +0x14 */
    u32 reserved18; /* +0x18 */
    u32 result; /* +0x1C */
    int (*callback)(void *, Work *); /* +0x20 */
    Work *user; /* +0x24 */
} NetSaveProcArgs;

/* Arguments of the ov115 table process (tbl_021D654C). */
typedef struct {
    void *save; /* +0x0 */
    int zero; /* +0x4 */
    int enabled; /* +0x8 */
    int pad[2];
    u32 (*callback)(Work *); /* +0x14 */
    Work *context; /* +0x18 */
} NetProcArgs;

typedef struct {
    void *sys; /* +0x0 */
    u8 pad4[0x8 - 0x4];
    void *party; /* +0x8 */
    union { /* +0xC */
        u32 box;
        void *save;
    };
    union { /* +0x10 */
        u32 zukanSave_u;
        void *zukanSave;
    };
    void *wifiList; /* +0x14 */
    void *wifiHistory; /* +0x18 */
    union { /* +0x1C */
        u32 myStatus_u;
        void *myStatus;
    };
    void *statusConfig; /* +0x20 */
    void *record; /* +0x24 */
    u8 pad28[0x2C - 0x28];
    u32 nationalDexEnabled; /* +0x2C */
    u8 pad30[0x3C - 0x30];
    void *saveData; /* +0x3C */
    void *gameData; /* +0x40 */
} Ctx;

/* Request handed to the Pokemon status screen (PokeStatusProc). */
typedef struct {
    void *mon;
    void *config;
    void *save;
    u8 type;
    u8 enabled;
    u8 slotCount;
    u8 slot; /* chosen slot, read back after the screen closes */
    u8 mode;
    u8 pad11[3];
    u16 page;
    u16 pad16;
    u32 nationalDexEnabled;
    u32 reserved1C;
    u32 result;
    u32 reserved24;
} PokeStatusRequest;

struct Work {
    union { /* +0x0 */
        Args *args;
        Ctx *ctx;
    };
    unsigned int f4_u;
    unsigned int f8_u;
    unsigned int fC_u;
    u32 screenId; /* +0x10 */
    u32 nextScreenId; /* +0x14 */
    unsigned int f18_u;
    unsigned int prevScreenId;
    int kind; /* +0x20 */
    int mode; /* +0x24 */
    union { /* +0x28 */
        int state_i;
        u32 state;
        unsigned state_un;
    };
    union { /* +0x2C */
        u32 returnState;
        struct {
            u16 returnStateLow;
            u16 returnStateHigh;
        };
    };
    u16 titleEntered; /* +0x30 */
    u16 busy; /* +0x32 */
    u8 pad34_[2];
    unsigned short cooldownFrames;
    int err; /* +0x38 */
    u8 pad3C[0xB8 - 0x3C];
    u32 subLcdRefresh; /* +0xB8 */
    unsigned short menuChoice;
    u8 padBE[2];
    u16 sel; /* +0xC0 */
    u8 padC2[0xC4 - 0xC2];
    u16 box; /* +0xC4 */
    u16 slot; /* +0xC6 */
    union { /* +0xC8 */
        int boxes;
        u32 nbox;
        unsigned count;
    };
    void *mon; /* +0xCC */
    u32 d0; /* +0xD0 */
    int cur; /* +0xD4 */
    void *info; /* +0xD8 */
    u32 box_u; /* +0xDC */
    u32 pos; /* +0xE0 */
    union { /* +0xE4 */
        Entry ent[9];
        struct {
            Entry single; /* +0xE4 */
            Entry arr[8]; /* +0x20C */
        };
        struct {
            u8 padE4[0x207 - 0xE4];
            s8 receivedEgg; /* +0x207 */
            u8 pad208[0x20C - 0x208];
            Entry arr_entry1[1]; /* +0x20C */
        };
        struct {
            u8 padE4_[0x20C - 0xE4];
            u8 list[1][0x128]; /* +0x20C */
        };
    };
    unsigned short haveSpecies;
    unsigned short haveFormGender;
    short wantSpecies;
    union {
        unsigned short wantGenderLevelMin;
        struct {
            signed char wantGender;
            signed char wantLevelMin;
        };
    };
    union {
        unsigned short wantLevelMaxPair;
        signed char wantLevelMax;
    };
    union { /* +0xB56 */
        Rec rec_rec2[2];
        struct {
            Rec rec; /* +0xB56 */
            u16 rec2Name; /* +0xB5C */
        };
        struct {
            u16 sel_h; /* +0xB56 */
            s8 mode_sb; /* +0xB58 */
            u8 recKey; /* +0xB59 */
            u8 recVal; /* +0xB5A */
        };
        struct {
            u8 padB56[0xB58 - 0xB56];
            u8 recMode; /* +0xB58 */
        };
    };
    u8 padB62[0xB64 - 0xB62];
    u32 lastCountryFilter; /* +0xB64 */
    void *words; /* +0xB68 */
    union { /* +0xB6C */
        void *msg[5];
        struct {
            u32 bank_u; /* +0xB6C */
            void *names; /* +0xB70 */
            u8 padB74[0xB7C - 0xB74];
            void *msg_p; /* +0xB7C */
        };
        void *bank;
    };
    void *boxNameStr; /* +0xB80 */
    void *strs; /* +0xB84 */
    void *str; /* +0xB88 */
    void *titleStr;
    void *name0; /* +0xB90 */
    void *name1; /* +0xB94 */
    u8 padB98[0xBC0 - 0xB98];
    union { /* +0xBC0 */
        Sub sub;
        struct {
            Res res_res; /* +0xBC0 */
            u32 cursor; /* +0xBF4 */
            void *mark; /* +0xBF8 */
            u32 cursor_u; /* +0xBFC */
            u32 icon[30]; /* +0xC00 */
            u32 item[30]; /* +0xC78 */
        };
        struct {
            void *res; /* +0xBC0 */
            void *set[3]; /* +0xBC4 */
            u8 padBD0[0xBE8 - 0xBD0];
            void *set2; /* +0xBE8 */
            u8 padBEC[0xBF0 - 0xBEC];
            void *set3; /* +0xBF0 */
            void *cursor_p; /* +0xBF4 */
        };
    };
    u32 arrC[6]; /* +0xCF0 */
    void *obj; /* +0xD08 */
    union { /* +0xD0C */
        u32 spr[10];
        struct {
            u8 padD0C[0xD2C - 0xD0C];
            u32 arrows[2]; /* +0xD2C */
        };
        struct {
            u8 padD0C_[0xD2C - 0xD0C];
            void *btn[2]; /* +0xD2C */
        };
    };
    u32 arrow; /* +0xD34 */
    u32 scrollBarObj; /* +0xD38 */
    union { /* +0xD3C */
        int scroll;
        u32 pageNum;
    };
    union { /* +0xD40 */
        u32 frame;
        void *d40;
    };
    u8 padD44_[4];
    void *titleWin;
    void *boxNameWin; /* +0xD4C */
    union { /* +0xD50 */
        u8 menuWins[0xD90 - 0xD50];
        u32 win[3];
        u32 side_u2[2];
        void *side_p2[2];
        struct {
            u32 side; /* +0xD50 */
            void *win3; /* +0xD54 */
        };
    };
    union { /* +0xD90 */
        u32 win_u16[16];
        struct {
            u32 item_u14[14]; /* +0xD90 */
            void *hint; /* +0xDC8 */
            void *pane; /* +0xDCC */
        };
        struct {
            void *win_p7[7]; /* +0xD90 */
            void *pane2[2]; /* +0xDAC */
            void *title; /* +0xDB4 */
            void *pane2_p5[5]; /* +0xDB8 */
        };
        struct {
            u32 item_u6[6]; /* +0xD90 */
            u32 page[3]; /* +0xDA8 */
            u8 padDB4[0xDC0 - 0xDB4];
            void *pane3[2]; /* +0xDC0 */
        };
        struct {
            void *wins[6]; /* +0xD90 */
            u8 padDA8[0xDB0 - 0xDA8];
            void *wDB0; /* +0xDB0 */
        };
        struct {
            void *win_p4[4]; /* +0xD90 */
            u8 padDA0[0xDA4 - 0xDA0];
            void *wDA4; /* +0xDA4 */
        };
        struct {
            u8 padD90[0xD94 - 0xD90];
            void *winA; /* +0xD94 */
            u8 padD98[0xD9C - 0xD98];
            void *winB; /* +0xD9C */
        };
    };
    union { /* +0xDD0 */
        void *dd0;
        u32 dd0_u;
    };
    u8 menuInitArg[4]; /* +0xDD4 */
    union { /* +0xDD8 */
        u32 tab[2];
        void *win2[2];
    };
    void *msgWin;
    void *menu; /* +0xDE4 */
    void *de8; /* +0xDE8 */
    u8 padDEC_[8];
    void *speciesMenuList;
    u32 timeIcon; /* +0xDF8 */
    int cnt; /* +0xDFC */
    union { /* +0xE00 */
        Aux *aux;
        State *st;
        Target *target;
    };
    void *taskMenuRes;
    void *taskMenu;
    unsigned short stateAfterSaveWait;
    unsigned short stateAfterSave;
    u32 next; /* +0xE10 */
    void *animTask;
    u16 active; /* +0xE18 */
    u16 historyFlag; /* +0xE1A */
    void *buf[16]; /* +0xE1C */
    CharData *chr[16]; /* +0xE5C */
    void *main; /* +0xE9C */
    void *palData; /* +0xEA0 */
    void *monCopy; /* +0xEA4 */
    void *tradeMon; /* +0xEA8 */
    Info *info_p; /* +0xEAC */
    u16 species; /* +0xEB0 */
    u16 speciesCleared; /* +0xEB2 */
    u32 eb4; /* +0xEB4 */
    IconRec *icons; /* +0xEB8 */
    union { /* +0xEBC */
        Cb once;
        void (*vblank_fn)(Work *);
    };
    union { /* +0xEC0 */
        Cb every;
        void (*vblank)(Work *);
    };
    SPos pos_spos8[8]; /* +0xEC4 */
    u8 padEE4[0xEEC - 0xEE4];
    union { /* +0xEEC */
        u8 area[0xFA0 - 0xEEC];
        SelTable selTable; /* +0xEEC */
        struct {
            u8 padEEC[0xEF0 - 0xEEC];
            u16 a[10]; /* +0xEF0 */
            u16 b[10]; /* +0xF04 */
            u8 trInfo[0xF7C - 0xF18]; /* +0xF18 */
            int state_iF7C; /* +0xF7C */
            int sub_i; /* +0xF80 */
            u32 countryFilter; /* +0xF84 */
            short subStep;
            short stepTimer;
            int wait; /* +0xF8C */
            void *vblank_p; /* +0xF90 */
            void *rec_p; /* +0xF94 */
            void *animTaskData;
            void *recMem; /* +0xF9C */
        };
        struct {
            u8 padEEC_[0xF8C - 0xEEC];
            u32 timer; /* +0xF8C */
        };
    };
    union { /* +0xFA0 */
        union {
            u8 tail[0x12F0 - 0xFA0];
            struct {
                u8 padFA0[832];
                unsigned int bgLayersLoaded;
                u8 pad12E4[4];
                int countdownFrames;
                unsigned int connectStep;
            };
        };
        struct {
            u8 printerBlock[4]; /* +0xFA0 */
            u8 padFA4[0x10DC - 0xFA4];
            union {
                Req *req; /* +0x10DC */
                PokeStatusRequest *statusReq;
                NetSaveProcArgs *saveArgs;
                NetProcArgs *netArgs;
            };
            void *wm; /* +0x10E0 */
            u8 valid; /* +0x10E4 */
            u8 pad10E5[0x10E8 - 0x10E5];
            u32 count_u; /* +0x10E8 */
            u8 buf_b128[0x80]; /* +0x10EC */
            u8 netBuf[0x12E4 - 0x116C]; /* +0x116C */
            u32 keepBgLayers; /* +0x12E4 */
        };
        PrintStreamCtx printCtx; /* +0xFA0 */
        struct {
            u32 uiResA; /* +0xFA0 */
            u8 padFA4_[8];
            u32 uiResB; /* +0xFAC */
        };
        u8 queue[1];
    };
    void *procSys; /* +0x12F0 */
    u32 busy_u; /* +0x12F4 */
    u32 checkEvolution; /* +0x12F8 */
    u32 flag; /* +0x12FC */
    u8 pad1300_[24];
    unsigned int profanityWords;
    u8 pad131C[4];
    union { /* +0x1320 */
        unsigned int badWordCountU;
        int nameCheckResult;
    };
    unsigned short reserved1324;
    u8 pad1326[2];
    u32 done; /* +0x1328 */
};

/* ---- types folded in from the per-file shared headers ---- */

struct Actor;
struct BigObj;
struct Blk37;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Node;
struct Obj;
struct Party;
struct PartyMon;
struct Personal;
struct Rec0200AD8C;
struct Rec0200AD94;
struct RecDC;
struct RegB;
struct Slot;
struct Strbuf;
struct Sub02007454Entry;
struct Sub020079BCEntry;
struct Sub0200852CObj;
struct Sub02009470Obj;
struct U16Vec;
struct Vec2;
struct WinMgr;
struct WordSet;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

typedef struct {
    s16 species; /* sign-extending original loads: ldrsh / ldrsb */
    s8 form;
    s8 level;
} MonTag;

/* The wanted mon of a trade deposit: species, form and the level range. */
typedef struct {
    s16 species; /* sign-extending original loads: ldrsh / ldrsb */
    s8 form;
    s8 levelMin;
    s8 levelMax;
} WantTag;

/* A deposit record: the offered mon header at +0xEC, the wanted tag at +0xF0. */
typedef struct {
    u8 pad0[0xEC];
    MonTag have;
    WantTag want;
} Deposit;

/* Deposit screen scratch, 0x30 bytes, allocated by WORLDTRADE_DEPOSIT_CreateStrings. */
typedef struct {
    u8 pad0[4];
    u16 menuRow; /* +0x4, menu row saved by BMP_MENULIST_Delete */
    u16 menuScroll; /* +0x6, menu scroll saved by BMP_MENULIST_Delete */
    u16 restoreRow; /* +0x8, row restored through SelTable b[] */
    u16 restoreScroll; /* +0xA, scroll restored through SelTable a[] */
    u8 padC[0x14 - 0xC];
    u8 *speciesFlags; /* +0x14, seen-species bitmap */
    u16 *speciesList; /* +0x18, species id list */
    u32 speciesCount; /* +0x1C */
    u32 genderEvent; /* +0x20, Personal param 20 of the selected species */
    u8 pad24[0x30 - 0x24];
} DepositState;

struct DispConfig {
    u32 dispMode;
    u32 bgMode;
    u32 subBgMode;
    u32 bg0As;
};

struct BgTemplate {
    u32 scrollX;
    u32 scrollY;
    u32 bufSize;
    u32 baseTile;
    u8  screenSize;
    u8  colorMode;
    u8  screenBase;
    u8  charBase;
    u32 tileDataSize;
    u8  extPltt;
    u8  priority;
    u8  areaOver;
    u8  pad_1b;
    u32 mosaic;
};

typedef struct { u16 x, y, z; u8 pri, bgPriority; } ObjPos;

typedef struct {
    void *win0;
    void *win1;
} Pane2;

/* One print job slot of a Printer: the window it prints into, whether the
 * print is still in flight, and whether the slot is in use. */
typedef struct {
    void *win;
    u8 busy;
    u8 pad5[3];
    u32 used;
} PrinterSlot;

/* The adapter's printer object (0x13C bytes).  It is the block embedded at
 * Work+0xFA0: a font, the TCB task and its argument, the print queue, the
 * yes/no print stream, 24 print slots and the key cursor. */
typedef struct {
    void *font;
    void *tcb;
    u32 arg;
    void *queue;
    void *yesno;
    void *yesnoArg;
    PrinterSlot slots[24];
    void *cursor;
} Printer;

struct Obj { u32 w0; u32 w1; u32 w2; u32 w3; void *h; u32 n; PrinterSlot e[24]; };

/* One print slot of the message system: the window it prints into and whether
 * the print is still in flight. */
typedef struct {
    void *win;
    u8 busy;
    u8 pad5[3];
} MsgSlot;

/* The adapter's message-system object (0x74 bytes, allocated by
 * WORLDTRADE_ADAPTER_InitMessageSystem): a font, the print queue, a WordSet,
 * a MsgBank, 8 print slots, their in-use flags and the heap id. */
typedef struct {
    void *font;
    void *queue;
    void *words;
    void *bank;
    MsgSlot slots[8];
    u32 used[8];
    u16 heap;
} MsgSys;

typedef volatile unsigned short vu16;

typedef volatile unsigned int vu32;

typedef struct {
    u16 x;
    u16 y;
} Pos;

/* tables of the input state machine */
typedef struct {
    u8 x;
    u8 y;
} Cell;

typedef struct {
    u8 x;
    u8 y;
} CurPos;

/* An index range into a table: first index and count. */
typedef struct {
    int first;
    int count;
} Range;

#endif
