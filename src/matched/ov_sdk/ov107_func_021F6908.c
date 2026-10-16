/*
 * function: MBi_SetRecvBufferFromChild
 * address:  0x021F6908
 * packet:   pkt_ov107_021F6908
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_SetRecvBufferFromChild (libmb.TWL.HYB.a mb_block.o)
 *
 * symbols:
 *   IsGetAllRequestData  0x021F6AA4  arm    ov107
 *   MI_CpuCopy8  0x02082D44  arm
 *   MBi_ReceiveRequestDataPiece  0x021F6A24  arm    ov107
 *   g_021F7008     0x021F7008  data
 */

#include "../include/G_piece.h"

typedef unsigned char u8;
typedef unsigned short u16;

struct hdr {
    u8 type;
    u8 f1;
    u16 h2;
    u8 data[1];
};

extern struct piece g_021F7008;

extern int IsGetAllRequestData(int a);
extern void MI_CpuCopy8(void *src, void *dst, unsigned long size);
extern u8 *MBi_ReceiveRequestDataPiece(struct hdr *hdr, u16 child);

u8 *MBi_SetRecvBufferFromChild(u8 *recvbuf, struct hdr *hdr, u16 child_id)
{
    u8 *ptr;
    u8 type;
    u8 idx;

    type = recvbuf[0];
    hdr->type = type;
    switch (type) {
    case 7:
        if (IsGetAllRequestData(child_id))
            return ((u8 *)g_021F7008.buf) + (child_id - 1) * 32;
        idx = recvbuf[1];
        *((u8 *)hdr + 2) = idx;
        if (idx > g_021F7008.max)
            return 0;
        MI_CpuCopy8(recvbuf + 2, (u8 *)hdr + 3, g_021F7008.size);
        ptr = MBi_ReceiveRequestDataPiece(hdr, child_id);
        break;
    case 8:
        hdr->h2 = recvbuf[1];
        hdr->h2 |= (recvbuf[2] << 8) & 0xFF00;
        ptr = recvbuf + 3;
        break;
    case 9:
        ptr = recvbuf + 3;
        hdr->h2 = recvbuf[1];
        hdr->h2 |= (recvbuf[2] << 8) & 0xFF00;
        MI_CpuCopy8(ptr, (u8 *)hdr + 4, g_021F7008.size);
        ptr += g_021F7008.size;
        break;
    default:
        return 0;
    }
    return ptr;
}
