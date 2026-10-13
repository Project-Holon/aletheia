/*
 * file:     zukan_detail_common.c
 * unit:     yes
 * function: func_021BC240, func_021BC26C, func_021BC274, func_021BC2F0, func_021BC310, func_021BC32C, func_021BC34C, func_021BC35C, func_021BC39C, func_021BC3A4, func_021BC3A8, func_021BC3AC, func_021BC3B0, func_021BC3B4, func_021BC3B8, func_021BC3BC, func_021BC3C0, func_021BC3CC, func_021BC40C, func_021BC448, func_021BC464, func_021BC46C, func_021BC4C8, func_021BC4D8, func_021BC4E4, func_021BC4F4, func_021BC508, func_021BC518, func_021BC520, func_021BC560, func_021BC610, func_021BC61C, func_021BC678, func_021BC6BC, func_021BC6C8, func_021BC6D8, func_021BC6F8, func_021BC718, func_021BC738, func_021BC758, func_021BC7B4, func_021BC844, func_021BC97C, func_021BC99C, func_021BC9BC, func_021BCA54, func_021BCA68, func_021BCB4C, func_021BCBB4, func_021BCC80, func_021BCC84, func_021BCD68
 * address:  0x021BC240
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021C8D80 0x021C8D80 data a1
 *   func_020307B0 0x020307B0  arm
 *   d_021C8D98     0x021C8D98  data  ov208  a4
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   ZUKAN_SAVE_IsSeen 0x0200D064 thumb
 *   func_0207D67C  0x0207D67C  arm
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030CBC 0x02030CBC arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   func_02030DA4 0x02030DA4 arm
 *   func_02030D28 0x02030D28 arm
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   PALANM_TransferPalettes 0x02021D50  thumb
 *   PALANM_LoadHandlePaletteToSlotAt 0x02021660 thumb
 *   PALANM_CopyHwPaletteToSlot  0x020216D4  thumb
 *   PALANM_RequestFade 0x0202173C thumb
 *   func_020490F4  0x020490F4  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   func_02049740  0x02049740  arm
 *   func_02049990  0x02049990  arm
 *   func_020413B0  0x020413B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_02041B6C  0x02041B6C  arm
 *   data_021C80E0  0x021C80E0  data
 *   data_021C80E8  0x021C80E8  data
 *   data_021C80F0  0x021C80F0  data
 *   func_0203FB44 0x0203FB44 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021BCE10 0x021BCE10 thumb
 *   func_021BCEC0 0x021BCEC0 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_020056A0 0x020056A0 thumb
 *   ZUKAN_SAVE_GetDexObtained 0x0200CA54 thumb
 *   func_021BD8C0 0x021BD8C0 thumb
 *   func_021BE710 0x021BE710 thumb
 *   FADE_Start 0x0204E720 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_021BE778 0x021BE778 thumb ov208
 *   func_021BD954 0x021BD954 thumb ov208
 *   func_02030EAC 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_021BDB08 0x021BDB08 thumb
 *   func_021BDB54 0x021BDB54 thumb
 *   func_021BD974 0x021BD974 thumb
 *   func_021BE7A4 0x021BE7A4 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_021BCF18 0x021BCF18 thumb
 *   func_021BCF2C 0x021BCF2C thumb
 *   func_021BCF3C 0x021BCF3C thumb
 *   func_021BEA00 0x021BEA00 thumb
 *   func_021BF784 0x021BF784 thumb ov208
 *   func_021C255C 0x021C255C thumb
 *   func_021C3B68 0x021C3B68 thumb
 *   d_021C8DB0 0x021C8DB0 data a1
 *   d_021C8508 0x021C8508 data a4
 *   d_021C8590 0x021C8590 data a4
 *   d_021C86F0 0x021C86F0 data a4
 *   d_021C881C 0x021C881C data a4
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021C8164 0x021C8164 data a2
 */
#include "../../matched/include/Obj09194.h"
#include "../../matched/include/Obj09195.h"
#include "../../matched/include/Obj18177.h"
#include "../../matched/include/Obj12110.h"
#include "../../matched/include/Obj03064.h"
#include "../../matched/include/Obj18183.h"
#include "../../matched/include/Obj25414.h"
#include "../../matched/include/Obj01178.h"
#include "../../matched/include/Obj02544.h"
#include "../../matched/include/Obj04893.h"
#include "../../matched/include/Obj18185.h"
#include "../../matched/include/Obj18186.h"
#include "../../matched/include/Obj18187.h"
#include "../../matched/include/Obj18188.h"
#include "../../matched/include/Obj18189.h"
#include "../../matched/include/Obj02252.h"
#include "../../matched/include/Obj12112.h"
#include "../../matched/include/Obj07226.h"
#include "../../matched/include/Obj02253.h"

#define REG60 (*(volatile u16 *)0x04000060)
struct State;
struct Blk37;
struct Ctx;
struct Obj02021EE4;
struct PalAnmSlot;
struct S02021D50;
struct Obj0203159C;
struct GfFont;
struct Ov208Icon;
struct Ov208Mode;
struct Ov208Slot;
struct PrintSys;
struct Node;
struct Ov208Mgr;
struct S020315D4;
struct Ov208Fade;
struct Ov208Obj;
typedef unsigned short u16;

typedef unsigned int u32;

struct Ov208Obj { void *owner; int f4; int f8; int fc; int f10; };

typedef int (*Callback)(struct State *,int *,int,int,int);

struct State { Callback *callbacks; int state,counter,a,b; };

typedef void (*Vfn)(char *self, char *a, int b, int c, int d);

struct Ov208Buf { int f0; int f4; int f8; int fc; void *buf; };

typedef struct {
    char pad[0x18];
    unsigned short *tbl;
    char pad2[4];
    unsigned short *idx;
} S;

struct Ov208Cur { void *blk; int f4; int f8; int fc; int f10; int f14; u16 *ids; u16 wrap; u16 pad; u16 *cur; };

typedef unsigned char u8;

struct Ov208Blend {
    int plane1;
    int plane2;
    int ev;
    int step;
    int wait;
};

typedef struct {void *task,*memory,*slots;u16 mask,pad;u32 mode;} PalFade;

struct Ov208Gfx { int f0; int f4; void *gfx; };

struct Ov208PalFade {
    u32 f0;
    u32 f4;
    void *slots;
    u16 mask;
};

struct Ov208BgArc {
    u32 chr;
    u32 scr;
    u32 size;
};

struct Ov208Win {
    u32 chrOfs;
    u8  layer;
    u8  kind;
};

struct Ov208Args { void *src; int f4; int f8; u16 fc; u16 fe; int f10; };

struct Ov208Main_021BCA68 {
    u16 heap; u16 pad;
    void *disp; void *font; void *gfx; int task;
    void *f14; void *f18; void *fsm;
    int f20; int f24; int f28;
};

typedef signed int     s32;

struct Ov208Main_021BCBB4 {
    u16 heap; u16 pad;
    void *disp; void *font; void *gfx; int task;
    void *f14; void *f18; void *fsm;
    void *obj; int f24; int f28;
};

struct Ov208Mode { int f0; int mode; };

struct Ov208Slot {
    u16 heap; u16 pad;
    int f4; int f8; int fc; int f10; int f14; int f18; int f1c;
    void *obj;
    void *mem;
};

typedef enum {ShadeToon=0,ShadeHighlight=1} GXShading;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void *ZUKAN_SAVE_GetFromGameData(void *a);
extern u32 ZUKAN_SAVE_IsSeen(struct Blk37 *p, u16 id);
extern void func_0207D67C(unsigned int, int, int, int, int, int);
extern u32 func_02030CB0(u32);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void *PALANM_Create(u32);
extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);
extern void func_02030DA4(void *);
extern void func_02030D28(struct Ctx *c);
extern u32 PALANM_GetFadeRequestBits(const char *ptr);
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern void PALANM_LoadHandlePaletteToSlotAt(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern int PALANM_RequestFade(void *,unsigned short,unsigned short,short,unsigned char,unsigned char,unsigned short,void *);
extern void *func_020490F4(u32 id, u32 heap);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void ARC_TOOL_DeleteHandle(void *h);
extern void func_02041B6C(u32 bit);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void GFL_HEAP_CreateChildHeap(u32 src, u32 heap, u32 size);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *p, int v, int n);
extern char *func_021BCE10(u32 display, u32 heap, int threeD);
extern void func_021BCEC0(char *p);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *p);
extern int func_020056A0(void (*fn)(void), void *arg, int n);
extern u32 ZUKAN_SAVE_GetDexObtained(struct Blk37 *p);
extern char *func_021BD8C0(u16 heap, unsigned arg);
extern struct Ov208Icon *func_021BE710(u16 heap, unsigned arg);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void func_021BE778(struct Ov208Mgr *m);
extern void func_021BD954(struct Ov208Mgr *m);
extern void func_02030EAC(struct Node *n);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern unsigned func_021BDB08(const struct State *p);
extern unsigned func_021BDB54(const struct State *p);
extern void func_021BD974(struct Ov208Fade *m);
extern void func_021BE7A4(struct Ov208Icon *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void func_021BCF18(char *p);
extern void func_021BCF2C(char *p);
extern void func_021BCF3C(char *p);
extern void func_021BEA00(void *mem, u32 heap);
extern void func_021BF784(u16 *p, u16 v);
extern void func_021C255C(u16 *dst, u16 value);
extern void func_021C3B68(u16 *p, u32 value);
extern void BG_SYS_SetMainPlaneVisible(unsigned,unsigned);
extern void G3X_SetFog(int,int,int,int);
extern void G3X_SetClearColor(u16,int,int,int,int);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(unsigned,unsigned);
struct Ov208Obj *func_021BC240(void *owner, int val, u32 heap);
void func_021BC26C(void *p);
int func_021BC274(struct State *p,int arg);
void func_021BC2F0(char *p, int a, int b);
void func_021BC310(char *p, int v);
void *func_021BC32C(struct Ov208Buf *p, u32 size, u32 heap);
void func_021BC34C(char *p);
void *func_021BC35C(u32 a, void *b, void *c, void *d, void *e, void *f, void *g, int h, unsigned short i, void *j);
void func_021BC39C(void *a0);
int func_021BC3A4(int *p);
int func_021BC3A8(int *p);
int func_021BC3AC(int *p);
int func_021BC3B0(int *p);
int func_021BC3B4(int *p);
int func_021BC3B8(char *p);
u16 ov208_func_021BC3BC(char *p);
unsigned short func_021BC3C0(S *p);
void func_021BC3CC(char *p);
void func_021BC40C(struct Ov208Cur *p);
void *func_021BC448(u32 heap);
void func_021BC464(void *a0);
void ov208_func_021BC46C(struct Ov208Blend *main, struct Ov208Blend *sub);
int ov208_func_021BC4C8(struct Ov208Blend *p);
void ov208_func_021BC4D8(struct Ov208Blend *p);
void ov208_func_021BC4E4(struct Ov208Blend *p);
void func_021BC4F4(int flag, int *p);
void func_021BC508(int flag, int *p);
void func_021BC518(int *p);
void func_021BC520(int flag, int *p);
PalFade *func_021BC560(u32 heap,u16 mask);
void *func_021BC610(u32 heap);
void func_021BC61C(char *p);
void func_021BC678(char *p);
void func_021BC6BC(char *p);
int func_021BC6C8(char *p);
void func_021BC6D8(char *p);
void func_021BC6F8(char *p);
void func_021BC718(char *p);
void func_021BC738(struct Ov208Gfx *p, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f, u16 g);
void ov208_func_021BC758(struct Ov208PalFade *p);
void func_021BC7B4(char *p,short b,unsigned char c,unsigned char d);
struct Ov208Win *ov208_func_021BC844(u16 heap, u32 kind, u8 layer, u8 pal, u8 objPal);
void func_021BC97C(char *p);
void func_021BC99C(char *p);
u32 ov208_func_021BC9BC(int skip, u16 heap, u8 layer, u8 count, u8 pal, u8 palOfs, u32 arc, u32 chr, u32 scr, u32 cell, u32 chrOfs);
void func_021BCA54(u32 a, u32 packed);
int func_021BCA68(void *owner, int unused, struct Ov208Args *args);
int func_021BCB4C(void *a,int b,int c,char *p);
int func_021BCBB4(void *unused, int *cnt, struct Ov208Args *a, struct Ov208Main_021BCBB4 *m);
void func_021BCC80(void);
void func_021BCC84(struct Ov208Mode *m, struct Ov208Slot *s);
void func_021BCD68(void);
extern const char d_021C8D80[];
extern const char d_021C8D98[];
extern const u8 data_021C80E0[2][4];
extern const u8 data_021C80E8[2][4];
extern const struct Ov208BgArc data_021C80F0[2];
extern const char d_021C8DB0[];
extern void *d_021C8508[];
extern void *d_021C8590[];
extern void *d_021C86F0[];
extern void *d_021C881C[];
extern const u16 d_021C8164[][4];


struct Ov208Obj *func_021BC240(void *owner, int val, u32 heap)
{
    struct Ov208Obj *p = func_02030734(heap, 20, 0, d_021C8D80, 0x4f);
    p->owner = owner;
    p->f4 = 0;
    p->f8 = 0;
    p->fc = val;
    p->f10 = 0;
    return p;
}



void func_021BC26C(void *p)
{
    func_020307B0(p);
}


int func_021BC274(struct State *p,int arg)
{
    int result=1;
    switch(p->state) {
    case 0:
        if(p->callbacks[0]) result=p->callbacks[0](p,&p->counter,p->a,p->b,arg);
        if(result==1) { p->state=1; p->counter=0; }
        break;
    case 1:
        if(p->callbacks[1]) result=p->callbacks[1](p,&p->counter,p->a,p->b,arg);
        if(result==1) { p->state=2; p->counter=0; }
        break;
    case 2:
        if(p->callbacks[2]) result=p->callbacks[2](p,&p->counter,p->a,p->b,arg);
        if(result==1) return 1;
        break;
    }
    return 0;
}




/*
 * Virtual call through the field at +0 of the object at +0, passing the object and three of its fields plus the two arguments.
 */
void func_021BC2F0(char *p, int a, int b)
{
    void (*fn)(char *, char *, int, int, int, int);

    fn = *(void (**)(char *, char *, int, int, int, int))(((struct Obj09194 *)p)->f0 + 0xc);
    if (fn != 0)
        fn(p, p + 8, ((struct Obj09194 *)p)->fC, ((struct Obj09194 *)p)->f10, a, b);
}



void func_021BC310(char *p, int v)
{
    Vfn fn = *(Vfn *)&((struct Obj18177 *)(*(char * *)&((struct Obj09195 *)p)->f0))->f10;

    if (fn != 0)
        fn(p, p + 8, ((struct Obj09195 *)p)->fC, ((struct Obj09195 *)p)->f10, v);
}


void *func_021BC32C(struct Ov208Buf *p, u32 size, u32 heap)
{
    p->buf = func_02030734(heap, size, 0, d_021C8D80, 0xc8);
    return p->buf;
}



void func_021BC34C(char *p)
{
    func_020307B0((void *)(((struct Obj12110 *)p)->f10));
    ((struct Obj12110 *)p)->f10 = 0;
}



void *func_021BC35C(u32 a, void *b, void *c, void *d, void *e, void *f, void *g, int h,
                    unsigned short i, void *j)
{
    int *p = (int *)func_02030734(a, 0x24, 1, d_021C8D98, 0x60);

    p[0] = (int)b;
    p[1] = (int)c;
    p[2] = (int)d;
    p[3] = (int)e;
    p[4] = (int)f;
    p[5] = (int)g;
    p[6] = h;
    ((struct Obj03064 *)p)->f1C = i;
    p[8] = (int)j;
    return p;
}



/*
 * Tail call to the ARM9 function at 0x020307B0: loads the pointer from the pool and branches through it.
 */
void func_021BC39C(void *a0)
{
    func_020307B0(a0);
}


/*
 * Returns the word at +0 of the object.
 */
int func_021BC3A4(int *p)
{
    return p[0];
}


/*
 * Returns the word at +4.
 */
int func_021BC3A8(int *p)
{
    return p[1];
}


int func_021BC3AC(int *p)
{
    return p[2];
}


int func_021BC3B0(int *p)
{
    return p[3];
}



/*
 * Returns the word at +0x10.
 */
int func_021BC3B4(int *p)
{
    return p[4];
}




int func_021BC3B8(char *p)
{
    return ((struct Obj18183 *)p)->f14;
}




u16 ov208_func_021BC3BC(char *p)
{
    return ((struct Obj25414 *)p)->f1C;
}




/*
 * Returns the halfword of the table at +0x18 indexed by the halfword read through the pointer at +0x20.
 */
unsigned short func_021BC3C0(S *p)
{
    return p->tbl[*p->idx];
}



void func_021BC3CC(char *p)
{
    unsigned short old=**(unsigned short * *)&((struct Obj01178 *)p)->f20;
    void *owner=ZUKAN_SAVE_GetFromGameData((void *)(*(int *)&((struct Obj01178 *)p)->f0));
    do {
        ++**(unsigned short * *)&((struct Obj01178 *)p)->f20;
        if(**(unsigned short * *)&((struct Obj01178 *)p)->f20>=((struct Obj01178 *)p)->f1C)
            **(unsigned short * *)&((struct Obj01178 *)p)->f20=0;
        if(**(unsigned short * *)&((struct Obj01178 *)p)->f20==old)break;
    }while(ZUKAN_SAVE_IsSeen(owner,(*(unsigned short **)(p+0x18))[**(unsigned short * *)&((struct Obj01178 *)p)->f20])==0);
}



void func_021BC40C(struct Ov208Cur *p)
{
    u16 start = *p->cur;
    u32 h = (u32)ZUKAN_SAVE_GetFromGameData(p->blk);
    do {
        if (*p->cur == 0)
            *p->cur = p->wrap - 1;
        else
            *p->cur = *p->cur - 1;
        if (*p->cur == start)
            break;
    } while (ZUKAN_SAVE_IsSeen((struct Blk37 *)h, p->ids[*p->cur]) == 0);
}



void *func_021BC448(u32 heap)
{
    return func_02030734(heap, 20, 1, d_021C8D98, 0x113);
}




void func_021BC464(void *a0)
{
    func_020307B0(a0);
}




void ov208_func_021BC46C(struct Ov208Blend *main, struct Ov208Blend *sub)
{
    struct Ov208Blend *b[2];
    struct Ov208Blend *p;
    u8 i;

    b[0] = main;
    b[1] = sub;
    for (i = 0; i < 2; i++) {
        p = b[i];
        if (p->step != 0) {
            if (p->wait == 0) {
                p->wait = 0;
                p->ev += p->step;
                if (p->step > 0) {
                    if (p->ev >= 16) {
                        p->ev = 16;
                        p->step = 0;
                    }
                } else if (p->ev <= 0) {
                    p->ev = 0;
                    p->step = 0;
                }
                func_021BC520(i, (int *)p);
            } else {
                p->wait--;
            }
        }
    }
}




int ov208_func_021BC4C8(struct Ov208Blend *p)
{
    if (p->step != 0)
        return 1;
    return 0;
}




void ov208_func_021BC4D8(struct Ov208Blend *p)
{
    p->ev = 0;
    p->step = 2;
    p->wait = 0;
}




void ov208_func_021BC4E4(struct Ov208Blend *p)
{
    p->ev = 16;
    p->step = -2;
    p->wait = 0;
}




void func_021BC4F4(int flag, int *p)
{
    p[2] = 0x10;
    p[3] = 0;
    p[4] = 0;
    func_021BC520(flag, p);
}




void func_021BC508(int flag, int *p)
{
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    func_021BC520(flag, p);
}



/*
 * Writes 0x2D to the first two words.
 */
void func_021BC518(int *p)
{
    p[0] = 0x2d;
    p[1] = 0x2d;
}




void func_021BC520(int flag, int *p)
{
    if (flag == 0) {
        func_0207D67C(0x04000050, p[0], p[1], p[2], 0, p[2] - 0x10);
    } else {
        func_0207D67C(0x04001050, p[0], p[1], p[2], 0, p[2] - 0x10);
    }
}



PalFade *func_021BC560(u32 heap,u16 mask)
{
    PalFade *p=func_02030734(heap,20,1,d_021C8D98,0x1e5);
    p->memory=func_02030734(heap,func_02030CB0(2),1,d_021C8D98,0x1e8);
    p->task=func_02030CBC(2,p->memory);
    p->slots=PALANM_Create(heap);
    PALANM_SetAutoTransfer(p->slots,1);
    p->mask=mask;
    if(p->mask&1)PALANM_AllocSlotBuffers(p->slots,0,0x1a0,heap);
    if(p->mask&4)PALANM_AllocSlotBuffers(p->slots,2,0x100,heap);
    if(p->mask&2)PALANM_AllocSlotBuffers(p->slots,1,0x1a0,heap);
    if(p->mask&8)PALANM_AllocSlotBuffers(p->slots,3,0x1c0,heap);
    p->mode=0;
    return p;
}



void *func_021BC610(u32 heap)
{
    return func_021BC560(heap, 0xf);
}



void func_021BC61C(char *p)
{
    if(((struct Obj02544 *)p)->fC&8)PALANM_FreeSlotBuffers(((struct Obj02544 *)p)->f8,3);
    if(((struct Obj02544 *)p)->fC&2)PALANM_FreeSlotBuffers(((struct Obj02544 *)p)->f8,1);
    if(((struct Obj02544 *)p)->fC&4)PALANM_FreeSlotBuffers(((struct Obj02544 *)p)->f8,2);
    if(((struct Obj02544 *)p)->fC&1)PALANM_FreeSlotBuffers(((struct Obj02544 *)p)->f8,0);
    PALANM_Delete(((struct Obj02544 *)p)->f8);
    func_02030DA4(((struct Obj02544 *)p)->f0);
    func_020307B0((void *)(((struct Obj02544 *)p)->f4));
    func_020307B0((void *)((unsigned)p));
}




/*
 * Releases +0 and re-checks the handle at +8 for the two armed states at +0x10.
 */
void func_021BC678(char *p)
{
    func_02030D28((struct Ctx *)(((struct Obj04893 *)p)->f0));
    switch (((struct Obj04893 *)p)->f10) {
    case 0:
    case 1:
        break;
    case 2:
        if (PALANM_GetFadeRequestBits((const char *)(((struct Obj04893 *)p)->f8)) == 0)
            ((struct Obj04893 *)p)->f10 = 0;
        break;
    case 3:
        if (PALANM_GetFadeRequestBits((const char *)(((struct Obj04893 *)p)->f8)) == 0)
            ((struct Obj04893 *)p)->f10 = 1;
        break;
    }
}




/*
 * Loads the word at +8 and tail-calls the function at 0x02021D51 (the thumb
 * address of the ARM9 function at 0x02021D50).
 */
void func_021BC6BC(char *p)
{
    PALANM_TransferPalettes((struct S02021D50 *)(((struct Obj18185 *)p)->f8));
}





/*
 * True when the word at +0x10, less two, is 0 or 1.
 */
int func_021BC6C8(char *p)
{
    unsigned int v = ((struct Obj18186 *)p)->f10;

    v -= 2;
    return v <= 1;
}




void func_021BC6D8(char *p)
{
    if (func_021BC6C8(p))
        return;
    func_021BC7B4(p, -1, 0x10, 0);
    ((struct Obj18187 *)p)->f10 = 2;
}




void func_021BC6F8(char *p)
{
    if (func_021BC6C8(p))
        return;
    func_021BC7B4(p, -1, 0, 0x10);
    ((struct Obj18188 *)p)->f10 = 3;
}




/*
 * Runs the idle transition with 0x10 twice and marks state 1.
 */
void func_021BC718(char *p)
{
    if (func_021BC6C8(p))
        return;
    func_021BC7B4(p, 0, 0x10, 0x10);
    ((struct Obj18189 *)p)->f10 = 1;
}



void func_021BC738(struct Ov208Gfx *p, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f, u16 g)
{
    PALANM_LoadHandlePaletteToSlotAt(p->gfx, (void *)a, b, c, d, e, f, g);
}




void ov208_func_021BC758(struct Ov208PalFade *p)
{
    if (p->mask & 1)
        PALANM_CopyHwPaletteToSlot(p->slots, 0, 0, 0x1a0);
    if (p->mask & 4)
        PALANM_CopyHwPaletteToSlot(p->slots, 2, 0, 0x100);
    if (p->mask & 2)
        PALANM_CopyHwPaletteToSlot(p->slots, 1, 0, 0x1a0);
    if (p->mask & 8)
        PALANM_CopyHwPaletteToSlot(p->slots, 3, 0, 0x1c0);
}



void func_021BC7B4(char *p,short b,unsigned char c,unsigned char d)
{
    if(((struct Obj02252 *)p)->fC&1)PALANM_RequestFade(((struct Obj02252 *)p)->f8,1,0x1fff,b,c,d,0,((struct Obj02252 *)p)->f0);
    if(((struct Obj02252 *)p)->fC&4)PALANM_RequestFade(((struct Obj02252 *)p)->f8,4,0xff,b,c,d,0,((struct Obj02252 *)p)->f0);
    if(((struct Obj02252 *)p)->fC&2)PALANM_RequestFade(((struct Obj02252 *)p)->f8,2,0x1fff,b,c,d,0,((struct Obj02252 *)p)->f0);
    if(((struct Obj02252 *)p)->fC&8)PALANM_RequestFade(((struct Obj02252 *)p)->f8,8,0x3fff,b,c,d,0,((struct Obj02252 *)p)->f0);
}




struct Ov208Win *ov208_func_021BC844(u16 heap, u32 kind, u8 layer, u8 pal, u8 objPal)
{
    struct Ov208Win *w;
    void *h;
    u32 sub;
    u32 type;
    u32 scr;

    w = func_02030734(heap, sizeof(*w), 1, d_021C8D98, 0x323);
    if (layer < 4) {
        sub = 0;
        type = 0;
    } else {
        sub = 1;
        type = 4;
    }
    h = func_020490F4(0x9f, heap);
    ARC_UTIL_UploadPaletteFromHandle(h, data_021C80F0[sub].chr, type, data_021C80E8[sub][kind] << 5, pal << 5,
                  0x20, heap);
    ARC_UTIL_UploadPaletteFromHandle(h, data_021C80F0[sub].chr, type, data_021C80E0[sub][kind] << 5,
                  objPal << 5, 0x20, heap);
    w->chrOfs = func_02049740(h, data_021C80F0[sub].scr, layer, 0, 0, heap);
    scr = data_021C80F0[sub].size;
    if (kind == 3 && sub == 0)
        scr = 0x20;
    func_02049990(h, scr, layer, 0, (u16)w->chrOfs, 0, 0, heap);
    func_020413B0(layer, 0, 0x15, 0x20, 3, pal);
    func_020413B0(layer, 0, 0, 0x20, 0x15, objPal);
    ARC_TOOL_DeleteHandle(h);
    func_02041B6C(layer);
    w->layer = layer;
    w->kind = 4;
    return w;
}




/*
 * Passes the byte at +4 and the two halfwords of the word at +0 on, then re-inits the object.
 */
void func_021BC97C(char *p)
{
    unsigned int w;

    w = ((struct Obj12112 *)p)->f0;
    func_0203FB44(((struct Obj12112 *)p)->f4, (unsigned short)w, (unsigned short)(w >> 16));
    func_020307B0((void *)((int)p));
}




void func_021BC99C(char *p)
{
    unsigned char c;

    c = ((struct Obj07226 *)p)->f5;
    if (c == 0) {
        func_02041EE4(((struct Obj07226 *)p)->f4, 1, 1);
        ((struct Obj07226 *)p)->f5 = 4;
    } else {
        ((struct Obj07226 *)p)->f5 = c - 1;
    }
}




u32 ov208_func_021BC9BC(int skip, u16 heap, u8 layer, u8 count, u8 pal, u8 palOfs, u32 arc,
                        u32 chr, u32 scr, u32 cell, u32 chrOfs)
{
    void *h;
    u32 type;

    type = 0;
    if (layer >= 4)
        type = 4;
    h = func_020490F4(arc, heap);
    if (skip == 0)
        ARC_UTIL_UploadPaletteFromHandle(h, chr, type, palOfs << 5, pal << 5, count << 5, heap);
    if (skip == 0)
        chrOfs = func_02049740(h, scr, layer, 0, 0, heap);
    func_02049990(h, cell, layer, 0, (u16)chrOfs, 0, 0, heap);
    func_020413B0(layer, 0, 0, 0x20, 0x18, pal);
    ARC_TOOL_DeleteHandle(h);
    func_02041B6C(layer);
    return chrOfs;
}



void func_021BCA54(u32 a, u32 packed)
{
    func_0203FB44(a, (u16)packed, (u16)(packed >> 16));
}



/*
 * 2026-10-02: only func_021BCC80 (unlabelled bx lr stub, filed as ov208_func_021BCC80.c) lacks a witness; bytes match.
 * Callee func_021BC35C is declared void in its matched file but returns the new object (caller stores r0).
 */
int func_021BCA68(void *owner, int unused, struct Ov208Args *args)
{
    struct Ov208Main_021BCA68 *p;
    GFL_HEAP_CreateChildHeap(1, 0x95, 0x90000);
    p = PROCSYS_AllocProcWork(owner, 0x2c, 0x95);
    MI_CpuFill8(p, 0, 0x2c);
    p->heap = 0x95;
    args->f10 = 0;
    p->disp = func_021BCE10(0, p->heap, 1);
    func_021BCEC0(p->disp);
    p->disp = func_021BCE10(0, p->heap, 0);
    p->font = GF_FONT_Create(0x17, 0, 0, 0, p->heap);
    p->gfx = (void *)PRINTSYS_QUE_Create((void *)p->heap);
    p->task = func_020056A0(func_021BCC80, p, 1);

    p->f14 = func_021BD8C0(p->heap, ZUKAN_SAVE_GetDexObtained(ZUKAN_SAVE_GetFromGameData(args->src)));
    p->f18 = func_021BE710(p->heap, (unsigned int)p->font);
    p->fsm = func_021BC35C(p->heap, args->src, p->disp, p->font, p->gfx, p->f14, p->f18, args->f8, args->fc, &args->fe);
    p->f20 = 0;
    p->f24 = 0;
    func_021BCC84((struct Ov208Mode *)args, (struct Ov208Slot *)p);
    p->f28 = 0;
    FADE_Start(3, 0, 0, 0);
    GFL_NET_RestartWithDefaultTimeout(1, p->heap);
    return 1;
}



/*
 * extent: 102 code bytes, then two zero alignment bytes at 021BCBB2.
 */
int func_021BCB4C(void *a,int b,int c,char *p)
{
    FADE_Start(3,16,16,0);
    if(((struct Obj02253 *)p)->f20)func_021BC26C(((struct Obj02253 *)p)->f20);
    if(((struct Obj02253 *)p)->f24)func_020307B0((void *)(((struct Obj02253 *)p)->f24));
    func_021BC39C(((struct Obj02253 *)p)->f1C);
    func_021BE778(((struct Obj02253 *)p)->f18);
    func_021BD954(((struct Obj02253 *)p)->f14);
    func_02030EAC(((struct Obj02253 *)p)->f10);
    PRINTSYS_QUE_Clear((struct PrintSys *)(*(unsigned *)&((struct Obj02253 *)p)->fC));
    PRINTSYS_QUE_Delete(((struct Obj02253 *)p)->fC);
    GF_FONT_Delete(((struct Obj02253 *)p)->f8);
    func_021BCEC0(*(char * *)&((struct Obj02253 *)p)->f4);
    func_020315D4(a);
    func_020306F0(149);
    return 1;
}



int func_021BCBB4(void *unused, int *cnt, struct Ov208Args *a, struct Ov208Main_021BCBB4 *m)
{
    int done = 0;
    u32 v;
    if (*cnt <= 8)
        *cnt = *cnt + 1;
    if (func_021BC274(m->obj, (int)m->fsm) != 0) {
        if (m->f28 != 0) {
            a->f4 = m->f28;
            func_021BCC84((struct Ov208Mode *)a, (struct Ov208Slot *)m);
            m->f28 = 0;
            done = 1;
        } else {
            return 1;
        }
    }
    if (done == 0) {
        v = func_021BDB08(m->f14);
        if (v == 0)
            v = func_021BDB54(m->f14);
        func_021BC2F0(m->obj, (int)m->fsm, v);
        switch (v) {
        case 1: a->f10 = 0; break;
        case 2: a->f10 = 1; break;
        case 6: m->f28 = 1; break;
        case 7: m->f28 = 2; break;
        case 8: m->f28 = 3; break;
        case 9: m->f28 = 4; break;
        }
    }
    func_021BD974(m->f14);
    func_021BE7A4(m->f18);
    PRINTSYS_QUE_Main(m->gfx);
    func_021BCF18(m->disp);
    func_021BCF2C(m->disp);
    if (done == 0)
        func_021BC310(m->obj, (int)m->fsm);
    func_021BCF3C(m->disp);
    return 0;
}



void func_021BCC80(void)
{
}



/*
 * 2026-10-04 (D2-16): callee func_021BF784 filed EXACT as src/matched/ov/ov208_func_021BF784.c (strh leaf). Still MATCH only because no
 * shard witnesses it yet; the integrator manifest run should make this EXACT. Symbols line now carries the ov208 hint.
 * 2026-10-02: only func_021BF784 (init for mode 2, another lane) has no witness yet; bytes match.
 */
void func_021BCC84(struct Ov208Mode *m, struct Ov208Slot *s)
{
    void **tbl;
    void *mem;
    if (s->obj != 0)
        func_021BC26C(s->obj);
    if (s->mem != 0)
        func_020307B0(s->mem);
    switch (m->mode) {
    case 1:
        mem = func_02030734(s->heap, 2, 1, d_021C8DB0, 0x1c3);
        func_021BEA00(mem, s->heap);
        s->mem = mem;
        tbl = d_021C8508;
        break;
    case 2:
        mem = func_02030734(s->heap, 2, 1, d_021C8DB0, 0x1cb);
        func_021BF784(mem, s->heap);
        s->mem = mem;
        tbl = d_021C8590;
        break;
    case 3:
        mem = func_02030734(s->heap, 2, 1, d_021C8DB0, 0x1d3);
        func_021C255C(mem, s->heap);
        s->mem = mem;
        tbl = d_021C86F0;
        break;
    case 4:
        mem = func_02030734(s->heap, 2, 1, d_021C8DB0, 0x1db);
        func_021C3B68(mem, s->heap);
        s->mem = mem;
        tbl = d_021C881C;
        break;
    }
    s->obj = func_021BC240(tbl, (int)s->mem, s->heap);
}



static inline void SetShading(GXShading shading) {REG60=(u16)((REG60 & ~0x3002)|(shading<<1));}



static inline void AntiAlias(int enable) {if(enable)REG60=(u16)((REG60 & ~0x3000)|0x10);else REG60&=(u16)~0x3010;}



static inline void AlphaTest(int enable,int ref) {if(enable){REG60=(u16)((REG60 & ~0x3000)|4);*(volatile u16 *)0x04000340=(u16)ref;}else REG60&=(u16)~0x3004;}



static inline void AlphaBlend(int enable) {if(enable)REG60=(u16)((REG60 & ~0x3000)|8);else REG60&=(u16)~0x3008;}



static inline void EdgeMarking(int enable) {if(enable)REG60=(u16)((REG60 & ~0x3000)|0x20);else REG60&=(u16)~0x3020;}



/*
 * lever: SDK g3x.h shading enum and boolean inline bodies preserve the hardware mask sequence; pool word at 021BCE04 is BFFF0000.
 * volatile: hardware 04000008 and 04000060 read/write at 021BCD78-021BCDBA; 04000580 write at 021BCDD8.
 */
void func_021BCD68(void)
{
    unsigned i;
    BG_SYS_SetMainPlaneVisible(1,1);
    *(volatile u16 *)0x04000008=(*(volatile u16 *)0x04000008 & ~3)|1;
    SetShading(ShadeHighlight);
    AntiAlias(0);
    AlphaTest(0,0);
    AlphaBlend(1);
    EdgeMarking(0);
    G3X_SetFog(0,0,0,0);
    G3X_SetClearColor(0,0,0x7fff,0x3f,0);
    *(volatile unsigned *)0x04000580=0xbfff0000;
    for(i=0;i<4;i++)G3D_SYSTEM_SetLight((unsigned char)i,d_021C8164[i]);
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
}
