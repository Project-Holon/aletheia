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
    unsigned int f14;
    void *mgr;
    void *bag;
    void *bank;
    void *msg;
    void *x28;
    u32 x2c;
    Item *items;
    void *num;
    s16 layout;
    s16 start;
    short f3C;
    short f3E;
    s8 f40;
    s8 f41;
    u8 pad42[2];
    int pos;
    int state;
    int f4C;
    u32 layer;
    short f54;
    s16 page;
    int total;
    int f5C;
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
            u8 lang; /* +0x120 */
            u8 ver; /* +0x121 */
        };
        struct {
            u8 padF6_[0xF6];
            u8 gender; /* +0xF6 */
            u8 profileFlagA; /* +0xF7 */
            u8 padF8_[0x108 - 0xF8];
            u32 profileId; /* +0x108 */
            u32 trainerId; /* +0x10C */
            u8 padName_[0x122 - 0x110];
            u8 country; /* +0x122 */
            u8 pad123_;
            u8 region; /* +0x124 */
            u8 city; /* +0x125 */
            u8 profileFlagB; /* +0x126 */
            u8 profileFlagC; /* +0x127 */
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
    u32 f14; /* +0x14 */
} Aux;

typedef struct {
    u8 pad0[0x4 - 0x0];
    u16 x4; /* +0x4 */
    u16 x6; /* +0x6 */
    u16 x8; /* +0x8 */
    u16 xA; /* +0xA */
    u8 padC[0x20 - 0xC];
    u32 x20; /* +0x20 */
} Target;

typedef struct {
    u32 f0; /* +0x0 */
    u32 f4; /* +0x4 */
    u32 f8; /* +0x8 */
    u32 fC; /* +0xC */
    u32 f10; /* +0x10 */
    u32 f14; /* +0x14 */
    u32 f18; /* +0x18 */
    u32 f1C; /* +0x1C */
    u32 f20; /* +0x20 */
    u32 f24; /* +0x24 */
    u32 f28; /* +0x28 */
    u32 f2C; /* +0x2C */
    u32 f30; /* +0x30 */
} Res;

typedef struct {
    s16 x; /* +0x0 */
    s16 y; /* +0x2 */
} SPos;

typedef struct {
    u8 pad0[0x14 - 0x0];
    void *pixels; /* +0x14 */
} CharData;

typedef struct {
    void *a0; /* +0x0 */
    void *a4; /* +0x4 */
    void *a8; /* +0x8 */
    void *aC; /* +0xC */
    u8 pad10[0x14 - 0x10];
    void *a14; /* +0x14 */
    void *a18; /* +0x18 */
    void *a1C; /* +0x1C */
    void *a20; /* +0x20 */
    void *a24; /* +0x24 */
    u8 pad28[0x3C - 0x28];
    void *a3C; /* +0x3C */
} Args;

typedef struct {
    u32 f0; /* +0x0 */
    u32 f4; /* +0x4 */
    u32 f8; /* +0x8 */
    u32 fC; /* +0xC */
    u8 pad10[0x28 - 0x10];
    u32 f28; /* +0x28 */
    u32 f2C; /* +0x2C */
    u32 f30; /* +0x30 */
    u32 f34; /* +0x34 */
    u32 f38; /* +0x38 */
    u32 f3C; /* +0x3C */
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
    s8 f2; /* +0x2 */
    u8 f3; /* +0x3 */
} Info;

typedef struct {
    u8 pad0[0x20 - 0x0];
    u32 f20; /* +0x20 */
    int f24; /* +0x24 */
    int f28; /* +0x28 */
    int f2C; /* +0x2C */
} State;

typedef struct {
    void *f0; /* +0x0 */
    void *list; /* +0x4 */
    u16 f8; /* +0x8 */
    u8 fA; /* +0xA */
    u8 fB; /* +0xB */
    u32 fC; /* +0xC */
    u32 f10; /* +0x10 */
    u8 pad14[0x30 - 0x14];
    void *f30; /* +0x30 */
    void *f34; /* +0x34 */
    void *f38; /* +0x38 */
    u32 f3C; /* +0x3C */
    void *f40; /* +0x40 */
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
    u16 f0; /* +0x0 */
    u16 f2; /* +0x2 */
    u16 a[10]; /* +0x4 */
    u16 b[10]; /* +0x18 */
} SelTable;

/* Arguments of the ov115 save-network process (gNetSaveMainProc), allocated by func_02030734. */
typedef struct {
    void *handle; /* +0x0 */
    u32 mode; /* +0x4 */
    u32 enabled; /* +0x8 */
    u32 timeout; /* +0xC */
    void *buf; /* +0x10 */
    u32 isTrade; /* +0x14 */
    u32 f18; /* +0x18 */
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
        u32 f10;
        void *dex;
    };
    void *wifiList; /* +0x14 */
    void *status; /* +0x18 */
    union { /* +0x1C */
        u32 f1C_u;
        void *f1C;
    };
    void *statusConfig; /* +0x20 */
    u8 pad24[0x2C - 0x24];
    void *statusRules; /* +0x2C */
    u8 pad30[0x40 - 0x30];
    void *f40; /* +0x40 */
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
    void *rules;
    u32 f1C;
    u32 result;
    u32 f24;
} PokeStatusRequest;

struct Work {
    union { /* +0x0 */
        Args *args;
        Ctx *ctx;
    };
    unsigned int f4_u;
    unsigned int f8_u;
    unsigned int fC_u;
    u32 x10; /* +0x10 */
    u32 x14; /* +0x14 */
    unsigned int f18_u;
    unsigned int f1C_u;
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
            u16 x2C;
            u16 x2E;
        };
    };
    u16 x30; /* +0x30 */
    u16 busy; /* +0x32 */
    u8 pad34_[2];
    unsigned short f36;
    int err; /* +0x38 */
    u8 pad3C[0xB8 - 0x3C];
    u32 fB8; /* +0xB8 */
    unsigned short fBC;
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
            s8 f207; /* +0x207 */
            u8 pad208[0x20C - 0x208];
            Entry arr_entry1[1]; /* +0x20C */
        };
        struct {
            u8 padE4_[0x20C - 0xE4];
            u8 list[1][0x128]; /* +0x20C */
        };
    };
    unsigned short fB4C;
    unsigned short fB4E;
    short fB50;
    union {
        unsigned short fB52_h;
        struct {
            signed char fB52;
            signed char fB53;
        };
    };
    union {
        unsigned short fB54;
        signed char fB54_c;
    };
    union { /* +0xB56 */
        Rec rec_rec2[2];
        struct {
            Rec rec; /* +0xB56 */
            u16 xB5C; /* +0xB5C */
        };
        struct {
            u16 sel_h; /* +0xB56 */
            s8 mode_sb; /* +0xB58 */
            u8 xB59; /* +0xB59 */
            u8 xB5A; /* +0xB5A */
        };
        struct {
            u8 padB56[0xB58 - 0xB56];
            u8 xB58; /* +0xB58 */
        };
    };
    u8 padB62[0xB64 - 0xB62];
    u32 fB64; /* +0xB64 */
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
    void *fB80; /* +0xB80 */
    void *strs; /* +0xB84 */
    void *str; /* +0xB88 */
    void *fB8C;
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
    u32 fD38; /* +0xD38 */
    union { /* +0xD3C */
        int scroll;
        u32 pageNum;
    };
    union { /* +0xD40 */
        u32 frame;
        void *d40;
    };
    u8 padD44_[4];
    void *fD48;
    void *fD4C; /* +0xD4C */
    union { /* +0xD50 */
        u8 fD50[0xD90 - 0xD50];
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
    void *dd0; /* +0xDD0 */
    u8 fDD4[4]; /* +0xDD4 */
    union { /* +0xDD8 */
        u32 tab[2];
        void *win2[2];
    };
    void *fDE0;
    void *menu; /* +0xDE4 */
    void *de8; /* +0xDE8 */
    u8 padDEC_[8];
    void *fDF4;
    u32 xDF8; /* +0xDF8 */
    int cnt; /* +0xDFC */
    union { /* +0xE00 */
        Aux *aux;
        State *st;
        Target *target;
    };
    void *fE04;
    void *fE08;
    unsigned short fE0C;
    unsigned short fE0E;
    u32 next; /* +0xE10 */
    void *fE14;
    u16 active; /* +0xE18 */
    u16 fE1A; /* +0xE1A */
    void *buf[16]; /* +0xE1C */
    CharData *chr[16]; /* +0xE5C */
    void *main; /* +0xE9C */
    void *palData; /* +0xEA0 */
    void *fEA4; /* +0xEA4 */
    void *fEA8; /* +0xEA8 */
    Info *info_p; /* +0xEAC */
    u16 species; /* +0xEB0 */
    u16 xEB2; /* +0xEB2 */
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
            u32 fF84; /* +0xF84 */
            short fF88;
            short fF8A;
            int wait; /* +0xF8C */
            void *vblank_p; /* +0xF90 */
            void *rec_p; /* +0xF94 */
            void *fF98;
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
                unsigned int f12E0;
                u8 pad12E4[4];
                int f12E8;
                unsigned int f12EC;
            };
        };
        struct {
            u8 fFA0[4]; /* +0xFA0 */
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
            u32 f12E4; /* +0x12E4 */
        };
        PrintStreamCtx printCtx; /* +0xFA0 */
        struct {
            u32 uiResA; /* +0xFA0 */
            u8 padFA4_[8];
            u32 uiResB; /* +0xFAC */
        };
        u8 queue[1];
    };
    void *f12F0; /* +0x12F0 */
    u32 busy_u; /* +0x12F4 */
    u32 f12F8; /* +0x12F8 */
    u32 flag; /* +0x12FC */
    u8 pad1300_[24];
    unsigned int f1318;
    u8 pad131C[4];
    unsigned int f1320;
    unsigned short f1324;
    u8 pad1326[2];
    u32 done; /* +0x1328 */
};

typedef struct WorldtradeEnterObj1 {
    u8 pad0[3976];
    short fF88;
    short fF8A;
} WorldtradeEnterObj1;

typedef struct WorldtradeEnterObj2 {
    u8 pad0[56];
    unsigned int f38;
    u8 pad3C[3920];
    unsigned int fF8C;
} WorldtradeEnterObj2;

typedef struct WorldtradeEnterObj3 {
    unsigned short f0;
    unsigned short f2;
} WorldtradeEnterObj3;

typedef struct WorldtradeEnterObj4 {
    u8 pad0[4];
    unsigned short f4;
    u8 pad6[18];
    unsigned short f18;
} WorldtradeEnterObj4;

typedef struct WorldtradeBoxObj1 {
    unsigned int f0;
    u8 pad4[28];
    unsigned int f20;
    u8 pad24[4];
    unsigned int f28;
    u8 pad2C[2880];
    void *fB6C;
    u8 padB70[140];
    unsigned int fBFC;
    u8 padC00[312];
    void *fD38;
    u8 padD3C[168];
    void *fDE4;
    void *fDE8;
    u8 padDEC[24];
    void *fE04;
    void *fE08;
    u8 padE0C[404];
    unsigned int fFA0;
    u8 padFA4[8];
    unsigned int fFAC;
} WorldtradeBoxObj1;

typedef struct WorldtradeBoxObj2 {
    void *f0;
    void *f4;
    void *f8;
} WorldtradeBoxObj2;

typedef struct WorldtradeBoxObj3 {
    u8 pad0[4];
    unsigned short f4;
    unsigned short f6;
    unsigned short f8;
    unsigned short fA;
} WorldtradeBoxObj3;

typedef struct WorldtradeBoxObj4 {
    u8 pad0[20];
    int f14;
    u8 pad18[16];
    int f28;
    u8 pad2C[3720];
    int fEB4;
} WorldtradeBoxObj4;

typedef struct WorldtradeBoxObj5 {
    u8 pad0[236];
    unsigned short fEC;
    unsigned short fEE;
    unsigned short fF0;
    unsigned short fF2;
    unsigned short fF4;
} WorldtradeBoxObj5;

typedef struct WorldtradeBoxObj6 {
    u8 pad0[4];
    unsigned short f4;
    unsigned short f6;
    u8 pad8[12];
    unsigned int f14;
    void *f18;
    unsigned int f1C;
} WorldtradeBoxObj6;

typedef struct WorldtradeBoxObj7 {
    short f0;
    signed char f2;
    signed char f3;
    signed char f4;
} WorldtradeBoxObj7;

typedef struct WorldtradeBoxObj8 {
    u8 pad0[2];
    unsigned char f2;
} WorldtradeBoxObj8;

typedef struct WorldtradeBoxObj9 {
    short f0;
    signed char f2;
    signed char f3;
} WorldtradeBoxObj9;

typedef struct WorldtradeBoxObj10 {
    u8 pad0[3072];
    unsigned int fC00;
    u8 padC04[116];
    unsigned int fC78;
} WorldtradeBoxObj10;

typedef struct WorldtradeAdapterObj1 {
    void *f0;
    u8 pad4[4];
    unsigned int f8;
    unsigned int fC;
    unsigned int f10;
    unsigned int f14;
    void *f18;
    u8 pad1C[4];
    void *f20;
    u8 pad24[4];
    void *f28;
    u8 pad2C[4];
    void *f30;
    void *f34;
    short f38;
    short f3A;
    u8 pad3C[2];
    short f3E;
    signed char f40;
    signed char f41;
    u8 pad42[2];
    int f44;
    int f48;
    int f4C;
    u8 pad50[6];
    short f56;
    int f58;
    u8 pad5C[106];
    unsigned short fC6;
    u8 padC8[4116];
    unsigned int f10DC;
} WorldtradeAdapterObj1;

typedef struct WorldtradeAdapterObj2 {
    u8 pad0[8];
    unsigned int f8;
    u8 padC[28];
    unsigned int f28;
    unsigned int f2C;
    u8 pad30[10];
    short f3A;
    u8 pad3C[8];
    unsigned int f44;
    unsigned int f48;
    unsigned int f4C;
    u8 pad50[3500];
    int fDFC;
} WorldtradeAdapterObj2;

typedef struct WorldtradeAdapterObj3 {
    u8 pad0[8];
    void *f8;
    u8 padC[28];
    int f28;
    u8 pad2C[20];
    signed char f40;
    u8 pad41[2837];
    unsigned short fB56;
    unsigned short fB58;
    unsigned short fB5A;
    unsigned short fB5C;
    unsigned short fB5E;
    unsigned short fB60;
    u8 padB62[2];
    unsigned int fB64;
    u8 padB68[690];
    unsigned short fE1A;
    u8 padE1C[360];
    int fF84;
    u8 padF88[4];
    int fF8C;
} WorldtradeAdapterObj3;

typedef struct WorldtradeAdapterObj5 {
    u8 pad0[236];
    unsigned short fEC;
    u8 padEE[9];
    unsigned char fF7;
    u8 padF8[20];
    unsigned int f10C;
    u8 pad110[22];
    unsigned char f126;
    unsigned char f127;
} WorldtradeAdapterObj5;

typedef struct WorldtradeAdapterObj6 {
    u8 pad0[3340];
    unsigned int fD0C;
    u8 padD10[264];
    unsigned short fE18;
} WorldtradeAdapterObj6;

typedef struct WorldtradeAdapterObj7 {
    u8 pad0[3340];
    unsigned int fD0C;
} WorldtradeAdapterObj7;

typedef struct WorldtradeAdapterObj8 {
    u8 pad0[3340];
    void *fD0C;
    u8 padD10[436];
    short fEC4;
    short fEC6;
} WorldtradeAdapterObj8;

typedef struct WorldtradeAdapterObj9 {
    u8 pad0[3340];
    void *fD0C;
    u8 padD10[436];
    short fEC4;
    short fEC6;
} WorldtradeAdapterObj9;

typedef struct WorldtradeAdapterObj10 {
    u8 pad0[15];
    unsigned char fF;
} WorldtradeAdapterObj10;

typedef struct WorldtradeAdapterObj11 {
    u8 pad0[12];
    void *fC;
} WorldtradeAdapterObj11;


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

struct DispConfig_021F4580 {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

struct BgTemplate_021F4580 {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

typedef struct {
    u16 species;
    u8 form;
    u8 gender;
} MonTag;

struct DispConfig {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

typedef struct { u16 x, y, z; u8 pri, f7; } ObjPos;

typedef struct {
    void *win0;
    void *win1;
} Pane2;

typedef struct {
    void *win;
    u8 busy;
    u8 pad5[3];
    u32 used;
} Slot_02202878;

typedef struct {
    u32 font;
    u8 pad4[0xC - 0x4];
    u32 print;
    u8 pad10[0x18 - 0x10];
    Slot_02202878 slots[24];
} Ctx_02202878;

struct Ent_02202940 { u32 a; u32 b; u32 c; };

struct Obj { u32 w0; u32 w1; u32 w2; u32 w3; void *h; u32 n; struct Ent_02202940 e[24]; };

typedef struct {
    void *win;
    u8 shown;
    u8 pad5[3];
} Slot;

typedef struct {
    void *font;
    void *print;
    void *words;
    void *bank;
    Slot slot[8];
    u32 used[8];
    u16 heap;
} Ctx_02202A50;

typedef volatile unsigned short vu16;

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

typedef struct {
    int first;
    int count;
} Range_021FA7C4;

#endif
