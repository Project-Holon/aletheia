/*
 * file:     br_btn.c
 * unit:     yes
 * function: func_021F9CB8, func_021F9F48, func_021F9FE8, func_021FA004, func_021FA018, func_021FA01C, func_021FA020, func_021FA0A8, func_021FA0FC, func_021FA1DC, func_021FA210, func_021FA21C, func_021FA274, func_021FA284, func_021FA444, func_021FA500, func_021FA6A8, func_021FA758, func_021FA7FC, func_021FA920, func_021FAA34, func_021FAA74, func_021FAAD0, func_021FAB7C, func_021FAC20, func_021FACE0, func_021FAD04, func_021FAD18, func_021FAD74, func_021FADB8, func_021FAE70, func_021FAEC0, func_021FAEE4, func_021FAF08, func_021FAF24, func_021FAFA0, func_021FAFB0, func_021FAFC0, func_021FAFCC, func_021FAFD0, func_021FB058, func_021FB0E8, func_021FB1EC, func_021FB2F0, func_021FB378, func_021FB3BC, func_021FB494, func_021FB4B4, func_021FB4CC, func_021FB514, func_021FB548, func_021FB578, func_021FB594, func_021FB5A0, func_021FB5B8, func_021FB5C4, func_021FB5E4, func_021FB63C, func_021FB644, func_021FB704, func_021FB760, func_021FB788, func_021FB7B0, func_021FB7D0, func_021FB884, func_021FB92C, func_021FB964, func_021FBDA4, func_021FBE54, func_021FC0C8, func_021FC124, func_021FC148, func_021FC1F8, func_021FC20C, func_021FC214, func_021FC21C, func_021FC224, func_021FC230, func_021FC238, func_021FC240, func_021FC31C, func_021FC344, func_021FC36C, func_021FC394
 * address:  0x021F9CB8
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034714 0x02034714 arm
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   func_0201C440 0x0201C440 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   d_02200D18 0x02200D18 data a1
 *   d_02200D1C 0x02200D1C data a1
 *   func_021FD714  0x021FD714  thumb  ov186
 *   func_021FD15C  0x021FD15C  thumb  ov186
 *   func_020307B0  0x020307B0  arm
 *   BMP_OAM_DeleteSys  0x02025588  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_021FD71C 0x021FD71C thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_02035D20 0x02035D20 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   d_02200358 0x02200358 data a4
 *   STRBUF_Clone 0x02045874 arm
 *   memset 0x02082BCC arm
 *   _s32_div_f 0x0209C0A4 arm
 *   func_02045EC0 0x02045EC0 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B688 0x0204B688 arm
 *   BMP_Create 0x02043678 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_OAM_Create 0x020255A0 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 *   BMP_OAM_SetObjMode 0x0202597C thumb
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_Delete 0x020437AC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   func_0204B404 0x0204B404 arm
 *   BMP_OAM_SetPos 0x0202590C thumb
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   BMP_OAM_SetDrawPriority  0x020259C4  thumb
 *   CLACT_GetActorDrawPriority 0x0204B838 arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   BMP_OAM_SetBgPriority  0x02025A0C  thumb
 *   CLACT_GetActorBgPriority 0x0204B864 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   BMP_OAM_SetPalette 0x02025A54 thumb
 *   d_022007F0 0x022007F0 data a4
 *   d_02200D28 0x02200D28 data a1
 *   d_02200D38 0x02200D38 data a1
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   STRBUF_GetLength 0x020458F8 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC74 0x0201EC74 thumb
 *   d_02200D3C 0x02200D3C data a1
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020414EC 0x020414EC arm
 *   func_020409B4 0x020409B4 arm
 *   d_02200D48       0x02200D48  data
 *   CLACT_RegisterCharacter    0x0204A6C8  arm
 *   CLACT_RegisterPaletteEx    0x0204AC18  arm
 *   CLACT_RegisterCellAnim    0x0204AF28  arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   func_02049B68 0x02049B68 arm
 *   func_021FE8E8 0x021FE8E8 thumb ov186
 *   d_022008C0 0x022008C0 data a4
 *   d_022008A0 0x022008A0 data a4
 *   d_02200880 0x02200880 data a4
 *   d_022008E0 0x022008E0 data a4
 */
#include "../../matched/include/Obj01175.h"
#include "../../matched/include/Obj08326.h"
#include "../../matched/include/Obj10776.h"
#include "../../matched/include/Obj24816.h"
#include "../../matched/include/Obj24817.h"
#include "../../matched/include/Obj03339.h"
#include "../../matched/include/Obj01277.h"
#include "../../matched/include/Obj08328.h"
#include "../../matched/include/Obj14451.h"
#include "../../matched/include/Obj06627.h"
#include "../../matched/include/Obj00313.h"
#include "../../matched/include/Obj03890.h"
#include "../../matched/include/Obj00684.h"
#include "../../matched/include/Obj06628.h"
#include "../../matched/include/Obj06629.h"
#include "../../matched/include/Obj01278.h"
#include "../../matched/include/Obj02234.h"
#include "../../matched/include/Obj03340.h"
#include "../../matched/include/Obj05499.h"
#include "../../matched/include/Obj06630.h"
#include "../../matched/include/Obj10784.h"
#include "../../matched/include/Obj03891.h"
#include "../../matched/include/Obj08331.h"
#include "../../matched/include/Obj00080.h"
#include "../../matched/include/Obj14454.h"
#include "../../matched/include/Obj24819.h"
#include "../../matched/include/Obj14455.h"
#include "../../matched/include/Obj02900.h"
#include "../../matched/include/Obj24822.h"
#include "../../matched/include/Obj24823.h"
#include "../../matched/include/Obj01280.h"
#include "../../matched/include/Obj01281.h"
#include "../../matched/include/Obj01282.h"
#include "../../matched/include/Obj10785.h"
#include "../../matched/include/Obj10786.h"
#include "../../matched/include/Obj14456.h"
#include "../../matched/include/Obj24826.h"
#include "../../matched/include/Obj24827.h"
#include "../../matched/include/Obj14459.h"
#include "../../matched/include/Obj03892.h"
#include "../../matched/include/Obj14460.h"
#include "../../matched/include/Obj10788.h"
#include "../../matched/include/Obj02235.h"
#include "../../matched/include/Obj01770.h"
#include "../../matched/include/Obj24829.h"
#include "../../matched/include/Obj24830.h"
#include "../../matched/include/Obj24831.h"
#include "../../matched/include/Obj24832.h"
#include "../../matched/include/Obj24833.h"
#include "../../matched/include/Obj24834.h"
#include "../../matched/include/Obj05501.h"

struct U16Vec;
struct MsgBank;
struct PrintSys;
struct Pair;
struct Actor;
struct Grid;
struct Obj;
struct Param;
struct Sys;
struct Bmp;
struct Obj020437AC;
struct Node;
struct WordSet;
struct GfFont;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int   u32_021F9CB8;

struct Rec_021F9CB8 { u16 a, b; };

struct Set { struct Rec_021F9CB8 rec[6]; u32_021F9CB8 count; };

struct Obj {
    u16 heap;
    u16 pad0;
    int f4;
    int f8;
    int *fC;
    int f10;
    int f14;
    int pad18;
    int f1C;
    int pad20[6];
    u8 f38;
    u8 f39;
    u8 f3a;
    u8 f3b;
    char *f3c;
    char *f40;
    void *f44;
    void *f48;
    u32_021F9CB8 f4c;
    int pad50[2];
    int f58;
    struct Set *f5c;
};


typedef unsigned u32_021FA0A8;

typedef struct Button {
    int active;                 /* 0x00 */
    int enabled;                /* 0x04 */
    char *result;               /* 0x08 */
    void *object;               /* 0x0C */
    int (*update)(struct Button *); /* 0x10 */
    int dest_x;                 /* 0x14 */
    int dest_y;                 /* 0x18 */
    int state;                  /* 0x1C */
    s16 from, to, tick, duration; /* 0x20 */
    unsigned index;             /* 0x28 */
    int *pos;                   /* 0x2C */
    char *owner;                /* 0x30 */
    unsigned short heap, pad;   /* 0x34 */
    unsigned a;                 /* 0x38 */
    void *b;                    /* 0x3C */
    struct U16Vec *work;        /* 0x40 */
} Button;

typedef struct {int x,y;} Pair;

typedef unsigned int   u32;


typedef struct { unsigned short x,y,z; unsigned char flag,pad; } Config_021FAC20;


typedef struct Placement { short x, y; unsigned short animation; unsigned char priority, attr; } Placement;

typedef struct Config_021FADB8 { int words[3]; } Config_021FADB8;





typedef struct { s16 x,y;u16 f4;u8 f6,f7; } Point;

typedef struct { void *bmp;s16 x,y;u32 f8,fc;u8 f10,f11;u16 f12;u32 f14; } Param;

typedef struct { void *actor,*grid,*bmp;u32 fC,b,a; } Obj;

typedef struct { u32 x,y,z; } Triple_021FB3BC;

typedef struct PtS { s16 x, y; } PtS;

struct Vec2{short x,y;};

typedef struct Record_021FB3BC { unsigned short fields[12]; } Record_021FB3BC;

typedef struct Descriptor_021FB514 { unsigned short count, unused; const Record_021FB3BC *records; int unknown; } Descriptor_021FB514;

typedef struct {unsigned short count,unused;void *records;int unknown;} Descriptor_021FB760;

typedef struct Object {char pad[0xe8];void *a,*b,*c;volatile unsigned flag,mode;} Object;

struct Rec_021FAA74 {void *a,*b;unsigned char pad[12];void *handle;};

typedef signed int     s32;

typedef struct {unsigned a,b,c;} Triple_021FB514;

typedef signed char s8;

extern void func_02034714(const char *expr, u32_021F9CB8 line, const char *file);
extern void *func_02030734(u32_021F9CB8 heap, u32_021F9CB8 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, int);
extern void *BMP_OAM_CreateSys(u32_021F9CB8 a0, void *a1);
extern u32_021F9CB8 func_0201C440(void *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern int *func_021FD6D8(int payload, int callback, u32_021F9CB8 heap);
extern int *func_021FD73C(int *p, int v);
extern void func_021FD714(void *p);
extern void func_021FD15C(void *p, int a1);
extern u32_021F9CB8 func_020307B0(void *p);
extern void BMP_OAM_DeleteSys(void *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_021FD71C(u8 *p);
extern u32_021F9CB8 PRINTSYS_QUE_Main(struct PrintSys *);
extern void func_021FD1BC(void *p);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_020061E4(u32 a);
extern void func_021FD860(char *,unsigned,const Pair *);
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD170(char *p, char *q, void *text);
extern struct U16Vec *STRBUF_Clone(struct U16Vec *src, u32 heapId);
extern void *memset(void *,int,unsigned);
extern int _s32_div_f(int,int);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct Obj *CLACT_CreateActor(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void func_0204B688(struct Actor *actor, u32 value);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);
extern struct Grid *BMP_OAM_Create(struct Sys *sys, const struct Param *param);
extern void BMP_OAM_UploadChars(struct Obj *o);
extern void BMP_OAM_SetObjMode(u8 *,u32);
extern void BMP_OAM_Delete(struct Grid *);
extern void BMP_Delete(struct Obj020437AC *);
extern void CLACT_DeleteActor(struct Obj *);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void BMP_OAM_SetPos(struct Grid *,short,short);
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void BMP_OAM_SetDrawPriority(u8 *g, u32 a);
/* Callee's complete leaf reads only r0; legacy r1-r3 are unused, unforwarded. */
extern int CLACT_GetActorDrawPriority(int);
extern void CLACT_SetActorBgPriority(int, unsigned int);
extern void BMP_OAM_SetBgPriority(u8 *g, u32 a);
extern unsigned CLACT_GetActorBgPriority(unsigned char *);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void BMP_OAM_SetPalette(u8 *g, u32 a);
extern struct WordSet *func_0201EC64(unsigned int heap);
extern void func_0201EE0C(struct WordSet *p, unsigned int i, const void *src, unsigned int n, unsigned int f, unsigned int c);
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201ED04(struct WordSet *p);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_0201EC74(unsigned,unsigned,unsigned);
extern unsigned int MSGDATA_Delete(struct Rec_021FAA74 *rec);
extern unsigned int GF_FONT_Delete(void *ptr);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned short);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_020414EC(u32 i);
extern void func_020409B4(u32 index);
extern u32 CLACT_RegisterCharacter(void *h, u32 a1, u32 a2, u32 a3, u32 s0);
extern u32 CLACT_RegisterPaletteEx(void *h, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void func_02049B68(void *,unsigned,unsigned,unsigned,unsigned,unsigned);
extern void func_021FE8E8(char *p, void *arc, u32 file, u32 idx, u32 off, u32 count, u16 tag);
struct Obj *func_021F9CB8(int a, int b, int c, int d, int e, int f, u16 heap);
void func_021F9F48(u8 *p);
void func_021F9FE8(char *p);
int func_021FA004(char *p,int *x,int *y);
int func_021FA018(char *p);
int func_021FA01C(char *p);
void func_021FA020(u8 *ctx, int a1, int a2);
int func_021FA0A8(unsigned char *ctx, Button *out);
void func_021FA0FC(u8 *p,int section,const int *pos);
void func_021FA1DC(char *p,int x,int y);
void func_021FA210(char *p);
void func_021FA21C(unsigned char *ctx, int mode);
void func_021FA274(void *p);
void func_021FA284(void *p,int *state,unsigned char *ctx);
void func_021FA444(void *p, int *state, unsigned char *ctx);
void func_021FA500(void *p,int *state,u8 *ctx);
void func_021FA6A8(void *p, int *state, unsigned char *ctx);
void func_021FA758(void *p, int *state, unsigned char *ctx);
void func_021FA7FC(void *p,int *state,unsigned char *ctx);
void func_021FA920(int *task,int *state,u8 *ctx);
void func_021FAA34(void *p, int *state, int *ctx);
void func_021FAA74(void *p, int *state, unsigned *ctx);
void func_021FAAD0(void *p, int *state, unsigned char *ctx);
void func_021FAB7C(void *p, int *state, unsigned char *ctx);
void func_021FAC20(Button *ctx, void *object, unsigned a, void *b, char *owner, const void *arg, unsigned index, unsigned short heap);
void func_021FACE0(Button *p);
int func_021FAD04(Button *p, int x, int y);
void func_021FAD18(Button *ctx, int mode, const int *target);
int func_021FAD74(Button *ctx);
void func_021FADB8(Button *ctx, int mode);
void func_021FAE70(void *ctx, Button *dest, const Button *source, int mode);
void func_021FAEC0(Button *p, unsigned index);
void func_021FAEE4(Button *p, int *out);
void func_021FAF08(Button *p, int a1);
int func_021FAF24(Button *ctx, int kind);
void func_021FAFA0(Button *p, int b);
void func_021FAFB0(Button *p, int b);
void func_021FAFC0(Button *p, unsigned value);
void func_021FAFCC(Button *p, unsigned value);
int func_021FAFD0(Button *ctx);
int func_021FB058(Button *ctx);
int func_021FB0E8(Button *p);
int func_021FB1EC(Button *p);
int func_021FB2F0(Button *ctx);
void *func_021FB378(void *ctx, int file, unsigned short a, int b, int c, int d, int e, int archive, void *config, unsigned short heap);
Obj *func_021FB3BC(const Point *pt,void *data,u16 a,u32 b,u32 c,void *owner,void *font,const Triple_021FB3BC *triple,u16 heap);
void func_021FB494(char *p);
int func_021FB4B4(unsigned int *obj, int x, int y);
int func_021FB4CC(u32 *p, int a1, int a2);
void func_021FB514(char *p, short x, int y);
void func_021FB548(char *p,short *x,short *y);
void func_021FB578(int *p, unsigned char b);
int func_021FB594(char *p);
void func_021FB5A0(int *p, int b);
unsigned func_021FB5B8(char *p);
void func_021FB5C4(char *p,int n);
void *func_021FB5E4(int *ctx, int heap);
void func_021FB63C(void *p);
void func_021FB644(char *ctx);
void *func_021FB704(char *ctx, int section, unsigned item);
unsigned short func_021FB760(void *p,int i);
unsigned func_021FB788(void *p);
int func_021FB7B0(void *p,int i);
void *func_021FB7D0(unsigned *const *p,void *record,struct MsgBank *archive,unsigned short heap);
void *func_021FB884(unsigned mode,unsigned flag,unsigned heap);
void func_021FB92C(char *p);
void func_021FB964(void *ctx,unsigned kind,unsigned short heap);
void func_021FBDA4(int a,unsigned mode);
void func_021FBE54(char *base, u32 idx, u32 area);
void func_021FC0C8(char *p,unsigned i);
int func_021FC124(char *p,unsigned i,void *out);
void func_021FC148(char *p,unsigned i,unsigned heap);
void func_021FC1F8(int *p, int i);
unsigned func_021FC20C(char *p);
int func_021FC214(char *p);
int func_021FC21C(char *p);
int func_021FC224(char *p);
void func_021FC230(char *p,int v);
int func_021FC238(char *p);
void func_021FC240(char *p,void *owner,unsigned short heap);
unsigned short func_021FC31C(unsigned i);
unsigned short func_021FC344(unsigned i);
unsigned short func_021FC36C(unsigned i);
u16 func_021FC394(u32 n);
extern char d_02200D18[];
extern char d_02200D1C[];
extern const int d_02200358[];
extern const Descriptor_021FB514 d_022007F0[];
extern char d_02200D28[];
extern char d_02200D38[];
extern const char d_02200D3C[];
extern char d_02200D48[];
extern const unsigned d_022008C0[];
extern const unsigned d_022008A0[];
extern const unsigned d_02200880[];
extern const u32 d_022008E0[];





struct Obj *func_021F9CB8(int a, int b, int c, int d, int e, int f, u16 heap)
{
    struct Obj *p;
    int tmp;
    int size;
    int i;
    int arch;
    u8 buf[0x44];
    if (a >= 12) func_02034714(d_02200D18, 0, d_02200D18);
    p = func_02030734(heap, 0x60, 0, d_02200D1C, 0x13F);
    func_02082BCC(p, 0, 0x60);
    p->f4 = c;
    p->f8 = b;
    p->heap = heap;
    p->f5c = (struct Set *)e;
    p->f48 = BMP_OAM_CreateSys(heap, (void *)b);
    p->f4c = func_0201C440((void *)heap);
    p->f58 = f;
    p->f14 = 1;
    func_02082BCC(&tmp, 0, 4);
    tmp = d;
    p->f44 = func_021FB5E4(&tmp, heap);
    if (a >= 10) p->f10 = 2;
    else p->f10 = 0;
    func_021FBE54((char *)p->f4, p->f10, heap);
    func_021FBE54((char *)p->f4, p->f10 + 1, heap);
    p->f38 = func_021FB788(p->f44);
    size = p->f38 * 0x44;
    p->f40 = func_02030734(heap, size, 0, d_02200D1C, 0x167);
    func_02082BCC(p->f40, 0, size);
    p->f3a = 6;
    p->f3c = func_02030734(heap, 0x198, 0, d_02200D1C, 0x171);
    func_02082BCC(p->f3c, 0, 0x198);
    p->fC = func_021FD6D8((int)p, (int)func_021FA274, heap);
    if (p->f5c->count != 0) {
        arch = func_021FC214((char *)c);
        for (i = 0; i < p->f5c->count; i++) {
            void *q = func_021FB704(p->f44, p->f5c->rec[i].a, (unsigned short)p->f5c->rec[i].b);
            void *rec = func_021FB7D0(p->f44, q, (struct MsgBank *)arch, (heap & 0x7FFF) | 0x8000);
            func_02082BCC(buf, 0, 0x44);
            func_021FAC20((Button *)buf, q, b, p->f48, (char *)c, rec, p->f10, heap);
            func_021FA020((u8 *)p, (int)buf, 0);
            STRBUF_Delete(rec);
        }
        for (i = 0; i < p->f3b; i++)
            func_021FAEC0((Button *)(p->f3c + (p->f3b - i - 1) * 0x44), (unsigned short)i);
        func_021FD73C(p->fC, (int)func_021FA920);
        p->f1C = 2;
    } else {
        arch = func_021FC214((char *)c);
        p->f39 = func_021FB760(p->f44, a);
        for (i = 0; i < p->f39; i++) {
            void *q = func_021FB704(p->f44, a, (unsigned short)i);
            void *rec = func_021FB7D0(p->f44, q, (struct MsgBank *)arch, (heap & 0x7FFF) | 0x8000);
            func_021FAC20((Button *)(p->f40 + i * 0x44), q, b, p->f48, (char *)c, rec, p->f10, heap);
            STRBUF_Delete(rec);
        }
        for (i = 0; i < p->f39; i++)
            func_021FAF08((Button *)(p->f40 + i * 0x44), 0xe0);
        func_021FD73C(p->fC, (int)func_021FAAD0);
    }
    return p;
}






void func_021F9F48(u8 *p)
{
    int i;

    func_021FD714((void *)(((struct Obj01175 *)p)->fC));
    if (((struct Obj01175 *)p)->f50 != 0) {
        func_021FD15C((void *)(((struct Obj01175 *)p)->f50), ((struct Obj01175 *)p)->f4);
        ((struct Obj01175 *)p)->f50 = 0;
    }
    for (i = 0; i < ((struct Obj01175 *)p)->f3B; i++)
        func_021FACE0((Button *)(((struct Obj01175 *)p)->f3C + i * 0x44));
    func_020307B0((void *)((struct Obj01175 *)p)->f3C);
    for (i = 0; i < ((struct Obj01175 *)p)->f39; i++)
        func_021FACE0((Button *)(((struct Obj01175 *)p)->f40 + i * 0x44));
    func_020307B0((void *)((struct Obj01175 *)p)->f40);
    func_021FC0C8((char *)(((struct Obj01175 *)p)->f4), ((struct Obj01175 *)p)->f10);
    func_021FC0C8((char *)(((struct Obj01175 *)p)->f4), ((struct Obj01175 *)p)->f10 + 1);
    func_021FB63C((void *)(((struct Obj01175 *)p)->f44));
    BMP_OAM_DeleteSys((void *)(((struct Obj01175 *)p)->f48));
    func_0201C4C0((struct PrintSys *)(((struct Obj01175 *)p)->f4C));
    func_020307B0(p);
}





void func_021F9FE8(char *p) { func_021FD71C((u8 *)(((struct Obj08326 *)p)->fC));PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct Obj08326 *)p)->f4C);if(*(char * *)&((struct Obj08326 *)p)->f50)func_021FD1BC(*(char * *)&((struct Obj08326 *)p)->f50); }





/*
 * blocker-leaf: ov183 021DB770; source/unit/shard ownership checked, parent cleared.
 */
int func_021FA004(char *p,int *x,int *y){if(x)*x=((struct Obj10776 *)p)->f24;if(y)*y=((struct Obj10776 *)p)->f28;return ((struct Obj10776 *)p)->f18;}





int func_021FA018(char *p){return ((struct Obj24816 *)p)->f14;}





int func_021FA01C(char *p){return ((struct Obj24817 *)p)->f54;}






void func_021FA020(u8 *ctx, int a1, int a2)
{
    int i;

    if (ctx[0x3b] >= ctx[0x3a])
        func_02034714((const char *)d_02200D18, 0, (const char *)d_02200D18);
    func_021FAE70(ctx, (Button *)(*(u8 * *)&((struct Obj03339 *)ctx)->f3C + ctx[0x3b] * 0x44), (const Button *)a1, a2);
    ctx[0x3b]++;
    for (i = 0; i < ctx[0x3b]; i++) {
        func_021FAFA0((Button *)(*(u8 * *)&((struct Obj03339 *)ctx)->f3C + i * 0x44), (u16)((ctx[0x3b] - i) * 2 + 1));
        func_021FAFB0((Button *)(*(u8 * *)&((struct Obj03339 *)ctx)->f3C + i * 0x44), 1);
    }
}




int func_021FA0A8(unsigned char *ctx, Button *out)
{
    if (ctx[0x3b]) {
        ctx[0x3b]--;
        *out = (*(Button **)(ctx + 0x3c))[ctx[0x3b]];
        func_02082BCC(&(*(Button **)(ctx + 0x3c))[ctx[0x3b]], 0, 0x44);
        return 1;
    }
    return 0;
}




void func_021FA0FC(u8 *p,int section,const int *pos)
{
 int i,bank;
 void *rec,*text;
 for(i=0;i<p[0x38];i++)func_021FACE0((Button *)(*(u8 * *)&((struct Obj01277 *)p)->f40+i*0x44));
 bank=func_021FC214(*(char * *)&((struct Obj01277 *)p)->f4);
 p[0x39]=func_021FB760(((struct Obj01277 *)p)->f44,section);
 for(i=0;i<p[0x39];i++){
  rec=func_021FB704(*(char * *)&((struct Obj01277 *)p)->f44,section,(u16)i);
  text=func_021FB7D0(*(unsigned *const * *)&((struct Obj01277 *)p)->f44,rec,(struct MsgBank *)bank,(((struct Obj01277 *)p)->f0&0x7fff)|0x8000);
  func_021FAC20((Button *)(*(u8 * *)&((struct Obj01277 *)p)->f40+i*0x44), rec, ((struct Obj01277 *)p)->f8, (void *)(((struct Obj01277 *)p)->f48), (char *)(((struct Obj01277 *)p)->f4), text, ((struct Obj01277 *)p)->f10, ((struct Obj01277 *)p)->f0);
  STRBUF_Delete(text);
  func_021FAFA0((Button *)(*(u8 * *)&((struct Obj01277 *)p)->f40+i*0x44), 3);
  if(pos)func_021FB514(*(void **)(*(u8 * *)&((struct Obj01277 *)p)->f40+i*0x44+8),pos[0],(short)pos[1]);
 }
}




void func_021FA1DC(char *p,int x,int y) { if(((struct Obj08328 *)p)->f18>=6)func_02034714(d_02200D18,0,d_02200D18);*(unsigned short *)((unsigned)p+((struct Obj08328 *)p)->f18*4)=x;*(unsigned short *)((unsigned)p+((struct Obj08328 *)p)->f18*4+2)=y;(((struct Obj08328 *)p)->f18)++; }



void func_021FA210(char *p) { if (((struct Obj14451 *)p)->f18!=0) (((struct Obj14451 *)p)->f18)--; }



void func_021FA21C(unsigned char *ctx, int mode)
{
    int i, selected;
    for (i = 0; i < ctx[0x3b]; i++) {
        switch (mode) {
        case 0: selected = (i == ctx[0x3b] - 1); break;
        case 1: selected = (i >= ctx[0x3b] - 2); break;
        }
        if (selected)
            func_021FAFC0((Button *)(*(char * *)&((struct Obj06627 *)ctx)->f3C + i * 0x44), 0);
        else
            func_021FAFC0((Button *)(*(char * *)&((struct Obj06627 *)ctx)->f3C + i * 0x44), 1);
    }
}



void func_021FA274(void *p)
{
    func_021FD73C(p, (int)func_021FA284);
}



void func_021FA284(void *p,int *state,unsigned char *ctx)
{
 int found,i,x,y,kind;
 found=0;((struct Obj00313 *)ctx)->f18=0;((struct Obj00313 *)ctx)->f14=0;
 if(func_02035D20((u32 *)(&x),(u32 *)(&y))){
  for(i=0;i<ctx[0x38];i++){
   if(func_021FAD04((Button *)(int *)(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44), x, y)){
    if(func_021FAF24((Button *)(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44), 3)){
     if(((struct Obj00313 *)ctx)->f50){
      func_021FD15C((void *)(((struct Obj00313 *)ctx)->f50),((struct Obj00313 *)ctx)->f4);
      ((struct Obj00313 *)ctx)->f50=0;
     }
     func_020061E4(0x703);
     ((struct Obj00313 *)ctx)->f2C=i;
     found=1;
     ((struct Obj00313 *)ctx)->f30=x;((struct Obj00313 *)ctx)->f34=y;
     func_021FD860(*(char * *)&((struct Obj00313 *)ctx)->f58,7,(Pair *)(ctx+0x30));
     func_021FAFCC((Button *)(*(char * *)&((struct Obj00313 *)ctx)->f40+((struct Obj00313 *)ctx)->f2C*0x44), (unsigned int)((Pair *)(ctx+0x30)));
     ((struct Obj00313 *)ctx)->f54=0;
    }else{
     kind=func_021FAF24((Button *)(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44), 5);
     func_021FAF24((Button *)(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44), 6);
     func_020061E4(0x704);
     if(kind==1){((struct Obj00313 *)ctx)->f2C=i;func_021FD73C(p,(int)func_021FAA74);}
    }
    break;
   }
  }
 }
 if(found){
  ((struct Obj00313 *)ctx)->f14=1;
  *(int *)&((struct Obj00313 *)ctx)->f1C=func_021FAF24((Button *)(*(char * *)&((struct Obj00313 *)ctx)->f40+((struct Obj00313 *)ctx)->f2C*0x44), 0);
  ((struct Obj00313 *)ctx)->f20=func_021FAF24((Button *)(*(char * *)&((struct Obj00313 *)ctx)->f40+((struct Obj00313 *)ctx)->f2C*0x44), 3);
  ((struct Obj00313 *)ctx)->f24=func_021FAF24((Button *)(*(char * *)&((struct Obj00313 *)ctx)->f40+((struct Obj00313 *)ctx)->f2C*0x44), 1);
  ((struct Obj00313 *)ctx)->f28=func_021FAF24((Button *)(*(char * *)&((struct Obj00313 *)ctx)->f40+((struct Obj00313 *)ctx)->f2C*0x44), 2);
  for(i=0;i<ctx[0x39];i++){
   if(i==((struct Obj00313 *)ctx)->f2C)func_021FAFA0((Button *)(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44), 1);
   else func_021FAFA0((Button *)(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44), 3);
  }
  switch(((struct Obj00313 *)ctx)->f1C){
  case 2:func_021FD73C(p,(int)func_021FA758);break;
  case 0:case 1:case 4:func_021FD73C(p,(int)func_021FA444);break;
  case 3:func_021FD73C(p,(int)func_021FAB7C);break;
  default:func_021FD73C(p,(int)func_021FAA34);break;
  }
 }
}



void func_021FA444(void *p, int *state, unsigned char *ctx)
{
    int i, ready;
    int values[2];
    switch (*state) {
    case 0:
        for (i = 0; i < ctx[0x39]; i++) {
            if (((struct Obj03890 *)ctx)->f2C != i) {
                func_021FAEE4((Button *)(*(char * *)&((struct Obj03890 *)ctx)->f40 + ((struct Obj03890 *)ctx)->f2C * 0x44), values);
                func_021FAD18((Button *)(*(char * *)&((struct Obj03890 *)ctx)->f40 + i * 0x44), 0, values);
            }
        }
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx[0x39]; i++)
            ready &= func_021FAD74((Button *)(*(char * *)&((struct Obj03890 *)ctx)->f40 + i * 0x44));
        if (ready) *state = 2;
        break;
    case 2:
        if (((struct Obj03890 *)ctx)->f1C == 4) {
            func_021FD73C(p, (int)func_021FA500);
            return;
        } else {
            func_021FD73C(p, (int)func_021FA500);
        }
        break;
    }
}



/*
 * lever: unsigned mode <= 1 range guard retains the original compare chain; switch(0,1,2) differs.
 */
void func_021FA500(void *p,int *state,u8 *ctx)
{
 int section,index,value,i,y;
 int pos[2],other[2];
 Button record;
 if(((struct Obj00684 *)ctx)->f1C<=1){
  section=((struct Obj00684 *)ctx)->f24;
  func_021FAEE4((Button *)(*(char * *)&((struct Obj00684 *)ctx)->f40+((struct Obj00684 *)ctx)->f2C*0x44), pos);
  func_021FA020(ctx,(int)(*(char * *)&((struct Obj00684 *)ctx)->f40+((struct Obj00684 *)ctx)->f2C*0x44),1);
  index=((struct Obj00684 *)ctx)->f2C;
  value=func_021FAF24((Button *)(*(char * *)&((struct Obj00684 *)ctx)->f40+index*0x44), 4);
  func_021FA1DC(((struct Obj00684 *)ctx)->f5C,(u16)value,(u16)index);
  func_02082BCC(*(char * *)&((struct Obj00684 *)ctx)->f40+((struct Obj00684 *)ctx)->f2C*0x44,0,0x44);
  pos[1]=-32;
  func_021FA0FC(ctx,section,pos);
  func_021FD73C(p,(int)func_021FA7FC);
 }else if(((struct Obj00684 *)ctx)->f1C==2){
  func_021FA210(((struct Obj00684 *)ctx)->f5C);
  if(func_021FA0A8(ctx, (Button *)&record)){
   section=func_021FAF24((Button *)&record, 4);
   if(!record.active)func_02034714(d_02200D18,0,d_02200D18);
   other[0]=func_021FB7B0(record.object,0);
   other[1]=func_021FB7B0(record.object,1);
   func_021FA0FC(ctx,section,other);
   y=func_021FB7B0(record.object,1);
   for(i=0;i<ctx[0x39];i++){
    if(y==func_021FB7B0((void *)(*(int *)(*(char * *)&((struct Obj00684 *)ctx)->f40+i*0x44+0xc)),1))
     func_021FAFA0((Button *)(*(char * *)&((struct Obj00684 *)ctx)->f40+i*0x44), 1);
   }
   func_021FACE0((Button *)(&record));
   func_021FD73C(p,(int)func_021FA6A8);
  }
 }else{
  func_021FA020(ctx,(int)(*(char * *)&((struct Obj00684 *)ctx)->f40+((struct Obj00684 *)ctx)->f2C*0x44),1);
  index=((struct Obj00684 *)ctx)->f2C;
  value=func_021FAF24((Button *)(*(char * *)&((struct Obj00684 *)ctx)->f40+index*0x44), 4);
  func_021FA1DC(((struct Obj00684 *)ctx)->f5C,(u16)value,(u16)index);
  func_02082BCC(*(char * *)&((struct Obj00684 *)ctx)->f40+((struct Obj00684 *)ctx)->f2C*0x44,0,0x44);
  for(i=0;i<ctx[0x39];i++)func_021FACE0((Button *)(*(char * *)&((struct Obj00684 *)ctx)->f40+i*0x44));
  func_021FD73C(p,(int)func_021FA7FC);
 }
}



void func_021FA6A8(void *p, int *state, unsigned char *ctx)
{
    int i, ready;
    switch (*state) {
    case 0:
        for (i = 0; i < ctx[0x39]; i++)
            func_021FAD18((Button *)(*(char * *)&((struct Obj06628 *)ctx)->f40 + i * 0x44), 1, 0);
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx[0x39]; i++)
            ready &= func_021FAD74((Button *)(*(char * *)&((struct Obj06628 *)ctx)->f40 + i * 0x44));
        if (ready) *state = 2;
        break;
    case 2:
        switch (((struct Obj06628 *)ctx)->f1C) {
        case 0: case 1: func_021FD73C(p, (int)func_021FAA34); break;
        case 4: func_021FD73C(p, (int)func_021FA7FC); break;
        default: func_021FD73C(p, (int)func_021FAA34); break;
        }
        break;
    }
}



void func_021FA758(void *p, int *state, unsigned char *ctx)
{
    int i, ready;
    int values[2];
    switch (*state) {
    case 0:
        for (i = 0; i < ctx[0x39]; i++) {
            func_021FAEE4((Button *)(*(char * *)&((struct Obj06629 *)ctx)->f40 + i * 0x44), values);
            values[1] = 0xe0;
            func_021FAD18((Button *)(*(char * *)&((struct Obj06629 *)ctx)->f40 + i * 0x44), 4, values);
        }
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx[0x39]; i++)
            ready &= func_021FAD74((Button *)(*(char * *)&((struct Obj06629 *)ctx)->f40 + i * 0x44));
        if (ready) *state = 2;
        break;
    case 2: func_021FD73C(p, (int)func_021FA920); break;
    }
}



void func_021FA7FC(void *p,int *state,unsigned char *ctx)
{
 int i,ready,kind;
 unsigned short value;
 char *entry;
 switch(*state){
 case 0:
  for(i=0;i<ctx[0x3b];i++){
   if(i==ctx[0x3b]-1)func_021FAD18((Button *)(*(char * *)&((struct Obj01278 *)ctx)->f3C+i*0x44), 2, d_02200358);
   else func_021FAD18((Button *)(*(char * *)&((struct Obj01278 *)ctx)->f3C+i*0x44), 4, d_02200358+(ctx[0x3b]-i-1)*2);
  }
  *state=1;break;
 case 1:
  ready=1;
  for(i=0;i<ctx[0x3b];i++)ready&=func_021FAD74((Button *)(*(char * *)&((struct Obj01278 *)ctx)->f3C+i*0x44));
  if(ready){func_021FA21C(ctx,0);*state=2;}break;
 case 2:
  entry=*(char * *)&((struct Obj01278 *)ctx)->f3C+(ctx[0x3b]-1)*0x44;
  kind=func_021FAF24((Button *)entry, 0);
  value=func_021FAF24((Button *)entry, 2);
  if(kind==1){
   if(!((struct Obj01278 *)ctx)->f50)((struct Obj01278 *)ctx)->f50=func_021FD12C((int)(((struct Obj01278 *)ctx)->f4),(void *)(((struct Obj01278 *)ctx)->f4C),((struct Obj01278 *)ctx)->f0);
   func_021FD170(((struct Obj01278 *)ctx)->f50,((struct Obj01278 *)ctx)->f4,(void *)value);
  }
  *state=3;break;
 case 3:
  switch(((struct Obj01278 *)ctx)->f1C){
  case 0:case 1:func_021FD73C(p,(int)func_021FA6A8);break;
  default:func_021FD73C(p,(int)func_021FAA34);break;
  }
  break;
 }
}



void func_021FA920(int *task,int *state,u8 *ctx)
{
    int position[2];
    int i;
    int ready;
    switch(*state) {
    case 0:
        for(i=0;i<ctx[0x3B];i++) {
            if(i==ctx[0x3B]-1) {
                position[0]=func_021FB7B0(*(void **)(*(u8 * *)&((struct Obj02234 *)ctx)->f3C+i*0x44+0xC),0);
                position[1]=func_021FB7B0(*(void **)(*(u8 * *)&((struct Obj02234 *)ctx)->f3C+i*0x44+0xC),1);
                func_021FAD18((Button *)(*(char * *)&((struct Obj02234 *)ctx)->f3C+i*0x44), 3, position);
                func_021FAFA0((Button *)(*(char * *)&((struct Obj02234 *)ctx)->f3C+i*0x44), 1);
            } else func_021FAD18((Button *)(*(char * *)&((struct Obj02234 *)ctx)->f3C+i*0x44), 4, (const int *)((unsigned)d_02200358+(ctx[0x3B]-i-2)*8));
        }
        for(i=0;i<ctx[0x39];i++)func_021FAFA0((Button *)(*(char * *)&((struct Obj02234 *)ctx)->f40+i*0x44), 3);
        *state=1;
        break;
    case 1:
        ready=1;
        for(i=0;i<ctx[0x3B];i++)ready&=func_021FAD74((Button *)(*(char * *)&((struct Obj02234 *)ctx)->f3C+i*0x44));
        if(ready){func_021FA21C(ctx,1);*state=2;}
        break;
    case 2:func_021FD73C(task,(int)func_021FA500);break;
    }
}



void func_021FAA34(void *p, int *state, int *ctx)
{
    if (*state == 0) {
        if (ctx[8]) {
            switch (ctx[7]) {
            case 0: case 1: case 2: break;
            case 3: ctx[6] = 2; break;
            case 4: ctx[6] = 1; break;
            }
        }
        func_021FD73C(p, (int)func_021FA284);
    }
}




void func_021FAA74(void *p, int *state, unsigned *ctx)
{
    int value;
    switch (*state) {
    case 0:
        value = func_021FAF24((Button *)(ctx[16] + ctx[11] * 0x44), 6);
        if (ctx[20] == 0)
            ctx[20] = (unsigned)func_021FD12C((int)((void *)ctx[1]), (void *)ctx[19], ((struct Obj03340 *)ctx)->f0);
        func_021FD170((void *)ctx[20], (void *)ctx[1], (void *)value);
        *state = 1;
        break;
    case 1: *state = 2; break;
    case 2: func_021FD73C(p, (int)func_021FA284); break;
    }
}




void func_021FAAD0(void *p, int *state, unsigned char *ctx)
{
    int i, ready;
    int values[2];
    switch (*state) {
    case 0:
        for (i = 0; i < ctx[0x39]; i++) {
            values[0] = func_021FAF24((Button *)(*(char * *)&((struct Obj05499 *)ctx)->f40 + i * 0x44), 8);
            values[1] = func_021FAF24((Button *)(*(char * *)&((struct Obj05499 *)ctx)->f40 + i * 0x44), 9);
            func_021FAD18((Button *)(*(char * *)&((struct Obj05499 *)ctx)->f40 + i * 0x44), 4, values);
        }
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx[0x39]; i++)
            ready &= func_021FAD74((Button *)(*(char * *)&((struct Obj05499 *)ctx)->f40 + i * 0x44));
        if (ready) *state = 2;
        break;
    case 2: func_021FD73C(p, (int)func_021FA274); break;
    }
}




void func_021FAB7C(void *p, int *state, unsigned char *ctx)
{
    int i, ready;
    int values[2];
    switch (*state) {
    case 0:
        for (i = 0; i < ctx[0x39]; i++) {
            func_021FAEE4((Button *)(*(char * *)&((struct Obj06630 *)ctx)->f40 + i * 0x44), values);
            values[1] = 0xe0;
            func_021FAD18((Button *)(*(char * *)&((struct Obj06630 *)ctx)->f40 + i * 0x44), 4, values);
        }
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx[0x39]; i++)
            ready &= func_021FAD74((Button *)(*(char * *)&((struct Obj06630 *)ctx)->f40 + i * 0x44));
        if (ready) *state = 2;
        break;
    case 2: func_021FD73C(p, (int)func_021FAA34); break;
    }
}




/*
 * lever: 02045874 takes the source and heap, forwarding r1 unchanged to its allocator.
 * evidence: matched arm9/STRBUF_Clone.c; original 021FAC58 loads heap into r1,
 * then loads source into r0 at021FAC5A before storing heap and calling021FAC62.
 */
void func_021FAC20(Button *ctx, void *object, unsigned a, void *b, char *owner, const void *arg, unsigned index, unsigned short heap)
{
    unsigned info[3];
    Config_021FAC20 config;
    const void *work;
    unsigned short heap_value;
    if (ctx->active) func_02034714(d_02200D18, 0, d_02200D18);
    func_02082BCC(ctx, 0, 0x44);
    ctx->active = 1;
    ctx->enabled = 1;
    ctx->object = object;
    ctx->index = index;
    ctx->owner = owner;
    heap_value = heap;
    work = arg;
    ctx->heap = heap_value;
    ctx->a = a;
    ctx->b = b;
    ctx->work = STRBUF_Clone((struct U16Vec *)work, heap_value);
    func_02082BCC(&config, 0, 8);
    config.x = func_021FB7B0(ctx->object, 0);
    config.y = func_021FB7B0(ctx->object, 1);
    config.z = func_021FB7B0(ctx->object, 4);
    config.flag = 1;
    func_021FC124(owner, ctx->index + 1, info);
    ctx->result = (char *)func_021FB3BC((const Point *)&config, ctx->work, 0xa0, ctx->enabled, a, b, (void *)func_021FC20C(owner), (const Triple_021FB3BC *)info, (unsigned short)((heap & 0x7fff) | 0x8000));
}




void func_021FACE0(Button *p)
{
    if (p->active != 0) {
        STRBUF_Delete(p->work);
        func_021FB494(p->result);
        memset(p, 0, 0x44);
    }
}





/*
 * func_021FB4CC reads r0, r1, r2 (obj, x, y); this function forwards its
 * incoming r1 and r2 untouched.  Naming them keeps r1 and r2 live, which is
 * why the original tests p[0] in r3 (the old one-parameter spelling put it
 * in r1 and missed by 2 bytes).
 */
int func_021FAD04(Button *p, int x, int y)
{
    if (p->active != 0)
        return func_021FB4CC((u32 *)p->result, x, y);
    return 0;
}




void func_021FAD18(Button *ctx, int mode, const int *target)
{
    ctx->state = 0;
    if (target) {
        ctx->dest_x = target[0];
        ctx->dest_y = target[1];
    }
    switch (mode) {
    case 0: ctx->update = func_021FAFD0; break;
    case 1: ctx->update = func_021FB058; break;
    case 2: ctx->update = func_021FB0E8; break;
    case 3: ctx->update = func_021FB1EC; break;
    case 4: ctx->update = func_021FB2F0; break;
    }
}




/*
 * tail: 021FADB6..021FADB8 is two zero alignment bytes.
 */
int func_021FAD74(Button *ctx)
{
    short x, y;
    int result;
    if (ctx->update != 0) {
        result = ctx->update(ctx);
        if (result != 0) ctx->update = 0;
        if (ctx->pos != 0) {
            func_021FB548(ctx->result, &x, &y);
            ctx->pos[0] = x + 80;
            ctx->pos[1] = y;
        }
        return result;
    }
    return 1;
}




void func_021FADB8(Button *ctx, int mode)
{
    Config_021FADB8 config;
    Placement placement;
    short x, y;
    int priority;
    int attr;
    int shift;
    unsigned resource;
    if (ctx->enabled == mode) return;
    ctx->enabled = mode;
    func_021FB548(ctx->result, &x, &y);
    priority = func_021FB594(ctx->result);
    attr = func_021FB5B8(ctx->result);
    func_021FB494(ctx->result);
    ctx->pos = 0;
    shift = mode == 0 ? 512 : -512;
    memset(&placement, 0, sizeof(placement));
    placement.x = x;
    placement.y = y + shift;
    placement.animation = func_021FB7B0(ctx->object, 4);
    placement.priority = priority;
    placement.attr = attr;
    func_021FC124(ctx->owner, ctx->index + mode, &config);
    resource = func_021FC20C(ctx->owner);
    func_021FC214(ctx->owner);
    func_021FB7B0(ctx->object, 3);
    ctx->result = (char *)func_021FB3BC((const Point *)&placement, ctx->work, 160, mode, ctx->a, ctx->b, (void *)resource, (const Triple_021FB3BC *)&config, ctx->heap);
}




void func_021FAE70(void *ctx, Button *dest, const Button *source, int mode)
{
    if (dest->active != 0) func_02034714(d_02200D18, 0, d_02200D18);
    if (source->active != 1) func_02034714(d_02200D18, 0, d_02200D18);
    *dest = *source;
    if (source->enabled != mode) func_021FADB8(dest, mode);
}






void func_021FAEC0(Button *p, unsigned index) { short x = (short)func_021FB7B0(p->object, 0); func_021FB514(p->result, x, (short)(169 - (index << 4))); }






void func_021FAEE4(Button *p, int *out) { short x, y; func_021FB548(p->result, &x, &y); out[0] = x; out[1] = y; }







void func_021FAF08(Button *p, int a1)
{
    short r = (short)func_021FB7B0(p->object, 0);

    func_021FB514(p->result, r, a1);
}






int func_021FAF24(Button *ctx, int kind)
{
    int result;
    switch (kind) {
    case 0: result = func_021FB7B0(ctx->object, 5); break;
    case 1: result = func_021FB7B0(ctx->object, 6); break;
    case 2: result = func_021FB7B0(ctx->object, 7); break;
    case 5: result = func_021FB7B0(ctx->object, 9); break;
    case 6: result = func_021FB7B0(ctx->object, 10); break;
    case 3: result = func_021FB7B0(ctx->object, 8); break;
    case 4: result = func_021FB7B0(ctx->object, 2); break;
    case 7: result = func_021FB7B0(ctx->object, 11); break;
    case 8: result = func_021FB7B0(ctx->object, 0); break;
    case 9: result = func_021FB7B0(ctx->object, 1); break;
    default: result = 0; func_02034714(d_02200D18, 0, d_02200D18); break;
    }
    return result;
}







void func_021FAFA0(Button *p, int b)
{
    func_021FB578((int *)p->result, (unsigned char)b);
}







void func_021FAFB0(Button *p, int b)
{
    func_021FB5A0((int *)p->result, (unsigned char)b);
}






void func_021FAFC0(Button *p, unsigned value) { func_021FB5C4(p->result, value); }






void func_021FAFCC(Button *p, unsigned value) { p->pos = (int *)value; }






/*
 * tail: 021FB056..021FB058 is two zero alignment bytes.
 */
int func_021FAFD0(Button *ctx)
{
    int position[2];
    short x;
    short value;
    switch (ctx->state) {
    case 0:
        func_021FAEE4(ctx, position);
        ctx->from = position[1];
        ctx->to = ctx->dest_y;
        ctx->tick = 0;
        ctx->duration = 10;
        ctx->state = 1;
        break;
    case 1:
        value = ctx->from + ((ctx->to - ctx->from) * ctx->tick) / ctx->duration;
        func_021FB548(ctx->result, &x, 0);
        func_021FB514(ctx->result, x, value);
        if (ctx->tick++ >= ctx->duration) ctx->state = 2;
        break;
    case 2: return 1;
    }
    return 0;
}






/*
 * tail: 021FB0E6..021FB0E8 is two zero alignment bytes.
 * lever: load position[1] to a local before the target and step stores.
 */
int func_021FB058(Button *ctx)
{
    int position[2];
    short x;
    short value;
    int target;
    int start;
    switch (ctx->state) {
    case 0:
        func_021FAEE4(ctx, position);
        target = func_021FB7B0(ctx->object, 1);
        start = position[1];
        ctx->to = target;
        ctx->tick = 0;
        ctx->from = start;
        ctx->duration = 16;
        ctx->state = 1;
        break;
    case 1:
        value = ctx->from + ((ctx->to - ctx->from) * ctx->tick) / ctx->duration;
        func_021FB548(ctx->result, &x, 0);
        func_021FB514(ctx->result, x, value);
        if (ctx->tick++ >= ctx->duration) ctx->state = 2;
        break;
    case 2: return 1;
    }
    return 0;
}






int func_021FB0E8(Button *p)
{
    s16 y,x;
    switch(p->state) {
    case 0: {
        int position[2];
        func_021FAEE4((Button *)p, position);
        p->from=position[1];p->to=-32;p->tick=0;p->duration=14;p->state=1;
        break;
    }
    case 1: {
        s16 value;
        value=p->from;
        value=value+_s32_div_f((p->to-value)*p->tick,p->duration);
        func_021FB548(p->result,&y,0);
        func_021FB514(p->result,y,value);
        if(p->tick++>=p->duration)p->state=2;
        break;
    }
    case 2:func_021FADB8(p,0);p->state=3;break;
    case 3: {
        int position[2];
        func_021FAEE4((Button *)p, position);
        p->from=position[1];p->to=p->dest_y;p->tick=0;p->duration=14;p->state=4;
        break;
    }
    case 4: {
        s16 value;
        value=p->from;
        value=value+_s32_div_f((p->to-value)*p->tick,p->duration);
        func_021FB548(p->result,&x,0);
        func_021FB514(p->result,x,value);
        if(p->tick++>=p->duration)p->state=5;
        break;
    }
    case 5:return 1;
    }
    return 0;
}






/*
 * tail: 021FB2EE..021FB2F0 is two zero alignment bytes.
 * lever: capture from in the s16 value before the named divider, keeping its load live across the helper.
 */
int func_021FB1EC(Button *p)
{
    s16 y,x;
    switch(p->state) {
    case 0: {
        int position[2];
        func_021FAEE4((Button *)p, position);
        p->from=position[1];p->to=224;p->tick=0;p->duration=14;p->state=1;
        break;
    }
    case 1: {
        s16 value;
        value=p->from;
        value=value+_s32_div_f((p->to-value)*p->tick,p->duration);
        func_021FB548(p->result,&y,0);
        func_021FB514(p->result,y,value);
        if(p->tick++>=p->duration)p->state=2;
        break;
    }
    case 2:func_021FADB8(p,1);p->state=3;break;
    case 3: {
        int position[2];
        func_021FAEE4((Button *)p, position);
        p->from=position[1];p->to=p->dest_y;p->tick=0;p->duration=14;p->state=4;
        break;
    }
    case 4: {
        s16 value;
        value=p->from;
        value=value+_s32_div_f((p->to-value)*p->tick,p->duration);
        func_021FB548(p->result,&x,0);
        func_021FB514(p->result,x,value);
        if(p->tick++>=p->duration)p->state=5;
        break;
    }
    case 5:return 1;
    }
    return 0;
}






int func_021FB2F0(Button *ctx)
{
    int position[2];
    short x;
    short value;
    switch (ctx->state) {
    case 0:
        func_021FAEE4(ctx, position);
        ctx->from = position[1];
        ctx->to = ctx->dest_y;
        ctx->tick = 0;
        ctx->duration = 26;
        ctx->state = 1;
        break;
    case 1:
        value = ctx->from + ((ctx->to - ctx->from) * ctx->tick) / ctx->duration;
        func_021FB548(ctx->result, &x, 0);
        func_021FB514(ctx->result, x, value);
        if (ctx->tick++ >= ctx->duration) ctx->state = 2;
        break;
    case 2: return 1;
    }
    return 0;
}




/*
 * tail: 021FB3BA..021FB3BC is two zero alignment bytes.
 */
void *func_021FB378(void *ctx, int file, unsigned short a, int b, int c, int d, int e, int archive, void *config, unsigned short heap)
{
    void *data;
    void *result;
    data = func_02045EC0((struct MsgBank *)archive, file);
    result = func_021FB3BC((const Point *)ctx, data, a, b, c, (void *)d, (void *)e, (const Triple_021FB3BC *)config, heap);
    STRBUF_Delete(data);
    return result;
}





/*
 * lever: parameter a declared u16 (u8 also EXACT); a narrow parameter pins its home store to the front of the prologue, see docs/idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md. 2026-10-05 wave P12 lane A5: the older draft (docs/notes/pkt_ov186_021FB3BC.c.txt) was only wrong here.
 */
Obj *func_021FB3BC(const Point *pt,void *data,u16 a,u32 b,u32 c,void *owner,void *font,const Triple_021FB3BC *triple,u16 heap)
{
    Param param;
    const Triple_021FB3BC *config;
    u32 value;
    Obj *p;
    value=b;config=triple;
    p=func_02030734(heap,24,0,d_02200D1C,0xA3B);
    func_02082BCC(p,0,24);
    p->a=a;p->b=value;
    p->actor=CLACT_CreateActor((void *)c,config->y,config->z,config->x,pt,value,heap);
    func_0204B688(p->actor,1);
    p->bmp=BMP_Create(p->a>>3,2,32,heap);
    PRINTSYS_PrintColor(p->bmp,1,0,data,font,0x3DA0);
    func_02082BCC(&param,0,24);
    param.bmp=p->bmp;
    param.x=pt->x+32;param.y=pt->y-8;
    param.f8=config->z;param.f10=pt->f6-1;param.f12=value;
    param.f14=value;param.f11=pt->f7;param.fc=1;
    p->grid=BMP_OAM_Create(owner,(const struct Param *)(&param));
    BMP_OAM_UploadChars(p->grid);
    BMP_OAM_SetObjMode(p->grid,1);
    return p;
}





void func_021FB494(char *p) { BMP_OAM_Delete(*(struct Grid * *)&((struct Obj10785 *)p)->f4);BMP_Delete(*(struct Obj020437AC * *)&((struct Obj10785 *)p)->f8);CLACT_DeleteActor(*(struct Obj * *)&((struct Obj10785 *)p)->f0);func_020307B0(p); }






int func_021FB4B4(unsigned int *obj, int x, int y)
{
    int r = func_021FB4CC(obj, x, y);

    if (r != 0)
        func_020061E4(0x703);
    return r;
}






static inline int in_range(int v, int lo, int hi)
{
    return (u32)(v - lo) <= (u32)(hi - lo);
}






/*
 * Recursive MATCH unblocker: unresolved callee named by the parked
 * func_021FAD04.  Expands p[0] through the arm9 helper 0x0204B454 into two
 * signed shorts and tests the incoming ranges against p[5] and the +/-16
 * window around tmp[1].  The scratch is a raw 4-byte buffer so the two reads
 * stay register-addressed off sp.
 *
 * 2026-10-05: decoded the original as two unsigned range tests (u32)(v-lo) <= (u32)(hi-lo) with hi,lo unfolded: (a1-x) <= ((x+p5)-x) and (a2-(y-16)) <= ((y+16)-(y-16)), flag r7=0 set before the loads (its zero is reused as the ldrsh index). A static inline in_range(v,lo,hi) with s16 t[2] read at the use gives the unfolded second test but loads t[1] first and puts a2/a1 in the wrong registers; locals x,y fold the second test to cmp #0x20. Not closed.
 *
 * 2026-10-05 (D9 lane 12): EXACT*. The range test is a static inline
 * in_range(v, lo, hi); its parameters keep (hi-lo) unfolded. The first result is a
 * named local, written before the second call: hx = in_range(x); return in_range(y) & hx.
 *
 * Addresses are Black-image addresses.
 */
int func_021FB4CC(u32 *p, int a1, int a2)
{
    PtS pos;
    int hx;
    CLACT_GetActorSurfacePos((struct Actor *)p[0], &pos, (u16)p[4]);
    hx = in_range(a1, pos.x, pos.x + p[5]);
    return in_range(a2, pos.y - 16, pos.y + 16) & hx;
}









void func_021FB514(char *p, short x, int y) { struct Vec2 v;v.x=x;v.y=y;func_0204B404(*(struct Obj * *)&((struct Obj10786 *)p)->f0,&v,(unsigned short)(((struct Obj10786 *)p)->f10));BMP_OAM_SetPos(*(struct Grid * *)&((struct Obj10786 *)p)->f4,v.x+32,v.y-8); }









void func_021FB548(char *p,short *x,short *y) { PtS v;CLACT_GetActorSurfacePos(*(struct Actor * *)&((struct Obj14456 *)p)->f0,&v,(unsigned short)((struct Obj14456 *)p)->f10);if(x)*x=v.x;if(y)*y=v.y; }










void func_021FB578(int *p, unsigned char b)
{
    CLACT_SetActorDrawPriority((struct Node *)p[0], b);
    BMP_OAM_SetDrawPriority((u8 *)p[1], (unsigned char)(b - 1));
}









int func_021FB594(char *p) { return CLACT_GetActorDrawPriority(((struct Obj24826 *)p)->f0); }










void func_021FB5A0(int *p, int b)
{
    CLACT_SetActorBgPriority(p[0], b);
    BMP_OAM_SetBgPriority((u8 *)p[1], b);
}









unsigned func_021FB5B8(char *p) { return CLACT_GetActorBgPriority(*(unsigned char * *)&((struct Obj24827 *)p)->f0); }









void func_021FB5C4(char *p,int n) { func_0204B6F4(((struct Obj14459 *)p)->f0,(unsigned char)n,0);BMP_OAM_SetPalette(*(unsigned char * *)&((struct Obj14459 *)p)->f4,(unsigned char)(n+1)); }









void *func_021FB5E4(int *ctx, int heap)
{
    int total = 0;
    int i;
    int *result;
    for (i = 0; i < 12; i++) total += d_022007F0[i].count;
    result = func_02030734(heap, total * 24 + 4, 0, d_02200D28, 0x429);
    func_02082BCC(result, 0, total * 24 + 4);
    *result = *ctx;
    func_021FB644((char *)result);
    return result;
}







void func_021FB63C(void *p) { func_020307B0(p); }






void func_021FB644(char *ctx)
{
    int i;
    unsigned count;
    const Record_021FB3BC *templates;
    unsigned index;
    unsigned j;
    unsigned total = 0;
    int *config = *(int * *)&((struct Obj14460 *)ctx)->f0;
    char *record;
    for (i = 0; i < 12; i++) {
        count = d_022007F0[i].count;
        templates = d_022007F0[i].records;
        for (j = 0; j < count; j++) {
            record = ctx + total * 24;
            *(Record_021FB3BC *)(record + 4) = templates[j];
            switch (((struct Obj03892 *)record)->f1A) {
            case 1: ((struct Obj03892 *)record)->f14 = config[0]; break;
            case 2: case 3: case 4:
                index = ((struct Obj03892 *)record)->f1A - 2;
                if (index >= 4) func_02034714(d_02200D38, 0, d_02200D38);
                ((struct Obj03892 *)record)->f14 = config[index + 1];
                if (((struct Obj03892 *)record)->f14) ((struct Obj03892 *)record)->fA = 26;
                break;
            case 5: ((struct Obj03892 *)record)->f14 = config[20]; break;
            case 0: default: ((struct Obj03892 *)record)->f14 = 1; break;
            }
            total++;
        }
    }
}





void *func_021FB704(char *ctx, int section, unsigned item)
{
    int i;
    int total;
    if (section >= 12) func_02034714(d_02200D38, 0, d_02200D38);
    if (item >= d_022007F0[section].count) func_02034714(d_02200D38, 0, d_02200D38);
    total = 0;
    for (i = 0; i < section; i++) total += d_022007F0[i].count;
    return ctx + 4 + (total + item) * 24;
}






unsigned short func_021FB760(void *p,int i) { if(i>=12)func_02034714(d_02200D38,0,d_02200D38);return d_022007F0[i].count; }






unsigned func_021FB788(void *p) { unsigned best=0;int i;for(i=0;i<12;i++){if(best<func_021FB760(p,i)) best=func_021FB760(p,i);}return best; }






int func_021FB7B0(void *p,int i) { if(i>=12)func_02034714(d_02200D38,0,d_02200D38);return *(unsigned short *)((unsigned)p+i*2); }






void *func_021FB7D0(unsigned *const *p,void *record,struct MsgBank *archive,unsigned short heap)
{
    int n,index,ok;
    void *tmp,*src,*result;
    n=func_021FB7B0(record,11);
    ok=0;
    if(n>=1 && n<=4){index=n-1;ok=1;}
    if(ok){
        if((*p)[index]!=0){
            tmp=func_0201EC64((unsigned short)((heap&0x7fff)|0x8000));
            func_0201EE0C(tmp,0,(const void *)((*p+index)[4]),(*p+index)[8],1,2);
            src=func_02045EC0(archive,(int)func_021FB7B0(record,3));
            result=STRBUF_Create(STRBUF_GetLength(src)+7,heap);
            func_0201F250(tmp,result,src);
            func_0201ED04(tmp);
            STRBUF_Delete(src);
        }else{
            result=func_02045EC0(archive,(int)func_021FB7B0(record,3));
        }
    }else{
        result=func_02045EC0(archive,(int)func_021FB7B0(record,3));
    }
    return result;
}






/*
 * volatile: allocated fields +F4 and +F8 re-read after their stores at 021FB8B0 and 021FB8C0.
 */
void *func_021FB884(unsigned mode,unsigned flag,unsigned heap)
{
    Object *p;
    p=func_02030734(heap,0xfc,0,d_02200D3C,0x60);
    func_02082BCC(p,0,0xfc);
    p->flag=flag;
    if(p->flag){p->mode=mode;if(p->mode==1)p->mode=0;}
    else p->mode=1;
    p->a=GF_FONT_Create(0x17,0,0,0,heap);
    p->b=func_02045B38(0,2,5,heap);
    p->c=func_0201EC74(8,0x40,heap);
    func_021FC148((char *)p,0,heap);
    func_021FC148((char *)p,1,heap);
    return p;
}






void func_021FB92C(char *p) {func_021FC1F8((int *)p,0);func_021FC1F8((int *)p,1);func_0201ED04(((struct Obj10788 *)p)->fF0);MSGDATA_Delete(*(struct Rec_021FAA74 * *)&((struct Obj10788 *)p)->fEC);GF_FONT_Delete(((struct Obj10788 *)p)->fE8);func_020307B0(p);}






void func_021FB964(void *ctx,unsigned kind,unsigned short heap)
{
    void *h;
    h=func_020490F4(0x89,heap);
    switch(kind) {
    case 0:
        func_02049658(h,0x26,3,0,0,0,heap);
        func_020498F4(h,0x28,3,0,0,0,heap);
        break;
    case 1:
        func_02049658(h,0x26,6,0,0,0,heap);
        func_020498F4(h,0x28,6,0,0,0,heap);
        break;
    case 2:
        func_02049658(h,0x6b,0,0,0,0,heap);
        func_020498F4(h,0x2,0,0,0,0,heap);
        break;
    case 3:
        func_02049658(h,0x26,2,0,0,0,heap);
        func_020498F4(h,0x27,2,0,0,0,heap);
        break;
    case 4:
        func_02049658(h,0x26,2,0,0,0,heap);
        func_020498F4(h,0x1a,2,0,0,0,heap);
        break;
    case 5:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x5,5,0,0,0,heap);
        break;
    case 6:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x2d,2,0,0,0,heap);
        break;
    case 7:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x2c,2,0,0,0,heap);
        break;
    case 8:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x2b,2,0,0,0,heap);
        break;
    case 9:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x61,5,0,0,0,heap);
        break;
    case 10:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x63,2,0,0,0,heap);
        break;
    case 11:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x64,2,0,0,0,heap);
        break;
    case 12:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x65,2,0,0,0,heap);
        break;
    case 13:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x66,2,0,0,0,heap);
        break;
    case 19:
        func_02049658(h,0x6b,2,0,0,0,heap);
        func_020498F4(h,0x2,2,0,0,0,heap);
        break;
    case 14:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x62,2,0,0,0,heap);
        break;
    case 15:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x67,5,0,0,0,heap);
        break;
    case 18:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x68,2,0,0,0,heap);
        break;
    case 17:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x69,2,0,0,0,heap);
        break;
    case 16:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x6a,2,0,0,0,heap);
        break;
    case 20:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x1f,5,0,0,0,heap);
        break;
    case 21:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x1d,5,0,0,0,heap);
        break;
    case 22:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0xd,5,0,0,0,heap);
        break;
    case 23:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0xe,5,0,0,0,heap);
        break;
    case 24:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x3,2,0,0,0,heap);
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,6,5,0,0,0,heap);
        break;
    case 25:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x1b,2,0,0,0,heap);
        break;
    case 26:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x1e,5,0,0,0,heap);
        break;
    case 28:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x1c,5,0,0,0,heap);
        break;
    case 27:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x20,5,0,0,0,heap);
        break;
    case 29:
        func_02049658(h,0x26,5,0,0,0,heap);
        func_020498F4(h,0x12,5,0,0,0,heap);
        break;
    case 30:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x2f,5,0,0,0,heap);
        break;
    }
    ARC_TOOL_DeleteHandle(h);
}






void func_021FBDA4(int a,unsigned mode)
{
    switch(mode){
    case 24:
        func_020414EC(2);func_020409B4(2);
        func_020414EC(5);func_020409B4(5);break;
    case 0:func_020414EC(3);func_020409B4(3);break;
    case 1:func_020414EC(6);func_020409B4(6);break;
    case 2:func_020414EC(0);func_020409B4(0);break;
    case 5:case 9:case 15:case 20:case 21:case 22:case 23:case 26:case 27:case 28:case 29:case 30:
        func_020414EC(5);func_020409B4(5);break;
    case 3:case 4:case 6:case 7:case 8:case 10:case 11:case 12:case 13:case 16:case 17:case 18:case 19:case 25:
        func_020414EC(2);func_020409B4(2);break;
    case 14:break;
    }
}







void func_021FBE54(char *base, u32 idx, u32 area)
{
    u32 *r4;

    r4 = (u32 *)(base + 8 + idx * 12);

    if (*(u32 *)(base + 0xb0 + idx * 4) != 0) {
        func_02034714(d_02200D48, 0, d_02200D48);
    }

    switch (idx) {
    case 4: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f0;
        r4[1] = CLACT_RegisterCharacter(h, 0x24, 0, 0, area);
        r4[0] = (u32)CLACT_RegisterCellAnim(h, 0x15, 0x14, area);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 5: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f4;
        r4[1] = CLACT_RegisterCharacter(h, 0x24, 0, 1, area);
        r4[0] = (u32)CLACT_RegisterCellAnim(h, 0x15, 0x14, area);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 0: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f0;
        r4[1] = CLACT_RegisterCharacter(h, 0x22, 0, 0, area);
        r4[0] = (u32)CLACT_RegisterCellAnim(h, 9, 0xa, area);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 1: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f4;
        r4[1] = CLACT_RegisterCharacter(h, 0x22, 0, 1, area);
        r4[0] = (u32)CLACT_RegisterCellAnim(h, 9, 0xa, area);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 2: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f0;
        r4[1] = CLACT_RegisterCharacter(h, 0x3f, 0, 0, area);
        r4[0] = (u32)CLACT_RegisterCellAnim(h, 0x3d, 0x3e, area);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 3: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f4;
        r4[1] = CLACT_RegisterCharacter(h, 0x3f, 0, 1, area);
        r4[0] = (u32)CLACT_RegisterCellAnim(h, 0x3d, 0x3e, area);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 6: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f4;
        r4[1] = CLACT_RegisterCharacter(h, 0x23, 0, 1, area);
        r4[0] = (u32)CLACT_RegisterCellAnim(h, 7, 8, area);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 8: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f4;
        r4[1] = CLACT_RegisterCharacter(h, 0x56, 0, 1, area);
        r4[0] = (u32)CLACT_RegisterCellAnim(h, 0x55, 0x54, area);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 7: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f0;
        r4[1] = CLACT_RegisterCharacter(h, 0x56, 0, 0, area);
        r4[0] = (u32)CLACT_RegisterCellAnim(h, 0x55, 0x54, area);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 11: {
        void *h = func_020490F4(0x89, area);
        r4[2] = CLACT_RegisterPaletteEx(h, 0x13, 1, 0x80, 0, 1, area);
        r4[1] = CLACT_RegisterCharacter(h, 0xf, 0, 1, area);
        r4[0] = (u32)CLACT_RegisterCellAnim(h, 0x10, 0x11, area);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 12: {
        void *h = func_020490F4(0x89, area);
        r4[2] = CLACT_RegisterPaletteEx(h, 0x33, 1, 0xa0, 0, 1, area);
        r4[1] = CLACT_RegisterCharacter(h, 0x32, 0, 1, area);
        r4[0] = (u32)CLACT_RegisterCellAnim(h, 0x30, 0x31, area);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 9: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f0;
        r4[1] = CLACT_RegisterCharacter(h, 0x36, 0, 0, area);
        r4[0] = (u32)CLACT_RegisterCellAnim(h, 0x34, 0x35, area);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 10: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f4;
        r4[1] = CLACT_RegisterCharacter(h, 0x36, 0, 1, area);
        r4[0] = (u32)CLACT_RegisterCellAnim(h, 0x34, 0x35, area);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    case 13: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f0;
        r4[0] = (u32)CLACT_RegisterCellAnim(h, 0x29, 0x2a, area);
        r4[1] = CLACT_RegisterCharacter(h, 0x25, 0, 0, area);
        ARC_TOOL_DeleteHandle(h);
        break;
    }
    default:
        break;
    }

    *(u32 *)(base + 0xb0 + idx * 4) = 1;
}






void func_021FC0C8(char *p,unsigned i)
{
    int *r=(int *)(p+8+i*12);
    switch(i){
    case 11: case 12:
        CLACT_ReleasePalette(r[2]);
        CLACT_ReleaseCharacter(r[1]);
        CLACT_ReleaseCellAnim(r[0]);
        break;
    case 0: case 1: case 2: case 3: case 6: case 7: case 8: case 9: case 10: case 13:
        CLACT_ReleaseCharacter(r[1]);
        CLACT_ReleaseCellAnim(r[0]);
        break;
    case 4: case 5: break;
    }
    *(int *)(p+0xb0+i*4)=0;
}






int func_021FC124(char *p,unsigned i,void *out) { if(*(int *)((unsigned)(p+0xb0)+i*4)) *(Triple_021FB514 *)out=*(Triple_021FB514 *)((unsigned)p+i*12+8);return *(int *)((unsigned)(p+0xb0)+i*4); }






void func_021FC148(char *p,unsigned i,unsigned heap)
{
    void *h;
    h=func_020490F4(0x89,heap);
    *(unsigned *)(p+i*4)=CLACT_RegisterPaletteEx(h,func_021FC31C(((struct Obj01770 *)p)->fF8),i,0,0,13,heap);
    if(i==0){
        func_02049B68(h,func_021FC344(((struct Obj01770 *)p)->fF8),0,0,0,heap);
        func_02049B68(h,func_021FC36C(((struct Obj01770 *)p)->fF8),0,0x1c0,0x20,heap);
    }else{
        func_02049B68(h,func_021FC344(((struct Obj01770 *)p)->fF8),4,0,0,heap);
        func_02049B68(h,func_021FC36C(((struct Obj01770 *)p)->fF8),4,0x1c0,0x20,heap);
    }
    ARC_TOOL_DeleteHandle(h);
}







void func_021FC1F8(int *p, int i)
{
    CLACT_ReleasePalette(p[i]);
    p[i] = -1;
}






unsigned func_021FC20C(char *p) { return ((struct Obj24829 *)p)->fE8; }







int func_021FC214(char *p)
{
    return ((struct Obj24830 *)p)->fEC;
}






/*
 * trailing: two zero padding bytes at 021FC222, then existing matched 021FC224.
 */
int func_021FC21C(char *p)
{
    return ((struct Obj24831 *)p)->fF0;
}







/*
 * Extent runs long: 0x021FC230 is an unlabelled follower leaf (a plain
 * `p[0x3e] = v` setter), so this is EXACT*.
 */
int func_021FC224(char *p)
{
    return func_021FC394(((struct Obj24832 *)p)->fF8);
}






void func_021FC230(char *p,int v){((struct Obj24833 *)p)->fF8=v;}






int func_021FC238(char *p) { return ((struct Obj24834 *)p)->fF8; }






/*
 * prototype: 490F4 receives full heap, no caller truncation; E8E8 reads stack heap halfword.
 */
void func_021FC240(char *p,void *owner,unsigned short heap)
{
    void *h;
    h=func_020490F4(0x89,heap);
    func_021FE8E8(owner,h,func_021FC31C(((struct Obj05501 *)p)->fF8),2,0,0x1C0,heap);
    func_021FE8E8(owner,h,func_021FC31C(((struct Obj05501 *)p)->fF8),3,0,0x1C0,heap);
    func_021FE8E8(owner,h,func_021FC344(((struct Obj05501 *)p)->fF8),0,0,0,heap);
    func_021FE8E8(owner,h,func_021FC344(((struct Obj05501 *)p)->fF8),1,0,0,heap);
    func_021FE8E8(owner,h,func_021FC36C(((struct Obj05501 *)p)->fF8),0,0xE0,0x20,heap);
    func_021FE8E8(owner,h,func_021FC36C(((struct Obj05501 *)p)->fF8),1,0xE0,0x20,heap);
    ARC_TOOL_DeleteHandle(h);
}






unsigned short func_021FC31C(unsigned i) { if(i>=8)func_02034714(d_02200D48,0,d_02200D48);return d_022008C0[i]; }






unsigned short func_021FC344(unsigned i) { if(i>=8)func_02034714(d_02200D48,0,d_02200D48);return d_022008A0[i]; }






unsigned short func_021FC36C(unsigned i) { if(i>=8)func_02034714(d_02200D48,0,d_02200D48);return d_02200880[i]; }






u16 func_021FC394(u32 n){if(n>=8)func_02034714(d_02200D48,0,d_02200D48);return *(const u32*)((u32)d_022008E0+n*4);}
