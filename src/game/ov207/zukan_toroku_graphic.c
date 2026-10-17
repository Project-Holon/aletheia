/*
 * file:     zukan_toroku_graphic.c
 * unit:     yes
 * function: ZUKAN_TOROKU_GRAPHIC_Init, ZUKAN_TOROKU_GRAPHIC_Exit, ZUKAN_TOROKU_GRAPHIC_Main, ZUKAN_TOROKU_GRAPHIC_CreateBg, ZUKAN_TOROKU_GRAPHIC_DeleteBg, ZUKAN_TOROKU_GRAPHIC_ClearTask, ZUKAN_TOROKU_GRAPHIC_CreateDisplay, ZUKAN_TOROKU_GRAPHIC_DeleteDisplay, ZUKAN_TOROKU_GRAPHIC_Draw, ZUKAN_TOROKU_GRAPHIC_Update, ZUKAN_TOROKU_GRAPHIC_UpdateSub, ZUKAN_TOROKU_GRAPHIC_GetDisplay, ZUKAN_TOROKU_GRAPHIC_VBlank, ZUKAN_TOROKU_GRAPHIC_InitBg, ZUKAN_TOROKU_GRAPHIC_ExitBg, ZUKAN_TOROKU_GRAPHIC_UpdateBg, ZUKAN_TOROKU_GRAPHIC_ResetDisplay, ZUKAN_TOROKU_GRAPHIC_InitActors, ZUKAN_TOROKU_GRAPHIC_DeleteActors, ZUKAN_TOROKU_GRAPHIC_DrawActors, ZUKAN_TOROKU_GRAPHIC_VBlankActors
 * address:  0x0220AF40
 * region:   ov207
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   overlay67 0x00000043 data
 *   overlay206 0x000000CE data
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   ZUKAN_INFO_CreateFromMon 0x021B9DE0 thumb ov206
 *   ZUKAN_NICKNAME_Create 0x0220B55C thumb ov207
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   FADE_Start 0x0204E720 arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   ZUKAN_NICKNAME_Delete 0x0220B6E4 thumb ov207
 *   ZUKAN_INFO_Delete 0x021BA2CC thumb ov206
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   ZUKAN_INFO_Update 0x021BA374 thumb ov206
 *   ZUKAN_NICKNAME_Main 0x0220B72C thumb ov207
 *   FADE_IsActive 0x0204E804 arm
 *   ZUKAN_INFO_Start 0x021BA544 thumb ov206
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   KEY_GetTrg 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   ZUKAN_INFO_NotifyMoveDone 0x021BA514 thumb ov206
 *   ZUKAN_INFO_IsMoving 0x021BA524 thumb ov206
 *   ZUKAN_INFO_IsDone 0x021BA534 thumb ov206
 *   G2x_SetBlendBrightnessExt_ 0x0207D67C arm
 *   ZUKAN_INFO_ClearDisplay 0x021BA4CC thumb ov206
 *   ZUKAN_INFO_NotifyFadeDone 0x021BA51C thumb ov206
 *   ZUKAN_NICKNAME_SetupScreen 0x0220B908 thumb ov207
 *   ZUKAN_NICKNAME_GetResult 0x0220B940 thumb ov207
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_RegisterObjCharFromHandle 0x02049740 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   d_0220BC20 0x0220BC20 data a1
 *   d_0220BAE8 0x0220BAE8 data a4
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   d_0220BABC 0x0220BABC data a4
 *   d_0220BB18 0x0220BB18 data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   BG_SYS_Update 0x020419E4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 */
struct GfFont;
struct Proc;
struct Node;
struct PrintSys;
struct Proc;
struct DispVram;
struct Bank;
struct BgTemplate;
struct DispConfig;
struct Cfg;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

/* The zukan-toroku graphic proc work (0x34 bytes). */
typedef struct ZukanTorokuWork {
    u16 heapId;         /* 0x00 */
    u16 pad2;           /* 0x02 */
    void *display;      /* 0x04, display object */
    void *font;         /* 0x08, GF font */
    u32 printQueue;     /* 0x0C, PRINTSYS queue */
    int state;          /* 0x10, top-level state (0 or 1 from args[0]) */
    int step;           /* 0x14, substep within the state */
    int fadeLevel;      /* 0x18 */
    int counter;        /* 0x1C, 4-step counter for fadeLevel */
    void *menu;         /* 0x20, menu object */
    void *nickname;     /* 0x24, nickname entry object */
    void *task;         /* 0x28, clear-task callback */
    int bgActive;       /* 0x2C, nonzero while the bg is up */
    u32 bgHandle;       /* 0x30, packed bg half handle */
} ZukanTorokuWork;

/* The 16-byte display object made by ZUKAN_TOROKU_GRAPHIC_CreateDisplay. */
typedef struct ZukanTorokuDisplay {
    u32 reserved0;          /* 0x00, cleared only */
    struct Bank *actors;    /* 0x04, CLACT unit; also returned by GetDisplay */
    u32 reserved8;          /* 0x08, cleared only */
    void *vblankTask;       /* 0x0C, vblank callback task */
} ZukanTorokuDisplay;

/* Pooled overlay-id lever (see ZUKAN_TOROKU_GRAPHIC_Exit). */
typedef enum OverlayId { OVERLAY_ZERO=0 } OverlayId;

/* One bg layer row of d_0220BB18. */
typedef struct ZukanTorokuBgEntry {
    unsigned bgId;          /* 0x00 */
    char bgTemplate[32];    /* 0x04, BgTemplate image */
    unsigned type;          /* 0x24 */
    unsigned enable;        /* 0x28 */
} ZukanTorokuBgEntry;

typedef char ZukanTorokuWork_size_check[(sizeof(ZukanTorokuWork) == 0x34) ? 1 : -1];
typedef char ZukanTorokuDisplay_size_check[(sizeof(ZukanTorokuDisplay) == 0x10) ? 1 : -1];
typedef char ZukanTorokuBgEntry_size_check[(sizeof(ZukanTorokuBgEntry) == 44) ? 1 : -1];

extern int GF_OVERLAY_Load(int);
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,int);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *);
extern void *ZUKAN_INFO_CreateFromMon(u16,void *,u32,u32,u32,u32,u8,u32,u32,u32,u32,u32,u32);
extern char *ZUKAN_NICKNAME_Create(u16 heap, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
extern void *GFL_USE_AddMainTask(u32,u32,u32);
extern void FADE_Start(u32,int,int,int);
extern void TCB_DeleteTask(struct Node *n);
extern void ZUKAN_NICKNAME_Delete(unsigned *p);
extern void ZUKAN_INFO_Delete(char *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void PROCSYS_FreeProcWork(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(u32 heap);
extern void GF_OVERLAY_Unload(int);
extern void ZUKAN_INFO_Update(char *);
extern int ZUKAN_NICKNAME_Main(char *);
extern int FADE_IsActive(void);
extern void ZUKAN_INFO_Start(char *);
extern int TOUCHPANEL_GetTrg(void);
extern u32 KEY_GetTrg(void);
extern void func_020355D8(u8);
extern void ZUKAN_INFO_NotifyMoveDone(char *);
extern int ZUKAN_INFO_IsMoving(char *);
extern int ZUKAN_INFO_IsDone(char *);
extern void G2x_SetBlendBrightnessExt_(u32,int,int,int,int,int);
extern void ZUKAN_INFO_ClearDisplay(char *);
extern void ZUKAN_INFO_NotifyFadeDone(char *);
extern void ZUKAN_NICKNAME_SetupScreen(char *);
extern int ZUKAN_NICKNAME_GetResult(char *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *);
extern void BG_SYS_ClearSlot(u32 i);
extern void BG_SYS_SetVisibleLayer(int idx, unsigned short val);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 ARC_UTIL_RegisterObjCharFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void ARC_UTIL_UploadBgPaletteFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_TOOL_DeleteHandle(void *);
extern void BG_SYS_PushTile(u32 index);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BMP_SetDisplaySwap(u32 swap);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern void GF_FONT_SetDefaultTextColor(void);
extern u32 GFL_HEAP_Free(void *p);
extern void BG_SYS_Create(int);
extern void BMP_WIN_Init(int);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void BG_SYS_Update(void);
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
int ZUKAN_TOROKU_GRAPHIC_Init(void *owner,int unused,u32 *args);
int ZUKAN_TOROKU_GRAPHIC_Exit(void *a,int b,int c,ZukanTorokuWork *work);
int ZUKAN_TOROKU_GRAPHIC_Main(void *unused,int unused2,u32 *args,ZukanTorokuWork *work);
void ZUKAN_TOROKU_GRAPHIC_CreateBg(ZukanTorokuWork *work);
void ZUKAN_TOROKU_GRAPHIC_DeleteBg(ZukanTorokuWork *work);
void ZUKAN_TOROKU_GRAPHIC_ClearTask(int unused, ZukanTorokuWork *work);
void *ZUKAN_TOROKU_GRAPHIC_CreateDisplay(int a,int heap);
void ZUKAN_TOROKU_GRAPHIC_DeleteDisplay(ZukanTorokuDisplay *display);
void ZUKAN_TOROKU_GRAPHIC_Draw(ZukanTorokuDisplay *display);
void ZUKAN_TOROKU_GRAPHIC_Update(void *a0);
void ZUKAN_TOROKU_GRAPHIC_UpdateSub(void *a0);
u32 ZUKAN_TOROKU_GRAPHIC_GetDisplay(ZukanTorokuDisplay *display);
void ZUKAN_TOROKU_GRAPHIC_VBlank(void*unused,ZukanTorokuDisplay *display);
void ZUKAN_TOROKU_GRAPHIC_InitBg(ZukanTorokuDisplay *display,int heap);
void ZUKAN_TOROKU_GRAPHIC_ExitBg(ZukanTorokuDisplay *display);
void ZUKAN_TOROKU_GRAPHIC_UpdateBg(ZukanTorokuDisplay *display);
void ZUKAN_TOROKU_GRAPHIC_ResetDisplay(ZukanTorokuDisplay *display);
void ZUKAN_TOROKU_GRAPHIC_InitActors(struct Bank **actors, int a, int b);
void ZUKAN_TOROKU_GRAPHIC_DeleteActors(struct Bank**p);
void ZUKAN_TOROKU_GRAPHIC_DrawActors(void*p);
void ZUKAN_TOROKU_GRAPHIC_VBlankActors(void*p);
u32 ZUKAN_TOROKU_GRAPHIC_GetWord(u32*p);
extern char overlay67[],overlay206[];
extern char d_0220BC20[];
extern unsigned d_0220BAE8[];
extern const unsigned d_0220BABC[];
extern const ZukanTorokuBgEntry d_0220BB18[];





int ZUKAN_TOROKU_GRAPHIC_Init(void *owner,int unused,u32 *args)
{
    ZukanTorokuWork *work;
    int mode;
    GF_OVERLAY_Load((int)overlay67);
    GF_OVERLAY_Load((int)overlay206);
    GFL_HEAP_CreateChildHeap((u32)((void *)1),0x6a,0x80000);
    work=PROCSYS_AllocProcWork(owner,0x34,0x6a);
    MI_CpuFill8(work,0,0x34);
    work->heapId=0x6a;
    work->display=ZUKAN_TOROKU_GRAPHIC_CreateDisplay(1,work->heapId);
    work->font=GF_FONT_Create(0x17,0,0,0,work->heapId);
    work->printQueue=PRINTSYS_QUE_Create((void *)(u32)work->heapId);
    if(args[0]==0) { work->state=0; work->step=0; } else { work->state=1; work->step=0; }
    mode=0;
    if(args[0]!=0) mode=1;
    work->menu=ZUKAN_INFO_CreateFromMon(work->heapId,(void *)args[1],args[2],1,mode,0,0,ZUKAN_TOROKU_GRAPHIC_GetDisplay(work->display),(u32)work->font,work->printQueue,0,0,0);
    work->nickname=ZUKAN_NICKNAME_Create(work->heapId,args[1],args[3],args[4],args[5],ZUKAN_TOROKU_GRAPHIC_GetDisplay(work->display),(u32)work->font,work->printQueue,args[6]);
    GFL_NET_RestartWithDefaultTimeout(0,work->heapId);
    if(work->state==1) ZUKAN_TOROKU_GRAPHIC_CreateBg(work);
    work->task=GFL_USE_AddMainTask((u32)ZUKAN_TOROKU_GRAPHIC_ClearTask,(u32)work,1);
    FADE_Start(3,16,0,2);
    return 1;
}





/*
 * lever: extern overlay-id addresses preserve the pooled FS_OVERLAY_ID values.
 */
int ZUKAN_TOROKU_GRAPHIC_Exit(void *a,int b,int c,ZukanTorokuWork *work)
{
    TCB_DeleteTask((void *)work->task);
    ZUKAN_TOROKU_GRAPHIC_DeleteBg(work);
    ZUKAN_NICKNAME_Delete((void *)work->nickname);
    ZUKAN_INFO_Delete((void *)work->menu);
    PRINTSYS_QUE_Clear((void *)work->printQueue);
    PRINTSYS_QUE_Delete((void *)work->printQueue);
    GF_FONT_Delete((void *)work->font);
    ZUKAN_TOROKU_GRAPHIC_DeleteDisplay((void *)work->display);
    PROCSYS_FreeProcWork(a);
    GFL_HEAP_DeleteChecked(106);
    GF_OVERLAY_Unload((OverlayId)overlay206);
    GF_OVERLAY_Unload((OverlayId)overlay67);
    return 1;
}





/*
 * ABI: 02035C60 is void in its matched forwarder, but this caller keeps and tests live r0.
 */
int ZUKAN_TOROKU_GRAPHIC_Main(void *unused,int unused2,u32 *args,ZukanTorokuWork *work)
{
    int done=0;
    int result,flag,input;
    ZUKAN_INFO_Update((char *)work->menu);
    result=ZUKAN_NICKNAME_Main((char *)work->nickname);
    switch(work->state) {
    case 0:
        switch(work->step) {
        case 0:
            if(FADE_IsActive()==0) { ZUKAN_INFO_Start((char *)work->menu); work->step=1; }
            break;
        case 1:
            flag=0;
            input=TOUCHPANEL_GetTrg();
            if(KEY_GetTrg()&3) { func_020355D8(0); flag=1; }
            if(input!=0) { func_020355D8(1); flag=1; }
            if(flag!=0) { ZUKAN_INFO_NotifyMoveDone((char *)work->menu); work->step=2; }
            break;
        case 2:
            if(ZUKAN_INFO_IsMoving((char *)work->menu)!=0 || ZUKAN_INFO_IsDone((char *)work->menu)!=0) { work->counter=0; work->fadeLevel=16; work->step=3; }
            break;
        case 3:
            work->counter++;
            if(work->counter==4) { work->counter=0; work->fadeLevel--; }
            G2x_SetBlendBrightnessExt_(0x04000050,15,15,work->fadeLevel,0,work->fadeLevel-16);
            if(work->fadeLevel==0) { ZUKAN_INFO_ClearDisplay((char *)work->menu); ZUKAN_TOROKU_GRAPHIC_CreateBg(work); work->step=4; }
            break;
        case 4:
            work->counter++;
            if(work->counter==4) { work->counter=0; work->fadeLevel++; }
            G2x_SetBlendBrightnessExt_(0x04000050,15,15,work->fadeLevel,0,work->fadeLevel-16);
            if(work->fadeLevel==16) work->step=5;
            break;
        case 5:
            if(ZUKAN_INFO_IsDone((char *)work->menu)!=0) { work->state=1; work->step=1; }
            break;
        }
        break;
    case 1:
        switch(work->step) {
        case 0:
            if(FADE_IsActive()==0) { ZUKAN_INFO_NotifyFadeDone((char *)work->menu); work->step=1; }
            break;
        case 1:
            ZUKAN_NICKNAME_SetupScreen((char *)work->nickname); work->step=2;
            break;
        case 2:
            if(result==1) { FADE_Start(3,0,16,2); work->step=3; }
            break;
        case 3:
            if(FADE_IsActive()==0) {
                switch(ZUKAN_NICKNAME_GetResult((char *)work->nickname)) {
                case 0: args[7]=0; break;
                case 1: args[7]=1; break;
                }
                work->step=4; done=1;
            }
            break;
        }
        break;
    }
    PRINTSYS_QUE_Main((struct PrintSys *)work->printQueue);
    ZUKAN_TOROKU_GRAPHIC_Draw((void *)work->display);
    ZUKAN_TOROKU_GRAPHIC_Update((void *)work->display);
    ZUKAN_TOROKU_GRAPHIC_UpdateSub((void *)work->display);
    return done;
}





void ZUKAN_TOROKU_GRAPHIC_CreateBg(ZukanTorokuWork *work)
{
    void *r;
    work->bgActive=1;
    BG_SYS_ClearSlot(3);
    BG_SYS_SetVisibleLayer(1,3);
    BG_SYS_SetVisibleLayer(3,0);
    r=ARC_TOOL_CreateHandle(159,work->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(r,7,0,0,32,work->heapId);
    work->bgHandle=ARC_UTIL_RegisterObjCharFromHandle(r,17,1,2048,0,work->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(r,(int)39,(int)1,(u16)work->bgHandle,(int)1536,(int)0,(unsigned)work->heapId);
    ARC_TOOL_DeleteHandle(r);
    BG_SYS_PushTile(1);
}





void ZUKAN_TOROKU_GRAPHIC_DeleteBg(ZukanTorokuWork *work){u32 v,hi;v=work->bgHandle;hi=v>>16;BG_SYS_DeleteHalf(1,(u16)v,(u16)hi);}







void ZUKAN_TOROKU_GRAPHIC_ClearTask(int unused, ZukanTorokuWork *work)
{
    if (work->bgActive != 0)
    {
        BG_SYS_SetPlaneVisible(0, 0);
        BG_SYS_SetPlaneVisible(2, 0);
        work->bgActive = 0;
    }
}





/*
 * volatile: hardware accesses 0x0220B33E-0x0220B352.
 */
void *ZUKAN_TOROKU_GRAPHIC_CreateDisplay(int a,int heap)
{
    ZukanTorokuDisplay *display=GFL_HEAP_Alloc(heap,16,0,d_0220BC20,455);
    MI_CpuFill8(display,0,16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_0220BAE8);
    BMP_SetDisplaySwap(a);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    ZUKAN_TOROKU_GRAPHIC_InitBg(display,heap);
    ZUKAN_TOROKU_GRAPHIC_InitActors((struct Bank **)&display->actors,(int)d_0220BAE8,heap);
    display->vblankTask=(void *)GFL_USE_AddMainTask((u32)((void (*)(void *, void *))ZUKAN_TOROKU_GRAPHIC_VBlank), (u32)display, 0);
    return display;
}





/*
 * volatile: hardware accesses at 0x0220B3D6-0x0220B3EC.
 */
void ZUKAN_TOROKU_GRAPHIC_DeleteDisplay(ZukanTorokuDisplay *display)
{
    TCB_DeleteTask((void *)display->vblankTask);
    ZUKAN_TOROKU_GRAPHIC_DeleteActors(&display->actors);
    ZUKAN_TOROKU_GRAPHIC_ExitBg(display);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    MI_CpuFill8(display,0,16);
    GFL_HEAP_Free(display);
}





void ZUKAN_TOROKU_GRAPHIC_Draw(ZukanTorokuDisplay *display){ZUKAN_TOROKU_GRAPHIC_DrawActors(&display->actors);ZUKAN_TOROKU_GRAPHIC_UpdateBg(display);}





void ZUKAN_TOROKU_GRAPHIC_Update(void *a0){}




void ZUKAN_TOROKU_GRAPHIC_UpdateSub(void *a0){}




u32 ZUKAN_TOROKU_GRAPHIC_GetDisplay(ZukanTorokuDisplay *display){return ZUKAN_TOROKU_GRAPHIC_GetWord((u32*)&display->actors);}



void ZUKAN_TOROKU_GRAPHIC_VBlank(void*unused,ZukanTorokuDisplay *display){ZUKAN_TOROKU_GRAPHIC_ResetDisplay(display);ZUKAN_TOROKU_GRAPHIC_VBlankActors(&display->actors);}


void ZUKAN_TOROKU_GRAPHIC_InitBg(ZukanTorokuDisplay *display,int heap)
{
    unsigned i;
    MI_CpuFill8(display,0,4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_0220BABC);
    for(i=0;i<4;i++) {
        const ZukanTorokuBgEntry *e=&d_0220BB18[i];
        unsigned id=e->bgId;
        BG_SYS_InitBgLayer((u8)id,(const struct BgTemplate *)e->bgTemplate,(u8)e->type);
        BG_SYS_FreeSlot(id);
        BG_SYS_SetPlaneVisible(id,e->enable);
    }
}


void ZUKAN_TOROKU_GRAPHIC_ExitBg(ZukanTorokuDisplay *display){u32 i;for(i=0;i<4;i++)BG_SYS_FreeLayerBuf((u8)d_0220BB18[i].bgId);BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(display,0,4);}



void ZUKAN_TOROKU_GRAPHIC_UpdateBg(ZukanTorokuDisplay *display){}



void ZUKAN_TOROKU_GRAPHIC_ResetDisplay(ZukanTorokuDisplay *display){BG_SYS_Update();}




void ZUKAN_TOROKU_GRAPHIC_InitActors(struct Bank **actors, int a, int b)
{
    MI_CpuFill8(actors, 0, 4);
    CLACT_InitSystem((const struct Cfg *)0x0220BACC, a, b);
    *actors = CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer(*actors);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}



void ZUKAN_TOROKU_GRAPHIC_DeleteActors(struct Bank**p){CLACT_DeleteUnit(*p);CLACT_ExitSystem();MI_CpuFill8(p,0,4);}



void ZUKAN_TOROKU_GRAPHIC_DrawActors(void*p){CLACT_DrawSystem();}



void ZUKAN_TOROKU_GRAPHIC_VBlankActors(void*p){CLACT_VBlankSystem();}



u32 ZUKAN_TOROKU_GRAPHIC_GetWord(u32*p){return *p;}
