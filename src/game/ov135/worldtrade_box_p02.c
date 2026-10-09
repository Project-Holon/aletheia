/*
 * file:     worldtrade_box_p02.c
 * unit:     yes
 * function: func_021F4D50, func_021F4E30, func_021F4E64, func_021F4E98, func_021F4EA0, func_021F4EB4, func_021F4EC0, func_021F4EC8, func_021F4ED4, func_021F4EDC, func_021F4EFC, func_021F4F84, func_021F4F90, func_021F4FA4, func_021F4FC4, func_021F4FF4, func_021F5008, func_021F5034, func_021F5060, func_021F5074, func_021F50EC, func_021F513C, func_021F5154, func_021F51F0, func_021F5204, func_021F5250, func_021F5358, func_021F5374, func_021F5420, func_021F577C, func_021F57EC, func_021F5940, func_021F5980, func_021F59E8, func_021F5A18, func_021F5A7C, func_021F5B8C, func_021F5CA4, func_021F5CD4, func_021F5CFC
 * address:  0x021F4D50
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
 *   func_02027F60 0x02027F60 thumb
 *   func_02027778 0x02027778 thumb
 *   func_02034714 0x02034714 arm
 *   func_02082BCC 0x02082BCC arm
 *   str_02203B08 0x02203B08 data
 *   data_02202C2C 0x02202C2C data a4
 *   func_0204B404  0x0204B404  arm
 *   func_0205CCD8  0x0205CCD8  arm
 *   sub_02012FFC  0x02012FFC  thumb  arm9
 *   func_021F4894  0x021F4894  thumb  ov135
 *   func_021F49F8  0x021F49F8  thumb  ov135
 *   func_021F4BCC  0x021F4BCC  thumb  ov135
 *   g_02202BFC  0x02202BFC  data  ov135
 *   func_021FFCD4  0x021FFCD4  thumb
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_020056BC  0x020056BC  thumb
 *   func_0202F038  0x0202F038  thumb
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_021F49A8  0x021F49A8  thumb
 *   func_021F4864  0x021F4864  thumb
 *   tbl_02202BB8  0x02202BB8  data
 *   func_02030EAC  0x02030EAC  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_0200F7C0   0x0200F7C0  thumb
 *   func_021FFFE8 0x021FFFE8 thumb ov135
 *   func_021FFD44 0x021FFD44 thumb ov135
 *   func_0207D55C 0x0207D55C arm
 *   func_021F68A4 0x021F68A4 thumb ov135
 *   func_021F9254 0x021F9254 thumb ov135
 *   g_02203B0C  0x02203B0C  data  ov135
 *   func_021FFD74 0x021FFD74 thumb ov135
 *   func_022000E4 0x022000E4 thumb ov135
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02043668  0x02043668  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_020435F4  0x020435F4  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040588  0x02040588  arm
 *   func_02040B94  0x02040B94  arm
 *   g_02202C94  0x02202C94  data  ov135
 *   g_02202CE4  0x02202CE4  data  ov135
 *   g_02202D04  0x02202D04  data  ov135
 *   g_02202CA4  0x02202CA4  data  ov135
 *   g_02202CC4  0x02202CC4  data  ov135
 *   sub_020403F4  0x020403F4  arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_02200AB4 0x02200AB4 thumb ov135
 *   func_02200B34 0x02200B34 thumb ov135
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_020355C4  0x020355C4  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B974  0x0204B974  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   tbl_02202D24   0x02202D24  data  a2
 *   tbl_02202C50   0x02202C50  data  a2
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_021F91A0  0x021F91A0  thumb
 *   func_02200BAC  0x02200BAC  thumb
 *   func_02202940 0x02202940 thumb ov135
 *   func_020452E8 0x020452E8 arm
 *   func_021F6E08 0x021F6E08 thumb ov135
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02030734 0x02030734 arm
 *   str_02203B54 0x02203B54 data a1
 *   func_020307B0 0x020307B0 arm
 *   func_02045808 0x02045808 arm
 *   func_021F663C 0x021F663C thumb ov135
 *   func_021F6C48  0x021F6C48  thumb
 *   func_021F6BA4  0x021F6BA4  thumb
 *   func_021F6B40  0x021F6B40  thumb
 *   func_022025E4  0x022025E4  thumb
 *   func_021F6CDC  0x021F6CDC  thumb
 *   tbl_02202E24  0x02202E24  data  a1
 *   func_021F5F9C  0x021F5F9C  thumb
 *   func_021F5F60  0x021F5F60  thumb
 *   func_021F5E44  0x021F5E44  thumb
 */
#include "../../matched/include/Obj00448.h"
#include "../../matched/include/Obj00045.h"
#include "../../matched/include/Obj00018.h"
#include "../../matched/include/Obj00287.h"
#include "../../matched/include/Obj00996.h"
#include "../../matched/include/Obj12193.h"
#include "../../matched/include/Obj02863.h"
#include "../../matched/include/Obj12194.h"
#include "../../matched/include/Obj05413.h"
#include "../../matched/include/Obj18539.h"
#include "../../matched/include/Obj10575.h"
#include "../../matched/include/Obj14160.h"
#include "../../matched/include/Obj14161.h"
#include "../../matched/include/Obj04526.h"
#include "../../matched/include/Obj12195.h"

struct R;
struct TaskMenu;
struct TaskMenuTmpl;
struct TaskMenuState;
struct Obj;
struct Vec2;
struct DispVram;
struct Bank;
struct Cfg;
struct Descriptor;
struct Node;
struct Ctx;
struct Actor;
struct CharBuf;
struct MsgBank;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 a,b,c; } Item;

typedef struct { Item item[3]; } Items;

typedef struct { u32 heap; u8 count,pad[3]; Item *items; u32 mode; u8 a,b,c,d; } Menu;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef volatile u16 vu16_021F5074;

struct DispConfig {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

typedef struct {
    u8 pad0[0xF90];
    void *vblank;
} Work_021F4D50;

typedef volatile unsigned short vu16_021F50EC;

typedef volatile unsigned int vu32;

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
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

typedef struct {
    u16 x;
    u16 y;
} Pos;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u8 pad10[0x18];
    u32 f28;
    u32 f2C;
    u32 f30;
    u32 f34;
    u32 f38;
    u32 f3C;
    u32 arrA[30];
    u32 arrB[30];
} Sub;

typedef struct {
    u8 pad0[0xC6];
    u16 idx;
    u8 padC8[0xBC0 - 0xC8];
    Sub sub;
    u32 arrC[6];
    u8 padD08[0xD2C - 0xD08];
    u32 arrD[2];
    u32 fD34;
    u32 fD38;
} Work_021F5420;

typedef struct {
    u8 pad0[0x20];
    int mode;
    u8 pad24[0xB84 - 0x24];
    void *strs;
    u8 padB88[0xD40 - 0xB88];
    void *win1;
    u8 padD44[0xD4C - 0xD44];
    void *win0;
    u8 padD50[0xD54 - 0xD50];
    void *win3;
    u8 padD58[0xDD0 - 0xD58];
    void *win2;
    u8 padDD4[0xFA0 - 0xDD4];
    u8 g[4];
} Work_021F57EC;

typedef struct {
    u8 pad0[8];
    void *party;
    void *save;
} Ctx;

typedef struct {
    Ctx *ctx;
    u8 pad4[0x28 - 4];
    u32 state;
    u8 pad2C[0xC4 - 0x2C];
    u16 box;
    u16 slot;
    u8 padC8[0xB68 - 0xC8];
    void *msg;
    u8 padB6C[0xBFC - 0xB6C];
    u32 cursor;
} Work_021F5A7C;

typedef struct {
    u8 pad0[0xF0];
    u8 want[0x128 - 0xF0];
} Entry;

typedef struct {
    Ctx *ctx;
    u8 pad4[0x28 - 4];
    u32 state;
    u8 pad2C[0xC4 - 0x2C];
    u16 box;
    u16 slot;
    u8 padC8[0xD4 - 0xC8];
    int sel;
    u8 padD8[0x20C - 0xD8];
    Entry list[1];
    u8 pad334[0xB68 - 0x334];
    void *msg;
    u8 padB6C[0xBFC - 0xB6C];
    u32 cursor;
} Work_021F5B8C;

typedef struct {
    u8 pad0[0xBF4];
    u32 cursor;
} Work_021F5CA4;

typedef struct {
    u8 pad0[0x20];
    int mode;
    u8 pad24[0x28 - 0x24];
    u32 state;
    u8 pad2C[0xC4 - 0x2C];
    u16 box;
    u16 slot;
    int boxes;
    u8 padCC[0xBF4 - 0xCC];
    u32 cursor;
    u8 padBF8[0xBFC - 0xBF8];
    u32 marker;
    u8 padC00[0xD2C - 0xC00];
    u32 arrows[2];
} Work_021F5CD4;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02082BCC(void *, u32, u32);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_02027974(void *m);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_02027858(struct TaskMenu *m);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern int func_0205CCD8(void);
extern signed char sub_02012FFC(void);
extern void func_021F4894(const struct DispVram *a0);
extern void func_021F49F8(u8 *p, u32 v);
extern void func_021F4BCC(u8 *p);
extern void func_021FFCD4(u8 *p);
extern void func_0204ADA4(u32 v);
extern void func_0204A8D4(u32 v);
extern void func_0204AFD8(u32 v);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern u32 func_020056BC(void);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern void func_0202F038(u8 *p);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 v);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 a);
extern void func_0203F8F4(u16 heapId);
extern void func_02045088(u16 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_021F49A8(void);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void func_021F4864(void *unused, Work_021F4D50 *p);
extern void func_02030EAC(struct Node *n);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void *func_020120F4(const struct Ctx *p);
extern void func_02012E08(char *p);
extern void func_0200F7C0(u32 c);
extern void func_021FFFE8(u8 *, u32, u32);
extern void func_021FFD44(char *p);
extern int func_0207D55C(volatile u16 *reg);
extern void func_0202208C(void *, u32, u32, u32, u32, u32, u32);
extern void func_021F68A4(u8 *, int);
extern void func_021F9254(u8 *);
extern void func_021FFD74(char *p);
extern void func_022000E4(char *p);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern u32 func_02043668(void);
extern void func_02043598(u32 mask, u32 enable);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_02041570(int channel, u16 val);
extern void sub_020403F4(u32 i);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *);
extern void func_02200AB4(u8 *);
extern void func_02200B34(u8 *);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B92C(struct Obj *, u32);
extern void func_0204B878(struct Obj *p, u16 value);
extern u8 func_020355C4(void);
extern void func_0204B84C(u32, int);
extern void func_0204B974(struct Actor *a);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern int func_021F91A0(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
extern void func_02200BAC(u8 *p, u32 k);
extern void func_02202940(struct Obj *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_021F6E08(u8 *);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020221A4(void);
extern void func_021F663C(u8 *, u32, u32, u32, u32, u32);
extern void func_0204B9A0(struct Actor *a);
extern void func_020061E4(u32 se);
extern int func_021F6C48(void *party, void *save, int box, int slot);
extern int func_021F6BA4(void *party, void *save, int box, int slot);
extern void *func_021F6B40(void *party, void *save, int box, int slot);
extern void func_022025E4(u32 a, u32 b, u32 c);
extern int func_021F6CDC(void *mon, void *want);
extern int func_02035C08(const void *key);
extern void func_020355D8(u8 v);
extern int func_021F5F9C(int a, int b, int c);
extern void func_021F5F60(u32 cursor, int i);
extern void func_021F5E44(Work_021F5CD4 *p);
extern u32 func_020362DC(void);
void func_021F4D50(u8 *p, u16 a, int count, int b);
u32 func_021F4E30(u8 *p);
void func_021F4E64(u8 *p);
void func_021F4E98(u8 *p, u32 a, u32 b);
void func_021F4EA0(u32 a, u16 b, u16 c);
int func_021F4EB4(void);
void func_021F4EC0(u8 *p, u32 a, u32 b);
void func_021F4EC8(u8 *p);
int func_021F4ED4(void);
void func_021F4EDC(u8 *p);
void func_021F4EFC(u8 *p);
void func_021F4F84(u8 *p);
void func_021F4F90(u8 *p);
void func_021F4FA4(u8 *p);
void func_021F4FC4(u8 *p);
void func_021F4FF4(u32 a, u32 b, u32 c);
void func_021F5008(u32 x);
void func_021F5034(u32 x);
void func_021F5060(void);
void func_021F5074(Work_021F4D50 *p);
void func_021F50EC(u8 *p);
void func_021F513C(u8 *p);
int func_021F5154(u8 *p);
void func_021F51F0(u8 *p);
int func_021F5204(u8 *p);
void func_021F5250(void);
void func_021F5358(void);
void func_021F5374(u8 *p);
void func_021F5420(Work_021F5420 *p);
void func_021F577C(u8 *p);
void func_021F57EC(Work_021F57EC *p);
void func_021F5940(u8 *p);
void func_021F5980(u8 *p);
void func_021F59E8(char *p);
int func_021F5A18(u8 *p);
void func_021F5A7C(Work_021F5A7C *p);
void func_021F5B8C(Work_021F5B8C *p);
int func_021F5CA4(Work_021F5CA4 *p);
void func_021F5CD4(u8 *p, u32 k);
int func_021F5CFC(Work_021F5CD4 *p);
extern const char str_02203B08[];
extern const Items data_02202C2C;
extern u8 g_02202BFC[];
extern const struct DispConfig tbl_02202BB8;
extern void *g_02203B0C[];
extern struct DispConfig g_02202C94;
extern struct BgTemplate g_02202CE4;
extern struct BgTemplate g_02202D04;
extern struct BgTemplate g_02202CA4;
extern struct BgTemplate g_02202CC4;
extern const Pos tbl_02202D24[];
extern const Pos tbl_02202C50[];
extern const char str_02203B54[];
extern const u8 tbl_02202E24[];





void func_021F4D50(u8 *p, u16 a, int count, int b)
{
    Items items;
    Menu menu;
    int i;
    if (*(u32 *)&((struct Obj00448 *)p)->fE04) func_02034714(str_02203B08,0,str_02203B08);
    if (*(u32 *)&((struct Obj00448 *)p)->fE08) func_02034714(str_02203B08,0,str_02203B08);
    ((struct Obj00448 *)p)->fE04=func_02027F60(a,10,((struct Obj00448 *)p)->fFA0,((struct Obj00448 *)p)->fFAC,0x48);
    items=data_02202C2C;
    func_02082BCC(&menu,0,20);
    if ((u32)count>3) func_02034714(str_02203B08,0,str_02203B08);
    for(i=0;i<count;i++) items.item[i].a=*(u32 *)(*(u32 *)&((struct Obj00448 *)p)->fDE8+i*8);
    menu.heap=0x48;
    menu.count=count;
    menu.items=items.item;
    menu.mode=1;
    menu.a=0x20;
    menu.b=b;
    menu.c=13;
    menu.d=3;
    ((struct Obj00448 *)p)->fE08=func_02027778((struct TaskMenuTmpl *)(&menu),((struct Obj00448 *)p)->fE04);
    func_021F5008(1);
}






u32 func_021F4E30(u8 *p)
{
    u32 r = (u32)-1;

    if (((struct Obj00045 *)p)->fE08 != 0) {
        func_02027974(((struct Obj00045 *)p)->fE08);
        if (func_020279E8(((struct Obj00045 *)p)->fE08) != 0) {
            r = func_02027A04(((struct Obj00045 *)p)->fE08) + 1;
            func_021F5060();
        }
    }
    return r;
}






void func_021F4E64(u8 *p)
{
    if (((struct Obj00045 *)p)->fE08 != 0) {
        func_02027858(((struct Obj00045 *)p)->fE08);
        ((struct Obj00045 *)p)->fE08 = 0;
    }
    if (((struct Obj00045 *)p)->fE04 != 0) {
        func_02027FD8(((struct Obj00045 *)p)->fE04);
        ((struct Obj00045 *)p)->fE04 = 0;
    }
    func_021F5060();
}





void func_021F4E98(u8 *p, u32 a, u32 b)
{
    ((struct Obj00018 *)p)->f28 = a;
    ((struct Obj00018 *)p)->f2C = b;
}






/*
 * Send a one-entry u16 table {b, c} to func_0204B404.
 */
void func_021F4EA0(u32 a, u16 b, u16 c)
{
    u16 t[2];

    t[0] = b;
    t[1] = c;
    func_0204B404((struct Obj *)a, (const struct Vec2 *)t, 1);
}






int func_021F4EB4(void)
{
    return 3 - func_0205CCD8();
}





/*
 * Store two words into the object at +0x14 and +0x20.
 */
void func_021F4EC0(u8 *p, u32 a, u32 b)
{
    ((struct Obj00018 *)p)->f14 = a;
    *(u32 *)&((struct Obj00018 *)p)->f20 = b;
}





/*
 * Save the current value at +0x10 into +0x1c and move +0x14 down into +0x10.
 */
void func_021F4EC8(u8 *p)
{
    ((struct Obj00287 *)p)->f1C = ((struct Obj00287 *)p)->f10;
    ((struct Obj00287 *)p)->f10 = ((struct Obj00287 *)p)->f14;
}






int func_021F4ED4(void)
{
    return sub_02012FFC();
}






/*
 * Wire the shared table into the two initialisers and release the channel.
 */
void func_021F4EDC(u8 *p)
{
    func_021F4894((const struct DispVram *)g_02202BFC);
    func_021F49F8(p, (u32)g_02202BFC);
    func_021F4BCC(p);
}






void func_021F4EFC(u8 *p)
{
    func_021FFCD4(p);
    func_0204ADA4(((struct Obj00996 *)p)->fBE0);
    func_0204A8D4(((struct Obj00996 *)p)->fBDC);
    func_0204AFD8(((struct Obj00996 *)p)->fBE4);
    func_0204ADA4(((struct Obj00996 *)p)->fBD4);
    func_0204A8D4(((struct Obj00996 *)p)->fBD0);
    func_0204AFD8(((struct Obj00996 *)p)->fBD8);
    func_0204ADA4(((struct Obj00996 *)p)->fBC8);
    func_0204A8D4(((struct Obj00996 *)p)->fBC4);
    func_0204AFD8(((struct Obj00996 *)p)->fBCC);
    func_0204A8D4(((struct Obj00996 *)p)->fBE8);
    func_0204AFD8(((struct Obj00996 *)p)->fBF0);
    func_0204B1CC((struct Bank *)(((struct Obj00996 *)p)->fBC0));
    ((struct Obj00996 *)p)->fBC0 = 0;
    func_0204A5AC();
}





/*
 * Decrement the u16 counter at +0x36 when it is non-zero.
 */
void func_021F4F84(u8 *p)
{
    u16 v = ((struct Obj12193 *)p)->f36;

    if (v != 0) {
        ((struct Obj12193 *)p)->f36 = v - 1;
    }
}





/*
 * Set the u16 flag at +0xeb2 and clear the one at +0xeb0.
 */
void func_021F4F90(u8 *p)
{
    ((struct Obj02863 *)p)->fEB2 = 1;
    ((struct Obj02863 *)p)->fEB0 = 0;
}






/*
 * blocker resolved: 0x020056BC was matched in arm9 (src/matched/
 * func_020056BC.c, shard pkt_020056BC); the call now attests as `matched`.
 * All 32 bytes are right.
 *
 * Start a frame with the 0x48-byte object held at +0xd40 and keep the result at +0xdf8.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_021F4FA4.c --func func_021F4FA4  *       --addr 0x021F4FA4 --region ov135 --thumb --cc dsi/1.1p1 --diff
 */
void func_021F4FA4(u8 *p)
{
    ((struct Obj12194 *)p)->fDF8 = (u32)func_0202EE30((void *)func_020056BC(), (void *)(((struct Obj12194 *)p)->fD40),
                                        0xf, 0x10, 0x48);
}






void func_021F4FC4(u8 *p)
{
    if (((struct Obj00018 *)p)->fDF8 != 0) {
        func_0202F038((u8 *)(((struct Obj00018 *)p)->fDF8));
        ((struct Obj00018 *)p)->fDF8 = 0;
        func_02045374((struct Cfg *)(((struct Obj00018 *)p)->fD40));
        func_020409B4(func_02045730((struct Descriptor *)(((struct Obj00018 *)p)->fD40)));
    }
}






void func_021F4FF4(u32 a, u32 b, u32 c)
{
    u16 t[2];

    t[0] = b;
    t[1] = c;
    func_0204B404((struct Obj *)a, (const struct Vec2 *)t, 0);
}






/*
 * Pick the 0x04000050 or 0x04001050 hardware register from the flag and write the 0x1e/-7 pair.
 */
void func_021F5008(u32 x)
{
    if (x != 0) {
        func_0207D658(0x04000050, 0x1e, -7);
    } else {
        func_0207D658(0x04001050, 0x1e, -7);
    }
}






/*
 * Pick the 0x04000050 or 0x04001050 hardware register from the flag and write the 0x1b/-7 pair.
 */
void func_021F5034(u32 x)
{
    if (x != 0) {
        func_0207D658(0x04000050, 0x1b, -7);
    } else {
        func_0207D658(0x04001050, 0x1b, -7);
    }
}





/*
 * Clear the two display control registers.
 */
void func_021F5060(void)
{
    *(u16 *)0x04000050 = 0;
    *(u16 *)0x04001050 = 0;
}






void func_021F5074(Work_021F4D50 *p)
{
    func_020434CC();
    func_02043588();
    func_02043534(0);
    func_020435F4(0);
    func_021F4EDC((u8 *)p);
    func_0203F8F4(0x48);
    func_02045088(0x48);
    {
        struct DispConfig c = tbl_02202BB8;

        func_0203FC28(&c);
    }
    func_021F49A8();
    *(vu16_021F5074 *)0x04000050 = 0;
    *(vu16_021F5074 *)0x04001050 = 0;
    if (p->vblank == 0) {
        p->vblank = func_020056A0(func_021F4864, p, 0);
    }
}






void func_021F50EC(u8 *p)
{
    if (((struct Obj05413 *)p)->fF90 != 0) {
        func_02030EAC(((struct Obj05413 *)p)->fF90);
        ((struct Obj05413 *)p)->fF90 = 0;
    }
    *(vu16_021F50EC *)0x04000050 = 0;
    *(vu16_021F50EC *)0x04001050 = 0;
    func_021F4EFC(p);
    func_020450C8();
    func_0203F9B4();
    *(vu32 *)0x04000000 &= 0xFFFF1FFF;
    *(vu32 *)0x04001000 &= 0xFFFF1FFF;
}






void func_021F513C(u8 *p)
{
    func_02012E08(func_020120F4((const struct Ctx *)(*(u32 *)(((struct Obj18539 *)p)->f0 + 0x40))));
    func_0200F7C0(0x29);
}





/*
 * volatile: hardware halfword 04000304 read at 021F5162 before masked write.
 */
int func_021F5154(u8 *p)
{
    func_021F5980(p);
    *(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000);
    func_021F5250();
    func_021FFFE8(p, 0, 0);
    func_021F5374(p);
    func_021F57EC((Work_021F57EC *)p);
    func_021F5420((Work_021F5420 *)p);
    func_021FFD44((char *)p);
    if (func_0207D55C((u16 *)0x0400106c) == 0) {
        func_0202208C((void *)3, 1, 1, 0, 6, 1, 0x48);
    } else {
        func_0202208C(0, 1, 1, 0, 6, 1, 0x48);
    }
    func_021F68A4(p, ((struct Obj10575 *)p)->fC4);
    func_021F9254(p);
    ((struct Obj10575 *)p)->f28 = 0;
    ((struct Obj10575 *)p)->f12E4 = 0;
    return 1;
}






/*
 * State-table dispatch through the table at 0x02203B0C.
 */
void func_021F51F0(u8 *p)
{
    ((void (*)(u8 *))g_02203B0C[*(u32 *)(p + 0x28)])(p);
}




int func_021F5204(u8 *p)
{
    if (func_0207D55C((u16 *)0x0400106c)) {
        func_021FFD74((char *)p);
    }
    func_021F577C(p);
    func_021F59E8((char *)p);
    func_021F5940(p);
    func_021F5358();
    func_022000E4((char *)p);
    func_0204B3DC((struct Obj *)*(u32 *)&((struct Obj00287 *)p)->fD38, 0);
    func_021F4EC8(p);
    return 0;
}





/*
 * Five-layer bring-up: the saved display config, then layers 0, 2 and 3
 * through 020414EC and layers 0 and 3 cleared through 02040B94.
 */
void func_021F5250(void)
{
    struct DispConfig c = g_02202C94;
    u32 v = func_02043668();

    func_0203FC28(&c);
    func_020435F4(v);
    {
        struct BgTemplate t = g_02202CE4;
        func_0203FCA0(0, &t, 0);
    }
    func_020414EC(0);
    func_02040588(0, 1);
    {
        struct BgTemplate t = g_02202D04;
        func_0203FCA0(1, &t, 0);
    }
    func_02040588(1, 1);
    {
        struct BgTemplate t = g_02202CA4;
        func_0203FCA0(2, &t, 0);
    }
    func_020414EC(2);
    func_02040588(2, 1);
    {
        struct BgTemplate t = g_02202CC4;
        func_0203FCA0(3, &t, 0);
    }
    func_020414EC(3);
    func_02040588(3, 1);
    func_02040B94(0, 0x20, 0, 0x48);
    func_02040B94(3, 0x20, 0, 0x48);
}





/*
 * Poke the channel-selection helper with 2, 1, 0, 3 in turn.
 */
void func_021F5358(void)
{
    sub_020403F4(2);
    sub_020403F4(1);
    sub_020403F4(0);
    sub_020403F4(3);
}




void func_021F5374(u8 *p)
{
    void *h;
    h = func_020490F4(0x60, 0x48);
    func_02049B68(h, 1, 0, 0, 0x60, 0x48);
    func_02049B40(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    func_0201F5BC(0, 1, 0xe, 0, 0x48);
    func_0201F5BC(0, 0x1f, 0xb, 0, 0x48);
    func_02049658(h, 0xa, 1, 0, 0xa00, 1, 0x48);
    func_020498F4(h, 0x15, 1, 0, 0x600, 1, 0x48);
    func_020498F4(h, 0x1f, 2, 0, 0x600, 1, 0x48);
    func_02049238(h);
    func_02200AB4(p);
    func_02200B34(p);
}





void func_021F5420(Work_021F5420 *p)
{
    Local s;
    int i;

    func_02082BCC(&s, 0, 8);
    s.a = tbl_02202D24[p->idx].x;
    s.b = tbl_02202D24[p->idx].y;
    p->sub.f34 = (u32)func_0204B294((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
    func_0204B92C((struct Obj *)p->sub.f34, 1);
    func_0204B878((struct Obj *)p->sub.f34, 4);
    if (func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)p->sub.f34, 0);
    } else {
        func_0204B3DC((struct Obj *)p->sub.f34, 1);
    }
    if (p->idx == 0x1f || p->idx <= 5) {
        func_0204B84C(p->sub.f34, 0);
    } else {
        func_0204B84C(p->sub.f34, 1);
    }

    for (i = 0; i < 30; i++) {
        s.a = tbl_02202D24[i].x;
        s.b = tbl_02202D24[i].y;
        s.d = 30 - i % 6;
        p->sub.arrA[i] = (u32)func_0204B294((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
        func_0204B878((struct Obj *)p->sub.arrA[i], i + 6);
        func_0204B84C(p->sub.arrA[i], 1);
    }

    for (i = 0; i < 30; i++) {
        s.a = tbl_02202D24[i].x;
        s.b = tbl_02202D24[i].y + 6;
        s.d = 10;
        p->sub.arrB[i] = (u32)func_0204B294((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
        func_0204B878((struct Obj *)p->sub.arrB[i], 0x28);
        func_0204B84C(p->sub.arrB[i], 1);
    }

    for (i = 0; i < 6; i++) {
        s.a = tbl_02202D24[i].x + 8;
        s.b = tbl_02202D24[i].y + 6;
        s.d = 10;
        p->arrC[i] = (u32)func_0204B294((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
        func_0204B878((struct Obj *)p->arrC[i], 0x2a);
        func_0204B84C(p->arrC[i], 1);
    }

    for (i = 0; i < 2; i++) {
        s.a = tbl_02202C50[i].x;
        s.b = tbl_02202C50[i].y;
        p->arrD[i] = (u32)func_0204B294((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
        func_0204B878((struct Obj *)p->arrD[i], i + 0x26);
        func_0204B84C(p->arrD[i], 1);
    }

    s.a = 0xef;
    s.b = 0x88;
    s.d = 100;
    s.e = 1;
    p->sub.f3C = (u32)func_0204B294((void *)p->sub.f0, p->sub.f28, p->sub.f8, p->sub.f30, &s, 0, 0x48);
    func_0204B878((struct Obj *)p->sub.f3C, 0xc);
    func_0204B92C((struct Obj *)p->sub.f3C, 1);
    func_0204B974((struct Actor *)p->sub.f3C);
    func_0204B3DC((struct Obj *)p->sub.f3C, 0);
    func_0204B3DC((struct Obj *)p->fD38, 1);
    func_021F4EA0(p->fD38, 0x37, 0xa8);
}




void func_021F577C(u8 *p)
{
    int i;
    u8 *q;
    func_0204B3B4((struct Obj *)(((struct Obj14160 *)p)->fBFC));
    for (i = 0; i < 2; i++) {
        func_0204B3B4((struct Obj *)(*(u32 *)(p + 0xd2c + i * 4)));
    }
    func_0204B3B4((struct Obj *)(((struct Obj14160 *)p)->fBF4));
    for (i = 0; i < 30; i++) {
        q = p + i * 4;
        func_0204B3B4((struct Obj *)(((struct Obj14161 *)q)->fC00));
        func_0204B3B4((struct Obj *)(((struct Obj14161 *)q)->fC78));
    }
    for (i = 0; i < 6; i++) {
        func_0204B3B4((struct Obj *)(*(u32 *)(p + 0xcf0 + i * 4)));
    }
}





void func_021F57EC(Work_021F57EC *p)
{
    void *w;

    p->win0 = (void *)func_020450F0(3, 4, 0, 0xD, 3, 0xD, 1);
    func_02043B5C(func_02045770(p->win0), 0);
    w = p->win0;
    func_02045334(w);
    func_02045374(w);
    func_020409B4(func_02045730(w));

    p->win1 = (void *)func_020450F0(0, 2, 0x15, 0x1B, 2, 0xD, 1);
    func_02043B5C(func_02045770(p->win1), 0);
    w = p->win1;
    func_02045334(w);
    func_02045374(w);
    func_020409B4(func_02045730(w));

    p->win2 = (void *)func_020450F0(0, 2, 0x13, 0x1B, 4, 0xD, 1);
    func_02043B5C(func_02045770(p->win2), 0);
    w = p->win1;
    func_02045334(w);
    func_02045374(w);
    func_020409B4(func_02045730(w));

    p->win3 = (void *)func_020450F0(1, 0x18, 0x10, 6, 2, 0, 1);
    func_02043B5C(func_02045770(p->win3), 4);
    w = p->win3;
    func_02045334(w);
    func_02045374(w);
    func_020409B4(func_02045730(w));

    func_021F91A0(p->win3, (u32)p->strs, 0, 1, 1, 0x3DC4, (u32)p->g);
    if (p->mode == 5) {
        func_02200BAC((u8 *)p, 3);
    } else {
        func_02200BAC((u8 *)p, 1);
    }
}




void func_021F5940(u8 *p)
{
    func_02202940((struct Obj *)(p + 0xfa0));
    func_020452E8(((struct Obj00287 *)p)->fDE0);
    func_020452E8(((struct Obj00287 *)p)->fDD0);
    func_020452E8(((struct Obj00287 *)p)->fD54);
    func_020452E8(((struct Obj00287 *)p)->fD40);
    func_020452E8(((struct Obj00287 *)p)->fD4C);
}




void func_021F5980(u8 *p)
{
    func_021F6E08(p);
    ((struct Obj04526 *)p)->fB80 = func_020457B0(0x12, 0x48);
    ((struct Obj04526 *)p)->fB88 = func_020457B0(0xb4, 0x48);
    ((struct Obj04526 *)p)->fB84 = func_02045EC0(((struct Obj04526 *)p)->fB6C, 0x73);
    if (((struct Obj04526 *)p)->fC6 == 0x1e) {
        ((struct Obj04526 *)p)->fC6 = 0;
    }
    ((struct Obj04526 *)p)->fEAC = func_02030734(0x48, 0x78, 0, str_02203B54, 0x344);
}



void func_021F59E8(char *p) { func_020307B0(((struct Obj00287 *)p)->fEAC); func_02045808(((struct Obj00287 *)p)->fB80); func_02045808(((struct Obj00287 *)p)->fB88); func_02045808(((struct Obj00287 *)p)->fB84); }



/*
 * precondition: entry mode at offset 0x20 must be 5 or 6; original
 *   leaves r4 unchanged for other modes at 021F5A32..021F5A38.
 */
int func_021F5A18(u8 *p)
{
    int index;
    if (func_020221A4()) {
        if (((struct Obj00018 *)p)->f20 == 5) {
            index = 0x15;
        } else if (((struct Obj00018 *)p)->f20 == 6) {
            index = 0x11;
        }
        func_021F663C(p, index, 1, 0, 0xf0f, 0);
        func_021F4E98(p, 3, 1);
        if (func_020355C4() == 1) {
            func_0204B3DC((struct Obj *)((struct Obj00018 *)p)->fBF4, 0);
        } else {
            func_0204B3DC((struct Obj *)((struct Obj00018 *)p)->fBF4, 1);
        }
    }
    return 2;
}




void func_021F5A7C(Work_021F5A7C *p)
{
    if (p->slot == 0x1E) {
        func_0204B3DC((struct Obj *)p->cursor, 1);
        func_0204B9A0((struct Actor *)p->cursor);
        p->state = 0x11;
        func_020061E4(0x551);
        return;
    }
    if (p->slot == 0x1F) {
        return;
    }
    switch (func_021F6C48(p->ctx->party, p->ctx->save, p->box, p->slot)) {
    case 1:
        func_020061E4(0x54C);
        if (func_021F6BA4(p->ctx->party, p->ctx->save, p->box, p->slot) != 0) {
            func_022025E4((u32)p->msg, 0, (u32)func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot));
            func_021F663C((u8 *)p, 0x16, 1, 0, 0xF0F, 0);
            func_021F4E98((u8 *)p, 3, 7);
        } else {
            func_021F663C((u8 *)p, 0x1A, 1, 0, 0xF0F, 1);
            func_021F4E98((u8 *)p, 4, 1);
        }
        break;
    case 2:
        func_020061E4(0x54C);
        func_021F663C((u8 *)p, 0x21, 1, 0, 0xF0F, 1);
        func_021F4E98((u8 *)p, 4, 1);
        break;
    }
}




void func_021F5B8C(Work_021F5B8C *p)
{
    void *mon;

    if (p->slot == 0x1E) {
        func_0204B3DC((struct Obj *)p->cursor, 1);
        func_0204B9A0((struct Actor *)p->cursor);
        p->state = 0x11;
        return;
    }
    if (p->slot == 0x1F) {
        return;
    }
    switch (func_021F6C48(p->ctx->party, p->ctx->save, p->box, p->slot)) {
    case 1:
        mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
        if (func_021F6CDC(mon, p->list[p->sel].want) != 0) {
            if (func_021F6BA4(p->ctx->party, p->ctx->save, p->box, p->slot) != 0) {
                func_022025E4((u32)p->msg, 0, (u32)mon);
                func_021F663C((u8 *)p, 0x12, 1, 0, 0xF0F, 0);
                func_021F4E98((u8 *)p, 3, 9);
                func_020061E4(0x54C);
            } else {
                func_021F663C((u8 *)p, 0x1A, 1, 0, 0xF0F, 1);
                func_021F4E98((u8 *)p, 4, 1);
            }
        } else {
            func_020061E4(0x551);
        }
        break;
    case 0:
    case 2:
        func_020061E4(0x551);
        break;
    }
}




int func_021F5CA4(Work_021F5CA4 *p)
{
    int r = func_02035C08(tbl_02202E24);

    if (r != -1) {
        func_0204B3DC((struct Obj *)p->cursor, 0);
        func_020355D8(1);
    }
    return r;
}



/*
 * Two-way mode dispatch on the second argument, each arm latching state 2.
 */
void func_021F5CD4(u8 *p, u32 k)
{
    if (k == 5) {
        func_021F4EC0(p, 1, 0);
        ((struct Obj12195 *)p)->f28 = 2;
    } else if (k == 6) {
        func_021F4EC0(p, 3, 0x11);
        ((struct Obj12195 *)p)->f28 = 2;
    }
}



int func_021F5CFC(Work_021F5CD4 *p)
{
    int r = func_021F5CA4((Work_021F5CA4 *)p);

    if (r != -1) {
        switch (r) {
        case 0x1F:
            func_0204B92C((struct Obj *)p->arrows[0], 1);
            func_0204B878((struct Obj *)p->arrows[0], 0x26);
            p->box = func_021F5F9C(p->box, p->boxes, 1);
            func_021F68A4((u8 *)p, p->box);
            func_020061E4(0x548);
            break;
        case 0x20:
            func_0204B92C((struct Obj *)p->arrows[1], 1);
            func_0204B878((struct Obj *)p->arrows[1], 0x27);
            p->box = func_021F5F9C(p->box, p->boxes, -1);
            func_021F68A4((u8 *)p, p->box);
            func_020061E4(0x548);
            break;
        case 0x1E:
            func_0204B3DC((struct Obj *)p->marker, 1);
            func_0204B9A0((struct Actor *)p->marker);
            p->state = 0x11;
            p->slot = r;
            func_020061E4(0x551);
            func_021F5F60(p->cursor, p->slot);
            break;
        default:
            p->slot = r;
            func_021F5F60(p->cursor, p->slot);
            if (p->mode == 5) {
                func_021F5A7C((Work_021F5A7C *)p);
            } else if (p->mode == 6) {
                func_021F5B8C((Work_021F5B8C *)p);
            }
            break;
        }
    } else {
        func_021F5E44((Work_021F5CD4 *)p);
        if (p->mode == 5) {
            if (func_020362DC() & 2) {
                func_0204B3DC((struct Obj *)p->marker, 1);
                func_0204B9A0((struct Actor *)p->marker);
                p->state = 0x11;
                func_020061E4(0x551);
            } else if (func_020362DC() & 1) {
                func_021F5A7C((Work_021F5A7C *)p);
            }
        } else if (p->mode == 6) {
            if (func_020362DC() & 2) {
                func_0204B3DC((struct Obj *)p->marker, 1);
                func_0204B9A0((struct Actor *)p->marker);
                p->state = 0x11;
                func_020061E4(0x551);
            } else if (func_020362DC() & 1) {
                func_021F5B8C((Work_021F5B8C *)p);
            }
        }
    }
    return 2;
}
