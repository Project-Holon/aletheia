/*
 * file:     c_gear.c
 * unit:     yes
 * function: func_021EFEC0, func_021EFEE4, func_021EFEF8, func_021EFF00, func_021EFF58, func_021F0000, func_021F0064, func_021F009C, func_021F0194, func_021F020C, func_021F0298, func_021F0300, func_021F0370, func_021F0390, func_021F05B4, func_021F05D0, func_021F06B8, func_021F0728, func_021F07AC, func_021F07EC, func_021F0824, func_021F0858, func_021F088C, func_021F08BC, func_021F09B4, func_021F09DC, func_021F0A0C, func_021F0A38, func_021F0A68, func_021F0AA0, func_021F0AC8, func_021F0AE0, func_021F0B00, func_021F0B7C, func_021F0B88, func_021F0C00, func_021F0C68, func_021F0C70, func_021F0CA0, func_021F0CB8, func_021F0CDC, func_021F0CF0, func_021F0D00, func_021F0D08, func_021F0D10, func_021F0D14, func_021F0D48, func_021F0D80, func_021F0DB4, func_021F0E70, func_021F0EB0, func_021F0F28, func_021F0F70, func_021F0FB0, func_021F0FF0, func_021F1000, func_021F1010, func_021F1060, func_021F11B4, func_021F122C, func_021F1290, func_021F133C, func_021F13FC, func_021F1458, func_021F1574, func_021F15FC, func_021F1624, func_021F1740, func_021F1758, func_021F18F0, func_021F1910, func_021F1950, func_021F1A44, func_021F1A64, func_021F1B30, func_021F1B50, func_021F1BBC, func_021F1BE4, func_021F1C0C, func_021F1CD8, func_021F1DB0, func_021F1DE8, func_021F1E98, func_021F1F24, func_021F1F70, func_021F1F80, func_021F20AC, func_021F2130, func_021F2180, func_021F21B4, func_021F21F8, func_021F2370, func_021F23CC, func_021F24C0, func_021F24FC, func_021F2508, func_021F251C, func_021F26E0, func_021F279C, func_021F27D8, func_021F2848, func_021F2980, func_021F2984, func_021F2994, func_021F29D8, func_021F2AB8, func_021F2AD4, func_021F2AEC, func_021F2B9C, func_021F2BB8, func_021F2BD4
 * address:  0x021EFEC0
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B878  0x0204B878  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_0204B49C  0x0204B49C  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B918  0x0204B918  arm
 *   func_0204B8F4  0x0204B8F4  arm
 *   func_0204B98C 0x0204B98C arm
 *   d_021F333C     0x021F333C  data  a4
 *   d_021F334C     0x021F334C  data  a4
 *   d_021F31BC     0x021F31BC  data  ov029  a2
 *   d_021F31AB     0x021F31AB  data  ov029  a1
 *   d_021F31B0     0x021F31B0  data  ov029  a1
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_0201058C  0x0201058C  thumb
 *   func_02158630  0x02158630  thumb  ov010
 *   _s32_div_f     0x0209C0A4  arm
 *   d_021F31EC     0x021F31EC  data  ov029  a4
 *   d_021F31F8     0x021F31F8  data  ov029  a4
 *   d_021F3255     0x021F3255  data  ov029  a1
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021F3292 0x021F3292 data ov029 a1
 *   d_021F3204 0x021F3204 data ov029 a1
 *   func_020215BC  0x020215BC  thumb
 *   d_021F31A8     0x021F31A8  data  ov029  a1
 *   func_02082BCC 0x02082BCC arm
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   d_021F323C     0x021F323C  data  a1
 *   d_021F32B3 0x021F32B3 data a1
 *   d_021F3344     0x021F3344  data  a4
 *   func_020221A4 0x020221A4 thumb
 *   func_0207D55C 0x0207D55C arm
 *   func_0201210C 0x0201210C thumb
 *   func_02189A48 0x02189A48 thumb ov021
 *   func_02021728  0x02021728  thumb
 *   func_02021730  0x02021730  thumb
 *   func_02021F64  0x02021F64  thumb
 *   func_02082D44  0x02082D44  arm
 *   d_021F31B6     0x021F31B6  data  a2
 *   func_0202173C  0x0202173C  thumb
 *   func_02021B18 0x02021B18 thumb
 *   func_02021ED8  0x02021ED8  thumb
 *   d_021F3324     0x021F3324  data  a4
 *   d_021F331C     0x021F331C  data  a4
 *   d_021F3410     0x021F3410  data  a4
 *   d_021F31D4     0x021F31D4  data  a2
 *   d_021F348C     0x021F348C  data  a4
 *   d_021F3334     0x021F3334  data  a4
 *   func_0204162C  0x0204162C  arm
 *   d_021F3354     0x021F3354  data  a4
 *   func_020091AC  0x020091AC  thumb
 *   d_021F332C     0x021F332C  data  a4
 *   func_02049F78  0x02049F78  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0207E468  0x0207E468  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0203FA08  0x0203FA08  arm
 *   func_02049658  0x02049658  arm
 *   func_02049990  0x02049990  arm
 *   d_021F31E0     0x021F31E0  data  a4
 *   d_021F32E0     0x021F32E0  data  a4
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0203D88C  0x0203D88C  arm
 *   func_0203D34C  0x0203D34C  arm
 *   d_021F31C8     0x021F31C8  data  a4
 *   d_021F33CC     0x021F33CC  data  a4
 *   func_02040588  0x02040588  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_0204047C  0x0204047C  arm
 *   func_02041300  0x02041300  arm
 *   d_021F338C     0x021F338C  data  ov029  a4
 *   d_021F33AC     0x021F33AC  data  a4
 *   d_021F336C     0x021F336C  data  ov029  a4
 *   func_0207D63C 0x0207D63C arm
 *   func_020355D8  0x020355D8  arm
 *   func_02035CB8  0x02035CB8  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021F2DA8  0x021F2DA8  thumb  ov029
 *   func_0203FB44  0x0203FB44  arm
 *   func_020090E8  0x020090E8  thumb
 *   func_0204B908  0x0204B908  arm
 *   func_0204B954  0x0204B954  arm
 *   func_02043598  0x02043598  arm
 *   func_02085D3C  0x02085D3C  arm
 *   func_0204BA20  0x0204BA20  arm
 *   d_021F3526     0x021F3526  data  ov029  a1
 *   d_021F3531     0x021F3531  data  ov029  a1
 *   d_021F353C     0x021F353C  data  ov029  a1
 *   d_021F3548     0x021F3548  data  ov029  a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02026C8C  0x02026C8C  thumb
 *   func_02026CA0  0x02026CA0  thumb
 *   func_02026C78  0x02026C78  thumb
 *   func_02165CD8  0x02165CD8  thumb  ov010
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_020090F0  0x020090F0  thumb
 *   func_0204B100  0x0204B100  arm
 *   func_0204B034  0x0204B034  arm
 *   func_0204B258  0x0204B258  arm
 *   func_02051B84  0x02051B84  arm
 *   d_021F3214     0x021F3214  data  a4
 *   d_021F3272     0x021F3272  data  a2
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_02051C6C  0x02051C6C  arm
 *   func_0204B084  0x0204B084  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_020403F4  0x020403F4  arm
 *   func_0203568C 0x0203568C arm
 *   d_021F3520 0x021F3520 data a1
 *   func_0203F4CC  0x0203F4CC  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0204B800  0x0204B800  arm
 *   func_02051C88  0x02051C88  arm
 *   func_021F2D50  0x021F2D50  thumb  ov029
 *   func_021F2DC8  0x021F2DC8  thumb  ov029
 *   func_021F2BF0  0x021F2BF0  thumb  ov029
 *   func_02030734  0x02030734  arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020072CC  0x020072CC  thumb
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_02009210  0x02009210  thumb
 *   func_0200910C  0x0200910C  thumb
 *   func_0200C6F0  0x0200C6F0  thumb
 *   func_02040B1C  0x02040B1C  arm
 *   func_02040E78  0x02040E78  arm
 *   func_02040AE0  0x02040AE0  arm
 *   func_0200734C  0x0200734C  thumb
 *   d_021F3554     0x021F3554  data  a4
 *   func_02030D28  0x02030D28  arm
 *   func_02021D50 0x02021D50 thumb
 *   func_0201214C  0x0201214C  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   func_02009100  0x02009100  thumb
 *   func_02021518  0x02021518  thumb
 *   func_02021EE4  0x02021EE4  thumb
 *   func_0202155C  0x0202155C  thumb
 *   func_020216D4  0x020216D4  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_02035010  0x02035010  arm
 *   func_02035040  0x02035040  arm
 *   func_021F2E10  0x021F2E10  thumb  ov029
 *   func_020120D8  0x020120D8  thumb
 *   func_021F3144  0x021F3144  thumb  ov029
 *   func_021F2D84  0x021F2D84  thumb  ov029
 *   func_021585E0  0x021585E0  thumb  ov010
 *   func_02158614  0x02158614  thumb  ov010
 *   func_021F2E5C  0x021F2E5C  thumb  ov029
 *   func_0203D8AC  0x0203D8AC  arm
 *   func_020215A0  0x020215A0  thumb
 *   func_02021540  0x02021540  thumb
 *   func_02030DA4  0x02030DA4  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02012A30  0x02012A30  thumb
 *   func_02028A70  0x02028A70  thumb
 *   func_02049238  0x02049238  arm
 *   func_020056EC  0x020056EC  thumb
 *   func_021F3190  0x021F3190  thumb  ov029
 *   func_02028A64  0x02028A64  thumb
 *   func_0202223C  0x0202223C  thumb
 *   func_02022230  0x02022230  thumb
 *   func_021F3098  0x021F3098  thumb  ov029
 *   func_021F3118  0x021F3118  thumb  ov029
 *   func_021F2EEC  0x021F2EEC  thumb  ov029
 *   func_021F2CD4  0x021F2CD4  thumb  ov029
 *   func_02009110 0x02009110 thumb
 *   func_02009134 0x02009134 thumb
 *   func_02009160 0x02009160 thumb
 */
#include "../../matched/include/Obj09784.h"
#include "../../matched/include/Obj05112.h"
#include "../../matched/include/Obj03631.h"
#include "../../matched/include/Obj00106.h"
#include "../../matched/include/Obj05115.h"
#include "../../matched/include/Obj09786.h"
#include "../../matched/include/Obj00042.h"
#include "../../matched/include/Obj20390.h"
#include "../../matched/include/Obj20391.h"
#include "../../matched/include/Obj04308.h"
#include "../../matched/include/Obj05116.h"
#include "../../matched/include/Obj02749.h"
#include "../../matched/include/Obj20392.h"
#include "../../matched/include/Obj13046.h"
#include "../../matched/include/Obj00811.h"
#include "../../matched/include/Obj06128.h"
#include "../../matched/include/Obj20395.h"
#include "../../matched/include/Obj00709.h"
#include "../../matched/include/Obj02111.h"
#include "../../matched/include/Obj07621.h"
#include "../../matched/include/Obj20396.h"
#include "../../matched/include/Obj13047.h"
#include "../../matched/include/Obj03633.h"
#include "../../matched/include/Obj00761.h"
#include "../../matched/include/Obj20398.h"

#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
struct Owner;
struct Actor;
struct Obj;
struct W;
struct Ctx;
struct BigObj;
struct PalAnmSlot;
struct Obj02021B18;
struct Sub020090B0Obj;
struct S;
struct Bank;
struct Sub0200852CObj;
struct RtcTime;
struct Node;
struct Vec2;
struct Big;
struct Sub02009210Obj;
struct Ctrl;
struct Buf2000;
struct Sub02007324Ctrl;
struct S02021D50;
struct Obj02021EE4;
struct SoundSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

struct Slot {
    void *obj;
    int a;
    int b;
};

struct Pt {
    s16 x;
    s16 y;
    u16 w;
    u8 z;
    u8 t;
};

struct Owner {
    unsigned char pad[0x3c];
    struct Slot s[20];
};

struct Pair {
    int a;
    int b;
};

struct W {
    u8 pad0[0x210];
    int unk_210;
    u8 pad1[0x1c];
    u16 unk_230[3][5];
    u16 unk_24E[3][5];
    u16 unk_26C[3];
    u16 unk_272[1][5];
};

struct S021F0B7C { unsigned short f0:1; };

typedef struct { u16 on:1, cnt:15; u16 f2; u8 f4, f5, f6, f7; } Ent;

typedef struct { unsigned short f0, f2, f4, f6; unsigned char f8, f9; } Record;

typedef enum { Zero } ZeroValue;

typedef struct { u8 key, row, col, v; } Ent_021F1010;

typedef struct { int w[6]; } Tab;

typedef signed int     s32;

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
    unsigned short x;
    unsigned short y;
    unsigned short z;
    unsigned char a;
    unsigned char b;
} S13Rec;

typedef struct {
    u32 hour;
    u32 minute;
    u32 second;
} RtcTime;

extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B9A0(struct Actor *a);
extern void func_0204B49C(struct Actor *actor, s16 value, u32 space, u32 axis);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 space, u16 heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern u16 func_0204B918(struct Obj *p);
extern u32 func_0204B8F4(struct Obj *p);
extern u32 func_0204B98C(struct Actor *a);
extern u32 func_02012138(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_0201058C(void *key);
extern int func_02158630(int);
extern void func_020215BC(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern void func_02082BCC(void *, int, int);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(unsigned int index);
extern unsigned int func_020221A4(void);
extern int func_0207D55C(volatile u16 *reg);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02189A48(char *p);
extern int func_02021728(char *p, int i);
extern int func_02021730(char *p, int i);
extern void func_02021F64(u16 *src, u16 *dst, int count, int weight, u16 color);
extern void func_02082D44(void *src, void *dst, int n);
extern int func_0202173C(void *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);
extern void func_02021B18(struct Obj02021B18 *o);
extern u32 func_02021ED8(const char *ptr);
extern u32 func_0204162C(int channel);
extern void func_020091AC(struct Sub020090B0Obj *obj, int row, int col, int kind, int marked, int flagged);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_020862F0(void *a, u32 b);
extern void func_0207E468(void *a, u32 b, u32 c);
extern u32 func_020307B0(void *p);
extern u32 func_0203FA08(u32 a, u32 b, u32 c);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern s32 func_0204ABF0(void *a, unsigned int b, unsigned int c, unsigned int d, u16 g);
extern s32 func_0204A6C8(void *a, unsigned int b, unsigned int c, unsigned int a3, u16 flags);
extern s32 func_0204AF28(void *owner, unsigned int first, unsigned int second, unsigned int mode);
extern void func_0203D88C(u32 a, u32 b);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_0207D63C(u32, int, int, int, int);
extern void func_020355D8(u8 v);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern void func_020061E4(u32 id);
extern int func_021F2DA8(u8 *p);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020090E8(struct Sub020090B0Obj *obj, u8 value);
extern void func_0204B908(int, int);
extern void func_0204B954(struct Actor *a, u32 v);
extern void func_02043598(u32 mask, u32 enable);
extern int func_02085D3C(void);
extern void func_0204BA20(struct Actor *a, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_02026C8C(void);
extern int func_02026CA0(int *p);
extern void *func_02026C78(int n);
extern u8 func_02165CD8(struct S *p);
extern unsigned char *func_02012944(void *p);
extern unsigned char func_02008550(const struct Sub0200852CObj *obj);
extern unsigned char func_020090F0(const struct Sub020090B0Obj *obj);
extern struct Bank *func_0204B100(int count, unsigned char flag, u32 heapId);
extern struct Obj *func_0204B034(unsigned char *a0, u32 a1, u32 heap);
extern void func_0204B258(struct Bank *bank, void *p);
extern void *func_02051B84(u8 *a0, int a1, int a2, int a3);
extern void func_0204AFD8(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_02051C6C(void *p);
extern void func_0204B084(int);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_020403F4(u32 i);
extern int func_0203568C(void);
extern void func_0203F4CC(struct RtcTime *time);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B800(struct Node *node, u32 val);
extern s32 func_02051C88(struct Ctx *c);
extern void func_021F2D50(u8 *p);
extern void func_021F2DC8(char *p);
extern int func_021F2BF0(char *p);
extern void *func_02030734(u32 heap, u32 size, int flag, const char *file, u16 line);
extern void *func_02012EBC(struct Big *p);
extern u32 func_020072CC(struct Ctrl *sv, u32 id, u8 heap, void *buf, u32 size);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern u16 func_0200910C(const struct Sub020090B0Obj *obj);
extern u32 func_0200C6F0(struct Buf2000 *p);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void func_02040E78(u32 a, void *src, u32 size, u32 ofs);
extern void func_02040AE0(u32 index, const void *src, u32 mode);
extern void func_0200734C(struct Sub02007324Ctrl *sv, u32 id);
extern void func_02030D28(struct Ctx *c);
extern void func_02021D50(struct S02021D50 *p);
extern u32 func_0201214C(const struct Ctx *p);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02030CB0(u32 n);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern u8 func_02009100(const struct Sub020090B0Obj *obj);
extern void *func_02021518(u32 heap);
extern void func_02021EE4(struct Obj02021EE4 *o, int v);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern int func_020056A0(void *callback, void *ctx, int a2);
extern void func_02035010(u32 a, u32 b);
extern void func_02035040(u32 a, u32 b);
extern void func_021F2E10(char *p, int *q);
extern int func_020120D8(char *p);
extern void func_021F3144(u8 *p, int v);
extern void func_021F2D84(u8 *p);
extern int func_021585E0(int a);
extern void func_02158614(void *p);
extern void func_021F2E5C(char *a);
extern void func_0203D8AC(void);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern void func_02030DA4(int a);
extern void func_02030EAC(struct Node *n);
extern u32 func_02012A30(const struct BigObj *p);
extern void func_02028A70(struct SoundSys *sys);
extern void func_02049238(int a);
extern u32 func_020056EC(u32 range);
extern void func_021F3190(int a, int b, int c, int d);
extern void func_02028A64(struct SoundSys *sys);
extern void func_0202223C(u32 a, u32 color);
extern void func_02022230(u32 which);
extern void func_021F3098(u8 *p);
extern void func_021F3118(void *p);
extern int func_021F2EEC(char *p, int k);
extern void func_021F2CD4(void);
extern u32 func_02009110(const struct Sub020090B0Obj *obj, int row, int col);
extern int func_02009134(const struct Sub020090B0Obj *obj, int row, int col);
extern u32 func_02009160(const struct Sub020090B0Obj *obj, int row, int col, int kind);
int func_021EFEC0(int a, int b);
void func_021EFEE4(unsigned char *p, unsigned int v);
void func_021EFEF8(char *p, void (*f)(void), int line);
void func_021EFF00(int x, int y, int *a, int *b);
void func_021EFF58(u8 *p, int a, int c);
struct Slot *func_021F0000(struct Owner *p);
int func_021F0064(unsigned char *p, int a, int b);
int func_021F009C(u8 *p);
void func_021F0194(u8 *p);
int func_021F020C(const void *p, int a, int b, int *c, int *d);
void func_021F0298(u8 *p);
void func_021F0300(u8 *p);
void func_021F0370(void *p);
void func_021F0390(u8 *p, int a, int b, int c, int e);
int func_021F05B4(unsigned char *p);
void func_021F05D0(u8 *p);
void func_021F06B8(u8 *p, int a, int b);
void func_021F0728(u8 *p);
void func_021F07AC(u8 *p, int i, u16 *e);
void func_021F07EC(void *p, int i, unsigned short *q);
void func_021F0824(void *p, int i, unsigned short *q);
void func_021F0858(void *p, int i, unsigned short *q);
void func_021F088C(void *p, int i, unsigned short *q);
void func_021F08BC(struct W *p, int i, int j, int k);
void func_021F09B4(unsigned char *p, unsigned char *q, int n);
int func_021F09DC(unsigned char *p, int i, int v, int a, int b, int j);
void func_021F0A0C(unsigned char *p);
void func_021F0A38(unsigned char *p);
int func_021F0A68(char *p);
void func_021F0AA0(char *p);
void func_021F0AC8(unsigned char *p, int a, int b);
void func_021F0AE0(Ent *p, void *q, int c);
void func_021F0B00(Ent *p, void *q, int a, int mode, int c, u16 d);
void func_021F0B7C(struct S021F0B7C *p);
void func_021F0B88(Ent *p, void *unused);
void func_021F0C00(Ent *p, int idx);
int func_021F0C68(unsigned short *p);
int func_021F0C70(void *p, int i, int j, int k);
void func_021F0CA0(Record *p, unsigned short a, unsigned char b, unsigned char c);
void func_021F0CB8(unsigned char *p);
int func_021F0CDC(unsigned short *p, int i);
void func_021F0CF0(unsigned char *p, int i);
void func_021F0D00(unsigned short *p, int i);
unsigned short func_021F0D08(unsigned short *p, int i);
void func_021F0D10(char *p, char v);
void func_021F0D14(int a, int b, int *c, int *d);
int func_021F0D48(char *p);
int func_021F0D80(void *p, int value);
void func_021F0DB4(char *p, int mode);
void func_021F0E70(char *p);
void func_021F0EB0(char *p, int flag);
void func_021F0F28(char *p, int flag);
void func_021F0F70(char *p);
void func_021F0FB0(char *p);
void func_021F0FF0(char *p);
int func_021F1000(char *p);
void func_021F1010(void *p);
int func_021F1060(u8 *p);
int func_021F11B4(char *p);
void func_021F122C(char *p);
void func_021F1290(void *q, int a, int b, int c);
int func_021F133C(char *p, int v, int *o1, int *o2);
void func_021F13FC(void *p);
u32 func_021F1458(u8 *p, int a, int b, int c);
void func_021F1574(char *p, int idx);
void func_021F15FC(char *p, int flag);
void func_021F1624(void *p);
void func_021F1740(void *p);
void func_021F1758(u8 *p, int key);
void func_021F18F0(int key, int flag, u8 *p);
void func_021F1910(char *p, int on);
void func_021F1950(char *p);
void func_021F1A44(char *p, int flag);
void func_021F1A64(char *p, int flag);
void func_021F1B30(char *p, int flag);
void func_021F1B50(char *p);
void func_021F1BBC(char *p);
int func_021F1BE4(char *p);
void func_021F1C0C(char *p);
void func_021F1CD8(char *p);
void func_021F1DB0(char *p);
void func_021F1DE8(char *p, int flag);
void func_021F1E98(char *p);
void func_021F1F24(char *p);
u8 func_021F1F70(void);
void func_021F1F80(char *p);
void func_021F20AC(char *p);
void func_021F2130(char *p);
void func_021F2180(char *p);
void func_021F21B4(char *p);
void func_021F21F8(char *p);
void func_021F2370(char *p);
int func_021F23CC(u8 *p, int a);
void func_021F24C0(char *p);
void func_021F24FC(unsigned char *p);
void func_021F2508(void *task, char *p);
void func_021F251C(u8 *p, int a1, int a2, int a3, int e);
void func_021F26E0(char *p);
void *func_021F279C(int a, int b, int c, int d);
char *func_021F27D8(int a0, int a1, int a2, void (*cb)(int), int arg, int flag);
void func_021F2848(u8 *p, u8 v);
void func_021F2980(void);
void func_021F2984(char *p);
int func_021F2994(int *p);
int func_021F29D8(char *p, int a);
int func_021F2AB8(char *p);
void func_021F2AD4(u8 *p);
void func_021F2AEC(unsigned char *p, int a1, int a2, int a3, int k);
u32 func_021F2B9C(u8 *p, int row, int col);
int func_021F2BB8(u8 *p, int row, int col);
int func_021F2BD4(u8 *p, int row, int col, int kind);
extern struct Pair d_021F333C;
extern struct Pair d_021F334C;
extern u16 d_021F31BC[];
extern u8 d_021F31AB[];
extern u8 d_021F31B0[];
extern const u32 d_021F31EC[];
extern const int d_021F31F8[];
extern u8 d_021F3255[];
extern unsigned char d_021F3292[];
extern unsigned char d_021F3204[];
extern const u8 d_021F31A8[];
extern const u8 d_021F323C[];
extern const unsigned char d_021F32B3[][9];
extern const struct Pair d_021F3344;
extern u16 d_021F31B6[];
extern const struct Pair d_021F3324;
extern const struct Pair d_021F331C;
extern const Ent_021F1010 d_021F3410[];
extern const u16 d_021F31D4[];
extern const Ent_021F1010 d_021F348C[];
extern const struct Pair d_021F3334;
extern const Tab d_021F3354;
extern const int d_021F332C[2];
extern const int d_021F31E0[];
extern const int d_021F32E0[][3];
extern const int d_021F31C8[];
extern const int d_021F33CC[];
extern struct BgTemplate d_021F338C;
extern struct BgTemplate d_021F33AC;
extern struct BgTemplate d_021F336C;
extern const u8 d_021F3526[];
extern const u8 d_021F3531[];
extern const u8 d_021F353C[];
extern const int d_021F3548[];
extern char d_021F3214[];
extern char d_021F3272[];
extern const u8 d_021F3520[];
extern int d_021F3554;






int func_021EFEC0(int a, int b)
{
    if (a % 2 == 0) {
        if (b < 3)
            return 1;
    } else {
        if (b < 4)
            return 1;
    }
    return 0;
}






void func_021EFEE4(unsigned char *p, unsigned int v)
{
    ((struct Obj09784 *)p)->f0 = v;
    p[0x456] = 0;
    p[0x455] = 0;
}







/*
 * evidence: func_021EFEE4 is ov029's own code (a store leaf ending in bx lr
 * after the bx lr at 0x021EFEE0), inside ov029's window, so only ov029 can be
 * resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference; it
 * attests as sole-ref/code from ov029's own listing.
 *
 * `line`: every caller loads r2 with a constant, but the callee never
 * reads it, so the thunk takes it and drops it.
 */
void func_021EFEF8(char *p, void (*f)(void), int line)
{
    func_021EFEE4((unsigned char *)p, (int)f);
}






void func_021EFF00(int x, int y, int *a, int *b)
{
    int m = x % 2;

    if (m == 0) {
        a[0] = x;
        b[0] = y - 1;
        a[1] = x;
        b[1] = y + 1;
        a[2] = x + 1;
        b[2] = y;
        a[3] = x + 1;
        b[3] = y - 1;
        a[4] = x - 1;
        b[4] = y;
        a[5] = x - 1;
        b[5] = y - 1;
    } else {
        a[0] = x;
        b[0] = y - 1;
        a[1] = x;
        b[1] = y + 1;
        a[2] = x + 1;
        b[2] = y;
        a[3] = x + 1;
        b[3] = y + 1;
        a[4] = x - 1;
        b[4] = y;
        a[5] = x - 1;
        b[5] = y + 1;
    }
}







void func_021EFF58(u8 *p, int a, int c)
{
    struct Pt s;
    int x;
    int y;
    struct Slot *sl;

    func_021F0D14(a, c, &x, &y);
    s.x = x * 8 + 16;
    s.y = y * 8 + 16;
    s.w = p[0x414] + 10;
    s.z = 0;
    s.t = 2;
    sl = func_021F0000((struct Owner *)p);
    if (sl->obj != 0) {
        func_0204B878(sl->obj, s.w);
        func_0204B9A0(sl->obj);
        func_0204B49C(sl->obj, s.x, 0, 0);
        func_0204B49C(sl->obj, s.y, 0, 1);
    } else {
        sl->obj = func_0204B294((void *)((struct Obj05112 *)p)->f34, ((struct Obj05112 *)p)->f2C, ((struct Obj05112 *)p)->f28, ((struct Obj05112 *)p)->f30, &s, 0, ((struct Obj05112 *)p)->fC);
        func_0204B92C(sl->obj, 1);
        func_0204B3DC(sl->obj, 1);
    }
    sl->a = a;
    sl->b = c;
}







struct Slot *func_021F0000(struct Owner *p)
{
    int best = -1;
    int bestSub = -1;
    int idx = 0;
    int i;
    int pri;
    int sub;

    for (i = 0; i < 20; i++) {
        if (p->s[i].obj == 0) {
            return &p->s[i];
        }
        pri = func_0204B918(p->s[i].obj);
        sub = func_0204B8F4(p->s[i].obj);
        if (pri > best || (pri == best && sub > bestSub)) {
            best = pri;
            bestSub = sub;
            idx = i;
        }
    }
    return &p->s[idx];
}






int func_021F0064(unsigned char *p, int a, int b)
{
    int i;
    for (i = 0; i < 20; i++) {
        if (*(int *)(p + i * 12 + 0x3c) != 0 && *(int *)(p + i * 12 + 0x40) == a && *(int *)(p + i * 12 + 0x44) == b) {
            if (func_0204B98C((struct Actor *)(*(int *)(p + i * 12 + 0x3c))) != 0) return 0;
        }
    }
    return 1;
}







int func_021F009C(u8 *p)
{
    int y;
    int x;
    int k;
    u8 *q;
    int xs[6];
    int ys[6];

    for (y = 0; y < 4; y++) {
        for (x = 0; x < 9; x++) {
            q = p + y + x * 4;
            if (q[0x3f0] == 4 && func_021F0064(p, x, y) != 0) {
                q[0x3f0] = 5;
            }
            if (q[0x3f0] == 2) {
                func_021EFF58(p, x, y);
                q[0x3f0] = 3;
            }
        }
    }
    p[0x415]++;
    if (p[0x415] >= 16) {
        return 1;
    }
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 9; x++) {
            q = p + y + x * 4;
            if (q[0x3f0] == 3) {
                q[0x3f0] = 4;
                func_021EFF00(x, y, xs, ys);
                for (k = 0; k < 6; k++) {
                    if (xs[k] >= 0 && xs[k] < 9 && ys[k] >= 0 && ys[k] < 4) {
                        q = p + xs[k] * 4 + ys[k];
                        if (q[0x3f0] == 1) {
                            q[0x3f0] = 2;
                        } else if (q[0x3f0] == 0) {
                            q[0x3f0] = 3;
                        }
                    }
                }
            }
        }
    }
    return 0;
}







void func_021F0194(u8 *p)
{
    int v;
    int j;
    int i;

    v = func_021F2B9C(p, p[0x452], p[0x453]);
    p[0x414] = v;
    i = 0;
    p[0x415] = i;
    for (; i < 4; i++) {
        for (j = 0; j < 9; j++) {
            if (v == func_021F2B9C(p, j, i)) {
                p[0x3f0 + j * 4 + i] = 1;
            }
        }
    }
    (p + p[0x452] * 4 + p[0x453])[0x3f0] = 2;
    func_021F009C(p);
}







/*
 * note 2026-10-05 (wD6 lane14): closed by reusing parameter a for x (the early
 * `adds r4,r1,#0` copy), b for the b/8 - lo[m] intermediate, and two 8-byte
 * struct copies of the tables (ldm r5,{r3,r5}).
 */
int func_021F020C(const void *p, int a, int b, int *c, int *d)
{
    int y;
    struct Pair lo;
    struct Pair hi;
    int ret = 5;
    int m;

    lo = d_021F333C;
    hi = d_021F334C;
    a = (a / 8 + 2) / 4;
    if (a < 0) {
        return 5;
    }
    m = a % 2;
    b = b / 8 - (&lo.a)[m];
    if (b < 0) {
        return 5;
    }
    y = b / 4;
    if (a < 9 && y < (&hi.a)[m]) {
        ret = func_021F2B9C((unsigned char *)p, a, y);
    }
    *c = a;
    *d = y;
    return ret;
}







void func_021F0298(u8 *p)
{
    Record *q = (Record *)(p + 0x418);
    int i;
    int j;

    for (i = 0; i < 5; i++) {
        func_021F0CA0(&q[i], d_021F31BC[i], d_021F31AB[i], d_021F31B0[i]);
        if (i == 0) {
            func_021F0D10((char *)(&q[i]), 0);
        }
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            func_021F0390(p, i, j, 0, 0);
        }
    }
}







void func_021F0300(u8 *p)
{
    Record *q = (Record *)(p + 0x418);
    int i;
    int j;

    for (i = 0; i < 5; i++) {
        func_021F0CA0(&q[i], d_021F31BC[i], d_021F31AB[i], d_021F31B0[i]);
        if (i != 0) {
            func_021F0D10((char *)(&q[i]), 0);
        }
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            func_021F0390(p, i, j, 1, p[0x461]);
        }
    }
}






void func_021F0370(void *p)
{
    int i;
    for (i = 0; i < 3; i++) func_021F08BC(p, i, 0, 31);
}







/*
 * `const` on the two key/row tables schedules the second table's pool load
 * above the `[sp]` stack-argument store in the cycle loop (14 bytes out
 * without it). The four-way reset is `s18 = s8 = sc = s14 = 0`: the chain
 * stores right to left.
 */
void func_021F0390(u8 *p, int a, int b, int c, int e)
{
    int sv;
    int flags;
    int one;
    int mode;
    int s18;
    int s14;
    int i;
    int sc;
    int s8;
    u32 keys;
    int idx;

    sv = func_02012138((const struct Ctx *)((struct Obj03631 *)p)->f1C);
    flags = 0;
    one = 1;
    s8 = 1;
    s18 = 4;
    s14 = 3;
    sc = 2;
    if (c != 0) {
        s18 = s8 = sc = s14 = 0;
    }
    keys = func_0201058C((void *)func_0201283C(func_020120F4((const struct Ctx *)(((struct Obj03631 *)p)->f1C))));
    mode = func_02158630(sv);
    if (e != 0) {
        if (mode == 3) {
            func_021F09DC(p, 2, 3, s14, a, b);
        } else if (keys & 8) {
            flags |= 4;
            func_021F09DC(p, 2, 2, s14, a, b);
        }
    }
    if (flags == 0) {
        one = 0;
        if (keys & 2) {
            flags |= 2;
        }
        if (keys & 0x3c) {
            flags |= 4;
        }
        if (keys & 0x3c0) {
            flags |= 8;
        }
        if (keys & 0x40) {
            func_021F09DC(p, 1, 3, sc, a, b);
        } else if (keys & 0x100) {
            func_021F09DC(p, 1, 0, sc, a, b);
        } else if (keys & 0x80) {
            func_021F09DC(p, 1, 1, sc, a, b);
        } else if (keys & 0x200) {
            func_021F09DC(p, 1, 0, sc, a, b);
        }
        if (mode != 0) {
            if (mode != 3) {
                func_021F09DC(p, 2, 3, sc, a, b);
            }
        } else {
            for (i = 0; i < 3; i++) {
                p[0x44d] = (p[0x44d] + 1) % 3;
                idx = p[0x44d];
                if ((d_021F31EC[idx] & keys) || (idx == 2 && p[0x450] != 0)) {
                    if (func_021F09DC(p, 2, d_021F31F8[idx], sc, a, b) != 0) {
                        if (p[0x44d] == 2) {
                            p[0x450] = 0;
                        }
                        break;
                    }
                }
            }
            if (i == 3) {
                func_021F09DC(p, 2, 8, s8, a, b);
            }
        }
    }
    if (one == 0) {
        func_021F09DC(p, 0, 6, s8, a, b);
        if (!(flags & 8)) {
            func_021F09DC(p, 1, 7, s8, a, b);
        }
        if (!(flags & 4)) {
            func_021F09DC(p, 2, 8, s8, a, b);
        }
    } else {
        func_021F09DC(p, 0, 5, s18, a, b);
        func_021F09DC(p, 1, 5, s18, a, b);
    }
}






int func_021F05B4(unsigned char *p)
{
    if (p[0x464] == 1 && p[0x461] == 1) return 1;
    return 0;
}







void func_021F05D0(u8 *p)
{
    Record *q2;
    Record *q;
    int i;
    int j;
    int flag;

    flag = 0;
    for (i = 0; i < 5; i++) {
        q = (Record *)(p + 0x418);
        func_021F0CB8((unsigned char *)(&q[i]));
        for (j = 0; j < 3; j++) {
            if (func_021F0CDC((short unsigned int *)(&q[i]), j) || p[0x460]) {
                func_021F0390(p, i, j, 0, p[0x461]);
                if (i == 0) {
                    flag = 1;
                }
                if (func_021F0CDC((short unsigned int *)(&q[i]), j)) {
                    func_021F0CF0((unsigned char *)(&q[i]), j);
                }
            }
        }
    }
    if (flag) {
        q2 = (Record *)(p + 0x418);
        for (i = 0; i < 5; i++) {
            if (i != 0) {
                func_021F0D10((char *)(&q2[i]), 1);
                for (j = 0; j < 3; j++) {
                    func_021F0390(p, i, j, 0, p[0x461]);
                }
            } else {
                func_021F0D10((char *)(&q2[i]), 0);
            }
        }
    }
    p[0x460] = 0;
}







void func_021F06B8(u8 *p, int a, int b)
{
    Record *q;
    int i;
    int j;
    int k;

    for (i = 0; i < 3; i++) {
        func_021F08BC((struct W *)p, i, 0, 0x1f);
    }
    q = (Record *)(p + 0x418);
    for (j = 0; j < 5; j++) {
        for (k = 0; k < 3; k++) {
            func_021F0D00((short unsigned int *)(&q[j]), k);
        }
    }
    p[0x461] = a;
    p[0x460] = 1;
    p[0x465] = 1;
    p[0x466] = 0;
    p[0x464] = b;
}







void func_021F0728(u8 *p)
{
    Record *q = (Record *)(p + 0x418);
    int i;

    for (i = 0; i < 3; i++) {
        u8 c = p[i + 0x44a];

        switch (c) {
        case 3:
            func_021F07AC(p, i, (u16 *)(&q[c]));
            break;
        case 1:
            func_021F07EC(p, i, (short unsigned int *)(&q[c]));
            break;
        case 2:
            func_021F0824(p, i, (short unsigned int *)(&q[c]));
            break;
        case 0:
            func_021F0858(p, i, (short unsigned int *)(&q[c]));
            break;
        case 4:
            func_021F088C(p, i, (short unsigned int *)(&q[c]));
            break;
        }
    }
}







void func_021F07AC(u8 *p, int i, u16 *e)
{
    unsigned int v = func_021F0D08(e, i);
    if (v > 0x24 || v < 4) return;
    v = (u16)(v - 4);
    v = (unsigned)(((int)v % 8) * 28) >> 3;
    v = d_021F3255[v];
    func_021F08BC((struct W *)p, i, v, 0x1f);
}






void func_021F07EC(void *p, int i, unsigned short *q)
{
    unsigned int v = func_021F0D08(q, i);
    if (v > 112 || v < 12) return;
    v = (unsigned)((unsigned short)(v - 12)) * 28 / 100;
    v = d_021F3255[v];
    func_021F08BC(p, i, v, 31);
}






void func_021F0824(void *p, int i, unsigned short *q)
{
    unsigned int v = func_021F0D08(q, i);
    if (v > 78 || v < 8) return;
    v = (unsigned)((unsigned short)(v - 8)) * 32 / 70;
    v = d_021F3292[v];
    func_021F08BC(p, i, v, 31);
}






void func_021F0858(void *p, int i, unsigned short *q)
{
    unsigned int v = func_021F0D08(q, i);
    if (v > 20) return;
    v = (unsigned)(((int)v % 10) * 28) / 10;
    v = d_021F3255[v];
    func_021F08BC(p, i, v, 31);
}






void func_021F088C(void *p, int i, unsigned short *q)
{
    unsigned int v = func_021F0D08(q, i);
    if (v > 15) return;
    v = (unsigned)(v * 12) / 15;
    v = d_021F3204[v];
    func_021F08BC(p, i, v, 31);
}







void func_021F08BC(struct W *p, int i, int j, int k)
{
    int n;
    int m;
    int a;
    int b;

    for (n = 0; n < 5; n++) {
        p->unk_24E[i][n] = 0;
        for (m = 0; m < 3; m++) {
            a = (p->unk_230[i][n] >> (m * 5)) & 0x1f;
            b = ((p->unk_272[p->unk_26C[i]][n] >> (m * 5)) & 0x1f) - a;
            p->unk_24E[i][n] |= ((a + b * j / k) & 0x1f) << (m * 5);
        }
        func_020215BC((struct PalAnmSlot *)p->unk_210, &p->unk_24E[i][n], 1, (u16)(d_021F31A8[i] + (n + 1) * 16), 2);
    }
}






void func_021F09B4(unsigned char *p, unsigned char *q, int n)
{
    int i;
    for (i = 0; i < 5; i++) *(unsigned short *)(p + n * 10 + i * 2 + 0x272) = *(unsigned short *)(q + n * 32 + i * 2 + 0x16);
}






int func_021F09DC(unsigned char *p, int i, int v, int a, int b, int j)
{
    if (a == b && i == j) {
        *(unsigned short *)(p + i * 2 + 0x26c) = v;
        *(p + i + 0x44a) = a;
        return 1;
    }
    return 0;
}






void func_021F0A0C(unsigned char *p)
{
    int i, j;
    unsigned char *base;
    i = 0;
    base = p + 0x2d0;
    for (; i < 9; i++) {
        for (j = 0; j < 4; j++) func_021F0AC8(base + i * 32 + j * 8, i, j);
    }
}






void func_021F0A38(unsigned char *p)
{
    int i, j;
    unsigned char *base;
    i = 0;
    base = p + 0x2d0;
    for (; i < 9; i++) {
        for (j = 0; j < 4; j++) func_021F0B88((Ent *)(base + i * 32 + j * 8), p);
    }
}






int func_021F0A68(char *p)
{
    int result, i, j;
    result = 0;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 4; j++) {
            if (func_021F0C68((unsigned short *)(p + 0x2d0 + i * 32 + j * 8))) {
                result = 1;
                break;
            }
        }
    }
    return result;
}






void func_021F0AA0(char *p)
{
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 4; j++) {
            func_021F0B7C((struct S021F0B7C *)(p + 0x2d0 + i * 32 + j * 8));
        }
    }
}




void func_021F0AC8(unsigned char *p, int a, int b)
{
    func_02082BCC(p, 0, 8);
    p[6] = a;
    p[7] = b;
}



void func_021F0AE0(Ent *p, void *q, int c)
{
    p->f4 = 0;
    func_021F1290(q, p->f6, p->f7, c);
    func_021F0C00((Ent *)p, 0);
}



/*
 * note:     `t = 0` must come first: set after the stores, the third parameter stays in r2
 *           instead of moving to r1 at entry (27 bytes out).
 */
void func_021F0B00(Ent *p, void *q, int a, int mode, int c, u16 d)
{
    int t;

    t = 0;
    p->f4 = a;
    p->cnt = 0;
    p->on = 1;
    p->f2 = d;
    if (mode == 0) {
        p->f5 = 0;
    } else if (mode == 1) {
        p->f5 = 4;
    } else if (mode == 2) {
        p->f5 = func_021F0C70(q, a, p->f6, p->f7);
        p->cnt = d * 5;
        t = 4;
    }
    func_021F1290(q, p->f6, p->f7, c);
    func_021F0C00((Ent *)p, t);
}










void func_021F0B7C(struct S021F0B7C *p)
{
    p->f0 = 0;
}










void func_021F0B88(Ent *p, void *unused)
{
    unsigned int q;
    int t;

    if (p->on) {
        p->cnt = p->cnt + 1;
        q = p->cnt / p->f2;
        t = 0;
        if (q >= 5) {
            q = 4 - q % 5;
            if (q == p->f5)
                p->on = 0;
        }
        if (q < 5) {
            if (p->cnt % p->f2 == 0)
                t = 1;
        }
        if (t)
            func_021F0C00((Ent *)p, q);
    }
}










void func_021F0C00(Ent *p, int idx)
{
    int x, y, w;
    int pal;

    pal = (d_021F323C + p->f4 * 5)[idx];
    func_021F0D14(p->f6, p->f7, &x, &y);
    w = 4;
    if (x < 0) {
        w = x + 4;
        x = 0;
    } else if (x + 4 > 0x20) {
        w = 0x20 - x;
    }
    func_020413B0(4, x, y, w, 4, pal);
    func_020409B4(4);
}









int func_021F0C68(unsigned short *p)
{
    return (int)((unsigned)(*p << 31) >> 31);
}









int func_021F0C70(void *p, int i, int j, int k)
{
    if (func_021F2BB8(p, j, k)) return d_021F32B3[i][4];
    return d_021F32B3[i][j];
}









/*
 * lever: enum zero and f2,f4,f0,f6 logical store order recover the
 * original scheduling; the previous f2,f0,f4,f6 order differed at two stores.
 */
void func_021F0CA0(Record *p, unsigned short a, unsigned char b, unsigned char c)
{
    ZeroValue z;
    z = Zero;
    p->f2 = b;
    p->f4 = z;
    p->f0 = b * 2;
    p->f6 = a;
    p->f8 = c;
    p->f9 = 1;
}









void func_021F0CB8(unsigned char *p)
{
    int i;
    if (p[9]) {
        for (i = 0; i < 3; i++) {
            if (((unsigned short *)p)[i] < ((unsigned short *)p)[3])
                ((unsigned short *)p)[i]++;
        }
    }
}









int func_021F0CDC(unsigned short *p, int i)
{
    if (p[i] >= p[3]) return 1;
    return 0;
}









void func_021F0CF0(unsigned char *p, int i)
{
    if (p[8] != 0) ((unsigned short *)p)[i] = 0;
}









void func_021F0D00(unsigned short *p, int i)
{
    p[i] = 0;
}










unsigned short func_021F0D08(unsigned short *p, int i)
{
    return p[i];
}










void func_021F0D10(char *p, char v)
{
    p[9] = v;
}










void func_021F0D14(int a, int b, int *c, int *d)
{
    struct Pair t = d_021F3344;
    *c = a * 4 - 2;
    *d = ((int *)&t)[a % 2] + b * 4;
}









/*
 * 2026-10-04 (wD2 lane 09): bytes are identical; only the relocation at +0024 is open.
 * Filed the callee as matched ov021_func_02189A48.c (EXACT, returns *(u32 *)(p+0x144)).
 * The tool still reports no independent witness for 02189A48 (3 overlays overlap).
 * Needs the integrator to regenerate the witness index, nothing left in the source.
 * interface: 0201210C returns the full word at +0x20; it is passed directly
 * to 02189A48, whose ov021 body reads the full word at +0x144. No value lost.
 */
int func_021F0D48(char *p)
{
    if (!func_020221A4()) return 0;
    if (func_0207D55C((unsigned short *)0x0400106c)) return 0;
    if (!func_02189A48((char *)func_0201210C(*(void **)(p + 0x1c)))) return 1;
    return 0;
}









int func_021F0D80(void *p, int value)
{
    int j, i, count;
    if (value == 4) return 1;
    count = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 9; j++) {
            if (value == func_021F2B9C(p, j, i)) count++;
        }
    }
    return count;
}










void func_021F0DB4(char *p, int mode)
{
    char *a, *b;
    int i;

    if (mode == 0) {
        a = (char *)func_02021728(*(char **)(p + 0x210), 3);
        b = (char *)func_02021730(*(char **)(p + 0x210), 3);
        for (i = 0; i < 14; i++) {
            if (0xFBEE & (1 << i)) {
                func_02021F64((u16 *)(a + i * 0x20), (u16 *)(a + i * 0x20), 0x10, 8,
                              d_021F31B6[*(u8 *)(p + 0x459)]);
                func_02082D44(a + i * 0x20, b + i * 0x20, 0x20);
            }
        }
        a = (char *)func_02021728(*(char **)(p + 0x210), 1);
        b = (char *)func_02021730(*(char **)(p + 0x210), 1);
        for (i = 0; i < 14; i++) {
            if (0x3E & (1 << i)) {
                func_02021F64((u16 *)(a + i * 0x20), (u16 *)(a + i * 0x20), 0x10, 8,
                              d_021F31B6[*(u8 *)(p + 0x459)]);
                func_02082D44(a + i * 0x20, b + i * 0x20, 0x20);
            }
        }
    }
}










void func_021F0E70(char *p)
{
    func_0202173C(((struct Obj00106 *)p)->f210, 8, 0xFFFF, -120, 0, 0x10,
                  d_021F31B6[((struct Obj00106 *)p)->f459], ((struct Obj00106 *)p)->f204);
}










void func_021F0EB0(char *p, int flag)
{
    int c = 8;
    if (flag == 0)
        c = 0;
    func_0202173C(((struct Obj05115 *)p)->f210, 8, 0xFFFF, -120, 0, c,
                  d_021F31B6[((struct Obj05115 *)p)->f459], ((struct Obj05115 *)p)->f204);
    func_0202173C(((struct Obj05115 *)p)->f210, 2, 0x3E, -120, 0, c,
                  d_021F31B6[((struct Obj05115 *)p)->f459], ((struct Obj05115 *)p)->f204);
}










void func_021F0F28(char *p, int flag)
{
    int c = 8;
    if (flag == 0)
        c = 0;
    func_0202173C(((struct Obj09786 *)p)->f210, 8, 0x3C0, -120, 0, c,
                  d_021F31B6[((struct Obj09786 *)p)->f459], ((struct Obj09786 *)p)->f204);
}










void func_021F0F70(char *p)
{
    func_0202173C(((struct Obj00106 *)p)->f210, 8, 0xFFFF, 1, 0, 0x10,
                  d_021F31B6[((struct Obj00106 *)p)->f459], ((struct Obj00106 *)p)->f204);
}










void func_021F0FB0(char *p)
{
    func_0202173C(((struct Obj00042 *)p)->f210, 8, 0xFFFF, 1, 0x10, 0,
                  d_021F31B6[((struct Obj00042 *)p)->f459], ((struct Obj00042 *)p)->f204);
}









/*
 * extent: followed by existing ov029_func_021F1000.c.
 */
void func_021F0FF0(char *p)
{
    func_02021B18(((struct Obj20390 *)p)->f210);
}










int func_021F1000(char *p)
{
    return func_02021ED8((const char *)(((struct Obj20391 *)p)->f210));
}









void func_021F1010(void *p)
{
    struct Pair t = d_021F3324;
    int i, j, n;

    for (i = 0; i < 9; i++) {
        n = ((int *)&t)[i % 2];
        for (j = 0; j < n; j++)
            func_021F1290(p, i, j, 0);
    }
    func_020409B4(4);
}









int func_021F1060(u8 *p)
{
    struct Pair t = d_021F331C;
    int i, j, n;
    unsigned int k;
    const Ent_021F1010 *e;
    int v;
    int col;
    int row;

    switch (p[0x455]) {
    case 0:
        for (i = 0; i < 9; i++) {
            n = ((int *)&t)[i % 2];
            for (j = 0; j < n; j++)
                func_021F0B00((Ent *)(p + 0x2D0 + i * 0x20 + j * 8), p, 4, 1, 4, 2);
        }
        p[0x455]++;
        break;
    case 1:
        if (func_021F0A68((char *)p) == 0)
            p[0x455]++;
        break;
    case 2:
        for (k = 0; k < 0x1F; k++) {
            e = &d_021F3410[k];
            if (p[0x456] == d_021F3410[k].key) {
                col = e->col;
                row = e->row;
                v = func_021F2B9C(p, row, col);
                func_021F0B00((Ent *)(p + 0x2D0 + row * 0x20 + col * 8), p, (u8)d_021F31D4[v], 2, v, e->v);
            }
        }
        if (p[0x456] >= 4) {
            func_021F0FB0((char *)p);
            func_021F1A44((char *)p, 1);
            p[0x455]++;
        }
        p[0x456]++;
        break;
    case 3:
        if (func_021F0A68((char *)p) == 0 && func_021F1000((char *)p) == 0)
            return 1;
        break;
    }
    func_021F0A38(p);
    return 0;
}









/*
 * The byte at +0x456 must be spelled out at each use (no cached pointer
 * local): a local pointer makes the increment reload the pool constant.
 */
int func_021F11B4(char *p)
{
    unsigned int i;

    if (((struct Obj00106 *)p)->f456 <= 0x7E) {
        for (i = 0; i < 0x24; i++) {
            if (((struct Obj00106 *)p)->f456 == d_021F348C[i].key)
                func_021F0B00((Ent *)(p + 0x2D0 + d_021F348C[i].row * 0x20 + d_021F348C[i].col * 8),
                              p, 4, 0, 4, d_021F348C[i].v);
        }
        ((struct Obj00106 *)p)->f456 = ((struct Obj00106 *)p)->f456 + 1;
    } else {
        if (func_021F0A68(p) == 0)
            return 1;
    }
    func_021F0A38((unsigned char *)p);
    return 0;
}









void func_021F122C(char *p)
{
    struct Pair t = d_021F3334;
    char *base;
    int i, j, n;

    i = 0;
    base = p + 0x2D0;
    for (; i < 9; i++) {
        n = ((int *)&t)[i % 2];
        for (j = 0; j < n; j++)
            func_021F0AE0((Ent *)(base + i * 0x20 + j * 8), p, 4);
    }
}









/*
 * note 2026-10-05 (wD7 lane15): closed. The table entry is a named block local (w = t.w[c]) in the
 *   store block. mwcc puts a named local first in `w + o` (adds r0,r0,r4); the plain t.w[c] load
 *   is a temp and goes second, which was the last 2-byte residue.
 */
void func_021F1290(void *q, int a, int b, int c)
{
    Tab t = d_021F3354;
    int y, x, xx, v, pal, i, yy, j;
    u16 *buf;

    buf = (u16 *)func_0204162C(4);
    func_021F0D14(a, b, &y, &x);
    v = d_021F31D4[c];
    pal = func_021F0C70(q, v, a, b);
    xx = x;
    for (i = 0; i < 4; i++) {
        int o = i * 32;
        u16 *row = buf + xx * 32;
        yy = y;
        for (j = 0; j < 4; j++) {
            if (yy >= 0 && yy < 0x20) {
                int w = t.w[c];
                row[yy] = (w + o + j) | ((d_021F323C + v * 5)[pal] << 12);
            }
            yy++;
        }
        xx++;
    }
}









int func_021F133C(char *p, int v, int *o1, int *o2)
{
    int a = 0;
    int b = 0;
    int found = 0;
    int i;
    int j;

    for (j = 0; j < 4; j++) {
        for (i = 0; i < 9; i++) {
            if (v == func_021F2B9C((unsigned char *)p, i, j)) {
                if (found == 0) {
                    a = i;
                    b = j;
                    found = 1;
                }
                if (func_021F2BB8((unsigned char *)p, i, j)) {
                    func_021F0D14(i, j, o1, o2);
                    return 1;
                }
                if (func_021F2BD4((u8 *)p, i, j, v)) {
                    a = i;
                    b = j;
                    found = 1;
                }
            }
        }
    }
    if (found) {
        func_021F0D14(a, b, o1, o2);
        func_020091AC((struct Sub020090B0Obj *)(*(int *)&((struct Obj00042 *)p)->f20), a, b, v, 1, 0);
        func_021F1290(p, a, b, v);
        func_020409B4(4);
        return 1;
    }
    return 0;
}









void func_021F13FC(void *p)
{
    int t[2];
    int i;
    int j;
    int n;

    t[0] = d_021F332C[0];
    t[1] = d_021F332C[1];
    for (i = 0; i < 9; i++) {
        n = t[i % 2];
        for (j = 0; j < n; j++)
            func_021F1290(p, i, j, func_021F2B9C(p, i, j));
    }
    func_020409B4(4);
}









/*
 * The 0x230 table must be a struct member (u16 [3][5]); a raw cast keeps
 * p + 0x230 in ip and spills the source pointer instead. `n` is declared
 * before `r` so the counter lands at [sp,#0x20] and the handle at [sp,#0x1c].
 */
u32 func_021F1458(u8 *p, int a, int b, int c)
{
    int n;
    int r;
    char *loc;
    u8 *src;
    int m;
    int k;
    u32 size;
    u32 v;

    if (c) {
        r = (int)func_02049F78((void *)(((struct Obj04308 *)p)->f24), d_021F31E0[a], (u32)(&loc), 0x8070);
        func_020862F0(((struct Obj05116 *)loc)->fC, ((struct Obj05116 *)loc)->f8);
        func_0207E468(((struct Obj05116 *)loc)->fC, 0, ((struct Obj05116 *)loc)->f8);
        src = *(u8 * *)&((struct Obj05116 *)loc)->fC;
        for (n = 0; n < 5; n++) {
            for (m = 0; m < 3; m++) {
                ((struct W *)p)->unk_230[m][n] = ((u16 *)(src + (n + 1) * 0x20))[d_021F31A8[m]];
            }
        }
        func_020307B0((void *)r);
        r = (int)func_02049F78((void *)(((struct Obj04308 *)p)->f24), 0x17, (u32)(&loc), 0x8070);
        for (k = 0; k < 9; k++) {
            func_021F09B4(p, ((struct Obj05116 *)loc)->fC, k);
        }
        func_020307B0((void *)r);
    }
    size = 0x5000;
    v = func_0203FA08(6, size, 0);
    ((struct Obj04308 *)p)->f14 = (u16)v | (size << 16);
    func_02049658((void *)(((struct Obj04308 *)p)->f24), d_021F32E0[b][a], 6, v, 0, 0, 0x70);
    return func_02049990((void *)(((struct Obj04308 *)p)->f24), 2, 6, 0, (u16)((struct Obj04308 *)p)->f14, 0, 0, 0x70);
}









/*
 * note:     the two tables are `const`: non-const, the copy of p lands after the first
 *           stack-argument store (4 bytes out). The loop needs i = 0 hoisted first, the
 *           base hoisted and q = p + i*4 with q[0x6e].
 */
void func_021F1574(char *p, int idx)
{
    int i;
    int r;
    char *loc;
    int *base;
    int *q;

    i = 0;
    ((struct Obj02749 *)p)->f28 = func_0204ABF0((void *)(((struct Obj02749 *)p)->f24), d_021F31C8[idx], 1, 0, 0x70);
    ((struct Obj02749 *)p)->f2C = func_0204A6C8((void *)(((struct Obj02749 *)p)->f24), 0x16, 0, 1, 0x70);
    ((struct Obj02749 *)p)->f30 = func_0204AF28((void *)(((struct Obj02749 *)p)->f24), 0x15, 0x14, ((struct Obj02749 *)p)->fC);
    r = (int)func_02049F78((void *)(((struct Obj02749 *)p)->f24), 0x18, (unsigned int)(&loc), ((struct Obj02749 *)p)->fC);
    base = *(int * *)&((struct Obj20392 *)loc)->fC;
    for (; i < 17; i++) {
        q = (int *)(p + i * 4);
        q[0x6e] = base[d_021F33CC[i]];
    }
    func_020307B0((void *)r);
    func_0203D88C(0xda, 0xe);
    func_0203D34C(0, ((struct Obj02749 *)p)->fC);
}








void func_021F15FC(char *p, int flag)
{
    if (flag == 0)
        func_02049990((void *)(((struct Obj13046 *)p)->f24), 1, 5, 0, (u16)((struct Obj13046 *)p)->f14, 0, 0, 0x70);
}









/*
 * volatile: 0x021F1722 ldr / 0x021F1726 str of 0x04001000 (REG_DB_DISPCNT_SUB read-modify-write, hardware register)
 *
 * Twin of ov030 func_021EFF54 (same three BgTemplate blocks), plus the
 * func_021F1740 call and the sub-screen window-mask clear. d_021F33AC's
 * ov029 hint is contested by another overlay, so its line carries only a4.
 */
void func_021F1624(void *p)
{
    int i;

    for (i = 4; i <= 7; i++) {
        func_02040588((u8)i, 0);
    }
    {
        struct BgTemplate t = d_021F338C;
        func_0203FCA0(6, &t, 0);
        func_02040588((u8)6, 1);
        func_0204047C(6, 3);
        func_02041300(6, 0, 0, 0, 0x20, 0x20, 0x11);
        func_020409B4(6);
    }
    {
        struct BgTemplate t = d_021F33AC;
        func_0203FCA0(5, &t, 0);
        func_02040588((u8)5, 1);
        func_0204047C(5, 1);
        func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
        func_020409B4(5);
    }
    {
        struct BgTemplate t = d_021F336C;
        func_0203FCA0(4, &t, 0);
        func_02040588((u8)4, 1);
        func_0204047C(4, 2);
        func_02041300(4, 0, 0, 0, 0x20, 0x20, 0x11);
        func_020409B4(4);
    }
    func_021F1740(p);
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
}








void func_021F1740(void *p)
{
    func_0207D63C(0x04001050, 2, 0x15, 9, 0x10);
}









/*
 * Stack order: c, d, x, y declared in that order ([sp,#0x10], #0xc, #8, #4).
 * The inner switch lists case 3 before case 2 (bodies 1, 6, 5 in the image).
 * func_021EFEC0 is the unlabelled ov029 leaf filed as ov029_func_021EFEC0.c.
 */
void func_021F1758(u8 *p, int key)
{
    int c;
    int d;
    int x;
    int y;
    int r;
    u32 v;

    if (p[0x45A] == 0 && key != 6 && key != 0)
        return;
    if (((struct Obj00042 *)p)->f214 != 0)
        return;
    func_020355D8(1);
    switch (key) {
    case 0:
        (int)func_02035CB8((u32 *)(&x), (u32 *)(&y));
        r = func_021F020C(p, x, y, &c, &d);
        if (p[0x457] != 0) {
            ((struct Obj00042 *)p)->f2CC = x;
            ((struct Obj00042 *)p)->f2CE = y;
            if ((func_021F0D80(p, r) > 1 || r == 4) && func_021EFEC0(c, d) != 0) {
                func_021F2AEC((unsigned char *)p, *(int *)&((struct Obj00042 *)p)->f20, c, d, (r + 1) % 5);
                func_020409B4(4);
                func_020061E4(0x628);
            }
        } else if (func_021F2DA8(p) == 0) {
            p[0x452] = c;
            p[0x453] = d;
            switch (r) {
            case 1:
                ((struct Obj00042 *)p)->f214 = 1;
                break;
            case 3:
                ((struct Obj00042 *)p)->f214 = 6;
                break;
            case 2:
                ((struct Obj00042 *)p)->f214 = 5;
                break;
            }
        }
        break;
    case 1:
        func_020061E4(0x628);
        p[0x457] ^= 1;
        func_021F1910((char *)p, p[0x457]);
        break;
    case 2:
        ((struct Obj00042 *)p)->f214 = 0xC;
        break;
    case 3:
        ((struct Obj00042 *)p)->f214 = 7;
        break;
    case 4:
        ((struct Obj00042 *)p)->f214 = 0xB;
        break;
    case 5:
        func_020061E4(0x628);
        v = ((struct Obj00042 *)p)->f14;
        func_0203FB44((int)6, (u16)v, (u16)(v >> 16));
        p[0x458]++;
        p[0x458] = p[0x458] % 5;
        func_020090E8((struct Sub020090B0Obj *)(*(int *)&((struct Obj00042 *)p)->f20), p[0x458]);
        func_021F1458(p, p[0x459], p[0x458], 0);
        func_021F13FC(p);
        func_021F1A44((char *)p, 1);
        break;
    case 6:
        ((struct Obj00042 *)p)->f214 = 0xD;
        break;
    }
}








void func_021F18F0(int key, int flag, u8 *p)
{
    if (func_021F2DA8(p) == 0 && flag == 0)
        func_021F1758(p, key);
}









void func_021F1910(char *p, int on)
{
    if (on) {
        func_0204B908(((struct Obj00811 *)p)->f150, 0);
        func_0204B954((struct Actor *)(((struct Obj00811 *)p)->f150), 0x2000);
        func_0204B92C((struct Obj *)((struct Obj00811 *)p)->f150, 1);
    } else {
        func_0204B92C((struct Obj *)((struct Obj00811 *)p)->f150, 0);
        func_0204B908(((struct Obj00811 *)p)->f150, 1);
    }
}









void func_021F1950(char *p)
{
    int i;
    int j;
    S13Rec s;
    int *q;

    func_02043598(0x10, 1);
    j = 0;
    for (i = 0; i < 11; i++) {
        s.x = d_021F3531[i];
        s.y = d_021F353C[i];
        s.z = d_021F3526[i];
        if (s.z == 6 && func_02085D3C()) {
            s.z = 7;
        }
        s.a = 0;
        s.b = 2;
        q = (int *)(p + i * 4);
        q[0x4b] = (int)func_0204B294((void *)((struct Obj00811 *)p)->f34, ((struct Obj00811 *)p)->f2C, ((struct Obj00811 *)p)->f28,
                                ((struct Obj00811 *)p)->f30, &s, 0, ((struct Obj00811 *)p)->fC);
        func_0204B3DC((struct Obj *)q[0x4b], 0);
        func_0204BA20((struct Actor *)q[0x4b], 0);
    }
    func_021F1910(p, 0);
    for (j = 0; j < 3; j++) {
        s.x = 8;
        s.y = 8;
        s.z = d_021F3548[j];
        s.a = 0;
        s.b = 2;
        q = (int *)(p + j * 4);
        q[0x56] = (int)func_0204B294((void *)((struct Obj00811 *)p)->f34, ((struct Obj00811 *)p)->f2C, ((struct Obj00811 *)p)->f28,
                                ((struct Obj00811 *)p)->f30, &s, 0, ((struct Obj00811 *)p)->fC);
        func_0204B3DC((struct Obj *)q[0x56], 0);
        func_0204BA20((struct Actor *)q[0x56], 0);
    }
    func_021F1F80(p);
    func_021F20AC(p);
}








void func_021F1A44(char *p, int flag)
{
    int i;
    for (i = 0; i < 3; i++)
        func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x158), flag);
}









void func_021F1A64(char *p, int flag)
{
    int i;

    for (i = 0; i < 20; i++) {
        if (*(int *)(p + i * 12 + 0x3c) != 0) {
            func_0204B3DC((struct Obj *)*(int *)(p + i * 12 + 0x3c), flag);
        }
    }
    for (i = 0; i < 3; i++) {
        if (*(int *)(p + i * 4 + 0x158) != 0 && ((struct Obj00106 *)p)->f45A != 0) {
            func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x158), flag);
        }
    }
    for (i = 0; i < 11; i++) {
        if (*(int *)(p + i * 4 + 0x12c) != 0) {
            if ((unsigned)(i - 8) <= 1) {
                if (((struct Obj00106 *)p)->f45A != 0) {
                    func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x12c), flag);
                }
            } else {
                func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x12c), flag);
            }
        }
    }
    if (((struct Obj00106 *)p)->f164 != 0 && ((struct Obj00106 *)p)->f45A != 0) {
        func_0204B3DC((struct Obj *)((struct Obj00106 *)p)->f164, flag);
    }
    if (((struct Obj00106 *)p)->f168 != 0 && ((struct Obj00106 *)p)->f45A != 0) {
        func_0204B3DC((struct Obj *)((struct Obj00106 *)p)->f168, flag);
    }
    if (((struct Obj00106 *)p)->f16C != 0 && ((struct Obj00106 *)p)->f45A != 0) {
        func_0204B3DC((struct Obj *)((struct Obj00106 *)p)->f16C, flag);
    }
    if (flag == 1) {
        func_021F1F80(p);
    }
}








void func_021F1B30(char *p, int flag)
{
    int i;
    for (i = 0; i < 18; i++)
        func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x170), flag);
}









void func_021F1B50(char *p)
{
    int i;
    S13Rec s;
    int *q;

    for (i = 0; i < 18; i++) {
        s.x = 0x80;
        s.y = 0x60;
        s.z = i + 0x12;
        s.a = 0;
        s.b = 2;
        q = (int *)(p + i * 4);
        q[0x5c] = (int)func_0204B294((void *)((struct Obj06128 *)p)->f34, ((struct Obj06128 *)p)->f2C, ((struct Obj06128 *)p)->f28,
                                ((struct Obj06128 *)p)->f30, &s, 0, ((struct Obj06128 *)p)->fC);
        func_0204B3DC((struct Obj *)q[0x5c], 0);
        func_0204B954((struct Actor *)q[0x5c], 0x2000);
        func_0204B9A0((struct Actor *)q[0x5c]);
        func_0204B92C((struct Obj *)q[0x5c], 1);
    }
}








void func_021F1BBC(char *p)
{
    int i;
    if (((struct Obj20395 *)p)->f170 != 0) {
        for (i = 0; i < 18; i++) {
            func_0204B3B4((struct Obj *)(*(int *)(p + i * 4 + 0x170)));
            *(int *)(p + i * 4 + 0x170) = 0;
        }
    }
}








int func_021F1BE4(char *p)
{
    int i;
    for (i = 0; i < 18; i++) {
        if (func_0204B98C((struct Actor *)(*(int *)(p + i * 4 + 0x170))) == 1)
            return 0;
    }
    return 1;
}









void func_021F1C0C(char *p)
{
    S13Rec s;

    s.x = 0x68;
    s.y = 0xaa;
    s.z = 0x28;
    s.a = 0;
    s.b = 2;
    ((struct Obj00709 *)p)->f164 = (int)func_0204B294((void *)((struct Obj00709 *)p)->f34, ((struct Obj00709 *)p)->f2C, ((struct Obj00709 *)p)->f28,
                                        ((struct Obj00709 *)p)->f30, &s, 0, ((struct Obj00709 *)p)->fC);
    func_0204B3DC((struct Obj *)((struct Obj00709 *)p)->f164, 0);
    func_0204BA20((struct Actor *)(((struct Obj00709 *)p)->f164), 0);

    s.x = 0x68;
    s.y = 0xaa;
    s.z = 0x27;
    s.a = 0x14;
    s.b = 2;
    ((struct Obj00709 *)p)->f168 = (int)func_0204B294((void *)((struct Obj00709 *)p)->f34, ((struct Obj00709 *)p)->f2C, ((struct Obj00709 *)p)->f28,
                                        ((struct Obj00709 *)p)->f30, &s, 0, ((struct Obj00709 *)p)->fC);
    func_0204B3DC((struct Obj *)((struct Obj00709 *)p)->f168, 0);
    func_0204BA20((struct Actor *)(((struct Obj00709 *)p)->f168), 0);

    s.x = 0x22;
    s.y = 0xaa;
    s.z = 0x10;
    s.a = 0;
    s.b = 2;
    ((struct Obj00709 *)p)->f16C = (int)func_0204B294((void *)((struct Obj00709 *)p)->f34, ((struct Obj00709 *)p)->f2C, ((struct Obj00709 *)p)->f28,
                                        ((struct Obj00709 *)p)->f30, &s, 0, ((struct Obj00709 *)p)->fC);
    func_0204B3DC((struct Obj *)((struct Obj00709 *)p)->f16C, 0);
    func_0204BA20((struct Actor *)(((struct Obj00709 *)p)->f16C), 0);
}









void func_021F1CD8(char *p)
{
    int n;
    int cnt;
    int k;
    int tmp;
    void *e;

    cnt = 0;
    if (((struct Obj00042 *)p)->f45A == 0) {
        return;
    }
    if (func_021F05B4((unsigned char *)p) != 0) {
        return;
    }
    n = func_02026C8C();
    if (((struct Obj00042 *)p)->f450 == 0) {
        tmp = 0;
        if (func_02026CA0(&tmp) != 30) {
            ((struct Obj00042 *)p)->f450 = 1;
        }
    }
    n--;
    for (k = 0; k < 30; k++) {
        if (cnt >= 10) {
            break;
        }
        if (n < 0) {
            func_020215BC((struct PalAnmSlot *)(*(int *)&((struct Obj00042 *)p)->f210), p + 0x1f8, (int)3, (u16)(d_021F33CC[cnt] * 2 + 0x60), 4);
            cnt++;
        } else {
            e = func_02026C78(n);
            if (e != 0) {
                func_020215BC((struct PalAnmSlot *)(*(int *)&((struct Obj00042 *)p)->f210), (u32 *)(p + 0x1b8) + func_02165CD8(e), (int)3,
                              (u16)(d_021F33CC[cnt] * 2 + 0x60), 4);
                cnt++;
            }
            n--;
        }
    }
}








void func_021F1DB0(char *p)
{
    if (((struct Obj02111 *)p)->f164 != 0) {
        func_0204B3B4((struct Obj *)(((struct Obj02111 *)p)->f164));
        ((struct Obj02111 *)p)->f164 = 0;
    }
    if (((struct Obj02111 *)p)->f168 != 0)
        func_0204B3B4((struct Obj *)(((struct Obj02111 *)p)->f168));
    if (((struct Obj02111 *)p)->f16C != 0) {
        func_0204B3B4((struct Obj *)(((struct Obj02111 *)p)->f16C));
        ((struct Obj02111 *)p)->f16C = 0;
    }
}









void func_021F1DE8(char *p, int flag)
{
    int z;

    ((struct Obj00106 *)p)->f459 = func_02008550((const struct Sub0200852CObj *)func_02012944((void *)func_020120F4((const struct Ctx *)(((struct Obj00106 *)p)->f1C))));
    ((struct Obj00106 *)p)->f458 = func_020090F0((const struct Sub020090B0Obj *)(((struct Obj00106 *)p)->f20));
    z = 0;
    ((struct Obj00106 *)p)->f34 = (int)func_0204B100(0x44, 0, ((struct Obj00106 *)p)->fC);
    ((struct Obj00106 *)p)->f38 = func_0204B034((unsigned char *)d_021F3214, 1, ((struct Obj00106 *)p)->fC);
    func_0204B258((struct Bank *)(((struct Obj00106 *)p)->f34), ((struct Obj00106 *)p)->f38);
    func_021F1458((unsigned char *)p, ((struct Obj00106 *)p)->f459, ((struct Obj00106 *)p)->f458, 1);
    func_021F1574(p, ((struct Obj00106 *)p)->f459);
    func_021F1950(p);
    func_021F1C0C(p);
    ((struct Obj00106 *)p)->f10 = (int)func_02051B84((u8 *)d_021F3272, (int)((void *)func_021F18F0), (int)p, ((struct Obj00106 *)p)->fC);
    if (flag) {
        func_021F1010(p);
        func_021F1A64(p, z);
    } else {
        func_021F13FC(p);
        func_021F1A64(p, 1);
        func_021F1A44(p, 1);
    }
}









void func_021F1E98(char *p)
{
    int i;
    int *q;
    unsigned int v;

    func_021F1DB0(p);
    func_021F1BBC(p);
    for (i = 0; i < 11; i++) {
        q = (int *)(p + i * 4);
        if (q[0x4b] != 0) {
            func_0204B3B4((struct Obj *)q[0x4b]);
            q[0x4b] = 0;
        }
    }
    for (i = 0; i < 3; i++) {
        q = (int *)(p + i * 4);
        if (q[0x56] != 0) {
            func_0204B3B4((struct Obj *)q[0x56]);
            q[0x56] = 0;
        }
    }
    for (i = 0; i < 20; i++) {
        q = (int *)(p + i * 12);
        if (q[0xf] != 0) {
            func_0204B3B4((struct Obj *)q[0xf]);
            q[0xf] = 0;
        }
    }
    func_0204AFD8(((struct Obj02111 *)p)->f30);
    func_0204A8D4(((struct Obj02111 *)p)->f2C);
    func_0204ADA4(((struct Obj02111 *)p)->f28);
    v = ((struct Obj02111 *)p)->f14;
    func_0203FB44((int)6, (unsigned short)v, (unsigned short)(v >> 16));
}








void func_021F1F24(char *p)
{
    if (((struct Obj07621 *)p)->f10)
        func_02051C6C((void *)(((struct Obj07621 *)p)->f10));
    func_021F1E98(p);
    func_0204B084(((struct Obj07621 *)p)->f38);
    func_0204B1CC((struct Bank *)(((struct Obj07621 *)p)->f34));
    func_020403F4(4);
    func_020403F4(5);
    func_020403F4(6);
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 0);
}







u8 func_021F1F70(void)
{
    return d_021F3520[func_0203568C()];
}








static inline void SetFrame(int o, int v)
{
    if (v != func_0204B918((struct Obj *)o)) {
        func_0204B908(o, (u16)v);
    }
}








void func_021F1F80(char *p)
{
    RtcTime t;
    int o;
    int v;

    func_0203F4CC((struct RtcTime *)(&t));
    func_0204B3DC((struct Obj *)((struct Obj00811 *)p)->f12C, 0);

    o = ((struct Obj00811 *)p)->f130;
    v = t.hour / 10;
    SetFrame(o, v);
    if (v == 0) {
        func_0204B3DC((struct Obj *)o, 0);
    } else {
        func_0204B3DC((struct Obj *)o, 1);
    }

    o = ((struct Obj00811 *)p)->f134;
    v = t.hour % 10;
    SetFrame(o, v);
    o = ((struct Obj00811 *)p)->f138;
    v = t.second & 1;
    SetFrame(o, v);
    o = ((struct Obj00811 *)p)->f13C;
    v = t.minute / 10;
    SetFrame(o, v);
    o = ((struct Obj00811 *)p)->f140;
    v = t.minute % 10;
    SetFrame(o, v);

    o = ((struct Obj00811 *)p)->f144;
    if (func_02085D3C()) {
        SetFrame(o, func_021F1F70());
    } else {
        SetFrame(o, func_0203568C() == 5);
    }
}








void func_021F20AC(char *p)
{
    int i;
    int a;
    int b;
    short s[2];

    for (i = 0; i < 3; i++) {
        if (func_021F133C(p, i + 1, &a, &b)) {
            a = a * 8;
            b = b * 8;
            s[0] = a + 0x10;
            s[1] = b + 0xf;
            func_0204B404((struct Obj *)(*(int *)(p + i * 4 + 0x158)), (const struct Vec2 *)s, 0);
            a += 0x20;
            func_0204B800((struct Node *)(*(int *)(p + i * 4 + 0x158)), (a / 8) & 0xff);
        } else {
            s[0] = -0x40;
            s[1] = 0;
            func_0204B404((struct Obj *)(*(int *)(p + i * 4 + 0x158)), (const struct Vec2 *)s, 0);
        }
    }
}








void func_021F2130(char *p)
{
    func_02051C88((struct Ctx *)(((struct Obj00042 *)p)->f10));
    func_021F2D50((u8 *)p);
    func_021F2DC8(p);
    func_021F1F80(p);
    if (func_021F2DA8((u8 *)p) == 0) {
        if (((struct Obj00042 *)p)->f45A) {
            func_021F05D0((u8 *)p);
            func_021F0728((u8 *)p);
            func_021F1CD8(p);
        }
    } else {
        ((struct Obj00042 *)p)->f214 = 0;
    }
}







void func_021F2180(char *p)
{
    if (*(void (**)(void *))(p + 0x1fc) != 0)
        (*(void (**)(void *))(p + 0x1fc))(((struct Obj00042 *)p)->f200);
    *(void (**)(void *))(p + 0x1fc) = 0;
    ((struct Obj00042 *)p)->f200 = 0;
    if (func_021F0D48(p))
        func_021F2130(p);
}








void func_021F21B4(char *p)
{
    void (*f)(int);

    if (func_021F1060((u8 *)p) == 0) {
        f = *(void (**)(int))(p + 0x1fc);
        if (f)
            f(*(int *)&((struct Obj00042 *)p)->f200);
        *(int *)&((struct Obj00042 *)p)->f1FC = 0;
        *(int *)&((struct Obj00042 *)p)->f200 = 0;
        return;
    }
    func_021F0300((u8 *)p);
    func_021EFEF8(p, (void *)func_021F2180, 0xF92);
}








void func_021F21F8(char *p)
{
    switch (((struct Obj00106 *)p)->f455) {
    case 0:
        func_021F1010(p);
        func_021F0370(p);
        func_021F1A64(p, 0);
        (((struct Obj00106 *)p)->f455)++;
        return;
    case 1:
        if (func_021F0D48(p)) {
            func_021F1B50(p);
            func_021F1B30(p, 1);
            (((struct Obj00106 *)p)->f455)++;
            return;
        }
        break;
    case 2:
        if (func_021F1BE4(p)) {
            func_021F0F70(p);
            ((struct Obj00106 *)p)->f456 = 0;
            (((struct Obj00106 *)p)->f455)++;
            return;
        }
        break;
    case 3:
        if (func_021F2BF0(p)) {
            func_021F0FF0(p);
            ((struct Obj00106 *)p)->f455 = 7;
            return;
        }
        if (((struct Obj00106 *)p)->f456 < 8) {
            (((struct Obj00106 *)p)->f456)++;
            return;
        }
        func_021F1B30(p, 0);
        func_021F1BBC(p);
        func_021F0E70(p);
        (((struct Obj00106 *)p)->f455)++;
        ((struct Obj00106 *)p)->f456 = 0;
        return;
    case 4:
        if (func_021F2BF0(p)) {
            ((struct Obj00106 *)p)->f455 = 7;
            return;
        }
        if (func_021F11B4(p) == 1) {
            ((struct Obj00106 *)p)->f456 = 0;
            (((struct Obj00106 *)p)->f455)++;
            return;
        }
        break;
    case 5:
        if (func_021F2BF0(p)) {
            ((struct Obj00106 *)p)->f455 = 7;
            return;
        }
        (((struct Obj00106 *)p)->f456)++;
        if (((struct Obj00106 *)p)->f456 >= 8) {
            func_021F122C(p);
            ((struct Obj00106 *)p)->f456 = 0;
            (((struct Obj00106 *)p)->f455)++;
            return;
        }
        break;
    case 6:
        (((struct Obj00106 *)p)->f456)++;
        if (((struct Obj00106 *)p)->f456 >= 8) {
            func_021F1A64(p, 1);
            func_021F1A44(p, 0);
            func_021EFEF8(p, (void (*)(void))func_021F21B4, 0x100b);
            return;
        }
        break;
    case 7:
        func_021F1BBC(p);
        func_021F0E70(p);
        func_021F0AA0(p);
        func_021F122C(p);
        ((struct Obj00106 *)p)->f456 = 8;
        ((struct Obj00106 *)p)->f455 = 6;
        break;
    }
}








void func_021F2370(char *p)
{
    if (((struct Obj00106 *)p)->f456 == 0) {
        func_021F0E70(p);
        func_021F1A64(p, 1);
        func_021F1A44(p, 0);
        func_021F1BBC(p);
        func_021F1010(p);
        func_021F0370(p);
    }
    ((struct Obj00106 *)p)->f456 += 1;
    if (((struct Obj00106 *)p)->f456 >= 0x10) {
        ((struct Obj00106 *)p)->f456 = 0;
        func_021EFEF8(p, (void (*)(void))func_021F21B4, 0x1041);
    }
}








/*
 * base is a u32 holding (u16)p->f14 and re-cast (u16) in the palette add:
 * that is the second lsls/lsrs pair.  The 0x0200910C result goes to a
 * local before base is loaded (the load sits between the call and cmp);
 * declaring i before buf gives i r4 and buf r5.
 */
int func_021F23CC(u8 *p, int a)
{
    int result;
    u32 h;
    u16 crc;
    u32 base;
    u16 x;
    int i;
    u8 *buf;
    u16 *pal;

    result = 0;
    buf = func_02030734(0x70, 0x3000, 0, (const char *)&d_021F3554, 0x104E);
    h = (u32)func_02012EBC(func_020120F4((const struct Ctx *)a));
    if (func_020072CC((struct Ctrl *)h, 4, 0x70, buf, 0x3000) == 1) {
        crc = func_0203F1FC(buf, 0x2600);
        x = func_0200910C((const struct Sub020090B0Obj *)func_02009210((void *)h));
        base = (u16)((struct Obj20396 *)p)->f14;
        if (crc == x && func_0200C6F0((struct Buf2000 *)buf) != 0) {
            result = 1;
            for (i = 0; i < 15; i++) {
                func_02040B1C(6, buf + i * 0x220, 0x220, base + (i + 5) * 0x20);
            }
            func_02040E78(6, buf + 0x1FE0, 0x20, 0x140);
            func_02040AE0(5, buf + 0x2000, 0x600);
            pal = (u16 *)func_0204162C(5);
            for (i = 0; i < 0x600 / 2; i++) {
                pal[i] += (u16)base;
            }
            func_020409B4(5);
        }
    }
    func_0200734C((struct Sub02007324Ctrl *)h, 4);
    func_020307B0(buf);
    return result;
}








void func_021F24C0(char *p)
{
    func_021F0FF0(p);
    if (*(int *)&((struct Obj00106 *)p)->f204 != 0)
        func_02030D28((struct Ctx *)(*(int *)&((struct Obj00106 *)p)->f204));
    func_021F0E70(p);
    func_021F1010(p);
    if (*(int *)&((struct Obj00106 *)p)->f204 != 0)
        func_02030D28((struct Ctx *)(*(int *)&((struct Obj00106 *)p)->f204));
    ((struct Obj00106 *)p)->f451 = 1;
}







void func_021F24FC(unsigned char *p)
{
    p[0x451] = 2;
}







void func_021F2508(void *task, char *p)
{
    if (((struct Obj13047 *)p)->f210 != 0)
        func_02021D50(((struct Obj13047 *)p)->f210);
}






/*
 * 2026-10-05 (wave D5 lane 02): arm9 func_02035010/func_02035040 and their setters func_02035004/func_02035034 are now filed in src/matched/arm9/; the wrappers show MATCH only until the labels exist. Re-run after the integrator labels them.
 * 2026-10-04 (wD2 lane 09): bytes are identical; 3 of 41 relocations open.
 * Filed leaf func_021F24FC as matched ov029_func_021F24FC.c (EXACT).
 * Open: ABS32 +01C0 to 021F24FC (witness index not yet regenerated),
 * and THM_CALL +0128/+0130 to unlabelled arm9 02035010 and 02035040 (arm9 wrappers:
 * r2=*(0x021469BC), tail call to 02035004/02035034 style stubs, no source or label yet).
 *
 * Byte-correct.  Blocked by two unlabelled ARM9 leaves (Ilias's), so the
 * overlay leaf 0x021F24FC is not filed either:
 *   +0128 func_02035010 (arm): verified MATCH with `one --arm`, capped
 *     only by its own unlabelled tail-call target 0x02035004
 *     (str r1,[r0,#0x14]; str r2,[r0,#0x28]; bx lr):
 *       extern void *d_021469BC;
 *       void func_02035010(void *cb, void *arg)
 *       { func_02035004(d_021469BC, cb, arg); }
 *   +0130 func_02035040 (arm): the same wrapper over 0x02035034
 *     (str r1,[r0,#0x10]; str r2,[r0,#0x28]; bx lr), MATCH likewise:
 *       void func_02035040(void *cb, void *arg)
 *       { func_02035034(d_021469BC, cb, arg); }
 *   +01C0 ABS32 func_021F24FC (ov029): unlabelled leaf
 *     `void func_021F24FC(u8 *p) { p[0x451] = 2; }` (ldr r1,=0x451;
 *     movs r2,#2; strb r2,[r0,r1]; bx lr).
 * Levers: r = 0 at the top shares the zero register with the 0x214/0x218
 * stores; t = 1 assigned after the func_02021518 store keeps t in a stack
 * slot and 0x1C0 in r7; p is u8 * (ldrb of 0x45A); func_021F3144's second
 * argument is int here (no narrowing before the call).
 *
 * 2026-10-05 (wD4 lane 15): re-run, still MATCH. Open: unlabelled arm9 02035010 and 02035040 (no source change possible here).
 */
void func_021F251C(u8 *p, int a1, int a2, int a3, int e)
{
    int r = 0;
    int t;
    int h;

    *(u16 *)(p + 0xc) = 0x70;
    *(int *)(p + 0x20) = a1;
    *(int *)(p + 0x18) = a2;
    *(int *)(p + 0x1c) = a3;
    p[0x454] = 1;
    p[0x45A] = func_0201214C((const struct Ctx *)a3);
    p[0x45B] = 1;
    *(int *)(p + 0x214) = 0;
    *(int *)(p + 0x218) = 0;
    *(int *)(p + 0x24) = (int)func_020490F4(0x1e, 0x70);
    *(void **)(p + 0x20C) = func_02030734(0x70, func_02030CB0(4), 1, (const char *)(&d_021F3554), 4280);
    *(int *)(p + 0x204) = (int)func_02030CBC(4, *(void **)(p + 0x20C));
    if (e != 0) {
        func_021EFEF8((char *)p, (void (*)(void))func_021F21F8, 4284);
    } else {
        func_021F0298(p);
        func_021EFEF8((char *)p, (void (*)(void))func_021F2180, 4287);
    }
    func_021F1624(p);
    func_021F1DE8((char *)p, e);
    if (func_02009100((const struct Sub020090B0Obj *)(*(int *)(p + 0x20))) != 0)
        r = func_021F23CC(p, a3);
    func_021F15FC((char *)p, r);
    func_021F0A0C(p);
    *(int *)(p + 0x210) = (int)func_02021518(0x70);
    t = 1;
    func_02021EE4((struct Obj02021EE4 *)(*(int *)(p + 0x210)), 1);
    func_0202155C((struct PalAnmSlot *)(*(int *)(p + 0x210)), 3, 0x1C0, 0x70);
    func_0202155C((struct PalAnmSlot *)(*(int *)(p + 0x210)), 1, 0x1C0, 0x70);
    func_020216D4((struct PalAnmSlot *)(*(int *)(p + 0x210)), 3, 0, 0x1C0);
    func_020216D4((struct PalAnmSlot *)(*(int *)(p + 0x210)), 1, 0, 0x1C0);
    func_021F0DB4((char *)p, p[0x45A]);
    func_02021D50((struct S02021D50 *)(*(int *)(p + 0x210)));
    *(int *)(p + 0x208) = func_020056A0((void *)func_021F2508, p, 1);
    func_02035010((u32)((void *)func_021F24C0), (u32)p);
    func_02035040((u32)((void *)func_021F24FC), (u32)p);
    func_021F2E10((char *)p, (int *)(p + 0x21C));
    func_021F1CD8((char *)p);
    func_021F1F80((char *)p);
    if (e == 0) {
        if (func_020120D8((char *)a3) != 0)
            t = 0;
        func_021F3144(p, t);
        func_021F2D84(p);
    } else {
        func_021F21F8((char *)p);
    }
    if (*(int *)(p + 0x204) != 0)
        func_02030D28((struct Ctx *)(*(int *)(p + 0x204)));
    h = func_02012138((const struct Ctx *)a3);
    if (h != 0 && func_021585E0(h) == 2)
        func_02158614((void *)h);
}






void func_021F26E0(char *p)
{
    int r = func_02012138((const struct Ctx *)(*(int *)(p + 0x1c)));

    if (r != 0) {
        if (func_021585E0(r) == 2)
            func_02158614((void *)r);
    }
    func_021F2E5C(p + 0x21c);
    func_02035010(0, 0);
    func_02035040(0, 0);
    func_0203D8AC();
    func_0203D34C(0, *(unsigned short *)(p + 0xc));
    func_020215A0((struct PalAnmSlot *)(*(int *)(p + 0x210)), 3);
    func_020215A0((struct PalAnmSlot *)(*(int *)(p + 0x210)), 1);
    func_02021540((void *)(*(int *)(p + 0x210)));
    func_02030DA4(*(int *)(p + 0x204));
    func_020307B0((void *)(*(int *)(p + 0x20c)));
    func_02030EAC((struct Node *)(*(int *)(p + 0x208)));
    if (*(int *)(p + 0x218) != 5) {
        func_02028A70((struct SoundSys *)func_02012A30(func_020120F4((const struct Ctx *)(*(int *)(p + 0x1c)))));
    }
    func_02049238(*(int *)(p + 0x24));
    func_021F1F24(p);
    *(volatile unsigned short *)0x04001050 = 0;
    func_02082BCC(p, 0, 0x468);
}





void *func_021F279C(int a, int b, int c, int d)
{
    u8 *p;
    p = func_02030734(0x70, 0x468, 1, (const char *)&d_021F3554, 0x1147);
    func_021F251C(p, a, b, c, d);
    return p;
}





char *func_021F27D8(int a0, int a1, int a2, void (*cb)(int), int arg, int flag)
{
    char *p = func_021F279C(a0, a1, a2, flag);

    *(void (**)(int))(p + 0x1fc) = cb;
    ((struct Obj03633 *)p)->f200 = arg;
    if (flag != 0) {
        func_021EFEF8(p, (void (*)(void))func_021F21F8, 0x1160);
        ((struct Obj03633 *)p)->f45B = 0;
    } else {
        if (*(void (**)(int))(p + 0x1fc) != 0)
            (*(void (**)(int))(p + 0x1fc))(((struct Obj03633 *)p)->f200);
        *(int *)&((struct Obj03633 *)p)->f1FC = 0;
        ((struct Obj03633 *)p)->f200 = 0;
    }
    func_021F3190(a0, ((struct Obj03633 *)p)->f24, func_020056EC(10), 0x70);
    func_021F20AC(p);
    return p;
}





/*
 * The listing extent (316 B) runs over an unlabelled 4-byte follower at
 * 0x021F2980 (`bx lr`); the function is 312 B.  func_021F3144's second
 * argument is this function's r1, forwarded untouched.
 */
void func_021F2848(u8 *p, u8 v)
{
    int st;
    u32 keys;
    void *snd;

    if (p[0x451] == 1)
        return;

    func_021F3144(p, v);
    if (func_021F2DA8(p) == 0) {
        st = func_02158630(func_02012138((const struct Ctx *)((struct Obj00761 *)p)->f1C));
        if (st == 3) {
            if (p[0x463] == 0) {
                func_021F06B8(p, 1, 0);
                p[0x463] = 1;
            }
        } else {
            if (p[0x463] == 1) {
                func_021F06B8(p, 0, 0);
                p[0x463] = 0;
            }
        }
        if (st == 0) {
            keys = func_0201058C((void *)func_0201283C(func_020120F4((const struct Ctx *)(((struct Obj00761 *)p)->f1C))));
            snd = (void *)func_02012A30((const struct BigObj *)func_020120F4((const struct Ctx *)(((struct Obj00761 *)p)->f1C)));
            if (keys & 8) {
                if (p[0x462] == 0) {
                    p[0x462] = 1;
                    func_021F06B8(p, 1, 1);
                }
                func_02028A64(snd);
            } else if ((keys & 8) == 0 && p[0x462] != 0) {
                func_02028A70(snd);
                p[0x462] = 0;
                func_021F06B8(p, 0, 0);
            }
        }
    }

    if (p[0x451] == 2) {
        p[0x451] = 0;
        if (func_021F2DA8(p) == 0) {
            func_021EFEF8((char *)p, (void (*)(void))func_021F2370, 0x11C5);
        } else {
            func_021F1BBC((char *)p);
            func_021F1A64((char *)p, 1);
            func_021F13FC(p);
            func_021F0EB0((char *)p, func_021F2DA8(p));
            func_021F0298(p);
            func_021EFEF8((char *)p, (void (*)(void))func_021F2180, 0x11D4);
        }
    }

    if (*(void (**)(u8 *))p != 0)
        (*(void (**)(u8 *))p)(p);
    if (((struct Obj00761 *)p)->f204 != 0)
        func_02030D28((struct Ctx *)(((struct Obj00761 *)p)->f204));
}




void func_021F2980(void)
{
}


void func_021F2984(char *p)
{
    func_021F26E0(p);
    func_020307B0((void *)((int)p));
}





int func_021F2994(int *p)
{
    int a = p[8];
    int b = p[6];
    int c = p[7];

    if (p[0] == (int)func_021F2180) {
        func_0202223C(1, 0);
        func_021F26E0((char *)p);
        func_021F251C((u8 *)p, a, b, c, 0);
        func_02022230(1);
        return 1;
    }
    return 0;
}





/*
 * The listing extent (252 B) runs over the matched follower 0x021F2AB8;
 * the function is 224 B.  Case order 1/6, 5, 12/13, 7/11 is the table's
 * code order; the shared "sound; r = func_021F2EEC" tails are cross-jumped.
 */
int func_021F29D8(char *p, int a)
{
    int r = 0;
    void *b;

    func_02012138((const struct Ctx *)*(int *)&((struct Obj00042 *)p)->f1C);
    b = func_0201210C(((struct Obj00042 *)p)->f1C);
    if (a == 0 || b == 0)
        return 0;

    switch (((struct Obj00042 *)p)->f214) {
    case 1:
    case 6:
        if (func_021F05B4((unsigned char *)p) == 0) {
            func_020061E4(0x54E);
            r = func_021F2EEC(p, ((struct Obj00042 *)p)->f214);
        } else {
            func_020061E4(0x7E3);
            func_021F3098((u8 *)p);
            func_021EFEF8(p, (void (*)(void))func_021F3118, 0x1238);
        }
        break;
    case 5:
        func_020061E4(0x54E);
        r = func_021F2EEC(p, ((struct Obj00042 *)p)->f214);
        break;
    case 12:
    case 13:
        func_020061E4(0x628);
        r = func_021F2EEC(p, ((struct Obj00042 *)p)->f214);
        break;
    case 7:
    case 11:
        if (func_021F05B4((unsigned char *)p) == 0) {
            func_020061E4(0x628);
            r = func_021F2EEC(p, ((struct Obj00042 *)p)->f214);
        } else {
            func_020061E4(0x7E3);
        }
        break;
    }

    if (r != 0) {
        ((struct Obj00042 *)p)->f218 = ((struct Obj00042 *)p)->f214;
        func_021EFEF8(p, func_021F2CD4, 0x1256);
    }
    ((struct Obj00042 *)p)->f214 = 0;
    return r;
}





/*
 * Unlabelled leaf, sole blocker of ov021 func_0218A6E8.
 */
int func_021F2AB8(char *p)
{
    if (p == 0)
        return 0;
    if (((struct Obj20398 *)p)->f218 == 5)
        return 1;
    return 0;
}




void func_021F2AD4(u8 *p)
{
    if (p != 0) {
        p[0x462] = 0;
        func_021F06B8(p, 0, 0);
    }
}





void func_021F2AEC(unsigned char *p, int a1, int a2, int a3, int k)
{
    int j;
    int i;

    for (j = 0; j < 4; j++) {
        for (i = 0; i < 9; i++) {
            if (k == func_021F2B9C(p, i, j)) {
                if (func_021F2BB8((u8 *)p, i, j) != 0) {
                    func_020091AC((struct Sub020090B0Obj *)a1, i, j, k, 0, 1);
                    func_021F1290((void *)p, i, j, k);
                } else if (func_021F2BD4((u8 *)p, i, j, k) != 0) {
                    func_020091AC((struct Sub020090B0Obj *)a1, i, j, k, 0, 0);
                }
            }
        }
    }
    func_020091AC((struct Sub020090B0Obj *)a1, a2, a3, k, 1, 0);
    func_021F1290((void *)p, a2, a3, k);
    func_020409B4(4);
    func_021F20AC((char *)p);
}




u32 func_021F2B9C(u8 *p, int row, int col)
{
    if (p[0x45a] != 0)
        return func_02009110(*(struct Sub020090B0Obj * *)&((struct Obj00042 *)p)->f20, row, col);
    return 0;
}




int func_021F2BB8(u8 *p, int row, int col)
{
    if (p[0x45a] != 0)
        return func_02009134(*(struct Sub020090B0Obj * *)&((struct Obj00042 *)p)->f20, row, col);
    return 0;
}




int func_021F2BD4(u8 *p, int row, int col, int kind)
{
    if (p[0x45a] != 0)
        return func_02009160(*(struct Sub020090B0Obj * *)&((struct Obj00042 *)p)->f20, row, col, kind);
    return 0;
}
