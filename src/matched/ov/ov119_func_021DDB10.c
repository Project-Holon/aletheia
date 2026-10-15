/*
 * function: POKETRADE_NEGO_StepWaitSync25
 * address: 0x021DDB10
 * packet: pkt_ov119_021DDB10
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   POKETRADE_NEGO_CheckCancelTouch 0x021DD24C thumb ov119
 *   POKETRADE_SAVE_CloseMessageWindowClear 0x021E1098 thumb ov119
 *   POKETRADE_NEGO_CloseCancelMenu 0x021DD294 thumb ov119
 *   POKETRADE_PROC_ResetTouchbarBackButton 0x021D8980 thumb ov119
 *   POKETRADE_PROC_UpdatePickedIcon 0x021DD09C thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepBrowseOffersMain 0x021DEA24 thumb ov119
 */

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int POKETRADE_PROC_IsNetSession(void *);
struct Link;
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,unsigned int,unsigned int);
extern int POKETRADE_NEGO_CheckCancelTouch(char *p);
extern void POKETRADE_SAVE_CloseMessageWindowClear(char *p);
extern void POKETRADE_NEGO_CloseCancelMenu(char *p, int a, int b);
extern int POKETRADE_PROC_ResetTouchbarBackButton(char *p);
extern void POKETRADE_PROC_UpdatePickedIcon(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepBrowseOffersMain(char *p);

void POKETRADE_NEGO_StepWaitSync25(unsigned char *p)
{
    GFL_NET_HANDLE_GetCurrentHandle(); if(POKETRADE_PROC_IsNetSession(p)) { if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),25,8)==0) {POKETRADE_NEGO_CheckCancelTouch((char *)p);return;} } POKETRADE_SAVE_CloseMessageWindowClear((char *)p);POKETRADE_NEGO_CloseCancelMenu((char *)p,0,0);POKETRADE_PROC_ResetTouchbarBackButton((char *)p);POKETRADE_PROC_UpdatePickedIcon((char *)p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepBrowseOffersMain);
}
