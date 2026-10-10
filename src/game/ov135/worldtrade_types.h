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
    u8 pad14[0x18 - 0x14];
    void *mgr;
    void *bag;
    void *bank;
    void *msg;
    u8 pad28[0x2C - 0x28];
    u32 x2c;
    Item *items;
    void *num;
    s16 layout;
    s16 start;
    u8 pad3C[0x44 - 0x3C];
    int pos;
    int state;
    u8 pad4C[0x50 - 0x4C];
    u32 layer;
    u8 pad54[0x56 - 0x54];
    s16 page;
    int total;
    u8 pad5C[0x60 - 0x5C];
    u8 flags[0x7A - 0x60];
    u8 last;
    u8 pad7B;
    u8 g[4];
} Menu;

/* ---- canonical work block (generated) ---- */

typedef void (*Cb)(void *p);

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
    u8 pad14[0x18 - 0x14];
    void *status; /* +0x18 */
    union { /* +0x1C */
        u32 f1C_u;
        void *f1C;
    };
    u8 pad20[0x40 - 0x20];
    void *f40; /* +0x40 */
} Ctx;

typedef struct {
    union { /* +0x0 */
        Args *args;
        Ctx *ctx;
    };
    u8 pad4[0x10 - 0x4];
    u32 x10; /* +0x10 */
    u32 x14; /* +0x14 */
    u8 pad18[0x20 - 0x18];
    int kind; /* +0x20 */
    int mode; /* +0x24 */
    union { /* +0x28 */
        int state_i;
        u32 state;
        unsigned state_un;
    };
    u16 x2C; /* +0x2C */
    u16 x2E; /* +0x2E */
    u16 x30; /* +0x30 */
    u16 busy; /* +0x32 */
    u8 pad34[0x38 - 0x34];
    int err; /* +0x38 */
    u8 pad3C[0xB8 - 0x3C];
    u32 fB8; /* +0xB8 */
    u8 padBC[0xC0 - 0xBC];
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
    u8 padB4C[0xB56 - 0xB4C];
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
    u8 padB8C[0xB90 - 0xB8C];
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
    u8 padD44[0xD4C - 0xD44];
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
    u8 padDE0[0xDE4 - 0xDE0];
    void *menu; /* +0xDE4 */
    void *de8; /* +0xDE8 */
    u8 padDEC[0xDF8 - 0xDEC];
    u32 xDF8; /* +0xDF8 */
    int cnt; /* +0xDFC */
    union { /* +0xE00 */
        Aux *aux;
        State *st;
        Target *target;
    };
    u8 padE04[0xE10 - 0xE04];
    u32 next; /* +0xE10 */
    u8 padE14[0xE18 - 0xE14];
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
        void (*vblank_fn)(void *);
    };
    union { /* +0xEC0 */
        Cb every;
        void (*vblank)(void *);
    };
    SPos pos_spos8[8]; /* +0xEC4 */
    u8 padEE4[0xEEC - 0xEE4];
    union { /* +0xEEC */
        u8 area[0xFA0 - 0xEEC];
        struct {
            u8 padEEC[0xEF0 - 0xEEC];
            u16 a[10]; /* +0xEF0 */
            u16 b[10]; /* +0xF04 */
            u8 padF18[0xF7C - 0xF18];
            int state_iF7C; /* +0xF7C */
            int sub_i; /* +0xF80 */
            u32 fF84; /* +0xF84 */
            u8 padF88[0xF8C - 0xF88];
            int wait; /* +0xF8C */
            void *vblank_p; /* +0xF90 */
            void *rec_p; /* +0xF94 */
            u8 padF98[0xF9C - 0xF98];
            void *recMem; /* +0xF9C */
        };
        struct {
            u8 padEEC_[0xF8C - 0xEEC];
            u32 timer; /* +0xF8C */
        };
    };
    union { /* +0xFA0 */
        u8 tail[0x12F0 - 0xFA0];
        struct {
            u8 fFA0[4]; /* +0xFA0 */
            u8 padFA4[0x10DC - 0xFA4];
            Req *req; /* +0x10DC */
            void *wm; /* +0x10E0 */
            u8 valid; /* +0x10E4 */
            u8 pad10E5[0x10E8 - 0x10E5];
            u32 count_u; /* +0x10E8 */
            u8 buf_b128[0x80]; /* +0x10EC */
            u8 pad116C[0x12E4 - 0x116C];
            u32 f12E4; /* +0x12E4 */
        };
        u8 queue[1];
    };
    void *f12F0; /* +0x12F0 */
    u32 busy_u; /* +0x12F4 */
    u32 f12F8; /* +0x12F8 */
    u32 flag; /* +0x12FC */
    u8 pad1300[0x1328 - 0x1300];
    u32 done; /* +0x1328 */
} Work;

#endif
