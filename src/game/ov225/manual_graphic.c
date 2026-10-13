/*
 * file:     manual_graphic.c
 * unit:     yes
 * function: func_021B95A0, func_021B9660, func_021B96BC, func_021B98FC, func_021B9900, func_021B99A0, func_021B99F4, func_021B9A08, func_021B9A14, func_021B9A28, func_021B9A88, func_021B9AC0, func_021B9AC4, func_021B9ACC, func_021B9B0C, func_021B9B28, func_021B9B30, func_021B9B38
 * address:  0x021B95A0
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_0204047C 0x0204047C arm
 *   FADE_Start 0x0204E720 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021B9D18 0x021B9D18 thumb ov225
 *   func_021BB2B4 0x021BB2B4 thumb ov225
 *   func_021BB308 0x021BB308 thumb ov225
 *   func_021BB7F4 0x021BB7F4 thumb ov225
 *   func_021BBA14 0x021BBA14 thumb ov225
 *   func_021BBAE8 0x021BBAE8 thumb ov225
 *   func_021B9DEC 0x021B9DEC thumb ov225
 *   func_02030EAC 0x02030EAC arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   FADE_IsActive 0x0204E804 arm
 *   func_021BB31C 0x021BB31C thumb ov225
 *   func_021BB6E0 0x021BB6E0 thumb ov225
 *   func_021BB844 0x021BB844 thumb ov225
 *   func_021BBA64 0x021BBA64 thumb ov225
 *   func_021B9BEC 0x021B9BEC thumb ov225
 *   func_021B9BE0 0x021B9BE0 thumb ov225
 *   func_021B9C98 0x021B9C98 thumb ov225
 *   func_021B9CB0 0x021B9CB0 thumb ov225
 *   func_021B9BC8 0x021B9BC8 thumb ov225
 *   func_021B9C0C 0x021B9C0C thumb ov225
 *   func_021B9CC8 0x021B9CC8 thumb ov225
 *   func_021B9BF8 0x021B9BF8 thumb ov225
 *   func_021BBA74 0x021BBA74 thumb ov225
 *   func_021BBB0C 0x021BBB0C thumb ov225
 *   func_021BB854 0x021BB854 thumb ov225
 *   func_021B9E60 0x021B9E60 thumb ov225
 *   func_02030734 0x02030734 arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   file 0x021BBFE0 data ov225 a1
 *   vram 0x021BBE1C data ov225
 *   func_020307B0 0x020307B0 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   config 0x021BBDF0 data ov225
 *   table 0x021BBE4C data ov225
 *   d_021BBE4C 0x021BBE4C data a4
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   BMP_WIN_Exit  0x020450C8  arm  arm9
 */
#include "../../matched/include/Obj04649.h"
#include "../../matched/include/Obj00100.h"
#include "../../matched/include/Obj26116.h"
#include "../../matched/include/Obj26117.h"
#include "../../matched/include/Obj26118.h"
#include "../../matched/include/Obj26119.h"
#include "../../matched/include/Obj26120.h"
#include "../../matched/include/Obj26122.h"
#include "../../matched/include/Obj26124.h"
#include "../../matched/include/Obj26125.h"
#include "../../matched/include/Obj26126.h"
#include "../../matched/include/Obj26127.h"
#include "../../matched/include/Obj26128.h"
#include "../../matched/include/Obj26129.h"
#include "../../matched/include/Obj26130.h"
#include "../../matched/include/Obj14801.h"
#include "../../matched/include/Obj26131.h"

struct Obj0203159C;
struct Node;
struct S020315D4;
struct Big;
struct Data;
struct Owner;
struct Q;
struct DispVram;
struct BgTemplate;
struct DispConfig;
struct Bank;
struct Cfg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Args { void *data; u32 flag; };

struct Work {
    u16 heap; u16 pad2; struct Args *args; void *data; void *task;
    u32 state; u8 record14[8]; void *record1c; u16 record20; u16 record22;
    u8 pad24[12]; void *record30; u16 record34; u16 record36; u16 record38;
    u8 pad3a[14]; u8 record48; u8 pad49; u16 record4a; u16 record4c; u16 record4e;
    u8 rest[40];
};

typedef enum {ZERO=0,ONE=1} Flag;

struct Record { u32 id; u32 bg[8]; u32 kind; u32 visible; };

extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,u32,u32);
extern void *func_021B9D18(void *,u16);
extern void func_0204047C(int,u16);
extern void *func_020056A0(void (*)(void *,char *),void *,u32);
extern void FADE_Start(u32,int,int,int);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
extern char *func_021BB2B4(char *,char *);
extern void func_021BB308(char *p);
extern void func_021BB7F4(char *p);
extern void func_021BBA14(char *p);
extern void func_021BBAE8(char *p);
extern void func_021B9DEC(char *p);
extern void func_02030EAC(struct Node *n);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern int FADE_IsActive(void);
extern int func_021BB31C(char *);
extern char *func_021BB6E0(char *,char *);
extern int func_021BB844(char *);
extern int func_021BBA64(char *);
extern u16 func_021B9BEC(char *,int);
extern u16 func_021B9BE0(char *,int);
extern int func_021B9C98(void *,int,int);
extern void func_021B9CB0(void *unused, int code, struct Big *save);
extern u16 func_021B9BC8(char *,int);
extern u16 func_021B9C0C(char *,int,int);
extern int func_021B9CC8(unsigned unused, unsigned key);
extern u16 func_021B9BF8(char *,int,int);
extern char *func_021BBA74(char *,char *);
extern int func_021BBB0C(char *);
extern struct Q *func_021BB854(struct Owner *p, struct Data *data);
extern void func_021B9E60(char *);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void BG_SYS_ClearGraphicsMemory(u32);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0204363C(u32);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern u32 func_020307B0(void *p);
extern void func_0201DD68(void);
extern void func_0203F8F4(u32);
extern void BMP_WIN_Init(u32);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8, u8);
extern void func_020403F4(u32 i);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, unsigned int heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
int func_021B95A0(void *proc, void *unused, struct Args *args);
int func_021B9660(void *proc, void *a, void *b, char *work);
int func_021B96BC(void *a,u32 *state,void *unused,char *p);
void func_021B98FC(void *unused, char *work);
void *func_021B9900(u32 swap, u32 heap);
void func_021B99A0(char *p);
void func_021B99F4(char *p);
u32 func_021B9A08(const u8 *p);
void func_021B9A14(void *unused, char *p);
void func_021B9A28(void *p, u32 heap);
void func_021B9A88(void *p);
void func_021B9AC0(void *a0);
void func_021B9AC4(void *a0);
void func_021B9ACC(unsigned char *p, int a, int b);
void func_021B9B0C(char *p);
void func_021B9B28(void *a0);
void func_021B9B30(void *a0);
u32 func_021B9B38(const u32 *p);
extern char file[], vram[];
extern u32 config[];
extern struct Record table[];
extern const u8 d_021BBE4C[];

int func_021B95A0(void *proc, void *unused, struct Args *args)
{
    struct Work *p;
    GFL_HEAP_CreateChildHeap(1,0x90,0x50000);
    p = PROCSYS_AllocProcWork(proc,0x78,0x90);
    MI_CpuFill8(p,0,0x78);
    p->heap = 0x90;
    p->args = args;
    args->flag = 1;
    p->data = func_021B9D18(p->args->data,p->heap);
    func_0204047C(4,3);
    func_0204047C(5,2);
    func_0204047C(6,1);
    func_0204047C(7,0);
    p->task = func_020056A0(func_021B98FC,p,1);
    FADE_Start(3,16,0,0);
    GFL_NET_RestartWithDefaultTimeout(0,p->heap);
    p->record14[0] = 0;
    p->record20 = 0;
    p->record22 = 0;
    p->record30 = 0;
    p->record34 = 0;
    p->record36 = 0;
    p->record38 = 0;
    p->record48 = 1;
    p->record4a = 0;
    p->record4c = 0xffff;
    p->record4e = 0;
    p->state = 0;
    p->record1c = func_021BB2B4((char *)p->record14,p->data);
    return 1;
}

int func_021B9660(void *proc, void *a, void *b, char *work)
{
    switch (((struct Obj04649 *)work)->f10) {
    case 0: func_021BB308(((struct Obj04649 *)work)->f1C); break;
    case 1: func_021BB7F4(((struct Obj04649 *)work)->f2C); break;
    case 2: func_021BBA14(((struct Obj04649 *)work)->f44); break;
    case 3: func_021BBAE8(((struct Obj04649 *)work)->f74); break;
    }
    func_02030EAC(((struct Obj04649 *)work)->fC);
    func_021B9DEC(((struct Obj04649 *)work)->f8);
    func_020315D4(proc);
    func_020306F0(0x90);
    return 1;
}

int func_021B96BC(void *a,u32 *state,void *unused,char *p)
{
 int done;
 u32 count;
 u16 id,i,item,selected;
 switch(*state) {
 case 0: *state=1; break;
 case 1: if(!FADE_IsActive()) *state=2; break;
 case 2:
  done=0;
  switch(((struct Obj00100 *)p)->f10) {
  case 0:
   if(!func_021BB31C(*(char * *)&((struct Obj00100 *)p)->f1C)) goto innerDone;
   {
    if(((struct Obj00100 *)p)->f18<=1) {
     if(((struct Obj00100 *)p)->f18==0) ((struct Obj26116 *)(*(char * *)&((struct Obj00100 *)p)->f4))->f4=0;
     else if(((struct Obj00100 *)p)->f18==1) ((struct Obj26117 *)(*(char * *)&((struct Obj00100 *)p)->f4))->f4=1;
     done=1;
    } else {
     func_021BB308(*(char * *)&((struct Obj00100 *)p)->f1C);
     if(((struct Obj00100 *)p)->f18==2) {
      ((struct Obj00100 *)p)->f10=1;
      ((struct Obj00100 *)p)->f20=0; ((struct Obj00100 *)p)->f22=0;
      *(char * *)&((struct Obj00100 *)p)->f2C=func_021BB6E0(p+0x20,*(char * *)&((struct Obj00100 *)p)->f8);
     } else if(((struct Obj00100 *)p)->f18==3) {
      ((struct Obj00100 *)p)->f10=2; ((struct Obj00100 *)p)->f30=1;
      ((struct Obj00100 *)p)->f34=done;
      ((struct Obj00100 *)p)->f36=done; ((struct Obj00100 *)p)->f38=done;
      *(char * *)&((struct Obj00100 *)p)->f44=(char *)func_021BB854((struct Owner *)(p+0x30),(struct Data *)(*(char * *)&((struct Obj00100 *)p)->f8));
     }
    }
   }
   break;
  case 1:
   if(!func_021BB844(*(char * *)&((struct Obj00100 *)p)->f2C)) {
   default:
innerDone:
    break;
   } else {
    func_021BB7F4(*(char * *)&((struct Obj00100 *)p)->f2C);
    if(((struct Obj00100 *)p)->f24==0) {
     ((struct Obj00100 *)p)->f10=done;
     *(char * *)&((struct Obj00100 *)p)->f1C=func_021BB2B4(p+0x14,*(char * *)&((struct Obj00100 *)p)->f8);
    } else {
     ((struct Obj00100 *)p)->f10=2; ((struct Obj00100 *)p)->f30=0;
     ((struct Obj00100 *)p)->f34=((struct Obj00100 *)p)->f28;
     ((struct Obj00100 *)p)->f36=done; ((struct Obj00100 *)p)->f38=done;
     *(char * *)&((struct Obj00100 *)p)->f44=(char *)func_021BB854((struct Owner *)(p+0x30),(struct Data *)(*(char * *)&((struct Obj00100 *)p)->f8));
    }
   }
   break;
  case 2:
   if(func_021BBA64(*(char * *)&((struct Obj00100 *)p)->f44)) {
    func_021BBA14(*(char * *)&((struct Obj00100 *)p)->f44);
    if(((struct Obj00100 *)p)->f3C==0) {
     if(((struct Obj00100 *)p)->f30==0) { ((struct Obj00100 *)p)->f10=1; *(char * *)&((struct Obj00100 *)p)->f2C=func_021BB6E0(p+0x20,*(char * *)&((struct Obj00100 *)p)->f8); }
     else if(((struct Obj00100 *)p)->f30==1) { ((struct Obj00100 *)p)->f10=done; *(char * *)&((struct Obj00100 *)p)->f1C=func_021BB2B4(p+0x14,*(char * *)&((struct Obj00100 *)p)->f8); }
    } else {
     ((struct Obj00100 *)p)->f10=3;
     id=((struct Obj00100 *)p)->f40;
     count=func_021B9BEC(*(char * *)&((struct Obj26118 *)(*(char * *)&((struct Obj00100 *)p)->f8))->f2C,id);
     selected=func_021B9BE0(*(char * *)&((struct Obj26119 *)(*(char * *)&((struct Obj00100 *)p)->f8))->f2C,id);
     if(!func_021B9C98(*(char * *)&((struct Obj26120 *)(*(char * *)&((struct Obj00100 *)p)->f8))->f2C,selected,**(int * *)&((struct Obj00100 *)p)->f8))
      func_021B9CB0(*(char * *)&((struct Obj26122 *)(*(char * *)&((struct Obj00100 *)p)->f8))->f2C,selected,(struct Big *)(**(int * *)&((struct Obj00100 *)p)->f8));
     ((struct Obj00100 *)p)->f4A=func_021B9BC8(*(char * *)&((struct Obj26124 *)(*(char * *)&((struct Obj00100 *)p)->f8))->f2C,id);
     ((struct Obj00100 *)p)->f48=func_021B9BEC(*(char * *)&((struct Obj26125 *)(*(char * *)&((struct Obj00100 *)p)->f8))->f2C,id);
     for(i=0;i<count;i++) {
      item=func_021B9C0C(*(char * *)&((struct Obj26126 *)(*(char * *)&((struct Obj00100 *)p)->f8))->f2C,id,i);
      if(!func_021B9CC8((unsigned int)(*(char * *)&((struct Obj26127 *)(*(char * *)&((struct Obj00100 *)p)->f8))->f2C),item)) item=65535;
      *(u16 *)(p+i*4+0x4c)=item;
      *(u16 *)(p+i*4+0x4e)=func_021B9BF8(*(char * *)&((struct Obj26128 *)(*(char * *)&((struct Obj00100 *)p)->f8))->f2C,id,i);
     }
     *(char * *)&((struct Obj00100 *)p)->f74=func_021BBA74(p+0x48,*(char * *)&((struct Obj00100 *)p)->f8);
    }
   }
   break;
  case 3:
   if(func_021BBB0C(*(char * *)&((struct Obj00100 *)p)->f74)) {
    func_021BBAE8(((struct Obj00100 *)p)->f74);
    if(((struct Obj00100 *)p)->f70==0) {
     ((struct Obj00100 *)p)->f10=2;
     *(char * *)&((struct Obj00100 *)p)->f44=(char *)func_021BB854((struct Owner *)(p+0x30),(struct Data *)(*(char * *)&((struct Obj00100 *)p)->f8));
    }
   }
   break;
  }
  if(done) { *state=3; FADE_Start(3,0,16,0); }
  break;
 case 3: if(!FADE_IsActive()) *state=4; break;
 case 4: return 1;
 }
 func_021B9E60(*(char * *)&((struct Obj00100 *)p)->f8);
 return 0;
}

void func_021B98FC(void *unused, char *work)
{
}


static inline void G2_BlendNone(void) { *(volatile u16 *)0x04000050 = 0; }

static inline void G2S_BlendNone(void) { *(volatile u16 *)0x04001050 = 0; }

static inline void GX_SetVisibleWnd(int window) {
    *(volatile u32 *)0x04000000 = (u32)((*(volatile u32 *)0x04000000 & ~0xE000) | (window << 13));
}

static inline void GXS_SetVisibleWnd(int window) {
    *(volatile u32 *)0x04001000 = (u32)((*(volatile u32 *)0x04001000 & ~0xE000) | (window << 13));
}

void *func_021B9900(u32 swap, u32 heap)
{
    char *p = func_02030734(heap, 16, 0, file, 454);
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
    func_021B9A28(p, heap);
    func_021B9ACC((unsigned char *)p + 4, (int)vram, heap);
    ((struct Obj26129 *)p)->fC = func_020056A0(func_021B9A14, p, 0);
    return p;
}

void func_021B99A0(char *p)
{
    func_02030EAC(((struct Obj26130 *)p)->fC);
    func_021B9B0C(p + 4);
    func_021B9A88(p);
    func_0201DD68();
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    MI_CpuFill8(p, 0, 16);
    func_020307B0(p);
}


void func_021B99F4(char *p)
{
    func_021B9B28(p + 4);
    func_021B9AC0(p);
}

u32 func_021B9A08(const u8 *p) { return func_021B9B38((const u32 *)(p+4)); }


void func_021B9A14(void *unused, char *p)
{
    func_021B9AC4(p);
    func_021B9B30(p + 4);
}

void func_021B9A28(void *p, u32 heap)
{
    u32 i = 0;
    MI_CpuFill8(p, 0, 4);
    func_0203F8F4(heap);
    BMP_WIN_Init(heap);
    func_0203FC28((struct DispConfig *)config);
    for (; i < 4; i++) {
        struct Record *r = &table[i];
        u32 id = r->id;
        func_0203FCA0((u8)id, (const struct BgTemplate *)r->bg, (u8)r->kind);
        func_020414AC(id);
        func_02040588(id, r->visible);
    }
}

void func_021B9A88(void *p) {
    u32 i;
    for (i=0; i<4; i++) func_020403F4((u8)(*(const u32 *)(d_021BBE4C+i*44)));
    BMP_WIN_Exit();
    func_0203F9B4();
    MI_CpuFill8(p,0,4);
}

void func_021B9AC0(void *a0) {}

void func_021B9AC4(void *a0) { func_020419E4(); }


void func_021B9ACC(unsigned char *p, int a, int b)
{
    MI_CpuFill8(p, 0, 4);
    CLACT_InitSystem((const struct Cfg *)0x021BBE00, a, b);
    ((struct Obj14801 *)p)->f0 = (int)CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer((void *)((struct Obj14801 *)p)->f0);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}


void func_021B9B0C(char *p)
{
    CLACT_DeleteUnit((struct Bank *)(((struct Obj26131 *)p)->f0));
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 4);
}

void func_021B9B28(void *a0) {CLACT_DrawSystem();}

void func_021B9B30(void *a0) {CLACT_VBlankSystem();}

u32 func_021B9B38(const u32 *p) {return *p;}
