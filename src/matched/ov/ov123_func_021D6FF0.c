/*
 * unit: yes
 * function: GSYNC_STATE_StateErrorMessage,GSYNC_STATE_StateSetErrorExit
 * address: 0x021D6FF0
 * packet: pkt_ov123_021D6FF0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: unit includes the 28-byte store-and-tail stub at 021D706C.
 * symbols:
 *   NHTTP_RAP_DeleteConnection 0x021B9774 thumb ov114
 *   GSYNC_MESSAGE_ClearStream 0x021D584C thumb ov123
 *   GSYNC_MESSAGE_PrintId 0x021D5950 thumb ov123
 *   GSYNC_MESSAGE_PrintInWindow 0x021D5960 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateWaitInputCancelSave 0x021D6F70 thumb ov123
 *   GSYNC_STATE_StateFadeOutAfterMessage 0x021D6F04 thumb ov123
 */
#include "../include/Obj02182.h"
#include "../include/Obj22956.h"
#include "../include/Obj22957.h"
typedef unsigned char  u8;
extern void NHTTP_RAP_DeleteConnection(u8 *p);
extern void GSYNC_MESSAGE_ClearStream(char *);
typedef unsigned int   u32;
extern int GSYNC_MESSAGE_PrintId(u8 *p, int x);
extern void GSYNC_MESSAGE_PrintInWindow(char *,int,int);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateWaitInputCancelSave(unsigned char *a);
extern void GSYNC_STATE_StateFadeOutAfterMessage(char *);
void GSYNC_STATE_StateErrorMessage(char *p)
{
    int n=((struct Obj02182 *)p)->f80+29;
    if (((struct Obj02182 *)p)->f10) NHTTP_RAP_DeleteConnection(((struct Obj02182 *)p)->f10);
    if (((struct Obj02182 *)p)->f80==0xfff0) n=39;
    else if (((struct Obj02182 *)p)->f80==0xfff1) n=40;
    else if (((struct Obj02182 *)p)->f80==0xfff2) n=41;
    else if (((struct Obj02182 *)p)->f80==0xfff3) n=38;
    else if (((struct Obj02182 *)p)->f80<=0 || ((struct Obj02182 *)p)->f80>=10) n=38;
    GSYNC_MESSAGE_ClearStream(*(char * *)&((struct Obj02182 *)p)->f18);
    GSYNC_MESSAGE_PrintId((u8 *)(*(char * *)&((struct Obj02182 *)p)->f18),n);
    GSYNC_MESSAGE_PrintInWindow(*(char * *)&((struct Obj02182 *)p)->f18,1,16);
    GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateWaitInputCancelSave,0x1b9);
}
void GSYNC_STATE_StateSetErrorExit(char *p)
{
    ((struct Obj22957 *)(*(char * *)&((struct Obj22956 *)p)->f20))->f1C8=6;
    GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateFadeOutAfterMessage,0x1c9);
}
