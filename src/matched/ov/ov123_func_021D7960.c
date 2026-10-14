/*
 * function: GSYNC_STATE_StateRequestFile
 * address: 0x021D7960
 * packet: pkt_ov123_021D7960
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_DOWNLOAD_GetFileAsync 0x021D5D24 thumb ov123
 *   GSYNC_STATE_StateWaitDownloadIdle 0x021D7910 thumb ov123
 *   GSYNC_STATE_StateErrorMessage 0x021D6FF0 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 */
#include "../include/Obj13988.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int GSYNC_DOWNLOAD_GetFileAsync(char *p);
extern void GSYNC_STATE_StateWaitDownloadIdle(int a);
extern void GSYNC_STATE_StateErrorMessage(char *p);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
void GSYNC_STATE_StateRequestFile(int a)
{
    if (GSYNC_DOWNLOAD_GetFileAsync((char *)(((struct Obj13988 *)a)->f8))) {
        GSYNC_STATE_ChangeState((u8 *)a, (int)GSYNC_STATE_StateWaitDownloadIdle, 0x3f1);
        return;
    }
    ((struct Obj13988 *)a)->f80 = 0xfff0;
    GSYNC_STATE_ChangeState((u8 *)a, (int)GSYNC_STATE_StateErrorMessage, 0x3f5);
}
