/*
 * function: DELIVERY_IRC_StepWaitConnect
 * address: 0x02157D68
 * packet: pkt_ov010_02157D68
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_GetNegotiationNum 0x0203D1B4 arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   DELIVERY_IRC_SetStepAtLine 0x02157960 thumb ov010
 *   DELIVERY_IRC_StepSendRequest 0x02157D0C thumb ov010
 */
typedef unsigned char u8;
extern int GFL_NET_GetNegotiationNum(void);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *, unsigned int, unsigned int);
extern void DELIVERY_IRC_SetStepAtLine(int, int, int);
extern void DELIVERY_IRC_StepSendRequest(int *p);
void DELIVERY_IRC_StepWaitConnect(int *p) { if (GFL_NET_GetNegotiationNum() > 1) { GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x17, (u8)p[0]); DELIVERY_IRC_SetStepAtLine((int)p, (int)DELIVERY_IRC_StepSendRequest, 0x1af); } }
