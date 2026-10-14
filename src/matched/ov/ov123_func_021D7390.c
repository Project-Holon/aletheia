/*
 * function: GSYNC_STATE_StatePollResponse
 * address: 0x021D7390
 * packet: pkt_ov123_021D7390
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   NHTTP_RAP_GetResultCode 0x021B99DC thumb ov114
 *   NHTTP_RAP_PollConnection 0x021B9790 thumb ov114
 *   NHTTP_RAP_GetRecvBuffer 0x021B97F4 thumb ov114
 *   GSYNC_STATE_HandleHttpError 0x021D6E08 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateSaveFinishMessage 0x021D72D8 thumb ov123
 */
#include "../include/Obj06464.h"
typedef unsigned char  u8;
struct Sub02009448Obj;
extern int NHTTP_RAP_GetResultCode(u8 *p);
extern int NHTTP_RAP_PollConnection(u8 *p);
extern u8 *NHTTP_RAP_GetRecvBuffer(u8 *p);
extern int GSYNC_STATE_HandleHttpError(char *,int);
extern struct Sub02009448Obj *func_02009448(void *sys);
typedef unsigned int   u32;
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateSaveFinishMessage(char *);
void GSYNC_STATE_StatePollResponse(char *p)
{
    if (GSYNC_STATE_HandleHttpError(p,NHTTP_RAP_GetResultCode(((struct Obj06464 *)p)->f10))==0) {
        if (NHTTP_RAP_PollConnection(((struct Obj06464 *)p)->f10)==0) {
            NHTTP_RAP_GetRecvBuffer(((struct Obj06464 *)p)->f10);
            func_02009448(((struct Obj06464 *)p)->f28);
            ((struct Obj06464 *)p)->fAE=1;
            GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateSaveFinishMessage,0x2ae);
        }
    }
}
