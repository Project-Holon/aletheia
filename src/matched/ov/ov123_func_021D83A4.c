/*
 * function: GSYNC_STATE_StateWaitMessageEnd
 * address: 0x021D83A4
 * packet: pkt_ov123_021D83A4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateShowEmptyMessage 0x021D834C thumb ov123
 *   GSYNC_MESSAGE_UpdateStream 0x021D580C thumb ov123
 */
#include "../include/Obj22967.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateShowEmptyMessage(char *);
extern int GSYNC_MESSAGE_UpdateStream(char *);
void GSYNC_STATE_StateWaitMessageEnd(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream(*(char * *)&((struct Obj22967 *)p)->f18)) {
        GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateShowEmptyMessage, 0x68d);
    }
}
