/*
 * function: GSYNC_STATE_StateWaitMessageThenPrintFifth
 * address: 0x021D8624
 * packet: pkt_ov123_021D8624
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateWaitInputFourth 0x021D85F0 thumb ov123
 *   GSYNC_MESSAGE_UpdateStream 0x021D580C thumb ov123
 *   GSYNC_MESSAGE_PrintStreamId 0x021D57B8 thumb ov123
 */
#include "../include/Obj13996.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateWaitInputFourth(char *);
extern int GSYNC_MESSAGE_UpdateStream(char *);
extern void GSYNC_MESSAGE_PrintStreamId(char *, int);
void GSYNC_STATE_StateWaitMessageThenPrintFifth(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream(*(char * *)&((struct Obj13996 *)p)->f18)) {
        GSYNC_MESSAGE_PrintStreamId(*(char * *)&((struct Obj13996 *)p)->f18, 20);
        GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateWaitInputFourth, 0x758);
    }
}
