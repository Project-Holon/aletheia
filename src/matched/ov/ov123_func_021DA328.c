/*
 * function: PDWACC_STATE_StateReceiveResponse
 * address: 0x021DA328
 * packet: pkt_ov123_021DA328
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
 *   PDWACC_STATE_HandleHttpError 0x021D9FD4 thumb ov123
 *   PDWACC_MESSAGE_ClearStream 0x021D9634 thumb ov123
 *   PDWACC_STATE_ChangeState 0x021DA034 thumb ov123
 *   PDWACC_STATE_StatePrintNumbersMessage 0x021DA1A0 thumb ov123
 *   PDWACC_STATE_StatePrintError 0x021DA1EC thumb ov123
 */
#include "../include/Obj03804.h"
extern int GFL_NET_GetRunState(void);
typedef unsigned char  u8;
extern int NHTTP_RAP_GetResultCode(u8 *p);
extern int NHTTP_RAP_PollConnection(u8 *p);
extern u8 *NHTTP_RAP_GetRecvBuffer(u8 *p);
extern int PDWACC_STATE_HandleHttpError(char *,int);
extern void PDWACC_MESSAGE_ClearStream(char *p);
extern void PDWACC_STATE_ChangeState(char *p, int n, int unused);
extern void PDWACC_STATE_StatePrintNumbersMessage(char *p);
extern void PDWACC_STATE_StatePrintError(char *p);
void PDWACC_STATE_StateReceiveResponse(char *p)
{
    int *q;
    if (GFL_NET_GetRunState() && !PDWACC_STATE_HandleHttpError(p,NHTTP_RAP_GetResultCode(((struct Obj03804 *)p)->f8)) && !NHTTP_RAP_PollConnection(((struct Obj03804 *)p)->f8)) {
        q = (int *)NHTTP_RAP_GetRecvBuffer(((struct Obj03804 *)p)->f8);
        PDWACC_MESSAGE_ClearStream(((struct Obj03804 *)p)->f10);
        if (*q == 2) { PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StatePrintNumbersMessage,0x1d4); return; }
        if (*q == 0) { PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StatePrintNumbersMessage,0x1d7); return; }
        ((struct Obj03804 *)p)->f70 = *q;
        PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StatePrintError,0x1db);
    }
}
