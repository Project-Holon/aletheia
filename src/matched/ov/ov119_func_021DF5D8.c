/*
 * function: POKETRADE_NEGO_StepShowCancelMessage
 * address: 0x021DF5D8
 * packet: pkt_ov119_021DF5D8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepOpenCancelMenu 0x021DF59C thumb ov119
 *   POKETRADE_SAVE_SetupWindowRegsSummary 0x021E26AC thumb ov119
 */
#include "../include/Obj10366.h"
typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *);
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);
extern void POKETRADE_PROC_SetStep(void *, int);
extern void POKETRADE_NEGO_StepOpenCancelMenu(void *);
extern void POKETRADE_SAVE_SetupWindowRegsSummary(void *);
void POKETRADE_NEGO_StepShowCancelMessage(char *p)
{
    MSGDATA_ReadString(((struct Obj10366 *)p)->f720, 0x87, ((struct Obj10366 *)p)->f738);
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    TOUCHBAR_SetButtonEnabled(((struct Obj10366 *)p)->f9C0, 1, 0);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepOpenCancelMenu);
    POKETRADE_SAVE_SetupWindowRegsSummary(p);
}
