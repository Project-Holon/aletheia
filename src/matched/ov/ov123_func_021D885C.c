/*
 * function: GSYNC_STATE_StateWaitMessageClearStream
 * address: 0x021D885C
 * packet: pkt_ov123_021D885C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_MESSAGE_UpdateStream 0x021D580C thumb ov123
 *   GSYNC_MESSAGE_ClearStream 0x021D584C thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateFadeOutAfterMessage 0x021D6F04 thumb ov123
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 */
#include "../include/Obj10450.h"
#include "../include/Obj22976.h"

typedef unsigned int u32;
extern int GSYNC_MESSAGE_UpdateStream(char *);
extern void GSYNC_MESSAGE_ClearStream(char *);
typedef unsigned char  u8;
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateFadeOutAfterMessage(char *p);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
void GSYNC_STATE_StateWaitMessageClearStream(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream(*(char * *)&((struct Obj10450 *)p)->f18)) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            ((struct Obj22976 *)(*(char * *)&((struct Obj10450 *)p)->f20))->f1C8 = 1;
            GSYNC_MESSAGE_ClearStream(*(char * *)&((struct Obj10450 *)p)->f18);
            GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateFadeOutAfterMessage, 0x808);
        }
    }
}
