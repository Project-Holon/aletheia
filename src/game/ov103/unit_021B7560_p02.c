/*
 * file:     unit_021B7560_p02.c
 * unit:     yes
 * function: func_021B795C, func_021B7970, func_021B7AE8, func_021B7B34, func_021B7B3C, func_021B7C08, func_021B7C4C, func_021B7C54, func_021B7C5C, func_021B7C64, func_021B7C68, func_021B7D08, func_021B7D30, func_021B7D44, func_021B7D4C, func_021B7D58, func_021B7DFC, func_021B7EB8, func_021B7F04, func_021B7F4C, func_021B7F50, func_021B7F60, func_021B7F78, func_021B7F7C, func_021B7FC8, func_021B7FF0, func_021B7FFC, func_021B8000, func_021B8004, func_021B8008, func_021B800C, func_021B8074, func_021B80E4, func_021B8100, func_021B8138, func_021B81A4, func_021B824C, func_021B82DC, func_021B831C, func_021B8338, func_021B8348, func_021B8358, func_021B8364, func_021B856C, func_021B8728, func_021B8828, func_021B8A44, func_021B8AF4, func_021B8B1C, func_021B8B38, func_021B8BC0, func_021B8BD8, func_021B8BFC, func_021B8C14, func_021B8C40, func_021B8C4C, func_021B8CA0, func_021B8CB0, func_021B8D54, func_021B8D9C, func_021B8DE4, func_021B8F00, func_021B8FA0, func_021B9060, func_021B9110, func_021B9174, func_021B9184, func_021B91A8, func_021B91B4, func_021B9214
 * address:  0x021B795C
 * region:   ov103
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02049740 0x02049740 arm
 *   func_02049238 0x02049238 arm
 *   func_0207D63C 0x0207D63C arm
 *   d_021B924C 0x021B924C data ov103 a4
 *   d_021B927C 0x021B927C data a4
 *   d_021B9298 0x021B9298 data a4
 *   d_021B9310 0x021B9310 data ov103 a4
 *   func_0203FB44 0x0203FB44 arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B84C 0x0204B84C arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 *   d_020A1448 0x020A1448 data a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204A648 0x0204A648 arm
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   d_021B9228 0x021B9228 data a4
 *   d_021B9234 0x021B9234 data a4
 *   d_021B9240 0x021B9240 data a4
 *   d_021B9218 0x021B9218 data a4
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_020479D8 0x020479D8 arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021B92B4 0x021B92B4 data a4
 *   func_02046E24 0x02046E24 arm
 *   func_02046F50 0x02046F50 arm
 *   func_02046FF8 0x02046FF8 arm
 *   func_02047400 0x02047400 arm
 *   func_0204755C 0x0204755C arm
 *   func_02047564 0x02047564 arm
 *   func_0204767C 0x0204767C arm
 *   func_020477A4 0x020477A4 arm
 *   func_0206E5EC 0x0206E5EC arm
 *   func_0207ADC4 0x0207ADC4 arm
 *   func_02047738 0x02047738 arm
 *   func_0204762C 0x0204762C arm
 *   func_02047504 0x02047504 arm
 *   func_02046EFC 0x02046EFC arm
 *   func_02047910 0x02047910 arm
 *   func_02047828 0x02047828 arm
 *   func_02047A60 0x02047A60 arm
 *   func_02047804 0x02047804 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_020450F0 0x020450F0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045738 0x02045738 arm
 *   func_02045740 0x02045740 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_021B7250 0x021B7250 thumb ov101
 *   func_021B727C 0x021B727C thumb ov101
 *   func_021B9214 0x021B9214 thumb ov103
 *   func_021B7954 0x021B7954 thumb ov103
 *   func_02006210 0x02006210 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021B6480 0x021B6480 thumb ov101
 *   d_021B925C 0x021B925C data a4
 *   d_021B926C 0x021B926C data a4
 *   func_021B630C 0x021B630C thumb ov101
 *   func_021B63CC 0x021B63CC thumb ov101
 *   func_021B6424 0x021B6424 thumb ov101
 *   func_021B72A0 0x021B72A0 thumb ov101
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_02008530 0x02008530 thumb
 *   func_0200A9D4 0x0200A9D4 thumb
 *   func_021B64F0 0x021B64F0 thumb ov101
 *   func_021B9220 0x021B9220 data a4
 *   func_021B6508 0x021B6508 thumb ov101
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_021B64B8 0x021B64B8 thumb ov101
 *   func_02039338 0x02039338 arm
 *   func_0206E0C4 0x0206E0C4 arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CCA4 0x0207CCA4 arm
 *   func_0207CEE4 0x0207CEE4 arm
 *   func_02035D20 0x02035D20 arm
 *   func_02035CB8 0x02035CB8 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021B793C 0x021B793C thumb ov103
 *   func_0204B6F4 0x0204B6F4 arm
 */
#include "../../matched/include/Obj07981.h"
#include "../../matched/include/Obj22180.h"
#include "../../matched/include/Obj22181.h"
#include "../../matched/include/Obj01708.h"
#include "../../matched/include/Obj10241.h"
#include "../../matched/include/Obj10242.h"
#include "../../matched/include/Obj06366.h"
#include "../../matched/include/Obj22183.h"
#include "../../matched/include/Obj10243.h"
#include "../../matched/include/Obj22184.h"
#include "../../matched/include/Obj07982.h"
#include "../../matched/include/Obj22185.h"
#include "../../matched/include/Obj22186.h"
#include "../../matched/include/Obj22187.h"
#include "../../matched/include/Obj22188.h"
#include "../../matched/include/Obj22189.h"
#include "../../matched/include/Obj03231.h"
#include "../../matched/include/Obj13732.h"
#include "../../matched/include/Obj06367.h"
#include "../../matched/include/Obj22190.h"
#include "../../matched/include/Obj02159.h"
#include "../../matched/include/Obj02811.h"
#include "../../matched/include/Obj01388.h"
#include "../../matched/include/Obj10244.h"
#include "../../matched/include/Obj13734.h"
#include "../../matched/include/Obj13735.h"
#include "../../matched/include/Obj22191.h"
#include "../../matched/include/Obj22192.h"
#include "../../matched/include/Obj22194.h"
#include "../../matched/include/Obj22196.h"
#include "../../matched/include/Obj22197.h"
#include "../../matched/include/Obj04428.h"
#include "../../matched/include/Obj22198.h"
#include "../../matched/include/Obj22200.h"
#include "../../matched/include/Obj22201.h"
#include "../../matched/include/Obj13737.h"
#include "../../matched/include/Obj22202.h"
#include "../../matched/include/Obj22203.h"
#include "../../matched/include/Obj03232.h"
#include "../../matched/include/Obj06369.h"
#include "../../matched/include/Obj22204.h"
#include "../../matched/include/Obj22205.h"
#include "../../matched/include/Obj22206.h"
#include "../../matched/include/Obj22207.h"
#include "../../matched/include/Obj22208.h"
#include "../../matched/include/Obj22209.h"
#include "../../matched/include/Obj22210.h"
#include "../../matched/include/Obj04429.h"
#include "../../matched/include/Obj22211.h"
#include "../../matched/include/Obj04430.h"
#include "../../matched/include/Obj07985.h"
#include "../../matched/include/Obj13740.h"
#include "../../matched/include/Obj03741.h"

#define D (*(volatile u16 *)0x04000060)
#define CTX (*(u8 **)(p+0xb0c))
struct BgTemplate;
struct DispConfig;
struct Cfg;
struct Bank;
struct Obj;
struct Rec;
struct AnmCtl;
struct GfFont;
struct MsgBank;
struct WordSet;
struct PrintSys;
struct Descriptor;
struct U16Vec;
struct Big;
struct Ctx;
struct T0200A9A4;
struct Sub0200852CObj;
struct Entry;
struct Link;
struct V3;
struct Pt;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef signed char s8;

typedef int s32;

typedef signed int     s32_021B7B3C;

struct State { void *bank; u32 palette, chars, other; void *actors[33]; };

typedef int s32_021B7C4C;

struct V3 { u32 a, b, c; };

struct Rec { u32 f0; u32 f4; u8 f8; u8 pad9[3]; u32 fC; u16 f10; };

typedef enum { OFFSET_AAC = 0xaac } Offset;

typedef struct {int x,y;} Pair;

typedef struct {Pair point[12];} Line;

typedef struct {Pair origin,end;Line a,b;u32 tail[2];} Block_021B8828;

typedef struct {int words[54];} Block_021B8AF4;

typedef struct {u32 words[54];} Copy;

typedef struct {int x,y,z;} Vec;

typedef struct {Pair origin,end;Line a,b;} Record;

typedef struct {Pair origin,end;Line a,b;u32 tail[2];} Block;

struct Pt { int x, y; };

extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8, u8);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void func_02040C14(u32, u32, u32, u32);
extern u32 func_02049740(void *, u32, u32, u32, u32, u16);
extern void func_02049238(void *);
extern void func_0207D63C(int, int, int, int, int);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02040DA8(int,int,int);
extern void func_020403F4(u8);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void func_02082BCC(void *,u8,u32);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32,u32);
extern void func_02043598(u32,u32);
extern signed int func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32_021B7B3C func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32_021B7B3C func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *,unsigned int);
extern void func_0204B84C(void *,u32);
extern void func_0204B92C(struct Obj *,u32);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(int);
extern void func_0204A8D4(int);
extern void func_0204AFD8(int);
extern int func_0204B1CC(int);
extern void func_0204A5AC(int);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_02046440(int, int, int, int, int, int, void *);
extern int func_02048A24(int, int, int, int, int, int, int, int, void *, void *, void *, int);
extern void func_02048AC4(void *);
extern void func_02046788(void);
extern void func_02047964(void);
extern void func_02048AD0(void *);
extern void func_020479D8(void);
extern void func_02047970(void);
extern void func_0207DC44(int,int,int,int);
extern void func_0207DD24(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void func_02046A94(u32 idx, const u16 *src);
extern void func_02046BE0(u32 a, u32 b);
extern void *func_02046E24(int,u16);
extern int func_02046F50(void *,int);
extern void func_02046FF8(void *);
extern void *func_02047400(void *,unsigned,void *);
extern int *func_0204755C(void *);
extern void *func_02047564(void *,const void *,int);
extern void *func_0204767C(void *,void *,int);
extern void func_020477A4(void *,u16);
extern void func_0206E5EC(int,int);
extern void func_0207ADC4(void *);
extern void func_02047738(struct Rec *p);
extern void func_0204762C(int);
extern void func_02047504(int);
extern void func_02046EFC(int);
extern int func_02047910(void *a, int idx, int amount);
extern void func_02047828(int,int,int *);
extern void func_02047A60(int,void *);
extern u32 func_02047804(struct AnmCtl *c, u16 idx);
extern void func_0201DD60(void);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_02045C04(void *);
extern void func_0201C4C0(void *);
extern void func_0201D83C(void *);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u8 index);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(int,u8);
extern void func_02045CAC(int,int,int);
extern void func_0201C6EC(int);
extern void func_0201C6FC(int,int,s16,s16,int,int);
extern void func_02045808(struct U16Vec *vec);
extern void func_020452E8(void *);
extern int func_0201C6C4(int,int);
extern u8 func_02045738(struct Descriptor *p);
extern int func_02045740(int);
extern int func_0201D304(int,int,int);
extern int func_0201D42C(int,int);
extern void func_0201C724(int,int,s16,s16,int,int,int);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern int func_02045EC0(int,int);
extern void func_0201F250(int,int,int);
extern int func_021B7250(int *);
extern int func_021B727C(int);
extern int func_021B9214(void *);
extern u8 *func_021B7954(u8 *);
extern void func_02006210(void);
extern void func_020061E4(u32);
extern int func_021B6480(int *);
extern int func_021B630C(int *,int);
extern void func_021B63CC(int *,int);
extern int func_021B6424(int);
extern void func_021B72A0(int,int);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200A8A0(void *);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern int func_0200A9D4(struct T0200A9A4 *o, u32 v);
extern void func_021B64F0(void *,int,void *,int,void *);
extern void func_021B6508(void *,int);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern u32 func_021B64B8(u32 p, u32 a, u32 b, u32 c, u8 d, u32 e, u32 f, u32 g);
extern u16 func_02039338(void);
extern void func_0206E0C4(int,int,Vec *,Vec *);
extern void func_0207CA00(Vec *,Vec *,Vec *);
extern void func_0207CCA4(Vec *,Vec *);
extern void func_0207CEE4(int,Vec *,Vec *,Vec *);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern int func_02062B30(void *file, void **out);
extern u8 func_0204169C(int channel);
extern u32 func_0204162C(int channel);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_020413B0(u8,u8,u8,u8,u8,u8);
extern u32 func_020307B0(void *p);
extern void func_02041300(u8,u8,u8,u8,u8,u8,u8);
extern void func_02041B6C(u32 bit);
extern int func_021B793C(u8 *p, int i);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
void func_021B795C(void *unused,u8 *p);
void func_021B7970(u32 *p, u16 heap);
void func_021B7AE8(unsigned *p);
void func_021B7B34(void *a0);
void func_021B7B3C(struct State *p,const void *config,u16 heap);
void func_021B7C08(u8 *p);
void func_021B7C4C(void *a0);
void func_021B7C54(void *a0);
u32 func_021B7C5C(u8 *p,u32 i);
u32 func_021B7C64(u32 *p);
void func_021B7C68(u8 *p, int heap);
void func_021B7D08(u8 *p);
void func_021B7D30(u8 *p);
void func_021B7D44(void *a0);
u8 *func_021B7D4C(u8 *p, u16 i);
void func_021B7D58(void);
void func_021B7DFC(u8 *p, int a, const u16 *t, int c, int a4);
void func_021B7EB8(u8 *p);
void func_021B7F04(u8 *p);
u32 func_021B7F4C(u8 *p);
void func_021B7F50(char *p, struct V3 *q);
void func_021B7F60(u8 *p,int n);
u32 func_021B7F78(u8 *p);
void func_021B7F7C(u32 *p, int skip, u32 heap);
void func_021B7FC8(u8 *p);
u32 func_021B7FF0(u8 *p);
int func_021B7FFC(void *p);
int func_021B8000(void *p);
int func_021B8004(void *p);
int func_021B8008(void *p);
void func_021B800C(struct Rec *p, int a, int b, u8 c, u8 d, u8 e, u8 f, u16 g);
void func_021B8074(u8 *p,int a,int b,u8 c,u8 d,u8 e,u8 f,u16 g,u8 h,u16 i);
void func_021B80E4(u8 *p);
int func_021B8100(u8 *p,u8 *q);
void func_021B8138(u8 *p,void *q,int c,int x,s16 y);
void func_021B81A4(u8 *p,void *q,int c);
void func_021B824C(u8 *p,void *q,int c,u8 *x,s16 y,s16 z,int k);
void func_021B82DC(u8 *a,u8 *b,int c);
void func_021B831C(u8 *p);
void func_021B8338(u32 p,u32 a);
void func_021B8348(u32 p,u32 a,u16 b);
void func_021B8358(u8 *p);
void func_021B8364(u8 *p,u16 *state);
void func_021B856C(u8 *p,u16 *state);
void func_021B8728(u8 *p,u16 *state);
void func_021B8828(u8 *p,u16 *state);
void func_021B8A44(u8 *p,u16 *s);
void func_021B8AF4(u8 *p,void *q);
void func_021B8B1C(u8 *p);
int func_021B8B38(u8 *p,const Block_021B8AF4 *q);
void func_021B8BC0(u8 *p,Copy *q);
void func_021B8BD8(u32 a, u32 b, u32 c, u8 *p, struct Entry *e);
u8 *func_021B8BFC(u32 a,u8 *p);
void func_021B8C14(u8 **p,u8 *q);
void func_021B8C40(void *p);
void func_021B8C4C(u8 **p);
void func_021B8CA0(u8 **p,int i,int v);
void func_021B8CB0(u8 *p,int i,int x,int y);
int func_021B8D54(u32 *p,u32 *out);
int func_021B8D9C(u32 *p,u32 *out);
u8 func_021B8DE4(u8 *p);
u8 func_021B8F00(struct Pt *pa, struct Pt *a, struct Pt *pb, struct Pt *b);
void func_021B8FA0(int a,int b,int c,int d,u8 e,u8 f,u8 g,u8 h,u8 i,u8 j,u8 k,u8 l,u8 m,int n,u16 o);
void func_021B9060(int a,u16 b);
void func_021B9110(u8 *p,void *q,int a,int b,int c,u8 d);
void func_021B9174(void *p);
void func_021B9184(u8 *p, struct Obj *q, int v, u8 w);
void func_021B91A8(void *p);
int func_021B91B4(u8 *p,u32 *rect);
extern u32 d_021B924C[], d_021B927C[], d_021B9298[];
extern const u32 d_021B9310[][8];
extern u32 d_021B927C[];
extern const char d_020A1448[];
extern u8 d_021B9228[];
extern u8 d_021B9234[];
extern u8 d_021B9240[];
extern u8 d_021B9218[];
extern const u8 d_021B92B4[];
extern u32 d_021B925C[];
extern u32 d_021B925C[],d_021B926C[];
extern u8 func_021B9220[];



void func_021B795C(void *unused,u8 *p) { func_021B7B34(p); func_021B7C54(p+204); }



void func_021B7970(u32 *p, u16 heap)
{
    int i;
    u32 layer;
    void *arc;
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)d_021B924C);
    for (i = 0; i < 7; i++) {
        layer = d_021B927C[i];
        func_0203FCA0((u8)layer, (const struct BgTemplate *)d_021B9310[i], (u8)d_021B9298[i]);
        func_020414AC(layer);
        func_02040588(layer, 1);
    }
    arc = func_020490F4(94, heap);
    func_02049B68(arc, 1, 0, 0, 0, heap);
    func_02049B68(arc, 1, 4, 0, 0, heap);
    func_02049B68(arc, 6, 0, 0x120, 0, heap);
    func_02049658(arc, 2, 3, 0, 0, 0, heap);
    func_02049658(arc, 0, 6, 0, 0, 0, heap);
    func_02049658(arc, 48, 4, 0, 0, 0, heap);
    func_02049658(arc, 5, 2, 0, 0, 0, heap);
    func_020498F4(arc, 3, 3, 0, 0, 0, heap);
    func_020498F4(arc, 4, 6, 0, 0, 0, heap);
    func_020498F4(arc, 45, 4, 0, 0, 0, heap);
    func_020498F4(arc, 7, 2, 0, 0, 0, heap);
    func_021B9060(1, heap);
    func_02040C14(5, 0, 1, 0);
    p[0] = func_02049740(arc, 49, 5, 0, 0, heap);
    func_02049238(arc);
    func_0207D63C(0x04000050, 5, 12, 13, 8);
}











void func_021B7AE8(unsigned *p) {int i; *(volatile u16 *)0x04000050=0; func_0203FB44((int)5,(u16)(*p),(u16)(*p>>16)); func_02040DA8(5,1,0); for(i=0;i<7;i++)func_020403F4(d_021B927C[i]); func_020450C8(); func_0203F9B4(); }











void func_021B7B34(void *a0) { func_020419E4(); }











void func_021B7B3C(struct State *p,const void *config,u16 heap)
{
    void *arc;
    int i;
    u16 point[4];
    func_02082BCC(p,0,0x94);
    func_0204A48C((const struct Cfg *)d_020A1448,(u32)config,heap);
    p->bank=func_0204B100(128,0,heap);
    func_0204B270(p->bank);
    func_020434DC(16,1);
    func_02043598(16,1);
    arc=func_020490F4(94,heap);
    p->palette=func_0204ABF0((void *)arc,12,1,0,heap);
    p->chars=func_0204A6C8((void *)((u32)arc),11,0,1,heap);
    p->other=func_0204AF28((void *)((u32)arc),10,9,heap);
    func_02049238(arc);
    func_02082BCC(point,0,8);
    for(i=0;i<32;i++) {
        p->actors[i]=func_0204B294(p->bank,p->chars,p->palette,p->other,point,1,heap);
        func_0204B3DC(p->actors[i],0);
        func_0204B84C(p->actors[i],3);
        func_0204B92C(p->actors[i],1);
        func_0204B878(p->actors[i],0);
    }
}











void func_021B7C08(u8 *p) { int i; for(i=0;i<33;i++) { if(*(int *)(p+16+i*4)) func_0204B3B4((struct Obj *)(*(int *)(p+16+i*4))); } func_0204ADA4(((struct Obj07981 *)p)->f4); func_0204A8D4(((struct Obj07981 *)p)->f8); func_0204AFD8(((struct Obj07981 *)p)->fC); func_0204A5AC(func_0204B1CC(((struct Obj07981 *)p)->f0)); func_02082BCC(p,0,0x94); }











void func_021B7C4C(void *a0) { func_0204A600(); }











void func_021B7C54(void *a0) { func_0204A648(); }











u32 func_021B7C5C(u8 *p,u32 i) { return *(u32 *)(p+i*4+16); }











/*
 * First-word accessor.
 */
u32 func_021B7C64(u32 *p)
{
    return *p;
}











void func_021B7C68(u8 *p, int heap)
{
    void *arc;
    func_02046440(0, 1, 0, 1, 0, heap, (void *)func_021B7D58);
    *(int *)p = func_02048A24(2, 6 << 14, 0xFFFE8000, 0xFFFE0000, 1 << 17, 1 << 12, 250 << 14, 0,
                              d_021B9228, d_021B9234, d_021B9240, heap);
    arc = func_020490F4(0x5e, heap);
    func_021B7DFC(p + 4, (int)arc, (const u16 *)d_021B9218, 1, heap);
    func_021B7DFC(p + 0x64, (int)arc, (const u16 *)d_021B9218, 2, heap);
    func_02049238(arc);
}










/*
 * note: Two-byte zero alignment padding follows the compiled body.
 */
void func_021B7D08(u8 *p) { int i; for(i=0;i<2;i++)func_021B7EB8(p+4+i*0x60); func_02048AC4(((struct Obj22180 *)p)->f0); func_02046788(); }










void func_021B7D30(u8 *p) {func_02047964(); func_02048AD0(((struct Obj22181 *)p)->f0); func_020479D8();}










void func_021B7D44(void *a0) { func_02047970(); }











u8 *func_021B7D4C(u8 *p, u16 i) { return p + 4 + i * 0x60; }










/*
 * note: Full u16 cast around the BG0 priority update preserves the full complement and bics.
 * volatile: DISP3DCNT re-read at 021B7D72, 021B7D7E, 021B7D88, 021B7D92, 021B7D9E.
 */
void func_021B7D58(void) {
 unsigned i;
 func_020434DC(1,1);
 *(volatile u16 *)0x04000008 = (u16)(*(volatile u16 *)0x04000008 & ~3);
 D=(D & ~0x3002)|2;
 D &= (u16)~0x3010;
 D &= (u16)~0x3004;
 D=(D & ~0x3000)|8;
 D &= (u16)~0x3020;
 func_0207DC44(0,0,0,0);
 func_0207DD24(0,0,0x7fff,63,0);
 *(volatile unsigned *)0x04000580=0xbfff0000;
 for(i=0;i<4;i++)func_02046A94((u8)i,(void *)(d_021B92B4+i*8));
 func_02046BE0(1,0);
}










void func_021B7DFC(u8 *p, int a, const u16 *t, int c, int a4) {int i,j; void *d=0; int *q; u8 *e; func_02082BCC(p,0,0x60); ((struct Obj01708 *)p)->f0=func_02046E24(a,t[0]); if(func_02046F50(((struct Obj01708 *)p)->f0,2)){d=((struct Obj01708 *)p)->f0; func_02046FF8(d);} if(func_02046F50(((struct Obj01708 *)p)->f0,1)) { i=0; ((struct Obj01708 *)p)->fC=func_02047400(((struct Obj01708 *)p)->f0,0,d); q=func_0204755C(((struct Obj01708 *)p)->fC); for(;i<2;i++) {e=p+i*4; ((struct Obj10241 *)e)->f4=func_02046E24(a,t[i+1]); ((struct Obj10241 *)e)->f14=func_02047564(((struct Obj01708 *)p)->fC,((struct Obj10241 *)e)->f4,0);} ((struct Obj01708 *)p)->f10=func_0204767C(((struct Obj01708 *)p)->fC,p+20,2); for(j=0;j<2;j++)func_020477A4(((struct Obj01708 *)p)->f10,j); func_0206E5EC(q[1],c); } func_0207ADC4(p+0x34); ((struct Obj01708 *)p)->f28=4096; ((struct Obj01708 *)p)->f2C=4096; ((struct Obj01708 *)p)->f30=4096; }










/*
 * note: 2-byte zero padding before the next labelled function.
 */
void func_021B7EB8(u8 *p) { int i; func_02047738((struct Rec *)(((struct Obj10242 *)p)->f10)); for(i=0;i<2;i++) {if(*(int *)(p+20+i*4))func_0204762C(*(int *)(p+20+i*4));} func_02047504(((struct Obj10242 *)p)->fC); for(i=0;i<2;i++)func_02046EFC(*(int *)(p+4+i*4)); func_02046EFC(((struct Obj10242 *)p)->f0); func_02082BCC(p,0,0x60); }










/*
 * note: Verified against the ov103 Thumb image.
 */
void func_021B7F04(u8 *p) { int i,x,y; if(((struct Obj06366 *)p)->f58) { for(i=0;i<2;i++) func_02047910((void *)(((struct Obj06366 *)p)->f10),(u16)i,4096); func_02047828(((struct Obj06366 *)p)->f10,0,&x); y=0; if(x==0)y=1; ((struct Obj06366 *)p)->f5C=y; func_02047A60(((struct Obj06366 *)p)->f10,p+0x1c); } }











u32 func_021B7F4C(u8 *p) { return ((struct Obj22183 *)p)->f5C; }










void func_021B7F50(char *p, struct V3 *q)
{
    *(struct V3 *)(p + 0x1c) = *q;
}










void func_021B7F60(u8 *p,int n) {if(((struct Obj10243 *)p)->f58!=n) {func_02047804(((struct Obj10243 *)p)->f10,0); ((struct Obj10243 *)p)->f58=n;}}











u32 func_021B7F78(u8 *p) { return ((struct Obj22184 *)p)->f58; }










void func_021B7F7C(u32 *p, int skip, u32 heap)
{
    func_02082BCC(p, 0, 16);
    func_0201DD60();
    if (skip == 0)
        p[0] = (u32)func_0201D7EC(23, 0, 0, 0, heap);
    p[2] = func_0201C440((void *)heap);
    p[1] = (u32)func_02045B38(0, 2, 47, heap);
    p[3] = (u32)func_0201EC64(heap);
}










void func_021B7FC8(u8 *p) {func_0201ED04(((struct Obj07982 *)p)->fC);func_02045C04(((struct Obj07982 *)p)->f4);func_0201C4C0(((struct Obj07982 *)p)->f8);func_0201D83C(((struct Obj07982 *)p)->f0);func_02082BCC(p,0,16);}










u32 func_021B7FF0(u8 *p) { return func_0201C4E4((struct PrintSys *)(((struct Obj22185 *)p)->f8)); }











/*
 * four int getters at +0, +8, +4, +c.
 */
int func_021B7FFC(void *p)
{
    return ((struct Obj22186 *)p)->f0;
}











int func_021B8000(void *p)
{
    return ((struct Obj22187 *)p)->f8;
}











int func_021B8004(void *p)
{
    return ((struct Obj22188 *)p)->f4;
}











int func_021B8008(void *p)
{
    return ((struct Obj22189 *)p)->fC;
}










void func_021B800C(struct Rec *p, int a, int b, u8 c, u8 d, u8 e, u8 f, u16 g)
{
    int q;
    func_02082BCC(p, 0, 20);
    p->f10 = 15;
    p->f0 = func_020450F0(a, b, c, d, e, f, 1);
    p->fC = (u32)func_020457B0(255, g);
    p->f4 = p->f0;
    p->f8 = 0;
    func_021B831C((u8 *)p);
    q = p->f0;
    func_02045334((void *)q);
    func_02045374((struct Cfg *)q);
    func_020409B4(func_02045730((struct Descriptor *)q));
}









/*
 * note: The third register parameter is u8: its full-word spill reload stays after the stack-argument stores.
 */
void func_021B8074(u8 *p,int a,int b,u8 c,u8 d,u8 e,u8 f,u16 g,u8 h,u16 i) {int q; func_02082BCC(p,0,20); ((struct Obj03231 *)p)->f10=g; ((struct Obj03231 *)p)->f0=func_020450F0(a,b,c,d,e,f,h); ((struct Obj03231 *)p)->fC=(int)func_020457B0(255,i); ((struct Obj03231 *)p)->f4=((struct Obj03231 *)p)->f0; p[8]=0; func_02043B5C((int)func_02045770((struct Descriptor *)((struct Obj03231 *)p)->f0),((struct Obj03231 *)p)->f10); q=((struct Obj03231 *)p)->f0; func_02045334((struct Descriptor *)q); func_02045374((struct Cfg *)q); func_020409B4(func_02045730((struct Descriptor *)q)); }









void func_021B80E4(u8 *p) {func_02045808(((struct Obj13732 *)p)->fC);func_020452E8(((struct Obj13732 *)p)->f0);func_02082BCC(p,0,20);}









int func_021B8100(u8 *p,u8 *q) {int a; a=((struct Obj22190 *)q)->f8; if(p[8]!=0) {if(func_0201C6C4(a,(int)func_02045770((struct Descriptor *)((struct Obj06367 *)p)->f4))==0) {func_02045334((struct Descriptor *)((struct Obj06367 *)p)->f4);p[8]=0;}} if(p[8]==0)return 1;return 0;}









void func_021B8138(u8 *p,void *q,int c,int x,s16 y) { int a,b,d; a=func_021B8004(q); b=func_021B8000(q); d=func_021B7FFC(q); func_02043B5C((int)func_02045770((struct Descriptor *)((struct Obj02159 *)p)->f0),((struct Obj02159 *)p)->f10); func_02045CAC(a,c,((struct Obj02159 *)p)->fC); func_0201C6EC(b); func_0201C6FC(b,(int)func_02045770((struct Descriptor *)((struct Obj02159 *)p)->f4),x,y,((struct Obj02159 *)p)->fC,d); p[8]=1; }








/*
 * note: Narrow each dimension after shifting right, then subtract from the u16 coordinates.
 */
void func_021B81A4(u8 *p,void *q,int c) {int a,b,d; u16 x,y; a=func_021B8004(q); b=func_021B8000(q); d=func_021B7FFC(q); func_02043B5C((int)func_02045770((struct Descriptor *)((struct Obj02811 *)p)->f0),((struct Obj02811 *)p)->f10); func_02045CAC(a,c,((struct Obj02811 *)p)->fC); x=func_02045738((struct Descriptor *)(((struct Obj02811 *)p)->f0))*4; y=func_02045740(((struct Obj02811 *)p)->f0)*4; x-=(u16)(func_0201D304(((struct Obj02811 *)p)->fC,d,0)>>1); y-=(u16)(func_0201D42C(((struct Obj02811 *)p)->fC,d)>>1); func_0201C6EC(b); func_0201C724(b,(int)func_02045770((struct Descriptor *)((struct Obj02811 *)p)->f4),x,y,((struct Obj02811 *)p)->fC,d,0x3dc4); p[8]=1; }








void func_021B824C(u8 *p,void *q,int c,u8 *x,s16 y,s16 z,int k) {int a,b,d,e; func_02043B5C((int)func_02045770((struct Descriptor *)((struct Obj02159 *)p)->f0),((struct Obj02159 *)p)->f10); a=func_021B8008(q); b=func_021B8004(q); func_0201F02C((struct WordSet *)a,0,x+12); e=func_02045EC0(b,c); func_0201F250(a,((struct Obj02159 *)p)->fC,e); func_02045808((struct U16Vec *)e); b=func_021B8000(q); d=func_021B7FFC(q); func_0201C6EC(b); func_0201C6FC(b,(int)func_02045770((struct Descriptor *)((struct Obj02159 *)p)->f4),y,z,((struct Obj02159 *)p)->fC,d); p[8]=1; }








void func_021B82DC(u8 *a,u8 *b,int c) { int *p=*(int * *)&((struct Obj01388 *)b)->fB0C; if(p[0])func_021B824C(a,b+0x174,c,(u8 *)p[2],0,0,0x37); else func_021B8138(a,b+0x174,c,0,0); }








void func_021B831C(u8 *p) {func_02043B5C((int)func_02045770((struct Descriptor *)((struct Obj10244 *)p)->f0),((struct Obj10244 *)p)->f10);func_02045334((struct Descriptor *)((struct Obj10244 *)p)->f0);}








void func_021B8338(u32 p,u32 a) {((struct Obj13734 *)p)->f728=a;((struct Obj13734 *)p)->f72C=0;}







void func_021B8348(u32 p,u32 a,u16 b) {((struct Obj13735 *)p)->f728=a;((struct Obj13735 *)p)->f72C=b;}








void func_021B8358(u8 *p) { ((struct Obj22191 *)p)->f730 = 1; }





void func_021B8364(u8 *p,u16 *state)
{
    u32 *pos;
    u8 *q;
    int i;
    pos=(u32 *)(p+0xa3c);
    if(func_021B7250(*(int * *)&((struct Obj01388 *)p)->fA38)==1) {
        ((struct Obj22192 *)(*(u8 * *)&((struct Obj01388 *)p)->fB0C))->fC=1;
        func_021B8358(p);
    } else if(!func_021B727C(*(int *)&((struct Obj01388 *)p)->fA38)) {
        switch(*state) {
        case 0:
            if(func_021B9214(p+0xa4c))
                func_021B8138(p+0x184,p+0x174,17,0,0);
            else if(**(void ** *)&((struct Obj01388 *)p)->fB0C)
                func_021B824C(p+0x184,p+0x174,0,*(u8 * *)&((struct Obj22194 *)(*(u8 * *)&((struct Obj01388 *)p)->fB0C))->f8,0,0,55);
            else func_021B8138(p+0x184,p+0x174,0,0,0);
            q=func_021B7954(p);
            for(i=0;i<2;i++) func_021B8CA0((u8 **)q,i,0);
            func_02006210();
            func_021B9060(1,55);
            ((struct Obj01388 *)p)->f740=0;
            *state=1;
            break;
        case 1:
            if(func_021B8D54(d_021B925C,pos)) {
                func_021B9060(0,55);
                ((struct Obj01388 *)p)->f740=0;
                ((struct Obj01388 *)p)->f744=0;
                q=func_021B7954(p);
                func_021B8CA0((u8 **)q,0,1);
                func_021B8CB0(q,0,pos[0],pos[1]);
                func_020061E4(0x651);
                if(func_021B9214(p+0xa4c)) {
                    func_021B8138(p+0x184,p+0x174,2,0,0);
                    func_021B9060(3,55);
                    func_021B8348((u32)p,(u32)func_021B856C,1);
                } else {
                    if(**(void ** *)&((struct Obj01388 *)p)->fB0C)
                        func_021B824C(p+0x184,p+0x174,1,*(u8 * *)&((struct Obj22196 *)(*(u8 * *)&((struct Obj01388 *)p)->fB0C))->f8,0,0,55);
                    else func_021B8138(p+0x184,p+0x174,1,0,0);
                    func_021B8338((u32)p,(u32)func_021B856C);
                }
            } else if(!func_021B9214(p+0xa4c)) {
                if((((struct Obj01388 *)p)->f740)++>=180) {
                    ((struct Obj01388 *)p)->f740=0;
                    ((struct Obj01388 *)p)->f744^=1;
                    if(((struct Obj01388 *)p)->f744) func_021B82DC(p+0x184,p,11);
                    else func_021B82DC(p+0x184,p,0);
                }
            }
            break;
        }
    }
    if(func_021B6480(*(int * *)&((struct Obj22197 *)(*(u8 * *)&((struct Obj01388 *)p)->fB0C))->f4))
        func_021B8338((u32)p,(u32)func_021B8A44);
}




/*
 * func_021B7250 0x021B7250 thumb ov101
 * func_021B727C 0x021B727C thumb ov101
 * func_021B8358 0x021B8358 thumb ov103
 * func_021B8D9C 0x021B8D9C thumb ov103
 * func_021B91B4 0x021B91B4 thumb ov103
 * func_021B9214 0x021B9214 thumb ov103
 * func_021B91A8 0x021B91A8 thumb ov103
 * func_021B8138 0x021B8138 thumb ov103
 * func_021B824C 0x021B824C thumb ov103
 * func_021B9060 0x021B9060 thumb ov103
 * func_021B7954 0x021B7954 thumb ov103
 * func_021B8CA0 0x021B8CA0 thumb ov103
 * func_021B8CB0 0x021B8CB0 thumb ov103
 * func_021B8338 0x021B8338 thumb ov103
 * func_021B8728 0x021B8728 thumb ov103
 * func_021B8364 0x021B8364 thumb ov103
 * func_021B8A44 0x021B8A44 thumb ov103
 * func_021B6480 0x021B6480 thumb ov101
 * func_020061E4 0x020061E4 thumb
 * d_021B925C 0x021B925C data a4
 * d_021B926C 0x021B926C data a4
 */
void func_021B856C(u8 *p,u16 *state)
{
    u32 xy[2];
    u32 *pos;
    u8 *history,*q;
    pos=(u32 *)(p+0xa44);
    history=p+0xa4c;
    if(func_021B7250(*(int * *)&((struct Obj04428 *)p)->fA38)==1) {
        ((struct Obj22198 *)(*(u8 * *)&((struct Obj04428 *)p)->fB0C))->fC=1;
        func_021B8358(p);
    } else if(!func_021B727C(*(int *)&((struct Obj04428 *)p)->fA38)) {
        switch(*state) {
        case 0:
            if(func_021B8D9C(d_021B925C,xy)) {
                if(func_021B91B4(history,d_021B925C)) {
                    func_021B8138(p+0x184,p+0x174,2,0,0);
                    func_021B9060(3,55);
                    *state=1;
                }
                q=func_021B7954(p);
                func_021B8CA0((u8 **)q,0,1);
                func_021B8CB0(q,0,xy[0],xy[1]);
            } else {
                if(func_021B9214(history)) {
                    func_021B8138(p+0x184,p+0x174,2,0,0);
                    func_021B9060(3,55);
                    *state=1;
                } else func_021B91A8(history);
                *state=2;
            }
            break;
        case 1:
            if(func_021B8D9C(d_021B926C,pos)) {
                func_021B9060(0,55);
                if(**(void ** *)&((struct Obj04428 *)p)->fB0C)
                    func_021B824C(p+0x184,p+0x174,1,*(u8 * *)&((struct Obj22200 *)(*(u8 * *)&((struct Obj04428 *)p)->fB0C))->f8,0,0,55);
                else func_021B8138(p+0x184,p+0x174,1,0,0);
                func_021B8338((u32)p,(u32)func_021B8728);
                q=func_021B7954(p);
                func_021B8CA0((u8 **)q,1,1);
                func_021B8CB0(q,1,pos[0],pos[1]);
                func_020061E4(0x656);
            } else if(!func_021B8D9C(d_021B925C,xy)) *state=2;
            break;
        case 2:
            (((struct Obj04428 *)p)->f738)++;
            func_021B8338((u32)p,(u32)func_021B8364);
            break;
        }
    }
    if(func_021B6480(*(int * *)&((struct Obj22201 *)(*(u8 * *)&((struct Obj04428 *)p)->fB0C))->f4))
        func_021B8338((u32)p,(u32)func_021B8A44);
}



/*
 * lever: grouped offset sums retain the original off/state colors; signed conversion of an unsigned second offset calculation prevents unwanted common subexpression retention.
 * permuter: historical types300 consumed; never repeated in wave77.
 * behavior: off/tmp/tmp1 assigned before uses; original supported callback order retained; out point fields read only after8D9C success and both initialized by that body. No new volatile or narrowed pointers.
 */
void func_021B8728(u8 *p,u16 *state)
{
    struct { int x,y; } point;
    Offset off;
    Offset tmp;
    u8 *tmp1;
    off=OFFSET_AAC;
    if(func_021B7250(*(int **)(p+(off-0x74)))==1) {
        tmp=(Offset)off;
        tmp1=*(u8 **)(p+(tmp+0x60))+12;
        ((struct Obj22202 *)tmp1)->f0=1;
        func_021B8358(p);
    } else if(func_021B727C(*(int *)(p+(int)((u32)off-0x74)))==0) {
        switch(*state) {
        case 0: {
            void *obj;
            if(func_021B8D9C(d_021B926C,(u32 *)&point)) {
                if(func_021B91B4(p+off,d_021B926C)) {
                    func_021B8138(p+0x184,p+0x174,3,0,0);
                    func_020061E4(0x654);
                    func_021B8338((u32)p,(u32)func_021B8828);
                }
                if(off) {}
                obj=func_021B7954(p);
                func_021B8CA0(obj,1,1);
                func_021B8CB0(obj,1,point.x,point.y);
            } else {
                obj=func_021B7954(p);
                func_021B8CA0(obj,1,0);
                func_021B91A8(p+off);
                *state=1;
            }
            break;
        }
        case 1:
            (((struct Obj13737 *)p)->f738)++;
            func_021B8338((u32)p,(u32)func_021B8364);
            break;
        }
    }
    if(func_021B6480(*(int * *)&((struct Obj22203 *)(*(u8 * *)&((struct Obj13737 *)p)->fB0C))->f4))
        func_021B8338((u32)p,(u32)func_021B8A44);
}





void func_021B8828(u8 *p,u16 *state) {
 Block_021B8828 ref; Block_021B8828 cur;
 if(*state<5 && func_021B7250(*(int * *)&((struct Obj03232 *)p)->fA38)==1) {
  *(u32 *)(CTX+12)=1; func_021B8358(p); return;
 }
 switch(*state) {
 case 0: if(func_021B630C(*(int **)(CTX+4),4)) *state=1; break;
 case 1: func_021B8138(p+0x184,p+0x174,4,0,0); *state=2; break;
 case 2:
  ref.origin=*(Pair *)(p+0xa3c);
  ref.end=*(Pair *)(p+0xa44);
  ref.a=*(Line *)(p+0xa4c);
  ref.b=*(Line *)(p+0xaac);
  ref.tail[0]=((struct Obj03232 *)p)->f738;
  if(*(void **)CTX) {
   void *src;
   src=func_0200A8A0(func_02012EBC(func_020120F4(*(void **)CTX)));
   ref.tail[1]=func_0200A9D4(src,func_02008530((const struct Sub0200852CObj *)(*(u8 **)(CTX+8)+12)))==0;
  }
  if(func_021B8B38(p+0x75c, (const Block_021B8AF4 *)&ref)) *state=3; break;
 case 3:
  func_021B63CC(*(int **)(CTX+4),3);
  if(func_021B6424(*(int *)(CTX+4))) *state=4; break;
 case 4:
  if(func_021B630C(*(int **)(CTX+4),5)) {
   func_021B72A0(*(int *)&((struct Obj03232 *)p)->fA38,0); *state=5;
  } break;
 case 5:
  if(((struct Obj03232 *)p)->f72E>=60) {
   func_020061E4(0x64b);func_021B8138(p+0x184,p+0x174,5,0,0);
   ((struct Obj03232 *)p)->f73C=0; *state=6;
  } break;
 case 6:
  if((((struct Obj03232 *)p)->f73C)++<30) return;
  CTX[0x10]=func_021B8DE4(p);
  func_021B8BC0(p+0x75c, (Copy *)((Block_021B8828 *)&cur));
  CTX[0x11]=((struct Obj03232 *)p)->f738+cur.tail[0];
  CTX[0x12]=cur.tail[1];
  *(u32 *)(CTX+12)=0;*state=7;return;
 case 7:func_021B8358(p);return;
 }
 if(*state<3 && func_021B6480(*(int **)(CTX+4))) func_021B8338((u32)p,(u32)func_021B8A44);
 if(*state>=1 && *state<=5) { if(((struct Obj03232 *)p)->f72E<=60) ++((struct Obj03232 *)p)->f72E; }
}





void func_021B8A44(u8 *p,u16 *s) {
 switch(*s) {
 case 0:
  if(func_021B6480(*(int * *)&((struct Obj22204 *)(*(u8 * *)&((struct Obj06369 *)p)->fB0C))->f4)>0)*s=1;
  else if(func_021B6480(*(int * *)&((struct Obj22205 *)(*(u8 * *)&((struct Obj06369 *)p)->fB0C))->f4)<0) {(*(u8 **)(p+0xb0c))[16]=0;((struct Obj22206 *)(*(u8 * *)&((struct Obj06369 *)p)->fB0C))->fC=2;func_021B8358(p);}
  break;
 case 1:(*(u8 **)(p+0xb0c))[16]=0;((struct Obj22207 *)(*(u8 * *)&((struct Obj06369 *)p)->fB0C))->fC=2;*s=2;break;
 case 2:func_021B8138(p+0x184,p+0x174,6,0,0);*s=3;break;
 case 3:if(func_021B630C(*(int * *)&((struct Obj22208 *)(*(u8 * *)&((struct Obj06369 *)p)->fB0C))->f4,6))*s=4;break;
 case 4:func_021B8358(p);break;
 }
}





void func_021B8AF4(u8 *p,void *q) {func_02082BCC(p,0,0x294);((struct Obj22209 *)p)->f0=q;func_021B64F0(q,0xe00,func_021B9220,1,p);}





void func_021B8B1C(u8 *p) {func_021B6508(((struct Obj22210 *)p)->f0,0xe00);func_02082BCC(p,0,0x294);}





int func_021B8B38(u8 *p,const Block_021B8AF4 *q) {
 switch(((struct Obj04429 *)p)->f4) {
 case 0: *(Block_021B8AF4 *)(p+0x1b8)=*q;((struct Obj04429 *)p)->f4=1;break;
 case 1:
  if(func_021B64B8(((struct Obj04429 *)p)->f0,0xe00,0xd8,(u32)(p+0x1b8),(u8)(func_0203D1A4((struct Link *)((int)func_020399A8()))==0),0,0,1))((struct Obj04429 *)p)->f4=2;
  break;
 case 2:
  if(((struct Obj04429 *)p)->f290) {((struct Obj04429 *)p)->f290=0;((struct Obj04429 *)p)->f4=0;return 1;}
  break;
 }
 return 0;
}




void func_021B8BC0(u8 *p,Copy *q) {*q=*(Copy *)(p+8);}




/*
 * extent: two zero alignment bytes follow compiled code.
 */
void func_021B8BD8(u32 a, u32 b, u32 c, u8 *p, struct Entry *e) { if(e == func_020399A8()) { if(a != func_02039338()) ((struct Obj22211 *)p)->f290=1; } }




u8 *func_021B8BFC(u32 a,u8 *p) { if(a == func_02039338()) p += 0xe0; else p += 8; return p; }




void func_021B8C14(u8 **p,u8 *q) { int i; func_02082BCC(p,0,16); for(i=0;i<2;i++) { p[i]=func_021B7D4C(q,i); func_021B7F60(p[i],0); } }




void func_021B8C40(void *p) { func_02082BCC(p, 0, 0x10); }




void func_021B8C4C(u8 **p) {
 int i;
 for(i=0;i<2;i++)func_021B7F04(p[i]);
 if(func_021B7F78(p[0]) && func_021B7F4C(p[0]))func_020061E4(0x651);
 if(func_021B7F78(p[1]) && func_021B7F4C(p[1]))func_020061E4(0x656);
}




void func_021B8CA0(u8 **p,int i,int v) { func_021B7F60(p[i],v); }




void func_021B8CB0(u8 *p,int i,int x,int y) {
 Vec a,b,c;
 switch(i) {
 case 0:
  func_0206E0C4(x,y,&a,&b);func_0207CA00(&b,&a,&c);func_0207CCA4(&c,&c);func_0207CEE4(0x40000,&c,&a,&a);func_021B7F50(*(void **)(p+i*4),(struct V3 *)(&a));((struct Obj04430 *)p)->f8=x;((struct Obj04430 *)p)->fC=y;break;
 case 1:
  func_0206E0C4(((struct Obj04430 *)p)->f8+(x-((struct Obj04430 *)p)->f8)*2,((struct Obj04430 *)p)->fC+(y-((struct Obj04430 *)p)->fC)*2,&a,&b);func_0207CA00(&b,&a,&c);func_0207CCA4(&c,&c);func_0207CEE4(0x40000,&c,&a,&a);func_021B7F50(*(void **)(p+i*4),(struct V3 *)(&a));break;
 }
}




int func_021B8D54(u32 *p,u32 *out) {
 u32 x,y;
 if(func_02035D20(&x,&y)) {
  if(x-p[0]<p[2]-p[0] && y-p[1]<p[3]-p[1]) {
   if(out) {out[0]=x;out[1]=y;}
   return 1;
  }
 }
 return 0;
}



int func_021B8D9C(u32 *p,u32 *out) {
 u32 x,y;
 if(func_02035CB8(&x,&y)) {
  if(x-p[0]<p[2]-p[0] && y-p[1]<p[3]-p[1]) {
   if(out) {out[0]=x;out[1]=y;}
   return 1;
  }
 }
 return 0;
}



u8 func_021B8DE4(u8 *p)
{
    Block ref;
    Block cur;
    Pair rp,cp;
    u32 dx,dy,dist;
    u32 score;
    u32 first,second,part1,part2;
    Line *tmp;
    ref.origin=*(Pair *)(p+0xa3c);
    tmp=(Line *)(p+0xa4c);
    ref.end=*(Pair *)(p+0xa44);
    ref.a=*tmp;
    ref.b=*(Line *)(p+0xaac);
    func_021B8BC0(p+0x75c, (Copy *)&cur);
    rp=ref.origin;
    cp=cur.origin;
    dy=(u32)rp.y;
    dy=dy-(u32)cp.y;
    dx=(u32)rp.x-(u32)cp.x;
    dist=dx*dx+dy*dy;
    if(dist>0 && dist<=64)score=100;
    else if(dist>64 && dist<=256)score=80;
    else if(dist>256 && dist<=576)score=50;
    else if(dist>576 && dist<=1024)score=30;
    else if(dist>1024 && dist<=1600)score=10;
    else score=0;
    first=func_021B8F00((struct Pt *)ref.a.point,(struct Pt *)ref.a.point,(struct Pt *)cur.a.point,(struct Pt *)cur.a.point);
    second=func_021B8F00((struct Pt *)ref.b.point,(struct Pt *)ref.b.point,(struct Pt *)cur.b.point,(struct Pt *)cur.b.point);
    return (score*40u)/100u+(first*40u)/100u+(second*20u)/100u;
}



u8 func_021B8F00(struct Pt *pa, struct Pt *a, struct Pt *pb, struct Pt *b)
{
    int i;
    u32 sum;
    sum = 0;
    for (i = 1; i < 10; i++) {
        int dy1, dx1, dy2, dx2;
        u32 d1, d2;
        u16 d;
        dx1 = a[i].x - pa->x;
        dy1 = a[i].y - pa->y;
        dx2 = b[i].x - pb->x;
        dy2 = b[i].y - pb->y;
        if (dy1 < 0) dy1 = -dy1;
        if (dx1 < 0) dx1 = -dx1;
        d1 = dx1 + dy1;
        if (dy2 < 0) dy2 = -dy2;
        if (dx2 < 0) dx2 = -dx2;
        d2 = dx2 + dy2;
        if (d1 > d2) d = d1 - d2; else d = d2 - d1;
        if (d == 0)
            sum += 100;
        else if (d == 1)
            sum += 80;
        else if (d == 2)
            sum += 50;
        else if (d >= 3 && d <= 5)
            sum += 30;
    }
    return (u8)(sum / 9);
}



void func_021B8FA0(int a,int b,int c,int d,u8 e,u8 f,u8 g,u8 h,u8 i,u8 j,u8 k,u8 l,u8 m,int n,u16 o) {
 void *handle;
 int t;
 u8 *data;
 u16 *p;
 int count;
 handle=func_0204A380((void *)a,b,n,(u16)((o&0x7fff)|0x8000));
 func_02062B30(handle,(void **)(&data));
 if(d && !func_0204169C((u8)c)) {
  count=h*g;
  p=(u16 *)(data+12);
  for(t=0;t<(g*h);t++)p[t]+=(u16)d;
 }
 if(func_0204162C((u8)c)) {
  func_020410D0((u8)c,i,j,k,l,(u32)(data+12),e,f,g,h);
  func_020413B0(c,i,j,k,l,m);
  func_020409B4(c);
 }
 func_020307B0(handle);
}



void func_021B9060(int a,u16 b) {
 void *p = func_020490F4(94,b);
 if(a&1)func_021B8FA0((int)p,7,2,0,0,0,16,24,0,0,16,24,9,0,b);
 else func_02041300(2,0,0,0,16,24,9);
 if(a&2)func_021B8FA0((int)p,8,2,0,0,0,16,24,16,0,16,24,9,0,b);
 else func_02041300(2,0,16,0,16,24,9);
 func_02041B6C(2);func_02049238(p);
}



void func_021B9110(u8 *p,void *q,int a,int b,int c,u8 d) {
 int i;
 func_02082BCC(p,0,0x590);
 ((struct Obj07985 *)p)->f580=a;((struct Obj07985 *)p)->f584=b;
 ((struct Obj07985 *)p)->f588=0;((struct Obj07985 *)p)->f58C=10;
 for(i=0;i<32;i++)func_021B9184(p+i*0x2c,(struct Obj *)func_021B793C(q,c+i),b,d);
}



void func_021B9174(void *p) { func_02082BCC(p,0,0x590); }



void func_021B9184(u8 *p, struct Obj *q, int v, u8 w) { func_02082BCC(p,0,0x2c); *(struct Obj * *)&((struct Obj13740 *)p)->f0=q; ((struct Obj13740 *)p)->f4=w; func_0204B6F4(q,(u8)v,1); }



void func_021B91A8(void *p) { func_02082BCC(p, 0, 0x60); }



/*
 * volatile: 021B91E6 and 021B91EC reread the halfword at offset 0x50.
 */
int func_021B91B4(u8 *p,u32 *rect) {
 u16 n;
 if(((struct Obj03741 *)p)->f5C)return 1;
 if((((struct Obj03741 *)p)->f54)++>150) {
  func_021B8D9C(rect,(u32 *)(p+0x48));
  ((struct Obj03741 *)p)->f5C=1;
  return 1;
 }
 if(((struct Obj03741 *)p)->f58==0) {
  n=*(volatile u16 *)&((struct Obj03741 *)p)->f50;
  (*(volatile u16 *)&((struct Obj03741 *)p)->f50)++;
  func_021B8D9C(rect,(u32 *)(p+n*8));
 }
 if((((struct Obj03741 *)p)->f58)++>15)((struct Obj03741 *)p)->f58=0;
 return 0;
}

#include "../../matched/include/Obj22213.h"

int func_021B9214(void *p)
{
    return ((struct Obj22213 *)p)->f5C;
}

