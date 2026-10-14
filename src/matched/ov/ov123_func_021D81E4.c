/*
 * function: GSYNC_STATE_StateWaitMessageThenPrintSecond
 * address: 0x021D81E4
 * packet: pkt_ov123_021D81E4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateWaitInputFirst 0x021D81B4 thumb ov123
 *   GSYNC_MESSAGE_UpdateStream 0x021D580C thumb ov123
 *   GSYNC_MESSAGE_PrintStreamId 0x021D57B8 thumb ov123
 */
#include "../include/Obj13992.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateWaitInputFirst(char *);
extern int GSYNC_MESSAGE_UpdateStream(char *);
extern void GSYNC_MESSAGE_PrintStreamId(char *, int);
void GSYNC_STATE_StateWaitMessageThenPrintSecond(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream(*(char * *)&((struct Obj13992 *)p)->f18)) {
        GSYNC_MESSAGE_PrintStreamId(*(char * *)&((struct Obj13992 *)p)->f18, 16);
        GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateWaitInputFirst, 0x5de);
    }
}
