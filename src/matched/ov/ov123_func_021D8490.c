/*
 * function: GSYNC_STATE_StateReceiveResponse
 * address: 0x021D8490
 * packet: pkt_ov123_021D8490
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   NHTTP_RAP_GetResultCode 0x021B99DC thumb ov114
 *   NHTTP_RAP_PollConnection 0x021B9790 thumb ov114
 *   NHTTP_RAP_GetRecvBuffer 0x021B97F4 thumb ov114
 *   GSYNC_STATE_HandleHttpError 0x021D6E08 thumb ov123
 *   GSYNC_MESSAGE_ClearStream 0x021D584C thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateSendFinalRequest 0x021D8958 thumb ov123
 *   GSYNC_STATE_StatePrintErrorMessage 0x021D8448 thumb ov123
 *   GSYNC_STATE_StateErrorMessage 0x021D6FF0 thumb ov123
 */
#include "../include/Obj00063.h"
#include "../include/Obj10448.h"
extern int GFL_NET_GetRunState(void);
typedef unsigned char  u8;
extern int NHTTP_RAP_GetResultCode(u8 *p);
extern int NHTTP_RAP_PollConnection(u8 *p);
extern char *NHTTP_RAP_GetRecvBuffer(void *);
extern int GSYNC_STATE_HandleHttpError(char *, int);
extern void GSYNC_MESSAGE_ClearStream(char *);
typedef unsigned int   u32;
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateSendFinalRequest(char *p);
extern void GSYNC_STATE_StatePrintErrorMessage(char *p);
extern void GSYNC_STATE_StateErrorMessage(char *p);
void GSYNC_STATE_StateReceiveResponse(char *p)
{
    char *q;
    if (GFL_NET_GetRunState()) {
        if (GSYNC_STATE_HandleHttpError(p, NHTTP_RAP_GetResultCode(((struct Obj00063 *)p)->f10))) return;
        if (NHTTP_RAP_PollConnection(((struct Obj00063 *)p)->f10)) return;
        q = NHTTP_RAP_GetRecvBuffer(((struct Obj00063 *)p)->f10);
        if (((struct Obj10448 *)q)->f0 == 2) {
            GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateSendFinalRequest, 0x6d4);
            return;
        }
        if (((struct Obj10448 *)q)->f0 == 0) {
            GSYNC_MESSAGE_ClearStream(*(char * *)&((struct Obj00063 *)p)->f18);
            GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StatePrintErrorMessage, 0x6d8);
            return;
        }
        ((struct Obj00063 *)p)->f80 = ((struct Obj10448 *)q)->f0;
        GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateErrorMessage, 0x6dc);
        return;
    } else {
        GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateSendFinalRequest, 0x6e2);
    }
}
