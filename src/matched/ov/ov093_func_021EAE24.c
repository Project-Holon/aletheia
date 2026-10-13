/*
 * unit: yes
 * function: BTLV_CORE_ClearWaitWindow, BTLV_CORE_GetWaitState
 * address: 0x021EAE24
 * packet: pkt_ov093_021EAE24
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_SCU_ClearWaitWindow 0x021EE23C thumb ov093
 *   BTLV_SCU_GetWaitState 0x021EE25C thumb ov093
 */
#include "../include/Obj21577.h"
#include "../include/Obj21578.h"
typedef unsigned char u8;
struct Q;
extern void BTLV_SCU_ClearWaitWindow(struct Q *q);
extern int BTLV_SCU_GetWaitState(void *);
void BTLV_CORE_ClearWaitWindow(u8 *p)
{
    BTLV_SCU_ClearWaitWindow(((struct Obj21577 *)p)->f17C);
}
int BTLV_CORE_GetWaitState(u8 *p)
{
    return BTLV_SCU_GetWaitState(((struct Obj21578 *)p)->f17C);
}
