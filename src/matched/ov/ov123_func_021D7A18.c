/*
 * function: GSYNC_STATE_StateRequestFileList
 * address: 0x021D7A18
 * packet: pkt_ov123_021D7A18
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_DOWNLOAD_GetFileListAsync 0x021D5CF8 thumb ov123
 *   GSYNC_STATE_StateWaitDownloadIdleThenRequest 0x021D79A4 thumb ov123
 *   GSYNC_STATE_StateErrorMessage 0x021D6FF0 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 */
#include "../include/Obj13989.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int GSYNC_DOWNLOAD_GetFileListAsync(char *p);
extern void GSYNC_STATE_StateWaitDownloadIdleThenRequest(int a);
extern void GSYNC_STATE_StateErrorMessage(char *p);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
void GSYNC_STATE_StateRequestFileList(int a)
{
    if (GSYNC_DOWNLOAD_GetFileListAsync((char *)(((struct Obj13989 *)a)->f8))) {
        GSYNC_STATE_ChangeState((u8 *)a, (int)GSYNC_STATE_StateWaitDownloadIdleThenRequest, 0x415);
        return;
    }
    ((struct Obj13989 *)a)->f80 = 0xfff0;
    GSYNC_STATE_ChangeState((u8 *)a, (int)GSYNC_STATE_StateErrorMessage, 0x419);
}
