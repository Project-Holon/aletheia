/*
 * function: POKETRADE_PROC_StepEnterBrowsing
 * address: 0x021DBAF8
 * packet: pkt_ov119_021DBAF8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   POKETRADE_PROC_ResetTouchbarBackButton 0x021D8980 thumb ov119
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   POKETRADE_2D_CreateBoxWindows 0x021E4420 thumb ov119
 *   POKETRADE_2D_SetupSubBlend 0x021E6700 thumb ov119
 *   POKETRADE_PROC_RequestBoxRedraw 0x021D8B38 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepBrowseGrid 0x021DBE70 thumb ov119
 */
#include "../include/Obj00001.h"
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);
extern int POKETRADE_PROC_ResetTouchbarBackButton(char *p);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void POKETRADE_2D_CreateBoxWindows(char *p);
extern void POKETRADE_2D_SetupSubBlend(void *);
extern void POKETRADE_PROC_RequestBoxRedraw(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepBrowseGrid(char *p);
void POKETRADE_PROC_StepEnterBrowsing(char *p)
{
    TOUCHBAR_SetButtonVisible((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),8,0);
    TOUCHBAR_SetButtonVisible((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),7,1);
    TOUCHBAR_SetButtonEnabled((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),7,1);
    TOUCHBAR_SetButtonVisible((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),9,0);
    POKETRADE_PROC_ResetTouchbarBackButton(p);
    CLACT_SetActorDrawEnable((struct Obj *)*(int *)&((struct Obj00001 *)p)->fF04,1);
    POKETRADE_2D_CreateBoxWindows(p);
    POKETRADE_2D_SetupSubBlend(p);
    ((struct Obj00001 *)p)->fF84=-1;
    ((struct Obj00001 *)p)->fF88=-1;
    POKETRADE_PROC_RequestBoxRedraw(p);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBrowseGrid);
}
