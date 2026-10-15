/*
 * function: GTSNEGO_DISP_StartWipe
 * address: 0x021D44AC
 * packet: pkt_ov120_021D44AC
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_Start 0x0202208C thumb
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_WaitWipeDone 0x021D4490 thumb ov120
 */
#include "../include/Obj13928.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_WaitWipeDone(int p);
void GTSNEGO_DISP_StartWipe(int *p) {
    if (--((struct Obj13928 *)p)->f14<=0) {
        WIPE_SYS_Start(0,0,0,0,6,1,((struct Obj13928 *)p)->fC);
        GTSNEGO_DISP_SetStateCallback(p,(int)((void (*)(void *))GTSNEGO_DISP_WaitWipeDone),0x21e);
    }
}
