/*
 * function: POKETRADE_NEGO_StepReturnFromSummary
 * address: 0x021DE2C4
 * packet: pkt_ov119_021DE2C4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_02040588 0x02040588 arm
 *   POKETRADE_2D_UpdateOfferIconHighlight 0x021E6440 thumb ov119
 *   POKETRADE_SAVE_CloseSummaryPage 0x021E1CE8 thumb ov119
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   POKETRADE_3D_AddUnitAndInit 0x021E3208 thumb ov119
 *   func_02041B6C 0x02041B6C arm
 *   POKETRADE_PROC_GetSideMon 0x021D8FA4 thumb ov119
 *   POKETRADE_PROC_IsMonValid 0x021D89EC thumb ov119
 *   POKETRADE_PROC_SetSideMon 0x021D9468 thumb ov119
 *   POKETRADE_NEGO_SetupWindowRegsOffers 0x021DEBD4 thumb ov119
 *   func_021DD09C 0x021DD09C thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepBrowseOffersMain 0x021DEA24 thumb ov119
 *   POKETRADE_PROC_ResetTouchbarBackButton 0x021D8980 thumb ov119
 *   WIPE_SYS_Start 0x0202208C thumb
 */
#include "../include/Obj06426.h"
typedef unsigned short u16;
extern unsigned WIPE_SYS_EndCheck(void);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void POKETRADE_2D_UpdateOfferIconHighlight(int,int,int);
extern void POKETRADE_SAVE_CloseSummaryPage(void *,int);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void ARC_TOOL_DeleteHandle(void *);
extern void POKETRADE_3D_AddUnitAndInit(void *,int);
extern void func_02041B6C(u32 bit);
extern void *POKETRADE_PROC_GetSideMon(void *,int);
extern int POKETRADE_PROC_IsMonValid(const u8 *p);
extern void POKETRADE_PROC_SetSideMon(void *,int,void *);
extern void POKETRADE_NEGO_SetupWindowRegsOffers(void *);
extern void func_021DD09C(char *p);
extern int POKETRADE_PROC_ResetTouchbarBackButton(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepBrowseOffersMain(char *p);
extern void WIPE_SYS_Start(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
void POKETRADE_NEGO_StepReturnFromSummary(char *p)
{
    void *resource;
    int zero,slot;
    void *mon;
    if(WIPE_SYS_EndCheck()) {
        zero=0;
        func_02040588(3,zero);
        POKETRADE_2D_UpdateOfferIconHighlight((int)p,-1,-1);
        POKETRADE_SAVE_CloseSummaryPage(p,0);
        resource=func_020490F4(102,((struct Obj06426 *)p)->f5F4);
        ARC_UTIL_UploadBgPaletteAddFromHandle(resource,11,2,0,(u16)((struct Obj06426 *)p)->f86C,zero,zero,((struct Obj06426 *)p)->f5F4);
        ARC_TOOL_DeleteHandle(resource);
        POKETRADE_3D_AddUnitAndInit(p,0);
        func_02041B6C(3);
        p[0x11f3]=zero;
        slot=1;
        if(POKETRADE_PROC_IsMonValid(POKETRADE_PROC_GetSideMon(p,slot))) {
            mon=POKETRADE_PROC_GetSideMon(p,slot);
            POKETRADE_PROC_SetSideMon(p,slot,mon);
        }
        slot=0;
        if(POKETRADE_PROC_IsMonValid(POKETRADE_PROC_GetSideMon(p,slot))) {
            mon=POKETRADE_PROC_GetSideMon(p,slot);
            POKETRADE_PROC_SetSideMon(p,slot,mon);
        }
        POKETRADE_NEGO_SetupWindowRegsOffers(p);
        func_021DD09C(p);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepBrowseOffersMain);
        POKETRADE_PROC_ResetTouchbarBackButton(p);
        WIPE_SYS_Start((void *)3,1,1,0,6,1,((struct Obj06426 *)p)->f5F4);
    }
}
