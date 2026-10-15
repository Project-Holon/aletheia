/*
 * function: POKETRADE_PROC_StepIntro
 * address: 0x021D9C00
 * packet: pkt_ov119_021D9C00
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   POKETRADE_NEGO_CheckCancelTouch 0x021DD24C thumb ov119
 *   POKETRADE_NEGO_CloseCancelMenu 0x021DD294 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   POKETRADE_SAVE_ShowTimeIcon 0x021E1030 thumb ov119
 *   POKETRADE_PROC_StepShowTradeSummary 0x021D9AD8 thumb ov119
 *   POKETRADE_PROC_StepStartSync20 0x021D9BC4 thumb ov119
 *   POKETRADE_PROC_StepShowWaitMessageA 0x021DAEF0 thumb ov119
 */
#include "../include/Obj03772.h"
#include "../include/Obj22727.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern int POKETRADE_PROC_IsNetSession(void *p);
struct Link;
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *h, u32 a, u32 b);
extern int POKETRADE_NEGO_CheckCancelTouch(char *p);
extern void POKETRADE_NEGO_CloseCancelMenu(char *p, int a, int b);
extern void POKETRADE_PROC_SetStep(void *p, int next);
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *p);
extern void POKETRADE_SAVE_ShowTimeIcon(char *p);
extern void POKETRADE_PROC_StepShowTradeSummary(char *p);
extern void POKETRADE_PROC_StepStartSync20(char *p);
extern void POKETRADE_PROC_StepShowWaitMessageA(char *p);

void POKETRADE_PROC_StepIntro(char *p)
{
    int cmd;
    u32 other;
    u32 me;
    u32 a;

    me = GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle());
    other = 1 - me;
    if (POKETRADE_PROC_IsNetSession(p) == 0) {
        me = 0;
        other = 1;
    }
    if (POKETRADE_PROC_IsNetSession(p) != 0 && GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1a, 8) == 0) {
        POKETRADE_NEGO_CheckCancelTouch(p);
        return;
    }
    POKETRADE_NEGO_CloseCancelMenu(p, 1, 1);
    a = ((u8 *)p + me)[0x11e0];
    if (a == 1 && ((u8 *)p + other)[0x11e0] == 1) {
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepShowTradeSummary);
        return;
    }
    if (a == 4 && ((u8 *)p + other)[0x11e0] == 4) {
        ((struct Obj22727 *)(*(char * *)&((struct Obj03772 *)p)->f8))->f8 = 3;
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj03772 *)p)->f720), 0x8d, (void *)(((struct Obj03772 *)p)->f738));
        POKETRADE_SAVE_OpenMessageWindowTop(p);
        POKETRADE_SAVE_ShowTimeIcon(p);
        ((struct Obj03772 *)p)->fF2C = 0;
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepStartSync20);
        return;
    }
    if (((u8 *)p + other)[0x11e0] == 4)
        cmd = 0x61;
    else if (a == 4)
        cmd = 0x66;
    MSGDATA_ReadString((struct MsgBank *)(((struct Obj03772 *)p)->f720), cmd, (void *)(((struct Obj03772 *)p)->f738));
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    p[0x11e0] = 0;
    p[0x11e1] = 0;
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepShowWaitMessageA);
}
