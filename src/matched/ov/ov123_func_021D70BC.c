/*
 * function: GSYNC_STATE_StateClearMessageExit
 * address: 0x021D70BC
 * packet: pkt_ov123_021D70BC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gGsyncMessageIds 0x021DA844 data a4
 *   GSYNC_MESSAGE_ClearStream 0x021D584C thumb ov123
 *   GSYNC_MESSAGE_PrintId 0x021D5950 thumb ov123
 *   GSYNC_MESSAGE_PrintInWindow 0x021D5960 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateWaitMessageInput 0x021D7088 thumb ov123
 *   GSYNC_STATE_StateSetErrorExit 0x021D706C thumb ov123
 */
#include "../include/Obj06463.h"
typedef struct { int x[8]; } Table;
extern const Table gGsyncMessageIds;
extern void GSYNC_MESSAGE_ClearStream(char *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int GSYNC_MESSAGE_PrintId(u8 *p, int x);
extern void GSYNC_MESSAGE_PrintInWindow(char *,int,int);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateWaitMessageInput(char *);
extern void GSYNC_STATE_StateSetErrorExit(char *);
void GSYNC_STATE_StateClearMessageExit(char *p)
{
    Table t=gGsyncMessageIds;
    if (((struct Obj06463 *)p)->fA8) {
        GSYNC_MESSAGE_ClearStream(*(char * *)&((struct Obj06463 *)p)->f18);
        GSYNC_MESSAGE_PrintId((u8 *)(*(char * *)&((struct Obj06463 *)p)->f18),t.x[((struct Obj06463 *)p)->fA8]);
        GSYNC_MESSAGE_PrintInWindow(*(char * *)&((struct Obj06463 *)p)->f18,1,8);
        GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateWaitMessageInput,0x1f0);
    } else {
        GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateSetErrorExit,0x1f3);
    }
}
