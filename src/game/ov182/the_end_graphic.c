/*
 * file:     the_end_graphic.c
 * unit:     yes
 * function: THE_END_GRAPHIC_Init, THE_END_GRAPHIC_Exit, THE_END_GRAPHIC_Main, THE_END_GRAPHIC_DummyTask, THE_END_GRAPHIC_LoadGraphics, THE_END_GRAPHIC_Dummy, THE_END_GRAPHIC_StartFade, THE_END_GRAPHIC_Setup3d, THE_END_GRAPHIC_Create, THE_END_GRAPHIC_Delete, THE_END_GRAPHIC_Update, THE_END_GRAPHIC_VBlankTask, THE_END_GRAPHIC_InitWindows, THE_END_GRAPHIC_ExitWindows, THE_END_GRAPHIC_Dummy2, THE_END_GRAPHIC_RefreshDisplay, THE_END_GRAPHIC_InitActors, THE_END_GRAPHIC_DeleteActors, THE_END_GRAPHIC_DrawActors, THE_END_GRAPHIC_VBlankActors, THE_END_GRAPHIC_InitCamera, THE_END_GRAPHIC_DeleteCamera
 * address:  0x021B95A0
 * region:   ov182
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021B9B9C 0x021B9B9C data a2
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BG_SYS_SetPriority 0x0204047C arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   GPOWER_GetSpecialPowerId 0x020111E8 thumb
 *   GXS_LoadBGPltt 0x0207E468 arm
 *   d_021B9BAC 0x021B9BAC data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   FADE_IsActive 0x0204E804 arm
 *   KEY_GetTrg 0x020362DC arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   FADE_Start  0x0204E720  arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021B9C28 0x021B9C28 data a4
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   d_021B9CE0 0x021B9CE0 data a1
 *   d_021B9C48 0x021B9C48 data a4
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   d_021B9BFC 0x021B9BFC data a4
 *   d_021B9C78 0x021B9C78 data a4
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   BG_SYS_Update 0x020419E4 arm
 *   d_021B9C0C      0x021B9C0C  data
 *   CLACT_InitSystem   0x0204A48C  arm
 *   CLACT_CreateUnit   0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer   0x0204B270  arm
 *   BG_SYS_SetSubPlaneVisible   0x02043598  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   d_020A1EB8 0x020A1EB8 data a2
 *   d_021B9BE4 0x021B9BE4 data a4
 *   d_021B9BD8 0x021B9BD8 data a4
 *   d_021B9BF0 0x021B9BF0 data a4
 *   G3D_CAMERA_Delete   0x02048AC4  arm
 *   G3D_SYSTEM_Exit   0x02046788  arm
 */
extern void BG_SYS_Delete(void);
extern void BMP_WIN_Exit(void);

struct ProcSystem;
struct GfFont;
struct Node;
struct PrintSys;
struct Proc;
struct DispVram;
struct BgTemplate;
struct DispConfig;
struct Bank;
struct Cfg;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct {u32 id; u32 v[10];} TheEndBgLayerRecord;

typedef signed int     s32;

typedef struct { unsigned id; unsigned v[8]; unsigned a, b; } TheEndWindowRecord;

/* proc work (0x1C) and graphic work (0x10) */
struct TheEndProcWork {
    u16 heapId;
    u8 pad2[2];
    void *graphic;
    void *font;
    struct PrintSys *printQueue;
    int initParam;
    void *vblankNode;
    int counter;
};

struct TheEndGraphic {
    u8 bgData[4];
    void *clactBank;
    u32 camera;
    void *vblankHandle;
};

/* offset-0 view of the clact slot: the actor helpers receive graphic + 4 */
struct TheEndActors {
    void *bank;
};

typedef unsigned long long u64;

extern void GFL_HEAP_CreateChildHeap(unsigned int, unsigned int, unsigned int);
extern void *PROCSYS_AllocProcWork(struct Proc *proc, unsigned int size, unsigned int heapId);
extern void MI_CpuFill8(void *, int, int);
extern struct GfFont *GF_FONT_Create(int archiveId, int fileId, int format, int isFixedWidth, u32 heapId);
struct PrintQueue;
extern struct PrintQueue *PRINTSYS_QUE_Create(unsigned int heap);
extern void BG_SYS_SetPriority(int idx, unsigned short val);
struct Tcb;
extern struct Tcb *GFL_USE_AddMainTask(void (*)(void), void *work, unsigned int priority);
extern unsigned GPOWER_GetSpecialPowerId(void);
extern void GXS_LoadBGPltt(void *pSrc, unsigned int offset, unsigned int szByte);
extern void BG_SYS_FreeLayerBuf(u32 i);
struct TcbTask;
extern void TCB_DeleteTask(struct TcbTask *task);
extern void PRINTSYS_QUE_Clear(struct PrintQueue *queue);
extern void PRINTSYS_QUE_Delete(struct PrintQueue *queue);
extern u32 GF_FONT_Delete(struct GfFont *font);
extern void PROCSYS_FreeProcWork(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(u32 heap);
extern int FADE_IsActive(void);
extern unsigned KEY_GetTrg(void);
extern u32 PRINTSYS_QUE_Main(struct PrintQueue *queue);
extern void *ARC_TOOL_CreateHandle(unsigned int archiveID, unsigned short heapID);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_UTIL_UploadBgPaletteFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void ARC_TOOL_DeleteHandle(void *handle);
extern void BG_SYS_PushTile(u32 index);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void G3X_SetFog(int, int, int, int);
extern void G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, int fog);
struct G3dLight;
extern void G3D_SYSTEM_SetLight(unsigned int lightIdx, struct G3dLight *light);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetLcdSwap(u32 swap);
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
extern void BG_SYS_FreeSlot(unsigned char);
extern void BG_SYS_Update(void);
struct DispVramCfg;
struct SysInit;
extern void CLACT_InitSystem(struct SysInit *cfg, struct DispVramCfg *res_cfg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, unsigned int heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void G3D_SYSTEM_Init(int,int,int,int,u16,u16,void *);
extern int G3D_CAMERA_Create(int,int,int,int,int,int,int,int,const void *,const void *,const void *,u16);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(void);
int THE_END_GRAPHIC_Init(void *task, int b, int c);
int THE_END_GRAPHIC_Exit(void *task, int b, int c, char *p);
int THE_END_GRAPHIC_Main(void *a, unsigned *state, void *c, char *p);
void THE_END_GRAPHIC_DummyTask(void);
void THE_END_GRAPHIC_LoadGraphics(unsigned short *p);
void THE_END_GRAPHIC_Dummy(void *p);
void THE_END_GRAPHIC_StartFade(void *a, void *b, void *c);
void THE_END_GRAPHIC_Setup3d(void);
char *THE_END_GRAPHIC_Create(int a, u16 heap);
void THE_END_GRAPHIC_Delete(char *p);
void THE_END_GRAPHIC_Update(char *p);
void THE_END_GRAPHIC_VBlankTask(int unused, char *p);
void THE_END_GRAPHIC_InitWindows(void *p, int heap);
void THE_END_GRAPHIC_ExitWindows(void *p);
void THE_END_GRAPHIC_Dummy2(void *p);
void THE_END_GRAPHIC_RefreshDisplay(void *unused);
void THE_END_GRAPHIC_InitActors(int *p, int b, int c);
void THE_END_GRAPHIC_DeleteActors(void *p);
void THE_END_GRAPHIC_DrawActors(void *unused);
void THE_END_GRAPHIC_VBlankActors(void *unused);
void THE_END_GRAPHIC_InitCamera(int *p,u16 heap);
void THE_END_GRAPHIC_DeleteCamera(unsigned int *p);
extern const u16 d_021B9B9C;
extern const TheEndBgLayerRecord d_021B9BAC[1];
extern const u32 d_021B9C28[][2];
extern const char d_021B9CE0[];
extern const u32 d_021B9C48[];
extern const unsigned d_021B9BFC[];
extern const TheEndWindowRecord d_021B9C78[];
extern unsigned char d_021B9C0C[];
extern const short d_020A1EB8[];
extern const int d_021B9BE4[],d_021B9BD8[],d_021B9BF0[];








int THE_END_GRAPHIC_Init(void *task, int b, int c)
{
    u16 value[1];
    char *p;
    u16 *vp;
    value[0] = d_021B9B9C;
    vp = value;
    GFL_HEAP_CreateChildHeap(1, 0x88, 0x30000);
    p = PROCSYS_AllocProcWork(task, 0x1c, 0x88);
    MI_CpuFill8(p, 0, 0x1c);
    ((struct TheEndProcWork *)p)->heapId = 0x88;
    ((struct TheEndProcWork *)p)->initParam = c;
    ((struct TheEndProcWork *)p)->graphic = THE_END_GRAPHIC_Create(1, ((struct TheEndProcWork *)p)->heapId);
    ((struct TheEndProcWork *)p)->font = GF_FONT_Create(0x17, 0, 0, 0, ((struct TheEndProcWork *)p)->heapId);
    ((struct TheEndProcWork *)p)->printQueue = (void *)PRINTSYS_QUE_Create((unsigned int)(((struct TheEndProcWork *)p)->heapId));
    BG_SYS_SetPriority(1, 1);
    BG_SYS_SetPriority(2, 0);
    ((struct TheEndProcWork *)p)->vblankNode = GFL_USE_AddMainTask(THE_END_GRAPHIC_DummyTask, p, 1);
    THE_END_GRAPHIC_LoadGraphics((u16 *)p);
    if (GPOWER_GetSpecialPowerId() == 0x14)
        GXS_LoadBGPltt(vp, 0, 2);
    THE_END_GRAPHIC_StartFade((void *)0x10, 0, 0);
    return 1;
}








/*
 * volatile: hardware 04001050 and 04001000 read/write at 021B966C-021B967A.
 */
int THE_END_GRAPHIC_Exit(void *task, int b, int c, char *p)
{
    int i;
    for (i = 0; i < sizeof(d_021B9BAC) / sizeof(d_021B9BAC[0]); i++)
        BG_SYS_FreeLayerBuf((u8)d_021B9BAC[i].id);
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04001000 &= ~0xe000;
    THE_END_GRAPHIC_Dummy(p);
    TCB_DeleteTask(((struct TheEndProcWork *)p)->vblankNode);
    PRINTSYS_QUE_Clear((struct PrintQueue *)(((struct TheEndProcWork *)p)->printQueue));
    PRINTSYS_QUE_Delete((struct PrintQueue *)(((struct TheEndProcWork *)p)->printQueue));
    GF_FONT_Delete(((struct TheEndProcWork *)p)->font);
    THE_END_GRAPHIC_Delete(((struct TheEndProcWork *)p)->graphic);
    PROCSYS_FreeProcWork(task);
    GFL_HEAP_DeleteChecked(0x88);
    return 1;
}








int THE_END_GRAPHIC_Main(void *a, unsigned *state, void *c, char *p)
{
    int ready;
    switch (*state) {
    case 0: *state = 4; break;
    case 1:
        if (!FADE_IsActive()) *state = 2;
        break;
    case 2:
        ready = 0;
        if (++((struct TheEndProcWork *)p)->counter > 0x384) ready = 1;
        if (ready) {
            *state = 3;
            THE_END_GRAPHIC_StartFade(0, (void *)0x10, 0);
        }
        break;
    case 3:
        if (!FADE_IsActive()) {
            THE_END_GRAPHIC_LoadGraphics((u16 *)p);
            THE_END_GRAPHIC_StartFade((void *)0x10, 0, 0);
            *state = 4;
        }
        break;
    case 4:
        if (!FADE_IsActive()) {
            ((struct TheEndProcWork *)p)->counter = 0;
            *state = 5;
        }
        break;
    case 5:
        if ((KEY_GetTrg() & 0xb) || ++((struct TheEndProcWork *)p)->counter > 0x384) {
            *state = 6;
            THE_END_GRAPHIC_StartFade(0, (void *)0x10, 0);
        }
        break;
    case 6:
        if (!FADE_IsActive()) *state = 7;
        break;
    case 7: return 1;
    }
    PRINTSYS_QUE_Main((struct PrintQueue *)(((struct TheEndProcWork *)p)->printQueue));
    THE_END_GRAPHIC_Update((char *)((struct TheEndProcWork *)p)->graphic);
    return 0;
}








void THE_END_GRAPHIC_DummyTask(void)
{
}








void THE_END_GRAPHIC_LoadGraphics(unsigned short *p)
{
    unsigned char *q = ARC_TOOL_CreateHandle(0xdc, *p);
    ARC_UTIL_UploadPaletteFromHandleWhole(q, 2, 0, 0, 0, *p);
    ARC_UTIL_UploadBgCharFromHandle(q, 3, 1, 0, 0, 0, *p);
    ARC_UTIL_UploadBgPaletteFromHandle(q, 5, 1, 0, 0, 0, *p);
    if (GPOWER_GetSpecialPowerId() == 0x14)
        BG_SYS_FillTileMap(1, 0, 0, 0x20, 0x18, 1);
    ARC_TOOL_DeleteHandle(q);
    BG_SYS_PushTile(1);
    BG_SYS_SetPlaneVisible(1, 1);
    BG_SYS_SetPlaneVisible(2, 0);
}








void THE_END_GRAPHIC_Dummy(void *p){}









void THE_END_GRAPHIC_StartFade(void *a, void *b, void *c)
{
    if (GPOWER_GetSpecialPowerId() == 0x15)
        FADE_Start(3, (s32)a, (s32)b, (s32)c);
    else
        FADE_Start(0xc, (s32)a, (s32)b, (s32)c);
}








/*
 * volatile: hardware 04000008/04000060 read/write 021B984E-021B988C, 04000580 write 021B98AA.
 */
void THE_END_GRAPHIC_Setup3d(void)
{
    unsigned i;
    BG_SYS_SetMainPlaneVisible(1, 1);
    *(volatile u16 *)0x04000008 = *(volatile u16 *)0x04000008 & ~3;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3002) | 2;
    *(volatile u16 *)0x04000060 &= (u16)~0x3010;
    *(volatile u16 *)0x04000060 &= (u16)~0x3004;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 8;
    *(volatile u16 *)0x04000060 &= (u16)~0x3020;
    G3X_SetFog(0, 0, 0, 0);
    G3X_SetClearColor(0, 0, 0x7fff, 0x3f, 0);
    *(volatile u32 *)0x04000580 = 0xbfff0000;
    for (i = 0; i < 4; i++)
        G3D_SYSTEM_SetLight((u8)i, (struct G3dLight *)d_021B9C28[i]);
    G3D_SYSTEM_SetSwapBuffersMode(0, 0);
}








char *THE_END_GRAPHIC_Create(int a, u16 heap)
{
    char *p;
    p = GFL_HEAP_Alloc(heap, 0x10, 0, d_021B9CE0, 0x1cc);
    MI_CpuFill8(p, 0, 0x10);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04000000 &= ~0xe000;
    *(volatile u32 *)0x04001000 &= ~0xe000;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021B9C48);
    BG_SYS_SetLcdSwap(a);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    THE_END_GRAPHIC_InitWindows(p, heap);
    THE_END_GRAPHIC_InitActors((int *)(p + 4), (int)d_021B9C48, heap);
    THE_END_GRAPHIC_InitCamera((int *)(p + 8), heap);
    ((struct TheEndGraphic *)p)->vblankHandle = GFL_USE_AddMainTask((void ( *)(void))THE_END_GRAPHIC_VBlankTask, p, 0);
    return p;
}








/*
 * volatile: Hardware registers 0x04000050, 0x04001050, 0x04000000, 0x04001000 read/write at 0x021B99B2..0x021B99C8.
 */
void THE_END_GRAPHIC_Delete(char *p)
{
    TCB_DeleteTask(((struct TheEndGraphic *)p)->vblankHandle);
    THE_END_GRAPHIC_DeleteCamera((unsigned *)(p + 8));
    THE_END_GRAPHIC_DeleteActors(p + 4);
    THE_END_GRAPHIC_ExitWindows(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    MI_CpuFill8(p, 0, 0x10);
    GFL_HEAP_Free(p);
}








void THE_END_GRAPHIC_Update(char *p)
{
    THE_END_GRAPHIC_DrawActors(p + 4);
    THE_END_GRAPHIC_Dummy2(p);
}








void THE_END_GRAPHIC_VBlankTask(int unused, char *p)
{
    THE_END_GRAPHIC_RefreshDisplay(p);
    THE_END_GRAPHIC_VBlankActors(p + 4);
}







void THE_END_GRAPHIC_InitWindows(void *p, int heap)
{
    unsigned i = 0;
    const TheEndWindowRecord *r;
    unsigned id;
    MI_CpuFill8(p, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021B9BFC);
    for (; i < 2; i++) {
        r = &d_021B9C78[i];
        id = r->id;
        BG_SYS_InitBgLayer((unsigned char)id, (const struct BgTemplate *)r->v, (unsigned char)r->a);
        BG_SYS_FreeSlot(id);
        BG_SYS_SetPlaneVisible(id, r->b);
    }
}







void THE_END_GRAPHIC_ExitWindows(void *p){u32 i;for(i=0;i<2;i++)BG_SYS_FreeLayerBuf((u8)d_021B9C78[i].id);BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4);}







void THE_END_GRAPHIC_Dummy2(void *p){}





void THE_END_GRAPHIC_RefreshDisplay(void *unused) { BG_SYS_Update(); }





void THE_END_GRAPHIC_InitActors(int *p, int b, int c)
{
    MI_CpuFill8((void *)((int)p), 0, 4);
    CLACT_InitSystem((struct SysInit *)d_021B9C0C, (struct DispVramCfg *)b, c);
    p[0] = (int)CLACT_CreateUnit(0x80, 0, c);
    CLACT_SetUnitDefaultRenderer((void *)p[0]);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}




void THE_END_GRAPHIC_DeleteActors(void *p)
{
    CLACT_DeleteUnit((struct Bank *)((struct TheEndActors *)p)->bank);
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 4);
}



void THE_END_GRAPHIC_DrawActors(void *unused) { CLACT_DrawSystem(); }



void THE_END_GRAPHIC_VBlankActors(void *unused) { CLACT_VBlankSystem(); }



void THE_END_GRAPHIC_InitCamera(int *p,u16 heap)
{
    G3D_SYSTEM_Init(0,1,0,1,0,heap,THE_END_GRAPHIC_Setup3d);
    *p=G3D_CAMERA_Create(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,0x1000,0x400000,0,d_021B9BE4,d_021B9BD8,d_021B9BF0,heap);
}


void THE_END_GRAPHIC_DeleteCamera(unsigned int *p)
{
    G3D_CAMERA_Delete((void *)(*p));
    G3D_SYSTEM_Exit();
}
