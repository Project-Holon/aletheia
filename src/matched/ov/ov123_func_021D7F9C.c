/*
 * function: GSYNC_STATE_StateReceiveList
 * address: 0x021D7F9C
 * packet: pkt_ov123_021D7F9C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_STATE_IsConnectionAlive 0x021D6E70 thumb ov123
 *   GSYNC_STATE_IsCommReady 0x021D6EBC thumb ov123
 *   GSYNC_DISP_UpdateProgressPosition 0x021D66D0 thumb ov123
 *   GSYNC_STATE_HandleHttpError 0x021D6E08 thumb ov123
 *   GSYNC_STATE_PrepareReceivedList 0x021D7E58 thumb ov123
 *   GSYNC_MESSAGE_PrintId 0x021D5950 thumb ov123
 *   GSYNC_MESSAGE_PrintInSubWindow 0x021D59E4 thumb ov123
 *   GSYNC_MESSAGE_ClearWindow 0x021D5A60 thumb ov123
 *   GSYNC_STATE_IsCommIdleWithTarget 0x021D6EA4 thumb ov123
 *   GSYNC_STATE_UpdateCurrentEntry 0x021D7F5C thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateSaveStart 0x021D746C thumb ov123
 *   GSYNC_STATE_StateErrorMessage 0x021D6FF0 thumb ov123
 *   NHTTP_RAP_GetResultCode 0x021B99DC thumb ov114
 *   NHTTP_RAP_PollConnection 0x021B9790 thumb ov114
 *   NHTTP_RAP_GetRecvBuffer 0x021B97F4 thumb ov114
 *   func_02030734 0x02030734 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   gGsyncStateAllocSource 0x021DAB78 data ov123 a1
 */
#include "../include/Obj00063.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GSYNC_STATE_IsConnectionAlive(u8 *p);
extern int GSYNC_STATE_IsCommReady(u8 *p);
extern void GSYNC_DISP_UpdateProgressPosition(u8 *,int);
extern int GSYNC_STATE_HandleHttpError(char *,int);
struct Sub02009448Obj;
extern int NHTTP_RAP_GetResultCode(u8 *p);
extern int NHTTP_RAP_PollConnection(u8 *p);
extern char *NHTTP_RAP_GetRecvBuffer(void *);
extern struct Sub02009448Obj *func_02009448(void *sys);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void MI_CpuCopy8(const void *,void *,u32);
extern void GSYNC_STATE_PrepareReceivedList(u8 *p, void *h, u8 *q, int *r);
extern int GSYNC_MESSAGE_PrintId(u8 *,int);
extern void GSYNC_MESSAGE_PrintInSubWindow(char *);
extern void GSYNC_MESSAGE_ClearWindow(char *);
extern int GSYNC_STATE_IsCommIdleWithTarget(char *);
extern int GSYNC_STATE_UpdateCurrentEntry(char *);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateSaveStart(int a);
extern void GSYNC_STATE_StateErrorMessage(char *);
extern const char gGsyncStateAllocSource[];
void GSYNC_STATE_StateReceiveList(char *p)
{
    char *q, *data;
    void *v, *allocated;
    if (GSYNC_STATE_IsConnectionAlive((u8 *)p) && !GSYNC_STATE_IsCommReady((u8 *)p)) {
        if (((struct Obj00063 *)p)->f70<30) ++((struct Obj00063 *)p)->f70;
        GSYNC_DISP_UpdateProgressPosition(*(u8 * *)&((struct Obj00063 *)p)->f14,((struct Obj00063 *)p)->f70);
        if (GSYNC_STATE_HandleHttpError(p,NHTTP_RAP_GetResultCode(((struct Obj00063 *)p)->f10))) return;
        if (NHTTP_RAP_PollConnection(((struct Obj00063 *)p)->f10)) return;
        q=NHTTP_RAP_GetRecvBuffer(((struct Obj00063 *)p)->f10);
        v=func_02009448(((struct Obj00063 *)p)->f28);
        data=q+0x80;
        allocated=func_02030734(((struct Obj00063 *)p)->f0,0x11c,1,gGsyncStateAllocSource,0x573);
        ((struct Obj00063 *)p)->f38=allocated;
        MI_CpuCopy8(data,allocated,0x11c);
        GSYNC_STATE_PrepareReceivedList((u8 *)p,v,(u8 *)data,(int *)q);
        return;
    } else {
        ++((struct Obj00063 *)p)->f74;
        if (((struct Obj00063 *)p)->f70<30) ++((struct Obj00063 *)p)->f70;
        if (((struct Obj00063 *)p)->f74==360) {
            GSYNC_MESSAGE_PrintId(*(u8 * *)&((struct Obj00063 *)p)->f18,43);
            GSYNC_MESSAGE_PrintInSubWindow(*(char * *)&((struct Obj00063 *)p)->f18);
        } else if (((struct Obj00063 *)p)->f74==720) {
            GSYNC_MESSAGE_PrintId(*(u8 * *)&((struct Obj00063 *)p)->f18,44);
            GSYNC_MESSAGE_PrintInSubWindow(*(char * *)&((struct Obj00063 *)p)->f18);
        } else if (((struct Obj00063 *)p)->f74==1080) {
            if (GSYNC_STATE_IsCommIdleWithTarget(p)) GSYNC_MESSAGE_ClearWindow(*(char * *)&((struct Obj00063 *)p)->f18);
            if (GSYNC_STATE_UpdateCurrentEntry(p)) {
                GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateSaveStart,0x58c);
            } else {
                ((struct Obj00063 *)p)->f80=9;
                GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateErrorMessage,0x591);
            }
        }
        GSYNC_DISP_UpdateProgressPosition(*(u8 * *)&((struct Obj00063 *)p)->f14,((struct Obj00063 *)p)->f70);
    }
}
