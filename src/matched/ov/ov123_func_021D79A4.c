/*
 * function: GSYNC_STATE_StateWaitDownloadIdleThenRequest
 * address: 0x021D79A4
 * packet: pkt_ov123_021D79A4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateErrorMessage 0x021D6FF0 thumb ov123
 *   GSYNC_STATE_StateRequestFile 0x021D7960 thumb ov123
 *   GSYNC_DOWNLOAD_Reset 0x021D5C2C thumb ov123
 *   GSYNC_DOWNLOAD_ClearResult 0x021D5C0C thumb ov123
 *   GSYNC_DOWNLOAD_IsBusy 0x021D5C9C thumb ov123
 *   GSYNC_DISP_GetPokeIconActor 0x021D5D8C thumb ov123
 */
#include "../include/Obj05365.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int GSYNC_DOWNLOAD_Reset(char *p);
extern int GSYNC_DOWNLOAD_ClearResult(char *p);
extern void *GSYNC_DISP_GetPokeIconActor(u8 *p);
extern void GSYNC_DOWNLOAD_IsBusy(char *p);
extern void GSYNC_STATE_StateErrorMessage(char *p);
extern void GSYNC_STATE_StateRequestFile(int a);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
void GSYNC_STATE_StateWaitDownloadIdleThenRequest(int a)
{
    if(GSYNC_DOWNLOAD_Reset((char *)(((struct Obj05365 *)a)->f8))) {
        ((struct Obj05365 *)a)->f80=0xfff0;
        GSYNC_STATE_ChangeState((u8 *)a,(int)GSYNC_STATE_StateErrorMessage,0x3fe);
        return;
    }
    if(GSYNC_DOWNLOAD_ClearResult((char *)(((struct Obj05365 *)a)->f8))) {
        if(GSYNC_DISP_GetPokeIconActor((u8 *)(((struct Obj05365 *)a)->f8))==0) {
            ((struct Obj05365 *)a)->f80=0xfff0;
            GSYNC_STATE_ChangeState((u8 *)a,(int)GSYNC_STATE_StateErrorMessage,0x407);
            return;
        }
        GSYNC_DOWNLOAD_IsBusy((char *)(((struct Obj05365 *)a)->f8));
        GSYNC_STATE_ChangeState((u8 *)a,(int)GSYNC_STATE_StateRequestFile,0x40d);
    }
}
