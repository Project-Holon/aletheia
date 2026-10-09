/*
 * file:     unit_021F6804.c
 * unit:     yes
 * function: func_021F6804, func_021F6830, func_021F6850, func_021F6890, func_021F6908, func_021F6A24
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
 *   func_02082BCC  0x02082BCC  arm
 *   g_021F7008     0x021F7008  data
 *   func_021F6AA4  0x021F6AA4  arm    ov107
 *   func_02082D44  0x02082D44  arm
 */
#include "../../matched/include/G_piece.h"
#include "../../matched/include/G_piece.h"

typedef unsigned short u16;

typedef int s32;

typedef unsigned long u32;

typedef unsigned char u8;

typedef struct {
    u8 type;
    u8 pad;
    u16 a;
    u16 b;
} ParentBlockHeader;

struct hdr {
    u8 type;
    u8 f1;
    u16 h2;
    u8 data[1];
};

typedef struct {
    u8 type;
    u8 pad;
    u8 piece;
} ChildBlockHeader;

extern void MI_CpuFill8(void *dst, int val, u32 len);
extern void func_02082BCC(void *dst, int val, u32 len);
extern int func_021F6AA4(int a);
extern void func_02082D44(void *src, void *dst, unsigned long size);
void MBi_SetChildMPMaxSize(u16 childMaxSize);
void MBi_SetParentPieceBuffer(void *buf);
void func_021F6850(u16 child_aid);
u8 *func_021F6890(const ParentBlockHeader *hdr, u8 *sendbuf);
u8 *func_021F6908(u8 *recvbuf, struct hdr *hdr, u16 child_id);
u8 *func_021F6A24(ChildBlockHeader *hdr, u16 child);
extern struct piece d_021F7008;
extern struct piece g_021F7008;





void MBi_SetChildMPMaxSize(u16 childMaxSize)
{
    s32 n = childMaxSize - 2;

    *(s32 *)(((char *)&d_021F7008) + 8) = n;
    *(s32 *)(((char *)&d_021F7008) + 0xC) = 0x1E / n;
    *(s32 *)(((char *)&d_021F7008) + 0x10) = 0x1E;
}





void MBi_SetParentPieceBuffer(void *buf)
{
    *(void **)(((char *)&d_021F7008) + 4) = buf;
    MI_CpuFill8(buf, 0, 0x21C);
}





/*
 * sdk:      MBi_ClearParentPieceBuffer (libmb.TWL.HYB.a mb_block.o)
 */
void func_021F6850(u16 child_aid)
{
    int i;

    if (g_021F7008.buf == 0)
        return;
    i = child_aid - 1;
    func_02082BCC(((u8 *)g_021F7008.buf) + i * 32, 0, 30);
    *(int *)(((u8 *)g_021F7008.buf) + 0x1E0 + i * 4) = 0;
}




/*
 * sdk:      MBi_MakeParentSendBuffer (libmb.TWL.HYB.a mb_block.o)
 *
 * notes:    a const header lets both halfwords load before the stores; with
 *           a plain pointer (or u16 locals) r1 and r2 swap.
 */
u8 *func_021F6890(const ParentBlockHeader *hdr, u8 *sendbuf)
{
    u8 *ptr = sendbuf;

    *ptr++ = hdr->type;
    switch (hdr->type) {
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        *ptr++ = (u8)(0x00FF & hdr->a);
        *ptr++ = (u8)((0xFF00 & hdr->a) >> 8);
        *ptr++ = (u8)(0x00FF & hdr->b);
        *ptr++ = (u8)((0xFF00 & hdr->b) >> 8);
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
u8 *func_021F6908(u8 *recvbuf, struct hdr *hdr, u16 child_id)
{
    u8 *ptr;
    u8 type;
    u8 idx;

    type = recvbuf[0];
    hdr->type = type;
    switch (type) {
    case 7:
        if (func_021F6AA4(child_id))
            return ((u8 *)g_021F7008.buf) + (child_id - 1) * 32;
        idx = recvbuf[1];
        *((u8 *)hdr + 2) = idx;
        if (idx > g_021F7008.max)
            return 0;
        func_02082D44(recvbuf + 2, (u8 *)hdr + 3, g_021F7008.size);
        ptr = func_021F6A24((ChildBlockHeader *)hdr, child_id);
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
        func_02082D44(ptr, (u8 *)hdr + 4, g_021F7008.size);
        ptr += g_021F7008.size;
        break;
    default:
        return 0;
    }
    return ptr;
}


u8 *func_021F6A24(ChildBlockHeader *hdr, u16 child)
{
    u8 piece;

    if (g_021F7008.buf == 0)
        return 0;
    piece = hdr->piece;
    if (piece > g_021F7008.max)
        return 0;
    func_02082D44((u8 *)hdr + 3,
                  ((u8 *)g_021F7008.buf) + (child - 1) * 32 + piece * g_021F7008.size,
                  g_021F7008.size);
    *(u32 *)(((u8 *)g_021F7008.buf) + 0x1E0 + (child - 1) * 4) |= 1 << piece;
    if (func_021F6AA4(child))
        return ((u8 *)g_021F7008.buf) + (child - 1) * 32;
    return 0;
}
