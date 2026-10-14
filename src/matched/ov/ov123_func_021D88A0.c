/*
 * function: GSYNC_STATE_StatePrintFinalMessage
 * address: 0x021D88A0
 * packet: pkt_ov123_021D88A0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateWaitMessageClearStream 0x021D885C thumb ov123
 *   GSYNC_MESSAGE_PrintStreamId 0x021D57B8 thumb ov123
 */
#include "../include/Obj22977.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateWaitMessageClearStream(char *);
extern void GSYNC_MESSAGE_PrintStreamId(char *, int);
void GSYNC_STATE_StatePrintFinalMessage(char *p)
{
    GSYNC_MESSAGE_PrintStreamId(*(char * *)&((struct Obj22977 *)p)->f18, 19);
    GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateWaitMessageClearStream, 0x817);
}
