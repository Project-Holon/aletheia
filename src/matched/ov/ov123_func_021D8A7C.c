/*
 * function: GSYNC_STATE_StateWaitMessageThenNext
 * address: 0x021D8A7C
 * packet: pkt_ov123_021D8A7C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StatePlaySeWaitInput 0x021D8A38 thumb ov123
 *   GSYNC_MESSAGE_UpdateStream 0x021D580C thumb ov123
 */
#include "../include/Obj22981.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StatePlaySeWaitInput(char *);
extern int GSYNC_MESSAGE_UpdateStream(char *);
void GSYNC_STATE_StateWaitMessageThenNext(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream(*(char * *)&((struct Obj22981 *)p)->f18)) {
        GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StatePlaySeWaitInput, 0x8a0);
    }
}
