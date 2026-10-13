/*
 * file:     local_tvt_sys.c
 * unit:     yes
 * function: func_021B6100, func_021B61C4, func_021B622C, func_021B63B0, func_021B63DC, func_021B6508, func_021B6538, func_021B655C, func_021B6594, func_021B6704, func_021B6754, func_021B6760, func_021B6824, func_021B687C, func_021B68E8, func_021B68F8, func_021B6994, func_021B6A04, func_021B6A90, func_021B6AF8, func_021B6B5C, func_021B6BC4, func_021B6C2C, func_021B6C5C, func_021B6C70, func_021B6D00, func_021B6D3C, func_021B6F2C, func_021B6F3C, func_021B7004, func_021B7180, func_021B71A0, func_021B71B8, func_021B7350, func_021B7360, func_021B7364
 * address:  0x021B6100
 * region:   ov174
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_02012984 0x02012984 thumb
 *   func_02011400 0x02011400 thumb
 *   func_0203F4CC 0x0203F4CC arm
 *   func_0203D34C 0x0203D34C arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_02049238 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 *   func_02005728 0x02005728 thumb
 *   func_02040618 0x02040618 arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0202223C 0x0202223C thumb
 *   func_02022224 0x02022224 thumb
 *   func_020433E0 0x020433E0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02082A7C 0x02082A7C arm
 *   func_0204A48C 0x0204A48C arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_0207D63C 0x0207D63C arm
 *   d_021B7450 0x021B7450 data a4
 *   d_021B7388 0x021B7388 data a4
 *   d_021B73D0 0x021B73D0 data a4
 *   d_021B73B0 0x021B73B0 data a4
 *   d_021B7410 0x021B7410 data a4
 *   d_021B7430 0x021B7430 data a4
 *   d_021B73F0 0x021B73F0 data a4
 *   d_020A1448 0x020A1448 data a4
 *   func_0204A5AC 0x0204A5AC arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204A380 0x0204A380 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02012944 0x02012944 thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02008550 0x02008550 thumb
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020413B0 0x020413B0 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   d_021B7380 0x021B7380 data a1
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_0201F548  0x0201F548  thumb
 *   func_02049B90  0x02049B90  arm
 *   func_02049B40  0x02049B40  arm
 *   func_0201DD68  0x0201DD68  thumb
 *   func_0203101C  0x0203101C  arm
 *   func_0201C440  0x0201C440  thumb
 *   func_02028590  0x02028590  thumb
 *   func_0201DD78  0x0201DD78  thumb
 *   func_02028604 0x02028604 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02031140 0x02031140 arm
 *   func_020310C4 0x020310C4 arm
 *   func_020286C4 0x020286C4 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_02028484 0x02028484 thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02028470 0x02028470 thumb
 *   func_02045730 0x02045730 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   g_021B7398  0x021B7398  data  a4
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_021B7378 0x021B7378 thumb ov174
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02030734 0x02030734 arm
 *   func_020124F4 0x020124F4 thumb
 *   func_0203630C 0x0203630C arm
 *   d_021B74AC 0x021B74AC data
 *   func_02012704 0x02012704 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   d_021B74BC 0x021B74BC data
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_020056EC 0x020056EC thumb
 *   func_0204B95C 0x0204B95C arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B918 0x0204B918 arm
 *   func_0204B974 0x0204B974 arm
 *   d_021B7485 0x021B7485 data a1
 *   d_021B7481 0x021B7481 data a1
 *   func_02049BDC 0x02049BDC arm
 *   d_021B7484 0x021B7484 data a1
 *   d_021B7480 0x021B7480 data a1
 *   func_02049DF4 0x02049DF4 arm
 *   func_02082A90  0x02082A90  arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C724 0x0201C724 thumb
 */
#include "../../matched/include/Obj01167.h"
#include "../../matched/include/Obj24197.h"
#include "../../matched/include/Obj00681.h"
#include "../../matched/include/Obj00152.h"
#include "../../matched/include/Obj03859.h"
#include "../../matched/include/Obj00545.h"
#include "../../matched/include/Obj24199.h"
#include "../../matched/include/Obj24200.h"
#include "../../matched/include/Obj00918.h"
#include "../../matched/include/Obj24201.h"
#include "../../matched/include/Obj02507.h"
#include "../../matched/include/Obj02218.h"
#include "../../matched/include/Obj00919.h"
#include "../../matched/include/Obj08268.h"
#include "../../matched/include/Obj24202.h"
#include "../../matched/include/Obj24203.h"
#include "../../matched/include/Obj10673.h"
#include "../../matched/include/Obj24204.h"
#include "../../matched/include/Obj01422.h"
#include "../../matched/include/Obj01759.h"
#include "../../matched/include/Obj24205.h"
#include "../../matched/include/Obj03860.h"
#include "../../matched/include/Obj00185.h"
#include "../../matched/include/Obj24206.h"
#include "../../matched/include/Obj24207.h"
#include "../../matched/include/Obj05453.h"
#include "../../matched/include/Obj00476.h"
#include "../../matched/include/Obj14322.h"
#include "../../matched/include/Obj24208.h"
#include "../../matched/include/Obj24209.h"
#include "../../matched/include/Obj24210.h"
#include "../../matched/include/Obj10674.h"

struct BigObj;
struct Bank;
struct Node;
struct Obj;
struct Cfg;
struct DispConfig;
struct DispVram;
struct BgTemplate;
struct Sub0200852CObj;
struct Actor;
struct Vec2;
struct GfFont;
struct MsgBank;
struct Tcbl;
struct Descriptor;
struct PrintSys;
struct Rec;
struct Rec3;
struct S02031140;
struct U16Vec;
struct WordSet;
struct Blk;
struct Ctx;
struct CharBuf;
struct Obj0203159C;
struct S020315D4;
struct StrObj;
typedef unsigned char u8;

typedef unsigned short u16;

struct RtcTime{unsigned hour,minute,second;};

typedef unsigned int   u32_021B6100;

typedef unsigned int   u32_021B61C4;

typedef unsigned u32_021B622C;

typedef enum { SZ0=0,SZ1=1,SZ2=2,SZ3=3 } GXBGScrSize256x16Pltt;

typedef enum { OVER0=0,OVER1=1 } GXBGAreaOver;

typedef enum { SB0=0,SB31=31 } GXBGScrBase;

typedef enum { CB0=0,CB15=15 } GXBGCharBase;

typedef unsigned u32_021B63DC;

typedef struct { u32_021B63DC w[7]; } Config;

typedef unsigned int   u32_021B655C;

typedef unsigned u32_021B6594;

typedef struct { u16 x,y,z; u8 a,b; } Spec;

typedef signed int     s32;

typedef unsigned int   u32_021B6704;

typedef unsigned int u32_021B6760;

typedef unsigned int   u32_021B6824;

typedef unsigned int   u32_021B687C;

typedef signed char s8;

typedef signed short s16;

typedef unsigned int u32_021B68E8;

typedef unsigned int   u32_021B68F8;

typedef unsigned int   u32_021B6994;

typedef unsigned int   u32_021B6A04;

typedef struct { u8 x, y; } Pair_021B6100;

typedef struct Obj Obj;

struct Obj {
    unsigned char pad00[0x0C];
    unsigned char state;
    unsigned char pad0D[0x34 - 0x0D];
    int pending;
    unsigned char pad38[0x40 - 0x38];
    unsigned char *steps;
    unsigned char pad44[0x89 - 0x44];
    unsigned char stepIdx;
};

typedef struct Ent {
    void (*init)(Obj *);
    int (*update)(Obj *);
} Ent;

typedef unsigned int u32;

struct E { u8 a, b; u16 c; };

struct P { u8 pad0[0x40]; struct E *tbl; u8 pad1[0x89 - 0x44]; u8 idx; };

typedef signed short s16_021B6F2C;

typedef struct { short x, y; u16 id; u8 a, b; } Request;

typedef short s16_021B71B8;

typedef struct { u8 x,y; } Pair_021B6A90;

typedef signed short s16_021B7364;

extern void *func_020490F4(u32_021B6100 id, u32_021B6100 heap);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern u8 func_02012984(const struct BigObj *p);
extern u8 func_02011400(int row, int col);
extern void func_0203F4CC(struct RtcTime *),func_0203D34C(unsigned,unsigned);
extern void func_02030EAC(struct Node *n);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32_021B61C4 i);
extern void func_0204A8D4(u32_021B61C4 i);
extern void func_0204AFD8(u32_021B61C4 i);
extern u32_021B61C4 func_0204B1CC(struct Bank *bank);
extern void func_02049238(void *);
extern u32_021B61C4 func_020307B0(void *p);
extern void func_0202208C(void *,u32_021B622C,u32_021B622C,u32_021B622C,u32_021B622C,u32_021B622C,u32_021B622C);
extern u32_021B622C func_020221A4(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern int func_02005728(int);
extern void func_02040618(unsigned,unsigned,unsigned);
extern void func_020434CC(void),func_02043588(void);
extern void func_0202223C(u32_021B63DC a, u32_021B63DC color);
extern u32_021B63DC func_02022224(void *win);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16),func_02045088(u16);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02082A7C(int,int,u32_021B63DC);
extern void func_0204A48C(const struct Cfg *cfg, u32_021B63DC arg, u32_021B63DC heapId);
extern void func_020434DC(u32_021B63DC mask, u32_021B63DC enable);
extern void func_02043598(u32_021B63DC mask, u32_021B63DC enable);
extern struct Bank *func_0204B100(int count, u8 flag, u32_021B63DC heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_0204A5AC(void),func_020403F4(unsigned),func_020450C8(void),func_0203F9B4(void);
extern void func_0203FCA0(unsigned,const struct BgTemplate *,unsigned);
extern void func_02040588(unsigned,unsigned),func_020414AC(unsigned),func_020409B4(unsigned);
extern void *func_0204A380(void *a0, u32_021B655C a1, u32_021B655C a2, u32_021B655C a3);
extern void func_020498F4(void *,u32_021B6594,u32_021B6594,u32_021B6594,u32_021B6594,u32_021B6594,u16);
extern u8 *func_02012944(void *p);
extern int func_0204ACEC(void *,u32_021B6594,u32_021B6594,u32_021B6594,u16);
extern int func_0204A6C8(void *,u32_021B6594,u32_021B6594,u32_021B6594,u16);
extern s32 func_0204AF28(void *owner, u32_021B6594 first, u32_021B6594 second, u32_021B6594 mode);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02049B68(void *,u32_021B6594,u32_021B6594,u32_021B6594,u32_021B6594,u16);
extern u32_021B6594 func_02049658(void *a, u32_021B6594 b, u32_021B6594 c, u32_021B6594 d, u32_021B6594 e, u32_021B6594 f, u16 g);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, u32_021B6594 v);
extern void func_0204B92C(struct Obj *p, u32_021B6594 v);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32_021B6704 which);
extern void func_0204B9A0(struct Actor *a);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32_021B6760 heapId);
extern struct MsgBank *func_02045B38(u32_021B6760 resident, u32_021B6760 arcId, u32_021B6760 fileId, u32_021B6760 heapId);
extern void func_0201F5BC(u32_021B6760 a, u32_021B6760 b, u32_021B6760 c, u32_021B6760 d, u16 e);
extern u8 func_0201F548(int i);
extern void func_02049B90(u32_021B6760 a0, u32_021B6760 a1, u32_021B6760 a2, u32_021B6760 a3, u32_021B6760 a4, u32_021B6760 a5, u16 a6);
extern void func_02049B40(u32_021B6760 a, u32_021B6760 b, u32_021B6760 c, u32_021B6760 d, u32_021B6760 e, u16 f);
extern void func_0201DD68(void);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32_021B6760 count, u32_021B6760 workSize);
extern u32_021B6760 func_0201C440(void *p);
extern u32_021B6760 func_02028590(int a, int b, int c, u32_021B6760 d);
extern void func_0201DD78(u32_021B6760 r, u32_021B6760 g, u32_021B6760 b);
extern int func_02028604(int a0);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern unsigned int func_02045C04(struct Rec *rec);
extern unsigned int func_020452E8(struct Descriptor *d);
extern u32_021B6824 func_0201D83C(void *ptr);
extern void func_02031140(struct S02031140 *p);
extern void func_020310C4(struct Tcbl *p);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern unsigned func_0201CE30(void *);
extern s32 func_02028484(struct Blk *blk, void *h);
extern u32_021B687C func_0201C4E4(struct PrintSys *ps);
extern void func_0201F7A8(void *desc, u32_021B68F8 kind);
extern void func_020456F8(struct Descriptor *d);
extern void func_02041B6C(unsigned);
extern void func_0201F73C(void *,int,int,int);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(struct Cfg *cfg);
extern void func_02028470(u8 *p, u32_021B68F8 v);
extern void func_02045334(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern u32_021B68F8 func_020450F0(u32_021B68F8 layer, u32_021B68F8 a, u32_021B68F8 b, u32_021B68F8 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_02045EC0(struct MsgBank *bank, u32_021B6A04 index);
extern struct U16Vec *func_020457B0(u32_021B6A04 capacity, u32_021B6A04 heapId);
extern signed char func_02012FFC(void);
extern unsigned func_0201CCE4(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,u16,u16);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_021B7378(char *);
extern void func_0203064C(unsigned int src, unsigned int dst, unsigned int size);
extern void *func_0203159C(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020124F4(u16);
extern unsigned int func_0203630C(void);
extern void func_021B61C4(unsigned char *),func_02012704(unsigned char *),func_020315D4(struct S020315D4 *),func_020306F0(unsigned int);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern unsigned func_020056EC(unsigned);
extern void func_0204B95C(struct Actor *a);
extern void func_0204B974(struct Actor *a);
extern u32 func_0204B98C(struct Actor *a);
extern u16 func_0204B918(struct Obj *p);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void *func_02049DF4(void *,unsigned,unsigned,unsigned,unsigned short);
extern void func_02082A90(int, int, int);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C724(void *,u32,u32,u32,u32,u32,u16);
void func_021B6100(u8 *p);
void func_021B61C4(u8 *p);
int func_021B622C(u8 *p);
void func_021B63B0(void);
void func_021B63DC(u8 *p);
void func_021B6508(unsigned char *p);
void func_021B6538(const struct BgTemplate *p, int i, int type);
void func_021B655C(char *p);
void func_021B6594(u8 *p);
void func_021B6704(u8 *p, int index);
void func_021B6754(char *p);
void func_021B6760(u8 *p);
void func_021B6824(u8 *p);
void func_021B687C(u8 *p);
int func_021B68E8(char *p);
void func_021B68F8(u8 *p,int mode);
void func_021B6994(u8 *p);
void func_021B6A04(u8 *p, int message);
void func_021B6A90(Obj *o);
void func_021B6AF8(u8 *p);
int func_021B6B5C(char *p);
void func_021B6B8C(char *p);
int func_021B6B94(char *p);
int func_021B6BC4(void *ctx,int unused,char *arg);
int func_021B6C2C(struct S020315D4 *a,unsigned unused,int own,unsigned char *p);
int func_021B6C5C(int a, int b, int c, int d);
char *func_021B6C70(char *p,int index);
void func_021B6D00(unsigned char *unused,char *p);
void func_021B6D3C(u8 *p,u8 *q);
void func_021B6F24(u8 *unused,u8 *q,int unused2);
int func_021B6F2C(int unused, char *p);
void func_021B6F3C(char *p,u8 *q);
void func_021B7004(u8 *p, u8 *q);
void func_021B7180(char *p, char *q, int id);
void func_021B71A0(int a, int *b, int c, int d, int e);
void func_021B71B8(u8 *p,u8 *q);
void func_021B7350(int a, int *p);
unsigned func_021B7360(unsigned char *p);
void func_021B7364(char *p, int v);
extern const u32_021B63DC d_021B7450[],d_021B7388[],d_021B73D0[],d_021B73B0[],d_021B7410[],d_021B7430[],d_021B73F0[];
extern const Config d_020A1448;
extern const Pair_021B6100 d_021B7380[];
extern const Ent g_021B7398[];
extern char d_021B74AC[];
extern char d_021B74BC[];
extern const u8 d_021B7485[],d_021B7481[];
extern const u8 d_021B7484[],d_021B7480[];


void func_021B6100(u8 *p)
{
 struct RtcTime time; unsigned config,lo,mid,hi; u8 i; void *task; unsigned one;
 func_021B63DC(p);
 ((struct Obj01167 *)p)->f18=func_020490F4(131,((struct Obj01167 *)p)->f0);
 func_021B655C((char *)p);func_021B6594(p);func_021B6760(p);
 config=func_02012984(((struct Obj24197 *)(*(u8 * *)&((struct Obj01167 *)p)->f30))->f4);
 lo=func_02011400(config,0);mid=func_02011400(config,2);hi=func_02011400(config,3);
 func_0203F4CC(&time);
 if(time.hour>=lo && time.hour<mid) ((struct Obj01167 *)p)->f10=0;
 else if(time.hour>=mid && time.hour<hi) ((struct Obj01167 *)p)->f10=1;
 else ((struct Obj01167 *)p)->f10=2;
 for(i=0;i<((struct Obj01167 *)p)->f8;i++) *(void **)(p+28+i*4)=func_021B6C70((char *)p,i);
 task=func_020056A0((unsigned)func_021B63B0,(unsigned)p,8);
 one=1;((struct Obj01167 *)p)->fD=one;((struct Obj01167 *)p)->f34=one;
 ((struct Obj01167 *)p)->f4=task;((struct Obj01167 *)p)->f89=0;
 ((struct Obj01167 *)p)->fE=0;((struct Obj01167 *)p)->f14=0;((struct Obj01167 *)p)->f2C=0;((struct Obj01167 *)p)->fC=0;
 func_0203D34C(0,((struct Obj01167 *)p)->f0);
}


void func_021B61C4(u8 *p)
{
    u8 i;
    func_02030EAC(((struct Obj00681 *)p)->f4);
    func_021B6824(p);
    for(i=0;i<((struct Obj00681 *)p)->f8;i++) if(*(void **)(p+28+i*4)) func_021B6D00(p,*(void **)(p+28+i*4));
    func_0204B3B4(((struct Obj00681 *)p)->f54);
    func_0204ADA4((u32_021B61C4)(((struct Obj00681 *)p)->f44));
    func_0204A8D4((u32_021B61C4)(((struct Obj00681 *)p)->f48));
    func_0204AFD8((u32_021B61C4)(((struct Obj00681 *)p)->f4C));
    func_0204B1CC(((struct Obj00681 *)p)->f50);
    func_02049238(((struct Obj00681 *)p)->f18);
    func_021B6508(p);
    func_020307B0(((struct Obj00681 *)p)->f38);
}


static inline void G2_SetBG2Control256x16Affine(GXBGScrSize256x16Pltt size,GXBGAreaOver over,GXBGScrBase scr,GXBGCharBase chr)
{
    *(volatile u16 *)0x0400000C=(u16)((*(volatile u16 *)0x0400000C &0x43)|(size<<14)|(chr<<2)|(scr<<8)|(over<<13));
}


static inline void G2_SetBG3Control256x16Affine(GXBGScrSize256x16Pltt size,GXBGAreaOver over,GXBGScrBase scr,GXBGCharBase chr)
{
    *(volatile u16 *)0x0400000E=(u16)((*(volatile u16 *)0x0400000E &0x43)|(size<<14)|(chr<<2)|(scr<<8)|(over<<13));
}


int func_021B622C(u8 *p)
{
    GXBGCharBase a,b;
    unsigned state;
    u8 i;
    switch(p[12]) {
    case 0:
        func_0202208C(0,1,1,0,6,1,((struct Obj00152 *)p)->f0);
        p[12]=1;
        break;
    case 1:
        if(func_020221A4()==1) p[12]=4;
        break;
    case 2:
        func_0202208C(0,0,0,0,6,1,((struct Obj00152 *)p)->f0);
        p[12]=3;
        break;
    case 3:
        if(func_020221A4()==1) return 1;
        break;
    case 4:
        func_021B6A90((Obj *)p);
        break;
    }
    if(p[14]<20) p[14]++;
    if(*(int *)&((struct Obj00152 *)p)->f2C==0 && ((struct Obj00152 *)p)->f14==4) {
        if(p[13]==0) {a=4;b=10;} else {a=7;b=13;}
        G2_SetBG2Control256x16Affine(SZ1,OVER1,(GXBGScrBase)13,a);
        G2_SetBG3Control256x16Affine(SZ1,OVER1,(GXBGScrBase)14,b);
        p[13]=p[13]==0?1:0;
        ((struct Obj00152 *)p)->f14=0;
        p[14]=0;
    }
    if(*(char * *)&((struct Obj00152 *)p)->f2C!=0 && func_021B6F2C((int)p,*(char * *)&((struct Obj00152 *)p)->f2C)==1)
        *(char * *)&((struct Obj00152 *)p)->f2C=0;
    if(*(int *)&((struct Obj00152 *)p)->f2C==0) {
        state=*(unsigned *)&((struct Obj00152 *)p)->f14;
        switch(state) {
        case 0: case 1: case 2: case 3: {
            u32_021B622C index=(u8)state*4;
            u32_021B622C table=(u32_021B622C)p+28;
            if(*(u8 **)(table+index)!=0) {
                func_021B6F24(p,*(u8 **)(table+index),p[13]);
                *(u8 * *)&((struct Obj00152 *)p)->f2C=*(u8 **)(table+index);
                if(((struct Obj00152 *)p)->f8==2 && ((struct Obj00152 *)p)->f14==1) ((struct Obj00152 *)p)->f14=4;
                else (((struct Obj00152 *)p)->f14)++;
            } else ((struct Obj00152 *)p)->f14=state+1;
            break;
        }
        }
    }
    for(i=0;i<((struct Obj00152 *)p)->f8;i++) {
        if(*(u8 **)(p+28+i*4)!=0) func_021B6D3C(p,*(u8 **)(p+28+i*4));
    }
    func_021B687C(p);
    func_0204A600();
    return 0;
}


void func_021B63B0(void) {func_0204A648();func_02040618(1,0,func_02005728(256));func_02040618(1,3,func_02005728(256));}


/*
 *   one --arm, no region: MATCH, 16 bytes, blocker434CC.log; concrete bytes agree,
 *   unresolved 020434B4 is also omitted from that owner unit's function header.
 *   Scratch copy of owner unit also verifies TU EXACT: blocker434unit.log.
 *   extern void func_0204349C(void),func_020434B4(void);
 *   void func_020434CC(void) {func_0204349C();func_020434B4();}
 *   one --arm, no region: EXACT, 16 bytes, blocker43588.log.
 *   extern void func_02043558(void),func_02043570(void);
 *   void func_02043588(void) {func_02043558();func_02043570();}
 *   retained without an overlay token, ROM pool +0128 names 020A1448.
 * volatile: DISPCNT reads/writes 021B63EE..021B63FE; blend writes 021B6420/6424; POWCNT1 read/write 021B6426..642E.
 */
void func_021B63DC(u8 *p)
{
    Config c;
    func_020434CC();
    func_02043588();
    *(volatile u32_021B63DC *)0x04000000 &= ~0x1F00;
    *(volatile u32_021B63DC *)0x04001000 &= ~0x1F00;
    func_0202223C(0,0);
    func_0202223C(1,0);
    func_02022224(0);
    func_02022224((void *)1);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u16 *)0x04000304 |=0x8000;
    func_020433E0((const struct DispVram *)d_021B7450);
    func_0203F8F4(*(u16 *)p);
    func_02045088(*(u16 *)p);
    func_0203FC28((void *)d_021B7388);
    func_021B6538((const struct BgTemplate *)d_021B73D0,0,0);
    func_021B6538((const struct BgTemplate *)d_021B73B0,1,0);
    func_021B6538((const struct BgTemplate *)d_021B7410,2,2);
    func_021B6538((const struct BgTemplate *)d_021B7430,3,2);
    func_021B6538((const struct BgTemplate *)d_021B73F0,7,0);
    func_02082A7C(0,0x06000000,0x40000);
    c=d_020A1448;
    func_0204A48C((const struct Cfg *)(&c),(u32_021B63DC)d_021B7450,*(u16 *)p);
    func_020434DC(16,1);
    func_02043598(16,1);
    *(void **)(p+80)=func_0204B100(16,0,*(u16 *)p);
    func_0204B270(*(void **)(p+80));
    func_0207D63C((void *)0x04000050,1,30,16,4);
}


void func_021B6508(unsigned char *p) {func_0204A5AC();func_020403F4(7);func_020403F4(3);func_020403F4(2);func_020403F4(1);func_020403F4(0);func_020450C8();func_0203F9B4();}


void func_021B6538(const struct BgTemplate *p, int i, int type) {func_0203FCA0(i,p,type);func_02040588(i,1);func_020414AC(i);func_020409B4(i);}


void func_021B655C(char *p) {unsigned char *q=func_0204A380(((struct Obj03859 *)p)->f18,**(unsigned short * *)&((struct Obj03859 *)p)->f30+62,0,((struct Obj03859 *)p)->f0);((struct Obj03859 *)p)->f38=q;((struct Obj03859 *)p)->f3C=q;((struct Obj03859 *)p)->f40=q+8;if(q[2]==255 && q[3]==255) ((struct Obj03859 *)p)->f8=2;else ((struct Obj03859 *)p)->f8=4;}


void func_021B6594(u8 *p)
{
    int id=37;
    void *save;
    void *arc;
    Spec s;
    if(((struct Obj00545 *)p)->f8!=2) id=38;
    func_020498F4(((struct Obj00545 *)p)->f18,id,2,0,0,0,((struct Obj00545 *)p)->f0);
    func_020498F4(((struct Obj00545 *)p)->f18,id,3,0,0,0,((struct Obj00545 *)p)->f0);
    save=func_02012944(((struct Obj24199 *)(*(u8 * *)&((struct Obj00545 *)p)->f30))->f4);
    arc=func_020490F4(172,((struct Obj00545 *)p)->f0);
    *(int *)&((struct Obj00545 *)p)->f44=func_0204ACEC(arc,3,0,0,((struct Obj00545 *)p)->f0);
    *(int *)&((struct Obj00545 *)p)->f48=func_0204A6C8(arc,24,0,0,((struct Obj00545 *)p)->f0);
    *(int *)&((struct Obj00545 *)p)->f4C=func_0204AF28(arc,20,22,((struct Obj00545 *)p)->f0);
    if(func_02008550(save)==0) func_02049B68(arc,7,4,0,0x60,((struct Obj00545 *)p)->f0);
    else func_02049B68(arc,6,4,0,0x60,((struct Obj00545 *)p)->f0);
    func_02049658(arc,11,7,0,0,0,((struct Obj00545 *)p)->f0);
    func_020498F4(arc,14,7,0,0,0,((struct Obj00545 *)p)->f0);
    func_020409B4(7);
    func_02049B68(arc,0,0,0x160,0x20,((struct Obj00545 *)p)->f0);
    func_02049658(arc,8,1,0,0,0,((struct Obj00545 *)p)->f0);
    func_020498F4(arc,13,1,0,0,0,((struct Obj00545 *)p)->f0);
    func_020413B0(1,0,0,32,32,11);
    func_020409B4(1);
    func_02049238(arc);
    s.a=10; s.b=1; s.x=0;s.y=0;s.z=0;
    ((struct Obj00545 *)p)->f54=func_0204B294((void *)((struct Obj00545 *)p)->f50,((struct Obj00545 *)p)->f48,((struct Obj00545 *)p)->f44,((struct Obj00545 *)p)->f4C,&s,0,((struct Obj00545 *)p)->f0);
    func_0204B3DC(((struct Obj00545 *)p)->f54,0);
    func_0204B92C(((struct Obj00545 *)p)->f54,1);
}


void func_021B6704(u8 *p, int index)
{
    u16 point[2];
    unsigned width;
    unsigned x;
    unsigned y;
    width = func_021B7360(*((void **) ((p + 28) + (index * 4))));
    width = width / 2;
    x = ((d_021B7380[index].x * 8) + 80) + width;
    point[0] = x;
    y = (d_021B7380[index].y * 8) + 16;
    point[1] = y;
    func_0204B404(*((void **) (p + 84)), (const struct Vec2 *)point, 0);
    func_0204B3DC(*((void **) (p + 84)), 1);
    func_0204B9A0(*((void **) (p + 84)));
}


void func_021B6754(char *p) {func_0204B3DC(*(struct Obj * *)&((struct Obj24200 *)p)->f54,0);}



void func_021B6760(u8 *p)
{
    ((struct Obj00918 *)p)->f60 = (u32_021B6760)func_0201D7EC(0x17, 0, 0, 0, ((struct Obj00918 *)p)->f0);
    ((struct Obj00918 *)p)->f68 = (u32_021B6760)func_02045B38(0, 2, 0xc6, ((struct Obj00918 *)p)->f0);
    ((struct Obj00918 *)p)->f6C = (u32_021B6760)func_02045B38(0, 2, (u16)(*(u16 *)(((struct Obj00918 *)p)->f30) + 0xbf), ((struct Obj00918 *)p)->f0);
    func_0201F5BC(0, 1, 0xd, 0, ((struct Obj00918 *)p)->f0);
    func_02049B90(5, func_0201F548(0), 0, 0x20, 0x1a0, 0x20, ((struct Obj00918 *)p)->f0);
    func_02049B40(0x17, 7, 0, 0x180, 0x20, ((struct Obj00918 *)p)->f0);
    func_0201DD68();
    ((struct Obj00918 *)p)->f58 = (u32_021B6760)func_0203101C(((struct Obj00918 *)p)->f0, ((struct Obj00918 *)p)->f0, 3, 0x100);
    ((struct Obj00918 *)p)->f64 = 0;
    ((struct Obj00918 *)p)->f5C = 0;
    ((struct Obj00918 *)p)->f70 = 0;
    ((struct Obj00918 *)p)->f74 = 0;
    ((struct Obj00918 *)p)->f78 = func_0201C440((void *)(((struct Obj00918 *)p)->f0));
    ((struct Obj00918 *)p)->f7C = func_02028590(0xf, 1, 1, ((struct Obj00918 *)p)->f0);
    func_0201DD78(1, 2, 0xf);
}


/*
 * extent: Two zero alignment bytes 021B687A..021B687C.
 */
void func_021B6824(u8 *p)
{
    func_02028604((int)(((struct Obj00681 *)p)->f7C));
    func_0201C4C0(((struct Obj00681 *)p)->f78);
    if(((struct Obj00681 *)p)->f64) func_0201CE48(((struct Obj00681 *)p)->f64);
    if(((struct Obj00681 *)p)->f70) func_02045808(((struct Obj00681 *)p)->f70);
    if(((struct Obj00681 *)p)->f74) func_0201ED04(((struct Obj00681 *)p)->f74);
    func_02045C04(((struct Obj00681 *)p)->f6C);
    func_02045C04(((struct Obj00681 *)p)->f68);
    if(((struct Obj00681 *)p)->f5C) func_020452E8(((struct Obj00681 *)p)->f5C);
    func_0201D83C(((struct Obj00681 *)p)->f60);
    func_02031140(((struct Obj00681 *)p)->f58);
    func_0201DD68();
}


void func_021B687C(u8 *p)
{
    func_020310C4(((struct Obj00152 *)p)->f58);
    if(((struct Obj00152 *)p)->f64) {
        func_020286C4(((struct Obj00152 *)p)->f7C,((struct Obj00152 *)p)->f64,((struct Obj00152 *)p)->f5C);
        if(func_0201CE30(((struct Obj00152 *)p)->f64)!=0) func_021B7364(*(void **)(p+28+((struct Obj00152 *)p)->f88*4),0);
        else func_021B7364(*(void **)(p+28+((struct Obj00152 *)p)->f88*4),1);
        if(func_02028484((struct Blk *)(p+128),((struct Obj00152 *)p)->f64)==1) {
            func_0201CE48(((struct Obj00152 *)p)->f64);
            ((struct Obj00152 *)p)->f64=0;
            func_02045808(((struct Obj00152 *)p)->f70);
            ((struct Obj00152 *)p)->f70=0;
        }
    }
    func_0201C4E4(((struct Obj00152 *)p)->f78);
}



int func_021B68E8(char *p)
{
    return ((struct Obj24201 *)p)->f64 == 0;
}


/*
 * extent: 0x021B6992..0x021B6994 is two zero alignment bytes.
 */
void func_021B68F8(u8 *p,int mode)
{
 void *tmp;
 if(((struct Obj02507 *)p)->f5C){
 func_0201F7A8(((struct Obj02507 *)p)->f5C,1);
 tmp=((struct Obj02507 *)p)->f5C;func_020456F8(tmp);func_02041B6C(func_02045730(tmp));
 func_020452E8(((struct Obj02507 *)p)->f5C);((struct Obj02507 *)p)->f5C=0;
 }
 if(mode==0) ((struct Obj02507 *)p)->f5C=(void *)func_020450F0(0,1,1,30,4,12,1);
 else if(mode==1) ((struct Obj02507 *)p)->f5C=(void *)func_020450F0(0,1,19,30,4,12,1);
 func_0201F73C(((struct Obj02507 *)p)->f5C,1,1,13);
 func_02043B5C(func_02045770(((struct Obj02507 *)p)->f5C),15);
 func_02045334(((struct Obj02507 *)p)->f5C);func_02045374(((struct Obj02507 *)p)->f5C);
 func_02041B6C(0);func_02028470(p+128,6);
}


void func_021B6994(u8 *p)
{
 void *tmp; u8 i;
 if(((struct Obj02218 *)p)->f5C){
 func_0201F7A8(((struct Obj02218 *)p)->f5C,1);tmp=((struct Obj02218 *)p)->f5C;
 func_020456F8(tmp);func_02041B6C(func_02045730(tmp));
 func_020452E8(((struct Obj02218 *)p)->f5C);((struct Obj02218 *)p)->f5C=0;
 }
 if(((struct Obj02218 *)p)->f64){func_0201CE48(((struct Obj02218 *)p)->f64);((struct Obj02218 *)p)->f64=0;}
 if(((struct Obj02218 *)p)->f70){func_02045808(((struct Obj02218 *)p)->f70);((struct Obj02218 *)p)->f70=0;}
 for(i=0;i<((struct Obj02218 *)p)->f8;i++) if(*(int **)(p+28+i*4)) func_021B7350((int)p,*(int **)(p+28+i*4));
}


/*
 * extent: 0x021B6A8E..0x021B6A90 is two zero alignment bytes.
 */
void func_021B6A04(u8 *p, int message)
{
 void *tmp; unsigned speed;
 if(((struct Obj00919 *)p)->f64){func_0201CE48(((struct Obj00919 *)p)->f64);((struct Obj00919 *)p)->f64=0;}
 if(((struct Obj00919 *)p)->f70){func_02045808(((struct Obj00919 *)p)->f70);((struct Obj00919 *)p)->f70=0;}
 func_02043B5C(func_02045770(((struct Obj00919 *)p)->f5C),15);
 ((struct Obj00919 *)p)->f70=func_02045EC0(((struct Obj00919 *)p)->f6C,message);
 if(((struct Obj00919 *)p)->f74){
 tmp=func_020457B0(1024,((struct Obj00919 *)p)->f0);
 func_0201F250(((struct Obj00919 *)p)->f74,tmp,((struct Obj00919 *)p)->f70);
 func_02045808(((struct Obj00919 *)p)->f70);((struct Obj00919 *)p)->f70=tmp;
 }
 speed=func_02012FFC();
 *(unsigned *)&((struct Obj00919 *)p)->f64=func_0201CCE4(*(unsigned *)&((struct Obj00919 *)p)->f5C,0,0,*(unsigned *)&((struct Obj00919 *)p)->f70,((struct Obj00919 *)p)->f60,speed,((struct Obj00919 *)p)->f58,2,((struct Obj00919 *)p)->f0,15);
}



void func_021B6A90(Obj *o)
{
    unsigned int cur = o->steps[o->stepIdx * 4];

    if (o->pending == 1) {
        o->pending = 0;
        g_021B7398[cur].init(o);
    }
    if (g_021B7398[cur].update(o) == 1) {
        unsigned int next;
        o->stepIdx++;
        next = o->steps[o->stepIdx * 4];
        if (next != 0) {
            g_021B7398[next].init(o);
            return;
        }
        o->state = 2;
    }
}


/*
 * lever: Write the table element access twice (tbl[idx].b and tbl[idx].c) with no element pointer local; the index shift then schedules before the table load.
 */
void func_021B6AF8(u8 *p)
{
    u32 a = ((struct P *)p)->tbl[((struct P *)p)->idx].b;
    u32 b = (u8)((struct P *)p)->tbl[((struct P *)p)->idx].c;
    p[0x88] = a;
    func_021B6704(p, a);
    if (a < 2) {
        func_021B68F8(p, 1);
    } else {
        func_021B68F8(p, 0);
    }
    if (*(void **)(p + 0x74) != 0) {
        func_0201ED04(*(void **)(p + 0x74));
    }
    *(void **)(p + 0x74) = func_0201EC64(*(u16 *)p);
    func_0201F02C(*(void **)(p + 0x74), 0, func_02012944(*(void **)(*(u8 **)(p + 0x30) + 4)));
    func_021B6A04(p, b);
}


int func_021B6B5C(char *p)
{
    if(func_021B68E8(p)==1) {
        func_021B6754(p);
        func_021B6994((u8 *)p);
        func_021B7378(*(char **)(p+0x1c+((struct Obj24202 *)p)->f88*4));
        return 1;
    }
    return 0;
}


void func_021B6B8C(char *p)
{
    ((struct Obj24203 *)p)->f8A=0;
}


int func_021B6B94(char *p)
{
    u8 threshold=*(u16 *)(*(char * *)&((struct Obj08268 *)p)->f40+((struct Obj08268 *)p)->f89*4+2);
    ++*(u16 *)&((struct Obj08268 *)p)->f8A;
    if(*(u16 *)&((struct Obj08268 *)p)->f8A>threshold) return 1;
    return 0;
}


int func_021B6BC4(void *ctx,int unused,char *arg)
{
    char *p;
    func_0203064C(1,0x55,0x40000);
    p=func_0203159C(ctx,0x8c,0x55);
    if(arg==0) {
        arg=func_02030734(0x55,8,0,d_021B74AC,0x3b8);
        ((struct Obj10673 *)arg)->f4=func_020124F4(1);
        ((struct Obj10673 *)arg)->f0=1;
        if(func_0203630C() & 0x100) ((struct Obj10673 *)arg)->f0=5;
    }
    ((struct Obj01167 *)p)->f0=0x55;
    *(char * *)&((struct Obj01167 *)p)->f30=arg;
    func_021B6100((u8 *)p);
    return 1;
}


int func_021B6C2C(struct S020315D4 *a,unsigned unused,int own,unsigned char *p) {func_021B61C4(p);if(own==0){func_02012704(*(unsigned char * *)&((struct Obj24204 *)(*(char * *)&((struct Obj00681 *)p)->f30))->f4);func_020307B0(((struct Obj00681 *)p)->f30);}func_020315D4(a);func_020306F0(85);return 1;}



int func_021B6C5C(int a, int b, int c, int d)
{
    return func_021B622C((u8 *)d) == 1;
}


char *func_021B6C70(char *p,int index)
{
    char *q;
    if((*(u8 **)(p+0x3c))[index]==0xff) return 0;
    q=func_02030734(((struct Obj01422 *)p)->f0,0x3c,0,d_021B74BC,0x7a);
    ((struct Obj01759 *)q)->f0=index;
    ((struct Obj01759 *)q)->f2=(*(u8 **)(p+0x3c))[index];
    ((struct Obj01759 *)q)->f3=(*(u8 * *)&((struct Obj01422 *)p)->f3C+index)[4];
    ((struct Obj01759 *)q)->f4=0;
    ((struct Obj01759 *)q)->f5=0;
    ((struct Obj01759 *)q)->f14=0;
    ((struct Obj01759 *)q)->f34=0;
    ((struct Obj01759 *)q)->f30=func_02005728(0x4b);
    if(((struct Obj01759 *)q)->f2==0 && func_02008550((const struct Sub0200852CObj *)func_02012944(((struct Obj24205 *)(*(char * *)&((struct Obj01422 *)p)->f30))->f4))==1) ((struct Obj01759 *)q)->f2=5;
    func_021B7004((u8 *)p,(u8 *)q);
    func_021B6F3C(p,(u8 *)q);
    func_021B71B8((u8 *)p,(u8 *)q);
    ((struct Obj01759 *)q)->f8=0;
    ((struct Obj01759 *)q)->f10=0;
    ((struct Obj01759 *)q)->f6=func_02005728(40);
    ((struct Obj01759 *)q)->f38=0;
    return q;
}


void func_021B6D00(unsigned char *unused,char *p) {func_0204B3B4(*(struct Obj * *)&((struct Obj03860 *)p)->f28);func_0204B3B4(*(struct Obj * *)&((struct Obj03860 *)p)->f2C);func_0204ADA4(((struct Obj03860 *)p)->f1C);func_0204A8D4(((struct Obj03860 *)p)->f20);func_0204AFD8(((struct Obj03860 *)p)->f24);func_020452E8(*(struct Descriptor * *)&((struct Obj03860 *)p)->f18);if(((struct Obj03860 *)p)->f10)func_020307B0(((struct Obj03860 *)p)->f10);func_020307B0(p);}


void func_021B6D3C(u8 *p,u8 *q)
{
    unsigned size;
    unsigned pal;
    unsigned base;
    unsigned step;
    if(((struct Obj00152 *)p)->f8==2) size=0x6000; else size=0x3000;
    if(p[13]==0) pal=0;else pal=0xC000;
    if(((struct Obj00152 *)p)->f8==2) base=0;else base=0x1C00;
    switch(((struct Obj00185 *)q)->f8) {
    case 1:
        q[1]=0;
        func_021B7180((char *)p,(char *)q,q[4]+d_021B7485[q[2]*3]);
        ((struct Obj00185 *)q)->f8=2;
        break;
    case 2:
        step=q[1]*0x3000u;
        func_021B71A0((int)p,(int *)q,base+step,pal+(step+(size*q[0]+0x10000)),0x3000);
        q[1]++;
        if(q[1]*0x3000u>=size) {
            ((struct Obj00185 *)q)->f8=3;
            func_020307B0(((struct Obj00185 *)q)->f10);
            ((struct Obj00185 *)q)->f10=0;
        }
        break;
    case 3:
        q[1]=0;
        func_021B7180((char *)p,(char *)q,(q[5]+d_021B7481[q[3]*2])+(((struct Obj00152 *)p)->f10*2));
        ((struct Obj00185 *)q)->f8=4;
        break;
    case 4:
        step=q[1]*0x3000u;
        func_021B71A0((int)p,(int *)q,base+step,pal+(step+(size*q[0]+0x28000)),0x3000);
        q[1]++;
        if(q[1]*0x3000u>=size) {
            ((struct Obj00185 *)q)->f8=5;
            func_020307B0(((struct Obj00185 *)q)->f10);
            ((struct Obj00185 *)q)->f10=0;
        }
        break;
    case 0:
        break;
    }
    if(q[6]<40) q[6]++;
    else if(((struct Obj00185 *)q)->f8==5 || ((struct Obj00185 *)q)->f8==0) {
        q[6]=0;
        q[4]=q[4]==0?1:0;
        q[5]=q[5]==0?1:0;
    }
    if(((struct Obj00185 *)q)->f14==1 && func_0201C6B4(((struct Obj00152 *)p)->f78)==1) {
        func_02045334(((struct Obj00185 *)q)->f18);
        ((struct Obj00185 *)q)->f14=0;
    }
    ((struct Obj00185 *)q)->f30+=(u16)(func_020056EC(2)+1);
    if(((struct Obj00185 *)q)->f30>=150) {
        func_0204B95C(((struct Obj00185 *)q)->f28);
        func_0204B9A0(((struct Obj00185 *)q)->f28);
        ((struct Obj00185 *)q)->f30=0;
    }
    if(((struct Obj00185 *)q)->f34==1 || ((struct Obj00185 *)q)->f38!=0) {
        if(func_0204B98C(((struct Obj00185 *)q)->f2C)==0) func_0204B95C(((struct Obj00185 *)q)->f2C);
    } else {
        if(func_0204B98C(((struct Obj00185 *)q)->f2C)==1 && func_0204B918(((struct Obj00185 *)q)->f2C)==0)
            func_0204B974(((struct Obj00185 *)q)->f2C);
    }
    if(((struct Obj00185 *)q)->f38!=0) (((struct Obj00185 *)q)->f38)--;
}


/*
 * extent: trailing store-and-return follower 021B6F24 included in this unit; 021B6F2A..021B6F2C is alignment padding.
 */
void func_021B6F24(u8 *unused,u8 *q,int unused2)
{
    ((struct Obj24206 *)q)->f8=1;
}



int func_021B6F2C(int unused, char *p)
{
    return ((struct Obj24207 *)p)->f8 == 5;
}


void func_021B6F3C(char *p,u8 *q)
{
    u8 height=24;
    if(((struct Obj05453 *)p)->f8!=2) height=12;
    func_02049BDC(((struct Obj05453 *)p)->f18,d_021B7484[q[2]*3],2,0,0x4000+q[0]*0x200,0x200,((struct Obj05453 *)p)->f0);
    func_02049BDC(((struct Obj05453 *)p)->f18,((struct Obj05453 *)p)->f10+d_021B7480[q[3]*2],2,0,0x6000+q[0]*0x200,0x200,((struct Obj05453 *)p)->f0);
    func_020413B0(2,(q[0]%2)*16,(q[0]/2)*height,16,height,q[0]);
    func_020413B0(3,(q[0]%2)*16,(q[0]/2)*height,16,height,q[0]);
    func_02041B6C(3);
    func_02041B6C(2);
}


/*
 * prototype: 0204B294 leaves its forwarder's result in r0, captured at
 *   021B712A and 021B715A; the returned object pointer is stored as a word.
 */
void func_021B7004(u8 *p, u8 *q)
{
    int step;
    int base;
    Request req;
    if (((struct Obj01422 *)p)->f8 == 2) { step = 0x6000; base = 0; }
    else { step = 0x3000; base = 0x1c00; }
    func_021B7180((char *)p, (char *)q, (d_021B7481 + 4)[q[2] * 3]);
    func_021B71A0((int)p, (int *)q, base, step * q[0] + 0x10000, step);
    func_020307B0(((struct Obj00476 *)q)->f10);
    func_021B7180((char *)p, (char *)q, d_021B7481[q[3] * 2] + ((struct Obj01422 *)p)->f10 * 2);
    func_021B71A0((int)p, (int *)q, base, step * q[0] + 0x28000, step);
    func_020307B0(((struct Obj00476 *)q)->f10);
    *(int *)&((struct Obj00476 *)q)->f1C = func_0204ACEC(((struct Obj01422 *)p)->f18, (d_021B7481 + 5)[q[2] * 3], 0, (u16)((q[0] * 2 + 4) << 5), ((struct Obj01422 *)p)->f0);
    *(int *)&((struct Obj00476 *)q)->f20 = func_0204A6C8(((struct Obj01422 *)p)->f18, (d_021B7481 + 5)[q[2] * 3] + 1, 0, 0, ((struct Obj01422 *)p)->f0);
    *(int *)&((struct Obj00476 *)q)->f24 = func_0204AF28(((struct Obj01422 *)p)->f18, (d_021B7481 + 5)[q[2] * 3] + 2, (d_021B7481 + 5)[q[2] * 3] + 3, ((struct Obj01422 *)p)->f0);
    req.a = 10; req.b = 1;
    req.x = (q[0] % 2) * 128 + 64;
    req.y = (q[0] / 2) * 96 + 48;
    if (((struct Obj01422 *)p)->f8 == 2) req.y += 56;
    req.id = 0;
    *(u32 *)&((struct Obj00476 *)q)->f28 = (u32)func_0204B294((void *)((struct Obj01422 *)p)->f50, ((struct Obj00476 *)q)->f20, ((struct Obj00476 *)q)->f1C, ((struct Obj00476 *)q)->f24, &req, 0, ((struct Obj01422 *)p)->f0);
    func_0204B3DC(((struct Obj00476 *)q)->f28, 1);
    func_0204B92C(((struct Obj00476 *)q)->f28, 1);
    func_0204B974(((struct Obj00476 *)q)->f28);
    req.id = 1;
    *(u32 *)&((struct Obj00476 *)q)->f2C = (u32)func_0204B294((void *)((struct Obj01422 *)p)->f50, ((struct Obj00476 *)q)->f20, ((struct Obj00476 *)q)->f1C, ((struct Obj00476 *)q)->f24, &req, 0, ((struct Obj01422 *)p)->f0);
    func_0204B3DC(((struct Obj00476 *)q)->f2C, 1);
    func_0204B92C(((struct Obj00476 *)q)->f2C, 1);
    func_0204B974(((struct Obj00476 *)q)->f2C);
}


void func_021B7180(char *p, char *q, int id) {((struct Obj24208 *)q)->f10=func_02049DF4(((struct Obj14322 *)p)->f18,id,0,(unsigned)(q+12),((struct Obj14322 *)p)->f0);}



void func_021B71A0(int a, int *b, int c, int d, int e)
{
    func_02082A90(*(int *)((char *)(((struct Obj24209 *)b)->fC) + 0x14) + c,
                  d + 0x06000000, e);
}


void func_021B71B8(u8 *p,u8 *q)
{
    void *s;
    void *dst;
    void *ws;
    u8 *save;
    *(u32 *)(q+0x18)=func_020450F0(0,(u8)(d_021B7380[q[0]].x+2),(u8)(d_021B7380[q[0]].y+1),12,2,12,1);
    func_02043B5C(func_02045770(*(void **)(q+0x18)),0);
    func_02045334(*(void **)(q+0x18));
    func_02045374(*(void **)(q+0x18));
    func_020409B4(0);
    s=func_02045EC0(*(void **)(p+0x68),q[2]);
    if(q[2]==0 || q[2]==5){
        dst=func_020457B0(128,*(u16 *)p);
        save=func_02012944(*(void **)(*(u8 **)(p+0x30)+4));
        ws=func_0201EC64(*(u16 *)p);
        func_0201F02C(ws,0,save);
        func_0201F250(ws,dst,s);
        func_02045808(s);
        func_0201ED04(ws);
        s=dst;
    }
    q[7]=func_0201D304(s,*(u32 *)(p+0x60),0);
    func_0201C724(*(void **)(p+0x78),(u32)func_02045770(*(void **)(q+0x18)),(s16_021B71B8)((96-q[7])/2+1),1,(u32)s,*(u32 *)(p+0x60),0x3c00);
    func_0201C724(*(void **)(p+0x78),(u32)func_02045770(*(void **)(q+0x18)),(s16_021B71B8)((96-q[7])/2-1),1,(u32)s,*(u32 *)(p+0x60),0x3c00);
    func_0201C724(*(void **)(p+0x78),(u32)func_02045770(*(void **)(q+0x18)),(s16_021B71B8)((96-q[7])/2),2,(u32)s,*(u32 *)(p+0x60),0x3c00);
    func_0201C724(*(void **)(p+0x78),(u32)func_02045770(*(void **)(q+0x18)),(s16_021B71B8)((96-q[7])/2),0,(u32)s,*(u32 *)(p+0x60),0x3c00);
    func_0201C724(*(void **)(p+0x78),(u32)func_02045770(*(void **)(q+0x18)),(s16_021B71B8)((96-q[7])/2),1,(u32)s,*(u32 *)(p+0x60),0x400);
    func_02045808(s);
    *(u32 *)(q+0x14)=1;
}



void func_021B7350(int a, int *p)
{
    func_02045374((struct Cfg *)(((struct Obj24210 *)p)->f18));
    func_02041B6C(0);
}


unsigned func_021B7360(unsigned char *p) {return p[7];}



void func_021B7364(char *p, int v)
{
    if (((struct Obj10674 *)p)->f34 == 1 && v == 0)
        ((struct Obj10674 *)p)->f38 = 0x46;
    ((struct Obj10674 *)p)->f34 = v;
}
