/*
 * file:     worldtrade_box_p01.c
 * unit:     yes
 * function: func_021F4580, func_021F46A8, func_021F47C0, func_021F4864, func_021F4894, func_021F489C, func_021F49A4, func_021F49A8, func_021F49F8, func_021F4BCC, func_021F4BE0, func_021F4BF8, func_021F4CE4, func_021F4D14, func_021F4D50, func_021F4E30, func_021F4E64, func_021F4E98, func_021F4EA0, func_021F4EB4, func_021F4EC0, func_021F4EC8, func_021F4ED4, func_021F4EDC, func_021F4EFC, func_021F4F84, func_021F4F90, func_021F4FA4, func_021F4FC4, func_021F4FF4, func_021F5008, func_021F5034, func_021F5060, func_021F5074, func_021F50EC, func_021F513C, func_021F5154, func_021F51F0, func_021F5204, func_021F5250, func_021F5358, func_021F5374, func_021F5420, func_021F577C, func_021F57EC, func_021F5940, func_021F5980, func_021F59E8, func_021F5A18, func_021F5A7C, func_021F5B8C, func_021F5CA4, func_021F5CD4, func_021F5CFC, func_021F5E44, func_021F5F60, func_021F5F9C, func_021F5FC0, func_021F601C, func_021F6178, func_021F61D4, func_021F632C, func_021F6384, func_021F63A8, func_021F63EC, func_021F6418, func_021F643C, func_021F6474, func_021F651C, func_021F6548, func_021F656C, func_021F65C8, func_021F65E8, func_021F6604, func_021F663C, func_021F66C8, func_021F66F0, func_021F6748, func_021F6754, func_021F67A8
 * address:  0x021F4580
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
 *   func_02202608  0x02202608  thumb
 *   func_022026D8  0x022026D8  thumb
 *   g_02203F80  0x02203F80  data
 *   str_02203AF8  0x02203AF8  data  a1
 *   ov114_id  0x00000072  data
 *   ov067_id  0x00000043  data
 *   func_0203CD98 0x0203CD98 arm
 *   func_0205D074 0x0205D074 arm
 *   func_020370F4 0x020370F4 arm
 *   func_021C7C1C 0x021C7C1C arm ov114
 *   func_02031330 0x02031330 arm
 *   func_02030D28 0x02030D28 arm
 *   func_02202770 0x02202770 thumb ov135
 *   func_020221A4 0x020221A4 thumb
 *   func_021FF6A4 0x021FF6A4 thumb ov135
 *   func_021FFB20 0x021FFB20 thumb ov135
 *   func_0204A600 0x0204A600 arm
 *   d_02203A80 0x02203A80 data a4
 *   func_02045C04 0x02045C04 arm
 *   func_02030DA4 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0203133C 0x0203133C arm
 *   func_02202744 0x02202744 thumb ov135
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   str_02203B08  0x02203B08  data  a1
 *   func_020490F4  0x020490F4  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_02049F34  0x02049F34  arm
 *   DC_FlushRange  0x020862F0  arm
 *   GX_LoadOBJPltt 0x0207E51C  arm
 *   func_02008550  0x02008550  thumb
 *   func_0204AC18  0x0204AC18  arm
 *   d_02202BE0     0x02202BE0  data
 *   func_02034714 0x02034714 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02027F60 0x02027F60 thumb
 *   func_02027778 0x02027778 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   data_02202BC8 0x02202BC8 data a4
 *   func_02027858 0x02027858 thumb
 *   func_02027FD8 0x02027FD8 thumb
 *   func_02027974 0x02027974 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   data_02202C2C 0x02202C2C data a4
 *   func_0204B404  0x0204B404  arm
 *   func_0205CCD8  0x0205CCD8  arm
 *   sub_02012FFC  0x02012FFC  thumb  arm9
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
 *   func_02049B68 0x02049B68 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
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
 *   func_02030734 0x02030734 arm
 *   str_02203B54 0x02203B54 data a1
 *   func_021F6C48  0x021F6C48  thumb
 *   func_021F6BA4  0x021F6BA4  thumb
 *   func_021F6B40  0x021F6B40  thumb
 *   func_022025E4  0x022025E4  thumb
 *   func_021F6CDC  0x021F6CDC  thumb
 *   tbl_02202E24  0x02202E24  data  a1
 *   tbl_02202DA4  0x02202DA4  data  a1
 *   func_021F6BC4  0x021F6BC4  thumb
 *   func_021F6BFC  0x021F6BFC  thumb
 *   func_021F6C28  0x021F6C28  thumb
 *   func_021F6B34  0x021F6B34  thumb
 *   d_02203B68 0x02203B68 data a4
 *   func_021F6DE8  0x021F6DE8  thumb
 *   func_021F6D14  0x021F6D14  thumb
 *   func_02202840  0x02202840  thumb  ov135
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
 *   func_0201BABC  0x0201BABC  thumb
 *   func_02082B0C  0x02082B0C  arm
 *   func_0201BB5C  0x0201BB5C  thumb
 *   GX_LoadOBJ     0x0207E780  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_02017DBC  0x02017DBC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   func_0202136C  0x0202136C  thumb
 */
#include "../../matched/include/Obj02853.h"
#include "../../matched/include/Obj02854.h"
#include "../../matched/include/Obj02489.h"
#include "../../matched/include/Obj00045.h"
#include "worldtrade_types.h"
#include "../../matched/include/Obj00448.h"
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
#include "../../matched/include/Obj06507.h"
#include "../../matched/include/Obj18540.h"
#include "../../matched/include/Obj18541.h"
#include "../../matched/include/Obj18542.h"
#include "../../matched/include/Obj12196.h"
#include "../../matched/include/Obj12197.h"
#include "../../matched/include/Obj09227.h"

#define ASSERT(x) if (!(x)) func_02034714(str_02203B08, 0, str_02203B08)
struct Ctx;
struct MsgBank;
struct WordSet;
struct Obj0203159C;
struct Rec;
struct S020314B8;
struct S020315D4;
struct DispVram;
struct Cfg;
struct Sub0200852CObj;
struct Bank;
struct R;
struct U16Vec;
struct TaskMenu;
struct TaskMenuTmpl;
struct TaskMenuState;
struct Obj;
struct Vec2;
struct Descriptor;
struct Node;
struct Actor;
struct CharBuf;
struct Slot;
struct ArcFile;
struct NitroFileHeader;
struct Sav;
typedef struct {
    u8 pad0[0x20];
    u32 x20;
} Args_021F4580;

typedef struct { int (*init)(u8 *, int); int (*update)(u8 *, int); int (*finish)(u8 *, int); } Handler;

typedef volatile u32 vu32_021F4580;

typedef volatile u16 vu16;

typedef struct {
    u8 pad0[0xC];
    u16 *data;
} PlttData;

typedef void (*Fn)(void);

typedef struct { union { void *text; u32 a; }; u32 b, c; } BoxItem;

typedef struct { BoxItem item[2]; } BoxItems2;

typedef struct { u32 heap; u8 count,pad[3]; BoxItem *items; u32 mode; u8 a,b,c,d; } BoxMenu;

typedef struct { BoxItem item[3]; } BoxItems3;

typedef volatile u16 vu16_021F5074;

struct DispConfig {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

typedef volatile unsigned short vu16_021F50EC;

typedef volatile unsigned int vu32_021F4D50;

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
    u8 pad0[0x14];
    void *pixels;
} CharData_p02;

typedef struct {
    u32 vram;
    u32 pal;
    u32 f8;
    u8 pixels[0x200];
} IconRec_021F5E44;

typedef struct {
    u16 species;
    s8 f2;
    u8 f3;
} Info_p02;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
} IconRec_p02;

extern int func_02034AC4(s32 handle);
extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void *func_02202608(u32 heap);
extern void *func_02031324(int a0);
extern u32 func_02030CB0(u32 n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void func_022026D8(void *ctx, u32 arg);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_0204335C(u32 keep);
extern void func_02005DE4(void *p);
extern void func_02005D28(void);
extern int func_0203CD98(void);
extern int func_0205D074(void);
extern u32 func_020370F4(u32);
extern void func_021C7C1C(void);
extern u32 func_02031330(void *);
extern void func_02030D28(struct Ctx *c);
extern void func_02202770(void *);
extern u32 func_020221A4(void);
extern void func_021FF6A4(u8 *);
extern void func_021FFB20(u8 *, int, int);
extern void func_0204A600(void *);
extern unsigned int func_02045C04(struct Rec *rec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern void func_02030DA4(void *);
extern u32 func_020307B0(void *p);
extern void func_0203133C(struct S020314B8 *p);
extern void func_02202744(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_02034A5C(s32 handle);
extern void func_020419E4(void);
extern void func_0204A648(void);
extern void func_020433E0(const struct DispVram *c);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void DC_FlushRange(void *p, u32 size);
extern void GX_LoadOBJPltt(const void *src, u32 offset, u32 size);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void func_020434DC(u32 a, u32 b);
extern void func_02043598(u32 a, u32 b);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern void func_02027858(struct TaskMenu *m);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_02027974(void *);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern int func_0205CCD8(void);
extern signed char sub_02012FFC(void);
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
extern void *func_020056A0(void *callback, void *ctx, int a2);
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
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_02041570(int channel, u16 val);
extern void sub_020403F4(u32 i);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
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
extern void func_0204B9A0(struct Actor *a);
extern void func_020061E4(u32 se);
extern int func_021F6C48(void *party, void *save, int box, int slot);
extern int func_021F6BA4(void *party, void *save, int box, int slot);
extern void *func_021F6B40(void *party, void *save, int box, int slot);
extern void func_022025E4(u32 a, u32 b, u32 c);
extern int func_021F6CDC(void *mon, void *want);
extern int func_02035C08(const void *key);
extern void func_020355D8(u8 v);
extern u32 func_020362DC(void);
extern u32 func_0201F81C(u32 a, u32 b);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern u32 func_0201F868(void *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 func_021F6BC4(void *mon);
extern int func_021F6BFC(u32 handle);
extern int func_021F6C28(u32 handle);
extern int func_021F6B34(int v);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern int func_020179B8(int a0, int a1);
extern int func_021F6DE8(u32 handle);
extern u32 func_0201AA18(void *p);
extern void func_021F6D14(void *dst, Work *p);
extern u32 func_0204B98C(struct Actor *a);
extern u32 func_02202840(u8 *p);
extern int func_02035C60(void);
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
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern s32 func_02062A4C(struct NitroFileHeader *file, void **out);
extern u32 func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern void func_02082B0C(const void *src, void *dst, u32 n);
extern u32 func_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg);
extern u32 func_02018438(void *p);
extern void GX_LoadOBJ(const void *src, u32 offset, u32 size);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern u32 func_0202136C(u16 v);
int func_021F4580(void *proc, int *seq, Args_021F4580 *args);
int func_021F46A8(void *unused0, int *state, void *unused2, u8 *p);
int func_021F47C0(void *ctx, int unused1, int unused2, u8 *p);
void func_021F4864(void *unused, Work *p);
void func_021F4894(const struct DispVram *a0);
void func_021F489C(Work *p, Args *args);
void func_021F49A4(void *a0);
void func_021F49A8(void);
void func_021F49F8(Work *p, u32 mode);
void func_021F4BCC(u8 *p);
void func_021F4BE0(u32 a, u32 b, u32 c, u32 d, u8 e);
void func_021F4BF8(u8 *p,int b,int unused,int a,int c,u8 flag);
void func_021F4CE4(char *p);
int func_021F4D14(char *p);
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
void func_021F5074(Work *p);
void func_021F50EC(u8 *p);
void func_021F513C(u8 *p);
int func_021F5154(u8 *p);
void func_021F51F0(u8 *p);
int func_021F5204(u8 *p);
void func_021F5250(void);
void func_021F5358(void);
void func_021F5374(u8 *p);
void func_021F5420(Work *p);
void func_021F577C(u8 *p);
void func_021F57EC(Work *p);
void func_021F5940(u8 *p);
void func_021F5980(u8 *p);
void func_021F59E8(char *p);
int func_021F5A18(u8 *p);
void func_021F5A7C(Work *p);
void func_021F5B8C(Work *p);
int func_021F5CA4(Work *p);
void func_021F5CD4(u8 *p, u32 k);
int func_021F5CFC(Work *p);
void func_021F5E44(Work *p);
void func_021F5F60(u32 cursor, int i);
int func_021F5F9C(int a, int b, int c);
int func_021F5FC0(u8 *p);
int func_021F601C(Work *p);
int func_021F6178(u8 *p);
int func_021F61D4(Work *p);
int func_021F632C(u8 *p);
int func_021F6384(u8 *p);
int func_021F63A8(u8 *p);
int func_021F63EC(u8 *p);
int func_021F6418(u8 *p);
int func_021F643C(u8 *p);
int func_021F6474(Work *p);
int func_021F651C(u8 *p);
int func_021F6548(u8 *p);
int func_021F656C(Work *p);
int func_021F65C8(u8 *p);
int func_021F65E8(u8 *p);
int func_021F6604(u8 *p);
void func_021F663C(u8 *p, u32 b, u32 c, u32 d, u32 e, u32 sel);
u32 func_021F66C8(u32 a, u32 b, u32 c, u32 d);
void func_021F66F0(u32 species, u32 form, u32 gender, u32 isEgg, u32 slot, u32 f8, u32 arc, IconRec_021F5E44 *rec);
void func_021F6748(u32 a, u8 *q);
void func_021F6754(Work *p);
void func_021F67A8(void *mon, u32 icon, u32 item_spr, u16 *species, u32 slot, u32 arc, Info_p02 *info, IconRec_p02 *rec);
extern u8 ov114_id[];
extern u8 ov067_id[];
extern Work *g_02203F80;
extern const char str_02203AF8[];
extern const Handler d_02203A80[];
extern const char str_02203B08[];
extern u8 d_02202BE0[];
extern const BoxItems2 data_02202BC8;
extern const BoxItems3 data_02202C2C;
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
extern const u8 tbl_02202DA4[][4];
extern const char d_02203B68[];



int func_021F4580(void *proc, int *seq, Args_021F4580 *args)
{
    Work *p;

    func_02034AC4((u32)ov114_id);
    func_02034AC4((u32)ov067_id);
    func_0203064C(1, 0x48, 0x30100);
    p = func_0203159C(proc, sizeof(Work), 0x48);
    func_02082BCC(p, 0, sizeof(Work));
    g_02203F80 = p;
    p->fEA8 = func_02202608(0x48);
    p->f12F0 = func_02031324(0x48);
    p->recMem = func_02030734(0x48, func_02030CB0(8), 0, str_02203AF8, 0xA1);
    p->rec_p = func_02030CBC(8, p->recMem);
    func_022026D8(p->tail, args->x20);
    p->words = func_0201EC74(0xB, 0x40, 0x48);
    p->msg[0] = func_02045B38(0, 2, 0xD0, 0x48);
    p->msg[2] = func_02045B38(0, 2, 0xD1, 0x48);
    p->msg[3] = func_02045B38(0, 2, 0xE8, 0x48);
    p->msg[1] = func_02045B38(0, 2, 0x46, 0x48);
    p->msg[4] = func_02045B38(0, 2, 0xE7, 0x48);
    func_021F489C((Work *)p, (Args *)args);
    func_0204335C(0);
    func_021F5074(p);
    func_02005DE4(0);
    func_02005D28();
    return 1;
}



int func_021F46A8(void *unused0, int *state, void *unused2, u8 *p)
{
    if (func_0203CD98() != 0) {
        func_0205D074();
        func_020370F4(func_021F4EB4());
    }
    func_021C7C1C();
    ((struct Obj02853 *)p)->f12F4 = func_02031330(((struct Obj02853 *)p)->f12F0);
    func_02030D28(((struct Obj02853 *)p)->fF94);
    func_02202770(p + 0xfa0);
    switch (*state) {
    case 0:
        *state = d_02203A80[*(u32 *)(p + 16)].init(p, *state);
        func_021F49A8();
        break;
    case 1:
        if (func_020221A4() != 0) *state = 2;
        break;
    case 2:
        *state = d_02203A80[*(u32 *)(p + 16)].update(p, *state);
        break;
    case 3:
        if (func_020221A4() != 0) {
            *state = d_02203A80[*(u32 *)(p + 16)].finish(p, *state);
            if (((struct Obj02853 *)p)->fB8 != 0) {
                func_021FF6A4(p);
                func_021FFB20(p, ((struct Obj02853 *)p)->fD0, 0);
                ((struct Obj02853 *)p)->fB8 = 0;
            }
        }
        break;
    case 4:
        *state = 5;
        break;
    case 5:
        return 1;
    }
    func_021F4F84(p);
    if (*(u32 *)&((struct Obj02853 *)p)->fBC0 != 0) func_0204A600(((struct Obj02853 *)p)->fBC0);
    if (((struct Obj02853 *)p)->f12E8 > 0) ((struct Obj02853 *)p)->f12E8 -= 1;
    return 0;
}



int func_021F47C0(void *ctx, int unused1, int unused2, u8 *p)
{
    func_02005D28();
    func_021F50EC(p);
    func_021F49A4(p);
    func_02045C04(((struct Obj02854 *)p)->fB70);
    func_02045C04(((struct Obj02854 *)p)->fB78);
    func_02045C04(((struct Obj02854 *)p)->fB74);
    func_02045C04(((struct Obj02854 *)p)->fB6C);
    func_02045C04(((struct Obj02854 *)p)->fB7C);
    func_0201ED04(((struct Obj02854 *)p)->fB68);
    func_02030DA4(((struct Obj02854 *)p)->fF94);
    func_020307B0(((struct Obj02854 *)p)->fF9C);
    func_0203133C(((struct Obj02854 *)p)->f12F0);
    func_020307B0(((struct Obj02854 *)p)->fEA8);
    func_02202744(p + 0xfa0);
    func_020315D4(ctx);
    func_020306F0(0x48);
    func_02034A5C((unsigned int)ov067_id);
    func_02034A5C((unsigned int)ov114_id);
    return 1;
}



void func_021F4864(void *unused, Work *p)
{
    func_020419E4();
    func_0204A648();
    if (p->once != 0) {
        p->once(p);
        p->once = 0;
    }
    if (p->every != 0) {
        p->every(p);
    }
}



void func_021F4894(const struct DispVram *a0)
{
    func_020433E0(a0);
}



void func_021F489C(Work *p, Args *args)
{
    ASSERT(args->a3C);
    ASSERT(args->a0);
    ASSERT(args->a4);
    ASSERT(args->a8);
    ASSERT(args->aC);
    ASSERT(args->a14);
    ASSERT(args->a18);
    ASSERT(args->a1C);
    ASSERT(args->a20);
    ASSERT(args->a24);
    p->args = args;
    p->x10 = 0;
    func_021F4EC0((u8 *)p, 0, 0x13);
    p->sel = 0;
    p->sel_h = 0;
    p->xB58 = 3;
    p->xB59 = 0;
    p->xB5A = 0;
    p->xB5C = 0;
    p->active = 0;
    p->box = 0xFF;
    p->species = 0;
    p->xEB2 = 0;
    p->fE1A = 0;
    p->xDF8 = 0;
    p->fF84 = 0;
}



/*
 * Empty stub: a bare `bx lr`, the overlay's no-op placeholder body.
 */
void func_021F49A4(void *a0)
{
}



static inline void SetWnd0InsidePlane(int wnd, int effect)
{
    u32 tmp = (*(vu16 *)0x04000048 & ~0x3F) | wnd;

    if (effect) {
        tmp |= 0x20;
    }
    *(vu16 *)0x04000048 = (u16)tmp;
}



static inline void SetWndOutsidePlane(int wnd, int effect)
{
    u32 tmp = (*(vu16 *)0x0400004A & ~0x3F) | wnd;

    if (effect) {
        tmp |= 0x20;
    }
    *(vu16 *)0x0400004A = (u16)tmp;
}



void func_021F49A8(void)
{
    *(vu32_021F4580 *)0x04001000 &= ~0xE000;
    *(vu32_021F4580 *)0x04000000 = (*(vu32_021F4580 *)0x04000000 & ~0xE000) | 0x2000;
    SetWnd0InsidePlane(0x1F, 0);
    SetWndOutsidePlane(0x1F, 1);
    *(vu16 *)0x04000040 = 0xF0FF;
    *(vu16 *)0x04000044 = 0x10;
}



/*
 * Load the screen's OBJ resources: the archive-0x60 cell, character,
 * palette and animation sets into the resource block at +0xBC0, the
 * OBJ palette from archive 7 at 0xA0 and a half-brightness copy of it
 * at 0x100, and from archive 0x1F the version-dependent set (files
 * 0x11/6/0xF/0x10 when func_02008550 reports 1, else 0xE/4/0xC/0xD).
 */
void func_021F49F8(Work *p, u32 mode)
{
    void *arc;
    void *buf;
    PlttData *pd;
    int i;
    u16 *d;
    u32 anm;
    u32 cell;
    u32 pal;
    u32 chr;

    arc = func_020490F4(0x60, 0x48);
    func_0204A48C((const struct Cfg *)d_02202BE0, mode, 0x48);
    p->res_res.f0 = (u32)func_0204B100(0x60, 0, 0x48);
    p->res_res.f4 = func_0204A6C8(arc, 0x11, 1, 0, 0x48);
    p->res_res.f8 = func_0204ABF0(arc, 8, 0, 0, 0x48);
    p->res_res.fC = func_0204AF28(arc, 0x12, 0x13, 0x48);
    p->res_res.f28 = func_0204A6C8(arc, 0x27, 1, 0, 0x48);
    p->res_res.f30 = func_0204AF28(arc, 0x28, 0x29, 0x48);
    p->res_res.f10 = func_0204A6C8(arc, 0x24, 1, 1, 0x48);
    p->res_res.f14 = func_0204ABF0(arc, 7, 1, 0, 0x48);
    p->res_res.f18 = func_0204AF28(arc, 0x25, 0x26, 0x48);
    func_02049238(arc);

    buf = func_02049F34(7, 0, (u32)(&pd), 0x48);
    DC_FlushRange(pd->data, 0x60);
    GX_LoadOBJPltt(pd->data, 0xA0, 0x60);
    d = pd->data;
    for (i = 0; i < 0x30; i++) {
        u16 c = d[i];
        d[i] = ((((c >> 10) & 0x1f) / 2) << 10) | ((((c >> 5) & 0x1f) / 2) << 5) | ((c & 0x1f) / 2);
    }
    DC_FlushRange(pd->data, 0x60);
    GX_LoadOBJPltt(pd->data, 0x100, 0x60);
    func_020307B0(buf);

    if ((u8)(u32)func_02008550(p->ctx->f1C) == 1) {
        chr = 0x11;
        anm = 0x10;
        cell = 0xF;
        pal = 6;
    } else {
        chr = 0xE;
        anm = 0xD;
        cell = 0xC;
        pal = 4;
    }
    arc = func_020490F4(0x1f, 0x48);
    p->res_res.f1C = func_0204A6C8(arc, chr, 0, 1, 0x48);
    p->res_res.f20 = func_0204AC18(arc, pal, 1, 0, 0, 1, 0x48);
    p->res_res.f24 = func_0204AF28(arc, cell, anm, 0x48);
    func_02049238(arc);
}



/*
 * Release the 0x10 channel on both hardware blocks.
 */
void func_021F4BCC(u8 *p)
{
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}



/*
 * Forward four register arguments plus a zero and the u8 stack argument.
 */
void func_021F4BE0(u32 a, u32 b, u32 c, u32 d, u8 e)
{
    func_021F4BF8((u8 *)a, b, c, d, 0, e);
}



void func_021F4BF8(u8 *p,int b,int unused,int a,int c,u8 flag)
{
    BoxItems2 items;
    BoxMenu menu;
    int on;
    if (*(u32 *)&((struct Obj02489 *)p)->fE04) func_02034714(str_02203B08,0,str_02203B08);
    if (*(u32 *)&((struct Obj02489 *)p)->fE08) func_02034714(str_02203B08,0,str_02203B08);
    ((struct Obj02489 *)p)->fE04=func_02027F60((u8)c,(u8)a,((struct Obj02489 *)p)->fFA0,((struct Obj02489 *)p)->fFAC,0x48);
    items=data_02202BC8;
    on=0;
    func_02082BCC(&menu,0,20);
    items.item[0].text=func_02045EC0(((struct Obj02489 *)p)->fB6C,63);
    items.item[1].text=func_02045EC0(((struct Obj02489 *)p)->fB6C,64);
    menu.heap=0x48;
    menu.count=2;
    menu.items=items.item;
    menu.mode=1;
    menu.a=0x20;
    menu.b=b;
    menu.c=8;
    menu.d=3;
    ((struct Obj02489 *)p)->fE08=func_02027778((struct TaskMenuTmpl *)(&menu),((struct Obj02489 *)p)->fE04);
    func_02045808(items.item[0].text);
    func_02045808(items.item[1].text);
    if (flag) {
        if(c<=3) on=1;
        func_021F5008(on);
    }
}



void func_021F4CE4(char *p) { if(((struct Obj00045 *)p)->fE08) { func_02027858(((struct Obj00045 *)p)->fE08); ((struct Obj00045 *)p)->fE08=0; } if(((struct Obj00045 *)p)->fE04) { func_02027FD8(((struct Obj00045 *)p)->fE04); ((struct Obj00045 *)p)->fE04=0; } }



int func_021F4D14(char *p) { int result; result=0; if(((struct Obj00045 *)p)->fE08) { func_02027974(((struct Obj00045 *)p)->fE08); if(func_020279E8(((struct Obj00045 *)p)->fE08)) { result=func_02027A04(((struct Obj00045 *)p)->fE08); if(result==0) result=1; else if(result==1) result=2; func_021F5060(); } } return result; }



void func_021F4D50(u8 *p, u16 a, int count, int b)
{
    BoxItems3 items;
    BoxMenu menu;
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
 * Send a one-entry u16 table {b, c}
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
    func_021F49F8((Work *)p, (u32)g_02202BFC);
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



void func_021F5074(Work *p)
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
    if (p->vblank_p == 0) {
        p->vblank_p = func_020056A0(func_021F4864, p, 0);
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
    *(vu32_021F4D50 *)0x04000000 &= 0xFFFF1FFF;
    *(vu32_021F4D50 *)0x04001000 &= 0xFFFF1FFF;
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
    func_021F57EC((Work *)p);
    func_021F5420((Work *)p);
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



void func_021F5420(Work *p)
{
    Local s;
    int i;

    func_02082BCC(&s, 0, 8);
    s.a = tbl_02202D24[p->slot].x;
    s.b = tbl_02202D24[p->slot].y;
    p->sub.f34 = (u32)func_0204B294((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
    func_0204B92C((struct Obj *)p->sub.f34, 1);
    func_0204B878((struct Obj *)p->sub.f34, 4);
    if (func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)p->sub.f34, 0);
    } else {
        func_0204B3DC((struct Obj *)p->sub.f34, 1);
    }
    if (p->slot == 0x1f || p->slot <= 5) {
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
        p->arrows[i] = (u32)func_0204B294((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
        func_0204B878((struct Obj *)p->arrows[i], i + 0x26);
        func_0204B84C(p->arrows[i], 1);
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



void func_021F57EC(Work *p)
{
    void *w;

    p->fD4C = (void *)func_020450F0(3, 4, 0, 0xD, 3, 0xD, 1);
    func_02043B5C(func_02045770(p->fD4C), 0);
    w = p->fD4C;
    func_02045334(w);
    func_02045374(w);
    func_020409B4(func_02045730(w));

    p->d40 = (void *)func_020450F0(0, 2, 0x15, 0x1B, 2, 0xD, 1);
    func_02043B5C(func_02045770(p->d40), 0);
    w = p->d40;
    func_02045334(w);
    func_02045374(w);
    func_020409B4(func_02045730(w));

    p->dd0 = (void *)func_020450F0(0, 2, 0x13, 0x1B, 4, 0xD, 1);
    func_02043B5C(func_02045770(p->dd0), 0);
    w = p->d40;
    func_02045334(w);
    func_02045374(w);
    func_020409B4(func_02045730(w));

    p->win3 = (void *)func_020450F0(1, 0x18, 0x10, 6, 2, 0, 1);
    func_02043B5C(func_02045770(p->win3), 4);
    w = p->win3;
    func_02045334(w);
    func_02045374(w);
    func_020409B4(func_02045730(w));

    func_021F91A0(p->win3, (u32)p->strs, 0, 1, 1, 0x3DC4, (u32)p->fFA0);
    if (p->kind == 5) {
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



void func_021F5A7C(Work *p)
{
    if (p->slot == 0x1E) {
        func_0204B3DC((struct Obj *)p->cursor_u, 1);
        func_0204B9A0((struct Actor *)p->cursor_u);
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
            func_022025E4((u32)p->words, 0, (u32)func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot));
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



void func_021F5B8C(Work *p)
{
    void *mon;

    if (p->slot == 0x1E) {
        func_0204B3DC((struct Obj *)p->cursor_u, 1);
        func_0204B9A0((struct Actor *)p->cursor_u);
        p->state = 0x11;
        return;
    }
    if (p->slot == 0x1F) {
        return;
    }
    switch (func_021F6C48(p->ctx->party, p->ctx->save, p->box, p->slot)) {
    case 1:
        mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
        if (func_021F6CDC(mon, p->arr_entry1[p->cur].key) != 0) {
            if (func_021F6BA4(p->ctx->party, p->ctx->save, p->box, p->slot) != 0) {
                func_022025E4((u32)p->words, 0, (u32)mon);
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



int func_021F5CA4(Work *p)
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



int func_021F5CFC(Work *p)
{
    int r = func_021F5CA4((Work *)p);

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
            func_0204B3DC((struct Obj *)p->cursor_u, 1);
            func_0204B9A0((struct Actor *)p->cursor_u);
            p->state = 0x11;
            p->slot = r;
            func_020061E4(0x551);
            func_021F5F60(p->cursor, p->slot);
            break;
        default:
            p->slot = r;
            func_021F5F60(p->cursor, p->slot);
            if (p->kind == 5) {
                func_021F5A7C((Work *)p);
            } else if (p->kind == 6) {
                func_021F5B8C((Work *)p);
            }
            break;
        }
    } else {
        func_021F5E44((Work *)((Work *)p));
        if (p->kind == 5) {
            if (func_020362DC() & 2) {
                func_0204B3DC((struct Obj *)p->cursor_u, 1);
                func_0204B9A0((struct Actor *)p->cursor_u);
                p->state = 0x11;
                func_020061E4(0x551);
            } else if (func_020362DC() & 1) {
                func_021F5A7C((Work *)p);
            }
        } else if (p->kind == 6) {
            if (func_020362DC() & 2) {
                func_0204B3DC((struct Obj *)p->cursor_u, 1);
                func_0204B9A0((struct Actor *)p->cursor_u);
                p->state = 0x11;
                func_020061E4(0x551);
            } else if (func_020362DC() & 1) {
                func_021F5B8C((Work *)p);
            }
        }
    }
    return 2;
}



void func_021F5E44(Work *p)
{
    int moved = 0;
    int dir = 0;
    u8 k;

    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)p->cursor, 1);
        func_020355D8(moved);
        func_020061E4(0x548);
        return;
    }
    if (func_020362DC() & 0x40) {
        dir = 1;
    } else if (func_020362DC() & 0x80) {
        dir = 2;
    } else if (func_020362DC() & 0x20) {
        dir = 3;
    } else if (func_020362DC() & 0x10) {
        dir = 4;
    }
    if (dir != 0) {
        dir = tbl_02202DA4[p->slot][dir - 1];
        if (dir != p->slot) {
            if (dir == 0x63 || dir == 0x65) {
                k = dir == 0x65 ? 0 : 1;
                func_0204B92C((struct Obj *)p->arrows[k], 1);
                func_0204B878((struct Obj *)p->arrows[k], k + 0x26);
                p->box = func_021F5F9C(p->box, p->boxes, dir - 0x64);
                func_021F68A4((u8 *)((Work *)p), p->box);
                func_020061E4(0x548);
            } else {
                moved = 1;
                p->slot = dir;
            }
        }
    }
    if (moved) {
        func_020061E4(0x548);
    }
    func_021F5F60(p->cursor, p->slot);
}



void func_021F5F60(u32 cursor, int i)
{
    func_021F4FF4(cursor, tbl_02202D24[i].x, tbl_02202D24[i].y);
    if (i == 0x1F || (i >= 0 && i <= 5)) {
        func_0204B84C(cursor, 0);
    } else {
        func_0204B84C(cursor, 1);
    }
}



/*
 * Byte-index arithmetic with 0xff as the out-of-range marker.
 */
int func_021F5F9C(int a, int b, int c)
{
    if (a == 0xff) {
        if (c > 0) {
            return 0;
        }
        if (c < 0) {
            return b - 1;
        }
        return a;
    }
    a += c;
    if (a < 0) {
        return 0xff;
    }
    if (a == b) {
        return 0xff;
    }
    return a;
}



/*
 * Create the resource, register the three 68/69/6a entries and latch state 0x8.
 */
int func_021F5FC0(u8 *p)
{
    *(u32 *)&((struct Obj00448 *)p)->fDE8 = func_0201F81C(3, 0x48);
    func_0201F878((struct Slot *)(*(u32 *)&((struct Obj00448 *)p)->fDE8), *(u32 *)&((struct Obj00448 *)p)->fB6C, 0x68, 1, 0x48);
    func_0201F878((struct Slot *)(*(u32 *)&((struct Obj00448 *)p)->fDE8), *(u32 *)&((struct Obj00448 *)p)->fB6C, 0x69, 2, 0x48);
    func_0201F878((struct Slot *)(*(u32 *)&((struct Obj00448 *)p)->fDE8), *(u32 *)&((struct Obj00448 *)p)->fB6C, 0x6a, 3, 0x48);
    func_021F4D50(p, 0, 3, 0x14);
    ((struct Obj00448 *)p)->f28 = 0x8;
    return 2;
}



int func_021F601C(Work *p)
{
    void *mon;

    switch (func_021F4E30((u8 *)p)) {
    case 1:
        func_021F4E64((u8 *)p);
        func_0201F868(p->de8);
        func_0201F7A8(p->d40, 0);
        p->state = 2;
        func_021F4EC0((u8 *)p, 8, 5);
        break;
    case 2:
        func_021F4E64((u8 *)p);
        func_0201F868(p->de8);
        mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
        if (func_021F6BC4(mon) != 0) {
            func_021F663C((u8 *)p, 0x2B, 1, 0, 0xF0F, 1);
            func_021F4E98((u8 *)p, 4, 1);
        } else if (func_021F6BFC((u32)mon) != 0) {
            if (func_021F6BFC((u32)mon) == 1) {
                func_021F663C((u8 *)p, 0xBF, 1, 0, 0xF0F, 1);
            } else {
                func_021F663C((u8 *)p, 0xC0, 1, 0, 0xF0F, 1);
            }
            func_021F4E98((u8 *)p, 4, 1);
        } else if (func_021F6C28((u32)mon) != 0) {
            func_021F663C((u8 *)p, 0xC1, 1, 0, 0xF0F, 1);
            func_021F4E98((u8 *)p, 4, 1);
        } else {
            if (func_021F6B34(p->box) != 0) {
                func_0201AB28(p->ctx->party, p->slot);
            }
            p->mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
            p->state = 2;
            func_021F4EC0((u8 *)p, 6, 0);
        }
        break;
    case 3:
    case (u32)-2:
        func_021F4E64((u8 *)p);
        func_0201F868(p->de8);
        func_0201F7A8(p->d40, 0);
        p->state = 0;
        break;
    }
    return 2;
}



/*
 * Create the resource, register the three 5d/5e/5f entries and latch state 0xa.
 */
int func_021F6178(u8 *p)
{
    *(u32 *)&((struct Obj00448 *)p)->fDE8 = func_0201F81C(3, 0x48);
    func_0201F878((struct Slot *)(*(u32 *)&((struct Obj00448 *)p)->fDE8), *(u32 *)&((struct Obj00448 *)p)->fB6C, 0x5d, 1, 0x48);
    func_0201F878((struct Slot *)(*(u32 *)&((struct Obj00448 *)p)->fDE8), *(u32 *)&((struct Obj00448 *)p)->fB6C, 0x5e, 2, 0x48);
    func_0201F878((struct Slot *)(*(u32 *)&((struct Obj00448 *)p)->fDE8), *(u32 *)&((struct Obj00448 *)p)->fB6C, 0x5f, 3, 0x48);
    func_021F4D50(p, 0, 3, 0x14);
    ((struct Obj00448 *)p)->f28 = 0xa;
    return 2;
}



int func_021F61D4(Work *p)
{
    void *mon;

    switch (func_021F4E30((u8 *)p)) {
    case 1:
        func_021F4E64((u8 *)p);
        func_0201F868(p->de8);
        p->state = 2;
        func_021F4EC0((u8 *)p, 8, 6);
        break;
    case 2:
        func_021F4E64((u8 *)p);
        func_0201F868(p->de8);
        func_0201F7A8(p->d40, 0);
        mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
        if (func_021F6BC4(mon) != 0) {
            func_021F663C((u8 *)p, 0x2B, 1, 0, 0xF0F, 1);
            func_021F4E98((u8 *)p, 4, 1);
        } else if (func_021F6BFC((u32)mon) != 0) {
            if (func_021F6BFC((u32)mon) == 1) {
                func_021F663C((u8 *)p, 0xBF, 1, 0, 0xF0F, 1);
            } else {
                func_021F663C((u8 *)p, 0xC0, 1, 0, 0xF0F, 1);
            }
            func_021F4E98((u8 *)p, 4, 1);
        } else if (func_021F6C28((u32)mon) != 0) {
            func_021F663C((u8 *)p, 0xC1, 1, 0, 0xF0F, 1);
            func_021F4E98((u8 *)p, 4, 1);
        } else {
            if (func_021F6B34(p->box) != 0) {
                func_0201AB28(p->ctx->party, p->slot);
            }
            if (func_02017E88(mon, 5, 0) == 0x1EC) {
                func_020179B8((int)mon, 0);
            }
            func_021F6474((Work *)((Work *)p));
        }
        break;
    case 3:
    case (u32)-2:
        func_021F4E64((u8 *)p);
        func_0201F868(p->de8);
        func_0201F7A8(p->d40, 0);
        p->state = 0;
        break;
    }
    return 2;
}



int func_021F632C(u8 *p)
{
    if (((struct Obj06507 *)p)->f14 == 0 || ((struct Obj06507 *)p)->f14 == 8 || ((struct Obj06507 *)p)->f14 == 3) {
        func_0202208C(0, 0, 0, 0, 6, 1, 0x48);
        ((struct Obj06507 *)p)->fEB4 = 1;
    } else {
        func_0202208C((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    ((struct Obj06507 *)p)->f28 = 0;
    return 3;
}



/*
 * State setter: build with the fixed 0x14/0x1ad/0x8/0x1 argument pair and latch state 0x6.
 */
int func_021F6384(u8 *p)
{
    func_021F4BE0((u32)p, 0x14, 0x1ad, 0x8, 0x1);
    ((struct Obj18540 *)p)->f28 = 0x6;
    return 2;
}



int func_021F63A8(u8 *p)
{
    unsigned result = func_021F4D14((char *)p);
    func_02034714(d_02203B68, 0, d_02203B68);
    if (result == 1) {
        func_021F4CE4((char *)p);
        ((struct Obj00045 *)p)->f28 = 2;
        func_021F4EC0(p, 0, 0);
    } else if (result == 2) {
        func_021F4CE4((char *)p);
        ((struct Obj00045 *)p)->f28 = 0;
    }
    return 2;
}



/*
 * Build through func_021F663C and publish the 3/0xc pair.
 */
int func_021F63EC(u8 *p)
{
    func_021F663C(p, 0x19, 1, 0, 0xf0f, 1);
    func_021F4E98(p, 3, 0xc);
    return 2;
}



/*
 * State setter: build with the fixed 0x12/0x1ad/0x8/0x1 argument pair and latch state 0xd.
 */
int func_021F6418(u8 *p)
{
    func_021F4BE0((u32)p, 0x12, 0x1ad, 0x8, 0x1);
    ((struct Obj18541 *)p)->f28 = 0xd;
    return 2;
}



/*
 * Two-way mode dispatch: mode 1 clears and runs the sub-step, mode 2 clears, releases the +0xdd0 word and latches state 1.
 */
int func_021F643C(u8 *p)
{
    u32 k = func_021F4D14((char *)p);

    if (k == 1) {
        func_021F4CE4((char *)p);
        func_021F6474((Work *)((Work *)p));
    } else if (k == 2) {
        func_021F4CE4((char *)p);
        func_0201F7A8((void *)(*(u32 *)&((struct Obj00045 *)p)->fDD0), 0);
        ((struct Obj00045 *)p)->f28 = 1;
    }
    return 2;
}



int func_021F6474(Work *p)
{
    if (func_021F6DE8((u32)p->list[p->cur]) != 0 && p->box != 0xFF
        && func_0201AA18(p->ctx->party) == 6) {
        func_021F663C((u8 *)p, 0x29, 1, 0, 0xF0F, 1);
        func_021F4E98((u8 *)p, 4, 1);
        return 0;
    }
    p->mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
    p->state = 2;
    p->eb4 = 1;
    func_021F4EC0((u8 *)p, 7, 9);
    func_021F6D14(p->ent, p);
    p->d0 = 0;
    return 1;
}



int func_021F651C(u8 *p)
{
    func_021F663C(p, 0x19, 1, 0, 0xf0f, 1);
    func_021F4E98(p, 3, 0xf);
    return 2;
}



/*
 * State setter: build with the fixed 0x12/0x1ad/0x8/0x1 argument pair and latch state 0x10.
 */
int func_021F6548(u8 *p)
{
    func_021F4BE0((u32)p, 0x12, 0x1ad, 0x8, 0x1);
    ((struct Obj18542 *)p)->f28 = 0x10;
    return 2;
}



int func_021F656C(Work *p)
{
    unsigned result = func_021F4D14((char *)p);
    if (result == 1) {
        func_021F4CE4((char *)p);
        p->mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
        p->state_un = 2;
        func_021F4EC0((u8 *)p, 6, 0);
    } else if (result == 2) {
        func_021F4CE4((char *)p);
        func_0201F7A8(p->dd0, 0);
        p->state_un = 1;
    }
    return 2;
}



/*
 * While the +0xbfc buffer is free, feed the mode word at +0x20 to the dispatch.
 */
int func_021F65C8(u8 *p)
{
    if (func_0204B98C((struct Actor *)(((struct Obj12196 *)p)->fBFC)) == 0) {
        func_021F5CD4(p, ((struct Obj12196 *)p)->f20);
    }
    return 2;
}



/*
 * When the sub-object at +0xfa0 is idle, re-arm the state word from +0x2c.
 */
int func_021F65E8(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        ((struct Obj12197 *)p)->f28 = ((struct Obj12197 *)p)->f2C;
    }
    return 2;
}



/*
 * When the build query answers 0 and either probe is set, release the +0xdd0 word and roll the state.
 */
int func_021F6604(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        if (func_020362DC() != 0 || func_02035C60() != 0) {
            func_0201F7A8((void *)(((struct Obj09227 *)p)->fDD0), 0);
            ((struct Obj09227 *)p)->f28 = ((struct Obj09227 *)p)->f2C;
        }
    }
    return 2;
}



/*
 * Window teardown: the handle is the 0xd40 or 0xdd0 window selected by the
 * sixth argument, and that one handle is used by every call in the body.
 */
void func_021F663C(u8 *p, u32 b, u32 c, u32 d, u32 e, u32 sel)
{
    u32 v = (u32)sub_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00018 *)p)->fB6C), b);
    u32 h;

    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00018 *)p)->fB68), (void *)(((struct Obj00018 *)p)->fB88), (void *)v);
    h = *(u32 *)(p + (sel == 0 ? 0xd40 : 0xdd0));
    sub_02043B5C((struct CharBuf *)((u32)sub_02045770((struct Descriptor *)h)), 0xf);
    sub_02045334((struct Descriptor *)h);
    sub_02045374((struct Cfg *)h);
    sub_020409B4(unit_02045730(h));
    func_0201F73C((void *)h, 0, 1, 0xe);
    func_02202858((void *)h, 0, (void *)(((struct Obj00018 *)p)->fB88), 0, 0, p + 0xfa0);
    sub_02045808((struct U16Vec *)v);
}



u32 func_021F66C8(u32 a, u32 b, u32 c, u32 d)
{
    u32 blk = (u32)func_02049250((struct ArcFile *)a, b, (u16)d);

    if (blk != 0 && func_02062A4C((struct NitroFileHeader *)blk, (void **)c) == 0) {
        func_020307B0((void *)blk);
        return 0;
    }
    return blk;
}



/*
 * Load the icon graphics of a Pokemon (species, form, gender/half, egg)
 * from the archive handle and copy its 0x200 bytes into the sprite
 * record: +0 gets the VRAM offset of slot `slot`, +4 the icon palette
 * (func_0201BB5C + 5), +8 `pal`, the pixels go to +0xC.
 */
void func_021F66F0(u32 species, u32 form, u32 gender, u32 isEgg, u32 slot, u32 f8, u32 arc, IconRec_021F5E44 *rec)
{
    CharData_p02 *cd;
    void *buf = (void *)func_021F66C8(arc, func_0201BABC(species, form, gender, isEgg), (u32)(&cd), 0x48);

    func_02082B0C(cd->pixels, rec->pixels, 0x200);
    rec->vram = (slot * 16 + 0x1c) * 32;
    rec->f8 = f8;
    rec->pal = func_0201BB5C(species, form, gender, isEgg) + 5;
    func_020307B0(buf);
}



/*
 * Store the query byte at +3 of the second argument.
 */
void func_021F6748(u32 a, u8 *q)
{
    q[3] = func_02018438((void *)a);
}



/*
 * Deferred icon upload (installed at +0xEBC by func_021F68A4): for each
 * of the 30 icon records at +0xEB8 that has a sprite (+8), flush and
 * load its 0x200 pixel bytes to its OBJ VRAM offset and set the sprite's
 * palette; then free the record block.
 */
void func_021F6754(Work *p)
{
    int i;
    IconRec *e;

    e = p->icons;
    for (i = 0; i < 30; i++, e++) {
        if (e->spr != 0) {
            DC_FlushRange(e->pixels, 0x200);
            GX_LoadOBJ(e->pixels, e->vram, 0x200);
            func_0204B6F4((struct Obj *)e->spr, (u8)e->pal, 1);
        }
    }
    func_020307B0(p->icons);
}



/*
 * Read one Pokemon's display parameters (presence 0xA9, species 5, form
 * 0x6F, egg 0x4C, held item 6, parameter 0x6E + 1) into the info record,
 * clearing its +3 byte for an egg. A present Pokemon gets its icon loaded
 * (func_021F66F0) and shown; the item sprite is shown with animation 0x29
 * or 0x28 by func_0202136C, or hidden when there is no item. An empty
 * slot hides both sprites and clears the icon record's +8 word.
 */
void func_021F67A8(void *mon, u32 icon, u32 item_spr, u16 *species, u32 slot, u32 arc, Info_p02 *info, IconRec_p02 *rec)
{
    u32 present;
    u32 item;
    u32 egg;
    u32 form;

    func_02017DBC(mon);
    present = func_02017E88(mon, 0xa9, 0);
    *species = func_02017E88(mon, 5, 0);
    form = func_02017E88(mon, 0x6f, 0);
    egg = func_02017E88(mon, 0x4c, 0);
    item = func_02017E88(mon, 6, 0);
    info->species = *species;
    info->f2 = func_02017E88(mon, 0x6e, 0) + 1;
    if (egg != 0) {
        info->f3 = 0;
    }
    func_02017DE4(mon, 1);
    if (present != 0) {
        func_021F66F0(*species, form, info->f2 - 1, egg, slot, icon, arc, (IconRec_021F5E44 *)rec);
        func_0204B3DC((struct Obj *)icon, 1);
        if (item != 0) {
            func_0204B3DC((struct Obj *)item_spr, 1);
            if (func_0202136C(item) != 0) {
                func_0204B878((struct Obj *)item_spr, 0x29);
            } else {
                func_0204B878((struct Obj *)item_spr, 0x28);
            }
        } else {
            func_0204B3DC((struct Obj *)item_spr, 0);
        }
    } else {
        func_0204B3DC((struct Obj *)icon, 0);
        func_0204B3DC((struct Obj *)item_spr, 0);
        rec->f8 = 0;
    }
}
