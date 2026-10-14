/*
 * function: GSYNC_STATE_StateWaitMessageThenPrintThird
 * address: 0x021D8244
 * packet: pkt_ov123_021D8244
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateWaitInputSecond 0x021D8210 thumb ov123
 *   GSYNC_MESSAGE_UpdateStream 0x021D580C thumb ov123
 *   GSYNC_MESSAGE_PrintStreamId 0x021D57B8 thumb ov123
 */
#include "../include/Obj13993.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateWaitInputSecond(char *);
extern int GSYNC_MESSAGE_UpdateStream(char *);
extern void GSYNC_MESSAGE_PrintStreamId(char *, int);
void GSYNC_STATE_StateWaitMessageThenPrintThird(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream(*(char * *)&((struct Obj13993 *)p)->f18)) {
        GSYNC_MESSAGE_PrintStreamId(*(char * *)&((struct Obj13993 *)p)->f18, 49);
        GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateWaitInputSecond, 0x5f6);
    }
}
