/*
 * function: GSYNC_STATE_StateReceiveFinalResponse
 * address: 0x021D88C0
 * packet: pkt_ov123_021D88C0
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
 *   MI_CpuCopy8 0x02082D44 arm
 *   GSYNC_STATE_HandleHttpError 0x021D6E08 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateFadeOutAfterMessage 0x021D6F04 thumb ov123
 *   GSYNC_STATE_StateErrorMessage 0x021D6FF0 thumb ov123
 */
#include "../include/Obj00063.h"
#include "../include/Obj22978.h"
#include "../include/Obj22979.h"
#include "../include/Obj22980.h"
extern int GFL_NET_GetRunState(void);
typedef unsigned char  u8;
extern int NHTTP_RAP_GetResultCode(u8 *p);
extern int NHTTP_RAP_PollConnection(u8 *p);
extern char *NHTTP_RAP_GetRecvBuffer(void *);
extern void MI_CpuCopy8(const void *,void *,unsigned int);
extern int GSYNC_STATE_HandleHttpError(char *,int);
typedef unsigned int   u32;
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateFadeOutAfterMessage(char *p);
extern void GSYNC_STATE_StateErrorMessage(char *p);
void GSYNC_STATE_StateReceiveFinalResponse(char *p)
{
    char *q;
    int state;
    if (GFL_NET_GetRunState()) {
        if (GSYNC_STATE_HandleHttpError(p,NHTTP_RAP_GetResultCode(((struct Obj00063 *)p)->f10))) return;
        if (NHTTP_RAP_PollConnection(((struct Obj00063 *)p)->f10)) return;
        q=NHTTP_RAP_GetRecvBuffer(((struct Obj00063 *)p)->f10);
        state=((struct Obj22978 *)q)->f0;
        if (state==0 || state==8) {
            MI_CpuCopy8(q+0x80,*(char * *)&((struct Obj00063 *)p)->f20+0x1d8,0x80);
            ((struct Obj22979 *)(*(char * *)&((struct Obj00063 *)p)->f20))->f1C8=5;
            GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateFadeOutAfterMessage,0x837);
        } else {
            ((struct Obj00063 *)p)->f80=state;
            GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateErrorMessage,0x842);
        }
    } else {
        ((struct Obj22980 *)(*(char * *)&((struct Obj00063 *)p)->f20))->f1C8=5;
        GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateFadeOutAfterMessage,0x849);
    }
}
