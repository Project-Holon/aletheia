/*
 * file:     net_ring_buff.c
 * unit:     yes
 * function: GFL_NET_RING_BUFF_Init, GFL_NET_RING_BUFF_Write, GFL_NET_RING_BUFF_Read, GFL_NET_RING_BUFF_ReadByte, GFL_NET_RING_BUFF_ReadU16, GFL_NET_RING_BUFF_Peek, GFL_NET_RING_BUFF_GetDataSize, GFL_NET_RING_BUFF_GetFreeSize, GFL_NET_RING_BUFF_WrapPos, GFL_NET_RING_BUFF_GetWritableSize, GFL_NET_RING_BUFF_EndChange
 * address:  0x0203640C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from touchpanel.c by tools/splitfile.py.
 *
 * symbols:
 *   GF_PANIC_Fail                    0x02034714  arm
 *   GFL_NET_SYSTEM_SetError                    0x02039548  arm
 *   _pTouchPanelWork                 0x021469C4  data
 *   net_ring_buff_File               0x020A79A4  data
 *   net_ring_buff_AssertDataArea     0x020A79B4  data
 *   net_ring_buff_AssertZero         0x020A79C0  data
 */
#include "touchpanel_shared_types.h"
#include "net_types.h"

#include "gf_panic.h"

#include "net_system.h"

/* net_ring_buff.c */
void GFL_NET_RING_BUFF_Init(NetRingBuff *ring, u8 *buf, int size);

void GFL_NET_RING_BUFF_Write(NetRingBuff *ring, const u8 *pDataArea, int size);

int GFL_NET_RING_BUFF_Read(NetRingBuff *ring, u8 *dst, u32 size, u32 max);

u32 GFL_NET_RING_BUFF_ReadByte(NetRingBuff *ring);

u32 GFL_NET_RING_BUFF_ReadU16(NetRingBuff *ring);

int GFL_NET_RING_BUFF_Peek(const NetRingBuff *ring, u8 *dst, int size, int max);

int GFL_NET_RING_BUFF_GetDataSize(NetRingBuff *ring);

int GFL_NET_RING_BUFF_GetFreeSize(NetRingBuff *ring);

int GFL_NET_RING_BUFF_WrapPos(const NetRingBuff *ring, int pos);

int GFL_NET_RING_BUFF_GetWritableSize(NetRingBuff *ring);

void GFL_NET_RING_BUFF_EndChange(NetRingBuff *ring);

extern const char net_ring_buff_File[];

extern const char net_ring_buff_AssertDataArea[];

extern const char net_ring_buff_AssertZero[];

/* ==================================================================
 * net_ring_buff.c
 * ================================================================== */
void GFL_NET_RING_BUFF_Init(NetRingBuff *ring, u8 *buf, int size)
{
    ring->buf = buf;
    ring->size = (short)size;   /* the store sign-extends from 16 bits */
    ring->readPos = 0;
    ring->writePos = 0;
}

/* Copies size bytes in at the write position; a full ring is a net error. */
void GFL_NET_RING_BUFF_Write(NetRingBuff *ring, const u8 *pDataArea, int size)
{
    int i;
    int k;

    if (GFL_NET_RING_BUFF_GetWritableSize(ring) <= size) {
        GFL_NET_SYSTEM_SetError();
        return;
    }
    k = 0;
    for (i = ring->writePos; i < ring->writePos + size; i++) {
        if (pDataArea == 0) {
            GF_PANIC_Fail(net_ring_buff_File, 0x44, net_ring_buff_AssertDataArea);
        }
        ring->buf[GFL_NET_RING_BUFF_WrapPos(ring, i)] = pDataArea[k];
        k++;
    }
    ring->writePos = (short)GFL_NET_RING_BUFF_WrapPos(ring, i);
}

/* Reads up to max bytes and moves the read position past them. */
int GFL_NET_RING_BUFF_Read(NetRingBuff *ring, u8 *dst, u32 size, u32 max)
{
    int got = GFL_NET_RING_BUFF_Peek(ring, dst, size, max);

    ring->readPos = (short)GFL_NET_RING_BUFF_WrapPos(ring, ring->readPos + got);
    return got;
}

u32 GFL_NET_RING_BUFF_ReadByte(NetRingBuff *ring)
{
    u8 byte;

    if (GFL_NET_RING_BUFF_Read(ring, &byte, 1, 1) == 1)
        return byte;
    GF_PANIC_Fail(net_ring_buff_File, 0x6C, net_ring_buff_AssertZero);
    return 0;
}

/* Big-endian halfword: the high byte comes first. */
u32 GFL_NET_RING_BUFF_ReadU16(NetRingBuff *ring)
{
    u16 hi;
    u32 lo;

    hi = (u16)(GFL_NET_RING_BUFF_ReadByte(ring) << 8);
    lo = GFL_NET_RING_BUFF_ReadByte(ring);
    return (u16)(hi | lo);
}

/* Copies up to max bytes from the read position without consuming them. */
int GFL_NET_RING_BUFF_Peek(const NetRingBuff *ring, u8 *dst, int size, int max)
{
    int i;
    int n;

    n = 0;
    for (i = ring->readPos; i < ring->readPos + size; i++) {
        if (ring->writePos == GFL_NET_RING_BUFF_WrapPos(ring, i) || n == max) {
            return n;
        }
        dst[n] = ring->buf[GFL_NET_RING_BUFF_WrapPos(ring, i)];
        n++;
    }
    return n;
}

/* Bytes waiting to be read. */
int GFL_NET_RING_BUFF_GetDataSize(NetRingBuff *ring)
{
    int readPos = ring->readPos;

    if (readPos > ring->writePos)
        return ring->size + ring->writePos - readPos;
    return ring->writePos - readPos;
}

int GFL_NET_RING_BUFF_GetFreeSize(NetRingBuff *ring)
{
    int used = GFL_NET_RING_BUFF_GetDataSize(ring);

    return ring->size - used;
}

int GFL_NET_RING_BUFF_WrapPos(const NetRingBuff *ring, int pos)
{
    return pos % ring->size;
}

static inline int GFL_NET_RING_BUFF_DataSize(NetRingBuff *ring)
{
    int readPos = ring->readPos;

    if (readPos > ring->writePos)
        return (u32)ring->size + ring->writePos - readPos;
    return ring->writePos - readPos;
}

/* Free space, with the data size computed inline. */
int GFL_NET_RING_BUFF_GetWritableSize(NetRingBuff *ring)
{
    return ring->size - GFL_NET_RING_BUFF_DataSize(ring);
}

/* Write commit hook; it does nothing in this version. */
void GFL_NET_RING_BUFF_EndChange(NetRingBuff *ring)
{
}
