/*
 * function: RESEARCH_TOP_InitSelection
 * address: 0x021BA560
 * packet: pkt_ov217_021BA560
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   RESEARCH_COMMON_GetPreviousScreen 0x021C09C8 thumb ov217
 *   RESEARCH_COMMON_GetEntryHandled 0x021C09CC thumb ov217
 *   RESEARCH_TOP_SetSelection 0x021BA3B0 thumb ov217
 *   RESEARCH_TOP_IsSelectionValid 0x021BA3B4 thumb ov217
 */
#include "../include/Obj25827.h"
extern unsigned RESEARCH_COMMON_GetPreviousScreen(void *);
extern unsigned RESEARCH_COMMON_GetEntryHandled(void *);
extern void RESEARCH_TOP_SetSelection(void *,unsigned);
extern unsigned RESEARCH_TOP_IsSelectionValid(unsigned,unsigned);
void RESEARCH_TOP_InitSelection(char *p)
{
    void *owner=((struct Obj25827 *)p)->f0;
    unsigned a=RESEARCH_COMMON_GetPreviousScreen(owner),b=RESEARCH_COMMON_GetEntryHandled(owner);
    if(a!=0 && b==0) {
        unsigned mode;
        switch(a) {case 2:default:mode=0;break;case 3:mode=1;break;}
        RESEARCH_TOP_SetSelection(p,mode);
    } else {
        if(RESEARCH_TOP_IsSelectionValid((unsigned)p,0)!=0) RESEARCH_TOP_SetSelection(p,0);
        else RESEARCH_TOP_SetSelection(p,1);
    }
}
