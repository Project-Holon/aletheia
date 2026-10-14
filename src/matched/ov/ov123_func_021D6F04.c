/*
 * function: GSYNC_STATE_StateFadeOutAfterMessage
 * address: 0x021D6F04
 * packet: pkt_ov123_021D6F04
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_MESSAGE_UpdateStream 0x021D580C thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateWaitFade 0x021D6EE8 thumb ov123
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 */
#include "../include/Obj13984.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern int GSYNC_MESSAGE_UpdateStream(char *);
extern void WIPE_SYS_Start(void *, u32, u32, u32, u32, u32, u32);
typedef unsigned char  u8;
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateWaitFade(char *);
void GSYNC_STATE_StateFadeOutAfterMessage(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream(*(char * *)&((struct Obj13984 *)p)->f18)) {
        WIPE_SYS_Start(0,0,0,0,6,1,((struct Obj13984 *)p)->f0);
        GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateWaitFade,0x16b);
    }
}
