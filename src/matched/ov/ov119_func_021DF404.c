/*
 * function: POKETRADE_NEGO_StepBeginFinalReady
 * address: 0x021DF404
 * packet: pkt_ov119_021DF404
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   POKETRADE_SAVE_ShowTimeIcon 0x021E1030 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepSendFinalReady 0x021DF37C thumb ov119
 */
#include "../include/Obj10364.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *);
extern void POKETRADE_SAVE_ShowTimeIcon(char *p);
extern void POKETRADE_PROC_SetStep(void *, int);
extern void POKETRADE_NEGO_StepSendFinalReady(u8 *p);
void POKETRADE_NEGO_StepBeginFinalReady(char *p)
{
    MSGDATA_ReadString(((struct Obj10364 *)p)->f720, 0x88, ((struct Obj10364 *)p)->f738);
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    POKETRADE_SAVE_ShowTimeIcon(p);
    ((struct Obj10364 *)p)->f11F1 = 0x78;
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepSendFinalReady);
}
