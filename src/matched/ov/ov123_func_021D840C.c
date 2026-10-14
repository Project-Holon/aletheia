/*
 * function: GSYNC_STATE_StateWaitInputPrintNext
 * address: 0x021D840C
 * packet: pkt_ov123_021D840C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateWaitInputClearWindow 0x021D83C8 thumb ov123
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GSYNC_MESSAGE_PrintId 0x021D5950 thumb ov123
 *   GSYNC_MESSAGE_PrintInWindow 0x021D5960 thumb ov123
 */
#include "../include/Obj13994.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateWaitInputClearWindow(char *);
extern unsigned int KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern int GSYNC_MESSAGE_PrintId(u8 *p, int x);
extern void GSYNC_MESSAGE_PrintInWindow(char *, int, int);
void GSYNC_STATE_StateWaitInputPrintNext(char *p)
{
    if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
        GSYNC_MESSAGE_PrintId((u8 *)(*(char * *)&((struct Obj13994 *)p)->f18), 48);
        GSYNC_MESSAGE_PrintInWindow(*(char * *)&((struct Obj13994 *)p)->f18, 7, 14);
        GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateWaitInputClearWindow, 0x6ab);
    }
}
