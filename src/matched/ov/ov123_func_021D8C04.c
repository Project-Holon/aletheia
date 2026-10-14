/*
 * function: GSYNC_STATE_StateReceiveRecordResponse
 * address: 0x021D8C04
 * packet: pkt_ov123_021D8C04
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_DISP_UpdateParticles 0x021D6934 thumb ov123
 *   GSYNC_STATE_IsCommIdleWithTarget 0x021D6EA4 thumb ov123
 *   GSYNC_STATE_IsConnectionAlive 0x021D6E70 thumb ov123
 *   GSYNC_MESSAGE_PrintId 0x021D5950 thumb ov123
 *   GSYNC_MESSAGE_PrintInSubWindow 0x021D59E4 thumb ov123
 *   GSYNC_MESSAGE_ClearWindow 0x021D5A60 thumb ov123
 *   GSYNC_DISP_UpdateProgressPosition 0x021D66D0 thumb ov123
 *   GSYNC_STATE_HandleHttpError 0x021D6E08 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateTrainerRecordSaveStart 0x021D8B7C thumb ov123
 *   GSYNC_STATE_StateErrorMessage 0x021D6FF0 thumb ov123
 *   NHTTP_RAP_GetResultCode 0x021B99DC thumb ov114
 *   NHTTP_RAP_PollConnection 0x021B9790 thumb ov114
 *   NHTTP_RAP_GetRecvBuffer 0x021B97F4 thumb ov114
 */
#include "../include/Obj00063.h"
#include "../include/Obj22982.h"
typedef unsigned char u8;
struct Obj;
struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
extern void GSYNC_DISP_UpdateParticles(struct Obj *p);
extern int GSYNC_STATE_IsCommIdleWithTarget(char *);
typedef unsigned int   u32;
extern int GSYNC_STATE_IsConnectionAlive(u8 *p);
extern int GSYNC_MESSAGE_PrintId(u8 *,int);
extern void GSYNC_MESSAGE_PrintInSubWindow(char *);
extern void GSYNC_MESSAGE_ClearWindow(char *);
extern void GSYNC_DISP_UpdateProgressPosition(u8 *,int);
extern int GSYNC_STATE_HandleHttpError(char *,int);
extern int NHTTP_RAP_GetResultCode(u8 *p);
extern int NHTTP_RAP_PollConnection(u8 *p);
extern char *NHTTP_RAP_GetRecvBuffer(void *);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateTrainerRecordSaveStart(char *);
extern void GSYNC_STATE_StateErrorMessage(char *);
void GSYNC_STATE_StateReceiveRecordResponse(char *p)
{
    char *q;
    int state;
    func_02009448(((struct Obj00063 *)p)->f28);
    GSYNC_DISP_UpdateParticles(((struct Obj00063 *)p)->f14);
    if (GSYNC_STATE_IsCommIdleWithTarget(p)) {
        if (((struct Obj00063 *)p)->f74==0) {
            GSYNC_MESSAGE_PrintId(*(u8 * *)&((struct Obj00063 *)p)->f18,42);
            GSYNC_MESSAGE_PrintInSubWindow(*(char * *)&((struct Obj00063 *)p)->f18);
        } else if (((struct Obj00063 *)p)->f74==360) {
            GSYNC_MESSAGE_PrintId(*(u8 * *)&((struct Obj00063 *)p)->f18,43);
            GSYNC_MESSAGE_PrintInSubWindow(*(char * *)&((struct Obj00063 *)p)->f18);
        } else if (((struct Obj00063 *)p)->f74==720) {
            GSYNC_MESSAGE_PrintId(*(u8 * *)&((struct Obj00063 *)p)->f18,44);
            GSYNC_MESSAGE_PrintInSubWindow(*(char * *)&((struct Obj00063 *)p)->f18);
        }
        ++((struct Obj00063 *)p)->f74;
    }
    if (GSYNC_STATE_IsConnectionAlive((u8 *)p)) {
        if (((struct Obj00063 *)p)->f70<50) ++((struct Obj00063 *)p)->f70;
        GSYNC_DISP_UpdateProgressPosition(*(u8 * *)&((struct Obj00063 *)p)->f14,((struct Obj00063 *)p)->f70);
        if (GSYNC_STATE_HandleHttpError(p,NHTTP_RAP_GetResultCode(((struct Obj00063 *)p)->f10))) return;
        if (NHTTP_RAP_PollConnection(((struct Obj00063 *)p)->f10)) return;
        q=NHTTP_RAP_GetRecvBuffer(((struct Obj00063 *)p)->f10);
        if (GSYNC_STATE_IsCommIdleWithTarget(p)) GSYNC_MESSAGE_ClearWindow(*(char * *)&((struct Obj00063 *)p)->f18);
        state=((struct Obj22982 *)q)->f0;
        if (state==0) {
            GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateTrainerRecordSaveStart,0x955);
            return;
        }
        ((struct Obj00063 *)p)->f80=state;
        GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateErrorMessage,0x959);
        return;
    } else {
        GSYNC_DISP_UpdateProgressPosition(*(u8 * *)&((struct Obj00063 *)p)->f14,((struct Obj00063 *)p)->f68);
        if (++((struct Obj00063 *)p)->f68==100) {
            if (GSYNC_STATE_IsCommIdleWithTarget(p)) GSYNC_MESSAGE_ClearWindow(*(char * *)&((struct Obj00063 *)p)->f18);
            GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateTrainerRecordSaveStart,0x967);
        }
    }
}
