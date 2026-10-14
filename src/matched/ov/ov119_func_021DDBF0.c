/*
 * function: POKETRADE_NEGO_StepResolveReplies
 * address:  0x021DDBF0
 * packet:   pkt_ov119_021DDBF0
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
 *   func_021DD140  0x021DD140  thumb  ov119
 *   POKETRADE_PROC_IsNetSession  0x021D8A24  thumb  ov119
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   POKETRADE_NEGO_CheckCancelTouch  0x021DD24C  thumb  ov119
 *   POKETRADE_NEGO_CloseCancelMenu  0x021DD294  thumb  ov119
 *   func_021DD080  0x021DD080  thumb  ov119
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   func_021DA76C  0x021DA76C  thumb  ov119
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   POKETRADE_SAVE_OpenMessageWindowTop  0x021E1024  thumb  ov119
 *   POKETRADE_NEGO_StepWaitReplyKey  0x021DDB90  thumb  ov119
 */
#include "../include/Obj00001.h"

typedef unsigned int u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
struct MsgBank;
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern int func_021DD140(char *p);
extern int POKETRADE_PROC_IsNetSession(void *p);
struct Link;
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *p, unsigned int lo, unsigned int hi);
extern int POKETRADE_NEGO_CheckCancelTouch(char *p);
extern void POKETRADE_NEGO_CloseCancelMenu(char *p, int a, int b);
extern void func_021DD080(void *a, void *b, void *c);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void func_021DA76C(void *p);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *p);
extern void POKETRADE_NEGO_StepWaitReplyKey(unsigned char *p);

void POKETRADE_NEGO_StepResolveReplies(char *p)
{
    int a, b, c, d, m;
    a = GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
    b = 1 - a;
    if (POKETRADE_SAVE_IsMessagePrintDone(p) == 0) return;
    if (func_021DD140(p) == 0) return;
    if (POKETRADE_PROC_IsNetSession(p) != 0 && GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1D, 8) == 0) {
        POKETRADE_NEGO_CheckCancelTouch(p);
        return;
    }
    POKETRADE_NEGO_CloseCancelMenu(p, 0, 0);
    c = (unsigned char)(p + a)[0x11E0];
    if (c == 13 && (unsigned char)(p + b)[0x11E0] == 13) {
        func_021DD080((void *)((u32)GFL_NET_HANDLE_GetCurrentHandle()), (void *)13, p);
        POKETRADE_PROC_SetStep(p, (int)func_021DA76C);
        return;
    }
    d = (unsigned char)(p + b)[0x11E0];
    if (d == 5) m = 0x61;
    else if (c == 5) m = 0x62;
    else if (d == 7) m = 0x63;
    else if (c == 7) m = 0x64;
    else if (d == 8) m = 0x64;
    else if (c == 8) m = 0x63;
    else if (d == 6) m = 0x61;
    else if (c == 6) m = 0x6F;
    else if (d == 14) m = 0x97;
    else if (c == 14) m = 0x96;
    MSGDATA_ReadString(((struct Obj00001 *)p)->f720, m, ((struct Obj00001 *)p)->f738);
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    p[0x11E0] = 0;
    p[0x11E1] = 0;
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepWaitReplyKey);
}
