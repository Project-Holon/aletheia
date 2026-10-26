/*
 * file:     mb_block.c
 * unit:     yes
 * function: MBi_SetChildMPMaxSize, MBi_SetParentPieceBuffer, MBi_ClearParentPieceBuffer, MBi_MakeParentSendBuffer, MBi_SetRecvBufferFromChild, MBi_ReceiveRequestDataPiece, IsGetAllRequestData
 * address:  0x021F6804
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F7008   0x021F7008  data
 *   _s32_div_f   0x0209C0A4  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   g_021F7008     0x021F7008  data
 *   MI_CpuCopy8  0x02082D44  arm
 */
struct MbBlockPiece {
    int reserved0;
    unsigned char *buf;
    int size;
    int max;
    int total;
};

#include "../types.h"

#include "../ov107/mb_block_types.h"

#include "../arm9/mi_memory.h"
int IsGetAllRequestData(int a);
void MBi_SetChildMPMaxSize(u16 childMaxSize);
void MBi_SetParentPieceBuffer(void *buf);
void MBi_ClearParentPieceBuffer(u16 child_aid);
u8 *MBi_MakeParentSendBuffer(const MBCommParentBlockHeader *hdr, u8 *sendbuf);
u8 *MBi_SetRecvBufferFromChild(u8 *recvbuf, MBCommChildBlockHeader *hdr, u16 child_id);
u8 *MBi_ReceiveRequestDataPiece(MBCommChildBlockHeader *hdr, u16 child);
extern struct MbBlockPiece d_021F7008;
extern struct MbBlockPiece g_021F7008;

void MBi_SetChildMPMaxSize(u16 childMaxSize)
{
    s32 n = childMaxSize - 2;

    d_021F7008.size = n;
    d_021F7008.max = 0x1E / n;
    d_021F7008.total = 0x1E;
}

void MBi_SetParentPieceBuffer(void *buf)
{
    d_021F7008.buf = buf;
    MI_CpuFill8(buf, 0, 0x21C);
}

/*
 * sdk:      MBi_ClearParentPieceBuffer (libmb.TWL.HYB.a mb_block.o)
 */
void MBi_ClearParentPieceBuffer(u16 child_aid)
{
    int i;

    if (g_021F7008.buf == 0)
        return;
    i = child_aid - 1;
    MI_CpuFill8(((u8 *)g_021F7008.buf) + i * 32, 0, 30);
    *(int *)(((u8 *)g_021F7008.buf) + 0x1E0 + i * 4) = 0;
}

/*
 * sdk:      MBi_MakeParentSendBuffer (libmb.TWL.HYB.a mb_block.o)
 *
 * notes:    a const header lets both halfwords load before the stores; with
 *           a plain pointer (or u16 locals) r1 and r2 swap.
 */
u8 *MBi_MakeParentSendBuffer(const MBCommParentBlockHeader *hdr, u8 *sendbuf)
{
    u8 *ptr = sendbuf;

    *ptr++ = hdr->type;
    switch (hdr->type) {
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        *ptr++ = (u8)(0x00FF & hdr->fid);
        *ptr++ = (u8)((0xFF00 & hdr->fid) >> 8);
        *ptr++ = (u8)(0x00FF & hdr->seqno);
        *ptr++ = (u8)((0xFF00 & hdr->seqno) >> 8);
        break;
    case 5:
    case 6:
        break;
    default:
        return 0;
    }
    return ptr;
}

/*
 * sdk:      MBi_SetRecvBufferFromChild (libmb.TWL.HYB.a mb_block.o)
 */
u8 *MBi_SetRecvBufferFromChild(u8 *recvbuf, MBCommChildBlockHeader *hdr, u16 child_id)
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
        hdr->u.data.req = recvbuf[1];
        hdr->u.data.req |= (recvbuf[2] << 8) & 0xFF00;
        ptr = recvbuf + 3;
        break;
    case 9:
        ptr = recvbuf + 3;
        hdr->u.data.req = recvbuf[1];
        hdr->u.data.req |= (recvbuf[2] << 8) & 0xFF00;
        MI_CpuCopy8(ptr, (u8 *)hdr + 4, g_021F7008.size);
        ptr += g_021F7008.size;
        break;
    default:
        return 0;
    }
    return ptr;
}

u8 *MBi_ReceiveRequestDataPiece(MBCommChildBlockHeader *hdr, u16 child)
{
    u8 piece;

    if (g_021F7008.buf == 0)
        return 0;
    piece = hdr->u.raw[0];
    if (piece > g_021F7008.max)
        return 0;
    MI_CpuCopy8((u8 *)hdr + 3,
                  ((u8 *)g_021F7008.buf) + (child - 1) * 32 + piece * g_021F7008.size,
                  g_021F7008.size);
    *(u32 *)(((u8 *)g_021F7008.buf) + 0x1E0 + (child - 1) * 4) |= 1 << piece;
    if (IsGetAllRequestData(child))
        return ((u8 *)g_021F7008.buf) + (child - 1) * 32;
    return 0;
}

/*
 * sdk:      IsGetAllRequestData (libmb.TWL.HYB.a mb_block.o)
 * address:  0x021F6AA4
 *
 * notes:    SDK library routine. It reads the piece count n from the shared
 *           piece state and returns 1 when the child's piece bitmap has every
 *           one of those n pieces set, else 0.
 */
int IsGetAllRequestData(int a)
{
    unsigned short i = 0;
    unsigned int v;
    int n = d_021F7008.max;

    if (n > 0) {
        v = *(unsigned int *)(d_021F7008.buf + (a - 1) * 4 + 0x1e0);
        do {
            if (!(v & (1u << i)))
                return 0;
        } while (++i < n);
    }
    return 1;
}
