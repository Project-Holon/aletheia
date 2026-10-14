/*
 * function: POKETRADE_NEGO_StepSendReady
 * address: 0x021DEDBC
 * packet: pkt_ov119_021DEDBC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepWipeToBrowse 0x021DED74 thumb ov119
 */
typedef unsigned char u8;
typedef unsigned short u16;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern int POKETRADE_PROC_IsNetSession(void *);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepWipeToBrowse(void *);
void POKETRADE_NEGO_StepSendReady(void *p) {
 unsigned h=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
 u8 b;
 if(POKETRADE_PROC_IsNetSession(p)) {
  b=1;
  if(GFL_NET_SendToHandle((void *)h,0xc0a,1,(u32)(&b))) {POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepWipeToBrowse);return;}
 } else {POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepWipeToBrowse);}
}
