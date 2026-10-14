/*
 * function: GSYNC_STATE_StateWaitDownloadIdle
 * address: 0x021D7910
 * packet: pkt_ov123_021D7910
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateErrorMessage 0x021D6FF0 thumb ov123
 *   GSYNC_STATE_StateMusicalSaveRetry 0x021D78C0 thumb ov123
 *   GSYNC_DOWNLOAD_Reset 0x021D5C2C thumb ov123
 *   GSYNC_DOWNLOAD_ClearResult 0x021D5C0C thumb ov123
 *   GSYNC_DOWNLOAD_IsBusy 0x021D5C9C thumb ov123
 */
#include "../include/Obj08112.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int GSYNC_DOWNLOAD_Reset(char *p);
extern int GSYNC_DOWNLOAD_ClearResult(char *p);
extern void GSYNC_DOWNLOAD_IsBusy(char *p);
extern void GSYNC_STATE_StateErrorMessage(char *p);
extern void GSYNC_STATE_StateMusicalSaveRetry(int a);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
void GSYNC_STATE_StateWaitDownloadIdle(int a)
{
    if(GSYNC_DOWNLOAD_Reset((char *)(((struct Obj08112 *)a)->f8))) {
        ((struct Obj08112 *)a)->f80=0xfff0;
        GSYNC_STATE_ChangeState((u8 *)a,(int)GSYNC_STATE_StateErrorMessage,0x3dd);
        return;
    }
    if(GSYNC_DOWNLOAD_ClearResult((char *)(((struct Obj08112 *)a)->f8))) {
        GSYNC_DOWNLOAD_IsBusy((char *)(((struct Obj08112 *)a)->f8));
        GSYNC_STATE_ChangeState((u8 *)a,(int)GSYNC_STATE_StateMusicalSaveRetry,0x3e8);
    }
}
