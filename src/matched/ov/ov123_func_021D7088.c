/*
 * function: GSYNC_STATE_StateWaitMessageInput
 * address: 0x021D7088
 * packet: pkt_ov123_021D7088
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_MESSAGE_UpdateStream 0x021D580C thumb ov123
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateSetErrorExit 0x021D706C thumb ov123
 */
#include "../include/Obj22958.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GSYNC_MESSAGE_UpdateStream(char *);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateSetErrorExit(char *p);
void GSYNC_STATE_StateWaitMessageInput(char *p) { if(GSYNC_MESSAGE_UpdateStream(*(char * *)&((struct Obj22958 *)p)->f18) && (KEY_GetTrg() || TOUCHPANEL_GetTrg())) GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateSetErrorExit,0x1d9); }
