/*
 * function: BTL_CLIENT_RecordReceivedPacket
 * address:  0x021D123C
 * packet:   pkt_ov093_021D123C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_ADAPTER_GetRecvData  0x021EEC20  thumb  ov093
 *   BTL_REC_AppendPacket  0x021EE608  thumb  ov093
 *   BTL_SERVER_LoadRecorderReplies  0x021BB4E0  thumb  ov093
 *   BTL_REC_GetPacketId  0x021EE638  thumb  ov093
 */
#include "../include/Obj05203.h"

extern int BTL_ADAPTER_GetRecvData(int, int *);
typedef unsigned char  u8;
extern void BTL_REC_AppendPacket(u8 *p, const u8 *src, int n);
extern void BTL_SERVER_LoadRecorderReplies(int, int, int);
extern u8 BTL_REC_GetPacketId(u8 *p);

int BTL_CLIENT_RecordReceivedPacket(int a)
{
    int tmp;
    int r4 = BTL_ADAPTER_GetRecvData(((struct Obj05203 *)a)->f50, &tmp);
    if (((struct Obj05203 *)a)->f10 != 0)
        BTL_REC_AppendPacket((u8 *)(((struct Obj05203 *)a)->f10), (const u8 *)tmp, r4);
    if (((struct Obj05203 *)a)->fA0 != 0) {
        BTL_SERVER_LoadRecorderReplies(((struct Obj05203 *)a)->fA0, tmp, r4);
        ((struct Obj05203 *)a)->f1AE = BTL_REC_GetPacketId((u8 *)tmp);
    }
    return 1;
}
