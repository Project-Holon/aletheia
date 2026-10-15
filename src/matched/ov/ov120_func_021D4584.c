/*
 * function: GTSNEGO_DISP_ShowTradeConfirm
 * address: 0x021D4584
 * packet: pkt_ov120_021D4584
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GTSNEGO_MSG_PrintSummary 0x021D880C thumb ov120
 *   GTSNEGO_MSG_SetIdleAnim 0x021D74B0 thumb ov120
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_WaitTradeStart 0x021D4544 thumb ov120
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 */
#include "../include/Obj04484.h"
#include "../include/Obj06433.h"
typedef unsigned char u8;
extern int GFL_NET_GetRunState(void);
typedef unsigned int   u32;
struct Sub0200852CObj;
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern void GTSNEGO_MSG_PrintSummary(char *p, void *q, u32 n);
extern void GTSNEGO_MSG_SetIdleAnim(u8 *p, int n);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_WaitTradeStart(int *a);
void GTSNEGO_DISP_ShowTradeConfirm(u8 *p)
{
    u8 *q = *(u8 * *)&((struct Obj06433 *)p)->f48;
    int value;
    int mode = 2;
    if (GFL_NET_GetRunState() == 0) {
        value = (int)GAME_DATA_GetMyStatus((void *)(((struct Obj04484 *)q)->f0));
    } else {
        value = ((struct Obj04484 *)q)->f18;
        mode = ((struct Obj06433 *)p)->f17C;
        *(int *)(q + ((struct Obj04484 *)q)->f1AC * 4 + 0x1c) = func_02008530((const struct Sub0200852CObj *)value);
        ((struct Obj04484 *)q)->f1AC = ((struct Obj04484 *)q)->f1AC + 1;
        if (((struct Obj04484 *)q)->f1AC >= 100)
            ((struct Obj04484 *)q)->f1AC = 0;
    }
    GTSNEGO_MSG_PrintSummary((char *)(((struct Obj06433 *)p)->f40), (void *)value, mode);
    GTSNEGO_MSG_SetIdleAnim((u8 *)(((struct Obj06433 *)p)->f3C), func_02008554((const struct Sub0200852CObj *)value));
    ((struct Obj06433 *)p)->f14 = 0xb4;
    GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_WaitTradeStart, 0x265);
}
