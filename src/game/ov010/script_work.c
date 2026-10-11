/*
 * file:     script_work.c
 * unit:     yes
 * function: func_02157954, func_02157960, func_02157968, func_0215796C, func_02157980, func_02157998, func_021579A4, func_021579AC, func_021579B0, func_02157A30, func_02157A58, func_02157A78, func_02157AC8, func_02157AF0, func_02157B88, func_02157C48, func_02157D0C, func_02157D68, func_02157D98, func_02157DB8, func_02157DD8, func_02157E08, func_02157E34, func_02157E6C, func_02157E78, func_02157E8C, func_02157E9C, func_02158318, func_02158344, func_02158378, func_0215839C, func_021583CC, func_021583EC, func_0215840C, func_0215841C, func_02158428, func_02158434, func_0215843C, func_02158468, func_021584A4, func_021584F4, func_0215850C, func_02158570, func_02158590, func_021585BC, func_021585E0, func_02158614, func_02158630, func_02158678, func_021586C8, func_0215870C, func_0215874C, func_02158768, func_02158780, func_021587B0, func_021587E0, func_02158804, func_02158824, func_0215882C, func_0215886C, func_02158894, func_0215889C, func_021588A4, func_021588B0, func_021588C0, func_021588D0, func_021588DC, func_02158920, func_0215897C, func_0215898C, func_021589A0, func_021589D0, func_021589DC, func_021589F4, func_02158A10, func_02158A20, func_02158A34, func_02158A90, func_02158AC8, func_02158AD4, func_02158AE0, func_02158B00, func_02158B3C, func_02158B6C, func_02158BFC, func_02158CB4, func_02158CD0, func_02158D78, func_02158D90, func_02158DB0, func_02158DBC, func_02158DE8, func_02158E38, func_02158E54, func_02158E7C, func_02158F18, func_02158F50, func_02158F54, func_02158F58, func_02158F6C, func_02158F74, func_02158F78, func_02158F7C, func_02158F80, func_02158F84, func_02158F88, func_02158F8C, func_02158F90, func_02158F94, func_02158FB4, func_02158FB8, func_02158FBC, func_02158FD0, func_02158FE0, func_0215901C, func_02159030, func_02159058, func_0215909C, func_021590D4, func_021590F4, func_021590FC, func_02159104, func_0215910C, func_02159114, func_0215911C, func_02159124, func_02159130, func_02159144, func_02159168, func_02159190, func_02159198, func_021591B4, func_02159204, func_02159240, func_02159244, func_02159248, func_02159254, func_02159260, func_02159284, func_0215929C, func_021592A8, func_021592C0, func_021592D8
 * address:  0x02157954
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203CD98  0x0203CD98  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_0203F328  0x0203F328  arm
 *   func_02179D3C 0x02179D3C thumb ov015
 *   func_0203CEAC 0x0203CEAC arm
 *   func_020399A8  0x020399A8  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0203D378  0x0203D378  arm
 *   func_0217998C  0x0217998C  thumb ov015
 *   func_02039C68 0x02039C68 arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_020056EC  0x020056EC  thumb
 *   func_0203D1B4 0x0203D1B4 arm
 *   func_0203D0DC 0x0203D0DC arm
 *   func_02030734 0x02030734 arm
 *   d_02172878 0x02172878 data a1
 *   func_0203CBAC 0x0203CBAC arm
 *   d_02172868 0x02172868 data a1
 *   d_02172808 0x02172808 data a1
 *   func_020307B0  0x020307B0  arm
 *   func_02012944  0x02012944  thumb
 *   func_02008530  0x02008530  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_020173F0  0x020173F0  thumb
 *   func_020186C8  0x020186C8  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017FA8  0x02017FA8  thumb
 *   func_0201808C  0x0201808C  thumb
 *   func_020180F4  0x020180F4  thumb
 *   func_02018A00  0x02018A00  thumb
 *   func_020185F0  0x020185F0  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_0202F2AC  0x0202F2AC  thumb
 *   func_02045A98  0x02045A98  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   d_02170068     0x02170068  data
 *   d_0209DF08     0x0209DF08  data  a1
 *   d_0209DF0C     0x0209DF0C  data  a1
 *   d_020A7370     0x020A7370  data
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_0202648C  0x0202648C  thumb
 *   func_02026474  0x02026474  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026460  0x02026460  thumb
 *   func_02026478  0x02026478  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_020127B8   0x020127B8  thumb
 *   func_020127AC   0x020127AC  thumb
 *   func_02012950   0x02012950  thumb
 *   func_02012B80   0x02012B80  thumb
 *   func_0200855C 0x0200855C thumb
 *   func_02012984  0x02012984  thumb
 *   func_02012B98  0x02012B98  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_0201444C  0x0201444C  thumb
 *   d_021700AC 0x021700AC data a2
 *   func_0201296C 0x0201296C thumb
 *   func_020142E8 0x020142E8 thumb
 *   d_021700A8 0x021700A8 data a2
 *   func_02175B14  0x02175B14  thumb
 *   func_02176258  0x02176258  thumb
 *   func_02176230  0x02176230  thumb
 *   func_02008500  0x02008500  thumb
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_020124E4 0x020124E4 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02012374 0x02012374 thumb
 *   func_0201235C  0x0201235C  thumb
 *   d_02172888 0x02172888 data a1
 *   func_02011298  0x02011298  thumb
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_02014368  0x02014368  thumb
 *   func_020143D8  0x020143D8  thumb
 *   func_02012844 0x02012844 thumb
 *   func_02162450 0x02162450 thumb ov010
 *   func_020143CC  0x020143CC  thumb
 *   func_0215A55C  0x0215A55C  thumb  ov010
 *   func_0201121C  0x0201121C  thumb
 *   func_0201126C  0x0201126C  thumb
 *   func_0215A760  0x0215A760  thumb  ov010
 *   func_0201127C  0x0201127C  thumb
 *   func_0201134C  0x0201134C  thumb
 *   d_0217062C     0x0217062C  data  ov010
 *   d_021705D8     0x021705D8  data  ov010
 *   func_02011324  0x02011324  thumb
 *   func_0215A5A4  0x0215A5A4  thumb  ov010
 *   func_02011264  0x02011264  thumb
 *   func_02034714  0x02034714  arm
 *   func_02013B5C  0x02013B5C  thumb
 *   func_02013B68  0x02013B68  thumb
 *   d_021701A8     0x021701A8  data  a4
 *   d_02172898     0x02172898  data  ov010  a1
 *   func_0204A1BC 0x0204A1BC arm
 *   func_0203CF04  0x0203CF04  arm
 *   func_0203D0D0  0x0203D0D0  arm
 *   func_0203CF5C  0x0203CF5C  arm
 *   func_020053EC  0x020053EC  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0215A5D4  0x0215A5D4  thumb  ov010
 *   func_0215A5D8  0x0215A5D8  thumb  ov010
 *   d_02170374     0x02170374  data  ov010
 *   func_02011328 0x02011328 thumb
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_02082A7C  0x02082A7C  arm
 *   func_02188C54  0x02188C54  thumb
 *   func_0201EC74  0x0201EC74  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0215A514  0x0215A514  thumb  ov010
 *   d_0217289C     0x0217289C  data  ov010  a1
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0215A554  0x0215A554  thumb  ov010
 *   func_0216D588 0x0216D588 thumb ov010
 *   func_02082A60 0x02082A60 arm
 *   d_02172BA0 0x02172BA0 data a4
 *   d_021705F0     0x021705F0  data  ov010
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_02011290  0x02011290  thumb
 *   func_0215A690  0x0215A690  thumb  ov010
 *   func_0215A684   0x0215A684  thumb  ov010
 *   func_02011330   0x02011330  thumb
 *   func_020113D0   0x020113D0  thumb
 *   func_020113B4  0x020113B4  thumb
 *   func_020113C4  0x020113C4  thumb
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02011398  0x02011398  thumb
 */
#include "../../matched/include/Obj18739.h"
#include "../../matched/include/Obj01335.h"
#include "../../matched/include/Obj02664.h"
#include "../../matched/include/Obj01831.h"
#include "../../matched/include/Obj04915.h"
#include "../../matched/include/Obj18743.h"
#include "../../matched/include/Obj18744.h"
#include "../../matched/include/Obj07276.h"
#include "../../matched/include/Obj18745.h"
#include "../../matched/include/Obj17623.h"
#include "../../matched/include/Obj00105.h"
#include "../../matched/include/Obj12028.h"
#include "../../matched/include/Obj09153.h"
#include "../../matched/include/Obj12029.h"
#include "../../matched/include/Obj17624.h"
#include "../../matched/include/Obj12271.h"
#include "../../matched/include/Obj17625.h"
#include "../../matched/include/Obj12030.h"
#include "../../matched/include/Obj17626.h"
#include "../../matched/include/Obj01023.h"
#include "../../matched/include/Obj17627.h"
#include "../../matched/include/Obj00020.h"
#include "../../matched/include/Obj17628.h"
#include "../../matched/include/Obj17629.h"
#include "../../matched/include/Obj17630.h"
#include "../../matched/include/Obj17631.h"
#include "../../matched/include/Obj17632.h"
#include "../../matched/include/Obj17633.h"
#include "../../matched/include/Obj17634.h"
#include "../../matched/include/Obj18753.h"
#include "../../matched/include/Obj17635.h"
#include "../../matched/include/Obj17636.h"
#include "../../matched/include/Obj17637.h"
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj18755.h"
#include "../../matched/include/Obj17639.h"
#include "../../matched/include/Obj17640.h"
#include "../../matched/include/Obj18756.h"
#include "../../matched/include/Obj18757.h"
#include "../../matched/include/Obj17641.h"
#include "../../matched/include/Obj17642.h"

struct Entry;
struct Link;
struct Object;
struct Req;
struct Mon;
struct MsgBank;
struct U16Vec;
struct Sub0200852CObj;
struct Ctx;
struct BigObj;
struct SaveBlock;
struct Rec44;
struct Sub24;
struct Sub02014444Obj;
struct Desc;
struct Obj;
struct Evt;
struct ScriptVm;
struct S0201235C;
struct ScriptVmParams;
struct Cursor;
struct WordSet;
struct S;
struct Stream;
struct Ring;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed short s16_02157954;

typedef signed int s32_0215796C;

typedef struct { u32 a; u16 b; } S;

typedef struct { u8 pad[0x668]; u32 a; u8 pad2[6]; u16 b; } D_0215796C;

typedef signed int s32_02157980;

typedef struct { u32 a, b; } V;

typedef struct { u8 pad[0x67c]; V v; } D_02157980;

typedef signed int s32_02157998;

typedef struct { u8 pad[0x66c]; u32 w; } D_02157998;

typedef signed int s32_021579A4;

typedef struct { int a; u16 b; } Loc;

typedef struct Object {
    u32 f00;
    u8 pad04[0x74];
    u32 n;
} Object;

typedef int s32_021579AC;

typedef unsigned long long u64;

typedef struct GiftMon {
    u32 otId;           /* 0x00 */
    u32 f04;            /* 0x04 */
    u32 pid;            /* 0x08 */
    u16 ribbons;        /* 0x0C */
    u16 ball;           /* 0x0E */
    u16 item;           /* 0x10 */
    u16 moves[4];       /* 0x12 */
    u16 species;        /* 0x1A */
    u8 form;            /* 0x1C */
    u8 lang;            /* 0x1D */
    u16 nick[11];       /* 0x1E */
    u8 nature;          /* 0x34 */
    u8 gender;          /* 0x35 */
    u8 ability;         /* 0x36 */
    u8 pidType;         /* 0x37 */
    u16 eggLoc;         /* 0x38 */
    u16 metLoc;         /* 0x3A */
    u8 f3C;             /* 0x3C */
    u8 contest[6];      /* 0x3D */
    u8 hp;              /* 0x43 */
    u8 atk;             /* 0x44 */
    u8 def;             /* 0x45 */
    u8 spe;             /* 0x46 */
    u8 spa;             /* 0x47 */
    u8 spd;             /* 0x48 */
    u8 pad49;
    u16 otName[8];      /* 0x4A */
    u8 otGender;        /* 0x5A */
    u8 level;           /* 0x5B */
    u8 isEgg;           /* 0x5C */
    u8 pad5D[0xAC - 0x5D];
    s32_021579AC date;           /* 0xAC */
    u8 padB0[3];
    u8 fB3;             /* 0xB3 */
} GiftMon;

typedef struct IvMoves {
    u8 iv[6];
    u16 moves[4];
} IvMoves;

typedef struct { u8 a : 4; u8 f : 2; u8 b : 2; } Fl_0;

typedef struct Rec28 {
    u8 data[0x28];
} Rec28;

typedef struct RecHolder {
    u8 pad[0x1AC];
    Rec28 recs[1];      /* 0x1AC */
} RecHolder;

typedef struct { u16 f : 3; u16 g : 13; } Fh;

typedef struct { u8 low:2; u8 flag:1; u8 high:5; } Flag_021585E0;

typedef struct { u8 a : 5; u8 f : 1; u8 b : 2; } Fl_1;

typedef struct { u8 a : 6; u8 f : 1; u8 b : 1; } FlagsF8;

typedef struct { u8 low:2; u8 flag:2; u8 high:4; } Flag_0215874C;

typedef signed char s8;

typedef short s16_021588D0;

struct V { u16 x, y; int a; int b; int c; };

struct W { u16 w, h; int p; int q; };

struct E { u16 lo, hi, a, b, c; };

struct Bits { u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; };

struct O {
    int f0; u16 f4; int f8; u16 fc; int f10, f14, f18[3];
    int f24;
    int f20, f28, f2c, f30, f34;
};

typedef signed short   s16;

typedef enum { BIT = 1 } Mask;

typedef int (*Fn)(int *, int *);

struct S { int _0, _4, _8; int c; int idx; int n; };

typedef struct TaskWork { void *system; void *vm; void *owner; int c; int idx; int n; } TaskWork;

typedef struct { u8 pad00[0x14]; u8 *pc; u8 pad18[4]; u32 *vars; } Ctx_021592D8;

extern int func_0203CD98(void);
extern void func_02082D44(void *, void *, u32);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void func_0203F328(u16 *p, u32 size, u32 seed);
extern int func_02179D3C(void);
extern int func_0203CEAC(int);
extern struct Entry *func_020399A8(void);
extern u32 func_02039CB4(struct Link *p, u32 lo, u32 hi);
extern u32 func_0203D378(void);
extern void func_0217998C(int);
extern void func_02039C68(struct Link *, unsigned int, unsigned int);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern u32 func_020056EC(u32 range);
extern int func_0203D1B4(void);
extern int func_0203D0DC(int a0);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern int func_020307B0();
extern u8 *func_02012944(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern const void *func_020084F4(const void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_020173F0(u16 species, u16 level, u64 id, int heap);
extern u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_02017FA8(void *p);
extern u32 func_0201808C(void *p, u32 move);
extern void func_020180F4(void *p, int move);
extern void func_02018A00(void *p, u32 a, u32 b);
extern void *func_020185F0(void *p);
extern void func_020185C4(void *p);
extern void func_0202F2AC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern u16 func_02045A98(void);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern int func_02045808();
extern u32 func_02012138(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern int func_02012B70(const struct BigObj *p);
extern u32 func_0202648C(void *obj);
extern u32 func_02026474(void *obj);
extern u32 func_0200FB24(void);
extern u32 func_02026454(void *obj);
extern u32 func_02026460(void *obj);
extern u32 func_02026478(void *obj);
extern u8 func_02012B58(const struct BigObj *p);
extern void *func_020127B8(void *p);
extern void *func_020127AC(struct SaveBlock *p, u32 idx);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern u8 func_02012B80(const struct BigObj *p);
extern u8 func_0200855C(const struct Sub0200852CObj *obj);
extern u8 func_02012984(const struct BigObj *p);
extern u8 func_02012B98(const struct BigObj *p, u32 i);
extern void *func_02012B38(const struct BigObj *p);
extern u32 func_0201444C(struct Sub02014444Obj *o);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *, int);
extern int func_02175B14();
extern int func_02176258(int);
extern int func_02176230(void *, void *);
extern void func_02008500(void *a, void *b);
int func_0203CDBC();
extern void *func_020124E4(struct Obj *p);
extern void *func_020124E8(struct Obj *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_0201235C();
extern int func_02011298(struct ScriptVm *vm);
extern u8 *func_020120F8(const struct Ctx *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, unsigned int size);
extern int func_02014368();
extern int func_020143D8();
extern u32 func_02012844(const struct BigObj *p);
extern u32 func_02162450(void *p);
extern u32 func_020143CC(u32 a, u32 b);
extern int func_0215A55C(const struct V *, int);
extern struct ScriptVm *func_0201121C(u32 heapId, const struct ScriptVmParams *params);
extern void func_0201126C(struct ScriptVm *vm, void *user);
extern void func_0215A760(u8 *a, unsigned b, unsigned c);
extern void func_0201127C(struct ScriptVm *vm, u8 *pc);
extern u32 func_0201134C(struct Cursor *p);
extern void *func_02011324(struct ScriptVm *vm);
extern int func_0215A5A4(int a0);
extern int func_02011264();
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_02013B5C(u32 id);
extern u16 func_02013B68(u16);
extern int func_0204A1BC(int, int, int, int);
extern int func_0203CF04();
extern int func_0203D0D0();
extern u32 func_0203CF5C(void);
extern int func_020053EC();
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_0215A5D4(void *p);
extern u32 func_0215A5D8(void *p);
extern void *func_0215A5DC(void *a0);
extern void func_02011328(void *, int (*)(int, void *, void *, int), void *);
extern int func_02082A7C();
extern int func_02188C54();
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_0215A514(int a, int heap);
extern int func_0201ED04();
extern int func_0215A554();
extern u16 func_0216D588(void *);
extern void func_02082A60(const void *, void *, unsigned int);
extern void *func_0215A5F4(void *p);
extern struct ScriptVm *func_02011290(struct ScriptVm *vm);
extern int func_0215A690(char *);
extern u16 func_02011330(struct Stream *s);
extern void func_0215A684(int *p, unsigned short v);
extern void func_020113D0(char *p, int val);
extern int func_020113B4();
extern u32 func_020113C4(struct Ring *r);
extern void *func_0215A5E4(void *a0);
extern unsigned int func_02159B10(void *, void *);
extern u32 func_02011398(struct Ring *r);
void func_02157954(u8 *p, int v, int a2);
void func_02157960(int a, int b, int c);
void func_02157968(void);
void func_0215796C(int x, int y, S *s, D_0215796C *d);
void func_02157980(int x, int y, const V *s, D_02157980 *d);
void func_02157998(int x, int y, u32 *s, D_02157998 *d);
u8 *func_021579A4(int a, u8 *p);
void func_021579AC(void);
void func_021579B0(u8 *p);
void func_02157A30(int p);
void func_02157A58(int p);
void func_02157A78(u32 *p);
void func_02157AC8(int *p);
void func_02157AF0(int *p);
void func_02157B88(int *p);
void func_02157C48(Object *p);
void func_02157D0C(int *p);
void func_02157D68(int *p);
void func_02157D98(int p);
void func_02157DB8(int p);
void *func_02157DD8(u8 *p);
int func_02157E08(void *p);
int func_02157E34(void *p);
unsigned char func_02157E6C(char *p);
void func_02157E78(u8 *p);
int func_02157E8C(void *a0);
void *func_02157E9C(const GiftMon *g, int heap, void *save);
int func_02158318(int a0);
int func_02158344(int a0);
int func_02158378(void *p);
int func_0215839C(u8 *p, int m, int a2);
int func_021583CC(void *a0, int a1);
int func_021583EC(void *a0, int a1);
Rec28 *func_0215840C(RecHolder *h, int idx);
u8 func_0215841C(void *p);
u8 func_02158428(u8 *p);
void *func_02158434(char *p);
int func_0215843C(void *p);
int func_02158468(int a0);
int func_021584A4(int unused, int a, int mode);
int func_021584F4(int a0, int a1);
int func_0215850C(int a0, int a1);
int func_02158570(u16 value);
int func_02158590(void *p);
int func_021585BC(int a0);
int func_021585E0(int p);
void func_02158614(void *p);
int func_02158630(int a);
int func_02158678(void *p);
int func_021586C8(int a, int b);
int func_0215870C(void *p, int b);
void func_0215874C(void *p);
struct Desc *func_02158768(int a0, u16 a1, int a2, int a3);
int func_02158780(void *p, u16 b, int c, int d, u16 e);
int func_021587B0(int a0, u16 a1, int a2, int a3);
int func_021587E0(int a, int b);
void *func_02158804(u32 heap);
void func_02158824(void *a0);
int func_0215882C(int a0);
int func_0215886C(int a0, int a1);
int func_02158894(int a0, int a1);
void func_0215889C(void *p, u32 *out);
void func_021588A4(void *p, int a);
int func_021588B0(struct Obj00105 *obj, int arg);
int func_021588C0(int a0);
u16 func_021588D0(int a0);
int func_021588DC(int arg, int unused, struct Obj12030 *cell);
struct Desc *func_02158920(int a, int b, u16 c, int d, int e);
void func_0215897C(void *vm, void *task);
void func_0215898C(int a, int b);
int func_021589A0(int a, u16 b, u16 c);
int func_021589D0(int a0);
int func_021589DC(int a0);
int func_021589F4(int a0);
void func_02158A10(int a, int b);
void func_02158A20(int a, int v);
void func_02158A34(int a, int b, u16 c, int d);
int func_02158A90(void *a, int unused, int key, int d);
void func_02158AC8(int a, int b);
void func_02158AD4(int a, int b);
void func_02158AE0(void *a0, void *a1);
void *func_02158B00(void *a, u32 b);
u16 func_02158B3C(const u8 *p, int key);
u16 func_02158B6C(const void *a, const u8 *list, u32 key);
int *func_02158BFC(u16 a0, int a1, u16 a2, u16 a3, int a4);
int func_02158CB4(int a0);
u16 func_02158CD0(unsigned k, unsigned v, u16 *o1, u16 *o2, u16 *o3);
void *func_02158D78(int a, int b);
int func_02158D90(u16 v);
int func_02158DB0(int a0);
int func_02158DBC(void);
int func_02158DE8(int a, int b, int c, int idx);
void func_02158E38(void *a);
int func_02158E54(int a0, int a1);
int *func_02158E7C(u16 a, int b, int c, int d, int e, int f);
int func_02158F18(int a0);
void *func_02158F50(void *p);
void *func_02158F54(void *p);
int func_02158F58(int a0);
u32 func_02158F6C(void *p);
void *func_02158F74(void *p);
u32 func_02158F78(u8 *p);
u32 func_02158F7C(u8 *p);
void func_02158F80(u8 *p, u32 v);
u32 func_02158F84(u8 *p);
u8 *func_02158F88(void *p);
u16 func_02158F8C(u8 *p);
void *func_02158F90(void *p);
void func_02158F94();
void *func_02158FB4(void *p);
u32 func_02158FB8(void *p);
void func_02158FBC(int a0);
int func_02158FD0();
u16 *func_02158FE0(void *a, void *b, unsigned int id);
unsigned int func_0215901C(void *a, void *b, unsigned int id);
int func_02159030(int a0, int a1, int a2);
int func_02159058(int a, int b, int c, int d, u16 e);
void *func_0215909C(u8 *a);
void func_021590D4(void *a, void *b, int a2);
void func_021590F4(void *p, u32 v);
u32 func_021590FC(void *p);
void func_02159104(u8 *p, u32 v);
u32 func_0215910C(void *p);
void *func_02159114(void *p, u32 v);
u32 func_0215911C(void *p);
char *func_02159124(char *p, int i);
void func_02159130(void);
void func_02159144(int n);
void func_02159168(int n);
int func_02159190(int a0);
int func_02159198(int n);
int func_021591B4(int a, int b, struct S *p);
void *func_02159204(void *vm);
int func_02159240(void);
int func_02159244(void);
int func_02159248(struct ScriptVm *a0);
void func_02159254(char *a0, char *a1);
int func_02159260(void *a0, void *a1);
int func_02159284(int a0, int a1, int a2);
int func_0215929C(struct Ring *a0);
int func_021592A8(int a0, int a1);
int func_021592C0(int a0, int a1);
int func_021592D8(Ctx_021592D8 *c);
extern const char d_02172878[];
extern u8 d_02172868[];
extern u8 d_02172808[];
extern u32 d_02170068[];
extern u8 d_0209DF08[];
extern u8 d_0209DF0C[];
extern void *d_020A7370;
extern const u16 d_021700AC[61];
extern const u16 d_021700A8[2];
extern const char d_02172888[];
extern int d_0217062C;
extern int d_021705D8;
extern const struct E d_021701A8[];
extern char d_02172898[];
extern struct Bits d_02170374[];
extern char d_0217289C[];
extern int d_02172BA0;
extern Fn d_021705F0[];





/*
 * Unlabelled leaf setter (hidden in a .word run); filed as a helper because
 * its address is the witness for the tail-call thunk at 0x02157960.
 */
void func_02157954(u8 *p, int v, int a2)
{
    ((struct Obj18739 *)p)->f678 = v;
}





void func_02157960(int a, int b, int c)
{
    func_02157954((u8 *)a, b, c);
}




void func_02157968(void) {}



void func_0215796C(int x, int y, S *s, D_0215796C *d) { d->b = s->b; d->a = s->a; }



void func_02157980(int x, int y, const V *s, D_02157980 *d) { d->v = *s; }



void func_02157998(int x, int y, u32 *s, D_02157998 *d) { d->w = *s; }




u8 *func_021579A4(int a, u8 *p) { return p + 0x7c; }









/*
 * Unlabelled empty callback (bx lr) hidden in a .word run; witness for the
 * function pointer taken in func_021579B0.
 */
void func_021579AC(void)
{
}










void func_021579B0(u8 *p)
{
    if (func_0203CD98() != 0)
        return;
    if (p[0x675] == 0) {
        if (((struct Obj01335 *)p)->f66C == 1) {
            p[0x674] = 3;
        } else {
            p[0x674] = 1;
            func_02082D44(p + 0x7C, ((struct Obj01335 *)p)->fC, ((struct Obj01335 *)p)->f8);
            if (((struct Obj01335 *)p)->f672 != func_0203F1FC(*(const u8 * *)&((struct Obj01335 *)p)->fC, ((struct Obj01335 *)p)->f8))
                p[0x674] = 2;
            func_0203F328(((struct Obj01335 *)p)->fC, ((struct Obj01335 *)p)->f8, ((struct Obj01335 *)p)->f668);
        }
    } else {
        if (p[0x676] == 1)
            p[0x674] = 1;
        else
            p[0x674] = 3;
    }
    func_02157960((int)p, (int)func_021579AC, 0xF8);
}









void func_02157A30(int p) { if (func_02179D3C()) func_0203CEAC(0); func_02157960(p, (int)func_021579B0, 0x102); }









void func_02157A58(int p) { func_0203CEAC(0); func_02157960(p, (int)func_021579B0, 0x10a); }










void func_02157A78(u32 *p)
{
    int k = 0x23;
    void *h = func_020399A8();

    if (func_02039CB4(h, 0x23, (u8)*p) != 0) {
        if (func_0203D378() != 0) {
            k = 0x12C;
            func_0217998C(k);
            k -= 0x19;
            func_02157960((int)p, (int)func_02157A30, k);
            return;
        }
        k += 0xF3;
        func_02157960((int)p, (int)func_02157A58, k);
    }
}









void func_02157AC8(int *p) { int k = 0x23; func_02039C68((struct Link *)func_020399A8(), k, (u8)p[0]); func_02157960((int)p, (int)func_02157A78, k + 0xfc); }









void func_02157AF0(int *p)
{
    u8 *b = (u8 *)p;
    if (func_02039CB4((struct Link *)func_020399A8(), 0x18, (u8)p[0]) == 0)
        return;
    if (b[0x675] != 0) {
        if (b[0x676] == 1) {
            int *e = (int *)(b + 8 + b[0x677] * 16);
            int k = 0xFF;
            if (func_0203D3F8((u32)func_020399A8(), 0xFF, (unsigned)(p[0] << 24) >> 16, e[0], e[1], 0, 0, 1) == 0)
                return;
            func_02157960((int)p, (int)((void *)func_02157AC8), k + 0x2F);
            return;
        }
        func_02157960((int)p, (int)((void *)func_02157AC8), 0x133);
        return;
    }
    func_02157960((int)p, (int)((void *)func_02157AC8), 0x137);
}









void func_02157B88(int *p)
{
    u8 *b = (u8 *)p;
    if (b[0x676] == 1) {
        Loc l;
        int *s = *(int * *)&((struct Obj02664 *)b)->f664;
        l.b = func_0203F1FC((const u8 *)s[1], s[0]);
        l.a = ((struct Obj02664 *)b)->f668;
        if (func_0203D3A8(func_020399A8(), (u16)((p[0] << 8) + 1), (u16)8, (u32)(&l)) == 0)
            return;
        func_02039C68((struct Link *)func_020399A8(), 0x18, (u8)p[0]);
        ((struct Obj02664 *)b)->f670 = 0;
        func_02157960((int)p, (int)((void *)func_02157AF0), 0x152);
        return;
    }
    ((struct Obj02664 *)b)->f66C = 1;
    if (func_0203D3A8(func_020399A8(), (u16)((p[0] << 8) + 3), (u16)4, (u32)(b + 0x66C)) == 0)
        return;
    func_02039C68((struct Link *)func_020399A8(), 0x18, (u8)p[0]);
    ((struct Obj02664 *)b)->f670 = 0;
    func_02157960((int)p, (int)((void *)func_02157AF0), 0x162);
}









/*
 * levers: the RNG result is the third argument to func_0203F328, kept live
 *   in r2 across its preceding store. The bound is read as p->n in the for
 *   condition rather than through n; expanding that one use changes the
 *   hoisted bound/far-word allocation from r7/r6 to the original r6/r7.
 */
void func_02157C48(Object *p)
{
    u8 *b = (u8 *)p;
    int *e;
    u32 i;
    unsigned long n;
    if (func_02039CB4((struct Link *)func_020399A8(), 0x17, (u8)p->f00) == 0)
        return;
    if (b[0x675] != 0) {
        e = 0;
        b[0x676] = 0;
        n = p->n;
        for (i = 0; i < p->n; i++) {
            e = (int *)(b + 8 + i * 16);
            if (e[2] == ((struct Obj01831 *)b)->f67C && (e[3] & ((struct Obj01831 *)b)->f680)) {
                b[0x677] = i;
                b[0x676] = 1;
                break;
            }
        }
        func_02157960((int)p, (int)func_02157B88, 0x188);
        if (b[0x676] == 1) {
            u32 t = func_020056EC(0);
            ((struct Obj01831 *)b)->f668 = t;
            func_0203F328((u16 *)e[1], e[0], t);
            *(int * *)&((struct Obj01831 *)b)->f664 = e;
        }
        return;
    }
    func_02039C68((struct Link *)func_020399A8(), 0x18, (u8)p->f00);
    func_02157960((int)p, (int)func_02157AF0, 0x193);
}









void func_02157D0C(int *p)
{
    if (*((u8 *)p + 0x675) == 0) {
        ((struct Obj04915 *)p)->f67C = p[4];
        ((struct Obj04915 *)p)->f680 = p[5];
        if (func_0203D3A8(func_020399A8(), (u16)((p[0] << 8) + 2), (u16)8, (u32)((u8 *)p + 0x67C)) == 0)
            return;
        func_02157960((int)p, (int)((void *)func_02157C48), 0x1A2);
        return;
    }
    func_02157960((int)p, (int)((void *)func_02157C48), 0x1A6);
}








void func_02157D68(int *p) { if (func_0203D1B4() > 1) { func_02039C68((struct Link *)func_020399A8(), 0x17, (u8)p[0]); func_02157960((int)p, (int)func_02157D0C, 0x1af); } }








void func_02157D98(int p)
{
    func_0203D0DC(0);
    func_02157960(p, (int)func_02157D68, 0x1B7);
}








void func_02157DB8(int p)
{
    if (func_0203CD98() == 1)
        func_02157960(p, (int)func_02157D98, 0x1BE);
}








void *func_02157DD8(u8 *p)
{
    void *q = func_02030734(((struct Obj18743 *)p)->f6, 0x684, 1, d_02172878, 0x1CD);
    func_02082D44(p, q, 0x7C);
    return q;
}








int func_02157E08(void *p)
{
    if (func_0203CD98() != 0)
        return 0;
    d_02172868[7] = ((struct Obj18744 *)p)->f0;
    func_0203CBAC((struct Req *)d_02172808, 0, (u32)p);
    return 1;
}








int func_02157E34(void *p)
{
    int r = func_02157E08(p);
    *((u8 *)p + 0x675) = 0;
    *((u8 *)p + 0x676) = 0;
    *((u8 *)p + 0x677) = 0;
    ((struct Obj07276 *)p)->f66C = 0;
    func_02157960((int)p, (int)((void *)func_02157DB8), 0x231);
    return r;
}







/*
 * extent: Accessor ends at 02157E78, followed by labelled callback function.
 */
unsigned char func_02157E6C(char *p)
{
    return ((struct Obj18745 *)p)->f674;
}







void func_02157E78(u8 *p)
{
    void (*callback)(u8 *) = *(void (**)(u8 *))(p + 0x678);
    if (callback != 0)
        callback(p);
}








int func_02157E8C(void *a0)
{

    a0 = (void *)func_020307B0(a0);
loc_02157E92:
a0 = 0;
    a0 = (void *)func_0203CEAC((int)a0);
loc_02157E98:
    return (int)a0;}








/*
 * Wave 76 lever: gender is a u8 local, loaded from GiftMon.gender and
 * remapped from 0xFF to 2. With the form extern parameter u8, this restores
 * both personality-call setup schedules: 19 differing bytes become EXACT.
 * Signed 64-bit PID and ID were flat19; union PID worsened to38. The u8
 * form extern alone stayed19. Old seed7201 budget400 was not repeated.
 * checks: 1 own callees and forwarding bodies re-read, six personality inputs; 2 021684E8/ov121 DEFAC inspected; 3 byte form flat19, byte gender EXACT; 4 existing width/const idioms inspected; 5 current neighbours and idioms inspected before filing.
 * Wave 75 fresh pass: unsigned-long species, enum flag argument, enum slot, u16 form argument, and nonconst GiftMon each19/1148 B; retain original const best. All54 relocations resolved. Old seed7201 budget400 consumed; never rerun.
 * Prior recorded evidence (retained):
 * func_02157E9C (ov010, Thumb, 1148 bytes), tree_ov010_2, 2026-09-28
 *
 * Best source: src/pending/ov010_func_02157E9C.c (DIFF, size right, 54 of 54
 * relocations resolved, 10 instructions out). The residue is the argument
 * setup of the first and third func_020186C8 calls:
 *
 *   image  (pidType 0): ldr r1,[sp,#0x20]; str r0,[sp]; movs r0,#0; lsls r1;
 *                       ldrb r2,[r4,#0x1c]; str r0,[sp,#0x28]; str r0,[sp,#4]
 *   this C (pidType 0): str r0,[sp]; movs r0,#0; ldr r1,[sp,#0x20];
 *                       str r0,[sp,#4]; str r0,[sp,#0x28]; lsls r1; ldrb r2
 *   image  (pidType 2): ldr r1; ldrb r2; str r0,[sp,#4]; lsls r1
 *   this C (pidType 2): ldr r1; str r0,[sp,#4]; lsls r1; ldrb r2
 *
 * Measured:
 * - 288-shape grid (species u32/int/u16 x species arg plain/(u16) x callee
 *   a1 u16/int/u32 x form arg plain/(int) x slot u32/int x gender u32/int x
 *   if-chain/switch on pidType): flat at 10 or 11, never lower.
 * - pid as two u32 locals (the ov121 func_021DEFAC spelling, hi written
 *   before the call in pidType 0 and after in 1 and 2): 431 at every one of
 *   the 46 declaration positions (level leaves its stack slot for r7).
 * - pid as u32[2]: 432. Half writes through ((u32 *)&pid)[k]: 52 (pid moves
 *   to sp+0x34).
 * - permuter seed 7201, budget 400, focus 0x17E: no gain.
 *
 * The same function exists in ov121 (src/pending/func_021DEFAC.c, DIFF); a
 * lever found for one should be tried on the other.
 *
 * 2026-09-28, tree_ov010_3: not re-drafted (the lane's time went to the
 * open roots); the residue above is unchanged at 10 instructions.
 *
 * Builds a gift Pokemon from a mystery-gift record. 1148/1148 bytes, every
 * relocation resolved, 10 instructions out in two argument-setup schedules
 * of the func_020186C8 calls (pid types 0 and 2). See
 * docs/notes/pkt_ov010_02157E9C.c.txt.
 */
void *func_02157E9C(const GiftMon *g, int heap, void *save)
{
    u16 moves[4];
    u8 iv[6];
    u32 month;
    u32 ability;
    u8 gender;
    u64 pid;
    u32 species;
    u32 otId;
    u64 id;
    u16 level;
    u32 slot;
    void *ret;
    u32 ivs;
    int i;
    u32 k;
    u16 mv;
    void *pp;
    void *name;
    u32 v;
    u8 day;
    u16 year;
    u32 loc;

    level = g->level;
    otId = g->otId;
    species = g->species;
    gender = g->gender;
    ability = g->ability;
    iv[0] = g->hp;
    iv[1] = g->atk;
    iv[2] = g->def;
    iv[3] = g->spa;
    iv[4] = g->spd;
    iv[5] = g->spe;
    moves[0] = g->moves[0];
    moves[1] = g->moves[1];
    moves[2] = g->moves[2];
    moves[3] = g->moves[3];

    if (g->fB3 != 1) {
        ret = 0;
        goto out;
    }
    if (species > 649) {
        ret = 0;
        goto out;
    }
    if (species == 0) {
        ret = 0;
        goto out;
    }
    if (level > 100) {
        ret = 0;
        goto out;
    }
    if (g->item > 626) {
        ret = 0;
        goto out;
    }

    if (level == 0)
        level = func_020056EC(100) + 1;
    if (g->otId == 0)
        otId = func_02008530((const struct Sub0200852CObj *)func_02012944(save));
    if (gender == 0xFF)
        gender = 2;
    for (i = 0; i < 6; i++) {
        if (iv[i] == 0xFF)
            iv[i] = func_020056EC(32);
    }

    id = otId;
    pp = func_020173F0(species, level, id, heap);
    ivs = (iv[0] & 0x1F) | ((iv[1] & 0x1F) << 5) | ((iv[2] & 0x1F) << 10)
        | ((iv[3] & 0x1F) << 15) | ((iv[4] & 0x1F) << 20) | ((iv[5] & 0x1F) << 25);

    if (ability == 4)
        ability = (u8)func_020056EC(3);
    switch (ability) {
    case 0:
        slot = 0;
        break;
    case 1:
        slot = 1;
        break;
    case 2:
        slot = 0;
        break;
    case 3:
        slot = 2;
        break;
    default:
        ret = 0;
        goto out;
    }

    if (g->pid != 0) {
        pid = g->pid;
    } else if (g->pidType == 0) {
        pid = func_020186C8(otId, (u16)species, (u8)g->form, gender, slot, 0);
    } else if (g->pidType == 1) {
        pid = func_020186C8(otId, (u16)species, (u8)g->form, gender, slot, 2);
    } else if (g->pidType == 2) {
        pid = func_020186C8(otId, (u16)species, (u8)g->form, gender, slot, 1);
    }

    func_02017588(pp, g->species, level, id, ivs, pid);
    func_02017E40(pp, 6, g->item);
    func_02017FA8(pp);
    for (i = 0; i < 4; i++) {
        mv = moves[i];
        if (mv != 0 && mv < 0x230) {
            if (func_0201808C(pp, mv) == 0xFFFF)
                func_020180F4(pp, mv);
        }
    }
    if (g->pid == 0 && ability == 2)
        func_02018A00(pp, species, g->form);
    func_02017E40(pp, 0x6F, g->form);
    if (g->ball != 0 && g->ball <= 0x19)
        func_02017E40(pp, 0x98, g->ball);
    else
        func_02017E40(pp, 0x98, 4);
    if (g->f3C != 0)
        func_02017E40(pp, 0x99, g->f3C);
    func_02017E40(pp, 0x13, g->contest[0]);
    func_02017E40(pp, 0x14, g->contest[1]);
    func_02017E40(pp, 0x15, g->contest[2]);
    func_02017E40(pp, 0x16, g->contest[3]);
    func_02017E40(pp, 0x17, g->contest[4]);
    func_02017E40(pp, 0x18, g->contest[4]);
    for (k = 0; k < 15; k++) {
        if (g->ribbons & (1 << k))
            func_02017E40(pp, d_02170068[k], 1);
    }
    if (g->f04 == 0)
        func_02017E40(pp, 0x77, d_0209DF08[0]);
    else
        func_02017E40(pp, 0x77, g->f04);
    if (g->lang == 0)
        func_02017E40(pp, 0xC, d_0209DF0C[0]);
    else
        func_02017E40(pp, 0xC, g->lang);
    if (g->nick[0] == 0) {
        func_020307B0(pp);
        ret = 0;
        goto out;
    }
    if (g->nick[0] != func_02045A98())
        func_02017E40(pp, 0x74, (u32)g->nick);
    v = g->nature;
    if (v == 0xFF)
        v = (u8)func_020056EC(25);
    func_02017E40(pp, 0x70, v);
    func_02017E40(pp, 0x95, g->eggLoc);
    func_02017E40(pp, 0x96, g->metLoc);
    if (g->otName[0] == 0) {
        func_020307B0(pp);
        ret = 0;
        goto out;
    }
    if (g->otName[0] == func_02045A98())
        func_02017E40(pp, 0x8E, (u32)func_020084F4(func_02012944(save)));
    else
        func_02017E40(pp, 0x8E, (u32)g->otName);
    if (g->otGender <= 2)
        func_02017E40(pp, 0x9A, g->otGender);
    else
        func_02017E40(pp, 0x9A, func_02008550((const struct Sub0200852CObj *)func_02012944(save)));
    if (g->isEgg) {
        func_02017E40(pp, 0x4C, 1);
        name = func_02045EC0(d_020A7370, 0x28A);
        func_02017E40(pp, 0x73, (u32)name);
        func_02045808(name);
        func_02017E40(pp, 9, 10);
    }
    year = g->date >> 16;
    month = (u8)(g->date >> 8);
    day = g->date;
    loc = g->isEgg ? g->eggLoc : g->metLoc;
    func_0202F2AC(func_020185F0(pp), loc, year - 2000, month, day);
    func_020185C4(pp);
    ret = 0;
    if (func_02017E1C(pp, 3, 0) != 0)
        func_020307B0(pp);
    else
        ret = pp;
out:
    return ret;
}








int func_02158318(int a0)
{
    int t4;
    int t5;
    void *p;

t5 = a0 + 0;
    a0 = func_02012138((const struct Ctx *)a0);
loc_02158320:
t4 = a0 + 0;
a0 = t5 + 0;
    p = func_020120F4((const struct Ctx *)a0);
loc_02158328:
    a0 = func_02012B70(p);
loc_0215832C:
    if (a0 != 1) goto loc_0215833E;
loc_02158330:
a0 = t4 + 0;
    a0 = func_0202648C((void *)a0);
loc_02158336:
    if (a0 == 0) goto loc_0215833E;
loc_0215833A:
a0 = 0;
    return a0;
loc_0215833E:
a0 = 1;
    return a0;}








int func_02158344(int a0)
{
    int t4;
    int t5;

t5 = a0 + 0;
    a0 = func_02026474((void *)a0);
loc_0215834C:
t4 = a0 + 0;
    a0 = func_0200FB24();
loc_02158352:
    if (a0 != 0) goto loc_0215836E;
loc_02158356:
a0 = t5 + 0;
    a0 = func_02026454((void *)a0);
loc_0215835C:
    if (a0 != 2) goto loc_0215836E;
loc_02158360:
a0 = t5 + 0;
    a0 = func_02026460((void *)a0);
loc_02158366:
    if (a0 == 1) goto loc_0215836E;
loc_0215836A:
    if (t4 != 0) goto loc_02158372;
loc_0215836E:
a0 = 0;
    return a0;
loc_02158372:
a0 = t4 + 0;
    return a0;}








int func_02158378(void *p)
{
    u8 *q = (u8 *)func_02158344((int)p);
    if (q == 0) {
        return func_02012B58((const struct BigObj *)func_02026478(p));
    }
    return q[0x911];
}








int func_0215839C(u8 *p, int m, int a2)
{
    Fl_0 *s = (Fl_0 *)(p + 0x93F);
    u8 t = s->f;
    if (m & t) {
        s->f ^= 1;
        return 1;
    }
    return 0;
}








/*
 * Dispatch on the record's key: an equal key goes to the
 * single-argument arm9 read, anything else to the pair form.
 */
int func_021583CC(void *a0, int a1)
{
    if (func_02012B58(a0) == a1)
        return (int)func_020127B8(a0);

    return (int)func_020127AC(a0, a1);
}








int func_021583EC(void *a0, int a1)
{
    if (func_02012B58(a0) == a1)
        return (int)func_02012944(a0);

    return (int)func_02012950(a0, a1);
}








/*
 * Address of the idx-th 0x28-byte record at +0x1AC.
 */
Rec28 *func_0215840C(RecHolder *h, int idx)
{
    return &h->recs[idx];
}








/*
 * Byte out of the arm9 reader, zero-extended.
 */
u8 func_0215841C(void *p)
{
    return (u8)(unsigned)func_02012B80(p);
}








/*
 * Unlabelled leaf (no lr save, so disasm.py prints it inside the extent of
 * func_0215841C); sole blocker of ov018 func_0217D1C0. Followed by another
 * unlabelled leaf at 0x02158434.
 */
u8 func_02158428(u8 *p)
{
    return p[0x90C];
}







/*
 * Unlabelled Thumb leaf (no lr save, prints as .word data in the listing),
 * called from ov020 func_021870C4.
 */
void *func_02158434(char *p)
{
    return p + 0x35C;
}







/*
 * extent: Two zero alignment bytes at 0x02158466 precede 0x02158468.
 * lever: A named u8 id truncates the result in r0 before preparing r1.
 */
int func_0215843C(void *p)
{
    void *q = (void *)func_02026478(p);
    u8 id;
    if (func_02012B70(q) == 0)
        return 21;
    id = (int)func_02012B80(q);
    return func_0200855C((const struct Sub0200852CObj *)func_021583EC(q, id));
}








int func_02158468(int a0)
{
    int a1;
    int t4;
    int t5;

    a0 = func_02026478((void *)a0);
loc_0215846E:
t5 = a0 + 0;
    a0 = func_02012B70((const struct BigObj *)a0);
loc_02158474:
    if (a0 != 0) goto loc_02158480;
loc_02158478:
a0 = t5 + 0;
    a0 = func_02012984((const struct BigObj *)a0);
loc_0215847E:
    return a0;
loc_02158480:
a0 = t5 + 0;
    a0 = func_0215841C((void *)a0);
loc_02158486:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02012B58((const struct BigObj *)a0);
loc_0215848E:
    if (t4 != a0) goto loc_0215849A;
loc_02158492:
a0 = t5 + 0;
    a0 = func_02012984((const struct BigObj *)a0);
loc_02158498:
    return a0;
loc_0215849A:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02012B98((const struct BigObj *)a0, a1);
loc_021584A2:
    return a0;}








int func_021584A4(int unused, int a, int mode)
{
    u8 *q = (u8 *)func_02158344(unused);
    int n;
    int cur;
    if (q == 0)
        return 1;
    cur = ((Fh *)(q + 0x86))->f;
    if (mode == 2) {
        n = cur - 1;
        if (n < 0)
            n = q[0x901];
    } else {
        n = cur + 1;
        if (n >= q[0x901] + 1)
            n = 0;
    }
    if (n == func_02012B58((const struct BigObj *)a))
        return 1;
    return 0;
}









int func_021584F4(int a0, int a1)
{

    if (a0 == 0x15) goto loc_0215850A;
loc_021584F8:
    if (a0 == 0x14) goto loc_0215850A;
loc_021584FC:
a0 = 1;
a0 = a0 << 0x10;
    if ((a0 & a1) == 0) goto loc_02158508;
loc_02158504:
a0 = 0x14;
    return a0;
loc_02158508:
a0 = 0x15;
loc_0215850A:
    return a0;}







int func_0215850C(int a0, int a1)
{
    int t4;
    int t5;
    void *p;
    struct Rec44 *rec;

t5 = a1 + 0;
    a0 = func_02158344(a0);
loc_02158514:
a0 = t5 + 0;
    p = func_02012B38((const struct BigObj *)a0);
loc_0215851A:
    a0 = func_0201444C(p);
loc_0215851E:
    if (a0 == 1) goto loc_02158526;
loc_02158522:
a0 = 0;
    return a0;
loc_02158526:
a0 = t5 + 0;
    a0 = func_0215841C((void *)a0);
loc_0215852C:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02012B58((const struct BigObj *)a0);
loc_02158534:
    if (t4 != a0) goto loc_0215853C;
loc_02158538:
a0 = 0;
    return a0;
loc_0215853C:
a0 = t5 + 0;
a1 = t4 + 0;
    rec = func_02012950((struct Sub24 *)a0, a1);
loc_02158544:
    a0 = func_0200855C((const struct Sub0200852CObj *)rec);
loc_0215854A:
t4 = a0 + 0;
    a0 = func_02008530((const struct Sub0200852CObj *)rec);
loc_02158552:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_021584F4(a0, a1);
loc_0215855A:
    if (a0 == 0x14) goto loc_02158564;
loc_0215855E:
    if (a0 == 0x15) goto loc_02158568;
loc_02158562:
    goto loc_0215856C;
loc_02158564:
a0 = 1;
    return a0;
loc_02158568:
a0 = 2;
    return a0;
loc_0215856C:
a0 = 3;
    return a0;}






/*
 * lever: The ternary loop condition preserves the branch to the bottom test.
 */
int func_02158570(u16 value)
{
    unsigned int i;
    for (i = 0; (i < 61) ? 1 : 0; i++) {
        if (value == d_021700AC[i])
            return 1;
    }
    return 0;
}






int func_02158590(void *p)
{
    void *q = (void *)func_0201296C(p);
    unsigned int i;
    for (i = 0; i < 2; i++) {
        if (func_020142E8(q, d_021700A8[i]) == 0)
            return 0;
    }
    return 1;
}







int func_021585BC(int a0)
{
    int a1;

a1 = 0x25;
a1 = a1 << 6;
a1 = *(int *)((char *)a0 + a1);
a1 = (unsigned)a1 >> 0x1f;
    if (a1 == 0) goto loc_021585DA;
loc_021585C8:
a1 = 0x6b;
a1 = a1 << 2;
a0 = a0 + a1;
    a0 = func_02175B14(a0, a1);
loc_021585D2:
    if (a0 != 0) goto loc_021585DA;
loc_021585D6:
a0 = 1;
    return a0;
loc_021585DA:
a0 = 0;
    return a0;}






/*
 * Callee 02158344 consumes incoming r0; the flag extract reads bit 2.
 */
int func_021585E0(int p)
{
    u8 *q = (u8 *)func_02158344((int)((void *)p));
    if (q == 0)
        return 0;
    if (((Flag_021585E0 *)(q + 0x93F))->flag == 0) {
        if (func_02158630(p) == 3)
            return 2;
        return 1;
    }
    return 3;
}






/*
 * The callee reads its incoming r0; legacy void prototypes omit it.
 */
void func_02158614(void *p)
{
    u8 *q = (u8 *)func_02158344((int)p);
    if (q != 0)
        q[0x93F] |= 4;
}







int func_02158630(int a)
{
    int q = func_02158344(a);
    if (q == 0)
        return 0;
    if (func_02175B14(q + 0x1AC) == 1) {
        if (func_02176258(q) == 1)
            return 2;
        if (func_02158590((void *)func_02026478((void *)a)) == 0)
            return 1;
        return 3;
    }
    return 1;
}







int func_02158678(void *p)
{
    int n = 0;
    u8 i;
    u8 *q = (u8 *)func_02158344((int)p);
    if (q == 0)
        return n;
    if (func_02175B14(q + 0x1AC) == 0)
        return n;
    for (i = 0; i < 3; i++) {
        if (((Fl_1 *)(q + 0xA6 + i * 0x1C))->f == 1)
            n++;
    }
    if (n == 0)
        n = 1;
    return n;
}







int func_021586C8(int a, int b)
{
    char *q = (char *)func_02158344(a);
    int r = func_02026478((void *)a);
    if (q == 0 || func_02175B14(q + 0x1AC) == 0)
        return 0;
    func_02008500(func_02012950((struct Sub24 *)r, func_02176230(q, q + 0x1AC)), (void *)b);
    return 1;
}







/*
 * Three guards (state == 2, a non-null lookup, bit 6 of a far byte) then a
 * predicate whose one result is inverted.
 */
int func_0215870C(void *p, int b)
{
    u8 *q;

    if (func_02026454((void *)((int)p)) != 2)
        return 0;
    q = (u8 *)func_02026474((void *)((int)p));
    if (q == 0)
        return 0;
    if (((FlagsF8 *)(q + 0x8f8))->f == 0)
        return 0;
    if (func_0203CDBC() == 1)
        return 0;
    return 1;
}






void func_0215874C(void *p)
{
    u8 *q = (u8 *)func_02158344((int)p);
    if (q != 0)
        ((Flag_0215874C *)(q + 0x904))->flag = 0;
}







struct Desc *func_02158768(int a0, u16 a1, int a2, int a3)
{
    return func_02158920(a0, a3, a1, a2, 0);
}






int func_02158780(void *p, u16 b, int c, int d, u16 e)
{
    struct Desc *h = func_02158920((int)func_020124E4(p), e, b, c, d);
    int *q = func_020124E8((void *)h);
    func_02012374(p, (struct Evt **)((void **)h));
    return *q;
}







int func_021587B0(int a0, u16 a1, int a2, int a3)
{
    void *p;
    void *q;
    struct Desc *v0;
    p = func_020124E4((struct Obj *)a0);
    v0 = func_02158920((int)p, a3, a1, a2, 0);
    q = func_020124E8((struct Obj *)v0);
    a0 = func_0201235C(a0, v0);
    return ((struct Obj17623 *)q)->f0;
}






/*
 * Extent ends in two alignment padding bytes.
 */
int func_021587E0(int a, int b) {
    void *p = (void *)func_021589DC(a);
    if (!p) return 0;
    if (func_02158894((int)p, b)) return 1;
    return 0;
}






/*
 * Allocates 0x18 bytes and initializes the leading heap halfword.
 */
void *func_02158804(u32 heap) {
    u16 *p = func_02030734(heap, 0x18, 1, d_02172888, 0xef);
    *p = heap;
    return p;
}






/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_020307B0, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02158824.c \
 *       --func func_02158824 --addr 0x02158824 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_02158824(void *a0)
{

    func_020307B0(a0);
}






int func_0215882C(int a0)
{
    int t4;
    int t5;
    int t6;
    int t7;

t5 = a0 + 0;
t4 = 0;
loc_02158832:
a0 = t4 << 2;
t7 = t5 + a0;
t6 = ((struct Obj12028 *)t7)->f4;
    if (t6 == 0) goto loc_02158856;
loc_0215883C:
a0 = t6 + 0;
    a0 = func_02011298((struct ScriptVm *)a0);
loc_02158842:
    if (a0 != 0) goto loc_02158856;
loc_02158846:
a0 = 0;
((struct Obj12028 *)t7)->f4 = a0;
a0 = ((struct Obj00105 *)t5)->f2;
a0 = a0 - 1;
((struct Obj00105 *)t5)->f2 = a0;
a0 = t6 + 0;
    a0 = func_02158CB4(a0);
loc_02158856:
t4 = t4 + 1;
    if (t4 < 3) goto loc_02158832;
loc_0215885C:
a0 = ((struct Obj00105 *)t5)->f2;
    if (a0 == 0) goto loc_02158866;
loc_02158862:
a0 = 1;
    return a0;
loc_02158866:
a0 = 0;
    return a0;}








int func_0215886C(int a0, int a1)
{
    int a2;
    int a3;
    int t4;

t4 = 0;
loc_02158870:
a2 = t4 << 2;
a3 = a0 + a2;
a2 = ((struct Obj12029 *)a3)->f4;
    if (a2 != 0) goto loc_02158888;
loc_0215887A:
((struct Obj12029 *)a3)->f4 = a1;
a1 = ((struct Obj09153 *)a0)->f2;
a1 = a1 + 1;
((struct Obj09153 *)a0)->f2 = a1;
a0 = t4 + 0;
    return a0;
loc_02158888:
t4 = t4 + 1;
    if (t4 < 3) goto loc_02158870;
loc_0215888E:
a0 = 3;
    return a0;}








int func_02158894(int a0, int a1)
{

a1 = a1 << 2;
a0 = a0 + a1;
a0 = ((struct Obj17624 *)a0)->f4;
    return a0;}





/*
 * extent: 8-byte tail stub; existing labelled func_021588A4 follows.
 */
void func_0215889C(void *p, u32 *out)
{
    func_0201235C(p, out);
}





/*
 * lever: Callback-field assignment before argument-field assignment hoists
 *        the callback pool load before both stores, preserving argument first.
 */
void func_021588A4(void *p, int a)
{
    void (*callback)(void *, u32 *) = func_0215889C;
    *(void (**)(void *, u32 *))((u32)p + 0x10) = callback;
    ((struct Obj12271 *)((u32)p))->f14 = a;
}








int func_021588B0(struct Obj00105 *obj, int arg)
{
    return ((int (*)(int, int))obj->f10)(arg, (int)obj->f14);
}








int func_021588C0(int a0)
{

a0 = ((struct Obj17625 *)a0)->f10;
    if (a0 == 0) goto loc_021588CA;
loc_021588C6:
a0 = 1;
    return a0;
loc_021588CA:
a0 = 0;
    return a0;}






u16 func_021588D0(int a0)
{
    return func_02012AC8((const struct Rec44 *)func_020120F8((const struct Ctx *)a0));
}






int func_021588DC(int arg, int unused, struct Obj12030 *cell)
{
    int v;
    int h;

    h = cell->f4;
    v = cell->f0;
    if (func_0215882C(h) == 1) {
        return 0;
    }
    func_02158F18(v);
    if (func_021588C0(h) == 1) {
        func_021588B0((struct Obj00105 *)h, arg);
        func_02158824((void *)h);
        return 0;
    }
    func_02158824((void *)h);
    return 1;
}






struct Desc *func_02158920(int a, int b, u16 c, int d, int e)
{
    struct Desc *h = func_020122C0((void *)a, 0, (void *)func_021588DC, 8);
    void **w = func_020124E8((struct Obj *)h);
    w[1] = func_02158804(4);
    w[0] = func_02158E7C(4, a, (int)h, c, e, 0);
    func_02158F94(w[0], (void *)d);
    func_021589A0((int)w[0], func_021588D0(a), c);
    return h;
}






/*
 * Queue a task on the script's event list.
 */
void func_0215897C(void *vm, void *task)
{
    func_02012374(func_02158F50(vm), task);
}





void func_0215898C(int a, int b) {
    void *p = (void *)func_021589DC(a);
    if (p != 0) func_021588A4(p, b);
}





/*
 * Extent ends in two alignment padding bytes.
 */
int func_021589A0(int a, u16 b, u16 c) {
    u16 *p = (u16 *)func_021589DC(a);
    if (p) return func_0215886C((int)p, (int)func_02158BFC(*p, a, b, c, 0));
    return 3;
}






int func_021589D0(int a0)
{
    void *p;

    p = func_020124E8((struct Obj *)a0);
loc_021589D6:
a0 = ((struct Obj17626 *)p)->f0;
    return a0;}






int func_021589DC(int a0)
{
    void *p;

    p = func_02158F50((void *)a0);
loc_021589E2:
    if (p != 0) goto loc_021589EA;
loc_021589E6:
a0 = 0;
    return a0;
loc_021589EA:
    p = func_020124E8((struct Obj *)p);
loc_021589EE:
a0 = *(int *)&((struct Obj01023 *)p)->f4;
    return a0;}






int func_021589F4(int a0)
{
    int a1;
    int a2;
    int t4;

a1 = 0;
a2 = 0x63;
t4 = a0 + 0;
    a0 = func_02014368(a0, a1, a2);
loc_02158A00:
a1 = 1;
a1 = a1 << 0xe;
a2 = a1 + 0;
a0 = t4 + 0;
a2 = a2 + 0x1f;
    a0 = func_020143D8(a0, a1, a2);
loc_02158A0E:
    return a0;}





void func_02158A10(int a, int b) { func_02158A34(a, 0, 9600, 2); }





void func_02158A20(int a, int v) { func_02158A34(a, 0, 9601, 2); }




/*
 * Narrow parameter c matches func_02158E7C's stored halfword and restores
 * spill/call scheduling. The remaining two bytes are zero alignment padding.
 */
void func_02158A34(int a, int b, u16 c, int d)
{
    int t = 0;
    int r;
    if (b == 0) {
        t = (int)func_02158E7C(4, a, t, c, t, d);
        b = t;
    }
    r = (int)func_02158BFC(4, b, func_021588D0(a), c, d);
    while (func_02011298((struct ScriptVm *)r) == 1)
        ;
    func_02158CB4(r);
    if (t != 0)
        func_02158F18(t);
}







int func_02158A90(void *a, int unused, int key, int d) {
    u16 result = func_02158B3C((const u8 *)func_02162450((void *)func_02012844(func_020120F4(a))), key);
    if (result == 0xffff) return 0;
    func_02158A34((int)a, 0, result, d);
    return 1;
}









void func_02158AC8(int a, int b)
{
    func_02158A90((void *)a, b, 4, 1);
}









void func_02158AD4(int a, int b)
{
    func_02158A90((void *)a, b, 3, 1);
}









/*
 * Two arm9 frame calls, an overlay reset, then the four-argument submit.
 */
void func_02158AE0(void *a0, void *a1)
{
    func_021589F4(func_0201296C(func_020120F4(a0)));
    func_02158A90(a0, (int)a1, 2, 2);
}








void *func_02158B00(void *a, u32 b) {
    void *s = func_020120F4(a);
    u16 msg = func_02158B6C(s, (const u8 *)func_02162450((void *)func_02012844(s)), 1);
    if (msg == 0xffff) return 0;
    return func_02158768((int)a, msg, 0, b);
}







u16 func_02158B3C(const u8 *p, int key) {
    for (;;) {
        u16 v = p[0] + (p[1] << 8);
        if (v == 0) return 0xffff;
        if (key == v) return (u16)(p[2] + (p[3] << 8));
        p += 6;
    }
}







inline static u16 RD16(const u8 *p)
{
  return (u16) (p[0] + (p[1] << 8));
}








/*
 * levers: wave76 reused cursor p across both parsing phases; p += 6 at the
 * matched key, then p += key before save accessor. Local base/q produced
 * DIFF40; cursor reuse alone31, resetting it through base129; in-place
 * advances give EXACT. Permuter300 previously consumed, not repeated.
 */
u16 func_02158B6C(const void *a, const u8 *list, u32 key)
{
  const u8 *p = list;
  u32 h;
  const u8 *tmp;
  int pad;
  u16 tmp1;
  u32 tmp2;
  for (;; p += 6)
  {
    u32 id = RD16(p);
    if (id == 0)
      return 0xFFFF;
    if (key == id)
    {
      key = ((p[2] + (p[3] << 8)) + (p[4] << 16)) + (p[5] << 24);
      p += 6;
      break;
    }
  }

  if (key == 0)
    return 0xFFFF;
  p += key;
  tmp2 = func_0201296C(a);
  h = tmp2;
  for (;; p += 6)
  {
    u16 val;
    u16 id = RD16(p);
    if (id == 0)
      return 0xFFFF;
    if (id == 0)
      return 0xFFFF;
    tmp1 = RD16(p + 2);
    val = tmp1;
    if (val == (*((u16 *)func_020143CC(h, id))))
      return RD16(p + 4);
  }

}








int *func_02158BFC(u16 a0, int a1, u16 a2, u16 a3, int a4)
{
    struct V v;
    struct W w;
    u16 s[4];
    int r6, t, n;
    int *o;

    r6 = func_02158DB0(a4);
    v.x = a2;
    v.y = a3;
    v.a = a4;
    v.b = r6;
    v.c = a1;
    t = func_0215A55C(&v, a0);
    w.w = 0x100;
    w.h = 0x40;
    w.p = (int)&d_0217062C;
    w.q = d_021705D8;
    o = (int *)func_0201121C(a0, (const struct ScriptVmParams *)(&w));
    func_0201126C((struct ScriptVm *)o, (void *)t);
    n = func_02158CD0(a2, a3, &s[2], &s[1], &s[0]);
    o[0x2C / 4] = (int)func_02158D78(s[2], a0);
    if (r6 == 0) {
        if (s[0] != -1)
            func_0215A760((u8 *)t, s[1], s[0]);
    }
    func_0201127C((struct ScriptVm *)o, (u8 *)o[0x2C / 4]);
    o[0x14 / 4] += n << 2;
    o[0x14 / 4] += func_0201134C((struct Cursor *)o);
    func_02158E38(o);
    return o;
}








int func_02158CB4(int a0)
{
    int t4;
    void *p;

t4 = a0 + 0;
    p = func_02011324((struct ScriptVm *)a0);
loc_02158CBC:
    a0 = func_0215A5A4((int)p);
loc_02158CC0:
a0 = ((struct Obj17627 *)t4)->f2C;
    a0 = func_020307B0(a0);
loc_02158CC6:
a0 = t4 + 0;
    a0 = func_02011264(a0);
loc_02158CCC:
    return a0;}








/*
 * Looks up value v in a table of 46 range records (lo, hi, a, b, c).
 * Writes a, b, c to the three outputs and returns v - lo. Past the table
 * it falls back to two lookups by k, or to fixed outputs when v is 0.
 * 2026-10-05 (wave P15): the table is const and the three outputs are
 * stored directly from the record. The old DIFF 14 B draft copied b and c
 * into u16 locals; that form is not needed.
 */
u16 func_02158CD0(unsigned k, unsigned v, u16 *o1, u16 *o2, u16 *o3)
{
    unsigned i;
    const struct E *t = d_021701A8;
    const struct E *e;
    for (i = 0; i < 46; i++) {
        if (v < t[i].lo)
            continue;
        if (v > t[i].hi)
            func_02034714(d_02172898, (int)0, d_02172898);
        e = &t[i];
        *o1 = e->a;
        *o2 = e->b;
        *o3 = e->c;
        return v - t[i].lo;
    }
    if (v >= 1) {
        u16 x = (u16)func_02013B5C((u16)k);
        u16 y = func_02013B68(k);
        *o1 = x;
        *o2 = 3;
        *o3 = y;
        return v - 1;
    }
    *o1 = 0x356;
    *o2 = 3;
    *o3 = 0x9E;
    return 0;
}







/*
 * The null pointer local is the branch condition, not parameter b.
 * Lever: a-null-pointer-local-tested-reuses-the-movs-flags.md.
 * Extent follower 0x02158D90 already has its own matched shard.
 */
void *func_02158D78(int a, int b) {
    void *result = 0;
    if (result == 0) result = (void *)func_0204A1BC(0x39, a, (int)result, b);
    return result;
}








/*
 * Unlabelled leaf (a .word run in the ov010 listing): 0 for 2000, 1 below
 * 0x291C, else 0.  Callee of ov021 func_0218A0E4, func_0218A278 and
 * func_02189BD0.
 * Addresses are Black-image addresses.
 */
int func_02158D90(u16 v)
{
    if (v == 2000)
        return 0;
    if (v < 0x291C)
        return 1;
    return 0;
}










int func_02158DB0(int a0)
{

    if (a0 == 0) goto loc_02158DB8;
loc_02158DB4:
a0 = 1;
    return a0;
loc_02158DB8:
a0 = 0;
    return a0;}








int func_02158DBC(void)
{
    int a0;

    a0 = func_0203CD98();
loc_02158DC2:
    if (a0 == 0) goto loc_02158DE0;
loc_02158DC6:
    a0 = func_0203CF04();
loc_02158DCA:
a0 = 0;
    a0 = func_0203CEAC(a0);
loc_02158DD0:
    a0 = func_0203D0D0();
loc_02158DD4:
    a0 = func_0203CF5C();
loc_02158DD8:
    a0 = func_0203CDBC(a0);
loc_02158DDC:
    if (a0 == 0) goto loc_02158DD4;
loc_02158DE0:
    a0 = func_020053EC();
loc_02158DE4:
    goto loc_02158DE0;}







int func_02158DE8(int a, int b, int c, int idx)
{
    int m, r;
    func_0201210C((void *)c);
    func_0215A5D4((void *)b);
    m = func_0215A5D8((void *)b);
    r = 0;
    switch (m) {
    case 0: r = d_02170374[idx].b0; break;
    case 1: r = d_02170374[idx].b1; break;
    case 2: r = d_02170374[idx].b2; break;
    }
    if (r == 0)
        func_02158DBC();
    return r;
}






/*
 * ARM9 interface evidence: 02011324 reads +0x20; 02011328 stores r1/r2 at +0x24/+0x28.
 */
void func_02158E38(void *a) {
    void *b = func_0215A5DC(func_02011324(a));
    func_02011328(a, (int (*)(int,  void *, void *, int))func_02158DE8, b);
}







int func_02158E54(int a0, int a1)
{
    int a2;
    void *t4;
    int t5;

t5 = a0 + 0;
a0 = a1 + 0;
    t4 = func_0201210C((const struct Ctx *)a0);
loc_02158E5E:
a0 = 0;
a1 = t5 + 0;
a2 = 8;
    a0 = func_02082A7C(a0, a1, a2);
loc_02158E6A:
((struct Obj00020 *)t5)->f4 = t4;
    if (t4 == 0) goto loc_02158E78;
loc_02158E70:
a0 = (int)t4 + 0; /* int-typed on purpose: pointer local changes codegen */
    a0 = func_02188C54(a0);
loc_02158E76:
((struct Obj00020 *)((char *)t5))->f0 = a0;
loc_02158E78:
    return a0;}







int *func_02158E7C(u16 a, int b, int c, int d, int e, int f)
{
    int *p = func_02030734(a, 0x14C, 1, d_0217289C, 0xAF);
    p[0] = 0x3643F;
    *(u16 *)(p + 3) = a;
    p[4] = b;
    p[5] = c;
    ((struct Obj00105 *)p)->f4 = d;
    p[2] = 0;
    p[8] = e;
    p[10] = f;
    p[9] = func_02158DB0(f);
    if (p[9] == 0) {
        p[11] = (int)func_0201EC74(0x1C, 0x40, a);
        p[12] = (int)func_020457B0(0x500, a);
        p[13] = (int)func_020457B0(0x500, a);
    } else {
        p[11] = 0;
        p[12] = 0;
        p[13] = 0;
    }
    p[0x52] = (int)func_0215A514((int)p, a);
    func_02158E54((int)(p + 6), b);
    if (p[9] == 0)
        func_02159130();
    return p;
}







int func_02158F18(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = 0;
*(int *)((char *)t4) = a0;
a0 = ((struct Obj00105 *)t4)->f2C;
    if (a0 == 0) goto loc_02158F2A;
loc_02158F26:
    a0 = func_0201ED04(a0);
loc_02158F2A:
a0 = ((struct Obj00105 *)t4)->f30;
    if (a0 == 0) goto loc_02158F34;
loc_02158F30:
    a0 = func_02045808(a0);
loc_02158F34:
a0 = ((struct Obj00105 *)t4)->f34;
    if (a0 == 0) goto loc_02158F3E;
loc_02158F3A:
    a0 = func_02045808(a0);
loc_02158F3E:
a0 = 0x52;
a0 = a0 << 2;
a0 = *(int *)((char *)t4 + a0);
    a0 = func_0215A554(a0);
loc_02158F48:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_02158F4E:
    return a0;}







/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02158F50.c \
 *       --func func_02158F50 --addr 0x02158F50 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_02158F50(void *p) { return ((struct Obj17628 *)p)->f14; }







/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02158F54.c \
 *       --func func_02158F54 --addr 0x02158F54 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_02158F54(void *p) { return ((struct Obj17629 *)p)->f10; }







int func_02158F58(int a0)
{
    int a1;
    int t4;

t4 = a0 + 0;
a1 = ((struct Obj17630 *)t4)->f10;
a0 = a0 + 0x18;
    a0 = func_02158E54(a0, a1);
loc_02158F64:
t4 = t4 + 0x18;
a0 = t4 + 0;
    return a0;}







/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Shifted-index word-field getter: the field table sits at a byte offset built from a small constant shifted left, so the leaf folds it to one immediate.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02158F6C.c \
 *       --func func_02158F6C --addr 0x02158F6C --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_02158F6C(void *p) { return ((struct Obj17631 *)p)->f148; }







/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02158F74.c \
 *       --func func_02158F74 --addr 0x02158F74 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_02158F74(void *p) { return ((struct Obj00020 *)p)->f2C; }








/*
 * Reads the word field at +0x30.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02158F78(u8 *p)
{
    return ((struct Obj17632 *)p)->f30;
}








/*
 * Reads the word field at +0x34.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02158F7C(u8 *p)
{
    return ((struct Obj17633 *)p)->f34;
}








/*
 * Stores the word field at +0x38.
 *
 * Addresses are Black-image addresses.
 */
void func_02158F80(u8 *p, u32 v)
{
    ((struct Obj17634 *)p)->f38 = v;
}







u32 func_02158F84(u8 *p)
{
    return ((struct Obj18753 *)p)->f38;
}







/*
 * Unlabelled leaf, blocker of ov021 func_021AF1E8..func_021AF26C: address of the field at +0x40.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u8 *func_02158F88(void *p)
{
    return (u8 *)p + 0x40;
}








/*
 * Reads the halfword field at +0x4.
 *
 * Addresses are Black-image addresses.
 */
u16 func_02158F8C(u8 *p)
{
    return ((struct Obj17635 *)p)->f4;
}








/*
 * Reads the word field at +0x8.
 *
 * Addresses are Black-image addresses.
 */
void *func_02158F90(void *p)
{
    return ((struct Obj17636 *)p)->f8;
}





void func_02158F94(p, q, a2)
void *p;
void *q;
int a2;
{
    *(void **)((char *)p + 8) = q;
    if (q != 0) {
        u16 *r = (u16 *)func_02158FD0((int)p, 0x8011, a2);
        *r = func_0216D588(q);
    }
}






/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Returns the address of an interior member (field address), pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02158FB4.c \
 *       --func func_02158FB4 --addr 0x02158FB4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_02158FB4(void *p) { return (char *)p + 60; }






/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02158FB8.c \
 *       --func func_02158FB8 --addr 0x02158FB8 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_02158FB8(void *p) { return ((struct Obj17637 *)p)->f3C; }






void func_02158FBC(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj00005 *)t4)->f3C;
    if (a0 == 0) goto loc_02158FCE;
loc_02158FC6:
    a0 = func_020307B0(a0);
loc_02158FCA:
a0 = 0;
((struct Obj00005 *)t4)->f3C = a0;
loc_02158FCE:
    return;}






int func_02158FD0(a0, a1, a2)
int a0;
u32 a1;
int a2;
{

a2 = 2;
a2 = a2 << 0xe;
a1 = a1 - a2;
a0 = a0 + 0x7c;
a1 = a1 << 1;
a0 = a0 + a1;
    return a0;}





u16 *func_02158FE0(void *a, void *b, unsigned int id)
{
    void *p = (void *)func_0201296C(b);
    if (id < 0x4000) return 0;
    if (id < 0x8000) return (u16 *)func_020143CC((unsigned int)p, id);
    if (id < 0xc000) return (u16 *)func_02158FD0(a, id);
    return 0;
}






/*
 * extent: two-byte zero alignment padding follows the 18-byte function.
 * Return stays full-width: the fallback id has no halfword truncation.
 */
unsigned int func_0215901C(void *a, void *b, unsigned int id)
{
    u16 *p = func_02158FE0(a, b, id);
    if (p) id = *p;
    return id;
}







int func_02159030(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;
    void *p;
    u16 *q;

t5 = a0 + 0;
a0 = *(int *)&((struct Obj00020 *)t5)->f10;
t6 = a1 + 0;
t4 = a2 + 0;
    p = func_020120F4((const struct Ctx *)a0);
loc_0215903E:
    q = func_02158FE0((void *)t5, p, t6);
loc_02159048:
    if (q != 0) goto loc_02159050;
loc_0215904C:
a0 = 0;
    return a0;
loc_02159050:
*q = t4;
a0 = 1;
    return a0;}






int func_02159058(int a, int b, int c, int d, u16 e)
{
    func_02159030(a, 0x8000, b);
    func_02159030(a, 0x8001, c);
    func_02159030(a, 0x8002, d);
    return func_02159030(a, 0x8003, e);
}





void *func_0215909C(u8 *a)
{
    void *p = func_02030734(((struct Obj18755 *)a)->fC, 0x7e, 1, d_0217289C, 0x21b);
    func_02082A60((void *)func_02158FD0(a, 0x8020), p, 0x7e);
    return p;
}






void func_021590D4(void *a, void *b, int a2)
{
    void *p = (void *)func_02158FD0((int)a, 0x8020, a2);
    func_02082A60(b, p, 0x7e);
    func_020307B0(b);
}







/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Shifted-index word-field setter, same shape as its getter partner.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021590F4.c \
 *       --func func_021590F4 --addr 0x021590F4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_021590F4(void *p, u32 v) { ((struct Obj17639 *)p)->f13C = v; }







/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Shifted-index word-field getter: the field table sits at a byte offset built from a small constant shifted left, so the leaf folds it to one immediate.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021590FC.c \
 *       --func func_021590FC --addr 0x021590FC --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_021590FC(void *p) { return ((struct Obj17640 *)p)->f13C; }







/*
 * Store of a word at +0x140.
 * Addresses are Black-image addresses.
 */
void func_02159104(u8 *p, u32 v)
{
    ((struct Obj18756 *)p)->f140 = v;
}







/*
 * Unlabelled leaf, blocker of ov021 func_021D1A54/021D1A74/021D1AB0: reads the word at +0x140.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u32 func_0215910C(void *p)
{
    return ((struct Obj18757 *)p)->f140;
}







/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Shifted-index word-field setter, same shape as its getter partner.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02159114.c \
 *       --func func_02159114 --addr 0x02159114 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_02159114(void *p, u32 v) { ((struct Obj17641 *)p)->f144 = v;  return p; }







/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Shifted-index word-field getter: the field table sits at a byte offset built from a small constant shifted left, so the leaf folds it to one immediate.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0215911C.c \
 *       --func func_0215911C --addr 0x0215911C --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0215911C(void *p) { return ((struct Obj17642 *)p)->f144; }





char *func_02159124(char *p, int i)
{
    return p + 0x44 + i * 0x1c;
}





void func_02159130(void)
{
    func_02082A7C(0, &d_02172BA0, 4);
}





/*
 * Input evidence: ov010 callers 0215F278/02164946 pass 11/7;
 * ov021 flag setters pass fixed IDs 0..13 (e.g. 021B5316 passes 0,
 * 021AEE1E passes 13). No traced setter call supplies a negative ID.
 * These primary paths make 1 << n defined; no new bound is assumed.
 */
void func_02159144(int n)
{
    if (n < 14 && !func_02159198(n)) d_02172BA0 |= 1 << n;
}





/*
 * lever: enum-typed BIT keeps the shifted mask opaque; plain int folds
 * the complement to mvns and shortens the body by four bytes.
 * Input evidence: ov010 sites 0215F298/021649D6/02164A14 pass 11/7/7;
 * ov021 flag clearers pass fixed IDs 0..13 (021B52D8 passes 0,
 * 021AF03A passes 13; 021B10C8 forwards its saved literal 3).
 * On these traced paths n is nonnegative and below 14 before the shift.
 */
void func_02159168(int n)
{
    if (n < 14 && func_02159198(n)) {
        Mask bit = BIT;
        d_02172BA0 &= (bit << n) ^ -1;
    }
}






/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_02159198, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02159190.c \
 *       --func func_02159190 --addr 0x02159190 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_02159190(int a0)
{

    return func_02159198(a0);
}





/*
 * Input evidence: direct callers are 0215914C, 02159170, 021591D0.
 * Set/clear callers use fixed nonnegative IDs 0..13; the 02159190 tail
 * forwarder has constant-ID callers in ov010/ov021/ov082 (021F5756: 3).
 * The task caller's index starts at zero (0215922E), advances by one
 * (021591EA), and sees a NULL callback at table index 14 (02170628)
 * before the test call. Its fourteen callbacks leave task+0x10 alone;
 * state updates use only task+0x0c. Thus shifted IDs are 0..13 on the
 * traced primary paths; no invented guard or domain was added.
 */
int func_02159198(int n)
{
    if (n >= 14) return 0;
    if ((d_02172BA0 >> n) & 1) return 1;
    return 0;
}






/*
 * volatile: 0x021591F2 re-reads idx after the store at 0x021591EC.
 */
int func_021591B4(int a, int b, struct S *p)
{
    int *pc = &p->c;
    int *pi = &p->idx;
    do {
        Fn fn = d_021705F0[p->idx];
        if (fn == 0)
            return 1;
        if (func_02159198(p->idx)) {
            if (fn((int *)p, pc)) {
                (*pi)++;
                p->c = 0;
            } else {
                return 0;
            }
        } else {
            (*pi)++;
            p->c = 0;
        }
    } while (*(volatile int *)&p->idx < p->n);
    return 1;
}





void *func_02159204(void *vm)
{
    void *owner = func_0215A5F4(vm);
    void *system = func_0215A5DC(vm);
    void *task = func_020122C0(system, 0, (void *)func_021591B4, sizeof(TaskWork));
    TaskWork *p = func_020124E8(task);
    p->system = system;
    p->vm = vm;
    p->owner = owner;
    p->idx = 0;
    p->c = 0;
    p->n = 15;
    return task;
}






/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Constant leaf: `movs r0, #N; bx lr`.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02159240.c \
 *       --func func_02159240 --addr 0x02159240 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_02159240(void) { return 0; }






/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Constant leaf: `movs r0, #N; bx lr`.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02159244.c \
 *       --func func_02159244 --addr 0x02159244 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_02159244(void) { return 0; }






int func_02159248(struct ScriptVm *a0)
{

    a0 = (struct ScriptVm *)func_02011290(a0);
loc_0215924E:
a0 = (struct ScriptVm *)1;
    return (int)a0;}






/*
 * Recursive MATCH unblocker: tail-call thunk at the pool word 0x0215A691
 * (func_0215A690). Matched so the ABS32 site in func_02159260 attests as
 * `matched`.
 */
void func_02159254(char *a0, char *a1)
{
    func_0215A690(a1);
    (void)a0;
}






/*
 * Unblocked by matching func_02159254 (ov010, EXACT; itself unblocked by
 * func_0215A690). The ABS32 pool word +0x20 now attests as `matched`.
 *
 * Registers the second argument under the key the first argument yields,
 * and installs the in-overlay handler the pool names.
 */
int func_02159260(void *a0, void *a1)
{
    func_0215A684(a1, func_02011330(a0));
    func_020113D0(a0, (int)func_02159254);

    return 1;
}






int func_02159284(int a0, int a1, int a2)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0201134C((struct Cursor *)a0);
loc_0215928C:
a2 = a0 + 0;
a1 = *(int *)&((struct Obj00005 *)t4)->f14;
a0 = t4 + 0;
a1 = a1 + a2;
    a0 = func_020113B4(a0, a1, a2);
loc_02159298:
a0 = 0;
    return a0;}






int func_0215929C(struct Ring *a0)
{

    a0 = (struct Ring *)func_020113C4(a0);
loc_021592A2:
a0 = 0;
    return (int)a0;}






int func_021592A8(int a0, int a1)
{
    int t4;
    int t5;
    void *v0;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_021592B4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_021592BC:
a0 = 0;
    return a0;}






int func_021592C0(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_02011398((struct Ring *)a0);
loc_021592CA:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_021592D2:
a0 = 0;
    return a0;}



static inline u8 rd8_021592D8(Ctx_021592D8 *c)
{
    u8 v = *c->pc;
    c->pc++;
    return v;
}



int func_021592D8(Ctx_021592D8 *c)
{
    u8 a = rd8_021592D8(c);
    u8 b = rd8_021592D8(c);
    c->vars[a] = b;
    return 0;
}
