/*
 * function: GSYNC_STATE_StateWaitInputCancelSave
 * address:  0x021D6F70
 * packet:   pkt_ov123_021D6F70
 * region:   ov123
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetTrg  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   GAME_DATA_SaveCancel  0x02012E08  thumb
 *   GSYNC_STATE_CommitReceivedMon  0x021D8F58  thumb  ov123
 *   GSYNC_DOWNLOAD_CleanupOnce  0x021D5D58  thumb  ov123
 *   GSYNC_STATE_ChangeState  0x021D6EE0  thumb  ov123
 *   GSYNC_STATE_StateFreeDownloadAndExit  0x021D6F44  thumb  ov123
 */
#include "../include/Obj05363.h"

typedef unsigned int u32;

extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void GAME_DATA_SaveCancel(char *p);
extern void GSYNC_STATE_CommitReceivedMon(char *p);
extern int GSYNC_DOWNLOAD_CleanupOnce(char *p);
extern void GSYNC_STATE_ChangeState(unsigned char *p, u32 v, int unused);
typedef unsigned char  u8;
extern void GSYNC_STATE_StateFreeDownloadAndExit(u8 *p);

void GSYNC_STATE_StateWaitInputCancelSave(unsigned char *a)
{
    if (((struct Obj05363 *)a)->fAB != 0)
        return;
    if (KEY_GetTrg() == 0 && TOUCHPANEL_GetTrg() == 0)
        return;
    if (((struct Obj05363 *)a)->fAD != 0) {
        GAME_DATA_SaveCancel((char *)(((struct Obj05363 *)a)->f2C));
        ((struct Obj05363 *)a)->fAD = 0;
    }
    GSYNC_STATE_CommitReceivedMon((char *)a);
    if (((struct Obj05363 *)a)->f8 != 0) {
        if (GSYNC_DOWNLOAD_CleanupOnce((char *)(((struct Obj05363 *)a)->f8)) != 0)
            GSYNC_STATE_ChangeState(a, (int)GSYNC_STATE_StateFreeDownloadAndExit, 0x191);
        GSYNC_STATE_ChangeState(a, 0x021D706D, 0x193);
    } else {
        GSYNC_STATE_ChangeState(a, 0x021D706D, 0x196);
    }
}
