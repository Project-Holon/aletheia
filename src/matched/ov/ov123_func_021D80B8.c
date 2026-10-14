/*
 * function: GSYNC_STATE_StateSendListRequest
 * address: 0x021D80B8
 * packet: pkt_ov123_021D80B8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_STATE_IsConnectionAlive 0x021D6E70 thumb ov123
 *   GSYNC_STATE_IsCommReady 0x021D6EBC thumb ov123
 *   GSYNC_STATE_IsCommIdleWithTarget 0x021D6EA4 thumb ov123
 *   NHTTP_RAP_CreateRequest 0x021B95D4 thumb ov114
 *   NHTTP_RAP_StartConnection 0x021B9748 thumb ov114
 *   GSYNC_MESSAGE_PrintId 0x021D5950 thumb ov123
 *   GSYNC_MESSAGE_PrintInSubWindow 0x021D59E4 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateReceiveList 0x021D7F9C thumb ov123
 */
#include "../include/Obj05368.h"
extern int GSYNC_STATE_IsConnectionAlive(unsigned char *p);
extern int GSYNC_STATE_IsCommReady(unsigned char *p);
extern int GSYNC_STATE_IsCommIdleWithTarget(char *);
typedef unsigned char  u8;
extern int NHTTP_RAP_CreateRequest(int index, u8 *p);
extern int NHTTP_RAP_StartConnection(u8 *p);
typedef unsigned int   u32;
extern int GSYNC_MESSAGE_PrintId(u8 *p, int x);
extern void GSYNC_MESSAGE_PrintInSubWindow(char *);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateReceiveList(char *p);
void GSYNC_STATE_StateSendListRequest(char *p)
{
    if (GSYNC_STATE_IsConnectionAlive((unsigned char *)p) && !GSYNC_STATE_IsCommReady((unsigned char *)p)) {
        if (NHTTP_RAP_CreateRequest(2, ((struct Obj05368 *)p)->f10) && !NHTTP_RAP_StartConnection(((struct Obj05368 *)p)->f10)) {
            GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateReceiveList, 0x59d);
            return;
        }
    } else {
        if (GSYNC_STATE_IsCommIdleWithTarget(p)) {
            ((struct Obj05368 *)p)->f74 = 0;
            GSYNC_MESSAGE_PrintId((u8 *)(*(char * *)&((struct Obj05368 *)p)->f18), 42);
            GSYNC_MESSAGE_PrintInSubWindow(*(char * *)&((struct Obj05368 *)p)->f18);
        } else {
            ((struct Obj05368 *)p)->f74 = 0x42e;
        }
        GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateReceiveList, 0x5aa);
    }
}
