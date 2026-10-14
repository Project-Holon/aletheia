/*
 * function: GSYNC_STATE_StateSendParsedRequest
 * address: 0x021D87F8
 * packet: pkt_ov123_021D87F8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_MESSAGE_PrintStreamId 0x021D57B8 thumb ov123
 *   GSYNC_MESSAGE_RestartTimeIcon 0x021D5A7C thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateReceiveParsedResponse 0x021D8790 thumb ov123
 *   NHTTP_RAP_CreateRequest 0x021B95D4 thumb ov114
 *   NHTTP_RAP_StartConnection 0x021B9748 thumb ov114
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 */
#include "../include/Obj08113.h"

typedef unsigned int u32;
extern void GSYNC_MESSAGE_PrintStreamId(char *,int);
extern void GSYNC_MESSAGE_RestartTimeIcon(char *);
extern void GSYNC_STATE_ChangeState(unsigned char *p, u32 v, int unused);
typedef unsigned char  u8;
extern void GSYNC_STATE_StateReceiveParsedResponse(char *p);
extern int NHTTP_RAP_CreateRequest(int index, u8 *p);
extern int NHTTP_RAP_StartConnection(u8 *p);
extern int GFL_NET_GetRunState(void);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
void GSYNC_STATE_StateSendParsedRequest(char *p)
{
    GSYNC_MESSAGE_PrintStreamId(*(char * *)&((struct Obj08113 *)p)->f18,13);
    GSYNC_MESSAGE_RestartTimeIcon(*(char * *)&((struct Obj08113 *)p)->f18);
    if (GFL_NET_GetRunState()) {
        if (NHTTP_RAP_CreateRequest(0,((struct Obj08113 *)p)->f10)) {
            if (!NHTTP_RAP_StartConnection(((struct Obj08113 *)p)->f10))
                GSYNC_STATE_ChangeState((unsigned char *)p,(int)GSYNC_STATE_StateReceiveParsedResponse,0x7ea);
        }
    } else {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg())
            GSYNC_STATE_ChangeState((unsigned char *)p,(int)GSYNC_STATE_StateReceiveParsedResponse,0x7f1);
    }
}
