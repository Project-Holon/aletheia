/*
 * file:     pmsiv_menu.c
 * unit:     yes
 * function: func_021BBE8C, func_021BBEF4, func_021BBF54, func_021BC068, func_021BC0CC, func_021BC120, func_021BC160, func_021BC1B8, func_021BC23C, func_021BC320, func_021BC340, func_021BC458, func_021BC484, func_021BC490, func_021BC564, func_021BC578, func_021BC58C, func_021BC5BC, func_021BC69C, func_021BC6D0, func_021BC6DC, func_021BC6E0, func_021BC6EC, func_021BC6F8, func_021BC704, func_021BC724, func_021BC728, func_021BC72C, func_021BC78C, func_021BC7DC, func_021BC828, func_021BC868, func_021BC898, func_021BC8C0, func_021BC8FC, func_021BC93C, func_021BC964, func_021BC990, func_021BCA30, func_021BCA84, func_021BCAD8, func_021BCB50, func_021BCC58, func_021BCC88, func_021BCCA8, func_021BCD44, func_021BCD80, func_021BCDE0, func_021BCDFC, func_021BCE30, func_021BCE48, func_021BCE54, func_021BCE70, func_021BCEA0, func_021BCEBC, func_021BCEE4, func_021BCF18, func_021BCF38, func_021BCF70, func_021BCF7C, func_021BCFBC, func_021BCFF0, func_021BD000, func_021BD028, func_021BD044, func_021BD0D4, func_021BD0F8, func_021BD114, func_021BD174, func_021BD194, func_021BD248, func_021BD264, func_021BD2F0, func_021BD344, func_021BD348, func_021BD448, func_021BD470, func_021BD484, func_021BD534, func_021BD578, func_021BD5A0, func_021BD5C4, func_021BD690, func_021BD6B4, func_021BD6F8, func_021BD740, func_021BD764, func_021BD7A0, func_021BD808, func_021BD868, func_021BD894, func_021BD8A8, func_021BD8B8, func_021BD8C8, func_021BD8D8, func_021BDA84, func_021BDA94, func_021BDAA4, func_021BDB50, func_021BDB98, func_021BDC70, func_021BDCB4, func_021BDEAC, func_021BDEF0, func_021BE1B8, func_021BE374, func_021BE3B8, func_021BE4C0, func_021BE580, func_021BE7B8, func_021BE7F0, func_021BE800, func_021BE890, func_021BE8B4, func_021BE934, func_021BEADC, func_021BEB44, func_021BEB60
 * address:  0x021BBE8C
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02041300 0x02041300 arm
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0202CC58 0x0202CC58 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_02005624 0x02005624 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_021BBE80 0x021BBE80 thumb ov110
 *   func_02040618 0x02040618 arm
 *   func_0204B4EC 0x0204B4EC arm
 *   func_0204B49C 0x0204B49C arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082A60 0x02082A60 arm
 *   func_020862F0 0x020862F0 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021BF6D8 0x021BF6D8 thumb ov110
 *   func_021BF6E4 0x021BF6E4 thumb ov110
 *   func_0207E3D0 0x0207E3D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_021BAC50 0x021BAC50 thumb ov110
 *   func_021BAC78 0x021BAC78 thumb ov110
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BAC64 0x021BAC64 thumb ov110
 *   func_0204B878 0x0204B878 arm
 *   func_0204B84C 0x0204B84C arm
 *   func_021BF6F0 0x021BF6F0 thumb ov110
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021BF708 0x021BF708 thumb ov110
 *   func_021BAC44 0x021BAC44 thumb ov110
 *   func_02045808 0x02045808 arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_02045A90 0x02045A90 arm
 *   func_02045994 0x02045994 arm
 *   func_0201D670 0x0201D670 thumb
 *   func_0201D688 0x0201D688 thumb
 *   func_02043AF4 0x02043AF4 arm
 *   func_02024508 0x02024508 thumb
 *   func_02024520 0x02024520 thumb
 *   func_02045730 0x02045730 arm
 *   func_02045758 0x02045758 arm
 *   func_02045760 0x02045760 arm
 *   func_0204B404 0x0204B404 arm
 *   func_020416D4 0x020416D4 arm
 *   func_02024838 0x02024838 thumb
 *   func_02041648 0x02041648 arm
 *   func_02041664 0x02041664 arm
 *   func_021B9BA4 0x021B9BA4 thumb ov110
 *   _s32_div_f 0x0209C0A4 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0207D658 0x0207D658 arm
 *   d_021C3C68 0x021C3C68 data
 *   func_02030734 0x02030734 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   func_021BF6D4 0x021BF6D4 thumb ov110
 *   func_021BAC4C 0x021BAC4C thumb ov110
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_02028148 0x02028148 thumb
 *   func_020409B4 0x020409B4 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027FEC 0x02027FEC thumb
 *   func_020282AC 0x020282AC thumb
 *   func_021BF7C4 0x021BF7C4 thumb ov110
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_0204B898 0x0204B898 arm
 *   d_021C38DF 0x021C38DF data a1
 *   d_021C38D4 0x021C38D4 data a1
 *   func_021BF824 0x021BF824 thumb ov110
 *   func_021BF7FC 0x021BF7FC thumb ov110
 *   func_021BF808 0x021BF808 thumb ov110
 *   func_020282A4 0x020282A4 thumb
 *   func_02028218 0x02028218 thumb
 *   func_0202822C 0x0202822C thumb
 *   func_02028230 0x02028230 thumb
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   d_021C38D9 0x021C38D9 data a1
 *   func_020275E4 0x020275E4 thumb
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_0204AC18 0x0204AC18 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BAC40 0x021BAC40 thumb ov110
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_02049F34 0x02049F34 arm
 *   func_02082D44 0x02082D44 arm
 *   func_02061CA4 0x02061CA4 arm
 *   tbl_020A1B38 0x020A1B38 data
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203064C 0x0203064C arm
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   func_021B9C74 0x021B9C74 thumb ov110
 *   func_021BABE8 0x021BABE8 thumb ov110
 *   func_0203D34C 0x0203D34C arm
 *   func_02030D28 0x02030D28 arm
 *   d_00000043 0x00000043 data a1
 *   func_020362DC 0x020362DC arm
 *   func_0203630C 0x0203630C arm
 *   func_0203633C 0x0203633C arm
 *   func_02051C88 0x02051C88 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x00000043 data
 *   func_0203159C 0x0203159C arm
 *   func_02024144 0x02024144 thumb
 *   func_0202421C 0x0202421C thumb
 *   func_02024168 0x02024168 thumb
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_021B95A0 0x021B95A0 thumb ov110
 *   func_021B9A50 0x021B9A50 thumb ov110
 *   func_02051B84 0x02051B84 arm
 *   func_021BAEDC 0x021BAEDC thumb ov110
 *   func_021BF4F8 0x021BF4F8 thumb ov110
 *   func_021BF508 0x021BF508 thumb ov110
 *   d_021C3908 0x021C3908 data a1
 *   d_021C3C78 0x021C3C78 data a1
 *   func_0202452C 0x0202452C thumb
 *   func_02024584 0x02024584 thumb
 *   func_02024530 0x02024530 thumb
 *   func_02024598 0x02024598 thumb
 *   func_02024224 0x02024224 thumb
 *   func_02051C6C 0x02051C6C arm
 *   func_021B9B20 0x021B9B20 thumb ov110
 *   func_02030DA4 0x02030DA4 arm
 *   func_021B95F4 0x021B95F4 thumb ov110
 *   func_021BAF4C 0x021BAF4C thumb ov110
 *   func_020315D4 0x020315D4 arm
 *   func_021BEDEC 0x021BEDEC thumb ov110
 *   func_021BAE24 0x021BAE24 thumb ov110
 *   func_021BAE94 0x021BAE94 thumb ov110
 *   func_021BAED0 0x021BAED0 thumb ov110
 *   func_02035C38 0x02035C38 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021BED84 0x021BED84 thumb ov110
 *   d_021C3920 0x021C3920 data a4
 *   func_021BF53C 0x021BF53C thumb ov110
 *   func_021BF608 0x021BF608 thumb ov110
 *   func_021BF82C 0x021BF82C thumb ov110
 *   func_021BF680 0x021BF680 thumb ov110
 *   d_021C3938 0x021C3938 data ov110 a1
 *   func_02035C08 0x02035C08 arm
 *   d_021C3948 0x021C3948 data ov110 a1
 *   d_021C38F0 0x021C38F0 data a1
 *   d_021C395C 0x021C395C data a1
 *   func_02035C60 0x02035C60 arm
 *   func_02035D20 0x02035D20 arm
 *   func_02035D40 0x02035D40 arm
 *   func_02024158 0x02024158 thumb
 *   func_021BAC00 0x021BAC00 thumb ov110
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021BAC30 0x021BAC30 thumb ov110
 *   func_021B9C90 0x021B9C90 thumb ov110
 *   func_021BB054 0x021BB054 thumb ov110
 *   func_021BAFAC 0x021BAFAC thumb ov110
 *   func_021BAF7C 0x021BAF7C thumb ov110
 *   d_021C392C 0x021C392C data a1
 *   d_021C3918 0x021C3918 data a1
 *   d_021C39B0 0x021C39B0 data a1
 *   d_021C39C4 0x021C39C4 data a1
 *   d_021C38F8 0x021C38F8 data a1
 *   func_021BB1F4 0x021BB1F4 thumb ov110
 *   func_021BB224 0x021BB224 thumb ov110
 *   func_021B999C 0x021B999C thumb ov110
 *   d_021C3910 0x021C3910 data a4
 */
#include "../../matched/include/Obj04447.h"
#include "../../matched/include/Obj02816.h"
#include "../../matched/include/Obj01053.h"
#include "../../matched/include/Obj22369.h"
#include "../../matched/include/Obj10276.h"
#include "../../matched/include/Obj02817.h"
#include "../../matched/include/Obj01393.h"
#include "../../matched/include/Obj05292.h"
#include "../../matched/include/Obj22370.h"
#include "../../matched/include/Obj22372.h"
#include "../../matched/include/Obj10277.h"
#include "../../matched/include/Obj22375.h"
#include "../../matched/include/Obj02461.h"
#include "../../matched/include/Obj05293.h"
#include "../../matched/include/Obj02818.h"
#include "../../matched/include/Obj03753.h"
#include "../../matched/include/Obj08002.h"
#include "../../matched/include/Obj03754.h"
#include "../../matched/include/Obj03241.h"
#include "../../matched/include/Obj04448.h"
#include "../../matched/include/Obj08003.h"
#include "../../matched/include/Obj01249.h"
#include "../../matched/include/Obj00295.h"
#include "../../matched/include/Obj06388.h"
#include "../../matched/include/Obj00295.h"
#include "../../matched/include/Obj13784.h"
#include "../../matched/include/Obj06389.h"
#include "../../matched/include/Obj01144.h"
#include "../../matched/include/Obj10278.h"
#include "../../matched/include/Obj06390.h"
#include "../../matched/include/Obj08004.h"
#include "../../matched/include/Obj13786.h"
#include "../../matched/include/Obj13787.h"
#include "../../matched/include/Obj02462.h"
#include "../../matched/include/Obj10279.h"
#include "../../matched/include/Obj22376.h"
#include "../../matched/include/Obj22377.h"
#include "../../matched/include/Obj22378.h"
#include "../../matched/include/Obj03242.h"
#include "../../matched/include/Obj05294.h"
#include "../../matched/include/Obj10281.h"
#include "../../matched/include/Obj05295.h"
#include "../../matched/include/Obj00012.h"
#include "../../matched/include/Obj13788.h"
#include "../../matched/include/Obj13789.h"
#include "../../matched/include/Obj13790.h"
#include "../../matched/include/Obj13791.h"
#include "../../matched/include/Obj10282.h"
#include "../../matched/include/Obj00189.h"
#include "../../matched/include/Obj22380.h"
#include "../../matched/include/Obj00586.h"
#include "../../matched/include/Obj13792.h"

#define F (*(int *)(p + 0xB8))
struct WinMgr;
struct Node;
struct V3;
struct Obj_021BC160;
struct Obj_021BC1B8;
struct CharBuf;
struct Descriptor;
struct Vec2;
struct StrObj;
struct U16Vec;
struct Cursor;
struct Strbuf;
struct Bmp;
struct Obj;
struct MsgBank;
struct R;
struct Rec;
struct TaskMenuState;
struct Actor;
struct T;
struct Ctx;
struct Obj0203159C;
struct Input;
struct S020315D4;
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct { u8 pad[0x14]; void *desc[2]; void *items[2][2]; } Obj_021BBF54;

typedef struct { int a,b,c; } Triple;

typedef struct { void *root; u8 pad[0x18]; void *items[2][2]; } Obj_021BC160;

typedef struct { short x,y; } Pair;

typedef struct { void *root; u8 *state; int pad; void *desc[2]; u8 gap0[8]; void *items[2][2]; u8 gap[12]; Pair pos[2]; int pad40; int count; } Obj_021BC1B8;

typedef struct { void *root; u8 *state; u8 pad[0x14]; void *items[2][2]; u8 gap[12]; Pair pos[2]; u16 ids[2]; int count; u8 parser[12]; u16 id; } Obj_021BC340;

typedef int s32;

typedef struct Cursor {
    u32 f00;
    u16 *f04;
    u32 f08;
    u16 f0c;
} Cursor;

typedef struct { short x, y; } Vec2_021BC58C;

typedef struct Vec2_021BC5BC { short x,y; } Vec2_021BC5BC;

struct Pt { short a, b, x, y; };

typedef struct { void *s; unsigned short x; unsigned short pad; int flag; } Record_021BC564;

typedef struct { u8 pad[0x40]; Record_021BC564 records[3]; void *windows[3]; void *items[8]; void *other[2]; } Object_021BC564;

typedef struct Record_021BCB50 { void *s; u16 x,pad; int flag; } Record_021BCB50;

typedef struct Object_021BCB50 {
    u32 f00;
    u8 *f04;
    u8 pad08[0x28];
    struct MsgBank *bank;
    u16 *windows[3];
    Record_021BCB50 records[3];
    struct T *menus[3];
    struct Obj *items[8];
    struct Obj *other[2];
} Object_021BCB50;

typedef struct { u8 pad[0x70]; void *items[8]; } Object;

typedef struct { void *root; u8 pad[0x6c]; void *items[8]; } Object_021BD044;

typedef struct { void *root; u8 pad[0x8c]; void *items[2]; } Object_021BD114;

typedef struct { u16 x,y,z; u8 a,b; } Params;

typedef struct { void *s; u16 x,pad; int flag; } Record;

typedef struct { u8 pad[0x30]; void *bank; void *a[3]; Record records[3]; void *windows[3]; } Object_021BD264;

typedef struct { short a; s8 b; s8 c; } State_021BD6B4;

typedef struct { short a; s8 b,c; } State_021BD6F8;

typedef short s16;

typedef int (*Handler)(u8 *,void *);

typedef struct { u8 b[8]; } Box;

typedef struct { s16 a; s8 b,c; } State;

typedef struct { u8 b[8]; } Box_021BE800;

typedef struct { unsigned char b[16]; } Box_021BE890;

typedef struct { u8 b[8]; } Box_021BE8B4;

extern void func_02041300(unsigned, int, int, int, u8, u8, u8);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0202CC58(struct WinMgr *mgr, u32 idx);
extern void func_02030EAC(struct Node *n);
extern void *func_02005624(u32 a, u32 b, u32 c);
extern void *func_020056A0(void *, void *, unsigned);
extern void func_021BBE80(void);
extern void func_02040618(unsigned,unsigned,unsigned);
extern short func_0204B4EC(void *,u16,unsigned);
extern void func_0204B49C(void *,short,u16,unsigned);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082A60(const void *, void *, int);
extern void func_020862F0(void *, unsigned);
extern u32 func_020307B0(void *p);
extern unsigned func_021BF6D8(u8 *);
extern int func_021BF6E4(u8 *p);
extern void func_0207E3D0(void *,int,int);
extern void func_0207E468(void *,int,int);
extern void func_021BAC50(char *p, struct V3 *out, int i);
extern void *func_021BAC78(void *,Triple *,int,int,int,int);
extern void func_0204B3DC(struct Obj_021BC160 *p, u32 v);
extern void func_021BAC64(void *,Triple *,int,int);
extern void func_0204B878(struct Obj_021BC1B8 *p, u16 value);
extern void func_0204B84C(void *,int);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32 func_021BF6F0(u8 *p, u32 i);
extern void func_02045334(struct Descriptor *d);
extern void func_02041B6C(unsigned);
extern void *func_021BF708(u8 *,u32);
extern u32 func_021BAC44(u8 *);
extern void func_0201DD78(u32,u32,u32);
extern void func_0201C7A4(void *,short,short,void *,void *);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_02045808(struct U16Vec *vec);
extern u16 *func_02045A90(struct U16Vec *vec);
extern void func_02045994(struct Strbuf *,const u16 *,u32);
extern u32 func_0201D670(const u16 *,u32);
extern u16 *func_0201D688(u16 *);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern u32 func_02024508(u32);
extern u32 func_02024520(u32);
extern u8 func_02045730(struct Descriptor *);
extern u8 func_02045758(struct Descriptor *);
extern u8 func_02045760(struct Descriptor *);
extern void func_0204B404(struct Obj *p, const struct Vec2_021BC5BC *delta, u32 which);
extern u8 func_020416D4(u32);
extern void func_02024838(u32,void *,u32);
extern unsigned int func_02041648(u8 channel);
extern u32 func_02041664(u8 channel);
extern void *func_021B9BA4(void (*fn)(void *, u8 *), u8 *p, int n);
extern int _s32_div_f(int, int);
extern void func_0207D63C(void *, int, int, int, int);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern u8 *func_021BF6D4(u8 *);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern unsigned func_021BAC4C(u8 *);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02028178(u8 *p);
extern u32 func_0204B98C(struct Actor *a);
extern void func_02028148(u8 *p);
extern void func_020409B4(u32 index);
extern void *func_02045EC0(struct MsgBank *,u32);
extern u32 func_02027FEC(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 a5);
extern void func_020282AC(struct T *,u16 *,u32,u32,u16);
extern u32 func_021BF7C4(u8 *);
extern u8 func_021BF6DC(u8 *);
extern u16 func_0204B898(struct Obj *p);
extern int func_021BF824(u8 *);
extern u8 func_021BF7FC(u8 *p);
extern int func_021BF808(u8 *);
extern void func_020282A4(struct Obj *obj);
extern void func_02028218(struct Obj *obj, u32 a);
extern void func_0202822C(char *,int);
extern u32 func_02028230(u8 *);
extern u32 func_0204B3F4(struct Obj *p);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204A6C8(void *a, unsigned int b, unsigned int c, unsigned int a3, u16 flags);
extern int func_0204AF28(void *owner, unsigned int first, unsigned int second, unsigned int mode);
extern void func_02049238(void *);
extern unsigned int func_020275E4(void);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern int func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void func_02082BCC(void *,int,unsigned);
extern u32 func_021BAC40(u8 *p);
extern struct Obj *func_0204B294(void *owner,u32 i,u32 j,u32 k,const void *position,u16 space,u16 heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *, void *, unsigned int);
extern int func_02061CA4(void *p, u32 a, u32 b, int size);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern int func_02034AC4(int handle);
extern void func_0203064C(unsigned int,unsigned int,unsigned int);
extern void func_021B9BEC(u8 *p, int id);
extern int func_021B9C74(unsigned int a);
extern int func_021BABE8(u8 *p);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02030D28(struct Ctx *c);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern unsigned int func_0203633C(void);
extern int func_02051C88(struct Ctx *c);
extern void func_020306F0(u32);
extern void func_02034A5C(int);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern u32 func_02024144(const u8 *);
extern u32 func_0202421C(void *);
extern void func_02024168(const struct Input *p, u16 *a, u16 *b);
extern u32 func_02030CB0(u32);
extern struct Ctx *func_02030CBC(u32,struct Ctx *);
extern void *func_021B95A0(u32,void *);
extern void *func_021B9A50(u8 *,void *);
extern void *func_02051B84(u8 *,int,int,int);
extern u8 *func_021BAEDC(void *,void *,u16);
extern void func_021BF4F8(u8 *,u32);
extern void func_021BF508(u8 *p, int *q);
extern int func_0202452C(const u16 *p);
extern u8 func_02024584(u32 i);
extern unsigned int func_02024530(const u16 *p);
extern void func_02024598(void *, int, int);
extern void func_02024224(void *,void *);
extern void func_02051C6C(void *);
extern void func_021B9B20(u8 *);
extern void func_02030DA4(void *);
extern void func_021B95F4(char *);
extern void func_021BAF4C(unsigned);
extern void func_020315D4(struct S020315D4 *p);
extern int func_021BEDEC(u8 *,void *);
extern int func_021BAE24(u8 *p, u8 *a1, void *a2);
extern int func_021BAE94(u8 *p, u8 *q, void *a2);
extern int func_021BAED0(u8 *p, u8 *a1, void *a2);
extern int func_02035C38(void);
extern void func_020061E4(u32);
extern void func_021BED84(u8 *,void *);
extern void func_021BF53C(u8 *,u32 *);
extern void func_021BF608(u8 *,u32 *);
extern void func_021BF82C(u8 *);
extern int func_021BF680(u8 *);
extern int func_02035C08(const void *p);
extern int func_02035C60(void);
extern unsigned int func_02035D20(unsigned int *outA, unsigned int *outB);
extern unsigned int func_02035D40(struct Ctx *ctx, unsigned int a, unsigned int b);
extern u32 func_02024158(const u8 *p);
extern void func_021BAC00(u8 *p, u8 *b, u8 n);
extern void func_021BAC30(u8 *,int);
extern int func_021B9C90(unsigned int a, int b);
extern int func_021BB054(u8 *);
extern int func_021BAFAC(u32 p);
extern void func_021BAF7C(unsigned p, int v);
extern int func_021BB1F4(void);
extern void func_021BB224(unsigned,int *,int *);
extern u32 func_021B999C(u8 *,int);
void func_021BBE8C(void *unused, u8 *p);
void func_021BBEF4(u8 *p, u8 value);
int func_021BBF54(Obj_021BBF54 *p);
void func_021BC068(u8 *p, void *a);
void func_021BC0CC(u8 *p);
void func_021BC120(u8 *p);
void func_021BC160(Obj_021BC160 *p);
void func_021BC1B8(u8 *p);
void func_021BC23C(Obj_021BC1B8 *p);
void func_021BC320(void *a, unsigned char *b, int n);
int func_021BC340(Obj_021BC340 *p,void *desc,u8 bank);
void func_021BC458(u8 *p,u8 *a);
void func_021BC484(u8 *p);
int func_021BC490(Cursor *p,struct Strbuf *out);
void func_021BC564(short *p,short *out);
void func_021BC578(const short *a, short *b);
void func_021BC58C(void *p, const Vec2_021BC58C *a);
void func_021BC5BC(u8 *p,struct Descriptor *window,const Vec2_021BC5BC *input,u32 id,struct Obj *sprite);
void func_021BC69C(u8 *p, int flag);
u32 func_021BC6D0(u32 n);
unsigned int func_021BC6DC(void *p);
u16 func_021BC6E0(u8 *p, int i);
void func_021BC6EC(void *p);
void func_021BC6F8(void *p);
void func_021BC704(u8 *p, u32 flag);
void func_021BC724(u8 *a0);
void func_021BC728(u8 *a0);
void func_021BC72C(char *p, int i);
void func_021BC78C(u8 *p, int a, int b, int step, int n);
int func_021BC7DC(u8 *p);
void func_021BC828(void *unused, u8 *p);
void func_021BC868(u8 *p, int a, int b, int start, int end, int frames);
int func_021BC898(u8 *p);
void func_021BC8C0(void *task, u8 *p);
void func_021BC8FC(u8 *p,int a,int start,int end,int n);
int func_021BC93C(u8 *p);
void func_021BC964(void *unused,u8 *p);
u8 *func_021BC990(u8 *a,u8 *b,void *c);
void func_021BCA30(u8 *p);
void func_021BCA84(u8 *p);
void func_021BCAD8(Object_021BC564 *p);
void func_021BCB50(Object_021BCB50 *p);
void func_021BCC58(u8 *p);
void func_021BCC88(u8 *p);
void func_021BCCA8(Object *p);
void func_021BCD44(u8 *p);
void func_021BCD80(u8 *p);
void func_021BCDE0(u8 *p);
int func_021BCDFC(char *p);
void func_021BCE24(void *p);
int func_021BCE30(char *p);
void func_021BCE48(void *p, int a1, int a2);
void func_021BCE54(char *p);
int func_021BCE70(char *p);
void func_021BCEA0(char *p);
int func_021BCEBC(char *p);
void func_021BCEE4(char *p,u32 mode);
void func_021BCF18(void *p,int mode);
int func_021BCF38(char *p,u32 mode);
void func_021BCF70(void *p, int i, int j);
void func_021BCF7C(u8 *p, int n, int v);
void func_021BCFBC(char *p,u32 index,int value);
u32 func_021BCFF0(char *p,u32 index);
int func_021BD000(char *p);
int func_021BD028(u8 *p);
void func_021BD044(Object_021BD044 *p);
void func_021BD0D4(u8 *p);
void func_021BD0F8(u8 *p,int i,int flag);
void func_021BD114(Object_021BD114 *p);
void func_021BD174(u8 *p);
void func_021BD194(u8 *p);
void func_021BD248(u8 *p);
void func_021BD264(Object_021BD264 *p);
void func_021BD2F0(u8 *p);
void func_021BD344(u8 *a0);
void func_021BD348(char *p);
void func_021BD448(u8 *p,int i);
void func_021BD470(u8 *p,int i);
int func_021BD484(void *a,int *state,int c,void *p);
int func_021BD534(void *a,int b,int c,u8 *p);
void func_021BD578(int value,unsigned int which,u8 *p);
int func_021BD5A0(void *a,int b,int c,u8 *p);
u8 *func_021BD5C4(struct Obj0203159C *owner,u8 *input);
void func_021BD690(u8 *p, u16 *out);
void func_021BD6B4(State_021BD6B4 *p, void *out);
void func_021BD6F8(State_021BD6F8 *p,void *out);
void func_021BD740(u8 *p,void *out,int v);
void func_021BD764(u8 *p,void *a);
void func_021BD7A0(u8 *p,Handler fn);
int func_021BD808(u8 *p,void *q);
void func_021BD868(u8 *p);
int func_021BD894(u8 *p,void *q);
int func_021BD8A8(u8 *p);
int func_021BD8B8(u8 *p);
int func_021BD8C8(u8 *p);
int func_021BD8D8(u8 *p,u32 *q);
int func_021BDA84(u8 *unused);
int func_021BDA94(u8 *unused);
int func_021BDAA4(u8 *p);
int func_021BDB50(u32 *p);
int func_021BDB98(u8 *p,u32 *q);
int func_021BDC70(u8 *p,unsigned *q);
int func_021BDCB4(u8 *p,u32 *q);
int func_021BDEAC(u8 *p,unsigned *q);
int func_021BDEF0(u8 *p,u32 *q);
int func_021BE1B8(u8 *p,u32 *q);
int func_021BE374(u8 *p,unsigned *q);
int func_021BE3B8(u8 *p,u32 *q);
int func_021BE4C0(u8 *p,unsigned *q);
void func_021BE580(u8 *p,u32 *q);
int func_021BE7B8(u8 *p);
int func_021BE7F0(void);
int func_021BE800(u8 *a0);
int func_021BE890(void *a0);
int func_021BE8B4(u8 *a0);
void func_021BE934(u8 *p,u32 *q);
void func_021BEADC(u8 *p,void *q);
int func_021BEB44(u8 *p);
int func_021BEB60(u8 *p);
extern const char d_021C3C68[];
extern const u8 d_021C38DF[],d_021C38D4[];
extern const u8 d_021C38DF[];
extern const u8 d_021C38D9[];
extern short tbl_020A1B38[];
extern const u8 d_00000043[];
extern char ov067_id[];
extern const u8 d_021C3908[];
extern const char d_021C3C78[];
extern u8 d_021C3938[];
extern u8 d_021C3948[];
extern const Box d_021C38F0;
extern const Box d_021C395C;
extern const u8 d_021C392C[];
extern const unsigned char d_021C3918[];
extern const Box_021BE800 d_021C39B0;
extern const Box_021BE890 d_021C39C4;
extern const Box_021BE8B4 d_021C38F8;





void func_021BBE8C(void *unused, u8 *p)
{
    ((struct Obj04447 *)p)->f1A8 = 0;
    ((struct Obj04447 *)p)->f1AC = 0;
    if (((struct Obj04447 *)p)->f1B8) {
        func_02041300(0, 0, 0, 0, 32, 6, 17);
        func_0202CB4C(((struct Obj04447 *)p)->f1B4, 0, 0, (s8)(-((struct Obj04447 *)p)->f198 / 8));
        func_0202CC58(((struct Obj04447 *)p)->f1B4, 0);
        ((struct Obj04447 *)p)->f1B8 = 0;
    }
}





void func_021BBEF4(u8 *p, u8 value)
{
    p[0x19c] = 0;
    p[0x19d] = value;
    if (((struct Obj02816 *)p)->f1A4) func_02030EAC(((struct Obj02816 *)p)->f1A4);
    ((struct Obj02816 *)p)->f1A4 = func_02005624((u32)func_021BBE80, (u32)p, 1);
    ((struct Obj02816 *)p)->f1A8 = 0;
    ((struct Obj02816 *)p)->f1AC = 0;
    if (((struct Obj02816 *)p)->f1B0) func_02030EAC(((struct Obj02816 *)p)->f1B0);
    ((struct Obj02816 *)p)->f1B0 = func_020056A0(func_021BBE8C, p, 1);
}





/*
 * lever: plain signed-halfword assignments and named coordinate results.
 * prototype: original call truncates space to u16; legacy 02040618 fourth input is unused by 02042360.
 */
int func_021BBF54(Obj_021BBF54 *p)
{
    int delta,i,j;
    u8 *b=(u8 *)p;
    if(b[0x19c]>5) return 1;
    if(b[0x19d]) delta=-8; else delta=8;
    ((struct Obj01053 *)b)->f19A=((struct Obj01053 *)b)->f19A+delta;
    ((struct Obj01053 *)b)->f198=((struct Obj01053 *)b)->f198+delta;
    func_02040618(4,3,((struct Obj01053 *)b)->f19A);
    for(i=0;i<2;i++) {
        short pos=func_0204B4EC(p->desc[i],i,1)-delta;
        func_0204B49C(p->desc[i],pos,i,1);
        for(j=0;j<2;j++) {
            short pos=func_0204B4EC(p->items[j][i],i,1)-delta;
            func_0204B49C(p->items[j][i],pos,i,1);
        }
    }
    b[0x19c]++;
    if(b[0x19d] && b[0x19c]==7) {
        func_02030EAC(((struct Obj01053 *)b)->f1A4);
        ((struct Obj01053 *)b)->f1A4=0;
        func_02030EAC(((struct Obj01053 *)b)->f1B0);
        ((struct Obj01053 *)b)->f1B0=0;
    }
    ((struct Obj01053 *)b)->f1B8=1;
    return 0;
}





/*
 * extent: two bytes of zero alignment padding after the return.
 */
void func_021BC068(u8 *p, void *a)
{
    u8 *data;
    void *handle;
    func_02049B68(a, 3, 0, 0, 448, 42);
    func_02049B68(a, 4, 4, 0, 160, 42);
    handle = func_02049F78(a, 6, (u32)((void **)&data), 42);
    func_02082A60(((struct Obj22369 *)data)->fC, p + 0x58, 320);
    func_020862F0(p + 0x58, 320);
    func_020307B0(handle);
}





void func_021BC0CC(u8 *p)
{
    if (func_021BF6D8(*(u8 * *)&((struct Obj10276 *)p)->f4)==2 && (unsigned)func_021BF6E4(*(u8 * *)&((struct Obj10276 *)p)->f4)<5) {
        unsigned n=(unsigned)func_021BF6E4(*(u8 * *)&((struct Obj10276 *)p)->f4)+1;
        func_0207E3D0(p+0x58+n*32,0,32);
        func_0207E468(p+0x58+n*32,0,32);
    } else {
        func_0207E3D0(p+0x58,0,32);
        func_0207E468(p+0x58,0,32);
    }
}





void func_021BC120(u8 *p)
{
    switch (func_021BF6D8(*(u8 * *)&((struct Obj02817 *)p)->f4)) {
    case 0: ((struct Obj02817 *)p)->f38=104; ((struct Obj02817 *)p)->f3A=16; ((struct Obj02817 *)p)->f44=1; break;
    case 1: ((struct Obj02817 *)p)->f38=48; ((struct Obj02817 *)p)->f3A=16; ((struct Obj02817 *)p)->f3C=160; ((struct Obj02817 *)p)->f3E=16; ((struct Obj02817 *)p)->f44=2; break;
    case 2: ((struct Obj02817 *)p)->f44=0; break;
    }
}





void func_021BC160(Obj_021BC160 *p)
{
    Triple t;
    int i,j;
    for (i=0;i<2;i++) {
        func_021BAC50(p->root,(struct V3 *)(&t),i);
        for (j=0;j<2;j++) {
            p->items[j][i]=func_021BAC78(p->root, (Triple *)((unsigned int *)(&t)), (int)0, (int)0, (int)2, i+1);
            func_0204B3DC(p->items[j][i],0);
        }
    }
}






/*
 * extent: two bytes zero alignment padding after return.
 * lever: coordinate arguments are int; the callee stores low halfwords
 * without caller-side narrowing, including y+192.
 */
void func_021BC1B8(u8 *p)
{
    Triple t;
    Pair pos;
    if (*(int *)&((struct Obj01393 *)p)->f44) func_021BC578((short *)((const short *)(p+0x38)), (short *)((short *)(&pos)));
    else { pos.x=128; pos.y=24; }
    func_021BAC64(((struct Obj01393 *)p)->f0, &t, 1, 0);
    ((struct Obj01393 *)p)->f18=func_021BAC78(((struct Obj01393 *)p)->f0, &t, pos.x, pos.y+192, 0, 2);
    func_0204B878((struct Obj_021BC1B8 *)(((struct Obj01393 *)p)->f18), 1);
    func_0204B84C(((struct Obj01393 *)p)->f18, 1);
    func_021BAC64(((struct Obj01393 *)p)->f0, &t, 0, 0);
    ((struct Obj01393 *)p)->f14=func_021BAC78(((struct Obj01393 *)p)->f0, &t, pos.x, pos.y, 0, 1);
    func_021BC69C(p,1);
}






/*
 * extent: two bytes zero alignment padding at 0x021BC31E.
 */
void func_021BC23C(Obj_021BC1B8 *p)
{
    int i,j;
    func_021BC0CC((u8 *)p);
    for(i=0;i<2;i++) {
        for(j=0;j<2;j++) {
            if(p->items[j][i]) func_0204B3DC((struct Obj_021BC160 *)((struct Obj_021BC1B8 *)(p->items[j][i])), 0);
        }
        func_02043B5C(func_02045770(p->desc[i]),15);
        switch(func_021BF6D8(p->state)) {
        case 0:
            func_021BC58C(p->desc[i], (const Vec2_021BC58C *)(&p->pos[0]));
            func_021BC5BC((u8 *)p, p->desc[i], (const Vec2_021BC5BC *)((const struct Vec2 *)(&p->pos[0])), func_021BF6F0(p->state,0), (struct Obj *)((struct Obj_021BC1B8 *)(p->items[0][i])));
            break;
        case 1:
            func_021BC58C(p->desc[i], (const Vec2_021BC58C *)(&p->pos[0]));
            func_021BC58C(p->desc[i], (const Vec2_021BC58C *)(&p->pos[1]));
            func_021BC5BC((u8 *)p, p->desc[i], (const Vec2_021BC5BC *)((const struct Vec2 *)(&p->pos[0])), func_021BF6F0(p->state,0), (struct Obj *)((struct Obj_021BC1B8 *)(p->items[0][i])));
            func_021BC5BC((u8 *)p, p->desc[i], (const Vec2_021BC5BC *)((const struct Vec2 *)(&p->pos[1])), func_021BF6F0(p->state,1), (struct Obj *)((struct Obj_021BC1B8 *)(p->items[1][i])));
            break;
        case 2:
            p->count=func_021BC340((Obj_021BC340 *)p, p->desc[i], i);
            break;
        }
        func_02045334(p->desc[i]);
    }
    func_02041B6C(0);
    func_02041B6C(4);
}






/*
 * Unlabelled Thumb leaf in a .word run.  Extent 0x021BC320..0x021BC340
 * (32 bytes).  Packs two short coordinates from a[n] into b.
 */
void func_021BC320(void *a, unsigned char *b, int n)
{
    int i = n * 4;

    b[2] = *(short *)((char *)a + i + 0x38) - 0x18;
    b[3] = b[2] + 0x60;
    b[0] = *(short *)((char *)a + i + 0x3a);
    b[1] = b[0] + 0x10;
}






int func_021BC340(Obj_021BC340 *p,void *desc,u8 bank)
{
    void *str;
    u16 id;
    int running,count,x,y;
    u32 font;
    str=func_021BF708(p->state,42);
    font=(u32)func_021BAC44(p->root);
    running=1;
    count=0; y=0; x=0;
    func_021BC458(p->parser,(u8 *)p);
    do {
        switch(func_021BC490((struct Cursor *)p->parser,str)) {
        case 0:
            func_0201DD78(1, 2, 15);
            func_0201C7A4(func_02045770(desc), x, y, str, (void *)font);
            x+=func_0201D304(str,font,0);
            break;
        case 1: {
            id=p->id;
            p->ids[count]=id;
            p->pos[count].x=x+50;
            p->pos[count].y=y+8;
            func_021BC58C(desc, (const Vec2_021BC58C *)(&p->pos[count]));
            func_021BC5BC((u8 *)p, desc, (const Vec2_021BC5BC *)((const struct Vec2 *)(&p->pos[count])), func_021BF6F0(p->state,id), (struct Obj *)((struct Obj_021BC1B8 *)(p->items[count][bank])));
            count++;
            x+=100;
            break;
        }
        case 2: y+=16; x=0; break;
        case 3: running=0; break;
        }
    } while(running);
    func_021BC484(p->parser);
    func_02045808(str);
    return count;
}






/*
 * extent: two bytes of zero alignment padding after return.
 */
void func_021BC458(u8 *p,u8 *a) { ((struct Obj05292 *)p)->f0=func_021BF708(*(u8 * *)&((struct Obj22370 *)a)->f4,42); *(u16 * *)&((struct Obj05292 *)p)->f4=func_02045A90(((struct Obj05292 *)p)->f0); if(**(u16 * *)&((struct Obj05292 *)p)->f4==0xF000) ((struct Obj05292 *)p)->f8=1; else ((struct Obj05292 *)p)->f8=0; }






void func_021BC484(u8 *p) { func_02045808((struct U16Vec *)(((struct Obj22372 *)p)->f0)); }






int func_021BC490(Cursor *p,struct Strbuf *out)
{
    u16 *start;
    int result;
    start=p->f04;
    switch(p->f08) {
    case 0:
        while(p->f08==0) {
            switch(*p->f04) {
            case 0xfffe: p->f08=2; break;
            case 0xffff: p->f08=3; break;
            case 0xf000: p->f08=1; break;
            default: p->f04+=1; break;
            }
        }
        func_02045994(out,start,(p->f04-start)+1);
        return 0;
    case 1:
        p->f0c=func_0201D670(start,0);
        p->f04=func_0201D688(p->f04);
        result=1;
        break;
    case 2:
        p->f04=start+1;
        result=2;
        break;
    case 3:
    default:
        return 3;
    }
    switch(*p->f04) {
    case 0xfffe: p->f08=2; break;
    case 0xffff: p->f08=3; break;
    case 0xf000: p->f08=1; break;
    default: p->f08=0; break;
    }
    return result;
}











void func_021BC564(short *p,short *out) { out[0]=p[0]-48; out[1]=p[1]-8; }











void func_021BC578(const short *a, short *b)
{
    b[0] = a[0] + 24;
    b[1] = a[1] + 8;
}










void func_021BC58C(void *p, const Vec2_021BC58C *a)
{
    Vec2_021BC58C pos;
    func_021BC564((short *)a, (short *)(&pos));
    func_02043AF4(func_02045770(p), pos.x, pos.y, 0x60, 16, 14);
}










void func_021BC5BC(u8 *p,struct Descriptor *window,const Vec2_021BC5BC *input,u32 id,struct Obj *sprite)
{
    Vec2_021BC5BC base;
    Vec2_021BC5BC pos;
    u32 font;
    u32 index;
    u32 layer;
    font=func_021BAC44(*(u8 * *)&((struct Obj10277 *)p)->f0);
    if(id==0xffff) return;
    func_021BC564((short *)input,(short *)(&base));
    if(func_02024508(id)!=0) {
        index=func_02024520(id)-1;
        layer=func_021BC6D0(func_02045730(window));
        pos.x=base.x+func_02045758(window)*8;
        pos.y=base.y+func_02045760(window)*8;
        if(layer==1) pos.y+=192;
        func_0204B878((struct Obj_021BC1B8 *)sprite, index);
        func_0204B404(sprite,&pos,(u16)layer);
        func_0204B3DC((struct Obj_021BC160 *)sprite, 1);
        func_0204B84C(sprite, (int)(func_020416D4(func_02045730(window))));
    } else {
        func_02024838(id,((struct Obj10277 *)p)->f30,42);
        func_0201DD78((u32)3, (u32)4, (u32)14);
        func_0201C7A4(func_02045770(window), (short)base.x, (short)base.y, ((struct Obj10277 *)p)->f30, (void *)font);
    }
}










void func_021BC69C(u8 *p, int flag)
{
    if (((struct Obj01393 *)p)->f44 != 0) {
        if (flag != 0) func_0204B878((struct Obj_021BC1B8 *)(((struct Obj01393 *)p)->f14), 0);
        else func_0204B878((struct Obj_021BC1B8 *)(((struct Obj01393 *)p)->f14), 1);
    } else {
        if (flag != 0) func_0204B878((struct Obj_021BC1B8 *)(((struct Obj01393 *)p)->f14), 14);
        else func_0204B878((struct Obj_021BC1B8 *)(((struct Obj01393 *)p)->f14), 15);
    }
}











u32 func_021BC6D0(u32 n)
{
    if (n >= 4) return 1;
    return 0;
}











unsigned int func_021BC6DC(void *p)
{
    return ((struct Obj22375 *)p)->f44;
}











/*
 * Halfword accessor: p + i*2 + 0x40.
 */
u16 func_021BC6E0(u8 *p, int i)
{
    return *(u16 *)(p + i * 2 + 0x40);
}










void func_021BC6EC(void *p) { func_021BC69C(p, 0); }










void func_021BC6F8(void *p) { func_021BC69C(p, 1); }










void func_021BC704(u8 *p, u32 flag)
{
    func_0204B3DC((struct Obj_021BC160 *)(((struct Obj01393 *)p)->f14), flag);
    func_0204B3DC((struct Obj_021BC160 *)(((struct Obj01393 *)p)->f18), flag);
    func_021BC69C(p, 1);
}











void func_021BC724(u8 *a0) { }











void func_021BC728(u8 *a0) { }










void func_021BC72C(char *p, int i)
{
    struct Pt t;
    if (*(u32 *)(p + 0x44) != 0) {
        func_021BC578((const short *)((const short *)(p + 0x38 + i * 4)), (short *)((short *)(&t)));
        t.x = t.a;
        t.y = t.b;
    } else {
        t.x = 0x80;
        t.y = 0x18;
    }
    func_0204B404(*(void **)(p + 0x14), (const struct Vec2_021BC5BC *)((const struct Vec2 *)(&t.x)), 0);
    t.y += 0xC0;
    func_0204B404(*(void **)(p + 0x18), (const struct Vec2_021BC5BC *)((const struct Vec2 *)(&t.x)), 1);
    func_021BC69C((u8 *)p, 1);
}









void func_021BC78C(u8 *p, int a, int b, int step, int n)
{
    ((struct Obj02461 *)p)->f0=a;
    if (b==0) {
        ((struct Obj02461 *)p)->f8=func_02041648(a);
        ((struct Obj02461 *)p)->f4=0;
    } else {
        ((struct Obj02461 *)p)->f8=func_02041664(a);
        ((struct Obj02461 *)p)->f4=3;
    }
    ((struct Obj02461 *)p)->fC=(((struct Obj02461 *)p)->f8+step)&511;
    ((struct Obj02461 *)p)->f8<<=12;
    ((struct Obj02461 *)p)->f10=(step<<12)/n;
    ((struct Obj02461 *)p)->f14=n;
    ((struct Obj02461 *)p)->f16=0;
}









int func_021BC7DC(u8 *p)
{
    switch (((struct Obj05293 *)p)->f16) {
    case 0:
        ((struct Obj05293 *)p)->f18=func_021B9BA4(func_021BC828,p,0);
        ++((struct Obj05293 *)p)->f16;
        break;
    case 1:
        if (((struct Obj05293 *)p)->f14==0) {
            func_02030EAC(((struct Obj05293 *)p)->f18);
            ++((struct Obj05293 *)p)->f16;
            return 1;
        }
        break;
    case 2: return 1;
    }
    return 0;
}









void func_021BC828(void *unused, u8 *p)
{
    if (((struct Obj02818 *)p)->f14) {
        ((struct Obj02818 *)p)->f8 += ((struct Obj02818 *)p)->f10;
        func_02040618((u8)(((struct Obj02818 *)p)->f0), (u8)(((struct Obj02818 *)p)->f4), (int)(((struct Obj02818 *)p)->f8>>12));
        --((struct Obj02818 *)p)->f14;
    } else {
        func_02040618((u8)(((struct Obj02818 *)p)->f0), (u8)(((struct Obj02818 *)p)->f4), (int)(((struct Obj02818 *)p)->fC));
    }
}









void func_021BC868(u8 *p, int a, int b, int start, int end, int frames)
{
    ((struct Obj03753 *)p)->f0 = a;
    ((struct Obj03753 *)p)->f4 = b;
    ((struct Obj03753 *)p)->f14 = frames;
    ((struct Obj03753 *)p)->f8 = start;
    ((struct Obj03753 *)p)->f10 = _s32_div_f(end - start, frames);
    ((struct Obj03753 *)p)->fC = end;
    ((struct Obj03753 *)p)->f18 = 0;
    ((struct Obj03753 *)p)->f1C = func_021B9BA4(func_021BC8C0, p, 0);
}









int func_021BC898(u8 *p)
{
    if (((struct Obj08002 *)p)->f18 == 0) {
        if (((struct Obj08002 *)p)->f14 == 0) {
            func_02030EAC(((struct Obj08002 *)p)->f1C);
            ((struct Obj08002 *)p)->f18 += 1;
            return 1;
        }
    } else {
        return 1;
    }
    return 0;
}









void func_021BC8C0(void *task, u8 *p)
{
    int level;
    if (((struct Obj03754 *)p)->f14 != 0) {
        ((struct Obj03754 *)p)->f8 += ((struct Obj03754 *)p)->f10;
        level = ((struct Obj03754 *)p)->f8 >> 3;
        ((struct Obj03754 *)p)->f14 -= 1;
    } else {
        level = ((struct Obj03754 *)p)->fC >> 3;
    }
    if (level > 16) level = 16;
    func_0207D63C((void *)0x04000050, ((struct Obj03754 *)p)->f0, ((struct Obj03754 *)p)->f4, level, 16 - level);
}









/*
 * lever: difference of stored fixed-point fields prevents shift factoring.
 */
void func_021BC8FC(u8 *p,int a,int start,int end,int n)
{
    func_0207D658(0x4000050,a,start);
    ((struct Obj03241 *)p)->f0=a;
    ((struct Obj03241 *)p)->f14=n;
    ((struct Obj03241 *)p)->f8=start<<12;
    ((struct Obj03241 *)p)->fC=end<<12;
    ((struct Obj03241 *)p)->f10=(((struct Obj03241 *)p)->fC-((struct Obj03241 *)p)->f8)/n;
    ((struct Obj03241 *)p)->f18=0;
    ((struct Obj03241 *)p)->f1C=func_021B9BA4(func_021BC964,p,0);
}








int func_021BC93C(u8 *p)
{
    if (((struct Obj08003 *)p)->f18==0) {
        if (((struct Obj08003 *)p)->f14==0) {
            func_02030EAC(((struct Obj08003 *)p)->f1C);
            ++((struct Obj08003 *)p)->f18;
            return 1;
        }
    } else return 1;
    return 0;
}








/*
 * follower: callback func_021BC964 included in unit; function_starts seed.
 */
void func_021BC964(void *unused,u8 *p)
{
    int value;
    if (((struct Obj04448 *)p)->f14) {
        ((struct Obj04448 *)p)->f8+=((struct Obj04448 *)p)->f10;
        value=((struct Obj04448 *)p)->f8>>12;
        --((struct Obj04448 *)p)->f14;
    } else value=((struct Obj04448 *)p)->fC>>12;
    func_0207D658(0x4000050,((struct Obj04448 *)p)->f0,value);
}








u8 *func_021BC990(u8 *a,u8 *b,void *c)
{
    u8 *p;
    int i;
    unsigned x;
    p=func_02030734(42,188,1,d_021C3C68,309);
    *(u8 * *)&((struct Obj01249 *)p)->f0=a; *(u8 * *)&((struct Obj01249 *)p)->f4=b; ((struct Obj01249 *)p)->f8=c;
    *(u8 * *)&((struct Obj01249 *)p)->fC=func_021BF6D4(b);
    ((struct Obj01249 *)p)->f30=func_02045B38(0,2,146,42);
    for (i=0;i<3;i++) {
        x=func_021BAC44(*(u8 * *)&((struct Obj01249 *)p)->f0);
        *(void **)(p+0x34+i*4)=func_02027F60(0,8,x,func_021BAC4C(*(u8 * *)&((struct Obj01249 *)p)->f0),42);
    }
    func_02049B40(43,9,0,448,64,42);
    func_021BD194(p);func_021BD044((Object_021BD044 *)p);func_021BD114((Object_021BD114 *)p);func_021BD2F0(p);
    return p;
}








/*
 * extent: two bytes zero alignment padding after return.
 */
void func_021BCA30(u8 *p)
{
    int i;
    func_021BCAD8((Object_021BC564 *)p);
    func_0204B3B4(((struct Obj00295 *)p)->f28);
    func_0204ADA4((u32)(((struct Obj00295 *)p)->f1C));
    func_0204A8D4((u32)(((struct Obj00295 *)p)->f20));
    func_0204AFD8((u32)(((struct Obj00295 *)p)->f24));
    for (i=0;i<3;i++) func_02027FD8(*(void **)(p+0x34+i*4));
    func_021BD344(p); func_021BD174(p); func_021BD0D4(p);
    func_02045C04(((struct Obj00295 *)p)->f30);
    func_020307B0(p);
}







void func_021BCA84(u8 *p)
{
    int i;
    for (i=0;i<3;i++) if (*(void **)(p+0x64+i*4)) func_02028178(*(void **)(p+0x64+i*4));
    switch (((struct Obj06388 *)p)->f2C) {
    case 0: break;
    case 1: ((struct Obj06388 *)p)->f2C=2;
    case 2: if (!func_0204B98C(((struct Obj06388 *)p)->f28)) ((struct Obj06388 *)p)->f2C=3; break;
    case 3: ((struct Obj06388 *)p)->f2C=0; break;
    }
    func_021BD348((char *)p);
}







void func_021BCAD8(Object_021BC564 *p) {
    int i;
    for(i=0;i<3;i++) {
        if(p->records[i].s) { func_02045808(p->records[i].s); p->records[i].s=0; }
        if(p->windows[i]) { func_02028148(p->windows[i]); p->windows[i]=0; }
    }
    for(i=0;i<8;i++) func_0204B3DC((struct Obj_021BC160 *)(p->items[i]), 0);
    for(i=0;i<2;i++) func_0204B3DC((struct Obj_021BC160 *)(p->other[i]), 0);
    func_020409B4(0);
    func_0204B3DC((struct Obj_021BC160 *)(((struct Obj00295 *)p)->f28), 0);
}





/*
 * lever: counter initialized before record-base assignment; existing
 *   a-loop-counter-zero-before-an-offset-assignment-schedules-before-its-spill.
 * evidence: own CAD8 establishes records[3], windows[3], items[8], other[2]
 *   and their offsets. Both loops use indices0..1; all selected fields are
 *   in those arrays. Stores/pointers keep original call order and word width.
 * abi: F7C4 own void thunk tail-forwards input00 to ARM9 24158; full
 *   8-byte target returns byte03 bit2 (0/1), consumed by original CB50.
 *   27FEC fourth argument explicitly truncated to u8 by original caller.
 */
void func_021BCB50(Object_021BCB50 *p)
{
    int i;
    Record_021BCB50 *records;
    func_021BCAD8((Object_021BC564 *)p);
    i=0;
    records=p->records;
    for(;i<2;i++) {
        p->records[i].s=func_02045EC0(p->bank,i+14);
        p->records[i].x=0x39e3;
        p->records[i].flag=(i==1);
        p->menus[i]=(struct T *)func_02027FEC((u32)p->windows[i],(u32)&records[i],23,(u8)(i*3+18),9,42);
        func_020282AC(p->menus[i],p->windows[i],8,0x3545,0x7b2c);
    }
    func_021BCD44((u8 *)p);
    func_020409B4(0);
    if(func_021BF7C4(p->f04)==0 && func_021BF6D8(p->f04)==2) {
        func_0204B3DC((struct Obj_021BC160 *)(p->items[0]), 1);
        func_0204B3DC((struct Obj_021BC160 *)(p->items[1]), 1);
        func_0204B3DC((struct Obj_021BC160 *)(p->items[2]), 1);
        func_0204B3DC((struct Obj_021BC160 *)(p->items[3]), 1);
        func_0204B3DC((struct Obj_021BC160 *)(p->items[4]), 1);
        func_0204B3DC((struct Obj_021BC160 *)(p->items[5]), 1);
        func_0204B3DC((struct Obj_021BC160 *)(p->items[6]), 1);
        for(i=0;i<2;i++) func_0204B3DC((struct Obj_021BC160 *)(p->other[i]), 1);
    }
    func_021BCCA8((Object *)p);
}




void func_021BCC58(u8 *p)
{
    func_021BCAD8((Object_021BC564 *)p);
    func_0204B3DC((struct Obj_021BC160 *)(((struct Obj00295 *)p)->f8C), 1);
    if (func_021BF6DC(*(u8 * *)&((struct Obj00295 *)p)->f4) == 0) func_021BD248(p);
    else func_021BD264((Object_021BD264 *)p);
}







void func_021BCC88(u8 *p)
{
    func_021BCAD8((Object_021BC564 *)p);
    func_0204B3DC((struct Obj_021BC160 *)(((struct Obj00295 *)p)->f28), 1);
    func_0204B878((struct Obj_021BC1B8 *)(((struct Obj00295 *)p)->f28), 1);
    ((struct Obj00295 *)p)->f2C = 0;
}







void func_021BCCA8(Object *p) {
    int old,new;
    int selected;
    int i;
    int state;
    old=-1; new=-1;
    selected=func_021BF6E4(((struct Obj13784 *)p)->f4);
    for(i=1;i<=5;i++) {
        state=func_0204B898(p->items[i]);
        if(state==d_021C38DF[i*2+1]) { old=i; break; }
    }
    for(i=0;i<5;i++) {
        if(i==selected) { new=d_021C38D4[i]; break; }
    }
    if(old>=0 && old!=new) func_021BD470((u8 *)p,old);
    for(i=0;i<5;i++) func_021BD0F8((u8 *)p,d_021C38D4[i],i==selected);
    if(new>=0 && old!=new) func_021BD448((u8 *)p,new);
}







/*
 * Reads r0 after BF824 and supplies p+4; preserve return and visible argument.
 */
void func_021BCD44(u8 *p)
{
    if (func_021BF824(*(u8 * *)&((struct Obj06389 *)p)->f4) != 0) {
        func_020282AC(((struct Obj06389 *)p)->f64, *(u16 * *)&((struct Obj06389 *)p)->f34, 8, 0x3545, 0x7b2c);
    } else {
        func_020282AC(((struct Obj06389 *)p)->f64, *(u16 * *)&((struct Obj06389 *)p)->f34, 14, 0x3545, 0x7b2c);
    }
}







void func_021BCD80(u8 *p) {
    if (func_021BF7FC(*(u8 * *)&((struct Obj01144 *)p)->f4))
        func_020282AC(((struct Obj01144 *)p)->f64,((struct Obj01144 *)p)->f34,8,0x3545,0x7b2c);
    else
        func_020282AC(((struct Obj01144 *)p)->f64,((struct Obj01144 *)p)->f34,14,0x3545,0x7b2c);
    if (func_021BF808(*(u8 * *)&((struct Obj01144 *)p)->f4))
        func_020282AC(((struct Obj01144 *)p)->f68,((struct Obj01144 *)p)->f38,8,0x3545,0x7b2c);
    else
        func_020282AC(((struct Obj01144 *)p)->f68,((struct Obj01144 *)p)->f38,14,0x3545,0x7b2c);
}







void func_021BCDE0(u8 *p)
{
    if (func_021BF6DC(*(u8 * *)&((struct Obj10278 *)p)->f4) == 1) func_021BCFBC((char *)p, 2, 1);
}







int func_021BCDFC(char *p) { if (func_021BF6DC(*(u8 * *)&((struct Obj06390 *)p)->f4)==1) { if (func_021BCFF0(p,2)) return 1; return 0; } return 1; }







void func_021BCE24(void *p) { func_021BD0F8(p,7,1); }







int func_021BCE30(char *p) { if (func_0204B98C(((struct Obj06390 *)p)->f8C)==0) return 1; return 0; }







void func_021BCE48(void *p, int a1, int a2) { func_021BD0F8(p, 7, 0); }







/*
 * Extent ends in two-byte alignment padding at 0x021BCE6E.
 */
void func_021BCE54(char *p) { if (func_021BF6DC(*(u8 * *)&((struct Obj10278 *)p)->f4)==1) func_021BCFBC(p,1,1); }







int func_021BCE70(char *p) { int result; if (func_021BF6DC(*(u8 * *)&((struct Obj06390 *)p)->f4)==1) { result=1; if (func_021BCFF0(p,1)) { func_020282A4(((struct Obj06390 *)p)->f68); return result; } } else { return 1; } return 0; }







/*
 * Extent ends in two-byte alignment padding at 0x021BCEBA.
 */
void func_021BCEA0(char *p) { if (func_021BF6DC(*(u8 * *)&((struct Obj10278 *)p)->f4)==1) func_021BCFBC(p,0,1); }







static inline int Check(char *p, int zero)
{
    u32 value;
    value = func_021BCFF0(p, zero);
    p = 0;
    if (value) p = (char *)1;
    return (int)p;
}







/*
 * extent: 38-byte function followed by two zero alignment bytes.
 * lever: inline helper reuses its dying pointer for the zero/one result;
 *   zero assignment remains explicit, and the allocator shares r4.
 */
int func_021BCEBC(char *p)
{
    if (func_021BF6DC(*(u8 * *)&((struct Obj06390 *)p)->f4)==1) {
        return Check(p, 0);
    }
    return 1;
}







/*
 * Extent ends in two-byte alignment padding at 0x021BCF16.
 */
void func_021BCEE4(char *p,u32 mode) { switch(mode) { case 0: func_021BCDE0((u8 *)p); break; case 1: func_021BCE24(p); break; case 2: func_021BCE54(p); break; case 3: func_021BCEA0(p); break; } }







void func_021BCF18(void *p,int mode) { switch(mode) { case 0: func_021BD0F8(p,0,1); break; case 1: func_021BD0F8(p,6,1); break; } }







int func_021BCF38(char *p,u32 mode) { switch(mode) { case 0: return func_021BCDFC(p); case 1: return func_021BCE30(p); case 2: return func_021BCE70(p); case 3: return func_021BCEBC(p); } return 1; }







void func_021BCF70(void *p, int i, int j) { if (i == 1) { func_021BCE48(p, i, j); } }







/*
 * extent: two zero padding bytes at 0x021BCFBA.
 */
void func_021BCF7C(u8 *p, int n, int v) {
    int i;
    void **a = (void **)(p + 0x64);
    if (a[n]) {
        for (i = 0; i < 3; i++) {
            if (*(void **)(p + 0x64 + i * 4)) func_02028218(*(void **)(p + 0x64 + i * 4), 0);
        }
        func_02028218(a[n], v);
    }
}







void func_021BCFBC(char *p,u32 index,int value) { int i; for(i=0;i<3;i++) { if (*(void **)((u32)p+(u32)i*4+0x64)) func_02028218(*(void **)((u32)p+(u32)i*4+0x64),0); } if (*(void **)((u32)p+index*4+0x64)) func_0202822C(*(char **)((u32)p+index*4+0x64),value); }







u32 func_021BCFF0(char *p,u32 index) { return func_02028230(*(u8 **)((u32)p+index*4+0x64)); }







/*
 * Extent ends in two-byte alignment padding at 0x021BD026.
 */
int func_021BD000(char *p) { if (func_0204B3F4(((struct Obj08004 *)p)->f28) && ((struct Obj08004 *)p)->f2C==0) { func_0204B878((struct Obj_021BC1B8 *)(((struct Obj08004 *)p)->f28), 9); ((struct Obj08004 *)p)->f2C=1; return 1; } return 0; }







int func_021BD028(u8 *p)
{
    if(func_0204B3F4(((struct Obj13786 *)p)->f28) && ((struct Obj13786 *)p)->f2C!=3) return 0;
    return 1;
}







void func_021BD044(Object_021BD044 *p) {
    void *h;
    int i;
    short x;
    h=func_020490F4(43,42);
    func_021BAC64(p->root, (Triple *)((u8 *)p+0x10), 0, 0);
    ((struct Obj01249 *)p)->f14=(void *)func_0204A6C8(h,13,0,0,42);
    ((struct Obj01249 *)p)->f18=(void *)func_0204AF28(h,35,41,42);
    func_02049238(h);
    for(i=0;i<8;i++) {
        x=24*i;
        if(i==7) x=0;
        p->items[i]=func_021BAC78(p->root, (Triple *)((unsigned int *)((u8 *)p+0x10)), (int)x, (int)168, (int)0, 1);
        func_021BD0F8((u8 *)p,i,0);
        func_0204B3DC((struct Obj_021BC160 *)(p->items[i]), 0);
    }
}







void func_021BD0D4(u8 *p)
{
    int i;
    for(i=0;i<8;i++) func_0204B3B4(*(void **)(p+i*4+0x70));
    func_0204A8D4(((struct Obj13787 *)p)->f14);
    func_0204AFD8(((struct Obj13787 *)p)->f18);
}







/*
 * lever: integer table-base arithmetic forms table+i*2 before adding flag;
 * d_021C38DF[i*2+flag] combined the two indices first (11 concrete bytes differed).
 */
void func_021BD0F8(u8 *p,int i,int flag)
{
    func_0204B878((struct Obj_021BC1B8 *)(*(void **)(p+i*4+0x70)), *(u8 *)((u32)d_021C38DF+i*2+flag));
}







void func_021BD114(Object_021BD114 *p) {
    u8 i;
    for(i=0;i<2;i++) {
        p->items[i]=func_021BAC78(p->root, (Triple *)((unsigned int *)((u8 *)p+0x10)), (int)(d_021C38D9[3*i]), (int)(d_021C38D9[3*i+1]), (int)0, 1);
        func_0204B878((struct Obj_021BC1B8 *)(p->items[i]), d_021C38D9[3*i+2]);
        func_0204B3DC((struct Obj_021BC160 *)(p->items[i]), 0);
    }
}







void func_021BD174(u8 *p)
{
    u8 i;
    for(i=0;i<2;i++) func_0204B3B4(*(void **)(p+i*4+0x90));
}







void func_021BD194(u8 *p) {
    void *h;
    int a;
    Params t;
    h=func_020490F4(func_020275E4(),42);
    ((struct Obj02462 *)p)->f1C=(void *)func_0204AC18(h,func_02027614(),0,384,0,3,42);
    ((struct Obj02462 *)p)->f20=(void *)func_0204A6C8(h,func_02027618(),0,0,42);
    a=func_0202761C(1);
    ((struct Obj02462 *)p)->f24=(void *)func_0204AF28(h,a,func_02027620(1),42);
    func_02049238(h);
    func_02082BCC(&t,0,8);
    t.x=232; t.y=168; t.z=1; t.a=0; t.b=3;
    ((struct Obj02462 *)p)->f28=func_0204B294((void *)func_021BAC40(((struct Obj02462 *)p)->f0),(u32)((struct Obj02462 *)p)->f20,(u32)((struct Obj02462 *)p)->f1C,(u32)((struct Obj02462 *)p)->f24,&t,0,42);
    func_0204B92C(((struct Obj02462 *)p)->f28,1);
    func_0204B3DC((struct Obj_021BC160 *)(((struct Obj02462 *)p)->f28), 0);
    ((struct Obj02462 *)p)->f2C=0;
}







/*
 * Extent remainder: two-byte zero alignment padding.
 */
void func_021BD248(u8 *p)
{
    func_0204B3DC((struct Obj_021BC160 *)(((struct Obj10279 *)p)->f28), 1);
    func_0204B878((struct Obj_021BC1B8 *)(((struct Obj10279 *)p)->f28), 1);
    ((struct Obj10279 *)p)->f2C=0;
}







void func_021BD264(Object_021BD264 *p) {
    int i;
    for(i=0;i<3;i++) {
        p->records[i].s=func_02045EC0(p->bank,i+18);
        p->records[i].x=0x39e3;
        p->records[i].flag=i==2;
        p->windows[i]=(void *)func_02027FEC((u32)p->a[i],(u32)(&p->records[i]),(u8)(5+9*i),(int)21,9,42);
        func_020282AC(p->windows[i],p->a[i],8,0x3545,0x7b2c);
    }
    func_021BCD80((u8 *)p);
    func_020409B4(0);
}







/*
 * extent: two zero padding bytes at 0x021BD342.
 */
void func_021BD2F0(u8 *p) {
    void *obj;
    void *handle;
    u8 *data;
    handle = func_02049F34(43, 7, (u32)(&obj), 42);
    data = *(u8 * *)&((struct Obj22377 *)obj)->fC;
    func_02082D44(data + 0x96, p + 0x98, 10);
    func_02082D44(data + 0x76, p + 0xa2, 10);
    func_020307B0(handle);
    func_02082D44(p + 0x98, p + 0xac, 10);
    ((struct Obj22376 *)p)->fB8 = 0;
}








void func_021BD344(u8 *a0) { }







static inline void lerp(u16 *p, int n, u16 a, u16 b)
{
 u8 r,g,blue; int dr,dg,db;
 g=(a&0x3E0)>>5;
 r=a&31;
 blue=(a&0x7C00)>>10;
 db=((u8)((b&0x7C00)>>10)-blue)*n>>12;
 dr=((u8)(b&31)-r)*n>>12;
 dg=((u8)((b&0x3E0)>>5)-g)*n>>12;
 *p=(u8)(r+dr)|((u8)(g+dg)<<5)|((u8)(blue+db)<<10);
}







/*
 * lever: the RGB555 lerp is a static inline helper (u16 colour params, as ov105 func_021B8734)
 */
void func_021BD348(char *p)
{
    int j;
    short t;
    u8 i;
    if (F + 0x400 >= 0x10000)
        F = F - 0xFC00;
    else
        F = F + 0x400;
    j = F >> 4;
    t = (tbl_020A1B38[j * 2 + 1] + 0x1000) / 2;
    for (i = 0; i < 5; i++) {
        lerp((u16 *)(p + i * 2 + 0xAC), t, *(u16 *)(p + i * 2 + 0x98), *(u16 *)(p + i * 2 + 0xA2));
    }
    func_02061CA4((void *)14, 0x56, (u32)(p + 0xAC), 10);
}







void func_021BD448(u8 *p,int i)
{
    func_0204B6F4(*(void **)(p+i*4+0x70),2,1);
    func_02082D44(p+0x98,p+0xac,10);
    ((struct Obj22378 *)p)->fB8=0;
}







void func_021BD470(u8 *p,int i)
{
    func_0204B6F4(*(void **)(p+i*4+0x70),6,1);
}







int func_021BD484(void *a,int *state,int c,void *p) {
    u8 *obj;
    switch(*state) {
    case 0:
        func_02034AC4((int)d_00000043);
        func_0203064C(1,41,0x18000);
        func_0203064C(1,42,0x32000);
        obj=func_021BD5C4(a,(u8 *)c);
        func_021B9BEC(((struct Obj03242 *)obj)->f14,0);
        ++*state;
        break;
    case 1:
        obj=p;
        if(func_021B9C74((unsigned int)(((struct Obj03242 *)obj)->f14))) {
            if(((struct Obj03242 *)obj)->f4==2) obj[0x68]=func_021BABE8(((struct Obj03242 *)obj)->f14);
            else obj[0x68]=0;
            func_021B9BEC(((struct Obj03242 *)obj)->f14,4);
            ++*state;
        }
        break;
    case 2:
        obj=p;
        if(func_021B9C74((unsigned int)(((struct Obj03242 *)obj)->f14))) {
            func_021BD7A0(obj, (Handler)func_021BD894);
            func_0203D34C(1,42);
            return 1;
        }
        break;
    }
    func_02030D28(((struct Obj03242 *)obj)->f7C);
    return 0;
}







/*
 * extent: unlabelled substantial switch leaf at 0x021BD578, excluded.
 */
int func_021BD534(void *a,int b,int c,u8 *p) {
    int result;
    int x;
    x=func_020362DC(); ((struct Obj05294 *)p)->f34=x;
    x=func_0203630C(); ((struct Obj05294 *)p)->f36=x;
    x=func_0203633C(); ((struct Obj05294 *)p)->f38=x;
    func_02051C88(((struct Obj05294 *)p)->f44);
    if (*(void (**)(u8 *,void *))(p+0x30)) {
        (*(void (**)(u8 *,void *))(p+0x30))(p,p+0x2c);
        result=0;
    } else result=(*(int (**)(u8 *,void *))(p+0x24))(p,p+0x20);
    func_02030D28(((struct Obj05294 *)p)->f7C);
    return result;
}







/*
 * extent: independent switch leaf following func_021BD534; all registers
 * are incoming arguments; each arm returns through bx lr.
 */
void func_021BD578(int value,unsigned int which,u8 *p) {
    switch(which) {
    case 0: ((struct Obj10281 *)p)->f3C=value; break;
    case 1:
    case 3: ((struct Obj10281 *)p)->f3C=1; break;
    case 2: break;
    default: ((struct Obj10281 *)p)->f3C=1; break;
    }
}







int func_021BD5A0(void *a,int b,int c,u8 *p)
{
    func_021BD764(p,a);
    func_020306F0(41);
    func_020306F0(42);
    func_02034A5C((int)ov067_id);
    return 1;
}







u8 *func_021BD5C4(struct Obj0203159C *owner,u8 *input)
{
    u8 *p;
    struct Ctx *q;
    p=func_0203159C(owner,128,41);
    *(u8 **)p=input;
    *(u32 *)(p+4)=func_02024144(input);
    *(u32 *)(p+0x70)=func_0202421C(*(u8 **)p);
    func_02024168((const struct Input *)(*(u8 **)p),(u16 *)(p+0x10),(u16 *)(p+8));
    if(*(u32 *)(p+4)==2) func_021BD690(p+0x64,(u16 *)(p+8));
    q=func_02030734(41,func_02030CB0(5),0,d_021C3C78,579);
    *(struct Ctx **)(p+0x78)=q;
    *(struct Ctx **)(p+0x7c)=func_02030CBC(5,q);
    *(void **)(p+0x18)=func_021B95A0(41,*(void **)p);
    *(void **)(p+0x14)=func_021B9A50(p,*(void **)(p+0x18));
    *(void **)(p+0x44)=func_02051B84((u8 *)d_021C3908,(int)func_021BD578,(int)p,41);
    p[0x69]=0;
    *(u32 *)(p+0x30)=0;
    *(u32 *)(p+0x2c)=0;
    *(u16 *)(p+0x4a)=0;
    *(u16 *)(p+0x48)=0;
    *(u32 *)(p+0x3c)=1;
    *(void **)(p+0x1c)=func_021BAEDC(p,*(void **)(p+0x18),41);
    func_021BF4F8(p,(u32)func_021BF508);
    return p;
}







/*
 * No witness outside this caller; tu --suggest-split leaves it out.
 * Scratch one verdict EXACT (4 bytes), fixed compiler/flags, no region:
 * typedef unsigned short u16;
 * unsigned int func_02024530(const u16 *p) { return p[1]; }
 * Extent remainder: two-byte zero alignment padding.
 */
void func_021BD690(u8 *p, u16 *out)
{
    *(short *)p=func_0202452C(out);
    p[3]=func_02024584(*(short *)p);
    p[2]=func_02024530(out);
}







void func_021BD6B4(State_021BD6B4 *p, void *out) {
    p->b++;
    if (p->b >= p->c) {
        p->b = 0;
        p->a++;
        if (p->a >= 5) p->a = 0;
        p->c = func_02024584(p->a);
    }
    func_02024598(out, p->a, p->b);
}







void func_021BD6F8(State_021BD6F8 *p,void *out) {
 p->b--;
 if(p->b<0) { p->a--; if(p->a<0) p->a=4; p->c=func_02024584(p->a); p->b=p->c-1; }
 func_02024598(out,p->a,p->b);
}







void func_021BD740(u8 *p,void *out,int v)
{
    p[2]=0;
    ((struct Obj05295 *)p)->f0=v;
    p[3]=func_02024584(((struct Obj05295 *)p)->f0);
    func_02024598(out,((struct Obj05295 *)p)->f0,*(s8 *)&((struct Obj05295 *)p)->f2);
}






void func_021BD764(u8 *p,void *a)
{
    func_02024224(*(void **)p,*(void **)(p+0x70));
    func_02051C6C(*(void **)(p+0x44));
    func_021B9B20(*(u8 **)(p+0x14));
    func_02030DA4(*(void **)(p+0x7c));
    func_020307B0(*(void **)(p+0x78));
    func_021B95F4(*(char **)(p+0x18));
    func_021BAF4C(*(u32 *)(p+0x1c));
    func_020315D4(a);
}






void func_021BD7A0(u8 *p,Handler fn) {
 *(Handler *)&((struct Obj00012 *)p)->f24=fn; ((struct Obj00012 *)p)->f20=0;
 if(fn==func_021BD894) { func_021BAE24(((struct Obj00012 *)p)->f14,p,((struct Obj00012 *)p)->f18); *(Handler *)&((struct Obj00012 *)p)->f74=(Handler)func_021BD8A8; }
 else if(fn==(Handler)func_021BE4C0) { func_021BAE94(((struct Obj00012 *)p)->f14,p,((struct Obj00012 *)p)->f18); *(Handler *)&((struct Obj00012 *)p)->f74=(Handler)func_021BD8B8; }
 else if(fn==func_021BEDEC) { func_021BAED0(((struct Obj00012 *)p)->f14,p,((struct Obj00012 *)p)->f18); *(Handler *)&((struct Obj00012 *)p)->f74=(Handler)func_021BD8C8; }
 else *(Handler *)&((struct Obj00012 *)p)->f74=0;
}






int func_021BD808(u8 *p,void *q) {
 void (*cb)(u8 *,void *);
 if(((struct Obj00012 *)p)->f70==1) {
  if(func_02035C38()) return 0;
  if(func_0203630C()) { cb=*(void (**)(u8 *,void *))(p+0x74); ((struct Obj00012 *)p)->f70=0; if(cb) cb(p,q); return 1; }
 } else {
  if(func_0203630C()) return 0;
  if(func_02035C38()) { cb=*(void (**)(u8 *,void *))(p+0x74); ((struct Obj00012 *)p)->f70=1; if(cb) cb(p,q); return 1; }
 }
 return 0;
}





void func_021BD868(u8 *p)
{
    func_020061E4(1356);
    func_021BED84(p+0x54,p);
    ((struct Obj13788 *)p)->f28=(u32)func_021BEDEC;
    func_021B9BEC(*(u8 * *)&((struct Obj13788 *)p)->f14,12);
}





extern int (*const d_021C3920[])(u8 *,void *);





int func_021BD894(u8 *p,void *q) { return d_021C3920[*(unsigned *)(p+4)](p,q); }





int func_021BD8A8(u8 *p) { return func_021BAE24((u8 *)(((struct Obj13789 *)p)->f14), p, ((struct Obj13789 *)p)->f18); }





int func_021BD8B8(u8 *p) { return func_021BAE94((u8 *)(((struct Obj13790 *)p)->f14), p, ((struct Obj13790 *)p)->f18); }





int func_021BD8C8(u8 *p) { return func_021BAED0((u8 *)(((struct Obj13791 *)p)->f14), p, ((struct Obj13791 *)p)->f18); }





int func_021BD8D8(u8 *p,u32 *q) {
    switch(*q) {
    case 0:
        if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) {
            if(((struct Obj00012 *)p)->f34&64) {
                func_020061E4(1352); ((struct Obj00012 *)p)->f48=1;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,7); *q=1;
            } else if(((struct Obj00012 *)p)->f34&136) {
                func_020061E4(1352); ((struct Obj00012 *)p)->f48=0;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,7); *q=1;
            } else if(((struct Obj00012 *)p)->f34&2) {
                func_020061E4(1361); func_021BF4F8(p,(u32)func_021BF608);
            } else if(((struct Obj00012 *)p)->f34&1) {
                func_020061E4(1356); func_021BF82C(p);
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,10); *q=5;
            }
        }
        break;
    case 1:
        if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) {
            if(((struct Obj00012 *)p)->f34&64) {
                func_020061E4(1352);
                if(((struct Obj00012 *)p)->f48) { ((struct Obj00012 *)p)->f48^=1; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,17); }
                else { func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,9); *q=0; }
            } else if(((struct Obj00012 *)p)->f34&128) {
                func_020061E4(1352);
                if(((struct Obj00012 *)p)->f48) { func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,9); *q=0; }
                else { ((struct Obj00012 *)p)->f48^=1; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,17); }
            } else if(((struct Obj00012 *)p)->f34&8) {
                func_020061E4(1352); ((struct Obj00012 *)p)->f48=0; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,17);
            } else if(((struct Obj00012 *)p)->f34&1) {
                if(((struct Obj00012 *)p)->f48==0) {
                    if(func_021BF680(p)) func_020061E4(1356); else func_020061E4(1367);
                    *q=2;
                } else { func_020061E4(1361); *q=3; }
            } else if(((struct Obj00012 *)p)->f34&2) { func_020061E4(1361); *q=3; }
        }
        break;
    case 2: *q=4; func_021BF4F8(p,(u32)func_021BF53C); break;
    case 3: *q=4; func_021BF4F8(p,(u32)func_021BF608); break;
    case 4: *q=1; break;
    case 6: if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,(Handler)func_021BE3B8); break;
    case 5: if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,(Handler)func_021BE4C0); break;
    }
    return 0;
}





/*
 * input: caller's incoming pointer in r0 is ignored; stub replaces it with the table.
 */
int func_021BDA84(u8 *unused)
{
    return func_02035C08(d_021C3938);
}




int func_021BDA94(u8 *unused)
{
    return func_02035C08(d_021C3948);
}




int func_021BDAA4(u8 *p) {
 int x,y;
 Box box=d_021C38F0;
 int i,count,result;
 if(!func_02035C60()) return -1;
 result=func_02035C08(&d_021C395C);
 if(result!=-1) {
  if(func_02024158((const u8 *)(((struct Obj10282 *)p)->f0))) { if((unsigned)(result-2)<=3) result=-1; return result; }
  return result;
 }
 count=func_021BABE8(((struct Obj10282 *)p)->f14);
 func_02035D20((unsigned int *)(&x),(unsigned int *)(&y));
 for(i=0;i<count;i++) { func_021BAC00(((struct Obj10282 *)p)->f14,(u8 *)(&box),i); if(func_02035D40((struct Ctx *)(&box),x,y)!=-1) return i+6; }
 return -1;
}




int func_021BDB50(u32 *p) {
 u32 x,y;
 int result;
 if(func_02024158((const u8 *)(*p))) return -1;
 if(!func_02035D20(&x,&y)) return -1;
 if(y>168) { result=x/24U-1; if(result>=0 && result<5) return result; }
 return -1;
}




/*
 * control-flow: inner hits 2/3 reach DC0A; outer states 2/3 preserve p for F4F8.
 * lever: preserve incoming r0 p at DA84/DA94 calls with their ignored pointer argument.
 */
int func_021BDB98(u8 *p,u32 *q)
{
    int hit;
    switch(*q) {
    case 0:
    case 1:
        if(((struct Obj00012 *)p)->f4==0) hit=func_021BDA84(p);
        else hit=func_021BDA94(p);
        switch(hit) {
        case 0:
            if(func_021BF680(p)) func_020061E4(1356);
            else func_020061E4(1367);
            *q=2;
            break;
        case 1:
            func_020061E4(1361);
            *q=3;
            break;
        case 2:
        case 3:
            func_020061E4(1356);
            func_021BF82C(p);
            ((struct Obj00012 *)p)->f4A=hit-2;
            func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,10);
            *q=5;
            break;
        }
        break;
    case 2: *q=4; func_021BF4F8(p,(u32)func_021BF53C); break;
    case 3: *q=4; func_021BF4F8(p,(u32)func_021BF608); break;
    case 4: *q=0; break;
    case 5:
        if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,(Handler)func_021BE4C0);
        break;
    }
    return 0;
}




int func_021BDC70(u8 *p,unsigned *q) {
 int result;
 if(*q<=1 && func_021BD808(p,q) && !((struct Obj00012 *)p)->f70) { func_020061E4(1352); return 0; }
 if(((struct Obj00012 *)p)->f70==0) { result=func_021BD8D8(p,q); }
 else { result=func_021BDB98(p,q); }
 return result;
}




/*
 * lever: The decoded table assigns the first callback arm to case 6 and the second to case 5.
 */
int func_021BDCB4(u8 *p,u32 *q)
{
    switch(*q) {
    case 0:
        if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) {
            if(((struct Obj00012 *)p)->f34&64) {
                func_020061E4(1352);
                ((struct Obj00012 *)p)->f48=1;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,7);
                *q=1;
            } else if(((struct Obj00012 *)p)->f34&136) {
                func_020061E4(1352);
                ((struct Obj00012 *)p)->f48=0;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,7);
                *q=1;
            } else if(((struct Obj00012 *)p)->f34&32) {
                if(((struct Obj00012 *)p)->f4A!=0) {
                    func_020061E4(1352);
                    ((struct Obj00012 *)p)->f4A=0;
                    func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,16);
                }
            } else if(((struct Obj00012 *)p)->f34&16) {
                if(((struct Obj00012 *)p)->f4A==0) {
                    func_020061E4(1352);
                    ((struct Obj00012 *)p)->f4A=1;
                    func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,16);
                }
            } else if(((struct Obj00012 *)p)->f34&2) {
                func_020061E4(1361);
                func_021BF4F8(p,(u32)func_021BF608);
            } else if(((struct Obj00012 *)p)->f34&1) {
                func_020061E4(1356);
                func_021BF82C(p);
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,10);
                *q=5;
            }
        }
        break;
    case 1:
        if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) {
            if(((struct Obj00012 *)p)->f34&64) {
                func_020061E4(1352);
                if(((struct Obj00012 *)p)->f48) { ((struct Obj00012 *)p)->f48^=1; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,17); }
                else { func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,9); *q=0; }
            } else if(((struct Obj00012 *)p)->f34&128) {
                func_020061E4(1352);
                if(((struct Obj00012 *)p)->f48) { func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,9); *q=0; }
                else { ((struct Obj00012 *)p)->f48^=1; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,17); }
            } else if(((struct Obj00012 *)p)->f34&8) {
                func_020061E4(1352); ((struct Obj00012 *)p)->f48=0; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,17);
            } else if(((struct Obj00012 *)p)->f34&1) {
                if(((struct Obj00012 *)p)->f48==0) {
                    if(func_021BF680(p)) func_020061E4(1356);
                    else func_020061E4(1367);
                    *q=2;
                } else { func_020061E4(1361); *q=3; }
            } else if(((struct Obj00012 *)p)->f34&2) { func_020061E4(1361); *q=3; }
        }
        break;
    case 2: *q=4; func_021BF4F8(p,(u32)func_021BF53C); break;
    case 3: *q=4; func_021BF4F8(p,(u32)func_021BF608); break;
    case 4: *q=1; break;
    case 6: if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,(Handler)func_021BE3B8); break;
    case 5: if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,(Handler)func_021BE4C0); break;
    }
    return 0;
}




int func_021BDEAC(u8 *p,unsigned *q) {
 if(*q<=1 && func_021BD808(p,q) && !((struct Obj00012 *)p)->f70) { func_020061E4(1352); return 0; }
 if(((struct Obj00012 *)p)->f70==0) { return func_021BDCB4(p,q); }
 else { return func_021BDB98(p,q); }
}


int func_021BDEF0(u8 *p,u32 *q)
{
    int keys;
    int accept;
    int index;
    switch(*q) {
    case 0:
        p[0x68]=func_021BABE8(*(u8 * *)&((struct Obj00012 *)p)->f14);
        *q=1;
    case 1:
        if(func_02024158((const u8 *)(*(u32 *)&((struct Obj00012 *)p)->f0))) {
            if(((struct Obj00012 *)p)->f38&32) break;
            if(((struct Obj00012 *)p)->f38&16) break;
        }
        keys=((struct Obj00012 *)p)->f34;
        if(keys&64) {
            func_020061E4(1352);
            if(((struct Obj00012 *)p)->f4A==0) {
                ((struct Obj00012 *)p)->f48=1;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,7);
                *q=2;
            } else if(p[0x68]>1 && ((struct Obj00012 *)p)->f4A!=0) {
                (((struct Obj00012 *)p)->f4A)--;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,16);
            }
        } else if(keys&128) {
            func_020061E4(1352);
            if(p[0x68]>1 && ((struct Obj00012 *)p)->f4A<p[0x68]-1) {
                (((struct Obj00012 *)p)->f4A)++;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,16);
            } else {
                ((struct Obj00012 *)p)->f48=0;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,7);
                *q=2;
            }
        } else if((keys&8) || ((accept=keys&1) && p[0x68]==0)) {
            func_020061E4(1352);
            ((struct Obj00012 *)p)->f48=0;
            func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,7);
            *q=2;
        } else if(((struct Obj00012 *)p)->f38&32) {
            func_020061E4(1636);
            ((struct Obj00012 *)p)->f4A=0;
            func_021BD6F8((State_021BD6F8 *)(p+0x64),p+8);
            func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,3);
            func_021BAC30(*(u8 * *)&((struct Obj00012 *)p)->f14,0);
            *q=3;
        } else if(((struct Obj00012 *)p)->f38&16) {
            func_020061E4(1636);
            ((struct Obj00012 *)p)->f4A=0;
            func_021BD6B4((State_021BD6B4 *)(p+0x64),p+8);
            func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,3);
            func_021BAC30(*(u8 * *)&((struct Obj00012 *)p)->f14,1);
            *q=3;
        } else if(keys&2) {
            func_020061E4(1361);
            func_021BF4F8(p,(u32)func_021BF608);
        } else if(accept) {
            func_020061E4(1356);
            func_021BF82C(p);
            func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,10);
            *q=8;
        }
        break;
    case 3: if(func_021B9C90((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14),3)) *q=0; break;
    case 2:
        if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) {
            if(((struct Obj00012 *)p)->f34&64) {
                func_020061E4(1352);
                if(((struct Obj00012 *)p)->f48) { ((struct Obj00012 *)p)->f48^=1; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,17); }
                else {
                    index=p[0x68]-1;
                    if(p[0x68]==0) index=0;
                    ((struct Obj00012 *)p)->f4A=index;
                    func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,9); *q=0;
                }
            } else if(((struct Obj00012 *)p)->f34&128) {
                func_020061E4(1352);
                if(((struct Obj00012 *)p)->f48) { ((struct Obj00012 *)p)->f4A=0; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,9); *q=0; }
                else { ((struct Obj00012 *)p)->f48^=1; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,17); }
            } else if(((struct Obj00012 *)p)->f34&8) {
                func_020061E4(1352); ((struct Obj00012 *)p)->f48=0; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,17);
            } else if(((struct Obj00012 *)p)->f34&1) {
                if(((struct Obj00012 *)p)->f48==0) {
                    if(func_021BF680(p)) func_020061E4(1356);
                    else func_020061E4(1367);
                    *q=4;
                } else { func_020061E4(1361); *q=5; }
            } else if(((struct Obj00012 *)p)->f34&2) { func_020061E4(1361); *q=5; }
        }
        break;
    case 4: *q=6; func_021BF4F8(p,(u32)func_021BF53C); break;
    case 5: *q=6; func_021BF4F8(p,(u32)func_021BF608); break;
    case 6: *q=2; break;
    case 7: if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,(Handler)func_021BE3B8); break;
    case 8: if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,(Handler)func_021BE4C0); break;
    }
    return 0;
}


int func_021BE1B8(u8 *p,u32 *q)
{
    int hit;
    int index;
    switch(*q) {
    case 0:
        p[0x68]=func_021BABE8(*(u8 * *)&((struct Obj00012 *)p)->f14);
        *q=1;
    case 1:
    case 2:
        index=func_021BDB50((u32 *)p);
        if(index>-1) {
            ((struct Obj00012 *)p)->f4A=0;
            func_021BD740((u8 *)(p+0x64),p+8,index);
            func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,3);
            func_020061E4(1352);
            *q=3;
        } else {
            hit=func_021BDAA4(p);
            switch(hit) {
            case 0:
                if(func_021BF680(p)) func_020061E4(1356);
                else func_020061E4(1367);
                ((struct Obj00012 *)p)->f48=0;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,8);
                *q=hit+4;
                break;
            case 1:
                func_020061E4(1361);
                ((struct Obj00012 *)p)->f48=1;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,8);
                *q=hit+4;
                break;
            case 2:
            case 4:
                func_020061E4(1636);
                ((struct Obj00012 *)p)->f4A=0;
                func_021BD6F8((State_021BD6F8 *)(p+0x64),p+8);
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,3);
                func_021BAC30(*(u8 * *)&((struct Obj00012 *)p)->f14,0);
                *q=3;
                break;
            case 3:
            case 5:
                func_020061E4(1636);
                ((struct Obj00012 *)p)->f4A=0;
                func_021BD6B4((State_021BD6B4 *)(p+0x64),p+8);
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,3);
                func_021BAC30(*(u8 * *)&((struct Obj00012 *)p)->f14,1);
                *q=3;
                break;
            case 6:
            case 7:
                func_020061E4(1356);
                func_021BF82C(p);
                ((struct Obj00012 *)p)->f4A=hit-6;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,10);
                *q=8;
                break;
            }
        }
        break;
    case 3: if(func_021B9C90((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14),3)) *q=0; break;
    case 4: *q=6; func_021BF4F8(p,(u32)func_021BF53C); break;
    case 5: *q=6; func_021BF4F8(p,(u32)func_021BF608); break;
    case 6: *q=2; break;
    case 7: if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,(Handler)func_021BE3B8); break;
    case 8: if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,(Handler)func_021BE4C0); break;
    }
    return 0;
}


int func_021BE374(u8 *p,unsigned *q) {
 if(*q<=2 && func_021BD808(p,q) && !((struct Obj00012 *)p)->f70) { func_020061E4(1352); return 0; }
 if(((struct Obj00012 *)p)->f70==0) { return func_021BDEF0(p,q); }
 else { return func_021BE1B8(p,q); }
}


int func_021BE3B8(u8 *p,u32 *q) {
    switch(*q) {
    case 0:
        if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) {
            if(((struct Obj00012 *)p)->f34&64) {
                func_020061E4(1352);
                if(((struct Obj00012 *)p)->f48) { ((struct Obj00012 *)p)->f48^=1; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,17); }
                else { func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,9); *q=0; }
            } else if(((struct Obj00012 *)p)->f34&128) {
                func_020061E4(1352);
                if(((struct Obj00012 *)p)->f48) { func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,9); *q=0; }
                else { ((struct Obj00012 *)p)->f48^=1; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,17); }
            } else if(((struct Obj00012 *)p)->f34&8) {
                func_020061E4(1352); ((struct Obj00012 *)p)->f48=0; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,17);
            } else if(((struct Obj00012 *)p)->f34&1) {
                func_020061E4(1356);
                if(((struct Obj00012 *)p)->f48==0) *q=1; else *q=2;
            } else if(((struct Obj00012 *)p)->f34&2) { func_020061E4(1356); *q=2; }
        }
        break;
    case 1: *q=3; func_021BF4F8(p,(u32)func_021BF53C); break;
    case 2: *q=4; func_021BF4F8(p,(u32)func_021BF608); break;
    case 3:
    case 4: *q=0; break;
    case 5: if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,func_021BD894); break;
    }
    return 0;
}


int func_021BE4C0(u8 *p,unsigned *q) {
 switch(*q) {
 case 0:
  if(func_021B9C90((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14),18) && func_021B9C90((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14),33) && func_021B9C90((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14),32)) func_021BEADC(p,q);
  break;
 case 1:
  if(func_021B9C90((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14),32)) {
   if(((struct Obj00012 *)p)->f50!=253) { ((struct Obj00012 *)p)->f4C=((struct Obj00012 *)p)->f50; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,18); }
   *q=0;
  }
  break;
 case 2:
  if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) { if(*(Handler *)&((struct Obj00012 *)p)->f28==func_021BD894) func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,4); *q=3; }
  break;
 case 3:
  if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,*(Handler *)&((struct Obj00012 *)p)->f28);
  break;
 case 4:
  if(func_021B9C90((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14),25)) *q=0;
  break;
 }
 return 0;
}


void func_021BE580(u8 *p,u32 *q)
{
    if((((struct Obj00189 *)p)->f34&8) && p[0x69]==1) {
        ((struct Obj00189 *)p)->f4C=252;
        if(func_021BB054(*(u8 * *)&((struct Obj00189 *)p)->f1C)) {
            func_021BD868(p);
            *q=2;
            return;
        }
        func_020061E4(1367);
        func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,18);
        return;
    }
    if(((struct Obj00189 *)p)->f3C==0 || (((struct Obj00189 *)p)->f34&4)) {
        func_020061E4(1355);
        p[0x69]^=1;
        func_021BF82C(p);
        func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,25);
        *q=4;
        return;
    }
    if(((struct Obj00189 *)p)->f34&2) {
        if(p[0x69]==1 && func_021BAFAC((u32)(*(u8 * *)&((struct Obj00189 *)p)->f1C))) {
            ((struct Obj00189 *)p)->f50=((struct Obj00189 *)p)->f4C;
            *q=1;
            if(((struct Obj00189 *)p)->f4C!=253) {
                ((struct Obj00189 *)p)->f4C=253;
                func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,18);
            }
            func_020061E4(1363);
            func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,32);
            func_021BB054(*(u8 * *)&((struct Obj00189 *)p)->f1C);
            func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,30);
            return;
        }
        if(p[0x69]==1 && ((struct Obj00189 *)p)->f4C!=254) {
            ((struct Obj00189 *)p)->f4C=254;
            func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,18);
        }
        func_020061E4(1361);
        func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,11);
        *(Handler *)&((struct Obj00189 *)p)->f28=func_021BD894;
        *q=2;
        return;
    }
    if(((struct Obj00189 *)p)->f34&1) {
        if(((struct Obj00189 *)p)->f4C==252) {
            if(func_021BB054(*(u8 * *)&((struct Obj00189 *)p)->f1C)) {
                func_021BD868(p);
                *q=2;
                return;
            }
            func_020061E4(1367);
            return;
        } else if(((struct Obj00189 *)p)->f4C==253) {
            if(p[0x69]==1 && func_021BAFAC((u32)(*(u8 * *)&((struct Obj00189 *)p)->f1C))) {
                ((struct Obj00189 *)p)->f50=((struct Obj00189 *)p)->f4C;
                *q=1;
                func_020061E4(1363);
                func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,32);
                func_021BB054(*(u8 * *)&((struct Obj00189 *)p)->f1C);
                func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,30);
                return;
            }
            func_020061E4(1367);
            return;
        } else if(((struct Obj00189 *)p)->f4C==254) {
            func_020061E4(1361);
            func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,11);
            *(Handler *)&((struct Obj00189 *)p)->f28=func_021BD894;
            *q=2;
            return;
        } else if(p[0x69]==0) {
            func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,33);
            if(func_021BEB44(p)) {
                func_021BD868(p);
                *q=2;
                return;
            }
            func_020061E4(1367);
            return;
        } else {
            func_021BAF7C((unsigned int)(*(u8 * *)&((struct Obj00189 *)p)->f1C),((struct Obj00189 *)p)->f4C);
            func_020061E4(1356);
            func_021BB054(*(u8 * *)&((struct Obj00189 *)p)->f1C);
            func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,30);
            func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,33);
            return;
        }
    }
    if(func_021BEB60(p)) {
        func_020061E4(1352);
        func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,18);
    }
}


int func_021BE7B8(u8 *p) {
 int n=func_02035C08(d_021C392C);
 if(n==-1) return 0;
 switch(n) {
 case 0: return 1;
 case 1: if(((struct Obj22380 *)p)->f3C==0) return 2; break;
 }
 return 0;
}


int func_021BE7F0(void) { return func_02035C08(d_021C3918); }


int func_021BE800(u8 *a0) {
 int x,y;
 Box_021BE800 box=d_021C39B0;
 int i,j;
 if(!func_02035C60()) return -1;
 func_02035D20((u32 *)(&x),(u32 *)(&y));
 for(i=0;i<4;i++) {
  box.b[0]=24*i+56; box.b[1]=box.b[0]+16;
  for(j=0;j<3;j++) { box.b[2]=80*j+12; box.b[3]=box.b[2]+72; if(func_02035D40((struct Ctx *)(&box),x,y)!=-1) return j+3*i; }
 }
 return -1;
}


int func_021BE890(void *a0) { Box_021BE890 box=d_021C39C4; return func_02035C08(&box); }


int func_021BE8B4(u8 *a0) {
 Box_021BE8B4 box;
 int x,y;
 Box_021BE8B4 template;
 int i,count;
 count=func_021BB1F4();
 i=0;
 if(count>0) {
  template=d_021C38F8;
  do { box=template; func_021BB224(i,&x,&y); box.b[0]=y+48; box.b[1]=y+64; box.b[2]=x+8; box.b[3]=x+24; if(func_02035C08(&box)!=-1) return i; i++; } while(i<count);
 }
 return -1;
}


void func_021BE934(u8 *p,u32 *q)
{
    int r;
    switch(func_021BE7B8(p)) {
    case 1:
        func_020061E4(1361);
        func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,11);
        *(Handler *)&((struct Obj00586 *)p)->f28=func_021BD894;
        *q=2;
        return;
    case 2:
        func_020061E4(1355);
        p[0x69]^=1;
        func_021BF82C(p);
        func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,25);
        *q=4;
        return;
    }
    if(p[0x69]==0) {
        r=func_021BE800(p);
        if(r>=0) {
            ((struct Obj00586 *)p)->f4C=r;
            func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,33);
            if(r>=12 || !func_021B999C(*(u8 * *)&((struct Obj00586 *)p)->f18,((struct Obj00586 *)p)->f4C)) {
                func_020061E4(1367);
                return;
            }
            func_021BD868(p);
            *q=2;
            return;
        }
    } else {
        r=func_021BE8B4(p);
        if(r>-1) {
            ((struct Obj00586 *)p)->f4C=r;
            func_021BAF7C((unsigned int)(*(u8 * *)&((struct Obj00586 *)p)->f1C),((struct Obj00586 *)p)->f4C);
            func_021BB054(*(u8 * *)&((struct Obj00586 *)p)->f1C);
            func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,30);
            func_020061E4(1356);
            func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,33);
            return;
        }
        switch(func_021BE890(p)) {
        case 0:
            ((struct Obj00586 *)p)->f4C=252;
            if(func_021BB054(*(u8 * *)&((struct Obj00586 *)p)->f1C)) {
                func_021BD868(p);
                *q=2;
                return;
            } else {
                func_020061E4(1367);
                return;
            }
        case 1:
            ((struct Obj00586 *)p)->f4C=253;
            if(func_021BAFAC((u32)(*(u8 * *)&((struct Obj00586 *)p)->f1C))) {
                ((struct Obj00586 *)p)->f50=((struct Obj00586 *)p)->f4C;
                *q=1;
                func_020061E4(1363);
                func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,32);
                func_021BB054(*(u8 * *)&((struct Obj00586 *)p)->f1C);
                func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,30);
                return;
            } else {
                func_020061E4(1367);
                return;
            }
        case 2:
            ((struct Obj00586 *)p)->f4C=254;
            func_020061E4(1361);
            func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,11);
            *(Handler *)&((struct Obj00586 *)p)->f28=func_021BD894;
            *q=2;
            break;
        case -1:
            break;
        }
    }
}


void func_021BEADC(u8 *p,void *q) {
    if(func_021BD808(p,q)) {
        if(p[105]==0) {
            if(*(u32 *)&((struct Obj00012 *)p)->f70==0 && !(func_020362DC()&2)) { func_020061E4(1352); return; }
        } else {
            if(*(u32 *)&((struct Obj00012 *)p)->f70==0) { func_020061E4(1352); return; }
        }
    }
    if(func_021B9C90((unsigned int)(((struct Obj00012 *)p)->f14),30)) {
        if(*(u32 *)&((struct Obj00012 *)p)->f70==0) func_021BE580(p,q);
        else func_021BE934(p,q);
    }
}


int func_021BEB44(u8 *p) { if(func_021B999C(*(u8 * *)&((struct Obj13792 *)p)->f18,((struct Obj13792 *)p)->f4C)!=0) return 1; return 0; }


extern int (*const d_021C3910[])(u8 *);


/*
 * extent: unlabelled follower 0x021BEB78, filed separately under its own shard.
 */
int func_021BEB60(u8 *p) { return d_021C3910[p[105]](p); }
