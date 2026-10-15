/*
 * function: POKETRADE_PROC_DeleteAllResources
 * address: 0x021DC720
 * packet: pkt_ov119_021DC720
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021DC726 reads hardware DISPCNT 0x04001000 before updating it.
 * symbols:
 *   POKETRADE_2D_DeleteAllOfferIconActors 0x021E64B8 thumb ov119
 *   POKETRADE_3D_RemoveCurrentUnit 0x021E3230 thumb ov119
 *   POKETRADE_NEGO_ReleaseIconResources 0x021DD588 thumb ov119
 *   POKETRADE_NEGO_ResetMarkers 0x021DF8E0 thumb ov119
 *   POKETRADE_NEGO_DeleteHeaderWindows 0x021DD9DC thumb ov119
 *   POKETRADE_2D_DeleteBoxWindows 0x021E4570 thumb ov119
 *   POKETRADE_3D_DeleteMcssSlot 0x021E36D8 thumb ov119
 *   POKETRADE_2D_DeletePickedIconActor 0x021E69A4 thumb ov119
 *   POKETRADE_NEGO_UpdateOfferMarkers 0x021DF7D0 thumb ov119
 *   POKETRADE_SAVE_DeleteOfferListWindows 0x021E2680 thumb ov119
 *   POKETRADE_2D_DeleteAllBoxIcons 0x021E4888 thumb ov119
 *   POKETRADE_SAVE_DeleteOfferCardWindow 0x021E2438 thumb ov119
 *   TOUCHBAR_Delete 0x021B639C thumb ov067
 *   POKETRADE_2D_DeleteOfferIcons 0x021E48E0 thumb ov119
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   POKETRADE_SAVE_DeleteMessageResources 0x021E11A8 thumb ov119
 *   POKETRADE_NEGO_FreeOfferMons 0x021DD174 thumb ov119
 *   POKETRADE_SAVE_DeletePartnerOfferCard 0x021E293C thumb ov119
 *   POKETRADE_2D_FreeBackgroundPalette 0x021E3F08 thumb ov119
 *   POKETRADE_2D_FreeMainResources 0x021E4000 thumb ov119
 *   POKETRADE_2D_ExitSubBgs 0x021E57A4 thumb ov119
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj10357.h"
typedef unsigned char  u8;
struct Bank;
extern void POKETRADE_2D_DeleteAllOfferIconActors(void *);
extern void POKETRADE_3D_RemoveCurrentUnit(void *);
extern void POKETRADE_NEGO_ReleaseIconResources(char *p);
extern void POKETRADE_NEGO_ResetMarkers(void *);
extern void POKETRADE_2D_DeleteBoxWindows(char *p);
extern void POKETRADE_NEGO_DeleteHeaderWindows(unsigned char *),POKETRADE_3D_DeleteMcssSlot(void *,int),POKETRADE_2D_DeletePickedIconActor(char *),POKETRADE_NEGO_UpdateOfferMarkers(void *),POKETRADE_SAVE_DeleteOfferListWindows(char *),POKETRADE_2D_DeleteAllBoxIcons(char *),POKETRADE_SAVE_DeleteOfferCardWindow(char *,int);
extern void TOUCHBAR_Delete(u8 *p);
extern void POKETRADE_2D_DeleteOfferIcons(char *);
extern unsigned int CLACT_DeleteUnit(struct Bank *bank);
extern void POKETRADE_SAVE_DeleteMessageResources(char *);
extern void POKETRADE_NEGO_FreeOfferMons(char *);
extern void POKETRADE_SAVE_DeletePartnerOfferCard(char *p, int i);
extern void POKETRADE_2D_FreeBackgroundPalette(char *);
extern void POKETRADE_2D_FreeMainResources(char *);
extern void POKETRADE_2D_ExitSubBgs(int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
#define P(o) (*(void **)(p+(o)))
void POKETRADE_PROC_DeleteAllResources(char *p)
{
    int i;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    POKETRADE_2D_DeleteAllOfferIconActors(p);POKETRADE_3D_RemoveCurrentUnit(p);POKETRADE_NEGO_ReleaseIconResources(p);POKETRADE_NEGO_ResetMarkers(p);POKETRADE_NEGO_DeleteHeaderWindows((unsigned char *)p);POKETRADE_2D_DeleteBoxWindows(p);
    POKETRADE_3D_DeleteMcssSlot(p,1);POKETRADE_2D_DeletePickedIconActor(p);POKETRADE_NEGO_UpdateOfferMarkers(p);POKETRADE_SAVE_DeleteOfferListWindows(p);POKETRADE_2D_DeleteAllBoxIcons(p);
    POKETRADE_SAVE_DeleteOfferCardWindow(p,0);POKETRADE_SAVE_DeleteOfferCardWindow(p,1);
    if(P(0x9c0)) {TOUCHBAR_Delete(P(0x9c0));P(0x9c0)=0;}
    POKETRADE_2D_DeleteOfferIcons(p);
    if(P(0x9c4)) {CLACT_DeleteUnit(P(0x9c4));P(0x9c4)=0;}
    POKETRADE_SAVE_DeleteMessageResources(p);POKETRADE_NEGO_FreeOfferMons(p);
    POKETRADE_SAVE_DeletePartnerOfferCard(p,0);POKETRADE_SAVE_DeletePartnerOfferCard(p,1);POKETRADE_2D_FreeBackgroundPalette(p);POKETRADE_2D_FreeMainResources(p);POKETRADE_2D_ExitSubBgs((int)p);
    if(P(0x818)) {func_020307B0(P(0x818));P(0x818)=0;}
    for(i=0;i<4;i++) {
        char *q=p+i*4;
        if(((struct Obj10357 *)q)->f85C) {func_020307B0(((struct Obj10357 *)q)->f85C);((struct Obj10357 *)q)->f85C=0;}
    }
}
