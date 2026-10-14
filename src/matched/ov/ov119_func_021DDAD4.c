/*
 * function: POKETRADE_NEGO_StepOpenQuitMenu
 * address: 0x021DDAD4
 * packet: pkt_ov119_021DDAD4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E76F4 0x021E76F4 data a4
 *   POKETRADE_SAVE_OpenTaskMenu 0x021E1410 thumb ov119
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepQuitMenuChoice 0x021DDA50 thumb ov119
 */
#include "../include/Obj22740.h"
typedef struct { int a,b; } Pair;
extern const Pair d_021E76F4;
extern void POKETRADE_SAVE_OpenTaskMenu(void *p, int *ids, int count);
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepQuitMenuChoice(void *);
void POKETRADE_NEGO_StepOpenQuitMenu(char *p)
{
    Pair t=d_021E76F4;
    POKETRADE_SAVE_OpenTaskMenu(p,(int *)(&t),2);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((struct Obj22740 *)p)->f9C0),1,0);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepQuitMenuChoice);
}
