/*
 * function: EVENT_FIELD_PROCLINK_GetReturnInfo
 * address:  0x02161F14
 * packet:   pkt_ov010_02161F14
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   OEKAKI_SendPendingCommand  0x021867C4  thumb ov023
 *   FIELD_WFBC_DATA_LOCAL_GetNpcRecord  0x0218682C  thumb
 *   FIELD_WFBC_DATA_LOCAL_CloseNpcData  0x02186804  thumb
 */
#include "../include/Obj12331.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern int OEKAKI_SendPendingCommand(int, int);
extern u16 *FIELD_WFBC_DATA_LOCAL_GetNpcRecord(int h);
extern void FIELD_WFBC_DATA_LOCAL_CloseNpcData(int);

void EVENT_FIELD_PROCLINK_GetReturnInfo(u16 *out, u8 *in, int c)
{
    int h;
    u16 *q;
    if (((struct Obj12331 *)in)->f2 == 1) {
        h = OEKAKI_SendPendingCommand(in[9], (u16)((c & 0x7FFF) | 0x8000));
        q = FIELD_WFBC_DATA_LOCAL_GetNpcRecord(h);
        out[0] = q[0x24 / 2];
        out[1] = q[8 / 2];
        FIELD_WFBC_DATA_LOCAL_CloseNpcData(h);
    } else {
        out[0] = 0;
        out[1] = 10;
    }
}
