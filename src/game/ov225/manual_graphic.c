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
 *   BG_SYS_SetPriority 0x0204047C arm
 *   FADE_Start 0x0204E720 arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   MANUAL_COMMON_CreateData 0x021B9D18 thumb ov225
 *   MANUAL_COMMON_CreateDialog 0x021BB2B4 thumb ov225
 *   MANUAL_COMMON_DeleteDialog 0x021BB308 thumb ov225
 *   MANUAL_CATEGORY_DeleteList 0x021BB7F4 thumb ov225
 *   MANUAL_CATEGORY_DeleteDetailList 0x021BBA14 thumb ov225
 *   MANUAL_CATEGORY_DeleteOption 0x021BBAE8 thumb ov225
 *   MANUAL_COMMON_DeleteData 0x021B9DEC thumb ov225
 *   TCB_DeleteTask 0x02030EAC arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   FADE_IsActive 0x0204E804 arm
 *   MANUAL_COMMON_UpdateDialog 0x021BB31C thumb ov225
 *   MANUAL_CATEGORY_CreateList 0x021BB6E0 thumb ov225
 *   MANUAL_CATEGORY_IsListFinished 0x021BB844 thumb ov225
 *   MANUAL_CATEGORY_IsDetailFinished 0x021BBA64 thumb ov225
 *   MANUAL_COMMON_GetEntryValue3 0x021B9BEC thumb ov225
 *   MANUAL_COMMON_GetEntryValue2 0x021B9BE0 thumb ov225
 *   MANUAL_COMMON_GetSaveValue 0x021B9C98 thumb ov225
 *   MANUAL_COMMON_SetSaveValue 0x021B9CB0 thumb ov225
 *   MANUAL_COMMON_GetEntryValue0 0x021B9BC8 thumb ov225
 *   MANUAL_COMMON_GetEntryPair1 0x021B9C0C thumb ov225
 *   MANUAL_COMMON_IsValidKey 0x021B9CC8 thumb ov225
 *   MANUAL_COMMON_GetEntryPair0 0x021B9BF8 thumb ov225
 *   MANUAL_CATEGORY_CreateOption 0x021BBA74 thumb ov225
 *   MANUAL_CATEGORY_UpdateOption 0x021BBB0C thumb ov225
 *   MANUAL_CATEGORY_CreateDetailList 0x021BB854 thumb ov225
 *   MANUAL_COMMON_DrawData 0x021B9E60 thumb ov225
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   file 0x021BBFE0 data ov225 a1
 *   vram 0x021BBE1C data ov225
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
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
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm  arm9
 */

struct Proc;
struct Node;
struct Proc;
struct Big;
struct Data;
struct Owner;
struct ManualMenuList;
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
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,u32,u32);
extern void *MANUAL_COMMON_CreateData(void *,u16);
extern void BG_SYS_SetPriority(int,u16);
struct Tcb;
extern struct Tcb *GFL_USE_AddMainTask(void (*)(void *,char *),void *,u32);
extern void FADE_Start(u32,int,int,int);
extern void GFL_NET_RefreshWmIconAtTopRight(u32,u32);
extern char *MANUAL_COMMON_CreateDialog(char *,char *);
extern void MANUAL_COMMON_DeleteDialog(char *p);
extern void MANUAL_CATEGORY_DeleteList(char *p);
extern void MANUAL_CATEGORY_DeleteDetailList(char *p);
extern void MANUAL_CATEGORY_DeleteOption(char *p);
extern void MANUAL_COMMON_DeleteData(char *p);
struct TcbTask;
extern void TCB_DeleteTask(struct TcbTask *task);
extern void PROCSYS_FreeProcWork(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern int FADE_IsActive(void);
extern int MANUAL_COMMON_UpdateDialog(char *);
extern char *MANUAL_CATEGORY_CreateList(char *,char *);
extern int MANUAL_CATEGORY_IsListFinished(char *);
extern int MANUAL_CATEGORY_IsDetailFinished(char *);
extern u16 MANUAL_COMMON_GetEntryValue3(char *,int);
extern u16 MANUAL_COMMON_GetEntryValue2(char *,int);
extern int MANUAL_COMMON_GetSaveValue(void *unused, int id, void *save);
extern void MANUAL_COMMON_SetSaveValue(void *unused, int code, struct Big *save);
extern u16 MANUAL_COMMON_GetEntryValue0(char *,int);
extern u16 MANUAL_COMMON_GetEntryPair1(char *,int,int);
extern int MANUAL_COMMON_IsValidKey(char *unused, u32 key);
extern u16 MANUAL_COMMON_GetEntryPair0(char *,int,int);
extern char *MANUAL_CATEGORY_CreateOption(char *,char *);
extern int MANUAL_CATEGORY_UpdateOption(char *);
struct ManualDetailOwner;
extern struct ManualMenuList *MANUAL_CATEGORY_CreateDetailList(struct ManualDetailOwner *p, struct ManualData *data);
extern void MANUAL_COMMON_DrawData(char *);
extern void *GFL_HEAP_Alloc(u32, u32, int, const char *, u16);
extern void BG_SYS_ClearGraphicsMemory(u32);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetLcdSwap(u32);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern u32 GFL_HEAP_Free(void *p);
extern void GF_FONT_SetDefaultTextColor(void);
extern void BG_SYS_Create(u32);
extern void BMP_WIN_Init(u32);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void BG_SYS_SetPlaneVisible(u8, u8);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void BG_SYS_Update(void);
struct DispVramCfg;
struct SysInit;
extern void CLACT_InitSystem(struct SysInit *cfg, struct DispVramCfg *res_cfg, u32 heapId);
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
void MANUAL_GRAPHIC_DrawBg(void *unused);
void MANUAL_GRAPHIC_VBlankBg(void *unused);
void MANUAL_GRAPHIC_CreateClactUnit(unsigned char *p, int a, int b);
void MANUAL_GRAPHIC_DeleteClactUnit(char *p);
void MANUAL_GRAPHIC_DrawClactUnit(void *unused);
void MANUAL_GRAPHIC_VBlankClactUnit(void *unused);
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
    work->data = MANUAL_COMMON_CreateData(work->args->data,work->heap);
    BG_SYS_SetPriority(4,3);
    BG_SYS_SetPriority(5,2);
    BG_SYS_SetPriority(6,1);
    BG_SYS_SetPriority(7,0);
    work->task = GFL_USE_AddMainTask(MANUAL_GRAPHIC_TaskNoop,work,1);
    FADE_Start(3,16,0,0);
    GFL_NET_RefreshWmIconAtTopRight(0,work->heap);
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
    work->menu = MANUAL_COMMON_CreateDialog((char *)work->listBuf,work->data);
    return 1;
}

int MANUAL_GRAPHIC_Exit(void *proc, void *unusedA, void *unusedB, char *work)
{
    switch (((struct ManualWork *)work)->state) {
    case 0: MANUAL_COMMON_DeleteDialog(((struct ManualWork *)work)->menu); break;
    case 1: MANUAL_CATEGORY_DeleteList(((struct ManualWork *)work)->list); break;
    case 2: MANUAL_CATEGORY_DeleteDetailList(((struct ManualWork *)work)->detailList); break;
    case 3: MANUAL_CATEGORY_DeleteOption(((struct ManualWork *)work)->optionList); break;
    }
    TCB_DeleteTask(((struct ManualWork *)work)->task);
    MANUAL_COMMON_DeleteData(((struct ManualWork *)work)->data);
    PROCSYS_FreeProcWork(proc);
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
   if(!MANUAL_COMMON_UpdateDialog(*(char * *)&((struct ManualWork *)work)->menu)) goto innerDone;
   {
    if(((struct ManualWork *)work)->choice<=1) {
     if(((struct ManualWork *)work)->choice==0) ((struct Args *)(*(char * *)&((struct ManualWork *)work)->args))->flag=0;
     else if(((struct ManualWork *)work)->choice==1) ((struct Args *)(*(char * *)&((struct ManualWork *)work)->args))->flag=1;
     done=1;
    } else {
     MANUAL_COMMON_DeleteDialog(*(char * *)&((struct ManualWork *)work)->menu);
     if(((struct ManualWork *)work)->choice==2) {
      ((struct ManualWork *)work)->state=1;
      ((struct ManualWork *)work)->listOriginX=0; ((struct ManualWork *)work)->listOriginY=0;
      *(char * *)&((struct ManualWork *)work)->list=MANUAL_CATEGORY_CreateList(work+0x20,*(char * *)&((struct ManualWork *)work)->data);
     } else if(((struct ManualWork *)work)->choice==3) {
      ((struct ManualWork *)work)->state=2; ((struct ManualWork *)work)->ownerState=1;
      ((struct ManualWork *)work)->detailId=done;
      ((struct ManualWork *)work)->detailCount=done; ((struct ManualWork *)work)->detailSelected=done;
      *(char * *)&((struct ManualWork *)work)->detailList=(char *)MANUAL_CATEGORY_CreateDetailList((struct ManualDetailOwner *)(work+0x30),(struct ManualData *)(*(char * *)&((struct ManualWork *)work)->data));
     }
    }
   }
   break;
  case 1:
   if(!MANUAL_CATEGORY_IsListFinished(*(char * *)&((struct ManualWork *)work)->list)) {
   default:
innerDone:
    break;
   } else {
    MANUAL_CATEGORY_DeleteList(*(char * *)&((struct ManualWork *)work)->list);
    if(((struct ManualWork *)work)->hasDetail==0) {
     ((struct ManualWork *)work)->state=done;
     *(char * *)&((struct ManualWork *)work)->menu=MANUAL_COMMON_CreateDialog(work+0x14,*(char * *)&((struct ManualWork *)work)->data);
    } else {
     ((struct ManualWork *)work)->state=2; ((struct ManualWork *)work)->ownerState=0;
     ((struct ManualWork *)work)->detailId=((struct ManualWork *)work)->detailEntry;
     ((struct ManualWork *)work)->detailCount=done; ((struct ManualWork *)work)->detailSelected=done;
     *(char * *)&((struct ManualWork *)work)->detailList=(char *)MANUAL_CATEGORY_CreateDetailList((struct ManualDetailOwner *)(work+0x30),(struct ManualData *)(*(char * *)&((struct ManualWork *)work)->data));
    }
   }
   break;
  case 2:
   if(MANUAL_CATEGORY_IsDetailFinished(*(char * *)&((struct ManualWork *)work)->detailList)) {
    MANUAL_CATEGORY_DeleteDetailList(*(char * *)&((struct ManualWork *)work)->detailList);
    if(((struct ManualWork *)work)->subFlag==0) {
     if(((struct ManualWork *)work)->ownerState==0) { ((struct ManualWork *)work)->state=1; *(char * *)&((struct ManualWork *)work)->list=MANUAL_CATEGORY_CreateList(work+0x20,*(char * *)&((struct ManualWork *)work)->data); }
     else if(((struct ManualWork *)work)->ownerState==1) { ((struct ManualWork *)work)->state=done; *(char * *)&((struct ManualWork *)work)->menu=MANUAL_COMMON_CreateDialog(work+0x14,*(char * *)&((struct ManualWork *)work)->data); }
    } else {
     ((struct ManualWork *)work)->state=3;
     id=((struct ManualWork *)work)->entryId;
     count=MANUAL_COMMON_GetEntryValue3(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualWork *)work)->data))->list,id);
     selected=MANUAL_COMMON_GetEntryValue2(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualWork *)work)->data))->list,id);
     if(!MANUAL_COMMON_GetSaveValue((void *)(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualWork *)work)->data))->list),selected,(void *)(**(int * *)&((struct ManualWork *)work)->data)))
      MANUAL_COMMON_SetSaveValue(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualWork *)work)->data))->list,selected,(struct Big *)(**(int * *)&((struct ManualWork *)work)->data));
     ((struct ManualWork *)work)->selectedId=MANUAL_COMMON_GetEntryValue0(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualWork *)work)->data))->list,id);
     ((struct ManualWork *)work)->entryCount=MANUAL_COMMON_GetEntryValue3(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualWork *)work)->data))->list,id);
     for(entryIndex=0;entryIndex<count;entryIndex++) {
      item=MANUAL_COMMON_GetEntryPair1(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualWork *)work)->data))->list,id,entryIndex);
      if(!MANUAL_COMMON_IsValidKey((*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualWork *)work)->data))->list),item)) item=65535;
      ((struct ManualWork *)work)->entries[entryIndex].item=item;
      ((struct ManualWork *)work)->entries[entryIndex].count=MANUAL_COMMON_GetEntryPair0(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualWork *)work)->data))->list,id,entryIndex);
     }
     *(char * *)&((struct ManualWork *)work)->optionList=MANUAL_CATEGORY_CreateOption(work+0x48,*(char * *)&((struct ManualWork *)work)->data);
    }
   }
   break;
  case 3:
   if(MANUAL_CATEGORY_UpdateOption(*(char * *)&((struct ManualWork *)work)->optionList)) {
    MANUAL_CATEGORY_DeleteOption(((struct ManualWork *)work)->optionList);
    if(((struct ManualWork *)work)->closeFlag==0) {
     ((struct ManualWork *)work)->state=2;
     *(char * *)&((struct ManualWork *)work)->detailList=(char *)MANUAL_CATEGORY_CreateDetailList((struct ManualDetailOwner *)(work+0x30),(struct ManualData *)(*(char * *)&((struct ManualWork *)work)->data));
    }
   }
   break;
  }
  if(done) { *state=3; FADE_Start(3,0,16,0); }
  break;
 case 3: if(!FADE_IsActive()) *state=4; break;
 case 4: return 1;
 }
 MANUAL_COMMON_DrawData(*(char * *)&((struct ManualWork *)work)->data);
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
    char *screen = GFL_HEAP_Alloc(heap, 16, 0, file, 454);
    MI_CpuFill8(screen, 0, 16);
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)vram);
    BG_SYS_SetLcdSwap(swap);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    MANUAL_GRAPHIC_CreateBg(screen, heap);
    MANUAL_GRAPHIC_CreateClactUnit((unsigned char *)screen + 4, (int)vram, heap);
    ((struct ManualScreen *)screen)->task = GFL_USE_AddMainTask(MANUAL_GRAPHIC_VBlankScreen, screen, 0);
    return screen;
}

void MANUAL_GRAPHIC_DeleteScreen(char *screen)
{
    TCB_DeleteTask(((struct ManualScreen *)screen)->task);
    MANUAL_GRAPHIC_DeleteClactUnit(screen + 4);
    MANUAL_GRAPHIC_DeleteBg(screen);
    GF_FONT_SetDefaultTextColor();
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    MI_CpuFill8(screen, 0, 16);
    GFL_HEAP_Free(screen);
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
        BG_SYS_SetPlaneVisible(id, row->visible);
    }
}

void MANUAL_GRAPHIC_DeleteBg(void *screen) {
    u32 index;
    for (index=0; index<4; index++) BG_SYS_FreeLayerBuf((u8)(*(const u32 *)((const u8 *)gManualGraphicMainBgLayerTable+index*44)));
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(screen,0,4);
}

void MANUAL_GRAPHIC_DrawBg(void *unused) {}

void MANUAL_GRAPHIC_VBlankBg(void *unused) { BG_SYS_Update(); }


void MANUAL_GRAPHIC_CreateClactUnit(unsigned char *clact, int arg, int heap)
{
    MI_CpuFill8(clact, 0, 4);
    CLACT_InitSystem((struct SysInit *)0x021BBE00, (struct DispVramCfg *)arg, heap);
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
