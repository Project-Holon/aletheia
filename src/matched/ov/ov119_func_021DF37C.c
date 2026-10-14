/*
 * function: POKETRADE_NEGO_StepSendFinalReady
 * address: 0x021DF37C
 * packet: pkt_ov119_021DF37C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepSendFinalAgree 0x021DF338 thumb ov119
 */
typedef unsigned char u8;
typedef unsigned short u16;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p,unsigned int lo,unsigned int hi);
extern int POKETRADE_SAVE_IsMessagePrintDone(char *);
extern int POKETRADE_PROC_IsNetSession(void *);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepSendFinalAgree(void *);
void POKETRADE_NEGO_StepSendFinalReady(u8 *p) {
 unsigned h=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
 u8 b;
 if(POKETRADE_SAVE_IsMessagePrintDone((char *)p)) {
  if(POKETRADE_PROC_IsNetSession(p)) {
   b=10;
   if(GFL_NET_SendToHandle((void *)h,0xc00,1,(u32)(&b))) {
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),26,8);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepSendFinalAgree);return;
   }
  } else {p[0x11e0]=10;p[0x11e1]=10;POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepSendFinalAgree);}
 }
}
