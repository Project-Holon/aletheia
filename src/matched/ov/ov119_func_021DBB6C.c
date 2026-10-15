/*
 * function: POKETRADE_PROC_UpdateTouchbarButtons
 * address: 0x021DBB6C
 * packet: pkt_ov119_021DBB6C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   POKETRADE_NEGO_HasOffer 0x021DD2F4 thumb ov119
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   POKETRADE_PROC_ResetTouchbarBackButton 0x021D8980 thumb ov119
 *   POKETRADE_PROC_RequestBoxRedraw 0x021D8B38 thumb ov119
 */
#include "../include/Obj00001.h"
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern int POKETRADE_NEGO_HasOffer(char *p);
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);
extern int POKETRADE_PROC_ResetTouchbarBackButton(char *p);
extern void POKETRADE_PROC_RequestBoxRedraw(char *p);
void POKETRADE_PROC_UpdateTouchbarButtons(char *p)
{
    CLACT_SetActorDrawEnable((struct Obj *)*(int *)&((struct Obj00001 *)p)->fF04,1);
    TOUCHBAR_SetButtonVisible((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),8,POKETRADE_NEGO_HasOffer(p));
    TOUCHBAR_SetButtonEnabled((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),8,POKETRADE_NEGO_HasOffer(p));
    TOUCHBAR_SetButtonVisible((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),7,1);
    TOUCHBAR_SetButtonEnabled((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),7,1);
    TOUCHBAR_SetButtonVisible((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),9,0);
    POKETRADE_PROC_ResetTouchbarBackButton(p);
    POKETRADE_PROC_RequestBoxRedraw(p);
}
