/*
 * function: GTSNEGO_DISP_ShowTradeReady
 * address: 0x021D44EC
 * packet: pkt_ov120_021D44EC
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021D8904 0x021D8904 data a2
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GTSNEGO_MSG_CreateDraw 0x021D8430 thumb ov120
 *   GTSNEGO_MSG_PrintDraw 0x021D8484 thumb ov120
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_StartWipe 0x021D44AC thumb ov120
 */
#include "../include/Obj08075.h"
typedef unsigned short u16;
typedef struct { u16 v[4]; } Halfwords;
extern const Halfwords d_021D8904;
extern int GFL_NET_GetRunState(void);
typedef unsigned char  u8;
extern void GTSNEGO_MSG_CreateDraw(u8 *p, void *q);
struct Obj05353;
extern void GTSNEGO_MSG_PrintDraw(struct Obj05353 *p, void *n);
extern void GTSNEGO_DISP_SetStateCallback(int, void (*)(int), int);
extern void GTSNEGO_DISP_StartWipe(int *p);
void GTSNEGO_DISP_ShowTradeReady(int a)
{
    Halfwords table = d_021D8904;
    const Halfwords *p = &table;
    if (GFL_NET_GetRunState() != 0)
        p = (const Halfwords *)(a + 0x174);
    ((struct Obj08075 *)a)->f14 = 0xb4;
    GTSNEGO_MSG_CreateDraw((u8 *)(((struct Obj08075 *)a)->f40), (void *)(((struct Obj08075 *)a)->f3C));
    GTSNEGO_MSG_PrintDraw((struct Obj05353 *)(((struct Obj08075 *)a)->f40), (void *)p);
    GTSNEGO_DISP_SetStateCallback(a, (void (*)(int))GTSNEGO_DISP_StartWipe, 0x232);
}
