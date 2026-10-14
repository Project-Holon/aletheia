/*
 * function: func_021DB45C
 * address: 0x021DB45C
 * packet: pkt_ov119_021DB45C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   POKETRADE_NEGO_SetOfferMarkersState 0x021DF7AC thumb ov119
 *   func_0207D658 0x0207D658 arm
 *   POKETRADE_2D_FadePaletteAll 0x021E71E0 thumb ov119
 *   POKETRADE_NEGO_HasOffer 0x021DD2F4 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   func_021DB41C 0x021DB41C thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned int   u32;
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);
extern void POKETRADE_NEGO_SetOfferMarkersState(void *,int);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void POKETRADE_2D_FadePaletteAll(void *,int);
extern int POKETRADE_NEGO_HasOffer(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void func_021DB41C(char *p);
void func_021DB45C(char *p)
{
    TOUCHBAR_SetButtonEnabled((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),7,0);
    POKETRADE_NEGO_SetOfferMarkersState(p,0);
    func_0207D658((u32)((void *)0x04001050),10,-8);
    POKETRADE_2D_FadePaletteAll(p,1);
    if(POKETRADE_NEGO_HasOffer(p))
        TOUCHBAR_SetButtonEnabled((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),8,0);
    POKETRADE_PROC_SetStep(p,(int)func_021DB41C);
}
