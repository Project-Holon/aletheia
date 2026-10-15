/*
 * file:     subway_map_graphic.c
 * unit:     yes
 * function: func_021B95A0, func_021B9718, func_021B9788, func_021B9820, func_021B9824, func_021B9898, func_021B989C, func_021B9940, func_021B99E8, func_021B9A44, func_021B9A58, func_021B9A6C, func_021B9ACC, func_021B9B04, func_021B9B08, func_021B9B10, func_021B9B50, func_021B9B6C, func_021B9B74, func_021B9B7C, func_021B9BE8
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
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_0204047C 0x0204047C arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0207D518 0x0207D518 arm
 *   BG_SYS_ClearSubBgPlanes 0x02043558 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 *   FADE_Start 0x0204E720 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_020056A0 0x020056A0 thumb
 *   d_021B9C04 0x021B9C04 data a4
 *   d_021B9D40 0x021B9D40 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_02030EAC 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   FADE_IsActive 0x0204E804 arm
 *   KEY_GetTrg 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   table_021B9C80 0x021B9C80 data ov224
 *   func_02030734 0x02030734 arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   func_0201DD60 0x0201DD60 thumb
 *   file 0x021B9D58 data ov224 a1
 *   vram 0x021B9CA0 data
 *   func_020307B0 0x020307B0 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   config 0x021B9C54 data
 *   table_021B9CD0 0x021B9CD0 data ov224
 *   d_021B9CD0 0x021B9CD0 data a4
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   vecA 0x021B9C3C data
 *   vecB 0x021B9C30 data
 *   vecC 0x021B9C48 data
 *   cfg 0x020A1EB8 data
 *   BMP_WIN_Exit  0x020450C8  arm  arm9
 *   CLACT_DrawSystem  0x0204A600  arm  arm9
 *   CLACT_VBlankSystem  0x0204A648  arm  arm9
 *   G3D_CAMERA_Delete  0x02048AC4  arm
 *   G3D_SYSTEM_Exit  0x02046788  arm
 *   BG_SYS_Delete  0x0203F9B4  arm  arm9
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

extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *,u32,u32);
extern void MI_CpuFill8(void *,u32,u32);
extern struct GfFont *GF_FONT_Create(int,int,int,int,u32);
extern u32 PRINTSYS_QUE_Create(void *);
extern void func_0204047C(int,u16);
extern void *func_020056A0(u32,u32,u32);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0207D518(u32);
extern void BG_SYS_ClearSubBgPlanes(void);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_020409B4(u32);
extern void FADE_Start(u32,int,int,int);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
extern void func_020403F4(u32 i);
extern void func_02030EAC(struct Node *n);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int heap);
extern int FADE_IsActive(void);
extern u32 KEY_GetTrg(void);
extern void func_020355D8(u8 v);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void BG_SYS_SetMainPlaneVisible(u32,u32);
extern void G3X_SetFog(int,int,int,int);
extern void G3X_SetClearColor(u16,int,int,int,int);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32,u32);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void BG_SYS_ClearGraphicsMemory(u32);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0204363C(u32);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void func_0201DD60(void);
extern u32 func_020307B0(void *p);
extern void func_0201DD68(void);
extern void BG_SYS_Create(u32);
extern void BMP_WIN_Init(u32);
extern void func_0203FC28(struct DispConfig *cfg);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void func_020419E4(void);
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, unsigned int heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void G3D_SYSTEM_Init(u32,u32,u32,u32,unsigned short,u32,void(*)(void));
extern void *G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,void *,void *,void *,u32);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(u32 x);
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
void func_021B9BE8(u32 *p);
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
 GFL_HEAP_CreateChildHeap((u32)((void *)1),0x88,0x30000);
 p=PROCSYS_AllocProcWork(proc,0x18,0x88);
 MI_CpuFill8(p,0,0x18);
 p->heap=0x88; p->args=args;
 p->screen=func_021B9940(1,p->heap);
 p->font=GF_FONT_Create(23,0,0,0,p->heap);
 p->string=PRINTSYS_QUE_Create((void *)(u32)p->heap);
 func_0204047C(1,1); func_0204047C(2,0);
 p->task=func_020056A0((u32)func_021B9820,(u32)p,1);
 func_021B9824((u16 *)p);
 i=ZERO;
 *(volatile u16 *)0x04001050=0;
 SetMode(MODE);
 BG_SYS_ClearSubPlanes();
 func_0207D518(0);
 BG_SYS_ClearSubBgPlanes();
 do {
  row=&d_021B9C04[i]; id=row->id;
  BG_SYS_InitBgLayer((u8)id,&row->bg,(u8)row->kind);
  func_020414AC(id);
  func_02040588(id,row->visible);
  i++;
 }while(i<1U);
 BG_SYS_SetSubPlaneVisible(16,1);
 heap=p->heap;
 choice=1;
 if(*((u8 *)*p->args+0x1d)!=1) choice=0;
 arc=func_020490F4(30,heap);
 func_02049B68(arc,d_021B9D40[choice].palette,4,0,0,heap);
 func_02049658(arc,d_021B9D40[choice].screen,4,0,0,0,heap);
 func_020498F4(arc,d_021B9D40[choice].chars,4,0,0,0,heap);
 ARC_TOOL_DeleteHandle(arc);
 func_020409B4(4);
 FADE_Start(3,16,0,0);
 GFL_NET_RestartWithDefaultTimeout(0,p->heap);
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
    func_02030EAC(((struct Obj06730 *)p)->f14); PRINTSYS_QUE_Clear(((struct Obj06730 *)p)->f10); PRINTSYS_QUE_Delete(((struct Obj06730 *)p)->f10);
    GF_FONT_Delete(((struct Obj06730 *)p)->fC); func_021B99E8(*(char * *)&((struct Obj06730 *)p)->f8);
    func_020315D4(a); func_020306F0(136);
    return 1;
}






int func_021B9788(void *a,unsigned *state,int b,char *p)
{
    int x,y,flag;
    switch(*state) {
    case 0: *state=1; break;
    case 1: if(!FADE_IsActive()) *state=2; break;
    case 2:
        flag=0;
        if(KEY_GetTrg()&3) { func_020355D8(0); flag=1; }
        else if(TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))) { func_020355D8(1); flag=1; }
        if(flag) { *state=3; FADE_Start(3,0,16,0); }
        break;
    case 3: if(!FADE_IsActive()) *state=4; break;
    case 4: return 1;
    }
    PRINTSYS_QUE_Main(((struct Obj14799 *)p)->f10); func_021B9A44(((struct Obj14799 *)p)->f8);
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
    ARC_TOOL_DeleteHandle(narc);
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
    BG_SYS_SetMainPlaneVisible(1,1);
    i = 0;
    G2_SetBG0Priority(0);
    G3X_SetShading(GX_SHADING_HIGHLIGHT);
    G3X_AntiAlias(0);
    G3X_AlphaTest(0,0);
    G3X_AlphaBlend(1);
    G3X_EdgeMarking(0);
    G3X_SetFog(0,0,0,0);
    G3X_SetClearColor(0,0,0x7fff,0x3f,0);
    *(volatile u32 *)0x04000580 = 0xbfff0000;
    for (; i < 4; i++) G3D_SYSTEM_SetLight((unsigned char)i,table_021B9C80[i]);
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
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
    MI_CpuFill8(p, 0, 16);
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)vram);
    func_0204363C(swap);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
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
    MI_CpuFill8(p, 0, 16);
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
    MI_CpuFill8(p, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    func_0203FC28((struct DispConfig *)config);
    for (; i < 2; i++) {
        struct Record *r = &table_021B9CD0[i];
        u32 id = r->id;
        BG_SYS_InitBgLayer((u8)id, (const struct BgTemplate *)r->bg, (u8)r->kind);
        func_020414AC(id);
        func_02040588(id, r->visible);
    }
}



void func_021B9ACC(void *p) {
    u32 i;
    for (i=0; i<2; i++) func_020403F4((u8)(*(const u32 *)(d_021B9CD0+i*44)));
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(p,0,4);
}



void func_021B9B04(void *a0) {}



void func_021B9B08(void *a0) { func_020419E4(); }




void func_021B9B10(unsigned char *p, int a, int b)
{
    MI_CpuFill8(p, 0, 4);
    CLACT_InitSystem((const struct Cfg *)0x021B9C64, a, b);
    ((struct Obj14800 *)p)->f0 = (int)CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer((void *)((struct Obj14800 *)p)->f0);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}




void func_021B9B50(char *p)
{
    CLACT_DeleteUnit((struct Bank *)(((struct Obj26111 *)p)->f0));
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 4);
}



void func_021B9B6C(void *a0) { CLACT_DrawSystem(); }



void func_021B9B74(void *a0) { CLACT_VBlankSystem(); }



void func_021B9B7C(void **p,u32 heap)
{
    G3D_SYSTEM_Init(0,1,0,1,0,heap,func_021B989C);
    *p = G3D_CAMERA_Create(0,cfg[6],cfg[7],0x1555,0,0x1000,0x400000,0,
        vecA,vecB,vecC,heap);
}


void func_021B9BE8(u32 *p)
{
    G3D_SYSTEM_Exit(G3D_CAMERA_Delete((void *)(*p)));
}
