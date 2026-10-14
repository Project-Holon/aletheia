/*
 * function: GSYNC_STATE_StateReceiveParsedResponse
 * address: 0x021D8790
 * packet: pkt_ov123_021D8790
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
 *   GSYNC_STATE_ParseResponse 0x021D8650 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateWaitMessageEnd 0x021D83A4 thumb ov123
 */
#include "../include/Obj00063.h"
#include "../include/Obj22974.h"
#include "../include/Obj22975.h"
extern int GFL_NET_GetRunState(void);
typedef unsigned char  u8;
extern int NHTTP_RAP_GetResultCode(u8 *p);
extern int NHTTP_RAP_PollConnection(u8 *p);
extern char *NHTTP_RAP_GetRecvBuffer(void *);
extern void MI_CpuCopy8(const void *,void *,unsigned int);
extern int GSYNC_STATE_HandleHttpError(char *,int);
typedef unsigned int   u32;
extern void GSYNC_STATE_ParseResponse(char *p, int x, int *q);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateWaitMessageEnd(char *p);
void GSYNC_STATE_StateReceiveParsedResponse(char *p)
{
    char *q;
    if (GFL_NET_GetRunState()) {
        if (GSYNC_STATE_HandleHttpError(p,NHTTP_RAP_GetResultCode(((struct Obj00063 *)p)->f10))) return;
        if (NHTTP_RAP_PollConnection(((struct Obj00063 *)p)->f10)) return;
        q=NHTTP_RAP_GetRecvBuffer(((struct Obj00063 *)p)->f10);
        MI_CpuCopy8(q+0x80,*(char * *)&((struct Obj00063 *)p)->f20+0xc,0x44);
        ((struct Obj22975 *)(*(char * *)&((struct Obj00063 *)p)->f20))->f50=1;
        GSYNC_STATE_ParseResponse(p,((struct Obj22974 *)q)->f80,(int *)q);
    } else {
        GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateWaitMessageEnd,0x7d4);
    }
}
