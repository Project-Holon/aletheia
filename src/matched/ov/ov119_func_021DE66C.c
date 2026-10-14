/*
 * function: POKETRADE_NEGO_StepOpenOfferActionMenu
 * address: 0x021DE66C
 * packet: pkt_ov119_021DE66C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E770C 0x021E770C data a4
 *   POKETRADE_SAVE_OpenTaskMenu 0x021E1410 thumb ov119
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepOfferActionChoice 0x021DE5C4 thumb ov119
 */
#include "../include/Obj22744.h"
typedef struct { int a,b,c; } Triple;
extern const Triple d_021E770C;
extern void POKETRADE_SAVE_OpenTaskMenu(void *p, int *ids, int count);
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepOfferActionChoice(char *p);
void POKETRADE_NEGO_StepOpenOfferActionMenu(char *p)
{
    Triple t=d_021E770C;
    POKETRADE_SAVE_OpenTaskMenu(p,(int *)(&t),3);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((struct Obj22744 *)p)->f9C0),1,0);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepOfferActionChoice);
}
