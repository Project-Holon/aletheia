/*
 * function: GSYNC_STATE_StateShowResultMessage
 * address:  0x021D7180
 * packet:   pkt_ov123_021D7180
 * region:   ov123
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GSYNC_MESSAGE_UpdateStream  0x021D580C  thumb  ov123
 *   KEY_GetTrg  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   GSYNC_STATE_ChangeState  0x021D6EE0  thumb  ov123
 *   GSYNC_MESSAGE_ClearWindow  0x021D5A60  thumb  ov123
 *   GSYNC_MESSAGE_SetMonName  0x021D57D0  thumb  ov123
 *   GSYNC_MESSAGE_PrintStream  0x021D56FC  thumb  ov123
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb
 *   GFL_USE_PushBgm  0x02005E64  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GSYNC_STATE_StateClearMessageExit  0x021D70BC  thumb  ov123
 *   GSYNC_STATE_StateWaitEndingBgm  0x021D7130  thumb  ov123
 */
#include "../include/Obj03792.h"

typedef unsigned int u32;

typedef unsigned char  u8;
extern int GSYNC_MESSAGE_UpdateStream(char *p);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_MESSAGE_ClearWindow(char *p);
extern void GSYNC_MESSAGE_SetMonName(void *p, int msg, int n, void *mon);
extern void GSYNC_MESSAGE_PrintStream(char *p, int mode);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(int, int);
extern void GSYNC_STATE_StateClearMessageExit(char *p);
extern void GSYNC_STATE_StateWaitEndingBgm(char *p);

void GSYNC_STATE_StateShowResultMessage(int a)
{
    if (GSYNC_MESSAGE_UpdateStream((char *)(((struct Obj03792 *)a)->f18)) == 0)
        return;
    if (KEY_GetTrg() == 0 && TOUCHPANEL_GetTrg() == 0)
        return;
    if (((struct Obj03792 *)a)->f6C == 0) {
        GSYNC_STATE_ChangeState((u8 *)a, (int)GSYNC_STATE_StateClearMessageExit, 0x217);
        return;
    }
    GSYNC_MESSAGE_ClearWindow((char *)(((struct Obj03792 *)a)->f18));
    GSYNC_MESSAGE_SetMonName((void *)(((struct Obj03792 *)a)->f18), 0x16, ((struct Obj03792 *)a)->f6C,
                 (void *)(((struct Obj03792 *)a)->fC));
    GSYNC_MESSAGE_PrintStream((char *)(((struct Obj03792 *)a)->f18), 0);
    GFL_USE_SetBgmPlayerParam((void *)1);
    GFL_USE_PushBgm();
    GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
    ((struct Obj03792 *)a)->f78 = 0xb4;
    GSYNC_STATE_ChangeState((u8 *)a, (int)GSYNC_STATE_StateWaitEndingBgm, 0x222);
}
