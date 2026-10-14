/*
 * function: POKETRADE_NEGO_StepOpenSummaryFromBrowse
 * address: 0x021DE518
 * packet: pkt_ov119_021DE518
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKETRADE_SAVE_OpenSummaryScreen 0x021E1D68 thumb ov119
 *   POKETRADE_2D_UpdateOfferIconHighlight 0x021E6440 thumb ov119
 *   POKETRADE_NEGO_SetupWindowRegsOffers 0x021DEBD4 thumb ov119
 *   WIPE_SYS_Start 0x0202208C thumb
 *   POKETRADE_PROC_ResetTouchbarBackButton 0x021D8980 thumb ov119
 *   func_021DD09C 0x021DD09C thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepBrowseOffers 0x021DE3E8 thumb ov119
 */
#include "../include/Obj03775.h"
typedef unsigned short u16;
typedef struct { char pad[0xfd8]; void *obj[2][3]; } State;
extern unsigned int WIPE_SYS_EndCheck(void);
typedef unsigned int   u32;
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void POKETRADE_SAVE_OpenSummaryScreen(char *p, void *a);
extern void POKETRADE_2D_UpdateOfferIconHighlight(int p, int a, int b);
extern void POKETRADE_NEGO_SetupWindowRegsOffers(void *);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern int POKETRADE_PROC_ResetTouchbarBackButton(char *p);
extern void func_021DD09C(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepBrowseOffers(char *p);
void POKETRADE_NEGO_StepOpenSummaryFromBrowse(State *p)
{
    char *b=(char *)p;
    u16 idx;
    int col,row;
    void *obj;
    int other;
    if(WIPE_SYS_EndCheck()) {
        idx=(u16)((struct Obj03775 *)b)->f10A0;
        col=idx%3; row=idx/3;
        other=1-row;
        obj=p->obj[other][col];
        b[0x11f3]=1;
        if(obj && POKE_TOOL_GetPartyValue(obj,169,0)) {
            POKETRADE_SAVE_OpenSummaryScreen((char *)p,obj); POKETRADE_2D_UpdateOfferIconHighlight((int)p,row,col);
        }
        POKETRADE_NEGO_SetupWindowRegsOffers(p);
        WIPE_SYS_Start((void *)3,1,1,0,6,1,((struct Obj03775 *)b)->f5F4);
        POKETRADE_PROC_ResetTouchbarBackButton((char *)p); func_021DD09C((char *)p);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepBrowseOffers);
    }
}
