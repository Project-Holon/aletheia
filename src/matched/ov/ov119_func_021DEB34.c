/*
 * function: POKETRADE_NEGO_StepWaitInputAfterMessage
 * address: 0x021DEB34
 * packet: pkt_ov119_021DEB34
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_TickWifiTimer 0x021DD140 thumb ov119
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   KEY_GetTrg 0x020362DC arm
 *   UI_SetInputMode 0x020355D8 arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_020355C4 0x020355C4 arm
 *   POKETRADE_2D_MovePickedIconActor 0x021E68F4 thumb ov119
 *   POKETRADE_SAVE_CloseMessageWindowClear 0x021E1098 thumb ov119
 *   POKETRADE_PROC_ResetTouchbarBackButton 0x021D8980 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepBrowseOffersMain 0x021DEA24 thumb ov119
 */

typedef unsigned int u32;
typedef unsigned char  u8;
extern int POKETRADE_PROC_TickWifiTimer(char *p);
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern u32 KEY_GetTrg(void);
extern void UI_SetInputMode(u8 v);
extern int TOUCHPANEL_GetTrg(void);
extern u8 func_020355C4(void);
extern void POKETRADE_2D_MovePickedIconActor(int p, int i);
extern void POKETRADE_SAVE_CloseMessageWindowClear(char *p);
extern int POKETRADE_PROC_ResetTouchbarBackButton(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepBrowseOffersMain(char *p);
void POKETRADE_NEGO_StepWaitInputAfterMessage(void *p)
{
    int v;
    if(POKETRADE_PROC_TickWifiTimer(p) && POKETRADE_SAVE_IsMessagePrintDone(p)) {
        v=KEY_GetTrg();
        if(v) UI_SetInputMode(0);
        if(v==0) {
            v=TOUCHPANEL_GetTrg();
            if(v) UI_SetInputMode(1);
            if(v==0) return;
        }
        if(func_020355C4()) POKETRADE_2D_MovePickedIconActor((int)p,-1);
        else POKETRADE_2D_MovePickedIconActor((int)p,0);
        POKETRADE_SAVE_CloseMessageWindowClear(p);
        POKETRADE_PROC_ResetTouchbarBackButton(p);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepBrowseOffersMain);
    }
}
