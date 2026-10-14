/*
 * function: POKETRADE_NEGO_StepWaitReplySync
 * address: 0x021DDD60
 * packet: pkt_ov119_021DDD60
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepResolveReplies 0x021DDBF0 thumb ov119
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   POKETRADE_NEGO_CheckCancelTouch 0x021DD24C thumb ov119
 *   POKETRADE_NEGO_CloseCancelMenu 0x021DD294 thumb ov119
 *   POKETRADE_NEGO_StepSendReply 0x021DDCF0 thumb ov119
 */

extern int POKETRADE_PROC_IsNetSession(void *);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepResolveReplies(char *p);
struct Link;
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,unsigned int,unsigned int);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int POKETRADE_NEGO_CheckCancelTouch(char *p);
extern void POKETRADE_NEGO_CloseCancelMenu(char *p, int a, int b);
extern void POKETRADE_NEGO_StepSendReply(unsigned char *p);

void POKETRADE_NEGO_StepWaitReplySync(unsigned char *p)
{
    if(POKETRADE_PROC_IsNetSession(p)==0){p[0x11e0]=13;p[0x11e1]=13;POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepResolveReplies);return;} if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),30,8)==0){POKETRADE_NEGO_CheckCancelTouch((char *)p);return;}POKETRADE_NEGO_CloseCancelMenu((char *)p,0,0);POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepSendReply);
}
