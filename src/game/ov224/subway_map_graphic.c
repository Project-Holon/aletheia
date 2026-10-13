/*
 * file:     subway_map_graphic.c
 * unit:     yes
 * function: func_021B95A0, func_021B9718, func_021B9788, func_021B9820, func_021B9824, func_021B9898, func_021B989C, func_021B9940, func_021B99E8, func_021B9A44, func_021B9A58, func_021B9A6C, func_021B9ACC, func_021B9B04, func_021B9B08, func_021B9B10, func_021B9B50, func_021B9B6C, func_021B9B74, func_021B9B7C
 * address:  0x021B95A0
 * region:   ov224
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
 *   func_02082BCC 0x02082BCC arm
 *   func_0204047C 0x0204047C arm
 *   func_02043588 0x02043588 arm
 *   func_0207D518 0x0207D518 arm
 *   func_02043558 0x02043558 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_02043598 0x02043598 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204E720 0x0204E720 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_020056A0 0x020056A0 thumb
 *   d_021B9C04 0x021B9C04 data a4
 *   d_021B9D40 0x021B9D40 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_0204E804 0x0204E804 arm
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_02035D20 0x02035D20 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   table_021B9C80 0x021B9C80 data ov224
 *   func_02030734 0x02030734 arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_0201DD60 0x0201DD60 thumb
 *   file 0x021B9D58 data ov224 a1
 *   vram 0x021B9CA0 data
 *   func_020307B0 0x020307B0 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021B9BE8 0x021B9BE8 thumb ov224
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   config 0x021B9C54 data
 *   table_021B9CD0 0x021B9CD0 data ov224
 *   d_021B9CD0 0x021B9CD0 data a4
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   vecA 0x021B9C3C data
 *   vecB 0x021B9C30 data
 *   vecC 0x021B9C48 data
 *   cfg 0x020A1EB8 data
 */
#include "../../matched/include/Obj06730.h"
#include "../../matched/include/Obj14799.h"
#include "../../matched/include/Obj26109.h"
#include "../../matched/include/Obj26110.h"
#include "../../matched/include/Obj14800.h"
#include "../../matched/include/Obj26111.h"

#define DISP (*(volatile u16 *)0x04000060)
struct GfFont;
struct Obj0203159C;
struct Node;
struct PrintSys;
struct S020315D4;
struct DispVram;
struct BgTemplate;
struct DispConfig;
struct Bank;
struct Cfg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef enum { ZERO=0,ONE=1 } Index;

typedef enum { MODE=2 } Mode;

struct BgTemplate {u32 words[8];};

struct Entry { u32 id; struct BgTemplate bg; u32 kind,visible; };

struct Assets {u32 palette,screen,chars;};

struct Work {u16 heap,pad2; void **args; void *screen,*font;u32 string;void *task;};

typedef signed int     s32;

typedef enum { GX_SHADING_TOON = 0, GX_SHADING_HIGHLIGHT = 1 } GXShading;

struct Record { u32 id; u32 bg[8]; u32 kind; u32 visible; };

typedef signed short s16;

extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Obj0203159C *,u32,u32);
extern void func_02082BCC(void *,u32,u32);
extern struct GfFont *func_0201D7EC(int,int,int,int,u32);
extern u32 func_0201C440(void *);
extern void func_0204047C(int,u16);
extern void *func_020056A0(u32,u32,u32);
extern void func_02043588(void);
extern void func_0207D518(u32);
extern void func_02043558(void);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
extern void func_02043598(u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_02049238(void *);
extern void func_020409B4(u32);
extern void func_0204E720(u32,int,int,int);
extern void func_0203D34C(u32,u32);
extern void func_020403F4(u32 i);
extern void func_02030EAC(struct Node *n);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int heap);
extern int func_0204E804(void);
extern u32 func_020362DC(void);
extern void func_020355D8(u8 v);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_020434DC(u32,u32);
extern void func_0207DC44(int,int,int,int);
extern void func_0207DD24(u16,int,int,int,int);
extern void func_02046A94(u32 idx, const u16 *src);
extern void func_02046BE0(u32,u32);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_0204335C(u32);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_0201DD60(void);
extern u32 func_020307B0(void *p);
extern void func_0201DD68(void);
extern void func_021B9BE8(u32 *p);
extern void func_0203F8F4(u32);
extern void func_02045088(u32);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, unsigned int heapId);
extern void func_0204B270(struct Bank *bank);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_02046440(u32,u32,u32,u32,unsigned short,u32,void(*)(void));
extern void *func_02048A24(u32,u32,u32,u32,u32,u32,u32,u32,void *,void *,void *,u32);
int func_021B95A0(struct Obj0203159C *proc,void *unused,void **args);
int func_021B9718(void *a,int b,int c,char *p);
int func_021B9788(void *a,unsigned *state,int b,char *p);
void func_021B9820(void);
void func_021B9824(u16 *work);
void func_021B9898(char *unused);
void func_021B989C(void);
void *func_021B9940(u32 swap, u32 heap);
void func_021B99E8(char *p);
void func_021B9A44(void *p);
void func_021B9A58(void *unused, char *p);
void func_021B9A6C(void *p, u32 heap);
void func_021B9ACC(void *p);
void func_021B9B04(void *a0);
void func_021B9B08(void *a0);
void func_021B9B10(unsigned char *p, int a, int b);
void func_021B9B50(char *p);
void func_021B9B6C(void *a0);
void func_021B9B74(void *a0);
void func_021B9B7C(void **p,u32 heap);
extern const struct Entry d_021B9C04[];
extern struct Assets d_021B9D40[];
extern u16 table_021B9C80[][4];
extern char file[], vram[];
extern u32 config[];
extern struct Record table_021B9CD0[];
extern const u8 d_021B9CD0[];
extern const s16 cfg[];
extern u32 vecA[],vecB[],vecC[];



static inline void SetMode(Mode mode) {
 *(volatile u32 *)0x04001000 &= 0xffff1fff;
 *(volatile u32 *)0x04001000 |= mode<<15;
}



int func_021B95A0(struct Obj0203159C *proc,void *unused,void **args)
{
 struct Work *p;
 Index i;
 const struct Entry *row;
 u32 id,choice;
 u16 heap;
 void *arc;
 func_0203064C((u32)((void *)1),0x88,0x30000);
 p=func_0203159C(proc,0x18,0x88);
 func_02082BCC(p,0,0x18);
 p->heap=0x88; p->args=args;
 p->screen=func_021B9940(1,p->heap);
 p->font=func_0201D7EC(23,0,0,0,p->heap);
 p->string=func_0201C440((void *)(u32)p->heap);
 func_0204047C(1,1); func_0204047C(2,0);
 p->task=func_020056A0((u32)func_021B9820,(u32)p,1);
 func_021B9824((u16 *)p);
 i=ZERO;
 *(volatile u16 *)0x04001050=0;
 SetMode(MODE);
 func_02043588();
 func_0207D518(0);
 func_02043558();
 do {
  row=&d_021B9C04[i]; id=row->id;
  func_0203FCA0((u8)id,&row->bg,(u8)row->kind);
  func_020414AC(id);
  func_02040588(id,row->visible);
  i++;
 }while(i<1U);
 func_02043598(16,1);
 heap=p->heap;
 choice=1;
 if(*((u8 *)*p->args+0x1d)!=1) choice=0;
 arc=func_020490F4(30,heap);
 func_02049B68(arc,d_021B9D40[choice].palette,4,0,0,heap);
 func_02049658(arc,d_021B9D40[choice].screen,4,0,0,0,heap);
 func_020498F4(arc,d_021B9D40[choice].chars,4,0,0,0,heap);
 func_02049238(arc);
 func_020409B4(4);
 func_0204E720(3,16,0,0);
 func_0203D34C(0,p->heap);
 return 1;
}




/*
 * lever: enum do-loop with unsigned bound retains one table iteration; unsigned for-loop folds it, enum for-loop adds an entry guard.
 * volatile: sub-display blend/control reads and writes 021B973C-021B9746.
 */
int func_021B9718(void *a,int b,int c,char *p)
{
    Index i=ZERO;
    do { func_020403F4((unsigned char)d_021B9C04[i].id); i++; } while(i<1U);
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04001000 &=~0xe000;
    func_021B9898(p);
    func_02030EAC(((struct Obj06730 *)p)->f14); func_0201C6EC(((struct Obj06730 *)p)->f10); func_0201C4C0(((struct Obj06730 *)p)->f10);
    func_0201D83C(((struct Obj06730 *)p)->fC); func_021B99E8(*(char * *)&((struct Obj06730 *)p)->f8);
    func_020315D4(a); func_020306F0(136);
    return 1;
}





int func_021B9788(void *a,unsigned *state,int b,char *p)
{
    int x,y,flag;
    switch(*state) {
    case 0: *state=1; break;
    case 1: if(!func_0204E804()) *state=2; break;
    case 2:
        flag=0;
        if(func_020362DC()&3) { func_020355D8(0); flag=1; }
        else if(func_02035D20((u32 *)(&x),(u32 *)(&y))) { func_020355D8(1); flag=1; }
        if(flag) { *state=3; func_0204E720(3,0,16,0); }
        break;
    case 3: if(!func_0204E804()) *state=4; break;
    case 4: return 1;
    }
    func_0201C4E4(((struct Obj14799 *)p)->f10); func_021B9A44(((struct Obj14799 *)p)->f8);
    return 0;
}





void func_021B9820(void) {}





void func_021B9824(u16 *work)
{
    void *narc = func_020490F4(0xce, *work);
    func_02049B68(narc, 0, 0, 0, 0, *work);
    func_02049658(narc, 1, 1, 0, 0, 0, *work);
    func_020498F4(narc, 2, 1, 0, 0, 0, *work);
    func_020498F4(narc, 3, 2, 0, 0, 0, *work);
    func_02049238(narc);
    func_020409B4(1);
    func_020409B4(2);
}



void func_021B9898(char *unused) {}



static inline void G2_SetBG0Priority(int priority) {
    *(volatile u16 *)0x04000008 = (u16)((*(volatile u16 *)0x04000008 & ~3) | priority);
}



static inline void G3X_SetShading(GXShading shading) {
    DISP = (u16)((DISP & ~(2 | 0x1000 | 0x2000)) | (shading << 1));
}



static inline void G3X_AntiAlias(int enable) {
    if(enable) DISP = (u16)((DISP & ~(0x1000|0x2000)) | 16);
    else DISP &= (u16)~(16|0x1000|0x2000);
}



static inline void G3X_AlphaTest(int enable,int ref) {
    if(enable) { DISP = (u16)((DISP & ~(0x1000|0x2000)) | 4); *(volatile u16 *)0x04000340 = (u16)ref; }
    else DISP &= (u16)~(4|0x1000|0x2000);
}



static inline void G3X_AlphaBlend(int enable) {
    if(enable) DISP = (u16)((DISP & ~(0x1000|0x2000)) | 8);
    else DISP &= (u16)~(8|0x1000|0x2000);
}



static inline void G3X_EdgeMarking(int enable) {
    if(enable) DISP = (u16)((DISP & ~(0x1000|0x2000)) | 32);
    else DISP &= (u16)~(32|0x1000|0x2000);
}



void func_021B989C(void)
{
    u32 i;
    func_020434DC(1,1);
    i = 0;
    G2_SetBG0Priority(0);
    G3X_SetShading(GX_SHADING_HIGHLIGHT);
    G3X_AntiAlias(0);
    G3X_AlphaTest(0,0);
    G3X_AlphaBlend(1);
    G3X_EdgeMarking(0);
    func_0207DC44(0,0,0,0);
    func_0207DD24(0,0,0x7fff,0x3f,0);
    *(volatile u32 *)0x04000580 = 0xbfff0000;
    for (; i < 4; i++) func_02046A94((unsigned char)i,table_021B9C80[i]);
    func_02046BE0(0,0);
}



static inline void G2_BlendNone(void) { *(volatile u16 *)0x04000050 = 0; }



static inline void G2S_BlendNone(void) { *(volatile u16 *)0x04001050 = 0; }



static inline void GX_SetVisibleWnd(int window) {
    *(volatile u32 *)0x04000000 = (u32)((*(volatile u32 *)0x04000000 & ~0xE000) | (window << 13));
}



static inline void GXS_SetVisibleWnd(int window) {
    *(volatile u32 *)0x04001000 = (u32)((*(volatile u32 *)0x04001000 & ~0xE000) | (window << 13));
}



void *func_021B9940(u32 swap, u32 heap)
{
    char *p = func_02030734(heap, 16, 0, file, 460);
    func_02082BCC(p, 0, 16);
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    func_0204335C(0);
    func_020433E0((const struct DispVram *)vram);
    func_0204363C(swap);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_021B9A6C(p, heap);
    func_021B9B10((unsigned char *)p + 4, (int)vram, heap);
    func_021B9B7C((void **)(p + 8), heap);
    ((struct Obj26109 *)p)->fC = func_020056A0((u32)func_021B9A58, (u32)p, 0);
    return p;
}



void func_021B99E8(char *p)
{
    func_02030EAC(((struct Obj26110 *)p)->fC);
    func_021B9BE8((u32 *)(p + 8));
    func_021B9B50(p + 4);
    func_021B9ACC(p);
    func_0201DD68();
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    func_02082BCC(p, 0, 16);
    func_020307B0(p);
}



void func_021B9A44(void *p)
{
    void func_021B9B6C(void *);
    void func_021B9B04(void *);
    func_021B9B6C((char *)p + 4);
    func_021B9B04(p);
}



/*
 * Addresses are Black-image addresses.
 */
void func_021B9A58(void *unused, char *p)
{
    func_021B9B08(p);
    func_021B9B74(p + 4);
}


void func_021B9A6C(void *p, u32 heap)
{
    u32 i = 0;
    func_02082BCC(p, 0, 4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)config);
    for (; i < 2; i++) {
        struct Record *r = &table_021B9CD0[i];
        u32 id = r->id;
        func_0203FCA0((u8)id, (const struct BgTemplate *)r->bg, (u8)r->kind);
        func_020414AC(id);
        func_02040588(id, r->visible);
    }
}


void func_021B9ACC(void *p) {
    u32 i;
    for (i=0; i<2; i++) func_020403F4((u8)(*(const u32 *)(d_021B9CD0+i*44)));
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(p,0,4);
}


void func_021B9B04(void *a0) {}


void func_021B9B08(void *a0) { func_020419E4(); }



void func_021B9B10(unsigned char *p, int a, int b)
{
    func_02082BCC(p, 0, 4);
    func_0204A48C((const struct Cfg *)0x021B9C64, a, b);
    ((struct Obj14800 *)p)->f0 = (int)func_0204B100(0x80, 0, b);
    func_0204B270((void *)((struct Obj14800 *)p)->f0);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}



void func_021B9B50(char *p)
{
    func_0204B1CC((struct Bank *)(((struct Obj26111 *)p)->f0));
    func_0204A5AC();
    func_02082BCC(p, 0, 4);
}


void func_021B9B6C(void *a0) { func_0204A600(); }


void func_021B9B74(void *a0) { func_0204A648(); }


void func_021B9B7C(void **p,u32 heap)
{
    func_02046440(0,1,0,1,0,heap,func_021B989C);
    *p = func_02048A24(0,cfg[6],cfg[7],0x1555,0,0x1000,0x400000,0,
        vecA,vecB,vecC,heap);
}
