/*
 * function: GSYNC_STATE_StateCreateReceivedMonIcon
 * address: 0x021D8E98
 * packet: pkt_ov123_021D8E98
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_Dummy 0x020185F0 thumb
 *   GSYNC_DISP_CreateMonIconActor 0x021D6458 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateTransferAnimationEffect 0x021D8E68 thumb ov123
 */
#include "../include/Obj10452.h"
extern int POKE_TOOL_Dummy(void *);
struct Obj02181;
extern void GSYNC_DISP_CreateMonIconActor(struct Obj02181 *p, void *n, int i);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateTransferAnimationEffect(char *p);
void GSYNC_STATE_StateCreateReceivedMonIcon(char *p) { GSYNC_DISP_CreateMonIconActor(((struct Obj10452 *)p)->f14,(void *)POKE_TOOL_Dummy(((struct Obj10452 *)p)->fC),1); ((struct Obj10452 *)p)->f60=10; GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateTransferAnimationEffect,0x9f6); }
