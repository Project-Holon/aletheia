/*
 * function: GTSNEGO_DISP_Step
 * address: 0x021D5D74
 * packet: pkt_ov120_021D5D74
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker resolved: +0x2a calls verified unlabelled Thumb ov067 0x021B6498.
 * symbols:
 *   func_0200FB24 0x0200FB24 thumb
 *   GTSNEGO_DISP_GetTouchbar 0x021D6988 thumb ov120
 *   TOUCHBAR_IsBusy 0x021B6498 thumb ov067
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   GTSNEGO_DISP_DrawSystem 0x021D5F98 thumb ov120
 *   GTSNEGO_MSG_Main 0x021D7858 thumb ov120
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   GTSNEGO_DISP_ResetScreen 0x021D5BEC thumb ov120
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   func_0200F7DC 0x0200F7DC thumb
 */
#include "../include/Obj01056.h"
#include "../include/Obj22837.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_0200FB24(void);
extern u32 GTSNEGO_DISP_GetTouchbar(u8 *p);
extern int TOUCHBAR_IsBusy(u8 *p);
extern void APP_TASKMENU_WIN_Update(u8 *p);
extern void APP_TASKMENU_UpdateMenu(void *);
extern void GTSNEGO_DISP_DrawSystem(u8 *p);
extern void GTSNEGO_MSG_Main(u8 *p);
extern int GFL_NET_GetRunState(void);
extern int DWC_RAPCOMMON_HandleNetError(int a0, int a1);
extern void GTSNEGO_DISP_ResetScreen(u8 *);
extern void WIPE_SetBrightnessFadeOut(u32, u32);
extern void func_0200F7DC(void);
int GTSNEGO_DISP_Step(int a, int b, int c, u8 *p)
{
    void (*callback)(u8 *) = *(void (**)(u8 *))p;
    int result = 1;
    if (callback) {
        if (func_0200FB24() == 0)
            callback(p);
        result = 0;
    }
    if (((struct Obj01056 *)p)->f34) {
        void *q = (void *)GTSNEGO_DISP_GetTouchbar(((struct Obj01056 *)p)->f3C);
        if (q == 0 || TOUCHBAR_IsBusy(q) == 0)
            APP_TASKMENU_WIN_Update(((struct Obj01056 *)p)->f34);
    }
    if (((struct Obj01056 *)p)->f38)
        APP_TASKMENU_UpdateMenu(((struct Obj01056 *)p)->f38);
    GTSNEGO_DISP_DrawSystem(((struct Obj01056 *)p)->f3C);
    GTSNEGO_MSG_Main(((struct Obj01056 *)p)->f40);
    if (GFL_NET_GetRunState()) {
        if (func_0200FB24()) {
            switch (DWC_RAPCOMMON_HandleNetError(1, 1)) {
            case 0: break;
            case 1:
            case 4:
                GTSNEGO_DISP_ResetScreen(p);
                break;
            case 2:
                ((struct Obj22837 *)(*(u8 * *)&((struct Obj01056 *)p)->f48))->f1B0 = 0;
                result = 1;
                WIPE_SetBrightnessFadeOut(0, 0);
                WIPE_SetBrightnessFadeOut(1, 0);
                break;
            case 3:
                func_0200F7DC();
                break;
            }
        }
    } else if (func_0200FB24()) {
        result = 1;
    }
    return result;
}
