/*
 * function: POKETRADE_NEGO_StepResolveConfirm
 * address:  0x021DDF74
 * packet:   pkt_ov119_021DDF74
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   POKETRADE_SAVE_IsMessagePrintDone  0x021E12AC  thumb  ov119
 *   POKETRADE_PROC_TickWifiTimer  0x021DD140  thumb  ov119
 *   POKETRADE_PROC_IsNetSession  0x021D8A24  thumb  ov119
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   POKETRADE_NEGO_CheckCancelTouch  0x021DD24C  thumb  ov119
 *   POKETRADE_NEGO_CloseCancelMenu  0x021DD294  thumb  ov119
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   POKETRADE_PROC_GetSideMon  0x021D8FA4  thumb  ov119
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   POKETRADE_SAVE_OpenMessageWindowTop  0x021E1024  thumb  ov119
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_PROC_ClearNetAutoExit  0x021D89CC  thumb  ov119
 *   POKETRADE_PROC_StepBeginWipeOut  0x021D9434  thumb  ov119
 *   POKETRADE_NEGO_StepOpenConfirmMenu  0x021DDF28  thumb  ov119
 *   POKETRADE_NEGO_StepWaitMessageThenWipe  0x021DE8C0  thumb  ov119
 */
#include "../include/Obj01251.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
struct MsgBank;
struct WordSet;
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern int POKETRADE_PROC_TickWifiTimer(char *p);
extern int POKETRADE_PROC_IsNetSession(void *p);
struct Link;
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *h, u32 a, u32 b);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *h, u32 a, u32 b);
extern int POKETRADE_NEGO_CheckCancelTouch(char *p);
extern void POKETRADE_NEGO_CloseCancelMenu(char *p, int a, int b);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void *POKETRADE_PROC_GetSideMon(void *p, int idx);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *p);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void POKETRADE_PROC_ClearNetAutoExit(char *p);
extern void POKETRADE_PROC_StepBeginWipeOut(void *p);
extern void POKETRADE_NEGO_StepOpenConfirmMenu(char *p);
extern void POKETRADE_NEGO_StepWaitMessageThenWipe(char *p);

void POKETRADE_NEGO_StepResolveConfirm(char *p)
{
    int a, b, c, i, m;
    a = GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
    b = 1 - a;
    if (POKETRADE_SAVE_IsMessagePrintDone(p) == 0) return;
    if (POKETRADE_PROC_TickWifiTimer(p) == 0) return;
    if (POKETRADE_PROC_IsNetSession(p) != 0 && GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1C, 8) == 0) {
        POKETRADE_NEGO_CheckCancelTouch(p);
        return;
    }
    i = 0;
    POKETRADE_NEGO_CloseCancelMenu(p, 0, 0);
    c = (unsigned char)(p + a)[0x11E0];
    if (c == 11 && (unsigned char)(p + b)[0x11E0] == 11) {
        MSGDATA_ReadString(((struct Obj01251 *)p)->f720, 0x92, ((struct Obj01251 *)p)->f73C);
        do {
            func_0201EEF4(((struct Obj01251 *)p)->f724, i, POKETRADE_PROC_GetSideMon(p, i));
            i++;
        } while (i < 2);
        func_0201F250(((struct Obj01251 *)p)->f724, ((struct Obj01251 *)p)->f738, ((struct Obj01251 *)p)->f73C);
        POKETRADE_SAVE_OpenMessageWindowTop(p);
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepOpenConfirmMenu);
        return;
    }
    if ((unsigned char)(p + b)[0x11E0] == 12) {
        (p + 0x11E0)[0x11] = 0x78;
        m = 0x93;
        if (((struct Obj01251 *)p)->f118C == 3 && (u8)p[0x11FA] >= 3) {
            POKETRADE_PROC_ClearNetAutoExit(p);
            POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepBeginWipeOut);
            return;
        }
    } else if (c == 12) {
        (p + 0x11E0)[0x11] = 0x78;
        m = 0x95;
        if (((struct Obj01251 *)p)->f118C == 3 && (u8)p[0x11FA] >= 3) {
            POKETRADE_PROC_ClearNetAutoExit(p);
            POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepBeginWipeOut);
            return;
        }
    }
    MSGDATA_ReadString(((struct Obj01251 *)p)->f720, m, ((struct Obj01251 *)p)->f738);
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    p[0x11E0] = 0;
    p[0x11E1] = 0;
    if (POKETRADE_PROC_IsNetSession(p) != 0) {
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x19, 8);
    }
    ((struct Obj01251 *)p)->fF2C = 0;
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepWaitMessageThenWipe);
}
