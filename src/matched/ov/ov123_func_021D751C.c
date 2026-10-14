/*
 * function: GSYNC_STATE_StateCleanupDownload
 * address: 0x021D751C
 * packet: pkt_ov123_021D751C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_DOWNLOAD_CleanupOnce 0x021D5D58 thumb ov123
 *   GSYNC_STATE_StateDownloadReset 0x021D7858 thumb ov123
 *   GSYNC_STATE_StateErrorMessage 0x021D6FF0 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 */
#include "../include/Obj13985.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int GSYNC_DOWNLOAD_CleanupOnce(char *p);
extern void GSYNC_STATE_StateDownloadReset(int a);
extern void GSYNC_STATE_StateErrorMessage(char *p);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
void GSYNC_STATE_StateCleanupDownload(int a)
{
    if (GSYNC_DOWNLOAD_CleanupOnce((char *)(((struct Obj13985 *)a)->f8))) {
        GSYNC_STATE_ChangeState((u8 *)a, (int)GSYNC_STATE_StateDownloadReset, 0x319);
        return;
    }
    ((struct Obj13985 *)a)->f80 = 0xfff0;
    GSYNC_STATE_ChangeState((u8 *)a, (int)GSYNC_STATE_StateErrorMessage, 0x31d);
}
