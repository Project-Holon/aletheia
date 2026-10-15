/*
 * file:     manual_graphic.c
 * unit:     yes
 * function: MANUAL_GRAPHIC_Init, MANUAL_GRAPHIC_Exit, MANUAL_GRAPHIC_Main, MANUAL_GRAPHIC_TaskNoop, MANUAL_GRAPHIC_CreateScreen, MANUAL_GRAPHIC_DeleteScreen, MANUAL_GRAPHIC_DrawScreen, MANUAL_GRAPHIC_GetClactUnit, MANUAL_GRAPHIC_VBlankScreen, MANUAL_GRAPHIC_CreateBg, MANUAL_GRAPHIC_DeleteBg, MANUAL_GRAPHIC_DrawBg, MANUAL_GRAPHIC_VBlankBg, MANUAL_GRAPHIC_CreateClactUnit, MANUAL_GRAPHIC_DeleteClactUnit, MANUAL_GRAPHIC_DrawClactUnit, MANUAL_GRAPHIC_VBlankClactUnit, MANUAL_GRAPHIC_GetUnitHandle
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
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
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
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
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
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   file 0x021BBFE0 data ov225 a1
 *   vram 0x021BBE1C data ov225
 *   func_020307B0 0x020307B0 arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   config 0x021BBDF0 data ov225
 *   gManualGraphicMainBgLayerTable 0x021BBE4C data ov225
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
 *   BG_SYS_Delete  0x0203F9B4  arm  arm9
 *   BG_SYS_Update  0x020419E4  arm  arm9
 */

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

struct ManualWork {
    u16 heap; u16 pad2;
    struct Args *args;
    void *data;
    void *task;
    u32 state;
    u8 listBuf[4];
    u32 choice;
    void *menu;
    u16 listOriginX; u16 listOriginY;
    u32 hasDetail;
    u16 detailEntry; u16 pad2A;
    void *list;
    u32 ownerState;
    u16 detailId; u16 detailCount; u16 detailSelected; u16 pad3A;
    u32 subFlag;
    u16 entryId; u16 pad42;
    void *detailList;
    u8 entryCount; u8 pad49;
    u16 selectedId;
    struct { u16 item; u16 count; } entries[9];
    u32 closeFlag;
    void *optionList;
};

struct ManualData { u8 pad0[0x2C]; void *list; };

struct ManualClactUnit { int unit; };

struct ManualScreen { u32 bgState; struct ManualClactUnit clactUnit; u32 reserved08; void *task; };

struct Record { u32 id; u32 bg[8]; u32 kind; u32 visible; };

extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,u32,u32);
extern void *func_021B9D18(void *,u16);
extern void BG_SYS_SetVisibleLayer(int,u16);
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
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
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
extern void BMP_SetDisplaySwap(u32);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern u32 func_020307B0(void *p);
extern void GF_FONT_SetDefaultTextColor(void);
extern void BG_SYS_Create(u32);
extern void BMP_WIN_Init(u32);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void func_02040588(u8, u8);
extern void func_020403F4(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void BG_SYS_Update(void);
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, unsigned int heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
int MANUAL_GRAPHIC_Init(void *proc, void *unused, struct Args *args);
int MANUAL_GRAPHIC_Exit(void *proc, void *a, void *b, char *work);
int MANUAL_GRAPHIC_Main(void *a,u32 *state,void *unused,char *p);
void MANUAL_GRAPHIC_TaskNoop(void *unused, char *work);
void *MANUAL_GRAPHIC_CreateScreen(u32 swap, u32 heap);
void MANUAL_GRAPHIC_DeleteScreen(char *p);
void MANUAL_GRAPHIC_DrawScreen(char *p);
u32 MANUAL_GRAPHIC_GetClactUnit(const u8 *p);
void MANUAL_GRAPHIC_VBlankScreen(void *unused, char *p);
void MANUAL_GRAPHIC_CreateBg(void *p, u32 heap);
void MANUAL_GRAPHIC_DeleteBg(void *p);
void MANUAL_GRAPHIC_DrawBg(void *a0);
void MANUAL_GRAPHIC_VBlankBg(void *a0);
void MANUAL_GRAPHIC_CreateClactUnit(unsigned char *p, int a, int b);
void MANUAL_GRAPHIC_DeleteClactUnit(char *p);
void MANUAL_GRAPHIC_DrawClactUnit(void *a0);
void MANUAL_GRAPHIC_VBlankClactUnit(void *a0);
u32 MANUAL_GRAPHIC_GetUnitHandle(const u32 *p);
extern char file[], vram[];
extern u32 config[];
extern struct Record gManualGraphicMainBgLayerTable[];

int MANUAL_GRAPHIC_Init(void *proc, void *unused, struct Args *args)
{
    struct ManualWork *work;
    GFL_HEAP_CreateChildHeap(1,0x90,0x50000);
    work = PROCSYS_AllocProcWork(proc,0x78,0x90);
    MI_CpuFill8(work,0,0x78);
    work->heap = 0x90;
    work->args = args;
    args->flag = 1;
    work->data = func_021B9D18(work->args->data,work->heap);
    BG_SYS_SetVisibleLayer(4,3);
    BG_SYS_SetVisibleLayer(5,2);
    BG_SYS_SetVisibleLayer(6,1);
    BG_SYS_SetVisibleLayer(7,0);
    work->task = func_020056A0(MANUAL_GRAPHIC_TaskNoop,work,1);
    FADE_Start(3,16,0,0);
    GFL_NET_RestartWithDefaultTimeout(0,work->heap);
    work->listBuf[0] = 0;
    work->listOriginX = 0;
    work->listOriginY = 0;
    work->ownerState = 0;
    work->detailId = 0;
    work->detailCount = 0;
    work->detailSelected = 0;
    work->entryCount = 1;
    work->selectedId = 0;
    work->entries[0].item = 0xffff;
    work->entries[0].count = 0;
    work->state = 0;
    work->menu = func_021BB2B4((char *)work->listBuf,work->data);
    return 1;
}

int MANUAL_GRAPHIC_Exit(void *proc, void *unusedA, void *unusedB, char *work)
{
    switch (((struct ManualWork *)work)->state) {
    case 0: func_021BB308(((struct ManualWork *)work)->menu); break;
    case 1: func_021BB7F4(((struct ManualWork *)work)->list); break;
    case 2: func_021BBA14(((struct ManualWork *)work)->detailList); break;
    case 3: func_021BBAE8(((struct ManualWork *)work)->optionList); break;
    }
    func_02030EAC(((struct ManualWork *)work)->task);
    func_021B9DEC(((struct ManualWork *)work)->data);
    func_020315D4(proc);
    GFL_HEAP_DeleteChecked(0x90);
    return 1;
}

int MANUAL_GRAPHIC_Main(void *unusedA,u32 *state,void *unused,char *work)
{
 int done;
 u32 count;
 u16 id,entryIndex,item,selected;
 switch(*state) {
 case 0: *state=1; break;
 case 1: if(!FADE_IsActive()) *state=2; break;
 case 2:
  done=0;
  switch(((struct ManualWork *)work)->state) {
  case 0:
   if(!func_021BB31C(*(char * *)&((struct ManualWork *)work)->menu)) goto innerDone;
   {
    if(((struct ManualWork *)work)->choice<=1) {
     if(((struct ManualWork *)work)->choice==0) ((struct Args *)(*(char * *)&((struct ManualWork *)work)->args))->flag=0;
     else if(((struct ManualWork *)work)->choice==1) ((struct Args *)(*(char * *)&((struct ManualWork *)work)->args))->flag=1;
     done=1;
    } else {
     func_021BB308(*(char * *)&((struct ManualWork *)work)->menu);
     if(((struct ManualWork *)work)->choice==2) {
      ((struct ManualWork *)work)->state=1;
      ((struct ManualWork *)work)->listOriginX=0; ((struct ManualWork *)work)->listOriginY=0;
      *(char * *)&((struct ManualWork *)work)->list=func_021BB6E0(work+0x20,*(char * *)&((struct ManualWork *)work)->data);
     } else if(((struct ManualWork *)work)->choice==3) {
      ((struct ManualWork *)work)->state=2; ((struct ManualWork *)work)->ownerState=1;
      ((struct ManualWork *)work)->detailId=done;
      ((struct ManualWork *)work)->detailCount=done; ((struct ManualWork *)work)->detailSelected=done;
      *(char * *)&((struct ManualWork *)work)->detailList=(char *)func_021BB854((struct Owner *)(work+0x30),(struct Data *)(*(char * *)&((struct ManualWork *)work)->data));
     }
    }
   }
   break;
  case 1:
   if(!func_021BB844(*(char * *)&((struct ManualWork *)work)->list)) {
   default:
innerDone:
    break;
   } else {
    func_021BB7F4(*(char * *)&((struct ManualWork *)work)->list);
    if(((struct ManualWork *)work)->hasDetail==0) {
     ((struct ManualWork *)work)->state=done;
     *(char * *)&((struct ManualWork *)work)->menu=func_021BB2B4(work+0x14,*(char * *)&((struct ManualWork *)work)->data);
    } else {
     ((struct ManualWork *)work)->state=2; ((struct ManualWork *)work)->ownerState=0;
     ((struct ManualWork *)work)->detailId=((struct ManualWork *)work)->detailEntry;
     ((struct ManualWork *)work)->detailCount=done; ((struct ManualWork *)work)->detailSelected=done;
     *(char * *)&((struct ManualWork *)work)->detailList=(char *)func_021BB854((struct Owner *)(work+0x30),(struct Data *)(*(char * *)&((struct ManualWork *)work)->data));
    }
   }
   break;
  case 2:
   if(func_021BBA64(*(char * *)&((struct ManualWork *)work)->detailList)) {
    func_021BBA14(*(char * *)&((struct ManualWork *)work)->detailList);
    if(((struct ManualWork *)work)->subFlag==0) {
     if(((struct ManualWork *)work)->ownerState==0) { ((struct ManualWork *)work)->state=1; *(char * *)&((struct ManualWork *)work)->list=func_021BB6E0(work+0x20,*(char * *)&((struct ManualWork *)work)->data); }
     else if(((struct ManualWork *)work)->ownerState==1) { ((struct ManualWork *)work)->state=done; *(char * *)&((struct ManualWork *)work)->menu=func_021BB2B4(work+0x14,*(char * *)&((struct ManualWork *)work)->data); }
    } else {
     ((struct ManualWork *)work)->state=3;
     id=((struct ManualWork *)work)->entryId;
     count=func_021B9BEC(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualWork *)work)->data))->list,id);
     selected=func_021B9BE0(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualWork *)work)->data))->list,id);
     if(!func_021B9C98(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualWork *)work)->data))->list,selected,**(int * *)&((struct ManualWork *)work)->data))
      func_021B9CB0(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualWork *)work)->data))->list,selected,(struct Big *)(**(int * *)&((struct ManualWork *)work)->data));
     ((struct ManualWork *)work)->selectedId=func_021B9BC8(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualWork *)work)->data))->list,id);
     ((struct ManualWork *)work)->entryCount=func_021B9BEC(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualWork *)work)->data))->list,id);
     for(entryIndex=0;entryIndex<count;entryIndex++) {
      item=func_021B9C0C(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualWork *)work)->data))->list,id,entryIndex);
      if(!func_021B9CC8((unsigned int)(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualWork *)work)->data))->list),item)) item=65535;
      ((struct ManualWork *)work)->entries[entryIndex].item=item;
      ((struct ManualWork *)work)->entries[entryIndex].count=func_021B9BF8(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualWork *)work)->data))->list,id,entryIndex);
     }
     *(char * *)&((struct ManualWork *)work)->optionList=func_021BBA74(work+0x48,*(char * *)&((struct ManualWork *)work)->data);
    }
   }
   break;
  case 3:
   if(func_021BBB0C(*(char * *)&((struct ManualWork *)work)->optionList)) {
    func_021BBAE8(((struct ManualWork *)work)->optionList);
    if(((struct ManualWork *)work)->closeFlag==0) {
     ((struct ManualWork *)work)->state=2;
     *(char * *)&((struct ManualWork *)work)->detailList=(char *)func_021BB854((struct Owner *)(work+0x30),(struct Data *)(*(char * *)&((struct ManualWork *)work)->data));
    }
   }
   break;
  }
  if(done) { *state=3; FADE_Start(3,0,16,0); }
  break;
 case 3: if(!FADE_IsActive()) *state=4; break;
 case 4: return 1;
 }
 func_021B9E60(*(char * *)&((struct ManualWork *)work)->data);
 return 0;
}

void MANUAL_GRAPHIC_TaskNoop(void *unused, char *work)
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

void *MANUAL_GRAPHIC_CreateScreen(u32 swap, u32 heap)
{
    char *screen = func_02030734(heap, 16, 0, file, 454);
    MI_CpuFill8(screen, 0, 16);
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)vram);
    BMP_SetDisplaySwap(swap);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    MANUAL_GRAPHIC_CreateBg(screen, heap);
    MANUAL_GRAPHIC_CreateClactUnit((unsigned char *)screen + 4, (int)vram, heap);
    ((struct ManualScreen *)screen)->task = func_020056A0(MANUAL_GRAPHIC_VBlankScreen, screen, 0);
    return screen;
}

void MANUAL_GRAPHIC_DeleteScreen(char *screen)
{
    func_02030EAC(((struct ManualScreen *)screen)->task);
    MANUAL_GRAPHIC_DeleteClactUnit(screen + 4);
    MANUAL_GRAPHIC_DeleteBg(screen);
    GF_FONT_SetDefaultTextColor();
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    MI_CpuFill8(screen, 0, 16);
    func_020307B0(screen);
}


void MANUAL_GRAPHIC_DrawScreen(char *screen)
{
    MANUAL_GRAPHIC_DrawClactUnit(screen + 4);
    MANUAL_GRAPHIC_DrawBg(screen);
}

u32 MANUAL_GRAPHIC_GetClactUnit(const u8 *screen) { return MANUAL_GRAPHIC_GetUnitHandle((const u32 *)(screen+4)); }


void MANUAL_GRAPHIC_VBlankScreen(void *unused, char *screen)
{
    MANUAL_GRAPHIC_VBlankBg(screen);
    MANUAL_GRAPHIC_VBlankClactUnit(screen + 4);
}

void MANUAL_GRAPHIC_CreateBg(void *screen, u32 heap)
{
    u32 index = 0;
    MI_CpuFill8(screen, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)config);
    for (; index < 4; index++) {
        struct Record *row = &gManualGraphicMainBgLayerTable[index];
        u32 id = row->id;
        BG_SYS_InitBgLayer((u8)id, (const struct BgTemplate *)row->bg, (u8)row->kind);
        BG_SYS_FreeSlot(id);
        func_02040588(id, row->visible);
    }
}

void MANUAL_GRAPHIC_DeleteBg(void *screen) {
    u32 index;
    for (index=0; index<4; index++) func_020403F4((u8)(*(const u32 *)((const u8 *)gManualGraphicMainBgLayerTable+index*44)));
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(screen,0,4);
}

void MANUAL_GRAPHIC_DrawBg(void *unused) {}

void MANUAL_GRAPHIC_VBlankBg(void *unused) { BG_SYS_Update(); }


void MANUAL_GRAPHIC_CreateClactUnit(unsigned char *clact, int arg, int heap)
{
    MI_CpuFill8(clact, 0, 4);
    CLACT_InitSystem((const struct Cfg *)0x021BBE00, arg, heap);
    ((struct ManualClactUnit *)clact)->unit = (int)CLACT_CreateUnit(0x80, 0, heap);
    CLACT_SetUnitDefaultRenderer((void *)((struct ManualClactUnit *)clact)->unit);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}


void MANUAL_GRAPHIC_DeleteClactUnit(char *clact)
{
    CLACT_DeleteUnit((struct Bank *)(((struct ManualClactUnit *)clact)->unit));
    CLACT_ExitSystem();
    MI_CpuFill8(clact, 0, 4);
}

void MANUAL_GRAPHIC_DrawClactUnit(void *unused) {CLACT_DrawSystem();}

void MANUAL_GRAPHIC_VBlankClactUnit(void *unused) {CLACT_VBlankSystem();}

u32 MANUAL_GRAPHIC_GetUnitHandle(const u32 *handle) {return *handle;}
