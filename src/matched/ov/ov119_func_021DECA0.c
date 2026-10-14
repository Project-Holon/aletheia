/*
 * function: POKETRADE_NEGO_StepBuildBrowseScene
 * address: 0x021DECA0
 * packet: pkt_ov119_021DECA0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_2D_FreeMainResources 0x021E4000 thumb ov119
 *   POKETRADE_NEGO_UpdateOfferMarkers 0x021DF7D0 thumb ov119
 *   POKETRADE_NEGO_ResetMarkers 0x021DF8E0 thumb ov119
 *   POKETRADE_2D_DeleteAllOfferIconActors 0x021E64B8 thumb ov119
 *   POKETRADE_NEGO_ReleaseIconResources 0x021DD588 thumb ov119
 *   POKETRADE_2D_DeleteBoxWindows 0x021E4570 thumb ov119
 *   POKETRADE_NEGO_DeleteHeaderWindows 0x021DD9DC thumb ov119
 *   POKETRADE_2D_DeleteAllBoxIcons 0x021E4888 thumb ov119
 *   POKETRADE_NEGO_RegisterIconResources 0x021DD528 thumb ov119
 *   func_02041570 0x02041570 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   POKETRADE_SAVE_DrawOfferListWindows 0x021E24E8 thumb ov119
 *   POKETRADE_2D_SetupCursorBg 0x021E6B90 thumb ov119
 *   WIPE_SYS_Start 0x0202208C thumb
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepWaitWipeBrowse 0x021DEC4C thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void POKETRADE_2D_FreeMainResources(char *p);
extern void POKETRADE_NEGO_UpdateOfferMarkers(void *);
extern void POKETRADE_NEGO_ResetMarkers(void *);
extern void POKETRADE_2D_DeleteAllOfferIconActors(void *);
extern void POKETRADE_NEGO_ReleaseIconResources(char *p);
extern void POKETRADE_2D_DeleteBoxWindows(char *p);
extern void POKETRADE_NEGO_DeleteHeaderWindows(unsigned char *);
extern void POKETRADE_2D_DeleteAllBoxIcons(char *p);
extern void POKETRADE_NEGO_RegisterIconResources(char *,int);
extern void func_02041570(int channel, u16 val);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);
extern void POKETRADE_SAVE_DrawOfferListWindows(char *p, int a1);
extern void POKETRADE_2D_SetupCursorBg(char *p);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepWaitWipeBrowse(void *);
void POKETRADE_NEGO_StepBuildBrowseScene(char *p) {
 POKETRADE_2D_FreeMainResources(p);POKETRADE_NEGO_UpdateOfferMarkers(p);POKETRADE_NEGO_ResetMarkers(p);POKETRADE_2D_DeleteAllOfferIconActors(p);POKETRADE_NEGO_ReleaseIconResources(p);POKETRADE_2D_DeleteBoxWindows(p);POKETRADE_NEGO_DeleteHeaderWindows((unsigned char *)p);POKETRADE_2D_DeleteAllBoxIcons(p);
 POKETRADE_NEGO_RegisterIconResources(p,1);func_02041570(6,0);CLACT_SetActorDrawEnable((struct Obj *)*(int *)&((struct Obj00001 *)p)->fF04,0);
 TOUCHBAR_SetButtonVisible((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),1,1);TOUCHBAR_SetButtonEnabled((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),1,0);POKETRADE_SAVE_DrawOfferListWindows(p,6);
 ((struct Obj00001 *)p)->f108C=0;((struct Obj00001 *)p)->f1084=1;POKETRADE_2D_SetupCursorBg(p);
 WIPE_SYS_Start(0,1,1,0,6,1,((struct Obj00001 *)p)->f5F4);POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepWaitWipeBrowse);
}
