/*
 * function: POKETRADE_NEGO_StepShowNoOfferMessage
 * address:  0x021DEBA0
 * packet:   pkt_ov119_021DEBA0
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   POKETRADE_SAVE_OpenMessageWindowTop  0x021E1024  thumb  ov119
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_NEGO_StepWaitInputAfterMessage  0x021DEB34  thumb  ov119
 */
#include "../include/Obj10363.h"

typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *p);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void POKETRADE_NEGO_StepWaitInputAfterMessage(void *p);

void POKETRADE_NEGO_StepShowNoOfferMessage(char *p)
{
    MSGDATA_ReadString(((struct Obj10363 *)p)->f720, 0x91, ((struct Obj10363 *)p)->f738);
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    *(p + 0x11F1) = 0x78;
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepWaitInputAfterMessage);
}
