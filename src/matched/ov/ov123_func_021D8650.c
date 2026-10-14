/*
 * function: GSYNC_STATE_ParseResponse
 * address: 0x021D8650
 * packet: pkt_ov123_021D8650
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateWaitMessageEnd 0x021D83A4 thumb ov123
 *   GSYNC_STATE_StateWaitMessageThenPrintFourth 0x021D85C4 thumb ov123
 *   GSYNC_STATE_StateWaitMessageThenPrintFifth 0x021D8624 thumb ov123
 *   GSYNC_STATE_StatePrintErrorMessage 0x021D8448 thumb ov123
 *   GSYNC_STATE_StateSendFinalRequest 0x021D8958 thumb ov123
 *   GSYNC_STATE_StateErrorMessage 0x021D6FF0 thumb ov123
 *   GSYNC_STATE_StateSendResponse 0x021D8520 thumb ov123
 */
#include "../include/Obj00063.h"
#include "../include/Obj22971.h"
#include "../include/Obj22972.h"
#include "../include/Obj22973.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateWaitMessageEnd(char *);
extern void GSYNC_STATE_StateWaitMessageThenPrintFourth(char *);
extern void GSYNC_STATE_StateWaitMessageThenPrintFifth(char *);
extern void GSYNC_STATE_StatePrintErrorMessage(char *);
extern void GSYNC_STATE_StateSendFinalRequest(char *);
extern void GSYNC_STATE_StateErrorMessage(char *);
extern void GSYNC_STATE_StateSendResponse(char *);
void GSYNC_STATE_ParseResponse(char *p,int x,int *q)
{
    int state;
    switch (*q) {
    case 0:
        state=((struct Obj22971 *)(*(char * *)&((struct Obj00063 *)p)->f20))->f1C8;
        switch (state) {
        case 0:
            if (x==0) GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateWaitMessageEnd,0x774);
            else if (x==3) GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateWaitMessageEnd,0x777);
            else if (x==1) GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateWaitMessageThenPrintFourth,0x77b);
            else if (x==2) GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateWaitMessageThenPrintFifth,0x77f);
            else if (x==4) GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateWaitMessageEnd,0x782);
            else GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateWaitMessageEnd,0x787);
            break;
        case 3:
            if (((struct Obj00063 *)p)->fAF==0) GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StatePrintErrorMessage,0x78c);
            else GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateSendFinalRequest,0x78f);
            break;
        }
        break;
    case 5:
        if (((struct Obj22972 *)(*(char * *)&((struct Obj00063 *)p)->f20))->f1C8==3)
            GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateSendFinalRequest,0x797);
        else {
            ((struct Obj00063 *)p)->f80=*q;
            GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateErrorMessage,0x79b);
        }
        break;
    case 8:
        switch (((struct Obj22973 *)(*(char * *)&((struct Obj00063 *)p)->f20))->f1C8) {
        case 0: GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateWaitMessageEnd,0x7a2); break;
        case 3: GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateSendResponse,0x7a6); break;
        }
        break;
    default:
        ((struct Obj00063 *)p)->f80=*q;
        GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateErrorMessage,0x7ac);
        break;
    }
}
