/*
 * function: POKETRADE_PROC_HideTouchbarButtons
 * address: 0x021D9E54
 * packet: pkt_ov119_021D9E54
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   POKETRADE_PROC_ClearDragIcon 0x021D8C6C thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepSendPartyBoxSelected 0x021D9E0C thumb ov119
 */
#include "../include/Obj04474.h"

extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void POKETRADE_PROC_ClearDragIcon(void *);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepSendPartyBoxSelected(char *p);
void POKETRADE_PROC_HideTouchbarButtons(char *p) {
    TOUCHBAR_SetButtonVisible((unsigned char *)(((struct Obj04474 *)p)->f9C0),7,0);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((struct Obj04474 *)p)->f9C0),8,0);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((struct Obj04474 *)p)->f9C0),9,0);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((struct Obj04474 *)p)->f9C0),1,0);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj04474 *)p)->fF04,0);
    POKETRADE_PROC_ClearDragIcon(p);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendPartyBoxSelected);
}
