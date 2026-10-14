/*
 * function: GSYNC_STATE_StateWaitInputThird
 * address: 0x021D8590
 * packet: pkt_ov123_021D8590
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateWaitMessageEnd 0x021D83A4 thumb ov123
 *   GSYNC_MESSAGE_UpdateStream 0x021D580C thumb ov123
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 */
#include "../include/Obj22969.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateWaitMessageEnd(char *);
extern int GSYNC_MESSAGE_UpdateStream(char *);
extern unsigned int KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
void GSYNC_STATE_StateWaitInputThird(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream(*(char * *)&((struct Obj22969 *)p)->f18)) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateWaitMessageEnd, 0x727);
        }
    }
}
