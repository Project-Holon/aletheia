/*
 * function: IRCBATTLEMENU_Init
 * address:  0x021978DC
 * packet:   pkt_ov021_021978DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BMP_WIN_Init  0x02045088  arm
 *   func_0201DD60  0x0201DD60  thumb
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   sVramBank     0x021DDB14  data   ov021  a4
 *   sGraphicsMode     0x021D4090  data   ov021  a4
 *   func_0203FC28  0x0203FC28  arm
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   gClActorInitParam     0x020A1448  data   a4
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   IRCBATTLEMENU_VBlankTask  0x021978D4  thumb  ov021
 *   func_020056A0  0x020056A0  thumb
 *   IRCBATTLEMENU_InitBgLayers  0x0219603C  thumb  ov021
 *   IRCBATTLEMENU_LoadMenuGraphics  0x02196538  thumb  ov021
 *   sIrcBattleMenuFileName     0x021DDBC4  data   ov021  a4
 *   func_02030734  0x02030734  arm
 *   TCBL_Create  0x0203101C  arm
 *   func_02028590  0x02028590  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb
 *   IRCBATTLEMENU_LoadActorResources  0x02196FFC  thumb  ov021
 *   IRCBATTLEMENU_CreateDecoration  0x0219749C  thumb  ov021
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   IRCBATTLEMENU_SeqSetupTopMenu  0x021966F0  thumb  ov021
 *   IRCBATTLEMENU_SetSeq  0x02196034  thumb  ov021
 *   func_02155A90  0x02155A90  thumb  ov010
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   func_0207D63C  0x0207D63C  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00150.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 w[4]; } Q16;

extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *, u32, u32);
extern void BG_SYS_Create(u16 heapId);
extern void BMP_WIN_Init(u16 heapId);
extern void func_0201DD60(void);
struct DispConfig;
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern u8 sVramBank[];
extern const Q16 sGraphicsMode;
extern void func_0203FC28(struct DispConfig *cfg);
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void BG_SYS_SetSubVisiblePlanes(u32);
extern u8 gClActorInitParam[];
struct Bank;
struct Cfg;
struct R;
struct Tcbl;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void IRCBATTLEMENU_VBlankTask(void);
extern u32 func_020056A0(void (*)(void), void *, u32);
extern void IRCBATTLEMENU_InitBgLayers(void *a0);
extern void IRCBATTLEMENU_LoadMenuGraphics(u8 *);
extern u8 sIrcBattleMenuFileName[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_02028590(u32, u32, u32, u32);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void IRCBATTLEMENU_LoadActorResources(u8 *);
extern void IRCBATTLEMENU_CreateDecoration(u8 *, u32, u32, u32, u32);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void IRCBATTLEMENU_SeqSetupTopMenu(u8 *p);
extern void IRCBATTLEMENU_SetSeq(u8 *, void (*)(void), u32);
struct Ctx;
extern u32 func_02155A90(u8 *);
extern void *ICA_ANIME_GetField1C(const struct Ctx *);
extern void func_0207D63C(u32, u32, u32, u32, u32);
extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);

int IRCBATTLEMENU_Init(struct Obj0203159C *a, u32 b, u32 c)
{
    u8 *w;

    GFL_HEAP_CreateChildHeap(1, 0x1f, 0x18000);
    w = PROCSYS_AllocProcWork(a, 0x308, 0x1f);
    MI_CpuFill8(w, 0, 0x308);
    ((struct Obj00150 *)w)->f10 = 0x1f;
    BG_SYS_Create(((struct Obj00150 *)w)->f10);
    BMP_WIN_Init(((struct Obj00150 *)w)->f10);
    func_0201DD60();
    BG_SYS_SetVramBanks((const struct DispVram *)sVramBank);
    {
        Q16 q = sGraphicsMode;
        func_0203FC28((struct DispConfig *)(&q));
    }
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    CLACT_InitSystem((const struct Cfg *)gClActorInitParam, (u32)sVramBank, ((struct Obj00150 *)w)->f10);
    ((struct Obj00150 *)w)->f26C = (u32)CLACT_CreateUnit(0x28, 0, ((struct Obj00150 *)w)->f10);
    ((struct Obj00150 *)w)->f268 = func_020056A0(IRCBATTLEMENU_VBlankTask, w, 0);
    IRCBATTLEMENU_InitBgLayers(w);
    IRCBATTLEMENU_LoadMenuGraphics(w);
    ((struct Obj00150 *)w)->f2EC = (unsigned int)func_02030734(((struct Obj00150 *)w)->f10, 0x200, 0, (const char *)sIrcBattleMenuFileName, 0x829);
    ((struct Obj00150 *)w)->f2F0 = (unsigned int)func_02030734(((struct Obj00150 *)w)->f10, 0x200, 0, (const char *)sIrcBattleMenuFileName, 0x82A);
    ((struct Obj00150 *)w)->f2B8 = (u32)TCBL_Create(((struct Obj00150 *)w)->f10, ((struct Obj00150 *)w)->f10, 2, 0);
    ((struct Obj00150 *)w)->f2A8 = func_02028590(0xf, 0, 1, ((struct Obj00150 *)w)->f10);
    ((struct Obj00150 *)w)->f2BC = PRINTSYS_QUE_Create((void *)(((struct Obj00150 *)w)->f10));
    ((struct Obj00150 *)w)->f2DC = (u32)APP_TASKMENU_RES_Create(5, 9, *(u32 *)&((struct Obj00150 *)w)->f2C, ((struct Obj00150 *)w)->f2BC, ((struct Obj00150 *)w)->f10);
    IRCBATTLEMENU_LoadActorResources(w);
    IRCBATTLEMENU_CreateDecoration(w, 0x39, 0x9a, 0, 10);
    IRCBATTLEMENU_CreateDecoration(w, 0xc8, 0x26, 1, 11);
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, ((struct Obj00150 *)w)->f10);
    IRCBATTLEMENU_SetSeq(w, (void (*)(void))IRCBATTLEMENU_SeqSetupTopMenu, 0x83B);
    ((struct Obj00150 *)w)->f2E4 = c;
    ((struct Obj00150 *)w)->f30 = (u32)ICA_ANIME_GetField1C((const struct Ctx *)func_02155A90((u8 *)((struct Obj00150 *)w)->f2E4));
    func_0207D63C(0x04001050, 4, 1, 0xf, 4);
    GFL_NET_RestartWithDefaultTimeout(0, ((struct Obj00150 *)w)->f10);
    BG_SYS_SetMainVisiblePlanes(0x13);
    BG_SYS_SetSubVisiblePlanes(0x17);
    func_0207D63C(0x04000050, 0x10, 3, 9, 0xe);
    return 1;
}
