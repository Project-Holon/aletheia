/*
 * function: func_021B6448
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
 *   func_021B6268 0x021B6268 thumb ov179
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_021B6248 0x021B6248 thumb ov179
 *   func_021B6220 0x021B6220 thumb ov179
 */
#include "../include/Obj14387.h"
typedef unsigned int   u32;
extern u32 WIPE_SYS_EndCheck(void); extern int GFL_USE_IsBgmFading(void); extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void func_021B6268(char *); extern void ARC_TOOL_DeleteHandle(void *); extern void func_021B6248(char *); extern void func_021B6220(void);
int func_021B6448(char *p) {
 if(WIPE_SYS_EndCheck()==0) return 1;
 if(GFL_USE_IsBgmFading()==1) return 1;
 GFL_USE_CancelChangeAndStopBgm();
 if(((struct Obj14387 *)p)->f6058==1) { func_021B6268(p); ARC_TOOL_DeleteHandle(((struct Obj14387 *)p)->f4); func_021B6248(p); func_021B6220(); }
 return 6;
}
