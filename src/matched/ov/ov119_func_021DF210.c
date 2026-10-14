/*
 * function: POKETRADE_NEGO_StepResolveFinalAgree
 * address: 0x021DF210
 * packet: pkt_ov119_021DF210
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   POKETRADE_NEGO_CheckCancelTouch 0x021DD24C thumb ov119
 *   POKETRADE_NEGO_CloseCancelMenu 0x021DD294 thumb ov119
 *   POKETRADE_NEGO_DrawOfferStatusLabel 0x021DD90C thumb ov119
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepBeginMonCheckWipe 0x021DF1C8 thumb ov119
 *   POKETRADE_NEGO_StepSendReady 0x021DEDBC thumb ov119
 *   POKETRADE_PROC_StepBeginWipeOut 0x021D9434 thumb ov119
 *   func_021DAEF0 0x021DAEF0 thumb ov119
 */
#include "../include/Obj00001.h"
#include "../include/Obj22747.h"
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_GetHandleNetID(struct Link *p);
struct Link;
extern unsigned GFL_NET_HANDLE_IsTimingSyncRange(struct Link *, unsigned, unsigned);
typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern int POKETRADE_PROC_IsNetSession(void *);
extern int POKETRADE_NEGO_CheckCancelTouch(char *p);
extern void POKETRADE_NEGO_CloseCancelMenu(char *p, int a, int b);
typedef unsigned char  u8;
extern void POKETRADE_NEGO_DrawOfferStatusLabel(u8 *p, int i, int msg, int force);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *);
extern void POKETRADE_PROC_SetStep(void *, int);
extern void POKETRADE_NEGO_StepBeginMonCheckWipe(void *);
extern void POKETRADE_NEGO_StepSendReady(void *);
extern void POKETRADE_PROC_StepBeginWipeOut(void *);
extern void func_021DAEF0(char *p);
void POKETRADE_NEGO_StepResolveFinalAgree(char *p)
{
    unsigned a, b;
    volatile int v; /* memory-resident on purpose: the original keeps v in [sp] and reads it uninitialised on the fall-through path; a plain local takes r7 */
    a = GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle());
    b = 1 - a;
    if (!POKETRADE_PROC_IsNetSession(p)) {
        a = 0;
        b = 1;
    }
    if (POKETRADE_PROC_IsNetSession(p)) {
        if (!GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1A, 8)) {
            POKETRADE_NEGO_CheckCancelTouch(p);
            return;
        }
    }
    POKETRADE_NEGO_CloseCancelMenu(p, 0, 0);
    ((struct Obj00001 *)p)->f11EA = 0;
    ((struct Obj00001 *)p)->f11E8 = 3;
    ((struct Obj00001 *)p)->f11E9 = 3;
    if (*(unsigned char *)(p + a + 0x11E0) == 10 && *(unsigned char *)(p + b + 0x11E0) == 10) {
        POKETRADE_NEGO_DrawOfferStatusLabel((u8 *)p, 0, 1, 1);
        POKETRADE_NEGO_DrawOfferStatusLabel((u8 *)p, 1, 1, 1);
        if (((struct Obj00001 *)p)->f118C == 3) {
            POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepBeginMonCheckWipe);
        } else {
            POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepSendReady);
        }
        return;
    }
    if (*(unsigned char *)(p + a + 0x11E0) == 4 && *(unsigned char *)(p + b + 0x11E0) == 4) {
        ((struct Obj22747 *)(*(char * *)&((struct Obj00001 *)p)->f8))->f8 = 3;
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepBeginWipeOut);
        return;
    }
    if (*(unsigned char *)(p + b + 0x11E0) == 4) {
        v = 0x61;
    } else if (*(unsigned char *)(p + a + 0x11E0) == 4) {
        v = 0x66;
    }
    MSGDATA_ReadString(((struct Obj00001 *)p)->f720, v, ((struct Obj00001 *)p)->f738);
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    ((struct Obj00001 *)p)->f11E0 = 0;
    ((struct Obj00001 *)p)->f11E1 = 0;
    ((struct Obj00001 *)p)->f11E8 = 0;
    ((struct Obj00001 *)p)->f11E9 = 0;
    POKETRADE_PROC_SetStep(p, (int)func_021DAEF0);
}
