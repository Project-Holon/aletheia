/*
 * file:     worldtrade_adapter_p03.c
 * unit:     yes
 * function: func_021FCFD8, func_021FD08C, func_021FD0F4, func_021FD104, func_021FD1E0, func_021FD270, func_021FD2FC, func_021FD31C, func_021FD368, func_021FD3CC, func_021FD4D4, func_021FD528, func_021FD550, func_021FD5F0, func_021FD65C, func_021FD66C, func_021FD698, func_021FD6D8, func_021FD6F4, func_021FD760, func_021FD790, func_021FD7DC, func_021FD85C, func_021FD8BC, func_021FD924, func_021FDAE4, func_021FDB74, func_021FDBCC, func_021FDCE4, func_021FDD00, func_021FDDA8, func_021FDEFC, func_021FDF2C, func_021FE0BC, func_021FE118, func_021FE178, func_021FE1A4, func_021FE254, func_021FE264, func_021FE338, func_021FE60C, func_021FE6A0, func_021FE744, func_021FE7F0, func_021FE84C, func_021FE8A8, func_021FE8E8
 * address:  0x021FCFD8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049B40  0x02049B40  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049238  0x02049238  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   tbl_02203668   0x02203668  data  a4
 *   func_02202940  0x02202940  thumb  ov135
 *   sub_020452E8   0x020452E8  arm
 *   sub_020456F8   0x020456F8  arm
 *   unit_02045730  0x02045730  arm
 *   sub_020409B4   0x020409B4  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201F31C  0x0201F31C  thumb
 *   func_0201F048  0x0201F048  thumb
 *   func_0201F094  0x0201F094  thumb
 *   func_02202670  0x02202670  thumb
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021FFD1C 0x021FFD1C thumb ov135
 *   func_020362DC 0x020362DC arm
 *   func_02035C08 0x02035C08 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0202208C 0x0202208C thumb
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_021FFB00 0x021FFB00 thumb ov135
 *   tbl_02203608 0x02203608 data a1
 *   tbl_022035FC 0x022035FC data a1
 *   func_021F4BF8  0x021F4BF8  thumb  ov135
 *   func_021F4D14 0x021F4D14 thumb ov135
 *   func_021F4CE4 0x021F4CE4 thumb ov135
 *   func_0204989C  0x0204989C  arm
 *   func_020221A4 0x020221A4 thumb
 *   func_02202840  0x02202840  thumb  ov135
 *   func_02202858  0x02202858  thumb  ov135
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_021F91A0  0x021F91A0  thumb
 *   func_021F91DC  0x021F91DC  thumb
 *   func_020409B4  0x020409B4  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021F7FD4  0x021F7FD4  thumb
 *   func_021F8104  0x021F8104  thumb
 *   func_021F886C  0x021F886C  thumb
 *   func_021F8178  0x021F8178  thumb
 *   func_02040618  0x02040618  arm
 *   func_021FFFE8  0x021FFFE8  thumb
 *   func_02200B34  0x02200B34  thumb
 *   func_02200BAC  0x02200BAC  thumb
 *   func_021F9890  0x021F9890  thumb
 *   func_021FF384  0x021FF384  thumb
 *   func_021FF474  0x021FF474  thumb
 *   func_021F7F9C  0x021F7F9C  thumb
 *   func_021F8098  0x021F8098  thumb
 *   func_021F8154  0x021F8154  thumb
 *   func_021F8010  0x021F8010  thumb
 *   func_021FF50C  0x021FF50C  thumb
 *   d_02203D80 0x02203D80 data a4
 *   d_02203D46 0x02203D46 data a2
 *   func_021F4EA0 0x021F4EA0 thumb ov135
 *   func_021FE9B0 0x021FE9B0 thumb ov135
 *   func_021F4FF4 0x021F4FF4 thumb ov135
 *   func_021F99D0 0x021F99D0 thumb ov135
 *   func_022000E4 0x022000E4 thumb ov135
 *   func_021F4EC8 0x021F4EC8 thumb ov135
 *   func_02043668  0x02043668  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_020435F4  0x020435F4  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040588  0x02040588  arm
 *   func_02040B94  0x02040B94  arm
 *   g_022037F4  0x022037F4  data  ov135
 *   g_02203844  0x02203844  data  ov135
 *   g_02203864  0x02203864  data  ov135
 *   g_02203804  0x02203804  data  ov135
 *   g_02203824  0x02203824  data  ov135
 *   sub_020403F4  0x020403F4  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_020355C4  0x020355C4  arm
 *   tbl_02203D38   0x02203D38  data  a1
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02040C14  0x02040C14  arm
 *   tbl_022037A8   0x022037A8  data  a2
 *   tbl_022037B0   0x022037B0  data  a2
 *   tbl_022037BC   0x022037BC  data  a2
 *   func_020452E8 0x020452E8 arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_02030734  0x02030734  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_021F84EC  0x021F84EC  thumb
 *   func_021F8990  0x021F8990  thumb
 *   g_02203E18     0x02203E18  data  ov135
 *   func_020307B0 0x020307B0 arm
 *   func_021FF318 0x021FF318 thumb ov135
 *   func_0207D55C 0x0207D55C arm
 *   g_022037D4  0x022037D4  data  ov135
 *   func_0201ADE4 0x0201ADE4 thumb
 *   func_0201AE1C 0x0201AE1C thumb
 *   func_0201AE14 0x0201AE14 thumb
 *   func_021F7B9C 0x021F7B9C thumb ov135
 *   func_020355D8  0x020355D8  arm
 *   func_021FEAE0  0x021FEAE0  thumb
 *   func_021FF4D0  0x021FF4D0  thumb
 *   func_021FE9DC  0x021FE9DC  thumb
 *   tbl_02203D46   0x02203D46  data  a2
 *   func_021FFBC8 0x021FFBC8 thumb ov135
 *   func_021C8B18 0x021C8B18 arm ov114
 *   func_021C8BC4 0x021C8BC4 arm ov114
 *   func_021F513C  0x021F513C  thumb  ov135
 *   func_02006210  0x02006210  thumb
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_0203CA04  0x0203CA04  arm
 *   func_0203C968  0x0203C968  arm
 *   func_021C866C  0x021C866C  arm
 *   func_021C86A8  0x021C86A8  arm
 *   func_021FFB20 0x021FFB20 thumb ov135
 */
#include "../../matched/include/Obj00240.h"
#include "../../matched/include/Obj18570.h"
#include "../../matched/include/Obj03069.h"
#include "../../matched/include/Obj09237.h"
#include "../../matched/include/Obj06517.h"
#include "../../matched/include/Obj01063.h"
#include "../../matched/include/Obj08187.h"
#include "../../matched/include/Obj02489.h"
#include "../../matched/include/Obj00045.h"
#include "../../matched/include/Obj02860.h"
#include "../../matched/include/Obj08188.h"
#include "../../matched/include/Obj10587.h"
#include "../../matched/include/Obj12211.h"
#include "../../matched/include/Obj00018.h"
#include "../../matched/include/Obj00287.h"
#include "../../matched/include/Obj08189.h"
#include "../../matched/include/Obj14174.h"
#include "../../matched/include/Obj05416.h"
#include "../../matched/include/Obj23412.h"
#include "../../matched/include/Obj08190.h"
#include "../../matched/include/Obj23413.h"
#include "../../matched/include/Obj23414.h"
#include "../../matched/include/Obj23415.h"
#include "../../matched/include/Obj06518.h"
#include "../../matched/include/Obj01161.h"
#include "../../matched/include/Obj04907.h"
#include "../../matched/include/Obj03832.h"
#include "../../matched/include/Obj14175.h"
#include "../../matched/include/Obj14176.h"
#include "../../matched/include/Obj08191.h"

struct Obj;
struct Descriptor;
struct Cfg;
struct U16Vec;
struct WordSet;
struct CharBuf;
struct MsgBank;
struct Personal;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 f7;
} ObjPos_vCFD8;

typedef struct {
    u8 pad0[0xBC0];
    void *res;
    void *set[3];
    u8 padBD0[0xD08 - 0xBD0];
    void *obj;
} Obj_vCFD8;

typedef struct {
    u32 x;
    u32 y;
    u32 w;
    u32 h;
    u32 bg;
} WinDef;

typedef struct {
    u8 pad0[0xD40];
    u32 frame;
    u8 padD44[0xD50 - 0xD44];
    u32 side[2];
    u8 padD58[0xD90 - 0xD58];
    u32 win[16];
    u8 padDD0[0x12FC - 0xDD0];
    u32 flag;
} Menu_vCFD8;

typedef signed int s32;

typedef struct {
    u8 pad0[0x120];
    u8 lang;
    u8 ver;
    u8 pad122[0x128 - 0x122];
} Entry_021FCFD8;

typedef struct {
    u8 pad0[0xD4];
    int cur;
    u8 padD8[0x20C - 0xD8];
    Entry_021FCFD8 arr[8];
    u8 padB4C[0xB68 - 0xB4C];
    void *words;
    void *msg;
    u8 padB70[0xB88 - 0xB70];
    void *str;
    u8 padB8C[4];
    void *name0;
    void *name1;
} Work_021FCFD8;

typedef struct {u8 left,right;} Pair;

typedef struct {
    u8 pad0[0xF0];
    u8 rec[0x128 - 0xF0];
} Entry_021FD5F0;

typedef struct {
    u8 pad0[0xD4];
    int cur;
    u8 padD8[0x20C - 0xD8];
    Entry_021FD5F0 arr[8];
    u8 padB4C[0xB6C - 0xB4C];
    void *bank;
    void *names;
    u8 padB74[0xB90 - 0xB74];
    void *name0;
    void *name1;
    u8 padB98[0xDB8 - 0xB98];
    void *pane2[5];
    void *pane;
    u8 padDD0[0xFA0 - 0xDD0];
    u8 fFA0[4];
} Work_021FD5F0;

typedef struct {
    void *win;
} Pane;

typedef struct {
    s16 name;
    s8 mode;
    s8 key;
    s8 val;
} Rec_vCFD8;

typedef struct {
    void *win0;
    void *win1;
} Pane2;

typedef struct {
    u8 pad0[0xD3C];
    int scroll;
} Work_vCFD8;

typedef struct {
    s16 name;
    s8 mode;
    s8 key;
    s8 val;
} Rec_vD924;

typedef struct {
    void *w00;
    void *w04;
    void *obj;
    void *w0c;
    void *w10;
    void *w14;
    void *bank;
    void *names;
    void *w20;
    u32 w24;
    u32 w28;
    u32 arg;
} Init;

typedef struct {
    u8 pad0[0x10];
    u32 f10;
} Ctx_vD924;

typedef struct {
    u8 pad0[0x14];
    u32 f14;
} Aux;

typedef struct {
    Ctx_vD924 *ctx;
    u8 pad4[0x20 - 4];
    int kind;
    u8 pad24[4];
    u32 f28;
    u8 pad2C[0xB56 - 0x2C];
    Rec_vD924 rec;
    u8 padB5C[0xB6C - 0xB5C];
    void *bank;
    void *names;
    u8 padB74[0xB7C - 0xB74];
    void *msg;
    u8 padB80[0xBF4 - 0xB80];
    void *cursor;
    void *mark;
    u8 padBFC[0xD2C - 0xBFC];
    void *btn[2];
    u8 padD34[0xD50 - 0xD34];
    u8 fD50[0xD90 - 0xD50];
    void *win[4];
    u8 padDA0[4];
    void *wDA4;
    u8 padDA8[0xDB0 - 0xDA8];
    void *wDB0;
    u8 padDB4[0xDD4 - 0xDB4];
    u8 fDD4[4];
    void *win2[2];
    u8 padDE0[4];
    void *menu;
    u8 padDE8[0xE00 - 0xDE8];
    Aux *aux;
    u8 padE04[0xE1A - 0xE04];
    u16 fE1A;
    u8 padE1C[0xEC0 - 0xE1C];
    void (*vblank)(void *);
    u8 padEC4[0xF84 - 0xEC4];
    u32 fF84;
    u8 padF88[0xFA0 - 0xF88];
    u8 fFA0[4];
    u8 padFA4[0x12E4 - 0xFA4];
    u32 f12E4;
} Work_vD924;

typedef struct { u16 x, y, a, b; } Pos_021FD924;

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

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 f7;
} ObjPos_vD924;

typedef struct {
    u8 page;
    u8 slot;
} Sel;

typedef struct {
    u16 x;
    u16 y;
    u16 anim;
} CurPos_vD924;

typedef struct {
    Sel sel[7];
    CurPos_vD924 cur[1];
} SelTbl;

typedef struct {
    u8 pad0[0xBC0];
    void *res;
    void *set[3];
    u8 padBD0[0xBE8 - 0xBD0];
    void *set2;
    u8 padBEC[4];
    void *set3;
    void *cursor;
    void *mark;
    u8 padBFC[0xD2C - 0xBFC];
    void *btn[2];
} Obj_vD924;

typedef struct {
    u16 x;
    u16 y;
} Pos_021FDB74;

typedef struct {
    u8 pad0[0xD40];
    u32 frame;
    u8 padD44[0xD90 - 0xD44];
    u32 item[6];
    u32 page[3];
    u8 padDB4[0xDD8 - 0xDB4];
    u32 tab[2];
} Menu_vD924;

typedef struct {
    u16 x;
    u16 y;
    u16 anim;
    u16 anim2;
} CurPos_vE338;

typedef struct {
    s16 a;
    s8 b;
    s8 c;
    s8 d;
    s8 pad;
} Rec_vE338;

typedef struct {
    u8 pad0[0x20];
    u32 f20;
    int page;
    int row0;
    int row1;
} State_vE338;

typedef struct {
    u8 pad0[0x28];
    int next;
    u8 pad2C[0xD0 - 0x2C];
    u32 fD0;
    u8 padD4[0xB56 - 0xD4];
    Rec_vE338 rec[2];
    u16 padB62;
    u32 fB64;
    u8 padB68[0xBF4 - 0xB68];
    u32 cursor;
    u8 padBF8[0xE00 - 0xBF8];
    State_vE338 *st;
    u8 padE04[0xF84 - 0xE04];
    u32 fF84;
} Work_vE338;

typedef struct { short id; s8 a, b, c, d; u8 mode, flag; } Request;

extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *h);
extern void func_02082BCC(void *p, int v, int n);
extern struct Obj *func_0204B294(void *res, unsigned int a, unsigned int b, unsigned int c, const void *pos, unsigned short f, unsigned short heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0203D34C(u32 a, u32 b);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 v);
extern void func_02202940(struct Obj *p);
extern u32 sub_020452E8(struct Descriptor *d);
extern void sub_020456F8(struct Descriptor *d);
extern u8 unit_02045730(u32 a);
extern void sub_020409B4(u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F31C(struct WordSet *p);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern u32 func_02202670(u32 a, u32 b, u32 c, u32 d);
extern void func_02045808(struct U16Vec *vec);
extern int func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_021FFD1C(void *, int, int);
extern void func_020061E4(u32);
extern u32 func_020362DC(void);
extern int func_02035C08(const void *);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
extern int func_021FFB00(int);
extern void func_021F4BF8(u8 *p, int b, int unused, int a, int c, u8 flag);
extern int func_021F4D14(char *p);
extern void func_021F4CE4(char *p);
extern void func_0201F7A8(void *, u32);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern unsigned func_020221A4(void);
extern u32 func_02202840(u8 *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern u32 func_02202858(void *p, u8 b, void *s, u32 x, u32 y, void *out);
extern void func_020409B4(u32 v);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern int func_021F91A0(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
extern int func_021F91DC(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
extern void func_021F7FD4(void *win, void *bank, u32 index, u32 y, u16 color, void *g);
extern void func_021F8104(void *win, void *bank, int mode, int force, u32 x, u32 y, u16 color, void *g);
extern int func_021F886C(int key, int val, int which);
extern void func_021F8178(void *win, void *bank, int idx, u32 e, u32 x, u32 y, u16 color, int alt, u32 g);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_021FFFE8(u8 *p, u32 a, u32 b);
extern void func_02200B34(u8 *p);
extern void func_02200BAC(u8 *p, u32 k);
extern void *func_021F9890(Init *init, u32 a, u32 b);
extern void func_021FF384(void **win, void **win2, void *bank, void *g);
extern void func_021FF474(void *win, void *bank, int flag, void *g);
extern void func_021F7F9C(void *win, void *bank, u32 index, u32 y, u32 x, u16 color, void *g);
extern void func_021F8098(void *win, void *bank, int mode, int force, u32 x, int y, u16 color, void *g);
extern void func_021F8154(void *win, void *bank, int idx, u32 e, u32 y, u16 color, int alt, void *g);
extern void func_021F8010(void *win, void *bank, void *bank2, u32 index, u32 y, u32 x, u16 color, void *g);
extern void func_021FF50C(void *p);
extern void func_021F4EA0(u32, int, int);
extern int func_021FE9B0(void *);
extern void func_021F4FF4(u32, u32, u32);
extern void func_021F99D0(u8 *p);
extern void func_022000E4(char *p);
extern void func_021F4EC8(u8 *p);
extern u32 func_02043668(void);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_020435F4(u32 a);
extern void func_02043598(u32 mask, u32 enable);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_02041570(int channel, u16 val);
extern void sub_020403F4(u32 i);
extern void func_0204B84C(void *o, int v);
extern u8 func_020355C4(void);
extern void func_02040C14(u32 a, u32 b, u32 c, u32 d);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082AC0(u32 value, void *dst, u32 size);
extern u8 *func_021F84EC(u32 id);
extern void func_021F8990(u8 *p);
extern u32 func_020307B0(void *p);
extern void func_021FF318(u8 *p, u32 k, int b, int c, int d);
extern int func_0207D55C(volatile u16 *reg);
extern void *func_0201ADE4(u32,int,u32);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern int func_021F7B9C(u8 *p, int event);
extern void func_020355D8(u8 v);
extern void func_021FEAE0(Work_vE338 *p, int i);
extern int func_021FF4D0(Rec_vE338 *x, Rec_vE338 *y, u32 m, u32 n);
extern void func_021FE9DC(Work_vE338 *p);
extern void func_021FFBC8(u8 *p);
extern void func_021C8B18(void *, int, void *);
extern void func_021C8BC4(const void *p, unsigned int x);
extern int func_021C866C();
extern s32 func_021C86A8(void);
extern void func_021F513C(u8 *p);
extern void func_02006210(void);
extern u32 func_0200FBB0(void);
extern void func_0200FBA0(void);
extern void func_0203CA04(void);
extern void func_0203C968(void);
extern void func_021FFB20(u8 *p, int count, int flag);
void func_021FCFD8(u8 *p);
void func_021FD08C(Obj_vCFD8 *p);
void func_021FD0F4(u8 *p);
void func_021FD104(Menu_vCFD8 *p);
void func_021FD1E0(u8 *p);
void func_021FD270(Work_021FCFD8 *p);
void func_021FD2FC(u8 *p);
int func_021FD31C(unsigned char *p);
void func_021FD368(unsigned char *p, int i);
int func_021FD3CC(u8 *p);
int func_021FD4D4(unsigned char *p);
int func_021FD528(u8 *p);
int func_021FD550(unsigned char *p);
void func_021FD5F0(Work_021FD5F0 *p);
int func_021FD65C(u8 *p);
int func_021FD66C(char *p);
int func_021FD698(unsigned char *p);
int func_021FD6D8(u8 *p);
void func_021FD6F4(u8 *p, u32 k, u32 a2, u32 a3, u32 a4);
void func_021FD760(void *bank, Pane *pane, u32 index, void *g, u16 color);
void func_021FD790(void *bank, Pane *pane, u32 index, void *g);
void func_021FD7DC(Pane *pane, void *bank, void *names, Rec_vCFD8 *rec, void *g);
void func_021FD85C(Pane2 *pane, void *s1, void *s2, void *g);
void func_021FD8BC(Work_vCFD8 *p);
int func_021FD924(Work_vD924 *p);
int func_021FDAE4(unsigned char *p);
int func_021FDB74(unsigned char *p);
void func_021FDBCC(void);
void func_021FDCE4(void);
void func_021FDD00(void *p);
void func_021FDDA8(Obj_vD924 *p);
void func_021FDEFC(char *p);
void func_021FDF2C(Menu_vD924 *p);
void func_021FE0BC(unsigned char *p);
void func_021FE118(u8 *p);
void func_021FE178(char *p);
int func_021FE1A4(unsigned char *p);
int func_021FE254(void);
void func_021FE264(u8 *p, int mode);
int func_021FE338(Work_vE338 *p);
int func_021FE60C(unsigned char *p);
int func_021FE6A0(u8 *p);
int func_021FE744(u8 *p);
int func_021FE7F0(char *p);
int func_021FE84C(char *p);
int func_021FE8A8(char *p);
int func_021FE8E8(char *p);
extern const WinDef tbl_02203668[];
extern const Pair tbl_02203608[];
extern const u8 tbl_022035FC[];
extern const Pos_021FD924 d_02203D46[];
extern struct DispConfig g_022037F4;
extern struct BgTemplate g_02203844;
extern struct BgTemplate g_02203864;
extern struct BgTemplate g_02203804;
extern struct BgTemplate g_02203824;
extern const SelTbl tbl_02203D38;
extern const Pos_021FDB74 tbl_022037A8[];
extern const Pos_021FDB74 tbl_022037B0[];
extern const Pos_021FDB74 tbl_022037BC[];
extern u8 g_02203E18[];
extern char g_022037D4[];
extern const CurPos_vE338 tbl_02203D46[];










/*
 * The 0x12fc-field variant: opens the 0x60x0x48 handle, then only when
 * *(u32 *)(p + 0x12fc) == 0 adds the 0xf/0x23 pair through 49658/498F4 and
 * the second 49B40 window.  Both tests reload the same field.
 */
void func_021FCFD8(u8 *p)
{
    void *h;

    func_02049B40(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    func_0201F5BC(4, 1, 2, 0, 0x48);
    h = func_020490F4(0x60, 0x48);
    func_02049658(h, 0x10, 1, 0, 0xc00, 1, 0x48);
    func_02049B68(h, 6, 0, 0, 0x60, 0x48);
    if (((struct Obj00240 *)p)->f12FC == 0) {
        func_02049658(h, 0xf, 6, 0, 0, 0, 0x48);
        func_020498F4(h, 0x23, 6, 0, 0, 0, 0x48);
    }
    func_02049238(h);
    if (((struct Obj00240 *)p)->f12FC == 0) {
        func_02049B40(0x17, 5, 4, 0x20, 0x20, 0x48);
    }
}










void func_021FD08C(Obj_vCFD8 *p)
{
    ObjPos_vCFD8 pos;

    func_02082BCC(&pos, 0, sizeof(pos));
    pos.x = 0xD0;
    pos.y = 0x3A;
    p->obj = func_0204B294(p->res, (u32)p->set[0], (u32)p->set[1], (u32)p->set[2], &pos, 0, 0x48);
    func_0204B92C(p->obj, 1);
    func_0204B878(p->obj, 0x24);
    func_0204B3DC(p->obj, 1);
    func_0203D34C(0, 0x48);
}










/*
 * Tail call into func_0204B3B4 with the pointer held at +0xd08.
 */
void func_021FD0F4(u8 *p)
{
    func_0204B3B4((struct Obj *)(((struct Obj18570 *)p)->fD08));
}










void func_021FD104(Menu_vCFD8 *p)
{
    int i;
    const WinDef *d;
    u32 v;

    p->frame = func_020450F0((u8)4, (u8)2, (u8)0x13, (u8)0x1b, 4, 1, (u16)1);
    if (p->flag == 0) {
        p->side[0] = func_020450F0((u8)4, (u8)1, (u8)0x15, (u8)0xd, 2, 1, (u16)1);
        p->side[1] = func_020450F0((u8)4, (u8)0x11, (u8)0x15, (u8)0xd, 2, 1, (u16)1);
    }
    for (i = 0; i < 16; i++) {
        d = &tbl_02203668[i];
        if (d->bg == 2) {
            p->win[i] = func_020450F0((u8)d->bg, (u8)d->x, (u8)d->y, (u8)d->w, d->h, 0xd, (u16)1);
        } else {
            p->win[i] = func_020450F0((u8)d->bg, (u8)d->x, (u8)d->y, (u8)d->w, d->h, 1, (u16)1);
        }
        v = p->win[i];
        func_02045334((struct Descriptor *)v);
        func_02045374((struct Cfg *)v);
        func_02041B6C(func_02045730((struct Descriptor *)v));
    }
}










/*
 * Tears down the p+0xd90 array of sixteen window handles, each a 020456F8/
 * 02045730/020409B4/020452E8 group, plus the two p+0xd50/p+0xd54 handles
 * and the p+0xd40 window when *(u32 *)(p + 0x12fc) is clear.
 */
void func_021FD1E0(u8 *p)
{
    u32 h;
    s32 i;

    func_02202940((struct Obj *)(p + 0xfa0));
    sub_020452E8((struct Descriptor *)(((struct Obj03069 *)p)->fD40));
    if (((struct Obj03069 *)p)->f12FC == 0) {
        h = ((struct Obj03069 *)p)->fD54;
        sub_020456F8((struct Descriptor *)h);
        sub_020409B4(unit_02045730(h));
        h = ((struct Obj03069 *)p)->fD50;
        sub_020456F8((struct Descriptor *)h);
        sub_020409B4(unit_02045730(h));
        sub_020452E8((struct Descriptor *)(((struct Obj03069 *)p)->fD54));
        sub_020452E8((struct Descriptor *)(((struct Obj03069 *)p)->fD50));
    }
    for (i = 0; i < 0x10; i++) {
        h = *(u32 *)(p + i * 4 + 0xd90);
        sub_020456F8((struct Descriptor *)h);
        sub_020409B4(unit_02045730(h));
        sub_020452E8((struct Descriptor *)(*(u32 *)(p + i * 4 + 0xd90)));
    }
}










void func_021FD270(Work_021FCFD8 *p)
{
    Entry_021FCFD8 *e = &p->arr[p->cur];

    p->str = func_020457B0(0xB4, 0x48);
    func_0201F31C(p->words);
    if (e->lang != 0) {
        func_0201F048(p->words, 8, e->lang);
    }
    if (e->ver != 0) {
        func_0201F094(p->words, 9, e->lang, e->ver);
    }
    p->name0 = (void *)func_02202670((u32)p->words, (u32)p->msg, 0x58, 0x48);
    p->name1 = (void *)func_02202670((u32)p->words, (u32)p->msg, 0x59, 0x48);
}










/*
 * Release the +0xb90, +0xb94 and +0xb88 handles.
 */
void func_021FD2FC(u8 *p)
{
    func_02045808((struct U16Vec *)(((struct Obj09237 *)p)->fB90));
    func_02045808((struct U16Vec *)(((struct Obj09237 *)p)->fB94));
    func_02045808((struct U16Vec *)(((struct Obj09237 *)p)->fB88));
}









int func_021FD31C(unsigned char *p)
{
    func_0204B3DC((struct Obj *)((struct Obj06517 *)p)->fD38, 0);
    if (((struct Obj06517 *)p)->f20 == 16) {
        func_0202208C(0, 1, 1, 0, 16, 1, 0x48);
        ((struct Obj06517 *)p)->f28 = 7;
    } else {
        ((struct Obj06517 *)p)->f28 = 1;
        func_0204B3DC((struct Obj *)((struct Obj06517 *)p)->fD34, 1);
    }
    return 2;
}









void func_021FD368(unsigned char *p, int i)
{
    if (i != ((struct Obj01063 *)p)->fD4 && i >= 0) {
        func_0204B878((struct Obj *)(*(u32 *)(p + (i + 1) * 4 + 0xd0c)), i * 4 + 16);
        ((struct Obj01063 *)p)->f28 = 2;
        func_021F4EC0(p, 3, 17);
        ((struct Obj01063 *)p)->fD4 = i;
        func_021FFD1C(p, i, 0);
        func_020061E4(0x54c);
        ((struct Obj01063 *)p)->f12E4 = 1;
        ((struct Obj01063 *)p)->f12FC = 1;
    }
}









/*
 * prototype: 021FD6F4 retains r2=1,r3=0,sp=0xF0F visibly loaded by this caller.
 */
int func_021FD3CC(u8 *p)
{
    int next, r;
    if(func_020362DC()&1) {
        func_021FD6F4(p,16,1,0,0xF0F);
        func_021F4E98(p,3,4);
        func_020061E4(0x54C);
    } else if(func_020362DC()&2) {
        func_0202208C(0,0,0,0,16,1,0x48);
        ((struct Obj01063 *)p)->f28=8;
        func_020061E4(0x551);
    } else if(func_020362DC()&32) {
        next=tbl_02203608[(u32)*(int *)(p+0xD4)].left;
        if(((struct Obj01063 *)p)->fD4!=next && ((struct Obj01063 *)p)->fD0>=next+1)
            func_021FD368(p,next);
    } else if(func_020362DC()&16) {
        next=tbl_02203608[(u32)*(int *)(p+0xD4)].right;
        if(((struct Obj01063 *)p)->fD4!=next && ((struct Obj01063 *)p)->fD0>=next+1)
            func_021FD368(p,next);
    } else {
        r=func_021FFB00(((struct Obj01063 *)p)->fD0);
        if(r!=-1) func_021FD368(p,r);
        r=func_02035C08(tbl_022035FC);
        if(r==0) {
            func_021FD6F4(p,16,1,0,0xF0F);
            func_021F4E98(p,3,4);
            func_020061E4(0x54C);
        } else if(r==1) {
            func_0202208C(0,0,0,0,16,1,0x48);
            ((struct Obj01063 *)p)->f28=8;
            func_020061E4(0x551);
        }
    }
    return 2;
}









int func_021FD4D4(unsigned char *p)
{
    func_0204B3DC((struct Obj *)((struct Obj08187 *)p)->fD34, 0);
    if (((struct Obj08187 *)p)->f20 != 15) {
        if (((struct Obj08187 *)p)->f20 == 6)
            func_0202208C(0, 0, 0, 0, 6, 1, 0x48);
        else
            func_0202208C((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    ((struct Obj08187 *)p)->f28 = 0;
    return 3;
}










/*
 * Build with the fixed 0x12/0x12e/3/4/1 argument pair and latch state 5.
 */
int func_021FD528(u8 *p)
{
    func_021F4BF8(p, 0x12, 0x12e, 3, 4, 1);
    ((struct Obj02489 *)p)->f28 = 5;
    return 2;
}









int func_021FD550(unsigned char *p)
{
    unsigned r = func_021F4D14((char *)p);
    if (r == 1) {
        func_021F4CE4((char *)p);
        *(int *)&((struct Obj00045 *)p)->f28 = 2;
        func_021F4EC0(p, 5, 6);
        func_021FD760(((struct Obj00045 *)p)->fB6C, (Pane *)(p + 0xdc8), 0x53, p + 0xfa0, 0x440);
        func_021FD760(((struct Obj00045 *)p)->fB6C, (Pane *)(p + 0xdb4), 0x57, p + 0xfa0, 0x3c40);
        func_021FD5F0((Work_021FD5F0 *)p);
    } else if (r == 2) {
        func_021F4CE4((char *)p);
        func_0201F7A8(((struct Obj00045 *)p)->fD40, 0);
        *(int *)&((struct Obj00045 *)p)->f28 = 1;
        func_021FD790(((struct Obj00045 *)p)->fB6C, (Pane *)(p + 0xd50), 0x5e, p + 0xfa0);
        func_021FD790(((struct Obj00045 *)p)->fB6C, (Pane *)(p + 0xd54), 0x73, p + 0xfa0);
    }
    return 2;
}








void func_021FD5F0(Work_021FD5F0 *p)
{
    func_0204989C(0x60, 0x1E, 1, 0, 0x800, 1, 0x48);
    func_021FD85C((Pane2 *)p->pane2, p->name0, p->name1, p->fFA0);
    func_021FD7DC((Pane *)(&p->pane), p->bank, p->names, (Rec_vCFD8 *)(p->arr[p->cur].rec), p->fFA0);
}







/*
 * Reset the sub-state and report 2.
 */
int func_021FD65C(u8 *p)
{
    func_021FD5F0((Work_021FD5F0 *)p);
    ((struct Obj02860 *)p)->f28 = 1;
    return 2;
}






int func_021FD66C(char *p) { (((struct Obj08188 *)p)->fD3C)++; if(func_020221A4()) {((struct Obj08188 *)p)->fD3C=0; ((struct Obj08188 *)p)->f28=1; func_0204B3DC(*(struct Obj * *)&((struct Obj08188 *)p)->fD34,1);} return 2; }






/*
 * volatile: 021FD6B0 reads hardware register 04000304.
 */
int func_021FD698(unsigned char *p)
{
    --((struct Obj10587 *)p)->fD3C;
    if (func_020221A4()) {
        *(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000);
        ((struct Obj10587 *)p)->f28 = 2;
        func_021F4EC0(p, 4, 15);
        ((struct Obj10587 *)p)->fD3C = 16;
    }
    return 2;
}







int func_021FD6D8(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        ((struct Obj12211 *)p)->f28 = ((struct Obj12211 *)p)->f2C;
    }
    return 2;
}






/*
 * Tear the object down: unhook the two sub-objects, release the +0xd40 resource, wire the 0/1/2 quad, then drain the four engine hooks.
 */
void func_021FD6F4(u8 *p, u32 k, u32 a2, u32 a3, u32 a4)
{
    u32 v;

    func_02045CAC((struct MsgBank *)(((struct Obj01063 *)p)->fB6C), k, (void *)(*(u32 *)(p + 0xb6c + 0x1c)));
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01063 *)p)->fD40)), 0xf);
    func_0201F73C((void *)(((struct Obj01063 *)p)->fD40), 0, 1, 0x2);
    func_02202858((void *)(((struct Obj01063 *)p)->fD40), 0, (void *)(*(u32 *)(p + 0xb6c + 0x1c)), 0, 0, p + 0xfa0);
    v = ((struct Obj01063 *)p)->fD40;
    func_02045334((struct Descriptor *)v);
    func_02045374((struct Cfg *)v);
    func_020409B4(func_02045730((struct Descriptor *)v));
}






void func_021FD760(void *bank, Pane *pane, u32 index, void *g, u16 color)
{
    void *str = func_02045EC0(bank, index);

    func_021F91A0(pane->win, (u32)str, 0, 2, 0, color, (u32)g);
    func_02045808(str);
}






void func_021FD790(void *bank, Pane *pane, u32 index, void *g)
{
    void *str = func_02045EC0(bank, index);
    void *win;

    func_021F91DC(pane->win, (u32)str, 0, 0, 1, 0x3C40, (u32)g);
    win = pane->win;
    func_02045334(win);
    func_02045374(win);
    func_020409B4(func_02045730(win));
    func_02045808(str);
}






void func_021FD7DC(Pane *pane, void *bank, void *names, Rec_vCFD8 *rec, void *g)
{
    func_02043B5C(func_02045770(pane->win), 0);
    func_021F7FD4(pane->win, names, rec->name, 0, 0x440, g);
    func_021F8104(pane->win, bank, rec->mode, 0, 0x49, 0, 0x440, g);
    func_021F8178(pane->win, bank, func_021F886C(rec->key, rec->val, 0), 0, 0x68, 0, 0x440, 0, (u32)g);
}





void func_021FD85C(Pane2 *pane, void *s1, void *s2, void *g)
{
    func_02043B5C(func_02045770(pane->win0), 0);
    func_02043B5C(func_02045770(pane->win1), 0);
    if (s1 != 0) {
        func_021F91A0(pane->win0, (u32)s1, 0, 0, 0, 0x440, (u32)g);
    }
    if (s2 != 0) {
        func_021F91A0(pane->win1, (u32)s2, 0, 0, 0, 0x440, (u32)g);
    }
}





void func_021FD8BC(Work_vCFD8 *p)
{
    func_02040618(0, 3, p->scroll);
    func_02040618(1, 3, p->scroll);
    func_02040618(2, 3, p->scroll);
    func_02040618(3, 3, p->scroll);
    func_02040618(4, 3, -p->scroll);
    func_02040618(5, 3, -32 - p->scroll);
    func_02040618(6, 3, -p->scroll);
    func_02040618(7, 3, -p->scroll);
}






int func_021FD924(Work_vD924 *p)
{
    Init init;

    func_021FE118((u8 *)p);
    func_021FDBCC();
    func_021FDD00(p);
    func_021FDF2C((Menu_vD924 *)p);
    func_021FDDA8((Obj_vD924 *)p);
    func_021FFFE8((u8 *)p, 0, 0);
    func_02200B34((u8 *)p);
    func_02200BAC((u8 *)p, 4);
    p->f12E4 = 0;
    init.w00 = p->fD50;
    init.w04 = p->fDD4;
    init.obj = p->mark;
    init.w0c = p->btn[0];
    init.w10 = p->btn[1];
    init.w14 = p->cursor;
    init.bank = p->bank;
    init.names = p->names;
    init.w20 = p->msg;
    init.w24 = p->ctx->f10;
    init.w28 = p->aux->f14;
    p->menu = func_021F9890(&init, 2, 1);
    func_021FF384(p->win, p->win2, p->bank, p->fFA0);
    func_021FF474(p->wDB0, p->bank, p->fE1A, p->fFA0);
    func_021F7F9C(p->win[1], p->names, p->rec.name, 0, 0, 0x3C40, p->fFA0);
    func_021F8098(p->win[3], p->bank, p->rec.mode, 1, 0, 0, 0x3C40, p->fFA0);
    func_021F8154(p->wDA4, p->bank, func_021F886C(p->rec.key, p->rec.val, 1), 0, 0, 0x3C40, 1, p->fFA0);
    func_021F8010(p->win2[1], p->msg, p->bank, p->fF84, 0, 0, 0x3C40, p->fFA0);
    p->vblank = func_021FF50C;
    if (p->kind == 0xd) {
        func_0202208C((void *)3, 1, 1, 0, 6, 1, 0x48);
    }
    p->f28 = 0;
    return 1;
}





extern int (*const d_02203D80[])(void *);





int func_021FDAE4(unsigned char *p)
{
    int result;
    int i;
    int x, y;
    result = d_02203D80[*(int *)(p + 0x28)](p);
    for (i = 0; i < 8; ++i)
        func_021F4EA0(*(u32 *)(p + i * 4 + 0xd0c), *(short *)(p + i * 4 + 0xec4), *(short *)(p + i * 4 + 0xec6) + ((struct Obj00018 *)p)->fD3C);
    x = func_021FE9B0(p);
    y = func_021FE9B0(p);
    func_021F4FF4(((struct Obj00018 *)p)->fBF4, d_02203D46[x].x, d_02203D46[y].y - ((struct Obj00018 *)p)->fD3C);
    func_021F4EA0(((struct Obj00018 *)p)->fD38, 55, ((struct Obj00018 *)p)->fD3C + 168);
    return result;
}





int func_021FDB74(unsigned char *p)
{
    ((struct Obj00287 *)p)->fEC0 = 0;
    func_021F99D0(((struct Obj00287 *)p)->fDE4);
    func_021FDEFC((char *)p);
    func_021FE178((char *)p);
    func_021FE0BC(p);
    func_021FDCE4();
    if (*(int *)&((struct Obj00287 *)p)->f14 == 1)
        *(int *)&((struct Obj00287 *)p)->f12E4 = 1;
    func_022000E4((char *)p);
    func_0204B3DC((struct Obj *)((struct Obj *)*(u32 *)&((struct Obj00287 *)p)->fD38), 0);
    func_021F4EC8(p);
    return 0;
}






/*
 * Four-layer bring-up, every layer 020414EC'd, with the tilemap clears for
 * layers 2, 0 and 3 in that order.
 */
void func_021FDBCC(void)
{
    struct DispConfig c = g_022037F4;
    u32 v = func_02043668();

    func_0203FC28(&c);
    func_020435F4(v);
    {
        struct BgTemplate t = g_02203844;
        func_0203FCA0(0, &t, 0);
    }
    func_020414EC(0);
    func_02040588(0, 1);
    {
        struct BgTemplate t = g_02203864;
        func_0203FCA0(1, &t, 0);
    }
    func_020414EC(1);
    func_02040588(1, 1);
    {
        struct BgTemplate t = g_02203804;
        func_0203FCA0(2, &t, 0);
    }
    func_020414EC(2);
    func_02040588(2, 1);
    {
        struct BgTemplate t = g_02203824;
        func_0203FCA0(3, &t, 0);
    }
    func_020414EC(3);
    func_02040588(3, 1);
    func_02040B94(2, 0x20, 0, 0x48);
    func_02040B94(0, 0x20, 0, 0x48);
    func_02040B94(3, 0x20, 0, 0x48);
}






/*
 * Poke the channel-selection helper with 2, 1, 0, 3 in turn.
 */
void func_021FDCE4(void)
{
    sub_020403F4(2);
    sub_020403F4(1);
    sub_020403F4(0);
    sub_020403F4(3);
}






/*
 * The parameterless member: handle open, the B68 and B40 window calls, two
 * F5BC text calls, three 49658/498F4 draws and the second B40 pair, then
 * the 49238 release.  Contents 166 of 168 bytes (pool pad).
 */
void func_021FDD00(void *p)
{
    void *h = func_020490F4(0x60, 0x48);

    func_02049B68(h, 2, 0, 0, 0x60, 0x48);
    func_02049B40(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    func_0201F5BC(0, 1, 0xe, 0, 0x48);
    func_0201F5BC(0, 0x1f, 0xb, 0, 0x48);
    func_02049658(h, 0xb, 1, 0, 0, 1, 0x48);
    func_020498F4(h, 0x17, 1, 0, 0, 1, 0x48);
    func_02049658(h, 0xc, 2, 0, 0, 1, 0x48);
    func_02049B40(0x17, 5, 4, 0x20, 0x20, 0x48);
    func_02049238(h);
}






void func_021FDDA8(Obj_vD924 *p)
{
    ObjPos_vD924 pos;

    func_02082BCC(&pos, 0, sizeof(pos));
    pos.x = tbl_02203D38.cur[0].x;
    pos.y = tbl_02203D38.cur[0].y;
    p->cursor = func_0204B294(p->res, (u32)p->set2, (u32)p->set[1], (u32)p->set3, &pos, 0, 0x48);
    func_0204B92C(p->cursor, 1);
    func_0204B878(p->cursor, tbl_02203D38.cur[0].anim);
    func_0204B84C(p->cursor, 1);
    if (func_020355C4() == 1) {
        func_0204B3DC(p->cursor, 0);
    } else {
        func_0204B3DC(p->cursor, 1);
    }
    pos.x = 0xA0;
    pos.y = 0x20;
    p->mark = func_0204B294(p->res, (u32)p->set2, (u32)p->set[1], (u32)p->set3, &pos, 0, 0x48);
    func_0204B878(p->mark, 4);
    func_0204B3DC(p->mark, 0);
    pos.x = 0xE4;
    pos.y = 0x75;
    p->btn[0] = func_0204B294(p->res, (u32)p->set[0], (u32)p->set[1], (u32)p->set[2], &pos, 0, 0x48);
    func_0204B878(p->btn[0], 0x26);
    func_0204B3DC(p->btn[0], 0);
    pos.x = 0x8C;
    p->btn[1] = func_0204B294(p->res, (u32)p->set[0], (u32)p->set[1], (u32)p->set[2], &pos, 0, 0x48);
    func_0204B878(p->btn[1], 0x27);
    func_0204B3DC(p->btn[1], 0);
    func_0203D34C(0, 0x48);
}





void func_021FDEFC(char *p) {func_0204B3B4((struct Obj *)(*(struct Obj * *)&((struct Obj08189 *)p)->fBF4));func_0204B3B4((struct Obj *)(*(struct Obj * *)&((struct Obj08189 *)p)->fBF8));func_0204B3B4((struct Obj *)(*(struct Obj * *)&((struct Obj08189 *)p)->fD2C));func_0204B3B4((struct Obj *)(*(struct Obj * *)&((struct Obj08189 *)p)->fD30));}






void func_021FDF2C(Menu_vD924 *p)
{
    int i;
    u32 v;

    p->frame = func_020450F0(0, (u8)2, (u8)0x15, (u8)0x1b, 2, 0xd, (u16)1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->frame)), 0);
    v = p->frame;
    func_02045334((struct Descriptor *)v);
    func_02045374((struct Cfg *)v);
    func_020409B4(func_02045730((struct Descriptor *)v));
    func_02040C14(3, 0, 1, 0);
    for (i = 0; i < 6; i++) {
        p->item[i] = func_020450F0(3, (u8)tbl_022037BC[i].x, (u8)tbl_022037BC[i].y, (u8)0xb, 2, 0xd, (u16)0);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->item[i])), 0);
        v = p->item[i];
        func_02045334((struct Descriptor *)v);
        func_02045374((struct Cfg *)v);
        func_020409B4(func_02045730((struct Descriptor *)v));
    }
    for (i = 0; i < 2; i++) {
        p->tab[i] = func_020450F0(3, (u8)tbl_022037A8[i].x, (u8)tbl_022037A8[i].y, (u8)0x1c, 2, 0xd, (u16)0);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->tab[i])), 0);
        v = p->tab[i];
        func_02045334((struct Descriptor *)v);
        func_02045374((struct Cfg *)v);
        func_020409B4(func_02045730((struct Descriptor *)v));
    }
    for (i = 0; i < 3; i++) {
        p->page[i] = func_020450F0(3, (u8)tbl_022037B0[i].x, (u8)tbl_022037B0[i].y, (u8)0xa, 2, 0xd, (u16)0);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->page[i])), 0);
        v = p->page[i];
        func_02045334((struct Descriptor *)v);
        func_02045374((struct Cfg *)v);
        func_020409B4(func_02045730((struct Descriptor *)v));
    }
}





void func_021FE0BC(unsigned char *p)
{
    int i;
    func_02202940((struct Obj *)((struct Obj *)(p + 0xfa0)));
    func_020452E8(((struct Obj14174 *)p)->fDE0);
    func_020452E8(((struct Obj14174 *)p)->fD40);
    for (i = 0; i < 9; ++i)
        func_020452E8(*(void **)(p + i * 4 + 0xd90));
    for (i = 0; i < 2; ++i)
        func_020452E8(*(void **)(p + i * 4 + 0xdd8));
    func_02040DA8(3, 1, 0);
}






void func_021FE118(u8 *p)
{
    ((struct Obj05416 *)p)->fB88 = func_020457B0(0xb4, 0x48);
    ((struct Obj05416 *)p)->fB8C = func_02045EC0(((struct Obj05416 *)p)->fB6C, 0x30);
    ((struct Obj05416 *)p)->fE00 = func_02030734(0x48, 0x30, 0, (const char *)g_02203E18, 0x351);
    func_02082AC0(0, ((struct Obj05416 *)p)->fE00, 0x30);
    *(u8 * *)&((struct Obj23412 *)(*(u8 * *)&((struct Obj05416 *)p)->fE00))->f14 = func_021F84EC(0x48);
    func_021F8990(p + 0xeec);
}




void func_021FE178(char *p) {func_020307B0(((struct Obj23413 *)(*(char * *)&((struct Obj08190 *)p)->fE00))->f14);func_020307B0(((struct Obj08190 *)p)->fE00);func_02045808(*(struct U16Vec * *)&((struct Obj08190 *)p)->fB88);func_02045808(*(struct U16Vec * *)&((struct Obj08190 *)p)->fB8C);}




int func_021FE1A4(unsigned char *p)
{
    if (func_020355C4() == 1)
        func_0204B3DC((struct Obj *)((struct Obj *)((struct Obj00018 *)p)->fBF4), 0);
    else
        func_0204B3DC((struct Obj *)((struct Obj *)((struct Obj00018 *)p)->fBF4), 1);
    if (((struct Obj00018 *)p)->f20 == 15) {
        if (((struct Obj00018 *)p)->fD0 != 0)
            func_021FF318(p, 38, 0, 0, 0xf0f);
        else
            func_021FF318(p, 8, 1, 0, 0xf0f);
        if (func_0207D55C((u16 *)0x0400006c) == -16) {
            func_0202208C(0, 1, 1, 0, 16, 1, 0x48);
            *(int *)&((struct Obj00018 *)p)->f28 = 33;
        } else {
            *(int *)&((struct Obj00018 *)p)->f28 = 1;
        }
    } else {
        func_021FF318(p, 8, 1, 0, 0xf0f);
        func_021F4E98(p, 23, 1);
    }
    func_0204B3DC((struct Obj *)((struct Obj *)((struct Obj00018 *)p)->fD38), 1);
    return 2;
}





int func_021FE254(void)
{
    return func_02035C08(g_022037D4);
}




void func_021FE264(u8 *p, int mode)
{
    u32 h,v;
    switch(mode) {
    case 0: ((struct Obj00018 *)p)->f28=4; break;
    case 1:
        if(((struct Obj00018 *)p)->fB56!=0) {
            h=(u32)func_0201ADE4((u16)((struct Obj00018 *)p)->fB56,0,0x48);
            v=func_0201AE1C((const struct Personal *)h,0x14);
            func_0201AE14((void *)h);
            ((struct Obj23414 *)(*(u8 * *)&((struct Obj00018 *)p)->fE00))->f20=v;
            if(func_021F7B9C(p+0xB56,((struct Obj23415 *)(*(u8 * *)&((struct Obj00018 *)p)->fE00))->f20)) break;
        }
        ((struct Obj00018 *)p)->f28=7;
        break;
    case 2: ((struct Obj00018 *)p)->f28=10; break;
    case 3: ((struct Obj00018 *)p)->f28=13; break;
    case 4:
        if(*(u32 *)&((struct Obj00018 *)p)->fD0) {
            ((struct Obj00018 *)p)->f28=32;
            func_0202208C(0,0,0,0,16,1,0x48);
        }
        break;
    case 5: ((struct Obj00018 *)p)->f28=16; break;
    case 6:
        func_021FF318(p,15,1,0,0xF0F);
        func_021F4E98(p,23,26);
        break;
    }
}






/*
 * Menu input handler. A touch on an entry (func_021FE254) selects it and
 * acts at once; otherwise the d-pad moves the cursor (func_021FE9DC) and A
 * acts on the current entry, B jumps to the last entry of page 1. Entry 1
 * hands the +0xB56 record to func_021F7B9C, entry 5 compares the two
 * records, entry 4 depends on the +0xD0 word; every path picks the next
 * state (+0x28) and a sound. Always returns 2.
 */
int func_021FE338(Work_vE338 *p)
{
    int sel = func_021FE254();

    if (sel != -1) {
        func_020355D8(1);
        func_021FEAE0(p, sel);
        sel = func_021FE9B0(p);
        switch (sel) {
        case 1:
            if (p->rec[0].a != 0) {
                u32 h = (u32)func_0201ADE4((u16)p->rec[0].a, 0, 0x48);
                u32 v = func_0201AE1C((const struct Personal *)h, 0x14);
                func_0201AE14((void *)h);
                p->st->f20 = v;
                if (func_021F7B9C((u8 *)(&p->rec[0]), p->st->f20) != 0) {
                    func_0204B3DC((struct Obj *)p->cursor, 1);
                    func_0204B878((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
                    func_020061E4(0x557);
                    return 2;
                }
            }
            func_0204B3DC((struct Obj *)p->cursor, 1);
            func_020061E4(0x54C);
            func_0204B878((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
            p->next = 0x23;
            break;
        case 5:
            if (p->rec[0].a == 0 || func_021FF4D0(&p->rec[0], &p->rec[1], p->fF84, p->fB64) != 0) {
                func_020061E4(0x557);
            } else {
                func_020061E4(0x54C);
            }
            func_0204B3DC((struct Obj *)p->cursor, 1);
            func_0204B878((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
            p->next = 0x23;
            break;
        case 4:
            if (p->fD0 != 0) {
                func_0204B3DC((struct Obj *)p->cursor, 1);
                func_020061E4(0x54C);
                func_0204B878((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
                p->next = 0x23;
            } else {
                func_0204B3DC((struct Obj *)p->cursor, 1);
                func_0204B878((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
                func_020061E4(0x557);
                p->next = 0x25;
            }
            break;
        default:
            func_0204B3DC((struct Obj *)p->cursor, 1);
            if (sel == 6) {
                func_020061E4(0x551);
            } else {
                func_020061E4(0x54C);
            }
            func_0204B878((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
            p->next = 0x23;
            break;
        }
    } else if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)p->cursor, 1);
        func_020355D8(0);
        func_020061E4(0x548);
        return 2;
    } else {
        func_021FE9DC(p);
        if (func_020362DC() & 1) {
            sel = func_021FE9B0(p);
            switch (sel) {
            case 1:
                if (p->rec[0].a != 0) {
                    u32 h = (u32)func_0201ADE4((u16)p->rec[0].a, 0, 0x48);
                    u32 v = func_0201AE1C((const struct Personal *)h, 0x14);
                    func_0201AE14((void *)h);
                    p->st->f20 = v;
                    if (func_021F7B9C((u8 *)(&p->rec[0]), p->st->f20) != 0) {
                        func_0204B3DC((struct Obj *)p->cursor, 1);
                        func_0204B878((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
                        func_020061E4(0x557);
                        return 2;
                    }
                }
                func_0204B3DC((struct Obj *)p->cursor, 1);
                func_020061E4(0x54C);
                func_0204B878((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
                p->next = 0x23;
                break;
            case 5:
                if (p->rec[0].a == 0 || func_021FF4D0(&p->rec[0], &p->rec[1], p->fF84, p->fB64) != 0) {
                    func_020061E4(0x557);
                } else {
                    func_020061E4(0x54C);
                }
                func_0204B878((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
                p->next = 0x23;
                break;
            case 4:
                if (p->fD0 != 0) {
                    func_020061E4(0x54C);
                    func_0204B878((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
                    p->next = 0x23;
                } else {
                    func_0204B3DC((struct Obj *)p->cursor, 1);
                    func_0204B878((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
                    func_020061E4(0x557);
                    p->next = 0x25;
                }
                break;
            default:
                if (sel == 6) {
                    func_020061E4(0x551);
                } else {
                    func_020061E4(0x54C);
                }
                func_0204B878((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
                p->next = 0x23;
                break;
            }
        } else if (func_020362DC() & 2) {
            p->st->page = 1;
            p->st->row1 = 2;
            func_0204B878((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
            p->next = 0x24;
            func_020061E4(0x551);
        }
    }
    return 2;
}





int func_021FE60C(unsigned char *p)
{
    if (((struct Obj06518 *)p)->fB56 == 0) {
        func_021FF318(p, 12, 1, 0, 0xf0f);
        func_021F4E98(p, 23, 1);
    } else {
        if (func_021FF4D0((Rec_vE338 *)(p + 0xb56), (Rec_vE338 *)(p + 0xb5c), ((struct Obj06518 *)p)->fF84, ((struct Obj06518 *)p)->fB64)) {
            func_021FF318(p, 39, 1, 0, 0xf0f);
            func_021F4E98(p, 23, 1);
        } else {
            func_020061E4(0x63f);
            ((struct Obj06518 *)p)->f12E8 = 0x76;
            func_021FF318(p, 13, 1, 0, 0xf0f);
            func_021F4E98(p, 23, 17);
            if (((struct Obj06518 *)p)->fD0 > 0)
                func_021FFBC8(p);
        }
    }
    return 2;
}





int func_021FE6A0(u8 *p)
{
    Request q;
    if (((struct Obj01161 *)p)->fF84 == 0) {
        func_021C8B18(p + 0xb56, 7, p + 0x20c);
    } else {
        func_02082BCC(&q, 0, 8);
        q.id = *(short *)&((struct Obj01161 *)p)->fB56;
        q.a = *(s8 *)&((struct Obj01161 *)p)->fB58;
        q.b = *(s8 *)(p + 0xb59);
        q.c = *(s8 *)&((struct Obj01161 *)p)->fB5A;
        q.d = *(s8 *)(p + 0xb5b);
        q.mode = 7;
        q.flag = ((struct Obj01161 *)p)->fF84;
        func_021C8BC4(&q, (unsigned int)(p + 0x20c));
    }
    ((struct Obj01161 *)p)->fB5C = ((struct Obj01161 *)p)->fB56;
    ((struct Obj01161 *)p)->fB5E = ((struct Obj01161 *)p)->fB58;
    ((struct Obj01161 *)p)->fB60 = ((struct Obj01161 *)p)->fB5A;
    ((struct Obj01161 *)p)->fB64 = *(u32 *)&((struct Obj01161 *)p)->fF84;
    ((struct Obj01161 *)p)->fF8C = 0;
    ((struct Obj01161 *)p)->f28 = 18;
    ((struct Obj01161 *)p)->fE1A = 0;
    return 2;
}






/*
 * 23-slot switch on the 0x021C86A8 index (case value = index + 15, so the
 * bound is 22): the +0xd0 archive with state 0x13 for indexes 15..22, the
 * state-0x1e group with the four redraw calls for 1 and 13, the shared redraw
 * for 2 and the state-0x16 pair for 0 and 3; 4..12 and 14 are table holes.
 * The counter in the else arm compares against 0x1c20, not 0xe10.
 * Concrete bytes are identical to the image; the only wildcards are the two
 * BLX sites to 0x021C866C and 0x021C86A8, which carry no func_ label in any
 * overlay listing (match.py's `label` class needs exactly one listing to
 * carry the label, so no region hint can witness them).  One-line fix:
 * trace 0x021C866C / 0x021C86A8 in layout/function_starts.txt and this
 * promotes automatically.
 *
 * UNBLOCKED: func_021C866C (0x021C866C) and func_021C86A8
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int func_021FE744(u8 *p)
{
    s32 n;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        ((struct Obj04907 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
            ((struct Obj04907 *)p)->fD0 = n;
            ((struct Obj04907 *)p)->f28 = 0x13;
            break;
        case 1:
        case 13:
            func_02006210();
            ((struct Obj04907 *)p)->f28 = 0x1e;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            break;
        case 2:
            func_02006210();
            func_021F513C(p);
            break;
        case 0:
        case 3:
            func_02006210();
            ((struct Obj04907 *)p)->f28 = 0x16;
            break;
        }
    } else {
        if (++((struct Obj04907 *)p)->fF8C == 0x1c20) {
            func_02006210();
            func_021F513C(p);
        }
    }
    return 2;
}





int func_021FE7F0(char *p)
{
    if (((struct Obj03832 *)p)->f12E8 == 0) {
        func_02006210();
        func_021FFB20((u8 *)p, ((struct Obj03832 *)p)->fD0, 1);
        if (((struct Obj03832 *)p)->fD0 == 0)
            func_021FF474(((struct Obj03832 *)p)->fDB0, ((struct Obj03832 *)p)->fB6C, 0, p + 0xfa0);
        else
            func_021FF474(((struct Obj03832 *)p)->fDB0, ((struct Obj03832 *)p)->fB6C, 1, p + 0xfa0);
        ((struct Obj03832 *)p)->f28 = 20;
    }
    return 2;
}




int func_021FE84C(char *p)
{
    if (((struct Obj14175 *)p)->fD0 == 0) {
        func_021FF318((unsigned char *)p, 14, 1, 0, 0xf0f);
        func_021F4E98((u8 *)p, 23, 1);
        func_020061E4(0x557);
    } else {
        func_021FF318((unsigned char *)p, 36, 1, 0, 0xf0f);
        func_021F4E98((u8 *)p, 23, 21);
        ((struct Obj14175 *)p)->fDFC = 0;
    }
    return 2;
}




int func_021FE8A8(char *p)
{
    if (++((struct Obj14176 *)p)->fDFC > 45) {
        func_021FF318((unsigned char *)p, 38, 1, 0, 0xf0f);
        func_021F4E98((u8 *)p, 23, 1);
        ((struct Obj14176 *)p)->fE1A = 1;
    }
    return 2;
}


int func_021FE8E8(char *p)
{
    ((struct Obj08191 *)p)->fB5C = 0;
    func_021FF318((unsigned char *)p, 44, 1, 0, 0xf0f);
    func_021F4E98((u8 *)p, 23, 1);
    func_020061E4(0x557);
    ((struct Obj08191 *)p)->fD0 = 0;
    func_021FF474(((struct Obj08191 *)p)->fDB0, ((struct Obj08191 *)p)->fB6C, 0, p + 0xfa0);
    return 2;
}
