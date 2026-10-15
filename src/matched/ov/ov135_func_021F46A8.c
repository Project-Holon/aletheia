/*
 * function: WORLDTRADE_ProcMain
 * address: 0x021F46A8
 * packet: pkt_ov135_021F46A8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   DWC_UpdateConnection 0x0205D074 arm
 *   WORLDTRADE_GetWifiLinkLevel 0x021F4EB4 thumb ov135
 *   GFL_NET_WM_ICON_EasySetLevel 0x020370F4 arm
 *   DPW_TR_Main 0x021C7C1C arm ov114
 *   PROCSYS_Main 0x02031330 arm
 *   func_02030D28 0x02030D28 arm
 *   WORLDTRADE_ADAPTER_UpdatePrinter 0x02202770 thumb ov135
 *   WORLDTRADE_SetupWindowPlanes 0x021F49A8 thumb ov135
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   WORLDTRADE_SUBLCD_CreateActors 0x021FF6A4 thumb ov135
 *   WORLDTRADE_SUBLCD_UpdateSlotPalettes 0x021FFB20 thumb ov135
 *   WORLDTRADE_DecrementTimer 0x021F4F84 thumb ov135
 *   CLACT_DrawSystem 0x0204A600 arm
 *   d_02203A80 0x02203A80 data a4
 */
#include "../include/Obj02853.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { int (*init)(u8 *, int); int (*update)(u8 *, int); int (*finish)(u8 *, int); } Handler;
extern const Handler d_02203A80[];
extern int GFL_NET_GetRunState(void);
struct Ctx;
extern int DWC_UpdateConnection(void);
extern int WORLDTRADE_GetWifiLinkLevel(void);
extern u32 GFL_NET_WM_ICON_EasySetLevel(u32);
extern void DPW_TR_Main(void);
extern u32 PROCSYS_Main(void *);
extern void func_02030D28(struct Ctx *c);
extern void WORLDTRADE_ADAPTER_UpdatePrinter(void *);
extern void WORLDTRADE_SetupWindowPlanes(void);
extern u32 WIPE_SYS_EndCheck(void);
extern void WORLDTRADE_SUBLCD_CreateActors(u8 *);
extern void WORLDTRADE_SUBLCD_UpdateSlotPalettes(u8 *, int, int);
extern void WORLDTRADE_DecrementTimer(u8 *);
extern void CLACT_DrawSystem(void *);
int WORLDTRADE_ProcMain(void *unused0, int *state, void *unused2, u8 *p)
{
    if (GFL_NET_GetRunState() != 0) {
        DWC_UpdateConnection();
        GFL_NET_WM_ICON_EasySetLevel(WORLDTRADE_GetWifiLinkLevel());
    }
    DPW_TR_Main();
    ((struct Obj02853 *)p)->f12F4 = PROCSYS_Main(((struct Obj02853 *)p)->f12F0);
    func_02030D28(((struct Obj02853 *)p)->fF94);
    WORLDTRADE_ADAPTER_UpdatePrinter(p + 0xfa0);
    switch (*state) {
    case 0:
        *state = d_02203A80[*(u32 *)(p + 16)].init(p, *state);
        WORLDTRADE_SetupWindowPlanes();
        break;
    case 1:
        if (WIPE_SYS_EndCheck() != 0) *state = 2;
        break;
    case 2:
        *state = d_02203A80[*(u32 *)(p + 16)].update(p, *state);
        break;
    case 3:
        if (WIPE_SYS_EndCheck() != 0) {
            *state = d_02203A80[*(u32 *)(p + 16)].finish(p, *state);
            if (((struct Obj02853 *)p)->fB8 != 0) {
                WORLDTRADE_SUBLCD_CreateActors(p);
                WORLDTRADE_SUBLCD_UpdateSlotPalettes(p, ((struct Obj02853 *)p)->fD0, 0);
                ((struct Obj02853 *)p)->fB8 = 0;
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
    if (*(u32 *)&((struct Obj02853 *)p)->fBC0 != 0) CLACT_DrawSystem(((struct Obj02853 *)p)->fBC0);
    if (((struct Obj02853 *)p)->f12E8 > 0) ((struct Obj02853 *)p)->f12E8 -= 1;
    return 0;
}
