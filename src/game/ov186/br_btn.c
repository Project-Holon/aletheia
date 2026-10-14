/*
 * file:     br_btn.c
 * unit:     yes
 * function: BR_BTN_Create, BR_BTN_Delete, func_021F9FE8, func_021FA004, func_021FA018, func_021FA01C, func_021FA020, BR_BTN_Init, func_021FA0FC, func_021FA1DC, func_021FA210, func_021FA21C, func_021FA274, func_021FA284, func_021FA444, func_021FA500, func_021FA6A8, func_021FA758, func_021FA7FC, func_021FA920, func_021FAA34, func_021FAA74, func_021FAAD0, func_021FAB7C, func_021FAC20, func_021FACE0, func_021FAD04, func_021FAD18, func_021FAD74, func_021FADB8, func_021FAE70, func_021FAEC0, func_021FAEE4, func_021FAF08, func_021FAF24, func_021FAFA0, func_021FAFB0, func_021FAFC0, BR_BTN_SetPos, func_021FAFD0, func_021FB058, func_021FB0E8, func_021FB1EC, func_021FB2F0, func_021FB378, func_021FB3BC, func_021FB494, func_021FB4B4, func_021FB4CC, func_021FB514, func_021FB548, func_021FB578, func_021FB594, func_021FB5A0, func_021FB5B8, func_021FB5C4
 * address:  0x021F9CB8
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from br_proc_sys.c, br_btn.c, br_graphic.c, br_util.c, br_net.c, ov186_func_02200228.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02034714 0x02034714 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_02030734 0x02030734 arm
 *   func_020307B0  0x020307B0  arm
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   d_02200D18 0x02200D18 data a1
 *   d_02200D1C 0x02200D1C data a1
 *   func_021FD714  0x021FD714  thumb  ov186
 *   func_021FD15C  0x021FD15C  thumb  ov186
 *   BMP_OAM_DeleteSys  0x02025588  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   func_021FD71C 0x021FD71C thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   d_02200358 0x02200358 data a4
 *   STRBUF_Clone 0x02045874 arm
 *   memset 0x02082BCC arm
 *   _s32_div_f 0x0209C0A4 arm
 *   func_02045EC0 0x02045EC0 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   BMP_Create 0x02043678 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_OAM_Create 0x020255A0 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 *   BMP_OAM_SetObjMode 0x0202597C thumb
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_Delete 0x020437AC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   BMP_OAM_SetPos 0x0202590C thumb
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   BMP_OAM_SetDrawPriority  0x020259C4  thumb
 *   CLACT_GetActorDrawPriority 0x0204B838 arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   BMP_OAM_SetBgPriority  0x02025A0C  thumb
 *   CLACT_GetActorBgPriority 0x0204B864 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   BMP_OAM_SetPalette 0x02025A54 thumb
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_ReleaseSprite 0x021FC0C8 thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   func_021FB494 0x021FB494 thumb ov186
 *   BR_BTN_DATA_Create 0x021FB5E4 thumb ov186
 *   BR_BTN_DATA_Delete 0x021FB63C thumb ov186
 *   BR_BTN_DATA_GetRow 0x021FB704 thumb ov186
 *   BR_BTN_DATA_GetSectionCount 0x021FB760 thumb ov186
 *   BR_BTN_DATA_GetMaxSectionCount 0x021FB788 thumb ov186
 *   BR_BTN_DATA_GetRowField 0x021FB7B0 thumb ov186
 *   BR_BTN_DATA_CreateLabel 0x021FB7D0 thumb ov186
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
#include "../../matched/include/Obj10785.h"
#include "../../matched/include/Obj10786.h"
#include "../../matched/include/Obj14456.h"
#include "../../matched/include/Obj24826.h"
#include "../../matched/include/Obj24827.h"
#include "../../matched/include/Obj14459.h"
#include "br_proc_sys_shared_types.h"
#include "br_btn_shared_types.h"

struct Pair;

extern void STRBUF_Delete(struct U16Vec *vec);

struct Grid;

struct Param;

struct Sys;

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

typedef struct { unsigned short x,y,z; unsigned char flag,pad; } Config_021FAC20;

typedef struct Placement { short x, y; unsigned short animation; unsigned char priority, attr; } Placement;

typedef struct Config_021FADB8 { int words[3]; } Config_021FADB8;

typedef struct { s16 x,y;u16 f4;u8 f6,f7; } Point;

typedef struct { void *bmp;s16 x,y;u32 f8,fc;u8 f10,f11;u16 f12;u32 f14; } Param;

typedef struct { u32 x,y,z; } Triple_021FB3BC;

typedef struct PtS { s16 x, y; } PtS;

struct Vec2{short x,y;};

extern void func_02034714(const char *expr, u32_021F9CB8 line, const char *file);

extern void *func_02030734(u32_021F9CB8 heap, u32_021F9CB8 size, int clear, const char *site, u16 tag);

extern void MI_CpuFill8(void *, int, int);

extern void *BMP_OAM_CreateSys(u32_021F9CB8 a0, void *a1);

extern u32_021F9CB8 PRINTSYS_QUE_Create(void *p);

extern int *func_021FD6D8(int payload, int callback, u32_021F9CB8 heap);

extern int *func_021FD73C(int *p, int v);

extern void func_021FD714(void *p);

extern void func_021FD15C(void *p, int a1);

extern u32_021F9CB8 func_020307B0(void *p);

extern void BMP_OAM_DeleteSys(void *p);

extern void PRINTSYS_QUE_Delete(struct PrintSys *p);

extern void func_021FD71C(u8 *p);

extern u32_021F9CB8 PRINTSYS_QUE_Main(struct PrintSys *);

extern void func_021FD1BC(void *p);

extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);

extern void GFL_USE_PlaySeDefaultVolume(u32 a);

extern void func_021FD860(char *,unsigned,const Pair *);

extern void *func_021FD12C(int a, void *owner, u16 heap);

extern void func_021FD170(char *p, char *q, void *text);

extern struct U16Vec *STRBUF_Clone(struct U16Vec *src, u32 heapId);

extern void *memset(void *,int,unsigned);

extern int _s32_div_f(int,int);

extern void *func_02045EC0(struct MsgBank *bank, u32 index);

extern struct Obj *CLACT_CreateActor(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);

extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);

extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);

extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);

extern struct Grid *BMP_OAM_Create(struct Sys *sys, const struct Param *param);

extern void BMP_OAM_UploadChars(struct Obj *o);

extern void BMP_OAM_SetObjMode(u8 *,u32);

extern void BMP_OAM_Delete(struct Grid *);

extern void BMP_Delete(struct Obj020437AC *);

extern void CLACT_DeleteActor(struct Obj *);

extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);

extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

extern void BMP_OAM_SetPos(struct Grid *,short,short);

extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);

extern void BMP_OAM_SetDrawPriority(u8 *g, u32 a);

/* Callee's complete leaf reads only r0; legacy r1-r3 are unused, unforwarded. */
extern int CLACT_GetActorDrawPriority(int);

extern void CLACT_SetActorBgPriority(int, unsigned int);

extern void BMP_OAM_SetBgPriority(u8 *g, u32 a);

extern unsigned CLACT_GetActorBgPriority(unsigned char *);

extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);

extern void BMP_OAM_SetPalette(u8 *g, u32 a);

struct Obj *BR_BTN_Create(int a, int b, int c, int d, int e, int f, u16 heap);

void BR_BTN_Delete(u8 *p);

void func_021F9FE8(char *p);

int func_021FA004(char *p,int *x,int *y);

int func_021FA018(char *p);

int func_021FA01C(char *p);

void func_021FA020(u8 *ctx, int a1, int a2);

int BR_BTN_Init(unsigned char *ctx, Button *out);

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

void BR_BTN_SetPos(Button *p, unsigned value);

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

void *BR_BTN_DATA_Create(int *ctx, int heap);

void BR_BTN_DATA_Delete(void *p);

void *BR_BTN_DATA_GetRow(char *ctx, int section, unsigned item);

unsigned short BR_BTN_DATA_GetSectionCount(void *p,int i);

unsigned BR_BTN_DATA_GetMaxSectionCount(void *p);

int BR_BTN_DATA_GetRowField(void *p,int i);

void *BR_BTN_DATA_CreateLabel(unsigned *const *p,void *record,struct MsgBank *archive,unsigned short heap);

void BR_RES_LoadSprite(char *base, u32 idx, u32 area);

void BR_RES_ReleaseSprite(char *p,unsigned i);

int BR_RES_GetSprite(char *p,unsigned i,void *out);

unsigned BR_RES_GetFont(char *p);

int BR_RES_GetMsgData(char *p);

extern char d_02200D18[];

extern char d_02200D1C[];

extern const int d_02200358[];

struct Obj *BR_BTN_Create(int a, int b, int c, int d, int e, int f, u16 heap)
{
    struct Obj *p;
    int tmp;
    int size;
    int i;
    int arch;
    u8 buf[0x44];
    if (a >= 12) func_02034714(d_02200D18, 0, d_02200D18);
    p = func_02030734(heap, 0x60, 0, d_02200D1C, 0x13F);
    MI_CpuFill8(p, 0, 0x60);
    p->f4 = c;
    p->f8 = b;
    p->heap = heap;
    p->f5c = (struct Set *)e;
    p->f48 = BMP_OAM_CreateSys(heap, (void *)b);
    p->f4c = PRINTSYS_QUE_Create((void *)heap);
    p->f58 = f;
    p->f14 = 1;
    MI_CpuFill8(&tmp, 0, 4);
    tmp = d;
    p->f44 = BR_BTN_DATA_Create(&tmp, heap);
    if (a >= 10) p->f10 = 2;
    else p->f10 = 0;
    BR_RES_LoadSprite((char *)p->f4, p->f10, heap);
    BR_RES_LoadSprite((char *)p->f4, p->f10 + 1, heap);
    p->f38 = BR_BTN_DATA_GetMaxSectionCount(p->f44);
    size = p->f38 * 0x44;
    p->f40 = func_02030734(heap, size, 0, d_02200D1C, 0x167);
    MI_CpuFill8(p->f40, 0, size);
    p->f3a = 6;
    p->f3c = func_02030734(heap, 0x198, 0, d_02200D1C, 0x171);
    MI_CpuFill8(p->f3c, 0, 0x198);
    p->fC = func_021FD6D8((int)p, (int)func_021FA274, heap);
    if (p->f5c->count != 0) {
        arch = BR_RES_GetMsgData((char *)c);
        for (i = 0; i < p->f5c->count; i++) {
            void *q = BR_BTN_DATA_GetRow(p->f44, p->f5c->rec[i].a, (unsigned short)p->f5c->rec[i].b);
            void *rec = BR_BTN_DATA_CreateLabel(p->f44, q, (struct MsgBank *)arch, (heap & 0x7FFF) | 0x8000);
            MI_CpuFill8(buf, 0, 0x44);
            func_021FAC20((Button *)buf, q, b, p->f48, (char *)c, rec, p->f10, heap);
            func_021FA020((u8 *)p, (int)buf, 0);
            STRBUF_Delete(rec);
        }
        for (i = 0; i < p->f3b; i++)
            func_021FAEC0((Button *)(p->f3c + (p->f3b - i - 1) * 0x44), (unsigned short)i);
        func_021FD73C(p->fC, (int)func_021FA920);
        p->f1C = 2;
    } else {
        arch = BR_RES_GetMsgData((char *)c);
        p->f39 = BR_BTN_DATA_GetSectionCount(p->f44, a);
        for (i = 0; i < p->f39; i++) {
            void *q = BR_BTN_DATA_GetRow(p->f44, a, (unsigned short)i);
            void *rec = BR_BTN_DATA_CreateLabel(p->f44, q, (struct MsgBank *)arch, (heap & 0x7FFF) | 0x8000);
            func_021FAC20((Button *)(p->f40 + i * 0x44), q, b, p->f48, (char *)c, rec, p->f10, heap);
            STRBUF_Delete(rec);
        }
        for (i = 0; i < p->f39; i++)
            func_021FAF08((Button *)(p->f40 + i * 0x44), 0xe0);
        func_021FD73C(p->fC, (int)func_021FAAD0);
    }
    return p;
}

void BR_BTN_Delete(u8 *p)
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
    BR_RES_ReleaseSprite((char *)(((struct Obj01175 *)p)->f4), ((struct Obj01175 *)p)->f10);
    BR_RES_ReleaseSprite((char *)(((struct Obj01175 *)p)->f4), ((struct Obj01175 *)p)->f10 + 1);
    BR_BTN_DATA_Delete((void *)(((struct Obj01175 *)p)->f44));
    BMP_OAM_DeleteSys((void *)(((struct Obj01175 *)p)->f48));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj01175 *)p)->f4C));
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

int BR_BTN_Init(unsigned char *ctx, Button *out)
{
    if (ctx[0x3b]) {
        ctx[0x3b]--;
        *out = (*(Button **)(ctx + 0x3c))[ctx[0x3b]];
        MI_CpuFill8(&(*(Button **)(ctx + 0x3c))[ctx[0x3b]], 0, 0x44);
        return 1;
    }
    return 0;
}

void func_021FA0FC(u8 *p,int section,const int *pos)
{
 int i,bank;
 void *rec,*text;
 for(i=0;i<p[0x38];i++)func_021FACE0((Button *)(*(u8 * *)&((struct Obj01277 *)p)->f40+i*0x44));
 bank=BR_RES_GetMsgData(*(char * *)&((struct Obj01277 *)p)->f4);
 p[0x39]=BR_BTN_DATA_GetSectionCount(((struct Obj01277 *)p)->f44,section);
 for(i=0;i<p[0x39];i++){
  rec=BR_BTN_DATA_GetRow(*(char * *)&((struct Obj01277 *)p)->f44,section,(u16)i);
  text=BR_BTN_DATA_CreateLabel(*(unsigned *const * *)&((struct Obj01277 *)p)->f44,rec,(struct MsgBank *)bank,(((struct Obj01277 *)p)->f0&0x7fff)|0x8000);
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
 if(TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))){
  for(i=0;i<ctx[0x38];i++){
   if(func_021FAD04((Button *)(int *)(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44), x, y)){
    if(func_021FAF24((Button *)(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44), 3)){
     if(((struct Obj00313 *)ctx)->f50){
      func_021FD15C((void *)(((struct Obj00313 *)ctx)->f50),((struct Obj00313 *)ctx)->f4);
      ((struct Obj00313 *)ctx)->f50=0;
     }
     GFL_USE_PlaySeDefaultVolume(0x703);
     ((struct Obj00313 *)ctx)->f2C=i;
     found=1;
     ((struct Obj00313 *)ctx)->f30=x;((struct Obj00313 *)ctx)->f34=y;
     func_021FD860(*(char * *)&((struct Obj00313 *)ctx)->f58,7,(Pair *)(ctx+0x30));
     BR_BTN_SetPos((Button *)(*(char * *)&((struct Obj00313 *)ctx)->f40+((struct Obj00313 *)ctx)->f2C*0x44), (unsigned int)((Pair *)(ctx+0x30)));
     ((struct Obj00313 *)ctx)->f54=0;
    }else{
     kind=func_021FAF24((Button *)(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44), 5);
     func_021FAF24((Button *)(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44), 6);
     GFL_USE_PlaySeDefaultVolume(0x704);
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
  MI_CpuFill8(*(char * *)&((struct Obj00684 *)ctx)->f40+((struct Obj00684 *)ctx)->f2C*0x44,0,0x44);
  pos[1]=-32;
  func_021FA0FC(ctx,section,pos);
  func_021FD73C(p,(int)func_021FA7FC);
 }else if(((struct Obj00684 *)ctx)->f1C==2){
  func_021FA210(((struct Obj00684 *)ctx)->f5C);
  if(BR_BTN_Init(ctx, (Button *)&record)){
   section=func_021FAF24((Button *)&record, 4);
   if(!record.active)func_02034714(d_02200D18,0,d_02200D18);
   other[0]=BR_BTN_DATA_GetRowField(record.object,0);
   other[1]=BR_BTN_DATA_GetRowField(record.object,1);
   func_021FA0FC(ctx,section,other);
   y=BR_BTN_DATA_GetRowField(record.object,1);
   for(i=0;i<ctx[0x39];i++){
    if(y==BR_BTN_DATA_GetRowField((void *)(*(int *)(*(char * *)&((struct Obj00684 *)ctx)->f40+i*0x44+0xc)),1))
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
  MI_CpuFill8(*(char * *)&((struct Obj00684 *)ctx)->f40+((struct Obj00684 *)ctx)->f2C*0x44,0,0x44);
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
                position[0]=BR_BTN_DATA_GetRowField(*(void **)(*(u8 * *)&((struct Obj02234 *)ctx)->f3C+i*0x44+0xC),0);
                position[1]=BR_BTN_DATA_GetRowField(*(void **)(*(u8 * *)&((struct Obj02234 *)ctx)->f3C+i*0x44+0xC),1);
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
    MI_CpuFill8(ctx, 0, 0x44);
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
    MI_CpuFill8(&config, 0, 8);
    config.x = BR_BTN_DATA_GetRowField(ctx->object, 0);
    config.y = BR_BTN_DATA_GetRowField(ctx->object, 1);
    config.z = BR_BTN_DATA_GetRowField(ctx->object, 4);
    config.flag = 1;
    BR_RES_GetSprite(owner, ctx->index + 1, info);
    ctx->result = (char *)func_021FB3BC((const Point *)&config, ctx->work, 0xa0, ctx->enabled, a, b, (void *)BR_RES_GetFont(owner), (const Triple_021FB3BC *)info, (unsigned short)((heap & 0x7fff) | 0x8000));
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
    placement.animation = BR_BTN_DATA_GetRowField(ctx->object, 4);
    placement.priority = priority;
    placement.attr = attr;
    BR_RES_GetSprite(ctx->owner, ctx->index + mode, &config);
    resource = BR_RES_GetFont(ctx->owner);
    BR_RES_GetMsgData(ctx->owner);
    BR_BTN_DATA_GetRowField(ctx->object, 3);
    ctx->result = (char *)func_021FB3BC((const Point *)&placement, ctx->work, 160, mode, ctx->a, ctx->b, (void *)resource, (const Triple_021FB3BC *)&config, ctx->heap);
}

void func_021FAE70(void *ctx, Button *dest, const Button *source, int mode)
{
    if (dest->active != 0) func_02034714(d_02200D18, 0, d_02200D18);
    if (source->active != 1) func_02034714(d_02200D18, 0, d_02200D18);
    *dest = *source;
    if (source->enabled != mode) func_021FADB8(dest, mode);
}

void func_021FAEC0(Button *p, unsigned index) { short x = (short)BR_BTN_DATA_GetRowField(p->object, 0); func_021FB514(p->result, x, (short)(169 - (index << 4))); }

void func_021FAEE4(Button *p, int *out) { short x, y; func_021FB548(p->result, &x, &y); out[0] = x; out[1] = y; }

void func_021FAF08(Button *p, int a1)
{
    short r = (short)BR_BTN_DATA_GetRowField(p->object, 0);

    func_021FB514(p->result, r, a1);
}

int func_021FAF24(Button *ctx, int kind)
{
    int result;
    switch (kind) {
    case 0: result = BR_BTN_DATA_GetRowField(ctx->object, 5); break;
    case 1: result = BR_BTN_DATA_GetRowField(ctx->object, 6); break;
    case 2: result = BR_BTN_DATA_GetRowField(ctx->object, 7); break;
    case 5: result = BR_BTN_DATA_GetRowField(ctx->object, 9); break;
    case 6: result = BR_BTN_DATA_GetRowField(ctx->object, 10); break;
    case 3: result = BR_BTN_DATA_GetRowField(ctx->object, 8); break;
    case 4: result = BR_BTN_DATA_GetRowField(ctx->object, 2); break;
    case 7: result = BR_BTN_DATA_GetRowField(ctx->object, 11); break;
    case 8: result = BR_BTN_DATA_GetRowField(ctx->object, 0); break;
    case 9: result = BR_BTN_DATA_GetRowField(ctx->object, 1); break;
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

void BR_BTN_SetPos(Button *p, unsigned value) { p->pos = (int *)value; }

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
        target = BR_BTN_DATA_GetRowField(ctx->object, 1);
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
    MI_CpuFill8(p,0,24);
    p->a=a;p->b=value;
    p->actor=CLACT_CreateActor((void *)c,config->y,config->z,config->x,pt,value,heap);
    CLACT_SetActorObjMode(p->actor,1);
    p->bmp=BMP_Create(p->a>>3,2,32,heap);
    PRINTSYS_PrintColor(p->bmp,1,0,data,font,0x3DA0);
    MI_CpuFill8(&param,0,24);
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
        GFL_USE_PlaySeDefaultVolume(0x703);
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

void func_021FB514(char *p, short x, int y) { struct Vec2 v;v.x=x;v.y=y;CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct Obj10786 *)p)->f0,&v,(unsigned short)(((struct Obj10786 *)p)->f10));BMP_OAM_SetPos(*(struct Grid * *)&((struct Obj10786 *)p)->f4,v.x+32,v.y-8); }

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

void func_021FB5C4(char *p,int n) { CLACT_SetActorPaletteOffset(((struct Obj14459 *)p)->f0,(unsigned char)n,0);BMP_OAM_SetPalette(*(unsigned char * *)&((struct Obj14459 *)p)->f4,(unsigned char)(n+1)); }
