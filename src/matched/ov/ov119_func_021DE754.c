/*
 * function: POKETRADE_NEGO_TrySelectOffer
 * address: 0x021DE754
 * packet: pkt_ov119_021DE754
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Shared failure label; padded two-dimensional array members reproduce index scheduling.
 * symbols:
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   POKETRADE_PROC_SetSideMon 0x021D9468 thumb ov119
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   POKETRADE_PROC_SetSideValue 0x021D8F60 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepOpenQuitMenu 0x021DDAD4 thumb ov119
 *   POKETRADE_NEGO_StepSendOfferIndex 0x021DE70C thumb ov119
 */
#include "../include/Obj00251.h"
extern unsigned POKE_TOOL_GetPartyValue(void *,unsigned,unsigned);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern void POKETRADE_PROC_SetSideMon(void *,int,void *);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void MI_CpuCopy8(void *,const void *,int);
extern void POKETRADE_PROC_SetSideValue(void *,int,int);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepOpenQuitMenu(char *p);
extern void POKETRADE_NEGO_StepSendOfferIndex(void *);
typedef struct { char pad[0xfa4]; int entry[2][3]; char gap[0x1c]; void *mon[2][3]; int value[2][3]; } State;
int POKETRADE_NEGO_TrySelectOffer(char *p,int idx)
{
    int row,col,entry;
    void *mon;
    int value;
    State *s=(State *)p;
    row=idx/3;
    col=idx%3;
    if(idx==-1) goto fail;
    entry=s->entry[1-row][col];
    if(entry==-1) goto fail;
    mon=s->mon[1-row][col];
    value=s->value[1-row][col];
    if(mon==0 || POKE_TOOL_GetPartyValue(mon,169,0)==0) goto fail;
    ((struct Obj00251 *)p)->f10A0=idx;
    GFL_USE_PlaySeDefaultVolume(0x54c);
    TOUCHBAR_SetButtonVisible((unsigned char *)(*(int *)&((struct Obj00251 *)p)->f9C0),1,0);
    if(row!=0) {
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepOpenQuitMenu);
    } else {
        POKETRADE_PROC_SetSideMon(p,row,mon);
        MI_CpuCopy8(mon,((struct Obj00251 *)p)->f106C,POKE_TOOL_GetPartyParamSize());
        POKETRADE_PROC_SetSideValue(p,0,value);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepSendOfferIndex);
    }
    return 1;
fail:
    return 0;
}
