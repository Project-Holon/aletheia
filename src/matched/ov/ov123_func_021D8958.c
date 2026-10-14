/*
 * function: GSYNC_STATE_StateSendFinalRequest
 * address: 0x021D8958
 * packet: pkt_ov123_021D8958
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020093C8 0x020093C8 thumb
 *   func_0203F4E4 0x0203F4E4 arm
 *   func_0203F540 0x0203F540 arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   NHTTP_RAP_CreateRequest 0x021B95D4 thumb ov114
 *   NHTTP_RAP_StartConnection 0x021B9748 thumb ov114
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateWaitMessageThenPrintSecond 0x021D81E4 thumb ov123
 *   GSYNC_STATE_StateReceiveFinalResponse 0x021D88C0 thumb ov123
 */
#include "../include/Obj06468.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct RtcDate { int year; u32 month; int day, week; };
struct Sub02008AECSession;
struct Sub02009448Obj;
extern struct Sub02008AECSession *func_02008B14(void *sys);
extern int func_02008BD0(const struct Sub02008AECSession *s);
extern struct Sub02009448Obj *func_02009448(void *sys);
struct Sub02009210Obj;
extern u32 func_020093C8(const struct Sub02009210Obj *obj);
extern void func_0203F4E4(struct RtcDate *);
extern int func_0203F540(struct RtcDate *);
extern int GFL_NET_GetRunState(void);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern int NHTTP_RAP_CreateRequest(int index, u8 *p);
extern int NHTTP_RAP_StartConnection(u8 *p);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateWaitMessageThenPrintSecond(char *);
extern void GSYNC_STATE_StateReceiveFinalResponse(char *);
void GSYNC_STATE_StateSendFinalRequest(char *p)
{
    struct RtcDate saved, current;
    u32 value;
    int day;
    if (func_02008BD0(func_02008B14(((struct Obj06468 *)p)->f28)) && ((struct Obj06468 *)p)->fAC) {
        GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateWaitMessageThenPrintSecond,0x85c);
        return;
    }
    value=func_020093C8((const struct Sub02009210Obj *)func_02009448(((struct Obj06468 *)p)->f28));
    saved.year=(u8)(value>>24);
    saved.month=(u8)(value>>16);
    saved.day=(u8)(value>>8);
    saved.week=(u8)value;
    func_0203F4E4(&current);
    day=func_0203F540(&saved);
    if (day==func_0203F540(&current)) {
        GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateWaitMessageThenPrintSecond,0x869);
        return;
    }
    if (GFL_NET_GetRunState()) {
        if (NHTTP_RAP_CreateRequest(1,((struct Obj06468 *)p)->f10) && !NHTTP_RAP_StartConnection(((struct Obj06468 *)p)->f10))
            GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateReceiveFinalResponse,0x871);
    } else {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg())
            GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateReceiveFinalResponse,0x878);
    }
}
