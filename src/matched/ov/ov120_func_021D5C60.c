/*
 * function: GTSNEGO_DISP_Create
 * address: 0x021D5C60
 * packet: pkt_ov120_021D5C60
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware halfword registers written at 0x021D5C78 and 0x021D5C7E.
 * prototype: 0203064C r2 explicitly loaded despite two-arg definition;
 * 0203159C r0 allocation result used despite void matched definition.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GTSNEGO_DISP_CreateMsgSystem 0x021D5E88 thumb ov120
 *   GTSNEGO_MSG_Create 0x021D7724 thumb ov120
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   d_021D88EC 0x021D88EC data a4
 *   func_0200F7E8 0x0200F7E8 thumb
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_ShowPartySelect 0x021D588C thumb ov120
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb  arm9
 *   GAME_DATA_GetField1A0  0x0201283C  thumb  arm9
 */
#include "../include/Obj01401.h"
#include "../include/Obj06435.h"
#include "../include/Obj22836.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *, int, u32);
extern u8 *GTSNEGO_DISP_CreateMsgSystem(u32, void *);
struct Big;
struct BigObj;
extern char *GTSNEGO_MSG_Create(u32 heap, u32 n);
extern void WIPE_SetBrightnessFadeOut(u32, u32);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u32 GAME_DATA_GetField1A0(const struct BigObj *p);
extern u8 *func_02012944(void *p);
struct Sub0200852CObj;
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern int GFL_NET_GetRunState(void);
extern void GFL_NET_COMMAND_AddCommandTable(u32, u32, u32, u32);
extern const u32 d_021D88EC[];
extern void WIPE_SYS_Start(void *, u32, u32, u32, u32, u32, u32);
extern void GFL_USE_CancelChangeAndPlayBgm(u32, u32);
extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);
extern void func_0200F7E8(u32 value);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_ShowPartySelect(u8 *);
int GTSNEGO_DISP_Create(void *a, int unused, u8 *q)
{
    u8 *p;
    int zero = 0;
    GFL_HEAP_CreateChildHeap(1, 0x1f, 0x38000);
    *(volatile u16 *)0x04000050 = zero;
    *(volatile u16 *)0x04001050 = zero;
    WIPE_SetBrightnessFadeOut(0, 0);
    WIPE_SetBrightnessFadeOut(1, 0);
    p = PROCSYS_AllocProcWork(a, 0x1b8, 0x1f);
    MI_CpuFill8(p, 0, 0x1b8);
    ((struct Obj01401 *)p)->fC = 0x1f;
    *(u8 * *)&((struct Obj01401 *)p)->f48 = q;
    ((struct Obj01401 *)p)->f3C = GTSNEGO_DISP_CreateMsgSystem(((struct Obj01401 *)p)->fC, ((struct Obj06435 *)q)->f0);
    ((struct Obj01401 *)p)->f40 = GTSNEGO_MSG_Create(((struct Obj01401 *)p)->fC, 0x28);
    ((struct Obj01401 *)p)->f2C = ((struct Obj06435 *)q)->f0;
    ((struct Obj01401 *)p)->f30 = GAME_DATA_GetSaveControl(((struct Obj06435 *)q)->f0);
    ((struct Obj01401 *)p)->f44 = GAME_DATA_GetField1A0(((struct Obj06435 *)q)->f0);
    ((struct Obj22836 *)(*(u8 * *)&((struct Obj01401 *)p)->f48))->f1B0 = 1;
    ((struct Obj01401 *)p)->f15C = zero;
    ((struct Obj01401 *)p)->f160 = 2;
    ((struct Obj01401 *)p)->f164 = 6;
    ((struct Obj01401 *)p)->f14C = func_02008530((const struct Sub0200852CObj *)func_02012944(((struct Obj06435 *)q)->f0));
    if (GFL_NET_GetRunState())
        GFL_NET_COMMAND_AddCommandTable(0x2200, (u32)d_021D88EC, 3, (u32)p);
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, ((struct Obj01401 *)p)->fC);
    GFL_USE_CancelChangeAndPlayBgm(0x486, 0xffff);
    GFL_NET_RestartWithDefaultTimeout(1, ((struct Obj01401 *)p)->fC);
    func_0200F7E8(1);
    GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_ShowPartySelect, 0x96a);
    return 1;
}
