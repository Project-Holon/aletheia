/*
 * function: INTRUDE_COMM_VIEW_Create
 * address: 0x021D5370
 * packet: pkt_ov122_021D5370
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: 021D53BA reads hardware DISPCNT, 021D53C0 writes the update.
 * ABI: 0203159C leaves the allocator result in r0 (020315BC/15C0); caller uses it.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   GX_DispOn 0x0207D46C arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   INTRUDE_COMM_VIEW_VBlankHandler 0x021D5368 thumb ov122
 *   INTRUDE_COMM_VIEW_SetupBackgrounds 0x021D424C thumb ov122
 *   INTRUDE_COMM_VIEW_CreateResources 0x021D48D8 thumb ov122
 *   TCBL_Create 0x0203101C arm
 *   func_0207D63C 0x0207D63C arm
 *   INTRUDE_COMM_VIEW_InitMenu 0x021D4A64 thumb ov122
 *   INTRUDE_COMM_VIEW_SetCallback 0x021D4244 thumb ov122
 *   GFL_NET_GetInitParam 0x0203D798 arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   INTRUDE_COMM_VIEW_StorePeerRecord 0x021D5278 thumb ov122
 *   NET_WHPIPE_SetNotifyCallback 0x02178118 thumb ov014
 *   UI_SetInputMode 0x020355D8 arm
 *   data_021D58B0 0x021D58B0 data a4
 *   data_021D5770 0x021D5770 data a4
 *   data_021D5740 0x021D5740 data a4
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 *   WORDSET_Create  0x0201EC74  thumb  arm9
 *   GF_FONT_InitTextColor  0x0201DD60  thumb  arm9
 */
#include "../include/Obj00073.h"
#include "../include/Obj13967.h"
#include "../include/Obj22934.h"
#include "../include/Obj22935.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 v[4]; } Display;
extern u32 data_021D58B0[], data_021D5740[];
extern const Display data_021D5770;
extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *, int, u32);
extern void BG_SYS_SetLcdSwap(u32);
extern void GX_DispOn(void);
extern void BG_SYS_Create(u16);
extern void BMP_WIN_Init(u16);
extern void GF_FONT_InitTextColor(void);
struct Cfg;
struct DispConfig;
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void BG_SYS_SetSubVisiblePlanes(u32);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
struct Bank;
struct R;
struct Tcbl;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void INTRUDE_COMM_VIEW_VBlankHandler(void);
extern void *func_020056A0(u32, void *, u32);
extern void INTRUDE_COMM_VIEW_SetupBackgrounds(void *);
extern void INTRUDE_COMM_VIEW_CreateResources(char *);
struct WordSet;
extern struct WordSet *WORDSET_Create(u32 n, u32 size, u16 heap);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_0207D63C(void *, u32, u32, u32, u32);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void INTRUDE_COMM_VIEW_InitMenu(char *);
extern void INTRUDE_COMM_VIEW_SetCallback(void *p, u32 a, int a2);
extern void *GFL_NET_GetInitParam(void);
extern void GFL_NET_RefreshWmIconAtTopRight(u32, u32);
extern int GFL_NET_GetRunState(void);
extern void INTRUDE_COMM_VIEW_StorePeerRecord(void *, const char *, int, int);
extern void NET_WHPIPE_SetNotifyCallback(u32, u32);
extern void UI_SetInputMode(u8);
int INTRUDE_COMM_VIEW_Create(void *owner, void *unused, char *args)
{
    char *p;
    Display display;
    GFL_HEAP_CreateChildHeap(1, 31, 0x18000);
    p = PROCSYS_AllocProcWork(owner, 0x3a8, 31);
    MI_CpuFill8(p, 0, 0x3a8);
    ((struct Obj00073 *)p)->fC = 31;
    ((struct Obj00073 *)p)->f350 = ((struct Obj13967 *)args)->f4;
    ((struct Obj00073 *)p)->f354 = ((struct Obj13967 *)args)->f0;
    BG_SYS_SetLcdSwap(1);
    *(volatile u32 *)0x04001000 |= 0x10000;
    GX_DispOn();
    BG_SYS_Create(((struct Obj00073 *)p)->fC);
    BMP_WIN_Init(((struct Obj00073 *)p)->fC);
    GF_FONT_InitTextColor();
    BG_SYS_SetVramBanks((const struct DispVram *)data_021D58B0);
    display = data_021D5770;
    BG_SYS_SetGraphicsMode((struct DispConfig *)(&display));
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    CLACT_InitSystem((const struct Cfg *)data_021D5740, (u32)data_021D58B0, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f30C = CLACT_CreateUnit(40, 0, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f310 = func_020056A0((u32)INTRUDE_COMM_VIEW_VBlankHandler, p, 0);
    INTRUDE_COMM_VIEW_SetupBackgrounds(p);
    INTRUDE_COMM_VIEW_CreateResources(p);
    ((struct Obj00073 *)p)->f48 = WORDSET_Create(11, 200, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f31C = TCBL_Create(((struct Obj00073 *)p)->fC, ((struct Obj00073 *)p)->fC, 1, 0);
    ((struct Obj00073 *)p)->f320 = PRINTSYS_QUE_Create((void *)(((struct Obj00073 *)p)->fC));
    ((struct Obj00073 *)p)->f340 = APP_TASKMENU_RES_Create(5, 13, *(u32 *)&((struct Obj00073 *)p)->f4C, ((struct Obj00073 *)p)->f320, ((struct Obj00073 *)p)->fC);
    func_0207D63C((void *)0x04001050, 4, 1, 15, 4);
    WIPE_SYS_Start((void *)4, 1, 1, 0, 6, 1, ((struct Obj00073 *)p)->fC);
    BG_SYS_SetSubVisiblePlanes(31);
    INTRUDE_COMM_VIEW_SetCallback(p, (u32)INTRUDE_COMM_VIEW_InitMenu, 0x6cb);
    *(char * *)&((struct Obj00073 *)p)->f344 = args;
    GFL_NET_GetInitParam();
    ((struct Obj22934 *)(*(char * *)&((struct Obj00073 *)p)->f344))->f10 = 1;
    ((struct Obj22935 *)(*(char * *)&((struct Obj00073 *)p)->f344))->fC = ((struct Obj00073 *)p)->f350;
    GFL_NET_RefreshWmIconAtTopRight(0, ((struct Obj00073 *)p)->fC);
    if (GFL_NET_GetRunState()) NET_WHPIPE_SetNotifyCallback((u32)INTRUDE_COMM_VIEW_StorePeerRecord, (u32)p);
    UI_SetInputMode(1);
    return 1;
}
