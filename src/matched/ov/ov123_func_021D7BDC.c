/*
 * function: GSYNC_STATE_StateSelectNextDownload
 * address: 0x021D7BDC
 * packet: pkt_ov123_021D7BDC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateInitDownload 0x021D7B68 thumb ov123
 *   GSYNC_STATE_StateSaveStart 0x021D746C thumb ov123
 */
#include "../include/Obj05366.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateInitDownload(char *p);
extern void GSYNC_STATE_StateSaveStart(int a);
void GSYNC_STATE_StateSelectNextDownload(char *p)
{
    if (((struct Obj05366 *)p)->fA5) {
        p[0xa7] = 0;
        GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateInitDownload, 0x465);
        return;
    }
    if (((struct Obj05366 *)p)->fA4) {
        p[0xa7] = 1;
        GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateInitDownload, 0x46a);
        return;
    }
    if (((struct Obj05366 *)p)->fA6) {
        p[0xa7] = 2;
        GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateInitDownload, 0x46f);
        return;
    }
    GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateSaveStart, 0x472);
}
