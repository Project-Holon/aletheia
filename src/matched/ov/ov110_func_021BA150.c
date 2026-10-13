/*
 * function: PMS_INPUT_VIEW_TaskFadeIn
 * address: 0x021BA150
 * packet: pkt_ov110_021BA150
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 */
#include "../include/Obj10265.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void WIPE_SYS_Start(void *, u32, u32, u32, u32, u32, u32);
extern u32 WIPE_SYS_EndCheck(void);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskFadeIn(int unused, u8 *p) {
    switch (((struct Obj10265 *)p)->f14) {
    case 0:
        WIPE_SYS_Start(0, 1, 1, 0, 5, 1, 42);
        ++((struct Obj10265 *)p)->f14;
        break;
    case 1:
        if (WIPE_SYS_EndCheck()) ++((struct Obj10265 *)p)->f14;
        break;
    default:
        PMS_INPUT_VIEW_EndTask(p);
        break;
    }
}
