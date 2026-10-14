/*
 * function: GSYNC_STATE_StateDownloadReset
 * address: 0x021D7858
 * packet: pkt_ov123_021D7858
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Word-array offset ((int *)a)[28] update avoids the cached
 *        address emitted for an integer-address lvalue at a+0x70.
 * symbols:
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateErrorMessage 0x021D6FF0 thumb ov123
 *   GSYNC_STATE_StateSelectNextDownload 0x021D7BDC thumb ov123
 *   GSYNC_DOWNLOAD_Reset 0x021D5C2C thumb ov123
 *   GSYNC_DOWNLOAD_ClearResult 0x021D5C0C thumb ov123
 *   GSYNC_DOWNLOAD_FreeWork 0x021D5B70 thumb ov123
 *   GSYNC_DISP_UpdateProgressPosition 0x021D66D0 thumb ov123
 */
#include "../include/Obj03270.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int GSYNC_DOWNLOAD_Reset(char *p);
extern int GSYNC_DOWNLOAD_ClearResult(char *p);
extern void GSYNC_DOWNLOAD_FreeWork(char *p);
extern void GSYNC_DISP_UpdateProgressPosition(unsigned char *,int);
extern void GSYNC_STATE_StateErrorMessage(char *p);
extern void GSYNC_STATE_StateSelectNextDownload(char *p);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
void GSYNC_STATE_StateDownloadReset(int a)
{
    if(GSYNC_DOWNLOAD_ClearResult((char *)(((struct Obj03270 *)a)->f8))) {
        if(GSYNC_DOWNLOAD_Reset((char *)(((struct Obj03270 *)a)->f8))) {
            ((struct Obj03270 *)a)->f80=0xfff0;
            GSYNC_STATE_ChangeState((u8 *)a,(int)GSYNC_STATE_StateErrorMessage,0x3b6);
            return;
        }
        GSYNC_DOWNLOAD_FreeWork((char *)(((struct Obj03270 *)a)->f8));
        ((struct Obj03270 *)a)->f8=0;
        if(((int *)a)[28]<100) ((int *)a)[28]+=10;
        GSYNC_DISP_UpdateProgressPosition(*(unsigned char * *)&((struct Obj03270 *)a)->f14,((struct Obj03270 *)a)->f70);
        GSYNC_STATE_ChangeState((u8 *)a,(int)GSYNC_STATE_StateSelectNextDownload,0x3c3);
    }
}
