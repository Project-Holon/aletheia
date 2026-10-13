/*
 * file:     pmsiv_wordwin.c
 * unit:     yes
 * function: func_021BEB78, func_021BEC20, func_021BED84, func_021BEDC4, func_021BEDD0, func_021BEDE0, func_021BEDE4, func_021BEDE8, func_021BEDEC, func_021BEE60, func_021BEF4C, func_021BF08C, func_021BF0C0, func_021BF1C4, func_021BF208, func_021BF338, func_021BF360, func_021BF3A0, func_021BF3D4, func_021BF408, func_021BF444, func_021BF4C4, func_021BF4F8, func_021BF500, func_021BF508, func_021BF53C, func_021BF608, func_021BF680, func_021BF6CC, func_021BF6D4, func_021BF6D8, func_021BF6DC, func_021BF6E4, func_021BF6F0, func_021BF708, func_021BF714, func_021BF71C, func_021BF724, func_021BF72C, func_021BF734, func_021BF758, func_021BF784, func_021BF7A0, func_021BF7AC, func_021BF7B8, func_021BF7C4, func_021BF7D0, func_021BF7D4, func_021BF7E0, func_021BF7EC, func_021BF7FC, func_021BF808, func_021BF814, func_021BF824, func_021BF82C, func_021BF844, func_021BF8BC, func_021BF8F4, func_021BF94C, func_021BF9F0, func_021BFA40, func_021BFAA0, func_021BFB58, func_021BFB7C, func_021BFBA0, func_021BFC20, func_021BFC64, func_021BFCA4, func_021BFD60, func_021BFD94, func_021BFDB0, func_021BFE24, func_021BFE60, func_021BFED0, func_021BFF60, func_021BFF7C, func_021C00AC, func_021C00FC, func_021C0134, func_021C01E4, func_021C022C
 * address:  0x021BEB78
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
 *   d_021C3978 0x021C3978 data a1
 *   func_021BB240 0x021BB240 thumb ov110
 *   func_021BB250 0x021BB250 thumb ov110
 *   func_021BB260 0x021BB260 thumb ov110
 *   func_021BB270 0x021BB270 thumb ov110
 *   func_021BB280 0x021BB280 thumb ov110
 *   func_021B9C90 0x021B9C90 thumb ov110
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   func_021B9C74 0x021B9C74 thumb ov110
 *   func_021BD7A0 0x021BD7A0 thumb ov110
 *   func_020061E4 0x020061E4 thumb
 *   func_021BE4C0 0x021BE4C0 thumb ov110
 *   func_021BD894 0x021BD894 thumb ov110
 *   d_021C39A8 0x021C39A8 data a1
 *   d_021C3900 0x021C3900 data a1
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   func_02035D20 0x02035D20 arm
 *   TOUCHPANEL_HitPoint 0x02035D40 arm
 *   func_021BACDC 0x021BACDC thumb ov110
 *   func_021BAD14 0x021BAD14 thumb ov110
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   func_021BE7F0 0x021BE7F0 thumb ov110
 *   func_021BD808 0x021BD808 thumb ov110
 *   func_020362DC 0x020362DC arm
 *   func_021BAD20 0x021BAD20 thumb ov110
 *   func_021B99C4 0x021B99C4 thumb ov110
 *   func_021BB1E4 0x021BB1E4 thumb ov110
 *   func_021BABF4 0x021BABF4 thumb ov110
 *   PMSI_PARAM_SetWordAt 0x020245A0 thumb
 *   func_021BAC0C 0x021BAC0C thumb ov110
 *   PMSI_PARAM_ClearUnusedWords 0x020245AC thumb
 *   PMSI_PARAM_SetResult 0x020241E0 thumb
 *   PMSI_PARAM_IsComplete 0x02024464 thumb
 *   PMSI_PARAM_GetSentenceType  0x0202452C  thumb
 *   PMSI_PARAM_GetWordRaw 0x020244F0 thumb
 *   func_021B999C 0x021B999C thumb ov110
 *   func_021BB1C0 0x021BB1C0 thumb ov110
 *   func_021B99A4 0x021B99A4 thumb ov110
 *   func_021BB1CC 0x021BB1CC thumb ov110
 *   PMSI_PARAM_HasInitialSentence  0x02024158  thumb
 *   func_021BB00C  0x021BB00C  thumb  ov110
 *   func_021BAFE4 0x021BAFE4 thumb ov110
 *   func_021BAFDC  0x021BAFDC  thumb  ov110
 *   func_02030734 0x02030734 arm
 *   d_021C3C84 0x021C3C84 data a1
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02040B94 0x02040B94 arm
 *   func_02041300 0x02041300 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   func_021BAC64 0x021BAC64 thumb ov110
 *   func_021BAC78 0x021BAC78 thumb ov110
 *   func_021BAC50 0x021BAC50 thumb ov110
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   func_021BAD2C 0x021BAD2C thumb ov110
 *   func_0207D63C 0x0207D63C arm
 *   func_021BC868 0x021BC868 thumb ov110
 *   func_021BC898 0x021BC898 thumb ov110
 *   func_0204B404 0x0204B404 arm
 *   func_021BC78C 0x021BC78C thumb ov110
 *   func_021BC7DC 0x021BC7DC thumb ov110
 *   func_0204B3F4 0x0204B3F4 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   BMP_FillRect 0x02043AF4 arm
 *   func_02040618 0x02040618 arm
 *   func_021BAC44 0x021BAC44 thumb ov110
 *   CLACT_SetActorPos 0x0204B528 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_Blit 0x020439A0 arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   overlay_id 0x00000043 data a1
 *   func_02034AC4 0x02034AC4 arm
 *   func_0207D534 0x0207D534 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   PMS_WORD_GetSaveData 0x02024988 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201C440 0x0201C440 thumb
 *   PROCSYS_Create 0x02031324 arm
 *   func_021C0490 0x021C0490 thumb ov110
 *   func_021C05B0 0x021C05B0 thumb ov110
 *   func_0203133C 0x0203133C arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_0201C6B4 0x0201C6B4 thumb
 *   PMS_DRAW_IsPrintEnd 0x0202DC98 thumb
 *   ov067_id                         0x00000043  data
 *   PMSI_PARAM_GetSourceString  0x0202441C  thumb  arm9
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 */
#include "../../matched/include/Obj01532.h"
#include "../../matched/include/Obj00296.h"
#include "../../matched/include/Obj02165.h"
#include "../../matched/include/Obj10283.h"
#include "../../matched/include/Obj22381.h"
#include "../../matched/include/Obj22382.h"
#include "../../matched/include/Obj22383.h"
#include "../../matched/include/Obj00012.h"
#include "../../matched/include/Obj01394.h"
#include "../../matched/include/Obj00493.h"
#include "../../matched/include/Obj04449.h"
#include "../../matched/include/Obj01923.h"
#include "../../matched/include/Obj05296.h"
#include "../../matched/include/Obj04450.h"
#include "../../matched/include/Obj04451.h"
#include "../../matched/include/Obj13793.h"
#include "../../matched/include/Obj13795.h"
#include "../../matched/include/Obj22384.h"
#include "../../matched/include/Obj13796.h"
#include "../../matched/include/Obj08007.h"
#include "../../matched/include/Obj22385.h"
#include "../../matched/include/Obj22386.h"
#include "../../matched/include/Obj22387.h"
#include "../../matched/include/Obj22388.h"
#include "../../matched/include/Obj22389.h"
#include "../../matched/include/Obj22390.h"
#include "../../matched/include/Obj22391.h"
#include "../../matched/include/Obj08008.h"
#include "../../matched/include/Obj08009.h"
#include "../../matched/include/Obj22392.h"
#include "../../matched/include/Obj22393.h"
#include "../../matched/include/Obj22394.h"
#include "../../matched/include/Obj22395.h"
#include "../../matched/include/Obj22396.h"
#include "../../matched/include/Obj13799.h"
#include "../../matched/include/Obj22399.h"
#include "../../matched/include/Obj22400.h"
#include "../../matched/include/Obj22401.h"
#include "../../matched/include/Obj02819.h"
#include "../../matched/include/Obj03755.h"
#include "../../matched/include/Obj01145.h"
#include "../../matched/include/Obj02166.h"
#include "../../matched/include/Obj08010.h"
#include "../../matched/include/Obj22402.h"
#include "../../matched/include/Obj22403.h"
#include "../../matched/include/Obj13800.h"
#include "../../matched/include/Obj04452.h"
#include "../../matched/include/Obj13801.h"
#include "../../matched/include/Obj03756.h"
#include "../../matched/include/Obj13802.h"
#include "../../matched/include/Obj13803.h"
#include "../../matched/include/Obj13802.h"
#include "../../matched/include/Obj13804.h"
#include "../../matched/include/Obj06392.h"
#include "../../matched/include/Obj01533.h"
#include "../../matched/include/Obj06393.h"
#include "../../matched/include/Obj05298.h"
#include "../../matched/include/Obj01713.h"
#include "../../matched/include/Obj06394.h"
#include "../../matched/include/Obj13806.h"
#include "../../matched/include/Obj22406.h"

struct Ctx;
struct T245;
struct T241;
struct T;
struct Struct_0202441C;
struct U16Vec;
struct Obj;
struct Descriptor;
struct CharBuf;
struct Cfg;
struct V3;
struct Vec2_021BFC64;
struct Actor;
struct PtS;
struct Vec2_021BFB58;
struct Bmp;
struct GfFont;
struct MsgBank;
struct Obj0203159C;
struct PrintSys;
struct Rec;
struct S020314B8;
struct S020315D4;
struct Obj0202DC98;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef int (*Handler_021BEE60)(u8 *,void *);

struct Box { u8 b[8]; };

typedef int (*Handler_021BF0C0)(u8 *, void *);

typedef int (*Handler_021BF53C)(u8 *, void *);

typedef struct { int x,y,z; } Triple;

typedef struct { void *root; void *a; void *b; void *c; void *d; void *first; void *unused; void *second; void *items[10]; } Obj;

typedef enum { FALSE, TRUE } BOOL;

typedef enum { PLANE_NONE=0, PLANE_ALL=31 } Plane;

typedef enum { WINDOW_NONE=0, WINDOW_0=1, WINDOW_1=2, WINDOW_OBJ=4 } Window;

typedef struct { unsigned char plane:5; unsigned char effect:1; unsigned char rest:2; } Wnd;

typedef struct { u16 x,y; } Vec2_021BFC64;

typedef struct Vec2_021BFD94 { short x,y; } Vec2_021BFD94;

typedef struct { short x,y; } Vec2_021BFB58;

typedef struct Vec2_021BFE24 { short x,y; } Vec2_021BFE24;

struct Pt { u16 x, y; };

typedef struct { short x,y; } Vec2_021BFF7C;

extern u8 func_021BB240(u32 i);
extern u8 func_021BB250(u32 i);
extern u8 func_021BB260(u32 i);
extern int func_021BB270(int n);
extern u8 func_021BB280(u32 i);
extern int func_021B9C90(unsigned int a, int b);
extern void func_021B9BEC(u8 *p, int id);
extern int func_021B9C74(unsigned int a);
extern void func_021BD7A0(u8 *,void *);
extern void func_020061E4(u32);
extern int func_021BE4C0(u8 *p, unsigned *q);
extern int func_021BD894(u8 *,void *);
extern int TOUCHPANEL_HitTrg(const void *p);
extern u32 func_02035D20(u32 *, u32 *);
extern u32 TOUCHPANEL_HitPoint(struct Ctx *, u32, u32);
extern int func_021BACDC(u8 *p, int unused, unsigned n);
extern void func_021BAD14(u8 *, u32);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern int func_021BE7F0(void);
extern int func_021BD808(u8 *,void *);
extern u32 func_020362DC(void);
extern unsigned func_021BAD20(u8 *,unsigned);
extern unsigned short func_021B99C4(unsigned int a, unsigned int b, unsigned int c);
extern u16 func_021BB1E4(u32 p, u32 i);
extern int func_021BABF4(u8 *p, int i);
extern void PMSI_PARAM_SetWordAt(u8 *p, unsigned i, u16 v);
extern int func_021BAC0C(u8 *p);
extern void PMSI_PARAM_ClearUnusedWords(struct T *p, u32 a1);
extern void PMSI_PARAM_SetResult(struct T *p, u16 *a1, u16 *a2);
extern int PMSI_PARAM_IsComplete(struct T *p, u32 a1);
extern int PMSI_PARAM_GetSentenceType(const u16 *p);
extern u16 PMSI_PARAM_GetWordRaw(void *,u32);
extern void *PMSI_PARAM_GetSourceString(const struct Struct_0202441C *obj, u32 heapId);
extern u32 func_021B999C(u8 *,int);
extern u8 func_021BB1C0(u8 *);
extern void func_021B99A4(u32,u32,u32,int);
extern int func_021BB1CC(u8 *p, u8 i, int c);
extern u32 PMSI_PARAM_HasInitialSentence(const u8 *p);
extern void func_021BB00C(void *p, void *q);
extern void func_021BAFE4(u32 p);
extern u8 func_021BAFDC(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void CLACT_DeleteActor(struct Obj *);
extern void STRBUF_Delete(struct U16Vec *);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_020307B0(void *p);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02041300(unsigned,int,int,int,u8,u8,u8);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void func_020409B4(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021BAC64(void *,Triple *,int,int);
extern struct Obj *func_021BAC78(char *p, unsigned int *r, short x, short y, unsigned int a, int mode);
extern void func_021BAC50(char *p, struct V3 *out, int i);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void CLACT_SetActorBgPriority(void *,int);
extern void func_021BAD2C(u8 *,int);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_021BC868(u8 *p, int a, int b, int start, int end, int frames);
extern int func_021BC898(u8 *p);
extern void func_0204B404(struct Obj *p, const struct Vec2_021BFC64 *delta, u32 which);
extern void func_021BC78C(u8 *,int,int,int,int);
extern int func_021BC7DC(u8 *);
extern u32 func_0204B3F4(struct Obj *p);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void BMP_FillRect(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_02040618(u32,u32,u32);
extern u32 func_021BAC44(u8 *);
extern void CLACT_SetActorPos(struct Actor *, const struct Pt *);
extern void func_0201DD68(void);
extern void PRINTSYS_Print(void *, short, short, void *, void *);
extern void BMP_Blit(struct Bmp *, struct Bmp *, u32, u32, int, int, u32, u32, u32);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern int func_02034AC4(int handle);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,unsigned);
extern void *PMS_WORD_GetSaveData(int a0);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_0201C440(void *p);
extern void *PROCSYS_Create(int a0);
extern void func_021C0490(u8 *);
extern void func_021C05B0(char *p);
extern void func_0203133C(struct S020314B8 *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_02034A5C(int handle);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern u32 PMS_DRAW_IsPrintEnd(struct Obj0202DC98 *o);
int func_021BEB78(u8 *p);
int func_021BEC20(u8 *p);
void func_021BED84(u8 *p, void *q);
u32 func_021BEDC4(u8 *p);
unsigned func_021BEDD0(u8 *p);
u32 func_021BEDE0(u8 *p);
u16 func_021BEDE4(u8 *p);
u16 func_021BEDE8(u8 *p);
int func_021BEDEC(u8 *p,u32 *q);
void func_021BEE60(u8 *p,u32 *q);
int func_021BEF4C(u8 *p);
int func_021BF08C(u8 *p);
void func_021BF0C0(u8 *p, u32 *q);
void func_021BF1C4(u8 *p,void *q);
int func_021BF208(u8 *p, u32 keys);
int func_021BF338(u8 *p);
u32 func_021BF360(u8 *p);
int func_021BF3A0(u8 *p,u8 *q);
int func_021BF3D4(u8 *p,u8 *q);
int func_021BF408(u8 *p,u8 *q);
int func_021BF444(u8 *p);
int func_021BF4C4(u8 *p,int *q);
void func_021BF4F8(u8 *p, u32 v);
void func_021BF500(u8 *p);
void func_021BF508(u8 *p,int *q);
void func_021BF53C(u8 *p, u32 *q);
void func_021BF608(u8 *p,u32 *q);
int func_021BF680(u8 *p);
void func_021BF6CC(u8 *p, u8 a, u8 b);
u8 *func_021BF6D4(u8 *p);
u32 func_021BF6D8(u8 *p);
u8 func_021BF6DC(u8 *p);
int func_021BF6E4(u8 *p);
u32 func_021BF6F0(u8 *p,u32 i);
void *func_021BF708(u8 *p, u32 heapId);
u16 func_021BF714(u8 *p);
u16 func_021BF71C(u8 *p);
u16 func_021BF724(u8 *p);
u16 func_021BF72C(u8 *p);
u32 func_021BF734(u8 *p);
void func_021BF758(u8 *p,u32 a,int b);
u32 func_021BF784(u8 *p);
int func_021BF7A0(u8 *p);
unsigned func_021BF7AC(u8 *p);
unsigned func_021BF7B8(u8 *p);
u32 func_021BF7C4(u8 *p);
u32 func_021BF7D0(u8 *p);
void func_021BF7D4(u8 *p, void *q);
void func_021BF7E0(u8 *p);
void func_021BF7EC(const u8 *p,u16 *a,u16 *b);
u8 func_021BF7FC(u8 *p);
int func_021BF808(u8 *p);
void func_021BF814(u8 *p,u32 a,int b);
int func_021BF824(u8 *a0);
void func_021BF82C(u8 *p);
u8 *func_021BF844(void *a,void *b,void *c);
void func_021BF8BC(u8 *p);
void func_021BF8F4(u8 *p);
void func_021BF94C(Obj *p);
void func_021BF9F0(u8 *p);
void func_021BFA40(u8 *p,unsigned a);
void func_021BFAA0(u8 *p);
int func_021BFB58(u8 *p);
void func_021BFB7C(u8 *p);
int func_021BFBA0(u8 *p);
void func_021BFC20(u8 *p, unsigned visible);
void func_021BFC64(u8 *p, unsigned i);
void func_021BFCA4(u8 *p,int amount);
int func_021BFD60(u8 *p);
u32 func_021BFD94(u8 *p,Vec2_021BFD94 *out);
void func_021BFDB0(u8 *p,unsigned a,unsigned n);
void func_021BFE24(u8 *p,int y);
unsigned func_021BFE60(u8 *p, unsigned n);
void func_021BFED0(u8 *p,int amount);
void func_021BFF60(u8 *p);
void func_021BFF7C(u8 *p, u32 n, u32 y);
void func_021C00AC(u8 *p, unsigned i);
int func_021C00FC(u8 *p);
int func_021C0134(void *owner,int unused,void **input);
int func_021C01E4(void *p, int a, int b, char *q);
int func_021C022C(u8 *p);
void func_021C0250(int *out,u8 *p,int value);
extern const u8 d_021C3978[][4];
extern const struct Box d_021C39A8;
extern const struct Box d_021C3900[];
extern const char d_021C3C84[];
extern const u8 overlay_id[];
extern char ov067_id[];








int func_021BEB78(u8 *p) {
    u16 v=((struct Obj01532 *)p)->f4C;
    u16 n=v;
    if(v==254) n=12;
    if(v!=254) {
        ((struct Obj01532 *)p)->f4E=v;
        if(((struct Obj01532 *)p)->f38&64) { ((struct Obj01532 *)p)->f4C=d_021C3978[n][0]; return 1; }
        if(((struct Obj01532 *)p)->f38&128) { ((struct Obj01532 *)p)->f4C=d_021C3978[n][1]; return 1; }
        if(((struct Obj01532 *)p)->f38&32) { ((struct Obj01532 *)p)->f4C=d_021C3978[n][2]; return 1; }
        if(((struct Obj01532 *)p)->f38&16) { ((struct Obj01532 *)p)->f4C=d_021C3978[n][3]; return 1; }
    } else {
        ((struct Obj01532 *)p)->f4E=254;
        if(((struct Obj01532 *)p)->f38&64) { ((struct Obj01532 *)p)->f4C=11; return 1; }
        if(((struct Obj01532 *)p)->f38&128) { ((struct Obj01532 *)p)->f4C=2; return 1; }
    }
    return 0;
}








/*
 * lever: repeat the halfword store before a shared return label to retain the cross-jumped branch; descending switch bodies retain the tail layout.
 * abi: full getter bodies at 021BB240/250/260/270/280 read only r0 and return a zero-extended table byte.
 */
int func_021BEC20(u8 *p) {
    int x=((struct Obj00296 *)p)->f4C;
    int y;
    if(x!=254 && x!=252 && x!=253) {
        y=255;
        if(((struct Obj00296 *)p)->f38&64) y=func_021BB240(x);
        else if(((struct Obj00296 *)p)->f38&128) y=func_021BB250(x);
        else if(((struct Obj00296 *)p)->f38&16) y=func_021BB270(x);
        else if(((struct Obj00296 *)p)->f38&32) y=func_021BB260(x);
        if(y!=255) { ((struct Obj00296 *)p)->f4E=((struct Obj00296 *)p)->f4C; ((struct Obj00296 *)p)->f4C=y; return 1; }
    } else if(((struct Obj00296 *)p)->f38&64) {
        if(((struct Obj00296 *)p)->f4E<=26) y=func_021BB280(((struct Obj00296 *)p)->f4E); else y=255;
        if(((struct Obj00296 *)p)->f4C==252) {
            if(y>=20 && y<=23) { ((struct Obj00296 *)p)->f4C=y; goto end64; }
            else { ((struct Obj00296 *)p)->f4C=22; goto end64; }
        } else if(((struct Obj00296 *)p)->f4C==253) {
            if(y==24 || y==25 || y==16) { ((struct Obj00296 *)p)->f4C=y; goto end64; }
            else { ((struct Obj00296 *)p)->f4C=25; goto end64; }
        } else {
            if(y==17 || y==18 || y==26) { ((struct Obj00296 *)p)->f4C=y; goto end64; }
            else { ((struct Obj00296 *)p)->f4C=26; goto end64; }
        }
end64: return 1;
    } else if(((struct Obj00296 *)p)->f38&128) {
        if(((struct Obj00296 *)p)->f4E<=26) y=func_021BB280(((struct Obj00296 *)p)->f4E); else y=255;
        if(((struct Obj00296 *)p)->f4C==252) {
            if(y>=0 && y<=3) { ((struct Obj00296 *)p)->f4C=y; goto end128; }
            else { ((struct Obj00296 *)p)->f4C=2; goto end128; }
        } else if(((struct Obj00296 *)p)->f4C==253) {
            if(y>=4 && y<=6) { ((struct Obj00296 *)p)->f4C=y; goto end128; }
            else { ((struct Obj00296 *)p)->f4C=5; goto end128; }
        } else {
            if(y>=7 && y<=9) { ((struct Obj00296 *)p)->f4C=y; goto end128; }
            else { ((struct Obj00296 *)p)->f4C=8; goto end128; }
        }
end128: return 1;
    } else if(((struct Obj00296 *)p)->f38&32) {
        switch(x) {
        case 254: ((struct Obj00296 *)p)->f4C=253; break;
        case 253: ((struct Obj00296 *)p)->f4C=252; break;
        case 252: ((struct Obj00296 *)p)->f4C=254; break;
        }
        return 1;
    } else if(((struct Obj00296 *)p)->f38&16) {
        switch(x) {
        case 254: ((struct Obj00296 *)p)->f4C=252; break;
        case 253: ((struct Obj00296 *)p)->f4C=254; break;
        case 252: ((struct Obj00296 *)p)->f4C=253; break;
        }
        return 1;
    }
    return 0;
}








void func_021BED84(u8 *p, void *q) {
    ((struct Obj02165 *)p)->f0=0; p[6]=0; p[7]=0;
    ((struct Obj02165 *)p)->f4=func_021BF734(q);
    ((struct Obj02165 *)p)->f8=0;
    ((struct Obj02165 *)p)->fC=0; ((struct Obj02165 *)p)->fE=65535;
    if (((struct Obj02165 *)p)->f4>14) ((struct Obj02165 *)p)->f2=(((struct Obj02165 *)p)->f4-14)/2+(((struct Obj02165 *)p)->f4&1);
    else ((struct Obj02165 *)p)->f2=0;
}









u32 func_021BEDC4(u8 *p) { return p[6] + p[7] * 2; }








unsigned func_021BEDD0(u8 *p) { return ((struct Obj10283 *)p)->f0*2+func_021BEDC4(p); }









u32 func_021BEDE0(u8 *p)
{
    return ((struct Obj22381 *)p)->f8;
}








/*
 * note: unlabelled blocker leaf for func_021BF7AC; ends at filed EDE8.
 */
u16 func_021BEDE4(u8 *p) { return ((struct Obj22382 *)p)->f0; }








u16 func_021BEDE8(u8 *p) { return ((struct Obj22383 *)p)->f2; }








int func_021BEDEC(u8 *p,u32 *q) {
    switch(*q) {
    case 0: func_021BF1C4(p,q); break;
    case 1: if(func_021B9C90((unsigned int)(((struct Obj00012 *)p)->f14),20)) *q=0; break;
    case 2: if(func_021B9C90((unsigned int)(((struct Obj00012 *)p)->f14),20)) { func_021B9BEC(((struct Obj00012 *)p)->f14,19); *q=0; } break;
    case 3: if(func_021B9C90((unsigned int)(((struct Obj00012 *)p)->f14),31)) *q=0; break;
    case 4: if(func_021B9C74((unsigned int)(((struct Obj00012 *)p)->f14))) { func_021BD7A0(p,((struct Obj00012 *)p)->f28); *q=0; } break;
    }
    return 0;
}








void func_021BEE60(u8 *p,u32 *q) {
    switch(func_021BF208(p+0x54,((struct Obj01394 *)p)->f38)) {
    case 1: func_020061E4(1352); func_021B9BEC(*(u8 * *)&((struct Obj01394 *)p)->f14,19); return;
    case 2: func_020061E4(1352); func_021B9BEC(*(u8 * *)&((struct Obj01394 *)p)->f14,20); *q=1; return;
    case 3: func_020061E4(1352); func_021B9BEC(*(u8 * *)&((struct Obj01394 *)p)->f14,20); func_021B9BEC(*(u8 * *)&((struct Obj01394 *)p)->f14,19); *q=2; return;
    }
    if(((struct Obj01394 *)p)->f34&2) {
        func_020061E4(1361); func_021B9BEC(*(u8 * *)&((struct Obj01394 *)p)->f14,13);
        *(Handler_021BEE60 *)&((struct Obj01394 *)p)->f28=(Handler_021BEE60)func_021BE4C0; *q=4; return;
    } else if(((struct Obj01394 *)p)->f34&1) {
        if(((struct Obj01394 *)p)->f60!=0) {
            func_020061E4(1361); func_021B9BEC(*(u8 * *)&((struct Obj01394 *)p)->f14,13);
            *(Handler_021BEE60 *)&((struct Obj01394 *)p)->f28=(Handler_021BEE60)func_021BE4C0; *q=4; return;
        } else {
            func_020061E4(1356); ((struct Obj01394 *)p)->f62=65535;
            func_021BF444(p);
            func_021B9BEC(*(u8 * *)&((struct Obj01394 *)p)->f14,34); func_021B9BEC(*(u8 * *)&((struct Obj01394 *)p)->f14,14);
            *(Handler_021BEE60 *)&((struct Obj01394 *)p)->f28=func_021BD894; *q=4;
        }
    }
}








/*
 * prototype: BAD14 retains r1 explicitly loaded at EF4C+68/+86 despite its unused input.
 */
int func_021BEF4C(u8 *p)
{
    u32 x, y;
    struct Box box = d_021C39A8;
    int outer, inner, stop;
    u16 index;
    if (TOUCHPANEL_HitTrg(d_021C3900) == 0) {
        func_02035D20(&x, &y);
        switch (func_021BACDC(*(u8 * *)&((struct Obj00493 *)p)->f14, x, y)) {
        case 0:
            p[106] = 1;
            func_020061E4(1352);
            return 0;
        case 1:
            p[106] = 1;
            func_021BAD14(*(u8 * *)&((struct Obj00493 *)p)->f14, y);
            return func_021BF3A0(*(u8 * *)&((struct Obj00493 *)p)->f14, p + 84);
        case 2:
            p[106] = 1;
            func_021BAD14(*(u8 * *)&((struct Obj00493 *)p)->f14, y);
            return func_021BF3D4(*(u8 * *)&((struct Obj00493 *)p)->f14, p + 84);
        case 3:
            break;
        }
    }
    func_02035D20(&x, &y);
    index = ((struct Obj00493 *)p)->f54 * 2;
    stop = 0;
    for (outer = 0; outer < 6; outer++) {
        box.b[0] = 24 * outer + 13;
        box.b[1] = box.b[0] + 22;
        for (inner = 0; inner < 2; inner++) {
            box.b[2] = 112 * inner + 16;
            box.b[3] = box.b[2] + 102;
            if (TOUCHPANEL_HitPoint((struct Ctx *)&box, x, y) != (u32)-1) {
                ((struct Obj00493 *)p)->f62 = index;
                p[90] = inner;
                p[91] = outer;
                return 5;
            }
            index++;
            if (index >= ((struct Obj00493 *)p)->f58 - 2) {
                stop = 1;
                break;
            }
        }
        if (stop) break;
    }
    return 0;
}








int func_021BF08C(u8 *p) {
 unsigned x,y;
 if(TOUCHPANEL_GetPointCont(&x,&y)==1 && p[0x6a]==1) { func_021BAD14(*(u8 * *)&((struct Obj00493 *)p)->f14,y); return 1; }
 p[0x6a]=0;
 return 0;
}








/*
 * lever: emit case 5 before cases 1/2/3 as in the original jump table.
 */
void func_021BF0C0(u8 *p, u32 *q)
{
    if (!func_021BE7F0()) {
        func_020061E4(1361);
        func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 13);
        *(Handler_021BF0C0 *)&((struct Obj00493 *)p)->f28 = (Handler_021BF0C0)func_021BE4C0;
        *q = 4;
        return;
    }
    if (func_021BF08C(p) == 1) {
        switch (func_021BF408(*(u8 * *)&((struct Obj00493 *)p)->f14, p + 84)) {
        case 2:
            func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 31);
            *q = 3;
            break;
        case 3:
            func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 31);
            func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 19);
            *q = 3;
            break;
        }
        return;
    }
    switch (func_021BEF4C(p)) {
    case 0: break;
    case 5:
        func_020061E4(1356);
        func_021BF444(p);
        *(Handler_021BF0C0 *)&((struct Obj00493 *)p)->f28 = func_021BD894;
        func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 34);
        func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 14);
        *q = 4;
        break;
    case 1:
        func_020061E4(1352);
        func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 19);
        break;
    case 2:
        func_020061E4(1352);
        func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 31);
        *q = 3;
        break;
    case 3:
        func_020061E4(1352);
        func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 20);
        func_021B9BEC(*(u8 * *)&((struct Obj00493 *)p)->f14, 19);
        *q = 2;
        break;
    case 4: break;
    }
}








void func_021BF1C4(u8 *p,void *q) {
    if(func_021BD808(p,q) && *(u32 *)&((struct Obj00012 *)p)->f70==0 && !(func_020362DC()&2)) { func_020061E4(1352); return; }
    if(*(u32 *)&((struct Obj00012 *)p)->f70==0) func_021BEE60(p,q);
    else func_021BF0C0(p,q);
}








int func_021BF208(u8 *p, u32 keys)
{
    u32 r;
    if (keys & 0x80) {
        if (*(u16 *)(p + 0xC) != 0)
            return 4;
        if (p[7] < 5) {
            p[7]++;
            r = func_021BEDD0(p);
            if (r < (u32)*(u16 *)(p + 4) - 2)
                return 1;
            if (r == (u32)*(u16 *)(p + 4) - 2) {
                if (r & 1) {
                    p[6] = 0;
                    return 1;
                }
                p[7]--;
                return 4;
            }
            p[7]--;
            return 4;
        }
        if (*(u16 *)p < *(u16 *)(p + 2)) {
            *(u32 *)(p + 8) = 1;
            *(u16 *)p = *(u16 *)p + 1;
            r = func_021BEDD0(p);
            if (r < (u32)*(u16 *)(p + 4) - 2)
                return 2;
            p[6] = 0;
            return 3;
        }
        return 4;
    }
    if (keys & 0x40) {
        if (*(u16 *)(p + 0xC) != 0) {
            *(u16 *)(p + 0xC) = 0;
            return 1;
        }
        if (p[7] != 0) {
            p[7]--;
            return 1;
        }
        if (*(u16 *)p != 0) {
            *(int *)(p + 8) = -1;
            *(u16 *)p = *(u16 *)p - 1;
            return 2;
        }
        return 4;
    }
    if (keys & 0x20) {
        if (p[6] == 1) {
            p[6] ^= 1;
            r = func_021BEDD0(p);
            if (r < (u32)*(u16 *)(p + 4) - 2)
                return 1;
            p[6] ^= 1;
        }
        return 4;
    }
    if (keys & 0x10) {
        if (p[6] == 0) {
            p[6] ^= 1;
            r = func_021BEDD0(p);
            if (r < (u32)*(u16 *)(p + 4) - 2)
                return 1;
            p[6] ^= 1;
        }
        return 4;
    }
    if (keys & 0x200)
        return func_021BF338(p);
    if (keys & 0x100)
        return func_021BF360(p);
    return 0;
}








int func_021BF338(u8 *p) {
 if(((struct Obj04449 *)p)->f0!=0) {
  if(((struct Obj04449 *)p)->f0>=6) { ((struct Obj04449 *)p)->f0-=6; ((struct Obj04449 *)p)->f8=-6; }
  else { ((struct Obj04449 *)p)->f8=-((struct Obj04449 *)p)->f0; ((struct Obj04449 *)p)->f0=0; }
  return 2;
 }
 return 4;
}








/*
 * extent: two bytes zero alignment padding at 0x021BF39E.
 */
u32 func_021BF360(u8 *p) {
    if (((struct Obj01923 *)p)->f0<((struct Obj01923 *)p)->f2) {
        if (((struct Obj01923 *)p)->f0+6<=((struct Obj01923 *)p)->f2) { ((struct Obj01923 *)p)->f8=6; ((struct Obj01923 *)p)->f0+=6; }
        else { ((struct Obj01923 *)p)->f8=((struct Obj01923 *)p)->f2-((struct Obj01923 *)p)->f0; ((struct Obj01923 *)p)->f0=((struct Obj01923 *)p)->f2; }
        if((int)func_021BEDD0(p)<((struct Obj01923 *)p)->f4-2) return 2;
        p[6]=0; return 3;
    }
    return 4;
}








int func_021BF3A0(u8 *p,u8 *q) {
 if(((struct Obj05296 *)q)->f0!=0) {
  ((struct Obj05296 *)q)->f0=func_021BAD20(p,((struct Obj05296 *)q)->f2);
  ((struct Obj05296 *)q)->f8=0;
  if((int)func_021BEDD0(q)<((struct Obj05296 *)q)->f4-2) return 2;
  q[6]=0; return 3;
 }
 return 4;
}








int func_021BF3D4(u8 *p,u8 *q) {
 if(((struct Obj04450 *)q)->f0<((struct Obj04450 *)q)->f2) {
  ((struct Obj04450 *)q)->f0=func_021BAD20(p,((struct Obj04450 *)q)->f2);
  ((struct Obj04450 *)q)->f8=0;
  if((int)func_021BEDD0(q)<((struct Obj04450 *)q)->f4-2) return 2;
  q[6]=0; return 3;
 }
 return 4;
}








int func_021BF408(u8 *p,u8 *q) {
 u16 n=((struct Obj04451 *)q)->f0;
 ((struct Obj04451 *)q)->f0=func_021BAD20(p,((struct Obj04451 *)q)->f2);
 ((struct Obj04451 *)q)->f8=0;
 if(n!=((struct Obj04451 *)q)->f0) func_020061E4(0x548);
 if((int)func_021BEDD0(q)<((struct Obj04451 *)q)->f4-2) return 2;
 q[6]=0; return 3;
}








/*
 *   Verified EXACT (blocker-r1.log), 12 bytes:
 *   void PMSI_PARAM_SetWordAt(u8 *p,unsigned i,u16 v) {
 *       if(i<2) *(u16 *)(p+4+2*i)=v;
 *   }
 */
int func_021BF444(u8 *p) {
    int i=*(u16 *)(p+98);
    u16 v;
    if(i==65535) i=func_021BEDD0(p+84);
    if(p[105]==0) v=func_021B99C4((unsigned int)(*(void **)(p+24)),*(u16 *)(p+76),i);
    else v=func_021BB1E4((u32)(*(void **)(p+28)),i);
    switch(*(u32 *)(p+4)) {
    case 0: *(u16 *)(p+16)=v; break;
    case 1: *(u16 *)(p+16+2* *(u16 *)(p+74))=v; break;
    case 2: PMSI_PARAM_SetWordAt(p+8,func_021BABF4(*(void **)(p+20),*(u16 *)(p+74)),v); break;
    }
    return func_021BF680(p);
}








int func_021BF4C4(u8 *p,int *q) {
 switch(*q) {
 case 0: func_021B9BEC(*(u8 * *)&((struct Obj13793 *)p)->f14,1); ++*q; break;
 case 1: if(func_021B9C74(*(unsigned *)&((struct Obj13793 *)p)->f14)!=0) return 1; break;
 }
 return 0;
}









void func_021BF4F8(u8 *p, u32 v) { ((struct Obj13795 *)p)->f30 = v; ((struct Obj13795 *)p)->f2C = 0; }









void func_021BF500(u8 *p) { ((struct Obj22384 *)p)->f30 = 0; }








void func_021BF508(u8 *p,int *q) {
 switch(*q) {
 case 0: func_021B9BEC(*(u8 * *)&((struct Obj13796 *)p)->f14,2); ++*q; break;
 case 1: if(func_021B9C74(*(unsigned *)&((struct Obj13796 *)p)->f14)!=0) func_021BF500(p); break;
 }
}








void func_021BF53C(u8 *p, u32 *q)
{
    switch (*q) {
    case 0:
        if (func_021B9C74((unsigned int)(((struct Obj00012 *)p)->f14))) {
            if (func_021BF680(p)) {
                func_021BF6CC(p + 107, 1, 0);
                ((struct Obj00012 *)p)->f48 = 0;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14, 21);
                *q = 1;
            } else *q = 3;
        }
        break;
    case 1:
        switch (func_021BAC0C(((struct Obj00012 *)p)->f14)) {
        case 0:
            func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14, 23);
            *q = 3;
            break;
        case 1:
            if (((struct Obj00012 *)p)->f4 == 2) PMSI_PARAM_ClearUnusedWords((struct T *)(p + 8), 42);
            PMSI_PARAM_SetResult((struct T *)(*(struct T241 * *)&((struct Obj00012 *)p)->f0), (u16 *)(p + 16), (u16 *)(p + 8));
            func_021BD7A0(p, (Handler_021BF53C)func_021BF4C4);
            *q = 3;
            break;
        }
        break;
    case 2:
        if (((struct Obj00012 *)p)->f34 & 243) *q = 3;
        break;
    case 3:
        if (func_021B9C74((unsigned int)(((struct Obj00012 *)p)->f14))) func_021BF500(p);
        break;
    }
}








void func_021BF608(u8 *p,u32 *q) {
    switch(*q) {
    case 0: func_021BF6CC(p+107,1,1); ((struct Obj00012 *)p)->f48=1; func_021B9BEC(((struct Obj00012 *)p)->f14,21); *q=1; break;
    case 1:
        switch(func_021BAC0C(((struct Obj00012 *)p)->f14)) {
        case 0: func_021B9BEC(((struct Obj00012 *)p)->f14,23); *q=2; break;
        case 1: func_021BD7A0(p,(void (*)(void))func_021BF4C4); *q=2; break;
        }
        break;
    case 2: if(func_021B9C74((unsigned int)(((struct Obj00012 *)p)->f14))) func_021BF500(p); break;
    }
}








int func_021BF680(u8 *p) {
    switch(((struct Obj08007 *)p)->f4) {
    case 0: if(((struct Obj08007 *)p)->f10!=65535) return 1; else return 0;
    case 1: if(((struct Obj08007 *)p)->f10!=65535 && ((struct Obj08007 *)p)->f12!=65535) return 1; else return 0;
    case 2: return PMSI_PARAM_IsComplete((struct T *)(p+8),42);
    }
    return 0;
}









void func_021BF6CC(u8 *p, u8 a, u8 b) { p[0] = b; p[1] = a; }









u8 *func_021BF6D4(u8 *p) { return p + 0x70; }









u32 func_021BF6D8(u8 *p) { return ((struct Obj22385 *)p)->f4; }









u8 func_021BF6DC(u8 *p) { return ((struct Obj22386 *)p)->f69; }








/*
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 PMSI_PARAM_GetSentenceType          -> unresolved: 0202452C (arm, from name) has no witness outside 021BF6E4..021BF6F0
 */
int func_021BF6E4(u8 *p) { return PMSI_PARAM_GetSentenceType((const u16 *)(p + 8)); }








u32 func_021BF6F0(u8 *p,u32 i) {
    if(((struct Obj22387 *)p)->f4==2) return PMSI_PARAM_GetWordRaw(p+8,i);
    return *(u16 *)((u32)p+i*2+0x10);
}








void *func_021BF708(u8 *p, u32 heapId) { return PMSI_PARAM_GetSourceString((const struct Struct_0202441C *)(p + 8), heapId); }









u16 func_021BF714(u8 *p) { return ((struct Obj22388 *)p)->f4A; }









u16 func_021BF71C(u8 *p) { return ((struct Obj22389 *)p)->f48; }









u16 func_021BF724(u8 *p) { return ((struct Obj22390 *)p)->f4C; }









u16 func_021BF72C(u8 *p) { return ((struct Obj22391 *)p)->f50; }








u32 func_021BF734(u8 *p) {
    if(p[0x69]==0) return func_021B999C(*(u8 * *)&((struct Obj08008 *)p)->f18,((struct Obj08008 *)p)->f4C)+2;
    else return func_021BB1C0(*(u8 * *)&((struct Obj08008 *)p)->f1C)+2;
}








void func_021BF758(u8 *p,u32 a,int b) {
    if(p[0x69]==0) func_021B99A4(((struct Obj08009 *)p)->f18,((struct Obj08009 *)p)->f4C,a,b);
    else func_021BB1CC(*(u8 * *)&((struct Obj08009 *)p)->f1C,a,b);
}








u32 func_021BF784(u8 *p) {
    if(((struct Obj22392 *)p)->f60!=0) return -1;
    return func_021BEDC4(p+0x54);
}








/*
 * Unblocked by matching func_021BEDE0 in ov110 (pkt_ov110_021BEDE0).
 */
int func_021BF7A0(u8 *p) { return func_021BEDE0(p + 0x54); }








unsigned func_021BF7AC(u8 *p) { return func_021BEDE4(p+0x54); }








/*
 * body: tail-forwards p+0x54 to EDE8, whose complete four-byte body is
 *   ldrh r0,[r0,#2]; bx lr. Widening that unsigned return preserves every bit.
 */
unsigned func_021BF7B8(u8 *p) { return func_021BEDE8(p+0x54); }








/*
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 PMSI_PARAM_HasInitialSentence          -> unresolved: 02024158 (arm, from name) has no witness outside 021BF7C4..021BF7D0
 */
u32 func_021BF7C4(u8 *p) { return PMSI_PARAM_HasInitialSentence((const u8 *)(((struct Obj22393 *)p)->f0)); }









u32 func_021BF7D0(u8 *p) { return ((struct Obj22394 *)p)->f7C; }








void func_021BF7D4(u8 *p, void *q) { func_021BB00C(((struct Obj22395 *)p)->f1C, q); }








void func_021BF7E0(u8 *p) { func_021BAFE4((u32)(*(u8 * *)&((struct Obj22396 *)p)->f1C)); }








void func_021BF7EC(const u8 *p,u16 *a,u16 *b) {
    *a=*(const u16 *)&((struct Obj13799 *)p)->f54;
    *b=*(const u16 *)&((struct Obj13799 *)p)->f56;
}







u8 func_021BF7FC(u8 *p) { return func_021BB1C0((u8 *)(((struct Obj22399 *)p)->f1C)); }







/*
 * Unblocked by matching func_021BAFDC in ov110 (pkt_ov110_021BAFDC).
 */
int func_021BF808(u8 *p) { return func_021BAFDC((u8 *)(((struct Obj22400 *)p)->f1C)); }







void func_021BF814(u8 *p,u32 a,int b) { func_021BB1CC(*(u8 * *)&((struct Obj22401 *)p)->f1C,a,b); }







int func_021BF824(u8 *a0) { return func_021BF680(a0); }







void func_021BF82C(u8 *p) {
    ((struct Obj00012 *)p)->f4C=0;
    ((struct Obj00012 *)p)->f4E=255;
    ((struct Obj00012 *)p)->f50=253;
}






u8 *func_021BF844(void *a,void *b,void *c) {
    u8 *p=func_02030734(42,160,0,d_021C3C84,154);
    ((struct Obj02819 *)p)->f0=a; ((struct Obj02819 *)p)->f4=b; ((struct Obj02819 *)p)->f8=c;
    ((struct Obj02819 *)p)->f48=STRBUF_Create(32,42);
    ((struct Obj02819 *)p)->fC=(void *)BMP_WIN_Create(2,3,0,26,32,13,1);
    ((struct Obj02819 *)p)->f10=(void *)BMP_WIN_Create(2,0,0,12,4,13,1);
    ((struct Obj02819 *)p)->f14=0; ((struct Obj02819 *)p)->f18=0;
    ((struct Obj02819 *)p)->f9C=func_021BF6D4(*(u8 * *)&((struct Obj02819 *)p)->f4);
    return p;
}






/*
 * note: two trailing zero alignment bytes.
 */
void func_021BF8BC(u8 *p) {
    if(*(struct Obj * *)&((struct Obj03755 *)p)->f14) CLACT_DeleteActor(*(struct Obj * *)&((struct Obj03755 *)p)->f14);
    if(*(struct Obj * *)&((struct Obj03755 *)p)->f1C) CLACT_DeleteActor(*(struct Obj * *)&((struct Obj03755 *)p)->f1C);
    if(*(struct U16Vec * *)&((struct Obj03755 *)p)->f48) STRBUF_Delete(*(struct U16Vec * *)&((struct Obj03755 *)p)->f48);
    func_020452E8(*(struct Descriptor * *)&((struct Obj03755 *)p)->f10);
    func_020452E8(*(struct Descriptor * *)&((struct Obj03755 *)p)->fC);
    func_020307B0(p);
}




void func_021BF8F4(u8 *p) {
    func_02040B94(2,32,0,42);
    func_02041300(2,0,0,0,32,32,13);
    BMP_Clear(func_02045770((struct Descriptor *)((struct Obj01145 *)p)->fC),0);
    BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj01145 *)p)->fC));
    BMP_WIN_TransferChars((struct Descriptor *)((struct Obj01145 *)p)->fC);
    func_020409B4(2); func_021BF94C((Obj *)p); func_02040588(2,0);
}




/*
 * extent: two bytes zero alignment padding at 0x021BF9EE.
 * lever: typed items member and z=i preserve indexed base and copied zero.
 */
void func_021BF94C(Obj *p) {
    Triple t;
    Triple s;
    int i;
    int z;
    i=0;
    func_021BAC64(p->root,&t,0,0);
    p->first=func_021BAC78(p->root,(unsigned int *)(&t),62,24,4,1);
    CLACT_SetActorAnimSeq(p->first,8);
    func_0204B3DC(p->first,0);
    p->second=func_021BAC78(p->root,(unsigned int *)(&t),244,18,5,1);
    CLACT_SetActorAnimSeq(p->second,18);
    func_0204B3DC(p->second,0);
    z=i;
    for(;i<10;i++) {
        func_021BAC50(p->root,(struct V3 *)(&s),z);
        p->items[i]=func_021BAC78(p->root,(unsigned int *)(&s),z,z,z,1);
        CLACT_SetActorAnimSeq(p->items[i],i);
        func_0204B3DC(p->items[i],z);
        CLACT_SetActorBgPriority(p->items[i],1);
    }
}




void func_021BF9F0(u8 *p) {
    unsigned y,i,n;
    BMP_Clear(func_02045770((struct Descriptor *)((struct Obj02166 *)p)->fC),0);
    func_021BFF60(p);
    n=func_021BF734(*(u8 * *)&((struct Obj02166 *)p)->f4);
    if(n>16) n=16;
    i=0;
    y=((struct Obj02166 *)p)->f94;
    for(;i<n;i++) {
        func_021BFF7C(p,i,y);
        if(i&1) y+=24;
    }
    BMP_WIN_TransferChars((struct Descriptor *)((struct Obj02166 *)p)->fC);
}



void func_021BFA40(u8 *p,unsigned a) {
    unsigned y,i,n;
    BMP_Clear(func_02045770((struct Descriptor *)((struct Obj02166 *)p)->fC),0);
    func_021BFF60(p);
    ((struct Obj02166 *)p)->f98=a*2;
    n=func_021BF734(*(u8 * *)&((struct Obj02166 *)p)->f4);
    if(n>16) n=16;
    i=0;
    y=((struct Obj02166 *)p)->f94;
    for(;i<n;i++) {
        func_021BFF7C(p,((struct Obj02166 *)p)->f98+i,y);
        if(i&1) y+=24;
    }
    BMP_WIN_TransferChars((struct Descriptor *)((struct Obj02166 *)p)->fC);
}



static inline void inside(Plane wnd,BOOL effect) {
    unsigned tmp=(*(volatile u16 *)0x04000048 & ~0x3f00) | ((unsigned)wnd<<8);
    if(effect) tmp|=0x2000;
    *(volatile u16 *)0x04000048=tmp;
}



static inline void outside(Plane wnd,BOOL effect) {
    unsigned tmp=(*(volatile u16 *)0x0400004a & ~0x3f) | (unsigned)wnd;
    if(effect) tmp|=0x20;
    *(volatile u16 *)0x0400004a=tmp;
}



static inline void wndpos(int x1,int y1,int x2,int y2) {
    *(volatile u16 *)0x04000042=(x1<<8)|x2;
    *(volatile u16 *)0x04000046=(y1<<8)|y2;
}



static inline void visible(Window wnd) {
    *(volatile unsigned *)0x04000000=(*(volatile unsigned *)0x04000000 & ~0xe000) | (wnd<<13);
}



/*
 * lever: outside window inline binds its masked load and plane OR in one
 *   initializer; splitting tmp and tmp |= wnd folds constants differently.
 * volatile: 0x021BFAD0 WININ, 0x021BFAF2 DISPCNT, 0x021BFB00 WINOUT,
 *   0x021BFB1E DISPCNT reads.
 */
void func_021BFAA0(u8 *p) {
    func_021BAD2C(*(u8 * *)&((struct Obj08010 *)p)->f0,1);
    func_0207D63C((void *)0x04000050,4,63,0,16);
    func_02040588(2,1);
    inside(31,1);
    ((struct Obj08010 *)p)->f8C=*(volatile u8 *)0x0400004a;
    ((struct Obj08010 *)p)->f90=(*(volatile unsigned *)0x04000000 & 0xe000)>>13;
    outside(27,1);
    wndpos(0,0,255,168);
    visible(2);
    ((struct Obj08010 *)p)->f88=0;
    func_021BC868(p+0x4c,4,63,0,124,12);
}







int func_021BFB58(u8 *p) {
    if(((struct Obj22402 *)p)->f88==0) {
        if(func_021BC898(p+0x4c)) return 1;
        else return 0;
    } else return 1;
}







void func_021BFB7C(u8 *p) {
    ((struct Obj22403 *)p)->f88=0;
    func_021BC868(p+0x4c,4,63,124,0,12);
}







static inline void outside_b(int wnd,int effect) {
    unsigned tmp=*(volatile u16 *)0x0400004a & ~0x3f;
    tmp|=wnd;
    if(effect) tmp|=0x20;
    *(volatile u16 *)0x0400004a=tmp;
}







static inline void visible_b(int window) {
    *(volatile unsigned *)0x04000000=(*(volatile unsigned *)0x04000000 & ~0xe000) | (window<<13);
}







int func_021BFBA0(u8 *p) {
    int i;
    if(((struct Obj13800 *)p)->f88==0) {
    if(func_021BC898(p+0x4c)) {
        for(i=0;i<10;i++) func_0204B3DC(*(void **)(p+0x20+4*i),0);
        func_02040588(2,0);
        outside_b(((Wnd *)(p+0x8c))->plane,((Wnd *)(p+0x8c))->effect);
        visible_b(((struct Obj13800 *)p)->f90);
        return 1;
    }
    } else return 1;
    return 0;
}







void func_021BFC20(u8 *p, unsigned visible) {
    if (visible) {
        if (**(unsigned * *)&((struct Obj04452 *)p)->f9C==0) func_0204B3DC(((struct Obj04452 *)p)->f14,1);
        else func_0204B3DC(((struct Obj04452 *)p)->f14,0);
        func_0204B3DC(((struct Obj04452 *)p)->f1C, func_021BF734(*(u8 * *)&((struct Obj04452 *)p)->f4)>14 ? 1 : 0);
    } else {
        func_0204B3DC(((struct Obj04452 *)p)->f14,visible);
        func_0204B3DC(((struct Obj04452 *)p)->f1C,0);
    }
}







/*
 * extent: two bytes of alignment padding follow the return.
 */
void func_021BFC64(u8 *p, unsigned i) {
    Vec2_021BFC64 pos;
    if (i != -1) {
        pos.x = 0x70*(i&1)+0x3e;
        pos.y = 0x18*((i>>1)+1);
        func_0204B404(((struct Obj13801 *)p)->f14, (const struct Vec2_021BFC64 *)(&pos), 0);
        CLACT_SetActorAnimSeq(((struct Obj13801 *)p)->f14, 8);
    }
}







void func_021BFCA4(u8 *p,int amount) {
    int count,i;
    u8 newy;
    int newstart,start,step;
    u8 y;
    func_021BFED0(p,amount);
    count=amount*2;
    start=((struct Obj03756 *)p)->f98;
    newstart=start+count;
    step=24*amount;
    newy=(u8)(((struct Obj03756 *)p)->f94+step);
    if(amount<0) {
        start=newstart;
        y=newy;
        count=-count;
        amount=-amount;
    } else {
        y=(u8)(((struct Obj03756 *)p)->f94+192);
        start+=16;
        if(count+start>func_021BF734(*(u8 * *)&((struct Obj03756 *)p)->f4)) count--;
    }
    for(i=0;i<count;i++) {
        func_021BFF7C(p,start+i,y);
        if(i&1) y+=24;
    }
    ((struct Obj03756 *)p)->f94=newy;
    ((struct Obj03756 *)p)->f98=newstart;
    BMP_WIN_TransferChars((struct Descriptor *)((struct Obj03756 *)p)->fC);
    BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj03756 *)p)->fC));
    func_021BC78C(p+0x6c,2,1,step,amount);
}







int func_021BFD60(u8 *p) { u16 x,y; if(func_021BC7DC(p+0x6c)) { func_021BF7EC(*(const u8 * *)&((struct Obj13802 *)p)->f4,&x,&y); func_021BFDB0(p,x,y); return 1; } return 0; }







u32 func_021BFD94(u8 *p,Vec2_021BFD94 *out) { u32 result; result=func_0204B3F4(((struct Obj13803 *)p)->f1C); CLACT_GetActorSurfacePos(((struct Obj13803 *)p)->f1C,(struct PtS *)out,0); return result; }





/*
 * lever: write clamp stores in their own arms before goto apply; low n==0
 *   has a shared label. Keep lower test as <18 and nest the upper test in else.
 */
void func_021BFDB0(u8 *p,unsigned a,unsigned n) {
    Vec2_021BFB58 pos;
    short lo,hi;
    pos.x=244;
    if(a==0) { pos.y=18; goto apply; }
    else if(a==n) { pos.y=149; goto apply; }
    else if(n==0) goto low;
    else {
        lo=132*a/(n+1)+18;
        hi=132*(a+1)/(n+1)+17;
        pos.y=(lo+hi)/2;
        if(pos.y<18) { pos.y=18; goto apply; }
        else {
            if(pos.y>149) { pos.y=149; goto apply; }
        }
    }
    goto apply;
low: pos.y=18;
apply:
    func_0204B404(((struct Obj13802 *)p)->f1C, (const struct Vec2_021BFC64 *)((const struct Vec2_021BFB58 *)(&pos)), 0);
}




void func_021BFE24(u8 *p,int y) { Vec2_021BFE24 pos; CLACT_GetActorSurfacePos((struct Actor *)((struct Obj13804 *)p)->f1C,(struct PtS *)&pos,0); pos.y=y; if(pos.y<18) pos.y=18; if(pos.y>149) pos.y=149; func_0204B404(((struct Obj13804 *)p)->f1C, (const struct Vec2_021BFC64 *)&pos, 0); }




unsigned func_021BFE60(u8 *p, unsigned n)
{
    int i;
    unsigned result;
    Vec2_021BFB58 pos;
    short y;
    func_021BFD94(p, (Vec2_021BFD94 *)((struct Vec2_021BFB58 *)(&pos)));
    if (n == 0) goto zero;
    else {
        y = pos.y;
        do {
            if (y == 18) { result = 0; goto end; }
            else if (y == 149) result = n;
            else {
                for (i = 0; i <= n; i = (short)(i + 1)) {
                    short lo, hi;
                    lo = 132 * (unsigned)i / (n + 1) + 18;
                    hi = 132 * (unsigned)(i + 1) / (n + 1) + 17;
                    if (lo > hi) hi = lo;
                    if (lo <= y && y <= hi) { result = (int)i; break; }
                }
            }
            goto end;
        } while (0);
        goto zero;
    }
    goto end;
zero: result = 0;
end:
    return result;
}




void func_021BFED0(u8 *p,int amount) {
    int start,end;
    if(amount>0) {
        start=(u8)(((struct Obj06392 *)p)->f94+192);
        end=(u8)(start+24*amount);
    } else {
        end=((struct Obj06392 *)p)->f94;
        start=(u8)(end+24*amount);
    }
    if(start<end) {
        BMP_FillRect(func_02045770((struct Descriptor *)((struct Obj06392 *)p)->fC),(short)0,(short)start,(u16)208,(u16)(end-start),(u8)0);
    } else {
        BMP_FillRect(func_02045770((struct Descriptor *)((struct Obj06392 *)p)->fC),(short)0,(short)start,(u16)208,(u16)(256-start),(u8)0);
        BMP_FillRect(func_02045770((struct Descriptor *)((struct Obj06392 *)p)->fC),(short)0,(short)0,(u16)208,(u16)end,(u8)0);
    }
}




void func_021BFF60(u8 *p) { ((struct Obj02166 *)p)->f94=0; ((struct Obj02166 *)p)->f98=0; func_02040618(2,3,8); }



void func_021BFF7C(u8 *p, u32 n, u32 y)
{
    u32 font;
    struct Pt pos;
    u32 wrap, x;
    struct Bmp *dest;
    font = func_021BAC44(*(u8 * *)&((struct Obj01533 *)p)->f0);
    if (n < 2 || n >= func_021BF734(*(u8 * *)&((struct Obj01533 *)p)->f4)) return;
    if (!func_021BF6DC(*(u8 * *)&((struct Obj01533 *)p)->f4) && func_021BF724(*(u8 * *)&((struct Obj01533 *)p)->f4) == 11) {
        x = 24 + 112 * ((n - 2) & 1);
        n = (n - 2) * 4;
        pos.x = x;
        pos.y = y - 8;
        p += 32;
        CLACT_SetActorPos(*(struct Actor **)(p + n), &pos);
        func_0204B3DC(*(struct Obj **)(p + n), 1);
        return;
    }
    func_021BF758(*(u8 * *)&((struct Obj01533 *)p)->f4, n - 2, (int)(((struct Obj01533 *)p)->f48));
    func_0201DD68();
    if (y <= 240) {
        PRINTSYS_Print(func_02045770(*(struct Descriptor * *)&((struct Obj01533 *)p)->fC), 112 * ((n - 2) & 1), y, ((struct Obj01533 *)p)->f48, (void *)font);
    } else {
        wrap = 256 - y;
        BMP_Clear(func_02045770(*(struct Descriptor * *)&((struct Obj01533 *)p)->f10), 0);
        PRINTSYS_Print(func_02045770(*(struct Descriptor * *)&((struct Obj01533 *)p)->f10), 0, 0, ((struct Obj01533 *)p)->f48, (void *)font);
        n = 112 * ((n - 2) & 1);
        dest = func_02045770(*(struct Descriptor * *)&((struct Obj01533 *)p)->f10);
        BMP_Blit(dest, func_02045770(*(struct Descriptor * *)&((struct Obj01533 *)p)->fC), 0, 0, n, y, 96, wrap, 65535);
        dest = func_02045770(*(struct Descriptor * *)&((struct Obj01533 *)p)->f10);
        BMP_Blit(dest, func_02045770(*(struct Descriptor * *)&((struct Obj01533 *)p)->fC), 0, wrap, n, 0, 96, 16 - wrap, 65535);
    }
}



void func_021C00AC(u8 *p, unsigned i) {
    Vec2_021BFF7C pos;
    ((struct Obj06393 *)p)->f18=func_0204B3F4(((struct Obj06393 *)p)->f14);
    func_0204B3DC(((struct Obj06393 *)p)->f14,1);
    if (i != -1) {
        pos.x=0x70*(i&1)+0x3e;
        pos.y=0x18*((i>>1)+1);
        func_0204B404(((struct Obj06393 *)p)->f14, (const struct Vec2_021BFC64 *)((const struct Vec2_021BFF7C *)(&pos)), 0);
        CLACT_SetActorAnimSeq(((struct Obj06393 *)p)->f14,0x1c);
    }
}



int func_021C00FC(u8 *p) { if(CLACT_GetActorAnimSeq(((struct Obj05298 *)p)->f14)!=28) return 1; if(!CLACT_IsActorAnimActive(((struct Obj05298 *)p)->f14)) { func_0204B3DC(((struct Obj05298 *)p)->f14,((struct Obj05298 *)p)->f18); CLACT_SetActorAnimSeq(((struct Obj05298 *)p)->f14,8); ((struct Obj05298 *)p)->f18=0; return 1; } return 0; }



int func_021C0134(void *owner,int unused,void **input) {
    u8 *p;
    func_02034AC4((unsigned)overlay_id);
    func_0207D534((void *)0x0400006c,-16);
    func_0207D534((void *)0x0400106c,-16);
    GFL_HEAP_CreateChildHeap(1,81,0x1c000);
    p=PROCSYS_AllocProcWork(owner,176,81);
    func_02082BCC(p,0,176);
    ((struct Obj01713 *)p)->f4=81;
    ((struct Obj01713 *)p)->f1C=*input;
    ((struct Obj01713 *)p)->f20=PMS_WORD_GetSaveData((int)(*input));
    *(void ** *)&((struct Obj01713 *)p)->f0=input;
    ((struct Obj01713 *)p)->f58=GF_FONT_Create(23,0,0,0,((struct Obj01713 *)p)->f4);
    ((struct Obj01713 *)p)->f60=func_02045B38(0,2,146,((struct Obj01713 *)p)->f4);
    ((struct Obj01713 *)p)->f5C=(void *)func_0201C440((void *)(((struct Obj01713 *)p)->f4));
    ((struct Obj01713 *)p)->fAC=PROCSYS_Create(((struct Obj01713 *)p)->f4);
    ((struct Obj01713 *)p)->f94=255;
    ((struct Obj01713 *)p)->f95=255;
    func_021C0490(p);
    return 1;
}



int func_021C01E4(void *p, int a, int b, char *q) {
    func_021C05B0(q);
    func_0203133C(((struct Obj06394 *)q)->fAC);
    func_0201C6EC(((struct Obj06394 *)q)->f5C);
    func_0201C4C0(((struct Obj06394 *)q)->f5C);
    MSGDATA_Delete(((struct Obj06394 *)q)->f60);
    GF_FONT_Delete(((struct Obj06394 *)q)->f58);
    func_020315D4(p);
    func_020306F0(0x51);
    func_02034A5C((int)ov067_id);
    return 1;
}



int func_021C022C(u8 *p) { if(func_0201C6B4(((struct Obj13806 *)p)->f5C) && PMS_DRAW_IsPrintEnd(((struct Obj13806 *)p)->f8C)) return 1; return 0; }



void func_021C0250(int *out,u8 *p,int value) { *out=value; ((struct Obj22406 *)p)->f9C=0; }
