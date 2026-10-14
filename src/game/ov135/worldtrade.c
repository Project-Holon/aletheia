/*
 * file:     worldtrade.c
 * unit:     yes
 * function: WORLDTRADE_ProcInit, WORLDTRADE_ProcMain, WORLDTRADE_ProcExit, WORLDTRADE_VBlankTask, WORLDTRADE_SetupVramBanks, WORLDTRADE_CallStateHandler, WORLDTRADE_Nop, WORLDTRADE_SetupWindowPlanes, WORLDTRADE_InitClactSystem, WORLDTRADE_SetPlaneVisibleAll, WORLDTRADE_OpenTaskMenuYesNoDefault, WORLDTRADE_OpenTaskMenuYesNo, WORLDTRADE_CloseTaskMenu, WORLDTRADE_UpdateTaskMenuYesNo, WORLDTRADE_OpenTaskMenuList, WORLDTRADE_UpdateTaskMenuList, WORLDTRADE_CloseTaskMenuList, WORLDTRADE_SetNextState, WORLDTRADE_SetActorSurfacePos, WORLDTRADE_GetWifiLinkLevel, WORLDTRADE_SetStateAndReturn, WORLDTRADE_ClearBusyFlag, WORLDTRADE_QueryGameData, WORLDTRADE_SetupGraphics, WORLDTRADE_ReleaseGraphics, WORLDTRADE_DecrementTimer, WORLDTRADE_ClearSelectedSpecies, WORLDTRADE_CreateTimeIcon, WORLDTRADE_DeleteTimeIcon, WORLDTRADE_SetActorPos, WORLDTRADE_SetBrightnessIn, WORLDTRADE_SetBrightnessOut, WORLDTRADE_ClearBlendRegs, WORLDTRADE_ClearAndShowPlanes, WORLDTRADE_ExitPlanes, WORLDTRADE_CancelSave
 * address:  0x021F4580
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from worldtrade_box.c, worldtrade_enter.c, worldtrade_adapter.c, WORLDTRADE_ADAPTER_QueueMessagePrint.c by tools/splitfile.py.
 *
 * symbols:
 *   WORLDTRADE_ADAPTER_AllocHeapBuf  0x02202608  thumb
 *   WORLDTRADE_ADAPTER_InitPrinter  0x022026D8  thumb
 *   g_02203F80  0x02203F80  data
 *   str_02203AF8  0x02203AF8  data  a1
 *   ov114_id  0x00000072  data
 *   ov067_id  0x00000043  data
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   func_0205D074 0x0205D074 arm
 *   GFL_NET_WM_ICON_EasySetLevel 0x020370F4 arm
 *   DPW_TR_Main 0x021C7C1C arm ov114
 *   PROCSYS_Main 0x02031330 arm
 *   func_02030D28 0x02030D28 arm
 *   WORLDTRADE_ADAPTER_UpdatePrinter 0x02202770 thumb ov135
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   WORLDTRADE_SUBLCD_CreateActors 0x021FF6A4 thumb ov135
 *   WORLDTRADE_SUBLCD_UpdateSlotPalettes 0x021FFB20 thumb ov135
 *   CLACT_DrawSystem 0x0204A600 arm
 *   d_02203A80 0x02203A80 data a4
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_02030DA4 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0203133C 0x0203133C arm
 *   WORLDTRADE_ADAPTER_ExitPrinter 0x02202744 thumb ov135
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   str_02203B08  0x02203B08  data  a1
 *   func_020490F4  0x020490F4  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_02049F34  0x02049F34  arm
 *   DC_FlushRange  0x020862F0  arm
 *   GX_LoadOBJPltt 0x0207E51C  arm
 *   func_02008550  0x02008550  thumb
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   d_02202BE0     0x02202BE0  data
 *   func_02034714 0x02034714 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   data_02202BC8 0x02202BC8 data a4
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   data_02202C2C 0x02202C2C data a4
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   DWC_GetLinkLevel  0x0205CCD8  arm
 *   sub_02012FFC  0x02012FFC  thumb  arm9
 *   g_02202BFC  0x02202BFC  data  ov135
 *   WORLDTRADE_SUBLCD_FreeResources  0x021FFCD4  thumb
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   func_020056BC  0x020056BC  thumb
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   tbl_02202BB8  0x02202BB8  data
 *   func_02030EAC  0x02030EAC  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_0200F7C0   0x0200F7C0  thumb
 *   func_0203FC28  0x0203FC28  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   func_02030734 0x02030734 arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb  arm9
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb  arm9
 *   GAME_DATA_SaveCancel  0x02012E08  thumb  arm9
 *   PROCSYS_Create  0x02031324  arm  arm9
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm  arm9
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm  arm9
 *   BG_SYS_ClearSubPlanes  0x02043588  arm  arm9
 *   TIME_ICON_Create  0x0202EE30  thumb  arm9
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm  arm9
 *   PROCSYS_AllocProcWork  0x0203159C  arm  arm9
 *   BG_SYS_SetVramBanks  0x020433E0  arm  arm9
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm  arm9
 *   BMP_WIN_Init  0x02045088  arm  arm9
 *   CLACT_VBlankSystem  0x0204A648  arm  arm9
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm  arm9
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm  arm9
 *   WORLDTRADE_ExitPlanes 0x021F50EC thumb ov135
 *   WORLDTRADE_ClearAndShowPlanes  0x021F5074  thumb  ov135
 *   WORLDTRADE_ClearBusyFlag  0x021F4EC8  thumb  ov135
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb
 *   WORLDTRADE_CancelSave  0x021F513C  thumb  ov135
 *   WORLDTRADE_DeleteTimeIcon  0x021F4FC4  thumb  ov135
 *   WORLDTRADE_SetActorPos  0x021F4FF4  thumb
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   WORLDTRADE_OpenTaskMenuYesNo  0x021F4BF8  thumb  ov135
 *   WORLDTRADE_ClearBlendRegs  0x021F5060  thumb  ov135
 *   WORLDTRADE_SetBrightnessOut  0x021F5034  thumb  ov135
 *   WORLDTRADE_UpdateTaskMenuYesNo 0x021F4D14 thumb ov135
 *   WORLDTRADE_CloseTaskMenu 0x021F4CE4 thumb ov135
 *   WORLDTRADE_OpenTaskMenuList 0x021F4D50 thumb ov135
 *   WORLDTRADE_UpdateTaskMenuList 0x021F4E30 thumb ov135
 *   WORLDTRADE_CloseTaskMenuList 0x021F4E64 thumb ov135
 *   WORLDTRADE_SetActorSurfacePos 0x021F4EA0 thumb ov135
 *   WORLDTRADE_OpenTaskMenuYesNoDefault  0x021F4BE0  thumb  ov135
 *   WORLDTRADE_ClearSelectedSpecies 0x021F4F90 thumb ov135
 *   WORLDTRADE_QueryGameData 0x021F4ED4 thumb ov135
 *   WORLDTRADE_CreateTimeIcon  0x021F4FA4  thumb
 *   func_02045B38 0x02045B38 arm
 */
#include "worldtrade_types.h"
#include "../../matched/include/Obj00018.h"

#define ASSERT(x) if (!(x)) func_02034714(str_02203B08, 0, str_02203B08)

struct Obj0203159C;

struct S020314B8;

struct S020315D4;

struct DispVram;

struct Bank;

struct R;

struct TaskMenu;

struct TaskMenuTmpl;

struct TaskMenuState;

typedef struct {
    u8 pad0[0x20];
    u32 x20;
} Args_021F4580;

typedef struct { int (*init)(u8 *, int); int (*update)(u8 *, int); int (*finish)(u8 *, int); } Handler;

typedef volatile u32 vu32_021F4580;

typedef volatile u16 vu16;

typedef struct {
    u8 pad0[0xC];
    u16 *data;
} PlttData;

typedef struct { union { void *text; u32 a; }; u32 b, c; } BoxItem;

typedef struct { BoxItem item[2]; } BoxItems2;

typedef struct { u32 heap; u8 count,pad[3]; BoxItem *items; u32 mode; u8 a,b,c,d; } BoxMenu_021F4580;

typedef struct { BoxItem item[3]; } BoxItems3;

typedef volatile u16 vu16_021F5074;

typedef volatile unsigned short vu16_021F50EC;

typedef volatile unsigned int vu32_021F4D50;

extern int func_02034AC4(s32 handle);

extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);

extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);

extern void MI_CpuFill8(void *p, u32 v, u32 n);

extern void *WORLDTRADE_ADAPTER_AllocHeapBuf(u32 heap);

extern void *PROCSYS_Create(int a0);

extern u32 func_02030CB0(u32 n);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);

extern void WORLDTRADE_ADAPTER_InitPrinter(void *ctx, u32 arg);

extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern void BG_SYS_ClearGraphicsMemory(u32 keep);

extern void GFL_USE_SetBgmPlayerParam(void *p);

extern void GFL_USE_CancelChangeAndStopBgm(void);

extern int GFL_NET_GetRunState(void);

extern int func_0205D074(void);

extern u32 GFL_NET_WM_ICON_EasySetLevel(u32);

extern void DPW_TR_Main(void);

extern u32 PROCSYS_Main(void *);

extern void func_02030D28(struct Ctx *c);

extern void WORLDTRADE_ADAPTER_UpdatePrinter(void *);

extern u32 WIPE_SYS_EndCheck(void);

extern void WORLDTRADE_SUBLCD_CreateActors(Work *);

extern void WORLDTRADE_SUBLCD_UpdateSlotPalettes(Work *, int, int);

extern void CLACT_DrawSystem(void *);

extern unsigned int MSGDATA_Delete(struct Rec *rec);

extern unsigned int func_0201ED04(struct WordSet *p);

extern void func_02030DA4(void *);

extern u32 func_020307B0(void *p);

extern void func_0203133C(struct S020314B8 *p);

extern void WORLDTRADE_ADAPTER_ExitPrinter(u8 *p);

extern void func_020315D4(struct S020315D4 *p);

extern void func_020306F0(unsigned int heap);

extern void func_02034A5C(s32 handle);

extern void func_020419E4(void);

extern void CLACT_VBlankSystem(void);

extern void BG_SYS_SetVramBanks(const struct DispVram *c);

extern void func_02034714(const char *expr, u32 line, const char *file);

extern void *func_020490F4(u32 id, u32 heap);

extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void ARC_TOOL_DeleteHandle(void *h);

extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);

extern void DC_FlushRange(void *p, u32 size);

extern void GX_LoadOBJPltt(const void *src, u32 offset, u32 size);

extern u8 func_02008550(const struct Sub0200852CObj *obj);

extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern void BG_SYS_SetMainPlaneVisible(u32 a, u32 b);

extern void BG_SYS_SetSubPlaneVisible(u32 a, u32 b);

extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);

extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);

extern void *func_02045EC0(struct MsgBank *bank, u32 index);

extern void STRBUF_Delete(struct U16Vec *vec);

extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);

extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);

extern void APP_TASKMENU_UpdateMenu(void *);

extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);

extern u8 APP_TASKMENU_GetCursorPos(const u8 *);

extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

extern int DWC_GetLinkLevel(void);

extern signed char sub_02012FFC(void);

extern void WORLDTRADE_SUBLCD_FreeResources(Work *p);

extern void CLACT_ReleasePalette(u32 v);

extern void CLACT_ReleaseCharacter(u32 v);

extern void CLACT_ReleaseCellAnim(u32 v);

extern u32 CLACT_DeleteUnit(struct Bank *bank);

extern void CLACT_ExitSystem(void);

extern u32 func_020056BC(void);

extern u8 *TIME_ICON_Create(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);

extern void TIME_ICON_Delete(u8 *p);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);

extern void func_020409B4(u32 v);

extern void func_0207D658(u32 addr, int plane, int brightness);

extern void BG_SYS_ClearMainPlanes(void);

extern void BG_SYS_ClearSubPlanes(void);

extern void BG_SYS_SetMainVisiblePlanes(u32 planes);

extern void BG_SYS_SetSubVisiblePlanes(u32 a);

extern void func_0203F8F4(u16 heapId);

extern void BMP_WIN_Init(u16 heapId);

extern void func_0203FC28(struct DispConfig_021F4580 *cfg);

extern void *func_020056A0(void *callback, void *ctx, int a2);

extern void func_02030EAC(struct Node *n);

extern void BMP_WIN_Exit(void);

extern void func_0203F9B4(void);

extern void *func_020120F4(const struct Ctx *p);

extern void GAME_DATA_SaveCancel(char *p);

extern void func_0200F7C0(u32 c);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern void STRBUF_Delete(struct U16Vec *vec);

int WORLDTRADE_ProcInit(void *proc, int *seq, Args_021F4580 *args);

int WORLDTRADE_ProcMain(void *unused0, int *state, void *unused2, Work *p);

int WORLDTRADE_ProcExit(void *ctx, int unused1, int unused2, Work *p);

void WORLDTRADE_VBlankTask(void *unused, Work *p);

void WORLDTRADE_SetupVramBanks(const struct DispVram *a0);

void WORLDTRADE_CallStateHandler(Work *p, Args *args);

void WORLDTRADE_Nop(Work *a0);

void WORLDTRADE_SetupWindowPlanes(void);

void WORLDTRADE_InitClactSystem(Work *p, u32 mode);

void WORLDTRADE_SetPlaneVisibleAll(Work *p);

void WORLDTRADE_OpenTaskMenuYesNoDefault(u32 a, u32 b, u32 c, u32 d, u8 e);

void WORLDTRADE_OpenTaskMenuYesNo(Work *p,int b,int unused,int a,int c,u8 flag);

void WORLDTRADE_CloseTaskMenu(Work *p);

int WORLDTRADE_UpdateTaskMenuYesNo(Work *p);

void WORLDTRADE_OpenTaskMenuList(Work *p, u16 a, int count, int b);

u32 WORLDTRADE_UpdateTaskMenuList(Work *p);

void WORLDTRADE_CloseTaskMenuList(Work *p);

void WORLDTRADE_SetNextState(Work *p, u32 a, u32 b);

void WORLDTRADE_SetActorSurfacePos(u32 a, u16 b, u16 c);

int WORLDTRADE_GetWifiLinkLevel(void);

void WORLDTRADE_SetStateAndReturn(Work *p, u32 a, u32 b);

void WORLDTRADE_ClearBusyFlag(Work *p);

int WORLDTRADE_QueryGameData(void);

void WORLDTRADE_SetupGraphics(Work *p);

void WORLDTRADE_ReleaseGraphics(Work *p);

void WORLDTRADE_DecrementTimer(Work *p);

void WORLDTRADE_ClearSelectedSpecies(Work *p);

void WORLDTRADE_CreateTimeIcon(Work *p);

void WORLDTRADE_DeleteTimeIcon(Work *p);

void WORLDTRADE_SetActorPos(u32 a, u32 b, u32 c);

void WORLDTRADE_SetBrightnessIn(u32 x);

void WORLDTRADE_SetBrightnessOut(u32 x);

void WORLDTRADE_ClearBlendRegs(void);

void WORLDTRADE_ClearAndShowPlanes(Work *p);

void WORLDTRADE_ExitPlanes(Work *p);

void WORLDTRADE_CancelSave(Work *p);

extern u8 ov114_id[];

extern u8 ov067_id[];

extern Work *g_02203F80;

extern const char str_02203AF8[];

extern const Handler d_02203A80[];

extern const char str_02203B08[];

extern u8 d_02202BE0[];

extern const BoxItems2 data_02202BC8;

extern const BoxItems3 data_02202C2C;

extern u8 g_02202BFC[];

extern const struct DispConfig_021F4580 tbl_02202BB8;

int WORLDTRADE_ProcInit(void *proc, int *seq, Args_021F4580 *args)
{
    Work *p;

    func_02034AC4((u32)ov114_id);
    func_02034AC4((u32)ov067_id);
    GFL_HEAP_CreateChildHeap(1, 0x48, 0x30100);
    p = PROCSYS_AllocProcWork(proc, sizeof(Work), 0x48);
    MI_CpuFill8(p, 0, sizeof(Work));
    g_02203F80 = p;
    p->fEA8 = WORLDTRADE_ADAPTER_AllocHeapBuf(0x48);
    p->f12F0 = PROCSYS_Create(0x48);
    p->recMem = func_02030734(0x48, func_02030CB0(8), 0, str_02203AF8, 0xA1);
    p->rec_p = func_02030CBC(8, p->recMem);
    WORLDTRADE_ADAPTER_InitPrinter(p->tail, args->x20);
    p->words = func_0201EC74(0xB, 0x40, 0x48);
    p->msg[0] = func_02045B38(0, 2, 0xD0, 0x48);
    p->msg[2] = func_02045B38(0, 2, 0xD1, 0x48);
    p->msg[3] = func_02045B38(0, 2, 0xE8, 0x48);
    p->msg[1] = func_02045B38(0, 2, 0x46, 0x48);
    p->msg[4] = func_02045B38(0, 2, 0xE7, 0x48);
    WORLDTRADE_CallStateHandler((Work *)p, (Args *)args);
    BG_SYS_ClearGraphicsMemory(0);
    WORLDTRADE_ClearAndShowPlanes(p);
    GFL_USE_SetBgmPlayerParam(0);
    GFL_USE_CancelChangeAndStopBgm();
    return 1;
}

int WORLDTRADE_ProcMain(void *unused0, int *state, void *unused2, Work *p)
{
    if (GFL_NET_GetRunState() != 0) {
        func_0205D074();
        GFL_NET_WM_ICON_EasySetLevel(WORLDTRADE_GetWifiLinkLevel());
    }
    DPW_TR_Main();
    p->busy_u = PROCSYS_Main(p->f12F0);
    func_02030D28(p->rec_p);
    WORLDTRADE_ADAPTER_UpdatePrinter((u8 *)p + 0xfa0);
    switch (*state) {
    case 0:
        *state = d_02203A80[p->x10].init((u8 *)p, *state);
        WORLDTRADE_SetupWindowPlanes();
        break;
    case 1:
        if (WIPE_SYS_EndCheck() != 0) *state = 2;
        break;
    case 2:
        *state = d_02203A80[p->x10].update((u8 *)p, *state);
        break;
    case 3:
        if (WIPE_SYS_EndCheck() != 0) {
            *state = d_02203A80[p->x10].finish((u8 *)p, *state);
            if (p->fB8 != 0) {
                WORLDTRADE_SUBLCD_CreateActors(p);
                WORLDTRADE_SUBLCD_UpdateSlotPalettes(p, (*(int *)&p->d0), 0);
                p->fB8 = 0;
            }
        }
        break;
    case 4:
        *state = 5;
        break;
    case 5:
        return 1;
    }
    WORLDTRADE_DecrementTimer(p);
    if (*(u32 *)&p->res != 0) CLACT_DrawSystem(p->res);
    if (p->f12E8 > 0) p->f12E8 -= 1;
    return 0;
}

int WORLDTRADE_ProcExit(void *ctx, int unused1, int unused2, Work *p)
{
    GFL_USE_CancelChangeAndStopBgm();
    WORLDTRADE_ExitPlanes(p);
    WORLDTRADE_Nop(p);
    MSGDATA_Delete(p->names);
    MSGDATA_Delete(p->msg[3]);
    MSGDATA_Delete(p->msg[2]);
    MSGDATA_Delete(p->bank);
    MSGDATA_Delete(p->msg_p);
    func_0201ED04(p->words);
    func_02030DA4(p->rec_p);
    func_020307B0(p->recMem);
    func_0203133C(p->f12F0);
    func_020307B0(p->fEA8);
    WORLDTRADE_ADAPTER_ExitPrinter((u8 *)p + 0xfa0);
    func_020315D4(ctx);
    func_020306F0(0x48);
    func_02034A5C((unsigned int)ov067_id);
    func_02034A5C((unsigned int)ov114_id);
    return 1;
}

void WORLDTRADE_VBlankTask(void *unused, Work *p)
{
    func_020419E4();
    CLACT_VBlankSystem();
    if (p->once != 0) {
        p->once(p);
        p->once = 0;
    }
    if (p->every != 0) {
        p->every(p);
    }
}

void WORLDTRADE_SetupVramBanks(const struct DispVram *a0)
{
    BG_SYS_SetVramBanks(a0);
}

void WORLDTRADE_CallStateHandler(Work *p, Args *args)
{
    ASSERT(args->a3C);
    ASSERT(args->a0);
    ASSERT(args->a4);
    ASSERT(args->a8);
    ASSERT(args->aC);
    ASSERT(args->a14);
    ASSERT(args->a18);
    ASSERT(args->a1C);
    ASSERT(args->a20);
    ASSERT(args->a24);
    p->args = args;
    p->x10 = 0;
    WORLDTRADE_SetStateAndReturn(p, 0, 0x13);
    p->sel = 0;
    p->sel_h = 0;
    p->xB58 = 3;
    p->xB59 = 0;
    p->xB5A = 0;
    p->xB5C = 0;
    p->active = 0;
    p->box = 0xFF;
    p->species = 0;
    p->xEB2 = 0;
    p->fE1A = 0;
    p->xDF8 = 0;
    p->fF84 = 0;
}

/*
 * Empty stub: a bare `bx lr`, the overlay's no-op placeholder body.
 */
void WORLDTRADE_Nop(Work *a0)
{
}

static inline void SetWnd0InsidePlane(int wnd, int effect)
{
    u32 tmp = (*(vu16 *)0x04000048 & ~0x3F) | wnd;

    if (effect) {
        tmp |= 0x20;
    }
    *(vu16 *)0x04000048 = (u16)tmp;
}

static inline void SetWndOutsidePlane(int wnd, int effect)
{
    u32 tmp = (*(vu16 *)0x0400004A & ~0x3F) | wnd;

    if (effect) {
        tmp |= 0x20;
    }
    *(vu16 *)0x0400004A = (u16)tmp;
}

void WORLDTRADE_SetupWindowPlanes(void)
{
    *(vu32_021F4580 *)0x04001000 &= ~0xE000;
    *(vu32_021F4580 *)0x04000000 = (*(vu32_021F4580 *)0x04000000 & ~0xE000) | 0x2000;
    SetWnd0InsidePlane(0x1F, 0);
    SetWndOutsidePlane(0x1F, 1);
    *(vu16 *)0x04000040 = 0xF0FF;
    *(vu16 *)0x04000044 = 0x10;
}

/*
 * Load the screen's OBJ resources: the archive-0x60 cell, character,
 * palette and animation sets into the resource block at +0xBC0, the
 * OBJ palette from archive 7 at 0xA0 and a half-brightness copy of it
 * at 0x100, and from archive 0x1F the version-dependent set (files
 * 0x11/6/0xF/0x10 when func_02008550 reports 1, else 0xE/4/0xC/0xD).
 */
void WORLDTRADE_InitClactSystem(Work *p, u32 mode)
{
    void *arc;
    void *buf;
    PlttData *pd;
    int i;
    u16 *d;
    u32 anm;
    u32 cell;
    u32 pal;
    u32 chr;

    arc = func_020490F4(0x60, 0x48);
    CLACT_InitSystem((const struct Cfg *)d_02202BE0, mode, 0x48);
    p->res_res.f0 = (u32)CLACT_CreateUnit(0x60, 0, 0x48);
    p->res_res.f4 = CLACT_RegisterCharacter(arc, 0x11, 1, 0, 0x48);
    p->res_res.f8 = CLACT_RegisterPalette(arc, 8, 0, 0, 0x48);
    p->res_res.fC = CLACT_RegisterCellAnim(arc, 0x12, 0x13, 0x48);
    p->res_res.f28 = CLACT_RegisterCharacter(arc, 0x27, 1, 0, 0x48);
    p->res_res.f30 = CLACT_RegisterCellAnim(arc, 0x28, 0x29, 0x48);
    p->res_res.f10 = CLACT_RegisterCharacter(arc, 0x24, 1, 1, 0x48);
    p->res_res.f14 = CLACT_RegisterPalette(arc, 7, 1, 0, 0x48);
    p->res_res.f18 = CLACT_RegisterCellAnim(arc, 0x25, 0x26, 0x48);
    ARC_TOOL_DeleteHandle(arc);

    buf = func_02049F34(7, 0, (u32)(&pd), 0x48);
    DC_FlushRange(pd->data, 0x60);
    GX_LoadOBJPltt(pd->data, 0xA0, 0x60);
    d = pd->data;
    for (i = 0; i < 0x30; i++) {
        u16 c = d[i];
        d[i] = ((((c >> 10) & 0x1f) / 2) << 10) | ((((c >> 5) & 0x1f) / 2) << 5) | ((c & 0x1f) / 2);
    }
    DC_FlushRange(pd->data, 0x60);
    GX_LoadOBJPltt(pd->data, 0x100, 0x60);
    func_020307B0(buf);

    if ((u8)(u32)func_02008550(p->ctx->f1C) == 1) {
        chr = 0x11;
        anm = 0x10;
        cell = 0xF;
        pal = 6;
    } else {
        chr = 0xE;
        anm = 0xD;
        cell = 0xC;
        pal = 4;
    }
    arc = func_020490F4(0x1f, 0x48);
    p->res_res.f1C = CLACT_RegisterCharacter(arc, chr, 0, 1, 0x48);
    p->res_res.f20 = CLACT_RegisterPaletteEx(arc, pal, 1, 0, 0, 1, 0x48);
    p->res_res.f24 = CLACT_RegisterCellAnim(arc, cell, anm, 0x48);
    ARC_TOOL_DeleteHandle(arc);
}

/*
 * Release the 0x10 channel on both hardware blocks.
 */
void WORLDTRADE_SetPlaneVisibleAll(Work *p)
{
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

/*
 * Forward four register arguments plus a zero and the u8 stack argument.
 */
void WORLDTRADE_OpenTaskMenuYesNoDefault(u32 a, u32 b, u32 c, u32 d, u8 e)
{
    WORLDTRADE_OpenTaskMenuYesNo((Work *)a, b, c, d, 0, e);
}

void WORLDTRADE_OpenTaskMenuYesNo(Work *p,int b,int unused,int a,int c,u8 flag)
{
    BoxItems2 items;
    BoxMenu_021F4580 menu;
    int on;
    if (p->fE04) func_02034714(str_02203B08,0,str_02203B08);
    if (p->fE08) func_02034714(str_02203B08,0,str_02203B08);
    p->fE04=APP_TASKMENU_RES_Create((u8)c,(u8)a,p->uiResA,p->uiResB,0x48);
    items=data_02202BC8;
    on=0;
    MI_CpuFill8(&menu,0,20);
    items.item[0].text=func_02045EC0(p->bank,63);
    items.item[1].text=func_02045EC0(p->bank,64);
    menu.heap=0x48;
    menu.count=2;
    menu.items=items.item;
    menu.mode=1;
    menu.a=0x20;
    menu.b=b;
    menu.c=8;
    menu.d=3;
    p->fE08=APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&menu),p->fE04);
    STRBUF_Delete(items.item[0].text);
    STRBUF_Delete(items.item[1].text);
    if (flag) {
        if(c<=3) on=1;
        WORLDTRADE_SetBrightnessIn(on);
    }
}

void WORLDTRADE_CloseTaskMenu(Work *p) { if(p->fE08) { APP_TASKMENU_CloseMenu(p->fE08); p->fE08=0; } if(p->fE04) { APP_TASKMENU_RES_Delete(p->fE04); p->fE04=0; } }

int WORLDTRADE_UpdateTaskMenuYesNo(Work *p) { int result; result=0; if(p->fE08) { APP_TASKMENU_UpdateMenu(p->fE08); if(APP_TASKMENU_IsFinish(p->fE08)) { result=APP_TASKMENU_GetCursorPos(p->fE08); if(result==0) result=1; else if(result==1) result=2; WORLDTRADE_ClearBlendRegs(); } } return result; }

void WORLDTRADE_OpenTaskMenuList(Work *p, u16 a, int count, int b)
{
    BoxItems3 items;
    BoxMenu_021F4580 menu;
    int i;
    if (p->fE04) func_02034714(str_02203B08,0,str_02203B08);
    if (p->fE08) func_02034714(str_02203B08,0,str_02203B08);
    p->fE04=APP_TASKMENU_RES_Create(a,10,p->uiResA,p->uiResB,0x48);
    items=data_02202C2C;
    MI_CpuFill8(&menu,0,20);
    if ((u32)count>3) func_02034714(str_02203B08,0,str_02203B08);
    for(i=0;i<count;i++) items.item[i].a=*(u32 *)((u32)p->de8+i*8);
    menu.heap=0x48;
    menu.count=count;
    menu.items=items.item;
    menu.mode=1;
    menu.a=0x20;
    menu.b=b;
    menu.c=13;
    menu.d=3;
    p->fE08=APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&menu),p->fE04);
    WORLDTRADE_SetBrightnessIn(1);
}

u32 WORLDTRADE_UpdateTaskMenuList(Work *p)
{
    u32 r = (u32)-1;

    if (p->fE08 != 0) {
        APP_TASKMENU_UpdateMenu(p->fE08);
        if (APP_TASKMENU_IsFinish(p->fE08) != 0) {
            r = APP_TASKMENU_GetCursorPos(p->fE08) + 1;
            WORLDTRADE_ClearBlendRegs();
        }
    }
    return r;
}

void WORLDTRADE_CloseTaskMenuList(Work *p)
{
    if (p->fE08 != 0) {
        APP_TASKMENU_CloseMenu(p->fE08);
        p->fE08 = 0;
    }
    if (p->fE04 != 0) {
        APP_TASKMENU_RES_Delete(p->fE04);
        p->fE04 = 0;
    }
    WORLDTRADE_ClearBlendRegs();
}

void WORLDTRADE_SetNextState(Work *p, u32 a, u32 b)
{
    p->state = a;
    p->returnState = b;
}

/*
 * Send a one-entry u16 table {b, c}
/*
 * Send a one-entry u16 table {b, c} to CLACT_AddActorSurfacePos.
 */
void WORLDTRADE_SetActorSurfacePos(u32 a, u16 b, u16 c)
{
    u16 t[2];

    t[0] = b;
    t[1] = c;
    CLACT_AddActorSurfacePos((struct Obj *)a, (const struct Vec2 *)t, 1);
}

int WORLDTRADE_GetWifiLinkLevel(void)
{
    return 3 - DWC_GetLinkLevel();
}

/*
 * Store two words into the object at +0x14 and +0x20.
 */
void WORLDTRADE_SetStateAndReturn(Work *p, u32 a, u32 b)
{
    p->x14 = a;
    *(u32 *)&p->kind = b;
}

/*
 * Save the current value at +0x10 into +0x1c and move +0x14 down into +0x10.
 */
void WORLDTRADE_ClearBusyFlag(Work *p)
{
    p->f1C_u = p->x10;
    p->x10 = p->x14;
}

int WORLDTRADE_QueryGameData(void)
{
    return sub_02012FFC();
}

/*
 * Wire the shared table into the two initialisers and release the channel.
 */
void WORLDTRADE_SetupGraphics(Work *p)
{
    WORLDTRADE_SetupVramBanks((const struct DispVram *)g_02202BFC);
    WORLDTRADE_InitClactSystem((Work *)p, (u32)g_02202BFC);
    WORLDTRADE_SetPlaneVisibleAll(p);
}

void WORLDTRADE_ReleaseGraphics(Work *p)
{
    WORLDTRADE_SUBLCD_FreeResources(p);
    CLACT_ReleasePalette(p->res_res.f20);
    CLACT_ReleaseCharacter(p->res_res.f1C);
    CLACT_ReleaseCellAnim(p->res_res.f24);
    CLACT_ReleasePalette(p->res_res.f14);
    CLACT_ReleaseCharacter(p->res_res.f10);
    CLACT_ReleaseCellAnim(p->res_res.f18);
    CLACT_ReleasePalette(p->sub.f8);
    CLACT_ReleaseCharacter(p->sub.f4);
    CLACT_ReleaseCellAnim(p->sub.fC);
    CLACT_ReleaseCharacter(p->sub.f28);
    CLACT_ReleaseCellAnim(p->sub.f30);
    CLACT_DeleteUnit((struct Bank *)(p->sub.f0));
    p->sub.f0 = 0;
    CLACT_ExitSystem();
}

/*
 * Decrement the u16 counter at +0x36 when it is non-zero.
 */
void WORLDTRADE_DecrementTimer(Work *p)
{
    u16 v = p->f36;

    if (v != 0) {
        p->f36 = v - 1;
    }
}

/*
 * Set the u16 flag at +0xeb2 and clear the one at +0xeb0.
 */
void WORLDTRADE_ClearSelectedSpecies(Work *p)
{
    p->xEB2 = 1;
    p->species = 0;
}

/*
 * blocker resolved: 0x020056BC was matched in arm9 (src/matched/
 * func_020056BC.c, shard pkt_020056BC); the call now attests as `matched`.
 * All 32 bytes are right.
 *
 * Start a frame with the 0x48-byte object held at +0xd40 and keep the result at +0xdf8.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/WORLDTRADE_CreateTimeIcon.c --func WORLDTRADE_CreateTimeIcon  *       --addr 0x021F4FA4 --region ov135 --thumb --cc dsi/1.1p1 --diff
 */
void WORLDTRADE_CreateTimeIcon(Work *p)
{
    p->xDF8 = (u32)TIME_ICON_Create((void *)func_020056BC(), (void *)(p->frame),
                                        0xf, 0x10, 0x48);
}

void WORLDTRADE_DeleteTimeIcon(Work *p)
{
    if (p->xDF8 != 0) {
        TIME_ICON_Delete((u8 *)(p->xDF8));
        p->xDF8 = 0;
        BMP_WIN_MakeScreen((struct Cfg *)(p->frame));
        func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)(p->frame)));
    }
}

void WORLDTRADE_SetActorPos(u32 a, u32 b, u32 c)
{
    u16 t[2];

    t[0] = b;
    t[1] = c;
    CLACT_AddActorSurfacePos((struct Obj *)a, (const struct Vec2 *)t, 0);
}

/*
 * Pick the 0x04000050 or 0x04001050 hardware register from the flag and write the 0x1e/-7 pair.
 */
void WORLDTRADE_SetBrightnessIn(u32 x)
{
    if (x != 0) {
        func_0207D658(0x04000050, 0x1e, -7);
    } else {
        func_0207D658(0x04001050, 0x1e, -7);
    }
}

/*
 * Pick the 0x04000050 or 0x04001050 hardware register from the flag and write the 0x1b/-7 pair.
 */
void WORLDTRADE_SetBrightnessOut(u32 x)
{
    if (x != 0) {
        func_0207D658(0x04000050, 0x1b, -7);
    } else {
        func_0207D658(0x04001050, 0x1b, -7);
    }
}

/*
 * Clear the two display control registers.
 */
void WORLDTRADE_ClearBlendRegs(void)
{
    *(u16 *)0x04000050 = 0;
    *(u16 *)0x04001050 = 0;
}

void WORLDTRADE_ClearAndShowPlanes(Work *p)
{
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    WORLDTRADE_SetupGraphics(p);
    func_0203F8F4(0x48);
    BMP_WIN_Init(0x48);
    {
        struct DispConfig_021F4580 c = tbl_02202BB8;

        func_0203FC28(&c);
    }
    WORLDTRADE_SetupWindowPlanes();
    *(vu16_021F5074 *)0x04000050 = 0;
    *(vu16_021F5074 *)0x04001050 = 0;
    if (p->vblank_p == 0) {
        p->vblank_p = func_020056A0(WORLDTRADE_VBlankTask, p, 0);
    }
}

void WORLDTRADE_ExitPlanes(Work *p)
{
    if (p->vblank_p != 0) {
        func_02030EAC(p->vblank_p);
        p->vblank_p = 0;
    }
    *(vu16_021F50EC *)0x04000050 = 0;
    *(vu16_021F50EC *)0x04001050 = 0;
    WORLDTRADE_ReleaseGraphics(p);
    BMP_WIN_Exit();
    func_0203F9B4();
    *(vu32_021F4D50 *)0x04000000 &= 0xFFFF1FFF;
    *(vu32_021F4D50 *)0x04001000 &= 0xFFFF1FFF;
}

void WORLDTRADE_CancelSave(Work *p)
{
    GAME_DATA_SaveCancel(func_020120F4((const struct Ctx *)p->ctx->f40));
    func_0200F7C0(0x29);
}
