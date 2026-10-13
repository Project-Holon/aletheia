/*
 * function: DELIVERY_IRC_StepStartEndSync
 * address: 0x02157AC8
 * packet: pkt_ov010_02157AC8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   DELIVERY_IRC_SetStepAtLine 0x02157960 thumb ov010
 *   DELIVERY_IRC_StepWaitEndSync 0x02157A78 thumb ov010
 */
typedef unsigned char u8;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void func_02039C68(struct Link *, unsigned int, unsigned int);
extern void DELIVERY_IRC_SetStepAtLine(int, int, int);
typedef unsigned int   u32;
extern void DELIVERY_IRC_StepWaitEndSync(u32 *p);
void DELIVERY_IRC_StepStartEndSync(int *p) { int k = 0x23; func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), k, (u8)p[0]); DELIVERY_IRC_SetStepAtLine((int)p, (int)DELIVERY_IRC_StepWaitEndSync, k + 0xfc); }
