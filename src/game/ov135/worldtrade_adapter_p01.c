/*
 * file:     worldtrade_adapter_p01.c
 * unit:     yes
 * function: func_021FB800, func_021FB964, func_021FB9E4, func_021FBA5C, func_021FBA84, func_021FBBA0, func_021FBC1C, func_021FBC78, func_021FBCB8, func_021FBCF4, func_021FBD68, func_021FBD94, func_021FBDD0, func_021FBE54, func_021FBE84, func_021FBEB8, func_021FBF04, func_021FBF6C, func_021FBFB0, func_021FC008, func_021FC014, func_021FC06C, func_021FC174, func_021FC188, func_021FC1C0, func_021FC2A4, func_021FC2C0, func_021FC360, func_021FC3D0, func_021FC3E0, func_021FC4E4, func_021FC528, func_021FC568, func_021FC5A0, func_021FC610, func_021FC638, func_021FC668, func_021FC6B8, func_021FC70C, func_021FC7C4, func_021FC7E0, func_021FC810, func_021FC8A8
 * address:  0x021FB800
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
 *   tbl_02203324  0x02203324  data  a4
 *   tbl_022033F8  0x022033F8  data
 *   tbl_02203440  0x02203440  data  a4
 *   tbl_022032C6  0x022032C6  data
 *   func_021F9260  0x021F9260  thumb
 *   func_021F4FF4  0x021F4FF4  thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021F9CDC 0x021F9CDC thumb ov135
 *   func_0204B98C 0x0204B98C arm
 *   func_021F9660 0x021F9660 thumb ov135
 *   func_020355C4  0x020355C4  arm
 *   func_0202CAE4 0x0202CAE4 thumb
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0204B92C 0x0204B92C arm
 *   func_021F8908 0x021F8908 thumb ov135
 *   func_021FB364 0x021FB364 thumb ov135
 *   func_021F9EEC 0x021F9EEC thumb ov135
 *   tbl_02203236 0x02203236 data a1
 *   func_021FA85C 0x021FA85C thumb ov135
 *   g_022033FC  0x022033FC  data  ov135
 *   func_021FAAD4  0x021FAAD4  thumb  ov135
 *   g_0220320E  0x0220320E  data  ov135
 *   g_0220320F  0x0220320F  data  ov135
 *   func_021FA15C 0x021FA15C thumb ov135
 *   func_021FAB70  0x021FAB70  thumb  ov135
 *   g_02203216  0x02203216  data  ov135
 *   g_02203217  0x02203217  data  ov135
 *   func_021FA394 0x021FA394 thumb ov135
 *   func_0201F868 0x0201F868 thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_021FAC50  0x021FAC50  thumb
 *   func_02045808  0x02045808  arm
 *   func_022028C8  0x022028C8  thumb
 *   func_02045334  0x02045334  arm
 *   func_0202CEBC  0x0202CEBC  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02202A50  0x02202A50  thumb
 *   func_02202B20  0x02202B20  thumb
 *   func_021F8498  0x021F8498  thumb
 *   func_021F84BC  0x021F84BC  thumb
 *   func_021FB240  0x021FB240  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_021F88D8  0x021F88D8  thumb  ov135
 *   func_0200ADB4 0x0200ADB4 thumb
 *   func_020185F0 0x020185F0 thumb
 *   func_020084F4 0x020084F4 thumb
 *   func_0202208C 0x0202208C thumb
 *   func_021FFFE8 0x021FFFE8 thumb ov135
 *   func_021FC8CC 0x021FC8CC thumb ov135
 *   func_021FCA8C 0x021FCA8C thumb ov135
 *   func_021F886C 0x021F886C thumb ov135
 *   func_021F8290 0x021F8290 thumb ov135
 *   func_021FCB54 0x021FCB54 thumb ov135
 *   g_02203CF0  0x02203CF0  data  ov135
 *   func_022000E4 0x022000E4 thumb ov135
 *   func_021F4EC8 0x021F4EC8 thumb ov135
 *   func_02043668  0x02043668  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_020435F4  0x020435F4  arm
 *   func_02043598  0x02043598  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040588  0x02040588  arm
 *   func_02040B94  0x02040B94  arm
 *   g_022034AC  0x022034AC  data  ov135
 *   g_022034DC  0x022034DC  data  ov135
 *   g_022034BC  0x022034BC  data  ov135
 *   g_022034FC  0x022034FC  data  ov135
 *   sub_020403F4  0x020403F4  arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049B40 0x02049B40 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_02200B34 0x02200B34 thumb ov135
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B84C 0x0204B84C arm
 *   func_0203D34C 0x0203D34C arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02200BAC 0x02200BAC thumb ov135
 *   tbl_0220351C 0x0220351C data a4
 *   func_02202940 0x02202940 thumb ov135
 *   func_020452E8 0x020452E8 arm
 *   func_020457B0 0x020457B0 arm
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_020061E4 0x020061E4 thumb
 *   func_021F4BF8  0x021F4BF8  thumb  ov135
 *   func_021F5060  0x021F5060  thumb  ov135
 *   func_021F5034  0x021F5034  thumb  ov135
 *   func_021F4D14 0x021F4D14 thumb ov135
 *   func_021F4CE4 0x021F4CE4 thumb ov135
 *   func_021FCBF0 0x021FCBF0 thumb ov135
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_021F4D50 0x021F4D50 thumb ov135
 *   func_021F4E30 0x021F4E30 thumb ov135
 *   func_021F4E64 0x021F4E64 thumb ov135
 *   func_021F6DE8 0x021F6DE8 thumb ov135
 *   func_0201AA18 0x0201AA18 thumb
 *   func_02202840  0x02202840  thumb  ov135
 *   func_0201EE84  0x0201EE84  thumb
 *   sub_02045EC0   0x02045EC0  arm
 *   func_0201F250  0x0201F250  thumb
 *   sub_02045770   0x02045770  arm
 *   sub_02043B5C   0x02043B5C  arm
 *   sub_02045334   0x02045334  arm
 *   sub_02045374   0x02045374  arm
 *   unit_02045730  0x02045730  arm
 *   sub_020409B4   0x020409B4  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   sub_02045808   0x02045808  arm
 *   func_02202858  0x02202858  thumb  ov135
 */
#include "../../matched/include/Obj00194.h"
#include "../../matched/include/Obj00098.h"
#include "../../matched/include/Obj05872.h"
#include "../../matched/include/Obj00437.h"
#include "../../matched/include/Obj23404.h"
#include "../../matched/include/Obj23405.h"
#include "../../matched/include/Obj02201.h"
#include "../../matched/include/Obj04906.h"
#include "../../matched/include/Obj02202.h"
#include "../../matched/include/Obj00474.h"
#include "../../matched/include/Obj01746.h"
#include "../../matched/include/Obj00287.h"
#include "../../matched/include/Obj03298.h"
#include "../../matched/include/Obj18568.h"
#include "../../matched/include/Obj10585.h"
#include "../../matched/include/Obj14170.h"
#include "../../matched/include/Obj23406.h"
#include "../../matched/include/Obj00018.h"
#include "../../matched/include/Obj18569.h"
#include "../../matched/include/Obj02489.h"
#include "../../matched/include/Obj08186.h"
#include "../../matched/include/Obj00448.h"
#include "../../matched/include/Obj00045.h"
#include "../../matched/include/Obj23409.h"
#include "../../matched/include/Obj12210.h"
#include "../../matched/include/Obj07246.h"

struct WinMgr;
struct Obj;
struct Actor;
struct MsgBank;
struct U16Vec;
struct Descriptor;
struct CharBuf;
struct Cfg;
struct Slot;
struct WordSet;
#include "worldtrade_types.h"

typedef struct {
    u8 x;
    u8 y;
} Cell_021FB800;

typedef struct {
    int first;
    int count;
} Span;

typedef struct {
    void **strs;
    u8 pad4[8 - 4];
    u32 cursor;
    u8 padC[0x14 - 0xC];
    u32 cursor2;
    void *mgr;
    u8 pad1C[0x20 - 0x1C];
    void *bank;
    u8 pad24[0x38 - 0x24];
    s16 layout;
    s16 start;
    u8 pad3C[0x44 - 0x3C];
    int pos;
    int state;
    u8 pad4C[0x60 - 0x4C];
    u8 flags[0x7C - 0x60];
    u8 g[4];
} Obj_vB800;

typedef struct {u8 x,y;} Cell_021FBA84;

typedef struct {
    u8 pad0[0x1C];
    u32 item;
    u8 pad20[0x2C - 0x20];
    u32 f2C;
} Menu_021FB800;

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

typedef struct {u32 x,y,w,h;} WinDef;


extern void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern u32 func_0202CF84(struct WinMgr *mgr, u32 idx);
extern void func_021F9260(Obj_vB800 *p, u32 mode);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern u8 func_020355C4(void);
extern void func_0204B3DC(struct Obj *obj, unsigned int on);
extern u16 func_0204B898(struct Obj *p);
extern int func_021F9CDC(void *p, u8 *flags);
extern u32 func_0204B98C(struct Actor *a);
extern void func_021F9660(void *p, u32 mode);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern void func_0204B92C(struct Obj *,u32);
extern int func_021F8908(void **menu, void *msg, int id);
extern void func_021FB364(void *,int,int);
extern u32 func_021F9EEC(u8 *p, u32 n);
extern int func_021FA85C(void *p);
extern u32 func_0201F868(void *p);
extern void func_021FAAD4(u8 *p);
extern int func_021FA15C(void *p);
extern void func_021FAB70(u8 *p);
extern int func_021FA394(void *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_021FAC50(void *mgr, void *win, void *str, u32 x, u16 color, void *g);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_022028C8(void *win, u32 z, void *str, u32 x, u32 y, u32 z2, u16 color, void *g);
extern void func_02045334(struct Descriptor *d);
extern void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02202A50(void *ctx, u32 num, u32 digits, u32 mode, void *win, int x, int y);
extern void func_02202B20(struct Obj *p, int arg1, void *arg2, int arg3, int arg4);
extern u16 *func_021F8498(u32 heap, u32 unused, u32 *count);
extern void func_021F84BC(u32 i, int *start, int *end);
extern int func_021FB240(u32 unused, u32 item, u32 c, u16 *list, int start, int end);
extern u32 func_020307B0(void *p);
extern int func_021F88D8(u32 id, u32 *start);
extern void *func_0200ADB4(void *);
extern void *func_020185F0(void *);
extern void *func_020084F4(void *);
extern int func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern void func_021FFFE8(u8 *,u32,u32);
extern void func_021FC8CC(void *,void *,void *,void **,void *,void *,void *);
extern void func_021FCA8C(void *,void *,void *,void *,void *,void *);
extern int func_021F886C(int,int,int);
extern void func_021F8290(void *,void *,int,u8 *,u32,int,int,void *);
extern void func_021FCB54(void *);
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
extern void func_020409B4(u32 layer);
extern void func_02041570(int channel, u16 val);
extern void sub_020403F4(u32 i);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *);
extern void func_02200B34(u8 *p);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B84C(void *, int);
extern void func_0203D34C(u32 a, u32 b);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02200BAC(u8 *p, u32 k);
extern void func_02202940(struct Obj *p);
extern u32 func_020452E8(struct Descriptor *d);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_020061E4(unsigned);
extern void func_021F4BF8(u8 *p, int b, int unused, int a, int c, u8 flag);
extern void func_021F5060(void);
extern void func_021F5034(u32 v);
extern int func_021F4D14(char *p);
extern void func_021F4CE4(char *p);
extern void func_021FCBF0(char *p);
extern void func_0201F7A8(void *p, unsigned kind);
extern void *func_0201F81C(u32 n, u32 heap);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern void func_021F4D50(u8 *p, u16 a, int count, int b);
extern unsigned int func_021F4E30(unsigned char *p);
extern void func_021F4E64(unsigned char *p);
extern int func_021F6DE8(unsigned int handle);
extern u32 func_0201AA18(void *p);
extern u32 func_02202840(u8 *p);
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern void *sub_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *sub_02045770(struct Descriptor *p);
extern void sub_02043B5C(struct CharBuf *buf, u8 value);
extern void sub_02045334(struct Descriptor *a);
extern void sub_02045374(struct Cfg *cfg);
extern u8 unit_02045730(u32 a);
extern void sub_020409B4(u32 index);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void sub_02045808(struct U16Vec *vec);
extern u32 func_02202858(void *p, u8 b, void *s, u32 x, u32 y, void *out);
int func_021FB800(Obj_vB800 *p);
int func_021FB964(u8 *p);
int func_021FB9E4(u8 *p);
int func_021FBA5C(u8 *p);
int func_021FBA84(u8 *p);
int func_021FBBA0(u8 *p);
int func_021FBC1C(u8 *p);
int func_021FBC78(u8 *p);
int func_021FBCB8(u8 *p);
int func_021FBCF4(u8 *p);
int func_021FBD68(u8 *p);
int func_021FBD94(u8 *p);
int func_021FBDD0(u8 *p);
int func_021FBE54(u8 *p);
void func_021FBE84(void *mgr, void *bank, void *win, u32 index, u32 x, u16 color, void *g);
void func_021FBEB8(void *mgr, void *bank, void *win, u32 index, void *g);
void func_021FBF04(void *mgr, void *ctx, void *win, int page, u32 pages);
int func_021FBF6C(Menu_021FB800 *m, u32 idx);
int func_021FBFB0(void *p, int idx);
int func_021FC008(void *p, u32 a);
int func_021FC014(void *p, int idx);
int func_021FC06C(u8 *p);
void func_021FC174(u8 *p);
int func_021FC188(u8 *p);
void func_021FC1C0(void);
void func_021FC2A4(void);
void func_021FC2C0(void *p);
void func_021FC360(char *p);
void func_021FC3D0(u8 *p);
void func_021FC3E0(Work *p);
void func_021FC4E4(char *p);
void func_021FC528(char *p);
void func_021FC568(char *p);
int func_021FC598(char *p);
int func_021FC5A0(char *p);
int func_021FC610(u8 *p, int a1);
int func_021FC638(u8 *p);
int func_021FC668(char *p);
int func_021FC6B8(char *p);
int func_021FC70C(char *p);
int func_021FC7C4(u8 *p);
int func_021FC7E0(u8 *p);
void func_021FC810(u8 *p, u32 b, u32 c, u32 d, u32 e, void *sel);
u16 func_021FC8A8(int mode);
extern const int tbl_02203324[];
extern const Span tbl_022033F8[];
extern const u32 tbl_02203440[];
extern const Cell_021FB800 tbl_022032C6[];
extern const Cell_021FBA84 tbl_02203236[];
extern u8 g_022033FC[];
extern u8 g_0220320E[];
extern u8 g_0220320F[];
extern u8 g_02203216[];
extern u8 g_02203217[];
extern void *g_02203CF0[];
extern struct DispConfig g_022034AC;
extern struct BgTemplate g_022034DC;
extern struct BgTemplate g_022034BC;
extern struct BgTemplate g_022034FC;
extern const WinDef tbl_0220351C[];


int func_021FB800(Obj_vB800 *p)
{
    int i;
    u16 color;

    func_0202CAE4(p->mgr, 0, 0x60, 0x1A, 1);
    func_0202CF84(p->mgr, 0);
    func_021F9260(p, 5);
    func_02082BCC(p->flags, 1, 0x1A);
    func_021FBE84(p->mgr, p->bank, p->strs[0], p->layout + 0x74, 2, 0x3DC2, p->g);
    for (i = 1; i < 4; i++) {
        if (func_021FC008(p, tbl_02203324[p->layout] + i - 1) > 0) {
            color = 0x3DC2;
            p->flags[tbl_02203324[p->layout] + i - 1] = 1;
        } else {
            color = 0x2122;
            p->flags[tbl_02203324[p->layout] + i - 1] = 0;
        }
        func_021FBE84(p->mgr, p->bank, p->strs[i], tbl_02203440[tbl_022033F8[p->layout].first + i - 1], 5, color, p->g);
    }
    func_021FBEB8(p->mgr, p->bank, p->strs[14], 0x4A, p->g);
    func_0202CB4C(p->mgr, 0, 0x10, 0);
    func_0204B878((struct Obj *)p->cursor, 4);
    if (p->start < 0) {
        p->pos = 0;
    } else {
        p->pos = p->start;
    }
    func_021F4FF4(p->cursor, (tbl_022032C6[p->pos].x + 0x10) * 8, tbl_022032C6[p->pos].y * 8);
    if (func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)p->cursor, 0);
    } else {
        func_0204B3DC((struct Obj *)p->cursor, 1);
    }
    if (p->cursor2 != 0) {
        func_0204B3DC((struct Obj *)p->cursor2, 1);
    }
    p->state = 0x17;
    return -1;
}


int func_021FB964(u8 *p)
{
    int r;
    r = func_021F9CDC(p, p + 0x60);
    switch ((u32)r) {
    case 0: case 1: case 2: case 3: case 4:
        func_0204B3DC((struct Obj *)((struct Obj00194 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj00194 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj00194 *)p)->f8)) + 9);
        ((struct Obj00194 *)p)->f48 = 24;
        ((struct Obj00194 *)p)->f3A = r;
        break;
    case -2:
        func_0204B3DC((struct Obj *)((struct Obj00194 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj00194 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj00194 *)p)->f8)) + 9);
        ((struct Obj00194 *)p)->f48 = 24;
        ((struct Obj00194 *)p)->f3A = -1;
        break;
    }
    return -1;
}


/*
 * Tail: two zero bytes of alignment padding after the return.
 */
int func_021FB9E4(u8 *p)
{
    if (func_0204B98C(((struct Obj00098 *)p)->f8) != 0) return -1;
    func_0204B3DC((struct Obj *)*(u32 *)&((struct Obj00098 *)p)->f8, 0);
    func_021F9660(p, 5);
    if (((struct Obj00098 *)p)->f3A < 0) {
        ((struct Obj00098 *)p)->f48 = 21;
    } else {
            func_0202CD64(((struct Obj00098 *)p)->f18, 0, -4, 0, 3);
            if (((struct Obj00098 *)p)->f14 != 0) func_0204B3DC((struct Obj *)((struct Obj00098 *)p)->f14, 0);
            func_0204B878((struct Obj *)(*(u32 *)&((struct Obj00098 *)p)->f8), 7);
            ((struct Obj00098 *)p)->f48 = 2;
            func_0202CAE4(((struct Obj00098 *)p)->f18, 0, 0x60, 0x18, 1);
            ((struct Obj00098 *)p)->f4C = 26;
    }
    return -1;
}


/*
 * State select before the notify call.
 */
int func_021FBA5C(u8 *p)
{
    u32 v;
    int n;

    ((struct Obj05872 *)p)->f48 = 0x16;
    ((struct Obj05872 *)p)->f44 = ((struct Obj05872 *)p)->f3A;
    if (func_020355C4() == 1) {
        v = ((struct Obj05872 *)p)->f8;
        n = 0;
    } else {
        v = ((struct Obj05872 *)p)->f8;
        n = 1;
    }
    func_0204B3DC((struct Obj *)v, n);
    return -1;
}


int func_021FBA84(u8 *p)
{
    u8 pages;
    func_0202CAE4(((struct Obj00437 *)p)->f18,0,0x60,0x18,1);
    func_021F9260((Obj_vB800 *)p, 3);
    ((struct Obj00437 *)p)->f58=func_021F8908((void **)(p+0x30),((struct Obj00437 *)p)->f28,((struct Obj00437 *)p)->f3A+tbl_02203324[((struct Obj00437 *)p)->f38]);
    func_021FB364(p,0,((struct Obj00437 *)p)->f58);
    ((struct Obj00437 *)p)->f56=0;
    pages=func_021F9EEC((u8 *)(((struct Obj00437 *)p)->f58),5);
    func_021FBF04(((struct Obj00437 *)p)->f18,((struct Obj00437 *)p)->f34,((struct Obj23404 *)(*(u8 * *)&((struct Obj00437 *)p)->f0))->f14,((struct Obj00437 *)p)->f56,pages);
    func_021FBEB8(((struct Obj00437 *)p)->f18,((struct Obj00437 *)p)->f20,((struct Obj23405 *)(*(u8 * *)&((struct Obj00437 *)p)->f0))->f38,0x4A,p+0x7C);
    func_0202CB4C(((struct Obj00437 *)p)->f18,0,1,0);
    ((struct Obj00437 *)p)->f44=0;
    func_021F4FF4(((struct Obj00437 *)p)->f8,tbl_02203236[*(int *)(p+0x44)].x,tbl_02203236[*(int *)(p+0x44)].y);
    func_021F4FF4(((struct Obj00437 *)p)->fC,0xB0,0x88);
    func_021F4FF4(((struct Obj00437 *)p)->f10,0x58,0x88);
    if(func_020355C4()==1)
        func_0204B3DC((struct Obj *)((struct Obj00437 *)p)->f8,0);
    else
        func_0204B3DC((struct Obj *)((struct Obj00437 *)p)->f8,1);
    if(pages==1) {
        func_0204B878((struct Obj *)(((struct Obj00437 *)p)->fC),0x3D);
        func_0204B878((struct Obj *)(((struct Obj00437 *)p)->f10),0x3E);
    } else {
        func_0204B878((struct Obj *)(((struct Obj00437 *)p)->fC),0x26);
        func_0204B878((struct Obj *)(((struct Obj00437 *)p)->f10),0x27);
    }
    func_0204B92C((struct Obj *)((struct Obj00437 *)p)->fC,0);
    func_0204B92C((struct Obj *)((struct Obj00437 *)p)->f10,0);
    func_0204B3DC((struct Obj *)((struct Obj00437 *)p)->fC,1);
    func_0204B3DC((struct Obj *)((struct Obj00437 *)p)->f10,1);
    ((struct Obj00437 *)p)->f48=27;
    return -1;
}


int func_021FBBA0(u8 *p)
{
    int r;
    r = func_021FA85C(p);
    switch (r) {
    case -2:
        func_0204B3DC((struct Obj *)((struct Obj02201 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj02201 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj02201 *)p)->f8)) + 9);
        func_0202CAE4(((struct Obj02201 *)p)->f18, 0, 0x60, 0x18, 1);
        ((struct Obj02201 *)p)->f48 = 5;
        ((struct Obj02201 *)p)->f4C = 28;
        break;
    case -1: break;
    default:
        func_0204B3DC((struct Obj *)((struct Obj02201 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj02201 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj02201 *)p)->f8)) + 9);
        ((struct Obj02201 *)p)->f48 = 3;
        ((struct Obj02201 *)p)->f4C = 29;
        ((struct Obj02201 *)p)->f3E = r;
        break;
    }
    return -1;
}


/*
 * If the buffer is still live return -1; otherwise release the three pointers and pick the 0x19/0x15 code from the table.
 */
int func_021FBC1C(u8 *p)
{
    if (func_0204B98C((struct Actor *)(*(u32 *)&((struct Obj00098 *)p)->f8)) != 0) {
        return -1;
    }
    func_0204B3DC((struct Obj *)*(u32 *)&((struct Obj00098 *)p)->f8, 0);
    func_0204B3DC((struct Obj *)((struct Obj00098 *)p)->fC, 0);
    func_0204B3DC((struct Obj *)((struct Obj00098 *)p)->f10, 0);
    func_021F9660(p, 0x3);
    func_0201F868((void *)(*(u32 *)&((struct Obj00098 *)p)->f30));
    *(u32 *)&((struct Obj00098 *)p)->f48 = (*(s32 *)(g_022033FC + ((struct Obj00098 *)p)->f38 * 8) != 1) ? 0x19 : 0x15;
    return -1;
}


int func_021FBC78(u8 *p)
{
    if (func_0204B98C(((struct Obj00098 *)p)->f8) != 0) return -1;
    func_0204B3DC((struct Obj *)*(u32 *)&((struct Obj00098 *)p)->f8, 0);
    func_0204B3DC((struct Obj *)((struct Obj00098 *)p)->fC, 0);
    func_0204B3DC((struct Obj *)((struct Obj00098 *)p)->f10, 0);
    func_021F9660(p, 3);
    func_0201F868(((struct Obj00098 *)p)->f30);
    return ((struct Obj00098 *)p)->f3E;
}


/*
 * Reset, re-arm the 6 frame, then index the two parallel stride-2 tables from the cursor at +0x44.
 */
int func_021FBCB8(u8 *p)
{
    u32 i;

    ((struct Obj04906 *)p)->f44 = 0;
    func_021FAAD4(p);
    func_0204B878((struct Obj *)(((struct Obj04906 *)p)->f8), 6);
    i = ((struct Obj04906 *)p)->f44;
    func_021F4FF4(((struct Obj04906 *)p)->f8, g_0220320E[i * 2], g_0220320F[i * 2]);
    ((struct Obj04906 *)p)->f48 = 1;
    ((struct Obj04906 *)p)->f4C = 0x1f;
    return -1;
}


int func_021FBCF4(u8 *p)
{
    int r;
    r = func_021FA15C(p);
    switch (r) {
    case -2:
        func_0204B3DC((struct Obj *)((struct Obj02202 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj02202 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj02202 *)p)->f8)) + 9);
        ((struct Obj02202 *)p)->f48 = 3;
        ((struct Obj02202 *)p)->f4C = 32;
        ((struct Obj02202 *)p)->f40 = -2;
        break;
    case -1: break;
    default:
        func_0204B3DC((struct Obj *)((struct Obj02202 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj02202 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj02202 *)p)->f8)) + 9);
        ((struct Obj02202 *)p)->f48 = 3;
        ((struct Obj02202 *)p)->f4C = 32;
        ((struct Obj02202 *)p)->f40 = r;
        break;
    }
    return -1;
}


/*
 * Extent remainder: 2-byte zero alignment padding.
 */
int func_021FBD68(u8 *p) { if(func_0204B98C(((struct Obj00098 *)p)->f8))return -1;func_0204B3DC(((struct Obj00098 *)p)->f8,0);func_021F9660(p,1);return ((struct Obj00098 *)p)->f40; }


int func_021FBD94(u8 *p)
{
    u32 i;

    ((struct Obj00474 *)p)->f44 = 0;
    func_021FAB70(p);
    func_0204B878((struct Obj *)(((struct Obj00474 *)p)->f8), 6);
    i = ((struct Obj00474 *)p)->f44;
    func_021F4FF4(((struct Obj00474 *)p)->f8, g_02203216[i * 2], g_02203217[i * 2]);
    ((struct Obj00474 *)p)->f48 = 1;
    ((struct Obj00474 *)p)->f4C = 0x22;
    return -1;
}


int func_021FBDD0(u8 *p)
{
    int r;
    r = func_021FA394(p);
    switch (r) {
    case -2:
        func_0204B3DC((struct Obj *)((struct Obj01746 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj01746 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj01746 *)p)->f8)) + 9);
        ((struct Obj01746 *)p)->f48 = 3;
        ((struct Obj01746 *)p)->f4C = 35;
        ((struct Obj01746 *)p)->f41 = -2;
        break;
    case -1: break;
    default:
        func_0204B3DC((struct Obj *)((struct Obj01746 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj01746 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj01746 *)p)->f8)) + 9);
        ((struct Obj01746 *)p)->f48 = 3;
        ((struct Obj01746 *)p)->f4C = 35;
        ((struct Obj01746 *)p)->f41 = *(u32 *)(*(u8 * *)&((struct Obj01746 *)p)->f30 + (r + ((struct Obj01746 *)p)->f56 * 4) * 8 + 4);
        break;
    }
    return -1;
}


int func_021FBE54(u8 *p) { if(func_0204B98C(((struct Obj00098 *)p)->f8))return -1;func_0204B3DC(((struct Obj00098 *)p)->f8,0);func_021F9660(p,2);func_0201F868(((struct Obj00098 *)p)->f30);return ((struct Obj00098 *)p)->f41; }


void func_021FBE84(void *mgr, void *bank, void *win, u32 index, u32 x, u16 color, void *g)
{
    void *str = func_02045EC0(bank, index);

    func_021FAC50(mgr, win, str, x, color, g);
    func_02045808(str);
}


void func_021FBEB8(void *mgr, void *bank, void *win, u32 index, void *g)
{
    void *str = func_02045EC0(bank, index);

    func_022028C8(win, 0, str, 0, 0, 0, 0x3DC2, g);
    func_02045334(win);
    func_0202CEBC(mgr, 0, win);
    func_02045808(str);
}


void func_021FBF04(void *mgr, void *ctx, void *win, int page, u32 pages)
{
    func_02043B5C(func_02045770(win), 8);
    func_02202A50(ctx, page + 1, 2, 1, win, 0, 0);
    func_02202B20(ctx, 0, win, 0x10, 0);
    func_02202A50(ctx, pages, 2, 0, win, 0x18, 0);
    func_02045334(win);
    func_0202CEBC(mgr, 0, win);
}


int func_021FBF6C(Menu_021FB800 *m, u32 idx)
{
    u32 n;
    int start;
    int end;
    u16 *list;
    int r;

    list = func_021F8498(0x48, 0, &n);
    func_021F84BC(idx, &start, &end);
    n = end - start;
    r = func_021FB240(m->f2C, m->item, n, list, start, end);
    func_020307B0(list);
    return r;
}


int func_021FBFB0(void *p, int idx)
{
    int base;
    int i;
    base = tbl_02203324[idx];
    if (tbl_022033F8[idx].count > 0) {
        for (i = 0; i < tbl_022033F8[idx].count; i++) {
            if (func_021FBF6C((Menu_021FB800 *)p, base + i) > 0) return 1;
        }
    } else {
        if (func_021FBF6C((Menu_021FB800 *)p, base) > 0) return 1;
    }
    return 0;
}


/*
 * Hand the second argument to func_021F88D8 with a scratch word.
 */
int func_021FC008(void *p, u32 a)
{
    u32 tmp;

    return func_021F88D8(a, &tmp);
}


int func_021FC014(void *p, int idx)
{
    int base;
    int i;
    base = tbl_02203324[idx];
    if (tbl_022033F8[idx].count > 0) {
        for (i = 0; i < tbl_022033F8[idx].count; i++) {
            if (func_021FC008(p, base + i) > 0) return 1;
        }
    } else {
        if (func_021FC008(p, base) > 0) return 1;
    }
    return 0;
}


/*
 * note: 2026-10-05 recoup: func_0202208C declared with an int return (first-check lever). With void the
 *   literal 1 stayed in r4 for the stack store, r1, r2 and the return (4 B differ); with int the
 *   constants are rematerialised as in the original. The other callees stay void as in their matched files.
 */
int func_021FC06C(u8 *p)
{
    void *mon;
    int index;
    mon=func_0200ADB4(*(void **)(*(u8 **)p));
    func_021FC528((char *)p);
    func_021FC1C0();
    func_021FFFE8(p,0,0);
    func_021FC2C0(p);
    func_021FC3E0((Work *)p);
    func_021FC360((char *)p);
    func_021FC8CC(*(void **)(p+0xB6C),*(void **)(p+0xB70),*(void **)(p+0xB68),(void **)(p+0xD90),func_020185F0(mon),p+0x1D0,p+0xFA0);
    func_021FCA8C(*(void **)(p+0xB6C),p+0xDAC,func_020084F4(*(void **)(*(u8 **)p+0x1C)),mon,p+0xDC0,p+0xFA0);
    index=func_021F886C(*(s8 *)(p+0x1D7),*(s8 *)(p+0x1D8),0);
    func_021F8290(*(void **)(p+0xB6C),*(void **)(p+0xB70),*(int *)(p+0xB68),p+0xDB4,*(s16 *)(p+0x1D4),*(s8 *)(p+0x1D6),index,p+0xFA0);
    func_021FCB54(mon);
    func_0202208C((void *)3,1,1,0,6,1,0x48);
    *(u32 *)(p+0x28)=0;
    *(u32 *)(p+0x12E4)=0;
    return 1;
}


/*
 * State-table dispatch through the table at 0x02203CF0.
 */
void func_021FC174(u8 *p)
{
    ((void (*)(u8 *))g_02203CF0[*(u32 *)(p + 0x28)])(p);
}


int func_021FC188(u8 *p) {func_021FC3D0(p);func_021FC568((char *)p);func_021FC4E4((char *)p);func_021FC2A4();func_022000E4((char *)p);func_0204B3DC(((struct Obj00287 *)p)->fD38,0);func_021F4EC8(p);return 0;}


/*
 * Three-layer bring-up after the display restore, with engine-B plane 0x16
 * toggled and layers 2 and 3 both 020414EC'd and tilemap-cleared.
 */
void func_021FC1C0(void)
{
    struct DispConfig c = g_022034AC;
    u32 v = func_02043668();

    func_0203FC28(&c);
    func_020435F4(v);
    func_02043598(0x16, 1);
    {
        struct BgTemplate t = g_022034DC;
        func_0203FCA0(2, &t, 0);
    }
    func_020414EC(2);
    func_02040588(2, 1);
    {
        struct BgTemplate t = g_022034BC;
        func_0203FCA0(1, &t, 0);
    }
    func_02040588(1, 1);
    {
        struct BgTemplate t = g_022034FC;
        func_0203FCA0(3, &t, 0);
    }
    func_020414EC(3);
    func_02040588(3, 1);
    func_02040B94(2, 0x20, 0, 0x48);
    func_02040B94(3, 0x20, 0, 0x48);
}


/*
 * Poke the channel-selection helper with 0, 1, 2, 3 in turn.
 */
void func_021FC2A4(void)
{
    sub_020403F4(0);
    sub_020403F4(1);
    sub_020403F4(2);
    sub_020403F4(3);
}


void func_021FC2C0(void *p)
{
    void *h;
    h = func_020490F4(0x60, 0x48);
    func_02049B68(h, 6, 0, 0, 0x60, 0x48);
    func_02049B40(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    func_0201F5BC(2, 1, 0xe, 0, 0x48);
    func_0201F5BC(2, 0x1f, 0xb, 0, 0x48);
    func_02049658(h, 0x10, 1, 0, 0, 1, 0x48);
    func_020498F4(h, 0x16, 1, 0, 0x600, 1, 0x48);
    func_02049B40(0x17, 5, 4, 0x20, 0x20, 0x48);
    func_02200B34(p);
    func_02049238(h);
}


void func_021FC360(char *p)
{
    ObjPos pos;
    func_02082BCC(&pos, 0, sizeof(pos));
    pos.x = 0xd0;
    pos.y = 0x3a;
    ((struct Obj03298 *)p)->fD08 = func_0204B294(((struct Obj03298 *)p)->fBC0, (unsigned int)((struct Obj03298 *)p)->fBC4, (unsigned int)((struct Obj03298 *)p)->fBC8, (unsigned int)((struct Obj03298 *)p)->fBCC, &pos, 0, 0x48);
    func_0204B92C(((struct Obj03298 *)p)->fD08, 1);
    func_0204B878(((struct Obj03298 *)p)->fD08, 0x24);
    func_0204B84C(((struct Obj03298 *)p)->fD08, 1);
    func_0204B3DC(((struct Obj03298 *)p)->fD08, 1);
    func_0203D34C(0, 0x48);
}


/*
 * Tail call into func_0204B3B4 with the pointer held at +0xd08.
 */
void func_021FC3D0(u8 *p)
{
    func_0204B3B4((struct Obj *)(((struct Obj18568 *)p)->fD08));
}


void func_021FC3E0(Work *p)
{
    int i;
    u32 w;
    p->frame=func_020450F0(2,(u8)2,(u8)21,(u8)27,2,13,(u16)1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->frame)),0);
    w=p->frame;
    func_02045334((struct Descriptor *)w);
    func_02045374((struct Cfg *)w);
    func_020409B4(func_02045730((struct Descriptor *)w));
    p->side=func_020450F0(2,(u8)21,(u8)15,(u8)10,4,13,(u16)1);
    w=p->side;
    func_02045334((struct Descriptor *)w);
    func_02045374((struct Cfg *)w);
    func_020409B4(func_02045730((struct Descriptor *)w));
    for(i=0;i<14;i++) {
        p->item_u14[i]=func_020450F0(3,(u8)tbl_0220351C[i].x,(u8)tbl_0220351C[i].y,(u8)tbl_0220351C[i].w,tbl_0220351C[i].h,13,(u16)1);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->item_u14[i])),0);
        w=p->item_u14[i];
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
    }
    func_02200BAC((u8 *)p,2);
}


/*
 * tail: 021FC526..021FC528 is two zero alignment bytes.
 */
void func_021FC4E4(char *p)
{
    int i;
    func_02202940((struct Obj *)(p + 0xfa0));
    func_020452E8(((struct Obj00287 *)p)->fDE0);
    func_020452E8(((struct Obj00287 *)p)->fD40);
    func_020452E8(((struct Obj00287 *)p)->fD50);
    for (i = 0; i < 14; i++) {
        func_020452E8(*(void **)(p + i * 4 + 0xd90));
    }
}


void func_021FC528(char *p)
{
    int i;
    ((struct Obj10585 *)p)->fB88 = func_020457B0(0xb4, 0x48);
    ((struct Obj10585 *)p)->fB8C = func_02045EC0(((struct Obj10585 *)p)->fB6C, 0x2d);
    for (i = 0; i < 10; i++) {
        *(void **)(p + i * 4 + 0xb90) = func_020457B0(0x14, 0x48);
    }
}


void func_021FC568(char *p) {int i;for(i=0;i<10;i++) func_02045808(*(struct U16Vec **)((unsigned)p+i*4+0xb90));func_02045808(*(struct U16Vec * *)&((struct Obj14170 *)p)->fB88);func_02045808(*(struct U16Vec * *)&((struct Obj14170 *)p)->fB8C);}


int func_021FC598(char *p) {((struct Obj23406 *)p)->f28=1;return 2;}


int func_021FC5A0(char *p)
{
    void *q;
    q = func_0200ADB4(**(void ** *)&((struct Obj00018 *)p)->f0);
    if ((func_020362DC() & 1) || func_02035C60()) {
        func_021FC810((u8 *)p, 5, 1, 0, 0xf0f, q);
        func_021F4E98((u8 *)p, 3, 7);
        func_020061E4(0x54c);
    } else if (func_020362DC() & 2) {
        *(int *)&((struct Obj00018 *)p)->f28 = 2;
        func_021F4EC0((u8 *)p, 1, 0);
        func_020061E4(0x551);
    }
    return 2;
}


int func_021FC610(u8 *p, int a1)
{
    func_0202208C((void *)3, 0, 0, 0, 6, 1, 0x48);
    ((struct Obj18569 *)p)->f28 = 0;
    return 3;
}


/*
 * Build, kick the two fixed helpers and latch state 6.
 */
int func_021FC638(u8 *p)
{
    func_021F4BF8(p, 0x14, 0x16a, 8, 2, 1);
    func_021F5060();
    func_021F5034(1);
    ((struct Obj02489 *)p)->f28 = 6;
    return 2;
}


/*
 * spelling: if/else keeps the first arm before the second compare; switch moved both compares ahead.
 */
int func_021FC668(char *p)
{
    unsigned r;
    r = func_021F4D14(p);
    if (r == 1) {
        func_021F4CE4(p);
        ((struct Obj08186 *)p)->f28 = 2;
        ((struct Obj08186 *)p)->fEB4 = 1;
        func_021F4EC0((u8 *)p, 7, 8);
        func_021FCBF0(p);
    } else if (r == 2) {
        func_021F4CE4(p);
        ((struct Obj08186 *)p)->f28 = 0;
        func_0201F7A8(((struct Obj08186 *)p)->fD40, 0);
        func_021FCBF0(p);
    }
    return 2;
}


int func_021FC6B8(char *p)
{
    ((struct Obj00448 *)p)->fDE8 = func_0201F81C(2, 0x48);
    func_0201F878(((struct Obj00448 *)p)->fDE8, (u32)(((struct Obj00448 *)p)->fB6C), 0x3d, 1, 0x48);
    func_0201F878(((struct Obj00448 *)p)->fDE8, (u32)(((struct Obj00448 *)p)->fB6C), 0x3e, 2, 0x48);
    func_021F4D50((u8 *)p, 2, 2, 0x14);
    func_021F5034(1);
    *(int *)&((struct Obj00448 *)p)->f28 = 8;
    return 2;
}


int func_021FC70C(char *p)
{
    int r;
    void *q;
    r = func_021F4E30((unsigned char *)p);
    if (r == 1) {
        func_021F4E64((unsigned char *)p);
        func_0201F868(((struct Obj00045 *)p)->fDE8);
        q = func_0200ADB4(**(void ** *)&((struct Obj00045 *)p)->f0);
        if (func_021F6DE8((unsigned int)q) && func_0201AA18(((struct Obj23409 *)(*(char * *)&((struct Obj00045 *)p)->f0))->f8) == 6) {
            func_021FC810((u8 *)p, 0x2a, 1, 0, 0xf0f, q);
            func_021F4E98((u8 *)p, 3, 1);
            return 2;
        }
        func_021FC810((u8 *)p, 6, 1, 0, 0xf0f, q);
        func_021F4E98((u8 *)p, 3, 5);
        func_021FCBF0(p);
    } else if (r == 2 || r == -2) {
        func_021F4E64((unsigned char *)p);
        func_0201F868(((struct Obj00045 *)p)->fDE8);
        *(int *)&((struct Obj00045 *)p)->f28 = 2;
        func_021F4EC0((u8 *)p, 1, 0);
        func_021FCBF0(p);
    }
    return 2;
}


int func_021FC7C4(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        ((struct Obj12210 *)p)->f28 = ((struct Obj12210 *)p)->f2C;
    }
    return 2;
}


/*
 * When the build query answers 0, bump the countdown at +0xdfc and roll state when it passes 0x2d.
 */
int func_021FC7E0(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        if (++((struct Obj07246 *)p)->fDFC > 0x2d) {
            ((struct Obj07246 *)p)->fDFC = 0;
            ((struct Obj07246 *)p)->f28 = ((struct Obj07246 *)p)->f2C;
        }
    }
    return 2;
}


/*
 * The two-parameter member of the 021F7538 family: an extra 0201EE84 call
 * keyed by the sixth argument, the same 0xb6c/0xb88 fields and the same
 * p+0xd40 window group in the other order.
 */
void func_021FC810(u8 *p, u32 b, u32 c, u32 d, u32 e, void *sel)
{
    u32 v;
    u32 h;

    func_0201EE84(((struct Obj00018 *)p)->fB68, 0, (void *)sel);
    v = (u32)sub_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00018 *)p)->fB6C), b);
    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00018 *)p)->fB68), (void *)(((struct Obj00018 *)p)->fB88), (void *)v);
    sub_02043B5C((struct CharBuf *)((u32)sub_02045770((struct Descriptor *)((struct Obj00018 *)p)->fD40)), 0xf);
    func_0201F73C((void *)(((struct Obj00018 *)p)->fD40), 0, 1, 0xe);
    h = ((struct Obj00018 *)p)->fD40;
    sub_02045334((struct Descriptor *)h);
    sub_02045374((struct Cfg *)h);
    sub_020409B4(unit_02045730(h));
    func_02202858((void *)(((struct Obj00018 *)p)->fD40), 0, (void *)(((struct Obj00018 *)p)->fB88), 0, 0, p + 0xfa0);
    sub_02045808((struct U16Vec *)v);
}


/*
 * Mode table: 0 -> 0, 1 -> 0x14c0, 2 -> 0xc80, anything else 0.
 */
u16 func_021FC8A8(int mode)
{
    switch (mode) {
    case 0:
        return 0;
    case 1:
        return 0x53 << 6;
    case 2:
        return 0x32 << 6;
    default:
        return 0;
    }
}
