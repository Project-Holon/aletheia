/*
 * function: POKETRADE_NEGO_StepBrowseOffersMain
 * address: 0x021DEA24
 * packet: pkt_ov119_021DEA24
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 02035C08 returns the r0 consumed by original after its forwarding call; matched 021D98AC documents full ARM9 forwarding proof.
 * symbols:
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfPressing 0x021B6470 thumb ov067
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   POKETRADE_PROC_UpdatePickedIcon 0x021DD09C thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepOpenDeclineMenu 0x021DE9E8 thumb ov119
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   d_021E80C4 0x021E80C4 data a4
 *   func_020355D8 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   POKETRADE_2D_MovePickedIconActor 0x021E68F4 thumb ov119
 *   POKETRADE_NEGO_TrySelectOffer 0x021DE754 thumb ov119
 *   func_020355C4 0x020355C4 arm
 *   KEY_GetTrg 0x020362DC arm
 *   POKETRADE_NEGO_PollOfferCursorKeys 0x021DE208 thumb ov119
 */
#include "../include/Obj00251.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct S S;
struct MsgBank;
extern void TOUCHBAR_Update(struct S *p);
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);
extern int TOUCHBAR_GetPressedButtonIdIfDone(u8 *),TOUCHBAR_GetPressedButtonIdIfPressing(u8 *);
extern void MSGDATA_ReadString(struct MsgBank *,unsigned,void *);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *);
extern void POKETRADE_PROC_UpdatePickedIcon(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepOpenDeclineMenu(void *);
extern int TOUCHPANEL_HitTrg(const void *);
extern u32 KEY_GetTrg(void);
extern u8 func_020355C4(void);
extern const char d_021E80C4[];
extern void func_020355D8(u8);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void POKETRADE_2D_MovePickedIconActor(int,int);
extern int POKETRADE_NEGO_TrySelectOffer(char *,int),POKETRADE_NEGO_PollOfferCursorKeys(char *);
static inline int poll(void) { int v=KEY_GetTrg(); if(v)func_020355D8(0); return v; }
void POKETRADE_NEGO_StepBrowseOffersMain(char *p)
{
    int idx,sentinel;
    TOUCHBAR_Update(*(S * *)&((struct Obj00251 *)p)->f9C0);
    if(TOUCHBAR_GetPressedButtonIdIfDone(*(u8 * *)&((struct Obj00251 *)p)->f9C0)==1) {
        MSGDATA_ReadString(*(struct MsgBank * *)&((struct Obj00251 *)p)->f720,148,((struct Obj00251 *)p)->f738);
        POKETRADE_SAVE_OpenMessageWindowTop(p);
        TOUCHBAR_SetButtonEnabled((unsigned char *)(*(int *)&((struct Obj00251 *)p)->f9C0),1,0);
        POKETRADE_PROC_UpdatePickedIcon(p);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepOpenDeclineMenu);
        return;
    }
    sentinel=-1;
    if(TOUCHBAR_GetPressedButtonIdIfPressing(*(u8 * *)&((struct Obj00251 *)p)->f9C0)==sentinel) {
        idx=TOUCHPANEL_HitTrg(d_021E80C4);
        if(idx!=sentinel) {
            func_020355D8(1);
            GFL_USE_PlaySeDefaultVolume(0x548);
            POKETRADE_2D_MovePickedIconActor((int)p,sentinel);
            if(POKETRADE_NEGO_TrySelectOffer(p,idx)) return;
        }
        if(func_020355C4() && poll()) {
            ((struct Obj00251 *)p)->f10A0%=6;
            if(((struct Obj00251 *)p)->f10A0<0) ((struct Obj00251 *)p)->f10A0=0;
            POKETRADE_2D_MovePickedIconActor((int)p,((struct Obj00251 *)p)->f10A0);
            GFL_USE_PlaySeDefaultVolume(0x548);
            return;
        }
        if(poll()==1) {
            if(POKETRADE_NEGO_TrySelectOffer(p,((struct Obj00251 *)p)->f10A0)) return;
        }
        if(POKETRADE_NEGO_PollOfferCursorKeys(p)) {
            POKETRADE_2D_MovePickedIconActor((int)p,((struct Obj00251 *)p)->f10A0);
            GFL_USE_PlaySeDefaultVolume(0x548);
        }
    }
}
