/*
 * function: POKETRADE_SAVE_OpenSummaryScreen
 * address: 0x021E1D68
 * packet: pkt_ov119_021E1D68
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040588 0x02040588 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   func_0207D658 0x0207D658 arm
 *   POKETRADE_3D_RemoveCurrentUnit 0x021E3230 thumb ov119
 *   POKETRADE_SAVE_CloseMessageWindowClear 0x021E1098 thumb ov119
 *   POKETRADE_SAVE_DeleteOfferCardWindow 0x021E2438 thumb ov119
 *   POKETRADE_2D_LoadMainPalette 0x021E5958 thumb ov119
 *   POKETRADE_SAVE_ShowSummaryMon 0x021E219C thumb ov119
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 *   POKETRADE_2D_CreateTouchbarActors 0x021E5998 thumb ov119
 *   POKETRADE_2D_LoadSubBackgroundGfx 0x021E3F30 thumb ov119
 *   POKETRADE_SAVE_VBlankSetupWindowRegs 0x021E2A98 thumb ov119
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 */
#include "../include/Obj03775.h"
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void POKETRADE_3D_RemoveCurrentUnit(void *);
extern void POKETRADE_SAVE_CloseMessageWindowClear(char *p);
extern void POKETRADE_SAVE_DeleteOfferCardWindow(char *,int);
extern void POKETRADE_2D_LoadMainPalette(int p);
extern void POKETRADE_SAVE_ShowSummaryMon(char *p, void *mon, int side, int flag);
extern int POKETRADE_PROC_IsHostSide(void *);
extern void POKETRADE_2D_CreateTouchbarActors(char *p);
extern void POKETRADE_2D_LoadSubBackgroundGfx(char *p);
extern void POKETRADE_SAVE_VBlankSetupWindowRegs(void *a, char *p);
extern void func_020056A0(void (*)(void *,void *),void *,int);
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
void POKETRADE_SAVE_OpenSummaryScreen(char *p,void *a)
{
    func_02040588(3,0);
    POKETRADE_3D_RemoveCurrentUnit(p);
    POKETRADE_SAVE_CloseMessageWindowClear(p);
    POKETRADE_SAVE_DeleteOfferCardWindow(p,0);
    POKETRADE_SAVE_DeleteOfferCardWindow(p,1);
    POKETRADE_2D_LoadMainPalette((int)p);
    POKETRADE_SAVE_ShowSummaryMon(p,a,0,1);
    if(POKETRADE_PROC_IsHostSide(p)==0) {
        POKETRADE_2D_CreateTouchbarActors(p);
        POKETRADE_2D_LoadSubBackgroundGfx(p);
        BG_SYS_SetMainVisiblePlanes(29);
        BG_SYS_SetSubVisiblePlanes(31);
        func_0207D658(0x04001050,26,-8);
        p[0x11f9]=1;
        func_020056A0((void (*)(void *, void *))POKETRADE_SAVE_VBlankSetupWindowRegs,p,0);
    }
    TOUCHBAR_SetButtonVisible((unsigned char *)(((struct Obj03775 *)p)->f9C0),1,1);
}
