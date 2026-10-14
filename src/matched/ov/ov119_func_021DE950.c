/*
 * function: POKETRADE_NEGO_StepBeginDeclineConfirm
 * address:  0x021DE950
 * packet:   pkt_ov119_021DE950
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
 *   POKETRADE_SAVE_ShowTimeIcon  0x021E1030  thumb  ov119
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_NEGO_StepSendDeclineConfirm  0x021DE918  thumb  ov119
 */
#include "../include/Obj10362.h"

typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *p);
extern void POKETRADE_SAVE_ShowTimeIcon(char *p);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void POKETRADE_NEGO_StepSendDeclineConfirm(void *p);

void POKETRADE_NEGO_StepBeginDeclineConfirm(char *p)
{
    MSGDATA_ReadString(((struct Obj10362 *)p)->f720, 0x88, ((struct Obj10362 *)p)->f738);
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    POKETRADE_SAVE_ShowTimeIcon(p);
    *(p + 0x11F1) = 0x78;
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepSendDeclineConfirm);
}
