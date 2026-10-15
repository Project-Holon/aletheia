/*
 * function: POKETRADE_PROC_StepSendContinue
 * address: 0x021DAF68
 * packet: pkt_ov119_021DAF68
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   POKETRADE_PROC_StepIntro 0x021D9C00 thumb ov119
 */
typedef unsigned char u8;
typedef unsigned short u16;

extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern int POKETRADE_PROC_IsNetSession(void *);
extern void POKETRADE_PROC_SetStep(void *,int);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void POKETRADE_PROC_StepIntro(char *p);
void POKETRADE_PROC_StepSendContinue(void *p) {
 unsigned id=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
 u8 b;
 if(POKETRADE_SAVE_IsMessagePrintDone(p)) {
  if(POKETRADE_PROC_IsNetSession(p)) {
   b=2;
   if(GFL_NET_SendToHandle((void *)id,0xc0f,1,(u32)(&b))) POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepIntro);
  } else { POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepIntro); }
 }
}
