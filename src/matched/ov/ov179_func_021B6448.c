/*
 * function: CDEMO_SCENE_Destroy
 * address: 0x021B6448
 * packet: pkt_ov179_021B6448
 * region: ov179
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   CDEMO_MAIN_StopTask 0x021B6268 thumb ov179
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CDEMO_MAIN_Noop 0x021B6248 thumb ov179
 *   CDEMO_MAIN_HidePlane 0x021B6220 thumb ov179
 */
#include "../include/Obj14387.h"
typedef unsigned int   u32;
extern u32 WIPE_SYS_EndCheck(void); extern int GFL_USE_IsBgmFading(void); extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void CDEMO_MAIN_StopTask(char *); extern void ARC_TOOL_DeleteHandle(void *); extern void CDEMO_MAIN_Noop(char *); extern void CDEMO_MAIN_HidePlane(void);
int CDEMO_SCENE_Destroy(char *p) {
 if(WIPE_SYS_EndCheck()==0) return 1;
 if(GFL_USE_IsBgmFading()==1) return 1;
 GFL_USE_CancelChangeAndStopBgm();
 if(((struct Obj14387 *)p)->f6058==1) { CDEMO_MAIN_StopTask(p); ARC_TOOL_DeleteHandle(((struct Obj14387 *)p)->f4); CDEMO_MAIN_Noop(p); CDEMO_MAIN_HidePlane(); }
 return 6;
}
