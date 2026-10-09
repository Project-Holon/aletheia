/*
 * file:     psel.c
 * unit:     yes
 * function: func_021B95A0, func_021B95B0, func_021B9600, func_021B9608, func_021B9674, func_021B96E0, func_021B9740, func_021B97F8, func_021B9830, func_021B9848, func_021B9854, func_021B98F4, func_021B9914, func_021B99A0, func_021B9A6C, func_021B9A8C, func_021B9AE4, func_021B9B4C, func_021B9B80, func_021B9C00, func_021B9C58, func_021B9C90, func_021B9D4C, func_021B9D9C, func_021BA050, func_021BA0AC, func_021BA2B4, func_021BA81C, func_021BA878, func_021BA8D0, func_021BA984, func_021BAA30, func_021BAA5C, func_021BAA84, func_021BAAB8, func_021BAB74, func_021BAB78, func_021BABFC, func_021BAC0C, func_021BAC6C, func_021BAC70, func_021BAD68, func_021BAD80, func_021BADFC, func_021BAE00, func_021BAEE0, func_021BAF30, func_021BAF48, func_021BAFC4, func_021BB0B0, func_021BB134, func_021BB18C, func_021BB274, func_021BB2A4, func_021BB35C, func_021BB38C, func_021BB3AC, func_021BB3BC, func_021BB424
 * address:  0x021B95A0
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020115EC  0x020115EC  thumb
 *   func_02030734 0x02030734 arm
 *   func_0207ADC4 0x0207ADC4 arm
 *   site 0x021BCB00 data a4
 *   func_020307B0 0x020307B0 arm
 *   func_0204E720 0x0204E720 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204E6E0 0x0204E6E0 arm
 *   func_0204E6F4 0x0204E6F4 arm
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   callbacks 0x021BC84C data a4
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021BC4F4 0x021BC4F4 thumb ov223
 *   func_021BC508 0x021BC508 thumb ov223
 *   func_021BC514 0x021BC514 thumb ov223
 *   func_02040588 0x02040588 arm
 *   func_02048A18 0x02048A18 arm
 *   func_02047A60 0x02047A60 arm
 *   func_02047CFC  0x02047CFC  arm
 *   func_02047E54 0x02047E54 arm
 *   func_02047E88 0x02047E88 arm
 *   func_020489F4 0x020489F4 arm
 *   func_0204779C 0x0204779C arm
 *   func_020477A4 0x020477A4 arm
 *   func_02011510 0x02011510 thumb
 *   func_021BC52C 0x021BC52C thumb ov223
 *   func_02011B8C 0x02011B8C thumb
 *   d_021BC7AC 0x021BC7AC data a4
 *   func_020480E4 0x020480E4 arm
 *   func_02011558 0x02011558 thumb
 *   func_02047910 0x02047910 arm
 *   func_02011590 0x02011590 thumb
 *   setup 0x021BC7BC data a4
 *   positions 0x021BC7CC data a4
 *   table 0x021BC78C data a4
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   d_021BC790 0x021BC790 data a2
 *   d_021BC792 0x021BC792 data a2
 *   func_020477D4 0x020477D4 arm
 *   func_0204784C 0x0204784C arm
 *   func_0204B908 0x0204B908 arm
 *   ids 0x021BC710 data a2
 *   banks 0x021BC6FC data a1
 *   motion 0x021BC7F0 data a1
 *   files 0x021BC73C data a1
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_0202D81C 0x0202D81C thumb
 *   func_0202D7D8 0x0202D7D8 thumb
 *   func_0202D898 0x0202D898 thumb
 *   func_02049238 0x02049238 arm
 *   func_021BC520 0x021BC520 thumb
 *   func_0204B294 0x0204B294 arm
 *   func_0204B324 0x0204B324 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   _fgr 0x0209BBB0 arm
 *   _ffltu 0x0209BE04 arm
 *   _fmul 0x0209C77C arm
 *   _fdiv 0x0209CE10 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B5AC 0x0204B5AC arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B800 0x0204B800 arm
 *   func_0204B84C 0x0204B84C arm
 *   d_021BC7F0 0x021BC7F0 data
 *   d_021BC8C0 0x021BC8C0 data ov223
 *   func_021BB974 0x021BB974 thumb
 *   func_0204B688 0x0204B688 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204B92C 0x0204B92C arm
 *   d_021BC716 0x021BC716 data a2
 *   file 0x021BCB00 data
 *   func_02040E78 0x02040E78 arm
 *   func_02043678 0x02043678 arm
 *   func_02043AF4 0x02043AF4 arm
 *   func_020437D4 0x020437D4 arm
 *   func_020437EC 0x020437EC arm
 *   func_02040B1C 0x02040B1C arm
 *   func_020437AC 0x020437AC arm
 *   func_02041090 0x02041090 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02041570  0x02041570  arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020409B4 0x020409B4 arm
 *   entry_table 0x021BC770 data a1
 *   func_02049B40 0x02049B40 arm
 *   func_02045B38 0x02045B38 arm
 *   func_0203101C 0x0203101C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02031140 0x02031140 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020310C4  0x020310C4  arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   func_020437DC 0x020437DC arm
 *   func_020437E4 0x020437E4 arm
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0203630C  0x0203630C  arm
 *   func_02035C38  0x02035C38  arm
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0201EE60 0x0201EE60 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C724 0x0201C724 thumb
 *   d_021BC730 0x021BC730 data a4
 *   d_021BC710 0x021BC710 data a2
 *   func_02027F60 0x02027F60 thumb
 *   func_02027FD8  0x02027FD8  thumb
 *   func_02027FEC 0x02027FEC thumb
 *   func_02028148 0x02028148 thumb
 *   func_02028178 0x02028178 thumb
 *   func_02028218 0x02028218 thumb
 *   func_0202822C 0x0202822C thumb
 *   func_02028230 0x02028230 thumb
 */
#include "../../matched/include/Obj03961.h"
#include "../../matched/include/Obj03962.h"
#include "../../matched/include/Obj03380.h"
#include "../../matched/include/Obj14786.h"
#include "../../matched/include/Obj00739.h"
#include "../../matched/include/Obj02266.h"
#include "../../matched/include/Obj05570.h"
#include "../../matched/include/Obj01594.h"
#include "../../matched/include/Obj00211.h"
#include "../../matched/include/Obj05571.h"
#include "../../matched/include/Obj00738.h"
#include "../../matched/include/Obj05572.h"
#include "../../matched/include/Obj10978.h"
#include "../../matched/include/Obj01786.h"
#include "../../matched/include/Obj05573.h"
#include "../../matched/include/Obj02938.h"
#include "../../matched/include/Obj01595.h"
#include "../../matched/include/Obj10980.h"
#include "../../matched/include/Obj10981.h"
#include "../../matched/include/Obj26089.h"
#include "../../matched/include/Obj02939.h"
#include "../../matched/include/Obj08461.h"
#include "../../matched/include/Obj26093.h"
#include "../../matched/include/Obj00084.h"
#include "../../matched/include/Obj03381.h"

#define FIX(x) ((int)(((x)>0)?((x)*4096.0f+.5f):((x)*4096.0f-.5f)))
struct Obj0203159C;
struct S020315D4;
struct PrintSys;
struct Arg;
struct Rec;
struct G3dSys;
struct Record;
struct Ctx;
struct IcaAnime;
struct Util;
struct Setup;
struct AnmCtl;
struct Owner;
struct Obj;
struct Pair;
struct Actor;
struct Node;
struct PtS;
struct Bmp;
struct Obj020437AC;
struct MsgBank;
struct Tcbl;
struct Descriptor;
struct CharBuf;
struct Rec3;
struct U16Vec;
struct S02031140;
struct Cfg;
struct StrObj;
struct WordSet;
struct R;
struct TaskMenuState;
typedef unsigned int u32;

typedef unsigned short u16;

typedef struct {int x,y,z;} Vec;

struct Record { u16 id,pad; Vec translation,scale; u32 matrix[9],flag; };

typedef unsigned char u8;

typedef int s32_021B95A0;

typedef signed int     s32_021B97F8;

typedef signed int     s32;

struct TableRow { u16 h[5]; };

struct Request {u16 x,y,z;u8 a,b;};

struct Desc {u16 x,y,z;u8 a,b;u16 c,d;u32 sx,sy;u16 e,f;};

typedef struct {u8 b[14];} Motion;

typedef struct {u8 b[5];} Files;

typedef signed short s16;

typedef struct Vec2 { s16 x, y; } Vec2;

typedef struct FxPair { int x, y; } FxPair;

typedef struct Entry_021B95A0 {
    u8 pad0[0x18];
    struct Obj *f18;
    struct Obj *f1C;
    u8 pad20[0x84 - 0x20];
    u16 f84;
    u16 pad86;
    u32 f88;
    int f8C;
    int f90;
} Entry_021B95A0;

typedef struct Main {
    u8 pad0[0x54];
    Entry_021B95A0 ents[3];
    u8 pad210[0x230 - 0x210];
    int f230;
} Main;

typedef struct BytePair {u8 x,y;} BytePair;

typedef struct {u8 a,b,c,d,e,f,g,h,i;} Entry_021BAA84;

struct Item { void *text; u16 color; unsigned value; };

extern int func_020115EC(int, int);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_0207ADC4(void *);
extern u32 func_020307B0(void *p);
extern void func_0204E720(u32,int,int,int);
extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,u32,u32);
extern u32 func_0204E6E0(void);
extern void func_0204E6F4(int);
extern u8 func_020355C4(void);
extern void func_020355D8(u32 v);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021BC4F4(char *);
extern void func_021BC508(unsigned char *p);
extern void func_021BC514(unsigned char *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_02048A18(u8 *,int);
extern void func_02047A60(void *,struct Arg *);
extern int func_02047CFC(int, int, u16);
extern void func_02047E54(struct Rec *);
extern u16 func_02047E88(void *, const void *);
extern u32 func_020489F4(u8 *a0, int i);
extern int func_0204779C(int *p);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void *func_02011510(u32 heap, u32 b, u32 c, u32 d);
extern unsigned func_021BC52C(u8 *p);
extern void func_02011B8C(void *, void *);
extern void func_020480E4(struct Ctx *,u32),func_021B9600(void *),func_02011558(struct IcaAnime *);
extern int func_02047910(void *,int,int);
extern u32 func_02011590(struct IcaAnime *p, s32_021B97F8 v);
extern void func_020480E4(struct Ctx *,u32);
extern int func_020477D4(struct Owner *owner, u32 index);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
/* B908 reads only r0, forwarding its live r1 to D478; legacy r2/r3 unused. */
extern void func_0204B908(int a0, int a1);
extern int func_0202D7C8(int a0);
extern u32 func_0202D81C(u32,u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern u32 func_0202D7D8(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern u32 func_0202D898(u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern void func_02049238(u32);
extern unsigned func_021BC520(unsigned char *p);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern struct Obj *func_0204B324(u32 owner, u32 i, u32 j, u32 k, u32 e, u16 f, u16 g);
extern void func_0204B3DC(struct Obj *,unsigned int);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204AFD8(unsigned);
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
extern void func_0204B404(struct Obj *, const Vec2 *, u32);
extern void func_0204B5AC(struct Obj *dst, struct Pair *src);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B84C(struct Obj *, u32);
extern void func_021BB974(unsigned char *p, unsigned index, int cmd);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0207D63C(unsigned,int,int,int,int);
extern int func_0204AC18(void *,unsigned,unsigned,unsigned,u16,u16,u16);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_02040E78(unsigned,void *,unsigned,unsigned);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void *func_020437D4(const struct Bmp *bmp);
extern u32 func_020437EC(const struct Bmp *bmp);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_02041090(unsigned,unsigned,unsigned,unsigned,u8,u8);
extern void func_02041B6C(unsigned);
extern int func_02041570(int, int);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void func_020409B4(unsigned);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern struct MsgBank *func_02045B38(u32,u32,u32,u32);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_0201DD78(u32,u32,u32);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,u8);
extern void func_02045334(struct Descriptor *);
extern void func_0201CE48(struct Rec3 *);
extern void func_02045808(struct U16Vec *);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02031140(struct S02031140 *);
extern u32 func_02045C04(struct Rec *rec);
extern void func_020310C4(struct Tcbl *p);
extern unsigned func_0201C6C4(struct PrintSys *, void *);
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void *func_02045EC0(struct MsgBank *, unsigned);
extern unsigned func_0201D304(struct StrObj *, unsigned, unsigned);
extern unsigned func_0201D42C(struct StrObj *, void *);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern signed char func_02012FFC(void);
extern u32 func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern u32 func_0201CE30(void *p);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201CE38(void *p);
extern unsigned int func_0203630C(void);
extern int func_02035C38(void);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201C724(void *, unsigned, unsigned, unsigned, unsigned, unsigned, u16);
extern struct R *func_02027F60(u16,u16,u32,u32,u16);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern unsigned func_02027FEC(unsigned, unsigned, unsigned, unsigned, u8, u16);
extern void func_02028148(u8 *);
extern void func_02028178(u8 *);
extern void func_02028218(struct Obj *,u32);
extern void func_0202822C(char *,int);
extern u32 func_02028230(u8 *);
int func_021B95A0(int a0, int a1);
struct Record *func_021B95B0(u32 heap,u32 count);
void func_021B9600(void *p);
int func_021B9608(void *a,int unused,void *c);
int func_021B9674(void *a, int unused1, int unused2, u8 *ctx);
int func_021B96E0(void *a,int *state,void *b,char *p);
void func_021B9740(void *unused,char *p);
void func_021B97F8(char *p);
void func_021B9830(char *p);
void func_021B9848(int *p);
void func_021B9854(u8 *p);
void func_021B98F4(char *p);
void func_021B9914(char *p);
void func_021B99A0(char *p);
void func_021B9A6C(char *p);
void func_021B9A8C(char *p);
void func_021B9AE4(char *p,int type,int flag);
int func_021B9B4C(char *p);
void func_021B9B80(char *p);
void func_021B9C00(char *p,unsigned index);
void func_021B9C58(char *p);
void func_021B9C90(char *p,unsigned next);
void func_021B9D4C(char *p);
void func_021B9D9C(char *p);
void func_021BA050(char *p);
int func_021BA0AC(s16 *pos,int *size,u16 a,u16 b,u8 c,u8 d,u8 e,u8 f,u32 duration,u8 amplitude,u32 time);
void func_021BA2B4(Main *p);
void func_021BA81C(char *p,unsigned selected);
void func_021BA878(char *p);
int func_021BA8BC(char *p);
void func_021BA8D0(char *p);
void func_021BA984(char *p);
void func_021BAA30(char *p);
void func_021BAA5C(char *p,int flag);
void func_021BAA84(char *p, int unused);
void func_021BAAB8(u16 *p);
void func_021BAB74(int *a0);
void func_021BAB78(u16 *p);
int func_021BABFC(void);
void func_021BAC0C(u16 *p);
void func_021BAC6C(void);
void func_021BAC70(const u16 *p);
void func_021BAD68(char *a0);
void func_021BAD80(u16 *p);
void func_021BADFC(char *a0);
void func_021BAE00(char *p);
void func_021BAEE0(char *p);
void func_021BAF30(int *p);
int func_021BAF48(char *p);
void func_021BAFC4(char *p, int idx);
int func_021BB0B0(char *a);
void func_021BB134(char *p);
void func_021BB18C(char *p, int idx);
void func_021BB274(char *p);
void func_021BB2A4(char *p);
void func_021BB35C(char *p);
void func_021BB38C(char *p);
int func_021BB3AC(int *p);
void func_021BB3BC(char *p);
void func_021BB404(char *p);
void func_021BB414(char *p);
void func_021BB424(char *p);
u32 func_021BB440(char *p);
extern const char site[];
extern const u8 d_021BC7AC[];
extern const struct Setup setup;
extern const Vec positions[];
extern u16 table[][5];
extern const struct TableRow d_021BC790[];
extern const u16 d_021BC792[];
extern const u16 ids[];
extern const u8 banks[];
extern const Motion motion[];
extern const Files files[];
extern const u8 d_021BC7F0[3][14];
extern const u8 d_021BC8C0[3];
extern const BytePair d_021BC716[];
extern const char file[];
extern const Entry_021BAA84 entry_table[];
extern const u32 d_021BC730[];
extern const u16 d_021BC710[];






int func_021B95A0(int a0, int a1)
{
    return func_020115EC(a0, a1 / 2);
}





struct Record *func_021B95B0(u32 heap,u32 count)
{
    struct Record *p;
    u16 i;
    p=func_02030734(heap,count*sizeof(struct Record),1,site,654);
    for(i=0;i<count;i++) {
        p[i].translation.x=0;
        p[i].translation.y=0;
        p[i].translation.z=0;
        p[i].scale.x=4096;
        p[i].scale.y=4096;
        p[i].scale.z=4096;
        func_0207ADC4(p[i].matrix);
    }
    return p;
}





void func_021B9600(void *p) { func_020307B0(p); }





int func_021B9608(void *a,int unused,void *c)
{
    char *p;
    func_0204E720(3,16,16,0);
    func_0203064C(1,135,1<<20);
    p=func_0203159C(a,2168,135);
    func_02082BCC(p,0,2168);
    ((struct Obj03961 *)p)->f0=135;
    ((struct Obj03961 *)p)->f4=c;
    ((struct Obj03961 *)p)->f874=func_0204E6E0();
    func_0204E6F4(1);
    ((struct Obj03961 *)p)->f8=func_020355C4();
    ((struct Obj03961 *)p)->f228=4;
    ((struct Obj03961 *)p)->f22C=4;
    ((struct Obj03961 *)p)->f230=0;
    ((struct Obj03961 *)p)->fC=0;
    return 1;
}





int func_021B9674(void *a, int unused1, int unused2, u8 *ctx)
{
    u16 v;
    func_0204E720(0xC, 0x10, 0x10, 0);
    func_020355D8(*(u32 *)(ctx + 8));
    func_0204E6F4(*(u32 *)(ctx + 0x874));
    switch (*(u32 *)(ctx + 0x228)) {
    case 0:
        ***(u16 ***)(ctx + 4) = 0;
        break;
    case 1:
        v = 1;
    st:
        ***(u16 ***)(ctx + 4) = v;
        break;
    case 2:
        v = 2;
        goto st;
    default:
        ***(u16 ***)(ctx + 4) = 0;
        break;
    }
    *(u32 *)(*(u8 **)(ctx + 4) + 4) = *(u32 *)(ctx + 0x228);
    func_020315D4(a);
    func_020306F0(0x87);
    return 1;
}





extern int (*callbacks[])(char *,int *);





int func_021B96E0(void *a,int *state,void *b,char *p)
{
    int old=*state;
    *state=callbacks[*state](p,(int *)(p+12));
    if(*state!=13) {
        if(*state!=old) ((struct Obj03962 *)p)->fC=0;
    } else return 1;
    if(*state>=2&&*state<=11) {
        func_0201C4E4(((struct Obj03962 *)p)->f1C);
        func_021BAF30((int *)p);
        func_021BC4F4(*(char * *)&((struct Obj03962 *)p)->f14);
        func_021BC508(((struct Obj03962 *)p)->f14);
        func_021B97F8(p);
        func_021BC514(((struct Obj03962 *)p)->f14);
    }
    return 0;
}





void func_021B9740(void *unused,char *p)
{
    if(((struct Obj03380 *)p)->f24&1) func_02040588(3,1);
    if(((struct Obj03380 *)p)->f24&2) func_02040588(3,0);
    if(((struct Obj03380 *)p)->f24&4) {func_02040588(3,1);func_02040588(2,1);}
    if(((struct Obj03380 *)p)->f24&8) {func_02040588(3,0);func_02040588(2,0);}
    if(((struct Obj03380 *)p)->f24&16) {func_02040588(7,1);func_02040588(6,1);func_02040588(5,1);}
    if(((struct Obj03380 *)p)->f24&32) {func_02040588(7,0);func_02040588(6,0);func_02040588(5,0);}
    if(((struct Obj03380 *)p)->f24&64) func_02040588(3,1);
    if(((struct Obj03380 *)p)->f24&128) func_02040588(3,0);
    ((struct Obj03380 *)p)->f24=0;
}







void func_021B97F8(char *p) { u16 i;for(i=0;i<((struct Obj03962 *)p)->f3A;i++){char *q=(char *)(((struct Obj03962 *)p)->f3C+(u32)i*68);if(((struct Obj14786 *)q)->f40)func_02047A60(func_02048A18(*(u8 * *)&((struct Obj03962 *)p)->f28,((struct Obj14786 *)q)->f0),(struct Arg *)(q+4));} }








void func_021B9830(char *p)
{
    ((struct Obj00739 *)p)->f28 = func_02047CFC(5, 4, ((struct Obj00739 *)p)->f0);
    ((struct Obj00739 *)p)->f3A = 0;
}







void func_021B9848(int *p) { func_02047E54(*(struct Rec * *)&((struct Obj02266 *)p)->f28); }







void func_021B9854(u8 *p)
{
    u16 i;
    u32 n;
    u16 j;
    u8 *rec;
    u32 r;
    void *h;
    *(u16 *)(p + 0x2C) = func_02047E88(*(void **)(p + 0x28), d_021BC7AC);
    *(u16 *)(p + 0x3A) = 1;
    *(void **)(p + 0x3C) = func_021B95B0(*(u16 *)p, *(u16 *)(p + 0x3A));
    r = func_020489F4(*(void **)(p + 0x28), *(u16 *)(p + 0x2C));
    *(u16 *)(p + 0x30) = 0;
    rec = *(u8 **)(p + 0x3C);
    *(u16 *)rec = r;
    *(u32 *)(rec + 0x40) = 1;
    for (i = 0; i < *(u16 *)(p + 0x3A); i++) {
        h = (void *)func_02048A18(*(void **)(p + 0x28), *(u16 *)(*(u8 **)(p + 0x3C) + i * 0x44));
        n = func_0204779C(h);
        for (j = 0; j < n; j++) {
            func_020477A4(h, j);
        }
    }
    *(void **)(p + 0x40) = func_02011510(*(u16 *)p, 0xCD, 0x21, 0xA);
    func_02011B8C((void *)func_021BC52C(*(u8 **)(p + 0x14)), *(void **)(p + 0x40));
    *(u32 *)(p + 0x50) = 0;
}







void func_021B98F4(char *p) { func_020480E4(*(struct Ctx * *)&((struct Obj05570 *)p)->f28,((struct Obj05570 *)p)->f2C);func_021B9600(((struct Obj05570 *)p)->f3C);((struct Obj05570 *)p)->f3A=0;func_02011558(*(struct IcaAnime * *)&((struct Obj05570 *)p)->f40); }







void func_021B9914(char *p)
{
    int *obj;
    u32 n;
    u16 i,j;
    for(i=0;i<((struct Obj01594 *)p)->f3A;i++) {
        obj=(int *)func_02048A18(*(unsigned char * *)&((struct Obj01594 *)p)->f28,*(u16 *)(*(char * *)&((struct Obj01594 *)p)->f3C+i*68));
        n=func_0204779C(obj);
        for(j=0;j<n;j++) func_02047910(obj,j,2048);
    }
    func_02011590(((struct Obj01594 *)p)->f40,2048);
    func_02011B8C((void *)func_021BC52C(((struct Obj01594 *)p)->f14),((struct Obj01594 *)p)->f40);
    (*(u32 *)&((struct Obj01594 *)p)->f50)++;
}







void func_021B99A0(char *p)
{
    u16 i,n,j;
    u32 base,count;
    int *obj;
    struct Record *r;
    ((struct Obj00211 *)p)->f2E=func_02047E88(*(struct Util * *)&((struct Obj00211 *)p)->f28,&setup);
    ((struct Obj00211 *)p)->f3A=4;
    *(struct Record * *)&((struct Obj00211 *)p)->f3C=func_021B95B0(((struct Obj00211 *)p)->f0,((struct Obj00211 *)p)->f3A);
    n=0;
    base=func_020489F4(*(u8 * *)&((struct Obj00211 *)p)->f28,((struct Obj00211 *)p)->f2E);
    for(i=0;i<4;i++) {
        *(u16 *)(p+i*2+50)=n;
        r=*(struct Record * *)&((struct Obj00211 *)p)->f3C+n;
        r->id=base+i;
        r->flag=1;
        if(i+1>=2&&i+1<=4)r->translation=*(positions+i-1);
        n++;
    }
    obj=(int *)func_02048A18(*(u8 * *)&((struct Obj00211 *)p)->f28,*(u16 *)(*(char * *)&((struct Obj00211 *)p)->f3C+((struct Obj00211 *)p)->f32*68));
    count=func_0204779C(obj);
    for(j=0;j<count;j++)func_020477A4((struct G3dSys *)obj,j);
    ((struct Obj00211 *)p)->f40=func_02011510(((struct Obj00211 *)p)->f0,205,36,10);
    func_02011B8C((void *)func_021BC52C(((struct Obj00211 *)p)->f14),((struct Obj00211 *)p)->f40);
    ((struct Obj00211 *)p)->f50=0;
}







void func_021B9A6C(char *p) {func_020480E4(*(struct Ctx * *)&((struct Obj05571 *)p)->f28,((struct Obj05571 *)p)->f2E);func_021B9600(((struct Obj05571 *)p)->f3C);((struct Obj05571 *)p)->f3A=0;func_02011558(*(struct IcaAnime * *)&((struct Obj05571 *)p)->f40);}







void func_021B9A8C(char *p)
{
    int *obj;
    u32 n;
    u16 j;
    obj=(int *)func_02048A18(*(unsigned char * *)&((struct Obj00738 *)p)->f28,*(u16 *)(*(char * *)&((struct Obj00738 *)p)->f3C+((struct Obj00738 *)p)->f32*68));
    n=func_0204779C(obj);
    for(j=0;j<n;j++) func_02047910(obj,j,2048);
    func_02011590(((struct Obj00738 *)p)->f40,2048);
    func_02011B8C((void *)func_021BC52C(((struct Obj00738 *)p)->f14),((struct Obj00738 *)p)->f40);
    (((struct Obj00738 *)p)->f50)++;
}







void func_021B9AE4(char *p,int type,int flag)
{
    u16 v;
    float f;
    v=table[type][flag?1:0];
    if(v!=0) f=0.5f+(float)(v<<12);
    else f=(float)(v<<12)-0.5f;
    func_021B95A0(*(int *)&((struct Obj05572 *)p)->f40,(int)f);
    func_02011B8C((void *)func_021BC52C(((struct Obj05572 *)p)->f14),((struct Obj05572 *)p)->f40);
    ((struct Obj05572 *)p)->f44=type;
    ((struct Obj05572 *)p)->f48=flag;
    ((struct Obj05572 *)p)->f4C=v;
}





int func_021B9B4C(char *p)
{
    int select=0;
    if(((struct Obj10978 *)p)->f48==0) select=1;
    if(((struct Obj10978 *)p)->f4C==table[((struct Obj10978 *)p)->f44][select]) return 1;
    return 0;
}





void func_021B9B80(char *p)
{
    unsigned i=0;
    if(((struct Obj01786 *)p)->f48==0) i=1;
    i=table[*(unsigned *)(p+68)][i];
    if(((struct Obj01786 *)p)->f4C!=i) {
        int step;
        if(((struct Obj01786 *)p)->f48!=0) step=-2048; else step=2048;
        func_02011590(((struct Obj01786 *)p)->f40,step);
        func_02011B8C((void *)func_021BC52C(((struct Obj01786 *)p)->f14),((struct Obj01786 *)p)->f40);
        if(((struct Obj01786 *)p)->f48!=0) --((struct Obj01786 *)p)->f4C; else ++((struct Obj01786 *)p)->f4C;
    if(((struct Obj01786 *)p)->f4C==i && ((struct Obj01786 *)p)->f48!=0) {
        func_021B95A0((int)(((struct Obj01786 *)p)->f40),0x4E000);
        func_02011B8C((void *)func_021BC52C(((struct Obj01786 *)p)->f14),((struct Obj01786 *)p)->f40);
    }
    }
}





void func_021B9C00(char *p,unsigned index)
{
    u16 value;
    int coordinate;
    value=d_021BC790[index].h[0];
    if(value!=0) coordinate=(int)((float)(value<<12)+0.5f);
    else coordinate=(int)((float)(value<<12)-0.5f);
    func_021B95A0(*(int *)&((struct Obj05573 *)p)->f40,coordinate);
    func_02011B8C((void *)func_021BC52C(((struct Obj05573 *)p)->f14),((struct Obj05573 *)p)->f40);
    ((struct Obj05573 *)p)->f44=index;
    ((struct Obj05573 *)p)->f48=0;
    ((struct Obj05573 *)p)->f4C=value;
}






void func_021B9C58(char *p) {if(((struct Obj00738 *)p)->f4C!=*(const u16 *)((const u8 *)d_021BC792+((struct Obj00738 *)p)->f44*10)) {func_02011590(*(struct IcaAnime * *)&((struct Obj00738 *)p)->f40,2048);func_02011B8C((void *)func_021BC52C((unsigned char *)(((struct Obj00738 *)p)->f14)),((struct Obj00738 *)p)->f40);(((struct Obj00738 *)p)->f4C)++;}}







void func_021B9C90(char *p,unsigned next)
{
    void *object;
    unsigned count;
    u16 i;
    int frame;
    if(((struct Obj02938 *)p)->f22C!=4 && ((struct Obj02938 *)p)->f22C!=next) {
        object=(void *)func_02048A18(((struct Obj02938 *)p)->f28,*(u16 *)(*(char * *)&((struct Obj02938 *)p)->f3C+68*(*(u16 *)(p+48+2*(((struct Obj02938 *)p)->f22C+2)))));
        count=func_0204779C(object);
        for(i=0;i<count;i++) func_020477D4(object,i);
    }
    if(next!=4 && ((struct Obj02938 *)p)->f22C!=next) {
        object=(void *)func_02048A18(((struct Obj02938 *)p)->f28,*(u16 *)(*(char * *)&((struct Obj02938 *)p)->f3C+68*(*(u16 *)(p+48+2*(next+2)))));
        count=func_0204779C(object);
        frame=0;
        for(i=0;i<count;i++) {
            func_020477A4(object,i);
            func_0204784C(object,i,&frame);
        }
        func_0204B908((int)(((struct Obj02938 *)p)->f224),0);
    }
    ((struct Obj02938 *)p)->f22C=next;
}







void func_021B9D4C(char *p)
{
    void *object;
    unsigned count;
    u16 i;
    if(((struct Obj00738 *)p)->f22C!=4) {
        object=(void *)func_02048A18(((struct Obj00738 *)p)->f28,*(u16 *)(*(char * *)&((struct Obj00738 *)p)->f3C+68*(*(u16 *)(p+48+2*(((struct Obj00738 *)p)->f22C+2)))));
        count=func_0204779C(object);
        for(i=0;i<count;i++) func_02047910(object,i,2048);
    }
}







/*
 * lever: bind the file table record before the sprite record to reproduce their address scheduling.
 */
void func_021B9D9C(char *p)
{
    struct Desc desc;
    struct Request request;
    u32 arc,other,id;
    char *r;
    const Files *f;
    u8 i,j;
    arc=func_0202D7C8(((struct Obj00211 *)p)->f0);
    for(i=0;i<3;i++) {
        id=ids[i];r=p+i*148;
        ((struct Obj01595 *)r)->f54=func_0202D81C(arc,id,0,0,0,0,0,0,1,((struct Obj00211 *)p)->f0);
        ((struct Obj01595 *)r)->f58=func_0202D7D8(arc,id,0,0,0,0,0,1,(u16)(banks[i]<<5),((struct Obj00211 *)p)->f0);
        ((struct Obj01595 *)r)->f5C=func_0202D898(id,0,0,0,0,0,0,1,((struct Obj00211 *)p)->f0);
    }
    func_02049238(arc);
    for(j=0;j<3;j++) {
        func_02082BCC(&request,0,8);
        request.x=motion[j].b[0];request.y=motion[j].b[1];request.z=0;request.a=2;request.b=3;
        r=p+j*148;
        ((struct Obj01595 *)r)->f6C=(u32)func_0204B294((void *)func_021BC520(((struct Obj00211 *)p)->f14),((struct Obj01595 *)r)->f54,((struct Obj01595 *)r)->f58,((struct Obj01595 *)r)->f5C,&request,1,((struct Obj00211 *)p)->f0);
        func_0204B3DC((struct Obj *)((struct Obj01595 *)r)->f6C,0);
    }
    other=(u32)func_020490F4(205,((struct Obj00211 *)p)->f0);
    for(i=0;i<3;i++) {
        f=files+i;
        r=p+i*148;
        ((struct Obj01595 *)r)->f60=func_0204A6C8((void *)other,f->b[0],0,1,((struct Obj00211 *)p)->f0);
        ((struct Obj01595 *)r)->f68=func_0204AF28((void *)other,f->b[2],f->b[3],((struct Obj00211 *)p)->f0);
    }
    func_02049238(other);
    for(j=0;j<3;j++) {
        func_02082BCC(&desc,0,24);
        desc.x=motion[j].b[0];desc.y=motion[j].b[1];desc.z=0;desc.a=2;desc.b=3;desc.c=0;desc.d=0;
        desc.sx=FIX((float)motion[j].b[6]/16.0f);desc.sy=FIX((float)motion[j].b[6]/16.0f);
        desc.e=0;desc.f=1;
        r=p+j*148;
        ((struct Obj01595 *)r)->f70=(unsigned int)func_0204B324(func_021BC520(((struct Obj00211 *)p)->f14),((struct Obj01595 *)r)->f60,((struct Obj01595 *)r)->f58,((struct Obj01595 *)r)->f68,(u32)(&desc),1,((struct Obj00211 *)p)->f0);
        func_0204B3DC((struct Obj *)((struct Obj01595 *)r)->f70,0);
    }
    for(i=0;i<3;i++) {
        *(u16 *)(p+i*148+216)=0;
        *(u32 *)(p+i*148+220)=0;
        *(u32 *)(p+i*148+224)=0;
        *(u32 *)(p+i*148+228)=0;
    }
    ((struct Obj00211 *)p)->f210=0;((struct Obj00211 *)p)->f214=0;
}







void func_021BA050(char *p)
{
    u8 i,j;
    char *row,*entry;
    for(i=0;i<3;i++) {
        row=p+i*148;
        for(j=0;j<2;j++) {
            func_0204B3B4(*(void **)(row+108+j*4));
            entry=row+j*12;
            func_0204AFD8(((struct Obj10980 *)entry)->f5C);
            func_0204A8D4(((struct Obj10980 *)entry)->f54);
            if(j!=1) func_0204ADA4(((struct Obj10980 *)entry)->f58);
        }
    }
}







int func_021BA0AC(s16 *pos,int *size,u16 a,u16 b,u8 c,u8 d,u8 e,u8 f,u32 duration,u8 amplitude,u32 time)
{
    float x,y,arc,scale;
    s16 px,py,result;
    int fixed;
    x=(float)a+(float)time*((float)c-(float)a)/(float)duration;
    y=(float)b+(float)time*((float)d-(float)b)/(float)duration;
    arc=4.0f*((0.0f-(float)amplitude)*((float)time-(float)duration/2.0f)*((float)time-(float)duration/2.0f))/(float)duration/(float)duration+(float)amplitude;
    scale=(float)e+(float)time*((float)f-(float)e)/(float)duration;
    px=(s16)x;
    py=(s16)(y-arc);
    fixed=FIX(scale/16.0f);
    pos[0]=px;pos[1]=py;
    size[0]=size[1]=fixed;
    result=(s16)y;
    return result;
}







void func_021BA2B4(Main *p)
{
    int flags[3] = {0, 0, 0};
    s16 res[3];
    u8 i;
    for (i = 0; i < 3; i++) {
        Entry_021B95A0 *e = &p->ents[i];
        const u8 *t = d_021BC7F0[i];
        int d = 0;
        if (e->f8C == 0)
            continue;
        switch (e->f8C) {
        case 0: break;
        case 1: d = 1; break;
        case 2: d = -1; break;
        }
        if (d < 0) {
            e->f84 = 0;
            e->f88 = 1;
        }
        switch (e->f88) {
        case 0:
            if (d > 0) {
                func_0204B3DC(e->f18, 0);
                func_0204B3DC(e->f1C, 1);
                e->f84 = 0;
                e->f88 = 1;
                e->f90 = 0;
            } else {
                if (e->f8C == 2)
                    e->f8C = 0;
                break;
            }
        case 1:
            if (e->f84 == 0) {
                Vec2 v1;
                FxPair s1;
                u8 n1;
                v1.x = t[0];
                v1.y = t[1];
                n1 = t[6];
                s1.x = s1.y = FIX((float)n1 / 16.0f);
                func_0204B404(e->f1C, &v1, 1);
                func_0204B5AC(e->f1C, (struct Pair *)(&s1));
            } else {
                Vec2 a1;
                FxPair b1;
                res[i] = func_021BA0AC((s16 *)(&a1), (int *)(&b1), t[0], t[1], t[2], t[3], t[6], t[7], t[10], t[12], e->f84);
                flags[i] = 1;
                func_0204B404(e->f1C, &a1, 1);
                func_0204B5AC(e->f1C, (struct Pair *)(&b1));
            }
            if (e->f84 == 0 && d < 0) {
                func_0204B3DC(e->f18, 1);
                func_0204B3DC(e->f1C, 0);
                e->f84 = 0;
                e->f88 = 0;
                e->f90 = 0;
                break;
            }
            e->f84 = e->f84 + d;
            e->f90 = 0;
            if (e->f84 == t[10]) {
                e->f84 = 0;
                e->f88 = 2;
            }
            break;
        case 2: {
            Vec2 v2;
            FxPair s2;
            u8 n2;
            v2.x = t[2];
            v2.y = t[3];
            n2 = t[7];
            s2.x = s2.y = FIX((float)n2 / 16.0f);
            func_0204B404(e->f1C, &v2, 1);
            func_0204B5AC(e->f1C, (struct Pair *)(&s2));
            if (e->f84 == 0 && d < 0) {
                e->f84 = t[10] - 1;
                e->f88 = 1;
                e->f90 = 0;
                break;
            }
            e->f84 = e->f84 + d;
            e->f90 = 0;
            if (e->f84 == t[9]) {
                e->f84 = 0;
                e->f88 = 3;
            }
            break;
        }
        case 3:
            if (e->f84 == 0) {
                Vec2 v3;
                FxPair s3;
                u8 n3;
                v3.x = t[2];
                v3.y = t[3];
                n3 = t[7];
                s3.x = s3.y = FIX((float)n3 / 16.0f);
                func_0204B404(e->f1C, &v3, 1);
                func_0204B5AC(e->f1C, (struct Pair *)(&s3));
            } else {
                Vec2 a3;
                FxPair b3;
                res[i] = func_021BA0AC((s16 *)(&a3), (int *)(&b3), t[2], t[3], t[4], t[5], t[7], t[8], t[11], t[13], e->f84);
                flags[i] = 1;
                func_0204B404(e->f1C, &a3, 1);
                func_0204B5AC(e->f1C, (struct Pair *)(&b3));
            }
            if (e->f84 == 0 && d < 0) {
                e->f84 = t[9] - 1;
                e->f88 = 2;
                e->f90 = 0;
                break;
            }
            e->f84 = e->f84 + d;
            e->f90 = 0;
            if (e->f84 == t[11]) {
                e->f84 = 0;
                e->f88 = 4;
            }
            break;
        case 4: {
            Vec2 v4;
            FxPair s4;
            u8 n4;
            v4.x = t[4];
            v4.y = t[5];
            n4 = t[8];
            s4.x = s4.y = FIX((float)n4 / 16.0f);
            func_0204B404(e->f1C, &v4, 1);
            func_0204B5AC(e->f1C, (struct Pair *)(&s4));
            if (d < 0) {
                func_0204B84C(e->f1C, 3);
                e->f84 = t[11] - 1;
                e->f88 = 3;
                e->f90 = 0;
                break;
            }
            if (e->f8C == 1) {
                func_0204B84C(e->f1C, 2);
                e->f8C = 0;
                if (e->f90 == 0)
                    p->f230 = 1;
            }
            break;
        }
        }
    }
    {
    u8 order[3];
    s16 z[3];
    Vec2 pos;
    u8 j;
    order[0] = d_021BC8C0[0];
    order[1] = d_021BC8C0[1];
    order[2] = d_021BC8C0[2];
    for (i = 0; i < 3; i++) {
        if (flags[i]) {
            z[i] = res[i];
        } else {
            func_0204B454((struct Actor *)p->ents[i].f1C, (struct PtS *)(&pos), 1);
            z[i] = pos.y;
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 2; j > i; j--) {
            u8 a = order[j - 1];
            u8 b = order[j];
            if (z[b] > z[a]) {
                order[j - 1] = b;
                order[j] = a;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        u32 pr;
        if (order[0] == i)
            pr = 0;
        else {
            pr = 1;
            if (order[1] != i)
                pr = 2;
        }
        func_0204B800((struct Node *)p->ents[i].f1C, pr);
    }
    }
}







void func_021BA81C(char *p,unsigned selected)
{
    u8 i;
    for(i=0;i<3;i++) {
        if(i==selected) func_021BB974((unsigned char *)p,i,0); else func_021BB974((unsigned char *)p,i,2);
        if(i==selected) {
            *(unsigned *)(p+i*148+224)=1;
            *(unsigned *)(p+i*148+228)=1;
        } else {
            *(unsigned *)(p+i*148+224)=2;
            *(unsigned *)(p+i*148+228)=1;
        }
    }
}







void func_021BA878(char *p)
{
    u8 i;
    int alpha;
    for(i=0;i<3;i++) func_0204B688(*(void **)(p+i*148+108),1);
    ((struct Obj10981 *)p)->f210=0;
    ((struct Obj10981 *)p)->f214=1;
    alpha=((struct Obj10981 *)p)->f210;
    func_0207D63C(0x04001050,0,63,alpha,16-alpha);
}







int func_021BA8BC(char *p)
{
    if(((struct Obj26089 *)p)->f214==0) return 1;
    return 0;
}






void func_021BA8D0(char *p)
{
    u8 i;
    switch(((struct Obj02939 *)p)->f214) {
    case 1:
        for(i=0;i<3;i++) func_0204B3DC(*(void **)(p+i*148+108),1);
        ((struct Obj02939 *)p)->f214=2;
        break;
    case 2:
        if(((struct Obj02939 *)p)->f210<16) {
            ++((struct Obj02939 *)p)->f210;
            if(((struct Obj02939 *)p)->f210==16) {
                for(i=0;i<3;i++) func_0204B688(*(void **)(p+i*148+108),0);
                ((struct Obj02939 *)p)->f214=3;
            }
            func_0207D63C(0x04001050,0,63,((struct Obj02939 *)p)->f210,16-((struct Obj02939 *)p)->f210);
        } else ((struct Obj02939 *)p)->f214=3;
        break;
    case 3:
        func_0207D63C(0x04001050,4,63,8,8);
        ((struct Obj02939 *)p)->f214=0;
        break;
    }
}






void func_021BA984(char *p)
{
    void *object;
    struct Request request;
    object=func_020490F4(205,((struct Obj00211 *)p)->f0);
    ((struct Obj00211 *)p)->f21C=func_0204AC18(object,11,0,0,0,1,((struct Obj00211 *)p)->f0);
    ((struct Obj00211 *)p)->f218=func_0204A6C8(object,17,0,0,((struct Obj00211 *)p)->f0);
    ((struct Obj00211 *)p)->f220=func_0204AF28(object,24,28,((struct Obj00211 *)p)->f0);
    func_02049238((u32)object);
    func_02082BCC(&request,0,8);
    request.x=66;request.y=39;request.z=0;request.a=0;request.b=2;
    ((struct Obj00211 *)p)->f224=func_0204B294((void *)func_021BC520(((struct Obj00211 *)p)->f14),((struct Obj00211 *)p)->f218,((struct Obj00211 *)p)->f21C,((struct Obj00211 *)p)->f220,&request,0,((struct Obj00211 *)p)->f0);
    func_0204B92C(((struct Obj00211 *)p)->f224,1);
    func_021BAA5C(p,0);
}






void func_021BAA30(char *p) {u32 off;off=0x224;func_0204B3B4(*(struct Obj **)(p+off));func_0204AFD8(*(u32 *)(p+off-4));func_0204A8D4(*(u32 *)(p+off-12));off-=8;func_0204ADA4(*(u32 *)(p+off));}



void func_021BAA5C(char *p,int flag) {Vec2 pos;if(flag) {func_021BAA84(p,flag);}else {pos.x=400;pos.y=300;func_0204B404(*(struct Obj * *)&((struct Obj00211 *)p)->f224,&pos,0);}}




void func_021BAA84(char *p, int unused) {Vec2 pos;u32 idx,off;off=0x228;idx=*(u32 *)(p+off);off-=4;pos.x=d_021BC716[idx].x;pos.y=d_021BC716[idx].y;func_0204B404(*(struct Obj **)(p+off),&pos,0);}





void func_021BAAB8(u16 *p)
{
    u16 *buffer;
    void *bmp,*data;
    unsigned size;
    buffer=func_02030734(*p,32,1,file,0x92B);
    buffer[0]=0;buffer[1]=0;buffer[2]=0x7FFF;
    func_02040E78(2,buffer,32,0x1A0);
    func_02040E78(6,buffer,32,0);
    func_020307B0(buffer);
    bmp=func_02043678(2,1,32,*p);
    func_02043AF4(bmp,0,0,8,8,0);
    func_02043AF4(bmp,8,0,8,8,1);
    data=func_020437D4(bmp);size=func_020437EC(bmp);
    func_02040B1C(2,data,size,0);
    data=func_020437D4(bmp);size=func_020437EC(bmp);
    func_02040B1C(6,data,size,0);
    func_020437AC(bmp);
}





void func_021BAB74(int *a0) {}




/*
 * lever: cast the whole ternary to u16; declare col,row before index.
 */
void func_021BAB78(u16 *p)
{
    u8 col,row;
    u16 *buffer,index;
    buffer=func_02030734(*p,1536,1,file,0x951);
    index=0;
    for(row=0;row<24;row++) {
        for(col=0;col<32;col++) {
            u16 tile;
            tile=(u16)((row>=4 && row<20)?1:0);
            buffer[index]=tile|0xD000;
            index++;
        }
    }
    func_02041090(2,(unsigned)buffer,0,0,32,24);
    func_02041B6C(2);
    func_020307B0(buffer);
}





/*
 * Addresses are Black-image addresses.
 */
int func_021BABFC(void)
{
    return func_02041570(2, 0xd000);
}




void func_021BAC0C(u16 *p)
{
    void *object;
    object=func_020490F4(205,*p);
    func_02049BDC(object,6,4,256,256,256,*p);
    func_02049658(object,15,4,0,0,0,*p);
    func_020498F4(object,18,4,0,0,0,*p);
    func_02049238((u32)object);
    func_020409B4(4);
}




void func_021BAC6C(void) {}




void func_021BAC70(const u16 *p)
{
    u16 *buffer;
    u8 x;
    u16 v;
    u8 y;
    u16 n;
    buffer=func_02030734(*p,1536,1,site,2463);
    n=0;
    for(y=0;y<24;y++)for(x=0;x<32;x++) {
        v=(y>=17&&y<23)?1:0;
        buffer[n]=v|0xd000;
        n++;
    }
    func_02041090(2,(u32)buffer,0,0,32,24);
    func_02041B6C(2);func_020307B0(buffer);
    buffer=func_02030734(*p,1536,1,site,2488);
    n=0;
    for(x=0;x<24;x++)for(y=0;y<32;y++) {
        v=(x>=17&&x<23)?1:0;
        buffer[n]=v;
        n++;
    }
    func_02041090(6,(u32)buffer,0,0,32,24);
    func_02041B6C(6);func_020307B0(buffer);
}





void func_021BAD68(char *a0)
{
    func_02041570(2, 0xd000);
    func_02041570(6, 0);
}




/*
 * Trailing ADFA halfword is zero alignment padding.
 */
void func_021BAD80(u16 *p)
{
    void *object;
    object = func_020490F4(205, *p);
    func_02049BDC(object, 7, 4, 256, 256, 256, *p);
    func_02049658(object, 16, 4, 0, 0, 0, *p);
    func_020498F4(object, 19, 4, 0, 0, 0, *p);
    func_020498F4(object, 20, 5, 0, 0, 0, *p);
    func_02049238((u32)object);
    func_020409B4(4);
    func_020409B4(5);
}




void func_021BADFC(char *a0) {}



void func_021BAE00(char *p)
{
    u8 i=0;
    func_02049B40(23,5,0,448,32,((struct Obj00739 *)p)->f0);
    func_02049B40(23,5,4,32,32,((struct Obj00739 *)p)->f0);
    *(struct MsgBank * *)&((struct Obj00739 *)p)->f234=func_02045B38(0,3,430,((struct Obj00739 *)p)->f0);
    *(struct Tcbl * *)&((struct Obj00739 *)p)->f254=func_0203101C(((struct Obj00739 *)p)->f0,((struct Obj00739 *)p)->f0,1,0);
    func_0201DD78(15,2,0);
    for(;i<3;i++) {
        *(u32 *)(p+i*4+568)=func_020450F0(entry_table[i].a,entry_table[i].b,entry_table[i].c,entry_table[i].d,entry_table[i].e,entry_table[i].f,entry_table[i].g);
        func_02043B5C(func_02045770(*(struct Descriptor **)(p+i*4+568)),0);
        func_02045334(*(struct Descriptor **)(p+i*4+568));
        *(u32 *)(p+i*4+580)=1;
    }
    ((struct Obj00739 *)p)->f250=0;((struct Obj00739 *)p)->f258=0;
}



void func_021BAEE0(char *p)
{
    u8 i;
    if (*(struct Rec3 * *)&((struct Obj02266 *)p)->f250)
        func_0201CE48(*(struct Rec3 * *)&((struct Obj02266 *)p)->f250);
    if (*(struct U16Vec * *)&((struct Obj02266 *)p)->f258)
        func_02045808(*(struct U16Vec * *)&((struct Obj02266 *)p)->f258);
    for (i = 0; i < 3; i++)
        func_020452E8(*(struct Descriptor **)(p + 0x238 + i * 4));
    func_02031140(*(struct S02031140 * *)&((struct Obj02266 *)p)->f254);
    func_02045C04(*(struct Rec * *)&((struct Obj02266 *)p)->f234);
}




void func_021BAF30(int *p)
{
    func_020310C4((struct Tcbl *)p[0x95]);
    func_021BAF48((char *)p);
}



/*
 * Trailing AFC2 halfword is zero alignment padding. Forming q = p + i*4
 * before fixed field offsets retains the observed invariant constants;
 * computing p + constant + i*4 instead hoists pointer bases and spills p.
 */
int func_021BAF48(char *p)
{
    int finished = 1;
    u8 i;
    for (i = 0; i < 3; i++) {
        char *q = p + i * 4;
        if (((struct Obj08461 *)q)->f244 == 0) {
            if (func_0201C6C4(*(struct PrintSys * *)&((struct Obj26093 *)p)->f1C,
                            func_02045770(*(struct Descriptor * *)&((struct Obj08461 *)q)->f238)) != 0) {
                finished = 0;
            } else {
                struct Descriptor *d = *(struct Descriptor * *)&((struct Obj08461 *)q)->f238;
                func_02045334(d);
                func_02045374((struct Cfg *)d);
                func_02041B6C(func_02045730(d));
                ((struct Obj08461 *)q)->f244 = 1;
            }
        }
    }
    return finished;
}



void func_021BAFC4(char *p, int idx)
{
    struct Descriptor *desc = *(struct Descriptor **)(p + 0x23C);
    s16 x = 0;
    s16 y = 0;
    unsigned w, h;
    unsigned W, H;
    func_02043B5C((struct CharBuf *)func_02045770(desc), 0);
    if (*(u32 *)(p + 0x250) != 0)
        func_0201CE48(*(struct Rec3 **)(p + 0x250));
    if (*(u32 *)(p + 0x258) != 0)
        func_02045808(*(struct U16Vec **)(p + 0x258));
    *(void **)(p + 0x258) = func_02045EC0(*(struct MsgBank **)(p + 0x234), idx);
    w = (u16)func_0201D304(*(struct StrObj **)(p + 0x258), *(unsigned *)(p + 0x18), 0);
    h = (u16)func_0201D42C(*(struct StrObj **)(p + 0x258), *(void **)(p + 0x18));
    W = func_020437DC(func_02045770(desc));
    H = func_020437E4(func_02045770(desc));
    if (W > w)
        x = ((int)(W - w)) / 2;
    if (H > h)
        y = ((int)(H - h)) / 2;
    *(u32 *)(p + 0x250) = func_0201CCE4((u32)desc, x, y, *(u32 *)(p + 0x258), *(u32 *)(p + 0x18), func_02012FFC(),
                                         *(u32 *)(p + 0x254), 2, *(u16 *)p, 0);
    func_02045334(desc);
    func_02045374((struct Cfg *)desc);
    func_02041B6C(func_02045730(desc));
}




int func_021BB0B0(char *a)
{
    int r = 0;

    switch (func_0201CE30((void *)(*(u32 *)&((struct Obj00084 *)a)->f250))) {
    case 0:
        if ((func_0203630C() & 3) != 0 || func_02035C38() != 0) {
            func_0201CE5C((struct Rec *)(*(u32 *)&((struct Obj00084 *)a)->f250), 0);
            if ((func_0203630C() & 3) != 0)
                ((struct Obj00084 *)a)->f8 = 0;
            else
                ((struct Obj00084 *)a)->f8 = 1;
        }
        break;
    case 1:
        if ((func_020362DC() & 3) != 0 || func_02035C60() != 0) {
            func_0201CE38((void *)(*(u32 *)&((struct Obj00084 *)a)->f250));
            if ((func_020362DC() & 3) != 0)
                ((struct Obj00084 *)a)->f8 = 0;
            else
                ((struct Obj00084 *)a)->f8 = 1;
        }
        break;
    case 2:
        r = 1;
        break;
    }
    return r;
}



void func_021BB134(char *p)
{
    struct Descriptor *d;
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00084 *)p)->f23C), 0);
    d = *(struct Descriptor * *)&((struct Obj00084 *)p)->f23C;
    func_02045334(d);
    func_02045374((struct Cfg *)d);
    func_02041B6C(func_02045730(d));
    if (*(struct Rec3 * *)&((struct Obj00084 *)p)->f250)
        func_0201CE48(*(struct Rec3 * *)&((struct Obj00084 *)p)->f250);
    *(int *)&((struct Obj00084 *)p)->f250 = 0;
    if (*(struct U16Vec * *)&((struct Obj00084 *)p)->f258)
        func_02045808(*(struct U16Vec * *)&((struct Obj00084 *)p)->f258);
    *(int *)&((struct Obj00084 *)p)->f258 = 0;
}



/*
 * note: 2026-10-05 (wD8 lane03): EXACT. The 0x24C slot is a pointer local `flag = (u32 *)(p + 0x24C)`
 *   set right after the desc load and written at the end (`*flag = 0`). mwcc keeps the 0x240 base from
 *   the desc load in r4, derives 0x24C from it at the top, spills only the offset and uses [r5,r0] at the
 *   store. The k/off locals and the enum type of earlier drafts are gone.
 */
void func_021BB18C(char *p, int idx)
{
    struct Descriptor *desc;
    u16 x;
    void *words;
    void *text;
    u32 *flag;
    struct StrObj *buf;
    u16 height;
    unsigned h;
    desc = *(struct Descriptor **)(p + 0x240);
    flag = (u32 *)(p + 0x24C);
    x = 0;
    words = func_0201EC64(*(u16 *)p);
    text = func_02045EC0(*(struct MsgBank **)(p + 0x234), d_021BC730[idx]);
    buf = (struct StrObj *)func_020457B0(0x40, *(u16 *)p);
    func_0201EE60(words, 1, d_021BC710[idx]);
    func_0201F250(words, buf, text);
    func_02045808((struct U16Vec *)text);
    func_0201ED04(words);
    func_02043B5C((struct CharBuf *)func_02045770(desc), 0);
    func_0201D304(buf, *(unsigned *)(p + 0x18), 0);
    height = func_0201D42C(buf, *(void **)(p + 0x18));
    func_020437DC(func_02045770(desc));
    h = func_020437E4(func_02045770(desc));
    if (h > height)
        x = ((int)h - height) / 2;
    func_0201C724(*(void **)(p + 0x1C), (unsigned)func_02045770(desc), 0, (s16)x, (unsigned)buf, *(unsigned *)(p + 0x18), 0x3C40);
    func_02045808((struct U16Vec *)buf);
    *flag = 0;
    func_021BAF48(p);
}



void func_021BB274(char *p) {struct Descriptor *d;u32 off;off=0x240;func_02043B5C(func_02045770(*(struct Descriptor **)(p+off)),0);d=*(struct Descriptor **)(p+off);func_02045334(d);func_02045374((struct Cfg *)d);func_02041B6C(func_02045730(d));}



/*
 * Declare width before the zero x initializer: its store shares the
 * upcoming call's zero r2; const p left the six-byte scheduling diff.
 * The bitmap accessors' own sources return u16. This caller uses each
 * result at full width without truncation, so its declarations widen them.
 */
void func_021BB2A4(char *p)
{
    struct StrObj *text = func_02045EC0(*(struct MsgBank * *)&((struct Obj03381 *)p)->f234, 12);
    u16 width = func_0201D304(text, *(unsigned *)&((struct Obj03381 *)p)->f18, 0);
    u16 x = 0;
    u16 height = func_0201D42C(text, ((struct Obj03381 *)p)->f18);
    unsigned w = func_020437DC(func_02045770(*(struct Descriptor * *)&((struct Obj03381 *)p)->f238));
    unsigned h = func_020437E4(func_02045770(*(struct Descriptor * *)&((struct Obj03381 *)p)->f238));
    u16 y = 0;
    if (w > width)
        x = ((int)w - width) / 2;
    if (h > height)
        y = ((int)h - height) / 2;
    func_0201C724(((struct Obj03381 *)p)->f1C, (unsigned)func_02045770(*(struct Descriptor * *)&((struct Obj03381 *)p)->f238),
                 (s16)x, (s16)y, (unsigned)text, *(unsigned *)&((struct Obj03381 *)p)->f18, 0x3C40);
    func_02045808((struct U16Vec *)text);
    ((struct Obj03381 *)p)->f244 = 0;
    func_021BAF48(p);
}



void func_021BB35C(char *p) {struct Descriptor *d;u32 off;off=0x238;func_02043B5C(func_02045770(*(struct Descriptor **)(p+off)),0);d=*(struct Descriptor **)(p+off);func_02045334(d);func_02045374((struct Cfg *)d);func_02041B6C(func_02045730(d));}



void func_021BB38C(char *p) {*(struct R * *)&((struct Obj00739 *)p)->f25C=func_02027F60(3,11,*(u32 *)&((struct Obj00739 *)p)->f18,((struct Obj00739 *)p)->f1C,((struct Obj00739 *)p)->f0);}




int func_021BB3AC(int *p)
{
    return func_02027FD8((struct TaskMenuState *)p[0x97]);
}



/*
 * The lead's EXACT* ends at BB404; two complete 16-byte load/tail-call
 * followers cover the remaining extent. Parent cleared both starts.
 */
void func_021BB3BC(char *p)
{
    struct Item item;
    item.text = func_02045EC0(*(struct MsgBank * *)&((struct Obj00084 *)p)->f234, 21);
    item.color = 0x39E3;
    item.value = 0;
    *(unsigned *)&((struct Obj00084 *)p)->f260 = func_02027FEC(*(unsigned *)&((struct Obj00084 *)p)->f25C, (unsigned)&item, 9, 21, 14, ((struct Obj00084 *)p)->f0);
    func_02045808(item.text);
}



void func_021BB404(char *p)
{
    func_02028148(*(u8 * *)&((struct Obj00084 *)p)->f260);
}



void func_021BB414(char *p)
{
    func_02028178(*(u8 * *)&((struct Obj00084 *)p)->f260);
}



void func_021BB424(char *p) {u32 off;off=0x260;func_02028218(*(struct Obj **)(p+off),1);func_0202822C(*(char **)(p+off),1);}



u32 func_021BB440(char *p) {return func_02028230(*(u8 * *)&((struct Obj00084 *)p)->f260);}
