/*
 * file:     irc_ranking.c
 * unit:     yes
 * function: func_021B7560, func_021B7798, func_021B7848, func_021B7890, func_021B78AC, func_021B78B8, func_021B78CC, func_021B78D0, func_021B78D8, func_021B78E0, func_021B7948, func_021B7984, func_021B7BC4, func_021B7D14, func_021B7F00, func_021B7F74, func_021B7F7C, func_021B7F88, func_021B7FC8, func_021B7FE4, func_021B7FEC, func_021B7FF4, func_021B7FF8, func_021B807C, func_021B80A0, func_021B80AC, func_021B80B0, func_021B80BC, func_021B80D0, func_021B8304, func_021B838C, func_021B8408, func_021B84C4, func_021B84D0, func_021B8518, func_021B8524, func_021B8648, func_021B8690, func_021B87B0, func_021B89F4, func_021B8A28, func_021B8A6C, func_021B8AD0, func_021B8B4C, func_021B8B5C, func_021B8B9C, func_021B8D5C, func_021B8D8C, func_021B8D90, func_021B8D9C, func_021B8DA8, func_021B8E50, func_021B8E90, func_021B8FA8, func_021B8FB8, func_021B8FC4, func_021B8FD0, func_021B900C, func_021B9134, func_021B913C, func_021B9198, func_021B91A8, func_021B9298, func_021B92D4, func_021B9360, func_021B9380, func_021B93D8, func_021B93DC, func_021B93E4
 * address:  0x021B7560
 * region:   ov106
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   fill 0x02082BCC arm
 *   func_020120F4 0x020120F4 thumb
 *   func_020124F4 0x020124F4 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02025538 0x02025538 thumb
 *   func_021B70DC 0x021B70DC thumb ov101
 *   func_020490F4 0x020490F4 arm
 *   func_0204ACEC 0x0204ACEC arm
 *   func_02049238 0x02049238 arm
 *   d_021B94D4 0x021B94D4 data a4
 *   func_021B71C0 0x021B71C0 thumb ov101
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_02025588 0x02025588 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02012704 0x02012704 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021B727C 0x021B727C thumb ov101
 *   func_0207CA68 0x0207CA68 arm
 *   d_021B949C 0x021B949C data a4
 *   func_021B7250 0x021B7250 thumb ov101
 *   func_021B71E4 0x021B71E4 thumb ov101
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _ll_mul 0x0209C054 arm
 *   func_0207C768 0x0207C768 arm
 *   _fflt 0x0209BDBC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02049740 0x02049740 arm
 *   func_02049B40 0x02049B40 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02012944 0x02012944 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021B94A8 0x021B94A8 data
 *   d_021B9524 0x021B9524 data a4
 *   func_020452E8 0x020452E8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   d_021B94B8 0x021B94B8 data a4
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   d_021B94F4 0x021B94F4 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_02040618 0x02040618 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_02041300 0x02041300 arm
 *   func_02043678 0x02043678 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201BABC 0x0201BABC thumb
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_020437AC 0x020437AC arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_02049EB4 0x02049EB4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02041090 0x02041090 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200A930 0x0200A930 thumb
 *   func_0200A8E4 0x0200A8E4 thumb
 *   func_0200A908 0x0200A908 thumb
 *   func_02030734 0x02030734 arm
 *   func_02045924 0x02045924 arm
 *   d_021B9680 0x021B9680 data a1
 *   func_02035D20 0x02035D20 arm
 *   func_02035CB8 0x02035CB8 arm
 *   func_020362DC 0x020362DC arm
 *   func_0203630C 0x0203630C arm
 *   func_02035C38 0x02035C38 arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_02045738 0x02045738 arm
 *   func_02045740 0x02045740 arm
 *   func_0201D42C 0x0201D42C thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_020437D4 0x020437D4 arm
 *   func_02082A90 0x02082A90 arm
 *   func_020255A0 0x020255A0 thumb
 *   func_0202570C 0x0202570C thumb
 *   func_021B9414 0x021B9414 thumb ov106
 *   func_0201C724 0x0201C724 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_020257D0 0x020257D0 thumb
 */
#include "../../matched/include/Obj00978.h"
#include "../../matched/include/Obj03744.h"
#include "../../matched/include/Obj22255.h"
#include "../../matched/include/Obj22256.h"
#include "../../matched/include/Obj22257.h"
#include "../../matched/include/Obj13757.h"
#include "../../matched/include/Obj22258.h"
#include "../../matched/include/Obj10252.h"
#include "../../matched/include/Obj10253.h"
#include "../../matched/include/G_BgEntry.h"
#include "../../matched/include/Obj13758.h"
#include "../../matched/include/Obj22261.h"
#include "../../matched/include/Obj05281.h"
#include "../../matched/include/Obj02814.h"
#include "../../matched/include/Obj01710.h"
#include "../../matched/include/Obj22262.h"
#include "../../matched/include/Obj22263.h"
#include "../../matched/include/Obj22264.h"
#include "../../matched/include/Obj01390.h"
#include "../../matched/include/Obj10254.h"
#include "../../matched/include/Obj13760.h"
#include "../../matched/include/Obj22265.h"
#include "../../matched/include/Obj22267.h"
#include "../../matched/include/Obj07991.h"
#include "../../matched/include/Obj22269.h"
#include "../../matched/include/Obj06376.h"
#include "../../matched/include/Obj07992.h"
#include "../../matched/include/Obj10256.h"
#include "../../matched/include/Obj03746.h"
#include "../../matched/include/Obj22271.h"
#include "../../matched/include/Obj10257.h"
#include "../../matched/include/Obj05282.h"

#define SLOT(p,i) (*(u8 **)((u8 *)((u32 *)(p)+(i))+0x62c))
#define SCALE(a) ((int)(((long long)func_0207C768(ROUND(a)-81920,163840)*245760+2048)>>12))
#define H(o) (*(s16_021B8690 *)(p + (o)))
#define W(o) (*(u32 *)(p + (o)))
struct Obj0203159C;
struct Ctx;
struct GfFont;
struct MsgBank;
struct PrintSys;
struct Rec;
struct S020315D4;
struct DispConfig;
struct Descriptor;
struct StrObj;
struct Cfg;
struct CharBuf;
struct U16Vec;
struct Bank;
struct DispVram;
struct Node;
struct WordSet;
struct Bmp;
struct Obj;
struct Obj020437AC;
struct Actor;
struct PtS;
struct Big;
struct Entry;
struct Strbuf;
struct Grid;
struct Param_021B9298;
struct Sys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16_021B7560;

typedef unsigned int u32;

typedef struct { s16_021B7560 x,y; u16 a,b; } Entry;

typedef struct { s16_021B7560 x,y; u16 flags; u8 a,b; } Pos;

typedef short s16_021B78AC;

typedef signed char s8;

typedef int s32;

typedef struct C C;

struct C { void (*callback)(C *, int *, int); int flag, value, arg; };

typedef short s16_021B78D8;

typedef int s32_021B78D8;

typedef signed int     s32_021B78E0;

typedef signed int     s32_021B7948;

typedef signed short s16_021B7984;

typedef struct { int x,y; } Pair_021B7560;

typedef struct { int x,y,z; } Vec_021B7560;

typedef signed short s16_021B7BC4;

struct BgTemplate { u8 bytes[32]; };

typedef struct { u32 bg; struct BgTemplate t; u32 type; } BgEntry;

typedef short s16_021B7F74;

typedef int s32_021B7F74;

typedef short s16_021B7F7C;

typedef int s32_021B7F7C;

typedef short s16;

typedef short s16_021B80AC;

typedef short s16_021B80B0;

typedef signed short s16_021B80D0;

typedef signed short s16_021B838C;

typedef signed short s16_021B8408;

typedef short s16_021B84C4;

typedef signed short s16_021B84D0;

typedef short s16_021B8518;

typedef int s32_021B8518;

typedef signed short s16_021B8524;

typedef signed short s16_021B8690;

typedef signed short s16_021B87B0;

typedef struct {void *text;u32 id:7,value:10,tag:8,seq:7;u16 number;u8 a,b,c,active,pad[2];} Item_021B87B0;

typedef struct {s16_021B87B0 x,y;u16 z;u8 a,b;} Param_021B7560;

typedef signed short s16_021B8A6C;

typedef struct {s16_021B8A6C x,y;} Pair_021B80AC;

typedef struct {
 void *text;
 u32 id:7, value:10, tag:8, seq:7;
 u16 number;
 u8 a,b,c,active,pad[2];
} Item_021B8B9C;

typedef signed int     s32_021B8B9C;

typedef short s16_021B8D8C;

typedef int s32_021B8D8C;

typedef short s16_021B8D90;

typedef int s32_021B8D90;

typedef short s16_021B8D9C;

typedef int s32_021B8D9C;

typedef struct { int x,y; } Pair_021B8E50;

typedef struct { int x, y; } Pair_021B8E90;

typedef struct { long x, y, z; } Vec_021B80AC;

typedef struct {
    Pair_021B8E90 start, end;
    int x, y, dx, dy, count;
    u32 consumed;
    int flags;
} State;

typedef struct { int a,b,v,dirty; } State_021B8FD0;

typedef struct { int a,b,v,d; signed char direction; } State_021B913C;

typedef struct { void *bmp; s16 x,y; int f8,fc;u8 f10,f11;u16 f12;int f14; } Param_021B9298;

extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void fill(void *,int,u32);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_020124F4(u16);
extern u32 func_0201C440(void *);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02025538(unsigned int a0, void *a1);
extern void *func_021B70DC(u32 a, u32 b, u16 layer, u16 x, u8 y, u32 extra, u32 c, u32 d, u16 heap);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02049238(void *);
extern void func_021B71C0(void *);
extern void func_0204ADA4(u32 i);
extern void func_02025588(void *);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02012704(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_02082BCC(void *,unsigned char,unsigned int);
extern void func_0204E720(u32 a, s32_021B78E0 b, s32_021B78E0 c, s32_021B78E0 d);
extern int func_0204E804(void);
extern int func_021B727C(int);
extern int func_021B7250(int *);
extern int func_0207CA68(const Vec_021B7560 *,const Vec_021B7560 *);
extern int func_0207C768(int,int);
extern void func_021B71E4(int a);
extern void func_0203F8F4(u32);
extern void func_02045088(u32);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern unsigned int func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02040C14(u32, u32, u32, u32);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 flags);
extern void func_02049B40(u32, u32, u32, u32, u32, u32);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *, u32);
extern u8 *func_02012944(void *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern void func_020409B4(u32);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_0204335C(u32);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_0201DD60(void);
extern void *func_020056A0(void (*)(void *, u8 *), void *, int);
extern void func_02030EAC(struct Node *n);
extern struct WordSet *func_0201EC64(u32 heap);
extern int func_0201BC3C(void);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_020061E4(u32 a);
extern void func_02041300(u32,int,int,int,u8,u8,u8);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct U16Vec *func_020457B0(int capacity, u16 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C7A4(void *,s16_021B87B0,s16_021B87B0,void *,void *);
extern u32 func_0201BABC(u32,u32,u32,u32);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern int func_0204AF28(void *,u32,u32,u32);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern u32 func_0201BB5C(u32,u32,u32,u32);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
extern void func_020437AC(struct Obj020437AC *);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(void *,Pair_021B80AC *,u16);
extern void *func_02049EB4(u32,u32,u32,u32,u16);
extern u32 func_020307B0(void *p);
extern void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_020413B0(u32,u8,u8,u8,u8,u8);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200A8A0(void *);
extern s32_021B8B9C func_0200A8AC(struct Rec *r);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern u8 func_0200A930(char *p);
extern struct Entry *func_0200A8C8(struct Rec *r, u32 index);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern u8 func_0200A8D0(struct Rec *r, u32 index);
extern u16 func_0200A8E4(struct Rec *r, u32 index);
extern u32 func_0200A8F8(struct Rec *r, u32 index);
extern void func_0200A908(void *,u32,u16 *,u8 *,u8 *,u8 *);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern int func_02035C38(void);
extern void func_0207CA00(const Vec_021B80AC *, const Vec_021B80AC *, Vec_021B80AC *);
extern float _fflt(int);
extern int _ffix(float);
extern float _fadd(float, float);
extern float _fsub(float, float);
extern float _ffltu(u32);
extern u8 func_02045738(struct Descriptor *);
extern u8 func_02045740(struct Descriptor *);
extern u32 func_0201D42C(struct StrObj *,void *);
extern void func_0201F02C(struct WordSet *,u32,void *);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02082A90(const void *src, void *dst, u32 size);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param_021B9298 *param);
extern void func_0202570C(struct Grid *g);
extern void func_021B9414(void *,int,int *);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_020257D0(void *);
int func_021B7560(void *sys,u32 unused,void **args);
int func_021B7798(void *a,int b,int *state,u8 *p);
int func_021B7848(int a, int b, int c, u8 *p);
void func_021B7890(unsigned char *p,unsigned int a,unsigned int b);
void func_021B78AC(void *p);
void func_021B78B8(C *p);
u32 func_021B78CC(u8 *p);
void func_021B78D0(u8 *p, u32 v);
void func_021B78D8(u8 *p);
void func_021B78E0(u8 *a, int *state, u8 *p);
void func_021B7948(u8 *a,int *s);
void func_021B7984(u8 *a,u32 unused,u8 *p);
void func_021B7BC4(u8 *a,u32 unused,u8 *p);
void func_021B7D14(u32 *p, void *arg, u32 heap);
void func_021B7F00(u32 *p);
void func_021B7F74(u8 *a0);
u32 func_021B7F7C(u8 *p, u32 i);
void func_021B7F88(void **p, int a, int b);
void func_021B7FC8(void **p);
void func_021B7FE4(void *a0);
void func_021B7FEC(u8 *a0);
void *func_021B7FF4(void **p);
void func_021B7FF8(u8 *p, void *a, u32 b);
void func_021B807C(u8 *p);
void func_021B80A0(u8 *p);
u32 func_021B80AC(u8 *p);
void *func_021B80B0(u8 *p);
void func_021B80BC(void *a,u8 *p);
void func_021B80D0(u8 *p,u32 a1,u8 a2,u8 a3,u8 s0,u32 s1,void *s2,void *s3,u8 *s4,u16 heap);
void func_021B8304(u8 *p);
void func_021B838C(u8 *p);
void func_021B8408(u8 *p,s16_021B8408 delta);
s16_021B84C4 func_021B84C4(u8 *p);
int func_021B84D0(u8 *p);
s16_021B8518 func_021B8518(u8 *p);
void func_021B8524(u8 *p);
void func_021B8648(u8 *p);
void func_021B8690(void *unused, u8 *p);
void func_021B87B0(u8 *p,const Item_021B87B0 *item,void *sys,u32 first,u32 second,void *msg,u32 font,void *set,void *bg,s16_021B87B0 y1,s16_021B87B0 y2,u16 heap);
void func_021B89F4(u8 *p);
void func_021B8A28(u32 *p,u32 a,u32 b,u16 c);
void func_021B8A6C(u8 *p,int delta);
void func_021B8AD0(u8 *p,u8 *a,u16 b);
void func_021B8B4C(void *p);
void func_021B8B5C(u8 *p, u32 a, int b, u8 c);
void *func_021B8B9C(void *sys,u16 heap);
void func_021B8D5C(u8 *p);
u32 func_021B8D8C(u8 *p);
void func_021B8D90(void *p, u32 heap);
void func_021B8D9C(void *p);
void func_021B8DA8(int *p);
int func_021B8E50(char *p, Pair_021B8E50 *a, Pair_021B8E50 *b, Pair_021B8E50 *c);
int func_021B8E90(State *p, Pair_021B8E90 *start, Pair_021B8E90 *end, Vec_021B80AC *delta, int *count);
void *func_021B8FA8(u8 *p,int *out);
void func_021B8FB8(void *p);
void func_021B8FC4(void *p);
void func_021B8FD0(State_021B8FD0 *p);
void func_021B900C(u8 *p,int amount,int duration);
void func_021B9134(u8 *p);
short func_021B913C(State_021B913C *p);
int func_021B9198(int *p);
void func_021B91A8(struct Descriptor *desc,struct StrObj *text,void *value,u32 font);
void func_021B9298(const struct Bmp *a, const struct Bmp *b, int x, int y, u16 sx, u16 sy, u16 w, u16 h);
void *func_021B92D4(const u8 *pos, u8 a, u8 b, int c, u8 d, int e, void *sys, void *owner, u16 heap);
void func_021B9360(u8 *p);
void func_021B9380(u8 *p,void *a,void *b,int c);
void func_021B93D8(u8 *p, u16 v);
void func_021B93DC(u8 *p, u32 a, u32 b, u32 c);
int func_021B93E4(u8 *p);
extern const Entry d_021B94D4[];
extern const Vec_021B7560 d_021B949C;
extern struct DispConfig d_021B94A8;
extern BgEntry d_021B9524[];
extern char d_021B94B8[];
extern const u8 d_021B94F4[];
extern const char d_021B9680[];







int func_021B7560(void *sys,u32 unused,void **args) {
    u8 *p;
    u32 e;
    void *arc;
    Pos pos;
    int i;
    func_0203064C(1,67,6<<16);
    p=func_0203159C(sys,0x648,67);
    fill(p,0,0x648);
    if(*args)((struct Obj00978 *)p)->f628=func_020120F4(*args);
    else ((struct Obj00978 *)p)->f628=func_020124F4(1);
    *(u32 *)&((struct Obj00978 *)p)->f61C=func_0201C440((void *)67);
    ((struct Obj00978 *)p)->f618=(u32)func_0201D7EC(23,0,0,0,67);
    ((struct Obj00978 *)p)->f620=func_02045B38(0,2,50,67);
    ((struct Obj00978 *)p)->f63C=(unsigned int)func_021B8B9C(((struct Obj00978 *)p)->f628,67);
    func_021B7FF8(p,((struct Obj00978 *)p)->f628,67);
    ((struct Obj00978 *)p)->f624=func_02025538(67,func_021B80B0(p));
    func_021B7890(p+0x28,(unsigned int)p,(u32)func_021B78E0);
    func_021B8D90(p+0x5d4,67);func_021B8FB8(p+0x600);
    e=func_021B80AC(p);
    func_021B80D0(p+0x38,1,2,5,6,e,func_021B80B0(p),((struct Obj00978 *)p)->f620,(u8 *)(((struct Obj00978 *)p)->f63C),67);
    ((struct Obj00978 *)p)->f614=func_021B70DC(2,(u32)func_021B80B0(p),4,13,0,2,((struct Obj00978 *)p)->f618,*(u32 *)&((struct Obj00978 *)p)->f61C,67);
    arc=func_020490F4(23,67);
    ((struct Obj00978 *)p)->f644=func_0204ACEC(arc,5,0,448,67);
    func_02049238(arc);
    fill(&pos,0,8);
    pos.x=8;pos.y=41;pos.a=0;pos.b=0;
    for(i=0;i<4;i++) {
        pos.x=d_021B94D4[i].x;pos.y=d_021B94D4[i].y;
        SLOT(p,i)=func_021B92D4((u8 *)&pos,d_021B94D4[i].a,d_021B94D4[i].b,*(int *)&((struct Obj00978 *)p)->f644,3,0,((struct Obj00978 *)p)->f624,((struct Obj00978 *)p)->f61C,67);
        func_021B93D8(SLOT(p,i),1088);
        func_021B93DC(SLOT(p,i),0,0,1);
        func_021B9380(SLOT(p,i),((struct Obj00978 *)p)->f620,(void *)(i+1),*(int *)&((struct Obj00978 *)p)->f618);
    }
    return 1;
}







int func_021B7798(void *a,int b,int *state,u8 *p)
{
 int i;
 for(i=0;i<4;i++)func_021B9360(*(void **)(p+0x62C+i*4));
 func_0204ADA4((u32)(((struct Obj03744 *)p)->f644));
 func_021B71C0(((struct Obj03744 *)p)->f614);
 func_021B8304(p+0x38);
 func_021B8FC4(p+0x600); func_021B8D9C(p+0x5D4);func_021B78AC(p+0x28);
 func_02025588(((struct Obj03744 *)p)->f624);func_021B807C(p);func_021B8D5C(((struct Obj03744 *)p)->f63C);
 func_02045C04(((struct Obj03744 *)p)->f620);func_0201D83C(((struct Obj03744 *)p)->f618);func_0201C4C0(((struct Obj03744 *)p)->f61C);
 if(*state==0)func_02012704(((struct Obj03744 *)p)->f628);
 func_020315D4(a);func_020306F0(67);return 1;
}







int func_021B7848(int a, int b, int c, u8 *p)
{
    int i;
    func_021B78B8((C *)(p + 0x28));
    func_021B80A0(p);
    func_0201C4E4((struct PrintSys *)(((struct Obj22255 *)p)->f61C));
    for (i = 0; i < 4; i++) func_021B93E4((u8 *)(*(u32 *)(p + 0x62C + i * 4)));
    if (func_021B78CC(p + 0x28)) return 1;
    return 0;
}







void func_021B7890(unsigned char *p,unsigned int a,unsigned int b) { func_02082BCC(p,0,16); ((struct Obj22256 *)p)->fC=a; func_021B78D0(p,b); }







void func_021B78AC(void *p) { func_02082BCC(p, 0, 0x10); }







void func_021B78B8(C *p) { if (p->flag == 0) p->callback(p, &p->value, p->arg); }








u32 func_021B78CC(u8 *p) { return ((struct Obj22257 *)p)->f4; }








void func_021B78D0(u8 *p, u32 v) { ((struct Obj13757 *)p)->f0 = v; ((struct Obj13757 *)p)->f8 = 0; }







void func_021B78D8(u8 *p) { ((struct Obj22258 *)p)->f4 = 1; }






void func_021B78E0(u8 *a, int *state, u8 *p)
{
    switch (*state) {
    case 0: func_0204E720(3,16,0,0); *state = 1; break;
    case 1: if (!func_0204E804()) *state = 2; break;
    case 2:
        if (func_021B84D0(p+0x38) != 65535) func_021B78D0(p+0x28,(u32)func_021B7BC4);
        else func_021B78D0(a,(u32)func_021B7984);
        break;
    }
}






void func_021B7948(u8 *a,int *s) { switch (*s) { case 0: func_0204E720(3,0,16,0); *s=1; break; case 1: if (!func_0204E804()) *s=2; break; case 2: func_021B78D8(a); break; } }






#define ROUND(a) ((int)((a)!=0 ? (float)((a)<<12)+0.5f : (float)((a)<<12)-0.5f))






/*
 * note: Unsigned conversion and ROUND use runtime-proven add C95C/sub CB8C. 8FA8 stores word +28 then tail-calls 3630C; 8E90 reads five inputs, writes Pair_021B7560/Vec_021B7560/word outputs.
 */
void func_021B7984(u8 *a,u32 unused,u8 *p) {
    u32 value;
    Pair_021B7560 pair;
    Vec_021B7560 vec;
    int duration;
    if(!func_021B727C(*(int *)&((struct Obj10252 *)p)->f614)) {
        if(((u32)func_021B8FA8(p+0x5d4,(int *)(&value)))&128) {
            if(ROUND(value)>81920)func_021B900C(p+0x600,SCALE(value),12);
            else func_021B900C(p+0x600,8192,12);
        } else if(((u32)func_021B8FA8(p+0x5d4,(int *)(&value)))&64) {
            if(ROUND(value)>81920)func_021B900C(p+0x600,-SCALE(value),12);
            else func_021B900C(p+0x600,-8192,12);
        } else if(func_021B8E50((char *)(p+0x5d4), (Pair_021B8E50 *)0, (Pair_021B8E50 *)0, (Pair_021B8E50 *)&pair)) {
            func_021B8408(p+0x38,-pair.y);
            func_021B9134(p+0x600);
        } else if(func_021B8E90((State *)(p+0x5d4), (Pair_021B8E90 *)0, (Pair_021B8E90 *)0, (Vec_021B80AC *)&vec, (int *)&duration))
            func_021B900C(p+0x600,func_0207CA68(&d_021B949C,&vec),duration);
    }
    if(func_021B9198((int *)(p+0x600)))func_021B8408((u8 *)(p+0x38), func_021B913C((State_021B913C *)(p+0x600)));
    if(func_021B7250(*(int * *)&((struct Obj10252 *)p)->f614)==1)func_021B78D0(a,(u32)func_021B7948);
    func_021B838C(p+0x38);
    func_021B8DA8((int *)(p+0x5d4));
    func_021B8FD0((State_021B8FD0 *)(p+0x600));
    func_021B71E4(*(u32 *)&((struct Obj10252 *)p)->f614);
}






#undef ROUND





#undef ROUND




#undef ROUND



#undef ROUND


#undef ROUND

#undef ROUND
#define ROUND(a) ((int)((a)>0 ? (float)((a)<<12)+0.5f : (float)((a)<<12)-0.5f))






/*
 * note: The signed-halfword result of 021B913C is already sign-extended by its body. ROUND follows the runtime-confirmed add/subtract mapping.
 */
void func_021B7BC4(u8 *a,u32 unused,u8 *p) {
    int target,current,last;
    target=(s16_021B7BC4)(func_021B84D0(p+0x38)-192);
    if(target<0) target=0;
    current=func_021B84C4(p+0x38);
    last=func_021B8518(p+0x38);
    if((s16_021B7BC4)target>current && current!=last) {
        int n=++((struct Obj10253 *)p)->f640;
        if(ROUND(n)>81920)
            func_021B900C(p+0x600,(int)(((long long)(int)func_0207C768((int)(ROUND(n)-81920),(int)163840)*245760+2048)>>12),12);
        else func_021B900C(p+0x600,8192,12);
    } else {
        func_021B9134(p+0x600);
        func_021B78D0(p+0x28,(u32)func_021B7984);
    }
    if(func_021B9198((int *)(p+0x600))) func_021B8408((u8 *)(p+0x38), func_021B913C((State_021B913C *)(p+0x600)));
    if(func_021B7250(*(int * *)&((struct Obj10253 *)p)->f614)==1)func_021B78D0(a,(u32)func_021B7948);
    func_021B838C(p+0x38);
    func_021B8FD0((State_021B8FD0 *)(p+0x600));
    func_021B71E4((u32)(*(u32 *)&((struct Obj10253 *)p)->f614));
}






void func_021B7D14(u32 *p, void *arg, u32 heap) {
 int i; int k; u32 bg; struct MsgBank *msg; struct GfFont *font; struct StrObj *str;
 func_02082BCC(p, 0, 0x10);
 func_0203F8F4(heap);
 func_02045088(heap);
 func_0203FC28(&d_021B94A8);
 for (i = 0; i < 8; i++) {
  bg = d_021B9524[i].bg;
  func_0203FCA0((u8)bg, &d_021B9524[i].t, (u8)d_021B9524[i].type);
  func_020414AC(bg);
  func_02040588(bg, 1);
 }
 p[0] = (u32)func_020490F4(0x4d, heap);
 func_02049B68((void *)p[0], 0, 0, 0, 0, heap);
 func_02049658((void *)p[0], 1, 3, 0, 0, 0, heap);
 func_02049658((void *)p[0], 3, 0, 0, 0, 0, heap);
 func_020498F4((void *)p[0], 4, 3, 0, 0, 0, heap);
 func_020498F4((void *)p[0], 6, 0, 0, 0, 0, heap);
 func_02049B68((void *)p[0], 0, 4, 0, 0, heap);
 k = 7;
 func_02049658((void *)p[0], 3, 7, 0, 0, 0, heap);
 func_020498F4((void *)p[0], 7, 7, 0, 0, 0, heap);
 func_02040C14(1, 0, 1, 0);
 func_02040C14(5, 0, 1, 0);
 p[1] = func_02049740((void *)p[0], 2, 1, 0, 0, heap);
 p[2] = func_02049740((void *)p[0], 2, 5, 0, 0, heap);
 func_02049B40(0x17, 5, 0, k << 6, 0x20, heap);
 func_02049B40(0x17, 5, 4, k << 6, 0x20, heap);
 func_02049238((void *)p[0]);
 msg = func_02045B38(0, 2, 0x32, heap);
 font = func_0201D7EC(0x17, 0, 0, 0, heap);
 p[3] = func_020450F0(0, 3, 1, 0x1a, (u32)2, (u32)0xe, (u32)1);
 func_02043B5C(func_02045770((struct Descriptor *)p[3]), 0xf);
 str = (struct StrObj *)func_02045EC0(msg, 0);
 func_021B91A8((struct Descriptor *)p[3], str, func_02012944(arg), (u32)font);
 func_02045808((struct U16Vec *)str);
 func_0201D83C(font);
 func_02045C04((struct Rec *)msg);
 func_02045334((struct Descriptor *)p[3]);
 func_02045374((struct Cfg *)p[3]);
 func_020409B4(0);
}






void func_021B7F00(u32 *p) {
    int i;
    func_020452E8((struct Descriptor *)p[3]);
    func_0203FB44((int)1,(u16)p[1],(u16)(p[1]>>16));
    func_0203FB44((int)5,(u16)p[2],(u16)(p[2]>>16));
    func_02040DA8(5,1,0);
    func_02040DA8(1,1,0);
    for(i=0;i<8;i++)func_020403F4((u8)d_021B9524[i].bg);
    func_020450C8();func_0203F9B4();
    func_02082BCC(p,0,16);
}






void func_021B7F74(u8 *a0) { func_020419E4(); }







u32 func_021B7F7C(u8 *p, u32 i) { return i ? ((struct Obj13758 *)p)->f4 : ((struct Obj13758 *)p)->f8; }





void func_021B7F88(void **p, int a, int b) {
    func_02082BCC(p,0,0x14);
    func_0204A48C((const struct Cfg *)d_021B94B8,a,b);
    *p=func_0204B100(128,0,b);
    func_0204B270(*p);
    func_020434DC(16,1);
    func_02043598(16,1);
}





void func_021B7FC8(void **p) { func_0204B1CC(*p); func_0204A5AC(); func_02082BCC(p,0,20); }






/*
 * Tail-call thunk to the ARM function at 0x0204A600.
 */
void func_021B7FE4(void *a0)
{
    func_0204A600();
}





void func_021B7FEC(u8 *a0) { func_0204A648(); }






/*
 * First-word accessor.
 */
void *func_021B7FF4(void **p)
{
    return *p;
}





void func_021B7FF8(u8 *p, void *a, u32 b) {
 func_02082BCC(p,0,0x28);
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 *(volatile unsigned *)0x04000000 &= ~0xe000;
 *(volatile unsigned *)0x04001000 &= ~0xe000;
 func_0204335C(0);
 func_020433E0((const struct DispVram *)d_021B94F4);
 func_0204363C(1);
 func_0204361C();
 func_020434CC();
 func_0201DD60();
 func_021B7D14((u32 *)p,a,b);
 func_021B7F88((void **)(p+0x10),(int)d_021B94F4,b);
 *(void **)(p+0x24)=func_020056A0(func_021B80BC,p,0);
}





void func_021B807C(u8 *p) { func_02030EAC(((struct Obj22261 *)p)->f24); func_021B7FC8((void **)(p+16)); func_021B7F00((u32 *)p); func_02082BCC(p,0,40); }





/*
 * Unblocked by matching func_021B7FE4 in ov106 (pkt_ov106_021B7FE4).
 */
void func_021B80A0(u8 *p) { func_021B7FE4(p + 0x10); }







u32 func_021B80AC(u8 *p) { return (u32)p; }






/*
 * Unblocked by matching func_021B7FF4 in ov106 (pkt_ov106_021B7FF4).
 */
void *func_021B80B0(u8 *p) { return func_021B7FF4((void **)(p + 0x10)); }






void func_021B80BC(void *a,u8 *p) { func_021B7F74(p); func_021B7FEC(p+16); }






/*
 * note 2026-10-05 (final push G8L9): closed. The two zero stores at +0x556/+0x558 are written with
 *   literal 0 and `m = 0;` comes after them, just before the clamp. With `m = 0;` before the calls the
 *   zero joins the clamp's phi web, so -40 was derived from the held 1 (`subs r7,#0x29`) and 1 won the
 *   block-constant register over 0x20. With the literal zero stores the zero stays a plain constant
 *   and -40 is built fresh (`movs r1,#0; subs r1,#0x28`) while 0x20 keeps r7.
 */
void func_021B80D0(u8 *p,u32 a1,u8 a2,u8 a3,u8 s0,u32 s1,void *s2,void *s3,u8 *s4,u16 heap) {
    void *arc;
    int i;
    int m;
    i = 0;
    func_02082BCC(p,0,0x59C);
    *(u32 *)(p+0x54C) = s1;
    *(u8 *)(p+0x548) = a1;
    *(u8 *)(p+0x549) = a2;
    *(u8 *)(p+0x54A) = a3;
    *(u8 *)(p+0x54B) = s0;
    *(u8 **)(p+0x550) = s4;
    *(u16 *)(p+0x554) = func_021B8D8C(s4);
    *(struct GfFont **)(p+0x570) = func_0201D7EC(23,0,0,1,heap);
    *(void **)(p+0x574) = s3;
    *(struct WordSet **)(p+0x588) = func_0201EC64(heap);
    func_021B8AD0(p+8,(u8 *)s1,heap);
    arc = func_020490F4(7,heap);
    *(int *)p = func_0204ACEC(arc,func_0201BC3C(),0,0x20,heap);
    *(int *)(p+4) = func_0204ACEC(arc,func_0201BC3C(),1,0x20,heap);
    func_02049238(arc);
    for (i = 0; i < func_021B8D8C(s4); i++) {
        func_021B87B0(p+0x188+i*32, (const Item_021B87B0 *)(s4+4+i*16), s2, *(u32 *)p, *(u32 *)(p+4), *(void **)(p+0x574), *(u32 *)(p+0x570), *(void **)(p+0x588), p+8, i*24+0x52, i*24-0x70, heap);
    }
    *(u32 *)(p+0x568) = func_020450F0(a2,0,0,0x20,0x20,14,1);
    *(u32 *)(p+0x56C) = func_020450F0(s0,0,0,0x20,0x20,14,1);
    *(s16_021B80D0 *)(p+0x564) = -40;
    *(s16_021B80D0 *)(p+0x566) = 24;
    func_02040618(*(u8 *)(p+0x548),3,*(s16_021B80D0 *)(p+0x564));
    func_02040618(*(u8 *)(p+0x549),3,*(s16_021B80D0 *)(p+0x564));
    func_02040618(*(u8 *)(p+0x54A),3,*(s16_021B80D0 *)(p+0x566));
    func_02040618(*(u8 *)(p+0x54B),3,*(s16_021B80D0 *)(p+0x566));
    *(u16 *)(p+0x556) = 0;
    *(u16 *)(p+0x558) = 0;
    m = 0;
    *(u16 *)(p+0x55A) = *(u16 *)(p+0x554) * 24 - 0x120;
    if (*(s16_021B80D0 *)(p+0x55A) > 0) m = *(s16_021B80D0 *)(p+0x55A);
    *(u16 *)(p+0x55A) = m;
    func_021B8524(p);
    func_021B8648(p);
    *(void **)(p+0x58C) = func_020056A0(func_021B8690, p, 0);
}






void func_021B8304(u8 *p) {
    int i;
    func_02030EAC(((struct Obj05281 *)p)->f58C);
    for(i=0;i<2;i++)func_020452E8(*(void **)((u8 *)((u32 *)p+i)+0x568));
    for(i=0;i<func_021B8D8C(*(u8 * *)&((struct Obj05281 *)p)->f550);i++)func_021B89F4(p+0x188+i*32);
    func_0204ADA4((u32)(((struct Obj05281 *)p)->f0));
    func_0204ADA4((u32)(((struct Obj05281 *)p)->f4));
    func_021B8B4C(p+8);
    func_0201ED04(((struct Obj05281 *)p)->f588);
    func_0201D83C(((struct Obj05281 *)p)->f570);
    func_02082BCC(p,0,0x59c);
}






void func_021B838C(u8 *p) {
    int value;
    if(((struct Obj02814 *)p)->f594==0)return;
    ((struct Obj02814 *)p)->f594=0;
    value=((struct Obj02814 *)p)->f556;
    if(value%24==0) {
        if(((struct Obj02814 *)p)->f55C!=value/24)func_020061E4(1605);
        ((struct Obj02814 *)p)->f55C=((struct Obj02814 *)p)->f556/24;
        ((struct Obj02814 *)p)->f564=-40;
        ((struct Obj02814 *)p)->f566=24;
        func_021B8524(p);
        ((struct Obj02814 *)p)->f590=1;
    } else ((struct Obj02814 *)p)->f598=1;
}






void func_021B8408(u8 *p,s16_021B8408 delta) {
    int old,next;
    int i;
    old=((struct Obj01710 *)p)->f556;
    next=old+delta;
    if(((struct Obj01710 *)p)->f558>next) {
        ((struct Obj01710 *)p)->f556=((struct Obj01710 *)p)->f558;
        ((struct Obj01710 *)p)->f55E=0;
    } else if(((struct Obj01710 *)p)->f55A<next) {
        ((struct Obj01710 *)p)->f556=((struct Obj01710 *)p)->f55A;
        ((struct Obj01710 *)p)->f55E=0;
    } else {
        if(old/24!=next/24 && old%24!=0) {
            if(delta>=0)delta=delta-next%24;
            else delta=delta+(24-next%24);
        }
        ((struct Obj01710 *)p)->f556+=delta;
        ((struct Obj01710 *)p)->f55E=delta;
    }
    for(i=0;i<((struct Obj01710 *)p)->f554;i++)func_021B8A6C(p+0x188+i*32,((struct Obj01710 *)p)->f556);
    ((struct Obj01710 *)p)->f594=1;
}







s16_021B84C4 func_021B84C4(u8 *p) { return ((struct Obj22262 *)p)->f556; }






/*
 * volatile: count halfword re-read at 0x021B84D6 and 0x021B84F4.
 */
int func_021B84D0(u8 *p) {
    int i;
    int found;
    found=0;
    i=0;
    for (; i<*(volatile u16 *)&((struct Obj22263 *)p)->f554; i++) {
        if ((*(u8 **)(p+0x188+i*32))[13] != 0) {found=1; break;}
    }
    if(found) return (s16_021B84D0)(24*i);
    return -1;
}







s16_021B8518 func_021B8518(u8 *p) { return ((struct Obj22264 *)p)->f55A; }






void func_021B8524(u8 *p) {
    int i, y;
    func_02041300(p[0x548],0,0,0,32,24,0);
    func_02041300(p[0x54a],0,0,0,32,24,0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01390 *)p)->f568)),0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01390 *)p)->f56C)),0);
    for (i=((struct Obj01390 *)p)->f55C-1; i<((struct Obj01390 *)p)->f55C+10; i++) {
        if (i>=0 && i<((struct Obj01390 *)p)->f554) {
            y=(i-((struct Obj01390 *)p)->f55C)*3+4;
            if (y>=0 && y<=24)
                func_021B8A28((u32 *)(p+0x188+i*32),((struct Obj01390 *)p)->f568,p[0x548],(u16)y);
        }
    }
    for (i=((struct Obj01390 *)p)->f55C+4; i<((struct Obj01390 *)p)->f55C+17; i++) {
        if (i>=0 && i<((struct Obj01390 *)p)->f554) {
            y=(i-(((struct Obj01390 *)p)->f55C+4))*3;
            if (y>=0 && y<=24)
                func_021B8A28((u32 *)(p+0x188+i*32),((struct Obj01390 *)p)->f56C,p[0x54a],(u16)y);
        }
    }
}






void func_021B8648(u8 *p) {
    int i;
    for(i=0;i<2;i++) {
        func_02045334(*(void **)((u8 *)((unsigned int *)p+i)+0x568));
        func_02045374(*(void **)((u8 *)((unsigned int *)p+i)+0x568));
    }
    func_020409B4(p[0x548]);
    func_020409B4(p[0x54a]);
    func_020409B4(p[0x549]);
    func_020409B4(p[0x54b]);
}






/*
 * Evidence: original signed halfword loads and stores fix scroll widths.
 * ARM9 sub_02040618's legacy fourth input is forwarded only to
 * sub_02042360, whose complete three-input body does not read it;
 * this caller supplies only three inputs, so the unused fourth is omitted.
 */
void func_021B8690(void *unused, u8 *p)
{
    s16_021B8690 step, x, y;
    if (W(0x590)) {
        func_021B8648(p);
        W(0x590) = 0;
        W(0x598) = 1;
    }
    if (W(0x598)) {
        step = H(0x556) % 24;
        if (step == 0) {
            x = H(0x564) + step;
            y = H(0x566) + step;
            H(0x560) = H(0x55e);
            H(0x562) = 1;
        } else {
            if ((H(0x55e) >= 0 && H(0x560) >= 0) ||
                (H(0x55e) < 0 && H(0x560) < 0) || H(0x562) != 0) {
                H(0x562) = 0;
                if (H(0x55e) >= 0) {
                    x = H(0x564) + step;
                    y = H(0x566) + step;
                    H(0x560) = 1;
                } else {
                    x = H(0x564) - (23 - step);
                    y = H(0x566) - (23 - step);
                    H(0x560) = -1;
                }
            } else {
                if (H(0x560) >= 0) {
                    x = H(0x564) + step;
                    y = H(0x566) + step;
                    H(0x560) = 1;
                } else {
                    x = H(0x564) - (23 - step);
                    y = H(0x566) - (23 - step);
                    H(0x560) = -1;
                }
            }
        }
        func_02040618(p[0x548], 3, x);
        func_02040618(p[0x549], 3, x);
        func_02040618(p[0x54a], 3, y);
        func_02040618(p[0x54b], 3, y);
        W(0x598) = 0;
    }
}






/*
 * lever: the r3 and first-stack token parameters and the loop's token local
 *   are full words (u32); as u16 the prologue spill of r3 and the in-arm token
 *   reload scheduled differently (43 bytes).  func_0204B294 takes the word in
 *   its u32 third slot, so no narrowing is visible anywhere.
 */
void func_021B87B0(u8 *p,const Item_021B87B0 *item,void *sys,u32 first,u32 second,void *msg,u32 font,void *set,void *bg,s16_021B87B0 y1,s16_021B87B0 y2,u16 heap) {
 Param_021B7560 cfg; u32 member,mode1,mode2; void *arc; void *a,*b,*c,*text; int i,width; u32 token;
 i=0;
 func_02082BCC(p,0,32);
 *(const Item_021B87B0 **)p=item; *(void **)(p+28)=bg;
 *(void **)(p+4)=func_02043678(32,3,32,heap);
 a=func_020457B0(32,heap); b=func_020457B0(32,heap);
 c=func_020457B0(32,heap); text=func_020457B0(32,heap);
 func_02045CAC(msg,5,a);func_02045CAC(msg,7,b);func_02045CAC(msg,8,c);
 func_0201EFA4(set,0,item->seq,2,0,1);
 func_0201EFA4(set,2,item->id,3,0,1);
 func_0201EFA4(set,3,item->value,3,0,1);
 func_0201F250(set,text,a);
 width=func_0201D304(text,font,0)>>1;
 func_0201C7A4(*(void **)(p+4),38-width,5,text,(void *)font);
 func_0201C7A4(*(void **)(p+4),52,5,item->text,(void *)font);
 func_0201F250(set,text,b);
 width=func_0201D304(text,font,0)>>1;
 func_0201C7A4(*(void **)(p+4),142-width,5,text,(void *)font);
 func_0201F250(set,text,c);
 width=func_0201D304(text,font,0)>>1;
 func_0201C7A4(*(void **)(p+4),194-width,5,text,(void *)font);
 func_02045808(text);func_02045808(c);func_02045808(b);func_02045808(a);
 member=func_0201BABC(item->number,item->a,item->b,item->c);
 mode1=func_0201BC40(); mode2=func_0201BCB4();
 arc=func_020490F4(7,heap);
 *(u32 *)(p+20)=func_0204A6C8(arc,member,0,2,heap);
 *(u32 *)(p+24)=func_0204AF28(arc,mode1,mode2,heap);
 func_02049238(arc);
 func_02082BCC(&cfg,0,8);cfg.z=1;cfg.b=1;
 for(;i<2;i++) {
  u8 *q;
  cfg.x=232;
  if(i==0) {cfg.y=y1;token=first;} else {cfg.y=y2;token=second;}
  *(s16_021B87B0 *)(p+16+i*2)=cfg.y;
  q=p+i*4;
  *(void **)(q+8)=func_0204B294(sys,*(u32 *)(p+20),token,*(u32 *)(p+24),&cfg,i,heap);
  func_0204B6F4(*(void **)(q+8),func_0201BB5C(item->number,item->a,item->b,item->c),0);
  if(cfg.y>-16 && cfg.y<208) func_0204B3DC(*(void **)(q+8),1);
  else func_0204B3DC(*(void **)(q+8),0);
 }
}






void func_021B89F4(u8 *p) { int i; for(i=0;i<2;i++) func_0204B3B4(*(void **)(p+8+i*4)); func_0204A8D4(((struct Obj10254 *)p)->f14); func_0204AFD8(((struct Obj10254 *)p)->f18); func_020437AC(*(struct Obj020437AC * *)&((struct Obj10254 *)p)->f4); func_02082BCC(p,0,32); }






/*
 * extent: two zero padding bytes follow the return, before 0x021B8A6C.
 */
void func_021B8A28(u32 *p,u32 a,u32 b,u16 c) {
    func_021B9298((const struct Bmp *)p[1],(const struct Bmp *)((u32)func_02045770((struct Descriptor *)a)),0,0,0,c,32,3);
    func_021B8B5C((u8 *)p[7],b,c,(*(u32 *)(p[0]+4)<<7)>>24);
}






void func_021B8A6C(u8 *p,int delta) {
    Pair_021B80AC pos;
    int offsets[2];
    int i;
    offsets[0]=-delta;
    offsets[1]=-delta;
    for(i=0;i<2;i++) {
        func_0204B454(*(void **)((u8 *)((unsigned int *)p+i)+8),(struct PtS *)&pos,(u16)i);
        pos.y=offsets[i]+*(s16_021B8A6C *)((u8 *)((s16_021B8A6C *)p+i)+16);
        func_0204B404(*(void **)((u8 *)((unsigned int *)p+i)+8),&pos,i);
        if(pos.y>-16 && pos.y<208) func_0204B3DC(*(void **)((u8 *)((unsigned int *)p+i)+8),1);
        else func_0204B3DC(*(void **)((u8 *)((unsigned int *)p+i)+8),0);
    }
}






/*
 * extent: two zero padding bytes follow the return, before 0x021B8B4C.
 * lever: allocation declared before table keeps allocation in ip and table spilled;
 * table assignments repeat the data source to retain both stores without a reload.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`table=(int)data;` before `table=(int)data+12;`). Game code has no line
 * table, so these were stand-ins. The plain single assignment gives EXACT*
 * in --lang c99 and --lang c: the output bytes do not change. Older text in
 * this header that asks for the double assignment is superseded.
 */
void func_021B8AD0(u8 *p,u8 *a,u16 b) {
    void *data;
    void *allocation;
    int table;
    u16 x,y;
    int i,j;
    func_02082BCC(p,0,384);
    x=func_021B7F7C(a,1);
    y=func_021B7F7C(a,0);
    allocation=func_02049EB4(77,5,0,(u32)&data,b);
    table=(int)data+12;
    for(i=0;i<3;i++) {
        for(j=0;j<32;j++) {
            *(u16 *)(p+i*64+j*2)=*(u16 *)(table+i*64+j*2)+x;
            *(u16 *)(p+i*64+j*2+192)=*(u16 *)(table+i*64+j*2)+y;
        }
    }
    func_020307B0(allocation);
}






void func_021B8B4C(void *p) { func_02082BCC(p,0,384); }






void func_021B8B5C(u8 *p, u32 a, int b, u8 c) {
    if(a>=4) p+=192;
    func_02041090(a,(u32)p,0,(u8)b,32,3);
    func_020413B0(a,0,b,32,3,c);
}






void *func_021B8B9C(void *sys,u16 heap) {
 void *src; u16 count; u8 *out; Item_021B8B9C *item; u32 i; u8 prev,seq,active;
 src=func_0200A8A0(func_02012EBC(sys));
 count=func_0200A8AC(src);
 out=func_02030734(heap,count*16+4,0,d_021B9680,2724);
 func_02082BCC(out,0,count*16+4);
 *(u32 *)out=count;
 if(count) {
  prev=128; seq=0; active=func_0200A930(src);
  for(i=0;i<*(u32 *)out;i++) {
   item=(Item_021B8B9C *)(out+4+i*16);
   item->text=func_020457B0(8,heap);
   func_02045924(item->text,(const u16 *)func_0200A8C8(src,i));
   item->id=func_0200A8D0(src,i);
   item->value=func_0200A8E4(src,i);
   if(item->id<prev) item->seq=i+1;
   else if(item->id==prev) item->seq=seq;
   {
    u8 flag; int v;
    flag=func_0200A8F8(src,i);
    if(active==i) {
     v=flag==0;
     item->tag=5*(v+1);
     item->active=1;
    } else if(item->seq==1) {
     v=0; if(flag==0) v=5; item->tag=v+2;
    } else if(item->seq==2) {
     v=0; if(flag==0) v=5; item->tag=v+3;
    } else if(item->seq==3) {
     v=0; if(flag==0) v=5; item->tag=v+4;
    } else {
     v=0; if(flag==0) v=5; item->tag=v+1;
    }
   }
   func_0200A908(src,i,&item->number,&item->a,&item->b,&item->c);
   prev=item->id; seq=item->seq;
  }
 }
 return out;
}






/*
 * trailing: two-byte alignment padding, no follower.
 */
void func_021B8D5C(u8 *p) { u32 i; if (((struct Obj13760 *)p)->f0 != 0) { for(i=0;i<((struct Obj13760 *)p)->f0;i++) { struct U16Vec *v; v=*(struct U16Vec **)(p+4+i*16); if(v) func_02045808(v); } } func_020307B0(p); }







u32 func_021B8D8C(u8 *p) { return ((struct Obj22265 *)p)->f0; }






void func_021B8D90(void *p, u32 heap) { func_02082BCC(p, 0, 0x2c); }






void func_021B8D9C(void *p) { func_02082BCC(p, 0, 0x2c); }






/*
 * extent: two zero padding bytes follow the return, before 0x021B8E50.
 */
void func_021B8DA8(int *p) {
    int x,y;
    int d;
    if(func_02035D20((u32 *)(&x),(u32 *)(&y))) {
        p[0]=x;p[1]=y;p[2]=x;p[3]=y;p[4]=x;p[5]=y;
        p[6]=0;p[7]=0;p[8]=0;
    } else if(func_02035CB8((u32 *)(&x),(u32 *)(&y))) {
        d=y-p[1];
        if(d<0)d=-d;
        if(d>=1) {
            p[6]=x-p[4];p[7]=y-p[5];p[4]=x;p[5]=y;
        }
        p[2]=x;p[3]=y;p[8]++;p[9]=0;
    } else p[9]++;
    if(func_020362DC()&192) {p[10]=0;return;}
    if(func_0203630C()&192)p[10]++;
}





/*
 * extent: two bytes of alignment padding after the return.
 */
int func_021B8E50(char *p, Pair_021B8E50 *a, Pair_021B8E50 *b, Pair_021B8E50 *c) {
 if (func_02035C38()) {
 if(a) *a=*(Pair_021B8E50 *)p;
 if(b) *b=*(Pair_021B8E50 *)(p+8);
 if(c) *c=*(Pair_021B8E50 *)(p+24);
 return 1;
 }
 return 0;
}





static inline int convert(int v)
{
    float f;
    if (v > 0)
        f = _fadd(0.5f, _fflt((int)((u32)v << 12)));
    else
        f = _fsub(_fflt((int)((u32)v << 12)), 0.5f);
    return _ffix(f);
}





int func_021B8E90(State *p, Pair_021B8E90 *start, Pair_021B8E90 *end, Vec_021B80AC *delta, int *count)
{
    Vec_021B80AC a, b;
    int y;
    if (!func_0203630C()) {
        if (p->consumed < 1) {
            p->consumed = 1;
            if (start)
                *start = p->start;
            if (end)
                *end = p->end;
            if (delta) {
                y = convert(p->start.y);
                a.x = convert(p->start.x);
                a.y = y;
                a.z = 0;
                y = convert(p->end.y);
                b.x = convert(p->end.x);
                b.z = 0;
                b.y = y;
                func_0207CA00(&a, &b, delta);
            }
            if (count)
                *count = p->count;
            return 1;
        }
    }
    return 0;
}





void *func_021B8FA8(u8 *p,int *out) { if(out) *out=((struct Obj22267 *)p)->f28; return (void *)func_0203630C(); }





void func_021B8FB8(void *p) { func_02082BCC(p, 0, 0x14); }




void func_021B8FC4(void *p) { func_02082BCC(p, 0, 0x14); }




/*
 * trailing: two-byte alignment padding, no follower.
 */
void func_021B8FD0(State_021B8FD0 *p) { if(p->dirty) { p->dirty=0; p->v=p->a+p->b/2; p->v=(int)(((long long)p->v*163840+2048)>>12); } }




static inline int magnitude(int v) { return v<0 ? (int)(0u-(u32)v) : v; }




static inline int rounded(int v) {
 if(v!=0) return _ffix(_fadd(0.5f,_ffltu((u32)v<<12)));
 return _ffix(_fsub(_ffltu((u32)v<<12),0.5f));
}




/*
 * note: Compiled code ends 021B9132; handed tail 021B9132..021B9134 is two zero alignment bytes. Unsigned magnitude subtraction and duration shift preserve 32-bit wrap; runtime helpers retain all repeated calls.
 */
void func_021B900C(u8 *p,int amount,int duration) {
 int value;
 if(magnitude(amount)<=4096) return;
 p[16]=amount/magnitude(amount);
 amount=magnitude(amount);
 if(amount>245760) amount=245760;
 else if(amount<4096) amount=4096;
 if(rounded(duration)>=53248) return;
 if(rounded(duration)>53248) value=53248;
 else if(rounded(duration)<0) value=0;
 else value=rounded(duration);
 ((struct Obj07991 *)p)->f0=func_0207C768(amount-4096,241664);
 ((struct Obj07991 *)p)->f4=4096-func_0207C768(value,53248);
 ((struct Obj07991 *)p)->fC=1;
}





void func_021B9134(u8 *p) { ((struct Obj22269 *)p)->f8 = 0; }




short func_021B913C(State_021B913C *p) {
 int v=p->v*p->direction;
 if(v>32768) v=32768; else if(v< -32768) v= -32768;
 p->v -= (int)(((long long)p->v*205+2048)>>12);
 if(p->v> -4096 && p->v<4096) p->v=0;
 return (short)(v>>12);
}




int func_021B9198(int *p) { if(p[2]) return 1; else return 0; }




void func_021B91A8(struct Descriptor *desc,struct StrObj *text,void *value,u32 font) {
 u16 x,y; struct WordSet *set; struct U16Vec *expanded;
 if(!value) {
  x=func_02045738(desc)*4;
  y=func_02045740(desc)*4;
  x-=(u16)(func_0201D304(text,font,0)>>1);
  y-=(u16)(func_0201D42C(text,(void *)font)>>1);
  func_0201C7A4(func_02045770(desc),(s16)x,(s16)y,text,(void *)font);
 } else {
  set=func_0201EC64(0x8043);
  expanded=func_020457B0(128,0x8043);
  func_0201F02C(set,0,value);
  func_0201F250(set,expanded,text);
  x=func_02045738(desc)*4;
  y=func_02045740(desc)*4;
  x-=(u16)(func_0201D304((struct StrObj *)expanded,font,0)>>1);
  y-=(u16)(func_0201D42C((struct StrObj *)expanded,(void *)font)>>1);
  func_0201C7A4(func_02045770(desc),(s16)x,(s16)y,expanded,(void *)font);
  func_02045808(expanded);
  func_0201ED04(set);
 }
}



void func_021B9298(const struct Bmp *a, const struct Bmp *b, int x, int y, u16 sx, u16 sy, u16 w, u16 h) {
    u8 *dst = func_020437D4(a);
    u8 *src = func_020437D4(b);
    func_02082A90(dst + (x + w * y) * 32, src + (sx + w * sy) * 32, w * h * 32);
}



void *func_021B92D4(const u8 *pos, u8 a, u8 b, int c, u8 d, int e, void *sys, void *owner, u16 heap) {
 u8 *p; Param_021B9298 cfg;
 p=func_02030734(heap,36,0,d_021B9680,3402);
 func_02082BCC(p,0,36);
 ((struct Obj06376 *)p)->f20=owner;
 ((struct Obj06376 *)p)->f18=func_020457B0(128,heap);
 ((struct Obj06376 *)p)->f0=func_02043678(a,b,32,heap);
 func_02082BCC(&cfg,0,24);
 cfg.bmp=((struct Obj06376 *)p)->f0;cfg.x=((struct Obj07992 *)pos)->f0;cfg.y=((struct Obj07992 *)pos)->f2;
 cfg.f8=c;cfg.f10=pos[6];cfg.f12=e;cfg.f14=e;cfg.f11=pos[7];cfg.fc=d;
 ((struct Obj06376 *)p)->f1C=func_020255A0(sys,(const struct Param_021B9298 *)(&cfg));
 return p;
}



void func_021B9360(u8 *p) { func_0202570C(((struct Obj10256 *)p)->f1C); func_020437AC(((struct Obj10256 *)p)->f0); func_02045808(((struct Obj10256 *)p)->f18); func_020307B0(p); }



/*
 * extent: two bytes of alignment padding after the return.
 */
void func_021B9380(u8 *p,void *a,void *b,int c) {
 int xy[2];
 func_02043B5C(((struct Obj03746 *)p)->f0,((struct Obj03746 *)p)->f4&31);
 func_02045CAC(a,(u32)b,((struct Obj03746 *)p)->f18);
 func_021B9414(p,c,xy);
 func_0201C724(((struct Obj03746 *)p)->f20,(u32)(((struct Obj03746 *)p)->f0),(short)xy[0],(short)xy[1],(u32)(((struct Obj03746 *)p)->f18),c,((struct Obj03746 *)p)->f4);
 ((struct Obj03746 *)p)->f8=1;
}




void func_021B93D8(u8 *p, u16 v) { ((struct Obj22271 *)p)->f4 = v; }




void func_021B93DC(u8 *p, u32 a, u32 b, u32 c) { ((struct Obj10257 *)p)->fC = a; ((struct Obj10257 *)p)->f10 = b; ((struct Obj10257 *)p)->f14 = c; }



int func_021B93E4(u8 *p) { if(((struct Obj05282 *)p)->f8 && !func_0201C6C4(((struct Obj05282 *)p)->f20,((struct Obj05282 *)p)->f0)){func_020257D0(((struct Obj05282 *)p)->f1C);((struct Obj05282 *)p)->f8=0;} if(!((struct Obj05282 *)p)->f8)return 1; return 0; }
