/*
 * function: POKETRADE_PROC_StepSendIntroReady
 * address: 0x021D9CFC
 * packet: pkt_ov119_021D9CFC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepIntro 0x021D9C00 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 */
typedef unsigned short u16;
typedef unsigned char u8;
extern int POKETRADE_PROC_IsNetSession(void *);
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
struct Entry;
extern void POKETRADE_PROC_StepIntro(char *p);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned,unsigned);
void POKETRADE_PROC_StepSendIntroReady(u8 *p) { int kind=POKETRADE_PROC_IsNetSession(p); u8 b; if(POKETRADE_SAVE_IsMessagePrintDone((char *)p)) { if(kind==0) {p[0x11e0]=1;p[0x11e1]=1;POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepIntro);return;} b=1; if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc00,1,(u32)(&b))==0) return; GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),26,8);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepIntro); } }
